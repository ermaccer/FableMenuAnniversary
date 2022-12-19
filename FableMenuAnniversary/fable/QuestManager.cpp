#include "QuestManager.h"
#include "../core.h"

bool CQuestManager::ActivateQuest(CCharString& name, bool game, bool load_resources)
{
    return ((bool(__thiscall*)(CQuestManager*, CCharString&, bool, bool))_addr(0x1FC2580))(this, name, game, load_resources);
}

bool CQuestManager::IsActive(CCharString& name)
{
    return ((bool(__thiscall*)(CQuestManager*, CCharString&))_addr(0x1FB92D0))(this, name);
}

void CQuestManager::DeactivateQuest(CCharString& name, int flags)
{
    ((void(__thiscall*)(CQuestManager*, CCharString&, int))_addr(0x1FC2630))(this, name, flags);
}

CQuestManager* CQuestManager::Get()
{
    return *(CQuestManager**)(_addr(0x3630360));
}
