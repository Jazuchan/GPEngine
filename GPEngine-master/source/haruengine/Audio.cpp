#include "Audio.h"

#include <AL/al.h>
#include <vorbis/vorbisfile.h>

#include <iostream>
#include <vector>

namespace haru
{
	struct AudioImpl
	{
		ALuint id;

		~AudioImpl()
		{
			alDeleteBuffers(1, &id);
		}

		void load_ogg(std::string fileName, std::vector<char> &buffer,
			ALenum &format, ALsizei &freq)
		{
			int endian = 0;
			int bitStream = 0;
			long bytes = 0;
			char array[2048] = { 0 };

			vorbis_info *pInfo = NULL;
			OggVorbis_File oggFile = { 0 };

			if (ov_fopen(fileName.c_str(), &oggFile) != 0)
			{
				std::cout << "Failed to open file '" << fileName << "' for decoding" << std::endl;
				throw std::exception();
			}

			pInfo = ov_info(&oggFile, -1);

			if (pInfo->channels == 1)
			{
				format = AL_FORMAT_MONO16;
			}
			else
			{
				format = AL_FORMAT_STEREO16;
			}

			freq = pInfo->rate;

			while (true)
			{
				bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitStream);

				if (bytes < 0)
				{
					ov_clear(&oggFile);
					std::cout << "Failed to decode file '" << fileName << "'." << std::endl;
					throw std::exception();
				}
				else if (bytes == 0)
				{
					break;
				}

				buffer.insert(buffer.end(), array, array + bytes);
			}

			ov_clear(&oggFile);
		}
	};

	Audio::Audio() { }

	Audio::Audio(std::string path)
	{
		load(path);
	}

	void Audio::load(std::string path)
	{
		impl = std::make_shared<AudioImpl>();

		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;

		alGenBuffers(1, &impl->id);

		impl->load_ogg(path.c_str(), bufferData, format, freq);

		alBufferData(impl->id, format, &bufferData[0],
			static_cast<ALsizei>(bufferData.size()), freq);
	}

	void Audio::play()
	{
		ALuint sid = 0;
		alGenSources(1, &sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sid, AL_BUFFER, impl->id);
		alSourcePlay(sid);

		//audioSources.push_back(sid);
	}

	void Audio::play(float vol, float varMin, float varMax)
	{
		
		varMin *= 1000.0f;
		varMax *= 1000.0f;
		float variance = (std::rand() % ((int)varMin + 1 - (int)varMax) + (int)varMin) / 1000.0f;
		//return std::rand() % (max + 1 - min) + min;
		ALuint sid = 0;
		alGenSources(1, &sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sid, AL_BUFFER, impl->id);
		alSourcef(sid, AL_PITCH, variance);
		alSourcef(sid, AL_GAIN, vol);
		alSourcePlay(sid);

		//audioSources.push_back(sid);
	}
}
