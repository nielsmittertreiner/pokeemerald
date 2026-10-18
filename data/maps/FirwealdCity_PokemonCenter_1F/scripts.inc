FirwealdCity_PokemonCenter_1F_MapScripts::
	.byte 0


FirwealdCity_PokemonCenter_1F_EventScript_Nurse::
# 6 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	lock
# 7 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 8 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_0, MSGBOX_NPC
# 10 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	loadspeechtail FALSE, 1
# 11 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_1, MSGBOX_YESNO
# 12 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	destroyspeechtail
# 13 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	switch VAR_RESULT
# 14 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	case YES, FirwealdCity_PokemonCenter_1F_EventScript_Nurse_3
# 45 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	case NO, FirwealdCity_PokemonCenter_1F_EventScript_Nurse_4
FirwealdCity_PokemonCenter_1F_EventScript_Nurse_1:
# 48 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_5, MSGBOX_NPC
	end

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_3:
# 15 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	incrementgamestat GAME_STAT_USED_POKECENTER
# 16 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_2, MSGBOX_NPC
# 18 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
# 19 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 20 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	dofieldeffect FLDEFF_POKECENTER_HEAL
# 21 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	waitfieldeffect FLDEFF_POKECENTER_HEAL
# 22 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
# 23 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 24 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	special HealPlayerParty
# 25 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_POKERUS_EXPLAINED, FirwealdCity_PokemonCenter_1F_EventScript_Nurse_6
# 38 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_4, MSGBOX_NPC
# 41 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	applymovement 1, Common_Movement_NurseBow
# 42 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	waitmovement 0
FirwealdCity_PokemonCenter_1F_EventScript_Nurse_5:
	goto FirwealdCity_PokemonCenter_1F_EventScript_Nurse_1

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_4:
	goto FirwealdCity_PokemonCenter_1F_EventScript_Nurse_1

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_6:
# 26 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, IsPokerusInParty
# 27 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FirwealdCity_PokemonCenter_1F_EventScript_Nurse_9
	goto FirwealdCity_PokemonCenter_1F_EventScript_Nurse_5

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_9:
# 28 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_3, MSGBOX_NPC
# 35 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	setflag FLAG_POKERUS_EXPLAINED
	goto FirwealdCity_PokemonCenter_1F_EventScript_Nurse_5


FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_0:
# 8 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	.string "Welcome to CEDARRED TOWN's\n"
	.string "POKéMON CENTER.$"

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_1:
# 11 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	.string "Would you like to rest your POKEMON?$"

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_2:
# 16 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	.string "Okay, I'll take your POKéMON\n"
	.string "for a few seconds.$"

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_3:
# 28 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	.string "Your POKéMON may be infected with\n"
	.string "POKéRUS.\p"
	.string "Little is known about the POKéRUS\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to POKéMON.\p"
	.string "While infected, POKéMON are said to\n"
	.string "grow exceptionally well.$"

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_4:
# 38 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	.string "Thank you for waiting.\p"
	.string "We've restored your POKéMON\n"
	.string "to full health.$"

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_5:
# 48 "data/maps/FirwealdCity_PokemonCenter_1F/scripts.pory"
	.string "Thanks you for visiting\n"
	.string "CEDARRED TOWN's POKEMON CENTER!$"
