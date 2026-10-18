LitorTown_MapScripts::
# 16 "data/maps/LitorTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LitorTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

LitorTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 17 "data/maps/LitorTown/scripts.pory"
	call FishermanFerry_EventScript_UpdateFerryLocation
# 18 "data/maps/LitorTown/scripts.pory"
	setrespawn HEAL_LOCATION_LITOR_TOWN
# 19 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_VISITED_LITOR_TOWN
	return


LitorTown_EventScript_Fisherman::
# 24 "data/maps/LitorTown/scripts.pory"
	lock
# 25 "data/maps/LitorTown/scripts.pory"
	faceplayer
# 26 "data/maps/LitorTown/scripts.pory"
	goto_if_unset FLAG_MET_SCOTT_ON_LITOR, LitorTown_EventScript_Fisherman_2
# 26 "data/maps/LitorTown/scripts.pory"
	goto_if_unset FLAG_MET_JULIA_ON_LITOR, LitorTown_EventScript_Fisherman_2
LitorTown_EventScript_Fisherman_1:
# 38 "data/maps/LitorTown/scripts.pory"
	loadspeechtail FALSE, 2
# 39 "data/maps/LitorTown/scripts.pory"
	message LitorTown_Text_WhereAreWeHeaded
# 40 "data/maps/LitorTown/scripts.pory"
	waitmessage
# 41 "data/maps/LitorTown/scripts.pory"
	multichoicedefault 21, 6, MULTI_FERRY_ON_LITOR, 1, 0
# 42 "data/maps/LitorTown/scripts.pory"
	switch VAR_RESULT
# 43 "data/maps/LitorTown/scripts.pory"
	case 0, LitorTown_EventScript_Fisherman_7
# 45 "data/maps/LitorTown/scripts.pory"
	case 1, LitorTown_EventScript_Fisherman_8
# 47 "data/maps/LitorTown/scripts.pory"
	case 2, LitorTown_EventScript_Fisherman_9
# 49 "data/maps/LitorTown/scripts.pory"
	case MULTI_B_PRESSED, LitorTown_EventScript_Fisherman_10
	return

LitorTown_EventScript_Fisherman_2:
# 27 "data/maps/LitorTown/scripts.pory"
	loadspeechtail FALSE, 2
# 28 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Fisherman_Text_0, MSGBOX_YESNO
# 29 "data/maps/LitorTown/scripts.pory"
	switch VAR_RESULT
# 30 "data/maps/LitorTown/scripts.pory"
	case YES, LitorTown_EventScript_Fisherman_12
# 32 "data/maps/LitorTown/scripts.pory"
	case NO, LitorTown_EventScript_Fisherman_13
# 34 "data/maps/LitorTown/scripts.pory"
	case MULTI_B_PRESSED, LitorTown_EventScript_Fisherman_14
	goto LitorTown_EventScript_Fisherman_1

LitorTown_EventScript_Fisherman_7:
# 44 "data/maps/LitorTown/scripts.pory"
	goto LitorTown_EventScript_ChooseMurena
	return

LitorTown_EventScript_Fisherman_8:
# 46 "data/maps/LitorTown/scripts.pory"
	goto LitorTown_EventScript_ChooseNavire
	return

LitorTown_EventScript_Fisherman_9:
# 48 "data/maps/LitorTown/scripts.pory"
	goto LitorTown_EventScript_CancelFerrySelect
	return

LitorTown_EventScript_Fisherman_10:
# 50 "data/maps/LitorTown/scripts.pory"
	goto LitorTown_EventScript_CancelFerrySelect
	return

LitorTown_EventScript_Fisherman_12:
# 31 "data/maps/LitorTown/scripts.pory"
	goto LitorTown_EventScript_ChooseMurena
	goto LitorTown_EventScript_Fisherman_1

LitorTown_EventScript_Fisherman_13:
# 33 "data/maps/LitorTown/scripts.pory"
	goto LitorTown_EventScript_CancelFerrySelect
	goto LitorTown_EventScript_Fisherman_1

LitorTown_EventScript_Fisherman_14:
# 35 "data/maps/LitorTown/scripts.pory"
	goto LitorTown_EventScript_CancelFerrySelect
	goto LitorTown_EventScript_Fisherman_1


LitorTown_EventScript_ChooseMurena::
# 57 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_ChooseMurena_Text_0
# 59 "data/maps/LitorTown/scripts.pory"
	destroyspeechtail
# 60 "data/maps/LitorTown/scripts.pory"
	closemessage
# 61 "data/maps/LitorTown/scripts.pory"
	goto LitorTown_EventScript_SailToMurena
	return


LitorTown_EventScript_ChooseNavire::
# 65 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_ChooseNavire_Text_0
# 67 "data/maps/LitorTown/scripts.pory"
	destroyspeechtail
# 68 "data/maps/LitorTown/scripts.pory"
	closemessage
# 69 "data/maps/LitorTown/scripts.pory"
	goto LitorTown_EventScript_SailToNavire
	return


LitorTown_EventScript_CancelFerrySelect::
# 73 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_CancelFerrySelect_Text_0
# 75 "data/maps/LitorTown/scripts.pory"
	destroyspeechtail
# 76 "data/maps/LitorTown/scripts.pory"
	closemessage
# 77 "data/maps/LitorTown/scripts.pory"
	release
	end


LitorTown_EventScript_SailToMurena::
# 82 "data/maps/LitorTown/scripts.pory"
	call FishermanFerry_EventScript_BackupFerryLocation
# 83 "data/maps/LitorTown/scripts.pory"
	hideobjectat 10, MAP_MURENA_CITY
# 84 "data/maps/LitorTown/scripts.pory"
	setobjectsubpriority 2, MAP_LITOR_TOWN, 0
# 85 "data/maps/LitorTown/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN, 0
# 86 "data/maps/LitorTown/scripts.pory"
	applymovement 2, Common_Movement_WalkRight
# 87 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
# 88 "data/maps/LitorTown/scripts.pory"
	removeobject 2
# 89 "data/maps/LitorTown/scripts.pory"
	switch VAR_FACING
# 90 "data/maps/LitorTown/scripts.pory"
	case DIR_NORTH, LitorTown_EventScript_SailToMurena_3
# 94 "data/maps/LitorTown/scripts.pory"
	case DIR_EAST, LitorTown_EventScript_SailToMurena_4
# 98 "data/maps/LitorTown/scripts.pory"
	case DIR_SOUTH, LitorTown_EventScript_SailToMurena_5
LitorTown_EventScript_SailToMurena_1:
# 103 "data/maps/LitorTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
# 104 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 105 "data/maps/LitorTown/scripts.pory"
	playbgm MUS_SAILING, FALSE
# 106 "data/maps/LitorTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_SailToMurena
# 107 "data/maps/LitorTown/scripts.pory"
	applymovement 1, LitorTown_Movement_SailToMurena
# 108 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
# 109 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_HIDE_LITOR_TOWN_BOAT
# 110 "data/maps/LitorTown/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 111 "data/maps/LitorTown/scripts.pory"
	fadedefaultbgm
# 112 "data/maps/LitorTown/scripts.pory"
	setvar VAR_FISHERMAN_FERRY_STATE, 3
# 113 "data/maps/LitorTown/scripts.pory"
	warpsilent MAP_MURENA_CITY_SHIPYARD, 0xFF, 8, 6
# 114 "data/maps/LitorTown/scripts.pory"
	waitstate
	end

LitorTown_EventScript_SailToMurena_3:
# 91 "data/maps/LitorTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatNorth
# 92 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
	goto LitorTown_EventScript_SailToMurena_1

LitorTown_EventScript_SailToMurena_4:
# 95 "data/maps/LitorTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatEast
# 96 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
	goto LitorTown_EventScript_SailToMurena_1

LitorTown_EventScript_SailToMurena_5:
# 99 "data/maps/LitorTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatSouth
# 100 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
	goto LitorTown_EventScript_SailToMurena_1


LitorTown_EventScript_SailToNavire::
# 119 "data/maps/LitorTown/scripts.pory"
	call FishermanFerry_EventScript_BackupFerryLocation
# 120 "data/maps/LitorTown/scripts.pory"
	hideobjectat 1, MAP_NAVIRE_TOWN
# 121 "data/maps/LitorTown/scripts.pory"
	setobjectsubpriority 2, MAP_LITOR_TOWN, 0
# 122 "data/maps/LitorTown/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN, 0
# 123 "data/maps/LitorTown/scripts.pory"
	applymovement 2, Common_Movement_WalkRight
# 124 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
# 125 "data/maps/LitorTown/scripts.pory"
	removeobject 2
# 126 "data/maps/LitorTown/scripts.pory"
	switch VAR_FACING
# 127 "data/maps/LitorTown/scripts.pory"
	case DIR_NORTH, LitorTown_EventScript_SailToNavire_3
# 131 "data/maps/LitorTown/scripts.pory"
	case DIR_EAST, LitorTown_EventScript_SailToNavire_4
# 135 "data/maps/LitorTown/scripts.pory"
	case DIR_SOUTH, LitorTown_EventScript_SailToNavire_5
LitorTown_EventScript_SailToNavire_1:
# 140 "data/maps/LitorTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
# 141 "data/maps/LitorTown/scripts.pory"
	delay 30
# 142 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 143 "data/maps/LitorTown/scripts.pory"
	playbgm MUS_SAILING, FALSE
# 144 "data/maps/LitorTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_SailToNavire
# 145 "data/maps/LitorTown/scripts.pory"
	applymovement 1, LitorTown_Movement_SailToNavire
# 146 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
# 147 "data/maps/LitorTown/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 148 "data/maps/LitorTown/scripts.pory"
	fadedefaultbgm
# 149 "data/maps/LitorTown/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_NAVIRE_TOWN
# 150 "data/maps/LitorTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerExitBoat
# 151 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
# 152 "data/maps/LitorTown/scripts.pory"
	clearflag FLAG_HIDE_NAVIRE_TOWN_FISHERMAN
# 153 "data/maps/LitorTown/scripts.pory"
	setobjectxyperm 2, 8, 9
# 154 "data/maps/LitorTown/scripts.pory"
	addobject 2
# 155 "data/maps/LitorTown/scripts.pory"
	setobjectsubpriority 2, MAP_NAVIRE_TOWN, 0
# 156 "data/maps/LitorTown/scripts.pory"
	applymovement 2, LitorTown_Movement_FishermanExitBoat
# 157 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
# 158 "data/maps/LitorTown/scripts.pory"
	clearflag FLAG_HIDE_NAVIRE_TOWN_FISHERMAN
# 159 "data/maps/LitorTown/scripts.pory"
	addobject 1
# 160 "data/maps/LitorTown/scripts.pory"
	setobjectsubpriority 1, MAP_NAVIRE_TOWN, 1
# 161 "data/maps/LitorTown/scripts.pory"
	clearflag FLAG_HIDE_NAVIRE_TOWN_BOAT
# 162 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
# 163 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_HIDE_MURENA_CITY_BOAT
# 164 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_HIDE_LITOR_TOWN_BOAT
# 165 "data/maps/LitorTown/scripts.pory"
	hideobjectat 10, MAP_MURENA_CITY
# 166 "data/maps/LitorTown/scripts.pory"
	hideobjectat 1, MAP_MURENA_CITY_SHIPYARD
# 167 "data/maps/LitorTown/scripts.pory"
	hideobjectat 1, MAP_LITOR_TOWN
# 168 "data/maps/LitorTown/scripts.pory"
	loadspeechtail FALSE, 2
# 169 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_SailToNavire_Text_0
# 171 "data/maps/LitorTown/scripts.pory"
	destroyspeechtail
# 172 "data/maps/LitorTown/scripts.pory"
	closemessage
# 173 "data/maps/LitorTown/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_NAVIRE_TOWN
# 174 "data/maps/LitorTown/scripts.pory"
	resetobjectsubpriority 2, MAP_NAVIRE_TOWN
# 175 "data/maps/LitorTown/scripts.pory"
	copyobjectxytoperm 2
# 176 "data/maps/LitorTown/scripts.pory"
	call FishermanFerry_EventScript_RestoreFerryLocation
# 177 "data/maps/LitorTown/scripts.pory"
	release
	end

LitorTown_EventScript_SailToNavire_3:
# 128 "data/maps/LitorTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatNorth
# 129 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
	goto LitorTown_EventScript_SailToNavire_1

LitorTown_EventScript_SailToNavire_4:
# 132 "data/maps/LitorTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatEast
# 133 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
	goto LitorTown_EventScript_SailToNavire_1

LitorTown_EventScript_SailToNavire_5:
# 136 "data/maps/LitorTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatSouth
# 137 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
	goto LitorTown_EventScript_SailToNavire_1


LitorTown_EventScript_Scott::
# 182 "data/maps/LitorTown/scripts.pory"
	lock
# 183 "data/maps/LitorTown/scripts.pory"
	faceplayer
# 184 "data/maps/LitorTown/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_ON_LITOR, LitorTown_EventScript_Scott_1
# 194 "data/maps/LitorTown/scripts.pory"
	loadspeechtail FALSE, 7
# 195 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Scott_Text_1
# 200 "data/maps/LitorTown/scripts.pory"
	destroyspeechtail
# 201 "data/maps/LitorTown/scripts.pory"
	closemessage
# 202 "data/maps/LitorTown/scripts.pory"
	playse SE_PIN
# 203 "data/maps/LitorTown/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 204 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
# 205 "data/maps/LitorTown/scripts.pory"
	loadspeechtail FALSE, 7
# 206 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Scott_Text_2
# 219 "data/maps/LitorTown/scripts.pory"
	destroyspeechtail
# 220 "data/maps/LitorTown/scripts.pory"
	closemessage
# 221 "data/maps/LitorTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 222 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_SYS_POKENAV_GET
# 223 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 224 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 225 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Scott_Text_3
# 227 "data/maps/LitorTown/scripts.pory"
	waitfanfare
# 228 "data/maps/LitorTown/scripts.pory"
	closemessage
# 229 "data/maps/LitorTown/scripts.pory"
	loadspeechtail FALSE, 7
# 230 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Scott_Text_4
# 239 "data/maps/LitorTown/scripts.pory"
	destroyspeechtail
# 240 "data/maps/LitorTown/scripts.pory"
	closemessage
# 241 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_MET_SCOTT_ON_LITOR
# 242 "data/maps/LitorTown/scripts.pory"
	release
	end

LitorTown_EventScript_Scott_1:
# 185 "data/maps/LitorTown/scripts.pory"
	loadspeechtail FALSE, 7
# 186 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Scott_Text_0
# 189 "data/maps/LitorTown/scripts.pory"
	destroyspeechtail
# 190 "data/maps/LitorTown/scripts.pory"
	closemessage
# 191 "data/maps/LitorTown/scripts.pory"
	release
	end


LitorTown_EventScript_JuliaEncounter::
# 249 "data/maps/LitorTown/scripts.pory"
	playse SE_EXIT
# 250 "data/maps/LitorTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 251 "data/maps/LitorTown/scripts.pory"
	addobject 13
# 252 "data/maps/LitorTown/scripts.pory"
	waitse
# 253 "data/maps/LitorTown/scripts.pory"
	applymovement 13, Common_Movement_WalkDown
# 254 "data/maps/LitorTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerWalkDown
# 255 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
# 256 "data/maps/LitorTown/scripts.pory"
	loadspeechtail FALSE, 13
# 257 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_JuliaEncounter_Text_0
# 266 "data/maps/LitorTown/scripts.pory"
	destroyspeechtail
# 267 "data/maps/LitorTown/scripts.pory"
	closemessage
# 268 "data/maps/LitorTown/scripts.pory"
	applymovement 13, Common_Movement_QuestionMark
# 269 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
# 270 "data/maps/LitorTown/scripts.pory"
	loadspeechtail FALSE, 13
# 271 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_JuliaEncounter_Text_1
# 276 "data/maps/LitorTown/scripts.pory"
	destroyspeechtail
# 277 "data/maps/LitorTown/scripts.pory"
	closemessage
# 278 "data/maps/LitorTown/scripts.pory"
	applymovement 13, LitorTown_Movement_JuliaWalkOffscreen
# 279 "data/maps/LitorTown/scripts.pory"
	waitmovement 0
# 280 "data/maps/LitorTown/scripts.pory"
	removeobject 13
# 281 "data/maps/LitorTown/scripts.pory"
	setflag FLAG_MET_JULIA_ON_LITOR
# 282 "data/maps/LitorTown/scripts.pory"
	setvar VAR_JULIA_STATE, 2
# 283 "data/maps/LitorTown/scripts.pory"
	release
	end


LitorTown_EventScript_TuberM::
# 288 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_TuberM_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_TuberMSwimmer::
# 293 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_TuberMSwimmer_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_TuberF1::
# 299 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_TuberF1_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_TuberF2::
# 305 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_TuberF2_Text_0, MSGBOX_NPC
# 307 "data/maps/LitorTown/scripts.pory"
	compare VAR_JULIA_STATE, 2
	goto_if_lt LitorTown_EventScript_TuberF2_2
LitorTown_EventScript_TuberF2_1:
	end

LitorTown_EventScript_TuberF2_2:
# 308 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_TuberF2_Text_1, MSGBOX_NPC
	goto LitorTown_EventScript_TuberF2_1


LitorTown_EventScript_Youngster::
# 316 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Youngster_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_Beauty::
# 322 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Beauty_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_Sailor::
# 328 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Sailor_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_Gentleman::
# 334 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Gentleman_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_Boy::
# 341 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_Boy_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_TownSign::
# 348 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


LitorTown_EventScript_BarSign::
# 354 "data/maps/LitorTown/scripts.pory"
	msgbox LitorTown_EventScript_BarSign_Text_0, MSGBOX_SIGN
	end


# 359 "data/maps/LitorTown/scripts.pory"
LitorTown_Movement_PlayerBoardBoatNorth:
# 360 "data/maps/LitorTown/scripts.pory"
	walk_up
# 361 "data/maps/LitorTown/scripts.pory"
	walk_right
	step_end

# 364 "data/maps/LitorTown/scripts.pory"
LitorTown_Movement_PlayerBoardBoatEast:
# 365 "data/maps/LitorTown/scripts.pory"
	walk_right
# 365 "data/maps/LitorTown/scripts.pory"
	walk_right
	step_end

# 368 "data/maps/LitorTown/scripts.pory"
LitorTown_Movement_PlayerBoardBoatSouth:
# 369 "data/maps/LitorTown/scripts.pory"
	walk_down
# 370 "data/maps/LitorTown/scripts.pory"
	walk_right
	step_end

# 373 "data/maps/LitorTown/scripts.pory"
LitorTown_Movement_SailToMurena:
# 374 "data/maps/LitorTown/scripts.pory"
	walk_down
# 375 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 375 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 376 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 376 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 377 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 377 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 378 "data/maps/LitorTown/scripts.pory"
	walk_down
# 379 "data/maps/LitorTown/scripts.pory"
	walk_left
# 380 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 380 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 381 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 381 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 381 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 381 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 381 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 381 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 381 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 382 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 382 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 383 "data/maps/LitorTown/scripts.pory"
	walk_left
# 384 "data/maps/LitorTown/scripts.pory"
	walk_down
# 385 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 386 "data/maps/LitorTown/scripts.pory"
	walk_down
# 387 "data/maps/LitorTown/scripts.pory"
	walk_left
# 388 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 388 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 389 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 389 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 389 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 389 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 389 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 389 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 389 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 389 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 389 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 389 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 390 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 390 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 391 "data/maps/LitorTown/scripts.pory"
	walk_left
# 392 "data/maps/LitorTown/scripts.pory"
	walk_up
# 393 "data/maps/LitorTown/scripts.pory"
	walk_fast_up
# 393 "data/maps/LitorTown/scripts.pory"
	walk_fast_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 394 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 395 "data/maps/LitorTown/scripts.pory"
	walk_fast_up
# 395 "data/maps/LitorTown/scripts.pory"
	walk_fast_up
# 396 "data/maps/LitorTown/scripts.pory"
	walk_up
# 397 "data/maps/LitorTown/scripts.pory"
	walk_left
# 398 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 398 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 399 "data/maps/LitorTown/scripts.pory"
	walk_left
# 400 "data/maps/LitorTown/scripts.pory"
	walk_up
# 401 "data/maps/LitorTown/scripts.pory"
	walk_fast_up
# 401 "data/maps/LitorTown/scripts.pory"
	walk_fast_up
# 402 "data/maps/LitorTown/scripts.pory"
	walk_up
# 403 "data/maps/LitorTown/scripts.pory"
	walk_left
# 404 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 404 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 405 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 406 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 406 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 407 "data/maps/LitorTown/scripts.pory"
	walk_left
# 408 "data/maps/LitorTown/scripts.pory"
	walk_down
# 409 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 409 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 409 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 409 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 410 "data/maps/LitorTown/scripts.pory"
	walk_down
# 411 "data/maps/LitorTown/scripts.pory"
	walk_left
# 412 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 412 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 413 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 413 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 413 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 413 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 413 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 413 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 413 "data/maps/LitorTown/scripts.pory"
	walk_faster_left
# 414 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 414 "data/maps/LitorTown/scripts.pory"
	walk_fast_left
# 415 "data/maps/LitorTown/scripts.pory"
	walk_left
# 416 "data/maps/LitorTown/scripts.pory"
	walk_up
# 417 "data/maps/LitorTown/scripts.pory"
	walk_fast_up
# 417 "data/maps/LitorTown/scripts.pory"
	walk_fast_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/LitorTown/scripts.pory"
	walk_faster_up
# 419 "data/maps/LitorTown/scripts.pory"
	walk_fast_up
# 419 "data/maps/LitorTown/scripts.pory"
	walk_fast_up
# 420 "data/maps/LitorTown/scripts.pory"
	walk_up
# 421 "data/maps/LitorTown/scripts.pory"
	walk_right
# 422 "data/maps/LitorTown/scripts.pory"
	walk_fast_right
# 422 "data/maps/LitorTown/scripts.pory"
	walk_fast_right
# 422 "data/maps/LitorTown/scripts.pory"
	walk_fast_right
# 423 "data/maps/LitorTown/scripts.pory"
	walk_right
	step_end

# 426 "data/maps/LitorTown/scripts.pory"
LitorTown_Movement_SailToNavire:
# 427 "data/maps/LitorTown/scripts.pory"
	walk_down
# 428 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 428 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 429 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 429 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 429 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 429 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 429 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 429 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 429 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 429 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 430 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 430 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 431 "data/maps/LitorTown/scripts.pory"
	walk_down
# 432 "data/maps/LitorTown/scripts.pory"
	walk_left
# 432 "data/maps/LitorTown/scripts.pory"
	walk_left
# 433 "data/maps/LitorTown/scripts.pory"
	walk_down
# 434 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 434 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 435 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 436 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 436 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 437 "data/maps/LitorTown/scripts.pory"
	walk_down
# 438 "data/maps/LitorTown/scripts.pory"
	walk_right
# 439 "data/maps/LitorTown/scripts.pory"
	walk_fast_right
# 439 "data/maps/LitorTown/scripts.pory"
	walk_fast_right
# 439 "data/maps/LitorTown/scripts.pory"
	walk_fast_right
# 440 "data/maps/LitorTown/scripts.pory"
	walk_right
# 441 "data/maps/LitorTown/scripts.pory"
	walk_down
# 442 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 442 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 443 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 443 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 443 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 443 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 443 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 443 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 443 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 443 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 443 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 444 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 444 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 445 "data/maps/LitorTown/scripts.pory"
	walk_down
# 446 "data/maps/LitorTown/scripts.pory"
	walk_left
# 446 "data/maps/LitorTown/scripts.pory"
	walk_left
# 447 "data/maps/LitorTown/scripts.pory"
	walk_down
# 448 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 448 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 449 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 449 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 449 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 449 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 450 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 450 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 451 "data/maps/LitorTown/scripts.pory"
	walk_down
# 452 "data/maps/LitorTown/scripts.pory"
	walk_right
# 453 "data/maps/LitorTown/scripts.pory"
	walk_fast_right
# 453 "data/maps/LitorTown/scripts.pory"
	walk_fast_right
# 454 "data/maps/LitorTown/scripts.pory"
	walk_faster_right
# 455 "data/maps/LitorTown/scripts.pory"
	walk_fast_right
# 455 "data/maps/LitorTown/scripts.pory"
	walk_fast_right
# 456 "data/maps/LitorTown/scripts.pory"
	walk_right
# 457 "data/maps/LitorTown/scripts.pory"
	walk_down
# 458 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 458 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 459 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 459 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 459 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 459 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 459 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 459 "data/maps/LitorTown/scripts.pory"
	walk_faster_down
# 460 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 460 "data/maps/LitorTown/scripts.pory"
	walk_fast_down
# 461 "data/maps/LitorTown/scripts.pory"
	walk_down
# 462 "data/maps/LitorTown/scripts.pory"
	walk_left
# 463 "data/maps/LitorTown/scripts.pory"
	walk_down
# 463 "data/maps/LitorTown/scripts.pory"
	walk_down
# 463 "data/maps/LitorTown/scripts.pory"
	walk_down
# 463 "data/maps/LitorTown/scripts.pory"
	walk_down
# 463 "data/maps/LitorTown/scripts.pory"
	walk_down
# 463 "data/maps/LitorTown/scripts.pory"
	walk_down
	step_end

# 466 "data/maps/LitorTown/scripts.pory"
LitorTown_Movement_PlayerExitBoat:
# 467 "data/maps/LitorTown/scripts.pory"
	walk_right
# 467 "data/maps/LitorTown/scripts.pory"
	walk_right
# 468 "data/maps/LitorTown/scripts.pory"
	face_left
	step_end

# 471 "data/maps/LitorTown/scripts.pory"
LitorTown_Movement_FishermanExitBoat:
# 472 "data/maps/LitorTown/scripts.pory"
	walk_right
# 473 "data/maps/LitorTown/scripts.pory"
	face_right
	step_end

# 476 "data/maps/LitorTown/scripts.pory"
LitorTown_Movement_PlayerWalkDown:
# 477 "data/maps/LitorTown/scripts.pory"
	lock_facing_direction
# 478 "data/maps/LitorTown/scripts.pory"
	walk_down
# 479 "data/maps/LitorTown/scripts.pory"
	unlock_facing_direction
	step_end

# 482 "data/maps/LitorTown/scripts.pory"
LitorTown_Movement_JuliaWalkOffscreen:
# 483 "data/maps/LitorTown/scripts.pory"
	walk_right
# 484 "data/maps/LitorTown/scripts.pory"
	walk_down
# 484 "data/maps/LitorTown/scripts.pory"
	walk_down
# 485 "data/maps/LitorTown/scripts.pory"
	walk_right
# 485 "data/maps/LitorTown/scripts.pory"
	walk_right
# 485 "data/maps/LitorTown/scripts.pory"
	walk_right
# 485 "data/maps/LitorTown/scripts.pory"
	walk_right
# 485 "data/maps/LitorTown/scripts.pory"
	walk_right
# 486 "data/maps/LitorTown/scripts.pory"
	walk_down
# 486 "data/maps/LitorTown/scripts.pory"
	walk_down
# 486 "data/maps/LitorTown/scripts.pory"
	walk_down
# 486 "data/maps/LitorTown/scripts.pory"
	walk_down
# 486 "data/maps/LitorTown/scripts.pory"
	walk_down
	step_end

LitorTown_EventScript_Fisherman_Text_0:
# 28 "data/maps/LitorTown/scripts.pory"
	.string "Shall we head back to MURENA?$"

LitorTown_EventScript_ChooseMurena_Text_0:
# 57 "data/maps/LitorTown/scripts.pory"
	.string "We're headed to MURENA CITY!\n"
	.string "Let's set sail!$"

LitorTown_EventScript_ChooseNavire_Text_0:
# 65 "data/maps/LitorTown/scripts.pory"
	.string "We're headed to NAVIRE TOWN!\n"
	.string "Let's set sail!$"

LitorTown_EventScript_CancelFerrySelect_Text_0:
# 73 "data/maps/LitorTown/scripts.pory"
	.string "Tell me whenever you need me\n"
	.string "and my trusty boat.$"

LitorTown_EventScript_SailToNavire_Text_0:
# 169 "data/maps/LitorTown/scripts.pory"
	.string "These are the sands of NAVIRE!\n"
	.string "We've hit the mainland again!$"

LitorTown_EventScript_Scott_Text_0:
# 186 "data/maps/LitorTown/scripts.pory"
	.string "Boot up that new POKéNAV of yours now!\p"
	.string "And check out the map while you're at it,\n"
	.string "you can even check out city views!$"

LitorTown_EventScript_Scott_Text_1:
# 195 "data/maps/LitorTown/scripts.pory"
	.string "Hey there, my name is SCOTT.\n"
	.string "I'm the founder of the HOENN\l"
	.string "BATTLE FRONTIER.\p"
	.string "… … … … … …\p"
	.string "Hmmm, you seem familiar to me…$"

LitorTown_EventScript_Scott_Text_2:
# 206 "data/maps/LitorTown/scripts.pory"
	.string "Ah that's it!\n"
	.string "I saw you on TV!\p"
	.string "You won the FIRWEALD CITY TOURNAMENT,\n"
	.string "didn't you?\p"
	.string "I've always had an eye for\n"
	.string "talented TRAINERS.\p"
	.string "I think you're one of them.\p"
	.string "I'll be keeping an eye out for you.\p"
	.string "Let's register each other\n"
	.string "in our POKéNAVs!\l"
	.string "Wait, you don't have one?\p"
	.string "Well, I know a solution for that.\n"
	.string "Take this!$"

LitorTown_EventScript_Scott_Text_3:
# 225 "data/maps/LitorTown/scripts.pory"
	.string "{PLAYER} recieved the POKéNAV\n"
	.string "from SCOTT!$"

LitorTown_EventScript_Scott_Text_4:
# 230 "data/maps/LitorTown/scripts.pory"
	.string "A POKéNAV is the perfect device for\n"
	.string "any TRAINER!\p"
	.string "You can view the map of the EURUS\n"
	.string "REGION at any time you'd like.\p"
	.string "And you can use MATCH CALL to\n"
	.string "rematch registered TRAINERS.\p"
	.string "Pretty handy device, ey?\p"
	.string "I'll be staying here for a while, but\n"
	.string "perhaps our paths cross again.$"

LitorTown_EventScript_JuliaEncounter_Text_0:
# 257 "data/maps/LitorTown/scripts.pory"
	.string "Oh hey there {PLAYER}!\n"
	.string "I didn't expect you here on LITOR too.\p"
	.string "What a coincidence don't you agree?\n"
	.string "First I meet you while I'm buying\l"
	.string "flowers, and just now I bought a drink\l"
	.string "from here.\p"
	.string "Oh you should totally get a FRESH WATER!\n"
	.string "It's important to stay hydrated\l"
	.string "on an island like this!$"

LitorTown_EventScript_JuliaEncounter_Text_1:
# 271 "data/maps/LitorTown/scripts.pory"
	.string "What? You want to battle me?\p"
	.string "Oh no no, I'm not prepared for that now.\p"
	.string "Maybe when we meet again we'll battle.\n"
	.string "I promise, alright?!\p"
	.string "Anyway emm… I'll be going again hehe…$"

LitorTown_EventScript_TuberM_Text_0:
# 288 "data/maps/LitorTown/scripts.pory"
	.string "Hey! This is my floatie!$"

LitorTown_EventScript_TuberMSwimmer_Text_0:
# 293 "data/maps/LitorTown/scripts.pory"
	.string "I can't swim too far"
	.string "in the open sea.$"

LitorTown_EventScript_TuberF1_Text_0:
# 299 "data/maps/LitorTown/scripts.pory"
	.string "Did you know you can jump onto\n"
	.string "the floaties in the water?$"

LitorTown_EventScript_TuberF2_Text_0:
# 305 "data/maps/LitorTown/scripts.pory"
	.string "My daddy makes the best drinks of LITOR!\n"
	.string "I like his LEMONADE the most.$"

LitorTown_EventScript_TuberF2_Text_1:
# 308 "data/maps/LitorTown/scripts.pory"
	.string "Sometimes a particular girl buys our\n"
	.string "too. She says she likes flowers a lot,\l"
	.string "and our FRESH WATER too.$"

LitorTown_EventScript_Youngster_Text_0:
# 316 "data/maps/LitorTown/scripts.pory"
	.string "Sheesh, being in the hot sun all day\n"
	.string "is tiring…$"

LitorTown_EventScript_Beauty_Text_0:
# 322 "data/maps/LitorTown/scripts.pory"
	.string "Sunbathing in a chair like this…\n"
	.string "I can do it all day.$"

LitorTown_EventScript_Sailor_Text_0:
# 328 "data/maps/LitorTown/scripts.pory"
	.string "Ahh, finally some rest after a\n"
	.string "exhausting day…$"

LitorTown_EventScript_Gentleman_Text_0:
# 334 "data/maps/LitorTown/scripts.pory"
	.string "Renting a cottage at the beach really\n"
	.string "was the right choice after all!\p"
	.string "The grandkids love it!$"

LitorTown_EventScript_Boy_Text_0:
# 341 "data/maps/LitorTown/scripts.pory"
	.string "These beach umbrellas are everywhere\n"
	.string "to keep everyone from getting a\l"
	.string "nasty sunburn.$"

LitorTown_EventScript_TownSign_Text_0:
# 348 "data/maps/LitorTown/scripts.pory"
	.string "LITOR TOWN\n"
	.string "“A sunny, sandy palace.”$"

LitorTown_EventScript_BarSign_Text_0:
# 354 "data/maps/LitorTown/scripts.pory"
	.string "LITOR TOWN BAR\n"
	.string "“Come get a drink!”$"

LitorTown_Text_WhereAreWeHeaded::
# 489 "data/maps/LitorTown/scripts.pory"
	.string "Ahoy!\n"
	.string "Where shall we sail to next?$"
