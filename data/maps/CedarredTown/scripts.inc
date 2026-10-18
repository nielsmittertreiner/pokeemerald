CedarredTown_MapScripts::
# 4 "data/maps/CedarredTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CedarredTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

CedarredTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/CedarredTown/scripts.pory"
	setrespawn HEAL_LOCATION_CEDARRED_TOWN
# 6 "data/maps/CedarredTown/scripts.pory"
	setflag FLAG_VISITED_CEDARRED_TOWN
# 7 "data/maps/CedarredTown/scripts.pory"
	compare VAR_SUNSET_TOWN_STATE, 3
	goto_if_eq CedarredTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

CedarredTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 9 "data/maps/CedarredTown/scripts.pory"
	setvar VAR_SUNSET_TOWN_FOLLOWER_STATE, 3
	return


CedarredTown_EventScript_TownSign::
# 15 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


CedarredTown_EventScript_LoggersCabinSign::
# 21 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_LoggersCabinSign_Text_0, MSGBOX_SIGN
	end


CedarredTown_EventScript_AcrenForestSign::
# 27 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_AcrenForestSign_Text_0, MSGBOX_SIGN
	end


CedarredTown_EventScript_LoreMan::
# 32 "data/maps/CedarredTown/scripts.pory"
	lock
# 33 "data/maps/CedarredTown/scripts.pory"
	faceplayer
# 34 "data/maps/CedarredTown/scripts.pory"
	loadspeechtail FALSE, 2
# 35 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_LoreMan_Text_0, MSGBOX_YESNO
# 37 "data/maps/CedarredTown/scripts.pory"
	destroyspeechtail
# 38 "data/maps/CedarredTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq CedarredTown_EventScript_LoreMan_1
# 47 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_LoreMan_Text_2, MSGBOX_NPC
	end

CedarredTown_EventScript_LoreMan_1:
# 40 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_LoreMan_Text_1, MSGBOX_NPC
	end


CedarredTown_EventScript_MartEmployee::
# 66 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_MartEmployee_Text_0, MSGBOX_NPC
	end


CedarredTown_EventScript_Boy::
# 72 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_Boy_Text_0, MSGBOX_NPC
	end


CedarredTown_EventScript_ShowLoggersCabin::
# 79 "data/maps/CedarredTown/scripts.pory"
	lock
# 80 "data/maps/CedarredTown/scripts.pory"
	playse SE_PIN
# 81 "data/maps/CedarredTown/scripts.pory"
	applymovement LOCALID_FOLLOWER, Common_Movement_ExclamationMark
# 82 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
# 83 "data/maps/CedarredTown/scripts.pory"
	facefollower
# 84 "data/maps/CedarredTown/scripts.pory"
	loadspeechtail FALSE, LOCALID_FOLLOWER
# 85 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_ShowLoggersCabin_Text_0
# 89 "data/maps/CedarredTown/scripts.pory"
	destroyspeechtail
# 90 "data/maps/CedarredTown/scripts.pory"
	closemessage
# 91 "data/maps/CedarredTown/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 92 "data/maps/CedarredTown/scripts.pory"
	special SpawnCameraObject
# 93 "data/maps/CedarredTown/scripts.pory"
	switch VAR_TEMP_1
# 95 "data/maps/CedarredTown/scripts.pory"
	case 15, CedarredTown_EventScript_ShowLoggersCabin_3
# 98 "data/maps/CedarredTown/scripts.pory"
	case 16, CedarredTown_EventScript_ShowLoggersCabin_4
# 101 "data/maps/CedarredTown/scripts.pory"
	case 17, CedarredTown_EventScript_ShowLoggersCabin_5
CedarredTown_EventScript_ShowLoggersCabin_1:
# 105 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_ShowLoggersCabin_Text_1
# 107 "data/maps/CedarredTown/scripts.pory"
	closemessage
# 108 "data/maps/CedarredTown/scripts.pory"
	switch VAR_TEMP_1
# 110 "data/maps/CedarredTown/scripts.pory"
	case 15, CedarredTown_EventScript_ShowLoggersCabin_8
# 113 "data/maps/CedarredTown/scripts.pory"
	case 16, CedarredTown_EventScript_ShowLoggersCabin_9
# 116 "data/maps/CedarredTown/scripts.pory"
	case 17, CedarredTown_EventScript_ShowLoggersCabin_10
CedarredTown_EventScript_ShowLoggersCabin_6:
# 120 "data/maps/CedarredTown/scripts.pory"
	special RemoveCameraObject
# 121 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_ShowLoggersCabin_Text_2, MSGBOX_NPC
# 122 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
# 123 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
# 124 "data/maps/CedarredTown/scripts.pory"
	setvar VAR_CEDARRED_TOWN_STATE, 1
# 125 "data/maps/CedarredTown/scripts.pory"
	release
	end

CedarredTown_EventScript_ShowLoggersCabin_3:
# 96 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToCabinOne
# 97 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_1

CedarredTown_EventScript_ShowLoggersCabin_4:
# 99 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToCabinTwo
# 100 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_1

CedarredTown_EventScript_ShowLoggersCabin_5:
# 102 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToCabinThree
# 103 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_1

CedarredTown_EventScript_ShowLoggersCabin_8:
# 111 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToPlayerOne
# 112 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_6

CedarredTown_EventScript_ShowLoggersCabin_9:
# 114 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToPlayerTwo
# 115 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_6

CedarredTown_EventScript_ShowLoggersCabin_10:
# 117 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, CedarredTown_Movement_CameraToPlayerThree
# 118 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
	goto CedarredTown_EventScript_ShowLoggersCabin_6


CedarredTown_EventScript_EnterLoggersCabin::
# 130 "data/maps/CedarredTown/scripts.pory"
	lock
# 131 "data/maps/CedarredTown/scripts.pory"
	playse SE_PIN
# 132 "data/maps/CedarredTown/scripts.pory"
	applymovement LOCALID_FOLLOWER, Common_Movement_ExclamationMark
# 133 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
# 134 "data/maps/CedarredTown/scripts.pory"
	facefollower
# 135 "data/maps/CedarredTown/scripts.pory"
	loadspeechtail FALSE, LOCALID_FOLLOWER
# 136 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_EnterLoggersCabin_Text_0
# 140 "data/maps/CedarredTown/scripts.pory"
	destroyspeechtail
# 141 "data/maps/CedarredTown/scripts.pory"
	closemessage
# 142 "data/maps/CedarredTown/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 143 "data/maps/CedarredTown/scripts.pory"
	switch VAR_TEMP_0
# 145 "data/maps/CedarredTown/scripts.pory"
	case 14, CedarredTown_EventScript_EnterLoggersCabin_3
# 148 "data/maps/CedarredTown/scripts.pory"
	case 15, CedarredTown_EventScript_EnterLoggersCabin_4
# 151 "data/maps/CedarredTown/scripts.pory"
	case 16, CedarredTown_EventScript_EnterLoggersCabin_5
# 154 "data/maps/CedarredTown/scripts.pory"
	case 17, CedarredTown_EventScript_EnterLoggersCabin_6
CedarredTown_EventScript_EnterLoggersCabin_1:
# 158 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
# 159 "data/maps/CedarredTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 160 "data/maps/CedarredTown/scripts.pory"
	opendoor 20, 18
# 161 "data/maps/CedarredTown/scripts.pory"
	waitdooranim
# 162 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_PlayerWalkToDoor
# 163 "data/maps/CedarredTown/scripts.pory"
	applymovement LOCALID_FOLLOWER, CedarredTown_Movement_ConiferWalkToDoor
# 164 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
# 165 "data/maps/CedarredTown/scripts.pory"
	closedoor 20, 18
# 166 "data/maps/CedarredTown/scripts.pory"
	waitdooranim
# 167 "data/maps/CedarredTown/scripts.pory"
	setvar VAR_CEDARRED_TOWN_STATE, 2
# 168 "data/maps/CedarredTown/scripts.pory"
	warp MAP_CEDARRED_TOWN_LOGGERS_CABIN, 0, 6, 8
# 169 "data/maps/CedarredTown/scripts.pory"
	waitstate
	end

CedarredTown_EventScript_EnterLoggersCabin_3:
# 146 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_PlayerWalkToCabinOne
# 147 "data/maps/CedarredTown/scripts.pory"
	applymovement LOCALID_FOLLOWER, CedarredTown_Movement_ConiferWalkToCabinOne
	goto CedarredTown_EventScript_EnterLoggersCabin_1

CedarredTown_EventScript_EnterLoggersCabin_4:
# 149 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_PlayerWalkToCabinTwo
# 150 "data/maps/CedarredTown/scripts.pory"
	applymovement LOCALID_FOLLOWER, CedarredTown_Movement_ConiferWalkToCabinTwo
	goto CedarredTown_EventScript_EnterLoggersCabin_1

CedarredTown_EventScript_EnterLoggersCabin_5:
# 152 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_PlayerWalkToCabinThree
# 153 "data/maps/CedarredTown/scripts.pory"
	applymovement LOCALID_FOLLOWER, CedarredTown_Movement_ConiferWalkToCabinThree
	goto CedarredTown_EventScript_EnterLoggersCabin_1

CedarredTown_EventScript_EnterLoggersCabin_6:
# 155 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_PlayerWalkToCabinFour
# 156 "data/maps/CedarredTown/scripts.pory"
	applymovement LOCALID_FOLLOWER, CedarredTown_Movement_ConiferWalkToCabinFour
	goto CedarredTown_EventScript_EnterLoggersCabin_1


CedarredTown_EventScript_PreventWander::
# 174 "data/maps/CedarredTown/scripts.pory"
	lock
# 175 "data/maps/CedarredTown/scripts.pory"
	playse SE_PIN
# 176 "data/maps/CedarredTown/scripts.pory"
	applymovement LOCALID_FOLLOWER, Common_Movement_ExclamationMark
# 177 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
# 178 "data/maps/CedarredTown/scripts.pory"
	facefollower
# 179 "data/maps/CedarredTown/scripts.pory"
	loadspeechtail FALSE, LOCALID_FOLLOWER
# 180 "data/maps/CedarredTown/scripts.pory"
	msgbox CedarredTown_EventScript_PreventWander_Text_0
# 183 "data/maps/CedarredTown/scripts.pory"
	destroyspeechtail
# 184 "data/maps/CedarredTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CedarredTown_Movement_WalkDown
# 185 "data/maps/CedarredTown/scripts.pory"
	waitmovement 0
# 186 "data/maps/CedarredTown/scripts.pory"
	turnobject LOCALID_FOLLOWER, DIR_SOUTH
# 187 "data/maps/CedarredTown/scripts.pory"
	release
	end


# 191 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_CameraToCabinOne:
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 193 "data/maps/CedarredTown/scripts.pory"
	walk_fast_down
# 193 "data/maps/CedarredTown/scripts.pory"
	walk_fast_down
# 193 "data/maps/CedarredTown/scripts.pory"
	walk_fast_down
	step_end

# 196 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_CameraToCabinTwo:
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 198 "data/maps/CedarredTown/scripts.pory"
	walk_fast_down
# 198 "data/maps/CedarredTown/scripts.pory"
	walk_fast_down
	step_end

# 201 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_CameraToCabinThree:
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/CedarredTown/scripts.pory"
	walk_fast_right
# 203 "data/maps/CedarredTown/scripts.pory"
	walk_fast_down
	step_end

# 206 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_CameraToPlayerOne:
# 207 "data/maps/CedarredTown/scripts.pory"
	walk_fast_up
# 207 "data/maps/CedarredTown/scripts.pory"
	walk_fast_up
# 207 "data/maps/CedarredTown/scripts.pory"
	walk_fast_up
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 208 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
	step_end

# 211 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_CameraToPlayerTwo:
# 212 "data/maps/CedarredTown/scripts.pory"
	walk_fast_up
# 212 "data/maps/CedarredTown/scripts.pory"
	walk_fast_up
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
	step_end

# 216 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_CameraToPlayerThree:
# 217 "data/maps/CedarredTown/scripts.pory"
	walk_fast_up
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
# 218 "data/maps/CedarredTown/scripts.pory"
	walk_fast_left
	step_end

# 221 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_WalkDown:
# 222 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 222 "data/maps/CedarredTown/scripts.pory"
	walk_down
	step_end

# 225 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_PlayerWalkToCabinOne:
# 226 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 227 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 227 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 227 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 228 "data/maps/CedarredTown/scripts.pory"
	walk_diag_northeast
# 229 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 229 "data/maps/CedarredTown/scripts.pory"
	walk_right
	step_end

# 232 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_PlayerWalkToCabinTwo:
# 233 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 234 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 234 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 235 "data/maps/CedarredTown/scripts.pory"
	walk_diag_northeast
# 236 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 236 "data/maps/CedarredTown/scripts.pory"
	walk_right
	step_end

# 239 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_PlayerWalkToCabinThree:
# 240 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 241 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 242 "data/maps/CedarredTown/scripts.pory"
	walk_diag_northeast
# 243 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 243 "data/maps/CedarredTown/scripts.pory"
	walk_right
	step_end

# 246 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_PlayerWalkToCabinFour:
# 247 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 248 "data/maps/CedarredTown/scripts.pory"
	walk_diag_northeast
# 249 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 249 "data/maps/CedarredTown/scripts.pory"
	walk_right
	step_end

# 252 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_ConiferWalkToCabinOne:
# 253 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 253 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 254 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 254 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 254 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 255 "data/maps/CedarredTown/scripts.pory"
	walk_diag_northeast
# 256 "data/maps/CedarredTown/scripts.pory"
	walk_right
	step_end

# 259 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_ConiferWalkToCabinTwo:
# 260 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 260 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 261 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 261 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 262 "data/maps/CedarredTown/scripts.pory"
	walk_diag_northeast
# 263 "data/maps/CedarredTown/scripts.pory"
	walk_right
	step_end

# 266 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_ConiferWalkToCabinThree:
# 267 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 267 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 268 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 269 "data/maps/CedarredTown/scripts.pory"
	walk_diag_northeast
# 270 "data/maps/CedarredTown/scripts.pory"
	walk_right
	step_end

# 273 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_ConiferWalkToCabinFour:
# 274 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 274 "data/maps/CedarredTown/scripts.pory"
	walk_down
# 275 "data/maps/CedarredTown/scripts.pory"
	walk_diag_northeast
# 276 "data/maps/CedarredTown/scripts.pory"
	walk_right
	step_end

# 279 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_PlayerWalkToDoor:
# 280 "data/maps/CedarredTown/scripts.pory"
	walk_up
# 281 "data/maps/CedarredTown/scripts.pory"
	set_invisible
	step_end

# 284 "data/maps/CedarredTown/scripts.pory"
CedarredTown_Movement_ConiferWalkToDoor:
# 285 "data/maps/CedarredTown/scripts.pory"
	walk_right
# 286 "data/maps/CedarredTown/scripts.pory"
	walk_up
# 287 "data/maps/CedarredTown/scripts.pory"
	set_invisible
	step_end

CedarredTown_EventScript_TownSign_Text_0:
# 15 "data/maps/CedarredTown/scripts.pory"
	.string "CEDARRED TOWN\n"
	.string "“World renowned for its logs!”$"

CedarredTown_EventScript_LoggersCabinSign_Text_0:
# 21 "data/maps/CedarredTown/scripts.pory"
	.string "CEDARRED's LOGGERS CABIN\n"
	.string "“Where CEDARRED's best LOGGERS reside.”$"

CedarredTown_EventScript_AcrenForestSign_Text_0:
# 27 "data/maps/CedarredTown/scripts.pory"
	.string "{UP_ARROW} ACREN FOREST$"

CedarredTown_EventScript_LoreMan_Text_0:
# 35 "data/maps/CedarredTown/scripts.pory"
	.string "Did you know this part of the EURUS\n"
	.string "region is famous for two things?$"

CedarredTown_EventScript_LoreMan_Text_1:
# 40 "data/maps/CedarredTown/scripts.pory"
	.string "Fantastic!\p"
	.string "It seems that you have followed your\n"
	.string "history lessons well, young man.$"

CedarredTown_EventScript_LoreMan_Text_2:
# 47 "data/maps/CedarredTown/scripts.pory"
	.string "Well then, here goes..\p"
	.string "This part of the EURUS region is well\n"
	.string "known for its logging industry and\l"
	.string "its vast forests you'll find.\p"
	.string "In ancient times, the people from here\n"
	.string "have learned to live alongside the\l"
	.string "POKéMON of the ACREN FOREST, and even\l"
	.string "worship its fabled keeper, CELEBI.\p"
	.string "Nowadays the people live, work and\n"
	.string "battle together as these towns\l"
	.string "produce some of the greatest GRASS\l"
	.string "TRAINERS the world has ever seen!\p"
	.string "Even the famous TRAINER, PHYLLOS, is\n"
	.string "from here…$"

CedarredTown_EventScript_MartEmployee_Text_0:
# 66 "data/maps/CedarredTown/scripts.pory"
	.string "Check out all of our products\n"
	.string "in the POKéMON MART of CEDARRED TOWN!$"

CedarredTown_EventScript_Boy_Text_0:
# 72 "data/maps/CedarredTown/scripts.pory"
	.string "When I grow up, I want to be\n"
	.string "stronger than the strongest LOGGERS\l"
	.string "from CEDARRED TOWN!$"

CedarredTown_EventScript_ShowLoggersCabin_Text_0:
# 85 "data/maps/CedarredTown/scripts.pory"
	.string "Ah, we're here!\n"
	.string "This is CEDARRED TOWN\p"
	.string "The LOGGERS CABIN should be at the\n"
	.string "far EAST of town.$"

CedarredTown_EventScript_ShowLoggersCabin_Text_1:
# 105 "data/maps/CedarredTown/scripts.pory"
	.string "Look, there it is!\n"
	.string "CEDARRED TOWN's LOGGERS CABIN.$"

CedarredTown_EventScript_ShowLoggersCabin_Text_2:
# 121 "data/maps/CedarredTown/scripts.pory"
	.string "Let's go there right now, {PLAYER}!$"

CedarredTown_EventScript_EnterLoggersCabin_Text_0:
# 136 "data/maps/CedarredTown/scripts.pory"
	.string "Remember {PLAYER}, we're here to help\n"
	.string "the LOGGERS with a problem in\l"
	.string "the ACREN FOREST.\p"
	.string "Let's head in and see what happened.$"

CedarredTown_EventScript_PreventWander_Text_0:
# 180 "data/maps/CedarredTown/scripts.pory"
	.string "We should be going to the LOGGERS\n"
	.string "CABIN, {PLAYER}.\p"
	.string "Let's move!$"
