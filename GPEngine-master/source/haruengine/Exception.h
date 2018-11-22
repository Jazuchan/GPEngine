#include <exception>
#include <string>
//#include <Windows.h>

namespace haru
{

	class Exception : public std::exception
	{
	public:
		Exception(std::string _message);
		~Exception() throw();

		const char *m_what() const noexcept { return m_message.c_str(); }
		
	private:
		std::string m_message;

	};
}