#include "Mesh.h"

namespace haru
{
	Mesh::~Mesh()
	{}

	void Mesh::AddFaces(std::shared_ptr<Face>& face)
	{

	}

	std::shared_ptr<Mesh>Mesh::Create()
	{
		return 0;
	}

	std::shared_ptr<Mesh>Mesh::Load(std::string _path)
	{
		return 0;
	}

	GLuint Mesh::GetId()
	{
		return m_id;
	}

}