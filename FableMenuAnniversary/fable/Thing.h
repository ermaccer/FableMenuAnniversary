#pragma once
#include "Hero.h"
#include "FCore.h"

class CTCEnemy;
class CTCRegionFollower;
class CTCLook;
class CTCGraphicAppearance;

class CThing {
public:
	char pad[204];
	float m_fMaxHealth;
	float m_fHealth;

	CTCHeroStats* GetHeroStats();
	CTCHeroMorph* GetHeroMorph();
	CTCHeroExperience* GetHeroExperience();
	CTCHero* GetHero();
	CTCEnemy* GetEnemy();
	CTCRegionFollower* GetRegionFollower();
	CTCGraphicAppearance* GetGraphicAppearance();

	CVector* GetPosition();
};

class CTCEnemy {
public:
	void SetFaction(CCharString* str);
	void AddAlly(CThing* thing);
};

class CTCRegionFollower {
public:
	void AddFollower(CThing* thing);
};


class CTCGraphicAppearance {
public:
	void SetAlpha(char value);
	void SetColor(int* color, CTCBase* base);
	void SetScale(float value);
};


struct  CreatureAI
{
	int field_0;
	int field_4;
	CCharString* name;
	CCharString* str;
	bool IsPlayer;
	bool Draw;
	bool unk[2];
	int homeBuilding;
	int workBuilding;

};

int GetThingID(char* name);
CThing* CreateThing(int id, CVector* pos, int plr, int unk, int unk2, char* name);
CThing* CreateCreature(int id, CVector* pos, int plr);