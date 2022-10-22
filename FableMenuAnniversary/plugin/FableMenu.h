#pragma once
#include "../fable.h"

#define FABLEMENU_VERSION "1.0"

enum eMenuSubMenus {
	SUBMENU_SETTINGS,
	TOTAL_SUBMENUS
};

enum eFreeCameraType {
	FREE_CAMERA_ORIGINAL,
	FREE_CAMERA_CUSTOM,
};

class FableMenu {
public:
	bool	 m_bIsActive = false;
	bool	 m_bSubmenuActive[TOTAL_SUBMENUS] = {};
	bool     m_bPressingKey = false;
	bool	 m_bIsFocused = true;

	bool	 freezeCam = false;
	bool	 m_bFrozeControls = false;
	bool	 m_bGodMode = false;
	bool	 m_bInfiniteWill = false;
	bool	 m_bMouseControl = false;

	char szFactionName[128] = {};

	int		m_nFreeCameraMode = FREE_CAMERA_CUSTOM;


	int* m_pCurrentVarToChange = nullptr;

	float  m_fFreeCamSpeed = 100.0f;

	CVector camPos = {};

	void Init();
	void Process();
	void Draw();

	void DrawPlayerTab();
	void DrawCameraTab();
	void DrawWorldTab();
	void DrawMiscTab();
	void DrawSettings();


	void DrawKeyBind(char* name, int* var);
	void KeyBind(int* var, char* bindName, char* name);

	static bool m_bCustomCameraPos;
	static bool ms_bFreeCam;
	static bool ms_bDisableHUD;
	static bool m_bCustomCameraFOV;
	static bool ms_bChangeTime;
	static float m_fTime;
};

extern FableMenu* TheMenu;

bool InGame();
void HookWorldUpdate(int);

float GetDeltaTime();
bool IsWindowFocused();
