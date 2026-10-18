Route406_MapScripts::
	.byte 0


Route406_EventScript_InitializeOureaCaveStoryline::
# 8 "data/maps/Route406/scripts.pory"
	lock
# 9 "data/maps/Route406/scripts.pory"
	delay 30
# 10 "data/maps/Route406/scripts.pory"
	playse SE_PIN
# 11 "data/maps/Route406/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 12 "data/maps/Route406/scripts.pory"
	waitmovement 0
# 13 "data/maps/Route406/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 14 "data/maps/Route406/scripts.pory"
	waitmovement 0
# 15 "data/maps/Route406/scripts.pory"
	loadspeechtail FALSE, 2
# 16 "data/maps/Route406/scripts.pory"
	msgbox Route406_EventScript_InitializeOureaCaveStoryline_Text_0
# 17 "data/maps/Route406/scripts.pory"
	destroyspeechtail
# 18 "data/maps/Route406/scripts.pory"
	closemessage
# 19 "data/maps/Route406/scripts.pory"
	playse SE_M_EARTHQUAKE
# 20 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8004, 0
# 21 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8005, 8
# 22 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8006, 20
# 23 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8007, 5
# 24 "data/maps/Route406/scripts.pory"
	special ShakeCameraSilent
# 25 "data/maps/Route406/scripts.pory"
	waitstate
# 26 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8004, 0
# 27 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8005, 5
# 28 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8006, 16
# 29 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8007, 5
# 30 "data/maps/Route406/scripts.pory"
	special ShakeCameraSilent
# 31 "data/maps/Route406/scripts.pory"
	waitstate
# 32 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8004, 0
# 33 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8005, 3
# 34 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8006, 8
# 35 "data/maps/Route406/scripts.pory"
	setvar VAR_0x8007, 5
# 36 "data/maps/Route406/scripts.pory"
	special ShakeCameraSilent
# 37 "data/maps/Route406/scripts.pory"
	waitstate
# 38 "data/maps/Route406/scripts.pory"
	delay 30
# 39 "data/maps/Route406/scripts.pory"
	applymovement 2, Route406_Movement_Hiker1LookAround
# 40 "data/maps/Route406/scripts.pory"
	waitmovement 0
# 41 "data/maps/Route406/scripts.pory"
	loadspeechtail FALSE, 2
# 42 "data/maps/Route406/scripts.pory"
	msgbox Route406_EventScript_InitializeOureaCaveStoryline_Text_1
# 43 "data/maps/Route406/scripts.pory"
	destroyspeechtail
# 44 "data/maps/Route406/scripts.pory"
	closemessage
# 45 "data/maps/Route406/scripts.pory"
	playse SE_PIN
# 46 "data/maps/Route406/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 47 "data/maps/Route406/scripts.pory"
	waitmovement 0
# 48 "data/maps/Route406/scripts.pory"
	delay 30
# 49 "data/maps/Route406/scripts.pory"
	applymovement 2, Route406_Movement_Hiker1RunToPlayer
# 50 "data/maps/Route406/scripts.pory"
	waitmovement 0
# 51 "data/maps/Route406/scripts.pory"
	loadspeechtail FALSE, 2
# 52 "data/maps/Route406/scripts.pory"
	msgbox Route406_EventScript_InitializeOureaCaveStoryline_Text_2
# 56 "data/maps/Route406/scripts.pory"
	destroyspeechtail
# 57 "data/maps/Route406/scripts.pory"
	closemessage
# 58 "data/maps/Route406/scripts.pory"
	applymovement 2, Route406_Movement_Hiker1TakePlayerToCave
# 59 "data/maps/Route406/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route406_Movement_PlayerWalkToCave
# 60 "data/maps/Route406/scripts.pory"
	waitmovement 0
# 61 "data/maps/Route406/scripts.pory"
	setflag FLAG_HIDE_ROUTE_406_CONSTRUCTION_WORKER
# 62 "data/maps/Route406/scripts.pory"
	setvar VAR_OUREA_CAVES_STATE, 1
# 63 "data/maps/Route406/scripts.pory"
	setvar VAR_OUREA_CAVES_LIGHTS_STATE, 1
# 64 "data/maps/Route406/scripts.pory"
	warp MAP_OUREA_CAVE_B2F, 5, 0, 0
# 65 "data/maps/Route406/scripts.pory"
	waitstate
# 66 "data/maps/Route406/scripts.pory"
	release
	end


Route406_EventScript_Hiker1::
# 71 "data/maps/Route406/scripts.pory"
	compare VAR_OUREA_CAVES_STATE, 0
	goto_if_gt Route406_EventScript_Hiker1_3
Route406_EventScript_Hiker1_2:
# 78 "data/maps/Route406/scripts.pory"
	msgbox Route406_EventScript_Hiker1_Text_1, MSGBOX_NPC
	end

Route406_EventScript_Hiker1_1:
# 72 "data/maps/Route406/scripts.pory"
	msgbox Route406_EventScript_Hiker1_Text_0, MSGBOX_NPC
	end

Route406_EventScript_Hiker1_3:
# 71 "data/maps/Route406/scripts.pory"
	compare VAR_OUREA_CAVES_STATE < 4, 0
	goto_if_ne Route406_EventScript_Hiker1_1
	goto Route406_EventScript_Hiker1_2


Route406_EventScript_Hiker2::
# 86 "data/maps/Route406/scripts.pory"
	lock
# 87 "data/maps/Route406/scripts.pory"
	face_down
# 88 "data/maps/Route406/scripts.pory"
	goto_if_set FLAG_TEMP_1, Route406_EventScript_Hiker2_2
# 99 "data/maps/Route406/scripts.pory"
	loadspeechtail FALSE, 1
# 100 "data/maps/Route406/scripts.pory"
	msgbox Route406_EventScript_Hiker2_Text_1
# 106 "data/maps/Route406/scripts.pory"
	destroyspeechtail
# 107 "data/maps/Route406/scripts.pory"
	closemessage
# 108 "data/maps/Route406/scripts.pory"
	giveitem ITEM_LEMONADE, 1
# 109 "data/maps/Route406/scripts.pory"
	closemessage
Route406_EventScript_Hiker2_1:
# 111 "data/maps/Route406/scripts.pory"
	release
	end

Route406_EventScript_Hiker2_2:
# 89 "data/maps/Route406/scripts.pory"
	applymovement 1, Common_Movement_FaceLeft
# 90 "data/maps/Route406/scripts.pory"
	waitmovement 0
# 91 "data/maps/Route406/scripts.pory"
	delay 60
# 92 "data/maps/Route406/scripts.pory"
	applymovement 1, Common_Movement_FaceRight
# 93 "data/maps/Route406/scripts.pory"
	waitmovement 0
# 94 "data/maps/Route406/scripts.pory"
	loadspeechtail FALSE, 1
# 95 "data/maps/Route406/scripts.pory"
	msgbox Route406_EventScript_Hiker2_Text_0
# 96 "data/maps/Route406/scripts.pory"
	destroyspeechtail
# 97 "data/maps/Route406/scripts.pory"
	closemessage
	goto Route406_EventScript_Hiker2_1


Route406_EventScript_Terrance::
# 116 "data/maps/Route406/scripts.pory"
	trainerbattle_single TRAINER_ROUTE406_TERRANCE, Route406_Text_TerranceIntro, Route406_Text_TerranceDefeat
# 117 "data/maps/Route406/scripts.pory"
	msgbox Route406_Text_TerrancePostBattle, MSGBOX_NPC
	end


Route406_EventScript_ItemSuperPotion::
# 122 "data/maps/Route406/scripts.pory"
	finditem ITEM_SUPER_POTION
	end


Route406_EventScript_Sign::
# 127 "data/maps/Route406/scripts.pory"
	msgbox Route406_EventScript_Sign_Text_0, MSGBOX_SIGN
	end


# 132 "data/maps/Route406/scripts.pory"
Route406_Movement_Hiker1LookAround:
# 133 "data/maps/Route406/scripts.pory"
	face_left
# 134 "data/maps/Route406/scripts.pory"
	delay_16
# 135 "data/maps/Route406/scripts.pory"
	delay_16
# 136 "data/maps/Route406/scripts.pory"
	face_right
# 137 "data/maps/Route406/scripts.pory"
	delay_16
# 138 "data/maps/Route406/scripts.pory"
	delay_16
# 139 "data/maps/Route406/scripts.pory"
	face_left
# 140 "data/maps/Route406/scripts.pory"
	delay_16
# 141 "data/maps/Route406/scripts.pory"
	delay_16
# 142 "data/maps/Route406/scripts.pory"
	face_right
# 143 "data/maps/Route406/scripts.pory"
	delay_16
	step_end

# 146 "data/maps/Route406/scripts.pory"
Route406_Movement_Hiker1RunToPlayer:
# 147 "data/maps/Route406/scripts.pory"
	walk_fast_right
# 147 "data/maps/Route406/scripts.pory"
	walk_fast_right
# 147 "data/maps/Route406/scripts.pory"
	walk_fast_right
# 148 "data/maps/Route406/scripts.pory"
	face_up
	step_end

# 151 "data/maps/Route406/scripts.pory"
Route406_Movement_Hiker1TakePlayerToCave:
# 152 "data/maps/Route406/scripts.pory"
	walk_left
# 152 "data/maps/Route406/scripts.pory"
	walk_left
# 152 "data/maps/Route406/scripts.pory"
	walk_left
# 152 "data/maps/Route406/scripts.pory"
	walk_left
# 152 "data/maps/Route406/scripts.pory"
	walk_left
# 152 "data/maps/Route406/scripts.pory"
	walk_left
# 153 "data/maps/Route406/scripts.pory"
	walk_up
# 154 "data/maps/Route406/scripts.pory"
	set_invisible
	step_end

# 157 "data/maps/Route406/scripts.pory"
Route406_Movement_PlayerWalkToCave:
# 158 "data/maps/Route406/scripts.pory"
	walk_down
# 159 "data/maps/Route406/scripts.pory"
	walk_left
# 159 "data/maps/Route406/scripts.pory"
	walk_left
# 159 "data/maps/Route406/scripts.pory"
	walk_left
# 159 "data/maps/Route406/scripts.pory"
	walk_left
# 159 "data/maps/Route406/scripts.pory"
	walk_left
# 159 "data/maps/Route406/scripts.pory"
	walk_left
# 160 "data/maps/Route406/scripts.pory"
	walk_up
	step_end

Route406_EventScript_InitializeOureaCaveStoryline_Text_0:
# 16 "data/maps/Route406/scripts.pory"
	.string "Earthquake! Get down!$"

Route406_EventScript_InitializeOureaCaveStoryline_Text_1:
# 42 "data/maps/Route406/scripts.pory"
	.string "Phew, it seems the quake settled down…$"

Route406_EventScript_InitializeOureaCaveStoryline_Text_2:
# 52 "data/maps/Route406/scripts.pory"
	.string "Wait… what's a kid like you\n"
	.string "doing here?!\p"
	.string "You could've gotten hurt!\p"
	.string "Come with me…$"

Route406_EventScript_Hiker1_Text_0:
# 72 "data/maps/Route406/scripts.pory"
	.string "Phew, that earthquake was quite\n"
	.string "heavy!\p"
	.string "I can withstand quite some more though!\n"
	.string "Hahaha!$"

Route406_EventScript_Hiker1_Text_1:
# 78 "data/maps/Route406/scripts.pory"
	.string "Us HIKERS belong in the mountains!\p"
	.string "On ROUTE 406 and the OUREA CAVES, I\n"
	.string "usually meet other comrades!$"

Route406_EventScript_Hiker2_Text_0:
# 95 "data/maps/Route406/scripts.pory"
	.string "I wonder what's down there?$"

Route406_EventScript_Hiker2_Text_1:
# 100 "data/maps/Route406/scripts.pory"
	.string "Hah, you thought I would fight\n"
	.string "you didn't you?\p"
	.string "Well… I could but I really don't\n"
	.string "feel like it now.\l"
	.string "Instead take a break, drink up\l"
	.string "and enjoy the view with me!$"

Route406_EventScript_Sign_Text_0:
# 127 "data/maps/Route406/scripts.pory"
	.string "{LEFT_ARROW} NAVIRE TOWN\n"
	.string "{UP_ARROW} OUREA CAVES$"

Route406_Text_TerranceIntro::
# 163 "data/maps/Route406/scripts.pory"
	.string "You know what's pretty metal?\n"
	.string "Rock climbing!$"

Route406_Text_TerranceDefeat::
# 168 "data/maps/Route406/scripts.pory"
	.string "You seem to be more prepared that I am…$"

Route406_Text_TerrancePostBattle::
# 172 "data/maps/Route406/scripts.pory"
	.string "Watch out for falling rocks in\n"
	.string "these parts.$"
