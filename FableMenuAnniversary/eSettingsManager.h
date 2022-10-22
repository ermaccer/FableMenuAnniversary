#pragma once
#include <Windows.h>

// as usual, pluginmh/mugenhook

struct eMouseSettings {
	float sens;
	bool invert_y;
	bool invert_x;
};


class eSettingsManager {
public:
	void Init();

	int iMenuOpenKey = VK_OEM_3;

	

	// free camera keys
	int iFreeCameraKeyForward;
	int iFreeCameraKeyBack;
	int iFreeCameraKeyLeft;
	int iFreeCameraKeyRight;
	int iFreeCameraKeyUp;
	int iFreeCameraKeyDown;


	eMouseSettings mouse;
	float fMenuScale;

	void SaveSettings();
	void ResetKeys();

};

extern eSettingsManager* SettingsMgr;