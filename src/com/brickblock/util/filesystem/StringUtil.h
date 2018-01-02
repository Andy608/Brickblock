#ifndef BB_STRINGUTIL_H_
#define BB_STRINGUTIL_H_

#include <string>
#include <vector>

namespace bb
{
	struct StringUtil
	{
		static std::string wtos(const std::wstring& wstr);
		static std::wstring stow(const std::string& str);

		static void StringUtil::split(const char* str, char delimiter, bool addDoubleDimiliterSpace, std::vector<std::string>& result);
	};
}

#endif