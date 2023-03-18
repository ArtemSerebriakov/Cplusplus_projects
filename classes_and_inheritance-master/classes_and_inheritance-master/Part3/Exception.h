#pragma once
#include <exception>
#include <iostream>
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
class CastException :public std::exception
{
private:
	std::string m_error;
public:
	CastException(std::string error)
		: m_error(error)
	{
	}
	const char* what() const noexcept { return m_error.c_str(); }
};