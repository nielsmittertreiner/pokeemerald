SunsetTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SunsetTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SunsetTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunsetTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunsetTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_SUNSET_TOWN
	setflag FLAG_VISITED_SUNSET_TOWN
	compare VAR_SUNSET_TOWN_STATE, 3
	goto_if_eq SunsetTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SunsetTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setvar VAR_SUNSET_TOWN_FOLLOWER_STATE, 1
	return

SunsetTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_SUNSET_TOWN_STATE, 2, SunsetTown_EventScript_SetUpObjects
	.2byte 0

SunsetTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SUNSET_TOWN_STATE, 2, SunsetTown_EventScript_TakeTheLead
	.2byte 0


SunsetTown_EventScript_SetUpObjects::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return


SunsetTown_EventScript_FollowerScript::
	lock
	facefollower
	load_speech_bubble OBJ_EVENT_ID_FOLLOWER
	switch VAR_SUNSET_TOWN_FOLLOWER_STATE
	case 1, SunsetTown_EventScript_FollowerScript_3
	case 2, SunsetTown_EventScript_FollowerScript_4
	case 3, SunsetTown_EventScript_FollowerScript_5
SunsetTown_EventScript_FollowerScript_1:
	destroy_speech_bubble
	closemessage
	release
	end

SunsetTown_EventScript_FollowerScript_3:
	msgbox SunsetTown_EventScript_FollowerScript_Text_0
	goto SunsetTown_EventScript_FollowerScript_1

SunsetTown_EventScript_FollowerScript_4:
	msgbox SunsetTown_EventScript_FollowerScript_Text_1
	goto SunsetTown_EventScript_FollowerScript_1

SunsetTown_EventScript_FollowerScript_5:
	msgbox SunsetTown_EventScript_FollowerScript_Text_2
	goto SunsetTown_EventScript_FollowerScript_1


SunsetTown_EventScript_TownSign::
	msgbox SunsetTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


SunsetTown_EventScript_PlayerHouseSign::
	msgbox SunsetTown_EventScript_PlayerHouseSign_Text_0, MSGBOX_SIGN
	return


SunsetTown_EventScript_AlexHouseSign::
	msgbox SunsetTown_EventScript_AlexHouseSign_Text_0, MSGBOX_SIGN
	return


SunsetTown_EventScript_LabSign::
	msgbox SunsetTown_EventScript_LabSign_Text_0, MSGBOX_SIGN
	return


SunsetTown_EventScript_FatMan::
	msgbox SunsetTown_EventScript_FatMan_Text_0, MSGBOX_NPC
	return


SunsetTown_EventScript_Lass::
	msgbox SunsetTown_EventScript_Lass_Text_0, MSGBOX_NPC
	return


SunsetTown_EventScript_ProfessorConifer::
	lock
	msgbox SunsetTown_EventScript_ProfessorConifer_Text_0, MSGBOX_NPC
	opendoor 15, 6
	applymovement 3, Common_Movement_FaceUp
	waitdooranim
	switch VAR_FACING
	case DIR_NORTH, SunsetTown_EventScript_ProfessorConifer_3
	case DIR_WEST, SunsetTown_EventScript_ProfessorConifer_4
	case DIR_EAST, SunsetTown_EventScript_ProfessorConifer_5
SunsetTown_EventScript_ProfessorConifer_1:
	closedoor 15, 6
	waitdooranim
	warp MAP_SUNSET_TOWN_PROFESSOR_CONIFER_LAB, 0, 12, 9
	waitstate
	end

SunsetTown_EventScript_ProfessorConifer_3:
	applymovement 3, SunsetTown_Movement_ConiferWalkIntoDoor
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_Movement_FollowProfessorFacingNorth
	waitmovement 0
	goto SunsetTown_EventScript_ProfessorConifer_1

SunsetTown_EventScript_ProfessorConifer_4:
	applymovement 3, SunsetTown_Movement_ConiferWalkIntoDoor
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_Movement_FollowProfessorFacingWest
	waitmovement 0
	goto SunsetTown_EventScript_ProfessorConifer_1

SunsetTown_EventScript_ProfessorConifer_5:
	applymovement 3, SunsetTown_Movement_ConiferWalkIntoDoor
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_Movement_FollowProfessorFacingEast
	waitmovement 0
	goto SunsetTown_EventScript_ProfessorConifer_1


SunsetTown_EventScript_BlockPlayer::
	lock
	playse SE_PIN
	applymovement 3, Common_Movement_FaceDown
	applymovement 3, Common_Movement_ExclamationMark
	load_speech_bubble 3
	msgbox SunsetTown_EventScript_BlockPlayer_Text_0
	destroy_speech_bubble
	closemessage
	waitmovement 0
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_1
	case 8, SunsetTown_EventScript_BlockPlayer_3
	case 9, SunsetTown_EventScript_BlockPlayer_4
	case 10, SunsetTown_EventScript_BlockPlayer_5
	case 11, SunsetTown_EventScript_BlockPlayer_6
SunsetTown_EventScript_BlockPlayer_1:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	applymovement 3, SunsetTown_Movement_WalkToPlayerX
	waitmovement 0
	load_speech_bubble 3
	msgbox SunsetTown_EventScript_BlockPlayer_Text_1
	destroy_speech_bubble
	closemessage
	warp MAP_SUNSET_TOWN_PROFESSOR_CONIFER_LAB, 0, 12, 9
	waitstate
	return

SunsetTown_EventScript_BlockPlayer_3:
	applymovement 3, SunsetTown_Movement_WalkToPlayerYOne
	waitmovement 0
	goto SunsetTown_EventScript_BlockPlayer_1

SunsetTown_EventScript_BlockPlayer_4:
	applymovement 3, SunsetTown_Movement_WalkToPlayerYTwo
	waitmovement 0
	goto SunsetTown_EventScript_BlockPlayer_1

SunsetTown_EventScript_BlockPlayer_5:
	applymovement 3, SunsetTown_Movement_WalkToPlayerYThree
	waitmovement 0
	goto SunsetTown_EventScript_BlockPlayer_1

SunsetTown_EventScript_BlockPlayer_6:
	applymovement 3, SunsetTown_Movement_WalkToPlayerYFour
	waitmovement 0
	goto SunsetTown_EventScript_BlockPlayer_1


SunsetTown_EventScript_TakeTheLead::
	lock
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_DOWN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	applymovement 3, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	load_speech_bubble 3
	msgbox SunsetTown_EventScript_TakeTheLead_Text_0
	destroy_speech_bubble
	closemessage
	loadword 0, SunsetTown_EventScript_FollowerScript
	setfollower 3, FOLLOWER_FLAG_CUSTOM_FOLLOW_SCRIPT
	setflag FLAG_DISABLE_ENCOUNTERS
	setflag FLAG_HIDE_SUNSET_TOWN_LAB_PROF_CONIFER
	setvar VAR_SUNSET_TOWN_STATE, 3
	setvar VAR_CEDARRED_TOWN_STATE, 0
	setvar VAR_SUNSET_TOWN_FOLLOWER_STATE, 1
	end


SunsetTown_Movement_ConiferWalkIntoDoor:
	walk_up
	set_invisible
	step_end

SunsetTown_Movement_FollowProfessorFacingNorth:
	walk_up
	walk_up
	set_invisible
	step_end

SunsetTown_Movement_FollowProfessorFacingWest:
	walk_left
	walk_up
	set_invisible
	step_end

SunsetTown_Movement_FollowProfessorFacingEast:
	walk_right
	walk_up
	set_invisible
	step_end

SunsetTown_Movement_WalkToPlayerYOne:
	walk_down
	step_end

SunsetTown_Movement_WalkToPlayerYTwo:
	walk_down
	walk_down
	step_end

SunsetTown_Movement_WalkToPlayerYThree:
	walk_down
	walk_down
	walk_down
	step_end

SunsetTown_Movement_WalkToPlayerYFour:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SunsetTown_Movement_WalkToPlayerX:
	walk_right
	walk_right
	step_end

SunsetTown_EventScript_FollowerScript_Text_0:
	.string "We need to get to CEDARRED TOWN\n"
	.string "as soon as possible!\p"
	.string "What if things got out of\n"
	.string "hand already?$"

SunsetTown_EventScript_FollowerScript_Text_1:
	.string "We can't be hanging at ROUTE 401\n"
	.string "for too long now…\p"
	.string "Let's keep going!$"

SunsetTown_EventScript_FollowerScript_Text_2:
	.string "Alright, this is CEDARRED TOWN…\n"
	.string "Let's find the LOGGERS CABIN.\p"
	.string "It should be at the far EAST of town.$"

SunsetTown_EventScript_TownSign_Text_0:
	.string "SUNSET TOWN\n"
	.string "“A town that can be shaded any hue.”$"

SunsetTown_EventScript_PlayerHouseSign_Text_0:
	.string "{PLAYER}'s HOUSE$"

SunsetTown_EventScript_AlexHouseSign_Text_0:
	.string "ALEX's HOUSE$"

SunsetTown_EventScript_LabSign_Text_0:
	.string "PROFESSOR CONIFER'S\n"
	.string "POKéMON LAB$"

SunsetTown_EventScript_FatMan_Text_0:
	.string "I bet you're playing this ROM-HACK\n"
	.string "on an EMULATOR!\p"
	.string "The power of emulation truly\n"
	.string "is staggering!$"

SunsetTown_EventScript_Lass_Text_0:
	.string "The flowers of SUNSET TOWN are so\n"
	.string "beautiful!\p"
	.string "I love them!$"

SunsetTown_EventScript_ProfessorConifer_Text_0:
	.string "Oh hey there {PLAYER}.\n"
	.string "You're finally here!\p"
	.string "Come in quickly, something\n"
	.string "happened not too far away\l"
	.string "from here and I need your help.$"

SunsetTown_EventScript_BlockPlayer_Text_0:
	.string "Oh hey there {PLAYER}.$"

SunsetTown_EventScript_BlockPlayer_Text_1:
	.string "Come in quickly, something\n"
	.string "happened not too far away\l"
	.string "from here and I need your help.$"

SunsetTown_EventScript_TakeTheLead_Text_0:
	.string "I'll let you take the lead.\n"
	.string "You're well of age to be responsible!\p"
	.string "To CEDARRED TOWN we go!$"
