#include "Segment.h"

#include <memory>

namespace haru
{

	class VertexArray;
	class ShaderProgram;

	class MeshRenderer : public Segment
	{
	public:
	  void onInit();

	private:
	  void onDisplay();

	  std::shared_ptr<VertexArray> shape;
	  std::shared_ptr<ShaderProgram> shader;

	};

}
