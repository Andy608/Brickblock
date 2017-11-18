#ifndef BB_FILELOCATION_H_
#define BB_FILELOCATION_H_

#include <glad\glad.h>
#include <string>

namespace bb
{
	class DirectoryLocation;
	class FileLocation
	{
	public:
		static const std::string TXT_EXT;
		static const std::string PNG_EXT;
		static const std::string OBJ_EXT;
		static const std::string VS_EXT;
		static const std::string FS_EXT;

		FileLocation(const DirectoryLocation& PARENT_DIR, std::string fileName, const std::string& EXT);
		~FileLocation();

		std::string getName() const;
		const std::string& getExt() const;
		std::string getNameAndExt() const;
		std::string getParentPath() const;
		std::string getPath() const;
		const DirectoryLocation& getParentDirectory() const;

		GLboolean isExist() const;
		const GLboolean isCreated() const;
		GLboolean createFile();

	private:
		const std::string mFILE_NAME;
		const std::string mFILE_EXTENSION;
		const DirectoryLocation& mPARENT_DIRECTORY;
		
		GLboolean mIsCreated;
	};
}

#endif