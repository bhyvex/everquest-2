#pragma once

void EQAPP_Detours_Load();
void EQAPP_Detours_Unload();

EQ_MACRO_FUNCTION_DefineDetour(CrashDetected);
EQ_MACRO_FUNCTION_DefineDetour(DrawNetStatus);
EQ_MACRO_FUNCTION_DefineDetour(ExecuteCmd);

EQ_MACRO_FUNCTION_DefineDetour(CXWndManager__DrawWindows);

EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__FollowPlayerAI);
EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__ChangeHeight);

EQ_MACRO_FUNCTION_DefineDetour(EQ_Character__eqspa_movement_rate);

EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__InterpretCmd);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__StartCasting);

char* __cdecl EQAPP_DETOURED_FUNCTION_CrashDetected();
int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int x, int y, int unknown);
int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero);

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__ChangeHeight(void* this_ptr, void* not_used, float height, float a2, float a3, int a4);

int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, int movementSpeed);

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, const char* text);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQ::CEverQuest__StartCasting_Message_ptr message);

void EQAPP_Detours_Load()
{
    EQ_MACRO_FUNCTION_AddDetour(CrashDetected);
    EQ_MACRO_FUNCTION_AddDetour(DrawNetStatus);
    ////EQ_MACRO_FUNCTION_AddDetour(ExecuteCmd);

    EQ_MACRO_FUNCTION_AddDetour(CXWndManager__DrawWindows);

    EQ_MACRO_FUNCTION_AddDetour(EQPlayer__FollowPlayerAI);
    ////EQ_MACRO_FUNCTION_AddDetour(EQPlayer__ChangeHeight);

    ////EQ_MACRO_FUNCTION_AddDetour(EQ_Character__eqspa_movement_rate);

    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__InterpretCmd);
    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__StartCasting);
}

void EQAPP_Detours_Unload()
{
    EQ_MACRO_FUNCTION_RemoveDetour(CrashDetected);
    EQ_MACRO_FUNCTION_RemoveDetour(DrawNetStatus);
    ////EQ_MACRO_FUNCTION_RemoveDetour(ExecuteCmd);

    EQ_MACRO_FUNCTION_RemoveDetour(CXWndManager__DrawWindows);

    EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__FollowPlayerAI);
    ////EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__ChangeHeight);

    ////EQ_MACRO_FUNCTION_RemoveDetour(EQ_Character__eqspa_movement_rate);

    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__InterpretCmd);
    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__StartCasting);
}

char* __cdecl EQAPP_DETOURED_FUNCTION_CrashDetected()
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CrashDetected();
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        std::cout << "********** CRASH DETECTED **********" << std::endl;
    }

    ////return "CrashDetected()";

    return EQAPP_REAL_FUNCTION_CrashDetected();
}

int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int x, int y, int unknown)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    if (g_EQAppIsLoaded == 0)
    {
        EQAPP_Load();
    }

    // kill switch
    if (GetAsyncKeyState(g_EQAppKillSwitchKey))
    {
        EQAPP_Unload();
        EQAPP_Console_Print();
        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    g_EQAppPlayerName = EQ_GetPlayerSpawnName();

    if (EQAPP_Timer_HasTimeElapsed(g_EQAppWindowTitleTimer, g_EQAppWindowTitleTimerInterval) == true)
    {
        EQAPP_SetWindowTitleToPlayerSpawnName();
    }

    if (g_SleepIsEnabled == true)
    {
        EQAPP_Sleep_Execute();
    }

    if (g_HUDIsEnabled == true)
    {
        EQAPP_HUD_Execute();
    }

    if (g_BoxChatIsEnabled == true)
    {
        if (g_BoxChatIsConnected == true)
        {
            EQAPP_BoxChat_Execute();
        }
    }

    if (g_AlwaysAttackIsEnabled == true)
    {
        EQAPP_AlwaysAttack_Execute();
    }

    if (g_AlwaysHotButtonIsEnabled == true)
    {
        EQAPP_AlwaysHotButton_Execute();
    }

    if (g_CombatHotButtonIsEnabled == true)
    {
        EQAPP_CombatHotButton_Execute();
    }

    if (g_AutoAlternateAbilityIsEnabled == true)
    {
        EQAPP_AutoAlternateAbility_Execute();
    }

    if (g_CombatAlternateAbilityIsEnabled == true)
    {
        EQAPP_CombatAlternateAbility_Execute();
    }

    if (g_ChangeHeightIsEnabled == true)
    {
        EQAPP_ChangeHeight_Execute();
    }

    EQAPP_Console_Print();

    return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
}

int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
    }

    std::cout << "ExecuteCmd(): " << commandID << " (Active: " << isActive << ") " << zero << std::endl;

/*
    if (commandID > EQ_EXECUTECMD_ID_LAST)
    {
        std::cout << "ExecuteCmd: " << commandID << " (Active: " << isActive << ")" << std::endl;
    }
*/

/*
    if (commandID >= EQ_EXECUTECMD_CAST1 && commandID <= EQ_EXECUTECMD_CAST14)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            EQ_WriteMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_FOLLOW_SPAWN, 0);
            EQ_WriteMemory<uint32_t>(EQ_ADDRESS_AUTO_RUN, 0);
        }
    }
*/

    return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
    }

    if (g_ESPIsEnabled == true)
    {
        EQAPP_ESP_Execute();
    }

    if (g_SpawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_Execute();
        EQAPP_SpawnCastSpell_DrawText();
    }

    return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);
    }

    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_3, 400.0f);

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        if ((uint32_t)this_ptr == playerSpawn)
        {
            uint32_t followSpawn = EQ_ReadMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_FOLLOW_SPAWN);
            if (followSpawn != NULL)
            {
                EQ_TurnPlayerTowardsTarget();

                EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_1, 5.0f);
                EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_2, 5.0f);
            }
        }
    }

    int result = EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);

    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_1, EQ_FOLLOW_DISTANCE_1_DEFAULT);
    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_2, EQ_FOLLOW_DISTANCE_2_DEFAULT);
    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_3, EQ_FOLLOW_DISTANCE_3_DEFAULT);

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__ChangeHeight(void* this_ptr, void* not_used, float height, float a2, float a3, int a4)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__ChangeHeight(this_ptr, height, a2, a3, a4);
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        if ((uint32_t)this_ptr == playerSpawn)
        {
            std::cout << "EQPlayer__ChangeHeight(): " << height << ", " << a2 << ", " << a3 << ", " << a4;
        }
    }

    return EQAPP_REAL_FUNCTION_EQPlayer__ChangeHeight(this_ptr, height, a2, a3, a4);
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, int movementSpeed)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__eqspa_movement_rate(this_ptr, movementSpeed);
    }

    // never snared, rooted or slowed below base movement speed
    if (movementSpeed < 0)
    {
        movementSpeed = 0;
    }

    ////std::cout << "movementSpeed: " << movementSpeed << std::endl;

    return EQAPP_REAL_FUNCTION_EQ_Character__eqspa_movement_rate(this_ptr, movementSpeed);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, const char* text)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, text);
    }

    if (g_InterpretCmdIsEnabled == true)
    {
        bool result = EQAPP_InterpretCmd_HandleEvent_CEverQuest__InterpretCmd(this_ptr, player, text);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, text);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQ::CEverQuest__StartCasting_Message_ptr message)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__StartCasting(this_ptr, message);
    }

/*
    std::cout << "---- CEverQuest::StartCasting() ----" << std::endl;
    std::cout << "SpawnID: " << message->SpawnID << std::endl;
    std::cout << "SpellID: " << message->SpellID << " <" << EQAPP_SpellList_GetNameByID(message->SpellID) << ">" << std::endl;
    std::cout << "SpellCastTime: " << message->SpellCastTime << std::endl;
    std::cout << "------------------------------------" << std::endl;
*/

    if (g_SpawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_HandleEvent_CEverQuest__StartCasting(this_ptr, message);
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__StartCasting(this_ptr, message);
}
