#ifndef BB_STRINGUTIL_H_
#define BB_STRINGUTIL_H_

#include <string>
#include <vector>
#include <set>
#include <glad/glad.h>

namespace bb
{
	struct StringUtil
	{
		static std::string wtos(const std::wstring& wstr);
		static std::wstring stow(const std::string& str);

		static void StringUtil::split(const char* str, char delimiter, bool addDoubleDimiliterSpace, std::vector<std::string>& result);
		static std::vector<std::string> StringUtil::split(const char* str, char delimiter, bool addDoubleDimiliterSpace = GL_FALSE);

		static std::string arrayToString(const std::string *array, GLuint size);
		static std::string vectorToString(const std::vector<std::string> &array);

		template <typename T>
		static std::string setToString(const std::set<T> &set)
		{
			std::string str;

			if (set.empty())
			{
				BBLogger::logWarn("StringUtil.cpp", "The set is empty. Return empty string.");
				str = "";
			}
			else
			{
				str = std::to_string(*set.begin());

				std::set<T>::iterator it;

				for (it = ++set.begin(); it != set.end(); ++it)
				{
					str += " " + std::to_string(*it);
				}
			}

			return str;
		}

		template <typename T>
		static std::string arrayToString(const T *array, GLuint size)
		{
			std::string str;

			if (!array || size == 0)
			{
				BBLogger::logWarn("StringUtil.cpp", "The array is null or empty. Return empty string.");
				str = "";
			}
			else
			{
				str = std::to_string(array[0]);

				GLuint i;
				for (i = 1; i < size; ++i)
				{
					str += " " + std::to_string(array[i]);
				}
			}

			return str;
		}
	};
}

#endif