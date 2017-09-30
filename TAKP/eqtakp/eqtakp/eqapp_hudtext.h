#pragma once

bool g_HUDTextIsEnabled = true;

uint32_t g_HUDTextX = 200;
uint32_t g_HUDTextY = 24;

void EQAPP_HUDText_Toggle();
void EQAPP_HUDText_Execute();

void EQAPP_HUDText_Toggle()
{
    EQ_ToggleBool(g_HUDTextIsEnabled);
    EQAPP_PrintBool("HUD Text", g_HUDTextIsEnabled);
}

void EQAPP_HUDText_Execute()
{
    std::stringstream text;

    uint32_t numPlayersInZone = EQ_GetNumPlayersInZone();
    if (numPlayersInZone > 0)
    {
        text << "Players in Zone: " << numPlayersInZone << "\n";
    }

    if (g_boxChatIsConnected == true)
    {
        text << "Box Chat is connected.\n";
    }

    if (g_hotButtonKeysIsEnabled == true)
    {
        if (g_hotButtonKeysModifier == VK_ALT)
        {
            text << "Hot Button Keys: ALT\n";
        }
        else if (g_hotButtonKeysModifier == VK_CONTROL)
        {
            text << "Hot Button Keys: CONTROL\n";
        }
        else if (g_hotButtonKeysModifier == VK_SHIFT)
        {
            text << "Hot Button Keys: SHIFT\n";
        }
    }

    if (g_alwaysAttackIsEnabled == true)
    {
        text << "Always Attack: On\n";
    }

    if (g_foodAndDrinkIsEnabled == true)
    {
        text << "Food and Drink: On\n";
    }

    if (g_freeCameraIsEnabled == true)
    {
        text << "Free Camera: On\n";
    }

    if (g_collisionHackIsEnabled == true)
    {
        text << "Collision Hack: On\n";
    }

    if (g_trainSpellsIsEnabled == true)
    {
        text << "Train Spells: On\n";
        text << "Train Spell: " << g_trainSpellsSpellName << "\n";
    }

    EQ_DrawText(text.str().c_str(), g_HUDTextX, g_HUDTextY, EQ_COLOR_ARGB_WHITE);
}