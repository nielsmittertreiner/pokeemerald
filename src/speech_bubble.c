#include "global.h"
#include "graphics.h"
#include "speech_bubble.h"
#include "event_data.h"
#include "decompress.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"

static const struct OamData sSpeechBubbleOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct CompressedSpriteSheet gSpeechBubbleSpriteSheet =
{
    gSpeechBubbleTiles, 0x1000, TAG_SPEECH_BUBBLE_TAIL_GFX
};

static const struct SpritePalette gSpeechBubblePalette =
{
    sSpeechBubblePalette, TAG_SPEECH_BUBBLE_TAIL_GFX
};

static const struct SpriteTemplate gSpeechBubbleSpriteTemplate =
{
    .tileTag = TAG_SPEECH_BUBBLE_TAIL_GFX,
    .paletteTag = TAG_SPEECH_BUBBLE_TAIL_GFX,
    .oam = &sSpeechBubbleOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static EWRAM_DATA u8 gSpeechBubbleGraphics = 0;

void LoadTailFromScript(void);
void LoadTailAutoFromScript(void);

void LoadTail(s16 x, s16 y)
{ 
    s16 textboxX = (x < 120) ? TEXTBOX_LEFT_X : TEXTBOX_RIGHT_X;

    if (GetSpriteTileStartByTag(TAG_SPEECH_BUBBLE_TAIL_GFX) == 0xFFFF)
        LoadCompressedSpriteSheet(&gSpeechBubbleSpriteSheet);

    if (IndexOfSpritePaletteTag(TAG_SPEECH_BUBBLE_TAIL_GFX) == 0xFF)
        LoadSpritePalette(&gSpeechBubblePalette);

    gSpeechBubbleGraphics = CreateSprite(&gSpeechBubbleSpriteTemplate, (textboxX + x) / 2, (TEXTBOX_Y + y) / 2, 0);
    InitSpriteAffineAnim(&gSprites[gSpeechBubbleGraphics]);
    SetOamMatrix(gSprites[gSpeechBubbleGraphics].oam.matrixNum, 
                 Q_8_8(1), 
                 Q_8_8(1.0 / ((float)(y - TEXTBOX_Y) / -(x - textboxX))), // calculate x shear factor
                 Q_8_8(0), 
                 Q_8_8(IMAGE_HEIGHT / (double)(TEXTBOX_Y - y))); // calculate y scale factor
}

void LoadTailFromObjectEventId(u32 id)
{
    struct ObjectEvent *objectEvent;
    struct Sprite *sprite;
    s16 x, y;

    objectEvent = &gObjectEvents[GetObjectEventIdByLocalIdAndMap(id, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup)];
    sprite = &gSprites[objectEvent->spriteId];

    x = sprite->oam.x - (sprite->pos2.x + sprite->centerToCornerVecX);
    y = sprite->oam.y - (sprite->pos2.y + sprite->centerToCornerVecY);

    //x += (gSpecialVar_0x8005 < 120) ? -5 : 5;
    y += 8;
    LoadTail(x, y);
}

void DestroyTail(void)
{
    FreeSpriteOamMatrix(&gSprites[gSpeechBubbleGraphics]);
    FreeSpritePaletteByTag(TAG_SPEECH_BUBBLE_TAIL_GFX);
    FreeSpriteTilesByTag(TAG_SPEECH_BUBBLE_TAIL_GFX);
    DestroySprite(&gSprites[gSpeechBubbleGraphics]);
}

void LoadTailFromScript(void)
{
    s16 x = (s16)(VarGet(gSpecialVar_0x8005));
    s16 y = (s16)(VarGet(gSpecialVar_0x8006));
    LoadTail(x, y);
}

// gSpecialVar_0x8004 is the object event id
void LoadTailAutoFromScript(void)
{
    LoadTailFromObjectEventId(VarGet(gSpecialVar_0x8004));
}
