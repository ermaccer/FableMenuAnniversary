// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "eSettingsManager.h"
#include "eDirectX9Hook.h"
#include <iostream>
#include "core.h"
#include "plugin/FableMenu.h"
#include "fable/GameCamera.h"
#include "helper/eMouse.h"
#include "eNotifManager.h"



void UpdateThread()
{
    while (true)
    {
        eMouse::UpdateMouse();
        Notifications->Update();
        Sleep(1);
    }
}

void Init()
{
#ifdef _DEBUG
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
#endif
    TheMenu->Init();
    Notifications->Init();

    eDirectX9Hook::Init();
    InjectHook(_addr(0x1C83C48), &CGameCameraManager::Update);

    InjectHook(_addr(0x1FAAD1F), CMessageEventUpdater_Update_Hook);
  
    eDirectX9Hook::RegisterHook(_addr(0x15E5902), _addr(0x15E5908), Method_EndScene);
    eDirectX9Hook::RegisterHook(_addr(0x15D3B6C), _addr(0x15D3B77), Method_Reset);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        SettingsMgr->Init();
        Init();
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(UpdateThread), nullptr, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

