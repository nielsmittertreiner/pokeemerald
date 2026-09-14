#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "main.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "time.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"

#define POPUP_OFFSCREEN_Y  24
#define POPUP_SLIDE_SPEED  2

#define tState         data[0]
#define tOnscreenTimer data[1]
#define tYOffset       data[2]
#define tIncomingPopUp data[3]
#define tPrintTimer    data[4]

// States and data defines for Task_MapNamePopUpWindow
enum
{
    STATE_SLIDE_IN,
    STATE_WAIT,
    STATE_SLIDE_OUT,
    STATE_UNUSED,
    STATE_ERASE,
    STATE_END,
    STATE_PRINT, // For some reason the first state is numerically last.
};

enum
{
    MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_GRASS,
    MAPPOPUP_THEME_MARBLE,
    MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_STONE2,
    MAPPOPUP_THEME_UNDERWATER,
};

// static functions
static void Task_MapNamePopUpWindow(u8 taskId);
static void ShowMapNamePopUpWindow(void);
static void LoadMapNamePopUpWindowBgs(void);

static const u8 sTextColor[] = {0, 1, 2};

static const u32 sMapPopup_WoodTop_Gfx[] = INCBIN_U32("graphics/map_popup/wood_top.4bpp");
static const u32 sMapPopup_WoodBottom_Gfx[] = INCBIN_U32("graphics/map_popup/wood_bottom.4bpp");
static const u16 sMapPopup_Wood_Pal[] = INCBIN_U16("graphics/map_popup/wood.gbapal");
static const u32 sMapPopup_GrassTop_Gfx[] = INCBIN_U32("graphics/map_popup/grass_top.4bpp");
static const u32 sMapPopup_GrassBottom_Gfx[] = INCBIN_U32("graphics/map_popup/grass_bottom.4bpp");
static const u16 sMapPopup_Grass_Pal[] = INCBIN_U16("graphics/map_popup/grass.gbapal");
static const u32 sMapPopup_MarbleTop_Gfx[] = INCBIN_U32("graphics/map_popup/marble_top.4bpp");
static const u32 sMapPopup_MarbleBottom_Gfx[] = INCBIN_U32("graphics/map_popup/marble_bottom.4bpp");
static const u16 sMapPopup_Marble_Pal[] = INCBIN_U16("graphics/map_popup/marble.gbapal");
static const u32 sMapPopup_BrickTop_Gfx[] = INCBIN_U32("graphics/map_popup/brick_top.4bpp");
static const u32 sMapPopup_BrickBottom_Gfx[] = INCBIN_U32("graphics/map_popup/brick_bottom.4bpp");
static const u16 sMapPopup_Brick_Pal[] = INCBIN_U16("graphics/map_popup/brick.gbapal");
static const u32 sMapPopup_StoneTop_Gfx[] = INCBIN_U32("graphics/map_popup/stone_top.4bpp");
static const u32 sMapPopup_StoneBottom_Gfx[] = INCBIN_U32("graphics/map_popup/stone_bottom.4bpp");
static const u16 sMapPopup_Stone_Pal[] = INCBIN_U16("graphics/map_popup/stone.gbapal");
static const u16 sMapPopup_Stone2_Pal[] = INCBIN_U16("graphics/map_popup/stone2.gbapal");
static const u32 sMapPopup_UnderwaterTop_Gfx[] = INCBIN_U32("graphics/map_popup/underwater_top.4bpp");
static const u32 sMapPopup_UnderwaterBottom_Gfx[] = INCBIN_U32("graphics/map_popup/underwater_bottom.4bpp");
static const u16 sMapPopup_Underwater_Pal[] = INCBIN_U16("graphics/map_popup/underwater.gbapal");
static const u16 sMapPopup_Underwater2_Pal[] = INCBIN_U16("graphics/map_popup/underwater2.gbapal");

static const u32 *const sMapPopup_GfxTable[][2] = 
{
    [MAPPOPUP_THEME_WOOD] = {sMapPopup_WoodTop_Gfx, sMapPopup_WoodBottom_Gfx},
    [MAPPOPUP_THEME_GRASS] = {sMapPopup_GrassTop_Gfx, sMapPopup_GrassBottom_Gfx},
    [MAPPOPUP_THEME_MARBLE] = {sMapPopup_MarbleTop_Gfx, sMapPopup_MarbleBottom_Gfx},
    [MAPPOPUP_THEME_BRICK] = {sMapPopup_BrickTop_Gfx, sMapPopup_BrickBottom_Gfx},
    [MAPPOPUP_THEME_STONE] = {sMapPopup_StoneTop_Gfx, sMapPopup_StoneBottom_Gfx},
    [MAPPOPUP_THEME_STONE2] = {sMapPopup_StoneTop_Gfx, sMapPopup_StoneBottom_Gfx},
    [MAPPOPUP_THEME_UNDERWATER] = {sMapPopup_UnderwaterTop_Gfx, sMapPopup_UnderwaterBottom_Gfx},
};

static const u16 *const sMapPopup_PalTable[] = 
{
    [MAPPOPUP_THEME_WOOD] = sMapPopup_Wood_Pal,
    [MAPPOPUP_THEME_GRASS] = sMapPopup_Grass_Pal,
    [MAPPOPUP_THEME_MARBLE] = sMapPopup_Marble_Pal,
    [MAPPOPUP_THEME_BRICK] = sMapPopup_Brick_Pal,
    [MAPPOPUP_THEME_STONE] = sMapPopup_Stone_Pal,
    [MAPPOPUP_THEME_STONE2] = sMapPopup_Stone2_Pal,
    [MAPPOPUP_THEME_UNDERWATER] = sMapPopup_Underwater_Pal,
};

static const u8 sRegionMapSectionId_To_PopUpThemeIdMapping[] =
{
    [MAPSEC_SUNSET_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_CEDARRED_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FIRWEALD_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_MURENA_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_LITOR_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_NAVIRE_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_PACIFIDLOG_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_PETALBURG_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_SLATEPORT_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_MAUVILLE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_RUSTBORO_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_FORTREE_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_LILYCOVE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_MOSSDEEP_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_SOOTOPOLIS_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_EVER_GRANDE_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_ROUTE_401] = MAPPOPUP_THEME_GRASS,
    [MAPSEC_ROUTE_402] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_403] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_404] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_405] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_406] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_407] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_408] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_409] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_410] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_411] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_412] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_413] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_414] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_415] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_416] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_417] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_418] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_419] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_420] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_421] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_422] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_423] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_424] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_425] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_426] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_427] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_428] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_429] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_430] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_431] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_432] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_433] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_434] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_UNDERWATER_124] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_126] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_127] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_128] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_SOOTOPOLIS] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_ACREN_FOREST] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_OUREA_CAVES] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SAFARI_ZONE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_BATTLE_FRONTIER] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_PETALBURG_WOODS] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_RUSTURF_TUNNEL] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ABANDONED_SHIP] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_NEW_MAUVILLE] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_METEOR_FALLS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_METEOR_FALLS2] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MT_PYRE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_AQUA_HIDEOUT_OLD] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SHOAL_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_VICTORY_ROAD] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MIRAGE_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_CAVE_OF_ORIGIN] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SOUTHERN_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FIERY_PATH] = MAPPOPUP_THEME_STONE,
    [MAPSEC_FIERY_PATH2] = MAPPOPUP_THEME_STONE,
    [MAPSEC_JAGGED_PASS] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_JAGGED_PASS2] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SEALED_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_SEALED_CHAMBER] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_SCORCHED_SLAB] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ISLAND_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DESERT_RUINS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ANCIENT_TOMB] = MAPPOPUP_THEME_STONE,
    [MAPSEC_INSIDE_OF_TRUCK] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SKY_PILLAR] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SECRET_BASE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DYNAMIC] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_AQUA_HIDEOUT - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MAGMA_HIDEOUT - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MIRAGE_TOWER - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_BIRTH_ISLAND - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FARAWAY_ISLAND - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ARTISAN_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MARINE_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_MARINE_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_TERRA_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_105 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_125 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_UNDERWATER_129 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_DESERT_UNDERPASS - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ALTERING_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_NAVEL_ROCK - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_TRAINER_HILL - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_MARBLE
};

// .text
void ShowMapNamePopup(void)
{
    if (FlagGet(FLAG_HIDE_MAP_NAME_POPUP) != TRUE)
    {
        if (!FuncIsActiveTask(Task_MapNamePopUpWindow))
        {
            gPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 100);
            gTasks[gPopupTaskId].tState = STATE_PRINT;
            gTasks[gPopupTaskId].data[2] = POPUP_OFFSCREEN_Y;
        }
        else
        {
            if (gTasks[gPopupTaskId].tState != STATE_SLIDE_OUT)
                gTasks[gPopupTaskId].tState = STATE_SLIDE_OUT;
            gTasks[gPopupTaskId].tIncomingPopUp = TRUE;
        }
    }
}

static void Task_MapNamePopUpWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case STATE_PRINT:
        // Wait, then create and print the pop up window
        if (++task->tPrintTimer > 30)
        {
            task->tState = STATE_SLIDE_IN;
            task->tPrintTimer = 0;
            ShowMapNamePopUpWindow();
            EnableInterrupts(INTR_FLAG_HBLANK);
            SetHBlankCallback(HBlankCB_DoublePopupWindow);
        }
        break;
    case STATE_SLIDE_IN:
        // Slide the window onscreen.
        task->tYOffset -= POPUP_SLIDE_SPEED;
        if (task->tYOffset <= 0 )
        {
            task->tYOffset = 0;
            task->tState = STATE_WAIT;
            gTasks[gPopupTaskId].tOnscreenTimer = 0;
        }
        break;
    case STATE_WAIT:
        // Wait while the window is fully onscreen.
        if (++task->tOnscreenTimer > 120)
        {
            task->tOnscreenTimer = 0;
            task->tState = STATE_SLIDE_OUT;
        }
        break;
    case STATE_SLIDE_OUT:
        task->tYOffset += POPUP_SLIDE_SPEED;
        if (task->tYOffset >= POPUP_OFFSCREEN_Y)
        {
            task->tYOffset = POPUP_OFFSCREEN_Y;
            if (task->tIncomingPopUp)
            {
                // A new pop up window is incoming,
                // return to the first state to show it.
                task->tState = STATE_PRINT;
                task->tPrintTimer = 0;
                task->tIncomingPopUp = FALSE;
            }
            else
            {
                task->tState = STATE_ERASE;
                return;
            }
        }
        break;
    case STATE_ERASE:
        ClearStdWindowAndFrame(GetPrimaryPopUpWindowId(), TRUE);
        ClearStdWindowAndFrame(GetSecondaryPopUpWindowId(), TRUE);
        task->tState = STATE_END;
        break;
    case STATE_END:
        HideMapNamePopUpWindow();
        return;
    }
}

void HideMapNamePopUpWindow(void)
{
    if (FuncIsActiveTask(Task_MapNamePopUpWindow))
    {
        if (GetPrimaryPopUpWindowId() != WINDOW_NONE)
        {
            ClearStdWindowAndFrame(GetPrimaryPopUpWindowId(), TRUE);
            RemovePrimaryPopUpWindow();
        }
        if (GetSecondaryPopUpWindowId() != WINDOW_NONE)
        {
            ClearStdWindowAndFrame(GetSecondaryPopUpWindowId(), TRUE);
            RemoveSecondaryPopUpWindow();
        }
        DisableInterrupts(INTR_FLAG_HBLANK);
        SetHBlankCallback(NULL);
        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, 0);
        DestroyTask(gPopupTaskId);
    }
}

static void ShowMapNamePopUpWindow(void)
{
    u8 mapDisplayHeader[24];
    u8 primaryPopUpWindowId = AddPrimaryPopUpWindow();
    u8 secondaryPopUpWindowId = AddSecondaryPopUpWindow();

    LoadMapNamePopUpWindowBgs();

    GetMapName(mapDisplayHeader, gMapHeader.regionMapSectionId, 0);
    AddTextPrinterParameterized3(primaryPopUpWindowId, FONT_SHORT, 4, 2, sTextColor, TEXT_SKIP_DRAW, mapDisplayHeader);
    CopyWindowToVram(primaryPopUpWindowId, COPYWIN_FULL);

    FormatDecimalTimeWithoutSeconds(mapDisplayHeader, gSaveBlock2Ptr->time.hours, gSaveBlock2Ptr->time.minutes, gSaveBlock2Ptr->optionsClockMode);
    AddTextPrinterParameterized3(secondaryPopUpWindowId, FONT_SMALL, GetStringRightAlignXOffset(FONT_SMALL, mapDisplayHeader, DISPLAY_WIDTH) - 8, 8, sTextColor, TEXT_SKIP_DRAW, mapDisplayHeader);
    CopyWindowToVram(secondaryPopUpWindowId, COPYWIN_FULL);
}

static void LoadMapNamePopUpWindowBgs(void)
{
    u8 primaryPopUpWindowId = GetPrimaryPopUpWindowId();
    u8 secondaryPopUpWindowId = GetSecondaryPopUpWindowId();
    u8 weather = GetCurrentWeather();
    u16 regionMapSectionId = gMapHeader.regionMapSectionId;
    u8 popUpThemeId;
    
    if (regionMapSectionId >= KANTO_MAPSEC_START)
    {
        if (regionMapSectionId > KANTO_MAPSEC_END)
            regionMapSectionId -= KANTO_MAPSEC_COUNT;
        else
            regionMapSectionId = 0; // Discard kanto region sections;
    }

    popUpThemeId = sRegionMapSectionId_To_PopUpThemeIdMapping[regionMapSectionId];

    PutWindowTilemap(primaryPopUpWindowId);
    PutWindowTilemap(secondaryPopUpWindowId);

    if (weather == WEATHER_UNDERWATER_BUBBLES)
        LoadPalette(sMapPopup_Underwater2_Pal, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    else
        LoadPalette(sMapPopup_PalTable[popUpThemeId], BG_PLTT_ID(14), PLTT_SIZE_4BPP);

    CopyToWindowPixelBuffer(primaryPopUpWindowId, sMapPopup_GfxTable[popUpThemeId][0], 0xB40, 0);
    CopyToWindowPixelBuffer(secondaryPopUpWindowId, sMapPopup_GfxTable[popUpThemeId][1], 0xB40, 0);
}
