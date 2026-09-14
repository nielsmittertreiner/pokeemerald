struct InGameClock
{
    s8 dayOfWeek;
    s8 hours;
    s8 minutes;
    s8 seconds;
    s8 vblanks;
};

struct SaveBlock2V0
{
    u8 playerName[7 + 1];
    u8 playerGender; // MALE, FEMALE
    u8 specialSaveWarpFlags;
    u8 playerTrainerId[4];
    u16 playTimeHours;
    u8 playTimeMinutes;
    u8 playTimeSeconds;
    u8 playTimeVBlanks;
    u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
    u16 optionsClockMode:1; // OPTIONS_CLOCK_[12H/24H]
    u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
    u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
    u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
    u16 optionsBattleSceneOff:1; // whether battle animations are disabled
    u16 regionMapZoom:1; // whether the map is zoomed in
    u16 expShare:1;
    struct Pokedex pokedex;
    struct Time localTimeOffset;
    struct Time lastBerryTreeUpdate;
    u32 gcnLinkFlags; // Read by Pokémon Colosseum/XD
    u32 encryptionKey;
    struct PlayersApprentice playerApprentice;
    struct Apprentice apprentices[4];
    struct BerryCrush berryCrush;
    struct PokemonJumpRecords pokeJump;
    struct BerryPickingResults berryPick;
    struct RankingHall1P hallRecords1P[9][2][3]; // From record mixing.
    struct RankingHall2P hallRecords2P[2][3]; // From record mixing.
    u16 contestLinkResults[5][4];
    struct BattleFrontier frontier;
    struct Follower follower;
    u8 itemFlags[ROUND_BITS_TO_BYTES(379)];
    struct InGameClock inGameClock;
    bool8 godmode:1;
};

struct SaveBlock1V0
{
    struct Coords16 pos;
    struct WarpData location;
    struct WarpData continueGameWarp;
    struct WarpData dynamicWarp;
    struct WarpData lastHealLocation; // used by white-out and teleport
    struct WarpData escapeWarp; // used by Dig and Escape Rope
    u16 savedMusic;
    u8 weather;
    u8 weatherCycleStage;
    u8 flashLevel;
    u16 mapLayoutId;
    u16 mapView[0x100];
    u8 playerPartyCount;
    struct Pokemon playerParty[6];
    u32 money;
    u16 coins;
    u16 registeredItem; // registered for use with SELECT button
    struct ItemSlot pcItems[50];
    struct ItemSlot bagPocket_Items[30];
    struct ItemSlot bagPocket_KeyItems[30];
    struct ItemSlot bagPocket_PokeBalls[16];
    struct ItemSlot bagPocket_TMHM[64];
    struct ItemSlot bagPocket_Berries[46];
    struct ItemSlot bagPocket_Medicine[32];
    struct Pokeblock pokeblocks[40];
    u16 berryBlenderRecords[3];
    u16 trainerRematchStepCounter;
    u8 trainerRematches[100];
    struct ObjectEvent objectEvents[16];
    struct ObjectEventTemplate objectEventTemplates[64];
    u8 flags[300];
    u16 vars[512];
    u32 gameStats[64];
    struct BerryTree berryTrees[128];
    struct SecretBase secretBases[20];
    u8 playerRoomDecorations[12];
    u8 playerRoomDecorationPositions[12];
    u8 decorationDesks[10];
    u8 decorationChairs[10];
    u8 decorationPlants[10];
    u8 decorationOrnaments[30];
    u8 decorationMats[30];
    u8 decorationPosters[10];
    u8 decorationDolls[40];
    u8 decorationCushions[10];
    TVShow tvShows[25];
    PokeNews pokeNews[16];
    u16 outbreakPokemonSpecies;
    u8 outbreakLocationMapNum;
    u8 outbreakLocationMapGroup;
    u8 outbreakPokemonLevel;
    u16 outbreakPokemonMoves[4];
    u8 outbreakPokemonProbability;
    u16 outbreakDaysLeft;
    struct GabbyAndTyData gabbyAndTyData;
    u16 easyChatProfile[6];
    u16 easyChatBattleStart[6];
    u16 easyChatBattleWon[6];
    u16 easyChatBattleLost[6];
    struct Mail mail[16];
    u8 unlockedTrendySayings[5]; // Bitfield for unlockable Easy Chat words in EC_GROUP_TRENDY_SAYING
    OldMan oldMan;
    struct DewfordTrend dewfordTrends[5];
    struct ContestWinner contestWinners[13]; // see CONTEST_WINNER_*
    struct DayCare daycare;
    struct LinkBattleRecords linkBattleRecords;
    u8 giftRibbons[11];
    struct ExternalEventData externalEventData;
    struct ExternalEventFlags externalEventFlags;
    struct Roamer roamer;
    struct EnigmaBerry enigmaBerry;
    struct MysteryGiftSave mysteryGift;
    u32 trainerHillTimes[4];
    struct RamScript ramScript;
    struct RecordMixingGift recordMixingGift;
    LilycoveLady lilycoveLady;
    struct TrainerNameRecord trainerNameRecords[20];
    u8 registeredTexts[10][21];
    struct TrainerHillSave trainerHill;
    struct WaldaPhrase waldaPhrase;
    u8 quests[ROUND_BITS_TO_BYTES(1)];
};
