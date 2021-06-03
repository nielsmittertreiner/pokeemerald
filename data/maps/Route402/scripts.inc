Route402_MapScripts::
	.byte 0


Route402_EventScript_RouteSign::
	msgbox Route402_EventScript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route402_EventScript_Boy::
	msgbox Route402_EventScript_Boy_Text_0, MSGBOX_NPC
	end


Route402_EventScript_Triathlete::
	msgbox Route402_EventScript_Triathlete_Text_0, MSGBOX_NPC
	end


Route402_EventScript_Fisherman1::
	msgbox Route402_EventScript_Fisherman1_Text_0, MSGBOX_NPC
	end


Route402_EventScript_Fisherman2::
	goto_if_unset FLAG_TEMP_1, Route402_EventScript_Fisherman2_3
	msgbox Route402_EventScript_Fisherman2_Text_1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

Route402_EventScript_Fisherman2_3:
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route402_EventScript_Fisherman2_Text_0, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end


Route402_EventScript_ItemPotion::
	finditem ITEM_POTION
	end


Route402_EventScript_Timmy::
	trainerbattle_single TRAINER_ROUTE_402_TIMMY, Route402_Text_TimmyIntro, Route402_Text_TimmyDefeat
	msgbox Route402_Text_TimmyPostBattle, MSGBOX_NPC
	end


Route402_EventScript_Mimi::
	trainerbattle_double TRAINER_ROUTE_402_TWINS_MIMI_AND_MOMO, Route402_Text_MimiIntro, Route402_Text_MimiDefeat, Route402_Text_MimiNotEnoughMons
	msgbox Route402_Text_MimiPostBattle, MSGBOX_NPC
	end


Route402_EventScript_Momo::
	trainerbattle_double TRAINER_ROUTE_402_TWINS_MIMI_AND_MOMO, Route402_Text_MomoIntro, Route402_Text_MomoDefeat, Route402_Text_MomoNotEnoughMons
	msgbox Route402_Text_MomoPostBattle, MSGBOX_NPC
	end


Route402_EventScript_RouteSign_Text_0:
	.string "{UP_ARROW} FIRWEALD CITY\n"
	.string "{DOWN_ARROW} ACREN FOREST$"

Route402_EventScript_Boy_Text_0:
	.string "Sniff sniff...\n"
	.string "Why did my parents move to this area?\p"
	.string "I have allergies...\p"
	.string "Achoo!$"

Route402_EventScript_Triathlete_Text_0:
	.string "Every day I train at this small lake.\n"
	.string "The fresh air helps me breathe easier!$"

Route402_EventScript_Fisherman1_Text_0:
	.string "I don't get a bite often with my OLD ROD…$"

Route402_EventScript_Fisherman2_Text_0:
	.string "Did I just catch a glimpse of a GYARADOS!$"

Route402_EventScript_Fisherman2_Text_1:
	.string "Did you just see that too?!$"

Route402_Text_MimiIntro::
	.string "Double the POKéMON!\n"
	.string "Double the fun!$"

Route402_Text_MimiDefeat::
	.string "Even though we battled\p"
	.string "together we lost…$"

Route402_Text_MimiNotEnoughMons::
	.string "We're with too, you're with one…$"

Route402_Text_MimiPostBattle::
	.string "You're a really strong trainer!$"

Route402_Text_MomoIntro::
	.string "We're twins, so we battle\n"
	.string "together.$"

Route402_Text_MomoDefeat::
	.string "Wow! You're so strong!$"

Route402_Text_MomoNotEnoughMons::
	.string "Oh? Only one POKéMON?\n"
	.string "Then, we don't battle with you.\p"
	.string "If there's only one POKéMON, it will\n"
	.string "be lonesome. That's not nice.$"

Route402_Text_MomoPostBattle::
	.string "Hopefully we'll become as strong\n"
	.string "as you once.$"

Route402_Text_TimmyIntro::
	.string "I just caught a ZIGZAGOON!\p"
	.string "Go ZIGZAGOON!$"

Route402_Text_TimmyDefeat::
	.string "I guess I didn't train\p"
	.string "my ZIGZAGOON enough yet…$"

Route402_Text_TimmyPostBattle::
	.string "I'll train my ZIGZAGOON stronger!$"
