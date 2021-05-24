OureaCave_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call OureaCaves_EventScript_SetCaveLights
	compare VAR_OUREA_CAVES_STATE, 1
	goto_if_eq OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 1, 82, 14
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_OUREA_CAVES_STATE, 1, OureaCave_B2F_EventScript_AfterEarthquakeScene
	map_script_2 VAR_TEMP_F, 0, OureaCaves_EventScript_TryShowMapNamePopup
	.2byte 0


OureaCave_B2F_EventScript_AfterEarthquakeScene::
	lock
	applymovement 1, OureaCave_B2F_Movement_HikerAndPlayerWalkForward
	applymovement OBJ_EVENT_ID_PLAYER, OureaCave_B2F_Movement_HikerAndPlayerWalkForward
	waitmovement 0
	delay 30
	msgbox OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_0
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	call OureaCave_B2F_EventScript_HikerAsksPlayerForHelp
	msgbox OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_1
	closemessage
	applymovement 1, OureaCave_B2F_Movement_HikerWalksToGenerator
	applymovement OBJ_EVENT_ID_PLAYER, OureaCave_B2F_Movement_PlayerWalksToGenerator
	waitmovement 0
	msgbox OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_2
	closemessage
	applymovement 1, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_3
	closemessage
	giveitem ITEM_HM06, 1
	msgbox OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_4
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_OUREA_CAVES_STATE, 2
	release
	end


OureaCave_B2F_EventScript_HikerAsksPlayerForHelp::
	msgbox OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_Text_0, MSGBOX_YESNO
	closemessage
	switch VAR_RESULT
	case YES, OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_3
	case NO, OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_4
	case MULTI_B_PRESSED, OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_5
OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_1:
	return

OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_3:
	goto OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_1

OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_4:
	goto OureaCave_B2F_EventScript_HikerAsksPlayerForHelp
	goto OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_1

OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_5:
	goto OureaCave_B2F_EventScript_HikerAsksPlayerForHelp
	goto OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_1


OureaCave_B2F_EventScript_PreventPlayerWander::
	applymovement 1, OureaCave_B2F_Movement_HikerWalkToPlayerOnStairs
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox OureaCave_B2F_EventScript_PreventPlayerWander_Text_0
	closemessage
	applymovement 1, OureaCave_B2F_Movement_HikerAndPlayerWalkBackToGenerator
	applymovement OBJ_EVENT_ID_PLAYER, OureaCave_B2F_Movement_HikerAndPlayerWalkBackToGenerator
	waitmovement 0
	msgbox OureaCave_B2F_EventScript_PreventPlayerWander_Text_1
	closemessage
	end


OureaCave_B2F_EventScript_Hiker::
	goto_if_set FLAG_OUREA_CAVES_GENERATOR_2, OureaCave_B2F_EventScript_Hiker_2
	goto_if_set FLAG_OUREA_CAVES_GENERATOR_1, OureaCave_B2F_EventScript_Hiker_3
	msgbox OureaCave_B2F_EventScript_Hiker_Text_2, MSGBOX_NPC
	end

OureaCave_B2F_EventScript_Hiker_2:
	msgbox OureaCave_B2F_EventScript_Hiker_Text_0, MSGBOX_NPC
	end

OureaCave_B2F_EventScript_Hiker_3:
	msgbox OureaCave_B2F_EventScript_Hiker_Text_1, MSGBOX_NPC
	end


OureaCave_B2F_EventScript_WarpHole::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warpholecustom MAP_OUREA_CAVE_B3F, 5, 4
	waitstate
	end


OureaCave_B2F_EventScript_Hiker2::
	msgbox OureaCave_B2F_EventScript_Hiker2_Text_0, MSGBOX_NPC
	end


OureaCave_B2F_EventScript_Robin::
	trainerbattle_single TRAINER_OUREA_CAVE_B2F_ROBIN, OureaCave_B2F_Text_RobinIntro, OureaCave_B2F_Text_RobinDefeat
	msgbox OureaCave_B2F_Text_RobinPostBattle, MSGBOX_NPC
	end


OureaCave_B2F_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL
	end


OureaCave_B2F_Movement_HikerAndPlayerWalkForward:
	walk_up
	walk_up
	walk_up
	step_end

OureaCave_B2F_Movement_HikerWalksToGenerator:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

OureaCave_B2F_Movement_PlayerWalksToGenerator:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

OureaCave_B2F_Movement_HikerWalkToPlayerOnStairs:
	walk_down
	walk_down
	step_end

OureaCave_B2F_Movement_HikerAndPlayerWalkBackToGenerator:
	walk_up
	walk_up
	face_left
	step_end

OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_0:
	.string "…$"

OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_1:
	.string "Ahhh! You're rock solid\n"
	.string "HOHOHO!\p"
	.string "Thanks so much for wanting to help!$"

OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_2:
	.string "See this right here?\n"
	.string "These are power switches.\p"
	.string "If you flip the switch on 'em\n"
	.string "they turn the lights on.\p"
	.string "Just go through the caves 'n flip 'em all.\n"
	.string "I'm sure your POKéMON will protect you.$"

OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_3:
	.string "To  help you clear any debris that might\n"
	.string "be in your way, take this.$"

OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_4:
	.string "Teach this to one of your POKéMON\n"
	.string "to clear rocks that may have fallen\l"
	.string "during the earthquake and to\l"
	.string "get our workers out safely.\p"
	.string "Now…\n"
	.string "Why don't you try turning this one on.$"

OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_Text_0:
	.string "Hmmm…\n"
	.string "It seems the earthquake knocked out\l"
	.string "the power grid…\p"
	.string "Can you maybe help us get it back up?\n"
	.string "That way we can evacuate safely.$"

OureaCave_B2F_EventScript_PreventPlayerWander_Text_0:
	.string "Come on now…$"

OureaCave_B2F_EventScript_PreventPlayerWander_Text_1:
	.string "Show me how you flip that switch!$"

OureaCave_B2F_EventScript_Hiker_Text_0:
	.string "Nice work, you found another.\p"
	.string "Keep on going!$"

OureaCave_B2F_EventScript_Hiker_Text_1:
	.string "Good job, now go find the others.$"

OureaCave_B2F_EventScript_Hiker_Text_2:
	.string "Try turning it on!$"

OureaCave_B2F_EventScript_Hiker2_Text_0:
	.string "Har har!\n"
	.string "Did I spook ya?!\p"
	.string "It's fun to spook people when\n"
	.string "it's dark.$"

OureaCave_B2F_Text_RobinIntro::
	.string "You'll have to look up to us when\n"
	.string "we take to the skies!$"

OureaCave_B2F_Text_RobinDefeat::
	.string "Hmmm maybe instead of looking down\n"
	.string "I should look back now…$"

OureaCave_B2F_Text_RobinPostBattle::
	.string "Phew… That battle was intense!$"
