#include "StringUtil.h"
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
	if (addDoubleDimiliterSpace)
	{
		do
		{
			const char *beginIndex = str;

			while (*str != delimiter && *str)
			{
				++str;
			}

			std::string s = std::string(beginIndex, str);
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

			std::string s = std::string(beginIndex, str);
			if (!s.empty())
			{
				result.push_back(std::string(beginIndex, str));
			}
		} while (0 != *str++);
	}
}