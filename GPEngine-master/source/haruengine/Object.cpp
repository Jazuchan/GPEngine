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

			try
			{
				( *it )->onTick();
			}
			catch(...){}
		}
	}

	std::shared_ptr<Root> Object::getRoot()
	{
		return root.lock();
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