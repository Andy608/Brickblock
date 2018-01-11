#include "StringUtil.h"
#include "../logger/BBLogger.h"
using namespace bb;

std::string StringUtil::wtos(const std::wstring& wstr)
{
	return std::string(wstr.begin(), wstr.end());
}

std::wstring StringUtil::stow(const std::string& str)
{
	return std::wstring(str.begin(), str.end());
}

void StringUtil::split(const char* str, char delimiter, bool addDoubleDimiliterSpace, std::vector<std::string>& result)
{
	std::string s;

	if (addDoubleDimiliterSpace)
	{
		do
		{
			const char *beginIndex = str;

			while (*str != delimiter && *str)
			{
				++str;
			}

			s = std::string(beginIndex, str);

			if (s.empty())
			{
				s = " ";
			}

			result.push_back(s);

		} while (0 != *str++);
	}
	else
	{
		do
		{
			const char *beginIndex = str;

			while (*str != delimiter && *str)
			{
				++str;
			}

			s = std::string(beginIndex, str);
			if (!s.empty())
			{
				result.push_back(s);
			}

		} while (0 != *str++);
	}
}

std::vector<std::string> StringUtil::split(const char* str, char delimiter, bool addDoubleDimiliterSpace)
{
	std::vector<std::string> result;
	std::string s;

	if (addDoubleDimiliterSpace)
	{
		do
		{
			const char *beginIndex = str;

			while (*str != delimiter && *str)
			{
				++str;
			}

			s = std::string(beginIndex, str);

			if (s.empty())
			{
				s = " ";
			}

			result.push_back(s);

		} while (0 != *str++);
	}
	else
	{
		do
		{
			const char *beginIndex = str;

			while (*str != delimiter && *str)
			{
				++str;
			}

			s = std::string(beginIndex, str);
			if (!s.empty())
			{
				result.push_back(s);
			}

		} while (0 != *str++);
	}

	return result;
}

std::string StringUtil::arrayToString(const std::string *array, GLuint size)
{
	std::string str;

	if (!array || size == 0)
	{
		BBLogger::logWarn("StringUtil.cpp", "The string array is null or empty. Return empty string.");
		str = "";
	}
	else
	{
		str = array[0];

		GLuint i;
		for (i = 1; i < size; ++i)
		{
			str += " " + array[i];
		}
	}

	return str;
}

std::string StringUtil::vectorToString(const std::vector<std::string> &array)
{
	std::string str;

	if (array.empty())
	{
		BBLogger::logWarn("StringUtil.cpp", "The string vector is empty. Return empty string.");
		str = "";
	}
	else
	{
		str = array[0];

		GLuint i;
		for (i = 1; i < array.size(); ++i)
		{
			str += " " + array[i];
		}
	}

	return str;
}