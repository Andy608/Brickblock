#include "IntegerSetting.h"
#include "../../../util/logger/BBLogger.h"
using namespace bb;

const std::string IntegerSetting::CLASS_NAME = "IntegerSetting.cpp";

IntegerSetting::IntegerSetting(std::string settingName, const GLint DEFAULT_INTEGER) :
	SettingBase(settingName),
	mDEFAULT_INTEGER(DEFAULT_INTEGER),
	mCustomInteger(mDEFAULT_INTEGER)
{
	BBLogger::logTrace(CLASS_NAME, "Creating IntegerSetting: " + toReadableString());
}

IntegerSetting::~IntegerSetting()
{
	BBLogger::logTrace(CLASS_NAME, "Deleting IntegerSetting: " + toReadableString());
}

std::string IntegerSetting::toReadableString() const
{
	return mSettingName + ": Default Integer: " + std::to_string(mDEFAULT_INTEGER) + ", Custom Integer: " + std::to_string(mCustomInteger);
}

void IntegerSetting::setCustomInteger(GLint customInteger)
{
	mCustomInteger = customInteger;
	BBLogger::logTrace(CLASS_NAME, "Creating IntegerSetting: " + toReadableString());
}

void IntegerSetting::setCustomInteger(std::string customIntegerAsString) 
{
	try
	{
		setCustomInteger(std::stoi(customIntegerAsString));
		return;
	}
	catch (const std::invalid_argument e)
	{
		BBLogger::logWarn(CLASS_NAME, "Could not convert \'" + customIntegerAsString + "\' to integer. Invalid argument. Returning default value.");
	}
	catch (const std::out_of_range e)
	{
		BBLogger::logWarn(CLASS_NAME, "Could not convert \'" + customIntegerAsString + "\' to integer. Out of range. Returning default value.");
	}
	catch (...)
	{
		BBLogger::logWarn(CLASS_NAME, "Could not convert \'" + customIntegerAsString + "\' to integer. Returning default value.");
	}

	setCustomInteger(mDEFAULT_INTEGER);
}

void IntegerSetting::operator=(GLint customInteger) 
{
	setCustomInteger(customInteger);
}

GLboolean IntegerSetting::operator==(GLint anotherInteger)
{
	return (mCustomInteger == anotherInteger);
}

const GLint& IntegerSetting::getDefaultInteger() const
{
	return mDEFAULT_INTEGER;
}

const GLint& IntegerSetting::getCustomInteger() const
{
	return mCustomInteger;
}

std::string IntegerSetting::toFileString() const
{
	return mSettingName + FILE_DELIMITER + std::to_string(mCustomInteger);
}

GLboolean IntegerSetting::isModified() const
{
	return (mDEFAULT_INTEGER != mCustomInteger);
}

void IntegerSetting::resetCustomValue()
{
	mCustomInteger = mDEFAULT_INTEGER;
}