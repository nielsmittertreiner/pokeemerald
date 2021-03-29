FirwealdCity_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FirwealdCity_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

FirwealdCity_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_PHYLLOS_LEFT_TOURNAMENT_HALL_LOBBY, FirwealdCity_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

FirwealdCity_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 37, 16, METATILE_Petalburg_ClosedTournamentHallDoor, 1
	return

FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_FIRWEALD_CITY
	setflag FLAG_VISITED_FIRWEALD_CITY
	compare VAR_ACREN_FOREST_STATE, 7
	goto_if_lt FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	compare VAR_FIRWEALD_CITY_STATE, 1
	goto_if_ge FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setobjectxyperm 6, 47, 18
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_UP
	goto FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	setobjectxyperm 1, 36, 10
	return


FirwealdCity_EventScript_ParkSign::
	msgbox FirwealdCity_EventScript_ParkSign_Text_0, MSGBOX_SIGN
	end


FirwealdCity_EventScript_CitySign::
	msgbox FirwealdCity_EventScript_CitySign_Text_0, MSGBOX_SIGN
	end


FirwealdCity_EventScript_CaveSign::
	msgbox FirwealdCity_EventScript_CaveSign_Text_0, MSGBOX_SIGN
	end


FirwealdCity_EventScript_TournamentHallSign::
	msgbox FirwealdCity_EventScript_TournamentHallSign_Text_0, MSGBOX_SIGN
	end


FirwealdCity_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end


FirwealdCity_EventScript_PhyllosEncounter::
	lock
	setmetatile 37, 16, METATILE_Petalburg_Door_BattleTent, 1
	opendoor 37, 16
	waitdooranim
	addobject 9
	applymovement 9, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_Movement_PlayerWalkDownBackwards
	waitmovement 0
	closedoor 37, 16
	waitdooranim
	waitmovement 0
	load_speech_bubble 9
	msgbox FirwealdCity_EventScript_PhyllosEncounter_Text_0
	destroy_speech_bubble
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_Movement_PlayerWalkDownBackwards
	applymovement 9, FirwealdCity_Movement_PhyllosWalkToForest
	waitmovement 0
	setmetatile 37, 16, METATILE_Petalburg_ClosedTournamentHallDoor, 1
	removeobject 9
	setflag FLAG_HIDE_ACREN_FOREST_GRUNTS_BLOCKING
	setvar VAR_ACREN_FOREST_STATE, 4
	setvar VAR_TOURNAMENT_HALL_STATE, 0
	release
	end


FirwealdCity_EventScript_Maniac::
	compare VAR_ACREN_FOREST_STATE, 7
	goto_if_lt FirwealdCity_EventScript_Maniac_1
	msgbox FirwealdCity_EventScript_Maniac_Text_1, MSGBOX_NPC
	return

FirwealdCity_EventScript_Maniac_1:
	msgbox FirwealdCity_EventScript_Maniac_Text_0, MSGBOX_NPC
	return


FirwealdCity_EventScript_BlockPath::
	compare VAR_ACREN_FOREST_STATE, 7
	goto_if_ge FirwealdCity_EventScript_BlockPath_1
	lock
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 6, FirwealdCity_Movement_WalkInFrontOfPlayer
	waitmovement 0
	load_speech_bubble 6
	msgbox FirwealdCity_EventScript_BlockPath_Text_0
	destroy_speech_bubble
	closemessage
	applymovement 6 FirwealdCity_Movement_PushBackPlayer
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_Movement_WalkBack
	waitmovement 0
	applymovement 6, Common_Movement_WalkUp
	waitmovement 0
	release
	end

FirwealdCity_EventScript_BlockPath_1:
	release
	end


FirwealdCity_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_FIRWEALD_CITY_FISHERMAN_MART_EVENT, FirwealdCity_EventScript_Fisherman_1
	msgbox FirwealdCity_EventScript_Fisherman_Text_1, MSGBOX_NPC
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	delay 32
	msgbox FirwealdCity_EventScript_Fisherman_Text_2, MSGBOX_NPC
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq FirwealdCity_EventScript_Fisherman_5
	applymovement 4, FirwealdCity_Movement_WalkToPokeMart
	waitmovement 0
FirwealdCity_EventScript_Fisherman_4:
	removeobject 4, MAP_FIRWEALD_CITY
	clearflag FLAG_HIDE_FIRWEALD_CITY_MART_FISHERMAN
	setflag FLAG_FIRWEALD_CITY_FISHERMAN_MART_EVENT
	release
	end

FirwealdCity_EventScript_Fisherman_1:
	msgbox FirwealdCity_EventScript_Fisherman_Text_0, MSGBOX_NPC
	end

FirwealdCity_EventScript_Fisherman_5:
	applymovement 4, FirwealdCity_Movement_WalkAroundPlayerToPokeMart
	waitmovement 0
	goto FirwealdCity_EventScript_Fisherman_4


FirwealdCity_EventScript_Triathlete::
	msgbox FirwealdCity_EventScript_Triathlete_Text_0, MSGBOX_NPC
	end


FirwealdCity_EventScript_Boy::
	msgbox FirwealdCity_EventScript_Boy_Text_0, MSGBOX_NPC
	end


FirwealdCity_EventScript_Lass::
	goto_if_set FLAG_FIRWEALD_CITY_HIDE_AND_SEEK_EVENT, FirwealdCity_EventScript_Lass_3
	lock
	faceplayer
	load_speech_bubble 3
	msgbox FirwealdCity_EventScript_Lass_Text_1, MSGBOX_YESNO
	destroy_speech_bubble
	switch VAR_RESULT
	case NO, FirwealdCity_EventScript_Lass_6
	case YES, FirwealdCity_EventScript_Lass_7
	return

FirwealdCity_EventScript_Lass_3:
	msgbox FirwealdCity_EventScript_Lass_Text_0, MSGBOX_NPC
	end

FirwealdCity_EventScript_Lass_6:
	msgbox FirwealdCity_EventScript_Lass_Text_2, MSGBOX_NPC
	end

FirwealdCity_EventScript_Lass_7:
	msgbox FirwealdCity_EventScript_Lass_Text_3, MSGBOX_NPC
	setflag FLAG_FIRWEALD_CITY_HIDE_AND_SEEK_EVENT
	end


FirwealdCity_EventScript_LittleGirl::
	goto_if_set FLAG_FIRWEALD_CITY_HIDE_AND_SEEK_EVENT, FirwealdCity_EventScript_LittleGirl_3
	msgbox FirwealdCity_EventScript_LittleGirl_Text_2, MSGBOX_NPC
	end

FirwealdCity_EventScript_LittleGirl_3:
	lock
	faceplayer
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_Movement_NoticeLittleGirlHidingSpot
	waitmovement 0
	load_speech_bubble 2
	msgbox FirwealdCity_EventScript_LittleGirl_Text_0
	destroy_speech_bubble
	closemessage
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq FirwealdCity_EventScript_LittleGirl_6
	applymovement 3, FirwealdCity_Movement_LassWalkToLittleGirlFacingEastAndWest
	waitmovement 0
FirwealdCity_EventScript_LittleGirl_5:
	load_speech_bubble 3
	msgbox FirwealdCity_EventScript_LittleGirl_Text_1
	destroy_speech_bubble
	closemessage
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq FirwealdCity_EventScript_LittleGirl_10
	applymovement 3, FirwealdCity_Movement_LassWalkHomeFacingEastAndWest
	applymovement 2, FirwealdCity_Movement_LittleGirlWalkHomeFacingEastAndWest
	waitmovement 0
FirwealdCity_EventScript_LittleGirl_9:
	removeobject 3, MAP_FIRWEALD_CITY
	removeobject 2, MAP_FIRWEALD_CITY
	clearflag FLAG_HIDE_FIRWEALD_CITY_HOUSE1_LITTLE_GIRL
	clearflag FLAG_HIDE_FIRWEALD_CITY_HOUSE1_LASS
	clearflag FLAG_FIRWEALD_CITY_HIDE_AND_SEEK_EVENT
	release
	end

FirwealdCity_EventScript_LittleGirl_6:
	applymovement 3, FirwealdCity_Movement_LassWalkToLittleGirlFacingSouth
	waitmovement 0
	goto FirwealdCity_EventScript_LittleGirl_5

FirwealdCity_EventScript_LittleGirl_10:
	applymovement 3, FirwealdCity_Movement_LassWalkHomeFacingSouth
	applymovement 2, FirwealdCity_Movement_LittleGirlWalkHomeFacingSouth
	waitmovement 0
	goto FirwealdCity_EventScript_LittleGirl_9


FirwealdCity_EventScript_OldWoman::
	compare VAR_FIRWEALD_CITY_STATE, 1
	goto_if_ge FirwealdCity_EventScript_OldWoman_1
	goto_if_set FLAG_BADGE01_GET, FirwealdCity_EventScript_OldWoman_2
	msgbox FirwealdCity_EventScript_OldWoman_Text_0, MSGBOX_NPC
	end

FirwealdCity_EventScript_OldWoman_1:
	msgbox FirwealdCity_EventScript_OldWoman_Text_0, MSGBOX_NPC
	end

FirwealdCity_EventScript_OldWoman_2:
	msgbox FirwealdCity_EventScript_OldWoman_Text_1, MSGBOX_NPC
	applymovement 1, FirwealdCity_Movement_OldWomanWalkToLeft
	waitmovement 0
	setobjectxyperm 1, 36, 10
	setvar VAR_FIRWEALD_CITY_STATE, 1
	end


EventScript_ClosedFirwealdDoor::
	msgbox FirwealdCity_Text_DoorIsClosed, MSGBOX_SIGN
	end


FirwealdCity_Movement_WalkInFrontOfPlayer:
	walk_right
	walk_down
	face_left
	step_end

FirwealdCity_Movement_PushBackPlayer:
	walk_left
	delay_16
	walk_up
	step_end

FirwealdCity_Movement_WalkBack:
	lock_facing_direction
	jump_left
	step_end

FirwealdCity_Movement_WalkAroundPlayerToPokeMart:
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

FirwealdCity_Movement_WalkToPokeMart:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

FirwealdCity_Movement_NoticeLittleGirlHidingSpot:
	emote_exclamation_mark
	delay_16
	delay_16
	lock_facing_direction
	jump_in_place_down
	jump_in_place_down
	step_end

FirwealdCity_Movement_LassWalkToLittleGirlFacingSouth:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_left
	step_end

FirwealdCity_Movement_LassWalkToLittleGirlFacingEastAndWest:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_down
	step_end

FirwealdCity_Movement_LassWalkHomeFacingEastAndWest:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FirwealdCity_Movement_LittleGirlWalkHomeFacingEastAndWest:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FirwealdCity_Movement_LassWalkHomeFacingSouth:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FirwealdCity_Movement_LittleGirlWalkHomeFacingSouth:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FirwealdCity_Movement_PlayerWalkDownBackwards:
	lock_facing_direction
	walk_down
	step_end

FirwealdCity_Movement_PhyllosWalkToForest:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FirwealdCity_Movement_OldWomanWalkToLeft:
	walk_slow_left
	face_down
	step_end

FirwealdCity_EventScript_ParkSign_Text_0:
	.string "FIRWEALD PARK$"

FirwealdCity_EventScript_CitySign_Text_0:
	.string "FIRWEALD CITY\n"
	.string "“Water and earth in harmony.”$"

FirwealdCity_EventScript_CaveSign_Text_0:
	.string "FOREST TUNNEL$"

FirwealdCity_EventScript_TournamentHallSign_Text_0:
	.string "FIRWEALD CITY TOURNAMENT HALL.\p"
	.string "Challenge PHYLLOS, the protector\n"
	.string "of ACREN FOREST.$"

FirwealdCity_EventScript_PhyllosEncounter_Text_0:
	.string "I've been expecting you {PLAYER}…\p"
	.string "… … … … … … … … …\p"
	.string "You ask how?\n"
	.string "Let's just say the trees…\l"
	.string "They carry my eyes,\l"
	.string "ears and voice.\p"
	.string "Me?\n"
	.string "My name is PHYLLOS, SHRINE KEEPER\l"
	.string "and FIRWEALD CITY's\l"
	.string " TOURNAMENT MASTER.\p"
	.string "They need help in the forest, yes?\p"
	.string "Well then let's not waste a moment\n"
	.string "and get going.\p"
	.string "Meet me in the forest, kid.$"

FirwealdCity_EventScript_Maniac_Text_0:
	.string "Don't bother me please.\n"
	.string "Something is happening in this tree,\l"
	.string "and I want to know what.$"

FirwealdCity_EventScript_Maniac_Text_1:
	.string "As it turned out…\p"
	.string "Nothing ever happened in that tree…\p"
	.string "I'm sorry for blocking your path…$"

FirwealdCity_EventScript_BlockPath_Text_0:
	.string "Hmmmm…\n"
	.string "That glint in your eyes…\p"
	.string "I'm sure you have some business\n"
	.string "to do here in FIRWEALD CITY.\p"
	.string "Fufufu… Fufufu…\p"
	.string "Go do your thing while I inspect this\n"
	.string "tree right here.$"

FirwealdCity_EventScript_Fisherman_Text_0:
	.string "Oh man…\n"
	.string "The GOLDEEN still aren't biting…$"

FirwealdCity_EventScript_Fisherman_Text_1:
	.string "Hiya there!\n"
	.string "I've heard there are rare GOLDEEN\l"
	.string "in this small lake.$"

FirwealdCity_EventScript_Fisherman_Text_2:
	.string "Oh no!\n"
	.string "I forgot to buy fishing bait!\p"
	.string "What a foolish mistake…\p"
	.string "I'll be off to the POKéMART to\n"
	.string "buy some then.$"

FirwealdCity_EventScript_Triathlete_Text_0:
	.string "Huff puff puff\n"
	.string "I don't have time for talking.\p"
	.string "I must keep running!$"

FirwealdCity_EventScript_Boy_Text_0:
	.string "My big sister always plays hide and\n"
	.string "seek with my other sister…$"

FirwealdCity_EventScript_Lass_Text_0:
	.string "Where could she be?\p"
	.string "She's very good at hiding!$"

FirwealdCity_EventScript_Lass_Text_1:
	.string "My little sister and I are\n"
	.string "playing hide and seek, but\l"
	.string "I really can't find her…\p"
	.string "Do you want to help me out?$"

FirwealdCity_EventScript_Lass_Text_2:
	.string "Aww, that's too bad$"

FirwealdCity_EventScript_Lass_Text_3:
	.string "Great!\p"
	.string "She should be somewehere here\n"
	.string "in FIRWEALD PARK.$"

FirwealdCity_EventScript_LittleGirl_Text_0:
	.string "Are you helping my big sister?!\p"
	.string "You're such a meanie!$"

FirwealdCity_EventScript_LittleGirl_Text_1:
	.string "Hey, he found you!\p"
	.string "Let's go home now, grandpa is\n"
	.string "waiting for us.$"

FirwealdCity_EventScript_LittleGirl_Text_2:
	.string "Shhh, I'm hiding from my big\n"
	.string "sister.\p"
	.string "Don't tell her I'm here!$"

FirwealdCity_EventScript_OldWoman_Text_0:
	.string "… … … … … …$"

FirwealdCity_EventScript_OldWoman_Text_1:
	.string "… … … … … …\p"
	.string "I see…$"

FirwealdCity_Text_DoorIsClosed::
	.string "The door of the TOURNAMENT HALL\n"
	.string "seems to be closed.$"
