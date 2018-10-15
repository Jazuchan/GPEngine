#pragma once
#ifndef SEGMENT_H
#define SEGMENT_H

#include <memory>

class Object;
class Root;
class Domain;
class Keyboard;

class Segment
{
public:
	virtual ~Segment();
	virtual void onTick();

	std::shared_ptr<Object> getObject();
	std::shared_ptr<Root> getRoot();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Domain> getDomain();

private:
	std::weak_ptr<Object> object;
	void onInit();
	void onBegin();
	void onDisplay();
};
#endif