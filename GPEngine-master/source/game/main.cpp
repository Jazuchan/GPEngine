#include <haruengine/haru.h>

#include <iostream>

class CheckScreen : public haru::Segment
{
public:
	void onInit( std::string color )
	{
		//std::cout << "onInit " << color << std::endl;
	}

	void onBegin()
	{
		//std::cout << "onBegin" << std::endl;
	}

	void onTick()
	{
		//std::cout << "onTick" << std::endl;
	}

	void onDisplay()
	{
		//std::cout << "onTick" << std::endl;
	}
};

int main()
{
	std::shared_ptr<haru::Root> r = haru::Root::load();
	std::shared_ptr<haru::Object> o = r->addObject();

	std::shared_ptr<haru::Audio> a = std::make_shared<haru::Audio>("../shootingStar.ogg");
	a->play();

	std::shared_ptr<CheckScreen> cs = o->addSegment<CheckScreen>( "Green" );
	std::shared_ptr<haru::MeshRenderer> mr = o->addSegment<haru::MeshRenderer>();
	std::shared_ptr<haru::MeshRenderer> mr2 = o->addSegment<haru::MeshRenderer>();

	try
	{
		r->start();
	}
	catch (haru::Exception& e)
	{
		std::cout << "Haru Engine Exception: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "An unknown object was thrown" << std::endl;
	}

	return 0;
}
