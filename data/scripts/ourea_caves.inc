OureaCaves_EventScript_TryShowMapNamePopup::
# 4 "data/scripts/ourea_caves.pory"
	special TryShowOureaCaveMapNamePopup
	end


OureaCaves_EventScript_SetCaveLights::
# 9 "data/scripts/ourea_caves.pory"
	switch VAR_OUREA_CAVES_LIGHTS_STATE
# 10 "data/scripts/ourea_caves.pory"
	case 1, OureaCaves_EventScript_SetCaveLights_3
# 13 "data/scripts/ourea_caves.pory"
	case 2, OureaCaves_EventScript_SetCaveLights_4
# 16 "data/scripts/ourea_caves.pory"
	case 3, OureaCaves_EventScript_SetCaveLights_5
# 19 "data/scripts/ourea_caves.pory"
	case 4, OureaCaves_EventScript_SetCaveLights_6
# 22 "data/scripts/ourea_caves.pory"
	case 5, OureaCaves_EventScript_SetCaveLights_7
# 25 "data/scripts/ourea_caves.pory"
	case 6, OureaCaves_EventScript_SetCaveLights_8
OureaCaves_EventScript_SetCaveLights_1:
	return

OureaCaves_EventScript_SetCaveLights_3:
# 11 "data/scripts/ourea_caves.pory"
	setflashlevel 5
	goto OureaCaves_EventScript_SetCaveLights_1

OureaCaves_EventScript_SetCaveLights_4:
# 14 "data/scripts/ourea_caves.pory"
	setflashlevel 4
	goto OureaCaves_EventScript_SetCaveLights_1

OureaCaves_EventScript_SetCaveLights_5:
# 17 "data/scripts/ourea_caves.pory"
	setflashlevel 3
	goto OureaCaves_EventScript_SetCaveLights_1

OureaCaves_EventScript_SetCaveLights_6:
# 20 "data/scripts/ourea_caves.pory"
	setflashlevel 2
	goto OureaCaves_EventScript_SetCaveLights_1

OureaCaves_EventScript_SetCaveLights_7:
# 23 "data/scripts/ourea_caves.pory"
	setflashlevel 1
	goto OureaCaves_EventScript_SetCaveLights_1

OureaCaves_EventScript_SetCaveLights_8:
# 26 "data/scripts/ourea_caves.pory"
	setflashlevel 0
	goto OureaCaves_EventScript_SetCaveLights_1


OureaCaves_EventScript_AnimateCaveLights::
# 33 "data/scripts/ourea_caves.pory"
	playse SE_SWITCH
# 34 "data/scripts/ourea_caves.pory"
	switch VAR_OUREA_CAVES_LIGHTS_STATE
# 35 "data/scripts/ourea_caves.pory"
	case 1, OureaCaves_EventScript_AnimateCaveLights_3
# 38 "data/scripts/ourea_caves.pory"
	case 2, OureaCaves_EventScript_AnimateCaveLights_4
# 41 "data/scripts/ourea_caves.pory"
	case 3, OureaCaves_EventScript_AnimateCaveLights_5
# 44 "data/scripts/ourea_caves.pory"
	case 4, OureaCaves_EventScript_AnimateCaveLights_6
# 47 "data/scripts/ourea_caves.pory"
	case 5, OureaCaves_EventScript_AnimateCaveLights_7
# 50 "data/scripts/ourea_caves.pory"
	case 6, OureaCaves_EventScript_AnimateCaveLights_8
OureaCaves_EventScript_AnimateCaveLights_1:
	return

OureaCaves_EventScript_AnimateCaveLights_3:
# 36 "data/scripts/ourea_caves.pory"
	animateflash 5
	goto OureaCaves_EventScript_AnimateCaveLights_1

OureaCaves_EventScript_AnimateCaveLights_4:
# 39 "data/scripts/ourea_caves.pory"
	animateflash 4
	goto OureaCaves_EventScript_AnimateCaveLights_1

OureaCaves_EventScript_AnimateCaveLights_5:
# 42 "data/scripts/ourea_caves.pory"
	animateflash 3
	goto OureaCaves_EventScript_AnimateCaveLights_1

OureaCaves_EventScript_AnimateCaveLights_6:
# 45 "data/scripts/ourea_caves.pory"
	animateflash 2
	goto OureaCaves_EventScript_AnimateCaveLights_1

OureaCaves_EventScript_AnimateCaveLights_7:
# 48 "data/scripts/ourea_caves.pory"
	animateflash 1
	goto OureaCaves_EventScript_AnimateCaveLights_1

OureaCaves_EventScript_AnimateCaveLights_8:
# 51 "data/scripts/ourea_caves.pory"
	animateflash 0
	goto OureaCaves_EventScript_AnimateCaveLights_1


OureaCaves_EventScript_LightGeneratorBoxLogic::
# 58 "data/scripts/ourea_caves.pory"
	compare VAR_OUREA_CAVES_STATE, 0
	goto_if_eq OureaCaves_EventScript_LightGeneratorBoxLogic_2
# 64 "data/scripts/ourea_caves.pory"
	msgbox OureaCaves_EventScript_LightGeneratorBoxLogic_Text_1, MSGBOX_YESNO
# 67 "data/scripts/ourea_caves.pory"
	switch VAR_RESULT
# 68 "data/scripts/ourea_caves.pory"
	case YES, OureaCaves_EventScript_LightGeneratorBoxLogic_6
# 75 "data/scripts/ourea_caves.pory"
	case NO, OureaCaves_EventScript_LightGeneratorBoxLogic_7
# 78 "data/scripts/ourea_caves.pory"
	case MULTI_B_PRESSED, OureaCaves_EventScript_LightGeneratorBoxLogic_8
OureaCaves_EventScript_LightGeneratorBoxLogic_4:
	return

OureaCaves_EventScript_LightGeneratorBoxLogic_2:
# 59 "data/scripts/ourea_caves.pory"
	msgbox OureaCaves_EventScript_LightGeneratorBoxLogic_Text_0
# 61 "data/scripts/ourea_caves.pory"
	closemessage
	end

OureaCaves_EventScript_LightGeneratorBoxLogic_6:
# 69 "data/scripts/ourea_caves.pory"
	msgbox OureaCaves_EventScript_LightGeneratorBoxLogic_Text_2
# 70 "data/scripts/ourea_caves.pory"
	closemessage
# 71 "data/scripts/ourea_caves.pory"
	addvar VAR_OUREA_CAVES_LIGHTS_STATE, 1
# 72 "data/scripts/ourea_caves.pory"
	call OureaCaves_EventScript_AnimateCaveLights
# 73 "data/scripts/ourea_caves.pory"
	call OureaCaves_EventScript_SetCaveLights
	goto OureaCaves_EventScript_LightGeneratorBoxLogic_4

OureaCaves_EventScript_LightGeneratorBoxLogic_7:
# 76 "data/scripts/ourea_caves.pory"
	closemessage
	end

OureaCaves_EventScript_LightGeneratorBoxLogic_8:
# 79 "data/scripts/ourea_caves.pory"
	closemessage
	end


OureaCaves_EventScript_GeneratorAlreadyTurnedOn::
# 86 "data/scripts/ourea_caves.pory"
	msgbox OureaCaves_EventScript_GeneratorAlreadyTurnedOn_Text_0
# 87 "data/scripts/ourea_caves.pory"
	closemessage
	end


OureaCaves_EventScript_LightGeneratorBox1::
# 92 "data/scripts/ourea_caves.pory"
	goto_if_set FLAG_OUREA_CAVES_GENERATOR_1, OureaCaves_EventScript_LightGeneratorBox1_2
OureaCaves_EventScript_LightGeneratorBox1_1:
# 95 "data/scripts/ourea_caves.pory"
	call OureaCaves_EventScript_LightGeneratorBoxLogic
# 96 "data/scripts/ourea_caves.pory"
	playse SE_PIN
# 97 "data/scripts/ourea_caves.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 98 "data/scripts/ourea_caves.pory"
	waitmovement 0
# 99 "data/scripts/ourea_caves.pory"
	applymovement 1, Common_Movement_FaceDown
# 100 "data/scripts/ourea_caves.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 101 "data/scripts/ourea_caves.pory"
	waitmovement 0
# 102 "data/scripts/ourea_caves.pory"
	msgbox OureaCaves_EventScript_LightGeneratorBox1_Text_0
# 109 "data/scripts/ourea_caves.pory"
	closemessage
# 110 "data/scripts/ourea_caves.pory"
	setflag FLAG_OUREA_CAVES_GENERATOR_1
# 111 "data/scripts/ourea_caves.pory"
	setvar VAR_OUREA_CAVES_STATE, 3
	end

OureaCaves_EventScript_LightGeneratorBox1_2:
# 93 "data/scripts/ourea_caves.pory"
	goto OureaCaves_EventScript_GeneratorAlreadyTurnedOn
	goto OureaCaves_EventScript_LightGeneratorBox1_1


OureaCaves_EventScript_LightGeneratorBox2::
# 116 "data/scripts/ourea_caves.pory"
	goto_if_set FLAG_OUREA_CAVES_GENERATOR_2, OureaCaves_EventScript_LightGeneratorBox2_2
OureaCaves_EventScript_LightGeneratorBox2_1:
# 119 "data/scripts/ourea_caves.pory"
	call OureaCaves_EventScript_LightGeneratorBoxLogic
# 120 "data/scripts/ourea_caves.pory"
	setflag FLAG_OUREA_CAVES_GENERATOR_2
	end

OureaCaves_EventScript_LightGeneratorBox2_2:
# 117 "data/scripts/ourea_caves.pory"
	goto OureaCaves_EventScript_GeneratorAlreadyTurnedOn
	goto OureaCaves_EventScript_LightGeneratorBox2_1


OureaCaves_EventScript_LightGeneratorBox3::
# 125 "data/scripts/ourea_caves.pory"
	goto_if_set FLAG_OUREA_CAVES_GENERATOR_3, OureaCaves_EventScript_LightGeneratorBox3_2
OureaCaves_EventScript_LightGeneratorBox3_1:
# 128 "data/scripts/ourea_caves.pory"
	call OureaCaves_EventScript_LightGeneratorBoxLogic
# 129 "data/scripts/ourea_caves.pory"
	setflag FLAG_OUREA_CAVES_GENERATOR_3
	end

OureaCaves_EventScript_LightGeneratorBox3_2:
# 126 "data/scripts/ourea_caves.pory"
	goto OureaCaves_EventScript_GeneratorAlreadyTurnedOn
	goto OureaCaves_EventScript_LightGeneratorBox3_1


OureaCaves_EventScript_LightGeneratorBox4::
# 134 "data/scripts/ourea_caves.pory"
	goto_if_set FLAG_OUREA_CAVES_GENERATOR_4, OureaCaves_EventScript_LightGeneratorBox4_2
OureaCaves_EventScript_LightGeneratorBox4_1:
# 137 "data/scripts/ourea_caves.pory"
	call OureaCaves_EventScript_LightGeneratorBoxLogic
# 138 "data/scripts/ourea_caves.pory"
	setflag FLAG_OUREA_CAVES_GENERATOR_4
	end

OureaCaves_EventScript_LightGeneratorBox4_2:
# 135 "data/scripts/ourea_caves.pory"
	goto OureaCaves_EventScript_GeneratorAlreadyTurnedOn
	goto OureaCaves_EventScript_LightGeneratorBox4_1


OureaCaves_EventScript_LightGeneratorBox5::
# 143 "data/scripts/ourea_caves.pory"
	goto_if_set FLAG_OUREA_CAVES_GENERATOR_5, OureaCaves_EventScript_LightGeneratorBox5_2
OureaCaves_EventScript_LightGeneratorBox5_1:
# 146 "data/scripts/ourea_caves.pory"
	call OureaCaves_EventScript_LightGeneratorBoxLogic
# 147 "data/scripts/ourea_caves.pory"
	setflag FLAG_OUREA_CAVES_GENERATOR_5
	end

OureaCaves_EventScript_LightGeneratorBox5_2:
# 144 "data/scripts/ourea_caves.pory"
	goto OureaCaves_EventScript_GeneratorAlreadyTurnedOn
	goto OureaCaves_EventScript_LightGeneratorBox5_1


OureaCaves_EventScript_LightGeneratorBoxLogic_Text_0:
# 59 "data/scripts/ourea_caves.pory"
	.string "It looks like a generator of\n"
	.string "some sort…$"

OureaCaves_EventScript_LightGeneratorBoxLogic_Text_1:
# 64 "data/scripts/ourea_caves.pory"
	.string "It's a power generator wired up to\n"
	.string "the lights in the cave.\p"
	.string "Do you want to turn it on?$"

OureaCaves_EventScript_LightGeneratorBoxLogic_Text_2:
# 69 "data/scripts/ourea_caves.pory"
	.string "You turned on the generator.$"

OureaCaves_EventScript_GeneratorAlreadyTurnedOn_Text_0:
# 86 "data/scripts/ourea_caves.pory"
	.string "This generator is already turned on.$"

OureaCaves_EventScript_LightGeneratorBox1_Text_0:
# 102 "data/scripts/ourea_caves.pory"
	.string "Nice one!\n"
	.string "You flipped the switch the right way!\p"
	.string "Not that there's really a way to do it\n"
	.string "wrong…\p"
	.string "Anyway, there should be 5 more of these\n"
	.string "generators scattered around…\p"
	.string "Good luck!$"
