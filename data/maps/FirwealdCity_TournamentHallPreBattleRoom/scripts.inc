FirwealdCity_TournamentHallPreBattleRoom_MapScripts::
# 5 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FirwealdCity_TournamentHallPreBattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 8 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FirwealdCity_TournamentHallPreBattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FirwealdCity_TournamentHallPreBattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, FirwealdCity_TournamentHallPreBattleRoom_EventScript_SetUpObjects
	.2byte 0

FirwealdCity_TournamentHallPreBattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	map_script_2 VAR_TOURNAMENT_HALL_ROUND, 0, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_EnterRoom
# 10 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer
	.2byte 0


FirwealdCity_TournamentHallPreBattleRoom_EventScript_SetUpObjects::
# 15 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	compare VAR_TOURNAMENT_HALL_ROUND, 0
	goto_if_eq FirwealdCity_TournamentHallPreBattleRoom_EventScript_SetUpObjects_2
# 19 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	setobjectxy 1, 3, 2
# 20 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
FirwealdCity_TournamentHallPreBattleRoom_EventScript_SetUpObjects_1:
# 22 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

FirwealdCity_TournamentHallPreBattleRoom_EventScript_SetUpObjects_2:
# 16 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	setobjectxy 1, 3, 7
# 17 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScript_SetUpObjects_1


FirwealdCity_TournamentHallPreBattleRoom_EventScripts_EnterRoom::
# 26 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallPreBattleRoom_Movement_AttendantWalkToDoor
# 27 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_TournamentHallPreBattleRoom_Movement_PlayerWalkToDoor
# 28 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 29 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	setvar VAR_TOURNAMENT_HALL_ROUND, 1
# 30 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer
	return


FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer::
# 34 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 35 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	compare VAR_TOURNAMENT_HALL_ROUND, 1
	goto_if_eq FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer_2
FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer_1:
# 41 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound
# 42 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 43 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer_Text_1
# 44 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	destroyspeechtail
# 45 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	closemessage
# 46 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	release
	end

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer_2:
# 36 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 37 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer_Text_0
# 38 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	destroyspeechtail
# 39 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	closemessage
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer_1


FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound::
# 51 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 52 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	switch VAR_TOURNAMENT_HALL_ROUND
# 53 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_3
# 57 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_4
# 61 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 3, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_5
# 65 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 4, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_6
FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_1:
# 70 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	destroyspeechtail
# 71 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	closemessage
	return

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_3:
# 54 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_Text_0
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_1

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_4:
# 58 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_Text_1
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_1

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_5:
# 62 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_Text_2
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_1

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_6:
# 66 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_Text_3
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_1


FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant::
# 76 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	call FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound
# 77 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	loadspeechtail FALSE, 1
# 78 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	message FirwealdCity_TournamentHallLobby_Text_WhatWouldYouLikeToDo
# 79 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmessage
# 80 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	multichoice 21, 6, MULTI_TOURNAMENT_HALL_PRE_BATTLE, 1
# 81 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 82 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 0, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_3
# 162 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_4
# 176 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_5
FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_1:
# 182 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	release
	end

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_3:
# 83 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	switch VAR_TOURNAMENT_HALL_ROUND
# 84 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 1, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_8
# 88 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 2, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_9
# 92 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 3, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_10
# 96 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case 4, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_11
FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_6:
# 106 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 107 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case YES, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_16
# 156 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case NO, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_17
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_1

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_4:
# 163 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_5, MSGBOX_YESNO
# 165 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 166 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case YES, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_13
# 172 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	case NO, FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_14
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_1

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_5:
# 177 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer_Text_1
# 178 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	destroyspeechtail
# 179 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	closemessage
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_1

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_8:
# 85 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_0, MSGBOX_YESNO
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_6

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_9:
# 89 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_1, MSGBOX_YESNO
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_6

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_10:
# 93 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_2, MSGBOX_YESNO
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_6

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_11:
# 97 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	playse SE_PIN
# 98 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 99 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 100 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_3, MSGBOX_YESNO
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_6

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_13:
# 167 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_6
# 169 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	destroyspeechtail
# 170 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	warp MAP_FIRWEALD_CITY_TOURNAMENT_HALL_LOBBY, 0xFF, 6, 6
# 171 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitstate
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_1

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_14:
# 173 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	destroyspeechtail
# 174 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_1

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_16:
# 108 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_4
# 110 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	destroyspeechtail
# 111 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	closemessage
# 112 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_19
# 126 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	compare VAR_FACING, DIR_EAST
	goto_if_eq FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_20
# 140 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	compare VAR_FACING, DIR_WEST
	goto_if_eq FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_21
FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_18:
# 154 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	warpsilent MAP_FIRWEALD_CITY_TOURNAMENT_HALL_BATTLE_ROOM, 0xFF, 7, 5
# 155 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitstate
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_1

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_17:
# 157 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer_Text_1
# 158 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	destroyspeechtail
# 159 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	closemessage
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_1

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_19:
# 114 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallPreBattleRoom_Movement_AttendantWalkAwayFromDoorNorth
# 115 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 116 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 117 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 118 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	opendoor 3, 1
# 119 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	playse SE_SLIDING_DOOR
# 120 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitdooranim
# 121 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_TournamentHallPreBattleRoom_Movement_PlayerWalkIntoDoor
# 122 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 123 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	closedoor 3, 1
# 124 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitdooranim
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_18

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_20:
# 128 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallPreBattleRoom_Movement_AttendantWalkAwayFromDoorEast
# 129 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 130 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
# 131 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 132 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	opendoor 3, 1
# 133 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	playse SE_SLIDING_DOOR
# 134 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitdooranim
# 135 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_TournamentHallPreBattleRoom_Movement_PlayerWalkIntoDoor
# 136 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 137 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	closedoor 3, 1
# 138 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitdooranim
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_18

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_21:
# 142 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallPreBattleRoom_Movement_AttendantWalkAwayFromDoorWest
# 143 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 144 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
# 145 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 146 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	opendoor 3, 1
# 147 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	playse SE_SLIDING_DOOR
# 148 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitdooranim
# 149 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_TournamentHallPreBattleRoom_Movement_PlayerWalkIntoDoor
# 150 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmovement 0
# 151 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	closedoor 3, 1
# 152 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitdooranim
	goto FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_18


FirwealdCity_TournamentHallPreBattleRoom_EventScripts_BulletinBoard::
# 187 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_BulletinBoard_Text_0, MSGBOX_SIGN
	end


FirwealdCity_TournamentHallPreBattleRoom_EventScripts_MartEmployee::
# 201 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	lock
# 202 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	faceplayer
# 203 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	loadspeechtail FALSE, 2
# 204 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	message FirwealdCity_TournamentHallPreBattleRoom_EventScripts_MartEmployee_Text_0
# 206 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	waitmessage
# 207 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	pokemart FirwealdCity_TournamentHallPreBattleRoom_Pokemart
# 208 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	destroyspeechtail
# 209 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	msgbox FirwealdCity_TournamentHallPreBattleRoom_EventScripts_MartEmployee_Text_1, MSGBOX_NPC
# 211 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	release
	end


# 215 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"

# 216 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
FirwealdCity_TournamentHallPreBattleRoom_Pokemart:
# 217 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
    .2byte ITEM_POTION
# 218 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
    .2byte ITEM_ANTIDOTE
# 219 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
    .2byte ITEM_PARALYZE_HEAL
# 220 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
    .2byte ITEM_ETHER
# 221 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
    .2byte ITEM_NONE
# 222 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
    release
# 223 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	end

# 226 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
FirwealdCity_TournamentHallPreBattleRoom_Movement_AttendantWalkToDoor:
# 227 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
# 227 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
# 227 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
# 227 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
# 227 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
# 228 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	face_down
	step_end

# 231 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
FirwealdCity_TournamentHallPreBattleRoom_Movement_PlayerWalkToDoor:
# 232 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
# 232 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
# 232 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
# 232 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
# 232 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
	step_end

# 235 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
FirwealdCity_TournamentHallPreBattleRoom_Movement_AttendantWalkAwayFromDoorNorth:
# 236 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_right
# 237 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	face_left
	step_end

# 240 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
FirwealdCity_TournamentHallPreBattleRoom_Movement_AttendantWalkAwayFromDoorEast:
# 241 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_right
# 242 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	face_left
	step_end

# 245 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
FirwealdCity_TournamentHallPreBattleRoom_Movement_AttendantWalkAwayFromDoorWest:
# 246 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_left
# 247 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	face_left
	step_end

# 250 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
FirwealdCity_TournamentHallPreBattleRoom_Movement_PlayerWalkIntoDoor:
# 251 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	walk_up
# 252 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	set_invisible
	step_end

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer_Text_0:
# 37 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "In this room, you are able to prepare\n"
	.string "yourself for your upcoming battles.\p"
	.string "If you wish to continue to the next\n"
	.string "round, or to retreat from the challenge,\l"
	.string "just talk to me.$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_InformPlayer_Text_1:
# 43 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "I'll be waiting right here.$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_Text_0:
# 54 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "Your first round of the TOURNAMENT\n"
	.string "is about to begin.$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_Text_1:
# 58 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "Your second round of the TOURNAMENT\n"
	.string "is about to begin.$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_Text_2:
# 62 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "The semifinals of the TOURNAMENT\n"
	.string "are about to begin.$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_ComingRound_Text_3:
# 66 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "The finals of the TOURNAMENT\n"
	.string "are about to begin.$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_0:
# 85 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "Are you ready for your\n"
	.string "first battle?$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_1:
# 89 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "Are you ready for your\n"
	.string "second battle?$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_2:
# 93 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "Are you ready for the\n"
	.string "semifinale?$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_3:
# 100 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "It seems you've made it to\n"
	.string "the FINALE!\p"
	.string "Are you ready for your\n"
	.string "last battle?$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_4:
# 108 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "I wish you good luck\n"
	.string "on your battle!$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_5:
# 163 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "Do you wish to retire from\n"
	.string "the TOURNAMENT CHALLENGE?$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_Attendant_Text_6:
# 167 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "Please follow me back to\n"
	.string "the LOBBY.$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_BulletinBoard_Text_0:
# 187 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "CONTESTANTS:\n"
	.string "MITOCHON: Newcoming CAMPER.\l"
	.string "DAISY: One with flowers.\l"
	.string "SINEAD: Avid BUG CATCHER.\l"
	.string "WALTER: Prodigy from HOENN!\l"
	.string "JAXON: GRASS-type collector.\l"
	.string "ARIANA: Lass from JOHTO!\l"
	.string "OLIVE: Youngster from KANTO!\l"
	.string "GORDON: Bought his way in.\l"
	.string "{PLAYER}: Newcoming challenger!$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_MartEmployee_Text_0:
# 204 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "Welcome to the TOURNAMENT SHOP.\n"
	.string "How can I help you?$"

FirwealdCity_TournamentHallPreBattleRoom_EventScripts_MartEmployee_Text_1:
# 209 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "Good luck on your\n"
	.string "TOURNAMENT CHALLENGE!$"

FirwealdCity_TournamentHallLobby_Text_WhatWouldYouLikeToDo::
# 255 "data/maps/FirwealdCity_TournamentHallPreBattleRoom/scripts.pory"
	.string "What would you like to do?$"
