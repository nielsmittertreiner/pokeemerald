SunsetTown_PlayerHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_SUNSET_TOWN_STATE, 0
	goto_if_gt SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 1, 5, 6
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SUNSET_TOWN_STATE, 0, SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lock
	turnobject 1, DIR_EAST
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 32
	msgbox SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_PlayerHouse_1F_Movement_PlayerWalksToMom
	waitmovement 0
	load_speech_bubble 1
	msgbox SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
	closemessage
	destroy_speech_bubble
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_PlayerHouse_1F_Movement_PlayerWalkBack
	waitmovement 0
	applymovement 1, SunsetTown_PlayerHouse_1F_Movement_MomWalksToChair
	waitmovement 0
	setvar VAR_SUNSET_TOWN_STATE, 1
	release
	end


SunsetTown_PlayerHouse_1F_EventScript_Mom::
	lock
	faceplayer
	load_speech_bubble 1
	msgbox SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_0, MSGBOX_YESNO
	destroy_speech_bubble
	closemessage
	switch VAR_RESULT
	case YES, SunsetTown_PlayerHouse_1F_EventScript_Mom_3
	case NO, SunsetTown_PlayerHouse_1F_EventScript_Mom_4
	case MULTI_B_PRESSED, SunsetTown_PlayerHouse_1F_EventScript_Mom_5
SunsetTown_PlayerHouse_1F_EventScript_Mom_1:
	compare VAR_SUNSET_TOWN_STATE, 1
	goto_if_eq SunsetTown_PlayerHouse_1F_EventScript_Mom_7
	msgbox SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_3, MSGBOX_NPC
SunsetTown_PlayerHouse_1F_EventScript_Mom_6:
	end

SunsetTown_PlayerHouse_1F_EventScript_Mom_3:
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	load_speech_bubble 1
	msgbox SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_1
	destroy_speech_bubble
	closemessage
	release
	end

SunsetTown_PlayerHouse_1F_EventScript_Mom_4:
	goto SunsetTown_PlayerHouse_1F_EventScript_Mom_1

SunsetTown_PlayerHouse_1F_EventScript_Mom_5:
	goto SunsetTown_PlayerHouse_1F_EventScript_Mom_1

SunsetTown_PlayerHouse_1F_EventScript_Mom_7:
	msgbox SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_2, MSGBOX_NPC
	goto SunsetTown_PlayerHouse_1F_EventScript_Mom_6


SunsetTown_PlayerHouse_1F_Movement_PlayerWalksToMom:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SunsetTown_PlayerHouse_1F_Movement_PlayerWalkBack:
	lock_facing_direction
	walk_right
	step_end

SunsetTown_PlayerHouse_1F_Movement_MomWalksToChair:
	walk_right
	walk_down
	face_left
	step_end

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "Come here, quickly!$"

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "I've heard DAD has something for you.\n"
	.string "Perhaps you should go see him.\p"
	.string "I have no idea what it is, though…$"

SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_0:
	.string "Do you want to rest here\n"
	.string "for a while, dear?$"

SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_1:
	.string "Phew, that must be refreshing right?\p"
	.string "Now have fun on your adventure\n"
	.string "dear! Stay safe.$"

SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_2:
	.string "What would your dad have\n"
	.string "for you?$"

SunsetTown_PlayerHouse_1F_EventScript_Mom_Text_3:
	.string "Have fun on your adventure,\n"
	.string "dear! Stay safe out there.$"
