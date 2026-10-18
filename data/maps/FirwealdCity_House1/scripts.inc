FirwealdCity_House1_MapScripts::
# 4 "data/maps/FirwealdCity_House1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FirwealdCity_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

FirwealdCity_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/FirwealdCity_House1/scripts.pory"
	goto_if_set FLAG_HIDE_FIRWEALD_CITY_HOUSE1_LITTLE_GIRL, FirwealdCity_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

FirwealdCity_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 6 "data/maps/FirwealdCity_House1/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_LOOK_AROUND
# 7 "data/maps/FirwealdCity_House1/scripts.pory"
	setobjectxyperm 2, 10, 6
	return


FirwealdCity_House1_EventScript_Gentleman::
# 13 "data/maps/FirwealdCity_House1/scripts.pory"
	msgbox FirwealdCity_House1_EventScript_Gentleman_Text_0, MSGBOX_NPC
	end


FirwealdCity_House1_EventScript_Lass::
# 19 "data/maps/FirwealdCity_House1/scripts.pory"
	msgbox FirwealdCity_House1_EventScript_Lass_Text_0, MSGBOX_NPC
	end


FirwealdCity_House1_EventScript_LittleGirl::
# 26 "data/maps/FirwealdCity_House1/scripts.pory"
	msgbox FirwealdCity_House1_EventScript_LittleGirl_Text_0, MSGBOX_NPC
	end


FirwealdCity_House1_EventScript_Zigzagoon::
# 32 "data/maps/FirwealdCity_House1/scripts.pory"
	lock
# 33 "data/maps/FirwealdCity_House1/scripts.pory"
	faceplayer
# 34 "data/maps/FirwealdCity_House1/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, 0
# 35 "data/maps/FirwealdCity_House1/scripts.pory"
	waitmoncry
# 36 "data/maps/FirwealdCity_House1/scripts.pory"
	release
	end


FirwealdCity_House1_EventScript_Gentleman_Text_0:
# 13 "data/maps/FirwealdCity_House1/scripts.pory"
	.string "I've always been a hard-working man, so\n"
	.string "I bought this new house with my pension.$"

FirwealdCity_House1_EventScript_Lass_Text_0:
# 19 "data/maps/FirwealdCity_House1/scripts.pory"
	.string "Thanks for helping me out!\p"
	.string "I don't think I would have found her\n"
	.string "myself…$"

FirwealdCity_House1_EventScript_LittleGirl_Text_0:
# 26 "data/maps/FirwealdCity_House1/scripts.pory"
	.string "Weeee!\n"
	.string "Grandpa's ZIGZAGOON is so adorable!$"
