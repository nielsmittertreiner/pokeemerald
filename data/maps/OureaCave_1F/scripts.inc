OureaCave_1F_MapScripts::
# 2 "data/maps/OureaCave_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OureaCave_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 5 "data/maps/OureaCave_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OureaCave_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OureaCave_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/OureaCave_1F/scripts.pory"
	call OureaCaves_EventScript_SetCaveLights
	return

OureaCave_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/OureaCave_1F/scripts.pory"
	map_script_2 VAR_TEMP_F, 0, OureaCaves_EventScript_TryShowMapNamePopup
	.2byte 0


OureaCave_1F_EventScript_Hiker1::
# 11 "data/maps/OureaCave_1F/scripts.pory"
	msgbox OureaCave_1F_EventScript_Hiker1_Text_0, MSGBOX_NPC
	end


OureaCave_1F_EventScript_Hiker1_Text_0:
# 11 "data/maps/OureaCave_1F/scripts.pory"
	.string "See those complicated boxes there?\p"
	.string "They're used to control the lights\n"
	.string "in the OUREA CAVES.$"
