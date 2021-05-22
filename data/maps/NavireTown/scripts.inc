NavireTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavireTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

NavireTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call FishermanFerry_EventScript_UpdateFerryLocation
	setrespawn HEAL_LOCATION_NAVIRE_TOWN
	setflag FLAG_VISITED_NAVIRE_TOWN
	return


NavireTown_EventScript_Fisherman::
	lock
	faceplayer
	load_speech_bubble 2
	msgbox NavireTown_EventScript_Fisherman_Text_0, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, NavireTown_EventScript_Fisherman_2
	case NO, NavireTown_EventScript_Fisherman_3
	case MULTI_B_PRESSED, NavireTown_EventScript_Fisherman_4
	return

NavireTown_EventScript_Fisherman_2:
	goto NavireTown_EventScript_ChooseLitor
	return

NavireTown_EventScript_Fisherman_3:
	goto NavireTown_EventScript_CancelFerrySelect
	return

NavireTown_EventScript_Fisherman_4:
	goto NavireTown_EventScript_CancelFerrySelect
	return


NavireTown_EventScript_ChooseLitor::
	msgbox NavireTown_EventScript_ChooseLitor_Text_0
	destroy_speech_bubble
	closemessage
	goto NavireTown_EventScript_SailToLitor
	return


NavireTown_EventScript_CancelFerrySelect::
	msgbox NavireTown_EventScript_CancelFerrySelect_Text_0
	destroy_speech_bubble
	closemessage
	release
	end


NavireTown_EventScript_SailToLitor::
	call FishermanFerry_EventScript_BackupFerryLocation
	hideobjectat 1, MAP_LITOR_TOWN
	setobjectpriority 2, MAP_NAVIRE_TOWN, 0
	setobjectpriority OBJ_EVENT_ID_PLAYER, MAP_NAVIRE_TOWN, 0
	applymovement 2, Common_Movement_WalkLeft
	waitmovement 0
	removeobject 2
	applymovement OBJ_EVENT_ID_PLAYER, NavireTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_NAVIRE_TOWN
	applymovement 1, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_SAILING, 0
	applymovement OBJ_EVENT_ID_PLAYER, NavireTown_Movement_SailToLitor
	applymovement 1, NavireTown_Movement_SailToLitor
	waitmovement 0
	clearflag FLAG_DONT_TRANSITION_MUSIC
	fadedefaultbgm
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, NavireTown_Movement_PlayerExitBoat
	waitmovement 0
	clearflag FLAG_HIDE_LITOR_TOWN_FISHERMAN
	setobjectxyperm 2, 34, 22
	addobject 2
	setobjectpriority 2, MAP_LITOR_TOWN, 0
	applymovement 2, Common_Movement_WalkLeft
	waitmovement 0
	clearflag FLAG_HIDE_LITOR_TOWN_FISHERMAN
	addobject 1
	setobjectpriority 1, MAP_LITOR_TOWN, 1
	clearflag FLAG_HIDE_LITOR_TOWN_BOAT
	setflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
	setflag FLAG_HIDE_MURENA_CITY_BOAT
	setflag FLAG_HIDE_NAVIRE_TOWN_BOAT
	hideobjectat 10, MAP_MURENA_CITY
	hideobjectat 1, MAP_MURENA_CITY_SHIPYARD
	hideobjectat 1, MAP_NAVIRE_TOWN
	load_speech_bubble 2
	msgbox NavireTown_EventScript_SailToLitor_Text_0
	destroy_speech_bubble
	closemessage
	resetobjectpriority OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
	resetobjectpriority 2, MAP_LITOR_TOWN
	copyobjectxytoperm 2
	call FishermanFerry_EventScript_RestoreFerryLocation
	release
	end


NavireTown_EventScript_Fisherman2::
	msgbox NavireTown_EventScript_Fisherman2_Text_0, MSGBOX_NPC
	end


NavireTown_EventScript_Fisherman3::
	msgbox NavireTown_EventScript_Fisherman3_Text_0, MSGBOX_NPC
	end


NavireTown_EventScript_Boy::
	msgbox NavireTown_EventScript_Boy_Text_0, MSGBOX_NPC
	end


NavireTown_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end


NavireTown_EventScript_FishingClubSign::
	msgbox NavireTown_EventScript_FishingClubSign_Text_0, MSGBOX_SIGN
	end


NavireTown_EventScript_TownSign::
	msgbox NavireTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


NavireTown_Movement_PlayerBoardBoat:
	walk_left
	walk_left
	step_end

NavireTown_Movement_SailToLitor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fastest_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_up
	step_end

NavireTown_Movement_PlayerExitBoat:
	walk_left
	walk_left
	face_right
	step_end

NavireTown_EventScript_Fisherman_Text_0:
	.string "You need a trip to LITOR?\n"
	.string "I'm always here.$"

NavireTown_EventScript_ChooseLitor_Text_0:
	.string "We're headed to LITOR TOWN!\n"
	.string "Let's set sail!$"

NavireTown_EventScript_CancelFerrySelect_Text_0:
	.string "Tell me whenever you need me\n"
	.string "and my trusty boat.$"

NavireTown_EventScript_SailToLitor_Text_0:
	.string "Ahoy! We've arrived at LITOR TOWN!\n"
	.string "Don't get sunburnt alright.$"

NavireTown_EventScript_Fisherman2_Text_0:
	.string "Any luck with fishing?\p"
	.string "You gotta be patient, or they won't\n"
	.string "bite…$"

NavireTown_EventScript_Fisherman3_Text_0:
	.string "If you go left here you enter the\n"
	.string "EURUS MOUNTAINS, namesake of the\l"
	.string "EURUS REGION.\p"
	.string "Personally I'm not a fan, I'm not\n"
	.string "not big on cold!$"

NavireTown_EventScript_Boy_Text_0:
	.string "My dad works in shipping!\p"
	.string "All the raw materials from ACREN FOREST\n"
	.string "are sent towards the mainland through\l"
	.string "the port of MURENA CITY.\p"
	.string "Boats are so cool!$"

NavireTown_EventScript_FishingClubSign_Text_0:
	.string "NAVIRE TOWN FISHING CLUB$"

NavireTown_EventScript_TownSign_Text_0:
	.string "NAVIRE TOWN\n"
	.string "“Sea crashing back on the mainland.”$"
