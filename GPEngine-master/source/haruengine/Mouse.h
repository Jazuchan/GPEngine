#include <vector>
#include <iostream>
#include <memory>

#include <SDL2/SDL.h>

namespace haru
{
	class MesherRender;
	class Mouse
	{
	public:
		int m_x = 0;
		int m_y = 0;
		//void OnInit();
		void MouseUpdate();
		SDL_Event m_mouseE;
		//SDL_MouseButtonEvent m_mouseE;
		//Uint32 SDL_GetMouseState( int x, int y );

	private:
		bool m_active;
	};
}