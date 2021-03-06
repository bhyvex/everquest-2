#pragma once

bool g_GUIMapWindowIsEnabled = false;

bool g_GUIMapWindowMapLinesIsEnabled = true;
bool g_GUIMapWindowMapLabelsIsEnabled = false;
bool g_GUIMapWindowMapSpawnsIsEnabled = true;

bool g_GUIMapWindowMapHeightFilterLinesIsEnabled = false;
bool g_GUIMapWindowMapHeightFilterLabelsIsEnabled = false;
bool g_GUIMapWindowMapHeightFilterSpawnsIsEnabled = false;

bool g_GUIMapWindowMapLayer0IsEnabled = true;
bool g_GUIMapWindowMapLayer1IsEnabled = true;
bool g_GUIMapWindowMapLayer2IsEnabled = false;
bool g_GUIMapWindowMapLayer3IsEnabled = false;

bool g_GUIMapWindowMapScaleToZoomIsEnabled = true;

bool g_GUIMapWindowMapSpawnsPlayerIsEnabled = true;
bool g_GUIMapWindowMapSpawnsNPCIsEnabled = true;
bool g_GUIMapWindowMapSpawnsCorpseIsEnabled = true;
bool g_GUIMapWindowMapSpawnsPetIsEnabled = true;
bool g_GUIMapWindowMapSpawnsMercenaryIsEnabled = true;

ImColor g_GUIMapWindowMapBorderColor = ImColor(1.0f, 1.0f, 1.0f, 1.0f); // white

ImColor g_GUIMapWindowMapSpawnDefaultColor        = ImColor(1.0f, 1.0f, 1.0f, 1.0f); // white
ImColor g_GUIMapWindowMapSpawnYouColor            = ImColor(1.0f, 0.5f, 0.0f, 1.0f); // orange
ImColor g_GUIMapWindowMapSpawnPlayerColor         = ImColor(1.0f, 0.0f, 0.0f, 1.0f); // red
ImColor g_GUIMapWindowMapSpawnNPCColor            = ImColor(0.0f, 1.0f, 1.0f, 1.0f); // cyan
ImColor g_GUIMapWindowMapSpawnCorpseColor         = ImColor(1.0f, 1.0f, 0.0f, 1.0f); // yellow
ImColor g_GUIMapWindowMapSpawnMercenaryColor      = ImColor(0.5f, 0.0f, 0.0f, 1.0f); // dark red
ImColor g_GUIMapWindowMapSpawnPetColor            = ImColor(0.0f, 0.5f, 0.5f, 1.0f); // dark cyan
ImColor g_GUIMapWindowMapSpawnGroupMemberColor    = ImColor(0.0f, 1.0f, 0.0f, 1.0f); // green
ImColor g_GUIMapWindowMapSpawnTargetColor         = ImColor(1.0f, 0.0f, 1.0f, 1.0f); // magenta

bool g_GUIMapWindowMapSpawnMouseHover = false;
bool g_GUIMapWindowMapSpawnMouseHoverDrawCircle = false;

ImColor g_GUIMapWindowMapSpawnMouseHoverColor        = ImColor(1.0f, 1.0f, 0.0f, 1.0f); // yellow
ImColor g_GUIMapWindowMapSpawnMouseHoverBackColor    = ImColor(0.0f, 0.0f, 0.0f, 1.0f); // black

float g_GUIMapWindowX = 0.0f;
float g_GUIMapWindowY = 0.0f;

float g_GUIMapWindowAlphaActive = 1.0f;
float g_GUIMapWindowAlphaInactive = 0.8f;

float g_GUIMapWindowMapX = 0.0f;
float g_GUIMapWindowMapY = 0.0f;

float g_GUIMapWindowMapWidth  = 500.0f;
float g_GUIMapWindowMapHeight = 400.0f;

float g_GUIMapWindowMapMinX = g_GUIMapWindowMapX;
float g_GUIMapWindowMapMaxX = g_GUIMapWindowMapX + g_GUIMapWindowMapWidth;

float g_GUIMapWindowMapMinY = g_GUIMapWindowMapY;
float g_GUIMapWindowMapMaxY = g_GUIMapWindowMapY + g_GUIMapWindowMapHeight;

float g_GUIMapWindowMapOriginX = g_GUIMapWindowMapX + (g_GUIMapWindowMapWidth  * 0.5f);
float g_GUIMapWindowMapOriginY = g_GUIMapWindowMapY + (g_GUIMapWindowMapHeight * 0.5f);

float g_GUIMapWindowMapOffsetX = 0.0f;
float g_GUIMapWindowMapOffsetY = 0.0f;

float g_GUIMapWindowMapHeightFilterLow  = 10.0f; // z axis
float g_GUIMapWindowMapHeightFilterHigh = 10.0f; // z axis

float g_GUIMapWindowMapZoom           = 1.0f;
float g_GUIMapWindowMapZoomMultiplier = 0.05f; // zoom speed
float g_GUIMapWindowMapZoomDefault    = 1.0f;
float g_GUIMapWindowMapZoomMinimum    = 10.0f;
float g_GUIMapWindowMapZoomMaximum    = 0.01f;

float g_GUIMapWindowMapMouseWheelZoomMultiplier = 0.5f; // mouse wheel zoom speed

float g_GUIMapWindowMapMouseCursorSize = 16.0f;

float g_GUIMapWindowMapTextHeightOffset = 5.0f;

float g_GUIMapWindowMapLabelCircleSize = 4.0f;
float g_GUIMapWindowMapSpawnCircleSize = 4.0f;

float g_GUIMapWindowMapArrowSize = 20.0f;

float g_GUIMapWindowMapSpawnClickDistance = 400.0f;

LPDIRECT3DTEXTURE9 g_GUIMapWindowMapBackgroundTexture = NULL;

static void EQAPP_GUI_MapWindow();
static void EQAPP_GUI_MapWindow_LoadTextures();
static void EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(float x, float y, float& screenX, float& screenY);
static void EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPositionEx(float x, float y, float& screenX, float& screenY, float zoom);
static bool EQAPP_GUI_MapWindow_Map_IsPointInsideMap(int x, int y);
static void EQAPP_GUI_MapWindow_Map_ZoomOut();
static void EQAPP_GUI_MapWindow_Map_ZoomIn();
static void EQAPP_GUI_MapWindow_Map_MouseWheelZoomOut();
static void EQAPP_GUI_MapWindow_Map_MouseWheelZoomIn();
static void EQAPP_GUI_MapWindow_Map_SetZoom(float zoom);
static void EQAPP_GUI_MapWindow_Map_ResetZoom();
static void EQAPP_GUI_MapWindow_Map_Scroll(float deltaX, float deltaY);
static void EQAPP_GUI_MapWindow_Map_Center();
static void EQAPP_GUI_MapWindow_Map_DrawSpawnArrow(uint32_t spawn, ImColor& color);
static void EQAPP_GUI_MapWindow_Map_Draw();
static void EQAPP_GUI_MapWindow_Map_PrintDebugInformation();

static void EQAPP_GUI_MapWindow()
{
    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true || io.WantCaptureKeyboard == true)
    {
       ImGui::PushStyleVar(ImGuiStyleVar_Alpha, g_GUIMapWindowAlphaActive);
    }
    else
    {
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, g_GUIMapWindowAlphaInactive);
    }

    ImGui::SetNextWindowPos(ImVec2(g_GUIMapWindowX, g_GUIMapWindowY), ImGuiCond_Once);

    if (ImGui::Begin("Map##MapWindow", &g_GUIMapWindowIsEnabled, ImGuiWindowFlags_MenuBar) == false)
    {
        ImGui::End();
        return;
    }

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File##MapWindowMenuFile"))
        {
            if (ImGui::MenuItem("Print Debug Information##MapWindowMenuItemFilePrintDebugInformation")) EQAPP_GUI_MapWindow_Map_PrintDebugInformation();

            ImGui::Separator();

            if (ImGui::MenuItem("Close##MapWindowMenuItemFileClose")) g_GUIMapWindowIsEnabled = false;

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("View##MapWindowMenuView"))
        {
            if (ImGui::MenuItem("Reset Zoom##MapWindowMenuItemViewResetZoom")) EQAPP_GUI_MapWindow_Map_ResetZoom();
            if (ImGui::MenuItem("Center##MapWindowMenuItemViewCenter")) EQAPP_GUI_MapWindow_Map_Center();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Options##MapWindowMenuOptions"))
        {
            if (ImGui::MenuItem("Base Layer##MapWindowMenuItemOptionsLayer0", NULL, &g_GUIMapWindowMapLayer0IsEnabled)) {}
            if (ImGui::MenuItem("Layer 1##MapWindowMenuItemOptionsLayer1", NULL, &g_GUIMapWindowMapLayer1IsEnabled)) {}
            if (ImGui::MenuItem("Layer 2##MapWindowMenuItemOptionsLayer2", NULL, &g_GUIMapWindowMapLayer2IsEnabled)) {}
            if (ImGui::MenuItem("Layer 3##MapWindowMenuItemOptionsLayer3", NULL, &g_GUIMapWindowMapLayer3IsEnabled)) {}

            ImGui::Separator();

            if (ImGui::MenuItem("Lines##MapWindowMenuItemOptionsLines", NULL, &g_GUIMapWindowMapLinesIsEnabled)) {}
            if (ImGui::MenuItem("Labels##MapWindowMenuItemOptionsLabels", NULL, &g_GUIMapWindowMapLabelsIsEnabled)) {}
            if (ImGui::MenuItem("Spawns##MapWindowMenuItemOptionsSpawns", NULL, &g_GUIMapWindowMapSpawnsIsEnabled)) {}

            ImGui::Separator();

            if (ImGui::MenuItem("Height Filter for Lines##MapWindowMenuItemOptionsHeightFilterForLines", NULL, &g_GUIMapWindowMapHeightFilterLinesIsEnabled)) {}
            if (ImGui::MenuItem("Height Filter for Labels##MapWindowMenuItemOptionsHeightFilterForLabels", NULL, &g_GUIMapWindowMapHeightFilterLabelsIsEnabled)) {}
            if (ImGui::MenuItem("Height Filter for Spawns##MapWindowMenuItemOptionsHeightFilterForSpawns", NULL, &g_GUIMapWindowMapHeightFilterSpawnsIsEnabled)) {}

            ImGui::Separator();

            if (ImGui::MenuItem("Scale to Zoom##MapWindowMenuItemOptionsScaleToZoom", NULL, &g_GUIMapWindowMapScaleToZoomIsEnabled)) {}

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Spawns##MapWindowMenuSpawns"))
        {
            if (ImGui::MenuItem("Player##MapWindowMenuItemSpawnsPlayer", NULL, &g_GUIMapWindowMapSpawnsPlayerIsEnabled)) {}
            if (ImGui::MenuItem("NPC##MapWindowMenuItemSpawnsNPC", NULL, &g_GUIMapWindowMapSpawnsNPCIsEnabled)) {}
            if (ImGui::MenuItem("Corpse##MapWindowMenuItemSpawnsCorpse", NULL, &g_GUIMapWindowMapSpawnsCorpseIsEnabled)) {}

            ImGui::Separator();

            if (ImGui::MenuItem("Mercenary##MapWindowMenuItemSpawnsMercenary", NULL, &g_GUIMapWindowMapSpawnsMercenaryIsEnabled)) {}
            if (ImGui::MenuItem("Pet##MapWindowMenuItemSpawnsPet", NULL, &g_GUIMapWindowMapSpawnsPetIsEnabled)) {}

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Colors##MapWindowMenuColors"))
        {
            ImGui::ColorEdit4("Player##MapWindowColorEditSpawnPlayer", (float*)&g_GUIMapWindowMapSpawnPlayerColor.Value, ImGuiColorEditFlags_NoInputs);
            ImGui::ColorEdit4("NPC##MapWindowColorEditSpawnNPC", (float*)&g_GUIMapWindowMapSpawnNPCColor.Value, ImGuiColorEditFlags_NoInputs);
            ImGui::ColorEdit4("Corpse##MapWindowColorEditSpawnCorpse", (float*)&g_GUIMapWindowMapSpawnCorpseColor.Value, ImGuiColorEditFlags_NoInputs);

            ImGui::Separator();

            ImGui::ColorEdit4("Mercenary##MapWindowColorEditSpawnMercenary", (float*)&g_GUIMapWindowMapSpawnMercenaryColor.Value, ImGuiColorEditFlags_NoInputs);
            ImGui::ColorEdit4("Pet##MapWindowColorEditSpawnPet", (float*)&g_GUIMapWindowMapSpawnPetColor.Value, ImGuiColorEditFlags_NoInputs);

            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    ImVec2 mapSize = ImGui::GetContentRegionAvail();

    ImGui::BeginChild("##MapWindowChildMap", ImVec2(mapSize.x, mapSize.y), false, ImGuiWindowFlags_NoMove);

    EQAPP_GUI_MapWindow_Map_Draw();

    ImGui::EndChild();

    ImGui::End();
}

static void EQAPP_GUI_MapWindow_LoadTextures()
{
    g_GUIMapWindowMapBackgroundTexture = NULL;

    auto render = EQ_GetRender();
    if (render == NULL)
    {
        return;
    }

    auto devicePointer = EQ_ReadMemory<LPDIRECT3DDEVICE9>(render + EQ_OFFSET_CRender_Direct3DDevicePointer);
    if (devicePointer == NULL)
    {
        return;
    }

    HRESULT result = D3DXCreateTextureFromFile(devicePointer, L"uifiles\\default\\cart.tga", &g_GUIMapWindowMapBackgroundTexture);
    if (result != D3D_OK)
    {
        std::cout << "D3DXCreateTextureFromFile() failed!" << std::endl;
    }
}

static void EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(float x, float y, float& screenX, float& screenY)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);

    screenX = (((x * g_GUIMapWindowMapZoom) + g_GUIMapWindowMapOriginX) + ((playerSpawnX + g_GUIMapWindowMapOffsetX) * g_GUIMapWindowMapZoom));
    screenY = (((y * g_GUIMapWindowMapZoom) + g_GUIMapWindowMapOriginY) + ((playerSpawnY + g_GUIMapWindowMapOffsetY) * g_GUIMapWindowMapZoom));
}

static void EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPositionEx(float x, float y, float& screenX, float& screenY, float zoom)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);

    screenX = (((x * zoom) + g_GUIMapWindowMapOriginX) + ((playerSpawnX + g_GUIMapWindowMapOffsetX) * zoom));
    screenY = (((y * zoom) + g_GUIMapWindowMapOriginY) + ((playerSpawnY + g_GUIMapWindowMapOffsetY) * zoom));
}

static bool EQAPP_GUI_MapWindow_Map_IsPointInsideMap(int x, int y)
{
    return EQ_IsPointInsideRectangle(x, y, (int)g_GUIMapWindowMapX, (int)g_GUIMapWindowMapY, (int)g_GUIMapWindowMapWidth, (int)g_GUIMapWindowMapHeight) == true;
}

static void EQAPP_GUI_MapWindow_Map_ZoomOut()
{
    g_GUIMapWindowMapZoom -= g_GUIMapWindowMapZoom * g_GUIMapWindowMapZoomMultiplier;

    if (g_GUIMapWindowMapZoom <= g_GUIMapWindowMapZoomMaximum)
    {
        g_GUIMapWindowMapZoom = g_GUIMapWindowMapZoomMaximum;
    }
}

static void EQAPP_GUI_MapWindow_Map_ZoomIn()
{
    g_GUIMapWindowMapZoom += g_GUIMapWindowMapZoom * g_GUIMapWindowMapZoomMultiplier;

    if (g_GUIMapWindowMapZoom >= g_GUIMapWindowMapZoomMinimum)
    {
        g_GUIMapWindowMapZoom = g_GUIMapWindowMapZoomMinimum;
    }
}

static void EQAPP_GUI_MapWindow_Map_MouseWheelZoomOut()
{
    g_GUIMapWindowMapZoom -= g_GUIMapWindowMapZoom * g_GUIMapWindowMapMouseWheelZoomMultiplier;

    if (g_GUIMapWindowMapZoom <= g_GUIMapWindowMapZoomMaximum)
    {
        g_GUIMapWindowMapZoom = g_GUIMapWindowMapZoomMaximum;
    }
}

static void EQAPP_GUI_MapWindow_Map_MouseWheelZoomIn()
{
    g_GUIMapWindowMapZoom += g_GUIMapWindowMapZoom * g_GUIMapWindowMapMouseWheelZoomMultiplier;

    if (g_GUIMapWindowMapZoom >= g_GUIMapWindowMapZoomMinimum)
    {
        g_GUIMapWindowMapZoom = g_GUIMapWindowMapZoomMinimum;
    }
}

static void EQAPP_GUI_MapWindow_Map_SetZoom(float zoom)
{
    g_GUIMapWindowMapZoom = zoom;
}

static void EQAPP_GUI_MapWindow_Map_ResetZoom()
{
    g_GUIMapWindowMapZoom = 1.0f;
}

static void EQAPP_GUI_MapWindow_Map_Scroll(float deltaX, float deltaY)
{
    if (deltaX != 0.0f)
    {
        if (g_GUIMapWindowMapZoom != 0.0f)
        {
            deltaX = deltaX / g_GUIMapWindowMapZoom;
        }

        g_GUIMapWindowMapOffsetX += deltaX;
    }

    if (deltaY != 0.0f)
    {
        if (g_GUIMapWindowMapZoom != 0.0f)
        {
            deltaY = deltaY / g_GUIMapWindowMapZoom;
        }

        g_GUIMapWindowMapOffsetY += deltaY;
    }
}

static void EQAPP_GUI_MapWindow_Map_Center()
{
    g_GUIMapWindowMapOffsetX = 0.0f;
    g_GUIMapWindowMapOffsetY = 0.0f;
}

static void EQAPP_GUI_MapWindow_Map_DrawSpawnArrow(uint32_t spawn, ImColor& color)
{
    float arrowZoom = g_GUIMapWindowMapZoom;

    if (g_GUIMapWindowMapScaleToZoomIsEnabled == false)
    {
        arrowZoom = 1.0f;
    }
    else
    {
        if (g_GUIMapWindowMapZoom < 1.0f)
        {
            arrowZoom = 1.0f;
        }
    }

    float arrowSize = g_GUIMapWindowMapArrowSize * arrowZoom;

    // spawn

    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);

    auto spawnHeading = EQ_GetSpawnHeading(spawn);

    spawnHeading = spawnHeading + EQ_HEADING_MAX_HALF;

    spawnHeading = EQ_FixHeading(spawnHeading);

    float spawnMapX = 0.0f;
    float spawnMapY = 0.0f;
    EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPositionEx(-spawnX, -spawnY, spawnMapX, spawnMapY, g_GUIMapWindowMapZoom);

    // line1

    float line1BeginMapX = spawnMapX;
    float line1BeginMapY = spawnMapY;

    float line1EndMapX = line1BeginMapX;
    float line1EndMapY = line1BeginMapY;

    EQ_ApplyForwardMovement(line1EndMapY, line1EndMapX, spawnHeading, arrowSize);

    // line 2

    float line2BeginMapX = line1EndMapX;
    float line2BeginMapY = line1EndMapY;

    float line2EndMapX = line2BeginMapX;
    float line2EndMapY = line2BeginMapY;

    EQ_ApplyBackwardMovement(line2EndMapY, line2EndMapX, spawnHeading, arrowSize * 0.5f);
    EQ_ApplyLeftwardMovement(line2EndMapY, line2EndMapX, spawnHeading, arrowSize * 0.25f);

    // line 3

    float line3BeginMapX = line1EndMapX;
    float line3BeginMapY = line1EndMapY;

    float line3EndMapX = line3BeginMapX;
    float line3EndMapY = line3BeginMapY;

    EQ_ApplyBackwardMovement(line3EndMapY, line3EndMapX, spawnHeading, arrowSize * 0.5f);
    EQ_ApplyRightwardMovement(line3EndMapY, line3EndMapX, spawnHeading, arrowSize * 0.25f);

    // draw lines

    ImDrawList* drawList = ImGui::GetWindowDrawList();

    drawList->AddLine(ImVec2(line1BeginMapX, line1BeginMapY), ImVec2(line1EndMapX, line1EndMapY), color);
    drawList->AddLine(ImVec2(line2BeginMapX, line2BeginMapY), ImVec2(line2EndMapX, line2EndMapY), color);
    drawList->AddLine(ImVec2(line3BeginMapX, line3BeginMapY), ImVec2(line3EndMapX, line3EndMapY), color);
}

static void EQAPP_GUI_MapWindow_Map_Draw()
{
    ImGuiIO& io = ImGui::GetIO();

    if (ImGui::IsWindowHovered() == true)
    {
        if (EQAPP_GUI_MapWindow_Map_IsPointInsideMap((int)io.MousePos.x, (int)io.MousePos.y) == true)
        {
            if (io.MouseWheel < 0.0f)
            {
                EQAPP_GUI_MapWindow_Map_MouseWheelZoomOut();
            }
            else if (io.MouseWheel > 0.0f)
            {
                EQAPP_GUI_MapWindow_Map_MouseWheelZoomIn();
            }

            if (g_GUIMapWindowMapSpawnMouseHover == false)
            {
                if (ImGui::IsMouseDragging(0, 0.001f) == true)
                {
                    ImGui::SetMouseCursor(ImGuiMouseCursor_ResizeAll);

                    EQAPP_GUI_MapWindow_Map_Scroll(io.MouseDelta.x, io.MouseDelta.y);
                }
            }

            // middle click
            if (io.MouseDown[2] == true)
            {
                EQAPP_GUI_MapWindow_Map_ResetZoom();
                EQAPP_GUI_MapWindow_Map_Center();
            }
        }
    }

    uint32_t drawCount = 0;

    ImVec2 drawPosition = ImGui::GetCursorScreenPos();

    g_GUIMapWindowMapX = drawPosition.x;
    g_GUIMapWindowMapY = drawPosition.y;

    ImVec2 mapSize = ImGui::GetContentRegionAvail();

    g_GUIMapWindowMapWidth = mapSize.x;
    g_GUIMapWindowMapHeight = mapSize.y;

    g_GUIMapWindowMapMinX = g_GUIMapWindowMapX;
    g_GUIMapWindowMapMaxX = g_GUIMapWindowMapX + g_GUIMapWindowMapWidth;

    g_GUIMapWindowMapMinY = g_GUIMapWindowMapY;
    g_GUIMapWindowMapMaxY = g_GUIMapWindowMapY + g_GUIMapWindowMapHeight;

    g_GUIMapWindowMapOriginX = g_GUIMapWindowMapX + (g_GUIMapWindowMapWidth  * 0.5f);
    g_GUIMapWindowMapOriginY = g_GUIMapWindowMapY + (g_GUIMapWindowMapHeight * 0.5f);

    float spawnCircleSize = g_GUIMapWindowMapSpawnCircleSize;

    if (g_GUIMapWindowMapScaleToZoomIsEnabled == true)
    {
        if (g_GUIMapWindowMapZoom != 0.0f)
        {
            spawnCircleSize = spawnCircleSize * g_GUIMapWindowMapZoom;

            if (spawnCircleSize < 1.0f)
            {
                spawnCircleSize = 1.0f;
            }
        }
    }

    auto targetSpawn = EQ_GetTargetSpawn();

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    float playerMapX = 0.0f;
    float playerMapY = 0.0f;
    EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(-playerSpawnX, -playerSpawnY, playerMapX, playerMapY);

    ImDrawList* drawList = ImGui::GetWindowDrawList();

    drawList->PushClipRect(ImVec2(g_GUIMapWindowMapX, g_GUIMapWindowMapY), ImVec2(g_GUIMapWindowMapMaxX, g_GUIMapWindowMapMaxY), true);

    if (g_GUIMapWindowMapLinesIsEnabled == true)
    {
        auto mapLines = EQ_MapWindow_GetLines();
        if (mapLines != NULL)
        {
            EQ::MapLine_ptr mapLine = (EQ::MapLine_ptr)mapLines;
            while (mapLine != NULL)
            {
                if (g_GUIMapWindowMapLayer0IsEnabled == false)
                {
                    if (mapLine->Layer == 0)
                    {
                        mapLine = mapLine->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer1IsEnabled == false)
                {
                    if (mapLine->Layer == 1)
                    {
                        mapLine = mapLine->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer2IsEnabled == false)
                {
                    if (mapLine->Layer == 2)
                    {
                        mapLine = mapLine->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer3IsEnabled == false)
                {
                    if (mapLine->Layer == 3)
                    {
                        mapLine = mapLine->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapHeightFilterLinesIsEnabled == true)
                {
                    if (g_GUIMapWindowMapHeightFilterLow > 0.0f)
                    {
                        if
                        (
                            mapLine->Begin.Z < (playerSpawnZ - g_GUIMapWindowMapHeightFilterLow) ||
                            mapLine->End.Z   < (playerSpawnZ - g_GUIMapWindowMapHeightFilterLow)
                        )
                        {
                            mapLine = mapLine->Next;
                            continue;
                        }
                    }

                    if (g_GUIMapWindowMapHeightFilterHigh > 0.0f)
                    {
                        if
                        (
                            mapLine->Begin.Z > (playerSpawnZ + g_GUIMapWindowMapHeightFilterHigh) ||
                            mapLine->End.Z   > (playerSpawnZ + g_GUIMapWindowMapHeightFilterHigh)
                        )
                        {
                            mapLine = mapLine->Next;
                            continue;
                        }
                    }
                }

                float lineBeginX = 0.0f;
                float lineBeginY = 0.0f;
                EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(mapLine->Begin.X, mapLine->Begin.Y, lineBeginX, lineBeginY);

                float lineEndX = 0.0f;
                float lineEndY = 0.0f;
                EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(mapLine->End.X, mapLine->End.Y, lineEndX, lineEndY);

                if (EQAPP_GUI_MapWindow_Map_IsPointInsideMap((int)lineBeginX, (int)lineBeginY) == false)
                {
                    if (EQAPP_GUI_MapWindow_Map_IsPointInsideMap((int)lineEndX, (int)lineEndY) == false)
                    {
                        mapLine = mapLine->Next;
                        continue;
                    }
                }

                ImColor lineColor = ImColor(mapLine->Color.R, mapLine->Color.G, mapLine->Color.B, mapLine->Color.A);

                // convert black lines to white lines
                if (lineColor.Value.x == 0 && lineColor.Value.y == 0 && lineColor.Value.z == 0)
                {
                    lineColor.Value.x = 1;
                    lineColor.Value.y = 1;
                    lineColor.Value.z = 1;
                }

                drawList->AddLine(ImVec2(lineBeginX, lineBeginY), ImVec2(lineEndX, lineEndY), lineColor);
                drawCount++;

                mapLine = mapLine->Next;
            }
        }
    }

    if (g_GUIMapWindowMapSpawnsIsEnabled == true)
    {
        g_GUIMapWindowMapSpawnMouseHover = false;
        g_GUIMapWindowMapSpawnMouseHoverDrawCircle = false;

        float spawnMouseHoverX = 0.0f;
        float spawnMouseHoverY = 0.0f;
        std::string spawnMouseHoverText = std::string();
        ImVec2 spawnMouseHoverTextSize;

        auto spawn = EQ_GetFirstSpawn();
        while (spawn != NULL)
        {
            if (spawn == playerSpawn)
            {
                spawn = EQ_GetSpawnNext(spawn);
                continue;
            }

            bool spawnIsGroupMember = EQ_IsSpawnGroupMember(spawn);
            bool spawnIsMercenary = EQ_IsSpawnMercenary(spawn);
            bool spawnIsPet = EQ_IsSpawnPet(spawn);

            auto spawnType = EQ_GetSpawnType(spawn);

            if (spawnType == EQ_SPAWN_TYPE_PLAYER)
            {
                if (g_GUIMapWindowMapSpawnsPlayerIsEnabled == false)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }
            }
            else if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (g_GUIMapWindowMapSpawnsNPCIsEnabled == false)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }

                if (EQ_IsSpawnMount(spawn) == true)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }

                if (EQ_IsSpawnAura(spawn) == true)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }
            }
            else if (spawnType == EQ_SPAWN_TYPE_CORPSE)
            {
                if (g_GUIMapWindowMapSpawnsCorpseIsEnabled == false)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }
            }

            if (spawnIsMercenary == true)
            {
                if (g_GUIMapWindowMapSpawnsMercenaryIsEnabled == false)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }
            }

            if (spawnIsPet == true)
            {
                if (g_GUIMapWindowMapSpawnsPetIsEnabled == false)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }
            }

            auto spawnY = EQ_GetSpawnY(spawn);
            auto spawnX = EQ_GetSpawnX(spawn);
            auto spawnZ = EQ_GetSpawnZ(spawn);

            if (g_GUIMapWindowMapHeightFilterSpawnsIsEnabled == true)
            {
                if (g_GUIMapWindowMapHeightFilterLow > 0.0f)
                {
                    if (spawnZ < (playerSpawnZ - g_GUIMapWindowMapHeightFilterLow))
                    {
                        spawn = EQ_GetSpawnNext(spawn);
                        continue;
                    }
                }

                if (g_GUIMapWindowMapHeightFilterHigh > 0.0f)
                {
                    if (spawnZ > (playerSpawnZ + g_GUIMapWindowMapHeightFilterHigh))
                    {
                        spawn = EQ_GetSpawnNext(spawn);
                        continue;
                    }
                }
            }

            float spawnMapX = 0.0f;
            float spawnMapY = 0.0f;
            EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(-spawnX, -spawnY, spawnMapX, spawnMapY);

            if (EQAPP_GUI_MapWindow_Map_IsPointInsideMap((int)spawnMapX, (int)spawnMapY) == false)
            {
                spawn = EQ_GetSpawnNext(spawn);
                continue;
            }

            if (ImGui::IsWindowHovered() == true)
            {
                if (g_GUIMapWindowMapSpawnMouseHover == false)
                {
                    auto mouseDistanceToSpawnX = std::fabsf(io.MousePos.x - spawnMapX);
                    auto mouseDistanceToSpawnY = std::fabsf(io.MousePos.y - spawnMapY);

                    float mouseDistanceToSpawnCheck = g_GUIMapWindowMapSpawnCircleSize + 1.0f;

                    if (g_GUIMapWindowMapScaleToZoomIsEnabled == true)
                    {
                        if (g_GUIMapWindowMapZoom != 0.0f)
                        {
                            mouseDistanceToSpawnCheck = mouseDistanceToSpawnCheck * g_GUIMapWindowMapZoom;

                            if (mouseDistanceToSpawnCheck < 2.0f)
                            {
                                mouseDistanceToSpawnCheck = 2.0f;
                            }
                        }
                    }

                    if (mouseDistanceToSpawnX < mouseDistanceToSpawnCheck)
                    {
                        if (mouseDistanceToSpawnY < mouseDistanceToSpawnCheck)
                        {
                            auto spawnName = EQ_GetSpawnName(spawn);
                            if (spawnName.size() != 0)
                            {
                                std::stringstream ssHoverText;
                                ssHoverText << spawnName;

                                if (spawnType == EQ_SPAWN_TYPE_NPC)
                                {
                                    auto spawnLastName = EQ_GetSpawnLastName(spawn);
                                    if (spawnLastName.size() != 0)
                                    {
                                        ssHoverText << "\n(" << spawnLastName << ")";
                                    }
                                }

                                ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);

                                spawnMouseHoverTextSize = ImGui::CalcTextSize(ssHoverText.str().c_str(), NULL);

                                float textHeightOffset = g_GUIMapWindowMapTextHeightOffset;
                                if (g_GUIMapWindowMapZoom > 1.0f)
                                {
                                    textHeightOffset = textHeightOffset * g_GUIMapWindowMapZoom;
                                }

                                spawnMouseHoverX = spawnMapX - (spawnMouseHoverTextSize.x * 0.5f);
                                spawnMouseHoverY = spawnMapY - spawnMouseHoverTextSize.y - textHeightOffset - (g_GUIMapWindowMapSpawnCircleSize * g_GUIMapWindowMapZoom);

                                spawnMouseHoverText = ssHoverText.str();

                                g_GUIMapWindowMapSpawnMouseHover = true;

                                g_GUIMapWindowMapSpawnMouseHoverDrawCircle = true;

                                if (io.MouseClicked[0] == true)
                                {
                                    float spawnDistance = EQ_CalculateDistance3D(playerSpawnY, playerSpawnX, playerSpawnZ, spawnY, spawnX, spawnZ);
                                    if (spawnDistance <= g_GUIMapWindowMapSpawnClickDistance)
                                    {
                                        EQ_SetTargetSpawn(spawn);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            ImColor spawnColor = g_GUIMapWindowMapSpawnDefaultColor;

            if (spawnType == EQ_SPAWN_TYPE_PLAYER)
            {
                spawnColor = g_GUIMapWindowMapSpawnPlayerColor;
            }
            else if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                spawnColor = g_GUIMapWindowMapSpawnNPCColor;
            }
            else if (spawnType == EQ_SPAWN_TYPE_CORPSE)
            {
                spawnColor = g_GUIMapWindowMapSpawnCorpseColor;
            }

            if (spawnIsMercenary == true)
            {
                spawnColor = g_GUIMapWindowMapSpawnMercenaryColor;
            }

            if (spawnIsPet == true)
            {
                spawnColor = g_GUIMapWindowMapSpawnPetColor;
            }

            if (spawnIsGroupMember == true)
            {
                spawnColor = g_GUIMapWindowMapSpawnGroupMemberColor;
            }

            if (spawn == targetSpawn)
            {
                spawnColor = g_GUIMapWindowMapSpawnTargetColor;
            }

            drawList->AddCircleFilled(ImVec2(spawnMapX, spawnMapY), spawnCircleSize, spawnColor);
            drawCount++;

            if (g_GUIMapWindowMapSpawnMouseHoverDrawCircle == true)
            {
                drawList->AddCircle(ImVec2(spawnMapX, spawnMapY), spawnCircleSize, g_GUIMapWindowMapSpawnMouseHoverColor);
                drawCount++;

                g_GUIMapWindowMapSpawnMouseHoverDrawCircle = false;
            }

            spawn = EQ_GetSpawnNext(spawn);
        }

        if (g_GUIMapWindowMapSpawnMouseHover == true)
        {
            drawList->AddRectFilled(ImVec2(spawnMouseHoverX, spawnMouseHoverY), ImVec2(spawnMouseHoverX + spawnMouseHoverTextSize.x, spawnMouseHoverY + spawnMouseHoverTextSize.y), g_GUIMapWindowMapSpawnMouseHoverBackColor);
            drawCount++;

            drawList->AddText(ImVec2(spawnMouseHoverX, spawnMouseHoverY), g_GUIMapWindowMapSpawnMouseHoverColor, spawnMouseHoverText.c_str(), NULL);
            drawCount++;
        }
    }

    if (g_GUIMapWindowMapLabelsIsEnabled == true)
    {
        float labelCircleSize = g_GUIMapWindowMapLabelCircleSize;

        if (g_GUIMapWindowMapScaleToZoomIsEnabled == true)
        {
            if (g_GUIMapWindowMapZoom != 0.0f)
            {
                labelCircleSize = labelCircleSize * g_GUIMapWindowMapZoom;

                if (labelCircleSize < 1.0f)
                {
                    labelCircleSize = 1.0f;
                }
            }
        }

        auto mapLabels = EQ_MapWindow_GetLabels();
        if (mapLabels != NULL)
        {
            EQ::MapLabel_ptr mapLabel = (EQ::MapLabel_ptr)mapLabels;
            while (mapLabel != NULL)
            {
                if (g_GUIMapWindowMapLayer0IsEnabled == false)
                {
                    if (mapLabel->Layer == 0)
                    {
                        mapLabel = mapLabel->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer1IsEnabled == false)
                {
                    if (mapLabel->Layer == 1)
                    {
                        mapLabel = mapLabel->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer2IsEnabled == false)
                {
                    if (mapLabel->Layer == 2)
                    {
                        mapLabel = mapLabel->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer3IsEnabled == false)
                {
                    if (mapLabel->Layer == 3)
                    {
                        mapLabel = mapLabel->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapHeightFilterLabelsIsEnabled == true)
                {
                    if (g_GUIMapWindowMapHeightFilterLow > 0.0f)
                    {
                        if (mapLabel->Location.Z < (playerSpawnZ - g_GUIMapWindowMapHeightFilterLow))
                        {
                            mapLabel = mapLabel->Next;
                            continue;
                        }
                    }

                    if (g_GUIMapWindowMapHeightFilterHigh > 0.0f)
                    {
                        if (mapLabel->Location.Z > (playerSpawnZ + g_GUIMapWindowMapHeightFilterHigh))
                        {
                            mapLabel = mapLabel->Next;
                            continue;
                        }
                    }
                }

                float labelMapX = 0.0f;
                float labelMapY = 0.0f;
                EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(mapLabel->Location.X, mapLabel->Location.Y, labelMapX, labelMapY);

                if (EQAPP_GUI_MapWindow_Map_IsPointInsideMap((int)labelMapX, (int)labelMapY) == false)
                {
                    mapLabel = mapLabel->Next;
                    continue;
                }

                ImColor labelColor = ImColor(mapLabel->Color.R, mapLabel->Color.G, mapLabel->Color.B, mapLabel->Color.A);

                // convert black labels to white labels
                if (labelColor.Value.x == 0 && labelColor.Value.y == 0 && labelColor.Value.z == 0)
                {
                    labelColor.Value.x = 1;
                    labelColor.Value.y = 1;
                    labelColor.Value.z = 1;
                }

                drawList->AddCircleFilled(ImVec2(labelMapX, labelMapY), labelCircleSize, labelColor);

                ImVec2 textSize = ImGui::CalcTextSize(mapLabel->Text, NULL);

                float textHeightOffset = g_GUIMapWindowMapTextHeightOffset;
                if (g_GUIMapWindowMapZoom > 1.0f)
                {
                    textHeightOffset = textHeightOffset * g_GUIMapWindowMapZoom;
                }

                labelMapX = labelMapX - (textSize.x * 0.5f);
                labelMapY = labelMapY - textSize.y - textHeightOffset - (g_GUIMapWindowMapLabelCircleSize * g_GUIMapWindowMapZoom);

                drawList->AddText(ImVec2(labelMapX, labelMapY), labelColor, mapLabel->Text, NULL);
                drawCount++;

                mapLabel = mapLabel->Next;
            }
        }
    }

    // player spawn
    drawList->AddCircleFilled(ImVec2(playerMapX, playerMapY), spawnCircleSize, g_GUIMapWindowMapSpawnYouColor);
    drawCount++;

    if (playerSpawn == targetSpawn)
    {
        drawList->AddCircle(ImVec2(playerMapX, playerMapY), spawnCircleSize, g_GUIMapWindowMapSpawnTargetColor);
        drawCount++;
    }

    EQAPP_GUI_MapWindow_Map_DrawSpawnArrow(playerSpawn, g_GUIMapWindowMapSpawnYouColor);
    drawCount += 3;

    drawList->PopClipRect();

    // map border
    drawList->AddRect(ImVec2(g_GUIMapWindowMapX, g_GUIMapWindowMapY), ImVec2(g_GUIMapWindowMapMaxX, g_GUIMapWindowMapMaxY), g_GUIMapWindowMapBorderColor);
    drawCount++;

/*
    std::stringstream ss;
    ss << "Draw Count: " << drawCount;

    EQ_DrawText(ss.str().c_str(), 100, 100);
*/
}

static void EQAPP_GUI_MapWindow_Map_PrintDebugInformation()
{
    uint32_t numMapLines = 0;
    uint32_t numMapLabels = 0;

    auto mapLines = EQ_MapWindow_GetLines();
    if (mapLines != NULL)
    {
        EQ::MapLine_ptr mapLine = (EQ::MapLine_ptr)mapLines;
        while (mapLine != NULL)
        {
            numMapLines++;

            mapLine = mapLine->Next;
        }
    }

    auto mapLabels = EQ_MapWindow_GetLabels();
    if (mapLabels != NULL)
    {
        EQ::MapLabel_ptr mapLabel = (EQ::MapLabel_ptr)mapLabels;
        while (mapLabel != NULL)
        {
            numMapLabels++;

            std::cout << "Map Label Text: " << mapLabel->Text << std::endl;

            mapLabel = mapLabel->Next;
        }
    }

    std::cout << "Map Lines: " << numMapLines << std::endl;
    std::cout << "Map Labels: " << numMapLabels << std::endl;
}
