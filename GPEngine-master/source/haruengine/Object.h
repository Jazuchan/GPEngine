#include "Segment.h"
#include <memory>
#include <vector>

#define ADDSEGMENT \
  std::shared_ptr<T> rtn = std::make_shared<T>(); \
  rtn->object = self; \
  rtn->began = false; \
  segments.push_back(rtn);

namespace haru
{
	class Root;

	class Object
	{
		friend class Root;

	public:
		
		template <typename T>
		std::shared_ptr<T> getSegment()
		{
			for(size_t i = 0; i < segments.size(); i++)
			{
				std::shared_ptr<T> tst = std::dynamic_pointer_cast< T >( segments.at( i ) );
				if(tst)
				{
					return tst;
				}
			}
			throw std::exception();
		}

		template <typename T>
		std::shared_ptr<T> addSegment()
		{
			ADDSEGMENT
				rtn->onInit();

			return rtn;
		}

		template <typename T, typename A>
		std::shared_ptr<T> addSegment( A a )
		{
			ADDSEGMENT
				rtn->onInit( a );

			return rtn;
		}

		template <typename T, typename A, typename B>
		std::shared_ptr<T> addSegment(A a, B b)
		{
			ADDSEGMENT
				rtn->onInit( a, b );

			return rtn;
		}

		template <typename T, typename A, typename B, typename C>
		std::shared_ptr<T> addSegment( A a, B b, C c )
		{
			ADDSEGMENT
				rtn->onInit( a, b,  );

			return rtn;
		}

		std::shared_ptr<Root> getRoot();

	private:
		std::vector<std::shared_ptr<Segment>> segments;
		std::weak_ptr<Root> root;
		std::weak_ptr<Object> self;
		void tick();
		void display();
	};
}