#include <memory>
#include <vector>

class Segment;
class Root;

class Object
{
public:
	std::shared_ptr<Root> getRoot();
	void tick();

	template <typename T>
	std::shared_ptr<T> addSegment()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		segments.push_back( rtn );
		return rtn;
	}

	//template <typename T, typename A>
	//std::shared_ptr<T> addSegment( a:A )
	//{

	//}

	//template <typename T, typename A, typename B>
	//std::shared_ptr<T> addSegment<T, A, B>(a:A, b:B)
	//{

	//}

	//template <typename T, typename A, typename B, typename C>
	//std::shared_ptr<T> addSegment<T, A, B, C>( a:A, b:B, c:C )
	//{

	//}


private:
	void display();
	std::vector<std::shared_ptr<Segment>> segments;
	std::weak_ptr<Root> root;
};
