#include "Transform.h"

namespace haru
{
	Transform::Transform()
	{

	}

	void Transform::Update(float deltaTs)
	{
		while (rot.x > (3.14159265358979323846 * 2.0))
		{
			rot.x += (float)(3.14159265358979323846 * 2.0);
		}

		while(rot.y > ( 3.14159265358979323846 * 2.0 ))
		{
			rot.y -= ( float ) ( 3.14159265358979323846 * 2.0 );
		}

		while(rot.z > ( 3.14159265358979323846 * 2.0 ))
		{
			rot.z -= ( float ) ( 3.14159265358979323846 * 2.0 );
		}

	}
}