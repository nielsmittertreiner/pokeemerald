FirwealdCity_TournamentHallLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TOURNAMENT_HALL_STATE, 0, FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, FirwealdCity_TournamentHallLobby_Movement_AttendantWalkDown
	waitmovement 0
	load_speech_bubble 1
	msgbox FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	destroy_speech_bubble
	closemessage
	delay 16
	load_speech_bubble 1
	msgbox FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
	destroy_speech_bubble
	load_speech_bubble 1
	msgbox FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3
	destroy_speech_bubble
	closemessage
FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	applymovement 1, FirwealdCity_TournamentHallLobby_Movement_AttendantWalkUp
	waitmovement 0
	setvar VAR_TOURNAMENT_HALL_STATE, 1
	release
	end

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
	destroy_speech_bubble
	load_speech_bubble 1
	msgbox FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2
	destroy_speech_bubble
	closemessage
	goto FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1


FirwealdCity_TournamentHallLobby_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, FirwealdCity_TournamentHallLobby_EventScript_Attendant_2
	load_speech_bubble 1
	message FirwealdCity_TournamentHallLobby_Text_WelcomeToFirwealdCityTounamentHall
	waitmessage
	multichoice 22, 6, MULTI_TOURNAMENT_HALL_JOIN, 1
	switch VAR_RESULT
	case 0, FirwealdCity_TournamentHallLobby_EventScript_Attendant_5
	case 1, FirwealdCity_TournamentHallLobby_EventScript_Attendant_6
	case 2, FirwealdCity_TournamentHallLobby_EventScript_Attendant_7
	return

FirwealdCity_TournamentHallLobby_EventScript_Attendant_2:
	load_speech_bubble 1
	msgbox FirwealdCity_TournamentHallLobby_EventScript_Attendant_Text_0
	destroy_speech_bubble
	release
	end

FirwealdCity_TournamentHallLobby_EventScript_Attendant_5:
	destroy_speech_bubble
	closemessage
	goto FirwealdCity_TournamentHallLobby_EventScript_JoinTournament
	return

FirwealdCity_TournamentHallLobby_EventScript_Attendant_6:
	destroy_speech_bubble
	closemessage
	msgbox FirwealdCity_TournamentHallLobby_EventScript_Attendant_Text_1, MSGBOX_NPC
	goto FirwealdCity_TournamentHallLobby_EventScript_Attendant
	return

FirwealdCity_TournamentHallLobby_EventScript_Attendant_7:
	destroy_speech_bubble
	closemessage
	goto FirwealdCity_TournamentHallLobby_EventScript_CancelTournament
	return


FirwealdCity_TournamentHallLobby_EventScript_CancelTournament::
	msgbox FirwealdCity_TournamentHallLobby_EventScript_CancelTournament_Text_0, MSGBOX_NPC
	end


FirwealdCity_TournamentHallLobby_EventScript_JoinTournament::
	load_speech_bubble 1
	msgbox FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_Text_0, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_3
	case NO, FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_4
FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_1:
	delay 15
	applymovement 1, FirwealdCity_TournamentHallLobby_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_TournamentHallLobby_Movement_WalkToDoor
	waitmovement 0
	opendoor 6, 1
	playse SE_SLIDING_DOOR
	waitdooranim
	applymovement 1, FirwealdCity_TournamentHallLobby_Movement_AttendantWalkInDoor
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_TournamentHallLobby_Movement_PlayerWalkInDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	setvar VAR_TOURNAMENT_HALL_ROUND, 0
	warpsilent MAP_FIRWEALD_CITY_TOURNAMENT_HALL_PRE_BATTLE_ROOM, 0xFF, 3, 8
	waitstate
	return

FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_3:
	destroy_speech_bubble
	closemessage
	call Common_EventScript_SaveGame
	closemessage
	goto FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_1

FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_4:
	destroy_speech_bubble
	closemessage
	goto FirwealdCity_TournamentHallLobby_EventScript_CancelTournament
	goto FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_1


FirwealdCity_TournamentHallLobby_EventScript_Maniac::
	msgbox FirwealdCity_TournamentHallLobby_EventScript_Maniac_Text_0, MSGBOX_NPC
	end


FirwealdCity_TournamentHallLobby_EventScript_Beauty::
	msgbox FirwealdCity_TournamentHallLobby_EventScript_Beauty_Text_0, MSGBOX_NPC
	end


FirwealdCity_TournamentHallLobby_Movement_AttendantWalkDown:
	walk_down
	walk_down
	walk_down
	step_end

FirwealdCity_TournamentHallLobby_Movement_AttendantWalkUp:
	walk_up
	walk_up
	walk_up
	face_down
	step_end

FirwealdCity_TournamentHallLobby_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

FirwealdCity_TournamentHallLobby_Movement_AttendantWalkInDoor:
	walk_up
	set_invisible
	step_end

FirwealdCity_TournamentHallLobby_Movement_PlayerWalkInDoor:
	walk_up
	walk_up
	set_invisible
	step_end

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "Hi there TRAINER, it seems like this\n"
	.string "is your first time in a TOURNAMENT\l"
	.string "HALL.$"

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "Would you like me to explain the use\n"
	.string "of TOURNAMENT HALLS?$"

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
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
	.string "Well then, I'll be waiting at the\n"
	.string "counter up front.$"

FirwealdCity_TournamentHallLobby_EventScript_Attendant_Text_0:
	.string "Congratulations!\n"
	.string "You have already earned the CONIFER\l"
	.string "BADGE.\p"
	.string "We can't let you participate when you\n"
	.string "already have this TOURNAMENT's BADGE…$"

FirwealdCity_TournamentHallLobby_EventScript_Attendant_Text_1:
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
	.string "We hope to see you again!$"

FirwealdCity_TournamentHallLobby_EventScript_JoinTournament_Text_0:
	.string "Before you join the TOURNAMENT,\n"
	.string "you must save your data. Is that okay?$"

FirwealdCity_TournamentHallLobby_EventScript_Maniac_Text_0:
	.string "Competitive POKéMON battles\n"
	.string "are so cool!$"

FirwealdCity_TournamentHallLobby_EventScript_Beauty_Text_0:
	.string "I've heard PHYLLOS is a very strong\n"
	.string "TOURNAMENT MASTER.$"

FirwealdCity_TournamentHallLobby_Text_WelcomeToFirwealdCityTounamentHall::
	.string "Welcome to FIRWEALD CITY's\n"
	.string "TOURNAMENT HALL.\p"
	.string "Would you like to sign up for\n"
	.string "a tournament?$"
