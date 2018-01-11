#include "SettingBase.h"
using namespace bb;

const GLchar SettingBase::FILE_DELIMITER = '=';

SettingBase::SettingBase(std::string settingName) :
	mSettingName(settingName)
{

}

SettingBase::~SettingBase()
{

}

const std::string& SettingBase::getSettingName() const
{
	return mSettingName;
}
