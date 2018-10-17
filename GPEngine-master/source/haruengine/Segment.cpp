#include "Segment.h"
#include "Object.h"

namespace haru
{
	Segment::~Segment()
	{
	}

	void Segment::onInit()
	{
	}

	void Segment::onBegin()
	{
	}

	void Segment::onTick()
	{
	}

	void Segment::onDisplay()
	{
	}

	std::shared_ptr<Object> Segment::getObject()
	{
		return object.lock();
	}

	std::shared_ptr<Root> Segment::getRoot()
	{
		return getObject()->getRoot();
	}

	std::shared_ptr<Keyboard> Segment::getKeyboard()
	{
		return 0;
	}

	std::shared_ptr<Domain> Segment::getDomain()
	{
		return 0;
	}

}