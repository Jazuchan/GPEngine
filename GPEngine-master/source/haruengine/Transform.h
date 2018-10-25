#include <vector>
#include <glm/glm.hpp>

namespace haru
{
	class Transform
	{
	public:
		Transform();

		glm::vec3 pos;
		glm::vec3 rot;
		glm::vec3 sca;

		void setPos(float posX, float posY, float posZ) { pos.x = posX; pos.y = posY; pos.z = posZ; }
		void setRot(float rotX, float rotY, float rotZ) { rot.x = rotX; rot.y = rotY; rot.z = rotZ; }
		void setSca(float scaX, float scaY, float scaZ) { sca.x = scaX; sca.y = scaY; sca.z = scaZ; }

		glm::vec3 GetPos() { return pos; }

		virtual void Update (float deltaTs);
	};
}