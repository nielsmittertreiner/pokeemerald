CedarredTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CedarredTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

CedarredTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_CEDARRED_TOWN
	setflag FLAG_VISITED_CEDARRED_TOWN
	compare VAR_SUNSET_TOWN_STATE, 3
	goto_if_eq CedarredTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

CedarredTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setvar VAR_SUNSET_TOWN_FOLLOWER_STATE, 3
	return


CedarredTown_EventScript_TownSign::
	msgbox CedarredTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


CedarredTown_EventScript_LoggersCabinSign::
	msgbox CedarredTown_EventScript_LoggersCabinSign_Text_0, MSGBOX_SIGN
	end


CedarredTown_EventScript_AcrenForestSign::
	msgbox CedarredTown_EventScript_AcrenForestSign_Text_0, MSGBOX_SIGN
	end


CedarredTown_EventScript_LoreMan::
	lock
	faceplayer
	load_speech_bubble 2
	msgbox CedarredTown_EventScript_LoreMan_Text_0, MSGBOX_YESNO
	destroy_speech_bubble
	compare VAR_RESULT, 1
	goto_if_eq CedarredTown_EventScript_LoreMan_1
	msgbox CedarredTown_EventScript_LoreMan_Text_2, MSGBOX_NPC
	end

CedarredTown_EventScript_LoreMan_1:
	msgbox CedarredTown_EventScript_LoreMan_Text_1, MSGBOX_NPC
	end


CedarredTown_EventScript_MartEmployee::
	msgbox CedarredTown_EventScript_MartEmployee_Text_0, MSGBOX_NPC
	end


CedarredTown_EventScript_Boy::
	msgbox CedarredTown_EventScript_Boy_Text_0, MSGBOX_NPC
	end


CedarredTown_EventScript_ShowLoggersCabin::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ExclamationMark
	waitmovement 0
	facefollower
	load_speech_bubble OBJ_EVENT_ID_FOLLOWER
	msgbox CedarredTown_EventScript_ShowLoggersCabin_Text_0
	destroy_speech_bubble
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	special SpawnCameraObject
	switch VAR_TEMP_1
	case 15, CedarredTown_EventScript_ShowLoggersCabin_3
	case 16, CedarredTown_EventScript_ShowLoggersCabin_4
	case 17, CedarredTown_EventScript_ShowLoggersCabin_5
CedarredTown_EventScript_ShowLoggersCabin_1:
	msgbox CedarredTown_EventScript_ShowLoggersCabin_Text_1
	closemessage
	switch VAR_TEMP_1
	case 15, CedarredTown_EventScript_ShowLoggersCabin_8
	case 16, CedarredTown_EventScript_ShowLoggersCabin_9
	case 17, CedarredTown_EventScript_ShowLoggersCabin_10
CedarredTown_EventScript_ShowLoggersCabin_6:
	special RemoveCameraObject
	msgbox CedarredTown_EventScript_ShowLoggersCabin_Text_2, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	setvar VAR_CEDARRED_TOWN_STATE, 1
	release
	end

CedarredTown_EventScript_ShowLoggersCabin_3:
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToCabinOne
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_1

CedarredTown_EventScript_ShowLoggersCabin_4:
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToCabinTwo
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_1

CedarredTown_EventScript_ShowLoggersCabin_5:
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToCabinThree
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_1

CedarredTown_EventScript_ShowLoggersCabin_8:
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToPlayerOne
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_6

CedarredTown_EventScript_ShowLoggersCabin_9:
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToPlayerTwo
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_6

CedarredTown_EventScript_ShowLoggersCabin_10:
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToPlayerThree
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_6


CedarredTown_EventScript_EnterLoggersCabin::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ExclamationMark
	waitmovement 0
	facefollower
	load_speech_bubble OBJ_EVENT_ID_FOLLOWER
	msgbox CedarredTown_EventScript_EnterLoggersCabin_Text_0
	destroy_speech_bubble
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_0
	case 14, CedarredTown_EventScript_EnterLoggersCabin_3
	case 15, CedarredTown_EventScript_EnterLoggersCabin_4
	case 16, CedarredTown_EventScript_EnterLoggersCabin_5
	case 17, CedarredTown_EventScript_EnterLoggersCabin_6
CedarredTown_EventScript_EnterLoggersCabin_1:
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	opendoor 20, 18
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_PlayerWalkToDoor
	applymovement OBJ_EVENT_ID_FOLLOWER, CedarredTown_Movement_ConiferWalkToDoor
	waitmovement 0
	closedoor 20, 18
	waitdooranim
	setvar VAR_CEDARRED_TOWN_STATE, 2
	warp MAP_CEDARRED_TOWN_LOGGERS_CABIN, 0, 6, 8
	waitstate
	end

CedarredTown_EventScript_EnterLoggersCabin_3:
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_PlayerWalkToCabinOne
	applymovement OBJ_EVENT_ID_FOLLOWER, CedarredTown_Movement_ConiferWalkToCabinOne
	goto CedarredTown_EventScript_EnterLoggersCabin_1

CedarredTown_EventScript_EnterLoggersCabin_4:
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_PlayerWalkToCabinTwo
	applymovement OBJ_EVENT_ID_FOLLOWER, CedarredTown_Movement_ConiferWalkToCabinTwo
	goto CedarredTown_EventScript_EnterLoggersCabin_1

CedarredTown_EventScript_EnterLoggersCabin_5:
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_PlayerWalkToCabinThree
	applymovement OBJ_EVENT_ID_FOLLOWER, CedarredTown_Movement_ConiferWalkToCabinThree
	goto CedarredTown_EventScript_EnterLoggersCabin_1

CedarredTown_EventScript_EnterLoggersCabin_6:
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_PlayerWalkToCabinFour
	applymovement OBJ_EVENT_ID_FOLLOWER, CedarredTown_Movement_ConiferWalkToCabinFour
	goto CedarredTown_EventScript_EnterLoggersCabin_1


CedarredTown_EventScript_PreventWander::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ExclamationMark
	waitmovement 0
	facefollower
	load_speech_bubble OBJ_EVENT_ID_FOLLOWER
	msgbox CedarredTown_EventScript_PreventWander_Text_0
	destroy_speech_bubble
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_WalkDown
	waitmovement 0
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_SOUTH
	release
	end


CedarredTown_Movement_CameraToCabinOne:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CedarredTown_Movement_CameraToCabinTwo:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	step_end

CedarredTown_Movement_CameraToCabinThree:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	step_end

CedarredTown_Movement_CameraToPlayerOne:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CedarredTown_Movement_CameraToPlayerTwo:
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CedarredTown_Movement_CameraToPlayerThree:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CedarredTown_Movement_WalkDown:
	walk_down
	walk_down
	step_end

CedarredTown_Movement_PlayerWalkToCabinOne:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_diag_northeast
	walk_right
	walk_right
	step_end

CedarredTown_Movement_PlayerWalkToCabinTwo:
	walk_down
	walk_right
	walk_right
	walk_diag_northeast
	walk_right
	walk_right
	step_end

CedarredTown_Movement_PlayerWalkToCabinThree:
	walk_down
	walk_right
	walk_diag_northeast
	walk_right
	walk_right
	step_end

CedarredTown_Movement_PlayerWalkToCabinFour:
	walk_down
	walk_diag_northeast
	walk_right
	walk_right
	step_end

CedarredTown_Movement_ConiferWalkToCabinOne:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_diag_northeast
	walk_right
	step_end

CedarredTown_Movement_ConiferWalkToCabinTwo:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_diag_northeast
	walk_right
	step_end

CedarredTown_Movement_ConiferWalkToCabinThree:
	walk_down
	walk_down
	walk_right
	walk_diag_northeast
	walk_right
	step_end

CedarredTown_Movement_ConiferWalkToCabinFour:
	walk_down
	walk_down
	walk_diag_northeast
	walk_right
	step_end

CedarredTown_Movement_PlayerWalkToDoor:
	walk_up
	set_invisible
	step_end

CedarredTown_Movement_ConiferWalkToDoor:
	walk_right
	walk_up
	set_invisible
	step_end

CedarredTown_EventScript_TownSign_Text_0:
	.string "CEDARRED TOWN\n"
	.string "“World renowned for its logs!”$"

CedarredTown_EventScript_LoggersCabinSign_Text_0:
	.string "CEDARRED's LOGGERS CABIN\n"
	.string "“Where CEDARRED's best LOGGERS reside.”$"

CedarredTown_EventScript_AcrenForestSign_Text_0:
	.string "{UP_ARROW} ACREN FOREST$"

CedarredTown_EventScript_LoreMan_Text_0:
	.string "Did you know this part of the EURUS\n"
	.string "region is famous for two things?$"

CedarredTown_EventScript_LoreMan_Text_1:
	.string "Fantastic!\p"
	.string "It seems that you have followed your\n"
	.string "history lessons well, young man.$"

CedarredTown_EventScript_LoreMan_Text_2:
	.string "Well then, here goes..\p"
	.string "This part of the EURUS region is well\n"
	.string "known for its logging industry and\l"
	.string "its vast forests you'll find.\p"
	.string "In ancient times, the people from here\n"
	.string "have learned to live alongside the\l"
	.string "POKéMON of the ACREN FOREST, and even\l"
	.string "worship its fabled keeper, CELEBI.\p"
	.string "Nowadays the people live, work and\n"
	.string "battle together as these towns\l"
	.string "produce some of the greatest GRASS\l"
	.string "TRAINERS the world has ever seen!\p"
	.string "Even the famous TRAINER, PHYLLOS, is\n"
	.string "from here…$"

CedarredTown_EventScript_MartEmployee_Text_0:
	.string "Check out all of our products\n"
	.string "in the POKéMON MART of CEDARRED TOWN!$"

CedarredTown_EventScript_Boy_Text_0:
	.string "When I grow up, I want to be\n"
	.string "stronger than the strongest LOGGERS\l"
	.string "from CEDARRED TOWN!$"

CedarredTown_EventScript_ShowLoggersCabin_Text_0:
	.string "Ah, we're here!\n"
	.string "This is CEDARRED TOWN\p"
	.string "The LOGGERS CABIN should be at the\n"
	.string "far EAST of town.$"

CedarredTown_EventScript_ShowLoggersCabin_Text_1:
	.string "Look, there it is!\n"
	.string "CEDARRED TOWN's LOGGERS CABIN.$"

CedarredTown_EventScript_ShowLoggersCabin_Text_2:
	.string "Let's go there right now, {PLAYER}!$"

CedarredTown_EventScript_EnterLoggersCabin_Text_0:
	.string "Remember {PLAYER}, we're here to help\n"
	.string "the LOGGERS with a problem in\l"
	.string "the ACREN FOREST.\p"
	.string "Let's head in and see what happened.$"

CedarredTown_EventScript_PreventWander_Text_0:
	.string "We should be going to the LOGGERS\n"
	.string "CABIN, {PLAYER}.\p"
	.string "Let's move!$"
