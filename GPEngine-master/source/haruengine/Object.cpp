#include "Object.h"

namespace haru
{
	void Object::tick()
	{
		for( std::vector<std::shared_ptr<Segment> >::iterator it = segments.begin();
		it != segments.end(); it++ )
		{
			if(!( *it )->began)
			{
				( *it )->onBegin();
				( *it )->began = true;
			}

			( *it )->onTick();
		}
	}

	std::shared_ptr<Root> Object::getRoot()
	{
		return 0;
	}

	void Object::display()
	{
		for(std::vector<std::shared_ptr<Segment> >::iterator it = segments.begin();
			it != segments.end(); it++)
		{
			( *it )->onDisplay();
		}
	}
}