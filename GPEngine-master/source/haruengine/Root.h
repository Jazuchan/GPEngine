#include <SDL2/SDL.h>
#include <memory>
#include <vector>

namespace haru
{
	class Object;
	class Domain;
	class Keyboard;

	class Root
	{
	public:
		std::shared_ptr<Root> load();

		void start();
		void finish();
		std::shared_ptr<Object> addObject();

	private:
		bool active;
		std::vector<std::shared_ptr<Object>> objects;
		std::shared_ptr<Domain> domain();
		std::shared_ptr<Keyboard> keyboard();
		std::weak_ptr<Root> self;

		SDL_Window * window;
	};
}