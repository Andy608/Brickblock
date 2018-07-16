#ifndef BB_STRINGFILEWRITER_H_
#define BB_STRINGFILEWRITER_H_

#include <fstream>
#include <string>
#include <vector>
#include <glad/glad.h>

namespace bb
{
	class FileLocation;
	class StringFileWriter
	{
	public:
		static StringFileWriter& getInstance()
		{
			static StringFileWriter instance;
			return instance;
		}

		StringFileWriter(StringFileWriter const &copy) = delete;
		void operator=(StringFileWriter const &copy) = delete;

		GLboolean writeLinesInFile(const FileLocation& FILE, const std::vector<std::string> &lines);

	private:
		static const std::string CLASS_NAME;
		std::ofstream *mWriteStream;

		StringFileWriter();
		~StringFileWriter();
	};
}

#endif