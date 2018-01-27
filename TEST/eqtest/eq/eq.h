#pragma once

#include "eq_executecmd.h"
#include "eq_keys.h"

DWORD EQ_ADDRESS_CLIENT_VERSION_DATE = 0xAE60B8; // WinMain()    "Starting EverQuest (Built %s %s)"
#define EQ_STRING_CLIENT_VERSION_DATE "Jan 22 2018"
#define EQ_SIZE_CLIENT_VERSION_DATE 12

DWORD EQ_ADDRESS_CLIENT_VERSION_TIME = 0xAE60C4; // WinMain()    "Starting EverQuest (Built %s %s)"
#define EQ_STRING_CLIENT_VERSION_TIME "10:35:37"
#define EQ_SIZE_CLIENT_VERSION_TIME 9

const float EQ_PI = 3.14159265358979f;

DWORD EQ_BASE_ADDRESS_VALUE    = 0x400000;

DWORD EQ_ADDRESS_AUTO_ATTACK    = 0xFB6A7B; // uint8_t
DWORD EQ_ADDRESS_AUTO_FIRE      = 0xFB6A7C; // uint8_t
DWORD EQ_ADDRESS_AUTO_RUN       = 0xF32514; // uint32_t
DWORD EQ_ADDRESS_MOUSE_LOOK     = 0xF324F6; // uint8_t
/*
search for 1 and 0
*/

DWORD EQ_ADDRESS_POINTER_WINDOW_HWND = 0xFBC0C0; // HWND hWnd
/*
PostMessageA(hWnd, 0x4647u, 0x4247u, (LPARAM)v3);
*/

DWORD EQ_ADDRESS_FUNCTION_DrawNetStatus    = 0x5BA110; // "%ldms" and "%0.2f%%"
DWORD EQ_ADDRESS_FUNCTION_ExecuteCmd       = 0x5219A0; // "ExecuteCmd has received a CMD_EXITGAME.\n" and "/%s %s" and "%c%s %s " and "help.html"
/*
ExecuteCmd()
case 508:
        sub_8A22E0("ExecuteCmd has received a CMD_EXITGAME.\n", v168);
        byte_F2FB27 = 1;
        return 1;
*/
/*
sub_8A55C0(
      "*** DISCONNECTING: HitBySpell() is throwing a CMD_EXITGAME at %s:%lu\n",
      (unsigned int)"c:\\p4\\EverQuest\\test\\Common\\CharacterMagicSystem.cpp");
    sub_523550(508, 0, 0, 0); // ExecuteCmd
*/
DWORD EQ_ADDRESS_FUNCTION_get_bearing    = 0x539620; // search for "fpatan"
/*
double __cdecl sub_53B1C0(float a1, float a2, float a3, float a4)
{
  double v4; // st6@1
  long double v5; // st5@1
  double v6; // st4@1
  long double v7; // st2@1
  long double v8; // rt2@3
  long double v9; // st2@3
  double v10; // st5@3
  long double v11; // st7@3
  double result; // st7@5
  double v13; // st3@8

  v4 = a3;
  v5 = fabs(a1 - a3);
  v6 = a2;
  v7 = fabs(a2 - a4);
  if ( v5 < 0.0000009999999974752427 )
    v5 = 0.0000009999999974752427;
  v8 = v7;
  v9 = v5;
  v10 = a4;
  v11 = atan2(v9, v8) * 180.0 * 0.3183099014828645;
  if ( a1 < v4 )
  {
    v13 = a1;
  }
  else
  {
    if ( a4 >= v6 )
      return (90.0 - v11 + 90.0) * 511.5 * 0.0027777778;
    if ( a4 <= v6 )
      return (v11 + 180.0) * 511.5 * 0.0027777778;
    v13 = a1;
    v10 = a4;
  }
  if ( v13 > v4 || v10 > v6 )
    result = v11 * 511.5 * 0.0027777778;
  else
    result = (90.0 - v11 + 270.0) * 511.5 * 0.0027777778;
  return result;
}
*/

// class EQPlayer
DWORD EQ_ADDRESS_POINTER_EQPlayerManager    = 0xFB80B0; // pinstSpawnManager

#define EQ_OFFSET_EQPlayerManager_FIRST_SPAWN    0x08
#define EQ_OFFSET_EQPlayerManager_LAST_SPAWN     0x0C

DWORD EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x5E2E00; // "Your inventory is full!"
/*
case 0xD:
      result = (_DWORD *)sub_5E2420((void *)dword_FB5090, *(_DWORD *)(a3 + 4)); // EQPlayerManager__GetSpawnByID and pinstSpawnManager
      if ( result )
      {
        if ( dword_F21FD4 )
        {
          result[151] = *(_BYTE *)(a3 + 72);
          if ( result == (_DWORD *)dword_F22004 )
          {
            if ( dword_10C2E68 )
            {
              dword_F22004 = 0;
              (*(void (__stdcall **)(_DWORD, signed int, signed int))(*(_DWORD *)dword_10C2E68 + 216))(0, 1, 1);
LABEL_53:
              dword_FB3A64 = 0;
              result = (_DWORD *)sub_645500();
            }
          }
        }
      }
      return result;
    case 0x16:
      if ( dword_10C2F58 )
      {
        v26 = 0;
        v35 = 3;
        sub_89F500("Your inventory is full!");
        v23 = (void *)sub_89F8E0(&v26);
        sub_676400(v23, 0);
        v24 = sub_89F8E0(&v26);
        sub_438B20(v24);
        result = v26;
        v35 = -1;
        if ( v26 )
          result = (_DWORD *)sub_89F270(v26);
      }
      return result;
*/

DWORD EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x5E3260; // "Incorrect Usage. Type /xtarget for correct usage."
/*
if ( !sub_8A3560(&v32, 0) || (sub_89F500(&v32), v8 = sub_89E950(&v28) - 1, v8 < 0) )
      {
LABEL_67:
        v26 = 0;
        v25 = 1;
        v24 = 13;
        v23 = "Incorrect Usage. Type /xtarget for correct usage.";
        goto LABEL_68;
      }
      v26 = (char *)&v29;
      v25 = v13;
      v30 = &v25;
      sub_89F340(&v33);
      if ( !(unsigned __int8)sub_52D7C0(v25, v26) )
      {
        v16 = 0;
        sub_89F500(&v33);
        v17 = sub_89F8E0(&v27);
        v18 = sub_5E2880((_DWORD **)dword_FB5090, v17); // EQPlayerManager__GetSpawnByName
        if ( v18 )
          v16 = *(_DWORD *)(v18 + 328);
        if ( *(_DWORD *)dword_F21F64 )
        {
          word_F1FA98 = sub_854800(28233, 0);
          dword_F1FA9A = v16;
          dword_F1FA9E = v8;
          v19 = sub_7EAEA0(4, &word_F1FA98, 10);
          sub_93ADF2(0);
          --dword_10D71E0;
          if ( !v19 )
            sub_478A00(dword_F21F64);
        }
        else if ( !byte_F2F424 )
        {
          sub_8A22E0("Attempt to send message %d on a void connection.", 73);
        }
        goto LABEL_69;
      }
*/
/*
EQPlayerManager__GetSpawnByName()
for ( i = v5; sub_8A64E0((const char *)(*(_DWORD *)i + 0xA4), (const char *)a2); i = result )
{
result = *(_DWORD *)(i + 8);
if ( !result )
    goto LABEL_6;
v7 = *(_DWORD *)(i + 4);
while ( *(_DWORD *)(result + 4) != v7 )
{
    result = *(_DWORD *)(result + 8);
    if ( !result )
    return result;
}
}
*/

// class EQPlayer
DWORD EQ_ADDRESS_POINTER_TARGET_SPAWN    = 0xF25020; // pinstTargetSpawn
DWORD EQ_ADDRESS_POINTER_PLAYER_SPAWN    = 0xF2501C; // pinstCharSpawn    "Local Player's World location at time of crash: %f, %f, %f.\n"
/*
if ( dword_F21FE8 ) // PlayerSpawn
  {
    v28 = *((float *)dword_F21FE8 + 27);
    v29 = *((float *)dword_F21FE8 + 26);
    v30 = *((float *)dword_F21FE8 + 25);
    sub_8A22E0("Local Player's World location at time of crash: %f, %f, %f.\n", SLOBYTE(v30));
  }
*/

DWORD EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI    = 0x5D4B60; // search for xref to autorun
/*
EQPlayer__FollowPlayerAI()
    if ( v21 + 15.0 <= *(float *)(v1 + 564) ) // Follow Distance 1
    {
      if ( v21 + 30.0 <= *(float *)(v1 + 564) // Follow Distance 2
        || *(float *)(*(_DWORD *)(v1 + 3868) + 124) >= (double)*(float *)(v1 + 124) && 0.0 != *(float *)(v1 + 124) )
      {
        byte_F2F440 = 1;
        AutoRun____dword_F2F4F4 = 1;
      }
      else
      {
        byte_F2F440 = 0;
        AutoRun____dword_F2F4F4 = 1;
      }
    }
    else
    {
      AutoRun____dword_F2F4F4 = 0;
      *(float *)(v1 + 124) = 0.0;
    }
*/

DWORD EQ_ADDRESS_FOLLOW_DISTANCE_1    = 0xACABE0; // 15.0f
DWORD EQ_ADDRESS_FOLLOW_DISTANCE_2    = 0xACAA84; // 30.0f
/*
EQPlayer__FollowPlayerAI()
*/

DWORD EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = 0x5EDE70; // PlayerZoneClient__ChangeHeight    "%s is now able to kill anyone (or be killed) as if they were an NPC." and "FORMAT: /becomenpc"
/*
v25 = sub_569850(v18);
sprintf(&v59, "Changing %s to race: %s.", dword_F26020 + 164, v25);
v26 = sub_476790();
sub_476850(v26, &v59, 273, 1, 1, 0);
if ( v57 )
sub_53CF80(dword_F26020, &v57); // do_height(TargetPlayer, &x);
if ( v52 )
v27 = atoi(&v52);
else
v27 = 110;
*(_DWORD *)(dword_F26020 + 1020) = v27;
v28 = *(_DWORD *)(dword_F26020 + 328);
sprintf(&v59, "%s is now able to kill anyone (or be killed) as if they were an NPC.", dword_F26020 + 164);
v29 = sub_476790();
result = sub_476850(v29, &v59, 273, 1, 1, 0);
*/

/*
v10 = 0.0;
  v11 = 0.0;
  v2 = (char *)dword_F26020;
  v12 = 1.0;
  v3 = sub_4A9BD0(a2, &v24, 40);
  v4 = sub_4A9BD0(v3, &v22, 40);
  sub_4A9BD0(v4, &v23, 40);
  if ( v24 )
    v10 = atof(&v24);
  if ( v22 )
    v11 = atof(&v22);
  if ( v23 )
    v12 = atof(&v23);
  if ( !v2 )
    v2 = dword_F26008;
  if ( v10 > 0.0 )
  {
    if ( byte_F33444 || dword_F3358C )
    {
      sprintf(byte_10F8BB8, "%f", *((float *)v2 + 79));
      sprintf(byte_10F8B98, "%f", v10);
      v13 = (int)(v2 + 164);
      v14 = byte_10F8BB8;
      v15 = byte_10F8B98;
      v16 = 0;
      v17 = 0;
      v18 = 0;
      v19 = 0;
      v20 = 0;
      v21 = 0;
      v8 = sub_86DB80((int)dword_F25F9C, 12963, 0);
      sub_52D240(&v25, (int)v8, (int)&v13, -1, 0);
      v9 = sub_476790();
      sub_476850(v9, &v25, 273, 1, 1, 0);
      sub_5EFD60(v2, v10, v11, 1.0, 0); // EQPlayer__ChangeHeight()
    }
*/

// double check offsets after patch!
#define EQ_OFFSET_SPAWN_PREVIOUS         0x04     // uint32_t pointer
#define EQ_OFFSET_SPAWN_NEXT             0x08     // uint32_t pointer
#define EQ_OFFSET_SPAWN_LAST_NAME        0x38     // 32 bytes
#define EQ_OFFSET_SPAWN_Y                0x64     // float
#define EQ_OFFSET_SPAWN_X                0x68     // float
#define EQ_OFFSET_SPAWN_Z                0x6C     // float
#define EQ_OFFSET_SPAWN_HEADING          0x80     // float
#define EQ_OFFSET_SPAWN_NAME_NUMBERED    0xA4     // 64 bytes
#define EQ_OFFSET_SPAWN_NAME             0xE4     // 64 bytes
#define EQ_OFFSET_SPAWN_TYPE             0x125    // uint8_t
#define EQ_OFFSET_SPAWN_HEIGHT           0x13C    // float
#define EQ_OFFSET_SPAWN_ID               0x148    // uint32_t
#define EQ_OFFSET_SPAWN_LEVEL            0x1C0    // uint8_t
#define EQ_OFFSET_SPAWN_FOLLOW_SPAWN     0xF20    // uint32_t pointer

#define EQ_SIZE_SPAWN_NAME         0x40 // 64 bytes
#define EQ_SIZE_SPAWN_LAST_NAME    0x20 // 32 bytes

#define EQ_SPAWN_TYPE_PLAYER    0x00
#define EQ_SPAWN_TYPE_NPC       0x01
#define EQ_SPAWN_TYPE_CORPSE    0x02

// class EQ_Character
DWORD EQ_ADDRESS_POINTER_PLAYER_CHARACTER    = 0x0; // psintCharData

DWORD EQ_ADDRESS_FUNCTION_EQ_Character__eqspa_movement_rate    = 0x0; // "*** EXITING: I have completed camping." and "Sending up a MSG_ONVEHICLE for vehicle %s.\n"
/*
if ( v94 - *(_DWORD *)(v112 + 900) > 1000 )
    {
      v113 = v94 - *(_DWORD *)(v112 + 900);
      *(_DWORD *)(v112 + 900) = v94;
      if ( !*(_BYTE *)(*(_DWORD *)(v6 + 8) + 293) )
      {
        sub_463A90(v6);
        v114 = (*(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v6 + 4) + 4) + v6 + 4) + 64))(*(_DWORD *)(*(_DWORD *)(v6 + 4) + 4) + v6 + 4);
        sub_4B6C70(v114, v113);
        v115 = sub_44F860(99, 1, 0, 1, 1);
        v116 = v6;
        if ( v115 >= 0 )
        {
          v115 = sub_44F860(3, 1, 0, 1, 1);
          v116 = v6;
        }
        sub_450400(v116, v115); // EQ_Character__eqspa_movement_rate
        sub_5D9D20();
        HIBYTE(word_F2FB24) = 1;
        if ( (char *)dword_F21FFC != PlayerSpawn____dword_F21FE8 )
          LOBYTE(word_F2FB24) = 1;
        sub_5CC8F0(v222);
        sub_46D100(v6);
        sub_462FD0(v6);
        v117 = *(_DWORD *)(v6 + 8);
        if ( !v117 )
        {
          v135 = v215;
          v136 = v215 == 0;
          goto LABEL_478;
        }
*/

// class CXWndManager
DWORD EQ_ADDRESS_POINTER_CXWndManager    = 0x1732E90; // pinstCXWndManager

DWORD EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x8CA260; // "DoAllDrawing() failed\n"

// class CEverQuest
DWORD EQ_ADDRESS_POINTER_CEverQuest    = 0x10C4438; // pinstCEverQuest
/*
CEverQuest__InterpretCmd()
if ( *(_DWORD *)(dword_10C1418 + 1480) == 5 ) // gamestate == in-game
*/

#define EQ_OFFSET_CEverQuest_GAME_STATE    0x5C8 // 1480

#define EQ_GAME_STATE_IN_GAME 5

DWORD EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd    = 0x56B890; // "#%s %s"
/*
CEverQuest__InterpretCmd()
switch ( byte_F334A0 )
{
case 2:
    sub_52DBF0(a2, &v23);
    break;
case 0xF:
    sub_4AFBC0(&v23);
    break;
case 0:
    sub_52B450(a2, &v23);
    break;
case 7:
    sprintf(&v27, "%s %s", &byte_F334A8, &v23);
    sub_52DD60(a2, &v27);
    break;
case 4:
    sub_52DD00(a2, &v23);
    break;
case 5:
    sub_52DD30(a2, &v23);
    break;
case 0x14:
    sprintf(&v26, "#%s %s", &byte_F334A8, &v23);
    sub_53E4D0(a2, &v26);
    break;
case 0x15:
    sub_52B470(a2, &v23);
    break;
default:
    sub_54BA30(a2, &v23);
    break;
}
*/

DWORD EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat        = 0x476560;
/*
CEverQuest__InterpretCmd()
sub_4764B0(v9, v8, 273, 1, 1, 0); // CEverQuest__dsp_chat
*/

#define EQ_CHAT_TEXT_COLOR_YELLOW    15

// class CDisplay
DWORD EQ_ADDRESS_POINTER_CDisplay    = 0xF25038; // pinstCDisplay    "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. "

#define EQ_OFFSET_CDisplay_CAMERA    0x118 // uint32_t pointer
#define EQ_OFFSET_CDisplay_TIMER     0x154 // uint32_t

#define EQ_OFFSET_CAMERA_FIELD_OF_VIEW                 0x04 // float
#define EQ_OFFSET_CAMERA_ASPECT_RATIO                  0x08 // float
#define EQ_OFFSET_CAMERA_UNKNOWN_0x0C                  0x0C // float, 0.0 to 1.0
#define EQ_OFFSET_CAMERA_DRAW_DISTANCE                 0x14 // float
#define EQ_OFFSET_CAMERA_SCREEN_WIDTH_HALF             0x38 // float
#define EQ_OFFSET_CAMERA_SCREEN_HEIGHT_HALF            0x3C // float
#define EQ_OFFSET_CAMERA_HEADING                       0xB0 // float
#define EQ_OFFSET_CAMERA_PITCH                         0xB4 // float
#define EQ_OFFSET_CAMERA_UNKNOWN_0xB8                  0xB8 // float, rotation?
#define EQ_OFFSET_CAMERA_Y                             0xBC // float
#define EQ_OFFSET_CAMERA_X                             0xC0 // float
#define EQ_OFFSET_CAMERA_Z                             0xC4 // float

const float EQ_CAMERA_FIELD_OF_VIEW_DEFAULT    = 45.0f;

const float EQ_CAMERA_PITCH_DEFAULT    = -8.5f;      // center view
const float EQ_CAMERA_PITCH_MIN        = -136.5f;    // look down
const float EQ_CAMERA_PITCH_MAX        = 119.5f;     // look up

DWORD EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2    = 0x4C20C0; // "%ldms" and "%0.2f%%"
/*
DrawNetStatus()
((void (__cdecl *)(char *, _DWORD, _DWORD, signed int))sub_4C2200)(
      &v11,
      (unsigned __int16)a1,
      (unsigned __int16)a2,
      12)
*/

#define EQ_DRAW_TEXT_COLOR_BLACK         0  // ARGB 0xFF000000
#define EQ_DRAW_TEXT_COLOR_DEFAULT       1  // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_DARK_GREEN    2  // ARGB 0xFF008000
#define EQ_DRAW_TEXT_COLOR_DEFAULT_2     3  // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_DARK_BLUE     4  // ARGB 0xFF000080
#define EQ_DRAW_TEXT_COLOR_PINK          5  // ARGB 0xFFF000F0
#define EQ_DRAW_TEXT_COLOR_DARK_GRAY     6  // ARGB 0xFF808080
#define EQ_DRAW_TEXT_COLOR_WHITE_2       7  // ARGB 0xFFE0E0E0
#define EQ_DRAW_TEXT_COLOR_DEFAULT_3     8  // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_DEFAULT_4     9  // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_WHITE         10 // ARGB 0xFFF0F0F0
#define EQ_DRAW_TEXT_COLOR_DEFAULT_5     11 // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_GRAY          12 // ARGB 0xFFA0A0A0
#define EQ_DRAW_TEXT_COLOR_RED           13 // ARGB 0xFFF00000
#define EQ_DRAW_TEXT_COLOR_GREEN         14 // ARGB 0xFF00F000
#define EQ_DRAW_TEXT_COLOR_YELLOW        15 // ARGB 0xFFF0F000
#define EQ_DRAW_TEXT_COLOR_BLUE          16 // ARGB 0xFF0000F0
#define EQ_DRAW_TEXT_COLOR_BLUE_2        17 // ARGB 0xFF0000AF
#define EQ_DRAW_TEXT_COLOR_TEAL          18 // ARGB 0xFF00F0F0
#define EQ_DRAW_TEXT_COLOR_DEFAULT_6     19 // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_BLACK_2       20 // ARGB 0xFF000000