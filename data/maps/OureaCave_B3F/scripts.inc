OureaCave_B3F_MapScripts::
# 5 "data/maps/OureaCave_B3F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 15 "data/maps/OureaCave_B3F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 6 "data/maps/OureaCave_B3F/scripts.pory"
	special UpdateOureaCaveTides
# 7 "data/maps/OureaCave_B3F/scripts.pory"
	call OureaCaves_EventScript_SetCaveLights
# 8 "data/maps/OureaCave_B3F/scripts.pory"
	goto_if_set FLAG_HIDE_OUREA_CAVE_B3F_ROCK1, OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 9 "data/maps/OureaCave_B3F/scripts.pory"
	setobjectxyperm 1, 7, 49
# 10 "data/maps/OureaCave_B3F/scripts.pory"
	setobjectxyperm 4, 4, 46
# 11 "data/maps/OureaCave_B3F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_WANDER_AROUND
# 12 "data/maps/OureaCave_B3F/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_WANDER_AROUND
	return

OureaCave_B3F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 16 "data/maps/OureaCave_B3F/scripts.pory"
	map_script_2 VAR_TEMP_F, 0, OureaCaves_EventScript_TryShowMapNamePopup
	.2byte 0


OureaCave_B3F_EventScript_BreakableRock::
# 21 "data/maps/OureaCave_B3F/scripts.pory"
	lockall
# 22 "data/maps/OureaCave_B3F/scripts.pory"
	checkpartymove MOVE_ROCK_SMASH
# 23 "data/maps/OureaCave_B3F/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq OureaCave_B3F_EventScript_BreakableRock_2
OureaCave_B3F_EventScript_BreakableRock_1:
# 26 "data/maps/OureaCave_B3F/scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 27 "data/maps/OureaCave_B3F/scripts.pory"
	bufferpartymonnick 0, VAR_RESULT
# 28 "data/maps/OureaCave_B3F/scripts.pory"
	buffermovename 1, MOVE_ROCK_SMASH
# 29 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox Text_WantToSmash, MSGBOX_YESNO
# 30 "data/maps/OureaCave_B3F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq OureaCave_B3F_EventScript_BreakableRock_5
OureaCave_B3F_EventScript_BreakableRock_4:
# 33 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 34 "data/maps/OureaCave_B3F/scripts.pory"
	closemessage
# 35 "data/maps/OureaCave_B3F/scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 36 "data/maps/OureaCave_B3F/scripts.pory"
	waitstate
# 37 "data/maps/OureaCave_B3F/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 38 "data/maps/OureaCave_B3F/scripts.pory"
	waitmovement 0
# 39 "data/maps/OureaCave_B3F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 40 "data/maps/OureaCave_B3F/scripts.pory"
	playse SE_PIN
# 41 "data/maps/OureaCave_B3F/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 42 "data/maps/OureaCave_B3F/scripts.pory"
	delay 8
# 43 "data/maps/OureaCave_B3F/scripts.pory"
	playse SE_PIN
# 44 "data/maps/OureaCave_B3F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 45 "data/maps/OureaCave_B3F/scripts.pory"
	waitmovement 0
# 46 "data/maps/OureaCave_B3F/scripts.pory"
	applymovement 1, OureaCave_B3F_Movment_BlackBeltWalkToPlayer
# 47 "data/maps/OureaCave_B3F/scripts.pory"
	applymovement 4, Common_Movement_FaceDown
# 48 "data/maps/OureaCave_B3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 49 "data/maps/OureaCave_B3F/scripts.pory"
	waitmovement 0
# 50 "data/maps/OureaCave_B3F/scripts.pory"
	goto OureaCave_B3F_EventScript_KarateChopTutor
# 51 "data/maps/OureaCave_B3F/scripts.pory"
	releaseall
	end

OureaCave_B3F_EventScript_BreakableRock_2:
# 24 "data/maps/OureaCave_B3F/scripts.pory"
	goto EventScript_CantSmashRock
	goto OureaCave_B3F_EventScript_BreakableRock_1

OureaCave_B3F_EventScript_BreakableRock_5:
# 31 "data/maps/OureaCave_B3F/scripts.pory"
	goto EventScript_CancelSmash
	goto OureaCave_B3F_EventScript_BreakableRock_4


OureaCave_B3F_EventScript_KarateChopTutor::
# 56 "data/maps/OureaCave_B3F/scripts.pory"
	goto_if_set FLAG_HIDE_OUREA_CAVE_B3F_ROCK1, OureaCave_B3F_EventScript_KarateChopTutor_1
# 98 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox OureaCave_B3F_EventScript_KarateChopTutor_Text_4, MSGBOX_NPC
# 102 "data/maps/OureaCave_B3F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_RUN_IN_PLACE_LEFT
	end

OureaCave_B3F_EventScript_KarateChopTutor_1:
# 57 "data/maps/OureaCave_B3F/scripts.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_KARATE_CHOP, OureaCave_B3F_EventScript_KarateChopTutor_5
# 61 "data/maps/OureaCave_B3F/scripts.pory"
	lock
# 62 "data/maps/OureaCave_B3F/scripts.pory"
	faceplayer
# 63 "data/maps/OureaCave_B3F/scripts.pory"
	loadspeechtail FALSE, 1
# 64 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox OureaCave_B3F_EventScript_KarateChopTutor_Text_1, MSGBOX_YESNO
# 68 "data/maps/OureaCave_B3F/scripts.pory"
	destroyspeechtail
# 69 "data/maps/OureaCave_B3F/scripts.pory"
	closemessage
# 70 "data/maps/OureaCave_B3F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq OureaCave_B3F_EventScript_KarateChopTutor_8
OureaCave_B3F_EventScript_KarateChopTutor_7:
# 73 "data/maps/OureaCave_B3F/scripts.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 74 "data/maps/OureaCave_B3F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq OureaCave_B3F_EventScript_KarateChopTutor_11
OureaCave_B3F_EventScript_KarateChopTutor_10:
# 77 "data/maps/OureaCave_B3F/scripts.pory"
	loadspeechtail FALSE, 1
# 78 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox OureaCave_B3F_EventScript_KarateChopTutor_Text_2
# 80 "data/maps/OureaCave_B3F/scripts.pory"
	destroyspeechtail
# 81 "data/maps/OureaCave_B3F/scripts.pory"
	closemessage
# 82 "data/maps/OureaCave_B3F/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_KARATE_CHOP
# 83 "data/maps/OureaCave_B3F/scripts.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 84 "data/maps/OureaCave_B3F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq OureaCave_B3F_EventScript_KarateChopTutor_14
OureaCave_B3F_EventScript_KarateChopTutor_13:
# 87 "data/maps/OureaCave_B3F/scripts.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_KARATE_CHOP
# 88 "data/maps/OureaCave_B3F/scripts.pory"
	loadspeechtail FALSE, 1
# 89 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox OureaCave_B3F_EventScript_KarateChopTutor_Text_3
# 93 "data/maps/OureaCave_B3F/scripts.pory"
	destroyspeechtail
# 94 "data/maps/OureaCave_B3F/scripts.pory"
	closemessage
# 95 "data/maps/OureaCave_B3F/scripts.pory"
	release
	end

OureaCave_B3F_EventScript_KarateChopTutor_5:
# 58 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox OureaCave_B3F_EventScript_KarateChopTutor_Text_0, MSGBOX_NPC
	end

OureaCave_B3F_EventScript_KarateChopTutor_8:
# 71 "data/maps/OureaCave_B3F/scripts.pory"
	goto OureaCave_B3F_EventScript_KarateChopDeclined
	goto OureaCave_B3F_EventScript_KarateChopTutor_7

OureaCave_B3F_EventScript_KarateChopTutor_11:
# 75 "data/maps/OureaCave_B3F/scripts.pory"
	goto OureaCave_B3F_EventScript_KarateChopDeclined
	goto OureaCave_B3F_EventScript_KarateChopTutor_10

OureaCave_B3F_EventScript_KarateChopTutor_14:
# 85 "data/maps/OureaCave_B3F/scripts.pory"
	goto OureaCave_B3F_EventScript_KarateChopDeclined
	goto OureaCave_B3F_EventScript_KarateChopTutor_13


OureaCave_B3F_EventScript_KarateChopDeclined::
# 108 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox OureaCave_B3F_EventScript_KarateChopDeclined_Text_0, MSGBOX_NPC
	end


OureaCave_B3F_EventScript_BlackBelt2::
# 114 "data/maps/OureaCave_B3F/scripts.pory"
	goto_if_set FLAG_HIDE_OUREA_CAVE_B3F_ROCK1, OureaCave_B3F_EventScript_BlackBelt2_1
# 120 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox OureaCave_B3F_EventScript_BlackBelt2_Text_1, MSGBOX_NPC
# 124 "data/maps/OureaCave_B3F/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT
	end

OureaCave_B3F_EventScript_BlackBelt2_1:
# 115 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox OureaCave_B3F_EventScript_BlackBelt2_Text_0, MSGBOX_NPC
	end


OureaCave_B3F_EventScript_WarpHole::
# 130 "data/maps/OureaCave_B3F/scripts.pory"
	lockall
# 131 "data/maps/OureaCave_B3F/scripts.pory"
	delay 20
# 132 "data/maps/OureaCave_B3F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
# 133 "data/maps/OureaCave_B3F/scripts.pory"
	waitmovement 0
# 134 "data/maps/OureaCave_B3F/scripts.pory"
	playse SE_FALL
# 135 "data/maps/OureaCave_B3F/scripts.pory"
	delay 60
# 136 "data/maps/OureaCave_B3F/scripts.pory"
	warpholecustom MAP_OUREA_CAVE_B4F_LOW_TIDE, 15, 5
# 137 "data/maps/OureaCave_B3F/scripts.pory"
	waitstate
	end


OureaCave_B3F_EventScript_Jonathan::
# 142 "data/maps/OureaCave_B3F/scripts.pory"
	trainerbattle_single TRAINER_OUREA_CAVE_B3F_JONATHAN, OureaCave_B3F_Text_JonathanIntro, OureaCave_B3F_Text_JonathanDefeat
# 143 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox OureaCave_B3F_Text_JonathanPostBattle, MSGBOX_NPC
	end


OureaCave_B3F_EventScript_Lawrence::
# 148 "data/maps/OureaCave_B3F/scripts.pory"
	trainerbattle_single TRAINER_OUREA_CAVE_B3F_LAWRENCE, OureaCave_B3F_Text_LawrenceIntro, OureaCave_B3F_Text_LawrenceDefeat
# 149 "data/maps/OureaCave_B3F/scripts.pory"
	msgbox OureaCave_B3F_Text_LawrencePostBattle, MSGBOX_NPC
	end


# 153 "data/maps/OureaCave_B3F/scripts.pory"
OureaCave_B3F_Movment_BlackBeltWalkToPlayer:
# 154 "data/maps/OureaCave_B3F/scripts.pory"
	walk_down
# 155 "data/maps/OureaCave_B3F/scripts.pory"
	face_left
	step_end

OureaCave_B3F_EventScript_KarateChopTutor_Text_0:
# 58 "data/maps/OureaCave_B3F/scripts.pory"
	.string "How'd that KARATE CHOP turn out?$"

OureaCave_B3F_EventScript_KarateChopTutor_Text_1:
# 64 "data/maps/OureaCave_B3F/scripts.pory"
	.string "Wow kid! You broke that rock like a twig!\n"
	.string "Maybe we can learn something from you?\p"
	.string "You know what, I can teach one of your\n"
	.string "POKéMON KARATE CHOP. Right?$"

OureaCave_B3F_EventScript_KarateChopTutor_Text_2:
# 78 "data/maps/OureaCave_B3F/scripts.pory"
	.string "Which POKéMON shall I teach\n"
	.string "KARATE CHOP, hmmm?$"

OureaCave_B3F_EventScript_KarateChopTutor_Text_3:
# 89 "data/maps/OureaCave_B3F/scripts.pory"
	.string "FIGHTING-type moves are super-\n"
	.string "effective against ROCK- and\l"
	.string "GROUND-types!\p"
	.string "This move will crush them.$"

OureaCave_B3F_EventScript_KarateChopTutor_Text_4:
# 98 "data/maps/OureaCave_B3F/scripts.pory"
	.string "We're black belts. We're practicing\n"
	.string "to break this rock!\p"
	.string "We're not moving until this rock\n"
	.string "is broken.$"

OureaCave_B3F_EventScript_KarateChopDeclined_Text_0:
# 108 "data/maps/OureaCave_B3F/scripts.pory"
	.string "Alright then, come back when you\n"
	.string "change your mind though.$"

OureaCave_B3F_EventScript_BlackBelt2_Text_0:
# 115 "data/maps/OureaCave_B3F/scripts.pory"
	.string "Wow! You broke that rock like it\n"
	.string "was nothing!\p"
	.string "You're really strong!$"

OureaCave_B3F_EventScript_BlackBelt2_Text_1:
# 120 "data/maps/OureaCave_B3F/scripts.pory"
	.string "We're black belts. We're practicing\n"
	.string "to break this rock!\p"
	.string "You'll be here for a while if we\n"
	.string "can't break it…$"

OureaCave_B3F_Text_JonathanIntro::
# 158 "data/maps/OureaCave_B3F/scripts.pory"
	.string "My moves are rock solid!\n"
	.string "Let's see if you can power through…$"

OureaCave_B3F_Text_JonathanDefeat::
# 163 "data/maps/OureaCave_B3F/scripts.pory"
	.string "Somehow my power has\p"
	.string "eroded before you…$"

OureaCave_B3F_Text_JonathanPostBattle::
# 168 "data/maps/OureaCave_B3F/scripts.pory"
	.string "Are my battling skills\n"
	.string "crumbling apart?$"

OureaCave_B3F_Text_LawrenceIntro::
# 173 "data/maps/OureaCave_B3F/scripts.pory"
	.string "After training here for a whole year\n"
	.string "I have become one with the mountain.$"

OureaCave_B3F_Text_LawrenceDefeat::
# 178 "data/maps/OureaCave_B3F/scripts.pory"
	.string "Another year to go it seems…$"

OureaCave_B3F_Text_LawrencePostBattle::
# 182 "data/maps/OureaCave_B3F/scripts.pory"
	.string "Come back next year and maybe we'll\n"
	.string "battle again hehe!$"
