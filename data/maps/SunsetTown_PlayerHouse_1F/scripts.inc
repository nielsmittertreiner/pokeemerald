SunsetTown_PlayerHouse_1F_MapScripts::
# 4 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 10 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	compare VAR_SUNSET_TOWN_STATE, 0
	goto_if_gt SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 6 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	setobjectxyperm 1, 5, 6
# 7 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	map_script_2 VAR_SUNSET_TOWN_STATE, 0, SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 12 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	lock
# 13 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	turnobject 1, DIR_EAST
# 14 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	playse SE_PIN
# 15 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 16 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	waitmovement 0
# 17 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	delay 32
# 18 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	msgbox SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
# 19 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 20 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_PlayerHouse_1F_Movement_PlayerWalksToMom
# 21 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	waitmovement 0
# 22 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	loadspeechtail FALSE, 1
# 23 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	msgbox SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
# 26 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 27 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	destroyspeechtail
# 28 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_PlayerHouse_1F_Movement_PlayerWalkBack
# 29 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	waitmovement 0
# 30 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	applymovement 1, SunsetTown_PlayerHouse_1F_Movement_MomWalksToChair
# 31 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	waitmovement 0
# 32 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	setvar VAR_SUNSET_TOWN_STATE, 1
# 33 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	release
	end


SunsetTown_PlayerHouse_1F_EventScript_Mom::
# 40 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	lock
# 41 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	faceplayer
# 42 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	loadspeechtail FALSE, 1
# 43 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	msgbox SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_0, MSGBOX_YESNO
# 45 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	destroyspeechtail
# 46 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 47 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	switch VAR_RESULT
# 48 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	case YES, SunsetTown_PlayerHouse_1F_EventScript_Mom_3
# 62 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	case NO, SunsetTown_PlayerHouse_1F_EventScript_Mom_4
# 64 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	case MULTI_B_PRESSED, SunsetTown_PlayerHouse_1F_EventScript_Mom_5
SunsetTown_PlayerHouse_1F_EventScript_Mom_1:
# 67 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	compare VAR_SUNSET_TOWN_STATE, 1
	goto_if_eq SunsetTown_PlayerHouse_1F_EventScript_Mom_7
# 74 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	msgbox SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_3, MSGBOX_NPC
SunsetTown_PlayerHouse_1F_EventScript_Mom_6:
	end

SunsetTown_PlayerHouse_1F_EventScript_Mom_3:
# 49 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 50 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	playfanfare MUS_HEAL
# 51 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	waitfanfare
# 52 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	special HealPlayerParty
# 53 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 54 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	loadspeechtail FALSE, 1
# 55 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	msgbox SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_1
# 58 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	destroyspeechtail
# 59 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	closemessage
# 60 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	release
	end

SunsetTown_PlayerHouse_1F_EventScript_Mom_4:
	goto SunsetTown_PlayerHouse_1F_EventScript_Mom_1

SunsetTown_PlayerHouse_1F_EventScript_Mom_5:
	goto SunsetTown_PlayerHouse_1F_EventScript_Mom_1

SunsetTown_PlayerHouse_1F_EventScript_Mom_7:
# 69 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	msgbox SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_2, MSGBOX_NPC
	goto SunsetTown_PlayerHouse_1F_EventScript_Mom_6


# 80 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
SunsetTown_PlayerHouse_1F_Movement_PlayerWalksToMom:
# 81 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	walk_down
# 81 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	walk_down
# 82 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	walk_left
# 82 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	walk_left
# 82 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	walk_left
# 82 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	walk_left
	step_end

# 85 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
SunsetTown_PlayerHouse_1F_Movement_PlayerWalkBack:
# 86 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	lock_facing_direction
# 87 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	walk_right
	step_end

# 90 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
SunsetTown_PlayerHouse_1F_Movement_MomWalksToChair:
# 91 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	walk_right
# 92 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	walk_down
# 93 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	face_left
	step_end

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
# 18 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	.string "Come here, quickly!$"

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
# 23 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	.string "I've heard DAD has something for you.\n"
	.string "Perhaps you should go see him.\p"
	.string "I have no idea what it is, though…$"

SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_0:
# 43 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	.string "Do you want to rest here\n"
	.string "for a while, dear?$"

SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_1:
# 55 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	.string "Phew, that must be refreshing right?\p"
	.string "Now have fun on your adventure\n"
	.string "dear! Stay safe.$"

SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_2:
# 69 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	.string "What would your dad have\n"
	.string "for you?$"

SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_3:
# 74 "data/maps/SunsetTown_PlayerHouse_1F/scripts.pory"
	.string "Have fun on your adventure,\n"
	.string "dear! Stay safe out there.$"
