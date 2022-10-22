#include "Thing.h"
#include "../core.h"
CTCHeroStats* CThing::GetHeroStats()
{
    int v29 = 4;
    int v5 = 0;
    ((void(__thiscall*)(int, int*, int*))_addr(0x1B80030))((int)this + 68, &v5, &v29);
    if (v5 == *(int*)((int)this + 72) || *(int*)v5 > 4)
        v5 = *(int*)((int)this + 72);
    return *(CTCHeroStats**)(v5 + 4);
}

CTCHeroMorph* CThing::GetHeroMorph()
{
    int v29 = 3;
    int v5 = 0;
    ((void(__thiscall*)(int, int*, int*))_addr(0x1B80030))((int)this + 68, &v5, &v29);
    if (v5 == *(int*)((int)this + 72) || *(int*)v5 > 3)
        v5 = *(int*)((int)this + 72);
    return *(CTCHeroMorph**)(v5 + 4);
}

CTCHeroExperience* CThing::GetHeroExperience()
{
    int v29 = 104;
    int v5 = 0;
    ((void(__thiscall*)(int, int*, int*))_addr(0x1B80030))((int)this + 68, &v5, &v29);
    if (v5 == *(int*)((int)this + 72) || *(int*)v5 > 104)
        v5 = *(int*)((int)this + 72);
    return *(CTCHeroExperience**)(v5 + 4);
}

CTCHero* CThing::GetHero()
{
    int v29 = 41;
    int v5 = 0;
    ((void(__thiscall*)(int, int*, int*))_addr(0x1B80030))((int)this + 68, &v5, &v29);
    if (v5 == *(int*)((int)this + 72) || *(int*)v5 > 41)
        v5 = *(int*)((int)this + 72);
    return *(CTCHero**)(v5 + 4);
}

CTCEnemy* CThing::GetEnemy()
{
    int v29 = 73;
    int v5 = 0;
    ((void(__thiscall*)(int, int*, int*))_addr(0x1B80030))((int)this + 68, &v5, &v29);
    if (v5 == *(int*)((int)this + 72) || *(int*)v5 > 73)
        v5 = *(int*)((int)this + 72);
    return *(CTCEnemy**)(v5 + 4);
}

CTCRegionFollower* CThing::GetRegionFollower()
{
    int v29 = 122;
    int v5 = 0;
    ((void(__thiscall*)(int, int*, int*))_addr(0x1B80030))((int)this + 68, &v5, &v29);
    if (v5 == *(int*)((int)this + 72) || *(int*)v5 > 122)
        v5 = *(int*)((int)this + 72);
    return *(CTCRegionFollower**)(v5 + 4);
}

CTCGraphicAppearance* CThing::GetGraphicAppearance()
{
    int v29 = 91;
    int v5 = 0;
    ((void(__thiscall*)(int, int*, int*))_addr(0x1B80030))((int)this + 68, &v5, &v29);
    if (v5 == *(int*)((int)this + 72) || *(int*)v5 > 91)
        v5 = *(int*)((int)this + 72);
    return *(CTCGraphicAppearance**)(v5 + 4);
}

CVector* CThing::GetPosition()
{
    return ((CVector*(__thiscall*)(CThing*))_addr(0x1F2B440))(this);
}

int GetThingID(char* name)
{
    int id = -1;
    int manager = ((int(__cdecl*)())_addr(0x1C1D600))();
    if (manager)
    {
        CCharString str(name);
        id = ((int(__thiscall*)(int, CCharString*))_addr(0x16CC3C0))(manager, &str);
    }
    return id;
}

CThing* CreateThing(int id, CVector* pos, int plr, int unk, int unk2, char* name)
{
    CCharString tmp(name);
    return  ((CThing * (__cdecl*)(int, CVector*, int, int,int, int, CCharString*))_addr(0x1F58490))(id, pos, plr, unk, 0, unk2, &tmp);
}

CThing* CreateCreature(int id, CVector* pos, int plr)
{
    CreatureAI ai = {};
    ai.IsPlayer = false;
    ai.Draw = true;
    ai.unk[0] = true;
    return ((CThing * (__cdecl*)(int, CVector*, int, CreatureAI*))_addr(0x1F38400))(id, pos, plr, &ai);
}

void CTCEnemy::SetFaction(CCharString* str)
{
    ((void(__thiscall*)(CTCEnemy*, CCharString*))_addr(0x1D87530))(this, str);
}

void CTCEnemy::AddAlly(CThing* thing)
{
    ((void(__thiscall*)(CTCEnemy*, CThing*))_addr(0x1D87A00))(this, thing);
}

void CTCRegionFollower::AddFollower(CThing* thing)
{
    ((void(__thiscall*)(CTCRegionFollower*, CThing*))_addr(0x1EFE0A0))(this, thing);
}

void CTCGraphicAppearance::SetAlpha(char value)
{
    ((void(__thiscall*)(CTCGraphicAppearance*, char))_addr(0x1DA20A0))(this, value);
}

void CTCGraphicAppearance::SetColor(int* color, CTCBase* base)
{
    ((void(__thiscall*)(CTCGraphicAppearance*, int*, CTCBase*))_addr(0x1DA2180))(this, color, base);
}

void CTCGraphicAppearance::SetScale(float value)
{
    ((void(__thiscall*)(CTCGraphicAppearance*, float))_addr(0x1DA2010))(this, value);
}
