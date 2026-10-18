MurenaCity_Shipyard_MapScripts::
# 13 "data/maps/MurenaCity_Shipyard/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 7 "data/maps/MurenaCity_Shipyard/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 10 "data/maps/MurenaCity_Shipyard/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 14 "data/maps/MurenaCity_Shipyard/scripts.pory"
	setrespawn HEAL_LOCATION_MURENA_CITY
# 15 "data/maps/MurenaCity_Shipyard/scripts.pory"
	call FishermanFerry_EventScript_UpdateFerryLocation
	return

MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 8 "data/maps/MurenaCity_Shipyard/scripts.pory"
	map_script_2 VAR_FISHERMAN_FERRY_STATE, 3, MurenaCity_Shipyard_EventScript_SetUpObjects
	.2byte 0

MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/MurenaCity_Shipyard/scripts.pory"
	map_script_2 VAR_FISHERMAN_FERRY_STATE, 4, MurenaCity_Shipyard_EventScript_FinishSailToMurena
	.2byte 0


MurenaCity_Shipyard_EventScript_SetUpObjects::
# 20 "data/maps/MurenaCity_Shipyard/scripts.pory"
	setvar VAR_FISHERMAN_FERRY_STATE, 4
# 21 "data/maps/MurenaCity_Shipyard/scripts.pory"
	clearflag FLAG_HIDE_MURENA_CITY_SHIPYARD_FISHERMAN
# 22 "data/maps/MurenaCity_Shipyard/scripts.pory"
	clearflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
# 23 "data/maps/MurenaCity_Shipyard/scripts.pory"
	clearflag FLAG_HIDE_MURENA_CITY_BOAT
# 24 "data/maps/MurenaCity_Shipyard/scripts.pory"
	addobject 2
# 25 "data/maps/MurenaCity_Shipyard/scripts.pory"
	addobject 1
# 26 "data/maps/MurenaCity_Shipyard/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_MURENA_CITY_SHIPYARD
# 27 "data/maps/MurenaCity_Shipyard/scripts.pory"
	turnobject 2, DIR_SOUTH
# 28 "data/maps/MurenaCity_Shipyard/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


MurenaCity_Shipyard_EventScript_FinishSailToMurena::
# 33 "data/maps/MurenaCity_Shipyard/scripts.pory"
	setvar VAR_FISHERMAN_FERRY_STATE, 0
# 34 "data/maps/MurenaCity_Shipyard/scripts.pory"
	loadspeechtail FALSE, 2
# 35 "data/maps/MurenaCity_Shipyard/scripts.pory"
	msgbox MurenaCity_Shipyard_EventScript_FinishSailToMurena_Text_0
# 37 "data/maps/MurenaCity_Shipyard/scripts.pory"
	destroyspeechtail
# 38 "data/maps/MurenaCity_Shipyard/scripts.pory"
	closemessage
# 39 "data/maps/MurenaCity_Shipyard/scripts.pory"
	release
	end


MurenaCity_Shipyard_EventScript_Fisherman::
# 44 "data/maps/MurenaCity_Shipyard/scripts.pory"
	lock
# 45 "data/maps/MurenaCity_Shipyard/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 46 "data/maps/MurenaCity_Shipyard/scripts.pory"
	compare VAR_TEMP_0, 9
	goto_if_eq MurenaCity_Shipyard_EventScript_Fisherman_2
MurenaCity_Shipyard_EventScript_Fisherman_1:
# 50 "data/maps/MurenaCity_Shipyard/scripts.pory"
	loadspeechtail FALSE, 2
# 51 "data/maps/MurenaCity_Shipyard/scripts.pory"
	msgbox MurenaCity_Shipyard_EventScript_Fisherman_Text_0, MSGBOX_YESNO
# 54 "data/maps/MurenaCity_Shipyard/scripts.pory"
	destroyspeechtail
# 55 "data/maps/MurenaCity_Shipyard/scripts.pory"
	closemessage
# 56 "data/maps/MurenaCity_Shipyard/scripts.pory"
	switch VAR_RESULT
# 57 "data/maps/MurenaCity_Shipyard/scripts.pory"
	case YES, MurenaCity_Shipyard_EventScript_Fisherman_5
# 64 "data/maps/MurenaCity_Shipyard/scripts.pory"
	case NO, MurenaCity_Shipyard_EventScript_Fisherman_6
# 66 "data/maps/MurenaCity_Shipyard/scripts.pory"
	case MULTI_B_PRESSED, MurenaCity_Shipyard_EventScript_Fisherman_7
	return

MurenaCity_Shipyard_EventScript_Fisherman_2:
# 47 "data/maps/MurenaCity_Shipyard/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MurenaCity_Shipyard_Movement_PlayerWalkToFisherman
# 48 "data/maps/MurenaCity_Shipyard/scripts.pory"
	waitmovement 0
	goto MurenaCity_Shipyard_EventScript_Fisherman_1

MurenaCity_Shipyard_EventScript_Fisherman_5:
# 58 "data/maps/MurenaCity_Shipyard/scripts.pory"
	loadspeechtail FALSE, 2
# 59 "data/maps/MurenaCity_Shipyard/scripts.pory"
	msgbox MurenaCity_Shipyard_EventScript_Fisherman_Text_1
# 61 "data/maps/MurenaCity_Shipyard/scripts.pory"
	destroyspeechtail
# 62 "data/maps/MurenaCity_Shipyard/scripts.pory"
	closemessage
# 63 "data/maps/MurenaCity_Shipyard/scripts.pory"
	goto MurenaCity_Shipyard_EventScript_SailToLitorTown
	return

MurenaCity_Shipyard_EventScript_Fisherman_6:
# 65 "data/maps/MurenaCity_Shipyard/scripts.pory"
	goto MurenaCity_Shipyard_EventScript_CancelFerrySelect
	return

MurenaCity_Shipyard_EventScript_Fisherman_7:
# 67 "data/maps/MurenaCity_Shipyard/scripts.pory"
	goto MurenaCity_Shipyard_EventScript_CancelFerrySelect
	return


MurenaCity_Shipyard_EventScript_CancelFerrySelect::
# 72 "data/maps/MurenaCity_Shipyard/scripts.pory"
	loadspeechtail FALSE, 2
# 73 "data/maps/MurenaCity_Shipyard/scripts.pory"
	msgbox MurenaCity_Shipyard_EventScript_CancelFerrySelect_Text_0
# 75 "data/maps/MurenaCity_Shipyard/scripts.pory"
	destroyspeechtail
# 76 "data/maps/MurenaCity_Shipyard/scripts.pory"
	closemessage
# 77 "data/maps/MurenaCity_Shipyard/scripts.pory"
	release
	end


MurenaCity_Shipyard_EventScript_SailToLitorTown::
# 82 "data/maps/MurenaCity_Shipyard/scripts.pory"
	call FishermanFerry_EventScript_BackupFerryLocation
# 83 "data/maps/MurenaCity_Shipyard/scripts.pory"
	setobjectsubpriority 2, MAP_MURENA_CITY_SHIPYARD, 0
# 84 "data/maps/MurenaCity_Shipyard/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_MURENA_CITY_SHIPYARD, 0
# 85 "data/maps/MurenaCity_Shipyard/scripts.pory"
	applymovement 2, MurenaCity_Shipyard_Movement_FishermanBoardBoat
# 86 "data/maps/MurenaCity_Shipyard/scripts.pory"
	waitmovement 0
# 87 "data/maps/MurenaCity_Shipyard/scripts.pory"
	removeobject 2
# 88 "data/maps/MurenaCity_Shipyard/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MurenaCity_Shipyard_Movement_PlayerBoardBoat
# 89 "data/maps/MurenaCity_Shipyard/scripts.pory"
	waitmovement 0
# 90 "data/maps/MurenaCity_Shipyard/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_MURENA_CITY_SHIPYARD
# 91 "data/maps/MurenaCity_Shipyard/scripts.pory"
	delay 24
# 92 "data/maps/MurenaCity_Shipyard/scripts.pory"
	applymovement 1, MurenaCity_Shipyard_Movement_BoatExitShipyard
# 93 "data/maps/MurenaCity_Shipyard/scripts.pory"
	waitmovement 0
# 94 "data/maps/MurenaCity_Shipyard/scripts.pory"
	setvar VAR_FISHERMAN_FERRY_STATE, 1
# 95 "data/maps/MurenaCity_Shipyard/scripts.pory"
	warpsilent MAP_MURENA_CITY, 0xFF, 32, 26
# 96 "data/maps/MurenaCity_Shipyard/scripts.pory"
	waitstate
	end


MurenaCity_Shipyard_EventScript_Man::
# 101 "data/maps/MurenaCity_Shipyard/scripts.pory"
	msgbox MurenaCity_Shipyard_EventScript_Man_Text_0, MSGBOX_NPC
# 106 "data/maps/MurenaCity_Shipyard/scripts.pory"
	applymovement 3, Common_Movement_FaceUp
# 107 "data/maps/MurenaCity_Shipyard/scripts.pory"
	waitmovement 0
	end


# 111 "data/maps/MurenaCity_Shipyard/scripts.pory"
MurenaCity_Shipyard_Movement_PlayerWalkToFisherman:
# 112 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_down
# 113 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_left
# 114 "data/maps/MurenaCity_Shipyard/scripts.pory"
	face_up
	step_end

# 117 "data/maps/MurenaCity_Shipyard/scripts.pory"
MurenaCity_Shipyard_Movement_FishermanBoardBoat:
# 118 "data/maps/MurenaCity_Shipyard/scripts.pory"
	disable_jump_landing_ground_effect
# 119 "data/maps/MurenaCity_Shipyard/scripts.pory"
	face_left
# 120 "data/maps/MurenaCity_Shipyard/scripts.pory"
	delay_16
# 121 "data/maps/MurenaCity_Shipyard/scripts.pory"
	jump_left
# 122 "data/maps/MurenaCity_Shipyard/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 125 "data/maps/MurenaCity_Shipyard/scripts.pory"
MurenaCity_Shipyard_Movement_PlayerBoardBoat:
# 126 "data/maps/MurenaCity_Shipyard/scripts.pory"
	disable_jump_landing_ground_effect
# 127 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_up
# 128 "data/maps/MurenaCity_Shipyard/scripts.pory"
	face_left
# 129 "data/maps/MurenaCity_Shipyard/scripts.pory"
	delay_16
# 130 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_in_place_faster_left
# 130 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_in_place_faster_left
# 130 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_in_place_faster_left
# 131 "data/maps/MurenaCity_Shipyard/scripts.pory"
	jump_left
# 132 "data/maps/MurenaCity_Shipyard/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 135 "data/maps/MurenaCity_Shipyard/scripts.pory"
MurenaCity_Shipyard_Movement_BoatExitShipyard:
# 136 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_left
# 136 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_left
# 136 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_left
# 136 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_left
# 136 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_left
# 136 "data/maps/MurenaCity_Shipyard/scripts.pory"
	walk_left
	step_end

MurenaCity_Shipyard_EventScript_FinishSailToMurena_Text_0:
# 35 "data/maps/MurenaCity_Shipyard/scripts.pory"
	.string "Ahoy! We've hit the docks of MURENA!\n"
	.string "Just come back to me if you need a ride!$"

MurenaCity_Shipyard_EventScript_Fisherman_Text_0:
# 51 "data/maps/MurenaCity_Shipyard/scripts.pory"
	.string "Hey there {PLAYER}!\n"
	.string "So…\p"
	.string "Wanna head to LITOR TOWN?$"

MurenaCity_Shipyard_EventScript_Fisherman_Text_1:
# 59 "data/maps/MurenaCity_Shipyard/scripts.pory"
	.string "Alright!\n"
	.string "We're headed to LITOR TOWN!$"

MurenaCity_Shipyard_EventScript_CancelFerrySelect_Text_0:
# 73 "data/maps/MurenaCity_Shipyard/scripts.pory"
	.string "Tell me whenever you need me\n"
	.string "and my trusty boat.$"

MurenaCity_Shipyard_EventScript_Man_Text_0:
# 101 "data/maps/MurenaCity_Shipyard/scripts.pory"
	.string "Hey there!\n"
	.string "Every day I check the sonar sensors\l"
	.string "for any detections.\p"
	.string "If there's too much rubble, no ships\n"
	.string "are allowed to leave.$"
