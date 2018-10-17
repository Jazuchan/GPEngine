#ifndef HARUENGINE_SEGMENT_H
#define HARUENGINE_SEGMENT_H

#include <memory>

namespace haru
{
	class Object;
	class Root;
	class Domain;
	class Keyboard;

	class Segment
	{
		friend class Object;

	public:
		virtual ~Segment();

		std::shared_ptr<Object> getObject();
		std::shared_ptr<Root> getRoot();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Domain> getDomain();

	private:
		std::weak_ptr<Object> object;
		bool began;

		virtual void onTick();
		virtual void onInit();
		virtual void onBegin();
		virtual void onDisplay();
	};
}
#endif