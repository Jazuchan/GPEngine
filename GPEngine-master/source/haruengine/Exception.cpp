#include "Exception.h"
#include <iostream>

namespace haru
{
	Exception::Exception(std::string message)
	{
		message = "Exception thrown";
	}

	Exception::~Exception() throw()
	{
		//throw std::exception();
	}

	//const char Exception::*what()
	//{
	//	
	//}
}