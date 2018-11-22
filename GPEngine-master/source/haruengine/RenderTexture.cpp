#include "RenderTexture.h"

namespace haru
{
	RenderTexture::RenderTexture(int _width, int _height) : Texture(_width, _height)
	{
		glGenFramebuffers(1, &m_fbo);
		if (!m_fbo) throw std::exception();
		glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_id, 0);

		GLuint m_rbo = 0;
		glGenRenderbuffers(1, &m_rbo);
		glBindRenderbuffer(GL_RENDERBUFFER, m_rbo);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, _width, _height);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_rbo);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	GLuint RenderTexture::GetFbId()
	{
		return m_fbo;
	}

	void RenderTexture::Clear()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
}