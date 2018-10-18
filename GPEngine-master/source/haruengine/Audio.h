#include <memory>
#include <string>

namespace haru
{
	struct AudioImpl;

	class Audio
	{
		std::shared_ptr<AudioImpl> impl;

	public:
		Audio();
		Audio(std::string path);

		void load(std::string path);
		void play();
		void play(float vol, float varMin, float varMax);
	};
}