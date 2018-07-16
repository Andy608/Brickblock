#ifndef BB_KEYSETTING_H_
#define BB_KEYSETTING_H_

#include "../numeric/IntegerSetting.h"
#include <set>
#include <vector>

namespace bb
{
	class KeySetting : public SettingBase
	{
	public:
		KeySetting(std::string settingName, const std::set<GLuint> DEFAULT_KEYS);
		virtual ~KeySetting();

		virtual std::string toReadableString() const;

		virtual const GLboolean& isPressed() const;
		void setPressed(GLboolean isPressed);

		void setNewPress(GLboolean isNewPress);
		const GLboolean& isNewPress() const;

		void setCustomKeyBinding(const std::set<GLuint> &customKeys);
		void setCustomKeyBinding(const std::vector<std::string> &customKeys);
		virtual void resetCustomValue();

		const std::set<GLuint>& getDefaultKeyBinding() const;
		const std::set<GLuint>& getCustomKeyBinding() const;

		const GLuint getDefaultBindingLength() const;
		const GLuint getCustomBindingLength() const;

		virtual std::string toFileString() const;
		virtual GLboolean isModified() const;

	protected:
		GLboolean mPressed;
		GLboolean mNewPress;

		const std::set<GLuint> mDEFAULT_KEYS;
		std::set<GLuint> mCustomKeys;

	private:
		static const std::string CLASS_NAME;
	};
}

#endif