#include "Texture.h"

namespace haru
{
	class RenderTexture : public Texture
	{
		GLuint m_fbo;

	public:
		RenderTexture(int _width, int _height);

		GLuint GetFbId();
		void Clear();

	};
}
