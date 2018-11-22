#ifndef HARUENGINE_SEGMENT_H
#define HARUENGINE_SEGMENT_H

#include <memory>
#include <SDL2/SDL.h>

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

		std::shared_ptr<Object> GetObject();
		std::shared_ptr<Root> GetRoot();
		std::shared_ptr<Keyboard> GetKeyboard();
		std::shared_ptr<Domain> GetDomain();

	private:
		std::weak_ptr<Object> m_object;
		bool m_began;
		virtual void OnTick();
		virtual void OnInit();
		virtual void OnBegin();
		virtual void OnDisplay();
	};
}
#endif