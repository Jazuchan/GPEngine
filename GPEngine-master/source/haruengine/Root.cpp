#include <GL/glew.h>
#include "Root.h"
#include "Object.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

namespace haru
{
	std::shared_ptr<Root> Root::load()
	{
		std::shared_ptr<Root> rtn = std::make_shared<Root>();
		rtn->active = false;
		rtn->self = rtn;

		if(SDL_Init( SDL_INIT_VIDEO ) < 0)
		{
			throw std::exception();
		}

		rtn->window = SDL_CreateWindow( "Haru Engine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT, 
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL );

		if(!SDL_GL_CreateContext( rtn->window ))
		{
			throw std::exception();
		}

		if(glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		return rtn;
	}

	void Root::start()
	{
		active = true;

		while(active)
		{
			SDL_Event event = { 0 };

			while(SDL_PollEvent( &event ))
			{
				if(event.type == SDL_QUIT)
				{
					active = true;
				}
			}

			for(std::vector<std::shared_ptr<Object>>::iterator it = objects.begin(); 
				it != objects.end(); it++)
			{
				(*it)->tick();
			}

			glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
			glClear( GL_COLOR_BUFFER_BIT );
;
			for(std::vector<std::shared_ptr<Object>>::iterator it = objects.begin();
				it != objects.end(); it++)
			{
				(*it)->display();
			}

			SDL_GL_SwapWindow( window );
		}
	}

	void Root::finish()
	{
		active = false;
	}

	std::shared_ptr<Object> Root::addObject()
	{
		std::shared_ptr<Object> rtn = std::make_shared<Object>();
		objects.push_back( rtn );
		rtn->self = rtn;
		rtn->root = self;

		return rtn;
	}

	std::shared_ptr<Domain> Root::domain()
	{
		return 0;
	}

	std::shared_ptr<Keyboard> Root::keyboard()
	{
		return 0;
	}
}
