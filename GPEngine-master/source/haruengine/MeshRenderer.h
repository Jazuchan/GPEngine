#include "Segment.h"

#include <memory>

namespace haru
{

	class VertexArray;
	class ShaderProgram;
	class Texture;
	class RenderTexture;

	class MeshRenderer : public Segment
	{
	public:
	  void OnInit();
	  int m_windowW = 800;
	  int m_windowH = 800;
	  float angle = 0;
	  

	private:
	  void OnDisplay();

	  std::shared_ptr<ShaderProgram> m_shader;
	  std::shared_ptr<ShaderProgram> m_lightkeyShader;
	  std::shared_ptr<ShaderProgram> m_nullShader;
	  std::shared_ptr<ShaderProgram> m_blurShader;
	  std::shared_ptr<ShaderProgram> m_mergeShader;

	  std::shared_ptr<RenderTexture> m_rt;
	  std::shared_ptr<RenderTexture> m_lightkeyRt;
	  std::shared_ptr<RenderTexture> m_blurRt;
	  std::shared_ptr<RenderTexture> m_blur2Rt;
	  std::shared_ptr<RenderTexture> m_blur3Rt;
	  std::shared_ptr<RenderTexture> m_mergeRt;

	  std::shared_ptr<Texture> m_texture;
	  std::shared_ptr<Texture> m_hallTex;

	  std::shared_ptr<VertexArray> m_cube;
	  std::shared_ptr<VertexArray> m_hallShape;
	 
	};

}
