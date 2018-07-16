#include "StringFileWriter.h"
#include "../FileLocation.h"
#include "../../../logger/BBLogger.h"
using namespace bb;

const std::string StringFileWriter::CLASS_NAME = "StringFileWriter.cpp";

StringFileWriter::StringFileWriter() :
	mWriteStream(new std::ofstream())
{

}

StringFileWriter::~StringFileWriter()
{
	delete mWriteStream;
}

GLboolean StringFileWriter::writeLinesInFile(const FileLocation& FILE, const std::vector<std::string> &lines)
{
	GLboolean success = GL_FALSE;
	mWriteStream->open(FILE.getPath(), std::fstream::trunc);

	if (mWriteStream->good())
	{
		if (!lines.empty())
		{
			*mWriteStream << lines.at(0);

			GLuint i;
			for (i = 1; i < lines.size(); ++i)
			{
				*mWriteStream << std::endl << lines.at(i);
			}

			success = GL_TRUE;
			BBLogger::logTrace(CLASS_NAME, "Successfuly wrote to file: " + FILE.getPath());
		}
		else
		{
			BBLogger::logTrace(CLASS_NAME, "Lines vector is empty. Not writing anything to file: " + FILE.getPath());
		}
	}
	else
	{
		BBLogger::logTrace(CLASS_NAME, "Failed to open file: " + FILE.getPath());
	}

	mWriteStream->close();
	return success;
}