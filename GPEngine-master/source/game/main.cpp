#include <haruengine/haru.h>

#include <iostream>

int main()
{
	std::shared_ptr<haru::Root> m_r = haru::Root::Load();
	std::shared_ptr<haru::Object> m_o = m_r->AddObject();

	std::shared_ptr<haru::Audio> m_a = std::make_shared<haru::Audio>("../resources/audio/shootingStar.ogg");
	m_a->Play();

	std::shared_ptr<haru::MeshRenderer> m_mr = m_o->AddSegment<haru::MeshRenderer>();
	std::shared_ptr<haru::MeshRenderer> m_mr2 = m_o->AddSegment<haru::MeshRenderer>();

	try
	{
		m_r->Start();
	}
	catch (haru::Exception& m_e)
	{
		std::cout << "Haru Engine Exception: " << m_e.what() << std::endl;
	}
	catch (std::exception& m_e)
	{
		std::cout << "Exception: " << m_e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "An unknown object was thrown" << std::endl;
	}

	return 0;
}
