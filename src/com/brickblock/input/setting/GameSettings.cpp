#include "GameSettings.h"
#include "key/KeySetting.h"
#include <GLFW/glfw3.h>
#include "../../util/filesystem/file/FileLocation.h"
#include "../../util/logger/BBLogger.h"
#include "../../util/filesystem/file/reader/StringFileReader.h"
#include "../../util/filesystem/file/writer/StringFileWriter.h"
#include "../../util/filesystem/StringUtil.h"
#include <vector>
using namespace bb;

GameSettings* GameSettings::instance = nullptr;
std::string GameSettings::CLASS_NAME = "GameSettings.cpp";
const GLuint GameSettings::MAX_KEYS_PRESSED = 6;

GameSettings* GameSettings::init()
{
	if (!instance)
	{
		instance = new GameSettings();
		return instance;
	}

	BBLogger::logWarn(CLASS_NAME, "GameSettings is already initialized. Returning null.");
	return nullptr;
}

GameSettings& GameSettings::getInstance()
{
	return *instance;
}

GameSettings::GameSettings()
try :
	mSettingsLocation(new FileLocation(*DirectoryList::getInstance().mRootDirectory, "settings", FileLocation::TXT_EXT))
{
	std::set<GLuint> keySetHelper;
	
	keySetHelper.insert(GLFW_KEY_ESCAPE);
	mWindowCloseKey = new KeySetting("window_close", keySetHelper);
	keySetHelper.clear();

	keySetHelper.insert(GLFW_KEY_W);
	mMoveForwardKey = new KeySetting("move_forward", keySetHelper);
	keySetHelper.clear();
	
	keySetHelper.insert(GLFW_KEY_S);
	mMoveBackwardKey = new KeySetting("move_backward", keySetHelper);
	keySetHelper.clear();
	
	keySetHelper.insert(GLFW_KEY_A);
	mMoveLeftKey = new KeySetting("move_left", keySetHelper);
	keySetHelper.clear();
	
	keySetHelper.insert(GLFW_KEY_D);
	mMoveRightKey = new KeySetting("move_right", keySetHelper);
	keySetHelper.clear();

	keySetHelper.insert(GLFW_KEY_Q);
	mRotateLeftKey = new KeySetting("rotate_left", keySetHelper);
	keySetHelper.clear();

	keySetHelper.insert(GLFW_KEY_E);
	mRotateRightKey = new KeySetting("rotate_right", keySetHelper);
	keySetHelper.clear();

	if (mSettingsLocation->isExist())
	{
		BBLogger::logTrace(CLASS_NAME, "Game Settings file exists: " + mSettingsLocation->getPath());
	}
	else if (mSettingsLocation->createFile())
	{
		BBLogger::logTrace(CLASS_NAME, "Successfully created Game Settings file at: " + mSettingsLocation->getPath());
	}
	else
	{
		std::string err = "Unable to create Game Settings file at: " + mSettingsLocation->getPath();
		throw std::invalid_argument(err);
	}

	loadSettingsFromFile();
}
catch (std::invalid_argument e)
{
	BBLogger::logError(CLASS_NAME, e.what());
}

GameSettings::~GameSettings()
{
	saveSettingsToFile();
	delete mSettingsLocation;

	delete mWindowCloseKey;

	delete mMoveForwardKey;
	delete mMoveBackwardKey;
	delete mMoveLeftKey;
	delete mMoveRightKey;

	delete mRotateLeftKey;
	delete mRotateRightKey;
}

void GameSettings::saveSettingsToFile()
{
	std::vector<std::string> gameSettings;

	gameSettings.push_back(mWindowCloseKey->toFileString());

	gameSettings.push_back(mMoveForwardKey->toFileString());
	gameSettings.push_back(mMoveBackwardKey->toFileString());
	gameSettings.push_back(mMoveLeftKey->toFileString());
	gameSettings.push_back(mMoveRightKey->toFileString());

	gameSettings.push_back(mRotateLeftKey->toFileString());
	gameSettings.push_back(mRotateRightKey->toFileString());

	StringFileWriter::getInstance().writeLinesInFile(*mSettingsLocation, gameSettings);
}

void GameSettings::loadSettingsFromFile()
{
	if (mSettingsLocation->isExist())
	{
		std::vector<std::string> fileLines;
		StringFileReader::getInstance().getContentsByLine(*mSettingsLocation, fileLines);

		std::string currentLine;
		std::string settingName;
		std::string settingAttrib;

		GLuint i;
		GLuint j;
		for (i = 0; i < fileLines.size(); ++i)
		{
			currentLine = fileLines.at(i);
			for (j = 0; j < currentLine.size(); ++j)
			{
				if (currentLine.at(j) == SettingBase::FILE_DELIMITER)
				{
					settingName = currentLine.substr(0, j);
					settingAttrib = currentLine.substr(j + 1);

					if (settingName.compare(mWindowCloseKey->getSettingName()) == 0)
					{
						mWindowCloseKey->setCustomKeyBinding(StringUtil::split(settingAttrib.c_str(), SettingBase::FILE_DELIMITER));
					}
					else if (settingName.compare(mMoveForwardKey->getSettingName()) == 0)
					{
						mMoveForwardKey->setCustomKeyBinding(StringUtil::split(settingAttrib.c_str(), SettingBase::FILE_DELIMITER));
					}
					else if (settingName.compare(mMoveBackwardKey->getSettingName()) == 0)
					{
						mMoveBackwardKey->setCustomKeyBinding(StringUtil::split(settingAttrib.c_str(), SettingBase::FILE_DELIMITER));
					}
					else if (settingName.compare(mMoveLeftKey->getSettingName()) == 0)
					{
						mMoveLeftKey->setCustomKeyBinding(StringUtil::split(settingAttrib.c_str(), SettingBase::FILE_DELIMITER));
					}
					else if (settingName.compare(mMoveRightKey->getSettingName()) == 0)
					{
						mMoveRightKey->setCustomKeyBinding(StringUtil::split(settingAttrib.c_str(), SettingBase::FILE_DELIMITER));
					}
					else if (settingName.compare(mRotateLeftKey->getSettingName()) == 0)
					{
						mRotateLeftKey->setCustomKeyBinding(StringUtil::split(settingAttrib.c_str(), SettingBase::FILE_DELIMITER));
					}
					else if (settingName.compare(mRotateRightKey->getSettingName()) == 0)
					{
						mRotateRightKey->setCustomKeyBinding(StringUtil::split(settingAttrib.c_str(), SettingBase::FILE_DELIMITER));
					}
					else
					{
						BBLogger::logWarn(CLASS_NAME, "Skipping unknown setting: \'" + currentLine + "\'");
					}
				}
			}
		}
	}
}

void GameSettings::setKeyPressed(GLuint keyCode)
{
	addKeyPressed(keyCode);

	if (isKeyBindingPressed(mWindowCloseKey->getCustomKeyBinding()))
	{
		mWindowCloseKey->setNewPress(GL_TRUE);
		mWindowCloseKey->setPressed(GL_TRUE);
	}
	
	if (isKeyBindingPressed(mMoveForwardKey->getCustomKeyBinding()))
	{
		mMoveForwardKey->setNewPress(GL_TRUE);
		mMoveForwardKey->setPressed(GL_TRUE);
	}
	
	if (isKeyBindingPressed(mMoveBackwardKey->getCustomKeyBinding()))
	{
		mMoveBackwardKey->setNewPress(GL_TRUE);
		mMoveBackwardKey->setPressed(GL_TRUE);
	}
	
	if (isKeyBindingPressed(mMoveLeftKey->getCustomKeyBinding()))
	{
		mMoveLeftKey->setNewPress(GL_TRUE);
		mMoveLeftKey->setPressed(GL_TRUE);
	}
	
	if (isKeyBindingPressed(mMoveRightKey->getCustomKeyBinding()))
	{
		mMoveRightKey->setNewPress(GL_TRUE);
		mMoveRightKey->setPressed(GL_TRUE);
	}

	if (isKeyBindingPressed(mRotateLeftKey->getCustomKeyBinding()))
	{
		mRotateLeftKey->setNewPress(GL_TRUE);
		mRotateLeftKey->setPressed(GL_TRUE);
	}

	if (isKeyBindingPressed(mRotateRightKey->getCustomKeyBinding()))
	{
		mRotateRightKey->setNewPress(GL_TRUE);
		mRotateRightKey->setPressed(GL_TRUE);
	}
}

void GameSettings::setKeyReleased(GLuint keyCode)
{
	removeKeyPressed(keyCode);

	if (!isKeyBindingPressed(mWindowCloseKey->getCustomKeyBinding()))
	{
		mWindowCloseKey->setPressed(GL_FALSE);
	}
	
	if (!isKeyBindingPressed(mMoveForwardKey->getCustomKeyBinding()))
	{
		mMoveForwardKey->setPressed(GL_FALSE);
	}
	
	if (!isKeyBindingPressed(mMoveBackwardKey->getCustomKeyBinding()))
	{
		mMoveBackwardKey->setPressed(GL_FALSE);
	}
	
	if (!isKeyBindingPressed(mMoveLeftKey->getCustomKeyBinding()))
	{
		mMoveLeftKey->setPressed(GL_FALSE);
	}
	
	if (!isKeyBindingPressed(mMoveRightKey->getCustomKeyBinding()))
	{
		mMoveRightKey->setPressed(GL_FALSE);
	}

	if (!isKeyBindingPressed(mRotateLeftKey->getCustomKeyBinding()))
	{
		mRotateLeftKey->setPressed(GL_FALSE);
	}

	if (!isKeyBindingPressed(mRotateRightKey->getCustomKeyBinding()))
	{
		mRotateRightKey->setPressed(GL_FALSE);
	}
}

void GameSettings::update()
{
	if (mWindowCloseKey->isNewPress())
	{
		mWindowCloseKey->setNewPress(GL_FALSE);
	}
	else if (mMoveForwardKey->isNewPress())
	{
		mMoveForwardKey->setNewPress(GL_FALSE);
	}
	else if (mMoveBackwardKey->isNewPress())
	{
		mMoveBackwardKey->setNewPress(GL_FALSE);
	}
	else if (mMoveLeftKey->isNewPress())
	{
		mMoveLeftKey->setNewPress(GL_FALSE);
	}
	else if (mMoveRightKey->isNewPress())
	{
		mMoveRightKey->setNewPress(GL_FALSE);
	}
	else if (mRotateLeftKey->isNewPress())
	{
		mRotateLeftKey->setNewPress(GL_FALSE);
	}
	else if (mRotateRightKey->isNewPress())
	{
		mRotateRightKey->setNewPress(GL_FALSE);
	}
}

GLboolean GameSettings::isKeyBindingPressed(std::set<GLuint> keyBinding) const
{
	std::set<GLuint>::iterator keyBindingIter;
	std::set<GLuint>::iterator activeKeysIter;

	GLuint count = 0;
	GLuint targetCount = keyBinding.size();

	for (activeKeysIter = mPressedKeyCodes.begin(); activeKeysIter != mPressedKeyCodes.end(); ++activeKeysIter)
	{
		for (keyBindingIter = keyBinding.begin(); keyBindingIter != keyBinding.end(); ++keyBindingIter)
		{
			if (*keyBindingIter == *activeKeysIter)
			{
				++count;
				break;
			}
		}
	}

	return (count == targetCount);
}

void GameSettings::addKeyPressed(GLuint asciiValue)
{
	if (mPressedKeyCodes.size() < MAX_KEYS_PRESSED)
	{
		mPressedKeyCodes.insert(asciiValue);
		BBLogger::logTrace(CLASS_NAME, "Added key: " + std::to_string(asciiValue));
		printPressedKeys();
	}
}

void GameSettings::removeKeyPressed(GLuint asciiValue)
{
	mPressedKeyCodes.erase(asciiValue);
	BBLogger::logTrace(CLASS_NAME, "Removed key: " + std::to_string(asciiValue));
	printPressedKeys();
}

void GameSettings::printPressedKeys() const
{
	std::string keyList = "Active Keys: ";
	std::set<GLuint>::iterator it;

	if (mPressedKeyCodes.size() > 0)
	{
		keyList = std::to_string(*mPressedKeyCodes.begin());

		for (it = ++mPressedKeyCodes.begin(); it != mPressedKeyCodes.end(); ++it)
		{
			keyList += ", " + std::to_string(*it);
		}
	}

	BBLogger::logTrace(CLASS_NAME, keyList);
}