AcrenForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AcrenForest_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_ACREN_FOREST_STATE, 2
	goto_if_eq AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	compare VAR_ACREN_FOREST_STATE, 3
	goto_if_eq AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	compare VAR_ACREN_FOREST_STATE, 4
	goto_if_eq AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
	compare VAR_ACREN_FOREST_STATE, 5
	goto_if_eq AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_10
	return

AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setobjectxyperm 17, 39, 11
	setobjectxyperm 18, 39, 10
	setobjectxyperm 19, 53, 5
	setobjectxyperm 20, 54, 5
	setobjectmovementtype 17, MOVEMENT_TYPE_RUN_IN_PLACE_LEFT
	setobjectmovementtype 18, MOVEMENT_TYPE_RUN_IN_PLACE_LEFT
	setobjectmovementtype 19, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 20, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 9, MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT
	setobjectmovementtype 10, MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT
	goto AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
	setobjectxyperm 17, 39, 11
	setobjectxyperm 18, 39, 10
	setobjectxyperm 19, 52, 6
	setobjectxyperm 20, 55, 6
	setobjectmovementtype 17, MOVEMENT_TYPE_RUN_IN_PLACE_LEFT
	setobjectmovementtype 18, MOVEMENT_TYPE_RUN_IN_PLACE_LEFT
	setobjectmovementtype 19, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 20, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 9, MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT
	setobjectmovementtype 10, MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT
	goto AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
	setobjectxyperm 17, 4, 6
	setobjectxyperm 18, 4, 7
	setobjectxyperm 19, 52, 6
	setobjectxyperm 20, 55, 6
	setobjectmovementtype 17, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 19, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 20, MOVEMENT_TYPE_FACE_DOWN
	goto AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
	setobjectxyperm 17, 4, 6
	setobjectxyperm 18, 4, 7
	setobjectxyperm 19, 52, 6
	setobjectxyperm 20, 55, 6
	setobjectmovementtype 17, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 19, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 20, MOVEMENT_TYPE_FACE_DOWN
	return

AcrenForest_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ACREN_FOREST_STATE, 0, AcrenForest_EventScript_LoggersCutscene
	map_script_2 VAR_FIRWEALD_CITY_STATE, 1, AcrenForest_EventScript_PhyllosShrineCutscene
	.2byte 0


AcrenForest_EventScript_PhyllosShrineCutscene::
	playse SE_PIN
	applymovement 31, Common_Movement_ExclamationMark
	waitmovement 0
	load_speech_bubble 31
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_0
	destroy_speech_bubble
	closemessage
	applymovement 31, AcrenForest_Movement_PhyllosWalkToShrine
	applymovement OBJ_EVENT_ID_PLAYER, AcrenForest_Movement_PlayerWalkToShrine
	waitmovement 0
	delay 30
	load_speech_bubble 31
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_1
	destroy_speech_bubble
	closemessage
	delay 10
	fadenewbgm MUS_CELEBI
	setweather WEATHER_SUNNY
	doweather
	applymovement 31, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	load_speech_bubble 31
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_2
	destroy_speech_bubble
	closemessage
	delay 10
	applymovement 31, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	load_speech_bubble 31
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_3
	destroy_speech_bubble
	closemessage
	delay 10
	fadedefaultbgm
	resetweather
	doweather
	applymovement 31, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	load_speech_bubble 31
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_4
	destroy_speech_bubble
	closemessage
	giveitem ITEM_BRIGHT_POWDER, 1
	load_speech_bubble 31
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_5
	destroy_speech_bubble
	closemessage
	applymovement 31, AcrenForest_Movement_PhyllosWalkFromShrine_1
	delay 32
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement 31, AcrenForest_Movement_PhyllosWalkFromShrine_2
	delay 32
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	applymovement 31, AcrenForest_Movement_PhyllosWalkFromShrine_3
	delay 32
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	waitmovement 0
	removeobject 31
	setvar VAR_FIRWEALD_CITY_STATE, 2
	end


AcrenForest_EventScript_LoggersCutscene::
	lock
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 29
	goto_if_eq AcrenForest_EventScript_LoggersCutscene_2
	compare VAR_TEMP_0, 29
	goto_if_gt AcrenForest_EventScript_LoggersCutscene_3
AcrenForest_EventScript_LoggersCutscene_1:
	load_speech_bubble 17
	msgbox AcrenForest_EventScript_LoggersCutscene_Text_0
	destroy_speech_bubble
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, AcrenForest_Movement_CameraToGrunts
	waitmovement 0
	msgbox AcrenForest_EventScript_LoggersCutscene_Text_1
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, AcrenForest_Movement_CameraToPlayer
	waitmovement 0
	special RemoveCameraObject
	load_speech_bubble 17
	msgbox AcrenForest_EventScript_LoggersCutscene_Text_2
	destroy_speech_bubble
	closemessage
	msgbox AcrenForest_EventScript_LoggersCutscene_Text_3
	closemessage
	load_speech_bubble 17
	msgbox AcrenForest_EventScript_LoggersCutscene_Text_4
	destroy_speech_bubble
	closemessage
	setvar VAR_ACREN_FOREST_STATE, 1
	release
	end

AcrenForest_EventScript_LoggersCutscene_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto AcrenForest_EventScript_LoggersCutscene_1

AcrenForest_EventScript_LoggersCutscene_3:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto AcrenForest_EventScript_LoggersCutscene_1


AcrenForest_EventScript_Logger1::
	compare VAR_ACREN_FOREST_STATE, 2
	goto_if_eq AcrenForest_EventScript_Logger1_2
	compare VAR_ACREN_FOREST_STATE, 5
	goto_if_eq AcrenForest_EventScript_Logger1_3
	msgbox AcrenForest_EventScript_Logger1_Text_2, MSGBOX_NPC
	end

AcrenForest_EventScript_Logger1_2:
	msgbox AcrenForest_EventScript_Logger1_Text_0, MSGBOX_NPC
	turnobject 17, DIR_WEST
	turnobject 18, DIR_WEST
	end

AcrenForest_EventScript_Logger1_3:
	msgbox AcrenForest_EventScript_Logger1_Text_1, MSGBOX_NPC
	end


AcrenForest_EventScript_Logger2::
	compare VAR_ACREN_FOREST_STATE, 2
	goto_if_eq AcrenForest_EventScript_Logger2_2
	compare VAR_ACREN_FOREST_STATE, 5
	goto_if_eq AcrenForest_EventScript_Logger2_3
	msgbox AcrenForest_EventScript_Logger2_Text_1, MSGBOX_NPC
	turnobject 17, DIR_WEST
	turnobject 18, DIR_WEST
	end

AcrenForest_EventScript_Logger2_2:
	msgbox AcrenForest_EventScript_Logger1_Text_0, MSGBOX_NPC
	turnobject 17, DIR_WEST
	turnobject 18, DIR_WEST
	end

AcrenForest_EventScript_Logger2_3:
	msgbox AcrenForest_EventScript_Logger2_Text_0, MSGBOX_NPC
	end


AcrenForest_EventScript_Logger3And4::
	compare VAR_ACREN_FOREST_STATE, 2
	goto_if_eq AcrenForest_EventScript_Logger3And4_2
	compare VAR_ACREN_FOREST_STATE, 3
	goto_if_eq AcrenForest_EventScript_Logger3And4_5
	compare VAR_ACREN_FOREST_STATE, 4
	goto_if_eq AcrenForest_EventScript_Logger3And4_6
	msgbox AcrenForest_EventScript_Logger2_Text_1, MSGBOX_NPC
	end

AcrenForest_EventScript_Logger3And4_2:
	lock
	msgbox AcrenForest_EventScript_Logger3And4_Text_0, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, AcrenForest_Movement_PlayerWalkBackwards
	applymovement 19, AcrenForest_Movement_Logger3WalkLeft
	applymovement 20, AcrenForest_Movement_Logger4WalkRight
	waitmovement 0
	copyobjectxytoperm 19
	copyobjectxytoperm 20
	setvar VAR_ACREN_FOREST_STATE, 3
	release
	end

AcrenForest_EventScript_Logger3And4_5:
	msgbox AcrenForest_EventScript_Logger3And4_Text_1, MSGBOX_NPC
	end

AcrenForest_EventScript_Logger3And4_6:
	msgbox AcrenForest_EventScript_Logger3And4_Text_2, MSGBOX_NPC
	end


AcrenForest_EventScript_TeamAirlockGrunt::
	random 6
	copyvar VAR_TEMP_F, VAR_RESULT
	switch VAR_TEMP_F
	case 0, AcrenForest_EventScript_TeamAirlockGrunt_3
	case 1, AcrenForest_EventScript_TeamAirlockGrunt_4
	case 2, AcrenForest_EventScript_TeamAirlockGrunt_5
	case 3, AcrenForest_EventScript_TeamAirlockGrunt_6
	case 4, AcrenForest_EventScript_TeamAirlockGrunt_7
	case 5, AcrenForest_EventScript_TeamAirlockGrunt_8
AcrenForest_EventScript_TeamAirlockGrunt_1:
	end

AcrenForest_EventScript_TeamAirlockGrunt_3:
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_0, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1

AcrenForest_EventScript_TeamAirlockGrunt_4:
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_1, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1

AcrenForest_EventScript_TeamAirlockGrunt_5:
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_2, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1

AcrenForest_EventScript_TeamAirlockGrunt_6:
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_3, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1

AcrenForest_EventScript_TeamAirlockGrunt_7:
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_4, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1

AcrenForest_EventScript_TeamAirlockGrunt_8:
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_5, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1


AcrenForest_EventScript_DescribeIllegalCamp::
	lock
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	playse SE_PIN
	applymovement 30, Common_Movement_ExclamationMark
	waitmovement 0
	compare VAR_TEMP_0, 5
	goto_if_eq AcrenForest_EventScript_DescribeIllegalCamp_2
AcrenForest_EventScript_DescribeIllegalCamp_1:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	load_speech_bubble 30
	msgbox AcrenForest_EventScript_DescribeIllegalCamp_Text_0
	destroy_speech_bubble
	closemessage
	turnobject 30, DIR_SOUTH
	applymovement 30, AcrenForest_Movement_PhyllosLaughterJump
	waitmovement 0
	load_speech_bubble 30
	msgbox AcrenForest_EventScript_DescribeIllegalCamp_Text_1
	destroy_speech_bubble
	closemessage
	delay 10
	teleportcamera 6, 28
	delay 30
	msgbox AcrenForest_EventScript_DescribeIllegalCamp_Text_2
	closemessage
	delay 10
	resetcamera
	delay 30
	load_speech_bubble 30
	msgbox AcrenForest_EventScript_DescribeIllegalCamp_Text_3
	destroy_speech_bubble
	closemessage
	setvar VAR_ACREN_FOREST_STATE, 5
	release
	end

AcrenForest_EventScript_DescribeIllegalCamp_2:
	applymovement 30, Common_Movement_WalkLeft
	waitmovement 0
	goto AcrenForest_EventScript_DescribeIllegalCamp_1


AcrenForest_EventScript_WarnBoss::
	lock
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement 29, Common_Movement_ExclamationMark
	waitmovement 0
	load_speech_bubble 29
	msgbox AcrenForest_EventScript_WarnBoss_Text_0
	destroy_speech_bubble
	closemessage
	applymovement 29, Common_Movement_WalkUp
	waitmovement 0
	playse SE_EXIT
	removeobject 29
	setobjectxyperm 29, 2, 24
	fadedefaultbgm
	setvar VAR_ACREN_FOREST_STATE, 6
	release
	end


AcrenForest_EventScript_Phyllos::
	msgbox AcrenForest_EventScript_DescribeIllegalCamp_Text_3, MSGBOX_NPC
	end


AcrenForest_EventScript_TrainerTipsSurf::
	msgbox AcrenForest_EventScript_TrainerTipsSurf_Text_0, MSGBOX_SIGN
	end


AcrenForest_EventScript_TrainerTipsHeldItems::
	msgbox AcrenForest_EventScript_TrainerTipsHeldItems_Text_0, MSGBOX_SIGN
	end


AcrenForest_EventScript_Boy::
	lock
	faceplayer
	load_speech_bubble 8
	msgbox AcrenForest_EventScript_Boy_Text_0, MSGBOX_YESNO
	destroy_speech_bubble
	switch VAR_RESULT
	case YES, AcrenForest_EventScript_Boy_3
	case NO, AcrenForest_EventScript_Boy_4
AcrenForest_EventScript_Boy_1:
	release
	end

AcrenForest_EventScript_Boy_3:
	msgbox AcrenForest_EventScript_Boy_Text_1, MSGBOX_NPC
	goto AcrenForest_EventScript_Boy_1

AcrenForest_EventScript_Boy_4:
	msgbox AcrenForest_EventScript_Boy_Text_2, MSGBOX_NPC
	goto AcrenForest_EventScript_Boy_1


AcrenForest_EventScript_BugCatcher::
	msgbox AcrenForest_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	end


AcrenForest_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL
	end


AcrenForest_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end


AcrenForest_EventScript_FlowerShopSign::
	msgbox AcrenForest_EventScript_FlowerShopSign_Text_0, MSGBOX_SIGN
	end


AcrenForest_EventScript_Frederick::
	trainerbattle_single TRAINER_ACREN_FOREST_FREDERICK, AcrenForest_Text_FrederickIntro, AcrenForest_Text_FrederickDefeat
	msgbox AcrenForest_Text_FrederickPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_Roddy::
	trainerbattle_single TRAINER_ACREN_FOREST_RODDY, AcrenForest_Text_RoddyIntro, AcrenForest_Text_RoddyDefeat
	msgbox AcrenForest_Text_RoddyPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_Armin::
	trainerbattle_single TRAINER_ACREN_FOREST_ARMIN, AcrenForest_Text_ArminIntro, AcrenForest_Text_ArminDefeat
	msgbox AcrenForest_Text_ArminPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_Marisha::
	trainerbattle_single TRAINER_ACREN_FOREST_MARISHA, AcrenForest_Text_MarishaIntro, AcrenForest_Text_MarishaDefeat
	msgbox AcrenForest_Text_MarishaPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_Lada::
	trainerbattle_single TRAINER_ACREN_FOREST_LADA, AcrenForest_Text_LadaIntro, AcrenForest_Text_LadaDefeat
	msgbox AcrenForest_Text_LadaPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_Grunt::
	trainerbattle_single TRAINER_ACREN_FOREST_GRUNT, AcrenForest_Text_GruntIntro, AcrenForest_Text_GruntDefeat
	msgbox AcrenForest_Text_GruntPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_SetShrineWeatherAndSong::
	fadenewbgm MUS_CELEBI
	setweather WEATHER_SUNNY
	doweather
	release
	end


AcrenForest_EventScript_SetDefaultWeatherAndSong::
	fadenewbgm MUS_ACREN_FOREST
	resetweather
	doweather
	release
	end


AcrenForest_EventScript_CelebiShrine::
	msgbox AcrenForest_EventScript_CelebiShrine_Text_0, MSGBOX_SIGN
	end


AcrenForest_Movement_CameraToGrunts:
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AcrenForest_Movement_CameraToPlayer:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	step_end

AcrenForest_Movement_Logger3WalkToSide:
	walk_left
	face_down
	step_end

AcrenForest_Movement_Logger4WalkToSide:
	walk_right
	face_down
	step_end

AcrenForest_Movement_Logger4WalkToSideFromWest:
	walk_down
	walk_right
	face_down
	step_end

AcrenForest_Movement_PlayerWalkBackwards:
	lock_facing_direction
	walk_down
	step_end

AcrenForest_Movement_Logger3WalkLeft:
	walk_down
	walk_left
	face_down
	step_end

AcrenForest_Movement_Logger4WalkRight:
	walk_down
	walk_right
	face_down
	step_end

AcrenForest_Movement_PhyllosLaughterJump:
	jump_in_place_down
	step_end

AcrenForest_Movement_PhyllosWalkToShrine:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	face_left
	step_end

AcrenForest_Movement_PlayerWalkToShrine:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	face_right
	step_end

AcrenForest_Movement_PhyllosWalkFromShrine_1:
	walk_down
	walk_left
	step_end

AcrenForest_Movement_PhyllosWalkFromShrine_2:
	walk_left
	walk_up
	step_end

AcrenForest_Movement_PhyllosWalkFromShrine_3:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

AcrenForest_EventScript_PhyllosShrineCutscene_Text_0:
	.string "Hello {PLAYER}.\n"
	.string "I have something important to\l"
	.string "tell you.\p"
	.string "Follow me if you will.$"

AcrenForest_EventScript_PhyllosShrineCutscene_Text_1:
	.string "As you may or may not know\n"
	.string "EURUS is divided in districts.\p"
	.string "These districts each have a\n"
	.string "dedicated shrine keeper.\p"
	.string "Usually the shrine keepers are\n"
	.string "important people.\p"
	.string "Often Majors, TOURNAMENT MASTERS,\n"
	.string "or both.\p"
	.string "Basically, every shrine is meant\n"
	.string "to honor a certain LEGENDARY\l"
	.string "POKéMON.\p"
	.string "As long as we worship these\n"
	.string "POKéMON, they will remain docile.\p"
	.string "As long as they stay docile, our\n"
	.string "world will be in balance.\p"
	.string "I am the shrine keeper of\n"
	.string "FIRWEALD CITY and its area.$"

AcrenForest_EventScript_PhyllosShrineCutscene_Text_2:
	.string "This shrine you see here is\n"
	.string "home to the LEGENDARY\l"
	.string "POKéMON CELEBI.\p"
	.string "Also known as the\n"
	.string "GUARDIAN of the FOREST.$"

AcrenForest_EventScript_PhyllosShrineCutscene_Text_3:
	.string "Anyways, I would like to\n"
	.string "ask you for a favor…\p"
	.string "Seeing as we had that run in\n"
	.string "those strange men in the FOREST\l"
	.string "the other day.\p"
	.string "I was wondering if you could\n"
	.string "check in with my colleague at\l"
	.string "the shrine to GROUDON.\p"
	.string "I am worried a storm might be\n"
	.string "brewing…\p"
	.string "GROUDON's shrine is in the\n"
	.string "mountainous area of the region\l"
	.string "across the sea."
	.string "I cannot thank you enough, you\n"
	.string "are clearly a skilled TRAINER.\p"
	.string "And I'm not the one to take\n"
	.string "this journey on at my age…\p"
	.string "Har har har!$"

AcrenForest_EventScript_PhyllosShrineCutscene_Text_4:
	.string "Here, take this.$"

AcrenForest_EventScript_PhyllosShrineCutscene_Text_5:
	.string "If you need me, I'll be at\n"
	.string "the TOURNAMENT HALL.\p"
	.string "Thank you once again, our battle\n"
	.string "really sparked joy!$"

AcrenForest_EventScript_LoggersCutscene_Text_0:
	.string "Hello there {PLAYER}!\p"
	.string "I heard from the boss we need to deal\n"
	.string "with those TEAM AIRLOCK GRUNTS\l"
	.string "back there…$"

AcrenForest_EventScript_LoggersCutscene_Text_1:
	.string "Look, those are the GRUNTS we're\n"
	.string "talking about…$"

AcrenForest_EventScript_LoggersCutscene_Text_2:
	.string "I just need to check if you're\n"
	.string "official POKéMON TRAINER.\p"
	.string "May I see your POKéDEX please?$"

AcrenForest_EventScript_LoggersCutscene_Text_3:
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …$"

AcrenForest_EventScript_LoggersCutscene_Text_4:
	.string "Hmmm…\n"
	.string "You don't seem to have a POKéDEX\l"
	.string "at all…\p"
	.string "You need to have a POKéDEX if you're\n"
	.string "an official POKéMON TRAINER.\p"
	.string "Go speak to the PROFESSOR about this.\p"
	.string "We'll handle it from here.$"

AcrenForest_EventScript_Logger1_Text_0:
	.string "Hey kid, we need some help from\n"
	.string "a professional here.\p"
	.string "Ask the LOGGERS at the exit of\n"
	.string "the forest for help…$"

AcrenForest_EventScript_Logger1_Text_1:
	.string "You definitely look like a strong\n"
	.string "TRAINER, kid.$"

AcrenForest_EventScript_Logger1_Text_2:
	.string "Go speak to the PROFESSOR about this.\n"
	.string "We'll handle it from here.$"

AcrenForest_EventScript_Logger2_Text_0:
	.string "Show those thugs, kiddo.$"

AcrenForest_EventScript_Logger2_Text_1:
	.string "We'll handle it from here kid.$"

AcrenForest_EventScript_Logger3And4_Text_0:
	.string "You need to get help from FIRWEALD CITY\n"
	.string "Try to find PHYLLOS.\l"
	.string "He's the TOURNAMENT MASTER of the city.$"

AcrenForest_EventScript_Logger3And4_Text_1:
	.string "We'll be waiting right here.$"

AcrenForest_EventScript_Logger3And4_Text_2:
	.string "Good work kid, PHYLLOS arrived\n"
	.string "a while back.\p"
	.string "Head deeper into the forest to find him.$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_0:
	.string "Get out of our way kid!$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_1:
	.string "Hey, you shouldn't be wandering\n"
	.string "around here!\p"
	.string "This isn't your business!$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_2:
	.string "What's a kid like you doing here?!$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_3:
	.string "You'll never get a hold of the\n"
	.string "mightly TEAM AIRLOCK!$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_4:
	.string "Hehehe…\n"
	.string "We're just doing business here kiddo.$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_5:
	.string "You don't know us kid!\n"
	.string "Get out!$"

AcrenForest_EventScript_DescribeIllegalCamp_Text_0:
	.string "Hi again {PLAYER}.\n"
	.string "You've managed to find us.\l"
	.string "Now let's get to business shall we.$"

AcrenForest_EventScript_DescribeIllegalCamp_Text_1:
	.string "Har har har!\p"
	.string "Well then…$"

AcrenForest_EventScript_DescribeIllegalCamp_Text_2:
	.string "This is the cabin we're looking for.\n"
	.string "It's guarded by some GRUNTS, but\l"
	.string "we'll deal with those.\p"
	.string "Har har har!$"

AcrenForest_EventScript_DescribeIllegalCamp_Text_3:
	.string "What are you waiting for kiddo?\p"
	.string "They should know you're coming.$"

AcrenForest_EventScript_WarnBoss_Text_0:
	.string "Oh no!\n"
	.string "How did you get here?!\p"
	.string "You shouldn't be able to get here!\n"
	.string "Didn't the GRUNTS keep you away?\p"
	.string "Hrmph.\n"
	.string "Fine then, the BOSS will make sure to\l"
	.string "get you out! Ha ha ha ha!$"

AcrenForest_EventScript_TrainerTipsSurf_Text_0:
	.string "TRAINER TIPS\p"
	.string "Using HM05 SURF, you can cross\n"
	.string "any body of water!$"

AcrenForest_EventScript_TrainerTipsHeldItems_Text_0:
	.string "TRAINER TIPS\p"
	.string "POKéMON with the PICKUP ability\n"
	.string "can find items in battle!\p"
	.string "When you catch a POKéMON with this\n"
	.string "ability, it could be holding on to\l"
	.string "an item.\p"
	.string "Always check if the POKéMON you\n"
	.string "caught has an item!$"

AcrenForest_EventScript_Boy_Text_0:
	.string "Did you know that jogging\n"
	.string "burn 446 calories an hour?$"

AcrenForest_EventScript_Boy_Text_1:
	.string "Oh did you now?$"

AcrenForest_EventScript_Boy_Text_2:
	.string "Well you look like you could\n"
	.string "use some excercise yourself!$"

AcrenForest_EventScript_BugCatcher_Text_0:
	.string "You can harvest berries from\n"
	.string "loamy soul and replant them.\p"
	.string "That way you'll never have to\n"
	.string "run out of berries!$"

AcrenForest_EventScript_FlowerShopSign_Text_0:
	.string "ELDER BERRY's GREENERY SHOP$"

AcrenForest_EventScript_CelebiShrine_Text_0:
	.string "You feel a strange presence\n"
	.string "around you…$"

AcrenForest_Text_FrederickIntro::
	.string "My RATTATA and I will become champions\n"
	.string "of the EURUS REGION!$"

AcrenForest_Text_FrederickDefeat::
	.string "Why would you crush my\n"
	.string "hopes and dreams?!$"

AcrenForest_Text_FrederickPostBattle::
	.string "See you at the EURUS LEAGUE, loser!$"

AcrenForest_Text_RoddyIntro::
	.string "I just pulled my worm out the box.$"

AcrenForest_Text_RoddyDefeat::
	.string "Eeee, eerrrr…$"

AcrenForest_Text_RoddyPostBattle::
	.string "Wait until I drop my next album…$"

AcrenForest_Text_ArminIntro::
	.string "I have a good friend called EREN.\n"
	.string "He lives in FIRWEALD CITY.$"

AcrenForest_Text_ArminDefeat::
	.string "Wow!\p"
	.string "You're a titan in battle!$"

AcrenForest_Text_ArminPostBattle::
	.string "Go visit my friend in\n"
	.string "FIRWEALD CITY once.$"

AcrenForest_Text_MarishaIntro::
	.string "My parents came here from a country\n"
	.string "far, far away.$"

AcrenForest_Text_MarishaDefeat::
	.string "You won't beat my parents\n"
	.string "in a battle!$"

AcrenForest_Text_MarishaPostBattle::
	.string "The country my parents are from\n"
	.string "is very dangerous and cold.$"

AcrenForest_Text_LadaIntro::
	.string "My parents named me after a car\n"
	.string "'cause I'm a machine in battle!$"

AcrenForest_Text_LadaDefeat::
	.string "Oh no!\n"
	.string "I choked my engine!$"

AcrenForest_Text_LadaPostBattle::
	.string "I guess I ran out of gas…$"

AcrenForest_Text_GruntIntro::
	.string "How did you get here?$"

AcrenForest_Text_GruntDefeat::
	.string "The others will take\n"
	.string "care of you!$"

AcrenForest_Text_GruntPostBattle::
	.string "The BOSS will get you kicked\n"
	.string "out of here, no problem!$"
