OureaCave_B4F_LowTide_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call OureaCaves_EventScript_SetCaveLights
	special UpdateOureaCaveTides
	goto_if_set FLAG_SYS_OUREA_TIDE, OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setmaplayoutindex LAYOUT_OUREA_CAVE_B4F_LOW_TIDE
	return

OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setmaplayoutindex LAYOUT_OUREA_CAVE_B4F_HIGH_TIDE
	return

OureaCave_B4F_LowTide_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_F, 0, OureaCaves_EventScript_TryShowMapNamePopup
	.2byte 0


OureaCave_B4F_LowTide_EventScript_ConstructionWorker1::
	lock
	faceplayer
	compare VAR_OUREA_CAVES_LIGHTS_STATE, 6
	goto_if_lt OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_1
	compare VAR_OUREA_CAVES_LIGHTS_STATE, 6
	goto_if_eq OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_2
	return

OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_1:
	msgbox OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_Text_0
	closemessage
	release
	end

OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_2:
	goto OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene
	return


OureaCave_B4F_LowTide_EventScript_ConstructionWorker2::
	lock
	faceplayer
	compare VAR_OUREA_CAVES_LIGHTS_STATE, 6
	goto_if_lt OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_1
	compare VAR_OUREA_CAVES_LIGHTS_STATE, 6
	goto_if_eq OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_2
	return

OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_1:
	msgbox OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_Text_0
	closemessage
	release
	end

OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_2:
	goto OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene
	return


OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene::
	msgbox OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_Text_0, MSGBOX_NPC
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	switch VAR_TEMP_2
	case 12, OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_3
	case 13, OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_4
OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_1:
	release
	end

OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_3:
	call OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker1
	goto OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_1

OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_4:
	call OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker2
	goto OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_1


OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker1::
	playse SE_POKENAV_CALL
	delay 60
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	turnobject 2, DIR_NORTH
	delay 30
	load_speech_bubble 2
	call OureaCave_B4F_LowTide_EventScript_DoCallDialogue
	turnobject 1, DIR_SOUTH
	delay 60
	load_speech_bubble 1
	msgbox OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker1_Text_0
	destroy_speech_bubble
	closemessage
	turnobject 1, DIR_WEST
	load_speech_bubble 1
	call OureaCave_B4F_LowTide_EventScript_DoAfterCallDialogue
	applymovement OBJ_EVENT_ID_PLAYER, OureaCave_B4F_LowTide_Movement_PlayerWalkDown
	applymovement 1, OureaCave_B4F_LowTide_Movement_ConstructionWorkerWalkOffScreen
	applymovement 2, OureaCave_B4F_LowTide_Movement_ConstructionWorker2FollowOffScreen
	waitmovement 0
	hideobjectat 1, MAP_OUREA_CAVE_B4F_LOW_TIDE
	hideobjectat 2, MAP_OUREA_CAVE_B4F_LOW_TIDE
	setflag FLAG_HIDE_OUREA_CAVE_B4F_LOW_TIDE_CONSTRUCTION_WORKERS
	return


OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker2::
	playse SE_POKENAV_CALL
	delay 60
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	turnobject 1, DIR_SOUTH
	delay 30
	load_speech_bubble 1
	call OureaCave_B4F_LowTide_EventScript_DoCallDialogue
	turnobject 2, DIR_NORTH
	delay 60
	load_speech_bubble 2
	msgbox OureaCave_B4F_LowTide_EventScript_DoCallCutsceneForWorker1_Text_0
	destroy_speech_bubble
	closemessage
	turnobject 2, DIR_WEST
	load_speech_bubble 2
	call OureaCave_B4F_LowTide_EventScript_DoAfterCallDialogue
	applymovement OBJ_EVENT_ID_PLAYER, OureaCave_B4F_LowTide_Movement_PlayerWalkUp
	applymovement 2, OureaCave_B4F_LowTide_Movement_ConstructionWorkerWalkOffScreen
	applymovement 1, OureaCave_B4F_LowTide_Movement_ConstructionWorker1FollowOffScreen
	waitmovement 0
	hideobjectat 1, MAP_OUREA_CAVE_B4F_LOW_TIDE
	hideobjectat 2, MAP_OUREA_CAVE_B4F_LOW_TIDE
	setflag FLAG_HIDE_OUREA_CAVE_B4F_LOW_TIDE_CONSTRUCTION_WORKERS
	return


OureaCave_B4F_LowTide_EventScript_DoCallDialogue::
	msgbox OureaCave_B4F_LowTide_EventScript_DoCallDialogue_Text_0
	destroy_speech_bubble
	closemessage
	return


OureaCave_B4F_LowTide_EventScript_DoAfterCallDialogue::
	msgbox OureaCave_B4F_LowTide_EventScript_DoAfterCallDialogue_Text_0
	destroy_speech_bubble
	closemessage
	return


OureaCave_B4F_LowTide_EventScript_OldMan::
	msgbox OureaCave_B4F_LowTide_EventScript_OldMan_Text_0, MSGBOX_NPC
	end


OureaCave_B4F_LowTide_Movement_PlayerWalkDown:
	walk_down
	face_up
	step_end

OureaCave_B4F_LowTide_Movement_PlayerWalkUp:
	walk_up
	face_down
	step_end

OureaCave_B4F_LowTide_Movement_ConstructionWorkerWalkOffScreen:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OureaCave_B4F_LowTide_Movement_ConstructionWorker2FollowOffScreen:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OureaCave_B4F_LowTide_Movement_ConstructionWorker1FollowOffScreen:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OureaCave_B4F_LowTide_EventScript_ConstructionWorker1_Text_0:
	.string "I heard from the BOSS that you're\n"
	.string "supposed to be helping us?\p"
	.string "Well err, not to be that person, but…\p"
	.string "It's still a bit dark here, don't you agree?$"

OureaCave_B4F_LowTide_EventScript_ConstructionWorker2_Text_0:
	.string "I heard from the BOSS that you're\n"
	.string "supposed to be helping us?\p"
	.string "Well err, not to be that person, but…\p"
	.string "It's still a bit dark here,\n"
	.string "don't you agree?$"

OureaCave_B4F_LowTide_EventScript_CompletedLightBoxCutscene_Text_0:
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
	.string "Ah alright, I see now…$"

OureaCave_B4F_LowTide_EventScript_DoCallDialogue_Text_0:
	.string "Mhm…\n"
	.string "Yes, alright.\n"
	.string "Understood sir.$"

OureaCave_B4F_LowTide_EventScript_DoAfterCallDialogue_Text_0:
	.string "Now that the lights are on again,\n"
	.string "the BOSS want us to get back to work…\p"
	.string "Sigh… It's a never ending cycle…\p"
	.string "Anyway, have safe travels and thanks\n"
	.string "for the help!$"

OureaCave_B4F_LowTide_EventScript_OldMan_Text_0:
	.string "Isn't it beautiful how the water\n"
	.string "floods this cave partially from\l"
	.string "time to time?\p"
	.string "The tides are a wonderful natural\n"
	.string "phenomenon, don't you agree?$"
