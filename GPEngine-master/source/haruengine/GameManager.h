#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <list>

#include "Resource.h"

namespace haru
{
	class Resource;

	class GameManager
	{
	public:
		template <typename T>
		std::shared_ptr<T> Load(std::string _path)
		{
			for (size_t i = 0; i < m_gameManager.size(); i++)
			{

			}
		}

		template <typename T>
		std::shared_ptr<T> Make()
		{

		}


	private:
		std::list<std::shared_ptr<Resource>> m_gameManager;
	};
}