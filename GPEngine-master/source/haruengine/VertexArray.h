#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>
#include <memory>

namespace haru
{

	class VertexBuffer;

	class VertexArray
	{
	  GLuint m_id;
	  bool m_dirty;
	  std::vector<std::shared_ptr<VertexBuffer>> m_buffers;

	  void SplitStringWhitespace( std::string& _input, std::vector<std::string>& _output );
	  void SplitString( std::string& _input, char _splitter, std::vector<std::string>& _output );

	public:
	  VertexArray();
	  VertexArray( std::string _path );
	  void SetBuffer(std::string _attribute, std::shared_ptr<VertexBuffer> _buffer);
	  int GetVertexCount();
	  GLuint GetId();

	};

}
