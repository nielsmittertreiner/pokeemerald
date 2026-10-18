AcrenForest_MapScripts::
# 15 "data/maps/AcrenForest/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AcrenForest_MapScripts_MAP_SCRIPT_ON_RESUME
# 19 "data/maps/AcrenForest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 65 "data/maps/AcrenForest/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AcrenForest_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AcrenForest_MapScripts_MAP_SCRIPT_ON_RESUME:
# 17 "data/maps/AcrenForest/scripts.pory"
	dynamicmusic DYNAMIC_MUSIC_MOVEMENT
	return

AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 20 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 2
	goto_if_eq AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 32 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 3
	goto_if_eq AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 44 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 4
	goto_if_eq AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 54 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 5
	goto_if_eq AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_10
	return

AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 21 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 17, 39, 11
# 22 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 18, 39, 10
# 23 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 19, 53, 5
# 24 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 20, 54, 5
# 25 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 17, MOVEMENT_TYPE_RUN_IN_PLACE_LEFT
# 26 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 18, MOVEMENT_TYPE_RUN_IN_PLACE_LEFT
# 27 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 19, MOVEMENT_TYPE_FACE_DOWN
# 28 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 20, MOVEMENT_TYPE_FACE_DOWN
# 29 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 9, MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT
# 30 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 10, MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT
	goto AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 33 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 17, 39, 11
# 34 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 18, 39, 10
# 35 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 19, 52, 6
# 36 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 20, 55, 6
# 37 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 17, MOVEMENT_TYPE_RUN_IN_PLACE_LEFT
# 38 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 18, MOVEMENT_TYPE_RUN_IN_PLACE_LEFT
# 39 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 19, MOVEMENT_TYPE_FACE_DOWN
# 40 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 20, MOVEMENT_TYPE_FACE_DOWN
# 41 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 9, MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT
# 42 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 10, MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT
	goto AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 45 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 17, 4, 6
# 46 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 18, 4, 7
# 47 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 19, 52, 6
# 48 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 20, 55, 6
# 49 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 17, MOVEMENT_TYPE_FACE_RIGHT
# 50 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_RIGHT
# 51 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 19, MOVEMENT_TYPE_FACE_DOWN
# 52 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 20, MOVEMENT_TYPE_FACE_DOWN
	goto AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

AcrenForest_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
# 55 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 17, 4, 6
# 56 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 18, 4, 7
# 57 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 19, 52, 6
# 58 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 20, 55, 6
# 59 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 17, MOVEMENT_TYPE_FACE_RIGHT
# 60 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_RIGHT
# 61 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 19, MOVEMENT_TYPE_FACE_DOWN
# 62 "data/maps/AcrenForest/scripts.pory"
	setobjectmovementtype 20, MOVEMENT_TYPE_FACE_DOWN
	return

AcrenForest_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 66 "data/maps/AcrenForest/scripts.pory"
	map_script_2 VAR_ACREN_FOREST_STATE, 0, AcrenForest_EventScript_LoggersCutscene
# 67 "data/maps/AcrenForest/scripts.pory"
	map_script_2 VAR_FIRWEALD_CITY_STATE, 1, AcrenForest_EventScript_PhyllosShrineCutscene
	.2byte 0


AcrenForest_EventScript_PhyllosShrineCutscene::
# 72 "data/maps/AcrenForest/scripts.pory"
	playse SE_PIN
# 73 "data/maps/AcrenForest/scripts.pory"
	applymovement 31, Common_Movement_ExclamationMark
# 74 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 75 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 31
# 76 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_0
# 80 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 81 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 82 "data/maps/AcrenForest/scripts.pory"
	applymovement 31, AcrenForest_Movement_PhyllosWalkToShrine
# 83 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AcrenForest_Movement_PlayerWalkToShrine
# 84 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 85 "data/maps/AcrenForest/scripts.pory"
	delay 30
# 86 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 31
# 87 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_1
# 104 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 105 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 106 "data/maps/AcrenForest/scripts.pory"
	delay 10
# 107 "data/maps/AcrenForest/scripts.pory"
	fadenewbgm MUS_CELEBI
# 108 "data/maps/AcrenForest/scripts.pory"
	setweather WEATHER_SUNNY
# 109 "data/maps/AcrenForest/scripts.pory"
	doweather
# 110 "data/maps/AcrenForest/scripts.pory"
	applymovement 31, Common_Movement_FaceUp
# 111 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 112 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 113 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 31
# 114 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_2
# 119 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 120 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 121 "data/maps/AcrenForest/scripts.pory"
	delay 10
# 122 "data/maps/AcrenForest/scripts.pory"
	applymovement 31, Common_Movement_FaceLeft
# 123 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 124 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 125 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 31
# 126 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_3
# 144 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 145 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 146 "data/maps/AcrenForest/scripts.pory"
	delay 10
# 147 "data/maps/AcrenForest/scripts.pory"
	fadedefaultbgm
# 148 "data/maps/AcrenForest/scripts.pory"
	resetweather
# 149 "data/maps/AcrenForest/scripts.pory"
	doweather
# 150 "data/maps/AcrenForest/scripts.pory"
	applymovement 31, Common_Movement_WalkInPlaceFastestLeft
# 151 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 152 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 31
# 153 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_4
# 154 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 155 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 156 "data/maps/AcrenForest/scripts.pory"
	giveitem ITEM_BRIGHT_POWDER, 1
# 157 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 31
# 158 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_PhyllosShrineCutscene_Text_5
# 162 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 163 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 164 "data/maps/AcrenForest/scripts.pory"
	applymovement 31, AcrenForest_Movement_PhyllosWalkFromShrine_1
# 165 "data/maps/AcrenForest/scripts.pory"
	delay 32
# 166 "data/maps/AcrenForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 167 "data/maps/AcrenForest/scripts.pory"
	applymovement 31, AcrenForest_Movement_PhyllosWalkFromShrine_2
# 168 "data/maps/AcrenForest/scripts.pory"
	delay 32
# 169 "data/maps/AcrenForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 170 "data/maps/AcrenForest/scripts.pory"
	applymovement 31, AcrenForest_Movement_PhyllosWalkFromShrine_3
# 171 "data/maps/AcrenForest/scripts.pory"
	delay 32
# 172 "data/maps/AcrenForest/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 173 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 174 "data/maps/AcrenForest/scripts.pory"
	removeobject 31
# 175 "data/maps/AcrenForest/scripts.pory"
	setvar VAR_FIRWEALD_CITY_STATE, 2
	end


AcrenForest_EventScript_LoggersCutscene::
# 180 "data/maps/AcrenForest/scripts.pory"
	lock
# 181 "data/maps/AcrenForest/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 182 "data/maps/AcrenForest/scripts.pory"
	compare VAR_TEMP_0, 55
	goto_if_eq AcrenForest_EventScript_LoggersCutscene_2
# 185 "data/maps/AcrenForest/scripts.pory"
	compare VAR_TEMP_0, 56
	goto_if_eq AcrenForest_EventScript_LoggersCutscene_3
AcrenForest_EventScript_LoggersCutscene_1:
# 191 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 17
# 192 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_LoggersCutscene_Text_0
# 196 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 197 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 198 "data/maps/AcrenForest/scripts.pory"
	special SpawnCameraObject
# 199 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AcrenForest_Movement_CameraToGrunts
# 200 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 201 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_LoggersCutscene_Text_1
# 203 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 204 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AcrenForest_Movement_CameraToPlayer
# 205 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 206 "data/maps/AcrenForest/scripts.pory"
	special RemoveCameraObject
# 207 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 17
# 208 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_LoggersCutscene_Text_2
# 211 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 212 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 213 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_LoggersCutscene_Text_3
# 215 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 216 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 17
# 217 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_LoggersCutscene_Text_4
# 224 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 225 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 226 "data/maps/AcrenForest/scripts.pory"
	setvar VAR_ACREN_FOREST_STATE, 1
# 227 "data/maps/AcrenForest/scripts.pory"
	release
	end

AcrenForest_EventScript_LoggersCutscene_2:
# 183 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 184 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
	goto AcrenForest_EventScript_LoggersCutscene_1

AcrenForest_EventScript_LoggersCutscene_3:
# 186 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 187 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
# 188 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 189 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
	goto AcrenForest_EventScript_LoggersCutscene_1


AcrenForest_EventScript_Logger1::
# 232 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 2
	goto_if_eq AcrenForest_EventScript_Logger1_2
# 240 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 5
	goto_if_eq AcrenForest_EventScript_Logger1_3
# 245 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Logger1_Text_2, MSGBOX_NPC
	end

AcrenForest_EventScript_Logger1_2:
# 233 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Logger1_Text_0, MSGBOX_NPC
# 237 "data/maps/AcrenForest/scripts.pory"
	turnobject 17, DIR_WEST
# 238 "data/maps/AcrenForest/scripts.pory"
	turnobject 18, DIR_WEST
	end

AcrenForest_EventScript_Logger1_3:
# 241 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Logger1_Text_1, MSGBOX_NPC
	end


AcrenForest_EventScript_Logger2::
# 251 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 2
	goto_if_eq AcrenForest_EventScript_Logger2_2
# 259 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 5
	goto_if_eq AcrenForest_EventScript_Logger2_3
# 263 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Logger2_Text_1, MSGBOX_NPC
	end

AcrenForest_EventScript_Logger2_2:
# 252 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Logger1_Text_0, MSGBOX_NPC
# 256 "data/maps/AcrenForest/scripts.pory"
	turnobject 17, DIR_WEST
# 257 "data/maps/AcrenForest/scripts.pory"
	turnobject 18, DIR_WEST
	end

AcrenForest_EventScript_Logger2_3:
# 260 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Logger2_Text_0, MSGBOX_NPC
	end


AcrenForest_EventScript_Logger3And4::
# 268 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 2
	goto_if_eq AcrenForest_EventScript_Logger3And4_2
# 283 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 3
	goto_if_eq AcrenForest_EventScript_Logger3And4_5
# 286 "data/maps/AcrenForest/scripts.pory"
	compare VAR_ACREN_FOREST_STATE, 4
	goto_if_eq AcrenForest_EventScript_Logger3And4_6
# 292 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Logger2_Text_1, MSGBOX_NPC
	end

AcrenForest_EventScript_Logger3And4_2:
# 269 "data/maps/AcrenForest/scripts.pory"
	lock
# 270 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Logger3And4_Text_0, MSGBOX_NPC
# 273 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AcrenForest_Movement_PlayerWalkBackwards
# 274 "data/maps/AcrenForest/scripts.pory"
	applymovement 19, AcrenForest_Movement_Logger3WalkLeft
# 275 "data/maps/AcrenForest/scripts.pory"
	applymovement 20, AcrenForest_Movement_Logger4WalkRight
# 276 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 277 "data/maps/AcrenForest/scripts.pory"
	copyobjectxytoperm 19
# 278 "data/maps/AcrenForest/scripts.pory"
	copyobjectxytoperm 20
# 279 "data/maps/AcrenForest/scripts.pory"
	setvar VAR_ACREN_FOREST_STATE, 3
# 280 "data/maps/AcrenForest/scripts.pory"
	release
	end

AcrenForest_EventScript_Logger3And4_5:
# 284 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Logger3And4_Text_1, MSGBOX_NPC
	end

AcrenForest_EventScript_Logger3And4_6:
# 287 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Logger3And4_Text_2, MSGBOX_NPC
	end


AcrenForest_EventScript_TeamAirlockGrunt::
# 297 "data/maps/AcrenForest/scripts.pory"
	random 6
# 298 "data/maps/AcrenForest/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 299 "data/maps/AcrenForest/scripts.pory"
	switch VAR_TEMP_F
# 300 "data/maps/AcrenForest/scripts.pory"
	case 0, AcrenForest_EventScript_TeamAirlockGrunt_3
# 303 "data/maps/AcrenForest/scripts.pory"
	case 1, AcrenForest_EventScript_TeamAirlockGrunt_4
# 308 "data/maps/AcrenForest/scripts.pory"
	case 2, AcrenForest_EventScript_TeamAirlockGrunt_5
# 311 "data/maps/AcrenForest/scripts.pory"
	case 3, AcrenForest_EventScript_TeamAirlockGrunt_6
# 315 "data/maps/AcrenForest/scripts.pory"
	case 4, AcrenForest_EventScript_TeamAirlockGrunt_7
# 319 "data/maps/AcrenForest/scripts.pory"
	case 5, AcrenForest_EventScript_TeamAirlockGrunt_8
AcrenForest_EventScript_TeamAirlockGrunt_1:
	end

AcrenForest_EventScript_TeamAirlockGrunt_3:
# 301 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_0, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1

AcrenForest_EventScript_TeamAirlockGrunt_4:
# 304 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_1, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1

AcrenForest_EventScript_TeamAirlockGrunt_5:
# 309 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_2, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1

AcrenForest_EventScript_TeamAirlockGrunt_6:
# 312 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_3, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1

AcrenForest_EventScript_TeamAirlockGrunt_7:
# 316 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_4, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1

AcrenForest_EventScript_TeamAirlockGrunt_8:
# 320 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_TeamAirlockGrunt_Text_5, MSGBOX_NPC
	goto AcrenForest_EventScript_TeamAirlockGrunt_1


AcrenForest_EventScript_DescribeIllegalCamp::
# 328 "data/maps/AcrenForest/scripts.pory"
	lock
# 329 "data/maps/AcrenForest/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 330 "data/maps/AcrenForest/scripts.pory"
	playse SE_PIN
# 331 "data/maps/AcrenForest/scripts.pory"
	applymovement 30, Common_Movement_ExclamationMark
# 332 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 333 "data/maps/AcrenForest/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_eq AcrenForest_EventScript_DescribeIllegalCamp_2
AcrenForest_EventScript_DescribeIllegalCamp_1:
# 337 "data/maps/AcrenForest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 338 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 339 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 30
# 340 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_DescribeIllegalCamp_Text_0
# 343 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 344 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 345 "data/maps/AcrenForest/scripts.pory"
	turnobject 30, DIR_SOUTH
# 346 "data/maps/AcrenForest/scripts.pory"
	applymovement 30, AcrenForest_Movement_PhyllosLaughterJump
# 347 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 348 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 30
# 349 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_DescribeIllegalCamp_Text_1
# 351 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 352 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 353 "data/maps/AcrenForest/scripts.pory"
	delay 10
# 354 "data/maps/AcrenForest/scripts.pory"
	teleportcamera 6, 28
# 355 "data/maps/AcrenForest/scripts.pory"
	delay 30
# 356 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_DescribeIllegalCamp_Text_2
# 360 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 361 "data/maps/AcrenForest/scripts.pory"
	delay 10
# 362 "data/maps/AcrenForest/scripts.pory"
	resetcamera
# 363 "data/maps/AcrenForest/scripts.pory"
	delay 30
# 364 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 30
# 365 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_DescribeIllegalCamp_Text_3
# 367 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 368 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 369 "data/maps/AcrenForest/scripts.pory"
	setvar VAR_ACREN_FOREST_STATE, 5
# 370 "data/maps/AcrenForest/scripts.pory"
	release
	end

AcrenForest_EventScript_DescribeIllegalCamp_2:
# 334 "data/maps/AcrenForest/scripts.pory"
	applymovement 30, Common_Movement_WalkLeft
# 335 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
	goto AcrenForest_EventScript_DescribeIllegalCamp_1


AcrenForest_EventScript_WarnBoss::
# 375 "data/maps/AcrenForest/scripts.pory"
	lock
# 376 "data/maps/AcrenForest/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 377 "data/maps/AcrenForest/scripts.pory"
	applymovement 29, Common_Movement_ExclamationMark
# 378 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 379 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 29
# 380 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_WarnBoss_Text_0
# 387 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 388 "data/maps/AcrenForest/scripts.pory"
	closemessage
# 389 "data/maps/AcrenForest/scripts.pory"
	applymovement 29, Common_Movement_WalkUp
# 390 "data/maps/AcrenForest/scripts.pory"
	waitmovement 0
# 391 "data/maps/AcrenForest/scripts.pory"
	playse SE_EXIT
# 392 "data/maps/AcrenForest/scripts.pory"
	removeobject 29
# 393 "data/maps/AcrenForest/scripts.pory"
	setobjectxyperm 29, 2, 24
# 394 "data/maps/AcrenForest/scripts.pory"
	fadedefaultbgm
# 395 "data/maps/AcrenForest/scripts.pory"
	setvar VAR_ACREN_FOREST_STATE, 6
# 396 "data/maps/AcrenForest/scripts.pory"
	release
	end


AcrenForest_EventScript_Phyllos::
# 401 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_DescribeIllegalCamp_Text_3, MSGBOX_NPC
	end


AcrenForest_EventScript_TrainerTipsSurf::
# 407 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_TrainerTipsSurf_Text_0, MSGBOX_SIGN
	end


AcrenForest_EventScript_TrainerTipsHeldItems::
# 414 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_TrainerTipsHeldItems_Text_0, MSGBOX_SIGN
	end


AcrenForest_EventScript_Boy::
# 426 "data/maps/AcrenForest/scripts.pory"
	lock
# 427 "data/maps/AcrenForest/scripts.pory"
	faceplayer
# 428 "data/maps/AcrenForest/scripts.pory"
	loadspeechtail FALSE, 8
# 429 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Boy_Text_0, MSGBOX_YESNO
# 431 "data/maps/AcrenForest/scripts.pory"
	destroyspeechtail
# 432 "data/maps/AcrenForest/scripts.pory"
	switch VAR_RESULT
# 433 "data/maps/AcrenForest/scripts.pory"
	case YES, AcrenForest_EventScript_Boy_3
# 436 "data/maps/AcrenForest/scripts.pory"
	case NO, AcrenForest_EventScript_Boy_4
AcrenForest_EventScript_Boy_1:
# 441 "data/maps/AcrenForest/scripts.pory"
	release
	end

AcrenForest_EventScript_Boy_3:
# 434 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Boy_Text_1, MSGBOX_NPC
	goto AcrenForest_EventScript_Boy_1

AcrenForest_EventScript_Boy_4:
# 437 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_Boy_Text_2, MSGBOX_NPC
	goto AcrenForest_EventScript_Boy_1


AcrenForest_EventScript_BugCatcher::
# 446 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	end


AcrenForest_EventScript_ItemGreatBall::
# 454 "data/maps/AcrenForest/scripts.pory"
	finditem ITEM_GREAT_BALL
	end


AcrenForest_EventScript_ItemPokeBall::
# 459 "data/maps/AcrenForest/scripts.pory"
	finditem ITEM_POKE_BALL
	end


AcrenForest_EventScript_FlowerShopSign::
# 464 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_FlowerShopSign_Text_0, MSGBOX_SIGN
	end


AcrenForest_EventScript_Frederick::
# 469 "data/maps/AcrenForest/scripts.pory"
	trainerbattle_single TRAINER_ACREN_FOREST_FREDERICK, AcrenForest_Text_FrederickIntro, AcrenForest_Text_FrederickDefeat
# 470 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_Text_FrederickPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_Roddy::
# 475 "data/maps/AcrenForest/scripts.pory"
	trainerbattle_single TRAINER_ACREN_FOREST_RODDY, AcrenForest_Text_RoddyIntro, AcrenForest_Text_RoddyDefeat
# 476 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_Text_RoddyPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_Armin::
# 481 "data/maps/AcrenForest/scripts.pory"
	trainerbattle_single TRAINER_ACREN_FOREST_ARMIN, AcrenForest_Text_ArminIntro, AcrenForest_Text_ArminDefeat
# 482 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_Text_ArminPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_Marisha::
# 487 "data/maps/AcrenForest/scripts.pory"
	trainerbattle_single TRAINER_ACREN_FOREST_MARISHA, AcrenForest_Text_MarishaIntro, AcrenForest_Text_MarishaDefeat
# 488 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_Text_MarishaPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_Lada::
# 493 "data/maps/AcrenForest/scripts.pory"
	trainerbattle_single TRAINER_ACREN_FOREST_LADA, AcrenForest_Text_LadaIntro, AcrenForest_Text_LadaDefeat
# 494 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_Text_LadaPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_Grunt::
# 499 "data/maps/AcrenForest/scripts.pory"
	trainerbattle_single TRAINER_ACREN_FOREST_GRUNT, AcrenForest_Text_GruntIntro, AcrenForest_Text_GruntDefeat
# 500 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_Text_GruntPostBattle, MSGBOX_NPC
	end


AcrenForest_EventScript_SetShrineWeatherAndSong::
# 505 "data/maps/AcrenForest/scripts.pory"
	fadenewbgm MUS_CELEBI
# 506 "data/maps/AcrenForest/scripts.pory"
	setweather WEATHER_SUNNY
# 507 "data/maps/AcrenForest/scripts.pory"
	doweather
# 508 "data/maps/AcrenForest/scripts.pory"
	release
	end


AcrenForest_EventScript_SetDefaultWeatherAndSong::
# 513 "data/maps/AcrenForest/scripts.pory"
	fadenewbgm MUS_ACREN_FOREST_DAY
# 514 "data/maps/AcrenForest/scripts.pory"
	resetweather
# 515 "data/maps/AcrenForest/scripts.pory"
	doweather
# 516 "data/maps/AcrenForest/scripts.pory"
	release
	end


AcrenForest_EventScript_CelebiShrine::
# 521 "data/maps/AcrenForest/scripts.pory"
	msgbox AcrenForest_EventScript_CelebiShrine_Text_0, MSGBOX_SIGN
	end


# 526 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_CameraToGrunts:
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 527 "data/maps/AcrenForest/scripts.pory"
	walk_diag_northwest
# 528 "data/maps/AcrenForest/scripts.pory"
	walk_fast_up
# 528 "data/maps/AcrenForest/scripts.pory"
	walk_fast_up
# 528 "data/maps/AcrenForest/scripts.pory"
	walk_fast_up
# 528 "data/maps/AcrenForest/scripts.pory"
	walk_fast_up
# 528 "data/maps/AcrenForest/scripts.pory"
	walk_fast_up
# 528 "data/maps/AcrenForest/scripts.pory"
	walk_fast_up
	step_end

# 531 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_CameraToPlayer:
# 532 "data/maps/AcrenForest/scripts.pory"
	walk_fast_down
# 532 "data/maps/AcrenForest/scripts.pory"
	walk_fast_down
# 532 "data/maps/AcrenForest/scripts.pory"
	walk_fast_down
# 532 "data/maps/AcrenForest/scripts.pory"
	walk_fast_down
# 532 "data/maps/AcrenForest/scripts.pory"
	walk_fast_down
# 532 "data/maps/AcrenForest/scripts.pory"
	walk_fast_down
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
# 533 "data/maps/AcrenForest/scripts.pory"
	walk_diag_southeast
	step_end

# 536 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_Logger3WalkToSide:
# 537 "data/maps/AcrenForest/scripts.pory"
	walk_left
# 538 "data/maps/AcrenForest/scripts.pory"
	face_down
	step_end

# 541 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_Logger4WalkToSide:
# 542 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 543 "data/maps/AcrenForest/scripts.pory"
	face_down
	step_end

# 546 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_Logger4WalkToSideFromWest:
# 547 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 548 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 549 "data/maps/AcrenForest/scripts.pory"
	face_down
	step_end

# 552 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_PlayerWalkBackwards:
# 553 "data/maps/AcrenForest/scripts.pory"
	lock_facing_direction
# 554 "data/maps/AcrenForest/scripts.pory"
	walk_down
	step_end

# 557 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_Logger3WalkLeft:
# 558 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 559 "data/maps/AcrenForest/scripts.pory"
	walk_left
# 560 "data/maps/AcrenForest/scripts.pory"
	face_down
	step_end

# 563 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_Logger4WalkRight:
# 564 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 565 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 566 "data/maps/AcrenForest/scripts.pory"
	face_down
	step_end

# 569 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_PhyllosLaughterJump:
# 570 "data/maps/AcrenForest/scripts.pory"
	jump_in_place_down
	step_end

# 573 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_PhyllosWalkToShrine:
# 574 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 575 "data/maps/AcrenForest/scripts.pory"
	walk_left
# 576 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 576 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 576 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 577 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 578 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 578 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 578 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 579 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 580 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 581 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 582 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 582 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 582 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 582 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 582 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 583 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 583 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 583 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 583 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 584 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 584 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 584 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 584 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 584 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 584 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 585 "data/maps/AcrenForest/scripts.pory"
	walk_left
# 586 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 586 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 586 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 586 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 587 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 587 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 588 "data/maps/AcrenForest/scripts.pory"
	face_left
	step_end

# 591 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_PlayerWalkToShrine:
# 592 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 592 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 593 "data/maps/AcrenForest/scripts.pory"
	walk_left
# 594 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 594 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 594 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 595 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 596 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 596 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 596 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 597 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 598 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 599 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 600 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 600 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 600 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 600 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 600 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 601 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 601 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 601 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 601 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 602 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 602 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 602 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 602 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 602 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 602 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 603 "data/maps/AcrenForest/scripts.pory"
	walk_left
# 604 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 604 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 604 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 604 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 605 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 606 "data/maps/AcrenForest/scripts.pory"
	face_right
	step_end

# 609 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_PhyllosWalkFromShrine_1:
# 610 "data/maps/AcrenForest/scripts.pory"
	walk_down
# 611 "data/maps/AcrenForest/scripts.pory"
	walk_left
	step_end

# 614 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_PhyllosWalkFromShrine_2:
# 615 "data/maps/AcrenForest/scripts.pory"
	walk_left
# 616 "data/maps/AcrenForest/scripts.pory"
	walk_up
	step_end

# 619 "data/maps/AcrenForest/scripts.pory"
AcrenForest_Movement_PhyllosWalkFromShrine_3:
# 620 "data/maps/AcrenForest/scripts.pory"
	walk_up
# 620 "data/maps/AcrenForest/scripts.pory"
	walk_up
# 620 "data/maps/AcrenForest/scripts.pory"
	walk_up
# 621 "data/maps/AcrenForest/scripts.pory"
	walk_right
# 622 "data/maps/AcrenForest/scripts.pory"
	walk_up
# 622 "data/maps/AcrenForest/scripts.pory"
	walk_up
# 622 "data/maps/AcrenForest/scripts.pory"
	walk_up
# 622 "data/maps/AcrenForest/scripts.pory"
	walk_up
	step_end

AcrenForest_EventScript_PhyllosShrineCutscene_Text_0:
# 76 "data/maps/AcrenForest/scripts.pory"
	.string "Hello {PLAYER}.\n"
	.string "I have something important to\l"
	.string "tell you.\p"
	.string "Follow me if you will.$"

AcrenForest_EventScript_PhyllosShrineCutscene_Text_1:
# 87 "data/maps/AcrenForest/scripts.pory"
	.string "As you may or may not know\n"
	.string "EURUS is divided in districts.\p"
	.string "These districts each have a\n"
	.string "dedicated shrine keeper.\p"
	.string "Usually the shrine keepers are\n"
	.string "important people.\p"
	.string "Often Majors, TOURNAMENT MASTERS,\n"
	.string "or both.\p"
	.string "Basically, every shrine is meant\n"
	.string "to honor a certain LEGENDARY\l"
	.string "POKéMON.\p"
	.string "As long as we worship these\n"
	.string "POKéMON, they will remain docile.\p"
	.string "As long as they stay docile, our\n"
	.string "world will be in balance.\p"
	.string "I am the shrine keeper of\n"
	.string "FIRWEALD CITY and its area.$"

AcrenForest_EventScript_PhyllosShrineCutscene_Text_2:
# 114 "data/maps/AcrenForest/scripts.pory"
	.string "This shrine you see here is\n"
	.string "home to the LEGENDARY\l"
	.string "POKéMON CELEBI.\p"
	.string "Also known as the\n"
	.string "GUARDIAN of the FOREST.$"

AcrenForest_EventScript_PhyllosShrineCutscene_Text_3:
# 126 "data/maps/AcrenForest/scripts.pory"
	.string "Anyways, I would like to\n"
	.string "ask you for a favor…\p"
	.string "Seeing as we had that run in\n"
	.string "those strange men in the FOREST\l"
	.string "the other day.\p"
	.string "I was wondering if you could\n"
	.string "check in with my colleague at\l"
	.string "the shrine to GROUDON.\p"
	.string "I am worried a storm might be\n"
	.string "brewing…\p"
	.string "GROUDON's shrine is in the\n"
	.string "mountainous area of the region\l"
	.string "across the sea."
	.string "I cannot thank you enough, you\n"
	.string "are clearly a skilled TRAINER.\p"
	.string "And I'm not the one to take\n"
	.string "this journey on at my age…\p"
	.string "Har har har!$"

AcrenForest_EventScript_PhyllosShrineCutscene_Text_4:
# 153 "data/maps/AcrenForest/scripts.pory"
	.string "Here, take this.$"

AcrenForest_EventScript_PhyllosShrineCutscene_Text_5:
# 158 "data/maps/AcrenForest/scripts.pory"
	.string "If you need me, I'll be at\n"
	.string "the TOURNAMENT HALL.\p"
	.string "Thank you once again, our battle\n"
	.string "really sparked joy!$"

AcrenForest_EventScript_LoggersCutscene_Text_0:
# 192 "data/maps/AcrenForest/scripts.pory"
	.string "Hello there {PLAYER}!\p"
	.string "I heard from the boss we need to deal\n"
	.string "with those TEAM AIRLOCK GRUNTS\l"
	.string "back there…$"

AcrenForest_EventScript_LoggersCutscene_Text_1:
# 201 "data/maps/AcrenForest/scripts.pory"
	.string "Look, those are the GRUNTS we're\n"
	.string "talking about…$"

AcrenForest_EventScript_LoggersCutscene_Text_2:
# 208 "data/maps/AcrenForest/scripts.pory"
	.string "I just need to check if you're\n"
	.string "official POKéMON TRAINER.\p"
	.string "May I see your POKéDEX please?$"

AcrenForest_EventScript_LoggersCutscene_Text_3:
# 213 "data/maps/AcrenForest/scripts.pory"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …$"

AcrenForest_EventScript_LoggersCutscene_Text_4:
# 217 "data/maps/AcrenForest/scripts.pory"
	.string "Hmmm…\n"
	.string "You don't seem to have a POKéDEX\l"
	.string "at all…\p"
	.string "You need to have a POKéDEX if you're\n"
	.string "an official POKéMON TRAINER.\p"
	.string "Go speak to the PROFESSOR about this.\p"
	.string "We'll handle it from here.$"

AcrenForest_EventScript_Logger1_Text_0:
# 233 "data/maps/AcrenForest/scripts.pory"
	.string "Hey kid, we need some help from\n"
	.string "a professional here.\p"
	.string "Ask the LOGGERS at the exit of\n"
	.string "the forest for help…$"

AcrenForest_EventScript_Logger1_Text_1:
# 241 "data/maps/AcrenForest/scripts.pory"
	.string "You definitely look like a strong\n"
	.string "TRAINER, kid.$"

AcrenForest_EventScript_Logger1_Text_2:
# 245 "data/maps/AcrenForest/scripts.pory"
	.string "Go speak to the PROFESSOR about this.\n"
	.string "We'll handle it from here.$"

AcrenForest_EventScript_Logger2_Text_0:
# 260 "data/maps/AcrenForest/scripts.pory"
	.string "Show those thugs, kiddo.$"

AcrenForest_EventScript_Logger2_Text_1:
# 263 "data/maps/AcrenForest/scripts.pory"
	.string "We'll handle it from here kid.$"

AcrenForest_EventScript_Logger3And4_Text_0:
# 270 "data/maps/AcrenForest/scripts.pory"
	.string "You need to get help from FIRWEALD CITY\n"
	.string "Try to find PHYLLOS.\l"
	.string "He's the TOURNAMENT MASTER of the city.$"

AcrenForest_EventScript_Logger3And4_Text_1:
# 284 "data/maps/AcrenForest/scripts.pory"
	.string "We'll be waiting right here.$"

AcrenForest_EventScript_Logger3And4_Text_2:
# 287 "data/maps/AcrenForest/scripts.pory"
	.string "Good work kid, PHYLLOS arrived\n"
	.string "a while back.\p"
	.string "Head deeper into the forest to find him.$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_0:
# 301 "data/maps/AcrenForest/scripts.pory"
	.string "Get out of our way kid!$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_1:
# 304 "data/maps/AcrenForest/scripts.pory"
	.string "Hey, you shouldn't be wandering\n"
	.string "around here!\p"
	.string "This isn't your business!$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_2:
# 309 "data/maps/AcrenForest/scripts.pory"
	.string "What's a kid like you doing here?!$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_3:
# 312 "data/maps/AcrenForest/scripts.pory"
	.string "You'll never get a hold of the\n"
	.string "mightly TEAM AIRLOCK!$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_4:
# 316 "data/maps/AcrenForest/scripts.pory"
	.string "Hehehe…\n"
	.string "We're just doing business here kiddo.$"

AcrenForest_EventScript_TeamAirlockGrunt_Text_5:
# 320 "data/maps/AcrenForest/scripts.pory"
	.string "You don't know us kid!\n"
	.string "Get out!$"

AcrenForest_EventScript_DescribeIllegalCamp_Text_0:
# 340 "data/maps/AcrenForest/scripts.pory"
	.string "Hi again {PLAYER}.\n"
	.string "You've managed to find us.\l"
	.string "Now let's get to business shall we.$"

AcrenForest_EventScript_DescribeIllegalCamp_Text_1:
# 349 "data/maps/AcrenForest/scripts.pory"
	.string "Har har har!\p"
	.string "Well then…$"

AcrenForest_EventScript_DescribeIllegalCamp_Text_2:
# 356 "data/maps/AcrenForest/scripts.pory"
	.string "This is the cabin we're looking for.\n"
	.string "It's guarded by some GRUNTS, but\l"
	.string "we'll deal with those.\p"
	.string "Har har har!$"

AcrenForest_EventScript_DescribeIllegalCamp_Text_3:
# 365 "data/maps/AcrenForest/scripts.pory"
	.string "What are you waiting for kiddo?\p"
	.string "They should know you're coming.$"

AcrenForest_EventScript_WarnBoss_Text_0:
# 380 "data/maps/AcrenForest/scripts.pory"
	.string "Oh no!\n"
	.string "How did you get here?!\p"
	.string "You shouldn't be able to get here!\n"
	.string "Didn't the GRUNTS keep you away?\p"
	.string "Hrmph.\n"
	.string "Fine then, the BOSS will make sure to\l"
	.string "get you out! Ha ha ha ha!$"

AcrenForest_EventScript_TrainerTipsSurf_Text_0:
# 407 "data/maps/AcrenForest/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Using HM05 SURF, you can cross\n"
	.string "any body of water!$"

AcrenForest_EventScript_TrainerTipsHeldItems_Text_0:
# 414 "data/maps/AcrenForest/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "POKéMON with the PICKUP ability\n"
	.string "can find items in battle!\p"
	.string "When you catch a POKéMON with this\n"
	.string "ability, it could be holding on to\l"
	.string "an item.\p"
	.string "Always check if the POKéMON you\n"
	.string "caught has an item!$"

AcrenForest_EventScript_Boy_Text_0:
# 429 "data/maps/AcrenForest/scripts.pory"
	.string "Did you know that jogging\n"
	.string "burn 446 calories an hour?$"

AcrenForest_EventScript_Boy_Text_1:
# 434 "data/maps/AcrenForest/scripts.pory"
	.string "Oh did you now?$"

AcrenForest_EventScript_Boy_Text_2:
# 437 "data/maps/AcrenForest/scripts.pory"
	.string "Well you look like you could\n"
	.string "use some excercise yourself!$"

AcrenForest_EventScript_BugCatcher_Text_0:
# 446 "data/maps/AcrenForest/scripts.pory"
	.string "You can harvest berries from\n"
	.string "loamy soul and replant them.\p"
	.string "That way you'll never have to\n"
	.string "run out of berries!$"

AcrenForest_EventScript_FlowerShopSign_Text_0:
# 464 "data/maps/AcrenForest/scripts.pory"
	.string "ELDER BERRY's GREENERY SHOP$"

AcrenForest_EventScript_CelebiShrine_Text_0:
# 521 "data/maps/AcrenForest/scripts.pory"
	.string "You feel a strange presence\n"
	.string "around you…$"

AcrenForest_Text_FrederickIntro::
# 625 "data/maps/AcrenForest/scripts.pory"
	.string "My RATTATA and I will become champions\p"
	.string "of the EURUS REGION!$"

AcrenForest_Text_FrederickDefeat::
# 630 "data/maps/AcrenForest/scripts.pory"
	.string "Why would you crush my\p"
	.string "hopes and dreams?!$"

AcrenForest_Text_FrederickPostBattle::
# 635 "data/maps/AcrenForest/scripts.pory"
	.string "See you at the EURUS LEAGUE, loser!$"

AcrenForest_Text_RoddyIntro::
# 639 "data/maps/AcrenForest/scripts.pory"
	.string "I just pulled my worm out the box.$"

AcrenForest_Text_RoddyDefeat::
# 643 "data/maps/AcrenForest/scripts.pory"
	.string "Eeee, eerrrr…$"

AcrenForest_Text_RoddyPostBattle::
# 647 "data/maps/AcrenForest/scripts.pory"
	.string "Wait until I drop my next album…$"

AcrenForest_Text_ArminIntro::
# 651 "data/maps/AcrenForest/scripts.pory"
	.string "I have a good friend called EREN.\n"
	.string "He lives in FIRWEALD CITY.$"

AcrenForest_Text_ArminDefeat::
# 656 "data/maps/AcrenForest/scripts.pory"
	.string "Wow!\p"
	.string "You're a titan in battle!$"

AcrenForest_Text_ArminPostBattle::
# 661 "data/maps/AcrenForest/scripts.pory"
	.string "Go visit my friend in\n"
	.string "FIRWEALD CITY once.$"

AcrenForest_Text_MarishaIntro::
# 666 "data/maps/AcrenForest/scripts.pory"
	.string "My parents came here from a country\n"
	.string "far, far away.$"

AcrenForest_Text_MarishaDefeat::
# 671 "data/maps/AcrenForest/scripts.pory"
	.string "You won't beat my parents in a battle!$"

AcrenForest_Text_MarishaPostBattle::
# 675 "data/maps/AcrenForest/scripts.pory"
	.string "The country my parents are from\n"
	.string "is very dangerous and cold.$"

AcrenForest_Text_LadaIntro::
# 680 "data/maps/AcrenForest/scripts.pory"
	.string "My parents named me after a car\n"
	.string "'cause I'm a machine in battle!$"

AcrenForest_Text_LadaDefeat::
# 685 "data/maps/AcrenForest/scripts.pory"
	.string "Oh no! I choked my engine!$"

AcrenForest_Text_LadaPostBattle::
# 689 "data/maps/AcrenForest/scripts.pory"
	.string "I guess I ran out of gas…$"

AcrenForest_Text_GruntIntro::
# 693 "data/maps/AcrenForest/scripts.pory"
	.string "How did you get here?$"

AcrenForest_Text_GruntDefeat::
# 697 "data/maps/AcrenForest/scripts.pory"
	.string "The others will take\n"
	.string "care of you!$"

AcrenForest_Text_GruntPostBattle::
# 702 "data/maps/AcrenForest/scripts.pory"
	.string "The BOSS will get you kicked\n"
	.string "out of here, no problem!$"
