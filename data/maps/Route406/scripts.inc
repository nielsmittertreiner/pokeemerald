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
	setflag FLAG_HIDE_ROUTE_406_HIKER1
	setvar VAR_OUREA_CAVES_STATE, 1
	setvar VAR_OUREA_CAVES_LIGHTS_STATE, 1
	warp MAP_OUREA_CAVE_B2F, 5, 0, 0
	waitstate
	release
	end


Route406_EventScript_Sign::
	msgbox Route406_EventScript_Sign_Text_0, MSGBOX_SIGN
	end


Route406_EventScript_Newt::
	trainerbattle_single TRAINER_ROUTE406_NEWT, Route406_Text_NewtIntro, Route406_Text_NewtDefeat
	msgbox Route406_Text_PostBattle, MSGBOX_NPC
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

Route406_EventScript_Sign_Text_0:
	.string "{LEFT_ARROW} NAVIRE TOWN\n"
	.string "{UP_ARROW} OUREA CAVES$"

Route406_Text_NewtIntro::
	.string "What's someone like you doing here\n"
	.string "all unprepared?$"

Route406_Text_NewtDefeat::
	.string "You seem to be more prepared that I am…$"

Route406_Text_PostBattle::
	.string "Watch out for falling rocks in\n"
	.string "these parts.$"
