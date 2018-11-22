#include "Texture.h"

#include <stb_image/stb_image.h>

namespace haru
{
	Texture::Texture(int _width, int _height)
	{
		m_size.x = _width;
		m_size.y = _height;

		glGenTextures(1, &m_id);
		glBindTexture(GL_TEXTURE_2D, m_id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	//std::shared_ptr<Texture>
	Texture::Texture(std::string _path)
	{
		int m_w = 0;
		int m_h = 0;
		int m_channels = 0;

		unsigned char *m_data = stbi_load( _path.c_str(), &m_w, &m_h, &m_channels, 4 );

		if(!m_data)
		{
			throw std::exception();
		}

		m_size.x = m_w;
		m_size.y = m_h;

		glGenTextures( 1, &m_id );

		if(!m_id)
		{
			throw std::exception();
		}

		glBindTexture( GL_TEXTURE_2D, m_id );

		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, m_w, m_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data );
		free( m_data );
		glGenerateMipmap( GL_TEXTURE_2D );

		glBindTexture( GL_TEXTURE_2D, 0 );
	}

	glm::vec2 Texture::GetSize()
	{
		return m_size;
	}

	GLuint Texture::GetId()
	{
		return m_id;
	}
}