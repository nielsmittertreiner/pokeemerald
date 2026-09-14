#ifdef DEBUG
#include "global.h"
#include "debug/debug.h"
#include "debug/sound_test_screen.h"
#include "battle_main.h"
#include "bg.h"
#include "decompress.h"
#include "data.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "random.h"
#include "region_map.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "time.h"
#include "util.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/weather.h"

// this file's functions
static void Task_DebugMenuFadeIn(u8 taskId);
static void Task_DebugMenuProcessInput(u8 taskId);
static void Task_DebugMenuFadeOut(u8 taskId);
static void BuildDebugListMenuData(u8 listMenuId);
static void Task_DebugActionBuildListMenuInfo(u8 taskId);
static void Task_DebugActionBuildListMenuWorld(u8 taskId);
static void Task_DebugActionBuildListMenuPlayer(u8 taskId);
static void Task_DebugActionSoundTestScreen(u8 taskId);
static void Task_GoToSoundTestScreen(u8 taskId);
static void Task_DebugActionSoftReset(u8 taskId);
static void Task_DebugActionCredits(u8 taskId);
static void Task_DebugActionSaveblock(u8 taskId);
static void Task_DebugActionWarp(u8 taskId);
static void Task_HandleWarpInput(u8 taskId);
static void Task_DebugActionFlags(u8 taskId);
static void Task_HandleFlagsInput(u8 taskId);
static void Task_DebugActionVars(u8 taskId);
static void Task_HandleVarsInput(u8 taskId);
static void Task_DebugActionSetTime(u8 taskId);
static void Task_HandleSetTimeInput(u8 taskId);
static void Task_DebugActionSetWeather(u8 taskId);
static void Task_HandleSetWeatherInput(u8 taskId);
static void Task_DebugActionHealParty(u8 taskId);
static void Task_DebugActionResetQuests(u8 taskId);
static void Task_DebugActionResetBerries(u8 taskId);
static void Task_DebugActionGodmode(u8 taskId);
static void Task_DebugActionBuildParty(u8 taskId);
static void Task_HandleBuildPartyInput(u8 taskId);
static void Task_BuildLearnableMoveList(u8 taskId);
static void Task_BuildCustomParty(u8 taskId);
static void Task_DebugActionGiveItem(u8 taskId);
static void Task_HandleGiveItemInput(u8 taskId);
static void Task_DebugActionChangeGender(u8 taskId);

struct DebugMenu
{
    void (*func)(u8);
    u16 cursorPosition;
    u16 cursorStack[3];
    u8 cursorStackDepth;
    u8 activeListMenu;
    u8 listTaskId;
    u8 arrowTaskId;
    u8 spriteId;
};

struct PartyBuilder
{
    u8 spriteId;
    u16 species;
    u8 level;
    u16 *moveList;
    u8 moveListIndex[MAX_MON_MOVES];
    u8 moveListSize;
    u8 moveListTaskId;
    u16 moves[MAX_MON_MOVES];
    u8 ability:1;
    u8 shiny:1;
};

enum
{
    TAG_SCROLL_ARROW,
    TAG_ITEM_ICON,
};

enum
{
    WIN_HEADER,
    WIN_LIST_MENU,
    WIN_DESCRIPTION,
};

enum
{
    ACTIVE_LIST_MAIN,
    ACTIVE_LIST_INFO,
    ACTIVE_LIST_WORLD,
    ACTIVE_LIST_PLAYER,
};

enum
{
    LIST_ITEM_INFO,
    LIST_ITEM_WORLD,
    LIST_ITEM_PLAYER,
    LIST_ITEM_SOUND_TEST_SCREEN,
    LIST_ITEM_SOFTRESET,
};

enum
{
    LIST_ITEM_CREDITS,
    LIST_ITEM_SAVEBLOCK,
};

enum
{
    LIST_ITEM_WARP,
    LIST_ITEM_FLAGS,
    LIST_ITEM_VARS,
    LIST_ITEM_TIME,
    LIST_ITEM_WEATHER,
    LIST_ITEM_RESET_QUESTS,
    LIST_ITEM_RESET_BERRIES,
};

enum
{
    LIST_ITEM_GODMODE,
    LIST_ITEM_HEAL_PARTY,
    LIST_ITEM_BUILD_PARTY,
    LIST_ITEM_GIVE_ITEM,
    LIST_ITEM_CHANGE_GENDER,
};

enum
{
    WARP_STATE_GROUP,
    WARP_STATE_NUM,
    WARP_STATE_WARP,
    WARP_STATE_X,
    WARP_STATE_Y,
};

enum
{
    PARTY_BUILDER_STATE_MON,
    PARTY_BUILDER_STATE_LVL,
    PARTY_BUILDER_STATE_MOVES,
    PARTY_BUILDER_STATE_ABILITY,
    PARTY_BUILDER_STATE_SHINY,
};

enum
{
    SET_TIME_STATE_HOURS,
    SET_TIME_STATE_MINUTES,
    SET_TIME_STATE_DAY_OF_WEEK,
};

EWRAM_DATA static struct DebugMenu *sDebugMenu = NULL;
EWRAM_DATA static struct PartyBuilder *sPartyBuilder[PARTY_SIZE] = {NULL};
EWRAM_DATA static bool8 sChangedWeatherDebug = FALSE;
EWRAM_DATA bool8 gGodMode = FALSE;

// .rodata
static const u32 sDebugTiles[] = INCBIN_U32("graphics/interface/debug_tiles.4bpp.lz");
static const u32 sDebugTilemap[] = INCBIN_U32("graphics/interface/debug_map.bin.lz");
static const u16 sDebugPalette[] = INCBIN_U16("graphics/interface/debug_tiles.gbapal");

static const u8 sTextColor_Default[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
static const u8 sTextColor_Green[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GREEN, TEXT_COLOR_GREEN};
static const u8 sTextColor_Red[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED};

extern const u8 EventScript_ResetAllBerries[];

static const struct BgTemplate sBgTemplates[] =
{
   {
       .bg = 0,
       .charBaseIndex = 0,
       .mapBaseIndex = 30,
       .screenSize = 2,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = 1,
       .charBaseIndex = 0,
       .mapBaseIndex = 26,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   }
};

static const struct WindowTemplate sWindowTemplates[] =
{
    [WIN_HEADER] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 28,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x10,
    },
    [WIN_LIST_MENU] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 4,
        .width = 11,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 0x80,
    },
    [WIN_DESCRIPTION] =
    {
        .bg = 0,
        .tilemapLeft = 13,
        .tilemapTop = 4,
        .width = 17,
        .height = 15,
        .paletteNum = 15,
        .baseBlock = 0x134,
    },
    DUMMY_WIN_TEMPLATE,
};

static const u8 sMapNumCount[MAP_GROUPS_COUNT] = 
{
    MAP_GROUP_COUNT(0),
    MAP_GROUP_COUNT(1),
    MAP_GROUP_COUNT(2),
    MAP_GROUP_COUNT(3),
    MAP_GROUP_COUNT(4),
    MAP_GROUP_COUNT(5),
    MAP_GROUP_COUNT(6),
    MAP_GROUP_COUNT(7),
    MAP_GROUP_COUNT(8),
    MAP_GROUP_COUNT(9),
    MAP_GROUP_COUNT(10),
    MAP_GROUP_COUNT(11),
    MAP_GROUP_COUNT(12),
    MAP_GROUP_COUNT(13),
    MAP_GROUP_COUNT(14),
};

static const u8 sText_VanadiumDebugMenu[] = _("POKéMON VANADIUM VERSION DEBUG MENU");

// options
static const u8 sText_Info[] = _("INFO");
static const u8 sText_World[] = _("WORLD");
static const u8 sText_Player[] = _("PLAYER");
static const u8 sText_SoundTestScreen[] = _("SOUND TESTING");
static const u8 sText_SoftReset[] = _("SOFT RESET");

static const u8 sText_Credits[] = _("CREDITS");
static const u8 sText_Saveblock[] = _("SAVEBLOCK");

static const u8 sText_Warp[] = _("WARP");
static const u8 sText_Flags[] = _("FLAGS");
static const u8 sText_Vars[] = _("VARS");
static const u8 sText_SetTime[] = _("SET TIME");
static const u8 sText_SetWeather[] = _("SET WEATHER");
static const u8 sText_ResetQuests[] = _("RESET QUESTS");
static const u8 sText_ResetBerries[] = _("RESET BERRIES");

static const u8 sText_Godmode[] = _("GODMODE");
static const u8 sText_HealParty[] = _("HEAL PARTY");
static const u8 sText_BuildParty[] = _("BUILD PARTY");
static const u8 sText_GiveItem[] = _("GIVE ITEM");
static const u8 sText_ChangeGender[] = _("CHANGE GENDER");

// descriptions
static const u8 sText_InfoDesc[] = _("DEBUGGING INFORMATION.");
static const u8 sText_WorldDesc[] = _("VIEW WORLD\nDEBUG OPTIONS.");
static const u8 sText_PlayerDesc[] = _("VIEW PLAYER\nDEBUG OPTIONS.");
static const u8 sText_SoftResetDesc[] = _("SOFT RESETS THE SYSTEM.\nCAN BE USEFUL ON HARDWARE.");

static const u8 sText_CreditsDesc[] = _("VIEW THE TEAM BEHIND\nPOKéMON: VANADIUM VERSION.");
static const u8 sText_SaveblockDesc[] = _("VIEW SAVEBLOCK DATA.");

static const u8 sText_WarpDesc[] = _("WARP TO ANY WARP POINT\nOR XY POSITION OF\nANY MAP IN THE GAME.");
static const u8 sText_FlagsDesc[] = _("TURN EVENT FLAGS ON\nOR OFF.");
static const u8 sText_VarsDesc[] = _("MANIPULATE VARS TO\nYOUR LIKING.");
static const u8 sText_SetTimeDesc[] = _("SET INGAME TIME TO\nYOUR LIKING.");
static const u8 sText_SetWeatherDesc[] = _("SET INGAME WEATHER TO\nYOUR LIKING.");
static const u8 sText_ResetQuestsDesc[] = _("RESET ALL QUESTS.");
static const u8 sText_ResetBerriesDesc[] = _("REPLANT ALL BERRIES\nIN THE OVERWORLD.");
static const u8 sText_SoundTestScreenDesc[] = _("GO TO SOUND TESTING\nSCREEN.");

static const u8 sText_GodmodeDesc[] = _("WALK THROUGH WALLS,\nDISABLE ENCOUNTERS AND\nDISABLE TRAINERS.");
static const u8 sText_HealPartyDesc[] = _("HEAL YOUR CURRENT PARTY\nBACK TO FULL HEALTH.");
static const u8 sText_BuildPartyDesc[] = _("CREATE A CUSTOMIZED\nPARTY OF POKéMON.");
static const u8 sText_GiveItemDesc[] = _("GIVE YOURSELF ANY\nITEM IN YOUR BAG.");
static const u8 sText_ChangeGenderDesc[] = _("CHANGE YOUR GENDER.");

// specifics
static const u8 sText_VanadiumTeam[] = _("JENA197, MOXIC, SPACESAUR,\nSENNA, ETHAN, N3RL, MORGAN,\nHOUSEFISH, AQUAMARINEKNIGHT,\nEKAT");

static const u8 sText_True[] = _("TRUE");
static const u8 sText_False[] = _("FALSE");
static const u8 sText_Status[] = _("STATUS: ");
static const u8 sText_Digit[] = _("DIGIT: ");

static const u8 sText_MapGroup[] = _("MAPGROUP: ");
static const u8 sText_MapNum[] = _("MAPNUM: ");
static const u8 sText_MapWarp[] = _("WARP: ");
static const u8 sText_X[] = _("X: ");
static const u8 sText_Y[] = _("Y: ");
static const u8 sText_ExactPosition[] = _("XY POSITION");

static const u8 sText_Flag[] = _("FLAG: ");
static const u8 sText_Var[] = _("VAR: ");
static const u8 sText_VarValue[] = _("VALUE: ");

static const u8 sText_ItemName[] = _("NAME: ");
static const u8 sText_ItemId[] = _("ID: ");
static const u8 sText_ItemDesc[] = _("DESCRIPTION: ");
static const u8 sText_ItemQuantity[] = _("QUANTITY: ");

static const u8 sText_Species[] = _("SPECIES: ");
static const u8 sText_Lvl[] = _("LVL: ");
static const u8 sText_Moves[] = _("MOVES: ");
static const u8 sText_Ability[] = _("ABILITY: ");
static const u8 sText_Shiny[] = _("SHINY: ");

static const u8 sText_Time[] = _("TIME: ");
static const u8 sText_Days[] = _("DAY: ");

static const u8 sText_Weather[] = _("WEATHER: ");
static const u8 sText_WeatherNone[] = _("NONE");
static const u8 sText_WeatherSunnyClouds[] = _("SUNNY CLOUDS");
static const u8 sText_WeatherSunny[] = _("SUNNY");
static const u8 sText_WeatherRain[] = _("RAIN");
static const u8 sText_WeatherSnow[] = _("SNOW");
static const u8 sText_WeatherRainThunderstorm[] = _("RAIN THUNDERSTORM");
static const u8 sText_WeatherFogHorizontal[] = _("FOG HORIZONTAL");
static const u8 sText_WeatherVolcanicAsh[] = _("VOLCANIC ASH");
static const u8 sText_WeatherSandstorm[] = _("SANDSTORM");
static const u8 sText_WeatherFogDiagonal[] = _("FOG DIAGONAL");
static const u8 sText_WeatherUnderwater[] = _("UNDERWATER");
static const u8 sText_WeatherShade[] = _("SHADE");
static const u8 sText_WeatherDrought[] = _("DROUGHT");
static const u8 sText_WeatherDownpour[] = _("DOWNPOUR");
static const u8 sText_WeatherUnderwaterBubbles[] = _("UNDERWATER BUBBLES");
static const u8 sText_WeatherAbnormal[] = _("ABNORMAL");

static const u8 sText_Gender[] = _("GENDER: ");
static const u8 sText_Male[] = _("MALE");
static const u8 sText_Female[] = _("FEMALE");

static const u8 *const sText_TrueFalse[] = 
{
    [TRUE]  = sText_True,
    [FALSE] = sText_False,
};

static const u8 *const sText_Genders[] =
{
    sText_Male,
    sText_Female
};

static const u8 *const sTextColor_TrueFalse[] = 
{
    [TRUE]  = sTextColor_Green,
    [FALSE] = sTextColor_Red,
};

static const u16 sHexDigitSelector[] =
{
    0x1,
    0x10,
    0x100,
};

static const u8 *const sText_MapGroupNumWarp[] =
{
    sText_MapGroup,
    sText_MapNum,
    sText_MapWarp,
    sText_X,
    sText_Y,
};

static const u8 *const sText_WeatherTypes[] =
{
    sText_WeatherNone,
    sText_WeatherSunnyClouds,
    sText_WeatherSunny,
    sText_WeatherRain,
    sText_WeatherSnow,
    sText_WeatherRainThunderstorm,
    sText_WeatherFogHorizontal,
    sText_WeatherVolcanicAsh,
    sText_WeatherSandstorm,
    sText_WeatherFogDiagonal,
    sText_WeatherUnderwater,
    sText_WeatherShade,
    sText_WeatherDrought,
    sText_WeatherDownpour,
    sText_WeatherUnderwaterBubbles,
    sText_WeatherAbnormal,
};

static const u8 *const sText_ListMenuDescriptions_Main[] =
{
    [LIST_ITEM_INFO]              = sText_InfoDesc,
    [LIST_ITEM_WORLD]             = sText_WorldDesc,
    [LIST_ITEM_PLAYER]            = sText_PlayerDesc,
    [LIST_ITEM_SOUND_TEST_SCREEN] = sText_SoundTestScreenDesc,
    [LIST_ITEM_SOFTRESET]         = sText_SoftResetDesc,
};

static const u8 *const sText_ListMenuDescriptions_Info[] =
{
    [LIST_ITEM_CREDITS]   = sText_CreditsDesc,
    [LIST_ITEM_SAVEBLOCK] = sText_SaveblockDesc,
};

static const u8 *const sText_ListMenuDescriptions_World[] =
{
    [LIST_ITEM_WARP]          = sText_WarpDesc,
    [LIST_ITEM_FLAGS]         = sText_FlagsDesc,
    [LIST_ITEM_VARS]          = sText_VarsDesc,
    [LIST_ITEM_TIME]          = sText_SetTimeDesc,
    [LIST_ITEM_WEATHER]       = sText_SetWeatherDesc,
    [LIST_ITEM_RESET_QUESTS]  = sText_ResetQuestsDesc,
    [LIST_ITEM_RESET_BERRIES] = sText_ResetBerriesDesc,
};

static const u8 *const sText_ListMenuDescriptions_Player[] =
{
    [LIST_ITEM_GODMODE]       = sText_GodmodeDesc,
    [LIST_ITEM_HEAL_PARTY]    = sText_HealPartyDesc,
    [LIST_ITEM_BUILD_PARTY]   = sText_BuildPartyDesc,
    [LIST_ITEM_GIVE_ITEM]     = sText_GiveItemDesc,
    [LIST_ITEM_CHANGE_GENDER] = sText_ChangeGenderDesc,
};

static const u8 *const *const sText_ListMenuDescriptions[] =
{
    [ACTIVE_LIST_MAIN]   = sText_ListMenuDescriptions_Main,
    [ACTIVE_LIST_INFO]   = sText_ListMenuDescriptions_Info,
    [ACTIVE_LIST_WORLD]  = sText_ListMenuDescriptions_World,
    [ACTIVE_LIST_PLAYER] = sText_ListMenuDescriptions_Player,
};

static const struct ListMenuItem sListMenuItems_Main[] =
{
    {sText_Info, NULL, LIST_ITEM_INFO},
    {sText_World, NULL, LIST_ITEM_WORLD},
    {sText_Player, NULL, LIST_ITEM_PLAYER},
    {sText_SoundTestScreen, NULL, LIST_ITEM_SOUND_TEST_SCREEN},
    {sText_SoftReset, NULL, LIST_ITEM_SOFTRESET},
};

static const struct ListMenuItem sListMenuItems_Info[] =
{
    {sText_Credits, NULL, LIST_ITEM_CREDITS},
    {sText_Saveblock, NULL, LIST_ITEM_SAVEBLOCK},
};

static const struct ListMenuItem sListMenuItems_World[] =
{
    {sText_Warp, NULL, LIST_ITEM_WARP},
    {sText_Flags, NULL, LIST_ITEM_FLAGS},
    {sText_Vars, NULL, LIST_ITEM_VARS},
    {sText_SetTime, NULL, LIST_ITEM_TIME},
    {sText_SetWeather, NULL, LIST_ITEM_WEATHER},
    {sText_ResetQuests, NULL, LIST_ITEM_RESET_QUESTS},
    {sText_ResetBerries, NULL, LIST_ITEM_RESET_BERRIES},
};

static const struct ListMenuItem sListMenuItems_Player[] =
{
    {sText_Godmode, NULL, LIST_ITEM_GODMODE},
    {sText_HealParty, NULL, LIST_ITEM_HEAL_PARTY},
    {sText_BuildParty, NULL, LIST_ITEM_BUILD_PARTY},
    {sText_GiveItem, NULL, LIST_ITEM_GIVE_ITEM},
    {sText_ChangeGender, NULL, LIST_ITEM_CHANGE_GENDER},
};

static void (*const sDebugActions_Main[])(u8) =
{
    [LIST_ITEM_INFO]              = Task_DebugActionBuildListMenuInfo,
    [LIST_ITEM_WORLD]             = Task_DebugActionBuildListMenuWorld,
    [LIST_ITEM_PLAYER]            = Task_DebugActionBuildListMenuPlayer,
    [LIST_ITEM_SOUND_TEST_SCREEN] = Task_DebugActionSoundTestScreen,
    [LIST_ITEM_SOFTRESET]         = Task_DebugActionSoftReset,
};

static void (*const sDebugActions_Info[])(u8) = 
{
    [LIST_ITEM_CREDITS]   = Task_DebugActionCredits,
    [LIST_ITEM_SAVEBLOCK] = Task_DebugActionSaveblock,
};

static void (*const sDebugActions_World[])(u8) = 
{
    [LIST_ITEM_WARP]          = Task_DebugActionWarp,
    [LIST_ITEM_FLAGS]         = Task_DebugActionFlags,
    [LIST_ITEM_VARS]          = Task_DebugActionVars,
    [LIST_ITEM_TIME]          = Task_DebugActionSetTime,
    [LIST_ITEM_WEATHER]       = Task_DebugActionSetWeather,
    [LIST_ITEM_RESET_QUESTS]  = Task_DebugActionResetQuests,
    [LIST_ITEM_RESET_BERRIES] = Task_DebugActionResetBerries,
};

static void (*const sDebugActions_Player[])(u8) = 
{
    [LIST_ITEM_GODMODE]       = Task_DebugActionGodmode,
    [LIST_ITEM_HEAL_PARTY]    = Task_DebugActionHealParty,
    [LIST_ITEM_BUILD_PARTY]   = Task_DebugActionBuildParty,
    [LIST_ITEM_GIVE_ITEM]     = Task_DebugActionGiveItem,
    [LIST_ITEM_CHANGE_GENDER] = Task_DebugActionChangeGender,
};

static void (*const *const sDebugActions[])(u8) =
{
    [ACTIVE_LIST_MAIN]    = sDebugActions_Main,
    [ACTIVE_LIST_INFO]    = sDebugActions_Info,
    [ACTIVE_LIST_WORLD]   = sDebugActions_World,
    [ACTIVE_LIST_PLAYER]  = sDebugActions_Player,
};

static const struct ListMenuTemplate sListMenuTemplate =
{
    .items = 0,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 0,
    .maxShowed = 8,
    .windowId = WIN_LIST_MENU,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 1,
    .fillValue = 0,
    .cursorShadowPal = 2,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

// code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    DoScheduledBgTilemapCopiesToVram();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

bool8 GetAndResetChangedWeatherDebug(void)
{
    bool8 changed = sChangedWeatherDebug;

    sChangedWeatherDebug = FALSE;
    return changed;
}

void CB2_DebugMenu(void)
{
    u32 i;
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
        DmaClear32(3, (void *)OAM, OAM_SIZE);
        DmaClear16(3, (void *)PLTT, PLTT_SIZE);
        gMain.state++;
        break;
    case 1:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        InitWindows(sWindowTemplates);
        DeactivateAllTextPrinters();
        ClearScheduledBgCopiesToVram();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);

        LZ77UnCompVram(sDebugTiles, (u16 *)BG_CHAR_ADDR(0));
        LZ77UnCompVram(sDebugTilemap, (u16 *)BG_SCREEN_ADDR(26));
        FillPalette(RGB_BLACK, 0, PLTT_SIZE);
        LoadPalette(sDebugPalette, 0, sizeof(sDebugPalette));
        LoadPalette(GetOverworldTextboxPalettePtr(), 0xF0, 32);
        gMain.state++;
        break;
    case 3:
        taskId = CreateTask(Task_DebugMenuFadeIn, 0);
        sDebugMenu = AllocZeroed(sizeof(struct DebugMenu));
        sDebugMenu->arrowTaskId = TASK_NONE;
        sDebugMenu->spriteId = SPRITE_NONE;

        gMultiuseListMenuTemplate = sListMenuTemplate;
        BuildDebugListMenuData(ACTIVE_LIST_MAIN);

        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, 0);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);

        PutWindowTilemap(WIN_HEADER);
        PutWindowTilemap(WIN_DESCRIPTION);
        FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(0));
        AddTextPrinterParameterized3(WIN_HEADER, FONT_NORMAL, GetStringCenterAlignXOffset(FONT_NORMAL, sText_VanadiumDebugMenu, DISPLAY_WIDTH), 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_VanadiumDebugMenu);
        CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);

        ShowBg(0);
        ShowBg(1);

        PlaySE(SE_PC_LOGIN);
    } 
}

static void Task_DebugMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_DebugMenuProcessInput;
}

static void Task_DebugMenuProcessInput(u8 taskId)
{
    u32 input = ListMenu_ProcessInput(sDebugMenu->listTaskId);

    if (JOY_NEW(A_BUTTON))
    {
        if ((sDebugMenu->func = sDebugActions[sDebugMenu->activeListMenu][input]) != NULL)
        {
            sDebugMenu->cursorStack[sDebugMenu->cursorStackDepth] = sDebugMenu->cursorPosition;
            sDebugMenu->func(taskId);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if (sDebugMenu->activeListMenu == ACTIVE_LIST_MAIN)
        {
            PlaySE(SE_PC_OFF);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_DebugMenuFadeOut;
            return;
        }
        else
        {
            PlaySE(SE_SELECT);
            sDebugMenu->cursorStack[sDebugMenu->cursorStackDepth] = 0;
            sDebugMenu->cursorStackDepth--;
            BuildDebugListMenuData(ACTIVE_LIST_MAIN);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (sDebugMenu->cursorPosition > 0)
            sDebugMenu->cursorPosition--;
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sDebugMenu->cursorPosition < gMultiuseListMenuTemplate.totalItems - 1)
            sDebugMenu->cursorPosition++;
    }

    if (JOY_NEW(DPAD_ANY))
    {
        FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_ListMenuDescriptions[sDebugMenu->activeListMenu][sDebugMenu->cursorPosition]);
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
    }
}

static void BuildDebugListMenuData(u8 activeListMenu)
{
    const struct ListMenuItem *items;
    u8 totalItems;
    u8 cursorPos = sDebugMenu->cursorStack[sDebugMenu->cursorStackDepth];

    switch (activeListMenu)
    {
    case ACTIVE_LIST_MAIN:
        items = sListMenuItems_Main;
        totalItems = ARRAY_COUNT(sListMenuItems_Main);
        break;
    case ACTIVE_LIST_INFO:
        items = sListMenuItems_Info;
        totalItems = ARRAY_COUNT(sListMenuItems_Info);
        break;
    case ACTIVE_LIST_WORLD:
        items = sListMenuItems_World;
        totalItems = ARRAY_COUNT(sListMenuItems_World);
        break;
    case ACTIVE_LIST_PLAYER:
        items = sListMenuItems_Player;
        totalItems = ARRAY_COUNT(sListMenuItems_Player);
        break;
    }

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_ListMenuDescriptions[activeListMenu][cursorPos]);
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

    gMultiuseListMenuTemplate = sListMenuTemplate;
    gMultiuseListMenuTemplate.items = items;
    gMultiuseListMenuTemplate.totalItems = totalItems;
    sDebugMenu->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, cursorPos);
    sDebugMenu->activeListMenu = activeListMenu;
    sDebugMenu->cursorPosition = cursorPos;

    if (sDebugMenu->spriteId != SPRITE_NONE)
        DestroySpriteAndFreeResources(&gSprites[sDebugMenu->spriteId]);

    if (sDebugMenu->arrowTaskId != TASK_NONE)
        RemoveScrollIndicatorArrowPair(sDebugMenu->arrowTaskId);
    
    sDebugMenu->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 39, 28, 148, totalItems - 1, TAG_SCROLL_ARROW, TAG_SCROLL_ARROW, &sDebugMenu->cursorPosition);
}

static void Task_DebugActionBuildListMenuInfo(u8 taskId)
{
    PlaySE(SE_SELECT);
    sDebugMenu->cursorStackDepth++;
    BuildDebugListMenuData(ACTIVE_LIST_INFO);
}

static void Task_DebugActionBuildListMenuWorld(u8 taskId)
{
    PlaySE(SE_SELECT);
    sDebugMenu->cursorStackDepth++;
    BuildDebugListMenuData(ACTIVE_LIST_WORLD);
}

static void Task_DebugActionBuildListMenuPlayer(u8 taskId)
{
    PlaySE(SE_SELECT);
    sDebugMenu->cursorStackDepth++;
    BuildDebugListMenuData(ACTIVE_LIST_PLAYER);
}

static void Task_DebugActionSoundTestScreen(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    gMain.savedCallback = CB2_DebugMenu;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    task->func = Task_GoToSoundTestScreen;
}

static void Task_GoToSoundTestScreen(u8 taskId)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitSoundTestScreen);
}

static void Task_DebugActionSoftReset(u8 taskId)
{
    DoSoftReset();
}

static void Task_DebugActionCredits(u8 taskId)
{
    PlaySE(SE_SELECT);
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_VanadiumTeam);
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
}

static void Task_DebugActionSaveblock(u8 taskId)
{
    u8 str[2][32];
    u8 *strPtr;
    u32 i;

    PlaySE(SE_SELECT);
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));

    for (i = 0; i < 2; i++)
    {
        strPtr = StringCopy(str[i], sText_Saveblock);
        strPtr = ConvertIntToDecimalStringN(strPtr, i + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, i * 32, sTextColor_Default, TEXT_SKIP_DRAW, str[i]);
    }
    
    strPtr = ConvertIntToDecimalStringN(str[0], sizeof(struct SaveBlock1), STR_CONV_MODE_LEFT_ALIGN, 6);
    *(strPtr)++ = CHAR_SLASH;
    strPtr = ConvertIntToDecimalStringN(strPtr, SECTOR_DATA_SIZE * (SECTOR_ID_SAVEBLOCK1_END - SECTOR_ID_SAVEBLOCK1_START + 1), STR_CONV_MODE_LEFT_ALIGN, 6);

    strPtr = ConvertIntToDecimalStringN(str[1], sizeof(struct SaveBlock2), STR_CONV_MODE_LEFT_ALIGN, 6);
    *(strPtr)++ = CHAR_SLASH;
    strPtr = ConvertIntToDecimalStringN(strPtr, SECTOR_DATA_SIZE * (SECTOR_ID_SAVEBLOCK2_END - SECTOR_ID_SAVEBLOCK2_START + 1), STR_CONV_MODE_LEFT_ALIGN, 6);

    for (i = 0; i < 2; i++)
    {
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 4, i * 32 + 12, sTextColor_Default, TEXT_SKIP_DRAW, str[i]);
    }

    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
}

#define tMapGroup data[0]
#define tMapNum data[1]
#define tWarpId data[2]
#define tXPos data[3]
#define tYPos data[4]
#define tState data[5]

static void Task_DebugActionWarp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[8];
    u8 x;
    u32 i;

    PlaySE(SE_SELECT);
    RemoveScrollIndicatorArrowPair(sDebugMenu->arrowTaskId);
    sDebugMenu->arrowTaskId = TASK_NONE;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    ConvertIntToDecimalStringN(str, 0, STR_CONV_MODE_LEFT_ALIGN, 3);

    for (i = 0; i < ARRAY_COUNT(sText_MapGroupNumWarp); i++)
    {
        x = GetStringRightAlignXOffset(FONT_SMALL, sText_MapGroupNumWarp[i], (sWindowTemplates[WIN_DESCRIPTION].width * 8) / 2);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, x, i * 16, sTextColor_Default, TEXT_SKIP_DRAW, sText_MapGroupNumWarp[i]);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 68, i * 16, (i == task->tState) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
    }

    GetMapNameGeneric(str, Overworld_GetMapHeaderByGroupAndId(task->tMapGroup, task->tMapNum)->regionMapSectionId);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, GetStringCenterAlignXOffset(FONT_SMALL, str, sWindowTemplates[WIN_DESCRIPTION].width * 8), 96, sTextColor_Green, TEXT_SKIP_DRAW, str);

    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

    task->func = Task_HandleWarpInput;
    task->tMapGroup = 0;
    task->tMapNum = 0;
    task->tWarpId = 0;
    task->tXPos = 0;
    task->tYPos = 0;
    task->tState = WARP_STATE_GROUP;

    sDebugMenu->cursorStackDepth++;
}

static void Task_HandleWarpInput(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    const struct MapHeader *mapHeader;
    u8 str[8];
    u8 x;
    u16 limit;
    u32 i;

    if (JOY_REPEAT(DPAD_UP))
    {
        switch (task->tState)
        {
        case WARP_STATE_GROUP:
            limit = MAP_GROUPS_COUNT;
            break;
        case WARP_STATE_NUM:
            limit = sMapNumCount[task->tMapGroup];
            break;
        case WARP_STATE_WARP:
            limit = Overworld_GetMapHeaderByGroupAndId(task->tMapGroup, task->tMapNum)->events->warpCount - 1;
            break;
        case WARP_STATE_X:
            limit = Overworld_GetMapHeaderByGroupAndId(task->tMapGroup, task->tMapNum)->mapLayout->width - 1;
            break;
        case WARP_STATE_Y:
            limit = Overworld_GetMapHeaderByGroupAndId(task->tMapGroup, task->tMapNum)->mapLayout->height - 1;
            break;
        }
        
        if (task->data[task->tState] < limit)
        {
            PlaySE(SE_SELECT);
            task->data[task->tState]++;
        }
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (task->data[task->tState] > ((task->tState == WARP_STATE_WARP) ? WARP_ID_NONE : 0))
        {
            PlaySE(SE_SELECT);
            task->data[task->tState]--;
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if ((task->tState == WARP_STATE_WARP) && task->tWarpId != -1)
        {
            SetWarpDestinationToMapWarp(task->tMapGroup, task->tMapNum, task->tWarpId);
            DoTeleportTileWarp();
            ResetInitialPlayerAvatarState();
            return;
        }
        else if ((task->tState == WARP_STATE_Y))
        {
            SetWarpDestination(task->tMapGroup, task->tMapNum, task->tWarpId, task->tXPos, task->tYPos);
            DoTeleportTileWarp();
            ResetInitialPlayerAvatarState();
            return;
        }
        else
        {
            task->tState++;
            PlaySE(SE_SELECT);
            FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));

            for (i = 0; i < ARRAY_COUNT(sText_MapGroupNumWarp); i++)
            {
                if (task->data[i] == WARP_ID_NONE)
                    StringCopy(str, sText_ExactPosition);
                else
                    ConvertIntToDecimalStringN(str, task->data[i], STR_CONV_MODE_LEFT_ALIGN, 3);
                x = GetStringRightAlignXOffset(FONT_SMALL, sText_MapGroupNumWarp[i], (sWindowTemplates[WIN_DESCRIPTION].width * 8) / 2);
                AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, x, i * 16, sTextColor_Default, TEXT_SKIP_DRAW, sText_MapGroupNumWarp[i]);
                AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 68, i * 16, (i == task->tState) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
            }

            GetMapNameGeneric(str, Overworld_GetMapHeaderByGroupAndId(task->tMapGroup, task->tMapNum)->regionMapSectionId);
            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 0, 96, sWindowTemplates[WIN_DESCRIPTION].width * 8, 16);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, GetStringCenterAlignXOffset(FONT_SMALL, str, sWindowTemplates[WIN_DESCRIPTION].width * 8), 96, sTextColor_Green, TEXT_SKIP_DRAW, str);

            CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if (task->tState == WARP_STATE_GROUP)
        {
            sDebugMenu->cursorStackDepth--;
            BuildDebugListMenuData(ACTIVE_LIST_WORLD);
            task->func = Task_DebugMenuProcessInput;
        }
        else
        {
            task->tState--;
            FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));

            if (task->tState == WARP_STATE_WARP)
            {
                task->tXPos = 0;
                task->tYPos = 0;
            }

            for (i = 0; i < ARRAY_COUNT(sText_MapGroupNumWarp); i++)
            {
                if (task->data[i] == WARP_ID_NONE)
                    StringCopy(str, sText_ExactPosition);
                else
                    ConvertIntToDecimalStringN(str, task->data[i], STR_CONV_MODE_LEFT_ALIGN, 3);
                x = GetStringRightAlignXOffset(FONT_SMALL, sText_MapGroupNumWarp[i], (sWindowTemplates[WIN_DESCRIPTION].width * 8) / 2);
                AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, x, i * 16, sTextColor_Default, TEXT_SKIP_DRAW, sText_MapGroupNumWarp[i]);
                AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 68, i * 16, (i == task->tState) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
            }

            GetMapNameGeneric(str, Overworld_GetMapHeaderByGroupAndId(task->tMapGroup, task->tMapNum)->regionMapSectionId);
            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 0, 96, sWindowTemplates[WIN_DESCRIPTION].width * 8, 16);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, GetStringCenterAlignXOffset(FONT_SMALL, str, sWindowTemplates[WIN_DESCRIPTION].width * 8), 96, sTextColor_Green, TEXT_SKIP_DRAW, str);

            CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
        }
    }

    if (JOY_REPEAT(DPAD_ANY))
    {
        if (task->data[task->tState] == WARP_ID_NONE)
            StringCopy(str, sText_ExactPosition);
        else
            ConvertIntToDecimalStringN(str, task->data[task->tState], STR_CONV_MODE_LEFT_ALIGN, 3);
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 68, task->tState * 16, (sWindowTemplates[WIN_DESCRIPTION].width * 8) - 68, 16);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 68, task->tState * 16, sTextColor_Green, TEXT_SKIP_DRAW, str);

        GetMapNameGeneric(str, Overworld_GetMapHeaderByGroupAndId(task->tMapGroup, task->tMapNum)->regionMapSectionId);
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 0, 96, sWindowTemplates[WIN_DESCRIPTION].width * 8, 16);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, GetStringCenterAlignXOffset(FONT_SMALL, str, sWindowTemplates[WIN_DESCRIPTION].width * 8), 96, sTextColor_Green, TEXT_SKIP_DRAW, str);
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
    }
}

#undef tMapGroup
#undef tMapNum
#undef tWarpId
#undef tXPos
#undef tYPos
#undef tState

#define tSelectedFlag data[0]
#define tSelectedDigit data[1]

static void Task_DebugActionFlags(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[8];

    PlaySE(SE_SELECT);
    RemoveScrollIndicatorArrowPair(sDebugMenu->arrowTaskId);
    sDebugMenu->arrowTaskId = TASK_NONE;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));

    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_Flag);
    ConvertIntToHexStringN(str, 1, STR_CONV_MODE_LEADING_ZEROS, 4);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 40, 0, sTextColor_Green, TEXT_SKIP_DRAW, str);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 72, 0, sTextColor_TrueFalse[FlagGet(1)], TEXT_SKIP_DRAW, sText_TrueFalse[FlagGet(1)]);
    
    ConvertIntToHexStringN(str, sHexDigitSelector[0], STR_CONV_MODE_LEADING_ZEROS, 3);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 16, sTextColor_Default, TEXT_SKIP_DRAW, sText_Digit);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 45, 16, sTextColor_Green, TEXT_SKIP_DRAW, str);
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

    task->func = Task_HandleFlagsInput;
    task->tSelectedFlag = 1;
    task->tSelectedDigit = 0;

    sDebugMenu->cursorStackDepth++;
}

static void Task_HandleFlagsInput(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[8];

    if (JOY_REPEAT(DPAD_UP))
    {
        if (task->tSelectedFlag < FLAGS_COUNT - sHexDigitSelector[task->tSelectedDigit])
        {
            PlaySE(SE_SELECT);
            task->tSelectedFlag += sHexDigitSelector[task->tSelectedDigit];
        }
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (task->tSelectedFlag > sHexDigitSelector[task->tSelectedDigit])
        {
            PlaySE(SE_SELECT);
            task->tSelectedFlag -= sHexDigitSelector[task->tSelectedDigit];
        }
    }
    else if (JOY_REPEAT(DPAD_RIGHT))
    {
        if (task->tSelectedDigit > 0)
        {
            PlaySE(SE_SELECT);
            task->tSelectedDigit--;
        }
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        if (task->tSelectedDigit < ARRAY_COUNT(sHexDigitSelector) - 1)
        {
            PlaySE(SE_SELECT);
            task->tSelectedDigit++;
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        FlagToggle(task->tSelectedFlag);

        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 72, 0, 64, 16);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 72, 0, sTextColor_TrueFalse[FlagGet(task->tSelectedFlag)], TEXT_SKIP_DRAW, sText_TrueFalse[FlagGet(task->tSelectedFlag)]);
    
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        sDebugMenu->cursorStackDepth--;
        BuildDebugListMenuData(ACTIVE_LIST_WORLD);
        task->func = Task_DebugMenuProcessInput;
    }

    if (JOY_REPEAT(DPAD_ANY))
    {
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 40, 0, 64, 16);
        ConvertIntToHexStringN(str, task->tSelectedFlag, STR_CONV_MODE_LEADING_ZEROS, 4);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 40, 0, sTextColor_Green, TEXT_SKIP_DRAW, str);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 72, 0, sTextColor_TrueFalse[FlagGet(task->tSelectedFlag)], TEXT_SKIP_DRAW, sText_TrueFalse[FlagGet(task->tSelectedFlag)]);
    
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 45, 16, 48, 16);
        ConvertIntToHexStringN(str, sHexDigitSelector[task->tSelectedDigit], STR_CONV_MODE_LEADING_ZEROS, 3);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 16, sTextColor_Default, TEXT_SKIP_DRAW, sText_Digit);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 45, 16, sTextColor_Green, TEXT_SKIP_DRAW, str);

        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
    }
    
}

#undef tSelectedFlag
#undef tSelectedDigit

#define tSelectedVar data[0]
#define tVarValue data[1]
#define tSelectedDigit data[2]
#define tState data[3]

static void Task_DebugActionVars(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[8];

    PlaySE(SE_SELECT);
    RemoveScrollIndicatorArrowPair(sDebugMenu->arrowTaskId);
    sDebugMenu->arrowTaskId = TASK_NONE;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));

    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_Var);
    ConvertIntToHexStringN(str, VARS_START, STR_CONV_MODE_LEADING_ZEROS, 4);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 40, 0, sTextColor_Green, TEXT_SKIP_DRAW, str);

    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 16, sTextColor_Default, TEXT_SKIP_DRAW, sText_VarValue);
    ConvertIntToHexStringN(str, VarGet(VARS_START), STR_CONV_MODE_LEADING_ZEROS, 4);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 40, 16, sTextColor_Default, TEXT_SKIP_DRAW, str);
    
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 32, sTextColor_Default, TEXT_SKIP_DRAW, sText_Digit);
    ConvertIntToHexStringN(str, sHexDigitSelector[0], STR_CONV_MODE_LEADING_ZEROS, 3);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 45, 32, sTextColor_Green, TEXT_SKIP_DRAW, str);

    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

    task->func = Task_HandleVarsInput;
    task->tSelectedVar = VARS_START;
    task->tVarValue = VarGet(VARS_START);
    task->tSelectedDigit = 0;

    sDebugMenu->cursorStackDepth++;
}

static void Task_HandleVarsInput(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[8];
    u16 limit;
    u32 i;


    if (JOY_REPEAT(DPAD_UP))
    {
        switch (task->tState)
        {
        case 0:
            limit = VARS_END + 1;
            break;
        case 1:
            limit = 65535;
            break;
        }

        if (task->data[task->tState] < limit - sHexDigitSelector[task->tSelectedDigit])
        {
            PlaySE(SE_SELECT);
            task->data[task->tState] += sHexDigitSelector[task->tSelectedDigit];
        }
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        switch (task->tState)
        {
        case 0:
            limit = VARS_START;
            break;
        case 1:
            limit = 0;
            break;
        }

        if (task->data[task->tState] >= limit + sHexDigitSelector[task->tSelectedDigit])
        {
            PlaySE(SE_SELECT);
            task->data[task->tState] -= sHexDigitSelector[task->tSelectedDigit];
        }
    }
    else if (JOY_REPEAT(DPAD_RIGHT))
    {
        if (task->tSelectedDigit > 0)
        {
            PlaySE(SE_SELECT);
            task->tSelectedDigit--;
        }
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        if (task->tSelectedDigit < ARRAY_COUNT(sHexDigitSelector) - 1)
        {
            PlaySE(SE_SELECT);
            task->tSelectedDigit++;
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        switch (task->tState)
        {
        case 0:
            task->tState++;
            task->tVarValue = VarGet(task->tSelectedVar);

            for (i = 0; i < 2; i++)
            {
                ConvertIntToHexStringN(str, task->data[i], STR_CONV_MODE_LEADING_ZEROS, 4);
                AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 40, i * 16, (i == task->tState) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
            }
            CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
            break;
        case 1:
            PlaySE(SE_SUCCESS);
            VarSet(task->tSelectedVar, task->tVarValue);
            break;
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        switch (task->tState)
        {
        case 0:
            sDebugMenu->cursorStackDepth--;
            BuildDebugListMenuData(ACTIVE_LIST_WORLD);
            task->func = Task_DebugMenuProcessInput;
            break;
        case 1:
            task->tState--;

            for (i = 0; i < 2; i++)
            {
                ConvertIntToHexStringN(str, task->data[i], STR_CONV_MODE_LEADING_ZEROS, 4);
                AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 40, i * 16, (i == task->tState) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
            }
            CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
            break;
        }
    }

    if (JOY_REPEAT(DPAD_ANY))
    {
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 40, 0, 32, 48);

        ConvertIntToHexStringN(str, task->tSelectedVar, STR_CONV_MODE_LEADING_ZEROS, 4);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 40, 0, (task->tState == 0) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);

        if (task->tState == 0)
            ConvertIntToHexStringN(str, VarGet(task->tSelectedVar), STR_CONV_MODE_LEADING_ZEROS, 4);
        else
            ConvertIntToHexStringN(str, task->tVarValue, STR_CONV_MODE_LEADING_ZEROS, 4);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 40, 16, (task->tState == 1) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);

        ConvertIntToHexStringN(str, sHexDigitSelector[task->tSelectedDigit], STR_CONV_MODE_LEADING_ZEROS, 3);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 45, 32, sTextColor_Green, TEXT_SKIP_DRAW, str);

        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
    }
}

#undef tSelectedVar
#undef tVarValue
#undef tSelectedDigit
#undef tState

#define tHours data[0]
#define tMinutes data[1]
#define tDays data[2]
#define tState data[3]

static void Task_DebugActionSetTime(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[8];
    u8 str2[8];

    PlaySE(SE_SELECT);
    RemoveScrollIndicatorArrowPair(sDebugMenu->arrowTaskId);
    sDebugMenu->arrowTaskId = TASK_NONE;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));

    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_Time);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 16, sTextColor_Default, TEXT_SKIP_DRAW, sText_Days);

    ConvertIntToDecimalStringN(str, gSaveBlock2Ptr->time.hours, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 30, 0, sTextColor_Green, TEXT_SKIP_DRAW, str);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 40, 0, sTextColor_Default, TEXT_SKIP_DRAW, gText_Colon2);
    ConvertIntToDecimalStringN(str, gSaveBlock2Ptr->time.minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 48, 0, sTextColor_Default, TEXT_SKIP_DRAW, str);

    ConvertIntToDecimalStringN(str2, gSaveBlock2Ptr->time.days, STR_CONV_MODE_LEADING_ZEROS, 5);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 30, 16, sTextColor_Default, TEXT_SKIP_DRAW, str2);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 64, 16, sTextColor_Default, TEXT_SKIP_DRAW, GetDayOfWeekString(gSaveBlock2Ptr->time.days));

    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

    task->func = Task_HandleSetTimeInput;
    task->tHours = gSaveBlock2Ptr->time.hours;
    task->tMinutes = gSaveBlock2Ptr->time.minutes;
    task->tDays = gSaveBlock2Ptr->time.days;
    task->tState = SET_TIME_STATE_HOURS;

    sDebugMenu->cursorStackDepth++;
}

static void Task_HandleSetTimeInput(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[8];
    u8 str2[8];

    if (JOY_REPEAT(DPAD_UP))
    {
        switch (task->tState)
        {
        case SET_TIME_STATE_HOURS:
            if (task->tHours < 23)
            {
                PlaySE(SE_SELECT);
                task->tHours++;
            }
            break;
        case SET_TIME_STATE_MINUTES:
            if (task->tMinutes < 59)
            {
                PlaySE(SE_SELECT);
                task->tMinutes++;
            }
            break;
        case SET_TIME_STATE_DAY_OF_WEEK:
            PlaySE(SE_SELECT);
            task->tDays++;
            break;
        }
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (task->data[task->tState] > 0)
        {
            PlaySE(SE_SELECT);
            task->data[task->tState]--;
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (task->tState < SET_TIME_STATE_DAY_OF_WEEK)
            task->tState++;
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (task->tState > SET_TIME_STATE_HOURS)
            task->tState--;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SUCCESS);
        InitInGameTime(task->tDays, task->tHours, task->tMinutes);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        sDebugMenu->cursorStackDepth--;
        BuildDebugListMenuData(ACTIVE_LIST_WORLD);
        task->func = Task_DebugMenuProcessInput;
    }

    if (JOY_REPEAT(DPAD_ANY))
    {
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 30, 0, 10, 16);
        ConvertIntToDecimalStringN(str, task->tHours, STR_CONV_MODE_LEADING_ZEROS, 2);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 30, 0, (task->tState == SET_TIME_STATE_HOURS) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
        
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 48, 0, 10, 16);
        ConvertIntToDecimalStringN(str, task->tMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 48, 0, (task->tState == SET_TIME_STATE_MINUTES) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);

        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 30, 16, 96, 16);
        //AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 60, 16, (task->tState == SET_TIME_STATE_DAY_OF_WEEK) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, GetDayOfWeekString(task->tDays));
        ConvertIntToDecimalStringN(str2, task->tDays, STR_CONV_MODE_LEADING_ZEROS, 5);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 30, 16, (task->tState == SET_TIME_STATE_DAY_OF_WEEK) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str2);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 64, 16, sTextColor_Default, TEXT_SKIP_DRAW, GetDayOfWeekString(task->tDays));

        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
    }
}

#undef tHours
#undef tMinutes
#undef tDays
#undef tState

#define tWeather data[0]

static void Task_DebugActionSetWeather(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 weather = GetCurrentWeather();
    u8 str[8];

    PlaySE(SE_SELECT);
    RemoveScrollIndicatorArrowPair(sDebugMenu->arrowTaskId);
    sDebugMenu->arrowTaskId = TASK_NONE;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));

    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_Weather);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 8, 16, sTextColor_Green, TEXT_SKIP_DRAW, sText_WeatherTypes[weather]);

    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

    task->tWeather = weather;
    task->func = Task_HandleSetWeatherInput;

    sDebugMenu->cursorStackDepth++;
}

static void Task_HandleSetWeatherInput(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[8];

    if (JOY_REPEAT(DPAD_UP))
    {
        if (task->tWeather < WEATHER_ABNORMAL)
        {
            PlaySE(SE_SELECT);
            task->tWeather++;
        }
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (task->tWeather > 0)
        {
            PlaySE(SE_SELECT);
            task->tWeather--;
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SUCCESS);
        SetWeather(task->tWeather);
        sChangedWeatherDebug = TRUE;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        sDebugMenu->cursorStackDepth--;
        BuildDebugListMenuData(ACTIVE_LIST_WORLD);
        task->func = Task_DebugMenuProcessInput;
    }

    if (JOY_REPEAT(DPAD_ANY))
    {
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 8, 16, 88, 16);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 8, 16, sTextColor_Green, TEXT_SKIP_DRAW, sText_WeatherTypes[task->tWeather]);
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
    }
}

#undef tWeather

static void Task_DebugActionResetQuests(u8 taskId)
{
    PlaySE(SE_PC_OFF);
    memset(gSaveBlock1Ptr->quests, 0, sizeof(gSaveBlock1Ptr->quests));
}

static void Task_DebugActionResetBerries(u8 taskId)
{
    PlaySE(SE_USE_ITEM);
    ScriptContext_SetupScript(EventScript_ResetAllBerries);
}

static void Task_DebugActionGodmode(u8 taskId)
{
    gGodMode ^= 1;

    if (gGodMode)
        PlaySE(SE_PC_LOGIN);
    else
        PlaySE(SE_PC_OFF);

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_Status);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 36, 0, sTextColor_TrueFalse[gGodMode], TEXT_SKIP_DRAW, sText_TrueFalse[gGodMode]);
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
}

static void Task_DebugActionHealParty(u8 taskId)
{
    PlaySE(SE_USE_ITEM);
    HealPlayerParty();
}

#define tSelectedMon data[0]
#define tSelectedMove data[1]
#define tMoveIndex data[2]
#define tState data[3]

static void Task_DebugActionBuildParty(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[16];
    u8 size;
    u32 i, j;

    PlaySE(SE_SELECT);
    RemoveScrollIndicatorArrowPair(sDebugMenu->arrowTaskId);
    sDebugMenu->arrowTaskId = TASK_NONE;

    LoadMonIconPalettes(); 

    for (i = 0; i < PARTY_SIZE; i++)
    {
        sPartyBuilder[i] = AllocZeroed(sizeof(struct PartyBuilder));
        sPartyBuilder[i]->spriteId = CreateMonIconNoPersonality(sPartyBuilder[i]->species, (i == 0) ? SpriteCB_MonIcon : SpriteCallbackDummy, i * 24 + 100, 40, 1, FALSE);

        sPartyBuilder[i]->species = SPECIES_NONE;
        sPartyBuilder[i]->level = 1;
        sPartyBuilder[i]->ability = 0;
        sPartyBuilder[i]->shiny = 0;

        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            sPartyBuilder[i]->moveListIndex[j] = 0;
            sPartyBuilder[i]->moves[j] = MOVE_NONE;
        }
    }
    
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 24, sTextColor_Default, TEXT_SKIP_DRAW, sText_Species);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 36, sTextColor_Default, TEXT_SKIP_DRAW, sText_Lvl);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 48, sTextColor_Default, TEXT_SKIP_DRAW, sText_Moves);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 88, sTextColor_Default, TEXT_SKIP_DRAW, sText_Ability);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 100, sTextColor_Default, TEXT_SKIP_DRAW, sText_Shiny);
    
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 24, sTextColor_Green, TEXT_SKIP_DRAW, gSpeciesNames[sPartyBuilder[0]->species]);
    ConvertIntToDecimalStringN(str, sPartyBuilder[0]->level, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 36, sTextColor_Default, TEXT_SKIP_DRAW, str);

    for (i = 0; i < MAX_MON_MOVES; i++)
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, (65 * (i & 1)), 60 + (6 * (i & 2)), sTextColor_Default, TEXT_SKIP_DRAW, gMoveNames[MOVE_NONE]);
    
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 88, (task->tState == PARTY_BUILDER_STATE_ABILITY) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, gAbilityNames[gSpeciesInfo[sPartyBuilder[0]->species].abilities[0]]);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 100, sTextColor_Default, TEXT_SKIP_DRAW, sText_TrueFalse[FALSE]);

    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

    task->func = Task_HandleBuildPartyInput;
    task->tSelectedMon = 0;
    task->tSelectedMove = 0;
    task->tMoveIndex = 0;
    task->tState = PARTY_BUILDER_STATE_MON;

    sDebugMenu->cursorStackDepth++;
}

static void Task_HandleBuildPartyInput(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[16];
    u32 i;

    if (JOY_REPEAT(DPAD_UP))
    {
        switch (task->tState)
        {
        case PARTY_BUILDER_STATE_MON:
            if (sPartyBuilder[task->tSelectedMon]->species < NUM_SPECIES - 1)
            {
                PlaySE(SE_SELECT);
                Free(sPartyBuilder[task->tSelectedMon]->moveList);
                FreeAndDestroyMonIconSprite(&gSprites[sPartyBuilder[task->tSelectedMon]->spriteId]);
                sPartyBuilder[task->tSelectedMon]->species++;
                sPartyBuilder[task->tSelectedMon]->spriteId = CreateMonIconNoPersonality(sPartyBuilder[task->tSelectedMon]->species, SpriteCB_MonIcon, task->tSelectedMon * 24 + 100, 40, 0, FALSE);
                sPartyBuilder[task->tSelectedMon]->moveListTaskId = CreateTask(Task_BuildLearnableMoveList, 1);
                for (i = 0; i < MAX_MON_MOVES; i++)
                    sPartyBuilder[task->tSelectedMon]->moveListIndex[i] = 0;
            }
            break;
        case PARTY_BUILDER_STATE_LVL:
            if (sPartyBuilder[task->tSelectedMon]->level < MAX_LEVEL)
            {
                PlaySE(SE_SELECT);
                sPartyBuilder[task->tSelectedMon]->level++;
            }
            break;
        case PARTY_BUILDER_STATE_MOVES:
            if (sPartyBuilder[task->tSelectedMon]->moveListIndex[task->tSelectedMove] < sPartyBuilder[task->tSelectedMon]->moveListSize)
            {
                PlaySE(SE_SELECT);
                sPartyBuilder[task->tSelectedMon]->moves[task->tSelectedMove] = sPartyBuilder[task->tSelectedMon]->moveList[sPartyBuilder[task->tSelectedMon]->moveListIndex[task->tSelectedMove]++];
            }
            break;
        case PARTY_BUILDER_STATE_ABILITY:
            if ((sPartyBuilder[task->tSelectedMon]->ability ^= 1) != ABILITY_NONE)
            {
                PlaySE(SE_SELECT);
                sPartyBuilder[task->tSelectedMon]->ability ^= 1;
            }
            break;
        case PARTY_BUILDER_STATE_SHINY:
            PlaySE(SE_SELECT);
            sPartyBuilder[task->tSelectedMon]->shiny ^= 1;
            break;
        }
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        switch (task->tState)
        {
        case PARTY_BUILDER_STATE_MON:
            if (sPartyBuilder[task->tSelectedMon]->species > SPECIES_NONE)
            {
                PlaySE(SE_SELECT);
                Free(sPartyBuilder[task->tSelectedMon]->moveList);
                FreeAndDestroyMonIconSprite(&gSprites[sPartyBuilder[task->tSelectedMon]->spriteId]);
                sPartyBuilder[task->tSelectedMon]->species--;
                sPartyBuilder[task->tSelectedMon]->spriteId = CreateMonIconNoPersonality(sPartyBuilder[task->tSelectedMon]->species, SpriteCB_MonIcon, task->tSelectedMon * 24 + 100, 40, 0, FALSE);
                sPartyBuilder[task->tSelectedMon]->moveListTaskId = CreateTask(Task_BuildLearnableMoveList, 1);
                for (i = 0; i < MAX_MON_MOVES; i++)
                    sPartyBuilder[task->tSelectedMon]->moveListIndex[i] = 0;
            }
            break;
        case PARTY_BUILDER_STATE_LVL:
            if (sPartyBuilder[task->tSelectedMon]->level > 1)
            {
                PlaySE(SE_SELECT);
                sPartyBuilder[task->tSelectedMon]->level--;
            }
            break;
        case PARTY_BUILDER_STATE_MOVES:
            if (sPartyBuilder[task->tSelectedMon]->moveListIndex[task->tSelectedMove] != 0)
            {
                PlaySE(SE_SELECT);
                sPartyBuilder[task->tSelectedMon]->moves[task->tSelectedMove] = sPartyBuilder[task->tSelectedMon]->moveList[sPartyBuilder[task->tSelectedMon]->moveListIndex[task->tSelectedMove]--];
            }
            break;
        case PARTY_BUILDER_STATE_ABILITY:
            if ((sPartyBuilder[task->tSelectedMon]->ability ^= 1) != ABILITY_NONE)
            {
                PlaySE(SE_SELECT);
                sPartyBuilder[task->tSelectedMon]->ability ^= 1;
            }
            break;
        case PARTY_BUILDER_STATE_SHINY:
            PlaySE(SE_SELECT);
            sPartyBuilder[task->tSelectedMon]->shiny ^= 1;
            break;
        }
    }
    else if (JOY_REPEAT(DPAD_RIGHT))
    {
        if (task->tState == PARTY_BUILDER_STATE_MOVES)
        {
            if (task->tSelectedMove < MAX_MON_MOVES - 1)
            {
                PlaySE(SE_SELECT);
                task->tSelectedMove++;
            }
        }
        else
        {
            if (task->tSelectedMon < PARTY_SIZE - 1)
            {
                PlaySE(SE_SELECT);
                gSprites[sPartyBuilder[task->tSelectedMon]->spriteId].callback = SpriteCallbackDummy;
                gSprites[sPartyBuilder[task->tSelectedMon]->spriteId].subpriority = 1;
                task->tSelectedMon++;
                gSprites[sPartyBuilder[task->tSelectedMon]->spriteId].callback = SpriteCB_MonIcon;
                gSprites[sPartyBuilder[task->tSelectedMon]->spriteId].subpriority = 0;
                task->tSelectedMove = 0;
                task->tState = PARTY_BUILDER_STATE_MON;
            }
        }
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        if (task->tState == PARTY_BUILDER_STATE_MOVES)
        {
            if (task->tSelectedMove > 0)
            {
                PlaySE(SE_SELECT);
                task->tSelectedMove--;
            }
        }
        else
        {
            if (task->tSelectedMon > 0)
            {
                PlaySE(SE_SELECT);
                gSprites[sPartyBuilder[task->tSelectedMon]->spriteId].callback = SpriteCallbackDummy;
                gSprites[sPartyBuilder[task->tSelectedMon]->spriteId].subpriority = 1;
                task->tSelectedMon--;
                gSprites[sPartyBuilder[task->tSelectedMon]->spriteId].callback = SpriteCB_MonIcon;
                gSprites[sPartyBuilder[task->tSelectedMon]->spriteId].subpriority = 0;
                task->tSelectedMove = 0;
                task->tState = PARTY_BUILDER_STATE_MON;
            }
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (task->tState == PARTY_BUILDER_STATE_SHINY)
        {
            if (sPartyBuilder[0]->species == SPECIES_NONE
             && sPartyBuilder[1]->species == SPECIES_NONE
             && sPartyBuilder[2]->species == SPECIES_NONE
             && sPartyBuilder[3]->species == SPECIES_NONE
             && sPartyBuilder[4]->species == SPECIES_NONE
             && sPartyBuilder[5]->species == SPECIES_NONE)
            {
                PlaySE(SE_FAILURE);
            }
            else
            {
                PlaySE(SE_SUCCESS);
                task->func = Task_BuildCustomParty;
            }
        }
        else
        {
            task->tState++;

            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 42, 24, 64, 32);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 24, (task->tState == PARTY_BUILDER_STATE_MON) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, gSpeciesNames[sPartyBuilder[task->tSelectedMon]->species]);

            ConvertIntToDecimalStringN(str, sPartyBuilder[task->tSelectedMon]->level, STR_CONV_MODE_LEFT_ALIGN, 3);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 36, (task->tState == PARTY_BUILDER_STATE_LVL) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);

            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 0, 60, sWindowTemplates[WIN_DESCRIPTION].width * 8, 32);
            for (i = 0; i < MAX_MON_MOVES; i++)
                AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, (65 * (i & 1)), 60 + (6 * (i & 2)), (task->tSelectedMove == i && task->tState == PARTY_BUILDER_STATE_MOVES) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, gMoveNames[sPartyBuilder[task->tSelectedMon]->moves[i]]);

            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 42, 88, 64, 32);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 88, (task->tState == PARTY_BUILDER_STATE_ABILITY) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, gAbilityNames[gSpeciesInfo[sPartyBuilder[task->tSelectedMon]->species].abilities[sPartyBuilder[task->tSelectedMon]->ability]]);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 100, (task->tState == PARTY_BUILDER_STATE_SHINY) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, sText_TrueFalse[sPartyBuilder[task->tSelectedMon]->shiny]);

            CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if (task->tState == PARTY_BUILDER_STATE_MON)
        {
            for (i = 0; i < PARTY_SIZE; i++)
            {
                FreeAndDestroyMonIconSprite(&gSprites[sPartyBuilder[i]->spriteId]);
                Free(sPartyBuilder[i]);
            }

            FreeMonIconPalettes();

            sDebugMenu->cursorStackDepth--;
            BuildDebugListMenuData(ACTIVE_LIST_PLAYER);
            task->func = Task_DebugMenuProcessInput;
        }
        else
        {
            task->tState--;

            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 42, 24, 64, 32);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 24, (task->tState == PARTY_BUILDER_STATE_MON) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, gSpeciesNames[sPartyBuilder[task->tSelectedMon]->species]);

            ConvertIntToDecimalStringN(str, sPartyBuilder[task->tSelectedMon]->level, STR_CONV_MODE_LEFT_ALIGN, 3);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 36, (task->tState == PARTY_BUILDER_STATE_LVL) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
            
            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 0, 60, sWindowTemplates[WIN_DESCRIPTION].width * 8, 32);
            for (i = 0; i < MAX_MON_MOVES; i++)
                AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, (65 * (i & 1)), 60 + (6 * (i & 2)), (task->tSelectedMove == i && task->tState == PARTY_BUILDER_STATE_MOVES) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, gMoveNames[sPartyBuilder[task->tSelectedMon]->moves[i]]);
        
            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 42, 88, 64, 32);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 88, (task->tState == PARTY_BUILDER_STATE_ABILITY) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, gAbilityNames[gSpeciesInfo[sPartyBuilder[task->tSelectedMon]->species].abilities[sPartyBuilder[task->tSelectedMon]->ability]]);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 100, (task->tState == PARTY_BUILDER_STATE_SHINY) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, sText_TrueFalse[sPartyBuilder[task->tSelectedMon]->shiny]);

            CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
        }
    }

    if (JOY_REPEAT(DPAD_ANY))
    {
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 42, 24, 64, 32);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 24, (task->tState == PARTY_BUILDER_STATE_MON) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, gSpeciesNames[sPartyBuilder[task->tSelectedMon]->species]);

        ConvertIntToDecimalStringN(str, sPartyBuilder[task->tSelectedMon]->level, STR_CONV_MODE_LEFT_ALIGN, 3);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 36, (task->tState == PARTY_BUILDER_STATE_LVL) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);

        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 0, 60, sWindowTemplates[WIN_DESCRIPTION].width * 8, 32);
        for (i = 0; i < MAX_MON_MOVES; i++)
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, (65 * (i & 1)), 60 + (6 * (i & 2)), (task->tSelectedMove == i && task->tState == PARTY_BUILDER_STATE_MOVES) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, gMoveNames[sPartyBuilder[task->tSelectedMon]->moves[i]]);

        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 42, 88, 64, 32);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 88, (task->tState == PARTY_BUILDER_STATE_ABILITY) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, gAbilityNames[gSpeciesInfo[sPartyBuilder[task->tSelectedMon]->species].abilities[sPartyBuilder[task->tSelectedMon]->ability]]);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 42, 100, (task->tState == PARTY_BUILDER_STATE_SHINY) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, sText_TrueFalse[sPartyBuilder[task->tSelectedMon]->shiny]);

        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
    }
}

static void Task_BuildLearnableMoveList(u8 taskId)
{
    struct Task *task = &gTasks[FindTaskIdByFunc(Task_HandleBuildPartyInput)];
    u16 species = sPartyBuilder[task->tSelectedMon]->species;
    const u16 *learnset = gLevelUpLearnsets[species];
    u8 moveListIndex = 0;
    u32 i;

    sPartyBuilder[task->tSelectedMon]->moveList = AllocZeroed((MAX_LEVEL_UP_MOVES + NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES) * sizeof(u16));

    for (i = 0; i < MAX_LEVEL_UP_MOVES; i++)
    {
        if (gLevelUpLearnsets[species][i] == LEVEL_UP_END)
            break;
        
        sPartyBuilder[task->tSelectedMon]->moveList[moveListIndex] = gLevelUpLearnsets[species][i]  & LEVEL_UP_MOVE_ID;
        moveListIndex++;
    }

    for (i = 0; i < (NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES); i++)
    {
        if (CanSpeciesLearnTMHM(species, i))
        {
            u16 moveId = ItemIdToBattleMoveId(ITEM_TM01 + i);
            sPartyBuilder[task->tSelectedMon]->moveList[moveListIndex] = moveId;
            moveListIndex++;
        }
    }

    sPartyBuilder[task->tSelectedMon]->moveListSize = moveListIndex;

    DestroyTask(taskId);
}

static void Task_BuildCustomParty(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct Pokemon mon[PARTY_SIZE];
    u32 i, j;
    u8 partyIndex;

    ZeroPlayerPartyMons();

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sPartyBuilder[i]->species == SPECIES_NONE)
            continue;
        
        if (sPartyBuilder[i]->shiny == TRUE)
        {
            CreateShinyMon(&mon[i], sPartyBuilder[i]->species, sPartyBuilder[i]->level);
        }
        else
        {
            CreateMon(&mon[i], sPartyBuilder[i]->species, sPartyBuilder[i]->level, USE_RANDOM_IVS, TRUE, Random32(), OT_ID_PLAYER_ID, 0);
        }

        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            SetMonMoveSlot(&mon[i], sPartyBuilder[i]->moves[j], j);
        }

        SetMonData(&mon[i], MON_DATA_ABILITY_NUM, &gSpeciesInfo[sPartyBuilder[i]->species].abilities[sPartyBuilder[i]->ability]);

        SetMonData(&mon[i], MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
        SetMonData(&mon[i], MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);

        CopyMon(&gPlayerParty[partyIndex], &mon[i], sizeof(mon[i]));
        partyIndex++;
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        FreeAndDestroyMonIconSprite(&gSprites[sPartyBuilder[i]->spriteId]);
        Free(sPartyBuilder[i]);
    }

    FreeMonIconPalettes();

    sDebugMenu->cursorStackDepth--;
    BuildDebugListMenuData(ACTIVE_LIST_PLAYER);
    task->func = Task_DebugMenuProcessInput;
}

#undef tSelectedMon
#undef tSelectedMove
#undef tMoveIndex
#undef tState

#define tItem data[0]
#define tQuantity data[1]
#define tState data[2]

static void Task_DebugActionGiveItem(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[8];

    PlaySE(SE_SELECT);
    RemoveScrollIndicatorArrowPair(sDebugMenu->arrowTaskId);
    sDebugMenu->arrowTaskId = TASK_NONE;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_ItemId);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 16, sTextColor_Default, TEXT_SKIP_DRAW, sText_ItemName);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 32, sTextColor_Default, TEXT_SKIP_DRAW, sText_ItemDesc);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 88, sTextColor_Default, TEXT_SKIP_DRAW, sText_ItemQuantity);
    
    ConvertIntToDecimalStringN(str, ItemId_GetId(1), STR_CONV_MODE_LEADING_ZEROS, 3);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 32, 0, sTextColor_Green, TEXT_SKIP_DRAW, str);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 32, 16, sTextColor_Default, TEXT_SKIP_DRAW, ItemId_GetName(1));
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 4, 44, sTextColor_Default, TEXT_SKIP_DRAW, ItemId_GetDescription(1));
    ConvertIntToDecimalStringN(str, 1, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 48, 88, sTextColor_Default, TEXT_SKIP_DRAW, str);

    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

    sDebugMenu->spriteId = AddItemIconSprite(TAG_ITEM_ICON, TAG_ITEM_ICON, 1);
    gSprites[sDebugMenu->spriteId].x = 220;
    gSprites[sDebugMenu->spriteId].y = 48;
    gSprites[sDebugMenu->spriteId].oam.priority = 0;

    task->func = Task_HandleGiveItemInput;
    task->tItem = 1;
    task->tQuantity = 1;
    task->tState = 0;

    sDebugMenu->cursorStackDepth++;
}

static void Task_HandleGiveItemInput(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 str[8];

    if (JOY_REPEAT(DPAD_UP))
    {
        if (task->data[task->tState] < (task->tState == 0) ? ITEMS_COUNT : MAX_BAG_ITEM_CAPACITY)
        {
            PlaySE(SE_SELECT);
            task->data[task->tState]++;
        }
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (task->data[task->tState] > 1)
        {
            PlaySE(SE_SELECT);
            task->data[task->tState]--;
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        switch (task->tState)
        {
        case 0:
            task->tState++;
            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 32, 0, 80, 16);
            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 48, 88, 16, 16);
            ConvertIntToDecimalStringN(str, ItemId_GetId(task->tItem), STR_CONV_MODE_LEADING_ZEROS, 3);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 32, 0, (task->tState == 0) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
            ConvertIntToDecimalStringN(str, task->tQuantity, STR_CONV_MODE_LEADING_ZEROS, 2);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 48, 88, (task->tState == 1) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
            CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
            break;
        case 1:
            AddBagItem(task->tItem, task->tQuantity);
            PlaySE(SE_SUCCESS);
            break;
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        switch (task->tState)
        {
        case 0:
            sDebugMenu->cursorStackDepth--;
            BuildDebugListMenuData(ACTIVE_LIST_PLAYER);
            task->func = Task_DebugMenuProcessInput;
            break;
        case 1:
            task->tState--;
            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 32, 0, 80, 16);
            FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 48, 88, 16, 16);
            ConvertIntToDecimalStringN(str, ItemId_GetId(task->tItem), STR_CONV_MODE_LEADING_ZEROS, 3);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 32, 0, (task->tState == 0) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
            ConvertIntToDecimalStringN(str, task->tQuantity, STR_CONV_MODE_LEADING_ZEROS, 2);
            AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 48, 88, (task->tState == 1) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
            CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
            break;
        }
    }

    if (JOY_REPEAT(DPAD_ANY))
    {
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 32, 0, 80, 32);
        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 4, 44, 96, 40);
        ConvertIntToDecimalStringN(str, task->tItem, STR_CONV_MODE_LEADING_ZEROS, 3);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 32, 0, (task->tState == 0) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 32, 16, sTextColor_Default, TEXT_SKIP_DRAW, ItemId_GetName(task->tItem));
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 4, 44, sTextColor_Default, TEXT_SKIP_DRAW, ItemId_GetDescription(task->tItem));

        DestroySpriteAndFreeResources(&gSprites[sDebugMenu->spriteId]);
        sDebugMenu->spriteId = AddItemIconSprite(TAG_ITEM_ICON, TAG_ITEM_ICON, task->tItem);
        gSprites[sDebugMenu->spriteId].x = 220;
        gSprites[sDebugMenu->spriteId].y = 48;
        gSprites[sDebugMenu->spriteId].oam.priority = 0;

        FillWindowPixelRect(WIN_DESCRIPTION, PIXEL_FILL(0), 48, 88, 16, 16);
        ConvertIntToDecimalStringN(str, task->tQuantity, STR_CONV_MODE_LEADING_ZEROS, 2);
        AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 48, 88, (task->tState == 1) ? sTextColor_Green : sTextColor_Default, TEXT_SKIP_DRAW, str);
        
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);
    }
}

#undef tItem
#undef tQuantity
#undef tState

static void Task_DebugActionChangeGender(u8 taskId)
{
    gSaveBlock2Ptr->playerGender ^= 1;

    PlaySE(SE_SUCCESS);

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 0, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_Gender);
    AddTextPrinterParameterized3(WIN_DESCRIPTION, FONT_SMALL, 36, 0, sTextColor_Default, TEXT_SKIP_DRAW, sText_Genders[gSaveBlock2Ptr->playerGender]);
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

    ResetInitialPlayerAvatarState();
}

static void Task_DebugMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        Free(sDebugMenu);
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_ReturnToFieldContestHall);
        gFieldCallback = FieldCB_ReturnToFieldNoScriptCheckMusic;
    }
}

#endif