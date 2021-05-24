FirwealdCity_House1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FirwealdCity_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

FirwealdCity_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_HIDE_FIRWEALD_CITY_HOUSE1_LITTLE_GIRL, FirwealdCity_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

FirwealdCity_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectmovementtype 2, MOVEMENT_TYPE_LOOK_AROUND
	setobjectxyperm 2, 10, 6
	return


FirwealdCity_House1_EventScript_Gentleman::
	msgbox FirwealdCity_House1_EventScript_Gentleman_Text_0, MSGBOX_NPC
	end


FirwealdCity_House1_EventScript_Lass::
	msgbox FirwealdCity_House1_EventScript_Lass_Text_0, MSGBOX_NPC
	end


FirwealdCity_House1_EventScript_LittleGirl::
	msgbox FirwealdCity_House1_EventScript_LittleGirl_Text_0, MSGBOX_NPC
	end


FirwealdCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	playmoncry SPECIES_ZIGZAGOON, 0
	waitmoncry
	release
	end


FirwealdCity_House1_EventScript_Gentleman_Text_0:
	.string "I've always been a hard-working man, so\n"
	.string "I bought this new house with my pension.$"

FirwealdCity_House1_EventScript_Lass_Text_0:
	.string "Thanks for helping me out!\p"
	.string "I don't think I would have found her\n"
	.string "myself…$"

FirwealdCity_House1_EventScript_LittleGirl_Text_0:
	.string "Weeee!\n"
	.string "Grandpa's ZIGZAGOON is so adorable!$"
