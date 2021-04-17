OureaCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OureaCave_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

OureaCave_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call OureaCaves_EventScript_SetCaveLights
	return


OureaCave_1F_EventScript_Hiker1::
	msgbox OureaCave_1F_EventScript_Hiker1_Text_0, MSGBOX_NPC
	end


OureaCave_1F_EventScript_Hiker1_Text_0:
	.string "See those complicated boxes there?\p"
	.string "They're used to control the lights\n"
	.string "in the OUREA CAVES.$"
