#include "Root.h"
#include "Object.h"

void Root::start()
{
	while(true)
	{
		for(auto it = objects.begin(); it != objects.end(); it++)
		{
			( *it )->tick();
		}
	}
}

void Root::finish()
{ }

std::shared_ptr<Object> Root::addObject()
{
	std::shared_ptr<Object> rtn = std::make_shared<Object>();
	objects.push_back( rtn );
	return rtn;
}

std::shared_ptr<Root> Root::load()
{
	return 0;
}

std::shared_ptr<Domain> Root::domain()
{
	return 0;
}

std::shared_ptr<Keyboard> Root::keyboard()
{
	return 0;
}

bool Root::active()
{
	return 0;
}