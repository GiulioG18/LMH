
// ========================================================================
//		Errors handler
// ========================================================================

#pragma once

#include <exception>
#include <sstream>
#include <string>
#include <boost/current_function.hpp>


#define MULTILINE_FAILURE_BEGIN do {
// Disable warning C4127 (conditional expression is constant)
#define MULTILINE_FAILURE_END \
        __pragma(warning(push)) \
        __pragma(warning(disable:4127)) \
        } while(false) \
        __pragma(warning(pop))

#define MULTILINE_ASSERTION_BEGIN do {
// Disable warning C4127 (conditional expression is constant)
#define MULTILINE_ASSERTION_END \
        __pragma(warning(push)) \
        __pragma(warning(disable:4127)) \
        } while(false) \
        __pragma(warning(pop))





// FAIL, ASSERT, REQUIRE, ENSURE:

// Throw an error (possibly with file and line information)
#define FAIL(message) \
MULTILINE_FAILURE_BEGIN \
    std::ostringstream msg_stream; \
    msg_stream << message; \
    throw Lmh::Error(__FILE__, __LINE__, BOOST_CURRENT_FUNCTION, msg_stream.str()); \
MULTILINE_FAILURE_END

// Throw an error if the given condition is not verified (General validation)
#define ASSERT(condition, message) \
MULTILINE_ASSERTION_BEGIN \
if (!(condition)) { \
    std::ostringstream msg_stream; \
    msg_stream << message; \
    throw Lmh::Error(__FILE__, __LINE__, BOOST_CURRENT_FUNCTION, msg_stream.str()); \
} \
MULTILINE_ASSERTION_END

//Throw an error if the given pre-condition is not verified (Input validation)
#define REQUIRE(condition, message) \
MULTILINE_ASSERTION_BEGIN \
if (!(condition)) { \
    std::ostringstream msg_stream; \
    msg_stream << message; \
    throw Lmh::Error(__FILE__, __LINE__, BOOST_CURRENT_FUNCTION, msg_stream.str()); \
} \
MULTILINE_ASSERTION_END

// Throw an error if the given post-condition is not verified (Output validation)
#define ENSURE(condition, message) \
MULTILINE_ASSERTION_BEGIN \
if (!(condition)) { \
    std::ostringstream msg_stream; \
    msg_stream << message; \
    throw Lmh::Error(__FILE__, __LINE__, BOOST_CURRENT_FUNCTION, msg_stream.str()); \
} \
MULTILINE_ASSERTION_END


namespace Lmh {

	class Error : public std::exception
	{
	public:
        Error(
			const std::string& file,
			long line,
			const std::string& functionName,
			const std::string& reason);

		const char* what() const noexcept override;

	private:
		std::string message_;
	};
}