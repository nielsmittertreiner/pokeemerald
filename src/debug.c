#if DEBUG

#include "global.h"
#include "debug.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "international_string_util.h"
#include "item.h"
#include "list_menu.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "pokemon.h"
#include "region_map.h"
#include "save_location.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "constants/songs.h"
#include "constants/items.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"

void Debug_OpenDebugMenu(void);
static void Debug_ShowMainMenu(void (*HandleInput)(u8), struct ListMenuTemplate ListMenuTemplate);
static void Debug_ShowTogglesSubMenu(void (*HandleInput)(u8), struct ListMenuTemplate ListMenuTemplate);
static void Debug_ShowUtilitySubMenu(void (*HandleInput)(u8), struct ListMenuTemplate ListMenuTemplate);
static void Debug_DestroyMenu(u8);
static void DebugAction_DestroyExtraWindow(u8);

// Input Handlers
static void DebugTask_HandleMenuInput_Main(u8);
static void DebugTask_HandleMenuInput_Utility(u8);
static void DebugTask_HandleMenuInput_Flags(u8);

// Open Menus
static void DebugAction_OpenMenu_Utility(u8);
static void DebugAction_OpenMenu_Flags(u8);

// Utility Functions
static void DebugAction_HealParty(u8);
static void DebugAction_GiveRareCandy(u8);
static void DebugAction_ResetMapFlags(u8);
static void DebugAction_PrepareTrades(u8);

static void DebugAction_Cancel(u8);

// Main menu
static const u8 gDebugText_Utility[] = _("UTILITY");
static const u8 gDebugText_Cancel[] = _("CANCEL");

// Utility menu
static const u8 gDebugText_Utility_SetFlag[] = _("SET FLAG");
static const u8 gDebugText_Utility_HealParty[] = _("HEAL PARTY");
static const u8 gDebugText_Utility_GiveRareCandy[] = _("GIVE RARE CANDY");
static const u8 gDebugText_Utility_ResetAllMapFlags[] = _("RESET MAP FLAGS");
static const u8 gDebugText_Utility_PrepareTrades[] = _("PREPARE TRADES");

// Flags menu
static const u8 gDebugText_Flag_FlagDef[] =_("FLAG: {STR_VAR_1}\n{STR_VAR_2}\n{STR_VAR_3}");
static const u8 gDebugText_Flag_FlagHex[] = _("{STR_VAR_1}\n0x{STR_VAR_2}");
static const u8 gDebugText_Flag_FlagSet[] = _("{COLOR}{06}TRUE{COLOR}{02}");
static const u8 gDebugText_Flag_FlagUnset[] = _("{COLOR}{04}FALSE{COLOR}{02}");

static const u8 digitInidicator_1[] =_("{LEFT_ARROW}+1{RIGHT_ARROW}");
static const u8 digitInidicator_10[] = _("{LEFT_ARROW}+10{RIGHT_ARROW}");
static const u8 digitInidicator_100[] = _("{LEFT_ARROW}+100{RIGHT_ARROW}");
static const u8 digitInidicator_1000[] = _("{LEFT_ARROW}+1000{RIGHT_ARROW}");
static const u8 digitInidicator_10000[] = _("{LEFT_ARROW}+10000{RIGHT_ARROW}");
static const u8 digitInidicator_100000[] = _("{LEFT_ARROW}+100000{RIGHT_ARROW}");
static const u8 digitInidicator_1000000[] = _("{LEFT_ARROW}+1000000{RIGHT_ARROW}");
static const u8 digitInidicator_10000000[] = _("{LEFT_ARROW}+10000000{RIGHT_ARROW}");

const u8 * const gText_DigitIndicator[] =
{
    digitInidicator_1,
    digitInidicator_10,
    digitInidicator_100,
    digitInidicator_1000,
    digitInidicator_10000,
    digitInidicator_100000,
    digitInidicator_1000000,
    digitInidicator_10000000
};

static const s32 sPowersOfTen[] =
{
             1,
            10,
           100,
          1000,
         10000,
        100000,
       1000000,
      10000000,
     100000000,
    1000000000,
};

extern const u8 EventScript_ResetAllMapFlags[];
extern const u8 Debug_EventScript_PrepareTrades[];

static const struct ListMenuItem sDebugMenuItems_Main[] =
{
    [DEBUG_MENU_ITEM_UTILITY] = {gDebugText_Utility, DEBUG_MENU_ITEM_UTILITY},
    [DEBUG_MENU_ITEM_CANCEL] = {gDebugText_Cancel, DEBUG_MENU_ITEM_CANCEL},
};

static const struct ListMenuItem sDebugMenuItems_Utility[] =
{
    [DEBUG_MENU_ITEM_SET_FLAG] = {gDebugText_Utility_SetFlag, DEBUG_MENU_ITEM_SET_FLAG},
    [DEBUG_MENU_ITEM_HEAL_PARTY] = {gDebugText_Utility_HealParty, DEBUG_MENU_ITEM_HEAL_PARTY},
    [DEBUG_MENU_ITEM_GIVE_RARE_CANDY] = {gDebugText_Utility_GiveRareCandy, DEBUG_MENU_ITEM_GIVE_RARE_CANDY},
    [DEBUG_MENU_ITEM_RESET_MAP_FLAGS] = {gDebugText_Utility_ResetAllMapFlags, DEBUG_MENU_ITEM_RESET_MAP_FLAGS},
    [DEBUG_MENU_ITEM_PREPARE_TRADES] = {gDebugText_Utility_PrepareTrades, DEBUG_MENU_ITEM_PREPARE_TRADES},
};

static void (*const sDebugMenuActions_Main[])(u8) =
{
    [DEBUG_MENU_ITEM_UTILITY] = DebugAction_OpenMenu_Utility,
    [DEBUG_MENU_ITEM_CANCEL] = DebugAction_Cancel,
};

static void (*const sDebugMenuActions_Utility[])(u8) =
{
    [DEBUG_MENU_ITEM_SET_FLAG] = DebugAction_OpenMenu_Flags,
    [DEBUG_MENU_ITEM_HEAL_PARTY] = DebugAction_HealParty,
    [DEBUG_MENU_ITEM_GIVE_RARE_CANDY] = DebugAction_GiveRareCandy,
    [DEBUG_MENU_ITEM_RESET_MAP_FLAGS] = DebugAction_ResetMapFlags,
    [DEBUG_MENU_ITEM_PREPARE_TRADES] = DebugAction_PrepareTrades,
};

static const struct WindowTemplate sDebugMainMenuWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = DEBUG_MAIN_MENU_WIDTH,
    .height = 2 * ARRAY_COUNT(sDebugMenuItems_Main),
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct WindowTemplate sDebugSubMenuUtilityWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = DEBUG_UTILITY_MENU_WIDTH,
    .height = 2 * ARRAY_COUNT(sDebugMenuItems_Utility),
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct WindowTemplate sDebugNumberDisplayWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 3 + DEBUG_UTILITY_MENU_WIDTH,
    .tilemapTop = 1,
    .width = DEBUG_NUMBER_DISPLAY_WIDTH,
    .height = 2 * DEBUG_NUMBER_DISPLAY_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 128,
};

static const struct ListMenuTemplate sDebugMenu_ListTemplate_Main =
{
    .items = sDebugMenuItems_Main,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sDebugMenuItems_Main),
};


static const struct ListMenuTemplate sDebugMenu_ListTemplate_Utility = 
{
    .items = sDebugMenuItems_Utility,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sDebugMenuItems_Utility),
};

void Debug_OpenDebugMenu(void)
{
    Debug_ShowMainMenu(DebugTask_HandleMenuInput_Main, sDebugMenu_ListTemplate_Main);
}

static void Debug_ShowMainMenu(void (*HandleInput)(u8), struct ListMenuTemplate ListMenuTemplate)
{
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugMainMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    menuTemplate = ListMenuTemplate;
    menuTemplate.maxShowed = ARRAY_COUNT(sDebugMenuItems_Main);
    menuTemplate.windowId = windowId;
    menuTemplate.header_X = 0;
    menuTemplate.item_X = 8;
    menuTemplate.cursor_X = 0;
    menuTemplate.upText_Y = 1;
    menuTemplate.cursorPal = 2;
    menuTemplate.fillValue = 1;
    menuTemplate.cursorShadowPal = 3;
    menuTemplate.lettersSpacing = 1;
    menuTemplate.itemVerticalPadding = 1;
    menuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    menuTemplate.fontId = 1;
    menuTemplate.cursorKind = 0;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    CopyWindowToVram(windowId, 3);

    inputTaskId = CreateTask(HandleInput, 3);
    gTasks[inputTaskId].data[0] = menuTaskId;
    gTasks[inputTaskId].data[1] = windowId;
}

static void Debug_ShowUtilitySubMenu(void (*HandleInput)(u8), struct ListMenuTemplate ListMenuTemplate)
{
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugSubMenuUtilityWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    menuTemplate = ListMenuTemplate;
    menuTemplate.maxShowed = ARRAY_COUNT(sDebugMenuItems_Utility);
    menuTemplate.windowId = windowId;
    menuTemplate.header_X = 0;
    menuTemplate.item_X = 8;
    menuTemplate.cursor_X = 0;
    menuTemplate.upText_Y = 1;
    menuTemplate.cursorPal = 2;
    menuTemplate.fillValue = 1;
    menuTemplate.cursorShadowPal = 3;
    menuTemplate.lettersSpacing = 1;
    menuTemplate.itemVerticalPadding = 0;
    menuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    menuTemplate.fontId = 1;
    menuTemplate.cursorKind = 0;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    CopyWindowToVram(windowId, 3);

    inputTaskId = CreateTask(HandleInput, 3);
    gTasks[inputTaskId].data[0] = menuTaskId;
    gTasks[inputTaskId].data[1] = windowId;
}

static void Debug_DestroyMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].data[1], TRUE);
    RemoveWindow(gTasks[taskId].data[1]);
    DestroyTask(taskId);
}

static void DebugAction_DestroyExtraWindow(u8 taskId)
{
    ClearStdWindowAndFrame(gTasks[taskId].data[2], TRUE);
    RemoveWindow(gTasks[taskId].data[2]);

    DestroyTask(taskId);
}

// Input Handlers
static void DebugTask_HandleMenuInput_Main(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if ((func = sDebugMenuActions_Main[input]) != NULL)
            func(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        Debug_DestroyMenu(taskId);
        EnableBothScriptContexts();
    }
}

static void DebugTask_HandleMenuInput_Utility(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if ((func = sDebugMenuActions_Utility[input]) != NULL)
            func(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        Debug_DestroyMenu(taskId);
        Debug_ShowMainMenu(DebugTask_HandleMenuInput_Main, sDebugMenu_ListTemplate_Main);
    }
}

static void DebugTask_HandleMenuInput_Flags(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
    {
        FlagToggle(gTasks[taskId].data[3]);
        if (FlagGet(gTasks[taskId].data[3]) == TRUE)
            PlaySE(SE_PC_LOGIN);
        else
            PlaySE(SE_PC_OFF);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        DebugAction_DestroyExtraWindow(taskId);
        DebugAction_OpenMenu_Utility(taskId);
        return;
    }

    if(gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[3] += sPowersOfTen[gTasks[taskId].data[4]];
        if(gTasks[taskId].data[3] >= FLAGS_COUNT){
            gTasks[taskId].data[3] = FLAGS_COUNT - 1;
        }
    }

    if(gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[3] -= sPowersOfTen[gTasks[taskId].data[4]];
        if(gTasks[taskId].data[3] < 0){
            gTasks[taskId].data[3] = 0;
        }
    }

    if(gMain.newKeys & DPAD_LEFT)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[4] -= 1;
        if(gTasks[taskId].data[4] < 0)
        {
            gTasks[taskId].data[4] = 0;
        }
    }

    if(gMain.newKeys & DPAD_RIGHT)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[4] += 1;
        if(gTasks[taskId].data[4] > DEBUG_NUMBER_DIGITS_FLAGS-1)
        {
            gTasks[taskId].data[4] = DEBUG_NUMBER_DIGITS_FLAGS-1;
        }
    }

    if (gMain.newKeys & DPAD_ANY || gMain.newKeys & A_BUTTON)
    {
        ConvertIntToDecimalStringN(gStringVar1, gTasks[taskId].data[3], STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_FLAGS);
        ConvertIntToHexStringN(gStringVar2, gTasks[taskId].data[3], STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar1, gDebugText_Flag_FlagHex);
        if(FlagGet(gTasks[taskId].data[3]) == TRUE)
            StringCopyPadded(gStringVar2, gDebugText_Flag_FlagSet, CHAR_SPACE, 15);
        else
            StringCopyPadded(gStringVar2, gDebugText_Flag_FlagUnset, CHAR_SPACE, 15);
        StringCopy(gStringVar3, gText_DigitIndicator[gTasks[taskId].data[4]]);
        StringExpandPlaceholders(gStringVar4, gDebugText_Flag_FlagDef);
        AddTextPrinterParameterized(gTasks[taskId].data[2], 1, gStringVar4, 1, 1, 0, NULL);
    }
}

// Open Menus
static void DebugAction_OpenMenu_Utility(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    Debug_ShowUtilitySubMenu(DebugTask_HandleMenuInput_Utility, sDebugMenu_ListTemplate_Utility);
}

static void DebugAction_OpenMenu_Flags(u8 taskId)
{
    u8 windowId;

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugNumberDisplayWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    CopyWindowToVram(windowId, 3);

    //Display initial Flag
    ConvertIntToDecimalStringN(gStringVar1, 0, STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_FLAGS);
    ConvertIntToHexStringN(gStringVar2, 0, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar1, gDebugText_Flag_FlagHex);
    if(FlagGet(0) == TRUE)
        StringCopyPadded(gStringVar2, gDebugText_Flag_FlagSet, CHAR_SPACE, 15);
    else
        StringCopyPadded(gStringVar2, gDebugText_Flag_FlagUnset, CHAR_SPACE, 15);
    StringCopy(gStringVar3, gText_DigitIndicator[0]);
    StringExpandPlaceholders(gStringVar4, gDebugText_Flag_FlagDef);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 1, 1, 0, NULL);

    gTasks[taskId].func = DebugTask_HandleMenuInput_Flags;
    gTasks[taskId].data[2] = windowId;
    gTasks[taskId].data[3] = 0;            //Current Flag
    gTasks[taskId].data[4] = 0;            //Digit Selected
}

static void DebugAction_Cancel(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    EnableBothScriptContexts();
}

// Utility Functions
static void DebugAction_HealParty(u8 taskId)
{
    HealPlayerParty();
    PlaySE(SE_USE_ITEM);
}

static void DebugAction_GiveRareCandy(u8 taskId)
{
    AddBagItem(ITEM_RARE_CANDY, 10);
    PlaySE(SE_USE_ITEM);
}

static void DebugAction_ResetMapFlags(u8 taskId)
{
    ScriptContext2_RunNewScript(EventScript_ResetAllMapFlags);
    PlaySE(SE_USE_ITEM);
}

static void DebugAction_PrepareTrades(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    ScriptContext1_SetupScript(Debug_EventScript_PrepareTrades);
    ScriptGiveMon(SPECIES_KECLEON, 20, ITEM_NONE, 0, 0, 0);
}

#endif