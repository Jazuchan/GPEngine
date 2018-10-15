#include "Segment.h"

Segment::~Segment()
{
}

void Segment::onTick()
{
}

std::shared_ptr<Object> Segment::getObject()
{
	return 0;
}

std::shared_ptr<Root> Segment::getRoot()
{
	return 0;
}

std::shared_ptr<Keyboard> Segment::getKeyboard()
{
	return 0;
}

std::shared_ptr<Domain> Segment::getDomain()
{
	return 0;
}

void Segment::onInit()
{
}

void Segment::onBegin()
{
}

void Segment::onDisplay()
{
}