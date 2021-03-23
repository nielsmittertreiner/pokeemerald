MurenaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MurenaCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MurenaCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_MURENA_CITY_STATE, 1
	goto_if_lt MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setrespawn HEAL_LOCATION_MURENA_CITY
	setflag FLAG_VISITED_MURENA_CITY
	call FishermanFerry_EventScript_UpdateFerryLocation
	return

MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setobjectxyperm 12, 41, 20
	goto MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

MurenaCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_FISHERMAN_FERRY_STATE, 1, MurenaCity_EventScript_SetUpSailing
	.2byte 0

MurenaCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FISHERMAN_FERRY_STATE, 2, MurenaCity_EventScript_SailToLitor
	.2byte 0


MurenaCity_EventScript_SetUpSailing::
	setvar VAR_FISHERMAN_FERRY_STATE, 2
	setflag FLAG_DONT_TRANSITION_MUSIC
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_MURENA_CITY
	return


MurenaCity_EventScript_SailToLitor::
	setvar VAR_FISHERMAN_FERRY_STATE, 0
	playbgm MUS_SAILING, 0
	applymovement OBJ_EVENT_ID_PLAYER, MurenaCity_Movement_SailToLitor
	applymovement 10, MurenaCity_Movement_SailToLitor
	waitmovement 0
	clearflag FLAG_DONT_TRANSITION_MUSIC
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, MurenaCity_Movement_ExitBoatLitorTown
	waitmovement 0
	setobjectxyperm 2, 34, 22
	addobject 2
	setobjectpriority 2, MAP_LITOR_TOWN, 0
	applymovement 2, Common_Movement_WalkLeft
	waitmovement 0
	clearflag FLAG_HIDE_LITOR_TOWN_FISHERMAN
	addobject 1
	setobjectpriority 1, MAP_LITOR_TOWN, 1
	clearflag FLAG_HIDE_LITOR_TOWN_BOAT
	setflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
	setflag FLAG_HIDE_MURENA_CITY_BOAT
	setflag FLAG_HIDE_NAVIRE_TOWN_BOAT
	hideobjectat 10, MAP_MURENA_CITY
	hideobjectat 1, MAP_MURENA_CITY_SHIPYARD
	hideobjectat 1, MAP_NAVIRE_TOWN
	load_speech_bubble 2
	msgbox MurenaCity_EventScript_SailToLitor_Text_0
	destroy_speech_bubble
	closemessage
	resetobjectpriority OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
	resetobjectpriority 2, MAP_LITOR_TOWN
	copyobjectxytoperm 2
	call FishermanFerry_EventScript_RestoreFerryLocation
	release
	end


MurenaCity_EventScript_TeamAirlockEncounter::
	playbgm MUS_ENCOUNTER_AQUA, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	load_speech_bubble 20
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_0
	destroy_speech_bubble
	closemessage
	load_speech_bubble 18
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_1
	destroy_speech_bubble
	closemessage
	applymovement 19, MurenaCity_Movement_Grunt2PunchFisherman
	waitmovement 0
	playse SE_M_COMET_PUNCH
	waitse
	applymovement 20, MurenaCity_Movement_FishermanStrugglesBack
	waitmovement 0
	delay 24
	playse SE_PIN
	applymovement 20, Common_Movement_ExclamationMark
	waitmovement 0
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 28
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_2
	compare VAR_TEMP_1, 29
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_3
MurenaCity_EventScript_TeamAirlockEncounter_1:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	load_speech_bubble 20
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_2
	destroy_speech_bubble
	closemessage
	compare VAR_TEMP_1, 28
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_7
	compare VAR_TEMP_1, 29
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_8
MurenaCity_EventScript_TeamAirlockEncounter_6:
	applymovement 18, Common_Movement_FaceRight
	waitmovement 0
	load_speech_bubble 18
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_3
	destroy_speech_bubble
	closemessage
	trainerbattle_no_intro TRAINER_MURENA_CITY_GRUNT, MurenaCity_Text_GruntDefeat
	load_speech_bubble 18
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_4
	destroy_speech_bubble
	closemessage
	fadedefaultbgm
	applymovement 18, MurenaCity_Movement_Grunt1RunAway
	applymovement 19, MurenaCity_Movement_Grunt2RunAway
	waitmovement 0
	removeobject 18
	removeobject 19
	compare VAR_TEMP_1, 28
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_12
	compare VAR_TEMP_1, 29
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_13
MurenaCity_EventScript_TeamAirlockEncounter_11:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	load_speech_bubble 20
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_5
	destroy_speech_bubble
	closemessage
	applymovement 20, MurenaCity_Movement_FishermanWalkToShipyard
	waitmovement 0
	playse SE_EXIT
	removeobject 20
	setvar VAR_MURENA_CITY_STATE, 1
	end

MurenaCity_EventScript_TeamAirlockEncounter_2:
	applymovement 20, MurenaCity_Movement_FishermanRunToPlayer1
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_1

MurenaCity_EventScript_TeamAirlockEncounter_3:
	applymovement 20, MurenaCity_Movement_FishermanRunToPlayer2
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_1

MurenaCity_EventScript_TeamAirlockEncounter_7:
	applymovement OBJ_EVENT_ID_PLAYER, MurenaCity_Movement_PlayerWalkToGrunt
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_6

MurenaCity_EventScript_TeamAirlockEncounter_8:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_6

MurenaCity_EventScript_TeamAirlockEncounter_12:
	applymovement 20, MurenaCity_Movement_FishermanWalkToPlayer1
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_11

MurenaCity_EventScript_TeamAirlockEncounter_13:
	applymovement 20, MurenaCity_Movement_FishermanWalkToPlayer2
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_11


MurenaCity_EventScript_ArtistTrader::
	lock
	faceplayer
	goto_if_set FLAG_MURENA_NPC_TRADE_COMPLETED, MurenaCity_EventScript_ArtistTrader_2
	setvar VAR_0x8008, INGAME_TRADE_SMEARGLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	load_speech_bubble 9
	msgbox MurenaCity_EventScript_ArtistTrader_Text_1, MSGBOX_YESNO
	destroy_speech_bubble
	closemessage
	compare VAR_RESULT, NO
	goto_if_eq MurenaCity_EventScript_ArtistTrader_5
MurenaCity_EventScript_ArtistTrader_4:
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq MurenaCity_EventScript_ArtistTrader_8
MurenaCity_EventScript_ArtistTrader_7:
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne MurenaCity_EventScript_ArtistTrader_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	load_speech_bubble 9
	msgbox MurenaCity_EventScript_ArtistTrader_Text_2
	destroy_speech_bubble
	closemessage
	setflag FLAG_MURENA_NPC_TRADE_COMPLETED
	release
	end

MurenaCity_EventScript_ArtistTrader_2:
	msgbox MurenaCity_EventScript_ArtistTrader_Text_0, MSGBOX_NPC
	end

MurenaCity_EventScript_ArtistTrader_5:
	goto MurenaCity_EventScript_ArtistTrader_Decline
	goto MurenaCity_EventScript_ArtistTrader_4

MurenaCity_EventScript_ArtistTrader_8:
	goto MurenaCity_EventScript_ArtistTrader_Decline
	goto MurenaCity_EventScript_ArtistTrader_7


MurenaCity_EventScript_ArtistTrader_Decline::
	load_speech_bubble 9
	msgbox MurenaCity_EventScript_ArtistTrader_Decline_Text_0
	destroy_speech_bubble
	closemessage
	release
	end


MurenaCity_EventScript_ArtistTrader_NotRequestedMon::
	msgbox MurenaCity_EventScript_ArtistTrader_NotRequestedMon_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_FeebasSeller::
	lock
	faceplayer
	goto_if_set FLAG_MURENA_BOUGHT_FEEBAS, MurenaCity_EventScript_FeebasSeller_2
	load_speech_bubble 4
	msgbox MurenaCity_EventScript_FeebasSeller_Text_1
	destroy_speech_bubble
	closemessage
	showmoneybox 0, 0, 0
	load_speech_bubble 4
	msgbox MurenaCity_EventScript_FeebasSeller_Text_2, MSGBOX_YESNO
	destroy_speech_bubble
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq MurenaCity_EventScript_FeebasSeller_5
	hidemoneybox
	load_speech_bubble 4
	msgbox MurenaCity_EventScript_FeebasSeller_Text_5
	destroy_speech_bubble
	closemessage
MurenaCity_EventScript_FeebasSeller_4:
	release
	end

MurenaCity_EventScript_FeebasSeller_2:
	load_speech_bubble 4
	msgbox MurenaCity_EventScript_FeebasSeller_Text_0
	destroy_speech_bubble
	closemessage
	release
	end

MurenaCity_EventScript_FeebasSeller_5:
	checkmoney 500, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MurenaCity_EventScript_FeebasSeller_9
	delay 10
	playse SE_SHOP
	removemoney 500, 0
	updatemoneybox 0, 0
	delay 30
	hidemoneybox
	givemon SPECIES_FEEBAS, 5, ITEM_NONE
	load_speech_bubble 4
	msgbox MurenaCity_EventScript_FeebasSeller_Text_4
	setflag FLAG_MURENA_BOUGHT_FEEBAS
	destroy_speech_bubble
	closemessage
	goto MurenaCity_EventScript_FeebasSeller_4

MurenaCity_EventScript_FeebasSeller_9:
	load_speech_bubble 4
	msgbox MurenaCity_EventScript_FeebasSeller_Text_3
	destroy_speech_bubble
	closemessage
	release
	end


MurenaCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_MURENA_SHOWN_RELICANTH, MurenaCity_EventScript_OldMan_2
	load_speech_bubble 15
	msgbox MurenaCity_EventScript_OldMan_Text_1
	destroy_speech_bubble
	closemessage
	delay 30
	specialvar VAR_RESULT, CheckMurenaCityRelicanth
	compare VAR_RESULT, TRUE
	goto_if_eq MurenaCity_EventScript_OldMan_5
	load_speech_bubble 15
	msgbox MurenaCity_EventScript_OldMan_Text_4
	destroy_speech_bubble
	closemessage
MurenaCity_EventScript_OldMan_4:
	release
	end

MurenaCity_EventScript_OldMan_2:
	load_speech_bubble 15
	msgbox MurenaCity_EventScript_OldMan_Text_0
	destroy_speech_bubble
	closemessage
	release
	end

MurenaCity_EventScript_OldMan_5:
	playse SE_PIN
	applymovement 15, Common_Movement_ExclamationMark
	waitmovement 0
	load_speech_bubble 15
	msgbox MurenaCity_EventScript_OldMan_Text_2
	destroy_speech_bubble
	closemessage
	showmoneybox 0, 0, 0
	delay 30
	playse SE_SHOP
	addmoney 25000, 0
	updatemoneybox 0, 0
	delay 30
	hidemoneybox
	load_speech_bubble 15
	msgbox MurenaCity_EventScript_OldMan_Text_3
	setflag FLAG_MURENA_SHOWN_RELICANTH
	destroy_speech_bubble
	closemessage
	goto MurenaCity_EventScript_OldMan_4


MurenaCity_EventScript_Wingull::
	lock
	playmoncry SPECIES_WINGULL, 0
	waitmoncry
	release
	end


MurenaCity_EventScript_MarketSalesWoman::
	giveitem ITEM_TENTACOOL_SKEWER, 1
	end


MurenaCity_EventScript_MarketSalesMan::
	msgbox MurenaCity_EventScript_MarketSalesMan_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_RichBoy::
	msgbox MurenaCity_EventScript_RichBoy_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_Sailor1::
	msgbox MurenaCity_EventScript_Sailor1_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_Sailor2::
	msgbox MurenaCity_EventScript_Sailor2_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_Sailor3::
	msgbox MurenaCity_EventScript_Sailor3_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_BugCatcher::
	msgbox MurenaCity_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_Woman::
	return


MurenaCity_EventScript_OldWoman::
	msgbox MurenaCity_EventScript_OldWoman_Text_0, MSGBOX_NPC
	delay 60
	msgbox MurenaCity_EventScript_OldWoman_Text_1
	delay 24
	msgbox MurenaCity_EventScript_OldWoman_Text_2, MSGBOX_NPC
	playse SE_PIN
	applymovement 12, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox MurenaCity_EventScript_OldWoman_Text_3, MSGBOX_NPC
	end


MurenaCity_EventScript_Fisherman::
	msgbox MurenaCity_EventScript_Fisherman_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_LittleGirl::
	msgbox MurenaCity_EventScript_LittleGirl_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_CitySign::
	msgbox MurenaCity_EventScript_CitySign_Text_0, MSGBOX_SIGN
	end


MurenaCity_EventScript_FishMarketSign::
	msgbox MurenaCity_EventScript_FishMarketSign_Text_0, MSGBOX_SIGN
	end


MurenaCity_EventScript_DockyardSign::
	msgbox MurenaCity_EventScript_DockyardSign_Text_0, MSGBOX_SIGN
	end


MurenaCity_EventScript_WailordFishingClubSign::
	msgbox MurenaCity_EventScript_WailordFishingClubSign_Text_0, MSGBOX_SIGN
	end


MurenaCity_Movement_Grunt2PunchFisherman:
	lock_facing_direction
	walk_slow_up
	unlock_facing_direction
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_fast_down
	step_end

MurenaCity_Movement_FishermanStrugglesBack:
	walk_in_place_fastest_up
	walk_in_place_fastest_up
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	step_end

MurenaCity_Movement_FishermanRunToPlayer1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_up
	face_left
	step_end

MurenaCity_Movement_FishermanRunToPlayer2:
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_down
	face_left
	step_end

MurenaCity_Movement_PlayerWalkToGrunt:
	walk_left
	walk_down
	face_left
	step_end

MurenaCity_Movement_Grunt1RunAway:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MurenaCity_Movement_Grunt2RunAway:
	delay_16
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MurenaCity_Movement_FishermanWalkToPlayer1:
	walk_left
	walk_left
	face_down
	step_end

MurenaCity_Movement_FishermanWalkToPlayer2:
	walk_left
	walk_up
	walk_left
	face_down
	step_end

MurenaCity_Movement_FishermanWalkToShipyard:
	walk_left
	walk_left
	walk_up
	step_end

MurenaCity_Movement_SailToLitor:
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_up
	walk_fast_up
	walk_up
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_up
	face_down
	step_end

MurenaCity_Movement_ExitBoatLitorTown:
	walk_left
	walk_left
	face_right
	step_end

MurenaCity_EventScript_SailToLitor_Text_0:
	.string "Ahoy! We've arrived at LITOR TOWN!\n"
	.string "You can smell the salty sea here too.$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_0:
	.string "Hey!\n"
	.string "Let me through!\p"
	.string "I've got to get an important TENTACOOL\n"
	.string "haul for the MARKET tomorrow!$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_1:
	.string "Do not resist!\p"
	.string "We are impounding your boat for\n"
	.string "the greater good!$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_2:
	.string "Hey kiddo, ya gotta help me out here!\p"
	.string "Those thugs are trying to\n"
	.string "steal my ship!\p"
	.string "Please do something!$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_3:
	.string "So what are you gonna do?!\n"
	.string "Save him?\p"
	.string "Hahaha!\n"
	.string "I don't think so kid!\p"
	.string "You can't take the wind\n"
	.string "out of our sails!$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_4:
	.string "Oh no!\n"
	.string "You're stronger than I thought!\p"
	.string "Quickly!\n"
	.string "Let's get out of here!$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_5:
	.string "Phew… Thank you.\p"
	.string "I don't know what I would've done\n"
	.string "without you…\p"
	.string "Y'know what, as a reward, I'll ferry you\n"
	.string "across the straits free of charge!\p"
	.string "I'll be right here in the SHIPYARD if\n"
	.string "you need me.$"

MurenaCity_EventScript_ArtistTrader_Text_0:
	.string "Jusqu'ici I am able to understand\n"
	.string "the ocean blue.$"

MurenaCity_EventScript_ArtistTrader_Text_1:
	.string "The ocean is a canvas…\p"
	.string "But to truly blend into it,\n"
	.string "that deep dark blue…\p"
	.string "Only one POKéMON knows the art…\n"
	.string "Can you bring me one.\p"
	.string "If you can find me a KECLEON,\n"
	.string "I will give you my SMEARGLE…$"

MurenaCity_EventScript_ArtistTrader_Text_2:
	.string "Magnificent…\n"
	.string "Such color I have never seen.$"

MurenaCity_EventScript_ArtistTrader_Decline_Text_0:
	.string "I see…\p"
	.string "I guess true culture is hard to\n"
	.string "come by in these parts…$"

MurenaCity_EventScript_ArtistTrader_NotRequestedMon_Text_0:
	.string "What?! I was offering you a\n"
	.string "SMEARGLE, not a pair of glasses!$"

MurenaCity_EventScript_FeebasSeller_Text_0:
	.string "SORRY KIDDO, I AIN'T GOT\n"
	.string "ANY MORE FISHES!$"

MurenaCity_EventScript_FeebasSeller_Text_1:
	.string "HEY KID!\n"
	.string "WANNA BUY THIS MAGIKARP?!\p"
	.string "IT'S KINDA UGLY, SO IT'S\n"
	.string "ONLY ¥500!$"

MurenaCity_EventScript_FeebasSeller_Text_2:
	.string "WHADDYA SAY?\n"
	.string "¥500 AIN'T MUCH!$"

MurenaCity_EventScript_FeebasSeller_Text_3:
	.string "NO NO NO, THAT WON'T DO!$"

MurenaCity_EventScript_FeebasSeller_Text_4:
	.string "HERE YA GO KIDDO!$"

MurenaCity_EventScript_FeebasSeller_Text_5:
	.string "IF YA DON'T APPRECIATE THE UGLY,\n"
	.string "YA DON'T DESERVE THE BEAUTIFUL!$"

MurenaCity_EventScript_OldMan_Text_0:
	.string "Thank you friend, for showing me\n"
	.string "the true beauty of a RELICANTH.\p"
	.string "Perhaps once I will catch one of\n"
	.string "my very own…$"

MurenaCity_EventScript_OldMan_Text_1:
	.string "I am looking for a creature…\n"
	.string "Ancient in age.\l"
	.string "Aquatic in nature.\p"
	.string "Bring my aquatic anomaly…\n"
	.string "For you shall be rewarded handsomely.$"

MurenaCity_EventScript_OldMan_Text_2:
	.string "Oh yes…\n"
	.string "It surpasses even the wildest\l"
	.string "of imaginations…\p"
	.string "Here you are… your reward.\n"
	.string "That will come down to ¥25000$"

MurenaCity_EventScript_OldMan_Text_3:
	.string "Spend it wisely…\p"
	.string "Thanks again, good friend…$"

MurenaCity_EventScript_OldMan_Text_4:
	.string "I see…\p"
	.string "What I'm looking for you do\n"
	.string "not possess…\p"
	.string "If you could find it for me…\n"
	.string "I shall be very grateful…$"

MurenaCity_EventScript_MarketSalesMan_Text_0:
	.string "If I sell anything?\n"
	.string "No no, talk to my wife for that.\l"
	.string "I just wanna grill for pete's sake.$"

MurenaCity_EventScript_RichBoy_Text_0:
	.string "Tssk…\p"
	.string "You may've beat me at FIRWEALD,\n"
	.string "but once my daddy's boat arrives\l"
	.string "I'll show you who's boss.$"

MurenaCity_EventScript_Sailor1_Text_0:
	.string "The breeze here is so nice.\n"
	.string "There truly is no place like MURENA.$"

MurenaCity_EventScript_Sailor2_Text_0:
	.string "A WINGULL just took my fry…\p"
	.string "Why do we keep these pests\n"
	.string "around anyway?$"

MurenaCity_EventScript_Sailor3_Text_0:
	.string "You should try a TENTACOOL skewer!\n"
	.string "They truly do taste like heaven!$"

MurenaCity_EventScript_BugCatcher_Text_0:
	.string "I wonder what BUG-types live\n"
	.string "across the EURUS region.$"

MurenaCity_EventScript_OldWoman_Text_0:
	.string "Oh, how it's changed here.\n"
	.string "See, back in my day…$"

MurenaCity_EventScript_OldWoman_Text_1:
	.string "(As you snap back to your senses\n"
	.string "you realize you zoned out…)$"

MurenaCity_EventScript_OldWoman_Text_2:
	.string "And that's why you young\n"
	.string "whippasnappas…$"

MurenaCity_EventScript_OldWoman_Text_3:
	.string "Hey, are you even listening to me?$"

MurenaCity_EventScript_Fisherman_Text_0:
	.string "I'm warming up.\p"
	.string "It's cold out at sea y'know.$"

MurenaCity_EventScript_LittleGirl_Text_0:
	.string "When I grow up, I want to be\n"
	.string "a fisher. Just like daddy!$"

MurenaCity_EventScript_CitySign_Text_0:
	.string "MURENA CITY\n"
	.string "“Fishing hotspot turned shipping port.”$"

MurenaCity_EventScript_FishMarketSign_Text_0:
	.string "MURENA FISHING MARKET\n"
	.string "“Get yer fish 'ere!”$"

MurenaCity_EventScript_DockyardSign_Text_0:
	.string "MURENA DOCKYARD$"

MurenaCity_EventScript_WailordFishingClubSign_Text_0:
	.string "WAILORD FISHING CLUB\n"
	.string "“In search of the oceanic giant!”$"

MurenaCity_Text_GruntDefeat::
	.string "Well that backfired…$"
