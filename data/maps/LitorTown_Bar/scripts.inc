LitorTown_Bar_MapScripts::
	.byte 0


LitorTown_Bar_EventScript_Barman::
# 6 "data/maps/LitorTown_Bar/scripts.pory"
	lock
# 7 "data/maps/LitorTown_Bar/scripts.pory"
	faceplayer
# 8 "data/maps/LitorTown_Bar/scripts.pory"
	loadspeechtail FALSE, 1
# 9 "data/maps/LitorTown_Bar/scripts.pory"
	message LitorTown_Bar_Text_WelcomeToMyBar
# 10 "data/maps/LitorTown_Bar/scripts.pory"
	waitmessage
# 11 "data/maps/LitorTown_Bar/scripts.pory"
	destroyspeechtail
# 12 "data/maps/LitorTown_Bar/scripts.pory"
	special SpawnCameraObject
# 13 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_SetUpShop
	end


LitorTown_Bar_EventScript_SetUpShop::
# 18 "data/maps/LitorTown_Bar/scripts.pory"
	call LitorTown_Bar_EventScript_SetUpShopCamera
# 19 "data/maps/LitorTown_Bar/scripts.pory"
	loadspeechtail FALSE, 1
# 20 "data/maps/LitorTown_Bar/scripts.pory"
	message LitorTown_Bar_Text_WhatDoYouFancy
# 21 "data/maps/LitorTown_Bar/scripts.pory"
	waitmessage
# 22 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_DrawShopMenu
	return


LitorTown_Bar_EventScript_SetUpShopCamera::
# 26 "data/maps/LitorTown_Bar/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LitorTown_Bar_Movement_MoveCameraShopView
# 27 "data/maps/LitorTown_Bar/scripts.pory"
	waitmovement 0
	return


LitorTown_Bar_EventScript_ResetShopCamera::
# 32 "data/maps/LitorTown_Bar/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LitorTown_Bar_Movement_ResetCameraShopView
# 33 "data/maps/LitorTown_Bar/scripts.pory"
	waitmovement 0
	return


LitorTown_Bar_EventScript_DrawShopMenu::
# 38 "data/maps/LitorTown_Bar/scripts.pory"
	showmoneybox 0, 0, 0
# 39 "data/maps/LitorTown_Bar/scripts.pory"
	multichoice 0, 4, MULTI_LITOR_BAR_SHOP, 0
# 40 "data/maps/LitorTown_Bar/scripts.pory"
	destroyspeechtail
# 41 "data/maps/LitorTown_Bar/scripts.pory"
	switch VAR_RESULT
# 42 "data/maps/LitorTown_Bar/scripts.pory"
	case 0, LitorTown_Bar_EventScript_DrawShopMenu_2
# 44 "data/maps/LitorTown_Bar/scripts.pory"
	case 1, LitorTown_Bar_EventScript_DrawShopMenu_3
# 46 "data/maps/LitorTown_Bar/scripts.pory"
	case 2, LitorTown_Bar_EventScript_DrawShopMenu_4
# 48 "data/maps/LitorTown_Bar/scripts.pory"
	case 3, LitorTown_Bar_EventScript_DrawShopMenu_5
# 51 "data/maps/LitorTown_Bar/scripts.pory"
	case MULTI_B_PRESSED, LitorTown_Bar_EventScript_DrawShopMenu_6
	return

LitorTown_Bar_EventScript_DrawShopMenu_2:
# 43 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_ChooseFreshWater
	return

LitorTown_Bar_EventScript_DrawShopMenu_3:
# 45 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_ChooseSodaPop
	return

LitorTown_Bar_EventScript_DrawShopMenu_4:
# 47 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_ChooseLemonade
	return

LitorTown_Bar_EventScript_DrawShopMenu_5:
# 49 "data/maps/LitorTown_Bar/scripts.pory"
	call LitorTown_Bar_EventScript_ResetShopCamera
# 50 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return

LitorTown_Bar_EventScript_DrawShopMenu_6:
# 52 "data/maps/LitorTown_Bar/scripts.pory"
	call LitorTown_Bar_EventScript_ResetShopCamera
# 53 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return


LitorTown_Bar_EventScript_ChooseFreshWater::
# 58 "data/maps/LitorTown_Bar/scripts.pory"
	call LitorTown_Bar_EventScript_ResetShopCamera
# 59 "data/maps/LitorTown_Bar/scripts.pory"
	loadspeechtail FALSE, 1
# 60 "data/maps/LitorTown_Bar/scripts.pory"
	msgbox LitorTown_Bar_EventScript_ChooseFreshWater_Text_0, MSGBOX_YESNO
# 61 "data/maps/LitorTown_Bar/scripts.pory"
	destroyspeechtail
# 62 "data/maps/LitorTown_Bar/scripts.pory"
	switch VAR_RESULT
# 63 "data/maps/LitorTown_Bar/scripts.pory"
	case YES, LitorTown_Bar_EventScript_ChooseFreshWater_2
# 65 "data/maps/LitorTown_Bar/scripts.pory"
	case NO, LitorTown_Bar_EventScript_ChooseFreshWater_3
# 67 "data/maps/LitorTown_Bar/scripts.pory"
	case MULTI_B_PRESSED, LitorTown_Bar_EventScript_ChooseFreshWater_4
	return

LitorTown_Bar_EventScript_ChooseFreshWater_2:
# 64 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_TryBuyFreshWater
	return

LitorTown_Bar_EventScript_ChooseFreshWater_3:
# 66 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return

LitorTown_Bar_EventScript_ChooseFreshWater_4:
# 68 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return


LitorTown_Bar_EventScript_ChooseSodaPop::
# 73 "data/maps/LitorTown_Bar/scripts.pory"
	call LitorTown_Bar_EventScript_ResetShopCamera
# 74 "data/maps/LitorTown_Bar/scripts.pory"
	msgbox LitorTown_Bar_EventScript_ChooseSodaPop_Text_0, MSGBOX_YESNO
# 75 "data/maps/LitorTown_Bar/scripts.pory"
	switch VAR_RESULT
# 76 "data/maps/LitorTown_Bar/scripts.pory"
	case YES, LitorTown_Bar_EventScript_ChooseSodaPop_2
# 78 "data/maps/LitorTown_Bar/scripts.pory"
	case NO, LitorTown_Bar_EventScript_ChooseSodaPop_3
# 80 "data/maps/LitorTown_Bar/scripts.pory"
	case MULTI_B_PRESSED, LitorTown_Bar_EventScript_ChooseSodaPop_4
	return

LitorTown_Bar_EventScript_ChooseSodaPop_2:
# 77 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_TryBuySodaPop
	return

LitorTown_Bar_EventScript_ChooseSodaPop_3:
# 79 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return

LitorTown_Bar_EventScript_ChooseSodaPop_4:
# 81 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return


LitorTown_Bar_EventScript_ChooseLemonade::
# 86 "data/maps/LitorTown_Bar/scripts.pory"
	call LitorTown_Bar_EventScript_ResetShopCamera
# 87 "data/maps/LitorTown_Bar/scripts.pory"
	msgbox LitorTown_Bar_EventScript_ChooseLemonade_Text_0, MSGBOX_YESNO
# 88 "data/maps/LitorTown_Bar/scripts.pory"
	switch VAR_RESULT
# 89 "data/maps/LitorTown_Bar/scripts.pory"
	case YES, LitorTown_Bar_EventScript_ChooseLemonade_2
# 91 "data/maps/LitorTown_Bar/scripts.pory"
	case NO, LitorTown_Bar_EventScript_ChooseLemonade_3
# 93 "data/maps/LitorTown_Bar/scripts.pory"
	case MULTI_B_PRESSED, LitorTown_Bar_EventScript_ChooseLemonade_4
	return

LitorTown_Bar_EventScript_ChooseLemonade_2:
# 90 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_TryBuyLemonade
	return

LitorTown_Bar_EventScript_ChooseLemonade_3:
# 92 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return

LitorTown_Bar_EventScript_ChooseLemonade_4:
# 94 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return


LitorTown_Bar_EventScript_TryBuyFreshWater::
# 100 "data/maps/LitorTown_Bar/scripts.pory"
	checkmoney 200, 0
# 101 "data/maps/LitorTown_Bar/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LitorTown_Bar_EventScript_TryBuyFreshWater_2
LitorTown_Bar_EventScript_TryBuyFreshWater_1:
# 108 "data/maps/LitorTown_Bar/scripts.pory"
	playse SE_SHOP
# 109 "data/maps/LitorTown_Bar/scripts.pory"
	removemoney 200, 0
# 110 "data/maps/LitorTown_Bar/scripts.pory"
	updatemoneybox 0
# 111 "data/maps/LitorTown_Bar/scripts.pory"
	delay 30
# 112 "data/maps/LitorTown_Bar/scripts.pory"
	hidemoneybox
# 113 "data/maps/LitorTown_Bar/scripts.pory"
	giveitem ITEM_FRESH_WATER, 1
# 114 "data/maps/LitorTown_Bar/scripts.pory"
	closemessage
# 115 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_SetUpShop
	return

LitorTown_Bar_EventScript_TryBuyFreshWater_2:
# 102 "data/maps/LitorTown_Bar/scripts.pory"
	loadspeechtail FALSE, 1
# 103 "data/maps/LitorTown_Bar/scripts.pory"
	msgbox LitorTown_Bar_EventScript_TryBuyFreshWater_Text_0
# 104 "data/maps/LitorTown_Bar/scripts.pory"
	destroyspeechtail
# 105 "data/maps/LitorTown_Bar/scripts.pory"
	closemessage
# 106 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	goto LitorTown_Bar_EventScript_TryBuyFreshWater_1


LitorTown_Bar_EventScript_TryBuySodaPop::
# 119 "data/maps/LitorTown_Bar/scripts.pory"
	checkmoney 200, 0
# 120 "data/maps/LitorTown_Bar/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LitorTown_Bar_EventScript_TryBuySodaPop_2
LitorTown_Bar_EventScript_TryBuySodaPop_1:
# 127 "data/maps/LitorTown_Bar/scripts.pory"
	playse SE_SHOP
# 128 "data/maps/LitorTown_Bar/scripts.pory"
	removemoney 250, 0
# 129 "data/maps/LitorTown_Bar/scripts.pory"
	updatemoneybox 0
# 130 "data/maps/LitorTown_Bar/scripts.pory"
	delay 30
# 131 "data/maps/LitorTown_Bar/scripts.pory"
	hidemoneybox
# 132 "data/maps/LitorTown_Bar/scripts.pory"
	giveitem ITEM_SODA_POP, 1
# 133 "data/maps/LitorTown_Bar/scripts.pory"
	closemessage
# 134 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_SetUpShop
	return

LitorTown_Bar_EventScript_TryBuySodaPop_2:
# 121 "data/maps/LitorTown_Bar/scripts.pory"
	loadspeechtail FALSE, 1
# 122 "data/maps/LitorTown_Bar/scripts.pory"
	msgbox LitorTown_Bar_EventScript_TryBuyFreshWater_Text_0
# 123 "data/maps/LitorTown_Bar/scripts.pory"
	destroyspeechtail
# 124 "data/maps/LitorTown_Bar/scripts.pory"
	closemessage
# 125 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	goto LitorTown_Bar_EventScript_TryBuySodaPop_1


LitorTown_Bar_EventScript_TryBuyLemonade::
# 138 "data/maps/LitorTown_Bar/scripts.pory"
	checkmoney 200, 0
# 139 "data/maps/LitorTown_Bar/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LitorTown_Bar_EventScript_TryBuyLemonade_2
LitorTown_Bar_EventScript_TryBuyLemonade_1:
# 146 "data/maps/LitorTown_Bar/scripts.pory"
	playse SE_SHOP
# 147 "data/maps/LitorTown_Bar/scripts.pory"
	removemoney 350, 0
# 148 "data/maps/LitorTown_Bar/scripts.pory"
	updatemoneybox 0
# 149 "data/maps/LitorTown_Bar/scripts.pory"
	delay 30
# 150 "data/maps/LitorTown_Bar/scripts.pory"
	hidemoneybox
# 151 "data/maps/LitorTown_Bar/scripts.pory"
	giveitem ITEM_LEMONADE, 1
# 152 "data/maps/LitorTown_Bar/scripts.pory"
	closemessage
# 153 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_SetUpShop
	return

LitorTown_Bar_EventScript_TryBuyLemonade_2:
# 140 "data/maps/LitorTown_Bar/scripts.pory"
	loadspeechtail FALSE, 1
# 141 "data/maps/LitorTown_Bar/scripts.pory"
	msgbox LitorTown_Bar_EventScript_TryBuyFreshWater_Text_0
# 142 "data/maps/LitorTown_Bar/scripts.pory"
	destroyspeechtail
# 143 "data/maps/LitorTown_Bar/scripts.pory"
	closemessage
# 144 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	goto LitorTown_Bar_EventScript_TryBuyLemonade_1


LitorTown_Bar_EventScript_CancelBuyDrink::
# 157 "data/maps/LitorTown_Bar/scripts.pory"
	loadspeechtail FALSE, 1
# 158 "data/maps/LitorTown_Bar/scripts.pory"
	msgbox LitorTown_Bar_EventScript_CancelBuyDrink_Text_0
# 159 "data/maps/LitorTown_Bar/scripts.pory"
	destroyspeechtail
# 160 "data/maps/LitorTown_Bar/scripts.pory"
	closemessage
# 161 "data/maps/LitorTown_Bar/scripts.pory"
	goto LitorTown_Bar_EventScript_ExitShop
	return


LitorTown_Bar_EventScript_ExitShop::
# 165 "data/maps/LitorTown_Bar/scripts.pory"
	hidemoneybox
# 166 "data/maps/LitorTown_Bar/scripts.pory"
	special RemoveCameraObject
# 167 "data/maps/LitorTown_Bar/scripts.pory"
	release
	end


LitorTown_Bar_EventScript_Lass::
# 172 "data/maps/LitorTown_Bar/scripts.pory"
	msgbox LitorTown_Bar_EventScript_Lass_Text_0, MSGBOX_NPC
	end


LitorTown_Bar_EventScript_Sailor::
# 178 "data/maps/LitorTown_Bar/scripts.pory"
	msgbox LitorTown_Bar_EventScript_Sailor_Text_0, MSGBOX_NPC
	end


LitorTown_Bar_EventScript_TuberM::
# 184 "data/maps/LitorTown_Bar/scripts.pory"
	msgbox LitorTown_Bar_EventScript_TuberM_Text_0, MSGBOX_NPC
	end


# 189 "data/maps/LitorTown_Bar/scripts.pory"
LitorTown_Bar_Movement_MoveCameraShopView:
# 190 "data/maps/LitorTown_Bar/scripts.pory"
	walk_faster_left
# 190 "data/maps/LitorTown_Bar/scripts.pory"
	walk_faster_left
# 190 "data/maps/LitorTown_Bar/scripts.pory"
	walk_faster_left
	step_end

# 193 "data/maps/LitorTown_Bar/scripts.pory"
LitorTown_Bar_Movement_ResetCameraShopView:
# 194 "data/maps/LitorTown_Bar/scripts.pory"
	walk_faster_right
# 194 "data/maps/LitorTown_Bar/scripts.pory"
	walk_faster_right
# 194 "data/maps/LitorTown_Bar/scripts.pory"
	walk_faster_right
	step_end

LitorTown_Bar_EventScript_ChooseFreshWater_Text_0:
# 60 "data/maps/LitorTown_Bar/scripts.pory"
	.string "Is one FRESH WATER your choice?$"

LitorTown_Bar_EventScript_ChooseSodaPop_Text_0:
# 74 "data/maps/LitorTown_Bar/scripts.pory"
	.string "Is one SODA POP your choice?$"

LitorTown_Bar_EventScript_ChooseLemonade_Text_0:
# 87 "data/maps/LitorTown_Bar/scripts.pory"
	.string "Is one LEMONADA your choice?$"

LitorTown_Bar_EventScript_TryBuyFreshWater_Text_0:
# 103 "data/maps/LitorTown_Bar/scripts.pory"
	.string "You don't seem to have enough money…$"

LitorTown_Bar_EventScript_CancelBuyDrink_Text_0:
# 158 "data/maps/LitorTown_Bar/scripts.pory"
	.string "Have a nice day!$"

LitorTown_Bar_EventScript_Lass_Text_0:
# 172 "data/maps/LitorTown_Bar/scripts.pory"
	.string "The barman makes his LEMONADE with\n"
	.string "fresh lemons!$"

LitorTown_Bar_EventScript_Sailor_Text_0:
# 178 "data/maps/LitorTown_Bar/scripts.pory"
	.string "This FRESH WATER is a lot better\n"
	.string "than a mouthful of salty sea water…$"

LitorTown_Bar_EventScript_TuberM_Text_0:
# 184 "data/maps/LitorTown_Bar/scripts.pory"
	.string "My mom told me I could have a SODA POP!\n"
	.string "Yay!$"

LitorTown_Bar_Text_WelcomeToMyBar::
# 197 "data/maps/LitorTown_Bar/scripts.pory"
	.string "Welcome to the LITOR BAR!\p"
	.string "Here, you can buy the best\n"
	.string "drinks of town!$"

LitorTown_Bar_Text_WhatDoYouFancy::
# 203 "data/maps/LitorTown_Bar/scripts.pory"
	.string "What refreshment do you fancy?$"
