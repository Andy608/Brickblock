#include "KeySetting.h"
#include "../../../util/filesystem/StringUtil.h"
#include "../../../util/logger/BBLogger.h"
using namespace bb;

const std::string KeySetting::CLASS_NAME = "KeySetting.cpp";

KeySetting::KeySetting(std::string settingName, const std::set<GLuint> DEFAULT_KEYS) :
	SettingBase(settingName),
	mDEFAULT_KEYS(DEFAULT_KEYS),
	mPressed(GL_FALSE),
	mNewPress(GL_FALSE)
{
	if (DEFAULT_KEYS.size() == 0)
	{
		std::string err = "Default keys cannot be empty or null.";
		BBLogger::logError(CLASS_NAME, err);
		throw std::invalid_argument(CLASS_NAME + ": " + err);
	}

	setCustomKeyBinding(mDEFAULT_KEYS);

	BBLogger::logTrace(CLASS_NAME, "Creating KeySetting: " + toReadableString());
}

KeySetting::~KeySetting()
{
	BBLogger::logTrace(CLASS_NAME, "Deleting KeySetting: " + toReadableString());
}

std::string KeySetting::toReadableString() const
{
	std::string s = mSettingName + " Default KeyBinding: ";
	
	if (mDEFAULT_KEYS.size() > 0)
	{
		s += std::to_string(*mDEFAULT_KEYS.begin());
	}

	std::set<GLuint>::iterator it;

	for (it = ++mDEFAULT_KEYS.begin(); it != mDEFAULT_KEYS.end(); ++it)
	{
		s += ", " + std::to_string(*it);
	}

	s += " Custom KeyBinding: ";
	
	if (mCustomKeys.size() > 0)
	{
		s += std::to_string(*mCustomKeys.begin());
	}

	for (it = ++mCustomKeys.begin(); it != mCustomKeys.end(); ++it)
	{
		s += ", " + std::to_string(*it);
	}

	return s;
}

void KeySetting::setPressed(GLboolean isPressed)
{
	mPressed = isPressed;
}

const GLboolean& KeySetting::isPressed() const
{
	return mPressed;
}

void KeySetting::setNewPress(GLboolean isNewPress)
{
	mNewPress = isNewPress;
}

const GLboolean& KeySetting::isNewPress() const
{
	return mNewPress;
}

void KeySetting::setCustomKeyBinding(const std::set<GLuint> &customKeys)
{
	if (customKeys.empty())
	{
		BBLogger::logError(CLASS_NAME, "Custom keys cannot be empty or null. Resetting keys.");
		resetCustomValue();
		return;
	}

	mCustomKeys = std::set<GLuint>();

	std::set<GLuint>::iterator it;
	for (it = customKeys.begin(); it != customKeys.end(); ++it)
	{
		mCustomKeys.insert(*it);
	}
}

void KeySetting::setCustomKeyBinding(const std::vector<std::string> &customKeys)
{
	try
	{
		std::set<GLuint> keys;
		
		GLuint i;
		for (i = 0; i < customKeys.size(); ++i)
		{
			keys.insert(std::stoi(customKeys[i]));
		}

		setCustomKeyBinding(keys);
		return;
	}
	catch(const std::invalid_argument e)
	{
		BBLogger::logWarn(CLASS_NAME, "Could not convert \'" + StringUtil::vectorToString(customKeys) + "\' to integer. Invalid argument. Returning default value.");
	}
	catch (const std::out_of_range e)
	{
		BBLogger::logWarn(CLASS_NAME, "Could not convert \'" + StringUtil::vectorToString(customKeys) + "\' to integer. Out of range. Returning default value.");
	}
	catch (...)
	{
		BBLogger::logWarn(CLASS_NAME, "Could not convert \'" + StringUtil::vectorToString(customKeys) + "\' to integer. Returning default value.");
	}

	setCustomKeyBinding(mDEFAULT_KEYS);
}

void KeySetting::resetCustomValue()
{
	setCustomKeyBinding(mDEFAULT_KEYS);
}

const std::set<GLuint>& KeySetting::getDefaultKeyBinding() const
{
	return mDEFAULT_KEYS;
}

const std::set<GLuint>& KeySetting::getCustomKeyBinding() const
{
	return mCustomKeys;
}

const GLuint KeySetting::getDefaultBindingLength() const
{
	return mDEFAULT_KEYS.size();
}

const GLuint KeySetting::getCustomBindingLength() const
{
	return mCustomKeys.size();
}

std::string KeySetting::toFileString() const
{
	std::string s = mSettingName + FILE_DELIMITER + std::to_string(*mCustomKeys.begin());
	
	std::set<GLuint>::iterator it;
	for (it = ++mCustomKeys.begin(); it != mCustomKeys.end(); ++it)
	{
		s += "," + std::to_string(*it);
	}
	
	return s;
}

GLboolean KeySetting::isModified() const
{
	GLboolean modified = GL_FALSE;

	if (mDEFAULT_KEYS.size() != mCustomKeys.size())
	{
		modified = GL_TRUE;
	}
	else
	{
		std::set<GLuint>::iterator defaultIter, customIter;
		for (defaultIter = mDEFAULT_KEYS.begin(), customIter = mCustomKeys.begin(); 
			defaultIter != mDEFAULT_KEYS.end(); ++defaultIter, ++customIter)
		{
			if (*defaultIter != *customIter)
			{
				modified = GL_TRUE;
				break;
			}
		}
	}

	return modified;
}