#include "global.h"
#include "speech_bubble.h"
#include "event_data.h"
#include "decompress.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"

static const u32 sTailGfx[] = INCBIN_U32("graphics/speech_bubble/speech_bubble_tail.4bpp.lz");
static const u16 sTailPal[] = INCBIN_U16("graphics/speech_bubble/speech_bubble_tail.gbapal");

static const struct Tail sTail = 
{
    sTailGfx, sTailPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64),
};

static EWRAM_DATA u8 sID = 0;

void LoadTailFromScript(void);
void LoadTailAutoFromScript(void);

void LoadTail(s16 x, s16 y)
{
    struct CompressedSpriteSheet sheet;
    struct SpritePalette palSheet;
    struct SpriteTemplate spriteTemp1;
    struct OamData oam = {0};
    
    s16 textboxX = (x < 120) ? TEXTBOX_LEFT_X : TEXTBOX_RIGHT_X;

    if (GetSpriteTileStartByTag(TAG_SPEECH_BUBBLE_TAIL) == 0xFFFF)
    {
        const u8 *gfxPtr = (const u8*)(sTail.gfx);

        sheet.tag = TAG_SPEECH_BUBBLE_TAIL;
        sheet.data = sTail.gfx;
        sheet.size = (gfxPtr[3] << 16) | (gfxPtr[2] << 8) | gfxPtr[1];

        LoadCompressedSpriteSheet(&sheet);
    }

    if (IndexOfSpritePaletteTag(TAG_SPEECH_BUBBLE_TAIL) == 0xFF)
    {
        palSheet.tag = TAG_SPEECH_BUBBLE_TAIL;
        palSheet.data = sTail.pal;

        LoadSpritePalette(&palSheet);
    }


    oam.size = sTail.size;
    oam.shape = sTail.shape;
    oam.priority = 0;
    oam.affineMode = ST_OAM_AFFINE_DOUBLE;

    spriteTemp1 = gDummySpriteTemplate;
    spriteTemp1.oam = &oam;
    spriteTemp1.paletteTag = spriteTemp1.tileTag = TAG_SPEECH_BUBBLE_TAIL;

    // place sprite at the midpoint between the textbox point and input point
    sID = CreateSprite(&spriteTemp1, (textboxX + x) / 2, (TEXTBOX_Y + y) / 2, 0); 

    InitSpriteAffineAnim(&gSprites[sID]);
    SetOamMatrix(gSprites[sID].oam.matrixNum, 
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
    DestroySprite(&gSprites[sID]);
    FreeSpritePaletteByTag(TAG_SPEECH_BUBBLE_TAIL);
    FreeSpriteTilesByTag(TAG_SPEECH_BUBBLE_TAIL);
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
