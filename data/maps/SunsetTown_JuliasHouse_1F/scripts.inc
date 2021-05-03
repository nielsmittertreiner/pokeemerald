SunsetTown_JuliasHouse_1F_MapScripts::
	.byte 0


SunsetTown_JuliasHouse_1F_EventScript_Woman::
	switch VAR_JULIA_STATE
	case 0, SunsetTown_JuliasHouse_1F_EventScript_Woman_3
	msgbox SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_2, MSGBOX_NPC
SunsetTown_JuliasHouse_1F_EventScript_Woman_1:
	end

SunsetTown_JuliasHouse_1F_EventScript_Woman_3:
	checkplayergender
	switch VAR_RESULT
	case 0, SunsetTown_JuliasHouse_1F_EventScript_Woman_7
	case 1, SunsetTown_JuliasHouse_1F_EventScript_Woman_8
SunsetTown_JuliasHouse_1F_EventScript_Woman_5:
	goto SunsetTown_JuliasHouse_1F_EventScript_Woman_1

SunsetTown_JuliasHouse_1F_EventScript_Woman_7:
	msgbox SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_0, MSGBOX_NPC
	goto SunsetTown_JuliasHouse_1F_EventScript_Woman_5

SunsetTown_JuliasHouse_1F_EventScript_Woman_8:
	msgbox SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_1, MSGBOX_NPC
	goto SunsetTown_JuliasHouse_1F_EventScript_Woman_5


SunsetTown_JuliasHouse_1F_EventScript_Item_Ball::
	msgbox SunsetTown_JuliasHouse_1F_EventScript_Item_Ball_Text_0
	closemessage
	end


SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_0:
	.string "Hi there! You must be {PLAYER},\n"
	.string "PROFESSOR CONIFER's son right?\p"
	.string "… … …\p"
	.string "JULIA is not here right now, she's\n"
	.string "at the GREENERY SHOP in ACREN FOREST\l"
	.string "buying some flowers for someone.\p"
	.string "If you want to meet her, you should\n"
	.string "go there.$"

SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_1:
	.string "Hi there! You must be {PLAYER},\n"
	.string "PROFESSOR CONIFER's daughter right?\p"
	.string "… … …\p"
	.string "JULIA is not here right now, she's\n"
	.string "at the GREENERY SHOP in ACREN FOREST\l"
	.string "buying some flowers for someone.\p"
	.string "If you want to meet her, you should\n"
	.string "go there.$"

SunsetTown_JuliasHouse_1F_EventScript_Woman_Text_2:
	.string "Oh hi there {PLAYER}!\n"
	.string "I hope you're doing alright.$"

SunsetTown_JuliasHouse_1F_EventScript_Item_Ball_Text_0:
	.string "It's a POKéBALL from JULIA's MOM.\n"
	.string "What could be inside…$"
