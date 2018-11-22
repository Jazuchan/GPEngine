#include "Segment.h"
#include "Object.h"
#include "Root.h"

namespace haru
{
	Segment::~Segment()
	{
	}

	void Segment::OnInit()
	{
	}

	void Segment::OnBegin()
	{
	}

	void Segment::OnTick()
	{
	}

	void Segment::OnDisplay()
	{
	}

	std::shared_ptr<Object> Segment::GetObject()
	{
		return m_object.lock();
	}

	std::shared_ptr<Root> Segment::GetRoot()
	{
		return GetObject()->GetRoot();
	}

	std::shared_ptr<Keyboard> Segment::GetKeyboard()
	{
		return 0;
	}

	std::shared_ptr<Domain> Segment::GetDomain()
	{
		return 0;
	}

}