#include "global.h"
#include "load_save.h"
#include "overworld.h"
#include "save.h"
#include "constants/heal_locations.h"
#include "data/save_versions/save.v0.h"

#define COPY_SAVEBLOCK_FIELD(saveblock, field) gSaveBlock##saveblock##Ptr->field = oldSaveBlock##saveblock##Ptr->field
#define COPY_SAVEBLOCK_BLOCK(saveblock, field) CpuCopy16(&oldSaveBlock##saveblock##Ptr->field, &gSaveBlock##saveblock##Ptr->field, sizeof(gSaveBlock##saveblock##Ptr->field))
#define COPY_SAVEBLOCK_ARRAY(saveblock, field)                                                                                      \
    for (u32 i = 0; i < min(ARRAY_COUNT(gSaveBlock##saveblock##Ptr->field), ARRAY_COUNT(oldSaveBlock##saveblock##Ptr->field)); i++) \
        gSaveBlock##saveblock##Ptr->field[i] = oldSaveBlock##saveblock##Ptr->field[i];                                              

bool8 DoUpdateSaveDataV0(const struct SaveSectorLocation *locations)
{
    const struct SaveBlock2V0 *oldSaveBlock2Ptr = (struct SaveBlock2V0 *)(locations[0].data); // SECTOR_ID_SAVEBLOCK2
    const struct SaveBlock1V0 *oldSaveBlock1Ptr = (struct SaveBlock1V0 *)(locations[3].data); // SECTOR_ID_SAVEBLOCK1_START
    const struct PokemonStorage *oldPokemonStoragePtr = (struct PokemonStorage *)(locations[19].data); // SECTOR_ID_PKMN_STORAGE_START

    gSaveBlock2Ptr->saveSentinel = 0xFF;
    gSaveBlock2Ptr->saveVersion = SAVE_VERSION;

    COPY_SAVEBLOCK_ARRAY(2, playerName);
    COPY_SAVEBLOCK_FIELD(2, playerGender);
    COPY_SAVEBLOCK_FIELD(2, specialSaveWarpFlags);
    COPY_SAVEBLOCK_ARRAY(2, playerTrainerId);

    COPY_SAVEBLOCK_FIELD(2, playTimeHours);
    COPY_SAVEBLOCK_FIELD(2, playTimeMinutes);
    COPY_SAVEBLOCK_FIELD(2, playTimeSeconds);
    COPY_SAVEBLOCK_FIELD(2, playTimeVBlanks);

    COPY_SAVEBLOCK_FIELD(2, optionsButtonMode);
    COPY_SAVEBLOCK_FIELD(2, optionsTextSpeed);
    COPY_SAVEBLOCK_FIELD(2, optionsClockMode);
    COPY_SAVEBLOCK_FIELD(2, optionsWindowFrameType);
    COPY_SAVEBLOCK_FIELD(2, optionsSound);
    COPY_SAVEBLOCK_FIELD(2, optionsBattleStyle);
    COPY_SAVEBLOCK_FIELD(2, optionsBattleSceneOff);
    COPY_SAVEBLOCK_FIELD(2, regionMapZoom);
    COPY_SAVEBLOCK_FIELD(2, expShare);

    COPY_SAVEBLOCK_FIELD(2, pokedex);
    COPY_SAVEBLOCK_FIELD(2, localTimeOffset);
    COPY_SAVEBLOCK_FIELD(2, lastBerryTreeUpdate);

    COPY_SAVEBLOCK_FIELD(2, gcnLinkFlags);
    COPY_SAVEBLOCK_FIELD(2, encryptionKey);

    COPY_SAVEBLOCK_FIELD(2, playerApprentice);
    COPY_SAVEBLOCK_BLOCK(2, apprentices);
    COPY_SAVEBLOCK_FIELD(2, berryCrush);
    COPY_SAVEBLOCK_FIELD(2, pokeJump);
    COPY_SAVEBLOCK_FIELD(2, berryPick);
    COPY_SAVEBLOCK_BLOCK(2, hallRecords1P);
    COPY_SAVEBLOCK_BLOCK(2, hallRecords2P);
    COPY_SAVEBLOCK_BLOCK(2, contestLinkResults);
    COPY_SAVEBLOCK_FIELD(2, frontier);
    COPY_SAVEBLOCK_FIELD(2, follower);
    COPY_SAVEBLOCK_ARRAY(2, itemFlags);
    //COPY_SAVEBLOCK_FIELD(2, inGameClock);

    COPY_SAVEBLOCK_FIELD(1, pos);
    COPY_SAVEBLOCK_FIELD(1, location);
    COPY_SAVEBLOCK_FIELD(1, continueGameWarp);
    COPY_SAVEBLOCK_FIELD(1, dynamicWarp);
    COPY_SAVEBLOCK_FIELD(1, lastHealLocation);
    COPY_SAVEBLOCK_FIELD(1, escapeWarp);
    COPY_SAVEBLOCK_FIELD(1, mapLayoutId);

    COPY_SAVEBLOCK_FIELD(1, playerPartyCount);
    COPY_SAVEBLOCK_ARRAY(1, playerParty);
    COPY_SAVEBLOCK_FIELD(1, money);
    COPY_SAVEBLOCK_FIELD(1, coins);
    COPY_SAVEBLOCK_FIELD(1, registeredItem);

    COPY_SAVEBLOCK_BLOCK(1, pcItems);
    COPY_SAVEBLOCK_BLOCK(1, bagPocket_Items);
    COPY_SAVEBLOCK_BLOCK(1, bagPocket_KeyItems);
    COPY_SAVEBLOCK_BLOCK(1, bagPocket_PokeBalls);
    COPY_SAVEBLOCK_BLOCK(1, bagPocket_TMHM);
    COPY_SAVEBLOCK_BLOCK(1, bagPocket_Berries);
    COPY_SAVEBLOCK_BLOCK(1, bagPocket_Medicine);

    COPY_SAVEBLOCK_BLOCK(1, pokeblocks);
    COPY_SAVEBLOCK_BLOCK(1, berryBlenderRecords);
    COPY_SAVEBLOCK_FIELD(1, trainerRematchStepCounter);
    COPY_SAVEBLOCK_BLOCK(1, trainerRematches);

    COPY_SAVEBLOCK_BLOCK(1, flags);
    COPY_SAVEBLOCK_BLOCK(1, vars);
    COPY_SAVEBLOCK_BLOCK(1, gameStats);
    COPY_SAVEBLOCK_BLOCK(1, berryTrees);
    COPY_SAVEBLOCK_BLOCK(1, secretBases);
    COPY_SAVEBLOCK_BLOCK(1, playerRoomDecorations);
    COPY_SAVEBLOCK_BLOCK(1, playerRoomDecorationPositions);
    COPY_SAVEBLOCK_BLOCK(1, decorationDesks);
    COPY_SAVEBLOCK_BLOCK(1, decorationChairs);
    COPY_SAVEBLOCK_BLOCK(1, decorationPlants);
    COPY_SAVEBLOCK_BLOCK(1, decorationOrnaments);
    COPY_SAVEBLOCK_BLOCK(1, decorationMats);
    COPY_SAVEBLOCK_BLOCK(1, decorationPosters);
    COPY_SAVEBLOCK_BLOCK(1, decorationDolls);
    COPY_SAVEBLOCK_BLOCK(1, decorationCushions);

    COPY_SAVEBLOCK_BLOCK(1, tvShows);
    COPY_SAVEBLOCK_BLOCK(1, pokeNews);
    COPY_SAVEBLOCK_FIELD(1, outbreakPokemonSpecies);
    COPY_SAVEBLOCK_FIELD(1, outbreakLocationMapNum);
    COPY_SAVEBLOCK_FIELD(1, outbreakLocationMapGroup);
    COPY_SAVEBLOCK_FIELD(1, outbreakPokemonLevel);
    COPY_SAVEBLOCK_BLOCK(1, outbreakPokemonMoves);
    COPY_SAVEBLOCK_FIELD(1, outbreakPokemonProbability);
    COPY_SAVEBLOCK_FIELD(1, outbreakDaysLeft);
    COPY_SAVEBLOCK_FIELD(1, gabbyAndTyData);
    COPY_SAVEBLOCK_BLOCK(1, easyChatProfile);
    COPY_SAVEBLOCK_BLOCK(1, easyChatBattleStart);
    COPY_SAVEBLOCK_BLOCK(1, easyChatBattleWon);
    COPY_SAVEBLOCK_BLOCK(1, easyChatBattleLost);
    COPY_SAVEBLOCK_BLOCK(1, mail);
    COPY_SAVEBLOCK_BLOCK(1, unlockedTrendySayings);
    COPY_SAVEBLOCK_FIELD(1, oldMan);
    COPY_SAVEBLOCK_BLOCK(1, dewfordTrends);
    COPY_SAVEBLOCK_BLOCK(1, contestWinners);
    COPY_SAVEBLOCK_FIELD(1, daycare);
    COPY_SAVEBLOCK_FIELD(1, linkBattleRecords);
    COPY_SAVEBLOCK_BLOCK(1, giftRibbons);
    COPY_SAVEBLOCK_FIELD(1, externalEventData);
    COPY_SAVEBLOCK_FIELD(1, externalEventFlags);
    COPY_SAVEBLOCK_FIELD(1, roamer);
    COPY_SAVEBLOCK_FIELD(1, enigmaBerry);
    COPY_SAVEBLOCK_FIELD(1, mysteryGift);
    COPY_SAVEBLOCK_BLOCK(1, trainerHillTimes);
    COPY_SAVEBLOCK_FIELD(1, ramScript);
    COPY_SAVEBLOCK_FIELD(1, recordMixingGift);
    COPY_SAVEBLOCK_FIELD(1, lilycoveLady);
    COPY_SAVEBLOCK_BLOCK(1, trainerNameRecords);
    COPY_SAVEBLOCK_BLOCK(1, registeredTexts);
    COPY_SAVEBLOCK_FIELD(1, trainerHill);
    COPY_SAVEBLOCK_FIELD(1, waldaPhrase);
    COPY_SAVEBLOCK_BLOCK(1, quests);

    *gPokemonStoragePtr = *oldPokemonStoragePtr;

    SetContinueGameWarpStatus();
    gSaveBlock1Ptr->continueGameWarp = gSaveBlock1Ptr->lastHealLocation;
    return TRUE;
}