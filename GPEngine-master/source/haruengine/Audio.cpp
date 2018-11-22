#include "Audio.h"

#include <AL/al.h>
#include <vorbis/vorbisfile.h>

#include <iostream>
#include <vector>

namespace haru
{
	struct AudioImpl
	{
		ALuint m_id;

		~AudioImpl()
		{
			alDeleteBuffers(1, &m_id);
		}

		void LoadOgg(std::string _fileName, std::vector<char> &_buffer,
			ALenum &_format, ALsizei &_freq)
		{
			int m_endian = 0;
			int m_bitStream = 0;
			long m_bytes = 0;
			char m_array[2048] = { 0 };

			vorbis_info *m_pInfo = NULL;
			OggVorbis_File m_oggFile = { 0 };

			if (ov_fopen(_fileName.c_str(), &m_oggFile) != 0)
			{
				std::cout << "Failed to open file '" << _fileName << "' for decoding" << std::endl;
				throw std::exception();
			}

			m_pInfo = ov_info(&m_oggFile, -1);

			if (m_pInfo->channels == 1)
			{
				_format = AL_FORMAT_MONO16;
			}
			else
			{
				_format = AL_FORMAT_STEREO16;
			}

			_freq = m_pInfo->rate;

			while (true)
			{
				m_bytes = ov_read(&m_oggFile, m_array, 2048, m_endian, 2, 1, &m_bitStream);

				if (m_bytes < 0)
				{
					ov_clear(&m_oggFile);
					std::cout << "Failed to decode file '" << _fileName << "'." << std::endl;
					throw std::exception();
				}
				else if (m_bytes == 0)
				{
					break;
				}

				_buffer.insert(_buffer.end(), m_array, m_array + m_bytes);
			}

			ov_clear(&m_oggFile);
		}
	};

	Audio::Audio() { }

	Audio::Audio(std::string _path)
	{
		Load(_path);
	}

	void Audio::Load(std::string _path)
	{
		m_impl = std::make_shared<AudioImpl>();

		ALenum m_format = 0;
		ALsizei m_freq = 0;
		std::vector<char> m_bufferData;

		alGenBuffers(1, &m_impl->m_id);

		m_impl->LoadOgg(_path.c_str(), m_bufferData, m_format, m_freq);

		alBufferData(m_impl->m_id, m_format, &m_bufferData[0],
			static_cast<ALsizei>( m_bufferData.size()), m_freq);
	}

	void Audio::Play()
	{
		ALuint m_sid = 0;
		alGenSources(1, &m_sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f( m_sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei( m_sid, AL_BUFFER, m_impl->m_id);
		alSourcePlay( m_sid);

		//audioSources.push_back(sid);
	}

	void Audio::Play(float _vol, float _varMin, float _varMax)
	{
		
		_varMin *= 1000.0f;
		_varMax *= 1000.0f;
		float m_variance = (std::rand() % ((int)_varMin + 1 - (int)_varMax) + (int)_varMin) / 1000.0f;
		//return std::rand() % (max + 1 - min) + min;
		ALuint m_sid = 0;
		alGenSources(1, &m_sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f( m_sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei( m_sid, AL_BUFFER, m_impl->m_id);
		alSourcef( m_sid, AL_PITCH, m_variance);
		alSourcef( m_sid, AL_GAIN, _vol);
		alSourcePlay( m_sid);

		//audioSources.push_back(sid);
	}
}
