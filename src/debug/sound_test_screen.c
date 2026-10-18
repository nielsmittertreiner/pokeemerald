#if DEBUG
#include "global.h"
#include "debug/debug.h"
#include "debug/sound_test_screen.h"
#include "bg.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "m4a.h"
#include "malloc.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "text.h"
#include "text_window.h"
#include "title_screen.h"
#include "window.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define NUM_BGM (MUS_CEDARRED_NIGHT - MUS_LITTLEROOT_TEST)
#define NUM_SE (SE_SUDOWOODO_SHAKE - MUS_DUMMY)

#define BGM 0
#define SE  1

struct SoundTestStruct
{
    u16 index[2];
    s16 volume;
    u16 trackBits:12;
    u16 fadeSpeed:4;
    u8 window:1;
    u8 alt:1;
};

static void MainCB2_SoundTestScreen(void);
static void VBlankCB_SoundTestScreen(void);
static bool8 CB2_SetupSoundTestScreen(void);
static void CB2_ExitSoundTestScreen(void);
static void InitSoundTestScreenWindows(void);
static void Task_DrawSoundTestScreenWindows(u8 taskId);
static void Task_HandleSoundTestScreenInput(u8 taskId);
static bool8 Task_CheckSoundTestScreenInput(u8 taskId);
static void Task_HandleDrawSoundTestScreenInfo(u8 taskId);
static void HighlightSelectedWindow(u8 selectedWindow);
static bool8 IsBGMWindow(u8 selectedWindow);

static EWRAM_DATA struct SoundTestStruct *sSoundTestStruct = NULL;
static EWRAM_DATA u8 sSoundTestHeaderWindowId = 0;

static const u8 sText_SoundTestScreen[] = _("SOUND TEST SCREEN {EMOJI_NOTE}");
static const u8 sText_DPadSelectWindowAndSong[] = _("{DPAD_UPDOWN} {DPAD_LEFTRIGHT} WINDOW/SONG");
static const u8 sText_ABPlayStop[] = _("{A_BUTTON} {B_BUTTON} PLAY{CLEAR_TO 58}/STOP");
static const u8 sText_LRVolume[] = _("{L_BUTTON} {R_BUTTON} DYN. VOLUME");
static const u8 sText_StartExit[] = _("{START_BUTTON} EXIT");
static const u8 sText_Music[] = _("MUSIC");
static const u8 sText_SoundEffects[] = _("SOUND EFFECTS");

static const struct BgTemplate sSoundTestBgTemplates[2] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    }
};

static const struct WindowTemplate sSoundTestScreenWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 9,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0xB3,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x123,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sSoundTestScreenHeaderWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0B,
};

static const u16 sSoundTestScreenBg_Pal[] = {RGB(5, 10, 14)};
static const u8 *const gBGMNames[];
static const u8 *const gSENames[];

static void MainCB2_SoundTestScreen(void)
{
    RunTasks();
    UpdatePaletteFade();
}

static void VBlankCB_SoundTestScreen(void)
{
    TransferPlttBuffer();
}

void CB2_InitSoundTestScreen(void)
{
    if (CB2_SetupSoundTestScreen())
    {
        CreateTask(Task_DrawSoundTestScreenWindows, 0);
    }
}

static void CB2_ExitSoundTestScreen(void)
{
    if (!UpdatePaletteFade())
    {
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sSoundTestStruct);
        SetMainCallback2(gMain.savedCallback);
    }
}

static bool8 CB2_SetupSoundTestScreen(void)
{
    switch(gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
        DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
        DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
        ResetPaletteFade();
        ResetTasks();
        ResetSpriteData();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSoundTestBgTemplates, ARRAY_COUNT(sSoundTestBgTemplates));
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(3);
        LoadPalette(sSoundTestScreenBg_Pal, 0, sizeof(sSoundTestScreenBg_Pal));

        sSoundTestStruct = AllocZeroed(sizeof(struct SoundTestStruct));
        sSoundTestStruct->volume = 256;

        InitSoundTestScreenWindows();
        BeginNormalPaletteFade(PALETTES_BG, 0, 0x10, 0, RGB_WHITEALPHA);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_SoundTestScreen);
        gMain.state = 1;
        break;
    case 1:
        UpdatePaletteFade();
        if(!gPaletteFade.active)
        {
            SetMainCallback2(MainCB2_SoundTestScreen);
            return TRUE;
        }
    }
    return FALSE;
}

static void InitSoundTestScreenWindows(void)
{
    InitWindows(sSoundTestScreenWindowTemplates);
    sSoundTestHeaderWindowId = AddWindow(&sSoundTestScreenHeaderWindowTemplate);
    DrawStdWindowFrame(sSoundTestHeaderWindowId, FALSE);
    FillWindowPixelBuffer(sSoundTestHeaderWindowId, PIXEL_FILL(1));
    PutWindowTilemap(sSoundTestHeaderWindowId);
    CopyWindowToVram(sSoundTestHeaderWindowId, 3);
    DeactivateAllTextPrinters();
    LoadWindowGfx(0, 0, 2, 224);
    LoadPalette(gStandardMenuPalette, 0xF0, 0x20);
}

static void Task_DrawSoundTestScreenWindows(u8 taskId)
{
    u8 string[16];

    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_OBJ | WININ_WIN1_BG0 | WININ_WIN1_OBJ);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 7);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 240));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 64));
    SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 240));
    SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(64, 112));

    DrawStdFrameWithCustomTileAndPalette(sSoundTestHeaderWindowId, TRUE, 2, 14);
    AddTextPrinterParameterized(sSoundTestHeaderWindowId, FONT_NORMAL, sText_SoundTestScreen, 3, 0, 0, 0);
    AddTextPrinterParameterized(sSoundTestHeaderWindowId, FONT_NORMAL, sText_DPadSelectWindowAndSong, 3, 16, 0, 0);
    AddTextPrinterParameterized(sSoundTestHeaderWindowId, FONT_NORMAL, sText_ABPlayStop, 3, 32, 0, 0);
    AddTextPrinterParameterized(sSoundTestHeaderWindowId, FONT_NORMAL, sText_LRVolume, 120, 16, 0, 0);
    AddTextPrinterParameterized(sSoundTestHeaderWindowId, FONT_NORMAL, sText_StartExit, 170, 32, 0, 0);

    DrawStdFrameWithCustomTileAndPalette(0, TRUE, 2, 14);
    ConvertIntToDecimalStringN(string, 0, STR_CONV_MODE_LEFT_ALIGN, 2);
    AddTextPrinterParameterized(0, FONT_NORMAL, string, 3, 16, 0, 0);
    AddTextPrinterParameterized(0, FONT_NORMAL, sText_Music, 3, 0, 0, 0);
    AddTextPrinterParameterized(0, FONT_NORMAL, gBGMNames[sSoundTestStruct->index[BGM]], 32, 16, 0, 0);
    ConvertUIntToDecimalStringN(string, sSoundTestStruct->volume, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized(0, FONT_SMALL, string, GetStringRightAlignXOffset(FONT_SMALL, string, 224) - 80, 1, 0, 0);
    ConvertUIntToBinaryStringN(string, gDynamicMusicData[sSoundTestStruct->index[BGM] + 350].trackBits, 12);
    AddTextPrinterParameterized(0, FONT_SMALL, string, GetStringRightAlignXOffset(FONT_SMALL, string, 224) - 16, 1, 0, 0);
    ConvertUIntToDecimalStringN(string, gDynamicMusicData[sSoundTestStruct->index[BGM] + 350].fadeSpeed, STR_CONV_MODE_LEFT_ALIGN, 1);
    AddTextPrinterParameterized(0, FONT_SMALL, string, GetStringRightAlignXOffset(FONT_SMALL, string, 224) - 4, 1, 0, 0);

    DrawStdFrameWithCustomTileAndPalette(1, TRUE, 2, 14);
    ConvertIntToDecimalStringN(string, 0, STR_CONV_MODE_LEFT_ALIGN, 2);
    AddTextPrinterParameterized(1, FONT_NORMAL, string, 3, 16, 0, 0);
    AddTextPrinterParameterized(1, FONT_NORMAL, sText_SoundEffects, 3, 0, 0, 0);
    AddTextPrinterParameterized(1, FONT_NORMAL, gSENames[sSoundTestStruct->index[SE]], 32, 16, 0, 0);

    m4aSoundInit();
    gTasks[taskId].func = Task_HandleSoundTestScreenInput;
    sSoundTestStruct->window = 0;
    sSoundTestStruct->index[BGM] = 0;
    sSoundTestStruct->index[SE] = 0;
}

static void Task_HandleSoundTestScreenInput(u8 taskId)
{
    if (Task_CheckSoundTestScreenInput(taskId))
    {
        gTasks[taskId].func = Task_HandleDrawSoundTestScreenInfo;
    }
}

static void Task_HandleDrawSoundTestScreenInfo(u8 taskId)
{
    u8 string[16];

    FillWindowPixelBuffer(sSoundTestStruct->window, PIXEL_FILL(1));

    if (IsBGMWindow(sSoundTestStruct->window))
    {
        ConvertIntToDecimalStringN(string, sSoundTestStruct->index[BGM], STR_CONV_MODE_LEFT_ALIGN, 3);
        AddTextPrinterParameterized(0, FONT_NORMAL, sText_Music, 3, 0, 0, 0);
        AddTextPrinterParameterized(0, FONT_NORMAL, string, 3, 16, 0, 0);
        AddTextPrinterParameterized(0, FONT_NORMAL, gBGMNames[sSoundTestStruct->index[BGM]], 32, 16, 0, 0);
        ConvertUIntToDecimalStringN(string, sSoundTestStruct->volume, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized(0, FONT_SMALL, string, GetStringRightAlignXOffset(FONT_SMALL, string, 224) - 80, 1, 0, 0);
        ConvertUIntToBinaryStringN(string, gDynamicMusicData[sSoundTestStruct->index[BGM] + 350].trackBits, 12);
        AddTextPrinterParameterized(0, FONT_SMALL, string, GetStringRightAlignXOffset(FONT_SMALL, string, 224) - 16, 1, 0, 0);
        ConvertUIntToDecimalStringN(string, gDynamicMusicData[sSoundTestStruct->index[BGM] + 350].fadeSpeed, STR_CONV_MODE_LEFT_ALIGN, 1);
        AddTextPrinterParameterized(0, FONT_SMALL, string, GetStringRightAlignXOffset(FONT_SMALL, string, 224) - 4, 1, 0, 0); 
    }
    else
    {
        ConvertIntToDecimalStringN(string, sSoundTestStruct->index[SE], STR_CONV_MODE_LEFT_ALIGN, 3);
        AddTextPrinterParameterized(1, FONT_NORMAL, sText_SoundEffects, 3, 0, 0, 0);
        AddTextPrinterParameterized(1, FONT_NORMAL, string, 3, 16, 0, 0);
        AddTextPrinterParameterized(1, FONT_NORMAL, gSENames[sSoundTestStruct->index[SE]], 32, 16, 0, 0);
    }

    HighlightSelectedWindow(sSoundTestStruct->window);
    gTasks[taskId].func = Task_HandleSoundTestScreenInput;
}

static bool8 Task_CheckSoundTestScreenInput(u8 taskId)
{
    u8 string[4];

    if (JOY_NEW(A_BUTTON))
    {
        m4aMPlayAllStop();
        if (IsBGMWindow(sSoundTestStruct->window))
        {
            m4aSongNumStart(sSoundTestStruct->index[BGM] + 350);
            sSoundTestStruct->volume = 256;
        }
        else
        {   
            m4aSongNumStart(sSoundTestStruct->index[SE]);
        }
        return TRUE;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        m4aMPlayAllStop();
    }
    else if (JOY_NEW(START_BUTTON))
    {
        m4aMPlayAllStop();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        if (gMain.savedCallback == CB2_DebugMenu)
            PlayNewMapMusic(GetCurrLocationDefaultMusic());

        SetMainCallback2(CB2_ExitSoundTestScreen);
    }
    else if ((JOY_NEW(DPAD_UP)) || (JOY_NEW(DPAD_DOWN)))
    {
        sSoundTestStruct->window ^= 1;
        sSoundTestStruct->volume = 256;
        return TRUE;
    }
    //else if ((JOY_NEW(DPAD_DOWN)))
    //{
    //    sSoundTestStruct->window ^= 1;
    //    sSoundTestStruct->volume = 256;
    //    return TRUE;
    //}
    else if ((JOY_REPEAT(DPAD_LEFT)))
    {
        if (IsBGMWindow(sSoundTestStruct->window))
        {
            if (sSoundTestStruct->index[BGM] == 0)
            {
                sSoundTestStruct->index[BGM] = NUM_BGM;
            }
            else
            {
                sSoundTestStruct->index[BGM]--;
            }
        }
        else
        {
            if (sSoundTestStruct->index[SE] == 0)
            {
                sSoundTestStruct->index[SE] = NUM_SE;
            }
            else
            {
                sSoundTestStruct->index[SE]--;
            }

        }
        return TRUE;
    }
    else if ((JOY_REPEAT(DPAD_RIGHT)))
    {
        if (IsBGMWindow(sSoundTestStruct->window))
        {
            if (sSoundTestStruct->index[BGM] == NUM_BGM)
            {
                sSoundTestStruct->index[BGM] = 0;
            }
            else
            {
                sSoundTestStruct->index[BGM]++;
            }
        }
        else
        {
            if (sSoundTestStruct->index[SE] == NUM_SE)
            {
                sSoundTestStruct->index[SE] = 0;
            }
            else
            {
                sSoundTestStruct->index[SE]++;
            }

        }
        return TRUE;
    }
    else if ((JOY_HELD(L_BUTTON)) && sSoundTestStruct->volume > 0 && gDynamicMusicData[sSoundTestStruct->index[BGM] + 350].trackBits && IsBGMWindow(sSoundTestStruct->window))
    {
        sSoundTestStruct->volume -= gDynamicMusicData[sSoundTestStruct->index[BGM] + 350].fadeSpeed;
        if (sSoundTestStruct->volume <= 0)
            sSoundTestStruct->volume = 0;

        m4aMPlayVolumeControl(&gMPlayInfo_BGM, gDynamicMusicData[sSoundTestStruct->index[BGM] + 350].trackBits, sSoundTestStruct->volume);

        ConvertUIntToDecimalStringN(string, sSoundTestStruct->volume, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized(0, FONT_SMALL, string, GetStringRightAlignXOffset(FONT_SMALL, string, 224) - 80, 1, 0, 0);
    }
    else if ((JOY_HELD(R_BUTTON)) && sSoundTestStruct->volume <= 256 && gDynamicMusicData[sSoundTestStruct->index[BGM] + 350].trackBits && IsBGMWindow(sSoundTestStruct->window))
    {
        sSoundTestStruct->volume +=  gDynamicMusicData[sSoundTestStruct->index[BGM] + 350].fadeSpeed;
        if (sSoundTestStruct->volume >= 256)
            sSoundTestStruct->volume = 256;

        m4aMPlayVolumeControl(&gMPlayInfo_BGM, gDynamicMusicData[sSoundTestStruct->index[BGM] + 350].trackBits, sSoundTestStruct->volume);

        ConvertUIntToDecimalStringN(string, sSoundTestStruct->volume, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized(0, FONT_SMALL, string, GetStringRightAlignXOffset(FONT_SMALL, string, 224) - 80, 1, 0, 0);
    }

    return FALSE;
}

static void HighlightSelectedWindow(u8 selectedWindow)
{
    switch (selectedWindow)
    {
    case 0:
        SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 240));
        SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(64, 112));
        break;
    case 1:
        SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 240));
        SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(112, 160));
        break;
    }
}

static bool8 IsBGMWindow(u8 selectedWindow)
{
    if (selectedWindow == 0)
    {
        return TRUE;
    }
    return FALSE;
}

#define SOUND_LIST_BGM \
    X(MUS_LITTLEROOT_TEST, "MUS-LITTLEROOT-TEST") \
    X(MUS_GSC_ROUTE38, "MUS-GSC-ROUTE38") \
    X(MUS_CAUGHT, "MUS-CAUGHT") \
    X(MUS_VICTORY_WILD, "MUS-VICTORY-WILD") \
    X(MUS_VICTORY_GYM_LEADER, "MUS-VICTORY-GYM-LEADER") \
    X(MUS_VICTORY_LEAGUE, "MUS-VICTORY-LEAGUE") \
    X(MUS_C_COMM_CENTER, "MUS-C-COMM-CENTER") \
    X(MUS_GSC_PEWTER, "MUS-GSC-PEWTER") \
    X(MUS_C_VS_LEGEND_BEAST, "MUS-C-VS-LEGEND-BEAST") \
    X(MUS_ROUTE101, "MUS-ROUTE101") \
    X(MUS_ROUTE110, "MUS-ROUTE110") \
    X(MUS_ROUTE120, "MUS-ROUTE120") \
    X(MUS_PETALBURG, "MUS-PETALBURG") \
    X(MUS_OLDALE, "MUS-OLDALE") \
    X(MUS_GYM, "MUS-GYM") \
    X(MUS_SURF, "MUS-SURF") \
    X(MUS_PETALBURG_WOODS, "MUS-PETALBURG-WOODS") \
    X(MUS_LEVEL_UP, "MUS-LEVEL-UP") \
    X(MUS_HEAL, "MUS-HEAL") \
    X(MUS_OBTAIN_BADGE, "MUS-OBTAIN-BADGE") \
    X(MUS_OBTAIN_ITEM, "MUS-OBTAIN-ITEM") \
    X(MUS_EVOLVED, "MUS-EVOLVED") \
    X(MUS_OBTAIN_TMHM, "MUS-OBTAIN-TMHM") \
    X(MUS_LILYCOVE_MUSEUM, "MUS-LILYCOVE-MUSEUM") \
    X(MUS_ROUTE122, "MUS-ROUTE122") \
    X(MUS_OCEANIC_MUSEUM, "MUS-OCEANIC-MUSEUM") \
    X(MUS_EVOLUTION_INTRO, "MUS-EVOLUTION-INTRO") \
    X(MUS_EVOLUTION, "MUS-EVOLUTION") \
    X(MUS_MOVE_DELETED, "MUS-MOVE-DELETED") \
    X(MUS_ENCOUNTER_GIRL, "MUS-ENCOUNTER-GIRL") \
    X(MUS_ENCOUNTER_MALE, "MUS-ENCOUNTER-MALE") \
    X(MUS_ABANDONED_SHIP, "MUS-ABANDONED-SHIP") \
    X(MUS_FORTREE, "MUS-FORTREE") \
    X(MUS_BIRCH_LAB, "MUS-BIRCH-LAB") \
    X(MUS_B_TOWER_RS, "MUS-B-TOWER-RS") \
    X(MUS_ENCOUNTER_SWIMMER, "MUS-ENCOUNTER-SWIMMER") \
    X(MUS_CAVE_OF_ORIGIN, "MUS-CAVE-OF-ORIGIN") \
    X(MUS_OBTAIN_BERRY, "MUS-OBTAIN-BERRY") \
    X(MUS_AWAKEN_LEGEND, "MUS-AWAKEN-LEGEND") \
    X(MUS_SLOTS_JACKPOT, "MUS-SLOTS-JACKPOT") \
    X(MUS_SLOTS_WIN, "MUS-SLOTS-WIN") \
    X(MUS_TOO_BAD, "MUS-TOO-BAD") \
    X(MUS_ROULETTE, "MUS-ROULETTE") \
    X(MUS_LINK_CONTEST_P1, "MUS-LINK-CONTEST-P1") \
    X(MUS_LINK_CONTEST_P2, "MUS-LINK-CONTEST-P2") \
    X(MUS_LINK_CONTEST_P3, "MUS-LINK-CONTEST-P3") \
    X(MUS_LINK_CONTEST_P4, "MUS-LINK-CONTEST-P4") \
    X(MUS_ENCOUNTER_RICH, "MUS-ENCOUNTER-RICH") \
    X(MUS_VERDANTURF, "MUS-VERDANTURF") \
    X(MUS_RUSTBORO, "MUS-RUSTBORO") \
    X(MUS_POKE_CENTER, "MUS-POKE-CENTER") \
    X(MUS_ROUTE104, "MUS-ROUTE104") \
    X(MUS_ROUTE119, "MUS-ROUTE119") \
    X(MUS_CYCLING, "MUS-CYCLING") \
    X(MUS_POKE_MART, "MUS-POKE-MART") \
    X(MUS_LITTLEROOT, "MUS-LITTLEROOT") \
    X(MUS_MT_CHIMNEY, "MUS-MT-CHIMNEY") \
    X(MUS_ENCOUNTER_FEMALE, "MUS-ENCOUNTER-FEMALE") \
    X(MUS_LILYCOVE, "MUS-LILYCOVE") \
    X(MUS_ROUTE111, "MUS-ROUTE111") \
    X(MUS_HELP, "MUS-HELP") \
    X(MUS_UNDERWATER, "MUS-UNDERWATER") \
    X(MUS_VICTORY_TRAINER, "MUS-VICTORY-TRAINER") \
    X(MUS_TITLE, "MUS-TITLE") \
    X(MUS_INTRO, "MUS-INTRO") \
    X(MUS_ENCOUNTER_MAY, "MUS-ENCOUNTER-MAY") \
    X(MUS_ENCOUNTER_INTENSE, "MUS-ENCOUNTER-INTENSE") \
    X(MUS_ENCOUNTER_COOL, "MUS-ENCOUNTER-COOL") \
    X(MUS_ROUTE113, "MUS-ROUTE113") \
    X(MUS_ENCOUNTER_AQUA, "MUS-ENCOUNTER-AQUA") \
    X(MUS_FOLLOW_ME, "MUS-FOLLOW-ME") \
    X(MUS_ENCOUNTER_BRENDAN, "MUS-ENCOUNTER-BRENDAN") \
    X(MUS_EVER_GRANDE, "MUS-EVER-GRANDE") \
    X(MUS_ENCOUNTER_SUSPICIOUS, "MUS-ENCOUNTER-SUSPICIOUS") \
    X(MUS_VICTORY_AQUA_MAGMA, "MUS-VICTORY-AQUA-MAGMA") \
    X(MUS_CABLE_CAR, "MUS-CABLE-CAR") \
    X(MUS_GAME_CORNER, "MUS-GAME-CORNER") \
    X(MUS_DEWFORD, "MUS-DEWFORD") \
    X(MUS_SAFARI_ZONE, "MUS-SAFARI-ZONE") \
    X(MUS_VICTORY_ROAD, "MUS-VICTORY-ROAD") \
    X(MUS_AQUA_MAGMA_HIDEOUT, "MUS-AQUA-MAGMA-HIDEOUT") \
    X(MUS_SAILING, "MUS-SAILING") \
    X(MUS_MT_PYRE, "MUS-MT-PYRE") \
    X(MUS_SLATEPORT, "MUS-SLATEPORT") \
    X(MUS_MT_PYRE_EXTERIOR, "MUS-MT-PYRE-EXTERIOR") \
    X(MUS_SCHOOL, "MUS-SCHOOL") \
    X(MUS_HALL_OF_FAME, "MUS-HALL-OF-FAME") \
    X(MUS_FALLARBOR, "MUS-FALLARBOR") \
    X(MUS_SEALED_CHAMBER, "MUS-SEALED-CHAMBER") \
    X(MUS_CONTEST_WINNER, "MUS-CONTEST-WINNER") \
    X(MUS_CONTEST, "MUS-CONTEST") \
    X(MUS_ENCOUNTER_MAGMA, "MUS-ENCOUNTER-MAGMA") \
    X(MUS_INTRO_BATTLE, "MUS-INTRO-BATTLE") \
    X(MUS_WEATHER_KYOGRE, "MUS-WEATHER-KYOGRE") \
    X(MUS_WEATHER_GROUDON, "MUS-WEATHER-GROUDON") \
    X(MUS_SOOTOPOLIS, "MUS-SOOTOPOLIS") \
    X(MUS_CONTEST_RESULTS, "MUS-CONTEST-RESULTS") \
    X(MUS_HALL_OF_FAME_ROOM, "MUS-HALL-OF-FAME-ROOM") \
    X(MUS_TRICK_HOUSE, "MUS-TRICK-HOUSE") \
    X(MUS_ENCOUNTER_TWINS, "MUS-ENCOUNTER-TWINS") \
    X(MUS_ENCOUNTER_ELITE_FOUR, "MUS-ENCOUNTER-ELITE-FOUR") \
    X(MUS_ENCOUNTER_HIKER, "MUS-ENCOUNTER-HIKER") \
    X(MUS_CONTEST_LOBBY, "MUS-CONTEST-LOBBY") \
    X(MUS_ENCOUNTER_INTERVIEWER, "MUS-ENCOUNTER-INTERVIEWER") \
    X(MUS_ENCOUNTER_CHAMPION, "MUS-ENCOUNTER-CHAMPION") \
    X(MUS_CREDITS, "MUS-CREDITS") \
    X(MUS_END, "MUS-END") \
    X(MUS_B_FRONTIER, "MUS-B-FRONTIER") \
    X(MUS_B_ARENA, "MUS-B-ARENA") \
    X(MUS_OBTAIN_B_POINTS, "MUS-OBTAIN-B-POINTS") \
    X(MUS_REGISTER_MATCH_CALL, "MUS-REGISTER-MATCH-CALL") \
    X(MUS_B_PYRAMID, "MUS-B-PYRAMID") \
    X(MUS_B_PYRAMID_TOP, "MUS-B-PYRAMID-TOP") \
    X(MUS_B_PALACE, "MUS-B-PALACE") \
    X(MUS_RAYQUAZA_APPEARS, "MUS-RAYQUAZA-APPEARS") \
    X(MUS_B_TOWER, "MUS-B-TOWER") \
    X(MUS_OBTAIN_SYMBOL, "MUS-OBTAIN-SYMBOL") \
    X(MUS_B_DOME, "MUS-B-DOME") \
    X(MUS_B_PIKE, "MUS-B-PIKE") \
    X(MUS_B_FACTORY, "MUS-B-FACTORY") \
    X(MUS_VS_RAYQUAZA, "MUS-VS-RAYQUAZA") \
    X(MUS_VS_FRONTIER_BRAIN, "MUS-VS-FRONTIER-BRAIN") \
    X(MUS_VS_MEW, "MUS-VS-MEW") \
    X(MUS_B_DOME_LOBBY, "MUS-B-DOME-LOBBY") \
    X(MUS_VS_WILD, "MUS-VS-WILD") \
    X(MUS_VS_AQUA_MAGMA, "MUS-VS-AQUA-MAGMA") \
    X(MUS_VS_TRAINER, "MUS-VS-TRAINER") \
    X(MUS_VS_GYM_LEADER, "MUS-VS-GYM-LEADER") \
    X(MUS_VS_CHAMPION, "MUS-VS-CHAMPION") \
    X(MUS_VS_REGI, "MUS-VS-REGI") \
    X(MUS_VS_KYOGRE_GROUDON, "MUS-VS-KYOGRE-GROUDON") \
    X(MUS_VS_RIVAL, "MUS-VS-RIVAL") \
    X(MUS_VS_ELITE_FOUR, "MUS-VS-ELITE-FOUR") \
    X(MUS_VS_AQUA_MAGMA_LEADER, "MUS-VS-AQUA-MAGMA-LEADER") \
    X(MUS_RG_FOLLOW_ME, "MUS-RG-FOLLOW-ME") \
    X(MUS_RG_GAME_CORNER, "MUS-RG-GAME-CORNER") \
    X(MUS_RG_ROCKET_HIDEOUT, "MUS-RG-ROCKET-HIDEOUT") \
    X(MUS_RG_GYM, "MUS-RG-GYM") \
    X(MUS_RG_JIGGLYPUFF, "MUS-RG-JIGGLYPUFF") \
    X(MUS_RG_INTRO_FIGHT, "MUS-RG-INTRO-FIGHT") \
    X(MUS_RG_TITLE, "MUS-RG-TITLE") \
    X(MUS_RG_CINNABAR, "MUS-RG-CINNABAR") \
    X(MUS_RG_LAVENDER, "MUS-RG-LAVENDER") \
    X(MUS_RG_HEAL, "MUS-RG-HEAL") \
    X(MUS_RG_CYCLING, "MUS-RG-CYCLING") \
    X(MUS_RG_ENCOUNTER_ROCKET, "MUS-RG-ENCOUNTER-ROCKET") \
    X(MUS_RG_ENCOUNTER_GIRL, "MUS-RG-ENCOUNTER-GIRL") \
    X(MUS_RG_ENCOUNTER_BOY, "MUS-RG-ENCOUNTER-BOY") \
    X(MUS_RG_HALL_OF_FAME, "MUS-RG-HALL-OF-FAME") \
    X(MUS_RG_VIRIDIAN_FOREST, "MUS-RG-VIRIDIAN-FOREST") \
    X(MUS_RG_MT_MOON, "MUS-RG-MT-MOON") \
    X(MUS_RG_POKE_MANSION, "MUS-RG-POKE-MANSION") \
    X(MUS_RG_CREDITS, "MUS-RG-CREDITS") \
    X(MUS_RG_ROUTE1, "MUS-RG-ROUTE1") \
    X(MUS_RG_ROUTE24, "MUS-RG-ROUTE24") \
    X(MUS_RG_ROUTE3, "MUS-RG-ROUTE3") \
    X(MUS_RG_ROUTE11, "MUS-RG-ROUTE11") \
    X(MUS_RG_VICTORY_ROAD, "MUS-RG-VICTORY-ROAD") \
    X(MUS_RG_VS_GYM_LEADER, "MUS-RG-VS-GYM-LEADER") \
    X(MUS_RG_VS_TRAINER, "MUS-RG-VS-TRAINER") \
    X(MUS_RG_VS_WILD, "MUS-RG-VS-WILD") \
    X(MUS_RG_VS_CHAMPION, "MUS-RG-VS-CHAMPION") \
    X(MUS_RG_PALLET, "MUS-RG-PALLET") \
    X(MUS_RG_OAK_LAB, "MUS-RG-OAK-LAB") \
    X(MUS_RG_OAK, "MUS-RG-OAK") \
    X(MUS_RG_POKE_CENTER, "MUS-RG-POKE-CENTER") \
    X(MUS_RG_SS_ANNE, "MUS-RG-SS-ANNE") \
    X(MUS_RG_SURF, "MUS-RG-SURF") \
    X(MUS_RG_POKE_TOWER, "MUS-RG-POKE-TOWER") \
    X(MUS_RG_SILPH, "MUS-RG-SILPH") \
    X(MUS_RG_FUCHSIA, "MUS-RG-FUCHSIA") \
    X(MUS_RG_CELADON, "MUS-RG-CELADON") \
    X(MUS_RG_VICTORY_TRAINER, "MUS-RG-VICTORY-TRAINER") \
    X(MUS_RG_VICTORY_WILD, "MUS-RG-VICTORY-WILD") \
    X(MUS_RG_VICTORY_GYM_LEADER, "MUS-RG-VICTORY-GYM-LEADER") \
    X(MUS_RG_VERMILLION, "MUS-RG-VERMILLION") \
    X(MUS_RG_PEWTER, "MUS-RG-PEWTER") \
    X(MUS_RG_ENCOUNTER_RIVAL, "MUS-RG-ENCOUNTER-RIVAL") \
    X(MUS_RG_RIVAL_EXIT, "MUS-RG-RIVAL-EXIT") \
    X(MUS_RG_DEX_RATING, "MUS-RG-DEX-RATING") \
    X(MUS_RG_OBTAIN_KEY_ITEM, "MUS-RG-OBTAIN-KEY-ITEM") \
    X(MUS_RG_CAUGHT_INTRO, "MUS-RG-CAUGHT-INTRO") \
    X(MUS_RG_PHOTO, "MUS-RG-PHOTO") \
    X(MUS_RG_GAME_FREAK, "MUS-RG-GAME-FREAK") \
    X(MUS_RG_CAUGHT, "MUS-RG-CAUGHT") \
    X(MUS_RG_NEW_GAME_INSTRUCT, "MUS-RG-NEW-GAME-INSTRUCT") \
    X(MUS_RG_NEW_GAME_INTRO, "MUS-RG-NEW-GAME-INTRO") \
    X(MUS_RG_NEW_GAME_EXIT, "MUS-RG-NEW-GAME-EXIT") \
    X(MUS_RG_POKE_JUMP, "MUS-RG-POKE-JUMP") \
    X(MUS_RG_UNION_ROOM, "MUS-RG-UNION-ROOM") \
    X(MUS_RG_NET_CENTER, "MUS-RG-NET-CENTER") \
    X(MUS_RG_MYSTERY_GIFT, "MUS-RG-MYSTERY-GIFT") \
    X(MUS_RG_BERRY_PICK, "MUS-RG-BERRY-PICK") \
    X(MUS_RG_SEVII_CAVE, "MUS-RG-SEVII-CAVE") \
    X(MUS_RG_TEACHY_TV_SHOW, "MUS-RG-TEACHY-TV-SHOW") \
    X(MUS_RG_SEVII_ROUTE, "MUS-RG-SEVII-ROUTE") \
    X(MUS_RG_SEVII_DUNGEON, "MUS-RG-SEVII-DUNGEON") \
    X(MUS_RG_SEVII_123, "MUS-RG-SEVII-123") \
    X(MUS_RG_SEVII_45, "MUS-RG-SEVII-45") \
    X(MUS_RG_SEVII_67, "MUS-RG-SEVII-67") \
    X(MUS_RG_POKE_FLUTE, "MUS-RG-POKE-FLUTE") \
    X(MUS_RG_VS_DEOXYS, "MUS-RG-VS-DEOXYS") \
    X(MUS_RG_VS_MEWTWO, "MUS-RG-VS-MEWTWO") \
    X(MUS_RG_VS_LEGEND, "MUS-RG-VS-LEGEND") \
    X(MUS_RG_ENCOUNTER_GYM_LEADER, "MUS-RG-ENCOUNTER-GYM-LEADER") \
    X(MUS_RG_ENCOUNTER_DEOXYS, "MUS-RG-ENCOUNTER-DEOXYS") \
    X(MUS_RG_TRAINER_TOWER, "MUS-RG-TRAINER-TOWER") \
    X(MUS_RG_SLOW_PALLET, "MUS-RG-SLOW-PALLET") \
    X(MUS_RG_TEACHY_TV_MENU, "MUS-RG-TEACHY-TV-MENU") \
    X(PH_TRAP_BLEND, "PH-TRAP-BLEND") \
    X(PH_TRAP_HELD, "PH-TRAP-HELD") \
    X(PH_TRAP_SOLO, "PH-TRAP-SOLO") \
    X(PH_FACE_BLEND, "PH-FACE-BLEND") \
    X(PH_FACE_HELD, "PH-FACE-HELD") \
    X(PH_FACE_SOLO, "PH-FACE-SOLO") \
    X(PH_CLOTH_BLEND, "PH-CLOTH-BLEND") \
    X(PH_CLOTH_HELD, "PH-CLOTH-HELD") \
    X(PH_CLOTH_SOLO, "PH-CLOTH-SOLO") \
    X(PH_DRESS_BLEND, "PH-DRESS-BLEND") \
    X(PH_DRESS_HELD, "PH-DRESS-HELD") \
    X(PH_DRESS_SOLO, "PH-DRESS-SOLO") \
    X(PH_FLEECE_BLEND, "PH-FLEECE-BLEND") \
    X(PH_FLEECE_HELD, "PH-FLEECE-HELD") \
    X(PH_FLEECE_SOLO, "PH-FLEECE-SOLO") \
    X(PH_KIT_BLEND, "PH-KIT-BLEND") \
    X(PH_KIT_HELD, "PH-KIT-HELD") \
    X(PH_KIT_SOLO, "PH-KIT-SOLO") \
    X(PH_PRICE_BLEND, "PH-PRICE-BLEND") \
    X(PH_PRICE_HELD, "PH-PRICE-HELD") \
    X(PH_PRICE_SOLO, "PH-PRICE-SOLO") \
    X(PH_LOT_BLEND, "PH-LOT-BLEND") \
    X(PH_LOT_HELD, "PH-LOT-HELD") \
    X(PH_LOT_SOLO, "PH-LOT-SOLO") \
    X(PH_GOAT_BLEND, "PH-GOAT-BLEND") \
    X(PH_GOAT_HELD, "PH-GOAT-HELD") \
    X(PH_GOAT_SOLO, "PH-GOAT-SOLO") \
    X(PH_THOUGHT_BLEND, "PH-THOUGHT-BLEND") \
    X(PH_THOUGHT_HELD, "PH-THOUGHT-HELD") \
    X(PH_THOUGHT_SOLO, "PH-THOUGHT-SOLO") \
    X(PH_CHOICE_BLEND, "PH-CHOICE-BLEND") \
    X(PH_CHOICE_HELD, "PH-CHOICE-HELD") \
    X(PH_CHOICE_SOLO, "PH-CHOICE-SOLO") \
    X(PH_MOUTH_BLEND, "PH-MOUTH-BLEND") \
    X(PH_MOUTH_HELD, "PH-MOUTH-HELD") \
    X(PH_MOUTH_SOLO, "PH-MOUTH-SOLO") \
    X(PH_FOOT_BLEND, "PH-FOOT-BLEND") \
    X(PH_FOOT_HELD, "PH-FOOT-HELD") \
    X(PH_FOOT_SOLO, "PH-FOOT-SOLO") \
    X(PH_GOOSE_BLEND, "PH-GOOSE-BLEND") \
    X(PH_GOOSE_HELD, "PH-GOOSE-HELD") \
    X(PH_GOOSE_SOLO, "PH-GOOSE-SOLO") \
    X(PH_STRUT_BLEND, "PH-STRUT-BLEND") \
    X(PH_STRUT_HELD, "PH-STRUT-HELD") \
    X(PH_STRUT_SOLO, "PH-STRUT-SOLO") \
    X(PH_CURE_BLEND, "PH-CURE-BLEND") \
    X(PH_CURE_HELD, "PH-CURE-HELD") \
    X(PH_CURE_SOLO, "PH-CURE-SOLO") \
    X(PH_NURSE_BLEND, "PH-NURSE-BLEND") \
    X(PH_NURSE_HELD, "PH-NURSE-HELD") \
    X(PH_NURSE_SOLO, "PH-NURSE-SOLO") \
    X(MUS_ROUTE403, "MUS-ROUTE403") \
    X(MUS_SUNSET, "MUS-SUNSET") \
    X(MUS_CELEBI, "MUS-CELEBI") \
    X(MUS_MURENA_DAY, "MUS-MURENA-DAY") \
    X(MUS_CEDARRED_DAY, "MUS-CEDARRED-DAY") \
    X(MUS_FIRWEALD_DAY, "MUS-FIRWEALD-DAY") \
    X(MUS_FIRWEALD_NIGHT, "MUS-FIRWEALD-NIGHT") \
    X(MUS_LITOR_DAY, "MUS-LITOR-DAY") \
    X(MUS_ACREN_FOREST_DAY, "MUS-ACREN-FOREST-DAY") \
    X(MUS_ACREN_FOREST_NIGHT, "MUS-ACREN-FOREST-NIGHT") \
    X(MUS_CEDARRED_NIGHT, "MUS-CEDARRED-NIGHT") \

#define SOUND_LIST_SE \
    X(MUS_DUMMY, "MUS-DUMMY") \
    X(SE_USE_ITEM, "SE-USE-ITEM") \
    X(SE_PC_LOGIN, "SE-PC-LOGIN") \
    X(SE_PC_OFF, "SE-PC-OFF") \
    X(SE_PC_ON, "SE-PC-ON") \
    X(SE_SELECT, "SE-SELECT") \
    X(SE_WIN_OPEN, "SE-WIN-OPEN") \
    X(SE_WALL_HIT, "SE-WALL-HIT") \
    X(SE_DOOR, "SE-DOOR") \
    X(SE_EXIT, "SE-EXIT") \
    X(SE_LEDGE, "SE-LEDGE") \
    X(SE_BIKE_BELL, "SE-BIKE-BELL") \
    X(SE_NOT_EFFECTIVE, "SE-NOT-EFFECTIVE") \
    X(SE_EFFECTIVE, "SE-EFFECTIVE") \
    X(SE_SUPER_EFFECTIVE, "SE-SUPER-EFFECTIVE") \
    X(SE_BALL_OPEN, "SE-BALL-OPEN") \
    X(SE_FAINT, "SE-FAINT") \
    X(SE_FLEE, "SE-FLEE") \
    X(SE_SLIDING_DOOR, "SE-SLIDING-DOOR") \
    X(SE_SHIP, "SE-SHIP") \
    X(SE_BANG, "SE-BANG") \
    X(SE_PIN, "SE-PIN") \
    X(SE_BOO, "SE-BOO") \
    X(SE_BALL, "SE-BALL") \
    X(SE_CONTEST_PLACE, "SE-CONTEST-PLACE") \
    X(SE_A, "SE-A") \
    X(SE_I, "SE-I") \
    X(SE_U, "SE-U") \
    X(SE_E, "SE-E") \
    X(SE_O, "SE-O") \
    X(SE_N, "SE-N") \
    X(SE_SUCCESS, "SE-SUCCESS") \
    X(SE_FAILURE, "SE-FAILURE") \
    X(SE_EXP, "SE-EXP") \
    X(SE_BIKE_HOP, "SE-BIKE-HOP") \
    X(SE_SWITCH, "SE-SWITCH") \
    X(SE_CLICK, "SE-CLICK") \
    X(SE_FU_ZAKU, "SE-FU-ZAKU") \
    X(SE_CONTEST_CONDITION_LOSE, "SE-CONTEST-CONDITION-LOSE") \
    X(SE_LAVARIDGE_FALL_WARP, "SE-LAVARIDGE-FALL-WARP") \
    X(SE_ICE_STAIRS, "SE-ICE-STAIRS") \
    X(SE_ICE_BREAK, "SE-ICE-BREAK") \
    X(SE_ICE_CRACK, "SE-ICE-CRACK") \
    X(SE_FALL, "SE-FALL") \
    X(SE_UNLOCK, "SE-UNLOCK") \
    X(SE_WARP_IN, "SE-WARP-IN") \
    X(SE_WARP_OUT, "SE-WARP-OUT") \
    X(SE_REPEL, "SE-REPEL") \
    X(SE_ROTATING_GATE, "SE-ROTATING-GATE") \
    X(SE_TRUCK_MOVE, "SE-TRUCK-MOVE") \
    X(SE_TRUCK_STOP, "SE-TRUCK-STOP") \
    X(SE_TRUCK_UNLOAD, "SE-TRUCK-UNLOAD") \
    X(SE_TRUCK_DOOR, "SE-TRUCK-DOOR") \
    X(SE_BERRY_BLENDER, "SE-BERRY-BLENDER") \
    X(SE_CARD, "SE-CARD") \
    X(SE_SAVE, "SE-SAVE") \
    X(SE_BALL_BOUNCE_1, "SE-BALL-BOUNCE-1") \
    X(SE_BALL_BOUNCE_2, "SE-BALL-BOUNCE-2") \
    X(SE_BALL_BOUNCE_3, "SE-BALL-BOUNCE-3") \
    X(SE_BALL_BOUNCE_4, "SE-BALL-BOUNCE-4") \
    X(SE_BALL_TRADE, "SE-BALL-TRADE") \
    X(SE_BALL_THROW, "SE-BALL-THROW") \
    X(SE_NOTE_C, "SE-NOTE-C") \
    X(SE_NOTE_D, "SE-NOTE-D") \
    X(SE_NOTE_E, "SE-NOTE-E") \
    X(SE_NOTE_F, "SE-NOTE-F") \
    X(SE_NOTE_G, "SE-NOTE-G") \
    X(SE_NOTE_A, "SE-NOTE-A") \
    X(SE_NOTE_B, "SE-NOTE-B") \
    X(SE_NOTE_C_HIGH, "SE-NOTE-C-HIGH") \
    X(SE_PUDDLE, "SE-PUDDLE") \
    X(SE_BRIDGE_WALK, "SE-BRIDGE-WALK") \
    X(SE_ITEMFINDER, "SE-ITEMFINDER") \
    X(SE_DING_DONG, "SE-DING-DONG") \
    X(SE_BALLOON_RED, "SE-BALLOON-RED") \
    X(SE_BALLOON_BLUE, "SE-BALLOON-BLUE") \
    X(SE_BALLOON_YELLOW, "SE-BALLOON-YELLOW") \
    X(SE_BREAKABLE_DOOR, "SE-BREAKABLE-DOOR") \
    X(SE_MUD_BALL, "SE-MUD-BALL") \
    X(SE_FIELD_POISON, "SE-FIELD-POISON") \
    X(SE_ESCALATOR, "SE-ESCALATOR") \
    X(SE_THUNDERSTORM, "SE-THUNDERSTORM") \
    X(SE_THUNDERSTORM_STOP, "SE-THUNDERSTORM-STOP") \
    X(SE_DOWNPOUR, "SE-DOWNPOUR") \
    X(SE_DOWNPOUR_STOP, "SE-DOWNPOUR-STOP") \
    X(SE_RAIN, "SE-RAIN") \
    X(SE_RAIN_STOP, "SE-RAIN-STOP") \
    X(SE_THUNDER, "SE-THUNDER") \
    X(SE_THUNDER2, "SE-THUNDER2") \
    X(SE_ELEVATOR, "SE-ELEVATOR") \
    X(SE_LOW_HEALTH, "SE-LOW-HEALTH") \
    X(SE_EXP_MAX, "SE-EXP-MAX") \
    X(SE_ROULETTE_BALL, "SE-ROULETTE-BALL") \
    X(SE_ROULETTE_BALL2, "SE-ROULETTE-BALL2") \
    X(SE_TAILLOW_WING_FLAP, "SE-TAILLOW-WING-FLAP") \
    X(SE_SHOP, "SE-SHOP") \
    X(SE_CONTEST_HEART, "SE-CONTEST-HEART") \
    X(SE_CONTEST_CURTAIN_RISE, "SE-CONTEST-CURTAIN-RISE") \
    X(SE_CONTEST_CURTAIN_FALL, "SE-CONTEST-CURTAIN-FALL") \
    X(SE_CONTEST_ICON_CHANGE, "SE-CONTEST-ICON-CHANGE") \
    X(SE_CONTEST_ICON_CLEAR, "SE-CONTEST-ICON-CLEAR") \
    X(SE_CONTEST_MONS_TURN, "SE-CONTEST-MONS-TURN") \
    X(SE_SHINY, "SE-SHINY") \
    X(SE_INTRO_BLAST, "SE-INTRO-BLAST") \
    X(SE_MUGSHOT, "SE-MUGSHOT") \
    X(SE_APPLAUSE, "SE-APPLAUSE") \
    X(SE_VEND, "SE-VEND") \
    X(SE_ORB, "SE-ORB") \
    X(SE_DEX_SCROLL, "SE-DEX-SCROLL") \
    X(SE_DEX_PAGE, "SE-DEX-PAGE") \
    X(SE_POKENAV_ON, "SE-POKENAV-ON") \
    X(SE_POKENAV_OFF, "SE-POKENAV-OFF") \
    X(SE_DEX_SEARCH, "SE-DEX-SEARCH") \
    X(SE_EGG_HATCH, "SE-EGG-HATCH") \
    X(SE_BALL_TRAY_ENTER, "SE-BALL-TRAY-ENTER") \
    X(SE_BALL_TRAY_BALL, "SE-BALL-TRAY-BALL") \
    X(SE_BALL_TRAY_EXIT, "SE-BALL-TRAY-EXIT") \
    X(SE_GLASS_FLUTE, "SE-GLASS-FLUTE") \
    X(SE_M_THUNDERBOLT, "SE-M-THUNDERBOLT") \
    X(SE_M_THUNDERBOLT2, "SE-M-THUNDERBOLT2") \
    X(SE_M_HARDEN, "SE-M-HARDEN") \
    X(SE_M_NIGHTMARE, "SE-M-NIGHTMARE") \
    X(SE_M_VITAL_THROW, "SE-M-VITAL-THROW") \
    X(SE_M_VITAL_THROW2, "SE-M-VITAL-THROW2") \
    X(SE_M_BUBBLE, "SE-M-BUBBLE") \
    X(SE_M_BUBBLE2, "SE-M-BUBBLE2") \
    X(SE_M_BUBBLE3, "SE-M-BUBBLE3") \
    X(SE_M_RAIN_DANCE, "SE-M-RAIN-DANCE") \
    X(SE_M_CUT, "SE-M-CUT") \
    X(SE_M_STRING_SHOT, "SE-M-STRING-SHOT") \
    X(SE_M_STRING_SHOT2, "SE-M-STRING-SHOT2") \
    X(SE_M_ROCK_THROW, "SE-M-ROCK-THROW") \
    X(SE_M_GUST, "SE-M-GUST") \
    X(SE_M_GUST2, "SE-M-GUST2") \
    X(SE_M_DOUBLE_SLAP, "SE-M-DOUBLE-SLAP") \
    X(SE_M_DOUBLE_TEAM, "SE-M-DOUBLE-TEAM") \
    X(SE_M_RAZOR_WIND, "SE-M-RAZOR-WIND") \
    X(SE_M_ICY_WIND, "SE-M-ICY-WIND") \
    X(SE_M_THUNDER_WAVE, "SE-M-THUNDER-WAVE") \
    X(SE_M_COMET_PUNCH, "SE-M-COMET-PUNCH") \
    X(SE_M_MEGA_KICK, "SE-M-MEGA-KICK") \
    X(SE_M_MEGA_KICK2, "SE-M-MEGA-KICK2") \
    X(SE_M_CRABHAMMER, "SE-M-CRABHAMMER") \
    X(SE_M_JUMP_KICK, "SE-M-JUMP-KICK") \
    X(SE_M_FLAME_WHEEL, "SE-M-FLAME-WHEEL") \
    X(SE_M_FLAME_WHEEL2, "SE-M-FLAME-WHEEL2") \
    X(SE_M_FLAMETHROWER, "SE-M-FLAMETHROWER") \
    X(SE_M_FIRE_PUNCH, "SE-M-FIRE-PUNCH") \
    X(SE_M_TOXIC, "SE-M-TOXIC") \
    X(SE_M_SACRED_FIRE, "SE-M-SACRED-FIRE") \
    X(SE_M_SACRED_FIRE2, "SE-M-SACRED-FIRE2") \
    X(SE_M_EMBER, "SE-M-EMBER") \
    X(SE_M_TAKE_DOWN, "SE-M-TAKE-DOWN") \
    X(SE_M_BLIZZARD, "SE-M-BLIZZARD") \
    X(SE_M_BLIZZARD2, "SE-M-BLIZZARD2") \
    X(SE_M_SCRATCH, "SE-M-SCRATCH") \
    X(SE_M_VICEGRIP, "SE-M-VICEGRIP") \
    X(SE_M_WING_ATTACK, "SE-M-WING-ATTACK") \
    X(SE_M_FLY, "SE-M-FLY") \
    X(SE_M_SAND_ATTACK, "SE-M-SAND-ATTACK") \
    X(SE_M_RAZOR_WIND2, "SE-M-RAZOR-WIND2") \
    X(SE_M_BITE, "SE-M-BITE") \
    X(SE_M_HEADBUTT, "SE-M-HEADBUTT") \
    X(SE_M_SURF, "SE-M-SURF") \
    X(SE_M_HYDRO_PUMP, "SE-M-HYDRO-PUMP") \
    X(SE_M_WHIRLPOOL, "SE-M-WHIRLPOOL") \
    X(SE_M_HORN_ATTACK, "SE-M-HORN-ATTACK") \
    X(SE_M_TAIL_WHIP, "SE-M-TAIL-WHIP") \
    X(SE_M_MIST, "SE-M-MIST") \
    X(SE_M_POISON_POWDER, "SE-M-POISON-POWDER") \
    X(SE_M_BIND, "SE-M-BIND") \
    X(SE_M_DRAGON_RAGE, "SE-M-DRAGON-RAGE") \
    X(SE_M_SING, "SE-M-SING") \
    X(SE_M_PERISH_SONG, "SE-M-PERISH-SONG") \
    X(SE_M_PAY_DAY, "SE-M-PAY-DAY") \
    X(SE_M_DIG, "SE-M-DIG") \
    X(SE_M_DIZZY_PUNCH, "SE-M-DIZZY-PUNCH") \
    X(SE_M_SELF_DESTRUCT, "SE-M-SELF-DESTRUCT") \
    X(SE_M_EXPLOSION, "SE-M-EXPLOSION") \
    X(SE_M_ABSORB_2, "SE-M-ABSORB-2") \
    X(SE_M_ABSORB, "SE-M-ABSORB") \
    X(SE_M_SCREECH, "SE-M-SCREECH") \
    X(SE_M_BUBBLE_BEAM, "SE-M-BUBBLE-BEAM") \
    X(SE_M_BUBBLE_BEAM2, "SE-M-BUBBLE-BEAM2") \
    X(SE_M_SUPERSONIC, "SE-M-SUPERSONIC") \
    X(SE_M_BELLY_DRUM, "SE-M-BELLY-DRUM") \
    X(SE_M_METRONOME, "SE-M-METRONOME") \
    X(SE_M_BONEMERANG, "SE-M-BONEMERANG") \
    X(SE_M_LICK, "SE-M-LICK") \
    X(SE_M_PSYBEAM, "SE-M-PSYBEAM") \
    X(SE_M_FAINT_ATTACK, "SE-M-FAINT-ATTACK") \
    X(SE_M_SWORDS_DANCE, "SE-M-SWORDS-DANCE") \
    X(SE_M_LEER, "SE-M-LEER") \
    X(SE_M_SWAGGER, "SE-M-SWAGGER") \
    X(SE_M_SWAGGER2, "SE-M-SWAGGER2") \
    X(SE_M_HEAL_BELL, "SE-M-HEAL-BELL") \
    X(SE_M_CONFUSE_RAY, "SE-M-CONFUSE-RAY") \
    X(SE_M_SNORE, "SE-M-SNORE") \
    X(SE_M_BRICK_BREAK, "SE-M-BRICK-BREAK") \
    X(SE_M_GIGA_DRAIN, "SE-M-GIGA-DRAIN") \
    X(SE_M_PSYBEAM2, "SE-M-PSYBEAM2") \
    X(SE_M_SOLAR_BEAM, "SE-M-SOLAR-BEAM") \
    X(SE_M_PETAL_DANCE, "SE-M-PETAL-DANCE") \
    X(SE_M_TELEPORT, "SE-M-TELEPORT") \
    X(SE_M_MINIMIZE, "SE-M-MINIMIZE") \
    X(SE_M_SKETCH, "SE-M-SKETCH") \
    X(SE_M_SWIFT, "SE-M-SWIFT") \
    X(SE_M_REFLECT, "SE-M-REFLECT") \
    X(SE_M_BARRIER, "SE-M-BARRIER") \
    X(SE_M_DETECT, "SE-M-DETECT") \
    X(SE_M_LOCK_ON, "SE-M-LOCK-ON") \
    X(SE_M_MOONLIGHT, "SE-M-MOONLIGHT") \
    X(SE_M_CHARM, "SE-M-CHARM") \
    X(SE_M_CHARGE, "SE-M-CHARGE") \
    X(SE_M_STRENGTH, "SE-M-STRENGTH") \
    X(SE_M_HYPER_BEAM, "SE-M-HYPER-BEAM") \
    X(SE_M_WATERFALL, "SE-M-WATERFALL") \
    X(SE_M_REVERSAL, "SE-M-REVERSAL") \
    X(SE_M_ACID_ARMOR, "SE-M-ACID-ARMOR") \
    X(SE_M_SANDSTORM, "SE-M-SANDSTORM") \
    X(SE_M_TRI_ATTACK, "SE-M-TRI-ATTACK") \
    X(SE_M_TRI_ATTACK2, "SE-M-TRI-ATTACK2") \
    X(SE_M_ENCORE, "SE-M-ENCORE") \
    X(SE_M_ENCORE2, "SE-M-ENCORE2") \
    X(SE_M_BATON_PASS, "SE-M-BATON-PASS") \
    X(SE_M_MILK_DRINK, "SE-M-MILK-DRINK") \
    X(SE_M_ATTRACT, "SE-M-ATTRACT") \
    X(SE_M_ATTRACT2, "SE-M-ATTRACT2") \
    X(SE_M_MORNING_SUN, "SE-M-MORNING-SUN") \
    X(SE_M_FLATTER, "SE-M-FLATTER") \
    X(SE_M_SAND_TOMB, "SE-M-SAND-TOMB") \
    X(SE_M_GRASSWHISTLE, "SE-M-GRASSWHISTLE") \
    X(SE_M_SPIT_UP, "SE-M-SPIT-UP") \
    X(SE_M_DIVE, "SE-M-DIVE") \
    X(SE_M_EARTHQUAKE, "SE-M-EARTHQUAKE") \
    X(SE_M_TWISTER, "SE-M-TWISTER") \
    X(SE_M_SWEET_SCENT, "SE-M-SWEET-SCENT") \
    X(SE_M_YAWN, "SE-M-YAWN") \
    X(SE_M_SKY_UPPERCUT, "SE-M-SKY-UPPERCUT") \
    X(SE_M_STAT_INCREASE, "SE-M-STAT-INCREASE") \
    X(SE_M_HEAT_WAVE, "SE-M-HEAT-WAVE") \
    X(SE_M_UPROAR, "SE-M-UPROAR") \
    X(SE_M_HAIL, "SE-M-HAIL") \
    X(SE_M_COSMIC_POWER, "SE-M-COSMIC-POWER") \
    X(SE_M_TEETER_DANCE, "SE-M-TEETER-DANCE") \
    X(SE_M_STAT_DECREASE, "SE-M-STAT-DECREASE") \
    X(SE_M_HAZE, "SE-M-HAZE") \
    X(SE_M_HYPER_BEAM2, "SE-M-HYPER-BEAM2") \
    X(SE_RG_DOOR, "SE-RG-DOOR") \
    X(SE_RG_CARD_FLIP, "SE-RG-CARD-FLIP") \
    X(SE_RG_CARD_FLIPPING, "SE-RG-CARD-FLIPPING") \
    X(SE_RG_CARD_OPEN, "SE-RG-CARD-OPEN") \
    X(SE_RG_BAG_CURSOR, "SE-RG-BAG-CURSOR") \
    X(SE_RG_BAG_POCKET, "SE-RG-BAG-POCKET") \
    X(SE_RG_BALL_CLICK, "SE-RG-BALL-CLICK") \
    X(SE_RG_SHOP, "SE-RG-SHOP") \
    X(SE_RG_SS_ANNE_HORN, "SE-RG-SS-ANNE-HORN") \
    X(SE_RG_HELP_OPEN, "SE-RG-HELP-OPEN") \
    X(SE_RG_HELP_CLOSE, "SE-RG-HELP-CLOSE") \
    X(SE_RG_HELP_ERROR, "SE-RG-HELP-ERROR") \
    X(SE_RG_DEOXYS_MOVE, "SE-RG-DEOXYS-MOVE") \
    X(SE_RG_POKE_JUMP_SUCCESS, "SE-RG-POKE-JUMP-SUCCESS") \
    X(SE_RG_POKE_JUMP_FAILURE, "SE-RG-POKE-JUMP-FAILURE") \
    X(SE_PHONE_CALL, "SE-PHONE-CALL") \
    X(SE_PHONE_CLICK, "SE-PHONE-CLICK") \
    X(SE_ARENA_TIMEUP1, "SE-ARENA-TIMEUP1") \
    X(SE_ARENA_TIMEUP2, "SE-ARENA-TIMEUP2") \
    X(SE_PIKE_CURTAIN_CLOSE, "SE-PIKE-CURTAIN-CLOSE") \
    X(SE_PIKE_CURTAIN_OPEN, "SE-PIKE-CURTAIN-OPEN") \
    X(SE_SUDOWOODO_SHAKE, "SE-SUDOWOODO-SHAKE") \

// Create BGM list
#define X(songId, name) static const u8 sBGMName_Emerald_##songId[] = _(name);
SOUND_LIST_BGM
#undef X

#define X(songId, name) sBGMName_Emerald_##songId,
static const u8 *const gBGMNames[] =
{
SOUND_LIST_BGM
};
#undef X

// Create SE list
#define X(songId, name) static const u8 sSEName_##songId[] = _(name);
SOUND_LIST_SE
#undef X

#define X(songId, name) sSEName_##songId,
static const u8 *const gSENames[] =
{
SOUND_LIST_SE
};
#undef X

#endif