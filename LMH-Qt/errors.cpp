
#include "errors.h"


namespace Lmh {

	Error::Error(
		const std::string& file,
		long line,
		const std::string& functionName,
		const std::string& reason)
	{
		std::ostringstream msg;
		msg << functionName << ": ";
		msg << "\n " << file << "(" << line << "): \n";
		msg << "Error: " << reason;

		message_ = msg.str();
	}

	const char* Error::what() const noexcept
	{
		return message_.c_str();
	}

}