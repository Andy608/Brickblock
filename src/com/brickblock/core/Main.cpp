#include "Brickblock.h"
#include <iostream>
#include "../util/filesystem/directory/DirectoryLocation.h"
#include "../util/filesystem/file/FileLocation.h"
#include "../util/libs/spdlog/spdlog.h"
#include "../util/filesystem/directory/DirectoryList.h"
#include "../util/logger/BBLogger.h"

#include "../input/setting/numeric/IntegerSetting.h"
#include "../input/setting/key/KeySetting.h"
#include "../util/filesystem/StringUtil.h"
#include <set>
#include <GLFW/glfw3.h>
using namespace bb;

static const std::string CLASS_NAME = "Main.cpp";

int main(int argc, int **argv)
{
	GLint exitResult = EXIT_SUCCESS;
	Brickblock *brickblock = nullptr;
	DirectoryList::getInstance().init();

	/*std::set<GLuint> mTestLolKeys;
	mTestLolKeys.insert(GLFW_KEY_W);
	KeySetting *mTestLol = new KeySetting("KeyTest", mTestLolKeys);
	
	BBLogger::logInfo("KEY TEST", mTestLol->toReadableString());
	BBLogger::logInfo("KEY TEST", mTestLol->toFileString());
	BBLogger::logInfo("KEY TEST", mTestLol->getSettingName());
	BBLogger::logInfo("KEY TEST", StringUtil::setToString(mTestLol->getDefaultKeyBinding()));
	BBLogger::logInfo("KEY TEST", std::to_string(mTestLol->getDefaultBindingLength()));
	BBLogger::logInfo("KEY TEST", StringUtil::setToString(mTestLol->getCustomKeyBinding()));
	BBLogger::logInfo("KEY TEST", std::to_string(mTestLol->getCustomBindingLength()));
	BBLogger::logInfo("KEY TEST", std::to_string(mTestLol->isModified()));

	mTestLolKeys.clear();
	mTestLol->setCustomKeyBinding(mTestLolKeys);

	BBLogger::logInfo("KEY TEST", mTestLol->toReadableString());
	BBLogger::logInfo("KEY TEST", mTestLol->toFileString());
	BBLogger::logInfo("KEY TEST", mTestLol->getSettingName());
	BBLogger::logInfo("KEY TEST", StringUtil::setToString(mTestLol->getDefaultKeyBinding()));
	BBLogger::logInfo("KEY TEST", std::to_string(mTestLol->getDefaultBindingLength()));
	BBLogger::logInfo("KEY TEST", StringUtil::setToString(mTestLol->getCustomKeyBinding()));
	BBLogger::logInfo("KEY TEST", std::to_string(mTestLol->getCustomBindingLength()));
	BBLogger::logInfo("KEY TEST", std::to_string(mTestLol->isModified()));

	mTestLol->resetCustomValue();

	BBLogger::logInfo("KEY TEST", mTestLol->toReadableString());
	BBLogger::logInfo("KEY TEST", mTestLol->toFileString());
	BBLogger::logInfo("KEY TEST", mTestLol->getSettingName());
	BBLogger::logInfo("KEY TEST", StringUtil::setToString(mTestLol->getDefaultKeyBinding()));
	BBLogger::logInfo("KEY TEST", std::to_string(mTestLol->getDefaultBindingLength()));
	BBLogger::logInfo("KEY TEST", StringUtil::setToString(mTestLol->getCustomKeyBinding()));
	BBLogger::logInfo("KEY TEST", std::to_string(mTestLol->getCustomBindingLength()));
	BBLogger::logInfo("KEY TEST", std::to_string(mTestLol->isModified()));

	delete mTestLol;*/

	try
	{
		brickblock = &Brickblock::getInstance();
		brickblock->start(argc, argv);
	}
	catch (std::string e)
	{
		exitResult = EXIT_FAILURE;
	}
	catch (...)
	{
		BBLogger::logCritical(CLASS_NAME, "Well this is awkward... There was a crash that I couldn't recover from.");
	}

	std::cin.get();
	return exitResult;
}