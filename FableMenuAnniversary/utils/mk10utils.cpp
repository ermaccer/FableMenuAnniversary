#include "..\pch.h"
#include "mk10utils.h"

int GetMKXEntryPoint()
{
	static int addr = reinterpret_cast<int>(GetModuleHandle(nullptr));
	return addr;
}

int _addr(int addr)
{
	return GetMKXEntryPoint() - 0x400000 + addr;
}
