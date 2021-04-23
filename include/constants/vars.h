#ifndef GUARD_CONSTANTS_VARS_H
#define GUARD_CONSTANTS_VARS_H

#define VARS_START                                       0x4000

// temporary vars
// The first 0x10 vars are are temporary--they are cleared every time a map is loaded.
#define TEMP_VARS_START                                  0x4000
#define VAR_TEMP_0                                       (TEMP_VARS_START + 0x0)
#define VAR_TEMP_1                                       (TEMP_VARS_START + 0x1)
#define VAR_TEMP_2                                       (TEMP_VARS_START + 0x2)
#define VAR_TEMP_3                                       (TEMP_VARS_START + 0x3)
#define VAR_TEMP_4                                       (TEMP_VARS_START + 0x4)
#define VAR_TEMP_5                                       (TEMP_VARS_START + 0x5)
#define VAR_TEMP_6                                       (TEMP_VARS_START + 0x6)
#define VAR_TEMP_7                                       (TEMP_VARS_START + 0x7)
#define VAR_TEMP_8                                       (TEMP_VARS_START + 0x8)
#define VAR_TEMP_9                                       (TEMP_VARS_START + 0x9)
#define VAR_TEMP_A                                       (TEMP_VARS_START + 0xA)
#define VAR_TEMP_B                                       (TEMP_VARS_START + 0xB)
#define VAR_TEMP_C                                       (TEMP_VARS_START + 0xC)
#define VAR_TEMP_D                                       (TEMP_VARS_START + 0xD)
#define VAR_TEMP_E                                       (TEMP_VARS_START + 0xE)
#define VAR_TEMP_F                                       (TEMP_VARS_START + 0xF)
#define TEMP_VARS_END                                    VAR_TEMP_F

// object gfx id vars
// These 0x10 vars are used to dynamically control a map object's sprite.
// For example, the rival's sprite id is dynamically set based on the player's gender.
// See VarGetObjectEventGraphicsId().
#define OBJ_GFX_ID_VARS_START                            0x4010
#define VAR_OBJ_GFX_ID_0                                 (OBJ_GFX_ID_VARS_START + 0x0)
#define VAR_OBJ_GFX_ID_1                                 (OBJ_GFX_ID_VARS_START + 0x1)
#define VAR_OBJ_GFX_ID_2                                 (OBJ_GFX_ID_VARS_START + 0x2)
#define VAR_OBJ_GFX_ID_3                                 (OBJ_GFX_ID_VARS_START + 0x3)
#define VAR_OBJ_GFX_ID_4                                 (OBJ_GFX_ID_VARS_START + 0x4)
#define VAR_OBJ_GFX_ID_5                                 (OBJ_GFX_ID_VARS_START + 0x5)
#define VAR_OBJ_GFX_ID_6                                 (OBJ_GFX_ID_VARS_START + 0x6)
#define VAR_OBJ_GFX_ID_7                                 (OBJ_GFX_ID_VARS_START + 0x7)
#define VAR_OBJ_GFX_ID_8                                 (OBJ_GFX_ID_VARS_START + 0x8)
#define VAR_OBJ_GFX_ID_9                                 (OBJ_GFX_ID_VARS_START + 0x9)
#define VAR_OBJ_GFX_ID_A                                 (OBJ_GFX_ID_VARS_START + 0xA)
#define VAR_OBJ_GFX_ID_B                                 (OBJ_GFX_ID_VARS_START + 0xB)
#define VAR_OBJ_GFX_ID_C                                 (OBJ_GFX_ID_VARS_START + 0xC)
#define VAR_OBJ_GFX_ID_D                                 (OBJ_GFX_ID_VARS_START + 0xD)
#define VAR_OBJ_GFX_ID_E                                 (OBJ_GFX_ID_VARS_START + 0xE)
#define VAR_OBJ_GFX_ID_F                                 (OBJ_GFX_ID_VARS_START + 0xF)
#define OBJ_GFX_ID_VARS_END                              VAR_OBJ_GFX_ID_F

// general purpose vars
#define GENERAL_PURPOSE_VARS_START                       0x4020
#define VAR_RECYCLE_GOODS                                (GENERAL_PURPOSE_VARS_START + 0x0) 
#define VAR_REPEL_STEP_COUNT                             (GENERAL_PURPOSE_VARS_START + 0x1) 
#define VAR_ICE_STEP_COUNT                               (GENERAL_PURPOSE_VARS_START + 0x2) 
#define VAR_STARTER_MON                                  (GENERAL_PURPOSE_VARS_START + 0x3)  // 0=Treecko, 1=Torchic, 2=Mudkip
#define VAR_MIRAGE_RND_H                                 (GENERAL_PURPOSE_VARS_START + 0x4) 
#define VAR_MIRAGE_RND_L                                 (GENERAL_PURPOSE_VARS_START + 0x5) 
#define VAR_SECRET_BASE_MAP                              (GENERAL_PURPOSE_VARS_START + 0x6) 
#define VAR_CYCLING_ROAD_RECORD_COLLISIONS               (GENERAL_PURPOSE_VARS_START + 0x7) 
#define VAR_CYCLING_ROAD_RECORD_TIME_L                   (GENERAL_PURPOSE_VARS_START + 0x8) 
#define VAR_CYCLING_ROAD_RECORD_TIME_H                   (GENERAL_PURPOSE_VARS_START + 0x9) 
#define VAR_FRIENDSHIP_STEP_COUNTER                      (GENERAL_PURPOSE_VARS_START + 0xA) 
#define VAR_POISON_STEP_COUNTER                          (GENERAL_PURPOSE_VARS_START + 0xB) 
#define VAR_RESET_RTC_ENABLE                             (GENERAL_PURPOSE_VARS_START + 0xC) 
#define VAR_ENIGMA_BERRY_AVAILABLE                       (GENERAL_PURPOSE_VARS_START + 0xD) 
#define VAR_0x402E                                       (GENERAL_PURPOSE_VARS_START + 0xE) 
#define VAR_FRONTIER_MANIAC_FACILITY                     (GENERAL_PURPOSE_VARS_START + 0xF) 
#define VAR_FRONTIER_GAMBLER_CHALLENGE                   (GENERAL_PURPOSE_VARS_START + 0x10)
#define VAR_FRONTIER_GAMBLER_SET_CHALLENGE               (GENERAL_PURPOSE_VARS_START + 0x11)
#define VAR_FRONTIER_GAMBLER_AMOUNT_BET                  (GENERAL_PURPOSE_VARS_START + 0x12)
#define VAR_FRONTIER_GAMBLER_STATE                       (GENERAL_PURPOSE_VARS_START + 0x13)
#define VAR_DEOXYS_ROCK_STEP_COUNT                       (GENERAL_PURPOSE_VARS_START + 0x14)
#define VAR_DEOXYS_ROCK_LEVEL                            (GENERAL_PURPOSE_VARS_START + 0x15)
#define VAR_PC_BOX_TO_SEND_MON                           (GENERAL_PURPOSE_VARS_START + 0x16)
#define VAR_ABNORMAL_WEATHER_LOCATION                    (GENERAL_PURPOSE_VARS_START + 0x17)
#define VAR_ABNORMAL_WEATHER_STEP_COUNTER                (GENERAL_PURPOSE_VARS_START + 0x18)
#define VAR_SHOULD_END_ABNORMAL_WEATHER                  (GENERAL_PURPOSE_VARS_START + 0x19)
#define VAR_FARAWAY_ISLAND_STEP_COUNTER                  (GENERAL_PURPOSE_VARS_START + 0x1A)
#define VAR_REGICE_STEPS_1                               (GENERAL_PURPOSE_VARS_START + 0x1B)
#define VAR_REGICE_STEPS_2                               (GENERAL_PURPOSE_VARS_START + 0x1C)
#define VAR_REGICE_STEPS_3                               (GENERAL_PURPOSE_VARS_START + 0x1D)
#define VAR_ALTERING_CAVE_WILD_SET                       (GENERAL_PURPOSE_VARS_START + 0x1E)
#define VAR_DISTRIBUTE_EON_TICKET                        (GENERAL_PURPOSE_VARS_START + 0x1F) // This var is read and written, but is always zero. The only way to obtain the Eon Ticket in Emerald is via Record Mixing
#define VAR_DAYS                                         (GENERAL_PURPOSE_VARS_START + 0x20)
#define VAR_FANCLUB_FAN_COUNTER                          (GENERAL_PURPOSE_VARS_START + 0x21)
#define VAR_FANCLUB_LOSE_FAN_TIMER                       (GENERAL_PURPOSE_VARS_START + 0x22)
#define VAR_DEPT_STORE_FLOOR                             (GENERAL_PURPOSE_VARS_START + 0x23)
#define VAR_TRICK_HOUSE_LEVEL                            (GENERAL_PURPOSE_VARS_START + 0x24)
#define VAR_POKELOT_PRIZE_ITEM                           (GENERAL_PURPOSE_VARS_START + 0x25)
#define VAR_NATIONAL_DEX                                 (GENERAL_PURPOSE_VARS_START + 0x26)
#define VAR_SEEDOT_SIZE_RECORD                           (GENERAL_PURPOSE_VARS_START + 0x27)
#define VAR_ASH_GATHER_COUNT                             (GENERAL_PURPOSE_VARS_START + 0x28)
#define VAR_BIRCH_STATE                                  (GENERAL_PURPOSE_VARS_START + 0x29)
#define VAR_CRUISE_STEP_COUNT                            (GENERAL_PURPOSE_VARS_START + 0x2A)
#define VAR_POKELOT_RND1                                 (GENERAL_PURPOSE_VARS_START + 0x2B)
#define VAR_POKELOT_RND2                                 (GENERAL_PURPOSE_VARS_START + 0x2C)
#define VAR_POKELOT_PRIZE_PLACE                          (GENERAL_PURPOSE_VARS_START + 0x2D)
#define VAR_CABLE_CLUB_STATE                             (GENERAL_PURPOSE_VARS_START + 0x2E) 
#define VAR_LOTAD_SIZE_RECORD                            (GENERAL_PURPOSE_VARS_START + 0x2F)
#define GENERAL_PURPOSE_VARS_END                         VAR_LOTAD_SIZE_RECORD

// Towns and City State Variables
#define TOWN_CITY_STATE_VARS_START                       0x4050
#define VAR_SUNSET_TOWN_STATE                            (TOWN_CITY_STATE_VARS_START + 0x0)
#define VAR_CEDARRED_TOWN_STATE                          (TOWN_CITY_STATE_VARS_START + 0x1)
#define VAR_FIRWEALD_CITY_STATE                          (TOWN_CITY_STATE_VARS_START + 0x2)
#define VAR_MURENA_CITY_STATE                            (TOWN_CITY_STATE_VARS_START + 0x3)
#define VAR_LITOR_TOWN_STATE                             (TOWN_CITY_STATE_VARS_START + 0x4)
#define VAR_0x4055                                       (TOWN_CITY_STATE_VARS_START + 0x5) // Unused Var
#define VAR_PACIFIDLOG_TOWN_STATE                        (TOWN_CITY_STATE_VARS_START + 0x6) // Unused Var
#define VAR_PETALBURG_CITY_STATE                         (TOWN_CITY_STATE_VARS_START + 0x7)
#define VAR_SLATEPORT_CITY_STATE                         (TOWN_CITY_STATE_VARS_START + 0x8)
#define VAR_MAUVILLE_CITY_STATE                          (TOWN_CITY_STATE_VARS_START + 0x9) // Unused Var
#define VAR_RUSTBORO_CITY_STATE                          (TOWN_CITY_STATE_VARS_START + 0xA)
#define VAR_FORTREE_CITY_STATE                           (TOWN_CITY_STATE_VARS_START + 0xB) // Unused Var
#define VAR_LILYCOVE_CITY_STATE                          (TOWN_CITY_STATE_VARS_START + 0xC) // Unused Var
#define VAR_MOSSDEEP_CITY_STATE                          (TOWN_CITY_STATE_VARS_START + 0xD)
#define VAR_SOOTOPOLIS_CITY_STATE                        (TOWN_CITY_STATE_VARS_START + 0xE)
#define VAR_EVER_GRANDE_CITY_STATE                       (TOWN_CITY_STATE_VARS_START + 0xF) // Unused Var
#define VAR_ROUTE101_STATE                               (TOWN_CITY_STATE_VARS_START + 0x10)
#define VAR_0x4061                                       (TOWN_CITY_STATE_VARS_START + 0x11) // Unused Var
#define VAR_0x4062                                       (TOWN_CITY_STATE_VARS_START + 0x12) // Unused Var
#define VAR_ROUTE104_STATE                               (TOWN_CITY_STATE_VARS_START + 0x13)
#define VAR_ROUTE105_STATE                               (TOWN_CITY_STATE_VARS_START + 0x14) // Unused Var
#define VAR_0x4065                                       (TOWN_CITY_STATE_VARS_START + 0x15) // Unused Var
#define VAR_ROUTE402_STATE                               (TOWN_CITY_STATE_VARS_START + 0x16) // Unused Var
#define VAR_ROUTE108_STATE                               (TOWN_CITY_STATE_VARS_START + 0x17) // Unused Var
#define VAR_ROUTE109_STATE                               (TOWN_CITY_STATE_VARS_START + 0x18) // Unused Var
#define VAR_ROUTE110_STATE                               (TOWN_CITY_STATE_VARS_START + 0x19)
#define VAR_ROUTE111_STATE                               (TOWN_CITY_STATE_VARS_START + 0x1A) // Unused Var
#define VAR_ROUTE112_STATE                               (TOWN_CITY_STATE_VARS_START + 0x1B) // Unused Var
#define VAR_ROUTE113_STATE                               (TOWN_CITY_STATE_VARS_START + 0x1C) // Unused Var
#define VAR_ROUTE114_STATE                               (TOWN_CITY_STATE_VARS_START + 0x1D) // Unused Var
#define VAR_ROUTE115_STATE                               (TOWN_CITY_STATE_VARS_START + 0x1E) // Unused Var
#define VAR_ROUTE116_STATE                               (TOWN_CITY_STATE_VARS_START + 0x1F)
#define TOWN_CITY_STATE_VARS_END                         VAR_ROUTE116_STATE

// Special Area and other State Variables
#define SPECIAL_STATE_VARS_START                         0x4070
#define VAR_ACREN_FOREST_STATE                           (SPECIAL_STATE_VARS_START + 0x0) // Acren Forest
#define VAR_SUNSET_TOWN_FOLLOWER_STATE                   (SPECIAL_STATE_VARS_START + 0x1) // Conifer Follower
#define VAR_JULIA_STATE                                  (SPECIAL_STATE_VARS_START + 0x2) // Julia Encounters
#define VAR_TOURNAMENT_HALL_STATE                        (SPECIAL_STATE_VARS_START + 0x3) // Tournament Hall
#define VAR_TOURNAMENT_HALL_OPPONENT                     (SPECIAL_STATE_VARS_START + 0x4)
#define VAR_TOURNAMENT_HALL_ROUND                        (SPECIAL_STATE_VARS_START + 0x5)
#define VAR_SUNSET_TOWN_FOLLOWER_STATE_2                 (SPECIAL_STATE_VARS_START + 0x6)
#define VAR_FISHERMAN_FERRY_LOCATION                     (SPECIAL_STATE_VARS_START + 0x7) // Fisherman Ferry Location
#define VAR_FISHERMAN_FERRY_STATE                        (SPECIAL_STATE_VARS_START + 0x8)
#define VAR_OUREA_CAVES_STATE                            (SPECIAL_STATE_VARS_START + 0x9)
#define VAR_OUREA_CAVES_LIGHTS_STATE                     (SPECIAL_STATE_VARS_START + 0xA)
#define VAR_UNUSED_0x40BB                                (SPECIAL_STATE_VARS_START + 0xB) // Unused Var
#define VAR_BRAVO_TRAINER_BATTLE_TOWER_ON                (SPECIAL_STATE_VARS_START + 0xC)
#define VAR_JAGGED_PASS_ASH_WEATHER                      (SPECIAL_STATE_VARS_START + 0xD)
#define VAR_GLASS_WORKSHOP_STATE                         (SPECIAL_STATE_VARS_START + 0xE)
#define VAR_METEOR_FALLS_STATE                           (SPECIAL_STATE_VARS_START + 0xF)
#define VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE              (SPECIAL_STATE_VARS_START + 0x10)
#define VAR_TRICK_HOUSE_PRIZE_PICKUP                     (SPECIAL_STATE_VARS_START + 0x11)
#define VAR_PACIFIDLOG_TM_RECEIVED_DAY                   (SPECIAL_STATE_VARS_START + 0x12)
#define VAR_VICTORY_ROAD_1F_STATE                        (SPECIAL_STATE_VARS_START + 0x13)
#define VAR_FOSSIL_RESURRECTION_STATE                    (SPECIAL_STATE_VARS_START + 0x14)
#define VAR_WHICH_FOSSIL_REVIVED                         (SPECIAL_STATE_VARS_START + 0x15)
#define VAR_STEVENS_HOUSE_STATE                          (SPECIAL_STATE_VARS_START + 0x16)
#define VAR_OLDALE_RIVAL_STATE                           (SPECIAL_STATE_VARS_START + 0x17)
#define VAR_JAGGED_PASS_STATE                            (SPECIAL_STATE_VARS_START + 0x18)
#define VAR_SCOTT_PETALBURG_ENCOUNTER                    (SPECIAL_STATE_VARS_START + 0x19)
#define VAR_SKY_PILLAR_STATE                             (SPECIAL_STATE_VARS_START + 0x1A)
#define VAR_MIRAGE_TOWER_STATE                           (SPECIAL_STATE_VARS_START + 0x1B)
#define VAR_FOSSIL_MANIAC_STATE                          (SPECIAL_STATE_VARS_START + 0x1C)
#define VAR_CABLE_CLUB_TUTORIAL_STATE                    (SPECIAL_STATE_VARS_START + 0x1D)
#define VAR_FRONTIER_BATTLE_MODE                         (SPECIAL_STATE_VARS_START + 0x1E)
#define VAR_FRONTIER_FACILITY                            (SPECIAL_STATE_VARS_START + 0x1F)
#define VAR_HAS_ENTERED_BATTLE_FRONTIER                  (SPECIAL_STATE_VARS_START + 0x20) // Var is used like a flag.
#define VAR_SCOTT_STATE                                  (SPECIAL_STATE_VARS_START + 0x21)
#define VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE               (SPECIAL_STATE_VARS_START + 0x22)
#define VAR_DEX_UPGRADE_JOHTO_STARTER_STATE              (SPECIAL_STATE_VARS_START + 0x23)
#define VAR_SS_TIDAL_SCOTT_STATE                         (SPECIAL_STATE_VARS_START + 0x24) // Always equal to FLAG_MET_SCOTT_ON_SS_TIDAL
#define VAR_ROAMER_POKEMON                               (SPECIAL_STATE_VARS_START + 0x25) // 0 = Latias, 1 = Latios
#define VAR_TRAINER_HILL_IS_ACTIVE                       (SPECIAL_STATE_VARS_START + 0x26)
#define VAR_SKY_PILLAR_RAQUAZA_CRY_DONE                  (SPECIAL_STATE_VARS_START + 0x27)
#define VAR_SOOTOPOLIS_WALLACE_STATE                     (SPECIAL_STATE_VARS_START + 0x28)
#define VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT (SPECIAL_STATE_VARS_START + 0x29)
#define VAR_REGISTER_BIRCH_STATE                         (SPECIAL_STATE_VARS_START + 0x2A)
#define VAR_UNUSED_0x40DB                                (SPECIAL_STATE_VARS_START + 0x2B) // Unused Var
#define VAR_UNUSED_0x40DC                                (SPECIAL_STATE_VARS_START + 0x2C) // Unused Var
#define VAR_EVENT_PICHU_SLOT                             (SPECIAL_STATE_VARS_START + 0x2D)
#define VAR_NEVER_READ_0x40DE                            (SPECIAL_STATE_VARS_START + 0x2E) // Var is written to, but never read
#define VAR_NEVER_READ_0x40DF                            (SPECIAL_STATE_VARS_START + 0x2F) // Var is written to, but never read
#define VAR_NEVER_READ_0x40E0                            (SPECIAL_STATE_VARS_START + 0x30) // Var is written to, but never read
#define VAR_NEVER_READ_0x40E1                            (SPECIAL_STATE_VARS_START + 0x31) // Var is written to, but never read
#define VAR_NEVER_READ_0x40E2                            (SPECIAL_STATE_VARS_START + 0x32) // Var is written to, but never read
#define VAR_NEVER_READ_0x40E3                            (SPECIAL_STATE_VARS_START + 0x33) // Var is written to, but never read
#define VAR_NEVER_READ_0x40E4                            (SPECIAL_STATE_VARS_START + 0x34) // var is written to, but never read
#define VAR_UNUSED_0x40E5                                (SPECIAL_STATE_VARS_START + 0x35) // Unused Var
#define VAR_DAILY_SLOTS                                  (SPECIAL_STATE_VARS_START + 0x36)
#define VAR_DAILY_WILDS                                  (SPECIAL_STATE_VARS_START + 0x37)
#define VAR_DAILY_BLENDER                                (SPECIAL_STATE_VARS_START + 0x38)
#define VAR_DAILY_PLANTED_BERRIES                        (SPECIAL_STATE_VARS_START + 0x39)
#define VAR_DAILY_PICKED_BERRIES                         (SPECIAL_STATE_VARS_START + 0x3A)
#define VAR_DAILY_ROULETTE                               (SPECIAL_STATE_VARS_START + 0x3B)
#define VAR_SECRET_BASE_STEP_COUNTER                     (SPECIAL_STATE_VARS_START + 0x3C) // Used by Secret Base TV programs
#define VAR_SECRET_BASE_LAST_ITEM_USED                   (SPECIAL_STATE_VARS_START + 0x3D) // Used by Secret Base TV programs
#define VAR_SECRET_BASE_LOW_TV_FLAGS                     (SPECIAL_STATE_VARS_START + 0x3E) // Used by Secret Base TV programs
#define VAR_SECRET_BASE_HIGH_TV_FLAGS                    (SPECIAL_STATE_VARS_START + 0x3F) // Used by Secret Base TV programs
#define VAR_SECRET_BASE_IS_NOT_LOCAL                     (SPECIAL_STATE_VARS_START + 0x40) // Set to TRUE while in another player's secret base.
#define VAR_DAILY_BP                                     (SPECIAL_STATE_VARS_START + 0x41)
#define VAR_WALLY_CALL_STEP_COUNTER                      (SPECIAL_STATE_VARS_START + 0x42)
#define VAR_SCOTT_FORTREE_CALL_STEP_COUNTER              (SPECIAL_STATE_VARS_START + 0x43)
#define VAR_ROXANNE_CALL_STEP_COUNTER                    (SPECIAL_STATE_VARS_START + 0x44)
#define VAR_SCOTT_BF_CALL_STEP_COUNTER                   (SPECIAL_STATE_VARS_START + 0x45)
#define VAR_RIVAL_RAYQUAZA_CALL_STEP_COUNTER             (SPECIAL_STATE_VARS_START + 0x46)
#define VAR_SECRET_BASE_INITIALIZED                      (SPECIAL_STATE_VARS_START + 0x47)
#define VAR_CURRENT_SECRET_BASE                          (SPECIAL_STATE_VARS_START + 0x48)
#define VAR_UNUSED_0x40F9                                (SPECIAL_STATE_VARS_START + 0x49) // Unused Var
#define VAR_UNUSED_0x40FA                                (SPECIAL_STATE_VARS_START + 0x4A) // Unused Var
#define VAR_UNUSED_0x40FB                                (SPECIAL_STATE_VARS_START + 0x4B) // Unused Var
#define VAR_UNUSED_0x40FC                                (SPECIAL_STATE_VARS_START + 0x4C) // Unused Var
#define VAR_UNUSED_0x40FD                                (SPECIAL_STATE_VARS_START + 0x4D) // Unused Var
#define VAR_UNUSED_0x40FE                                (SPECIAL_STATE_VARS_START + 0x4E) // Unused Var
#define VAR_UNUSED_0x40FF                                (SPECIAL_STATE_VARS_START + 0x4F) // Unused Var
#define VAR_ROUTE117_STATE                               (SPECIAL_STATE_VARS_START + 0x50)  // Unused Var
#define VAR_ROUTE118_STATE                               (SPECIAL_STATE_VARS_START + 0x51) 
#define VAR_ROUTE119_STATE                               (SPECIAL_STATE_VARS_START + 0x52) 
#define VAR_ROUTE120_STATE                               (SPECIAL_STATE_VARS_START + 0x53)  // Unused Var
#define VAR_ROUTE121_STATE                               (SPECIAL_STATE_VARS_START + 0x54) 
#define VAR_ROUTE122_STATE                               (SPECIAL_STATE_VARS_START + 0x55)  // Unused Var
#define VAR_ROUTE123_STATE                               (SPECIAL_STATE_VARS_START + 0x56)  // Unused Var
#define VAR_ROUTE124_STATE                               (SPECIAL_STATE_VARS_START + 0x57) // Unused Var
#define VAR_ROUTE125_STATE                               (SPECIAL_STATE_VARS_START + 0x58) // Unused Var
#define VAR_ROUTE126_STATE                               (SPECIAL_STATE_VARS_START + 0x59)  // Unused Var
#define VAR_ROUTE127_STATE                               (SPECIAL_STATE_VARS_START + 0x5A) // Unused Var
#define VAR_ROUTE128_STATE                               (SPECIAL_STATE_VARS_START + 0x5B) 
#define VAR_ROUTE129_STATE                               (SPECIAL_STATE_VARS_START + 0x5C)  // Unused Var
#define VAR_ROUTE130_STATE                               (SPECIAL_STATE_VARS_START + 0x5D) // Unused Var
#define VAR_ROUTE131_STATE                               (SPECIAL_STATE_VARS_START + 0x5E) // Unused Var
#define VAR_ROUTE132_STATE                               (SPECIAL_STATE_VARS_START + 0x5F)  // Unused Var
#define VAR_ROUTE133_STATE                               (SPECIAL_STATE_VARS_START + 0x60) // Unused Var
#define VAR_ROUTE134_STATE                               (SPECIAL_STATE_VARS_START + 0x61) // Unused Var
#define VAR_LITTLEROOT_HOUSES_STATE_MAY                  (SPECIAL_STATE_VARS_START + 0x62)
#define VAR_UNUSED_0x4083                                (SPECIAL_STATE_VARS_START + 0x63) // Unused Var
#define VAR_BIRCH_LAB_STATE                              (SPECIAL_STATE_VARS_START + 0x64)
#define VAR_PETALBURG_GYM_STATE                          (SPECIAL_STATE_VARS_START + 0x65) // 0-1: Wally tutorial, 2-6: 0-4 badges, 7: Defeated Norman, 8: Rematch Norman 
#define VAR_0x4086                                       (SPECIAL_STATE_VARS_START + 0x66)
#define VAR_0x4087                                       (SPECIAL_STATE_VARS_START + 0x67)
#define VAR_CONTEST_TYPE                                 (SPECIAL_STATE_VARS_START + 0x68)
#define VAR_0x4089                                       (SPECIAL_STATE_VARS_START + 0x69)
#define VAR_CONTEST_PRIZE_PICKUP                         (SPECIAL_STATE_VARS_START + 0x6A)
#define VAR_UNUSED_0x408B                                (SPECIAL_STATE_VARS_START + 0x6B) // Unused Var
#define VAR_LITTLEROOT_HOUSES_STATE_BRENDAN              (SPECIAL_STATE_VARS_START + 0x6C)
#define VAR_LITTLEROOT_RIVAL_STATE                       (SPECIAL_STATE_VARS_START + 0x6D)
#define VAR_BOARD_BRINEY_BOAT_STATE                      (SPECIAL_STATE_VARS_START + 0x6E)
#define VAR_DEVON_CORP_3F_STATE                          (SPECIAL_STATE_VARS_START + 0x6F)
#define VAR_BRINEY_HOUSE_STATE                           (SPECIAL_STATE_VARS_START + 0x70)
#define VAR_UNUSED_0x4091                                (SPECIAL_STATE_VARS_START + 0x71) // Unused Var
#define VAR_LITTLEROOT_INTRO_STATE                       (SPECIAL_STATE_VARS_START + 0x72)
#define VAR_MAUVILLE_GYM_STATE                           (SPECIAL_STATE_VARS_START + 0x73)
#define VAR_LILYCOVE_MUSEUM_2F_STATE                     (SPECIAL_STATE_VARS_START + 0x74)
#define VAR_LILYCOVE_FAN_CLUB_STATE                      (SPECIAL_STATE_VARS_START + 0x75)
#define VAR_BRINEY_LOCATION                              (SPECIAL_STATE_VARS_START + 0x76)
#define VAR_INIT_SECRET_BASE                             (SPECIAL_STATE_VARS_START + 0x77)
#define VAR_PETALBURG_WOODS_STATE                        (SPECIAL_STATE_VARS_START + 0x78)
#define VAR_LILYCOVE_CONTEST_LOBBY_STATE                 (SPECIAL_STATE_VARS_START + 0x79)
#define VAR_RUSTURF_TUNNEL_STATE                         (SPECIAL_STATE_VARS_START + 0x7A)
#define VAR_UNUSED_0x409B                                (SPECIAL_STATE_VARS_START + 0x7B) // Unused Var
#define VAR_ELITE_4_STATE                                (SPECIAL_STATE_VARS_START + 0x7C)
#define VAR_UNUSED_0x409D                                (SPECIAL_STATE_VARS_START + 0x7D) // Unused Var
#define VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE      (SPECIAL_STATE_VARS_START + 0x7E)
#define VAR_MOSSDEEP_SPACE_CENTER_STATE                  (SPECIAL_STATE_VARS_START + 0x7F)
#define VAR_SLATEPORT_HARBOR_STATE                       (SPECIAL_STATE_VARS_START + 0x80)
#define VAR_UNUSED_0x40A1                                (SPECIAL_STATE_VARS_START + 0x81) // Unused var
#define VAR_SEAFLOOR_CAVERN_STATE                        (SPECIAL_STATE_VARS_START + 0x82)
#define VAR_CABLE_CAR_STATION_STATE                      (SPECIAL_STATE_VARS_START + 0x83)
#define VAR_SAFARI_ZONE_STATE                            (SPECIAL_STATE_VARS_START + 0x84)  // 0: In or out of SZ, 1: Player exiting SZ, 2: Player entering SZ
#define VAR_TRICK_HOUSE_BEING_WATCHED_STATE              (SPECIAL_STATE_VARS_START + 0x85)
#define VAR_TRICK_HOUSE_FOUND_TRICK_MASTER               (SPECIAL_STATE_VARS_START + 0x86)
#define VAR_TRICK_HOUSE_ENTRANCE_STATE                   (SPECIAL_STATE_VARS_START + 0x87)
#define VAR_UNUSED_0x40A8                                (SPECIAL_STATE_VARS_START + 0x88) // Unused Var
#define VAR_CYCLING_CHALLENGE_STATE                      (SPECIAL_STATE_VARS_START + 0x89)
#define VAR_SLATEPORT_MUSEUM_1F_STATE                    (SPECIAL_STATE_VARS_START + 0x8A)
#define VAR_TRICK_HOUSE_PUZZLE_1_STATE                   (SPECIAL_STATE_VARS_START + 0x8B)
#define VAR_TRICK_HOUSE_PUZZLE_2_STATE                   (SPECIAL_STATE_VARS_START + 0x8C)
#define VAR_TRICK_HOUSE_PUZZLE_3_STATE                   (SPECIAL_STATE_VARS_START + 0x8D)
#define VAR_0x40AE                                       (SPECIAL_STATE_VARS_START + 0x8E)
#define VAR_TRICK_HOUSE_PUZZLE_5_STATE                   (SPECIAL_STATE_VARS_START + 0x8F)
#define SPECIAL_STATE_VARS_END                             VAR_TRICK_HOUSE_PUZZLE_5_STATE

#define VARS_END                                         0x41FF
#define VARS_COUNT                                       (VARS_END - VARS_START + 1)

// special vars
// They are commonly used as parameters to commands, or return values from commands.
#define SPECIAL_VARS_START                               0x8000
#define VAR_0x8000                                       0x8000
#define VAR_0x8001                                       0x8001
#define VAR_0x8002                                       0x8002
#define VAR_0x8003                                       0x8003
#define VAR_0x8004                                       0x8004
#define VAR_0x8005                                       0x8005
#define VAR_0x8006                                       0x8006
#define VAR_0x8007                                       0x8007
#define VAR_0x8008                                       0x8008
#define VAR_0x8009                                       0x8009
#define VAR_0x800A                                       0x800A
#define VAR_0x800B                                       0x800B
#define VAR_FACING                                       0x800C
#define VAR_RESULT                                       0x800D
#define VAR_ITEM_ID                                      0x800E
#define VAR_LAST_TALKED                                  0x800F
#define VAR_CONTEST_RANK                                 0x8010
#define VAR_CONTEST_CATEGORY                             0x8011
#define VAR_MON_BOX_ID                                   0x8012
#define VAR_MON_BOX_POS                                  0x8013
#define VAR_UNUSED_0x8014                                0x8014
#define VAR_TRAINER_BATTLE_OPPONENT_A                    0x8015 // Alias of gTrainerBattleOpponent_A
#define SPECIAL_VARS_END                                 0x8015

#endif // GUARD_CONSTANTS_VARS_H
