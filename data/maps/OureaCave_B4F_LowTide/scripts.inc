OureaCave_B4F_LowTide_MapScripts::
# 5 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 6 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	call OureaCaves_EventScript_SetCaveLights
# 7 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	special UpdateOureaCaveTides
# 8 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	goto_if_set FLAG_SYS_OUREA_TIDE, OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 11 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	setmaplayoutindex LAYOUT_OUREA_CAVE_B4F_LOW_TIDE
	return

OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 9 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	setmaplayoutindex LAYOUT_OUREA_CAVE_B4F_HIGH_TIDE
	return

OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 15 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	map_script_2 VAR_TEMP_F, 0, OureaCaves_EventScript_TryShowMapNamePopup
	.2byte 0


OureaCave_B4F_LowTide_EventScript_ConstructionWorker1::
# 20 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	lock
# 21 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	faceplayer
# 22 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	compare VAR_OUREA_CAVES_LIGHTS_STATE, 6
	goto_if_lt OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_1
# 30 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	compare VAR_OUREA_CAVES_LIGHTS_STATE, 6
	goto_if_eq OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_2
	return

OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_1:
# 23 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	msgbox OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_Text_0
# 27 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	closemessage
# 28 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	release
	end

OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_2:
# 31 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	goto OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene
	return


OureaCave_B4F_LowTide_EventScript_ConstructionWorker2::
# 36 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	lock
# 37 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	faceplayer
# 38 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	compare VAR_OUREA_CAVES_LIGHTS_STATE, 6
	goto_if_lt OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_1
# 47 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	compare VAR_OUREA_CAVES_LIGHTS_STATE, 6
	goto_if_eq OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_2
	return

OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_1:
# 39 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	msgbox OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_Text_0
# 44 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	closemessage
# 45 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	release
	end

OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_2:
# 48 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	goto OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene
	return


OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene::
# 53 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	msgbox OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_Text_0, MSGBOX_NPC
# 62 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 63 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	switch VAR_TEMP_2
# 64 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	case 12, OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_3
# 67 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	case 13, OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_4
OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_1:
# 71 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	release
	end

OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_3:
# 65 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	call OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker1
	goto OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_1

OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_4:
# 68 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	call OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker2
	goto OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_1


OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker1::
# 76 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	playse SE_POKENAV_CALL
# 77 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	delay 60
# 78 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 79 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	waitmovement 0
# 80 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	turnobject 2, DIR_NORTH
# 81 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	delay 30
# 82 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	loadspeechtail FALSE, 2
# 83 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	call OureaCave_B4F_LowTide_EventScript_DoCallDialogue
# 84 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	turnobject 1, DIR_SOUTH
# 85 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	delay 60
# 86 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	loadspeechtail FALSE, 1
# 87 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	msgbox OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker1_Text_0
# 88 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	destroyspeechtail
# 89 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	closemessage
# 90 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	turnobject 1, DIR_WEST
# 91 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	loadspeechtail FALSE, 1
# 92 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	call OureaCave_B4F_LowTide_EventScript_DoAfterCallDialogue
# 93 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OureaCave_B4F_LowTide_Movement_PlayerWalkDown
# 94 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	applymovement 1, OureaCave_B4F_LowTide_Movement_ConstructionWorkerWalkOffScreen
# 95 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	applymovement 2, OureaCave_B4F_LowTide_Movement_ConstructionWorker2FollowOffScreen
# 96 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	waitmovement 0
# 97 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	hideobjectat 1, MAP_OUREA_CAVE_B4F_LOW_TIDE
# 98 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	hideobjectat 2, MAP_OUREA_CAVE_B4F_LOW_TIDE
# 99 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	setflag FLAG_HIDE_OUREA_CAVE_B4F_LOW_TIDE_CONSTRUCTION_WORKERS
	return


OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker2::
# 104 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	playse SE_POKENAV_CALL
# 105 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	delay 60
# 106 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 107 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	waitmovement 0
# 108 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	turnobject 1, DIR_SOUTH
# 109 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	delay 30
# 110 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	loadspeechtail FALSE, 1
# 111 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	call OureaCave_B4F_LowTide_EventScript_DoCallDialogue
# 112 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	turnobject 2, DIR_NORTH
# 113 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	delay 60
# 114 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	loadspeechtail FALSE, 2
# 115 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	msgbox OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker1_Text_0
# 116 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	destroyspeechtail
# 117 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	closemessage
# 118 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	turnobject 2, DIR_WEST
# 119 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	loadspeechtail FALSE, 2
# 120 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	call OureaCave_B4F_LowTide_EventScript_DoAfterCallDialogue
# 121 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OureaCave_B4F_LowTide_Movement_PlayerWalkUp
# 122 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	applymovement 2, OureaCave_B4F_LowTide_Movement_ConstructionWorkerWalkOffScreen
# 123 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	applymovement 1, OureaCave_B4F_LowTide_Movement_ConstructionWorker1FollowOffScreen
# 124 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	waitmovement 0
# 125 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	hideobjectat 1, MAP_OUREA_CAVE_B4F_LOW_TIDE
# 126 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	hideobjectat 2, MAP_OUREA_CAVE_B4F_LOW_TIDE
# 127 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	setflag FLAG_HIDE_OUREA_CAVE_B4F_LOW_TIDE_CONSTRUCTION_WORKERS
	return


OureaCave_B4F_LowTide_EventScript_DoCallDialogue::
# 132 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	msgbox OureaCave_B4F_LowTide_EventScript_DoCallDialogue_Text_0
# 135 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	destroyspeechtail
# 136 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	closemessage
	return


OureaCave_B4F_LowTide_EventScript_DoAfterCallDialogue::
# 141 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	msgbox OureaCave_B4F_LowTide_EventScript_DoAfterCallDialogue_Text_0
# 146 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	destroyspeechtail
# 147 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	closemessage
	return


OureaCave_B4F_LowTide_EventScript_OldMan::
# 152 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	msgbox OureaCave_B4F_LowTide_EventScript_OldMan_Text_0, MSGBOX_NPC
	end


# 160 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
OureaCave_B4F_LowTide_Movement_PlayerWalkDown:
# 161 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_down
# 162 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	face_up
	step_end

# 165 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
OureaCave_B4F_LowTide_Movement_PlayerWalkUp:
# 166 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 167 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	face_down
	step_end

# 171 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
OureaCave_B4F_LowTide_Movement_ConstructionWorkerWalkOffScreen:
# 172 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 172 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 172 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 172 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 172 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 172 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 172 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 173 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 173 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 173 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 173 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 173 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 173 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 173 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
	step_end

# 176 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
OureaCave_B4F_LowTide_Movement_ConstructionWorker2FollowOffScreen:
# 177 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 178 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 178 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 178 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 178 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 178 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 178 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 178 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 179 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 179 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 179 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 179 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 179 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 179 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 179 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
	step_end

# 182 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
OureaCave_B4F_LowTide_Movement_ConstructionWorker1FollowOffScreen:
# 183 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_down
# 184 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 184 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 184 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 184 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 184 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 184 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 184 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_left
# 185 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 185 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 185 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 185 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 185 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 185 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
# 185 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	walk_up
	step_end

OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_Text_0:
# 23 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	.string "I heard from the BOSS that you're\n"
	.string "supposed to be helping us?\p"
	.string "Well err, not to be that person, but…\p"
	.string "It's still a bit dark here, don't you agree?$"

OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_Text_0:
# 39 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	.string "I heard from the BOSS that you're\n"
	.string "supposed to be helping us?\p"
	.string "Well err, not to be that person, but…\p"
	.string "It's still a bit dark here,\n"
	.string "don't you agree?$"

OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_Text_0:
# 53 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	.string "Har har!\n"
	.string "You've done it!\p"
	.string "I can finally see clearly again.\p"
	.string "Mining can be dangerous work, so being\n"
	.string "able to see properly is very important!\p"
	.string "Y'know, we've heard there are FOSSILS\n"
	.string "in other caves of the EURUS REGION…\p"
	.string "Maybe you'll meet some of our other\n"
	.string "workers there too!$"

OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker1_Text_0:
# 87 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	.string "Ah alright, I see now…$"

OureaCave_B4F_LowTide_EventScript_DoCallDialogue_Text_0:
# 132 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	.string "Mhm…\n"
	.string "Yes, alright.\n"
	.string "Understood sir.$"

OureaCave_B4F_LowTide_EventScript_DoAfterCallDialogue_Text_0:
# 141 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	.string "Now that the lights are on again,\n"
	.string "the BOSS want us to get back to work…\p"
	.string "Sigh… It's a never ending cycle…\p"
	.string "Anyway, have safe travels and thanks\n"
	.string "for the help!$"

OureaCave_B4F_LowTide_EventScript_OldMan_Text_0:
# 152 "data/maps/OureaCave_B4F_LowTide/scripts.pory"
	.string "Isn't it beautiful how the water\n"
	.string "floods this cave partially from\l"
	.string "time to time?\p"
	.string "The tides are a wonderful natural\n"
	.string "phenomenon, don't you agree?$"
