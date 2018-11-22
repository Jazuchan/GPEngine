#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>


namespace haru
{
	class RenderTexture;

	class Texture
	{
		friend class RenderTexture;

		GLuint m_id;
		glm::vec2 m_size;

		Texture(int _width, int _height);

	public:
		Texture( std::string _path );
		glm::vec2 GetSize();
		GLuint GetId();
	};
}
#endif