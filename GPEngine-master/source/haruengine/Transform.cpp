#include "Transform.h"

namespace haru
{
	Transform::Transform()
	{

	}

	void Transform::Update(float deltaTs)
	{
		while (rot.y > (3.14159265358979323846 * 2.0))
		{
			rot.y -= (float)(3.14159265358979323846 * 2.0);
		}
	}
}