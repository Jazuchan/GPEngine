#include <memory>
#include <string>

namespace haru
{
	struct AudioImpl;

	class Audio
	{
		std::shared_ptr<AudioImpl> m_impl;

	public:
		Audio();
		Audio(std::string _path);

		void Load(std::string _path);
		void Play();
		void Play(float _vol, float _varMin, float _varMax);
	};
}