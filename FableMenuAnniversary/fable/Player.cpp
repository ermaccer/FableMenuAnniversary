#include "Player.h"
#include "../core.h"

void CPlayer::SetMode(int id, bool unk)
{
	((void(__thiscall*)(CPlayer*, int, bool))_addr(0x1CFFBF0))(this, id, unk);
}

void CPlayer::ClearMode(int id)
{
	((void(__thiscall*)(CPlayer*, int))_addr(0x1CFF7B0))(this, id);
}

CThing* CPlayer::GetCharacterThing()
{
	return ((CThing* (__thiscall*)(CPlayer*))_addr(0x1EC1600))(this);
}
