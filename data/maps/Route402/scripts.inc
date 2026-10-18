Route402_MapScripts::
	.byte 0


Route402_EventScript_RouteSign::
# 6 "data/maps/Route402/scripts.pory"
	msgbox Route402_EventScript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route402_EventScript_Boy::
# 12 "data/maps/Route402/scripts.pory"
	msgbox Route402_EventScript_Boy_Text_0, MSGBOX_NPC
	end


Route402_EventScript_Triathlete::
# 20 "data/maps/Route402/scripts.pory"
	msgbox Route402_EventScript_Triathlete_Text_0, MSGBOX_NPC
	end


Route402_EventScript_Fisherman1::
# 26 "data/maps/Route402/scripts.pory"
	msgbox Route402_EventScript_Fisherman1_Text_0, MSGBOX_NPC
	end


Route402_EventScript_Fisherman2::
# 31 "data/maps/Route402/scripts.pory"
	goto_if_unset FLAG_TEMP_1, Route402_EventScript_Fisherman2_3
# 39 "data/maps/Route402/scripts.pory"
	msgbox Route402_EventScript_Fisherman2_Text_1, MSGBOX_NPC
# 40 "data/maps/Route402/scripts.pory"
	setflag FLAG_TEMP_1
	end

Route402_EventScript_Fisherman2_3:
# 32 "data/maps/Route402/scripts.pory"
	playse SE_PIN
# 33 "data/maps/Route402/scripts.pory"
	applymovement 6, Common_Movement_ExclamationMark
# 34 "data/maps/Route402/scripts.pory"
	waitmovement 0
# 35 "data/maps/Route402/scripts.pory"
	msgbox Route402_EventScript_Fisherman2_Text_0, MSGBOX_NPC
# 36 "data/maps/Route402/scripts.pory"
	setflag FLAG_TEMP_1
	end


Route402_EventScript_ItemPotion::
# 45 "data/maps/Route402/scripts.pory"
	finditem ITEM_POTION
	end


Route402_EventScript_Timmy::
# 50 "data/maps/Route402/scripts.pory"
	trainerbattle_single TRAINER_ROUTE_402_TIMMY, Route402_Text_TimmyIntro, Route402_Text_TimmyDefeat
# 51 "data/maps/Route402/scripts.pory"
	msgbox Route402_Text_TimmyPostBattle, MSGBOX_NPC
	end


Route402_EventScript_Mimi::
# 56 "data/maps/Route402/scripts.pory"
	trainerbattle_double TRAINER_ROUTE_402_TWINS_MIMI_AND_MOMO, Route402_Text_MimiIntro, Route402_Text_MimiDefeat, Route402_Text_MimiNotEnoughMons
# 57 "data/maps/Route402/scripts.pory"
	msgbox Route402_Text_MimiPostBattle, MSGBOX_NPC
	end


Route402_EventScript_Momo::
# 62 "data/maps/Route402/scripts.pory"
	trainerbattle_double TRAINER_ROUTE_402_TWINS_MIMI_AND_MOMO, Route402_Text_MomoIntro, Route402_Text_MomoDefeat, Route402_Text_MomoNotEnoughMons
# 63 "data/maps/Route402/scripts.pory"
	msgbox Route402_Text_MomoPostBattle, MSGBOX_NPC
	end


Route402_EventScript_RouteSign_Text_0:
# 6 "data/maps/Route402/scripts.pory"
	.string "{UP_ARROW} FIRWEALD CITY\n"
	.string "{DOWN_ARROW} ACREN FOREST$"

Route402_EventScript_Boy_Text_0:
# 12 "data/maps/Route402/scripts.pory"
	.string "Sniff sniff...\n"
	.string "Why did my parents move to this area?\p"
	.string "I have allergies...\p"
	.string "Achoo!$"

Route402_EventScript_Triathlete_Text_0:
# 20 "data/maps/Route402/scripts.pory"
	.string "Every day I train at this small lake.\n"
	.string "The fresh air helps me breathe easier!$"

Route402_EventScript_Fisherman1_Text_0:
# 26 "data/maps/Route402/scripts.pory"
	.string "I don't get a bite often with my OLD ROD…$"

Route402_EventScript_Fisherman2_Text_0:
# 35 "data/maps/Route402/scripts.pory"
	.string "Did I just catch a glimpse of a GYARADOS!$"

Route402_EventScript_Fisherman2_Text_1:
# 39 "data/maps/Route402/scripts.pory"
	.string "Did you just see that too?!$"

Route402_Text_MimiIntro::
# 67 "data/maps/Route402/scripts.pory"
	.string "Double the POKéMON!\n"
	.string "Double the fun!$"

Route402_Text_MimiDefeat::
# 72 "data/maps/Route402/scripts.pory"
	.string "Even though we battled\p"
	.string "together we lost…$"

Route402_Text_MimiNotEnoughMons::
# 77 "data/maps/Route402/scripts.pory"
	.string "We're with too, you're with one…$"

Route402_Text_MimiPostBattle::
# 81 "data/maps/Route402/scripts.pory"
	.string "You're a really strong trainer!$"

Route402_Text_MomoIntro::
# 85 "data/maps/Route402/scripts.pory"
	.string "We're twins, so we battle\n"
	.string "together.$"

Route402_Text_MomoDefeat::
# 90 "data/maps/Route402/scripts.pory"
	.string "Wow! You're so strong!$"

Route402_Text_MomoNotEnoughMons::
# 94 "data/maps/Route402/scripts.pory"
	.string "Oh? Only one POKéMON?\n"
	.string "Then, we don't battle with you.\p"
	.string "If there's only one POKéMON, it will\n"
	.string "be lonesome. That's not nice.$"

Route402_Text_MomoPostBattle::
# 101 "data/maps/Route402/scripts.pory"
	.string "Hopefully we'll become as strong\n"
	.string "as you once.$"

Route402_Text_TimmyIntro::
# 106 "data/maps/Route402/scripts.pory"
	.string "I just caught a ZIGZAGOON!\p"
	.string "Go ZIGZAGOON!$"

Route402_Text_TimmyDefeat::
# 111 "data/maps/Route402/scripts.pory"
	.string "I guess I didn't train\p"
	.string "my ZIGZAGOON enough yet…$"

Route402_Text_TimmyPostBattle::
# 116 "data/maps/Route402/scripts.pory"
	.string "I'll train my ZIGZAGOON stronger!$"
