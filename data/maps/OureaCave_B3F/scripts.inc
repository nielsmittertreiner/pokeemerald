OureaCave_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	special UpdateOureaCaveTides
	call OureaCaves_EventScript_SetCaveLights
	goto_if_set FLAG_HIDE_OUREA_CAVE_B3F_ROCK1, OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 1, 7, 49
	setobjectxyperm 4, 4, 46
	setobjectmovementtype 1, MOVEMENT_TYPE_WANDER_AROUND
	setobjectmovementtype 4, MOVEMENT_TYPE_WANDER_AROUND
	return

OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_F, 0, OureaCaves_EventScript_TryShowMapNamePopup
	.2byte 0


OureaCave_B3F_EventScript_BreakableRock::
	lockall
	checkpartymove MOVE_ROCK_SMASH
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq OureaCave_B3F_EventScript_BreakableRock_2
OureaCave_B3F_EventScript_BreakableRock_1:
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OureaCave_B3F_EventScript_BreakableRock_5
OureaCave_B3F_EventScript_BreakableRock_4:
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	delay 8
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, OureaCave_B3F_Movment_BlackBeltWalkToPlayer
	applymovement 4, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto OureaCave_B3F_EventScript_KarateChopTutor
	releaseall
	end

OureaCave_B3F_EventScript_BreakableRock_2:
	goto EventScript_CantSmashRock
	goto OureaCave_B3F_EventScript_BreakableRock_1

OureaCave_B3F_EventScript_BreakableRock_5:
	goto EventScript_CancelSmash
	goto OureaCave_B3F_EventScript_BreakableRock_4


OureaCave_B3F_EventScript_KarateChopTutor::
	goto_if_set FLAG_HIDE_OUREA_CAVE_B3F_ROCK1, OureaCave_B3F_EventScript_KarateChopTutor_1
	msgbox OureaCave_B3F_EventScript_KarateChopTutor_Text_4, MSGBOX_NPC
	setobjectmovementtype 1, MOVEMENT_TYPE_RUN_IN_PLACE_LEFT
	end

OureaCave_B3F_EventScript_KarateChopTutor_1:
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_KARATE_CHOP, OureaCave_B3F_EventScript_KarateChopTutor_5
	lock
	faceplayer
	load_speech_bubble 1
	msgbox OureaCave_B3F_EventScript_KarateChopTutor_Text_1, MSGBOX_YESNO
	destroy_speech_bubble
	closemessage
	compare VAR_RESULT, NO
	goto_if_eq OureaCave_B3F_EventScript_KarateChopTutor_8
OureaCave_B3F_EventScript_KarateChopTutor_7:
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq OureaCave_B3F_EventScript_KarateChopTutor_11
OureaCave_B3F_EventScript_KarateChopTutor_10:
	load_speech_bubble 1
	msgbox OureaCave_B3F_EventScript_KarateChopTutor_Text_2
	destroy_speech_bubble
	closemessage
	setvar VAR_0x8005, TUTOR_MOVE_KARATE_CHOP
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq OureaCave_B3F_EventScript_KarateChopTutor_14
OureaCave_B3F_EventScript_KarateChopTutor_13:
	setflag FLAG_MOVE_TUTOR_TAUGHT_KARATE_CHOP
	load_speech_bubble 1
	msgbox OureaCave_B3F_EventScript_KarateChopTutor_Text_3
	destroy_speech_bubble
	closemessage
	release
	end

OureaCave_B3F_EventScript_KarateChopTutor_5:
	msgbox OureaCave_B3F_EventScript_KarateChopTutor_Text_0, MSGBOX_NPC
	end

OureaCave_B3F_EventScript_KarateChopTutor_8:
	goto OureaCave_B3F_EventScript_KarateChopDeclined
	goto OureaCave_B3F_EventScript_KarateChopTutor_7

OureaCave_B3F_EventScript_KarateChopTutor_11:
	goto OureaCave_B3F_EventScript_KarateChopDeclined
	goto OureaCave_B3F_EventScript_KarateChopTutor_10

OureaCave_B3F_EventScript_KarateChopTutor_14:
	goto OureaCave_B3F_EventScript_KarateChopDeclined
	goto OureaCave_B3F_EventScript_KarateChopTutor_13


OureaCave_B3F_EventScript_KarateChopDeclined::
	msgbox OureaCave_B3F_EventScript_KarateChopDeclined_Text_0, MSGBOX_NPC
	end


OureaCave_B3F_EventScript_BlackBelt2::
	goto_if_set FLAG_HIDE_OUREA_CAVE_B3F_ROCK1, OureaCave_B3F_EventScript_BlackBelt2_1
	msgbox OureaCave_B3F_EventScript_BlackBelt2_Text_1, MSGBOX_NPC
	setobjectmovementtype 4, MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT
	end

OureaCave_B3F_EventScript_BlackBelt2_1:
	msgbox OureaCave_B3F_EventScript_BlackBelt2_Text_0, MSGBOX_NPC
	end


OureaCave_B3F_EventScript_WarpHole::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warpholecustom MAP_OUREA_CAVE_B4F_LOW_TIDE, 15, 5
	waitstate
	end


OureaCave_B3F_EventScript_Jonathan::
	trainerbattle_single TRAINER_OUREA_CAVE_B3F_JONATHAN, OureaCave_B3F_Text_JonathanIntro, OureaCave_B3F_Text_JonathanDefeat
	msgbox OureaCave_B3F_Text_JonathanPostBattle, MSGBOX_NPC
	end


OureaCave_B3F_EventScript_Lawrence::
	trainerbattle_single TRAINER_OUREA_CAVE_B3F_LAWRENCE, OureaCave_B3F_Text_LawrenceIntro, OureaCave_B3F_Text_LawrenceDefeat
	msgbox OureaCave_B3F_Text_LawrencePostBattle, MSGBOX_NPC
	end


OureaCave_B3F_Movment_BlackBeltWalkToPlayer:
	walk_down
	face_left
	step_end

OureaCave_B3F_EventScript_KarateChopTutor_Text_0:
	.string "How'd that KARATE CHOP turn out?$"

OureaCave_B3F_EventScript_KarateChopTutor_Text_1:
	.string "Wow kid! You broke that rock like a twig!\n"
	.string "Maybe we can learn something from you?\p"
	.string "You know what, I can teach one of your\n"
	.string "POKéMON KARATE CHOP. Right?$"

OureaCave_B3F_EventScript_KarateChopTutor_Text_2:
	.string "Which POKéMON shall I teach\n"
	.string "KARATE CHOP, hmmm?$"

OureaCave_B3F_EventScript_KarateChopTutor_Text_3:
	.string "FIGHTING-type moves are super-\n"
	.string "effective against ROCK- and\l"
	.string "GROUND-types!\p"
	.string "This move will crush them.$"

OureaCave_B3F_EventScript_KarateChopTutor_Text_4:
	.string "We're black belts. We're practicing\n"
	.string "to break this rock!\p"
	.string "We're not moving until this rock\n"
	.string "is broken.$"

OureaCave_B3F_EventScript_KarateChopDeclined_Text_0:
	.string "Alright then, come back when you\n"
	.string "change your mind though.$"

OureaCave_B3F_EventScript_BlackBelt2_Text_0:
	.string "Wow! You broke that rock like it\n"
	.string "was nothing!\p"
	.string "You're really strong!$"

OureaCave_B3F_EventScript_BlackBelt2_Text_1:
	.string "We're black belts. We're practicing\n"
	.string "to break this rock!\p"
	.string "You'll be here for a while if we\n"
	.string "can't break it…$"

OureaCave_B3F_Text_JonathanIntro::
	.string "My moves are rock solid!\n"
	.string "Let's see if you can power through…$"

OureaCave_B3F_Text_JonathanDefeat::
	.string "Somehow my power has\n"
	.string "eroded before you…$"

OureaCave_B3F_Text_JonathanPostBattle::
	.string "Are my battling skills\n"
	.string "crumbling apart?$"

OureaCave_B3F_Text_LawrenceIntro::
	.string "After training here for a whole year\n"
	.string "I have become one with the mountain.$"

OureaCave_B3F_Text_LawrenceDefeat::
	.string "Another year to go it seems…$"

OureaCave_B3F_Text_LawrencePostBattle::
	.string "Come back next year and maybe we'll\n"
	.string "battle again hehe!$"
