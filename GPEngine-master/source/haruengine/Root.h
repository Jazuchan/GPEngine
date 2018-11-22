#include <SDL2/SDL.h>

#include <AL/al.h>
#include <AL/alc.h>

#include <memory>
#include <vector>

namespace haru
{
	class Object;
	class Domain;
	class Keyboard;
	class ShaderProgram;
	class Mouse;

	class Root
	{
	public:
		static std::shared_ptr<Root> Load();

		void Start();
		void Finish();
		std::shared_ptr<Object> AddObject();

		
	private:
		bool m_active;
		std::shared_ptr<Mouse> m_mouse;
		std::shared_ptr<ShaderProgram> m_shader;
		std::vector<std::shared_ptr<Object>> m_objects;
		std::weak_ptr<Root> m_self;
		std::shared_ptr<Domain> Domain();
		std::shared_ptr<Keyboard> Keyboard();

		SDL_Window* m_window;
		ALCdevice* m_device;
		ALCcontext* m_context;
	};
}