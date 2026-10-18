Route403_MapScripts::
	.byte 0


Route403_EventScript_Timmy::
# 10 "data/maps/Route403/scripts.pory"
	trainerbattle_single TRAINER_ROUTE403_TIMMY, Route403_Text_TimmyIntro, Route403_Text_TimmyDefeat
# 11 "data/maps/Route403/scripts.pory"
	msgbox Route403_Text_TimmyPostBattle, MSGBOX_NPC
	end


Route403_EventScript_Anna::
# 16 "data/maps/Route403/scripts.pory"
	trainerbattle_single TRAINER_ROUTE403_ANNA, Route403_Text_AnnaIntro, Route403_Text_AnnaDefeat
# 17 "data/maps/Route403/scripts.pory"
	msgbox Route403_Text_AnnaPostBattle, MSGBOX_NPC
	end


Route403_EventScript_Warren::
# 22 "data/maps/Route403/scripts.pory"
	trainerbattle_single TRAINER_ROUTE403_WARREN, Route403_Text_WarrenIntro, Route403_Text_WarrenDefeat
# 23 "data/maps/Route403/scripts.pory"
	msgbox Route403_Text_WarrenPostBattle, MSGBOX_NPC
	end


Route403_EventScript_BugCatcher::
# 28 "data/maps/Route403/scripts.pory"
	lock
# 29 "data/maps/Route403/scripts.pory"
	msgbox Route403_EventScript_BugCatcher_Text_0, MSGBOX_NPC
# 32 "data/maps/Route403/scripts.pory"
	applymovement 4, Route403_Movement_YoungsterJumpInPlace
# 33 "data/maps/Route403/scripts.pory"
	applymovement 5, Route403_Movement_ZigzagoonJumpInPlace
# 34 "data/maps/Route403/scripts.pory"
	delay 8
# 35 "data/maps/Route403/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, 0
# 36 "data/maps/Route403/scripts.pory"
	waitmovement 0
# 37 "data/maps/Route403/scripts.pory"
	release
	end


Route403_EventScript_Zigzagoon::
# 42 "data/maps/Route403/scripts.pory"
	lock
# 43 "data/maps/Route403/scripts.pory"
	faceplayer
# 44 "data/maps/Route403/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, 0
# 45 "data/maps/Route403/scripts.pory"
	waitmoncry
# 46 "data/maps/Route403/scripts.pory"
	applymovement 5, Common_Movement_FaceRight
# 47 "data/maps/Route403/scripts.pory"
	waitmovement 0
# 48 "data/maps/Route403/scripts.pory"
	release
	end


Route403_EventScript_RichBoy::
# 53 "data/maps/Route403/scripts.pory"
	lock
# 54 "data/maps/Route403/scripts.pory"
	applymovement 8, Route403_Movement_RichBoyJumpInPlace
# 55 "data/maps/Route403/scripts.pory"
	waitmovement 0
# 56 "data/maps/Route403/scripts.pory"
	loadspeechtail FALSE, 8
# 57 "data/maps/Route403/scripts.pory"
	msgbox Route403_EventScript_RichBoy_Text_0
# 60 "data/maps/Route403/scripts.pory"
	destroyspeechtail
# 61 "data/maps/Route403/scripts.pory"
	closemessage
# 62 "data/maps/Route403/scripts.pory"
	compare VAR_FIRWEALD_CITY_STATE, 0
	goto_if_gt Route403_EventScript_RichBoy_2
Route403_EventScript_RichBoy_1:
# 73 "data/maps/Route403/scripts.pory"
	release
	end

Route403_EventScript_RichBoy_2:
# 63 "data/maps/Route403/scripts.pory"
	applymovement 6, Route403_Movement_TeamAirlockGrunt1WalkBack
# 64 "data/maps/Route403/scripts.pory"
	applymovement 8, Route403_Movement_RichBoyWalkToMurenaCity
# 65 "data/maps/Route403/scripts.pory"
	waitmovement 0
# 66 "data/maps/Route403/scripts.pory"
	applymovement 6, Route403_Movement_TeamAirlockGruntsWalkToMurenaCity
# 67 "data/maps/Route403/scripts.pory"
	applymovement 7, Route403_Movement_TeamAirlockGruntsWalkToMurenaCity
# 68 "data/maps/Route403/scripts.pory"
	waitmovement 0
# 69 "data/maps/Route403/scripts.pory"
	removeobject 8
# 70 "data/maps/Route403/scripts.pory"
	removeobject 6
# 71 "data/maps/Route403/scripts.pory"
	removeobject 7
	goto Route403_EventScript_RichBoy_1


Route403_EventScript_Grunt::
# 78 "data/maps/Route403/scripts.pory"
	msgbox Route403_EventScript_Grunt_Text_0, MSGBOX_NPC
	end


Route403_EventScript_TrainerTipsSign::
# 84 "data/maps/Route403/scripts.pory"
	msgbox Route403_EventScript_TrainerTipsSign_Text_0, MSGBOX_SIGN
	end


# 91 "data/maps/Route403/scripts.pory"
Route403_Movement_YoungsterJumpInPlace:
# 92 "data/maps/Route403/scripts.pory"
	face_left
# 93 "data/maps/Route403/scripts.pory"
	jump_in_place_left
# 93 "data/maps/Route403/scripts.pory"
	jump_in_place_left
# 93 "data/maps/Route403/scripts.pory"
	jump_in_place_left
	step_end

# 96 "data/maps/Route403/scripts.pory"
Route403_Movement_ZigzagoonJumpInPlace:
# 97 "data/maps/Route403/scripts.pory"
	jump_in_place_right
# 97 "data/maps/Route403/scripts.pory"
	jump_in_place_right
# 97 "data/maps/Route403/scripts.pory"
	jump_in_place_right
	step_end

# 100 "data/maps/Route403/scripts.pory"
Route403_Movement_RichBoyJumpInPlace:
# 101 "data/maps/Route403/scripts.pory"
	jump_in_place_right
# 101 "data/maps/Route403/scripts.pory"
	jump_in_place_right
	step_end

# 104 "data/maps/Route403/scripts.pory"
Route403_Movement_TeamAirlockGrunt1WalkBack:
# 105 "data/maps/Route403/scripts.pory"
	walk_right
# 106 "data/maps/Route403/scripts.pory"
	walk_down
# 107 "data/maps/Route403/scripts.pory"
	face_up
	step_end

# 110 "data/maps/Route403/scripts.pory"
Route403_Movement_RichBoyWalkToMurenaCity:
# 111 "data/maps/Route403/scripts.pory"
	walk_right
# 111 "data/maps/Route403/scripts.pory"
	walk_right
# 111 "data/maps/Route403/scripts.pory"
	walk_right
# 111 "data/maps/Route403/scripts.pory"
	walk_right
# 111 "data/maps/Route403/scripts.pory"
	walk_right
# 111 "data/maps/Route403/scripts.pory"
	walk_right
# 111 "data/maps/Route403/scripts.pory"
	walk_right
	step_end

# 114 "data/maps/Route403/scripts.pory"
Route403_Movement_TeamAirlockGruntsWalkToMurenaCity:
# 115 "data/maps/Route403/scripts.pory"
	walk_right
# 115 "data/maps/Route403/scripts.pory"
	walk_right
# 115 "data/maps/Route403/scripts.pory"
	walk_right
# 115 "data/maps/Route403/scripts.pory"
	walk_right
# 115 "data/maps/Route403/scripts.pory"
	walk_right
# 115 "data/maps/Route403/scripts.pory"
	walk_right
	step_end

Route403_EventScript_BugCatcher_Text_0:
# 29 "data/maps/Route403/scripts.pory"
	.string "I'm training my ZIGZAGOON\n"
	.string "so we can challenge PHYLLOS\l"
	.string "one day!$"

Route403_EventScript_RichBoy_Text_0:
# 57 "data/maps/Route403/scripts.pory"
	.string "Get outta here!\n"
	.string "You blue collar scum!\p"
	.string "My daddy's boat is about to arrive!$"

Route403_EventScript_Grunt_Text_0:
# 78 "data/maps/Route403/scripts.pory"
	.string "We got some business here, so\n"
	.string "I'm keeping an eye out.$"

Route403_EventScript_TrainerTipsSign_Text_0:
# 84 "data/maps/Route403/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Always make sure you have enough\n"
	.string "POKéBALLS in your bag!\p"
	.string "You never know what you'll run into.$"

Route403_Text_TimmyIntro::
# 118 "data/maps/Route403/scripts.pory"
	.string "My CLEFAIRY wields the power\n"
	.string "of the stars!$"

Route403_Text_TimmyPostBattle::
# 123 "data/maps/Route403/scripts.pory"
	.string "Now where did I keep that MOON STONE…?$"

Route403_Text_TimmyDefeat::
# 127 "data/maps/Route403/scripts.pory"
	.string "Guess sometimes you should\p"
	.string "get your head out of the stars\p"
	.string "and come down to earth…$"

Route403_Text_AnnaIntro::
# 133 "data/maps/Route403/scripts.pory"
	.string "Sleep tight and don't let the\n"
	.string "bed bugs bite!$"

Route403_Text_AnnaDefeat::
# 138 "data/maps/Route403/scripts.pory"
	.string "Hwwwaahhhh.... Nooo JIGGLYPUFF!\p"
	.string "Don't put ME to sleep!$"

Route403_Text_AnnaPostBattle::
# 143 "data/maps/Route403/scripts.pory"
	.string "Maybe I should get into\n"
	.string "CONTESTS instead…$"

Route403_Text_WarrenIntro::
# 148 "data/maps/Route403/scripts.pory"
	.string "You'll regret coming round\n"
	.string "here soon enough!\p"
	.string "Go RATTATA!\n"
	.string "Bite where it stings!$"

Route403_Text_WarrenDefeat::
# 155 "data/maps/Route403/scripts.pory"
	.string "The only place that stings now\p"
	.string "is my heart…$"

Route403_Text_WarrenPostBattle::
# 160 "data/maps/Route403/scripts.pory"
	.string "Fight me again when we're stronger!$"
