#include <vector>
#include <glm/glm.hpp>

namespace haru
{
	class Transform
	{
	public:
		
		void SetPos( glm::vec3 _pos );   //(float posX, float posY, float posZ) { m_pos.x = posX; m_pos.y = posY; m_pos.z = posZ; }
		void SetRot( glm::vec3 _rot );    //(float rotX, float rotY, float rotZ) { m_rot.x = rotX; m_rot.y = rotY; m_rot.z = rotZ; }
		void SetSca( glm::vec3 _sca );    //(float scaX, float scaY, float scaZ) { m_sca.x = scaX; m_sca.y = scaY; m_sca.z = scaZ; }

		//glm::vec3 GetPos() { return m_pos; }
		//virtual void Update (float _deltaTs);

	private:
		glm::vec3 m_pos;
		glm::vec3 m_rot;
		glm::vec3 m_sca;
	};
}