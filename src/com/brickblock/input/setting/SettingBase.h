#ifndef BB_SETTINGBASE_H_
#define BB_SETTINGBASE_H_

#include <string>
#include <glad/glad.h>

namespace bb
{
	//Class hierarchy to store setting name, value, and default value
	class SettingBase
	{
	public:
		static const GLchar FILE_DELIMITER;

		SettingBase(std::string settingName);
		virtual ~SettingBase();

		const std::string& getSettingName() const;

		virtual std::string toReadableString() const = 0;
		virtual std::string toFileString() const = 0;
		virtual GLboolean isModified() const = 0;
		virtual void resetCustomValue() = 0;

	protected:
		std::string mSettingName;
	};
}

#endif