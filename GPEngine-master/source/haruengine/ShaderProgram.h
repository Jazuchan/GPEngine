#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>
#include <memory>

namespace haru
{
	class RenderTexture;
	class VertexArray;
	class VertexBuffer;
	class Texture;

	struct Sampler
	{
		GLint m_id;
		std::shared_ptr<Texture> m_texture;
	};
	
	class ShaderProgram
	{
	  GLuint m_id;
	  std::vector<Sampler> m_samplers;
	  glm::vec4 m_viewport;
	  std::shared_ptr<VertexArray> m_simpleShape;
	  std::shared_ptr<VertexBuffer> m_positions;
	  std::shared_ptr<VertexBuffer> m_texCoords;

	  

	public:
	  ShaderProgram(std::string _vert, std::string _frag);
	  void Draw();
	  void Draw(std::shared_ptr<RenderTexture> _renderTexture);
	  void Draw(std::shared_ptr<VertexArray> _vertexArray);
	  void Draw(std::shared_ptr<RenderTexture> _renderTexture, std::shared_ptr<VertexArray> _vertexArray);
	  void SetUniform(std::string _uniform, glm::vec4 _value);
	  void SetUniform(std::string _uniform, float _value);
	  void SetUniform(std::string _uniform, int _value);
	  void SetUniform(std::string _uniform, glm::mat4 _value);
	  void SetUniform(std::string _uniform, std::shared_ptr<Texture> _texture);
	  void SetViewport(glm::vec4 _viewport);
	  GLuint GetId();

	};

}

