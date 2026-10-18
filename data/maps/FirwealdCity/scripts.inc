FirwealdCity_MapScripts::
# 9 "data/maps/FirwealdCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FirwealdCity_MapScripts_MAP_SCRIPT_ON_RESUME
# 13 "data/maps/FirwealdCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FirwealdCity_MapScripts_MAP_SCRIPT_ON_LOAD
# 18 "data/maps/FirwealdCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

FirwealdCity_MapScripts_MAP_SCRIPT_ON_RESUME:
# 11 "data/maps/FirwealdCity/scripts.pory"
	dynamicmusic DYNAMIC_MUSIC_DISTANCE, 3
	return

FirwealdCity_MapScripts_MAP_SCRIPT_ON_LOAD:
# 14 "data/maps/FirwealdCity/scripts.pory"
	goto_if_set FLAG_PHYLLOS_LEFT_TOURNAMENT_HALL_LOBBY, FirwealdCity_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

FirwealdCity_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 15 "data/maps/FirwealdCity/scripts.pory"
	setmetatile 37, 16, METATILE_Petalburg_ClosedTournamentHallDoor, 1
	return

FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 19 "data/maps/FirwealdCity/scripts.pory"
	setrespawn HEAL_LOCATION_FIRWEALD_CITY
# 20 "data/maps/FirwealdCity/scripts.pory"
	setflag FLAG_VISITED_FIRWEALD_CITY
# 21 "data/maps/FirwealdCity/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 7
	goto_if_lt FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 25 "data/maps/FirwealdCity/scripts.pory"
	compare VAR_FIRWEALD_CITY_STATE, 1
	goto_if_ge FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 22 "data/maps/FirwealdCity/scripts.pory"
	setobjectxyperm 6, 47, 18
# 23 "data/maps/FirwealdCity/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_UP
	goto FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

FirwealdCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 26 "data/maps/FirwealdCity/scripts.pory"
	setobjectxyperm 1, 36, 10
	return


FirwealdCity_EventScript_ParkSign::
# 32 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_ParkSign_Text_0, MSGBOX_SIGN
	end


FirwealdCity_EventScript_CitySign::
# 37 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_CitySign_Text_0, MSGBOX_SIGN
	end


FirwealdCity_EventScript_CaveSign::
# 43 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_CaveSign_Text_0, MSGBOX_SIGN
	end


FirwealdCity_EventScript_TournamentHallSign::
# 48 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_TournamentHallSign_Text_0, MSGBOX_SIGN
	end


FirwealdCity_EventScript_ItemHyperPotion::
# 55 "data/maps/FirwealdCity/scripts.pory"
	finditem ITEM_HYPER_POTION
	end


FirwealdCity_EventScript_PhyllosEncounter::
# 60 "data/maps/FirwealdCity/scripts.pory"
	lock
# 61 "data/maps/FirwealdCity/scripts.pory"
	setmetatile 37, 16, METATILE_Petalburg_Door_BattleTent, 1
# 62 "data/maps/FirwealdCity/scripts.pory"
	opendoor 37, 16
# 63 "data/maps/FirwealdCity/scripts.pory"
	waitdooranim
# 64 "data/maps/FirwealdCity/scripts.pory"
	addobject 9
# 65 "data/maps/FirwealdCity/scripts.pory"
	applymovement 9, Common_Movement_WalkDown
# 66 "data/maps/FirwealdCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_Movement_PlayerWalkDownBackwards
# 67 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
# 68 "data/maps/FirwealdCity/scripts.pory"
	closedoor 37, 16
# 69 "data/maps/FirwealdCity/scripts.pory"
	waitdooranim
# 70 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
# 71 "data/maps/FirwealdCity/scripts.pory"
	loadspeechtail FALSE, 9
# 72 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_PhyllosEncounter_Text_0
# 86 "data/maps/FirwealdCity/scripts.pory"
	destroyspeechtail
# 87 "data/maps/FirwealdCity/scripts.pory"
	closemessage
# 88 "data/maps/FirwealdCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_Movement_PlayerWalkDownBackwards
# 89 "data/maps/FirwealdCity/scripts.pory"
	applymovement 9, FirwealdCity_Movement_PhyllosWalkToForest
# 90 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
# 91 "data/maps/FirwealdCity/scripts.pory"
	setmetatile 37, 16, METATILE_Petalburg_ClosedTournamentHallDoor, 1
# 92 "data/maps/FirwealdCity/scripts.pory"
	removeobject 9
# 93 "data/maps/FirwealdCity/scripts.pory"
	setflag FLAG_HIDE_ACREN_FOREST_GRUNTS_BLOCKING
# 94 "data/maps/FirwealdCity/scripts.pory"
	setvar VAR_ACREN_FOREST_STATE, 4
# 95 "data/maps/FirwealdCity/scripts.pory"
	setvar VAR_TOURNAMENT_HALL_STATE, 0
# 96 "data/maps/FirwealdCity/scripts.pory"
	release
	end


FirwealdCity_EventScript_Maniac::
# 101 "data/maps/FirwealdCity/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 7
	goto_if_lt FirwealdCity_EventScript_Maniac_1
# 106 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Maniac_Text_1, MSGBOX_NPC
	return

FirwealdCity_EventScript_Maniac_1:
# 102 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Maniac_Text_0, MSGBOX_NPC
	return


FirwealdCity_EventScript_BlockPath::
# 113 "data/maps/FirwealdCity/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 7
	goto_if_ge FirwealdCity_EventScript_BlockPath_1
# 117 "data/maps/FirwealdCity/scripts.pory"
	lock
# 118 "data/maps/FirwealdCity/scripts.pory"
	playse SE_PIN
# 119 "data/maps/FirwealdCity/scripts.pory"
	applymovement 6, Common_Movement_ExclamationMark
# 120 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
# 121 "data/maps/FirwealdCity/scripts.pory"
	applymovement 6, FirwealdCity_Movement_WalkInFrontOfPlayer
# 122 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
# 123 "data/maps/FirwealdCity/scripts.pory"
	loadspeechtail FALSE, 6
# 124 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_BlockPath_Text_0
# 131 "data/maps/FirwealdCity/scripts.pory"
	destroyspeechtail
# 132 "data/maps/FirwealdCity/scripts.pory"
	closemessage
# 133 "data/maps/FirwealdCity/scripts.pory"
	applymovement 6, FirwealdCity_Movement_PushBackPlayer
# 134 "data/maps/FirwealdCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_Movement_WalkBack
# 135 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
# 136 "data/maps/FirwealdCity/scripts.pory"
	applymovement 6, Common_Movement_WalkUp
# 137 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
# 138 "data/maps/FirwealdCity/scripts.pory"
	release
	end

FirwealdCity_EventScript_BlockPath_1:
# 114 "data/maps/FirwealdCity/scripts.pory"
	release
	end


FirwealdCity_EventScript_Fisherman::
# 144 "data/maps/FirwealdCity/scripts.pory"
	lock
# 145 "data/maps/FirwealdCity/scripts.pory"
	faceplayer
# 146 "data/maps/FirwealdCity/scripts.pory"
	goto_if_set FLAG_FIRWEALD_CITY_FISHERMAN_MART_EVENT, FirwealdCity_EventScript_Fisherman_1
# 151 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Fisherman_Text_1, MSGBOX_NPC
# 154 "data/maps/FirwealdCity/scripts.pory"
	playse SE_PIN
# 155 "data/maps/FirwealdCity/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 156 "data/maps/FirwealdCity/scripts.pory"
	delay 32
# 157 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Fisherman_Text_2, MSGBOX_NPC
# 162 "data/maps/FirwealdCity/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq FirwealdCity_EventScript_Fisherman_5
# 166 "data/maps/FirwealdCity/scripts.pory"
	applymovement 4, FirwealdCity_Movement_WalkToPokeMart
# 167 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
FirwealdCity_EventScript_Fisherman_4:
# 169 "data/maps/FirwealdCity/scripts.pory"
	removeobject 4, MAP_FIRWEALD_CITY
# 170 "data/maps/FirwealdCity/scripts.pory"
	clearflag FLAG_HIDE_FIRWEALD_CITY_MART_FISHERMAN
# 171 "data/maps/FirwealdCity/scripts.pory"
	setflag FLAG_FIRWEALD_CITY_FISHERMAN_MART_EVENT
# 172 "data/maps/FirwealdCity/scripts.pory"
	release
	end

FirwealdCity_EventScript_Fisherman_1:
# 147 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Fisherman_Text_0, MSGBOX_NPC
	end

FirwealdCity_EventScript_Fisherman_5:
# 163 "data/maps/FirwealdCity/scripts.pory"
	applymovement 4, FirwealdCity_Movement_WalkAroundPlayerToPokeMart
# 164 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
	goto FirwealdCity_EventScript_Fisherman_4


FirwealdCity_EventScript_Triathlete::
# 178 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Triathlete_Text_0, MSGBOX_NPC
# 181 "data/maps/FirwealdCity/scripts.pory"
	enablequest QUEST_TEST
	end


FirwealdCity_EventScript_Boy::
# 186 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Boy_Text_0, MSGBOX_NPC
	end


FirwealdCity_EventScript_Lass::
# 192 "data/maps/FirwealdCity/scripts.pory"
	goto_if_set FLAG_FIRWEALD_CITY_HIDE_AND_SEEK_EVENT, FirwealdCity_EventScript_Lass_3
# 197 "data/maps/FirwealdCity/scripts.pory"
	lock
# 198 "data/maps/FirwealdCity/scripts.pory"
	faceplayer
# 199 "data/maps/FirwealdCity/scripts.pory"
	loadspeechtail FALSE, 3
# 200 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Lass_Text_1, MSGBOX_YESNO
# 204 "data/maps/FirwealdCity/scripts.pory"
	destroyspeechtail
# 205 "data/maps/FirwealdCity/scripts.pory"
	switch VAR_RESULT
# 206 "data/maps/FirwealdCity/scripts.pory"
	case NO, FirwealdCity_EventScript_Lass_6
# 209 "data/maps/FirwealdCity/scripts.pory"
	case YES, FirwealdCity_EventScript_Lass_7
	return

FirwealdCity_EventScript_Lass_3:
# 193 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Lass_Text_0, MSGBOX_NPC
	end

FirwealdCity_EventScript_Lass_6:
# 207 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Lass_Text_2, MSGBOX_NPC
	end

FirwealdCity_EventScript_Lass_7:
# 210 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_Lass_Text_3, MSGBOX_NPC
# 213 "data/maps/FirwealdCity/scripts.pory"
	setflag FLAG_FIRWEALD_CITY_HIDE_AND_SEEK_EVENT
	end


FirwealdCity_EventScript_LittleGirl::
# 219 "data/maps/FirwealdCity/scripts.pory"
	goto_if_set FLAG_FIRWEALD_CITY_HIDE_AND_SEEK_EVENT, FirwealdCity_EventScript_LittleGirl_3
# 260 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_LittleGirl_Text_2, MSGBOX_NPC
	end

FirwealdCity_EventScript_LittleGirl_3:
# 220 "data/maps/FirwealdCity/scripts.pory"
	lock
# 221 "data/maps/FirwealdCity/scripts.pory"
	faceplayer
# 222 "data/maps/FirwealdCity/scripts.pory"
	playse SE_PIN
# 223 "data/maps/FirwealdCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_Movement_NoticeLittleGirlHidingSpot
# 224 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
# 225 "data/maps/FirwealdCity/scripts.pory"
	loadspeechtail FALSE, 2
# 226 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_LittleGirl_Text_0
# 228 "data/maps/FirwealdCity/scripts.pory"
	destroyspeechtail
# 229 "data/maps/FirwealdCity/scripts.pory"
	closemessage
# 230 "data/maps/FirwealdCity/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq FirwealdCity_EventScript_LittleGirl_6
# 234 "data/maps/FirwealdCity/scripts.pory"
	applymovement 3, FirwealdCity_Movement_LassWalkToLittleGirlFacingEastAndWest
# 235 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
FirwealdCity_EventScript_LittleGirl_5:
# 237 "data/maps/FirwealdCity/scripts.pory"
	loadspeechtail FALSE, 3
# 238 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_LittleGirl_Text_1
# 241 "data/maps/FirwealdCity/scripts.pory"
	destroyspeechtail
# 242 "data/maps/FirwealdCity/scripts.pory"
	closemessage
# 243 "data/maps/FirwealdCity/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq FirwealdCity_EventScript_LittleGirl_10
# 248 "data/maps/FirwealdCity/scripts.pory"
	applymovement 3, FirwealdCity_Movement_LassWalkHomeFacingEastAndWest
# 249 "data/maps/FirwealdCity/scripts.pory"
	applymovement 2, FirwealdCity_Movement_LittleGirlWalkHomeFacingEastAndWest
# 250 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
FirwealdCity_EventScript_LittleGirl_9:
# 252 "data/maps/FirwealdCity/scripts.pory"
	removeobject 3, MAP_FIRWEALD_CITY
# 253 "data/maps/FirwealdCity/scripts.pory"
	removeobject 2, MAP_FIRWEALD_CITY
# 254 "data/maps/FirwealdCity/scripts.pory"
	clearflag FLAG_HIDE_FIRWEALD_CITY_HOUSE1_LITTLE_GIRL
# 255 "data/maps/FirwealdCity/scripts.pory"
	clearflag FLAG_HIDE_FIRWEALD_CITY_HOUSE1_LASS
# 256 "data/maps/FirwealdCity/scripts.pory"
	clearflag FLAG_FIRWEALD_CITY_HIDE_AND_SEEK_EVENT
# 257 "data/maps/FirwealdCity/scripts.pory"
	release
	end

FirwealdCity_EventScript_LittleGirl_6:
# 231 "data/maps/FirwealdCity/scripts.pory"
	applymovement 3, FirwealdCity_Movement_LassWalkToLittleGirlFacingSouth
# 232 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
	goto FirwealdCity_EventScript_LittleGirl_5

FirwealdCity_EventScript_LittleGirl_10:
# 244 "data/maps/FirwealdCity/scripts.pory"
	applymovement 3, FirwealdCity_Movement_LassWalkHomeFacingSouth
# 245 "data/maps/FirwealdCity/scripts.pory"
	applymovement 2, FirwealdCity_Movement_LittleGirlWalkHomeFacingSouth
# 246 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
	goto FirwealdCity_EventScript_LittleGirl_9


FirwealdCity_EventScript_OldWoman::
# 267 "data/maps/FirwealdCity/scripts.pory"
	compare VAR_FIRWEALD_CITY_STATE, 1
	goto_if_ge FirwealdCity_EventScript_OldWoman_1
# 270 "data/maps/FirwealdCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, FirwealdCity_EventScript_OldWoman_2
# 279 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_OldWoman_Text_0, MSGBOX_NPC
	end

FirwealdCity_EventScript_OldWoman_1:
# 268 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_OldWoman_Text_0, MSGBOX_NPC
	end

FirwealdCity_EventScript_OldWoman_2:
# 271 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_EventScript_OldWoman_Text_1, MSGBOX_NPC
# 273 "data/maps/FirwealdCity/scripts.pory"
	applymovement 1, FirwealdCity_Movement_OldWomanWalkToLeft
# 274 "data/maps/FirwealdCity/scripts.pory"
	waitmovement 0
# 275 "data/maps/FirwealdCity/scripts.pory"
	setobjectxyperm 1, 36, 10
# 276 "data/maps/FirwealdCity/scripts.pory"
	setvar VAR_FIRWEALD_CITY_STATE, 1
	end


EventScript_ClosedFirwealdDoor::
# 285 "data/maps/FirwealdCity/scripts.pory"
	msgbox FirwealdCity_Text_DoorIsClosed, MSGBOX_SIGN
	end


# 289 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_WalkInFrontOfPlayer:
# 290 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 291 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 292 "data/maps/FirwealdCity/scripts.pory"
	face_left
	step_end

# 295 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_PushBackPlayer:
# 296 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 297 "data/maps/FirwealdCity/scripts.pory"
	delay_16
# 298 "data/maps/FirwealdCity/scripts.pory"
	walk_up
	step_end

# 301 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_WalkBack:
# 302 "data/maps/FirwealdCity/scripts.pory"
	lock_facing_direction
# 303 "data/maps/FirwealdCity/scripts.pory"
	jump_left
	step_end

# 306 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_WalkAroundPlayerToPokeMart:
# 307 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 308 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 308 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 309 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 309 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 309 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 309 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 309 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 309 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 310 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 311 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 311 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 311 "data/maps/FirwealdCity/scripts.pory"
	walk_left
	step_end

# 314 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_WalkToPokeMart:
# 315 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 315 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 316 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 316 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 316 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 316 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 316 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 317 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 318 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 318 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 318 "data/maps/FirwealdCity/scripts.pory"
	walk_left
	step_end

# 321 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_NoticeLittleGirlHidingSpot:
# 322 "data/maps/FirwealdCity/scripts.pory"
	emote_exclamation_mark
# 323 "data/maps/FirwealdCity/scripts.pory"
	delay_16
# 323 "data/maps/FirwealdCity/scripts.pory"
	delay_16
# 324 "data/maps/FirwealdCity/scripts.pory"
	lock_facing_direction
# 325 "data/maps/FirwealdCity/scripts.pory"
	jump_in_place_down
# 325 "data/maps/FirwealdCity/scripts.pory"
	jump_in_place_down
	step_end

# 328 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_LassWalkToLittleGirlFacingSouth:
# 329 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 329 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 329 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 330 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 331 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 331 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 332 "data/maps/FirwealdCity/scripts.pory"
	walk_left
	step_end

# 335 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_LassWalkToLittleGirlFacingEastAndWest:
# 336 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 336 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 336 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 337 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 338 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 338 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 338 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 339 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 339 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 340 "data/maps/FirwealdCity/scripts.pory"
	face_down
	step_end

# 343 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_LassWalkHomeFacingEastAndWest:
# 344 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 344 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 344 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 345 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 345 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 345 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 346 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 346 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 346 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 346 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 346 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 346 "data/maps/FirwealdCity/scripts.pory"
	walk_right
	step_end

# 349 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_LittleGirlWalkHomeFacingEastAndWest:
# 350 "data/maps/FirwealdCity/scripts.pory"
	walk_up
# 351 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 351 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 351 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 352 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 352 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 352 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 353 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 353 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 353 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 353 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 353 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 353 "data/maps/FirwealdCity/scripts.pory"
	walk_right
	step_end

# 356 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_LassWalkHomeFacingSouth:
# 357 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 357 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 358 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 358 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 359 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 359 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 359 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 359 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 359 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 359 "data/maps/FirwealdCity/scripts.pory"
	walk_right
	step_end

# 362 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_LittleGirlWalkHomeFacingSouth:
# 363 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 363 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 363 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 364 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 364 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 365 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 365 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 365 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 365 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 365 "data/maps/FirwealdCity/scripts.pory"
	walk_right
# 365 "data/maps/FirwealdCity/scripts.pory"
	walk_right
	step_end

# 368 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_PlayerWalkDownBackwards:
# 369 "data/maps/FirwealdCity/scripts.pory"
	lock_facing_direction
# 370 "data/maps/FirwealdCity/scripts.pory"
	walk_down
	step_end

# 373 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_PhyllosWalkToForest:
# 374 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 375 "data/maps/FirwealdCity/scripts.pory"
	walk_left
# 376 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 376 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 376 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 376 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 376 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 376 "data/maps/FirwealdCity/scripts.pory"
	walk_down
# 376 "data/maps/FirwealdCity/scripts.pory"
	walk_down
	step_end

# 379 "data/maps/FirwealdCity/scripts.pory"
FirwealdCity_Movement_OldWomanWalkToLeft:
# 380 "data/maps/FirwealdCity/scripts.pory"
	walk_slow_left
# 381 "data/maps/FirwealdCity/scripts.pory"
	face_down
	step_end

FirwealdCity_EventScript_ParkSign_Text_0:
# 32 "data/maps/FirwealdCity/scripts.pory"
	.string "FIRWEALD PARK$"

FirwealdCity_EventScript_CitySign_Text_0:
# 37 "data/maps/FirwealdCity/scripts.pory"
	.string "FIRWEALD CITY\n"
	.string "“Water and earth in harmony.”$"

FirwealdCity_EventScript_CaveSign_Text_0:
# 43 "data/maps/FirwealdCity/scripts.pory"
	.string "FOREST TUNNEL$"

FirwealdCity_EventScript_TournamentHallSign_Text_0:
# 48 "data/maps/FirwealdCity/scripts.pory"
	.string "FIRWEALD CITY TOURNAMENT HALL.\p"
	.string "Challenge PHYLLOS, the protector\n"
	.string "of ACREN FOREST.$"

FirwealdCity_EventScript_PhyllosEncounter_Text_0:
# 72 "data/maps/FirwealdCity/scripts.pory"
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
# 102 "data/maps/FirwealdCity/scripts.pory"
	.string "Don't bother me please.\n"
	.string "Something is happening in this tree,\l"
	.string "and I want to know what.$"

FirwealdCity_EventScript_Maniac_Text_1:
# 106 "data/maps/FirwealdCity/scripts.pory"
	.string "As it turned out…\p"
	.string "Nothing ever happened in that tree…\p"
	.string "I'm sorry for blocking your path…$"

FirwealdCity_EventScript_BlockPath_Text_0:
# 124 "data/maps/FirwealdCity/scripts.pory"
	.string "Hmmmm…\n"
	.string "That glint in your eyes…\p"
	.string "I'm sure you have some business\n"
	.string "to do here in FIRWEALD CITY.\p"
	.string "Fufufu… Fufufu…\p"
	.string "Go do your thing while I inspect this\n"
	.string "tree right here.$"

FirwealdCity_EventScript_Fisherman_Text_0:
# 147 "data/maps/FirwealdCity/scripts.pory"
	.string "Oh man…\n"
	.string "The GOLDEEN still aren't biting…$"

FirwealdCity_EventScript_Fisherman_Text_1:
# 151 "data/maps/FirwealdCity/scripts.pory"
	.string "Hiya there!\n"
	.string "I've heard there are rare GOLDEEN\l"
	.string "in this small lake.$"

FirwealdCity_EventScript_Fisherman_Text_2:
# 157 "data/maps/FirwealdCity/scripts.pory"
	.string "Oh no!\n"
	.string "I forgot to buy fishing bait!\p"
	.string "What a foolish mistake…\p"
	.string "I'll be off to the POKéMART to\n"
	.string "buy some then.$"

FirwealdCity_EventScript_Triathlete_Text_0:
# 178 "data/maps/FirwealdCity/scripts.pory"
	.string "Huff puff puff\n"
	.string "I don't have time for talking.\p"
	.string "I must keep running!$"

FirwealdCity_EventScript_Boy_Text_0:
# 186 "data/maps/FirwealdCity/scripts.pory"
	.string "My big sister always plays hide and\n"
	.string "seek with my other sister…$"

FirwealdCity_EventScript_Lass_Text_0:
# 193 "data/maps/FirwealdCity/scripts.pory"
	.string "Where could she be?\p"
	.string "She's very good at hiding!$"

FirwealdCity_EventScript_Lass_Text_1:
# 200 "data/maps/FirwealdCity/scripts.pory"
	.string "My little sister and I are\n"
	.string "playing hide and seek, but\l"
	.string "I really can't find her…\p"
	.string "Do you want to help me out?$"

FirwealdCity_EventScript_Lass_Text_2:
# 207 "data/maps/FirwealdCity/scripts.pory"
	.string "Aww, that's too bad$"

FirwealdCity_EventScript_Lass_Text_3:
# 210 "data/maps/FirwealdCity/scripts.pory"
	.string "Great!\p"
	.string "She should be somewehere here\n"
	.string "in FIRWEALD PARK.$"

FirwealdCity_EventScript_LittleGirl_Text_0:
# 226 "data/maps/FirwealdCity/scripts.pory"
	.string "Are you helping my big sister?!\p"
	.string "You're such a meanie!$"

FirwealdCity_EventScript_LittleGirl_Text_1:
# 238 "data/maps/FirwealdCity/scripts.pory"
	.string "Hey, he found you!\p"
	.string "Let's go home now, grandpa is\n"
	.string "waiting for us.$"

FirwealdCity_EventScript_LittleGirl_Text_2:
# 260 "data/maps/FirwealdCity/scripts.pory"
	.string "Shhh, I'm hiding from my big\n"
	.string "sister.\p"
	.string "Don't tell her I'm here!$"

FirwealdCity_EventScript_OldWoman_Text_0:
# 268 "data/maps/FirwealdCity/scripts.pory"
	.string "… … … … … …$"

FirwealdCity_EventScript_OldWoman_Text_1:
# 271 "data/maps/FirwealdCity/scripts.pory"
	.string "… … … … … …\p"
	.string "I see…$"

FirwealdCity_Text_DoorIsClosed::
# 384 "data/maps/FirwealdCity/scripts.pory"
	.string "The door of the TOURNAMENT HALL\n"
	.string "seems to be closed.$"
