Route406_MapScripts::
	.byte 0


Route406_EventScript_InitializeOureaCaveStoryline::
	lock
	delay 30
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	load_speech_bubble 2
	msgbox Route406_EventScript_InitializeOureaCaveStoryline_Text_0
	destroy_speech_bubble
	closemessage
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 8
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 5
	special ShakeCameraSilent
	waitstate
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 5
	setvar VAR_0x8006, 16
	setvar VAR_0x8007, 5
	special ShakeCameraSilent
	waitstate
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCameraSilent
	waitstate
	delay 30
	applymovement 2, Route406_Movement_Hiker1LookAround
	waitmovement 0
	load_speech_bubble 2
	msgbox Route406_EventScript_InitializeOureaCaveStoryline_Text_1
	destroy_speech_bubble
	closemessage
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	applymovement 2, Route406_Movement_Hiker1RunToPlayer
	waitmovement 0
	load_speech_bubble 2
	msgbox Route406_EventScript_InitializeOureaCaveStoryline_Text_2
	destroy_speech_bubble
	closemessage
	applymovement 2, Route406_Movement_Hiker1TakePlayerToCave
	applymovement OBJ_EVENT_ID_PLAYER, Route406_Movement_PlayerWalkToCave
	waitmovement 0
	setflag FLAG_HIDE_ROUTE_406_CONSTRUCTION_WORKER
	setvar VAR_OUREA_CAVES_STATE, 1
	setvar VAR_OUREA_CAVES_LIGHTS_STATE, 1
	warp MAP_OUREA_CAVE_B2F, 5, 0, 0
	waitstate
	release
	end


Route406_EventScript_Hiker1::
	compare VAR_OUREA_CAVES_STATE, 0
	goto_if_gt Route406_EventScript_Hiker1_3
Route406_EventScript_Hiker1_2:
	msgbox Route406_EventScript_Hiker1_Text_1, MSGBOX_NPC
	end

Route406_EventScript_Hiker1_1:
	msgbox Route406_EventScript_Hiker1_Text_0, MSGBOX_NPC
	end

Route406_EventScript_Hiker1_3:
	compare VAR_OUREA_CAVES_STATE < 4, 0
	goto_if_ne Route406_EventScript_Hiker1_1
	goto Route406_EventScript_Hiker1_2


Route406_EventScript_Hiker2::
	lock
	face_down
	goto_if_set FLAG_TEMP_1, Route406_EventScript_Hiker2_2
	load_speech_bubble 1
	msgbox Route406_EventScript_Hiker2_Text_1
	destroy_speech_bubble
	closemessage
	giveitem ITEM_LEMONADE, 1
	closemessage
Route406_EventScript_Hiker2_1:
	release
	end

Route406_EventScript_Hiker2_2:
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	load_speech_bubble 1
	msgbox Route406_EventScript_Hiker2_Text_0
	destroy_speech_bubble
	closemessage
	goto Route406_EventScript_Hiker2_1


Route406_EventScript_Terrance::
	trainerbattle_single TRAINER_ROUTE406_TERRANCE, Route406_Text_TerranceIntro, Route406_Text_TerranceDefeat
	msgbox Route406_Text_TerrancePostBattle, MSGBOX_NPC
	end


Route406_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION
	end


Route406_EventScript_Sign::
	msgbox Route406_EventScript_Sign_Text_0, MSGBOX_SIGN
	end


Route406_Movement_Hiker1LookAround:
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	step_end

Route406_Movement_Hiker1RunToPlayer:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	step_end

Route406_Movement_Hiker1TakePlayerToCave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	set_invisible
	step_end

Route406_Movement_PlayerWalkToCave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

Route406_EventScript_InitializeOureaCaveStoryline_Text_0:
	.string "Earthquake! Get down!$"

Route406_EventScript_InitializeOureaCaveStoryline_Text_1:
	.string "Phew, it seems the quake settled down…$"

Route406_EventScript_InitializeOureaCaveStoryline_Text_2:
	.string "Wait… what's a kid like you\n"
	.string "doing here?!\p"
	.string "You could've gotten hurt!\p"
	.string "Come with me…$"

Route406_EventScript_Hiker1_Text_0:
	.string "Phew, that earthquake was quite\n"
	.string "heavy!\p"
	.string "I can withstand quite some more though!\n"
	.string "Hahaha!$"

Route406_EventScript_Hiker1_Text_1:
	.string "Us HIKERS belong in the mountains!\p"
	.string "On ROUTE 406 and the OUREA CAVES, I\n"
	.string "usually meet other comrades!$"

Route406_EventScript_Hiker2_Text_0:
	.string "I wonder what's down there?$"

Route406_EventScript_Hiker2_Text_1:
	.string "Hah, you thought I would fight\n"
	.string "you didn't you?\p"
	.string "Well… I could but I really don't\n"
	.string "feel like it now.\l"
	.string "Instead take a break, drink up\l"
	.string "and enjoy the view with me!$"

Route406_EventScript_Sign_Text_0:
	.string "{LEFT_ARROW} NAVIRE TOWN\n"
	.string "{UP_ARROW} OUREA CAVES$"

Route406_Text_TerranceIntro::
	.string "You know what's pretty metal?\n"
	.string "Rock climbing!$"

Route406_Text_TerranceDefeat::
	.string "You seem to be more prepared that I am…$"

Route406_Text_TerrancePostBattle::
	.string "Watch out for falling rocks in\n"
	.string "these parts.$"
