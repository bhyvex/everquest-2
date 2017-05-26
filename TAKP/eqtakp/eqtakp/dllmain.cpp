#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <random>
#include <functional>

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <ctime>

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <tlhelp32.h>
#include <fcntl.h>
#include <io.h>

#include <psapi.h>
#pragma comment(lib, "psapi.lib")

#include <d3d8.h>
#pragma comment(lib, "d3d8.lib")

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#pragma comment(lib, "dinput8.lib")
#define DINPUT_MOUSE_BUTTON_LEFT   0
#define DINPUT_MOUSE_BUTTON_RIGHT  1
#define DINPUT_MOUSE_BUTTON_MIDDLE 2
#define DINPUT_MOUSE_BUTTON_4      3
#define DINPUT_MOUSE_BUTTON_5      4
#define DINPUT_MOUSE_BUTTON_6      5
#define DINPUT_MOUSE_BUTTON_7      6
#define DINPUT_MOUSE_BUTTON_8      7

#include "detours.h"
#pragma comment(lib, "detours.lib")

#include "eq.h"
#include "eq_offsets.h"
#include "eq_functions.h"
#include "eq_graphicsdll.h"

#include "eqapp.h"
#include "eqapp_functions.h"

#include "eqapp_console.h"
#include "eqapp_ini.h"
#include "eqapp_memory.h"

#include "eqapp_autoloot.h"
#include "eqapp_namedspawns.h"

#include "eqapp_speedhack.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_bufftimers.h"
#include "eqapp_itemdisplay.h"
#include "eqapp_hidecorpselooted.h"
#include "eqapp_namespritestate.h"
#include "eqapp_namespritetint.h"
#include "eqapp_changeheight.h"
#include "eqapp_standwhencastspell.h"
#include "eqapp_maxskills.h"
#include "eqapp_useskills.h"
#include "eqapp_foodanddrink.h"
#include "eqapp_spellset.h"

#include "eqapp_map.h"
#include "eqapp_esp.h"

#include "eqapp_detours.h"

void EQAPP_Load()
{
    EQ_WriteChatText("Loading...");

    EQAPP_Memory_Load();

    if (EQ_IsInGame() == true)
    {
        g_zoneID = EQ_GetZoneID();

        EQ_UpdateLight(EQ_POINTER_PlayerCharacter);

        EQAPP_Map_Load();
        EQAPP_AutoLoot_Load();
        EQAPP_NamedSpawns_Load();
    }

    //EQ_CLASS_POINTER_DInputMouse->SetCooperativeLevel(EQ_GetWindow(), DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);

    //std::fstream myFile("eqtakp/test.txt", std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::trunc);
    //myFile.seekg(0);
    //myFile.write((char*)EQ_POINTER_PlayerSpawn, sizeof(EQ::Spawn));
    //myFile.close();

    g_bLoaded = 1;

    EQ_WriteChatText("Loaded!");
}

void EQAPP_Unload()
{
    EQ_WriteChatText("Unloading...");

    //EQ_CLASS_POINTER_DInputMouse->SetCooperativeLevel(EQ_GetWindow(), DISCL_BACKGROUND | DISCL_EXCLUSIVE);

    EQAPP_Memory_Unload();

    g_bExit = 1;
}

DWORD WINAPI EQAPP_ThreadLoop(LPVOID param)
{
    while (g_bExit == 0)
    {
        Sleep(1000);
    }

    // wait for the console to unload
    while (g_bConsole == 1)
    {
        Sleep(1000);
    }

    Sleep(1000);

    EQAPP_Detours_Remove();

    TerminateThread(EQAPP_ThreadLoad, 0);
    TerminateThread(EQAPP_ThreadConsole, 0);

    Sleep(1000);

    FreeLibraryAndExitThread(g_module, 0);
    return 0;
}

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param)
{
    EQAPP_EnableDebugPrivileges();

    if (EQ_GraphicsDLL_LoadFunctions() == false)
    {
        MessageBoxA(NULL, "Error: Failed to load graphics DLL functions!", g_applicationName, MB_ICONERROR);

        FreeLibraryAndExitThread(g_module, 0);
        return 0;
    }

    g_handleThreadConsole = CreateThread(NULL, 0, &EQAPP_ThreadConsole, NULL, 0, NULL);

    // wait for the console to load
    while (g_bConsole == 0);

    g_handleThreadLoop = CreateThread(NULL, 0, &EQAPP_ThreadLoop, NULL, 0, NULL);

    EQAPP_Detours_Add();

    ExitThread(0);

    return 0;
}

DWORD WINAPI EQAPP_ThreadConsole(LPVOID param)
{
    EQAPP_Console_Load();

    while (g_bExit == 0)
    {
        Sleep(100);
    }

    EQAPP_Console_Unload();

    ExitThread(0);

    return 0;
}

BOOL __stdcall DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    g_module = module;

    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(module);
            g_handleThreadLoad = CreateThread(NULL, 0, &EQAPP_ThreadLoad, NULL, 0, NULL);
            break;

        case DLL_PROCESS_DETACH:
            break;
    }

    return TRUE;
}
