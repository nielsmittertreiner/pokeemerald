FirwealdCity_TournamentHallBattleRoom_MapScripts::
# 10 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FirwealdCity_TournamentHallBattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 13 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FirwealdCity_TournamentHallBattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FirwealdCity_TournamentHallBattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 11 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects
	.2byte 0

FirwealdCity_TournamentHallBattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom
# 15 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	map_script_2 VAR_TOURNAMENT_HALL_ROUND, 4, FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals
	.2byte 0


FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects::
# 20 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 21 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_FIRWEALD_CITY_TOURNAMENT_HALL_BATTLE_ROOM
# 22 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	removeobject 1
# 23 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	checkplayergender
# 24 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_2
# 26 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	compare VAR_RESULT, FEMALE
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_3
FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_1:
# 29 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	compare VAR_TOURNAMENT_HALL_ROUND, 4
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_6
	return

FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_2:
# 25 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	goto FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_1

FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_3:
# 27 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	goto FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_1

FirwealdCity_TournamentHallBattleRoom_EventScript_SetUpObjects_6:
# 30 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_PHYLLOS
# 31 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
# 32 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	turnobject 2, DIR_EAST
# 33 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	addobject 2
# 34 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setobjectxy 2, 4, 5
# 35 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
	return


FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom::
# 40 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 41 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 2, FirwealdCity_TournamentHallBattleRoom_Movement_PlayerEnterBattleRoom
# 42 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 43 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TOURNAMENT_HALL_ROUND
# 44 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_3
# 51 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_4
# 58 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 3, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_5
FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_1:
# 66 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_3
# 69 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 70 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 71 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	delay 30
# 72 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 73 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 74 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_4
# 76 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 77 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	delay 30
# 78 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 79 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 80 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TOURNAMENT_HALL_ROUND
# 81 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_7
# 83 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_8
# 85 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 3, FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_9
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_3:
# 45 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 3, FirwealdCity_TournamentHallBattleRoom_Movement_RefereeWalkInPlaceFast
# 46 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 47 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 48 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_0
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_4:
# 52 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 3, FirwealdCity_TournamentHallBattleRoom_Movement_RefereeWalkInPlaceFast
# 53 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 54 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 55 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_1
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_5:
# 59 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 3, FirwealdCity_TournamentHallBattleRoom_Movement_RefereeEnthusiasticHop
# 60 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 61 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 62 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_2
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_7:
# 82 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_8:
# 84 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_9:
# 86 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals
	return


FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent::
# 91 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 92 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_Text_0
# 94 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 95 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 96 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 97 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	delay 60
# 98 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_DING_DONG
# 99 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 100 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	compare VAR_TOURNAMENT_HALL_ROUND, 1
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_2
# 100 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	compare VAR_TOURNAMENT_HALL_ROUND, 2
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_2
# 102 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	compare VAR_TOURNAMENT_HALL_ROUND, 3
	goto_if_eq FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_3
FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_1:
# 105 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 106 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_2:
# 101 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	random 3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_3:
# 103 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	random 2
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_1


FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom::
# 111 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallBattleRoom_Movement_OpponentEnterBattleRoom
# 112 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 113 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 114 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom_Text_0
# 116 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 117 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 118 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	delay 10
	return


FirwealdCity_TournamentHallBattleRoom_EventScripts_CompetitorsPrepareForBattle::
# 123 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkRight
# 124 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 1, Common_Movement_WalkLeft
# 125 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 126 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	delay 10
	return


FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle::
# 131 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_DING_DONG
# 132 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 133 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 134 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle_Text_0
# 135 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 136 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 137 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	delay 10
# 138 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallBattleRoom_OpponentMoveBack
# 139 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 2, FirwealdCity_TournamentHallBattleRoom_PlayerMoveBack
# 140 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 141 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 142 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 143 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle_Text_1
# 144 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 145 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 146 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 147 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallBattleRoom_Movement_OpponentExitBattleRoom
# 148 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 149 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	removeobject 1
# 150 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	delay 30
# 151 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	addvar VAR_TOURNAMENT_HALL_ROUND, 1
# 152 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	warp MAP_FIRWEALD_CITY_TOURNAMENT_HALL_PRE_BATTLE_ROOM, 0xFF, 3, 3
# 153 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitstate
	return


FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne::
# 157 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent
# 158 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TEMP_3
# 159 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_3
# 167 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_4
# 175 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_5
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_1:
# 184 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_EXIT
# 185 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	addobject 1
# 186 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 187 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 188 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 189 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom
# 190 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 191 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TEMP_3
# 192 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_8
# 196 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_9
# 200 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_10
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_6:
# 205 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 206 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 207 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_CompetitorsPrepareForBattle
# 208 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TEMP_3
# 209 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_13
# 212 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_14
# 215 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_15
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_11:
# 219 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_3:
# 160 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 161 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_0
# 163 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 164 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 165 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CAMPER
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_4:
# 168 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 169 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_1
# 171 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 172 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 173 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WOMAN_2
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_5:
# 176 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 177 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_2
# 179 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 180 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 181 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BUG_CATCHER
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_8:
# 193 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_9:
# 197 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_4
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_10:
# 201 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_5
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_13:
# 210 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_1, FirwealdCity_TournamentHallBattleRoom_Text_Opponent1Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_11

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_14:
# 213 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_2, FirwealdCity_TournamentHallBattleRoom_Text_Opponent2Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_11

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_15:
# 216 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_3, FirwealdCity_TournamentHallBattleRoom_Text_Opponent3Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_11


FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo::
# 223 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent
# 224 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TEMP_3
# 225 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_3
# 233 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_4
# 241 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_5
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_1:
# 250 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_EXIT
# 251 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	addobject 1
# 252 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 253 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 254 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 255 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom
# 256 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 257 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TEMP_3
# 258 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_8
# 264 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_9
# 268 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_10
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_6:
# 273 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 274 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 275 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_CompetitorsPrepareForBattle
# 276 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TEMP_3
# 277 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_13
# 280 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_14
# 283 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_15
FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_11:
# 287 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_3:
# 226 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 227 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_0
# 229 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 230 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 231 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAN_3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_4:
# 234 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 235 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_1
# 237 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 238 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 239 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_YOUNGSTER
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_5:
# 242 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 243 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_2
# 245 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 246 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 247 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_PICNICKER
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_8:
# 259 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_9:
# 265 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_4
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_10:
# 269 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_5
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_6

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_13:
# 278 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_4, FirwealdCity_TournamentHallBattleRoom_Text_Opponent4Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_11

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_14:
# 281 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_5, FirwealdCity_TournamentHallBattleRoom_Text_Opponent5Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_11

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_15:
# 284 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_6, FirwealdCity_TournamentHallBattleRoom_Text_Opponent6Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_11


FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals::
# 291 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent
# 292 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TEMP_3
# 293 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_3
# 301 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_4
FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_1:
# 310 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_EXIT
# 311 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	addobject 1
# 312 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 313 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 314 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 315 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom
# 316 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 317 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TEMP_3
# 318 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_7
# 324 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_8
FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_5:
# 329 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 330 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 331 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_CompetitorsPrepareForBattle
# 332 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	switch VAR_TEMP_3
# 333 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 0, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_11
# 336 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_12
FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_9:
# 340 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle
	return

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_3:
# 294 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 295 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_0
# 297 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 298 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 299 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAN_3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_4:
# 302 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 303 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_1
# 305 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 306 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 307 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RICH_BOY
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_1

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_7:
# 319 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_2
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_5

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_8:
# 325 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_3
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_5

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_11:
# 334 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_7, FirwealdCity_TournamentHallBattleRoom_Text_Opponent7Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_9

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_12:
# 337 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_OPPONENT_8, FirwealdCity_TournamentHallBattleRoom_Text_Opponent8Defeat
	goto FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_9


FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals::
# 344 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 345 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, -4
# 346 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 347 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_0
# 357 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 358 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, -1
# 359 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
# 360 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	addobject 1
# 361 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setobjectxy 1, 10, 5
# 362 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, -1
# 363 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 364 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_1
# 367 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 368 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 369 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallBattleRoom_EventScripts_CompetitorsPrepareForBattle
# 370 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_FIRWEALD_CITY_TOURNAMENT_PHYLLOS, FirwealdCity_TournamentHallBattleRoom_Text_PhyllosDefeat
# 371 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	special DoDomeConfetti
# 372 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 373 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 3, FirwealdCity_TournamentHallBattleRoom_Movement_RefereeEnthusiasticHop
# 374 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 375 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 376 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 3
# 377 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_2
# 380 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	special DoDomeConfetti
# 381 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 382 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 383 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	delay 120
# 384 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 385 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 386 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallBattleRoom_Movement_PhyllosWalkToPlayer
# 387 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitmovement 0
# 388 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 389 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_3
# 395 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 396 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 397 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 398 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 399 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_4
# 401 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitse
# 402 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 403 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 404 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_5
# 411 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 412 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 413 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	giveitem ITEM_TM_GIGA_DRAIN
# 414 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 415 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 416 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_6
# 422 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	destroyspeechtail
# 423 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	closemessage
# 424 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	warp MAP_FIRWEALD_CITY_TOURNAMENT_HALL_LOBBY, 0xFF, 6, 6
# 425 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	waitstate
	return


# 428 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
FirwealdCity_TournamentHallBattleRoom_Movement_PlayerEnterBattleRoom:
# 429 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_up
# 429 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_up
# 429 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_up
# 430 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_right
# 430 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_right
	step_end

# 433 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
FirwealdCity_TournamentHallBattleRoom_Movement_OpponentEnterBattleRoom:
# 434 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_down
# 434 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_down
# 434 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_down
# 434 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_down
# 435 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_left
# 435 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_left
	step_end

# 438 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
FirwealdCity_TournamentHallBattleRoom_Movement_RefereeWalkInPlaceFast:
# 439 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 442 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
FirwealdCity_TournamentHallBattleRoom_Movement_RefereeEnthusiasticHop:
# 443 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	jump_in_place_down
# 444 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	delay_4
# 445 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	jump_in_place_down
	step_end

# 448 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
FirwealdCity_TournamentHallBattleRoom_OpponentMoveBack:
# 449 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	lock_facing_direction
# 450 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_right
# 451 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 454 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
FirwealdCity_TournamentHallBattleRoom_PlayerMoveBack:
# 455 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	lock_facing_direction
# 456 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_left
# 457 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 460 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
FirwealdCity_TournamentHallBattleRoom_Movement_OpponentExitBattleRoom:
# 461 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_right
# 461 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_right
# 462 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_up
# 462 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_up
# 462 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_up
# 462 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_up
	step_end

# 465 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
FirwealdCity_TournamentHallBattleRoom_Movement_PhyllosWalkToPlayer:
# 466 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_left
# 466 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_left
# 466 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	walk_left
	step_end

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_0:
# 48 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Get ready for the first round\n"
	.string "of the FIRWEALD TOURNAMENT!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_1:
# 55 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Get ready for the second round\n"
	.string "of the FIRWEALD TOURNAMENT!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_2:
# 62 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Get ready for the SEMIFINALE\n"
	.string "of the FIRWEALD TOURNAMENT!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_3:
# 66 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "I will be your referee for the\n"
	.string "exciting FIRWEALD TOURNAMENT!\p"
	.string "Now let us begin!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_EnterRoom_Text_4:
# 74 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "{PLAYER} has entered the\n"
	.string "FIRWEALD BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_ChooseOpponent_Text_0:
# 92 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Now your opponent\n"
	.string "shall be chosen.$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_OpponentEnterRoom_Text_0:
# 114 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Both competitors ready?\n"
	.string "Let the match begin!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle_Text_0:
# 134 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "That concludes this match!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_ConcludeBattle_Text_1:
# 143 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "The winner is {PLAYER}!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_0:
# 161 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Everyone welcome MITOCHON to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_1:
# 169 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Everyone welcome DAISY to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_2:
# 177 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Everyone welcome SINEAD to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_3:
# 193 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "I'll kick you out of here before\n"
	.string "you can even get started!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_4:
# 197 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "My beauty will leave\n"
	.string "you speechless!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundOne_Text_5:
# 201 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Don't touch the mushrooms on\n"
	.string "my POKéMON!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_0:
# 227 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Everyone welcome WALTER to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_1:
# 235 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Everyone welcome JAXON to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_2:
# 243 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Everyone welcome ARIANA to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_3:
# 259 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "I came all the way from HOENN\n"
	.string "to win this.\p"
	.string "A wimpy kid like you won't\n"
	.string "stop me!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_4:
# 265 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Try and stop me?\n"
	.string "You and what army! Hahaha!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_RoundTwo_Text_5:
# 269 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "S-S-She's not as weak as\n"
	.string "people say…!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_0:
# 295 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Everyone welcome OLIVE to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_1:
# 303 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Everyone welcome GORDON to\n"
	.string "the BATTLE ROOM!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_2:
# 319 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "What's something me and RED share?\n"
	.string "That's right!\p"
	.string "The strongest trainers are named\n"
	.string "after colors!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Semifinals_Text_3:
# 325 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Money truly gets you everywhere\n"
	.string "you would want.$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_0:
# 347 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
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
# 364 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "So you have made it this far huh?\p"
	.string "Time to show you the guardian of the\n"
	.string "forest does not go down quietly!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_2:
# 377 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "What an amazing battle that was!\p"
	.string "With the winner being!…\n"
	.string "{PLAYER}!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_3:
# 389 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "I am proud of your achievements son.\n"
	.string "The trees had told me of this battle\l"
	.string "to come long before you ever arrived.\p"
	.string "I just wanted to make sure that my\n"
	.string "losing battle would be one they would\l"
	.string "speak of for ages to come. Har har har!$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_4:
# 399 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "{PLAYER} recieved the CONIFER BADGE\n"
	.string "from PHYLLOS.$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_5:
# 404 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "With this badge, you'll be one\n"
	.string "step closer to greatness, kid.\p"
	.string "Take pride in your journey, and\n"
	.string "beat all the TOURNAMENT MASTERS!\p"
	.string "Before I forget…\p"
	.string "Take this TM, it's a great GRASS-type\n"
	.string "move, GIGA DRAIN.$"

FirwealdCity_TournamentHallBattleRoom_EventScripts_Finals_Text_6:
# 416 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "You're truly exceptional {PLAYER},\n"
	.string "and for that reason, I wish to\l"
	.string "show you something.\p"
	.string "Meet me at the cave north of town\n"
	.string "and talk to the lady in front of\l"
	.string "the entrance.$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent1Defeat::
# 469 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "You may have bested me, but you'll\p"
	.string "never get past PHYLLOS!$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent2Defeat::
# 474 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "No need to be so blue…\p"
	.string "We will blossom again!$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent3Defeat::
# 479 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "It seems the real parasite is within…$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent4Defeat::
# 483 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Shame all around me, if I could\p"
	.string "only avenge this defeat…$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent5Defeat::
# 488 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "You need to train your POKéMON?\p"
	.string "Not only catch a bunch?$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent6Defeat::
# 493 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Why did mom give me a CHIKORITA…$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent7Defeat::
# 497 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Mother, why did you name me after\p"
	.string "a vegetable…$"

FirwealdCity_TournamentHallBattleRoom_Text_Opponent8Defeat::
# 502 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "Well that tasted rather foul…$"

FirwealdCity_TournamentHallBattleRoom_Text_PhyllosDefeat::
# 506 "data/maps/FirwealdCity_TournamentHallBattleRoom/scripts.pory"
	.string "I can hear them chanting!\p"
	.string "{PLAYER}! {PLAYER}! {PLAYER}!$"
