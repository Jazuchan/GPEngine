#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/ext.hpp>
#include <exception>
#include <iostream>
#include "Root.h"
#include "Object.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "MeshRenderer.h"
#include "Mouse.h"

int g_windowW = 800;
int g_windowH = 800;

namespace haru
{
	std::shared_ptr<Root> Root::Load()
	{
		std::shared_ptr<Root> m_rtn = std::make_shared<Root>();
		m_rtn->m_active = false;
		m_rtn->m_self = m_rtn;

		if(SDL_Init( SDL_INIT_VIDEO ) < 0)
		{
			throw std::exception();
		}

		m_rtn->m_window = SDL_CreateWindow( "Haru Engine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			g_windowW, g_windowH,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL );

		if(!SDL_GL_CreateContext( m_rtn->m_window ))
		{
			throw std::exception();
		}

		if(glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		m_rtn->m_device = alcOpenDevice(NULL);

		if (!m_rtn->m_device)
		{
			throw std::exception();
		}

		m_rtn->m_context = alcCreateContext( m_rtn->m_device, NULL);

		if (!m_rtn->m_context)
		{
			alcCloseDevice( m_rtn->m_device);
			throw std::exception();
		}

		if (!alcMakeContextCurrent( m_rtn->m_context))
		{
			alcDestroyContext( m_rtn->m_context);
			alcCloseDevice( m_rtn->m_device);
			throw std::exception();
		}

		return m_rtn;
	}

	void Root::Start()
	{
		m_active = true;

		glEnable( GL_CULL_FACE );
		glFrontFace(GL_CCW);
		glEnable( GL_DEPTH_TEST );

		m_mouse = std::make_shared<Mouse>();

		while(m_active)
		{
			SDL_Event m_event = { 0 };

			while(SDL_PollEvent( &m_event ))
			{
				if(m_event.type == SDL_QUIT)
				{
					m_active = true;
				}
				
				switch(m_event.type)
				{
				case SDL_MOUSEMOTION:
					std::cout << m_event.motion.x << ", " << m_event.motion.y << std::endl;
					break;
				}

				//m_mouse->MouseUpdate();

			}

			for(std::vector<std::shared_ptr<Object>>::iterator it = m_objects.begin();
				it != m_objects.end(); it++)
			{
				(*it)->Tick();
			}

			SDL_GetWindowSize( m_window, &g_windowW, &g_windowH );
			glViewport( 0, 0, g_windowW, g_windowH );
			glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


			for(std::vector<std::shared_ptr<Object>>::iterator it = m_objects.begin();
				it != m_objects.end(); it++)
			{
				(*it)->Display();
			}

			SDL_GL_SwapWindow( m_window );
		}
		SDL_DestroyWindow( m_window );
		SDL_Quit();
	}

	void Root::Finish()
	{
		m_active = false;
	}

	std::shared_ptr<Object> Root::AddObject()
	{
		std::shared_ptr<Object> m_rtn = std::make_shared<Object>();
		m_objects.push_back( m_rtn );
		m_rtn->m_self = m_rtn;
		m_rtn->m_root = m_self;

		return m_rtn;
	}

	std::shared_ptr<Domain> Root::Domain()
	{
		return 0;
	}

	std::shared_ptr<Keyboard> Root::Keyboard()
	{
		return 0;
	}
}
