#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

namespace haru
{
	class VertexBuffer
	{
	  GLuint m_id;
	  int m_components;
	  std::vector<GLfloat> m_data;
	  bool m_dirty;

	public:
	  VertexBuffer();
	  void Add(glm::vec2 _value);
	  void Add(glm::vec3 _value);
	  void Add(glm::vec4 _value);
	  int GetComponents();
	  int GetDataSize();
	  GLuint GetId();

	};
}
