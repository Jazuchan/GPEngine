#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/ext.hpp>

namespace haru
{
	struct Face
	{

	};

	class Mesh
	{
	public:
		~Mesh();
		void AddFaces(std::shared_ptr<Face>& face);
		GLuint GetId();


	private:
		std::vector<Face> m_faces;
		bool m_dirty;
		GLuint m_id;
		std::shared_ptr<Mesh> Create();
		std::shared_ptr<Mesh> Load(std::string _path);

	};
}