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

void StringUtil::split(const char* str, char delimiter, std::vector<std::string>& result)
{
	do
	{
		const char *beginIndex = str;

		while (*str != delimiter && *str)
		{
			++str;
		}

		result.push_back(std::string(beginIndex, str));
	} while (0 != *str++);
}