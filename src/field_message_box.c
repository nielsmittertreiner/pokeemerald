#include "global.h"
#include "bg.h"
#include "event_object_movement.h"
#include "graphics.h"
#include "main.h"
#include "menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "match_call.h"
#include "field_message_box.h"
#include "text_window.h"
#include "script.h"
#include "script_menu.h"
#include "script_movement.h"
#include "sound.h"
#include "constants/event_objects.h"
#include "constants/songs.h"

static EWRAM_DATA u8 sFieldMessageBoxMode = 0;

static void ExpandStringAndStartDrawFieldMessage(const u8 *, bool32);
static void StartDrawFieldMessage(void);
static bool32 SignMessage_LoadGfx(u8 taskId);
static bool32 SignMessage_DrawWindow(u8 taskId);
static bool32 SignMessage_SlideWindowIn(u8 taskId);
static bool32 SignMessage_ReadyMessage(u8 taskId);
static bool32 SignMessage_PrintMessage(u8 taskId);
static bool32 SignMessage_SlideWindowOut(u8 taskId);
static bool32 SignMessage_EndMessage(u8 taskId);

void InitFieldMessageBox(void)
{
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
    gTextFlags.canABSpeedUpPrint = FALSE;
    gTextFlags.useAlternateDownArrow = FALSE;
    gTextFlags.autoScroll = FALSE;
    gTextFlags.forceMidTextSpeed = FALSE;
}

#define tState data[0]
#define tWindowId data[1]

static void Task_DrawFieldMessage(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
        case 0:
            LoadMessageBoxAndBorderGfx();
            DrawDialogueFrame(0, TRUE);
            task->tState++;
            break;
        case 1:
            if (RunTextPrintersAndIsPrinter0Active() != TRUE)
            {
                sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
                DestroyTask(taskId);
            }
    }
}

static void Task_DrawMiniFieldMessage(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
        case 0:
            LoadMessageBoxAndBorderGfx();
            DrawMiniDialogueFrame(task->tWindowId, TRUE);
            task->tState++;
            break;
        case 1:
            RunTextPrinters();
            if (!IsTextPrinterActive(task->tWindowId))
                DestroyTask(taskId);            
    }
}

static bool32 (*const sSignMessageTaskFuncs[])(u8) =
{
    SignMessage_LoadGfx,
    SignMessage_DrawWindow,
    SignMessage_SlideWindowIn,
    SignMessage_PrintMessage,
    SignMessage_SlideWindowOut,
    SignMessage_EndMessage,
};

static bool32 SignMessage_LoadGfx(u8 taskId)
{
    LoadMessageBoxAndBorderGfx();
    ChangeBgY(0, Q_8_8(-32), BG_COORD_SET);
    return TRUE;
}

static bool32 SignMessage_DrawWindow(u8 taskId)
{
    DrawDialogueFrame(0, FALSE);
    AddTextPrinterParameterized(0, FONT_NORMAL, gStringVar4, 0, 0, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(0, COPYWIN_FULL);
    return TRUE;
}

static bool32 SignMessage_SlideWindowIn(u8 taskId)
{
    if (ChangeBgY(0, Q_8_8(6), BG_COORD_ADD) >= 0)
    {
        ChangeBgY(0, 0, BG_COORD_SET);
        return TRUE;
    }

    return FALSE;
}

static bool32 SignMessage_PrintMessage(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active() && !IsSEPlaying() && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_BALL_TRAY_ENTER);
        return TRUE;
    }
    return FALSE;
}

static bool32 SignMessage_SlideWindowOut(u8 taskId)
{
    if (ChangeBgY(0, Q_8_8(6), BG_COORD_SUB) <= Q_8_8(-32))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        return TRUE;
    }

    return FALSE;
}

static bool32 SignMessage_EndMessage(u8 taskId)
{
    ChangeBgY(0, 0, BG_COORD_SET);
    return TRUE;
}


void Task_ExecuteSignMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (sSignMessageTaskFuncs[tState](taskId))
    {
        tState++;
        if ((u16)tState > 5)
            DestroyTask(taskId);
    }
}

static void CreateTask_DrawFieldMessage(void)
{
    CreateTask(Task_DrawFieldMessage, 0x50);
}

static void DestroyTask_DrawFieldMessage(void)
{
    u8 taskId = FindTaskIdByFunc(Task_DrawFieldMessage);
    if (taskId != TASK_NONE)
        DestroyTask(taskId);
}

bool8 ShowFieldMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    ExpandStringAndStartDrawFieldMessage(str, TRUE);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

static void Task_HideSignMessageWhenDone(u8 taskId)
{
    if (!FuncIsActiveTask(Task_ExecuteSignMessage))
    {
        sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
        DestroyTask(taskId);
    }
}

bool8 ShowSignFieldMessage(const u8 *str)
{
    u8 taskId;

    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    StringExpandPlaceholders(gStringVar4, str);
    CreateTask(Task_HideSignMessageWhenDone, 0);
    PlaySE(SE_BALL_TRAY_ENTER);
    taskId = CreateTask(Task_ExecuteSignMessage, 1);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

#undef tState
#undef tType

bool8 ShowMiniFieldMessage(const u8 *str, u8 x, u8 y)
{
    u8 taskId;
    u8 width;
    u8 windowId;
    
    StringExpandPlaceholders(gStringVar1, str);
    width = (((GetStringWidth(FONT_SMALL, gStringVar1, -1) + 9) / 8) + 1);
    windowId = AddMiniWindow(x, y, width);
    if (windowId != WINDOW_NONE)
    {
        taskId = CreateTask(Task_DrawMiniFieldMessage, 0x50);
        gTasks[taskId].tWindowId = windowId;
        AddTextPrinterParameterized(windowId, FONT_SMALL, gStringVar1, 8, 4, GetPlayerTextSpeed(), NULL);
    }
    return TRUE;
}

static void DestroyTask_DrawMiniFieldMessage(void)
{
    u8 taskId = FindTaskIdByFunc(Task_DrawMiniFieldMessage);
    if (taskId != TASK_NONE)
        DestroyTask(taskId);
}

static void Task_HidePokenavMessageWhenDone(u8 taskId)
{
    if (!IsMatchCallTaskActive())
    {
        sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
        DestroyTask(taskId);
    }
}

bool8 ShowPokenavFieldMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    StringExpandPlaceholders(gStringVar4, str);
    CreateTask(Task_HidePokenavMessageWhenDone, 0);
    StartMatchCallFromScript(str);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

bool8 ShowFieldAutoScrollMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    ExpandStringAndStartDrawFieldMessage(str, FALSE);
    return TRUE;
}

static bool8 UNUSED ForceShowFieldAutoScrollMessage(const u8 *str)
{
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    ExpandStringAndStartDrawFieldMessage(str, TRUE);
    return TRUE;
}

// Same as ShowFieldMessage, but instead of accepting a
// string arg it just prints whats already in gStringVar4
bool8 ShowFieldMessageFromBuffer(void)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    StartDrawFieldMessage();
    return TRUE;
}

static void ExpandStringAndStartDrawFieldMessage(const u8 *str, bool32 allowSkippingDelayWithButtonPress)
{
    StringExpandPlaceholders(gStringVar4, str);
    AddTextPrinterForMessage(allowSkippingDelayWithButtonPress);
    CreateTask_DrawFieldMessage();
}

static void StartDrawFieldMessage(void)
{
    AddTextPrinterForMessage(TRUE);
    CreateTask_DrawFieldMessage();
}

void HideFieldMessageBox(void)
{
    DestroyTask_DrawFieldMessage();
    ClearDialogWindowAndFrame(0, TRUE);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}

u8 GetFieldMessageBoxMode(void)
{
    return sFieldMessageBoxMode;
}

bool8 IsFieldMessageBoxHidden(void)
{
    if (sFieldMessageBoxMode == FIELD_MESSAGE_BOX_HIDDEN)
        return TRUE;
    return FALSE;
}

static void UNUSED ReplaceFieldMessageWithFrame(void)
{
    DestroyTask_DrawFieldMessage();
    DrawStdWindowFrame(0, TRUE);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}

void StopFieldMessage(void)
{
    DestroyTask_DrawFieldMessage();
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}
