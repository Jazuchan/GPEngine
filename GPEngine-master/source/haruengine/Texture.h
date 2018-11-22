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
		bool m_dirty;
		Texture(int _width, int _height);

		/*std::shared_ptr<Texture> Create(unsigned int _width, unsigned int _height);*/
		//std::shared_ptr<Texture> Load(std::string _path);

	public:
		Texture( std::string _path );
		/*void SetPixel(unsigned int _x, unsigned int _y, glm::vec3 _color);
		void SetPixel(unsigned int _x, unsigned int _y, glm::vec4 _color);*/
		glm::vec2 GetSize();
		GLuint GetId();
	};
}
#endif