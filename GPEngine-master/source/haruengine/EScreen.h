#include "Transform.h"
#include "Root.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>

#include <iostream>
#include <sstream>
#include <fstream>


namespace haru
{
	class EScreen
	{
	public:

		void OnTick();
		void MouseMove();

		glm::mat4 m_viewMat;
		int m_mousePosX, m_mousePosY;

	};
}