Route403_MapScripts::
	.byte 0


Route403_EventScript_Timmy::
	trainerbattle_single TRAINER_ROUTE403_TIMMY, Route403_Text_TimmyIntro, Route403_Text_TimmyDefeat
	msgbox Route403_Text_TimmyPostBattle, MSGBOX_NPC
	end


Route403_EventScript_Anna::
	trainerbattle_single TRAINER_ROUTE403_ANNA, Route403_Text_AnnaIntro, Route403_Text_AnnaDefeat
	msgbox Route403_Text_AnnaPostBattle, MSGBOX_NPC
	end


Route403_EventScript_Warren::
	trainerbattle_single TRAINER_ROUTE403_WARREN, Route403_Text_WarrenIntro, Route403_Text_WarrenDefeat
	msgbox Route403_Text_WarrenPostBattle, MSGBOX_NPC
	end


Route403_EventScript_BugCatcher::
	lock
	msgbox Route403_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	applymovement 4, Route403_Movement_YoungsterJumpInPlace
	applymovement 5, Route403_Movement_ZigzagoonJumpInPlace
	delay 8
	playmoncry SPECIES_ZIGZAGOON, 0
	waitmovement 0
	release
	end


Route403_EventScript_Zigzagoon::
	lock
	faceplayer
	playmoncry SPECIES_ZIGZAGOON, 0
	waitmoncry
	applymovement 5, Common_Movement_FaceRight
	waitmovement 0
	release
	end


Route403_EventScript_RichBoy::
	lock
	applymovement 8, Route403_Movement_RichBoyJumpInPlace
	waitmovement 0
	load_speech_bubble 8
	msgbox Route403_EventScript_RichBoy_Text_0
	destroy_speech_bubble
	closemessage
	compare VAR_FIRWEALD_CITY_STATE, 0
	goto_if_gt Route403_EventScript_RichBoy_2
Route403_EventScript_RichBoy_1:
	release
	end

Route403_EventScript_RichBoy_2:
	applymovement 6, Route403_Movement_TeamAirlockGrunt1WalkBack
	applymovement 8, Route403_Movement_RichBoyWalkToMurenaCity
	waitmovement 0
	applymovement 6, Route403_Movement_TeamAirlockGruntsWalkToMurenaCity
	applymovement 7, Route403_Movement_TeamAirlockGruntsWalkToMurenaCity
	waitmovement 0
	removeobject 8
	removeobject 6
	removeobject 7
	goto Route403_EventScript_RichBoy_1


Route403_EventScript_Grunt::
	msgbox Route403_EventScript_Grunt_Text_0, MSGBOX_NPC
	end


Route403_EventScript_TrainerTipsSign::
	msgbox Route403_EventScript_TrainerTipsSign_Text_0, MSGBOX_SIGN
	end


Route403_Movement_YoungsterJumpInPlace:
	face_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

Route403_Movement_ZigzagoonJumpInPlace:
	jump_in_place_right
	jump_in_place_right
	jump_in_place_right
	step_end

Route403_Movement_RichBoyJumpInPlace:
	jump_in_place_right
	jump_in_place_right
	step_end

Route403_Movement_TeamAirlockGrunt1WalkBack:
	walk_right
	walk_down
	face_up
	step_end

Route403_Movement_RichBoyWalkToMurenaCity:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route403_Movement_TeamAirlockGruntsWalkToMurenaCity:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route403_EventScript_BugCatcher_Text_0:
	.string "I'm training my ZIGZAGOON\n"
	.string "so we can challenge PHYLLOS\l"
	.string "one day!$"

Route403_EventScript_RichBoy_Text_0:
	.string "Get outta here!\n"
	.string "You blue collar scum!\p"
	.string "My daddy's boat is about to arrive!$"

Route403_EventScript_Grunt_Text_0:
	.string "We got some business here, so\n"
	.string "I'm keeping an eye out.$"

Route403_EventScript_TrainerTipsSign_Text_0:
	.string "TRAINER TIPS\p"
	.string "Always make sure you have enough\n"
	.string "POKéBALLS in your bag!\p"
	.string "You never know what you'll run into.$"

Route403_Text_TimmyIntro::
	.string "My CLEFAIRY wields the power\n"
	.string "of the stars!$"

Route403_Text_TimmyPostBattle::
	.string "Now where did I keep that MOON STONE…?$"

Route403_Text_TimmyDefeat::
	.string "Guess sometimes you should\p"
	.string "get your head out of the stars\p"
	.string "and come down to earth…$"

Route403_Text_AnnaIntro::
	.string "Sleep tight and don't let the\n"
	.string "bed bugs bite!$"

Route403_Text_AnnaDefeat::
	.string "Hwwwaahhhh.... Nooo JIGGLYPUFF!\p"
	.string "Don't put ME to sleep!$"

Route403_Text_AnnaPostBattle::
	.string "Maybe I should get into\n"
	.string "CONTESTS instead…$"

Route403_Text_WarrenIntro::
	.string "You'll regret coming round\n"
	.string "here soon enough!\p"
	.string "Go RATTATA!\n"
	.string "Bite where it stings!$"

Route403_Text_WarrenDefeat::
	.string "The only place that stings now\p"
	.string "is my heart…$"

Route403_Text_WarrenPostBattle::
	.string "Fight me again when we're stronger!$"
