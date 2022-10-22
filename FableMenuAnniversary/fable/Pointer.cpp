#include "Pointer.h"
#include "../core.h"

CIntelligentPointer::CIntelligentPointer(CThing* thing)
{
	vTable = *(int*)_addr(0x2EB1714);
	Pointer = 0;
	((void(__thiscall*)(CIntelligentPointer*, CThing*))_addr(0x16E6EE0))(this, thing);
}

CThing* CIntelligentPointer::operator*()
{
	return ((CThing * (__thiscall*)(CIntelligentPointer*))_addr(0x16E6EA0))(this);
}
