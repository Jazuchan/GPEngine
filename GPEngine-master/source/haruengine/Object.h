#include "Segment.h"
#include <memory>
#include <vector>

#define ADDSEGMENT \
  std::shared_ptr<T> m_rtn = std::make_shared<T>(); \
m_rtn->m_object = m_self; \
  m_rtn->m_began = false; \
  m_segments.push_back(m_rtn);

namespace haru
{
	class Root;

	class Object
	{
		friend class Root;

	public:
		
		template <typename T>
		std::shared_ptr<T> GetSegment()
		{
			for(size_t i = 0; i < m_segments.size(); i++)
			{
				std::shared_ptr<T> m_tst = std::dynamic_pointer_cast< T >( m_segments.at( i ) );
				if(m_tst)
				{
					return m_tst;
				}
			}
			throw std::exception();
		}

		template <typename T>
		std::shared_ptr<T> AddSegment()
		{
			ADDSEGMENT
				m_rtn->OnInit();

			return m_rtn;
		}

		template <typename T, typename A>
		std::shared_ptr<T> AddSegment( A a )
		{
			ADDSEGMENT
				m_rtn->OnInit( a );

			return m_rtn;
		}

		template <typename T, typename A, typename B>
		std::shared_ptr<T> AddSegment(A a, B b)
		{
			ADDSEGMENT
				m_rtn->OnInit( a, b );

			return m_rtn;
		}

		template <typename T, typename A, typename B, typename C>
		std::shared_ptr<T> AddSegment( A a, B b, C c )
		{
			ADDSEGMENT
				m_rtn->OnInit( a, b, c);

			return m_rtn;
		}

		std::shared_ptr<Root> GetRoot();

	private:
		std::vector<std::shared_ptr<Segment>> m_segments;
		std::weak_ptr<Root> m_root;
		std::weak_ptr<Object> m_self;
		void Tick();
		void Display();
	};
}