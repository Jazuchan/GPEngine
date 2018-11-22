#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/ext.hpp>


namespace haru
{
	struct ReMesh
	{
		std::string m_path;
		GLuint GetId();

	};

	class Resource
	{

		Resource();

	};
}