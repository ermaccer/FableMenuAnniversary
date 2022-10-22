#include "PlayerManager.h"
#include "../core.h"

CPlayer* CPlayerManager::GetPlayer()
{
	return ((CPlayer*(__thiscall*)(CPlayerManager*))_addr(0x1CFD7D0))(this);
}
