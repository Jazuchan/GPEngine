#include "Vertex.h"
#include "Texture.h"

#include <iostream>
#include <sstream>
#include <fstream>


namespace haru
{
	class Mesh
	{
	public:
		Mesh();
		void Draw();

		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture> textures;

		unsigned int VAO;

	private:
		void setUpMesh();

		unsigned int VBO, EBO;
	};
}
//https://learnopengl.com/code_viewer_gh.php?code=includes/learnopengl/mesh.h