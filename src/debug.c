#if DEBUG

#include "global.h"
#include "debug.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
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
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/songs.h"

// Functions
// Window Functions
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
static void DebugTask_HandleMenuInput_Vars(u8);

// Open Menus
static void DebugAction_OpenMenu_Utility(u8);

// Utility Functions
static void DebugAction_ManageFlags(u8);
static void DebugAction_ManageVars(u8);
static void DebugAction_SetVarValue(u8);
static void DebugAction_HealParty(u8);
static void DebugAction_GiveRareCandy(u8);
static void DebugAction_ResetMapFlags(u8);
static void DebugAction_PrepareTrades(u8);

static void DebugAction_Cancel(u8);

#define DEBUG_MAIN_MENU_WIDTH 7
#define DEBUG_UTILITY_MENU_WIDTH 12

#define DEBUG_NUMBER_DISPLAY_WIDTH 14
#define DEBUG_NUMBER_DISPLAY_HEIGHT 3

#define DEBUG_NUMBER_DIGITS_FLAGS 4
#define DEBUG_NUMBER_DIGITS_VARIABLES 5

// Main Menu Strings
static const u8 gDebugText_Utility[] = _("UTILITY");
static const u8 gDebugText_Cancel[] = _("CANCEL");

// Utility Menu Strings
static const u8 gDebugText_Utility_ManageFlag[] = _("MANAGE FLAGS");
static const u8 gDebugText_Utility_ManageVars[] = _("MANAGE VARS");
static const u8 gDebugText_Utility_HealParty[] = _("HEAL PARTY");

// Flags Menu Strings
static const u8 gDebugText_Flag_FlagDef[] =_("FLAG: {STR_VAR_1}\n{STR_VAR_2}\n{STR_VAR_3}");
static const u8 gDebugText_Flag_FlagHex[] = _("{STR_VAR_1}         0x{STR_VAR_2}");
static const u8 gDebugText_Flag_FlagSet[] = _("{COLOR}{06}TRUE{COLOR}{02}");
static const u8 gDebugText_Flag_FlagUnset[] = _("{COLOR}{04}FALSE{COLOR}{02}");

// Var Menu Strings
static const u8 gDebugText_Var_VariableDef[] = _("VAR: {COLOR}{06}{STR_VAR_1}\n{COLOR}{02}VAL: {STR_VAR_3}\n{STR_VAR_2}");
static const u8 gDebugText_Var_VariableHex[] = _("{STR_VAR_1}       0x{STR_VAR_2}");
static const u8 gDebugText_Var_VariableVal[] = _("VAR: {STR_VAR_1}\nVAL: {COLOR}{06}{STR_VAR_3}{COLOR}{02}\n{STR_VAR_2}{A_BUTTON}");

// Digit Indicator Strings
static const u8 digitInidicator_1[]        = _("{LEFT_ARROW}    +1                        {RIGHT_ARROW}");
static const u8 digitInidicator_10[]       = _("{LEFT_ARROW}    +10                      {RIGHT_ARROW}");
static const u8 digitInidicator_100[]      = _("{LEFT_ARROW}    +100                    {RIGHT_ARROW}");
static const u8 digitInidicator_1000[]     = _("{LEFT_ARROW}    +1000                  {RIGHT_ARROW}");
static const u8 digitInidicator_10000[]    = _("{LEFT_ARROW}    +10000                {RIGHT_ARROW}");
static const u8 digitInidicator_100000[]   = _("{LEFT_ARROW}    +100000              {RIGHT_ARROW}");
static const u8 digitInidicator_1000000[]  = _("{LEFT_ARROW}    +1000000            {RIGHT_ARROW}");
static const u8 digitInidicator_10000000[] = _("{LEFT_ARROW}    +10000000          {RIGHT_ARROW}");

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

// Main Menu
enum {
    DEBUG_MENU_ITEM_UTILITY,
    DEBUG_MENU_ITEM_CANCEL,
};

// Utility Menu
enum {
    DEBUG_MENU_ITEM_MANAGE_FLAGS,
    DEBUG_MENU_ITEM_MANAGE_VARS,
    DEBUG_MENU_ITEM_HEAL_PARTY,
};

// List Menu Items
static const struct ListMenuItem sDebugMenuItems_Main[] =
{
    [DEBUG_MENU_ITEM_UTILITY] = {gDebugText_Utility, DEBUG_MENU_ITEM_UTILITY},
    [DEBUG_MENU_ITEM_CANCEL] = {gDebugText_Cancel, DEBUG_MENU_ITEM_CANCEL},
};

static const struct ListMenuItem sDebugMenuItems_Utility[] =
{
    [DEBUG_MENU_ITEM_MANAGE_FLAGS] = {gDebugText_Utility_ManageFlag, DEBUG_MENU_ITEM_MANAGE_FLAGS},
    [DEBUG_MENU_ITEM_MANAGE_VARS] = {gDebugText_Utility_ManageVars, DEBUG_MENU_ITEM_MANAGE_VARS},
    [DEBUG_MENU_ITEM_HEAL_PARTY] = {gDebugText_Utility_HealParty, DEBUG_MENU_ITEM_HEAL_PARTY},
};

// Menu Actions
static void (*const sDebugMenuActions_Main[])(u8) =
{
    [DEBUG_MENU_ITEM_UTILITY] = DebugAction_OpenMenu_Utility,
    [DEBUG_MENU_ITEM_CANCEL] = DebugAction_Cancel,
};

static void (*const sDebugMenuActions_Utility[])(u8) =
{
    [DEBUG_MENU_ITEM_MANAGE_FLAGS] = DebugAction_ManageFlags,
    [DEBUG_MENU_ITEM_MANAGE_VARS] = DebugAction_ManageVars,
    [DEBUG_MENU_ITEM_HEAL_PARTY] = DebugAction_HealParty,
};

// Window Templates
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
    .baseBlock = 256,
};

// List Menu Templates
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

// Window Functions
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
        PlaySE(SE_SELECT);
        DebugAction_DestroyExtraWindow(taskId);
        DebugAction_OpenMenu_Utility(taskId);
        return;
    }

    if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[3] += sPowersOfTen[gTasks[taskId].data[4]];
        if(gTasks[taskId].data[3] >= FLAGS_COUNT){
            gTasks[taskId].data[3] = FLAGS_COUNT - 1;
        }
    }

    if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[3] -= sPowersOfTen[gTasks[taskId].data[4]];
        if(gTasks[taskId].data[3] < 0){
            gTasks[taskId].data[3] = 0;
        }
    }

    if (gMain.newKeys & DPAD_LEFT)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[4] -= 1;
        if(gTasks[taskId].data[4] < 0)
        {
            gTasks[taskId].data[4] = 0;
        }
    }

    if (gMain.newKeys & DPAD_RIGHT)
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

static void DebugTask_HandleMenuInput_Vars(u8 taskId)
{
    if (gMain.newKeys & DPAD_UP)
    {
        gTasks[taskId].data[3] += sPowersOfTen[gTasks[taskId].data[4]];
        if(gTasks[taskId].data[3] > VARS_END){
            gTasks[taskId].data[3] = VARS_END;
        }
    }
    if (gMain.newKeys & DPAD_DOWN)
    {
        gTasks[taskId].data[3] -= sPowersOfTen[gTasks[taskId].data[4]];
        if(gTasks[taskId].data[3] < VARS_START){
            gTasks[taskId].data[3] = VARS_START;
        }
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        gTasks[taskId].data[4] -= 1;
        if(gTasks[taskId].data[4] < 0)
        {
            gTasks[taskId].data[4] = 0;
        }
    }
    if (gMain.newKeys & DPAD_RIGHT)
    {
        gTasks[taskId].data[4] += 1;
        if(gTasks[taskId].data[4] > DEBUG_NUMBER_DIGITS_VARIABLES-1)
        {
            gTasks[taskId].data[4] = DEBUG_NUMBER_DIGITS_VARIABLES-1;
        }
    }

    if (gMain.newKeys & DPAD_ANY)
    {
        PlaySE(SE_SELECT);

        ConvertIntToDecimalStringN(gStringVar1, gTasks[taskId].data[3], STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_VARIABLES);
        ConvertIntToHexStringN(gStringVar2, gTasks[taskId].data[3], STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar1, gDebugText_Var_VariableHex);
        if (VarGetIfExist(gTasks[taskId].data[3]) == 65535) //Current value, if 65535 the value hasnt been set
            gTasks[taskId].data[5] = 0;
        else
            gTasks[taskId].data[5] = VarGet(gTasks[taskId].data[3]);
        ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].data[5], STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_VARIABLES);
        StringCopy(gStringVar2, gText_DigitIndicator[gTasks[taskId].data[4]]); //Current digit

        //Combine str's to full window string
        StringExpandPlaceholders(gStringVar4, gDebugText_Var_VariableDef);
        AddTextPrinterParameterized(gTasks[taskId].data[2], 1, gStringVar4, 1, 1, 0, NULL);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        gTasks[taskId].data[4] = 0;

        PlaySE(SE_SELECT);

        ConvertIntToDecimalStringN(gStringVar1, gTasks[taskId].data[3], STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_VARIABLES);
        ConvertIntToHexStringN(gStringVar2, gTasks[taskId].data[3], STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar1, gDebugText_Var_VariableHex);
        if (VarGetIfExist(gTasks[taskId].data[3]) == 65535) //Current value if 65535 the value hasnt been set
            gTasks[taskId].data[5] = 0;
        else
            gTasks[taskId].data[5] = VarGet(gTasks[taskId].data[3]);
        ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].data[5], STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_VARIABLES);
        StringCopyPadded(gStringVar3, gStringVar3, CHAR_SPACE, 15);
        StringCopy(gStringVar2, gText_DigitIndicator[gTasks[taskId].data[4]]); //Current digit
        StringExpandPlaceholders(gStringVar4, gDebugText_Var_VariableVal);
        AddTextPrinterParameterized(gTasks[taskId].data[2], 1, gStringVar4, 1, 1, 0, NULL);

        gTasks[taskId].data[6] = gTasks[taskId].data[5]; //New value selector
        gTasks[taskId].func = DebugAction_SetVarValue;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        DebugAction_DestroyExtraWindow(taskId);
        DebugAction_OpenMenu_Utility(taskId);
        return;
    }
}

// Open Menus
static void DebugAction_OpenMenu_Utility(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    Debug_ShowUtilitySubMenu(DebugTask_HandleMenuInput_Utility, sDebugMenu_ListTemplate_Utility);
}

// Utility Functions
static void DebugAction_ManageFlags(u8 taskId)
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

static void DebugAction_ManageVars(u8 taskId)
{
    u8 windowId;

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugNumberDisplayWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    CopyWindowToVram(windowId, 3);

    //Display initial Variable
    ConvertIntToDecimalStringN(gStringVar1, VARS_START, STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_VARIABLES);
    ConvertIntToHexStringN(gStringVar2, VARS_START, STR_CONV_MODE_LEFT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar1, gDebugText_Var_VariableHex);
    ConvertIntToDecimalStringN(gStringVar3, 0, STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_VARIABLES);
    StringCopyPadded(gStringVar3, gStringVar3, CHAR_SPACE, 15);
    StringCopy(gStringVar2, gText_DigitIndicator[0]);
    StringExpandPlaceholders(gStringVar4, gDebugText_Var_VariableDef);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 1, 1, 0, NULL);

    gTasks[taskId].func = DebugTask_HandleMenuInput_Vars;
    gTasks[taskId].data[2] = windowId;
    gTasks[taskId].data[3] = VARS_START;   //Current Variable
    gTasks[taskId].data[4] = 0;            //Digit Selected
    gTasks[taskId].data[5] = 0;            //Current Variable VALUE
}

static void DebugAction_SetVarValue(u8 taskId)
{
    if (gMain.newKeys & DPAD_UP)
    {
        if (gTasks[taskId].data[6] + sPowersOfTen[gTasks[taskId].data[4]] <= 32000)
            gTasks[taskId].data[6] += sPowersOfTen[gTasks[taskId].data[4]];
        else
            gTasks[taskId].data[6] = 32000-1;
        if (gTasks[taskId].data[6] >= 32000)
            gTasks[taskId].data[6] = 32000-1;
    }

    if (gMain.newKeys & DPAD_DOWN)
    {
        gTasks[taskId].data[6] -= sPowersOfTen[gTasks[taskId].data[4]];
        if(gTasks[taskId].data[6] < 0){
            gTasks[taskId].data[6] = 0;
        }
    }

    if (gMain.newKeys & DPAD_LEFT)
    {
        gTasks[taskId].data[4] -= 1;
        if(gTasks[taskId].data[4] < 0)
        {
            gTasks[taskId].data[4] = 0;
        }
    }

    if (gMain.newKeys & DPAD_RIGHT)
    {
        gTasks[taskId].data[4] += 1;
        if(gTasks[taskId].data[4] > 4)
        {
            gTasks[taskId].data[4] = 4;
        }
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        VarSet(gTasks[taskId].data[3], gTasks[taskId].data[6]);
        //DebugAction_ManageVars(taskId);
        //DebugTask_HandleMenuInput_Vars(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        DebugAction_ManageVars(taskId);
        //DebugTask_HandleMenuInput_Vars(taskId);
        return;
    }

    if (gMain.newKeys & DPAD_ANY || gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        ConvertIntToDecimalStringN(gStringVar1, gTasks[taskId].data[3], STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_VARIABLES);
        ConvertIntToHexStringN(gStringVar2, gTasks[taskId].data[3], STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar1, gDebugText_Var_VariableHex);
        StringCopyPadded(gStringVar1, gStringVar1, CHAR_SPACE, 15);
        ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].data[6], STR_CONV_MODE_LEADING_ZEROS, DEBUG_NUMBER_DIGITS_VARIABLES);
        StringCopyPadded(gStringVar3, gStringVar3, CHAR_SPACE, 15);
        StringCopy(gStringVar2, gText_DigitIndicator[gTasks[taskId].data[4]]); //Current digit
        StringExpandPlaceholders(gStringVar4, gDebugText_Var_VariableVal);
        AddTextPrinterParameterized(gTasks[taskId].data[2], 1, gStringVar4, 1, 1, 0, NULL);
    }
}

static void DebugAction_HealParty(u8 taskId)
{
    HealPlayerParty();
    PlaySE(SE_USE_ITEM);
}

static void DebugAction_Cancel(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    EnableBothScriptContexts();
}

#endif