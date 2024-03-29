#ifndef BB_DIRECTORYLOCATION_H_
#define BB_DIRECTORYLOCATION_H_

#include <glad\glad.h>
#include <string>

namespace bb
{
	class DirectoryLocation
	{
	public:

		enum EnumPathType : GLint
		{
			ABSOLUTE_PATH,
			RELATIVE_PATH
		};

		DirectoryLocation(std::string parentPath, std::string directoryName, const EnumPathType& PATH_TYPE);
		~DirectoryLocation();

		std::string getPath() const;
		std::string getParentPath() const;
		std::string getDirectoryName() const;

		GLboolean isPathRelative() const;
		GLboolean isDirectoryCreated() const;
		GLboolean createDirectory();

		operator std::string() const;

	private:
		const std::string mPARENT_PATH;
		const std::string mDIRECTORY_NAME;
		const GLboolean mIS_PATH_RELATIVE;
		GLboolean mIsCreated;
	};
}

#endif