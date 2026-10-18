CedarredTown_LoggersCabin_MapScripts::
# 14 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 15 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	map_script_2 VAR_CEDARRED_TOWN_STATE, 2, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 16 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	lock
# 17 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_LoggersCabin_Movement_PlayerWalkIn
# 18 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement LOCALID_FOLLOWER, CedarredTown_LoggersCabin_Movement_ConiferWalkIn
# 19 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 20 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_PIN
# 21 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 1, CedarredTown_LoggersCabin_Movement_LoggerManOneReaction
# 22 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFastestDown
# 23 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 6, Common_Movement_WalkInPlaceFastestDown
# 24 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_PIN
# 25 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 9, CedarredTown_LoggersCabin_Movement_LoggerManFourReaction
# 26 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_PIN
# 27 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 3, CedarredTown_LoggersCabin_Movement_LoggerWomanOneReaction
# 28 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_PIN
# 29 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 5, CedarredTown_LoggersCabin_Movement_LoggerWomanTwoReaction
# 30 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
# 31 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceFastestDown
# 32 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 33 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay 48
# 34 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_PIN
# 35 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 4, CedarredTown_LoggersCabin_Movement_LoggerQuestMasterNoticePlayer
# 36 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 37 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, 4
# 38 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
# 44 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 45 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 46 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_PIN
# 47 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 48 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 49 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay 8
# 50 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	turnobject 2, DIR_EAST
# 51 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, 2
# 52 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
# 57 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 58 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 59 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	turnobject 4, DIR_WEST
# 60 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, 4
# 61 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2
# 66 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 67 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 68 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, 2
# 69 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3
# 71 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 72 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 73 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_BIKE_HOP
# 74 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 2, CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToCupboard
# 75 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 76 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay 48
# 77 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 2, CedarredTown_LoggersCabin_Movement_LoggerManTwoGetBallsFromCupboard
# 78 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 79 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay 16
# 80 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_BIKE_HOP
# 81 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 2, CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToSeat
# 82 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 83 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_BIKE_HOP
# 84 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement 2, CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToLeader
# 85 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 86 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, 4
# 87 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4
# 90 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 91 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 92 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	turnobject 4, DIR_SOUTH
# 93 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	random 3
# 94 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, 4
# 95 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5
# 97 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 98 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 99 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay 30
# 100 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	fadescreen FADE_TO_BLACK
# 101 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6
# 102 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 103 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 104 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 0, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_3
# 163 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 1, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_4
# 222 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 2, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_5
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
# 282 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 283 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_17
# 284 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitfanfare
# 285 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 286 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	hidemonpic
# 287 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 288 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, 4
# 289 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_18, MSGBOX_YESNO
# 291 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 292 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_8
# 302 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_9
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_6:
# 310 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_PIN
# 311 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement LOCALID_FOLLOWER, Common_Movement_ExclamationMark
# 312 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 313 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, LOCALID_FOLLOWER
# 314 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_21
# 318 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 319 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 320 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	turnobject LOCALID_FOLLOWER, DIR_WEST
# 321 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 322 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, LOCALID_FOLLOWER
# 323 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_22
# 325 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 326 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 327 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement LOCALID_FOLLOWER, CedarredTown_LoggersCabin_Movement_ConiferWalkOut
# 328 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 329 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	playse SE_EXIT
# 330 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	removeobject LOCALID_FOLLOWER, MAP_CEDARRED_TOWN_LOGGERS_CABIN
# 331 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyfollower
# 332 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay 16
# 333 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_LoggersCabin_Movement_PlayerWalkInFrontOfLeader
# 334 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	waitmovement 0
# 335 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, 4
# 336 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_23
# 340 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 341 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 342 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	clearflag FLAG_HIDE_SUNSET_TOWN_LAB_PROF_CONIFER
# 343 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	clearflag FLAG_DISABLE_ENCOUNTERS
# 344 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setvar VAR_CEDARRED_TOWN_STATE, 3
# 345 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	release
	end

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_3:
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_11:
# 106 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7
# 107 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	multichoice 10, 4, MULTI_CEDARRED_CHOOSE_STARTER_SET_ONE, 1
# 108 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 109 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 0, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_21
# 126 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 1, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_22
# 143 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 2, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_23
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19:
# 161 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setvar VAR_TEMP_0, 0
# 162 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_11
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_4:
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_14:
# 165 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7
# 166 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	multichoice 10, 4, MULTI_CEDARRED_CHOOSE_STARTER_SET_TWO, 1
# 167 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 168 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 0, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_26
# 185 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 1, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_27
# 202 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 2, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_28
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24:
# 220 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setvar VAR_TEMP_0, 1
# 221 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_14
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_5:
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_17:
# 224 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7
# 225 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	multichoice 10, 4, MULTI_CEDARRED_CHOOSE_STARTER_SET_THREE, 1
# 226 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 227 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 0, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_31
# 244 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 1, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_32
# 261 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case 2, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_33
CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29:
# 279 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setvar VAR_TEMP_0, 2
# 280 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_17
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_8:
# 293 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 294 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setvar VAR_0x8004, 0
# 295 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 296 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	bufferpartymonnick 1, 0
# 297 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, 4
# 298 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_19
# 300 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_6

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_9:
# 303 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 304 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	loadspeechtail FALSE, 4
# 305 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_20
# 307 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_6

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_21:
# 110 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 111 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	showmonpic SPECIES_BULBASAUR, 10, 3
# 112 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	bufferspeciesname 0, SPECIES_BULBASAUR
# 113 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_8, MSGBOX_YESNO
# 115 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 116 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_35
# 120 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_36
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_22:
# 127 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 128 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	showmonpic SPECIES_CHARMANDER, 10, 3
# 129 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	bufferspeciesname 0, SPECIES_CHARMANDER
# 130 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_9, MSGBOX_YESNO
# 132 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 133 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_38
# 137 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_39
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_23:
# 144 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 145 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	showmonpic SPECIES_SQUIRTLE, 10, 3
# 146 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	bufferspeciesname 0, SPECIES_SQUIRTLE
# 147 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_10, MSGBOX_YESNO
# 149 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 150 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_41
# 154 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_42
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_26:
# 169 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 170 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 171 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	bufferspeciesname 0, SPECIES_CHIKORITA
# 172 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_11, MSGBOX_YESNO
# 174 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 175 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_44
# 179 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_45
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_27:
# 186 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 187 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 188 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	bufferspeciesname 0, SPECIES_CYNDAQUIL
# 189 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_12, MSGBOX_YESNO
# 191 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 192 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_47
# 196 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_48
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_28:
# 203 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 204 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 205 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	bufferspeciesname 0, SPECIES_TOTODILE
# 206 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_13, MSGBOX_YESNO
# 208 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 209 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_50
# 213 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_51
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_31:
# 228 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 229 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	showmonpic SPECIES_TREECKO, 10, 3
# 230 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	bufferspeciesname 0, SPECIES_TREECKO
# 231 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_14, MSGBOX_YESNO
# 233 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 234 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_53
# 238 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_54
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_32:
# 245 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 246 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	showmonpic SPECIES_TORCHIC, 10, 3
# 247 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	bufferspeciesname 0, SPECIES_TORCHIC
# 248 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_15, MSGBOX_YESNO
# 250 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 251 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_56
# 255 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_57
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_33:
# 262 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
# 263 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	showmonpic SPECIES_MUDKIP, 10, 3
# 264 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	bufferspeciesname 0, SPECIES_MUDKIP
# 265 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_16, MSGBOX_YESNO
# 267 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	switch VAR_RESULT
# 268 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case YES, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_59
# 272 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	case NO, CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_60
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_35:
# 117 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	givemon SPECIES_BULBASAUR, 5, ITEM_NONE
# 118 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_36:
# 121 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	hidemonpic
# 122 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 123 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_38:
# 134 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	givemon SPECIES_CHARMANDER, 5, ITEM_NONE
# 135 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_39:
# 138 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	hidemonpic
# 139 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 140 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_41:
# 151 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	givemon SPECIES_SQUIRTLE, 5, ITEM_NONE
# 152 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_42:
# 155 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	hidemonpic
# 156 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 157 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_19

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_44:
# 176 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE
# 177 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_45:
# 180 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	hidemonpic
# 181 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 182 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_47:
# 193 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE
# 194 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_48:
# 197 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	hidemonpic
# 198 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 199 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_50:
# 210 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	givemon SPECIES_TOTODILE, 5, ITEM_NONE
# 211 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_51:
# 214 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	hidemonpic
# 215 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 216 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_24

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_53:
# 235 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	givemon SPECIES_TREECKO, 5, ITEM_NONE
# 236 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_54:
# 239 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	hidemonpic
# 240 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 241 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_56:
# 252 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	givemon SPECIES_TORCHIC, 5, ITEM_NONE
# 253 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_57:
# 256 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	hidemonpic
# 257 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 258 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_59:
# 269 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	givemon SPECIES_MUDKIP, 5, ITEM_NONE
# 270 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_60:
# 273 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	hidemonpic
# 274 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	destroyspeechtail
# 275 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	closemessage
	goto CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_29


CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster::
# 352 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 3
	goto_if_lt CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_3
# 360 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_8
CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_7:
# 364 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_6
	return

CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_3:
# 354 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_23, MSGBOX_NPC
	end

CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_5:
	return

CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_6:
	return

CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_8:
# 360 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	goto_if_set FLAG_JOINED_LOGGERS_GUILD, CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_5
	goto CedarredTown_LoggersCabin_EventScript_LoggerQuestMaster_7


CedarredTown_LoggersCabin_EventScript_LoggerManOne::
# 372 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerManOne_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerManTwo::
# 379 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerManTwo_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerManThree::
# 387 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerManThree_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerManFour::
# 393 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerManFour_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerWomanOne::
# 399 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerWomanOne_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerWomanTwo::
# 407 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerWomanTwo_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerWomanThree::
# 415 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerWomanThree_Text_0, MSGBOX_NPC
	end


CedarredTown_LoggersCabin_EventScript_LoggerWomanFour::
# 421 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	msgbox CedarredTown_LoggersCabin_EventScript_LoggerWomanFour_Text_0, MSGBOX_NPC
	end


# 426 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_PlayerWalkIn:
# 427 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_up
# 427 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_up
# 428 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_left
# 429 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	face_up
	step_end

# 432 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_ConiferWalkIn:
# 433 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_16
# 434 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	set_visible
# 435 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_up
# 435 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_up
	step_end

# 438 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_LoggerManOneReaction:
# 439 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	emote_exclamation_mark
# 440 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 440 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 441 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_faster_left
# 442 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 442 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 442 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 443 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_faster_right
# 444 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 444 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 445 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_faster_down
	step_end

# 448 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_LoggerManFourReaction:
# 449 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	emote_exclamation_mark
# 450 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 450 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 451 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_faster_down
	step_end

# 454 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_LoggerWomanOneReaction:
# 455 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	emote_exclamation_mark
# 456 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 456 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 456 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 456 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 457 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_faster_down
	step_end

# 460 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_LoggerWomanTwoReaction:
# 461 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	emote_exclamation_mark
# 462 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 463 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_faster_up
# 464 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 465 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_faster_down
	step_end

# 468 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_LoggerQuestMasterNoticePlayer:
# 469 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	emote_exclamation_mark
# 470 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 470 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 471 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	jump_in_place_down
	step_end

# 474 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToCupboard:
# 475 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	jump_in_place_down
# 476 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_down
# 476 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_down
# 477 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_right
# 477 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_right
# 477 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_right
# 477 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_right
# 478 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_up
# 479 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_right
# 480 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_up
# 480 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_up
# 480 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_up
# 480 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_up
# 481 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_right
# 481 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_right
# 482 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	face_up
	step_end

# 485 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_LoggerManTwoGetBallsFromCupboard:
# 486 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_fast_up
# 487 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 487 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 487 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 487 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 488 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_fast_up
# 489 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 489 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 489 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 489 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 490 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_fast_up
# 491 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 491 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 491 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 491 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_4
# 492 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	face_down
	step_end

# 495 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToSeat:
# 496 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	jump_in_place_down
# 497 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_left
# 497 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_left
# 498 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_down
# 498 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_down
# 498 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_down
# 498 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_down
# 499 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_left
# 500 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_down
# 501 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_left
# 501 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_left
# 501 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_left
# 501 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_left
# 502 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_up
# 502 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_up
# 503 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	face_right
	step_end

# 506 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_LoggerManTwoWalkToLeader:
# 507 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	jump_in_place_right
# 508 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_right
# 508 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_fast_right
# 509 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	delay_16
# 510 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_fast_right
# 510 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_fast_right
# 510 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_in_place_fast_right
	step_end

# 513 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_ConiferWalkOut:
# 514 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_down
# 514 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_down
	step_end

# 517 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
CedarredTown_LoggersCabin_Movement_PlayerWalkInFrontOfLeader:
# 518 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	walk_right
# 519 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	face_up
	step_end

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
# 38 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Ah, PROFESSOR CONIFER!\n"
	.string "We've been waiting for you.\p"
	.string "Hmmm, who's that you brought with you?\p"
	.string "Any extra help is always nice to have.\n"
	.string "Definitely with what we have going on\l"
	.string "in ACREN FOREST.$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
# 52 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Sir!\p"
	.string "I have an idea on how the kid could\n"
	.string "help us, Sir!\p"
	.string "We could lend him one of our POKéMON.\n"
	.string "Sir!$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
# 61 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Hmmm…\n"
	.string "One of our POKéMON you say…\p"
	.string "I think that's a great idea!\p"
	.string "Recruit, could you fetch me our\n"
	.string "POKéBALLS the kid can use?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
# 69 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Yes, Sir!\p"
	.string "I'll get them right away!$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4:
# 87 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Aha… I see, you chose these\n"
	.string "POKéMON for the kid.\p"
	.string "These POKéMON should do well.$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5:
# 95 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Now…\n"
	.string "Close your eyes…$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6:
# 101 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Follow your heart now…$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7:
# 106 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Which POKéMON will you choose?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_8:
# 113 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Will you choose {STR_VAR_1},\n"
	.string "The SEED POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_9:
# 130 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Will you choose {STR_VAR_1},\n"
	.string "The LIZARD POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_10:
# 147 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Will you choose {STR_VAR_1},\n"
	.string "The TINY TURTLE POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_11:
# 172 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Will you choose {STR_VAR_1},\n"
	.string "The LEAF POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_12:
# 189 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Will you choose {STR_VAR_1},\n"
	.string "The FIRE MOUSE POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_13:
# 206 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Will you choose {STR_VAR_1},\n"
	.string "The BIG JAW POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_14:
# 231 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Will you choose {STR_VAR_1},\n"
	.string "The WOOD GECKO POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_15:
# 248 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Will you choose {STR_VAR_1},\n"
	.string "The CHICK POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_16:
# 265 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Will you choose {STR_VAR_1},\n"
	.string "The MUD FISH POKéMON?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_17:
# 283 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "{PLAYER} recieved a {STR_VAR_1}!$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_18:
# 289 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "While you're at it, why not give a\n"
	.string "nickname to that {STR_VAR_1}?$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_19:
# 298 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "{STR_VAR_2}…\p"
	.string "That's a nice nickname for a {STR_VAR_1}!$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_20:
# 305 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "No nickname?\p"
	.string "That's okay, not everybody likes them.$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_21:
# 314 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "On that note…\n"
	.string "I'll be going back to the LAB.\p"
	.string "I'm sure {PLAYER} will be able\n"
	.string "to help  you like no other.$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_22:
# 323 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "And {PLAYER}…\p"
	.string "See me in my LAB after you're done.$"

CedarredTown_LoggersCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_23:
# 336 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Now that you have a POKéMON, you should\n"
	.string "head to ACREN FOREST and see what is\l"
	.string "going on there…\p"
	.string "Now off you go…$"

CedarredTown_LoggersCabin_EventScript_LoggerManOne_Text_0:
# 372 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Every single one of us here works\n"
	.string "very hard to get the best quality\l"
	.string "lumber for all sorts of REGIONS!$"

CedarredTown_LoggersCabin_EventScript_LoggerManTwo_Text_0:
# 379 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "I hope you like the starters I\n"
	.string "got you…\p"
	.string "There were more POKéMON, but I thought\n"
	.string "these would fit you best.$"

CedarredTown_LoggersCabin_EventScript_LoggerManThree_Text_0:
# 387 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "I think we're the best TRAINER GUILD!\p"
	.string "No arguments, we're the best.$"

CedarredTown_LoggersCabin_EventScript_LoggerManFour_Text_0:
# 393 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "We have a TV here…\p"
	.string "But we're not even allowed to use it!$"

CedarredTown_LoggersCabin_EventScript_LoggerWomanOne_Text_0:
# 399 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Did you know that we're a TRAINER\n"
	.string "GUILD too?\p"
	.string "Perhaps if you've won some TOURNAMENTS\n"
	.string "you could join our GUILD!$"

CedarredTown_LoggersCabin_EventScript_LoggerWomanTwo_Text_0:
# 407 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Yum, the coffee we make here is so\n"
	.string "delicious!\p"
	.string "Sometimes we even have visitors just\n"
	.string "because of how great our coffee is.$"

CedarredTown_LoggersCabin_EventScript_LoggerWomanThree_Text_0:
# 415 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "I'm not very strong…\n"
	.string "That's why I help with administration.$"

CedarredTown_LoggersCabin_EventScript_LoggerWomanFour_Text_0:
# 421 "data/maps/CedarredTown_LoggersCabin/scripts.pory"
	.string "Oh my oh my…\p"
	.string "I work so much I basically live here…$"
