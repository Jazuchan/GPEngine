#include "Object.h"

namespace haru
{
	void Object::Tick()
	{
		for( std::vector<std::shared_ptr<Segment> >::iterator it = m_segments.begin();
		it != m_segments.end(); it++ )
		{
			if(!( *it )->m_began)
			{
				( *it )->OnBegin();
				( *it )->m_began = true;
			}

			try
			{
				( *it )->OnTick();
			}
			catch(...){}
		}
	}

	std::shared_ptr<Root> Object::GetRoot()
	{
		return m_root.lock();
	}

	void Object::Display()
	{
		for(std::vector<std::shared_ptr<Segment> >::iterator it = m_segments.begin();
			it != m_segments.end(); it++)
		{
			( *it )->OnDisplay();
		}
	}

	
}