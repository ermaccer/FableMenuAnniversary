#include "MainGameComponent.h"
#include "../core.h"

CMainGameComponent* CMainGameComponent::Get()
{
    return *(CMainGameComponent**)(_addr(0x362AE48));
}

CWorld* CMainGameComponent::GetWorld()
{
    return *(CWorld**)((int)this + 44);
}

CPlayerManager* CMainGameComponent::GetPlayerManager()
{
    return *(CPlayerManager**)((int)this + 36);
}
