#ifndef BB_GAMESETTINGS_H_
#define BB_GAMESETTINGS_H_

#include <string>
#include <set>
#include <glad/glad.h>
#include "key/KeySetting.h"

namespace bb
{
	class FileLocation;
	class GameSettings
	{
	public:
		static GameSettings* init();
		static GameSettings& getInstance();
		
		~GameSettings();

		GameSettings(GameSettings const &copy) = delete;
		void operator=(GameSettings const &copy) = delete;

		void saveSettingsToFile();
		void loadSettingsFromFile();

		void setKeyPressed(GLuint keyCode);
		void setKeyReleased(GLuint keyCode);

		void update();

		static const KeySetting& getWindowCloseKey() { return *instance->mWindowCloseKey; }

		static const KeySetting& getMoveForwardKey() { return *instance->mMoveForwardKey; }
		static const KeySetting& getMoveBackwardKey() { return *instance->mMoveBackwardKey; }
		static const KeySetting& getMoveLeftKey() { return *instance->mMoveLeftKey; }
		static const KeySetting& getMoveRightKey() { return *instance->mMoveRightKey; }

	private:
		static GameSettings *instance;
		static std::string CLASS_NAME;
		static const GLuint MAX_KEYS_PRESSED;

		std::set<GLuint> mPressedKeyCodes;

		FileLocation *mSettingsLocation;

		KeySetting *mWindowCloseKey;

		KeySetting *mMoveForwardKey;
		KeySetting *mMoveBackwardKey;
		KeySetting *mMoveLeftKey;
		KeySetting *mMoveRightKey;

		GameSettings();

		GLboolean isKeyBindingPressed(std::set<GLuint> keyBinding) const;
		
		void addKeyPressed(GLuint asciiValue);
		void removeKeyPressed(GLuint asciiValue);
		void printPressedKeys() const;

	};
}

#endif