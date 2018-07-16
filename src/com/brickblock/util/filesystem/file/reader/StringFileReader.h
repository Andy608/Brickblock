#ifndef BB_STRINGFILEREADER_H_
#define BB_STRINGFILEREADER_H_

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

namespace bb
{
	class FileLocation;
	class StringFileReader
	{
	public:
		static StringFileReader& getInstance()
		{
			static StringFileReader instance;
			return instance;
		}

		StringFileReader(StringFileReader const &copy) = delete;
		void operator=(StringFileReader const &copy) = delete;

		void getContents(const FileLocation& FILE, std::string& fileContents);
		void getContentsByLine(const FileLocation& FILE, std::vector<std::string>& fileContents);

	private:
		static const std::string CLASS_NAME;
		std::ifstream *mReadStream;
		std::stringstream *mStringStream;

		StringFileReader();
		~StringFileReader();
	};
}

#endif