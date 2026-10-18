NavireTown_MapScripts::
# 13 "data/maps/NavireTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NavireTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

NavireTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 14 "data/maps/NavireTown/scripts.pory"
	call FishermanFerry_EventScript_UpdateFerryLocation
# 15 "data/maps/NavireTown/scripts.pory"
	setrespawn HEAL_LOCATION_NAVIRE_TOWN
# 16 "data/maps/NavireTown/scripts.pory"
	setflag FLAG_VISITED_NAVIRE_TOWN
	return


NavireTown_EventScript_Fisherman::
# 21 "data/maps/NavireTown/scripts.pory"
	lock
# 22 "data/maps/NavireTown/scripts.pory"
	faceplayer
# 23 "data/maps/NavireTown/scripts.pory"
	loadspeechtail FALSE, 2
# 24 "data/maps/NavireTown/scripts.pory"
	msgbox NavireTown_EventScript_Fisherman_Text_0, MSGBOX_YESNO
# 26 "data/maps/NavireTown/scripts.pory"
	switch VAR_RESULT
# 27 "data/maps/NavireTown/scripts.pory"
	case YES, NavireTown_EventScript_Fisherman_2
# 29 "data/maps/NavireTown/scripts.pory"
	case NO, NavireTown_EventScript_Fisherman_3
# 31 "data/maps/NavireTown/scripts.pory"
	case MULTI_B_PRESSED, NavireTown_EventScript_Fisherman_4
	return

NavireTown_EventScript_Fisherman_2:
# 28 "data/maps/NavireTown/scripts.pory"
	goto NavireTown_EventScript_ChooseLitor
	return

NavireTown_EventScript_Fisherman_3:
# 30 "data/maps/NavireTown/scripts.pory"
	goto NavireTown_EventScript_CancelFerrySelect
	return

NavireTown_EventScript_Fisherman_4:
# 32 "data/maps/NavireTown/scripts.pory"
	goto NavireTown_EventScript_CancelFerrySelect
	return


NavireTown_EventScript_ChooseLitor::
# 37 "data/maps/NavireTown/scripts.pory"
	msgbox NavireTown_EventScript_ChooseLitor_Text_0
# 39 "data/maps/NavireTown/scripts.pory"
	destroyspeechtail
# 40 "data/maps/NavireTown/scripts.pory"
	closemessage
# 41 "data/maps/NavireTown/scripts.pory"
	goto NavireTown_EventScript_SailToLitor
	return


NavireTown_EventScript_CancelFerrySelect::
# 45 "data/maps/NavireTown/scripts.pory"
	msgbox NavireTown_EventScript_CancelFerrySelect_Text_0
# 47 "data/maps/NavireTown/scripts.pory"
	destroyspeechtail
# 48 "data/maps/NavireTown/scripts.pory"
	closemessage
# 49 "data/maps/NavireTown/scripts.pory"
	release
	end


NavireTown_EventScript_SailToLitor::
# 54 "data/maps/NavireTown/scripts.pory"
	call FishermanFerry_EventScript_BackupFerryLocation
# 55 "data/maps/NavireTown/scripts.pory"
	hideobjectat 1, MAP_LITOR_TOWN
# 56 "data/maps/NavireTown/scripts.pory"
	setobjectsubpriority 2, MAP_NAVIRE_TOWN, 0
# 57 "data/maps/NavireTown/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_NAVIRE_TOWN, 0
# 58 "data/maps/NavireTown/scripts.pory"
	applymovement 2, Common_Movement_WalkLeft
# 59 "data/maps/NavireTown/scripts.pory"
	waitmovement 0
# 60 "data/maps/NavireTown/scripts.pory"
	removeobject 2
# 61 "data/maps/NavireTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NavireTown_Movement_PlayerBoardBoat
# 62 "data/maps/NavireTown/scripts.pory"
	waitmovement 0
# 63 "data/maps/NavireTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_NAVIRE_TOWN
# 64 "data/maps/NavireTown/scripts.pory"
	applymovement 1, Common_Movement_FaceUp
# 65 "data/maps/NavireTown/scripts.pory"
	waitmovement 0
# 66 "data/maps/NavireTown/scripts.pory"
	delay 30
# 67 "data/maps/NavireTown/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 68 "data/maps/NavireTown/scripts.pory"
	playbgm MUS_SAILING, FALSE
# 69 "data/maps/NavireTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NavireTown_Movement_SailToLitor
# 70 "data/maps/NavireTown/scripts.pory"
	applymovement 1, NavireTown_Movement_SailToLitor
# 71 "data/maps/NavireTown/scripts.pory"
	waitmovement 0
# 72 "data/maps/NavireTown/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 73 "data/maps/NavireTown/scripts.pory"
	fadedefaultbgm
# 74 "data/maps/NavireTown/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
# 75 "data/maps/NavireTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NavireTown_Movement_PlayerExitBoat
# 76 "data/maps/NavireTown/scripts.pory"
	waitmovement 0
# 77 "data/maps/NavireTown/scripts.pory"
	clearflag FLAG_HIDE_LITOR_TOWN_FISHERMAN
# 78 "data/maps/NavireTown/scripts.pory"
	setobjectxyperm 2, 34, 22
# 79 "data/maps/NavireTown/scripts.pory"
	addobject 2
# 80 "data/maps/NavireTown/scripts.pory"
	setobjectsubpriority 2, MAP_LITOR_TOWN, 0
# 81 "data/maps/NavireTown/scripts.pory"
	applymovement 2, Common_Movement_WalkLeft
# 82 "data/maps/NavireTown/scripts.pory"
	waitmovement 0
# 83 "data/maps/NavireTown/scripts.pory"
	clearflag FLAG_HIDE_LITOR_TOWN_FISHERMAN
# 84 "data/maps/NavireTown/scripts.pory"
	addobject 1
# 85 "data/maps/NavireTown/scripts.pory"
	setobjectsubpriority 1, MAP_LITOR_TOWN, 1
# 86 "data/maps/NavireTown/scripts.pory"
	clearflag FLAG_HIDE_LITOR_TOWN_BOAT
# 87 "data/maps/NavireTown/scripts.pory"
	setflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
# 88 "data/maps/NavireTown/scripts.pory"
	setflag FLAG_HIDE_MURENA_CITY_BOAT
# 89 "data/maps/NavireTown/scripts.pory"
	setflag FLAG_HIDE_NAVIRE_TOWN_BOAT
# 90 "data/maps/NavireTown/scripts.pory"
	hideobjectat 10, MAP_MURENA_CITY
# 91 "data/maps/NavireTown/scripts.pory"
	hideobjectat 1, MAP_MURENA_CITY_SHIPYARD
# 92 "data/maps/NavireTown/scripts.pory"
	hideobjectat 1, MAP_NAVIRE_TOWN
# 93 "data/maps/NavireTown/scripts.pory"
	loadspeechtail FALSE, 2
# 94 "data/maps/NavireTown/scripts.pory"
	msgbox NavireTown_EventScript_SailToLitor_Text_0
# 96 "data/maps/NavireTown/scripts.pory"
	destroyspeechtail
# 97 "data/maps/NavireTown/scripts.pory"
	closemessage
# 98 "data/maps/NavireTown/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
# 99 "data/maps/NavireTown/scripts.pory"
	resetobjectsubpriority 2, MAP_LITOR_TOWN
# 100 "data/maps/NavireTown/scripts.pory"
	copyobjectxytoperm 2
# 101 "data/maps/NavireTown/scripts.pory"
	call FishermanFerry_EventScript_RestoreFerryLocation
# 102 "data/maps/NavireTown/scripts.pory"
	release
	end


NavireTown_EventScript_Fisherman2::
# 107 "data/maps/NavireTown/scripts.pory"
	msgbox NavireTown_EventScript_Fisherman2_Text_0, MSGBOX_NPC
	end


NavireTown_EventScript_Fisherman3::
# 114 "data/maps/NavireTown/scripts.pory"
	msgbox NavireTown_EventScript_Fisherman3_Text_0, MSGBOX_NPC
	end


NavireTown_EventScript_Boy::
# 123 "data/maps/NavireTown/scripts.pory"
	msgbox NavireTown_EventScript_Boy_Text_0, MSGBOX_NPC
	end


NavireTown_EventScript_ItemNugget::
# 132 "data/maps/NavireTown/scripts.pory"
	finditem ITEM_NUGGET
	end


NavireTown_EventScript_FishingClubSign::
# 137 "data/maps/NavireTown/scripts.pory"
	msgbox NavireTown_EventScript_FishingClubSign_Text_0, MSGBOX_SIGN
	end


NavireTown_EventScript_TownSign::
# 142 "data/maps/NavireTown/scripts.pory"
	msgbox NavireTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


# 147 "data/maps/NavireTown/scripts.pory"
NavireTown_Movement_PlayerBoardBoat:
# 148 "data/maps/NavireTown/scripts.pory"
	walk_left
# 148 "data/maps/NavireTown/scripts.pory"
	walk_left
	step_end

# 151 "data/maps/NavireTown/scripts.pory"
NavireTown_Movement_SailToLitor:
# 152 "data/maps/NavireTown/scripts.pory"
	walk_up
# 152 "data/maps/NavireTown/scripts.pory"
	walk_up
# 152 "data/maps/NavireTown/scripts.pory"
	walk_up
# 152 "data/maps/NavireTown/scripts.pory"
	walk_up
# 152 "data/maps/NavireTown/scripts.pory"
	walk_up
# 152 "data/maps/NavireTown/scripts.pory"
	walk_up
# 153 "data/maps/NavireTown/scripts.pory"
	walk_right
# 154 "data/maps/NavireTown/scripts.pory"
	walk_up
# 155 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 155 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 156 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 156 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 156 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 156 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 156 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 156 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 157 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 157 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 158 "data/maps/NavireTown/scripts.pory"
	walk_up
# 159 "data/maps/NavireTown/scripts.pory"
	walk_left
# 160 "data/maps/NavireTown/scripts.pory"
	walk_fast_left
# 160 "data/maps/NavireTown/scripts.pory"
	walk_fast_left
# 161 "data/maps/NavireTown/scripts.pory"
	walk_faster_left
# 162 "data/maps/NavireTown/scripts.pory"
	walk_fast_left
# 162 "data/maps/NavireTown/scripts.pory"
	walk_fast_left
# 163 "data/maps/NavireTown/scripts.pory"
	walk_left
# 164 "data/maps/NavireTown/scripts.pory"
	walk_up
# 165 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 165 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 166 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 166 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 166 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 166 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 167 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 167 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 168 "data/maps/NavireTown/scripts.pory"
	walk_up
# 169 "data/maps/NavireTown/scripts.pory"
	walk_right
# 169 "data/maps/NavireTown/scripts.pory"
	walk_right
# 170 "data/maps/NavireTown/scripts.pory"
	walk_up
# 171 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 171 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 172 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 172 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 172 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 172 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 172 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 172 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 172 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 172 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 172 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 173 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 173 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 174 "data/maps/NavireTown/scripts.pory"
	walk_up
# 175 "data/maps/NavireTown/scripts.pory"
	walk_left
# 176 "data/maps/NavireTown/scripts.pory"
	walk_fast_left
# 176 "data/maps/NavireTown/scripts.pory"
	walk_fast_left
# 176 "data/maps/NavireTown/scripts.pory"
	walk_fast_left
# 177 "data/maps/NavireTown/scripts.pory"
	walk_left
# 178 "data/maps/NavireTown/scripts.pory"
	walk_up
# 179 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 179 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 180 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 180 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 180 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 180 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 180 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 180 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 181 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 181 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 182 "data/maps/NavireTown/scripts.pory"
	walk_up
# 183 "data/maps/NavireTown/scripts.pory"
	walk_right
# 183 "data/maps/NavireTown/scripts.pory"
	walk_right
# 184 "data/maps/NavireTown/scripts.pory"
	walk_up
# 185 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 185 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 186 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 186 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 186 "data/maps/NavireTown/scripts.pory"
	walk_faster_up
# 187 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 187 "data/maps/NavireTown/scripts.pory"
	walk_fast_up
# 188 "data/maps/NavireTown/scripts.pory"
	walk_up
	step_end

# 191 "data/maps/NavireTown/scripts.pory"
NavireTown_Movement_PlayerExitBoat:
# 192 "data/maps/NavireTown/scripts.pory"
	walk_left
# 192 "data/maps/NavireTown/scripts.pory"
	walk_left
# 193 "data/maps/NavireTown/scripts.pory"
	face_right
	step_end

NavireTown_EventScript_Fisherman_Text_0:
# 24 "data/maps/NavireTown/scripts.pory"
	.string "You need a trip to LITOR?\n"
	.string "I'm always here.$"

NavireTown_EventScript_ChooseLitor_Text_0:
# 37 "data/maps/NavireTown/scripts.pory"
	.string "We're headed to LITOR TOWN!\n"
	.string "Let's set sail!$"

NavireTown_EventScript_CancelFerrySelect_Text_0:
# 45 "data/maps/NavireTown/scripts.pory"
	.string "Tell me whenever you need me\n"
	.string "and my trusty boat.$"

NavireTown_EventScript_SailToLitor_Text_0:
# 94 "data/maps/NavireTown/scripts.pory"
	.string "Ahoy! We've arrived at LITOR TOWN!\n"
	.string "Don't get sunburnt alright.$"

NavireTown_EventScript_Fisherman2_Text_0:
# 107 "data/maps/NavireTown/scripts.pory"
	.string "Any luck with fishing?\p"
	.string "You gotta be patient, or they won't\n"
	.string "bite…$"

NavireTown_EventScript_Fisherman3_Text_0:
# 114 "data/maps/NavireTown/scripts.pory"
	.string "If you go left here you enter the\n"
	.string "EURUS MOUNTAINS, namesake of the\l"
	.string "EURUS REGION.\p"
	.string "Personally I'm not a fan, I'm not\n"
	.string "not big on cold!$"

NavireTown_EventScript_Boy_Text_0:
# 123 "data/maps/NavireTown/scripts.pory"
	.string "My dad works in shipping!\p"
	.string "All the raw materials from ACREN FOREST\n"
	.string "are sent towards the mainland through\l"
	.string "the port of MURENA CITY.\p"
	.string "Boats are so cool!$"

NavireTown_EventScript_FishingClubSign_Text_0:
# 137 "data/maps/NavireTown/scripts.pory"
	.string "NAVIRE TOWN FISHING CLUB$"

NavireTown_EventScript_TownSign_Text_0:
# 142 "data/maps/NavireTown/scripts.pory"
	.string "NAVIRE TOWN\n"
	.string "“Sea crashing back on the mainland.”$"
