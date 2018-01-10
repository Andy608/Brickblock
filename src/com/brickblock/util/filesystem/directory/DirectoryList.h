#ifndef BB_DIRECTORYLIST_H
#define BB_DIRECTORYLIST_H

namespace bb
{
	class DirectoryLocation;
	class DirectoryList
	{
	private:
		DirectoryList();
		~DirectoryList();

	public:
		static DirectoryList& getInstance()
		{
			static DirectoryList instance;
			return instance;
		}

		DirectoryList(DirectoryList const& copy) = delete;
		void operator=(DirectoryList const& copy) = delete;

		DirectoryLocation *mRootDirectory;
		DirectoryLocation *mLoggerDirectory;//Should be in appdata

		DirectoryLocation *mAssetDirectory;//Should be in program folder
		DirectoryLocation *mMeshDirectory;//In asset directory
		DirectoryLocation *mBrickMeshDirectory;

		DirectoryLocation *mShaderDirectory;//In asset directory
		DirectoryLocation *mTextureDirectory;//In asset directory

		void init();
	};
}

#endif