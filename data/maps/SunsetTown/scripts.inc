SunsetTown_MapScripts::
# 4 "data/maps/SunsetTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SunsetTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 12 "data/maps/SunsetTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SunsetTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 15 "data/maps/SunsetTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunsetTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunsetTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/SunsetTown/scripts.pory"
	setrespawn HEAL_LOCATION_SUNSET_TOWN
# 6 "data/maps/SunsetTown/scripts.pory"
	setflag FLAG_VISITED_SUNSET_TOWN
# 7 "data/maps/SunsetTown/scripts.pory"
	compare VAR_SUNSET_TOWN_STATE, 3
	goto_if_eq SunsetTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SunsetTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 9 "data/maps/SunsetTown/scripts.pory"
	setvar VAR_SUNSET_TOWN_FOLLOWER_STATE, 1
	return

SunsetTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 13 "data/maps/SunsetTown/scripts.pory"
	map_script_2 VAR_SUNSET_TOWN_STATE, 2, SunsetTown_EventScript_SetUpObjects
	.2byte 0

SunsetTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 16 "data/maps/SunsetTown/scripts.pory"
	map_script_2 VAR_SUNSET_TOWN_STATE, 2, SunsetTown_EventScript_TakeTheLead
	.2byte 0


SunsetTown_EventScript_SetUpObjects::
# 21 "data/maps/SunsetTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return


SunsetTown_EventScript_FollowerScript::
# 25 "data/maps/SunsetTown/scripts.pory"
	lock
# 26 "data/maps/SunsetTown/scripts.pory"
	facefollower
# 27 "data/maps/SunsetTown/scripts.pory"
	loadspeechtail FALSE, LOCALID_FOLLOWER
# 28 "data/maps/SunsetTown/scripts.pory"
	switch VAR_SUNSET_TOWN_FOLLOWER_STATE
# 30 "data/maps/SunsetTown/scripts.pory"
	case 1, SunsetTown_EventScript_FollowerScript_3
# 35 "data/maps/SunsetTown/scripts.pory"
	case 2, SunsetTown_EventScript_FollowerScript_4
# 39 "data/maps/SunsetTown/scripts.pory"
	case 3, SunsetTown_EventScript_FollowerScript_5
SunsetTown_EventScript_FollowerScript_1:
# 44 "data/maps/SunsetTown/scripts.pory"
	destroyspeechtail
# 45 "data/maps/SunsetTown/scripts.pory"
	closemessage
# 46 "data/maps/SunsetTown/scripts.pory"
	release
	end

SunsetTown_EventScript_FollowerScript_3:
# 31 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_FollowerScript_Text_0
	goto SunsetTown_EventScript_FollowerScript_1

SunsetTown_EventScript_FollowerScript_4:
# 36 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_FollowerScript_Text_1
	goto SunsetTown_EventScript_FollowerScript_1

SunsetTown_EventScript_FollowerScript_5:
# 40 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_FollowerScript_Text_2
	goto SunsetTown_EventScript_FollowerScript_1


SunsetTown_EventScript_TownSign::
# 51 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


SunsetTown_EventScript_PlayerHouseSign::
# 56 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_PlayerHouseSign_Text_0, MSGBOX_SIGN
	return


SunsetTown_EventScript_JuliaHouseSign::
# 60 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_JuliaHouseSign_Text_0, MSGBOX_SIGN
	return


SunsetTown_EventScript_LabSign::
# 64 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_LabSign_Text_0, MSGBOX_SIGN
	return


SunsetTown_EventScript_FatMan::
# 69 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_FatMan_Text_0, MSGBOX_NPC
	return


SunsetTown_EventScript_Lass::
# 76 "data/maps/SunsetTown/scripts.pory"
	lock
# 77 "data/maps/SunsetTown/scripts.pory"
	faceplayer
# 78 "data/maps/SunsetTown/scripts.pory"
	minimsg SunsetTown_EventScript_Lass_Text_0, 1, 7
# 79 "data/maps/SunsetTown/scripts.pory"
	minimsg SunsetTown_EventScript_Lass_Text_0, 5, 12
# 80 "data/maps/SunsetTown/scripts.pory"
	minimsg SunsetTown_EventScript_Lass_Text_0, 15, 14
# 81 "data/maps/SunsetTown/scripts.pory"
	minimsg SunsetTown_EventScript_Lass_Text_0, 21, 8
# 82 "data/maps/SunsetTown/scripts.pory"
	loadspeechtail TRUE, 2
# 83 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_Lass_Text_1, MSGBOX_DEFAULT, TRUE
# 84 "data/maps/SunsetTown/scripts.pory"
	closelastminimessage
# 85 "data/maps/SunsetTown/scripts.pory"
	waitbuttonpress
# 86 "data/maps/SunsetTown/scripts.pory"
	closelastminimessage
# 87 "data/maps/SunsetTown/scripts.pory"
	waitbuttonpress
# 88 "data/maps/SunsetTown/scripts.pory"
	closelastminimessage
# 89 "data/maps/SunsetTown/scripts.pory"
	waitbuttonpress
# 90 "data/maps/SunsetTown/scripts.pory"
	closelastminimessage
# 91 "data/maps/SunsetTown/scripts.pory"
	destroyspeechtail
# 92 "data/maps/SunsetTown/scripts.pory"
	closemessage
# 93 "data/maps/SunsetTown/scripts.pory"
	release
	end


SunsetTown_EventScript_ProfessorConifer::
# 98 "data/maps/SunsetTown/scripts.pory"
	lock
# 99 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_ProfessorConifer_Text_0, MSGBOX_NPC
# 104 "data/maps/SunsetTown/scripts.pory"
	opendoor 15, 6
# 105 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, Common_Movement_FaceUp
# 106 "data/maps/SunsetTown/scripts.pory"
	waitdooranim
# 107 "data/maps/SunsetTown/scripts.pory"
	switch VAR_FACING
# 109 "data/maps/SunsetTown/scripts.pory"
	case DIR_NORTH, SunsetTown_EventScript_ProfessorConifer_3
# 114 "data/maps/SunsetTown/scripts.pory"
	case DIR_WEST, SunsetTown_EventScript_ProfessorConifer_4
# 119 "data/maps/SunsetTown/scripts.pory"
	case DIR_EAST, SunsetTown_EventScript_ProfessorConifer_5
SunsetTown_EventScript_ProfessorConifer_1:
# 125 "data/maps/SunsetTown/scripts.pory"
	closedoor 15, 6
# 126 "data/maps/SunsetTown/scripts.pory"
	waitdooranim
# 127 "data/maps/SunsetTown/scripts.pory"
	warp MAP_SUNSET_TOWN_PROFESSOR_CONIFER_LAB, 0, 12, 9
# 128 "data/maps/SunsetTown/scripts.pory"
	waitstate
	end

SunsetTown_EventScript_ProfessorConifer_3:
# 110 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, SunsetTown_Movement_ConiferWalkIntoDoor
# 111 "data/maps/SunsetTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_Movement_FollowProfessorFacingNorth
# 112 "data/maps/SunsetTown/scripts.pory"
	waitmovement 0
	goto SunsetTown_EventScript_ProfessorConifer_1

SunsetTown_EventScript_ProfessorConifer_4:
# 115 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, SunsetTown_Movement_ConiferWalkIntoDoor
# 116 "data/maps/SunsetTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_Movement_FollowProfessorFacingWest
# 117 "data/maps/SunsetTown/scripts.pory"
	waitmovement 0
	goto SunsetTown_EventScript_ProfessorConifer_1

SunsetTown_EventScript_ProfessorConifer_5:
# 120 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, SunsetTown_Movement_ConiferWalkIntoDoor
# 121 "data/maps/SunsetTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_Movement_FollowProfessorFacingEast
# 122 "data/maps/SunsetTown/scripts.pory"
	waitmovement 0
	goto SunsetTown_EventScript_ProfessorConifer_1


SunsetTown_EventScript_BlockPlayer::
# 133 "data/maps/SunsetTown/scripts.pory"
	lock
# 134 "data/maps/SunsetTown/scripts.pory"
	playse SE_PIN
# 135 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, Common_Movement_FaceDown
# 136 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, Common_Movement_ExclamationMark
# 137 "data/maps/SunsetTown/scripts.pory"
	loadspeechtail FALSE, 3
# 138 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_BlockPlayer_Text_0
# 139 "data/maps/SunsetTown/scripts.pory"
	destroyspeechtail
# 140 "data/maps/SunsetTown/scripts.pory"
	closemessage
# 141 "data/maps/SunsetTown/scripts.pory"
	waitmovement 0
# 142 "data/maps/SunsetTown/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 143 "data/maps/SunsetTown/scripts.pory"
	switch VAR_TEMP_1
# 145 "data/maps/SunsetTown/scripts.pory"
	case 8, SunsetTown_EventScript_BlockPlayer_3
# 148 "data/maps/SunsetTown/scripts.pory"
	case 9, SunsetTown_EventScript_BlockPlayer_4
# 151 "data/maps/SunsetTown/scripts.pory"
	case 10, SunsetTown_EventScript_BlockPlayer_5
# 154 "data/maps/SunsetTown/scripts.pory"
	case 11, SunsetTown_EventScript_BlockPlayer_6
SunsetTown_EventScript_BlockPlayer_1:
# 158 "data/maps/SunsetTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 159 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, SunsetTown_Movement_WalkToPlayerX
# 160 "data/maps/SunsetTown/scripts.pory"
	waitmovement 0
# 161 "data/maps/SunsetTown/scripts.pory"
	loadspeechtail FALSE, 3
# 162 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_BlockPlayer_Text_1
# 165 "data/maps/SunsetTown/scripts.pory"
	destroyspeechtail
# 166 "data/maps/SunsetTown/scripts.pory"
	closemessage
# 167 "data/maps/SunsetTown/scripts.pory"
	warp MAP_SUNSET_TOWN_PROFESSOR_CONIFER_LAB, 0, 12, 9
# 168 "data/maps/SunsetTown/scripts.pory"
	waitstate
	return

SunsetTown_EventScript_BlockPlayer_3:
# 146 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, SunsetTown_Movement_WalkToPlayerYOne
# 147 "data/maps/SunsetTown/scripts.pory"
	waitmovement 0
	goto SunsetTown_EventScript_BlockPlayer_1

SunsetTown_EventScript_BlockPlayer_4:
# 149 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, SunsetTown_Movement_WalkToPlayerYTwo
# 150 "data/maps/SunsetTown/scripts.pory"
	waitmovement 0
	goto SunsetTown_EventScript_BlockPlayer_1

SunsetTown_EventScript_BlockPlayer_5:
# 152 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, SunsetTown_Movement_WalkToPlayerYThree
# 153 "data/maps/SunsetTown/scripts.pory"
	waitmovement 0
	goto SunsetTown_EventScript_BlockPlayer_1

SunsetTown_EventScript_BlockPlayer_6:
# 155 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, SunsetTown_Movement_WalkToPlayerYFour
# 156 "data/maps/SunsetTown/scripts.pory"
	waitmovement 0
	goto SunsetTown_EventScript_BlockPlayer_1


SunsetTown_EventScript_TakeTheLead::
# 172 "data/maps/SunsetTown/scripts.pory"
	lock
# 173 "data/maps/SunsetTown/scripts.pory"
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_DOWN
# 174 "data/maps/SunsetTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 175 "data/maps/SunsetTown/scripts.pory"
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
# 176 "data/maps/SunsetTown/scripts.pory"
	waitmovement 0
# 177 "data/maps/SunsetTown/scripts.pory"
	loadspeechtail FALSE, 3
# 178 "data/maps/SunsetTown/scripts.pory"
	msgbox SunsetTown_EventScript_TakeTheLead_Text_0
# 181 "data/maps/SunsetTown/scripts.pory"
	destroyspeechtail
# 182 "data/maps/SunsetTown/scripts.pory"
	closemessage
# 183 "data/maps/SunsetTown/scripts.pory"
	loadword 0, SunsetTown_EventScript_FollowerScript
# 184 "data/maps/SunsetTown/scripts.pory"
	setfollower 3, FOLLOWER_FLAG_CUSTOM_FOLLOW_SCRIPT
# 185 "data/maps/SunsetTown/scripts.pory"
	setflag FLAG_DISABLE_ENCOUNTERS
# 186 "data/maps/SunsetTown/scripts.pory"
	setflag FLAG_HIDE_SUNSET_TOWN_LAB_PROF_CONIFER
# 187 "data/maps/SunsetTown/scripts.pory"
	setvar VAR_SUNSET_TOWN_STATE, 3
# 188 "data/maps/SunsetTown/scripts.pory"
	setvar VAR_CEDARRED_TOWN_STATE, 0
# 189 "data/maps/SunsetTown/scripts.pory"
	setvar VAR_SUNSET_TOWN_FOLLOWER_STATE, 1
	end


# 193 "data/maps/SunsetTown/scripts.pory"
SunsetTown_Movement_ConiferWalkIntoDoor:
# 194 "data/maps/SunsetTown/scripts.pory"
	walk_up
# 195 "data/maps/SunsetTown/scripts.pory"
	set_invisible
	step_end

# 198 "data/maps/SunsetTown/scripts.pory"
SunsetTown_Movement_FollowProfessorFacingNorth:
# 199 "data/maps/SunsetTown/scripts.pory"
	walk_up
# 199 "data/maps/SunsetTown/scripts.pory"
	walk_up
# 200 "data/maps/SunsetTown/scripts.pory"
	set_invisible
	step_end

# 203 "data/maps/SunsetTown/scripts.pory"
SunsetTown_Movement_FollowProfessorFacingWest:
# 204 "data/maps/SunsetTown/scripts.pory"
	walk_left
# 205 "data/maps/SunsetTown/scripts.pory"
	walk_up
# 206 "data/maps/SunsetTown/scripts.pory"
	set_invisible
	step_end

# 209 "data/maps/SunsetTown/scripts.pory"
SunsetTown_Movement_FollowProfessorFacingEast:
# 210 "data/maps/SunsetTown/scripts.pory"
	walk_right
# 211 "data/maps/SunsetTown/scripts.pory"
	walk_up
# 212 "data/maps/SunsetTown/scripts.pory"
	set_invisible
	step_end

# 215 "data/maps/SunsetTown/scripts.pory"
SunsetTown_Movement_WalkToPlayerYOne:
# 216 "data/maps/SunsetTown/scripts.pory"
	walk_down
	step_end

# 219 "data/maps/SunsetTown/scripts.pory"
SunsetTown_Movement_WalkToPlayerYTwo:
# 220 "data/maps/SunsetTown/scripts.pory"
	walk_down
# 220 "data/maps/SunsetTown/scripts.pory"
	walk_down
	step_end

# 223 "data/maps/SunsetTown/scripts.pory"
SunsetTown_Movement_WalkToPlayerYThree:
# 224 "data/maps/SunsetTown/scripts.pory"
	walk_down
# 224 "data/maps/SunsetTown/scripts.pory"
	walk_down
# 224 "data/maps/SunsetTown/scripts.pory"
	walk_down
	step_end

# 227 "data/maps/SunsetTown/scripts.pory"
SunsetTown_Movement_WalkToPlayerYFour:
# 228 "data/maps/SunsetTown/scripts.pory"
	walk_down
# 228 "data/maps/SunsetTown/scripts.pory"
	walk_down
# 228 "data/maps/SunsetTown/scripts.pory"
	walk_down
# 228 "data/maps/SunsetTown/scripts.pory"
	walk_down
	step_end

# 231 "data/maps/SunsetTown/scripts.pory"
SunsetTown_Movement_WalkToPlayerX:
# 232 "data/maps/SunsetTown/scripts.pory"
	walk_right
# 232 "data/maps/SunsetTown/scripts.pory"
	walk_right
	step_end

SunsetTown_EventScript_FollowerScript_Text_0:
# 31 "data/maps/SunsetTown/scripts.pory"
	.string "We need to get to CEDARRED TOWN\n"
	.string "as soon as possible!\p"
	.string "What if things got out of\n"
	.string "hand already?$"

SunsetTown_EventScript_FollowerScript_Text_1:
# 36 "data/maps/SunsetTown/scripts.pory"
	.string "We can't be hanging at ROUTE 401\n"
	.string "for too long now…\p"
	.string "Let's keep going!$"

SunsetTown_EventScript_FollowerScript_Text_2:
# 40 "data/maps/SunsetTown/scripts.pory"
	.string "Alright, this is CEDARRED TOWN…\n"
	.string "Let's find the LOGGERS CABIN.\p"
	.string "It should be at the far EAST of town.$"

SunsetTown_EventScript_TownSign_Text_0:
# 51 "data/maps/SunsetTown/scripts.pory"
	.string "{COLOR BLUE}SUNSET TOWN\n"
	.string "{COLOR RED}“A town that can be shaded any hue.”$"

SunsetTown_EventScript_PlayerHouseSign_Text_0:
# 56 "data/maps/SunsetTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"

SunsetTown_EventScript_JuliaHouseSign_Text_0:
# 60 "data/maps/SunsetTown/scripts.pory"
	.string "JULIA's HOUSE$"

SunsetTown_EventScript_LabSign_Text_0:
# 64 "data/maps/SunsetTown/scripts.pory"
	.string "PROFESSOR CONIFER'S\n"
	.string "POKéMON LAB$"

SunsetTown_EventScript_FatMan_Text_0:
# 69 "data/maps/SunsetTown/scripts.pory"
	.string "I bet you're playing this ROM-HACK\n"
	.string "on an EMULATOR!\p"
	.string "The power of emulation truly\n"
	.string "is staggering!$"

SunsetTown_EventScript_Lass_Text_0:
# 78 "data/maps/SunsetTown/scripts.pory"
	.string "Hello :D$"

SunsetTown_EventScript_Lass_Text_1:
# 83 "data/maps/SunsetTown/scripts.pory"
	.string "America ya :D$"

SunsetTown_EventScript_ProfessorConifer_Text_0:
# 99 "data/maps/SunsetTown/scripts.pory"
	.string "Oh hey there {PLAYER}.\n"
	.string "You're finally here!\p"
	.string "Come in quickly, something\n"
	.string "happened not too far away\l"
	.string "from here and I need your help.$"

SunsetTown_EventScript_BlockPlayer_Text_0:
# 138 "data/maps/SunsetTown/scripts.pory"
	.string "Oh hey there {PLAYER}.$"

SunsetTown_EventScript_BlockPlayer_Text_1:
# 162 "data/maps/SunsetTown/scripts.pory"
	.string "Come in quickly, something\n"
	.string "happened not too far away\l"
	.string "from here and I need your help.$"

SunsetTown_EventScript_TakeTheLead_Text_0:
# 178 "data/maps/SunsetTown/scripts.pory"
	.string "I'll let you take the lead.\n"
	.string "You're well of age to be responsible!\p"
	.string "To CEDARRED TOWN we go!$"
