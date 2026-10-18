SunsetTown_JuliasHouse_1F_MapScripts::
	.byte 0


SunsetTown_JuliasHouse_1F_EventScript_Woman::
# 6 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	switch VAR_JULIA_STATE
# 7 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	case 0, SunsetTown_JuliasHouse_1F_EventScript_Woman_3
# 33 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	msgbox SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_2, MSGBOX_NPC
SunsetTown_JuliasHouse_1F_EventScript_Woman_1:
	end

SunsetTown_JuliasHouse_1F_EventScript_Woman_3:
# 8 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	checkplayergender
# 9 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	switch VAR_RESULT
# 10 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	case 0, SunsetTown_JuliasHouse_1F_EventScript_Woman_7
# 20 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	case 1, SunsetTown_JuliasHouse_1F_EventScript_Woman_8
SunsetTown_JuliasHouse_1F_EventScript_Woman_5:
	goto SunsetTown_JuliasHouse_1F_EventScript_Woman_1

SunsetTown_JuliasHouse_1F_EventScript_Woman_7:
# 11 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	msgbox SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_0, MSGBOX_NPC
	goto SunsetTown_JuliasHouse_1F_EventScript_Woman_5

SunsetTown_JuliasHouse_1F_EventScript_Woman_8:
# 21 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	msgbox SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_1, MSGBOX_NPC
	goto SunsetTown_JuliasHouse_1F_EventScript_Woman_5


SunsetTown_JuliasHouse_1F_EventScript_Item_Ball::
# 41 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	msgbox SunsetTown_JuliasHouse_1F_EventScript_Item_Ball_Text_0
# 43 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	closemessage
	end


SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_0:
# 11 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	.string "Hi there! You must be {PLAYER},\n"
	.string "PROFESSOR CONIFER's son right?\p"
	.string "… … …\p"
	.string "JULIA is not here right now, she's\n"
	.string "at the GREENERY SHOP in ACREN FOREST\l"
	.string "buying some flowers for someone.\p"
	.string "If you want to meet her, you should\n"
	.string "go there.$"

SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_1:
# 21 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	.string "Hi there! You must be {PLAYER},\n"
	.string "PROFESSOR CONIFER's daughter right?\p"
	.string "… … …\p"
	.string "JULIA is not here right now, she's\n"
	.string "at the GREENERY SHOP in ACREN FOREST\l"
	.string "buying some flowers for someone.\p"
	.string "If you want to meet her, you should\n"
	.string "go there.$"

SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_2:
# 33 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	.string "Oh hi there {PLAYER}!\n"
	.string "I hope you're doing alright.$"

SunsetTown_JuliasHouse_1F_EventScript_Item_Ball_Text_0:
# 41 "data/maps/SunsetTown_JuliasHouse_1F/scripts.pory"
	.string "It's a POKéBALL from JULIA's MOM.\n"
	.string "What could be inside…$"
