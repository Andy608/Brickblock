#ifndef BB_STRINGUTIL_H_
#define BB_STRINGUTIL_H_

#include <string>

namespace bb
{
	struct StringUtil
	{
		static std::string wtos(const std::wstring& wstr);
		static std::wstring stow(const std::string& str);
	};
}

#endif