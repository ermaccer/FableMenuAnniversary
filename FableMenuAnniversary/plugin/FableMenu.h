#pragma once
#include "../fable.h"

#define FABLEMENU_VERSION "1.1"

enum eMenuSubMenus {
	SM_Settings,
	SM_Creature_List,
	SM_Object_List,
	SM_Total
};


enum eFableMenu_MessageType {
	MT_None,
	MT_QuestActivate,
	MT_QuestDeactivate
};

class FableMenu {
public:
	bool	 m_bIsActive = false;
	bool	 m_bSubmenuActive[SM_Total] = {};
	bool     m_bPressingKey = false;
	bool	 m_bIsFocused = true;
	eFableMenu_MessageType m_currentMessage = MT_None;

	bool	 freezeCam = false;
	bool	 m_bFrozeControls = false;
	bool	 m_bGodMode = false;
	bool	 m_bInfiniteWill = false;
	bool	 m_bMouseControl = false;

	bool	 m_bNoBodyGuardsLimit = false;

	char szFactionName[128] = {};
	char scriptName[256] = {};
	int* m_pCurrentVarToChange = nullptr;

	float  m_fFreeCamSpeed = 100.0f;

	CVector camPos = {};

	void Init();
	void Process();
	void Draw();
	
	void SetMessage(eFableMenu_MessageType msg);

	void DrawPlayerTab();
	void DrawCameraTab();
	void DrawWorldTab();
	void DrawQuestTab();
	void DrawMiscTab();

	void DrawSettings();
	void DrawCreatureList();
	void DrawObjectList();

	void DrawKeyBind(char* name, int* var);
	void KeyBind(int* var, char* bindName, char* name);

	static bool m_bCustomCameraPos;
	static bool ms_bFreeCam;
	static bool ms_bDisableHUD;
	static bool m_bCustomCameraFOV;
	static bool ms_bChangeTime;
	static float m_fTime;
	

	void MSG_ActivateQuest();
	void MSG_DeactivateQuest();

	void ProcessMessages();

	
};

extern FableMenu* TheMenu;

bool InGame();
void HookWorldUpdate(int);

float GetDeltaTime();
bool IsWindowFocused();

void __fastcall CMessageEventUpdater_Update_Hook(int ptr);
