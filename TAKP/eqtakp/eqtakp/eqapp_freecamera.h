#pragma once

bool g_FreeCameraIsEnabled = false;

float g_FreeCameraMultiplier = 1.0f;

void EQAPP_FreeCamera_Toggle();
void EQAPP_FreeCamera_SetEnabled(bool bEnabled);
void EQAPP_FreeCamera_Execute();
bool EQAPP_FreeCamera_HandleEvent_ProcessKey(int keyID);
bool EQAPP_FreeCamera_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);

void EQAPP_FreeCamera_Toggle()
{
    if (g_FreeCameraIsEnabled == true)
    {
        EQAPP_FreeCamera_SetEnabled(false);
    }
    else
    {
        EQAPP_FreeCamera_SetEnabled(true);
    }
}

void EQAPP_FreeCamera_SetEnabled(bool bEnabled)
{
    uint32_t baseAddress = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dSetCameraLocation);

    uint32_t address = 0;
    DWORD oldProtection = 0;
    DWORD tempProtection = 0;

    if (bEnabled == true)
    {
        // NOP the instructions so that the game will not update the camera position

        address = baseAddress + 0x4B; // Camera Y
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90", 2, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, oldProtection, &tempProtection);

        address = baseAddress + 0x50; // Camera X
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90\x90", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);

        address = baseAddress + 0x56; // Camera Z
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90\x90", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);
    }
    else
    {
        // restore the instructions to their default values

        address = baseAddress + 0x4B; // Camera Y
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x01", 2, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, oldProtection, &tempProtection);

        address = baseAddress + 0x50; // Camera X
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x41\x04", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);

        address = baseAddress + 0x56; // Camera Z
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x51\x08", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);
    }

    if (bEnabled == true)
    {
        EQ_SetCameraView(EQ_CAMERA_VIEW_FIRST_PERSON);

        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            EQ_SetSpawnStandingState(playerSpawn, EQ_STANDING_STATE_STANDING);
        }
    }

    g_FreeCameraIsEnabled = bEnabled;

    EQAPP_PrintBool("Free Camera", g_FreeCameraIsEnabled);
}

void EQAPP_FreeCamera_Execute()
{
    if (EQAPP_IsForegroundWindowCurrentProcessId() == false)
    {
        return;
    }

    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    if (EQAPP_IsKeyDown(VK_CONTROL) == true)
    {
        g_FreeCameraMultiplier = 4.0f;
    }
    else
    {
        g_FreeCameraMultiplier = 1.0f;
    }

    if (EQAPP_IsKeyDown(VK_UP) == true)
    {
        float cameraY = camera->Y;
        float cameraX = camera->X;
        float cameraZ = camera->Z;

        float cameraHeading = camera->Heading;
        float cameraPitch   = camera->Pitch;

        cameraHeading = cameraHeading - 128.0f;

        EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = (float)(cameraPitch + fabs(EQ_CAMERA_PITCH_DEFAULT)); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = sinf(cameraHeadingRadians);
        float addX = cosf(cameraHeadingRadians);
        float addZ = sinf(cameraPitchRadians);

        if (fabs(cameraPitch) < 90.0f)
        {
            cameraY -= addY * g_FreeCameraMultiplier;
            cameraX += addX * g_FreeCameraMultiplier;
        }

        cameraZ += addZ * g_FreeCameraMultiplier;

        camera->Y = cameraY;
        camera->X = cameraX;
        camera->Z = cameraZ;
    }

    if (EQAPP_IsKeyDown(VK_DOWN) == true)
    {
        float cameraY = camera->Y;
        float cameraX = camera->X;
        float cameraZ = camera->Z;

        float cameraHeading = camera->Heading;
        float cameraPitch   = camera->Pitch;

        cameraHeading = cameraHeading - 128.0f;

        EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = (float)(cameraPitch + fabs(EQ_CAMERA_PITCH_DEFAULT)); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = sinf(cameraHeadingRadians);
        float addX = cosf(cameraHeadingRadians);
        float addZ = sinf(cameraPitchRadians);

        if (fabs(cameraPitch) < 90.0f)
        {
            cameraY += addY * g_FreeCameraMultiplier;
            cameraX -= addX * g_FreeCameraMultiplier;
        }

        cameraZ -= addZ * g_FreeCameraMultiplier;

        camera->Y = cameraY;
        camera->X = cameraX;
        camera->Z = cameraZ;
    }

    if (EQAPP_IsKeyDown(VK_LEFT) == true)
    {
        float cameraY = camera->Y;
        float cameraX = camera->X;
        float cameraZ = camera->Z;

        float cameraHeading = camera->Heading;
        float cameraPitch   = camera->Pitch;

        EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = (float)(cameraPitch + fabs(EQ_CAMERA_PITCH_DEFAULT)); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = sinf(cameraHeadingRadians);
        float addX = cosf(cameraHeadingRadians);
        float addZ = sinf(cameraPitchRadians);

        if (fabs(cameraPitch) < 90.0f)
        {
            cameraY -= addY * g_FreeCameraMultiplier;
            cameraX += addX * g_FreeCameraMultiplier;
        }

        cameraZ += addZ * g_FreeCameraMultiplier;

        camera->Y = cameraY;
        camera->X = cameraX;
        camera->Z = cameraZ;
    }

    if (EQAPP_IsKeyDown(VK_RIGHT) == true)
    {
        float cameraY = camera->Y;
        float cameraX = camera->X;
        float cameraZ = camera->Z;

        float cameraHeading = camera->Heading;
        float cameraPitch   = camera->Pitch;

        cameraHeading = cameraHeading + 256.0f;

        EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = (float)(cameraPitch + fabs(EQ_CAMERA_PITCH_DEFAULT)); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = sinf(cameraHeadingRadians);
        float addX = cosf(cameraHeadingRadians);
        float addZ = sinf(cameraPitchRadians);

        if (fabs(cameraPitch) < 90.0f)
        {
            cameraY -= addY * g_FreeCameraMultiplier;
            cameraX += addX * g_FreeCameraMultiplier;
        }

        cameraZ += addZ * g_FreeCameraMultiplier;

        camera->Y = cameraY;
        camera->X = cameraX;
        camera->Z = cameraZ;
    }
}

bool EQAPP_FreeCamera_HandleEvent_ProcessKey(int keyID)
{
    if (keyID == EQ_KEY_UP_ARROW || keyID == EQ_KEY_DOWN_ARROW || keyID == EQ_KEY_LEFT_ARROW || keyID == EQ_KEY_RIGHT_ARROW || keyID == EQ_KEY_NUMLOCK)
    {
        return true;
    }

    return false;
}

bool EQAPP_FreeCamera_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero)
{
    if (isActive != 1 && zero != 0)
    {
        return false;
    }

    if
    (
        commandID == EQ_EXECUTECMD_TOGGLECAM  ||
        commandID == EQ_EXECUTECMD_FORWARD    ||
        commandID == EQ_EXECUTECMD_BACK       ||
        commandID == EQ_EXECUTECMD_LEFT       ||
        commandID == EQ_EXECUTECMD_RIGHT      ||
        commandID == EQ_EXECUTECMD_JUMP       ||
        commandID == EQ_EXECUTECMD_AUTORUN
    )
    {
        return true;
    }

    return false;
}

