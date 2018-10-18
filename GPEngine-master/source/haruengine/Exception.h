#include <exception>
#include <string>
#include <Windows.h>

namespace haru
{

	class Exception : public std::exception
	{
	public:
		Exception(std::string message);
		~Exception() throw();

		const char *what() const noexcept { return message.c_str(); }
		
	private:
		std::string message;

	};
}