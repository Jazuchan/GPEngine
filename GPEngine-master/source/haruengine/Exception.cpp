#include "Exception.h"
#include <iostream>

namespace haru
{
	Exception::Exception(std::string _message)
	{
		_message = "Exception thrown";
	}

	Exception::~Exception() throw()
	{
		throw std::exception();
	}

	//const char Exception::*m_what()
	//{
	//	
	//}
} 