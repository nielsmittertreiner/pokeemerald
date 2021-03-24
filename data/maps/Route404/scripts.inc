Route404_MapScripts::
	.byte 0


Route404_EventScript_SwimmerM::
	trainerbattle_single TRAINER_ROUTE404_WILLIAM, Route404_Text_WilliamIntro, Route404_Text_WilliamDefeat
	msgbox Route404_Text_WilliamPostBattle, MSGBOX_NPC
	end


Route404_EventScript_SwimmerF::
	trainerbattle_single TRAINER_ROUTE404_SARAH, Route404_Text_SarahIntro, Route404_Text_SarahDefeat
	msgbox Route404_Text_SarahPostBattle, MSGBOX_NPC
	end


Route404_EventScript_TuberMSwimming::
	msgbox Route404_EventScript_TuberMSwimming_Text_0, MSGBOX_NPC
	end


Route404_EventScript_TuberMSwimming_Text_0:
	.string "Look how far I've drifted off of\n"
	.string "the beach!\p"
	.string "I might even end up in MURENA CITY.$"

Route404_Text_WilliamIntro::
	.string "Try beating me in the water!$"

Route404_Text_WilliamDefeat::
	.string "Huff puff puff…\n"
	.string "Swimming is tiring…$"

Route404_Text_WilliamPostBattle::
	.string "Swimming really gets you ripped\n"
	.string "you know!$"

Route404_Text_SarahIntro::
	.string "My GOLDEEN evolved a while back!\n"
	.string "I'll try its new power on you!$"

Route404_Text_SarahDefeat::
	.string "SEAKING held on for longer than\n"
	.string "GOLDEEN ever did.$"

Route404_Text_SarahPostBattle::
	.string "Is a female SEAKING called a SEAQUEEN?$"
