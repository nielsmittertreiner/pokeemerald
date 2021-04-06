CedarredTown_LoggersCabin_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_CEDARRED_TOWN_STATE, 2, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_LoggersCabin_Movement_PlayerWalkIn
	applymovement OBJ_EVENT_ID_FOLLOWER, CedarredTown_LoggersCabin_Movement_ConiferWalkIn
	waitmovement 0
	playse SE_PIN
	applymovement 1, CedarredTown_LoggersCabin_Movement_LoggerManOneReaction
	applymovement 2, Common_Movement_WalkInPlaceFastestDown
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
	playse SE_PIN
	applymovement 9, CedarredTown_LoggersCabin_Movement_LoggerManFourReaction
	playse SE_PIN
	applymovement 3, CedarredTown_LoggersCabin_Movement_LoggerWomanOneReaction
	playse SE_PIN
	applymovement 5, CedarredTown_LoggersCabin_Movement_LoggerWomanTwoReaction
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	applymovement 8, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 48
	playse SE_PIN
	applymovement 4, CedarredTown_LoggersCabin_Movement_LoggerQuestMasterNoticePlayer
	waitmovement 0
	load_speech_bubble 4
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	destroy_speech_bubble
	closemessage
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	delay 8
	turnobject 2, DIR_EAST
	load_speech_bubble 2
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
	destroy_speech_bubble
	closemessage
	turnobject 4, DIR_WEST
	load_speech_bubble 4
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2
	destroy_speech_bubble
	closemessage
	load_speech_bubble 2
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3
	destroy_speech_bubble
	closemessage
	playse SE_BIKE_HOP
	applymovement 2, CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToCupboard
	waitmovement 0
	delay 48
	applymovement 2, CedarredTown_LoggersCabin_Movement_LoggerManTwoGetBallsFromCupboard
	waitmovement 0
	delay 16
	playse SE_BIKE_HOP
	applymovement 2, CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToSeat
	waitmovement 0
	playse SE_BIKE_HOP
	applymovement 2, CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToLeader
	waitmovement 0
	load_speech_bubble 4
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4
	destroy_speech_bubble
	closemessage
	turnobject 4, DIR_SOUTH
	random 3
	load_speech_bubble 4
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5
	destroy_speech_bubble
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6
	closemessage
	switch VAR_RESULT
	case 0, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_3
	case 1, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_4
	case 2, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_5
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	playfanfare MUS_OBTAIN_ITEM
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_17
	waitfanfare
	closemessage
	hidemonpic
	fadescreen FADE_FROM_BLACK
	load_speech_bubble 4
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_18, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_8
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_9
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_6:
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ExclamationMark
	waitmovement 0
	load_speech_bubble OBJ_EVENT_ID_FOLLOWER
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_21
	destroy_speech_bubble
	closemessage
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	load_speech_bubble OBJ_EVENT_ID_FOLLOWER
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_22
	destroy_speech_bubble
	closemessage
	applymovement OBJ_EVENT_ID_FOLLOWER, CedarredTown_LoggersCabin_Movement_ConiferWalkOut
	waitmovement 0
	playse SE_EXIT
	removeobject OBJ_EVENT_ID_FOLLOWER, MAP_CEDARRED_TOWN_LOGGERS_CABIN
	destroyfollower
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_LoggersCabin_Movement_PlayerWalkInFrontOfLeader
	waitmovement 0
	load_speech_bubble 4
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_23
	destroy_speech_bubble
	closemessage
	clearflag FLAG_HIDE_SUNSET_TOWN_LAB_PROF_CONIFER
	clearflag FLAG_DISABLE_ENCOUNTERS
	setvar VAR_CEDARRED_TOWN_STATE, 3
	release
	end

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_3:
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_11:
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7
	multichoice 10, 4, MULTI_CEDARRED_CHOOSE_STARTER_SET_ONE, 1
	switch VAR_RESULT
	case 0, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_21
	case 1, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_22
	case 2, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_23
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19:
	setvar VAR_TEMP_0, 0
	goto_if_unset FLAG_SYS_POKEMON_GET, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_11
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_4:
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_14:
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7
	multichoice 10, 4, MULTI_CEDARRED_CHOOSE_STARTER_SET_TWO, 1
	switch VAR_RESULT
	case 0, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_26
	case 1, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_27
	case 2, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_28
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24:
	setvar VAR_TEMP_0, 1
	goto_if_unset FLAG_SYS_POKEMON_GET, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_14
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_5:
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_17:
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7
	multichoice 10, 4, MULTI_CEDARRED_CHOOSE_STARTER_SET_THREE, 1
	switch VAR_RESULT
	case 0, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_31
	case 1, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_32
	case 2, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_33
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29:
	setvar VAR_TEMP_0, 2
	goto_if_unset FLAG_SYS_POKEMON_GET, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_17
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_8:
	destroy_speech_bubble
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	bufferpartymonnick 1, 0
	load_speech_bubble 4
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_19
	destroy_speech_bubble
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_6

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_9:
	destroy_speech_bubble
	load_speech_bubble 4
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_20
	destroy_speech_bubble
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_6

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_21:
	closemessage
	showmonpic SPECIES_BULBASAUR, 10, 3
	bufferspeciesname 0, SPECIES_BULBASAUR
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_8, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_35
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_36
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_22:
	closemessage
	showmonpic SPECIES_CHARMANDER, 10, 3
	bufferspeciesname 0, SPECIES_CHARMANDER
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_9, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_38
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_39
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_23:
	closemessage
	showmonpic SPECIES_SQUIRTLE, 10, 3
	bufferspeciesname 0, SPECIES_SQUIRTLE
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_10, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_41
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_42
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_26:
	closemessage
	showmonpic SPECIES_CHIKORITA, 10, 3
	bufferspeciesname 0, SPECIES_CHIKORITA
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_11, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_44
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_45
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_27:
	closemessage
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	bufferspeciesname 0, SPECIES_CYNDAQUIL
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_12, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_47
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_48
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_28:
	closemessage
	showmonpic SPECIES_TOTODILE, 10, 3
	bufferspeciesname 0, SPECIES_TOTODILE
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_13, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_50
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_51
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_31:
	closemessage
	showmonpic SPECIES_TREECKO, 10, 3
	bufferspeciesname 0, SPECIES_TREECKO
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_14, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_53
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_54
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_32:
	closemessage
	showmonpic SPECIES_TORCHIC, 10, 3
	bufferspeciesname 0, SPECIES_TORCHIC
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_15, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_56
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_57
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_33:
	closemessage
	showmonpic SPECIES_MUDKIP, 10, 3
	bufferspeciesname 0, SPECIES_MUDKIP
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_16, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_59
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_60
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_35:
	givemon SPECIES_BULBASAUR, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_36:
	hidemonpic
	destroy_speech_bubble
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_38:
	givemon SPECIES_CHARMANDER, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_39:
	hidemonpic
	destroy_speech_bubble
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_41:
	givemon SPECIES_SQUIRTLE, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_42:
	hidemonpic
	destroy_speech_bubble
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_44:
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_45:
	hidemonpic
	destroy_speech_bubble
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_47:
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_48:
	hidemonpic
	destroy_speech_bubble
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_50:
	givemon SPECIES_TOTODILE, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_51:
	hidemonpic
	destroy_speech_bubble
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_53:
	givemon SPECIES_TREECKO, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_54:
	hidemonpic
	destroy_speech_bubble
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_56:
	givemon SPECIES_TORCHIC, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_57:
	hidemonpic
	destroy_speech_bubble
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_59:
	givemon SPECIES_MUDKIP, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_60:
	hidemonpic
	destroy_speech_bubble
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29


CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster::
	compare VAR_ACREN_FOREST_STATE, 3
	goto_if_lt CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_3
	goto_if_set FLAG_BADGE03_GET, CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_8
CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_7:
	goto_if_set FLAG_BADGE03_GET, CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_6
	return

CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_3:
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_23, MSGBOX_NPC
	end

CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_5:
	return

CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_6:
	return

CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_8:
	goto_if_set FLAG_JOINED_LOGGERS_GUILD, CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_5
	goto CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_7


CedarredTown_LoggersCabin_EventScript_LoggerManOne::
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerManOne_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerManTwo::
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerManTwo_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerManThree::
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerManThree_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerManFour::
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerManFour_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerWomanOne::
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerWomanOne_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerWomanTwo::
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerWomanTwo_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerWomanThree::
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerWomanThree_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerWomanFour::
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerWomanFour_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_Movement_PlayerWalkIn:
	walk_up
	walk_up
	walk_left
	face_up
	step_end

CedarredTown_LoggersCabin_Movement_ConiferWalkIn:
	delay_16
	set_visible
	walk_up
	walk_up
	step_end

CedarredTown_LoggersCabin_Movement_LoggerManOneReaction:
	emote_exclamation_mark
	delay_4
	delay_4
	walk_in_place_fastest_left
	delay_4
	delay_4
	delay_4
	walk_in_place_fastest_right
	delay_4
	delay_4
	walk_in_place_fastest_down
	step_end

CedarredTown_LoggersCabin_Movement_LoggerManFourReaction:
	emote_exclamation_mark
	delay_4
	delay_4
	walk_in_place_fastest_down
	step_end

CedarredTown_LoggersCabin_Movement_LoggerWomanOneReaction:
	emote_exclamation_mark
	delay_4
	delay_4
	delay_4
	delay_4
	walk_in_place_fastest_down
	step_end

CedarredTown_LoggersCabin_Movement_LoggerWomanTwoReaction:
	emote_exclamation_mark
	delay_4
	walk_in_place_fastest_up
	delay_4
	walk_in_place_fastest_down
	step_end

CedarredTown_LoggersCabin_Movement_LoggerQuestMasterNoticePlayer:
	emote_exclamation_mark
	delay_4
	delay_4
	jump_in_place_down
	step_end

CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToCupboard:
	jump_in_place_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	face_up
	step_end

CedarredTown_LoggersCabin_Movement_LoggerManTwoGetBallsFromCupboard:
	walk_in_place_fast_up
	delay_4
	delay_4
	delay_4
	delay_4
	walk_in_place_fast_up
	delay_4
	delay_4
	delay_4
	delay_4
	walk_in_place_fast_up
	delay_4
	delay_4
	delay_4
	delay_4
	face_down
	step_end

CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToSeat:
	jump_in_place_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	face_right
	step_end

CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToLeader:
	jump_in_place_right
	walk_fast_right
	walk_fast_right
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

CedarredTown_LoggersCabin_Movement_ConiferWalkOut:
	walk_down
	walk_down
	step_end

CedarredTown_LoggersCabin_Movement_PlayerWalkInFrontOfLeader:
	walk_right
	face_up
	step_end

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "Ah, PROFESSOR CONIFER!\n"
	.string "We've been waiting for you.\p"
	.string "Hmmm, who's that you brought with you?\p"
	.string "Any extra help is always nice to have.\n"
	.string "Definitely with what we have going on\l"
	.string "in ACREN FOREST.$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "Sir!\p"
	.string "I have an idea on how the kid could\n"
	.string "help us, Sir!\p"
	.string "We could lend him one of our POKéMON.\n"
	.string "Sir!$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
	.string "Hmmm…\n"
	.string "One of our POKéMON you say…\p"
	.string "I think that's a great idea!\p"
	.string "Recruit, could you fetch me our\n"
	.string "POKéBALLS the kid can use?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
	.string "Yes, Sir!\p"
	.string "I'll get them right away!$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4:
	.string "Aha… I see, you chose these\n"
	.string "POKéMON for the kid.\p"
	.string "These POKéMON should do well.$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5:
	.string "Now…\n"
	.string "Close your eyes…$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6:
	.string "Follow your heart now…$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7:
	.string "Which POKéMON will you choose?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_8:
	.string "Will you choose {STR_VAR_1},\n"
	.string "The SEED POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_9:
	.string "Will you choose {STR_VAR_1},\n"
	.string "The LIZARD POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_10:
	.string "Will you choose {STR_VAR_1},\n"
	.string "The TINY TURTLE POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_11:
	.string "Will you choose {STR_VAR_1},\n"
	.string "The LEAF POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_12:
	.string "Will you choose {STR_VAR_1},\n"
	.string "The FIRE MOUSE POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_13:
	.string "Will you choose {STR_VAR_1},\n"
	.string "The BIG JAW POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_14:
	.string "Will you choose {STR_VAR_1},\n"
	.string "The WOOD GECKO POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_15:
	.string "Will you choose {STR_VAR_1},\n"
	.string "The CHICK POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_16:
	.string "Will you choose {STR_VAR_1},\n"
	.string "The MUD FISH POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_17:
	.string "{PLAYER} recieved a {STR_VAR_1}!$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_18:
	.string "While you're at it, why not give a\n"
	.string "nickname to that {STR_VAR_1}?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_19:
	.string "{STR_VAR_2}…\p"
	.string "That's a nice nickname for a {STR_VAR_1}!$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_20:
	.string "No nickname?\p"
	.string "That's okay, not everybody likes them.$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_21:
	.string "On that note…\n"
	.string "I'll be going back to the LAB.\p"
	.string "I'm sure {PLAYER} will be able\n"
	.string "to help  you like no other.$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_22:
	.string "And {PLAYER}…\p"
	.string "See me in my LAB after you're done.$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_23:
	.string "Now that you have a POKéMON, you should\n"
	.string "head to ACREN FOREST and see what is\l"
	.string "going on there…\p"
	.string "Now off you go…$"

CedarredTown_LoggersCabin_EventScript_LoggerManOne_Text_0:
	.string "Every single one of us here works\n"
	.string "very hard to get the best quality\l"
	.string "lumber for all sorts of REGIONS!$"

CedarredTown_LoggersCabin_EventScript_LoggerManTwo_Text_0:
	.string "I hope you like the starters I\n"
	.string "got you…\p"
	.string "There were more POKéMON, but I thought\n"
	.string "these would fit you best.$"

CedarredTown_LoggersCabin_EventScript_LoggerManThree_Text_0:
	.string "I think we're the best TRAINER GUILD!\p"
	.string "No arguments, we're the best.$"

CedarredTown_LoggersCabin_EventScript_LoggerManFour_Text_0:
	.string "We have a TV here…\p"
	.string "But we're not even allowed to use it!$"

CedarredTown_LoggersCabin_EventScript_LoggerWomanOne_Text_0:
	.string "Did you know that we're a TRAINER\n"
	.string "GUILD too?\p"
	.string "Perhaps if you've won some TOURNAMENTS\n"
	.string "you could join our GUILD!$"

CedarredTown_LoggersCabin_EventScript_LoggerWomanTwo_Text_0:
	.string "Yum, the coffee we make here is so\n"
	.string "delicious!\p"
	.string "Sometimes we even have visitors just\n"
	.string "because of how great our coffee is.$"

CedarredTown_LoggersCabin_EventScript_LoggerWomanThree_Text_0:
	.string "I'm not very strong…\n"
	.string "That's why I help with administration.$"

CedarredTown_LoggersCabin_EventScript_LoggerWomanFour_Text_0:
	.string "Oh my oh my…\p"
	.string "I work so much I basically live here…$"
