FirwealdCity_TournamentHallLobby_MapScripts::
# 4 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 5 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	map_script_2 VAR_TOURNAMENT_HALL_STATE, 0, FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 6 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	playse SE_PIN
# 7 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 8 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	waitmovement 0
# 9 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallLobby_Movement_AttendantWalkDown
# 10 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	waitmovement 0
# 11 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	loadspeechtail FALSE, 1
# 12 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	msgbox FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
# 15 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 16 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	closemessage
# 17 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	delay 16
# 18 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	loadspeechtail FALSE, 1
# 19 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	msgbox FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1, MSGBOX_YESNO
# 21 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
# 36 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 37 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	loadspeechtail FALSE, 1
# 38 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	msgbox FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3
# 40 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 41 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	closemessage
FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
# 43 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallLobby_Movement_AttendantWalkUp
# 44 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	waitmovement 0
# 45 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	setvar VAR_TOURNAMENT_HALL_STATE, 1
# 46 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	release
	end

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
# 22 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 23 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	loadspeechtail FALSE, 1
# 24 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	msgbox FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2
# 33 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 34 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	closemessage
	goto FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1


FirwealdCity_TournamentHallLobby_EventScript_Attendant::
# 53 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	lock
# 54 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	faceplayer
# 55 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, FirwealdCity_TournamentHallLobby_EventScript_Attendant_2
# 67 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	loadspeechtail FALSE, 1
# 68 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	message FirwealdCity_TournamentHallLobby_Text_WelcomeToFirwealdCityTounamentHall
# 69 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	waitmessage
# 70 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	multichoice 22, 6, MULTI_TOURNAMENT_HALL_JOIN, 1
# 71 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	switch VAR_RESULT
# 72 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	case 0, FirwealdCity_TournamentHallLobby_EventScript_Attendant_5
# 77 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	case 1, FirwealdCity_TournamentHallLobby_EventScript_Attendant_6
# 94 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	case 2, FirwealdCity_TournamentHallLobby_EventScript_Attendant_7
	return

FirwealdCity_TournamentHallLobby_EventScript_Attendant_2:
# 57 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	loadspeechtail FALSE, 1
# 58 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	msgbox FirwealdCity_TournamentHallLobby_EventScript_Attendant_Text_0
# 63 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 64 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	release
	end

FirwealdCity_TournamentHallLobby_EventScript_Attendant_5:
# 73 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 74 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	closemessage
# 75 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	goto FirwealdCity_TournamentHallLobby_EventScript_JoinTournament
	return

FirwealdCity_TournamentHallLobby_EventScript_Attendant_6:
# 78 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 79 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	closemessage
# 80 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	msgbox FirwealdCity_TournamentHallLobby_EventScript_Attendant_Text_1, MSGBOX_NPC
# 92 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	goto FirwealdCity_TournamentHallLobby_EventScript_Attendant
	return

FirwealdCity_TournamentHallLobby_EventScript_Attendant_7:
# 95 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 96 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	closemessage
# 97 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	goto FirwealdCity_TournamentHallLobby_EventScript_CancelTournament
	return


FirwealdCity_TournamentHallLobby_EventScript_CancelTournament::
# 102 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	msgbox FirwealdCity_TournamentHallLobby_EventScript_CancelTournament_Text_0, MSGBOX_NPC
	end


FirwealdCity_TournamentHallLobby_EventScript_JoinTournament::
# 107 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	loadspeechtail FALSE, 1
# 108 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	msgbox FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_Text_0, MSGBOX_YESNO
# 110 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	switch VAR_RESULT
# 111 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	case YES, FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_3
# 117 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	case NO, FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_4
FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_1:
# 122 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	delay 15
# 123 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallLobby_Movement_WalkToDoor
# 124 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_TournamentHallLobby_Movement_WalkToDoor
# 125 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	waitmovement 0
# 126 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	opendoor 6, 1
# 127 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	playse SE_SLIDING_DOOR
# 128 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	waitdooranim
# 129 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	applymovement 1, FirwealdCity_TournamentHallLobby_Movement_AttendantWalkInDoor
# 130 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_TournamentHallLobby_Movement_PlayerWalkInDoor
# 131 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	waitmovement 0
# 132 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	closedoor 6, 1
# 133 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	waitdooranim
# 134 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	setvar VAR_TOURNAMENT_HALL_ROUND, 0
# 135 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	warpsilent MAP_FIRWEALD_CITY_TOURNAMENT_HALL_PRE_BATTLE_ROOM, 0xFF, 3, 8
# 136 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	waitstate
	return

FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_3:
# 112 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 113 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	closemessage
# 114 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 115 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	closemessage
	goto FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_1

FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_4:
# 118 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	destroyspeechtail
# 119 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	closemessage
# 120 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	goto FirwealdCity_TournamentHallLobby_EventScript_CancelTournament
	goto FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_1


FirwealdCity_TournamentHallLobby_EventScript_Maniac::
# 140 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	msgbox FirwealdCity_TournamentHallLobby_EventScript_Maniac_Text_0, MSGBOX_NPC
	end


FirwealdCity_TournamentHallLobby_EventScript_Beauty::
# 146 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	msgbox FirwealdCity_TournamentHallLobby_EventScript_Beauty_Text_0, MSGBOX_NPC
	end


# 151 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
FirwealdCity_TournamentHallLobby_Movement_AttendantWalkDown:
# 152 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_down
# 152 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_down
# 152 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_down
	step_end

# 155 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
FirwealdCity_TournamentHallLobby_Movement_AttendantWalkUp:
# 156 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_up
# 156 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_up
# 156 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_up
# 157 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	face_down
	step_end

# 160 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
FirwealdCity_TournamentHallLobby_Movement_WalkToDoor:
# 161 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_up
# 161 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_up
# 161 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_up
	step_end

# 164 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
FirwealdCity_TournamentHallLobby_Movement_AttendantWalkInDoor:
# 165 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_up
# 166 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	set_invisible
	step_end

# 169 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
FirwealdCity_TournamentHallLobby_Movement_PlayerWalkInDoor:
# 170 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_up
# 170 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	walk_up
# 171 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	set_invisible
	step_end

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
# 12 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "Hi there TRAINER, it seems like this\n"
	.string "is your first time in a TOURNAMENT\l"
	.string "HALL.$"

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
# 19 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "Would you like me to explain the use\n"
	.string "of TOURNAMENT HALLS?$"

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
# 24 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "Across the EURUS REGION, multiple\n"
	.string "TOURNAMENT HALLS are spread around\p"
	.string "They are used for competitive battling\n"
	.string "and all have a TOURNAMENT MASTER.\p"
	.string "When you beat the TOURNAMENT MASTER\n"
	.string "you'll obtain a gift when you beat\l"
	.string "the tournament challenge.\p"
	.string "You can sign up to join a \n"
	.string "tournament at the counter.$"

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
# 38 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "Well then, I'll be waiting at the\n"
	.string "counter up front.$"

FirwealdCity_TournamentHallLobby_EventScript_Attendant_Text_0:
# 58 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "Congratulations!\n"
	.string "You have already earned the CONIFER\l"
	.string "BADGE.\p"
	.string "We can't let you participate when you\n"
	.string "already have this TOURNAMENT's BADGE…$"

FirwealdCity_TournamentHallLobby_EventScript_Attendant_Text_1:
# 80 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "This is the FIRWEALD CITY\n"
	.string "TOURNAMENT HALL. Here trainers come\l"
	.string "together to compete in advanced\l"
	.string "POKéMON battles.\p"
	.string "The goal is to beat all trainers and\n"
	.string "finally defeat the TOURNAMENT MASTER.\p"
	.string "After each battle, your party is healed\n"
	.string "and you will face your next opponent.\p"
	.string "Have fun battling and in all our\n"
	.string "TOURNAMENT HALLS.\p"
	.string "You can challenge a TOURNAMENTS in\n"
	.string "any order you'd like.$"

FirwealdCity_TournamentHallLobby_EventScript_CancelTournament_Text_0:
# 102 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "We hope to see you again!$"

FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_Text_0:
# 108 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "Before you join the TOURNAMENT,\n"
	.string "you must save your data. Is that okay?$"

FirwealdCity_TournamentHallLobby_EventScript_Maniac_Text_0:
# 140 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "Competitive POKéMON battles\n"
	.string "are so cool!$"

FirwealdCity_TournamentHallLobby_EventScript_Beauty_Text_0:
# 146 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "I've heard PHYLLOS is a very strong\n"
	.string "TOURNAMENT MASTER.$"

FirwealdCity_TournamentHallLobby_Text_WelcomeToFirwealdCityTounamentHall::
# 174 "data/maps/FirwealdCity_TournamentHallLobby/scripts.pory"
	.string "Welcome to FIRWEALD CITY's\n"
	.string "TOURNAMENT HALL.\p"
	.string "Would you like to sign up for\n"
	.string "a tournament?$"
