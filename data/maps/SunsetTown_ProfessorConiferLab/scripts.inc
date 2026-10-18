SunsetTown_ProfessorConiferLab_MapScripts::
# 11 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 6 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 19 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 12 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	goto_if_set FLAG_BLOCK_SUNSET_TOWN_NURSERY, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 13 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setobjectxyperm 1, 2, 2
# 14 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setobjectxyperm 2, 3, 2
# 15 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
# 16 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	map_script_2 VAR_SUNSET_TOWN_STATE, 1, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 8 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setobjectxy 3, 12, 8
	return

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 20 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	map_script_2 VAR_SUNSET_TOWN_STATE, 1, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 21 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	lock
# 22 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	applymovement 3, SunsetTown_ProfessorConiferLab_Movement_ConiferWalkToMachine
# 23 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_ProfessorConiferLab_Movement_PlayerWalkToMachine
# 24 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	waitmovement 0
# 25 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	turnobject 3, DIR_EAST
# 26 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	delay 16
# 27 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	loadspeechtail FALSE, 3
# 28 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
# 36 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	destroyspeechtail
# 37 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	closemessage
# 38 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	addobject 3, MAP_SUNSET_TOWN
# 39 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setvar VAR_SUNSET_TOWN_STATE, 2
# 40 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	warp MAP_SUNSET_TOWN, 0xFF, 15, 8
# 41 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	waitstate
	end


SunsetTown_ProfessorConiferLab_EventScript_Conifer::
# 48 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 1
	goto_if_eq SunsetTown_ProfessorConiferLab_EventScript_Conifer_2
# 99 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_5, MSGBOX_NPC
	end

SunsetTown_ProfessorConiferLab_EventScript_Conifer_2:
# 49 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	lock
# 50 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	faceplayer
# 51 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	playse SE_PIN
# 52 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	applymovement 3, Common_Movement_ExclamationMark
# 53 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	waitmovement 0
# 54 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	loadspeechtail FALSE, 3
# 55 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_0
# 62 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	destroyspeechtail
# 63 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	closemessage
# 64 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 65 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_1
# 67 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	waitfanfare
# 68 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	closemessage
# 69 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 70 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 71 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 72 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	special EnableNationalPokedex
# 73 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
# 74 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setvar VAR_ACREN_FOREST_STATE, 2
# 75 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	loadspeechtail FALSE, 3
# 76 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_2
# 83 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	destroyspeechtail
# 84 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	closemessage
# 85 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 86 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_3
# 88 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	waitfanfare
# 89 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	closemessage
# 90 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 91 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	loadspeechtail FALSE, 3
# 92 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_4
# 94 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	destroyspeechtail
# 95 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	closemessage
# 96 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	release
	end


SunsetTown_ProfessorConiferLab_EventScript_Scientist1::
# 108 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	goto_if_set FLAG_BLOCK_SUNSET_TOWN_NURSERY, SunsetTown_ProfessorConiferLab_EventScript_Scientist1_3
# 113 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Scientist1_Text_1, MSGBOX_NPC
	end

SunsetTown_ProfessorConiferLab_EventScript_Scientist1_3:
# 109 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Scientist1_Text_0, MSGBOX_NPC
	end


SunsetTown_ProfessorConiferLab_EventScript_Scientist2::
# 120 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	goto_if_set FLAG_BLOCK_SUNSET_TOWN_NURSERY, SunsetTown_ProfessorConiferLab_EventScript_Scientist2_3
# 125 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Scientist2_Text_0, MSGBOX_NPC
	end

SunsetTown_ProfessorConiferLab_EventScript_Scientist2_3:
# 121 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Scientist1_Text_0, MSGBOX_NPC
	end


# 131 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
SunsetTown_ProfessorConiferLab_Movement_ConiferWalkToMachine:
# 132 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	face_up
# 133 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 133 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 133 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 133 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 133 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 133 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 133 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 133 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 133 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
	step_end

# 136 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
SunsetTown_ProfessorConiferLab_Movement_PlayerWalkToMachine:
# 137 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	face_up
# 138 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_up
# 139 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 139 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 139 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 139 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 139 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 139 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 139 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
# 139 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	walk_left
	step_end

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
# 28 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	.string "I just got word of one of my aides.\n"
	.string "It's about a raid in the forest\l"
	.string "nearby CEDARRED TOWN.\p"
	.string "Supposedly the POKéMON who got\n"
	.string "rescued are being held safe in the\l"
	.string "LOGGERS CABIN in CEDARRED TOWN.\p"
	.string "We should take a look and see if all\n"
	.string "is okay there…$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_0:
# 55 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	.string "Hey there, {PLAYER}.\p"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "Oh, I see!\n"
	.string "You don't have a POKéDEX yet.\p"
	.string "Luckily, I have one right here for you.\p"
	.string "Go ahead and take it, it's yours.$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_1:
# 65 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	.string "{PLAYER} received the POKéDEX from\n"
	.string "PROFESSOR CONIFER!$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_2:
# 76 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	.string "Now that you have a POKéDEX, I can\n"
	.string "register you as an official\l"
	.string "POKéMON TRAINER.\p"
	.string "Hold on a minute…\n"
	.string "Do you still have those old shoes?\l"
	.string "Well, I wanted to give you new ones\l"
	.string "anyway…$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_3:
# 86 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	.string "{PLAYER} received the RUNNING SHOES from\n"
	.string "PROFESSOR CONIFER!$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_4:
# 92 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	.string "I think you have some business\n"
	.string "to to now…$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_5:
# 99 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	.string "Hey there, {PLAYER}.\n"
	.string "I see you're finally going on an\l"
	.string "adventure now.\p"
	.string "I won't stop you!\p"
	.string "Have fun and take care of your POKéMON.$"

SunsetTown_ProfessorConiferLab_EventScript_Scientist1_Text_0:
# 109 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	.string "Sorry, but we can't let you in the\n"
	.string "POKéMON NURSERY right now…$"

SunsetTown_ProfessorConiferLab_EventScript_Scientist1_Text_1:
# 113 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	.string "Usually, I operate this big machine\n"
	.string "used for researching POKéMON.\p"
	.string "It's very interesting work to do!$"

SunsetTown_ProfessorConiferLab_EventScript_Scientist2_Text_0:
# 125 "data/maps/SunsetTown_ProfessorConiferLab/scripts.pory"
	.string "Working at PROFESSOR CONIFER's\n"
	.string "NURSERY is very exciting work.\p"
	.string "Learning about POKéMON is so fun.$"
