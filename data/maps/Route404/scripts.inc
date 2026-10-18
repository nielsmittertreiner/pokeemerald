Route404_MapScripts::
	.byte 0


Route404_EventScript_SwimmerM::
# 4 "data/maps/Route404/scripts.pory"
	trainerbattle_single TRAINER_ROUTE404_WILLIAM, Route404_Text_WilliamIntro, Route404_Text_WilliamDefeat
# 5 "data/maps/Route404/scripts.pory"
	msgbox Route404_Text_WilliamPostBattle, MSGBOX_NPC
	end


Route404_EventScript_SwimmerF::
# 10 "data/maps/Route404/scripts.pory"
	trainerbattle_single TRAINER_ROUTE404_SARAH, Route404_Text_SarahIntro, Route404_Text_SarahDefeat
# 11 "data/maps/Route404/scripts.pory"
	msgbox Route404_Text_SarahPostBattle, MSGBOX_NPC
	end


Route404_EventScript_TuberMSwimming::
# 16 "data/maps/Route404/scripts.pory"
	msgbox Route404_EventScript_TuberMSwimming_Text_0, MSGBOX_NPC
	end


Route404_EventScript_TuberMSwimming_Text_0:
# 16 "data/maps/Route404/scripts.pory"
	.string "Look how far I've drifted off of\n"
	.string "the beach!\p"
	.string "I might even end up in MURENA CITY.$"

Route404_Text_WilliamIntro::
# 22 "data/maps/Route404/scripts.pory"
	.string "Try beating me in the water!$"

Route404_Text_WilliamDefeat::
# 26 "data/maps/Route404/scripts.pory"
	.string "Huff puff puff…\p"
	.string "Swimming is tiring…$"

Route404_Text_WilliamPostBattle::
# 31 "data/maps/Route404/scripts.pory"
	.string "Swimming really gets you ripped\n"
	.string "you know!$"

Route404_Text_SarahIntro::
# 36 "data/maps/Route404/scripts.pory"
	.string "My GOLDEEN evolved a while back!\n"
	.string "I'll try its new power on you!$"

Route404_Text_SarahDefeat::
# 41 "data/maps/Route404/scripts.pory"
	.string "SEAKING held on for longer than\p"
	.string "GOLDEEN ever did.$"

Route404_Text_SarahPostBattle::
# 46 "data/maps/Route404/scripts.pory"
	.string "Is a female SEAKING called a SEAQUEEN?$"
