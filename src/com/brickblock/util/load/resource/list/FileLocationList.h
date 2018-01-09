#ifndef BB_FILELOCATIONLIST_H_
#define BB_FILELOCATIONLIST_H_

namespace bb
{
	class FileLocation;
	struct FileLocationList
	{
	public:
		friend struct FileLocResourcePack;

		static void init();
		static const FileLocationList& getInstance();

		FileLocation &testFileLocation;
		FileLocation &testModelVS;
		FileLocation &testModelFS;
		FileLocation &meshFileLocation;

	private:
		static FileLocationList *instance;
		FileLocationList();
	};
}

#endif