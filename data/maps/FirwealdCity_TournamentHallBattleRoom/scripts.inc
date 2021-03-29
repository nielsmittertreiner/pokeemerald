FirwealdCity_TournamentHallBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FirwealdCity_TournamentHallBattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FirwealdCity_TournamentHallBattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FirwealdCity_TournamentHallBattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_0, 0, FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects
	.2byte 0

FirwealdCity_TournamentHallBattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom
	map_script_2 VAR_TOURNAMENT_HALL_ROUND, 4, FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals
	.2byte 0


FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects::
	setvar VAR_TEMP_0, 1
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_FIRWEALD_CITY_TOURNAMENT_HALL_BATTLE_ROOM
	removeobject 1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_2
	compare VAR_RESULT, FEMALE
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_3
FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_1:
	compare VAR_TOURNAMENT_HALL_ROUND, 4
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_6
	return

FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_2:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	goto FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_1

FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_3:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	goto FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_1

FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_6:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_PHYLLOS
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	turnobject 2, DIR_EAST
	addobject 2
	setobjectxy 2, 4, 5
	setvar VAR_TEMP_1, 1
	return


FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom::
	setvar VAR_TEMP_1, 1
	applymovement 2, FirwealdCity_TournamentHallBattleRoom_Movement_PlayerEnterBattleRoom
	waitmovement 0
	switch VAR_TOURNAMENT_HALL_ROUND
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_3
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_4
	case 3, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_5
FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_1:
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_3
	destroy_speech_bubble
	closemessage
	delay 30
	playse SE_M_ENCORE2
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_4
	waitse
	delay 30
	destroy_speech_bubble
	closemessage
	switch VAR_TOURNAMENT_HALL_ROUND
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_7
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_8
	case 3, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_9
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_3:
	applymovement 3, FirwealdCity_TournamentHallBattleRoom_Movement_RefereeWalkInPlaceFast
	waitmovement 0
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_0
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_4:
	applymovement 3, FirwealdCity_TournamentHallBattleRoom_Movement_RefereeWalkInPlaceFast
	waitmovement 0
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_1
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_5:
	applymovement 3, FirwealdCity_TournamentHallBattleRoom_Movement_RefereeEnthusiasticHop
	waitmovement 0
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_2
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_7:
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_8:
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_9:
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals
	return


FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent::
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_Text_0
	destroy_speech_bubble
	closemessage
	fadescreen FADE_TO_BLACK
	delay 60
	playse SE_DING_DONG
	waitse
	compare VAR_TOURNAMENT_HALL_ROUND, 1
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_2
	compare VAR_TOURNAMENT_HALL_ROUND, 2
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_2
	compare VAR_TOURNAMENT_HALL_ROUND == 3, 0
	goto_if_ne FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_3
FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_1:
	copyvar VAR_TEMP_3, VAR_RESULT
	fadescreen FADE_FROM_BLACK
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_2:
	random 3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_3:
	random 2
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_1


FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom::
	applymovement 1, FirwealdCity_TournamentHallBattleRoom_Movement_OpponentEnterBattleRoom
	waitmovement 0
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom_Text_0
	destroy_speech_bubble
	closemessage
	delay 10
	return


FirwealdCity_TournamentHallBattleRoom_EventScripts_CompetitorsPrepareForBattle::
	applymovement 2, Common_Movement_WalkRight
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 0
	delay 10
	return


FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle::
	playse SE_DING_DONG
	waitse
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle_Text_0
	destroy_speech_bubble
	closemessage
	delay 10
	applymovement 1, FirwealdCity_TournamentHallBattleRoom_OpponentMoveBack
	applymovement 2, FirwealdCity_TournamentHallBattleRoom_PlayerMoveBack
	waitmovement 0
	playse SE_M_ENCORE2
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle_Text_1
	waitse
	destroy_speech_bubble
	closemessage
	applymovement 1, FirwealdCity_TournamentHallBattleRoom_Movement_OpponentExitBattleRoom
	waitmovement 0
	removeobject 1
	delay 30
	addvar VAR_TOURNAMENT_HALL_ROUND, 1
	warp MAP_FIRWEALD_CITY_TOURNAMENT_HALL_PRE_BATTLE_ROOM, 0xFF, 3, 3
	waitstate
	return


FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne::
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent
	switch VAR_TEMP_3
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_3
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_4
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_5
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_1:
	playse SE_EXIT
	addobject 1
	waitse
	playse SE_M_ENCORE2
	waitse
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom
	load_speech_bubble 1
	switch VAR_TEMP_3
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_8
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_9
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_10
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_6:
	destroy_speech_bubble
	closemessage
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_CompetitorsPrepareForBattle
	switch VAR_TEMP_3
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_13
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_14
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_15
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_11:
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_3:
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_0
	destroy_speech_bubble
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CAMPER
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_4:
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_1
	destroy_speech_bubble
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WOMAN_2
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_5:
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_2
	destroy_speech_bubble
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BUG_CATCHER
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_8:
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_9:
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_4
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_10:
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_5
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_13:
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_1, FirwealdCity_TournamentHallBattleRoom_Text_Opponent1Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_11

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_14:
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_2, FirwealdCity_TournamentHallBattleRoom_Text_Opponent2Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_11

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_15:
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_3, FirwealdCity_TournamentHallBattleRoom_Text_Opponent3Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_11


FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo::
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent
	switch VAR_TEMP_3
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_3
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_4
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_5
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_1:
	playse SE_EXIT
	addobject 1
	waitse
	playse SE_M_ENCORE2
	waitse
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom
	load_speech_bubble 1
	switch VAR_TEMP_3
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_8
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_9
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_10
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_6:
	destroy_speech_bubble
	closemessage
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_CompetitorsPrepareForBattle
	switch VAR_TEMP_3
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_13
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_14
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_15
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_11:
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_3:
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_0
	destroy_speech_bubble
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAN_3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_4:
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_1
	destroy_speech_bubble
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_YOUNGSTER
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_5:
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_2
	destroy_speech_bubble
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_PICNICKER
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_8:
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_9:
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_4
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_10:
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_5
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_13:
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_4, FirwealdCity_TournamentHallBattleRoom_Text_Opponent4Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_11

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_14:
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_5, FirwealdCity_TournamentHallBattleRoom_Text_Opponent5Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_11

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_15:
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_6, FirwealdCity_TournamentHallBattleRoom_Text_Opponent6Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_11


FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals::
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent
	switch VAR_TEMP_3
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_3
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_4
FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_1:
	playse SE_EXIT
	addobject 1
	waitse
	playse SE_M_ENCORE2
	waitse
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom
	load_speech_bubble 1
	switch VAR_TEMP_3
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_7
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_8
FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_5:
	destroy_speech_bubble
	closemessage
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_CompetitorsPrepareForBattle
	switch VAR_TEMP_3
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_11
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_12
FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_9:
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_3:
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_0
	destroy_speech_bubble
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAN_3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_4:
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_1
	destroy_speech_bubble
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RICH_BOY
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_7:
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_2
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_5

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_8:
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_5

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_11:
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_7, FirwealdCity_TournamentHallBattleRoom_Text_Opponent7Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_9

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_12:
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_8, FirwealdCity_TournamentHallBattleRoom_Text_Opponent8Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_9


FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals::
	applymovement 2, Common_Movement_ExclamationMark
	fadescreenspeed FADE_TO_BLACK, -4
	waitmovement 0
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_0
	closemessage
	fadescreenspeed FADE_TO_WHITE, -1
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	addobject 1
	setobjectxy 1, 10, 5
	fadescreenspeed FADE_FROM_WHITE, -1
	load_speech_bubble 1
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_1
	destroy_speech_bubble
	closemessage
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_CompetitorsPrepareForBattle
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_PHYLLOS, FirwealdCity_TournamentHallBattleRoom_Text_PhyllosDefeat
	special DoDomeConfetti
	playse SE_M_ENCORE2
	applymovement 3, FirwealdCity_TournamentHallBattleRoom_Movement_RefereeEnthusiasticHop
	waitmovement 0
	waitse
	load_speech_bubble 3
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_2
	special DoDomeConfetti
	playse SE_M_ENCORE2
	waitse
	delay 120
	destroy_speech_bubble
	closemessage
	applymovement 1, FirwealdCity_TournamentHallBattleRoom_Movement_PhyllosWalkToPlayer
	waitmovement 0
	load_speech_bubble 1
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_3
	destroy_speech_bubble
	closemessage
	playfanfare MUS_OBTAIN_BADGE
	setflag FLAG_BADGE01_GET
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_4
	waitse
	closemessage
	load_speech_bubble 1
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_5
	destroy_speech_bubble
	closemessage
	giveitem ITEM_TM19_GIGA_DRAIN
	closemessage
	load_speech_bubble 1
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_6
	destroy_speech_bubble
	closemessage
	warp MAP_FIRWEALD_CITY_TOURNAMENT_HALL_LOBBY, 0xFF, 6, 6
	waitstate
	return


FirwealdCity_TournamentHallBattleRoom_Movement_PlayerEnterBattleRoom:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

FirwealdCity_TournamentHallBattleRoom_Movement_OpponentEnterBattleRoom:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

FirwealdCity_TournamentHallBattleRoom_Movement_RefereeWalkInPlaceFast:
	walk_in_place_fast_down
	step_end

FirwealdCity_TournamentHallBattleRoom_Movement_RefereeEnthusiasticHop:
	jump_in_place_down
	delay_4
	jump_in_place_down
	step_end

FirwealdCity_TournamentHallBattleRoom_OpponentMoveBack:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

FirwealdCity_TournamentHallBattleRoom_PlayerMoveBack:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

FirwealdCity_TournamentHallBattleRoom_Movement_OpponentExitBattleRoom:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FirwealdCity_TournamentHallBattleRoom_Movement_PhyllosWalkToPlayer:
	walk_left
	walk_left
	walk_left
	step_end

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_0:
	.string "Get ready for the first round\n"
	.string "of the FIRWEALD TOURNAMENT!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_1:
	.string "Get ready for the second round\n"
	.string "of the FIRWEALD TOURNAMENT!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_2:
	.string "Get ready for the SEMIFINALE\n"
	.string "of the FIRWEALD TOURNAMENT!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_3:
	.string "I will be your referee for the\n"
	.string "exciting FIRWEALD TOURNAMENT!\p"
	.string "Now let us begin!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_4:
	.string "{PLAYER} has entered the\n"
	.string "FIRWEALD BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_Text_0:
	.string "Now your opponent\n"
	.string "shall be chosen.$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom_Text_0:
	.string "Both competitors ready?\n"
	.string "Let the match begin!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle_Text_0:
	.string "That concludes this match!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle_Text_1:
	.string "The winner is {PLAYER}!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_0:
	.string "Everyone welcome MITOCHON to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_1:
	.string "Everyone welcome DAISY to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_2:
	.string "Everyone welcome SINEAD to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_3:
	.string "I'll kick you out of here before\n"
	.string "you can even get started!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_4:
	.string "My beauty will leave\n"
	.string "you speechless!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_5:
	.string "Don't touch the mushrooms on\n"
	.string "my POKéMON!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_0:
	.string "Everyone welcome WALTER to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_1:
	.string "Everyone welcome JAXON to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_2:
	.string "Everyone welcome ARIANA to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_3:
	.string "I came all the way from HOENN\n"
	.string "to win this.\p"
	.string "A wimpy kid like you won't\n"
	.string "stop me!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_4:
	.string "Try and stop me?\n"
	.string "You and what army! Hahaha!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_5:
	.string "S-S-She's not as weak as\n"
	.string "people say…!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_0:
	.string "Everyone welcome OLIVE to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_1:
	.string "Everyone welcome GORDON to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_2:
	.string "What's something me and RED share?\n"
	.string "That's right!\p"
	.string "The strongest trainers are named\n"
	.string "after colors!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_3:
	.string "Money truly gets you everywhere\n"
	.string "you would want.$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_0:
	.string "And now, for the moment\n"
	.string "you've all been waiting for!\p"
	.string "Introducing our challenger,\n"
	.string "{PLAYER}.\p"
	.string "In the other corner…\n"
	.string "PHYLLOS.\p"
	.string "FIRWEALD CITY Shrine Keeper,\n"
	.string "TOURNAMENT MASTER and Mayor.\p"
	.string "Let's see whose song the FOREST\n"
	.string "will sing tonight.$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_1:
	.string "So you have made it this far huh?\p"
	.string "Time to show you the guardian of the\n"
	.string "forest does not go down quietly!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_2:
	.string "What an amazing battle that was!\p"
	.string "With the winner being!…\n"
	.string "{PLAYER}!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_3:
	.string "I am proud of your achievements son.\n"
	.string "The trees had told me of this battle\l"
	.string "to come long before you ever arrived.\p"
	.string "I just wanted to make sure that my\n"
	.string "losing battle would be one they would\l"
	.string "speak of for ages to come. Har har har!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_4:
	.string "{PLAYER} recieved the CONIFER BADGE\n"
	.string "from PHYLLOS.$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_5:
	.string "With this badge, you'll be one\n"
	.string "step closer to greatness, kid.\p"
	.string "Take pride in your journey, and\n"
	.string "beat all the TOURNAMENT MASTERS!\p"
	.string "Before I forget…\p"
	.string "Take this TM, it's a great GRASS-type\n"
	.string "move, GIGA DRAIN.$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_6:
	.string "You're truly exceptional {PLAYER},\n"
	.string "and for that reason, I wish to\l"
	.string "show you something.\p"
	.string "Meet me at the cave north of town\n"
	.string "and talk to the lady in front of\l"
	.string "the entrance.$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent1Defeat::
	.string "You may have bested me, but\n"
	.string "you'll never get past PHYLLOS!$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent2Defeat::
	.string "No need to be so blue…\n"
	.string "We will blossom again!$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent3Defeat::
	.string "It seems the real\n"
	.string "parasite is within…$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent4Defeat::
	.string "Shame all around me, if I\n"
	.string "could only avenge this defeat…$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent5Defeat::
	.string "You need to train your POKéMON?\n"
	.string "Not only catch a bunch?$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent6Defeat::
	.string "Why did mom give\n"
	.string "me a CHIKORITA…$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent7Defeat::
	.string "Mother, why did you name\n"
	.string "me after a vegetable…$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent8Defeat::
	.string "Well that tasted\n"
	.string "rather foul…$"

FirwealdCity_TournamentHallBattleRoom_Text_PhyllosDefeat::
	.string "I can hear them chanting!\n"
	.string "{PLAYER}! {PLAYER}! {PLAYER}!$"
