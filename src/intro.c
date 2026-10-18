#include "global.h"
#include "main.h"
#include "debug/sound_test_screen.h"
#include "palette.h"
#include "scanline_effect.h"
#include "task.h"
#include "title_screen.h"
#include "libgcnmultiboot.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "link.h"
#include "multiboot_pokemon_colosseum.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "m4a.h"
#include "random.h"
#include "decompress.h"
#include "constants/songs.h"
#include "intro_credits_graphics.h"
#include "trig.h"
#include "intro.h"
#include "graphics.h"
#include "sound.h"
#include "util.h"
#include "title_screen.h"
#include "constants/rgb.h"
#include "constants/battle_anim.h"

/*
    The intro is grouped into the following scenes
    Scene 0. Copyright screen
    Scene 1. Kecleon walks, get's caught and escapes

    After this it progresses to the title screen
*/

static void CB2_GoToSoundTestScreen(void);

// Scene main tasks
static void Task_Scene1_Load(u8);
static void Task_Scene1_FadeIn(u8);
static void Task_Scene1_Kecleon(u8);
static void Task_EndIntroMovie(u8);

// Scene supplemental functions
static void IntroResetGpuRegs(void);
static void SpriteCB_Kecleon(struct Sprite *sprite);
static void SpriteCB_ExclamationMark(struct Sprite *sprite);
static void SpriteCB_Sand(struct Sprite *sprite);
static void SpriteCB_PokeBall(struct Sprite *sprite);
static void SpriteCB_Flash(struct Sprite *sprite);

static void MainCB2_EndIntro(void);

#define TAG_KECLEON          3000
#define TAG_EXCLAMATION_MARK 3001
#define TAG_SAND             3002
#define TAG_POKE_BALL        3003
#define TAG_FLASH            3004

enum {
    COPYRIGHT_INITIALIZE,
    COPYRIGHT_START_FADE = 140,
    COPYRIGHT_START_INTRO,
};

#define MATRIX_POKE_BALL 0
#define MATRIX_KECLEON   1
#define MATRIX_FLASH     2

#define COLOSSEUM_GAME_CODE 0x65366347 // "Gc6e" in ASCII

// Used by various tasks and sprites
#define tState data[0]
#define sState data[0]

/*
    gIntroFrameCounter is used as a persistent timer throughout the
    intro cinematic. At various points it's used to determine when
    to trigger actions or progress through the cutscene.
    The values for these are defined contiguously below.
*/
#define TIMER_KECLEON_LOOK_AROUND        52
#define TIMER_KECLEON_SCARE             212
#define TIMER_KECLEON_RUN               228
#define TIMER_KECLEON_TRIP              252
#define TIMER_KECLEON_FALL              271
#define TIMER_POKE_BALL_THROW           285
#define TIMER_POKE_BALL_HIT             317
#define TIMER_POKE_BALL_OPEN            329
#define TIMER_KECLEON_TURN_RED          341
#define TIMER_KECLEON_CATCH             355
#define TIMER_POKE_BALL_CLOSE           399
#define TIMER_POKE_BALL_FALL            419
#define TIMER_POKE_BALL_FALL_2          450
#define TIMER_POKE_BALL_BOUNCE_1        464
#define TIMER_POKE_BALL_BOUNCE_2        497
#define TIMER_POKE_BALL_BOUNCE_3        531
#define TIMER_POKE_BALL_WIGGLE_1_START  591
#define TIMER_POKE_BALL_WIGGLE_1_STOP   TIMER_POKE_BALL_WIGGLE_1_START + 18
#define TIMER_POKE_BALL_WIGGLE_2_START  638
#define TIMER_POKE_BALL_WIGGLE_2_STOP   TIMER_POKE_BALL_WIGGLE_2_START + 18
#define TIMER_POKE_BALL_WIGGLE_3_START  685
#define TIMER_POKE_BALL_WIGGLE_3_STOP   TIMER_POKE_BALL_WIGGLE_3_START + 18
#define TIMER_POKE_BALL_JUMP_UP         730
#define TIMER_POKE_BALL_ESCAPE_OPEN     746
#define TIMER_KECLEON_ESCAPE            758
#define TIMER_KECLEON_ESCAPE_FINISH     791
#define TIMER_END                       800

COMMON_DATA u32 gIntroFrameCounter = 0;
COMMON_DATA struct GcmbStruct gMultibootProgramStruct = {0};

static const u32 sIntroKecleon_Gfx[]          = INCGFX_U32("graphics/intro/scene_kecleon/kecleon.png", ".4bpp.lz");
static const u16 sIntroKecleon_Pal[]          = INCGFX_U16("graphics/intro/scene_kecleon/kecleon.png", ".gbapal");
static const u32 sIntroExclamationMark_Gfx[]  = INCGFX_U32("graphics/intro/scene_kecleon/exclamation_mark.png", ".4bpp.lz");
static const u16 sIntroExclamationMark_Pal[]  = INCGFX_U16("graphics/intro/scene_kecleon/exclamation_mark.png", ".gbapal");
static const u32 sIntroSand_Gfx[]             = INCGFX_U32("graphics/intro/scene_kecleon/sand.png", ".4bpp.lz");
static const u16 sIntroSand_Pal[]             = INCGFX_U16("graphics/intro/scene_kecleon/sand.png", ".gbapal");
static const u32 sIntroPokeBall_Gfx[]         = INCGFX_U32("graphics/intro/scene_kecleon/poke_ball.png", ".4bpp.lz");
static const u16 sIntroPokeBall_Pal[]         = INCGFX_U16("graphics/intro/scene_kecleon/poke_ball.png", ".gbapal");
static const u32 sIntroFlash_Gfx[]            = INCGFX_U32("graphics/intro/scene_kecleon/flash.png", ".4bpp.lz");
static const u16 sIntroFlash_Pal[]            = INCGFX_U16("graphics/intro/scene_kecleon/flash.png", ".gbapal");

static const struct OamData sOamData_Kecleon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = MATRIX_KECLEON,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_KecleonWalk[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(48, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_KecleonLookAround[] =
{
    ANIMCMD_FRAME(64, 48),
    ANIMCMD_FRAME(64, 24, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 24),
    ANIMCMD_FRAME(64, 24, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 32),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KecleonScare[] =
{
    ANIMCMD_FRAME(80, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KecleonRun[] =
{
    ANIMCMD_FRAME(96, 4),
    ANIMCMD_FRAME(112, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(144, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_KecleonTrip[] =
{
    ANIMCMD_FRAME(160, 8),
    ANIMCMD_FRAME(176, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_KecleonHit[] =
{
    ANIMCMD_FRAME(192, 1),
    ANIMCMD_END,
};

enum
{
    KECLEON_ANIM_WALK,
    KECLEON_ANIM_LOOK_AROUND,
    KECLEON_ANIM_SCARE,
    KECLEON_ANIM_RUN,
    KECLEON_ANIM_TRIP,
    KECLEON_ANIM_HIT,
};

static const union AnimCmd *const sAnims_Kecleon[] =
{
    [KECLEON_ANIM_WALK]        = sAnim_KecleonWalk,
    [KECLEON_ANIM_LOOK_AROUND] = sAnim_KecleonLookAround,
    [KECLEON_ANIM_SCARE]       = sAnim_KecleonScare,
    [KECLEON_ANIM_RUN]         = sAnim_KecleonRun,
    [KECLEON_ANIM_TRIP]        = sAnim_KecleonTrip,
    [KECLEON_ANIM_HIT]         = sAnim_KecleonHit,
};

static const struct SpriteTemplate sSpriteTemplate_Kecleon =
{
    .tileTag = TAG_KECLEON,
    .paletteTag = TAG_KECLEON,
    .oam = &sOamData_Kecleon,
    .anims = sAnims_Kecleon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Kecleon,
};

static const struct SpritePalette sSpritePalette_Kecleon =
{
    sIntroKecleon_Pal, TAG_KECLEON
};

static const struct CompressedSpriteSheet sSpriteSheet_Kecleon =
{
    sIntroKecleon_Gfx, 0x1A00, TAG_KECLEON
};

static const struct OamData sOamData_ExclamationMark =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_ExclamationMark =
{
    .tileTag = TAG_EXCLAMATION_MARK,
    .paletteTag = TAG_EXCLAMATION_MARK,
    .oam = &sOamData_ExclamationMark,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ExclamationMark,
};

static const struct SpritePalette sSpritePalette_ExclamationMark =
{
    sIntroExclamationMark_Pal, TAG_EXCLAMATION_MARK
};

static const struct CompressedSpriteSheet sSpriteSheet_ExclamationMark =
{
    sIntroExclamationMark_Gfx, 0x80, TAG_EXCLAMATION_MARK
};

static const struct OamData sOamData_Sand =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_Sand[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Sand[] =
{
    sAnim_Sand,
};

static const struct SpriteTemplate sSpriteTemplate_Sand =
{
    .tileTag = TAG_SAND,
    .paletteTag = TAG_SAND,
    .oam = &sOamData_Sand,
    .anims = sAnims_Sand,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Sand,
};

static const struct SpritePalette sSpritePalette_Sand =
{
    sIntroSand_Pal, TAG_SAND
};

static const struct CompressedSpriteSheet sSpriteSheet_Sand =
{
    sIntroSand_Gfx, 0x600, TAG_SAND
};

static const struct OamData sOamData_PokeBall =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = MATRIX_POKE_BALL,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_PokeBall_Stationary[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PokeBall_Spin[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_FRAME(80, 1),
    ANIMCMD_FRAME(96, 1),
    ANIMCMD_FRAME(112, 1),
    ANIMCMD_FRAME(128, 1),
    ANIMCMD_FRAME(144, 1),
    ANIMCMD_FRAME(160, 1),
    ANIMCMD_FRAME(176, 1),
    ANIMCMD_FRAME(192, 1),
    ANIMCMD_FRAME(208, 1),
    ANIMCMD_FRAME(224, 1),
    ANIMCMD_FRAME(240, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_PokeBall_SpinSlow[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_FRAME(64, 2),
    ANIMCMD_FRAME(80, 2),
    ANIMCMD_FRAME(96, 2),
    ANIMCMD_FRAME(112, 2),
    ANIMCMD_FRAME(128, 2),
    ANIMCMD_FRAME(144, 2),
    ANIMCMD_FRAME(160, 2),
    ANIMCMD_FRAME(176, 2),
    ANIMCMD_FRAME(192, 2),
    ANIMCMD_FRAME(208, 2),
    ANIMCMD_FRAME(224, 2),
    ANIMCMD_FRAME(240, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_PokeBall_SpinSlowAlt[] =
{
    ANIMCMD_FRAME(240, 2),
    ANIMCMD_FRAME(224, 2),
    ANIMCMD_FRAME(208, 2),
    ANIMCMD_FRAME(192, 2),
    ANIMCMD_FRAME(176, 2),
    ANIMCMD_FRAME(160, 2),
    ANIMCMD_FRAME(144, 2),
    ANIMCMD_FRAME(128, 2),
    ANIMCMD_FRAME(112, 2),
    ANIMCMD_FRAME(96, 2),
    ANIMCMD_FRAME(80, 2),
    ANIMCMD_FRAME(64, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_PokeBall_Open[] =
{
    ANIMCMD_FRAME(240, 4),
    ANIMCMD_FRAME(256, 4),
    ANIMCMD_FRAME(272, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PokeBall_Close[] =
{
    ANIMCMD_FRAME(272, 4),
    ANIMCMD_FRAME(256, 4),
    ANIMCMD_FRAME(240, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PokeBall_WiggleLeft[] = 
{
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 8),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PokeBall_WiggleRight[] = 
{
    ANIMCMD_FRAME(240, 3),
    ANIMCMD_FRAME(224, 3),
    ANIMCMD_FRAME(208, 8),
    ANIMCMD_FRAME(224, 3),
    ANIMCMD_FRAME(240, 3),
    ANIMCMD_END,
};

enum
{
    POKE_BALL_ANIM_STATIONARY,
    POKE_BALL_ANIM_SPIN,
    POKE_BALL_ANIM_SPIN_SLOW,
    POKE_BALL_ANIM_SPIN_SLOW_ALT,
    POKE_BALL_ANIM_OPEN,
    POKE_BALL_ANIM_CLOSE,
    POKE_BALL_ANIM_WIGGLE_LEFT,
    POKE_BALL_ANIM_WIGGLE_RIGHT,
};

static const union AnimCmd *const sAnims_PokeBall[] =
{
    [POKE_BALL_ANIM_STATIONARY]    = sAnim_PokeBall_Stationary,
    [POKE_BALL_ANIM_SPIN]          = sAnim_PokeBall_Spin,
    [POKE_BALL_ANIM_SPIN_SLOW]     = sAnim_PokeBall_SpinSlow,
    [POKE_BALL_ANIM_SPIN_SLOW_ALT] = sAnim_PokeBall_SpinSlowAlt,
    [POKE_BALL_ANIM_OPEN]          = sAnim_PokeBall_Open,
    [POKE_BALL_ANIM_CLOSE]         = sAnim_PokeBall_Close,
    [POKE_BALL_ANIM_WIGGLE_LEFT]   = sAnim_PokeBall_WiggleLeft,
    [POKE_BALL_ANIM_WIGGLE_RIGHT]  = sAnim_PokeBall_WiggleRight,
};

static const struct SpriteTemplate sSpriteTemplate_PokeBall =
{
    .tileTag = TAG_POKE_BALL,
    .paletteTag = TAG_POKE_BALL,
    .oam = &sOamData_PokeBall,
    .anims = sAnims_PokeBall,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PokeBall,
};

static const struct SpritePalette sSpritePalette_PokeBall =
{
    sIntroPokeBall_Pal, TAG_POKE_BALL
};

static const struct CompressedSpriteSheet sSpriteSheet_PokeBall =
{
    sIntroPokeBall_Gfx, 0x2400, TAG_POKE_BALL
};

static const struct OamData sOamData_Flash =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = MATRIX_FLASH,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_Flash =
{
    .tileTag = TAG_FLASH,
    .paletteTag = TAG_FLASH,
    .oam = &sOamData_Flash,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Flash,
};

static const struct SpritePalette sSpritePalette_Flash =
{
    sIntroFlash_Pal, TAG_FLASH
};

static const struct CompressedSpriteSheet sSpriteSheet_Flash =
{
    sIntroFlash_Gfx, 0x800, TAG_FLASH
};

static void VBlankCB_Intro(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void MainCB2_Intro(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    if (gMain.newKeys != 0 && !gPaletteFade.active)
        SetMainCallback2(MainCB2_EndIntro);
    else if (gIntroFrameCounter != -1)
        gIntroFrameCounter++;
}

static void MainCB2_EndIntro(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitTitleScreen);
}

static void LoadCopyrightGraphics(u16 tilesetAddress, u16 tilemapAddress, u16 paletteOffset)
{
    LZ77UnCompVram(gIntroCopyright_Gfx, (void *)(VRAM + tilesetAddress));
    LZ77UnCompVram(gIntroCopyright_Tilemap, (void *)(VRAM + tilemapAddress));
    LoadPalette(gIntroCopyright_Pal, paletteOffset, PLTT_SIZE_4BPP);
}

static void SerialCB_CopyrightScreen(void)
{
    GameCubeMultiBoot_HandleSerialInterrupt(&gMultibootProgramStruct);
}

static u8 SetUpCopyrightScreen(void)
{
    switch (gMain.state)
    {
    case COPYRIGHT_INITIALIZE:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        *(u16 *)PLTT = RGB_WHITE;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        CpuFill32(0, (void *)OAM, OAM_SIZE);
        CpuFill16(0, (void *)(PLTT + 2), PLTT_SIZE - 2);
        ResetPaletteFade();
        LoadCopyrightGraphics(0, 0x3800, BG_PLTT_ID(0));
        ScanlineEffect_Clear();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITEALPHA);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Intro);
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON;
        SetSerialCallback(SerialCB_CopyrightScreen);
        GameCubeMultiBoot_Init(&gMultibootProgramStruct);
    default:
        #ifdef DEBUG
        if (JOY_NEW(START_BUTTON))
        {
            gMain.savedCallback = CB2_InitCopyrightScreenAfterBootup;
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            SetMainCallback2(CB2_GoToSoundTestScreen);
        }
        #endif
        UpdatePaletteFade();
        gMain.state++;
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        break;
    case COPYRIGHT_START_FADE:
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        if (gMultibootProgramStruct.gcmb_field_2 != 1)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gMain.state++;
        }
        break;
    case COPYRIGHT_START_INTRO:
        if (UpdatePaletteFade())
            break;
        CreateTask(Task_Scene1_Load, 0);
        SetMainCallback2(MainCB2_Intro);
        if (gMultibootProgramStruct.gcmb_field_2 != 0)
        {
            if (gMultibootProgramStruct.gcmb_field_2 == 2)
            {
                // check the multiboot ROM header game code to see if we already did this
                if (*(u32 *)(EWRAM_START + 0xAC) == COLOSSEUM_GAME_CODE)
                {
                    CpuCopy16(&gMultiBootProgram_PokemonColosseum_Start, (void *)EWRAM_START, sizeof(gMultiBootProgram_PokemonColosseum_Start));
                    *(u32 *)(EWRAM_START + 0xAC) = COLOSSEUM_GAME_CODE;
                }
                GameCubeMultiBoot_ExecuteProgram(&gMultibootProgramStruct);
            }
        }
        else
        {
            GameCubeMultiBoot_Quit();
            SetSerialCallback(SerialCB);
        }
        return 0;
    }

    return 1;
}

void CB2_InitCopyrightScreenAfterBootup(void)
{
    if (!SetUpCopyrightScreen())
    {
        SetSaveBlocksPointers(GetSaveBlocksPointersBaseOffset());
        ResetMenuAndMonGlobals();
        Save_ResetSaveCounters();
        LoadGameSave(SAVE_NORMAL);
        if (gSaveFileStatus == SAVE_STATUS_OUTDATED)
        {
            if (TryUpdatingSaveData())
                gSaveFileStatus = SAVE_STATUS_UPDATED;
        }
        if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
            Sav2_ClearSetDefault();
        SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
        InitHeap(gHeap, HEAP_SIZE);
    }
}

void CB2_InitCopyrightScreenAfterTitleScreen(void)
{
    SetUpCopyrightScreen();
}

#ifdef DEBUG
static void CB2_GoToSoundTestScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitSoundTestScreen);
}
#endif

#define sKecleonSpriteId data[0]

static void Task_Scene1_Load(u8 taskId)
{
    u8 spriteId;

    SetVBlankCallback(NULL);
    IntroResetGpuRegs();
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(22) | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(20) | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(18) | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(16) | BGCNT_16COLOR | BGCNT_TXT256x256);
    LoadCompressedSpriteSheet(&sSpriteSheet_Kecleon);
    LoadCompressedSpriteSheet(&sSpriteSheet_ExclamationMark);
    LoadCompressedSpriteSheet(&sSpriteSheet_Sand);
    LoadCompressedSpriteSheet(&sSpriteSheet_PokeBall);
    LoadCompressedSpriteSheet(&sSpriteSheet_Flash);
    LoadSpritePalette(&sSpritePalette_Kecleon);
    LoadSpritePalette(&sSpritePalette_ExclamationMark);
    LoadSpritePalette(&sSpritePalette_Sand);
    LoadSpritePalette(&sSpritePalette_PokeBall);
    LoadSpritePalette(&sSpritePalette_Flash);

    gTasks[taskId].sKecleonSpriteId = CreateSprite(&sSpriteTemplate_Kecleon, -16, 80, 1);
    gTasks[taskId].func = Task_Scene1_FadeIn;
}

static void IntroResetGpuRegs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void Task_Scene1_FadeIn(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetVBlankCallback(VBlankCB_Intro);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON);
    gIntroFrameCounter = 0;
    gTasks[taskId].func = Task_Scene1_Kecleon;
}

static void Task_Scene1_Kecleon(u8 taskId)
{
    u8 spriteId;

    if (gIntroFrameCounter == TIMER_KECLEON_SCARE)
        spriteId = CreateSprite(&sSpriteTemplate_ExclamationMark, gSprites[gTasks[taskId].sKecleonSpriteId].x + 8, gSprites[gTasks[taskId].sKecleonSpriteId].y - 12, 0);

    if (gIntroFrameCounter == TIMER_KECLEON_TRIP)
        spriteId = CreateSprite(&sSpriteTemplate_Sand, gSprites[gTasks[taskId].sKecleonSpriteId].x - 8, gSprites[gTasks[taskId].sKecleonSpriteId].y + 8, 2);

    if (gIntroFrameCounter == TIMER_POKE_BALL_THROW)
        spriteId = CreateSprite(&sSpriteTemplate_PokeBall, DISPLAY_WIDTH - 48, 80, 0);

    if (gIntroFrameCounter == TIMER_KECLEON_TURN_RED)
        BlendPalettesGradually(0x00010000, 0, 0, 8, RGB_RED, 3, 0);

    if (gIntroFrameCounter == TIMER_KECLEON_ESCAPE)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Flash, gSprites[gTasks[taskId].sKecleonSpriteId].x, gSprites[gTasks[taskId].sKecleonSpriteId].y - 20, 0);
        BlendPalettesGradually(PALETTES_ALL, 0, 0, 16, RGB_WHITEALPHA, 3, 0);
    }

    if (gIntroFrameCounter == TIMER_END)
        gTasks[taskId].func = Task_EndIntroMovie;
}

#undef sKecleonSpriteId

static void Task_EndIntroMovie(u8 taskId)
{
    DestroyTask(taskId);
    SetMainCallback2(MainCB2_EndIntro);
}

#define sSwooshState data[1]
#define sSinIndex data[2]
#define sRadius data[3]
#define sMatrix data[4]

static void SpriteCB_Kecleon(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        StartSpriteAnim(sprite, KECLEON_ANIM_WALK);
        sprite->sState++;
        break;
    case 1:
        sprite->x++;
        if (gIntroFrameCounter == TIMER_KECLEON_LOOK_AROUND)
            sprite->sState++;
        break;
    case 2:
        StartSpriteAnim(sprite, KECLEON_ANIM_LOOK_AROUND);
        sprite->sState++;
        break;
    case 3:
        if (gIntroFrameCounter == TIMER_KECLEON_SCARE)
            sprite->sState++;
        break;
    case 4:
        StartSpriteAnim(sprite, KECLEON_ANIM_SCARE);
        sprite->sState++;
        break;
    case 5:
        if (gIntroFrameCounter == TIMER_KECLEON_RUN)
            sprite->sState++;
        break;
    case 6:
        StartSpriteAnim(sprite, KECLEON_ANIM_RUN);
        sprite->sState++;
        break;
    case 7:
        sprite->x += 2;
        if (gIntroFrameCounter == TIMER_KECLEON_TRIP)
            sprite->sState++;
        break;
    case 8:
        StartSpriteAnim(sprite, KECLEON_ANIM_TRIP);
        sprite->sState++;
        break;
    case 9:
        if (gIntroFrameCounter < TIMER_KECLEON_FALL)
        {
            sprite->x += Sin(sprite->sSinIndex, 4);
            sprite->y2 = -Sin(sprite->sSinIndex, 4);
            sprite->sSinIndex += 8;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_HIT)
        {
            StartSpriteAnim(sprite, KECLEON_ANIM_HIT);
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sState++;
        }
        break;
    case 10:
        if (gIntroFrameCounter == TIMER_KECLEON_CATCH)
        {
            sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
            sprite->oam.priority = 0;
            sprite->sSinIndex = 0;
            sprite->sState++;
        }
        break;
    case 11:
        sprite->oam.matrixNum = MATRIX_KECLEON;

        if (gIntroFrameCounter < TIMER_POKE_BALL_CLOSE)
        {
            switch (sprite->sSwooshState)
            {
            case 0: // going into orbit
                sprite->sMatrix += 0x05;
                sprite->x2 = -Sin(sprite->sSinIndex, sprite->sRadius);
                sprite->y2 = -Cos(sprite->sSinIndex, sprite->sRadius);
                sprite->sSinIndex += 4;
                sprite->sRadius += 2;
                if (sprite->sRadius == 32)
                    sprite->sSwooshState++;

                break;
            case 1: // following constant radius
                sprite->sMatrix += 0x10;
                sprite->x2 = -Sin(sprite->sSinIndex, sprite->sRadius);
                sprite->y2 = -Cos(sprite->sSinIndex, sprite->sRadius);
                sprite->sSinIndex += 6;

                if (sprite->sSinIndex > 199)
                    sprite->sSwooshState++;
                break;
            case 2: // going straight into pokeball
                sprite->sMatrix += 0x80;
                sprite->y2 -= 8;
                break;
            }

            SetOamMatrix(sprite->oam.matrixNum, 0x100 + (sprite->sMatrix), 0, 0, 0x100 + (sprite->sMatrix));
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_CLOSE)
            SetOamMatrix(sprite->oam.matrixNum, 0x1000, 0, 0, 0x1000);

        if (gIntroFrameCounter == TIMER_POKE_BALL_FALL)
        {
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->oam.priority = 1;
            sprite->sSinIndex = 0;
            sprite->sMatrix = 0;
            sprite->sState++;
        }
        break;
    case 12:
        if (gIntroFrameCounter < TIMER_POKE_BALL_FALL_2)
        {
            sprite->x2--;
            sprite->y2 = -Sin(sprite->sSinIndex, 40);
            sprite->sSinIndex += 4;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_FALL_2)
        {
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sSinIndex = 0;
            sprite->sState++;
        }
        break;
    case 13:
        if (gIntroFrameCounter < TIMER_POKE_BALL_BOUNCE_1)
        {
            sprite->x2--;
            sprite->y2 += Sin(sprite->sSinIndex, 3) + 3;
            sprite->sSinIndex += 9;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_BOUNCE_1)
        {
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sSinIndex = 0;
            sprite->sState++;
        }

        break;
    case 14:
        if (gIntroFrameCounter < TIMER_POKE_BALL_BOUNCE_2)
        {
            if (gIntroFrameCounter % 1 == 0)
                sprite->x2++;

            sprite->sSinIndex += 4;
            sprite->y2 = -Sin(sprite->sSinIndex, 32);
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_BOUNCE_2)
        {
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sSinIndex = 0;
            sprite->sState++;
        }
        break;
    case 15:
        if (gIntroFrameCounter < TIMER_POKE_BALL_BOUNCE_3)
        {
            if (gIntroFrameCounter % 2 == 0)
                sprite->x2--;

            sprite->sSinIndex += 4;
            sprite->y2 = -Sin(sprite->sSinIndex, 24);
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_BOUNCE_3)
        {
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sSinIndex = 0;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_JUMP_UP)
            sprite->sState++;

        break;
    case 16:
        if (gIntroFrameCounter < TIMER_POKE_BALL_ESCAPE_OPEN)
        {
            sprite->y2 -= Cos(sprite->sSinIndex, 4);
            sprite->sSinIndex += 5;
        }

        if (gIntroFrameCounter == TIMER_KECLEON_ESCAPE)
        {
            DestroySpriteAndFreeResources(sprite);
        }
        break;
    }
}

#undef sSinIndex
#undef sRadius
#undef sMatrix

#define sTimer data[0]

static void SpriteCB_ExclamationMark(struct Sprite *sprite)
{
    if (sprite->sTimer < 8)
    {
        sprite->x += 1;
        sprite->y -= 2;
    }
    else if (sprite->sTimer == 16)
    {
        DestroySpriteAndFreeResources(sprite);
    }

    sprite->sTimer++;
}

#undef sTimer

static void SpriteCB_Sand(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroySpriteAndFreeResources(sprite);
}

#define sSinIndex data[1]
#define sMatrix data[2]

static void SpriteCB_PokeBall(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (gIntroFrameCounter < TIMER_POKE_BALL_HIT)
        {
            sprite->x -= 2;
            sprite->y2 = -Sin(sprite->sSinIndex, 48);
            sprite->sSinIndex += 4;
            sprite->sMatrix += 0x40;
            sprite->oam.matrixNum = MATRIX_POKE_BALL;
            SetOamMatrix(sprite->oam.matrixNum, 0x900 - sprite->sMatrix, 0, 0, 0x900 - sprite->sMatrix);
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_HIT)
        {
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sState++;
        }
        
        break;
    case 1:
        if (gIntroFrameCounter < TIMER_POKE_BALL_OPEN)
        {
            sprite->x += 2;
            sprite->y -= 3;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_OPEN)
            sprite->sState++;
        
        break;
    case 2:
        StartSpriteAnim(sprite, POKE_BALL_ANIM_OPEN);
        sprite->oam.priority = 1;
        sprite->sState++;
        break;
    case 3:
        if (gIntroFrameCounter == TIMER_POKE_BALL_CLOSE)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_CLOSE);
            sprite->oam.priority = 0;
            sprite->sState++;
        }
    case 4:
        if (gIntroFrameCounter == TIMER_POKE_BALL_FALL)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_SPIN_SLOW);
            sprite->sSinIndex = 0;
            sprite->sState++;
        }
        break;
    case 5:
        if (gIntroFrameCounter < TIMER_POKE_BALL_FALL_2)
        {
            sprite->x2--;
            sprite->y2 = -Sin(sprite->sSinIndex, 40);
            sprite->sSinIndex += 4;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_FALL_2)
        {
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sSinIndex = 0;
            sprite->sState++;
        }
        break;
    case 6:
        if (gIntroFrameCounter < TIMER_POKE_BALL_BOUNCE_1)
        {
            sprite->x2--;
            sprite->y2 += Sin(sprite->sSinIndex, 3) + 3;
            sprite->sSinIndex += 9;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_BOUNCE_1)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_SPIN_SLOW_ALT);
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sSinIndex = 0;
            sprite->sState++;
        }

        break;
    case 7:
        if (gIntroFrameCounter < TIMER_POKE_BALL_BOUNCE_2)
        {
            if (gIntroFrameCounter % 1 == 0)
                sprite->x2++;

            sprite->sSinIndex += 4;
            sprite->y2 = -Sin(sprite->sSinIndex, 32);
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_BOUNCE_2)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_SPIN_SLOW);
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sSinIndex = 0;
            sprite->sState++;
        }
        break;
    case 8:
        if (gIntroFrameCounter < TIMER_POKE_BALL_BOUNCE_3)
        {
            if (gIntroFrameCounter % 2 == 0)
                sprite->x2--;

            sprite->sSinIndex += 4;
            sprite->y2 = -Sin(sprite->sSinIndex, 24);
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_BOUNCE_3)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_STATIONARY);
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sSinIndex = 0;
            sprite->sState++;
        }
        break;
    case 9:
        if (gIntroFrameCounter == TIMER_POKE_BALL_WIGGLE_1_START)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_WIGGLE_LEFT);
            sprite->sState++;
        }
        break;
    case 10:
        if (gIntroFrameCounter < TIMER_POKE_BALL_WIGGLE_1_STOP)
        {
            sprite->x2 = -Sin(sprite->sSinIndex, 6);
            sprite->sSinIndex += 8;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_WIGGLE_1_STOP)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_STATIONARY);
            sprite->sSinIndex = 0;
            sprite->sState++;
        }
        break;
    case 11:
        if (gIntroFrameCounter == TIMER_POKE_BALL_WIGGLE_2_START)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_WIGGLE_RIGHT);
            sprite->sState++;
        }
        break;
    case 12:
        if (gIntroFrameCounter < TIMER_POKE_BALL_WIGGLE_2_STOP)
        {
            sprite->x2 = Sin(sprite->sSinIndex, 4);
            sprite->sSinIndex += 8;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_WIGGLE_2_STOP)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_STATIONARY);
            sprite->sSinIndex = 0;
            sprite->sState++;
        }
        break;
    case 13:
        if (gIntroFrameCounter == TIMER_POKE_BALL_WIGGLE_3_START)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_WIGGLE_LEFT);
            sprite->sState++;
        }
        break;
    case 14:
        if (gIntroFrameCounter < TIMER_POKE_BALL_WIGGLE_3_STOP)
        {
            sprite->x2 = -Sin(sprite->sSinIndex, 4);
            sprite->sSinIndex += 8;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_WIGGLE_3_STOP)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_STATIONARY);
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sSinIndex = 0;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_JUMP_UP)
            sprite->sState++;

        break;
    case 15:
        if (gIntroFrameCounter < TIMER_POKE_BALL_ESCAPE_OPEN)
        {
            sprite->y2 -= Cos(sprite->sSinIndex, 4);
            sprite->sSinIndex += 5;
        }

        if (gIntroFrameCounter == TIMER_POKE_BALL_ESCAPE_OPEN)
        {
            StartSpriteAnim(sprite, POKE_BALL_ANIM_OPEN);
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->sSinIndex = 0;
            sprite->oam.priority = 2;
        }
        break;
    }
}

static void SpriteCB_Flash(struct Sprite *sprite)
{
    sprite->invisible ^= 1;

    if (gIntroFrameCounter < TIMER_KECLEON_ESCAPE_FINISH)
    {
        sprite->oam.matrixNum = MATRIX_FLASH;
        sprite->sMatrix += Cos(sprite->sSinIndex, 0x5C);
        sprite->sSinIndex += 2;
        SetOamMatrix(sprite->oam.matrixNum, 0x800 - sprite->sMatrix, 0, 0, 0x800 - sprite->sMatrix);
    }
}

#undef sSinIndex
#undef sMatrix
