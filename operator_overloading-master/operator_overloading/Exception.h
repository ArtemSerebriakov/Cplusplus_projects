#include <exception>
#include <string>
class OutOfRangeException :public std::exception
{
private:
	std::string m_error;

public:
	OutOfRangeException(std::string error)
		: m_error(error)
	{
	}
	const char* what() const noexcept { return m_error.c_str(); }
};
class IncompetibleDimException :public std::exception
{
private:
	std::string m_error;

public:
	IncompetibleDimException(std::string error)
		: m_error(error)
	{
	}
	const char* what() const noexcept { return m_error.c_str(); }
};