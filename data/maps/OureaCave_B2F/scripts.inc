OureaCave_B2F_MapScripts::
# 4 "data/maps/OureaCave_B2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/OureaCave_B2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/OureaCave_B2F/scripts.pory"
	call OureaCaves_EventScript_SetCaveLights
# 6 "data/maps/OureaCave_B2F/scripts.pory"
	compare VAR_OUREA_CAVES_STATE, 1
	goto_if_eq OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 7 "data/maps/OureaCave_B2F/scripts.pory"
	setobjectxyperm 1, 82, 14
# 8 "data/maps/OureaCave_B2F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

OureaCave_B2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/OureaCave_B2F/scripts.pory"
	map_script_2 VAR_OUREA_CAVES_STATE, 1, OureaCave_B2F_EventScript_AfterEarthquakeScene
# 13 "data/maps/OureaCave_B2F/scripts.pory"
	map_script_2 VAR_TEMP_F, 0, OureaCaves_EventScript_TryShowMapNamePopup
	.2byte 0


OureaCave_B2F_EventScript_AfterEarthquakeScene::
# 18 "data/maps/OureaCave_B2F/scripts.pory"
	lock
# 19 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement 1, OureaCave_B2F_Movement_HikerAndPlayerWalkForward
# 20 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OureaCave_B2F_Movement_HikerAndPlayerWalkForward
# 21 "data/maps/OureaCave_B2F/scripts.pory"
	waitmovement 0
# 22 "data/maps/OureaCave_B2F/scripts.pory"
	delay 30
# 23 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_0
# 24 "data/maps/OureaCave_B2F/scripts.pory"
	closemessage
# 25 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 26 "data/maps/OureaCave_B2F/scripts.pory"
	waitmovement 0
# 27 "data/maps/OureaCave_B2F/scripts.pory"
	call OureaCave_B2F_EventScript_HikerAsksPlayerForHelp
# 28 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_1
# 31 "data/maps/OureaCave_B2F/scripts.pory"
	closemessage
# 32 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement 1, OureaCave_B2F_Movement_HikerWalksToGenerator
# 33 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OureaCave_B2F_Movement_PlayerWalksToGenerator
# 34 "data/maps/OureaCave_B2F/scripts.pory"
	waitmovement 0
# 35 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_2
# 41 "data/maps/OureaCave_B2F/scripts.pory"
	closemessage
# 42 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 43 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 44 "data/maps/OureaCave_B2F/scripts.pory"
	waitmovement 0
# 45 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_3
# 47 "data/maps/OureaCave_B2F/scripts.pory"
	closemessage
# 48 "data/maps/OureaCave_B2F/scripts.pory"
	giveitem ITEM_HM06, 1
# 49 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_4
# 55 "data/maps/OureaCave_B2F/scripts.pory"
	closemessage
# 56 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
# 57 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 58 "data/maps/OureaCave_B2F/scripts.pory"
	waitmovement 0
# 59 "data/maps/OureaCave_B2F/scripts.pory"
	setvar VAR_OUREA_CAVES_STATE, 2
# 60 "data/maps/OureaCave_B2F/scripts.pory"
	release
	end


OureaCave_B2F_EventScript_HikerAsksPlayerForHelp::
# 65 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_Text_0, MSGBOX_YESNO
# 70 "data/maps/OureaCave_B2F/scripts.pory"
	closemessage
# 72 "data/maps/OureaCave_B2F/scripts.pory"
	switch VAR_RESULT
# 73 "data/maps/OureaCave_B2F/scripts.pory"
	case YES, OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_3
# 75 "data/maps/OureaCave_B2F/scripts.pory"
	case NO, OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_4
# 77 "data/maps/OureaCave_B2F/scripts.pory"
	case MULTI_B_PRESSED, OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_5
OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_1:
	return

OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_3:
	goto OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_1

OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_4:
# 76 "data/maps/OureaCave_B2F/scripts.pory"
	goto OureaCave_B2F_EventScript_HikerAsksPlayerForHelp
	goto OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_1

OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_5:
# 78 "data/maps/OureaCave_B2F/scripts.pory"
	goto OureaCave_B2F_EventScript_HikerAsksPlayerForHelp
	goto OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_1


OureaCave_B2F_EventScript_PreventPlayerWander::
# 84 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement 1, OureaCave_B2F_Movement_HikerWalkToPlayerOnStairs
# 85 "data/maps/OureaCave_B2F/scripts.pory"
	waitmovement 0
# 86 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 87 "data/maps/OureaCave_B2F/scripts.pory"
	waitmovement 0
# 88 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_PreventPlayerWander_Text_0
# 89 "data/maps/OureaCave_B2F/scripts.pory"
	closemessage
# 90 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement 1, OureaCave_B2F_Movement_HikerAndPlayerWalkBackToGenerator
# 91 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OureaCave_B2F_Movement_HikerAndPlayerWalkBackToGenerator
# 92 "data/maps/OureaCave_B2F/scripts.pory"
	waitmovement 0
# 93 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_PreventPlayerWander_Text_1
# 94 "data/maps/OureaCave_B2F/scripts.pory"
	closemessage
	end


OureaCave_B2F_EventScript_Hiker::
# 99 "data/maps/OureaCave_B2F/scripts.pory"
	goto_if_set FLAG_OUREA_CAVES_GENERATOR_2, OureaCave_B2F_EventScript_Hiker_2
# 103 "data/maps/OureaCave_B2F/scripts.pory"
	goto_if_set FLAG_OUREA_CAVES_GENERATOR_1, OureaCave_B2F_EventScript_Hiker_3
# 107 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_Hiker_Text_2, MSGBOX_NPC
	end

OureaCave_B2F_EventScript_Hiker_2:
# 100 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_Hiker_Text_0, MSGBOX_NPC
	end

OureaCave_B2F_EventScript_Hiker_3:
# 104 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_Hiker_Text_1, MSGBOX_NPC
	end


OureaCave_B2F_EventScript_WarpHole::
# 112 "data/maps/OureaCave_B2F/scripts.pory"
	lockall
# 113 "data/maps/OureaCave_B2F/scripts.pory"
	delay 20
# 114 "data/maps/OureaCave_B2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
# 115 "data/maps/OureaCave_B2F/scripts.pory"
	waitmovement 0
# 116 "data/maps/OureaCave_B2F/scripts.pory"
	playse SE_FALL
# 117 "data/maps/OureaCave_B2F/scripts.pory"
	delay 60
# 118 "data/maps/OureaCave_B2F/scripts.pory"
	warpholecustom MAP_OUREA_CAVE_B3F, 5, 4
# 119 "data/maps/OureaCave_B2F/scripts.pory"
	waitstate
	end


OureaCave_B2F_EventScript_Hiker2::
# 124 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_EventScript_Hiker2_Text_0, MSGBOX_NPC
	end


OureaCave_B2F_EventScript_Robin::
# 132 "data/maps/OureaCave_B2F/scripts.pory"
	trainerbattle_single TRAINER_OUREA_CAVE_B2F_ROBIN, OureaCave_B2F_Text_RobinIntro, OureaCave_B2F_Text_RobinDefeat
# 133 "data/maps/OureaCave_B2F/scripts.pory"
	msgbox OureaCave_B2F_Text_RobinPostBattle, MSGBOX_NPC
	end


OureaCave_B2F_EventScript_ItemGreatBall::
# 138 "data/maps/OureaCave_B2F/scripts.pory"
	finditem ITEM_GREAT_BALL
	end


# 142 "data/maps/OureaCave_B2F/scripts.pory"
OureaCave_B2F_Movement_HikerAndPlayerWalkForward:
# 143 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 143 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 143 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
	step_end

# 146 "data/maps/OureaCave_B2F/scripts.pory"
OureaCave_B2F_Movement_HikerWalksToGenerator:
# 147 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 148 "data/maps/OureaCave_B2F/scripts.pory"
	walk_right
# 149 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 149 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 149 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 149 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 149 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 150 "data/maps/OureaCave_B2F/scripts.pory"
	face_left
	step_end

# 153 "data/maps/OureaCave_B2F/scripts.pory"
OureaCave_B2F_Movement_PlayerWalksToGenerator:
# 154 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 154 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 155 "data/maps/OureaCave_B2F/scripts.pory"
	walk_right
# 156 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 156 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 156 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 156 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 157 "data/maps/OureaCave_B2F/scripts.pory"
	face_left
	step_end

# 160 "data/maps/OureaCave_B2F/scripts.pory"
OureaCave_B2F_Movement_HikerWalkToPlayerOnStairs:
# 161 "data/maps/OureaCave_B2F/scripts.pory"
	walk_down
# 161 "data/maps/OureaCave_B2F/scripts.pory"
	walk_down
	step_end

# 164 "data/maps/OureaCave_B2F/scripts.pory"
OureaCave_B2F_Movement_HikerAndPlayerWalkBackToGenerator:
# 165 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 165 "data/maps/OureaCave_B2F/scripts.pory"
	walk_up
# 166 "data/maps/OureaCave_B2F/scripts.pory"
	face_left
	step_end

OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_0:
# 23 "data/maps/OureaCave_B2F/scripts.pory"
	.string "…$"

OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_1:
# 28 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Ahhh! You're rock solid\n"
	.string "HOHOHO!\p"
	.string "Thanks so much for wanting to help!$"

OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_2:
# 35 "data/maps/OureaCave_B2F/scripts.pory"
	.string "See this right here?\n"
	.string "These are power switches.\p"
	.string "If you flip the switch on 'em\n"
	.string "they turn the lights on.\p"
	.string "Just go through the caves 'n flip 'em all.\n"
	.string "I'm sure your POKéMON will protect you.$"

OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_3:
# 45 "data/maps/OureaCave_B2F/scripts.pory"
	.string "To  help you clear any debris that might\n"
	.string "be in your way, take this.$"

OureaCave_B2F_EventScript_AfterEarthquakeScene_Text_4:
# 49 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Teach this to one of your POKéMON\n"
	.string "to clear rocks that may have fallen\l"
	.string "during the earthquake and to\l"
	.string "get our workers out safely.\p"
	.string "Now…\n"
	.string "Why don't you try turning this one on.$"

OureaCave_B2F_EventScript_HikerAsksPlayerForHelp_Text_0:
# 65 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Hmmm…\n"
	.string "It seems the earthquake knocked out\l"
	.string "the power grid…\p"
	.string "Can you maybe help us get it back up?\n"
	.string "That way we can evacuate safely.$"

OureaCave_B2F_EventScript_PreventPlayerWander_Text_0:
# 88 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Come on now…$"

OureaCave_B2F_EventScript_PreventPlayerWander_Text_1:
# 93 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Show me how you flip that switch!$"

OureaCave_B2F_EventScript_Hiker_Text_0:
# 100 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Nice work, you found another.\p"
	.string "Keep on going!$"

OureaCave_B2F_EventScript_Hiker_Text_1:
# 104 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Good job, now go find the others.$"

OureaCave_B2F_EventScript_Hiker_Text_2:
# 107 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Try turning it on!$"

OureaCave_B2F_EventScript_Hiker2_Text_0:
# 124 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Har har!\n"
	.string "Did I spook ya?!\p"
	.string "It's fun to spook people when\n"
	.string "it's dark.$"

OureaCave_B2F_Text_RobinIntro::
# 169 "data/maps/OureaCave_B2F/scripts.pory"
	.string "You'll have to look up to us when\n"
	.string "we take to the skies!$"

OureaCave_B2F_Text_RobinDefeat::
# 174 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Hmmm maybe instead of looking down\p"
	.string "I should look back now…$"

OureaCave_B2F_Text_RobinPostBattle::
# 179 "data/maps/OureaCave_B2F/scripts.pory"
	.string "Phew… That battle was intense!$"
