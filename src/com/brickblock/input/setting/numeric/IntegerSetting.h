#ifndef BB_INTEGERSETTING_H_
#define BB_INTEGERSETTING_H_

#include "../SettingBase.h"

namespace bb
{
	class IntegerSetting : public SettingBase
	{
	public:
		IntegerSetting(std::string settingName, const GLint DEFAULT_INTEGER);
		virtual ~IntegerSetting();

		virtual std::string toReadableString() const;

		virtual void setCustomInteger(GLint customInteger);
		void setCustomInteger(std::string customIntegerAsString);

		void operator=(GLint customInteger);
		GLboolean operator==(GLint anotherInteger);

		const GLint& getDefaultInteger() const;
		const GLint& getCustomInteger() const;

		virtual std::string toFileString() const;
		virtual GLboolean isModified() const;
		void resetCustomValue();

	protected:
		const GLint mDEFAULT_INTEGER;
		GLint mCustomInteger;

	private:
		static const std::string CLASS_NAME;
	};
}

#endif