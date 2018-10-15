#include "Object.h"
#include "Segment.h"

void Object::tick()
{
	for(auto it = segments.begin(); it != segments.end(); it++)
	{
		( *it )->onTick();
	}
}

std::shared_ptr<Root> Object::getRoot()
{
	return 0;
}

void Object::display()
{ }