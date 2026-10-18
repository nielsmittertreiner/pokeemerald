FirwealdCity_Mart_MapScripts::
	.byte 0


FirwealdCity_Mart_EventScript_Clerk::
# 7 "data/maps/FirwealdCity_Mart/scripts.pory"
	lock
# 8 "data/maps/FirwealdCity_Mart/scripts.pory"
	faceplayer
# 9 "data/maps/FirwealdCity_Mart/scripts.pory"
	loadspeechtail FALSE, 1
# 10 "data/maps/FirwealdCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 11 "data/maps/FirwealdCity_Mart/scripts.pory"
	waitmessage
# 12 "data/maps/FirwealdCity_Mart/scripts.pory"
	pokemart FirwealdCity_Mart_Pokemart
# 13 "data/maps/FirwealdCity_Mart/scripts.pory"
	destroyspeechtail
# 14 "data/maps/FirwealdCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_NPC
# 15 "data/maps/FirwealdCity_Mart/scripts.pory"
	release
	end


# 19 "data/maps/FirwealdCity_Mart/scripts.pory"

# 20 "data/maps/FirwealdCity_Mart/scripts.pory"
FirwealdCity_Mart_Pokemart:
# 21 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_GREAT_BALL
# 22 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_POKE_BALL
# 23 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_POTION
# 24 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_ANTIDOTE
# 25 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_PARALYZE_HEAL
# 26 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_AWAKENING
# 27 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_ESCAPE_ROPE
# 28 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_REPEL
# 29 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_X_ATTACK
# 30 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_X_DEFEND
# 31 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_DIRE_HIT
# 32 "data/maps/FirwealdCity_Mart/scripts.pory"
    .2byte ITEM_NONE
# 33 "data/maps/FirwealdCity_Mart/scripts.pory"
    release
# 34 "data/maps/FirwealdCity_Mart/scripts.pory"
    end

FirwealdCity_Mart_EventScript_Fisherman::
# 38 "data/maps/FirwealdCity_Mart/scripts.pory"
	lock
# 39 "data/maps/FirwealdCity_Mart/scripts.pory"
	playse SE_PIN
# 40 "data/maps/FirwealdCity_Mart/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 41 "data/maps/FirwealdCity_Mart/scripts.pory"
	waitmovement 0
# 42 "data/maps/FirwealdCity_Mart/scripts.pory"
	faceplayer
# 43 "data/maps/FirwealdCity_Mart/scripts.pory"
	loadspeechtail FALSE, 2
# 44 "data/maps/FirwealdCity_Mart/scripts.pory"
	msgbox FirwealdCity_Mart_EventScript_Fisherman_Text_0, MSGBOX_DEFAULT
# 47 "data/maps/FirwealdCity_Mart/scripts.pory"
	destroyspeechtail
# 48 "data/maps/FirwealdCity_Mart/scripts.pory"
	closemessage
# 49 "data/maps/FirwealdCity_Mart/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq FirwealdCity_Mart_EventScript_Fisherman_2
FirwealdCity_Mart_EventScript_Fisherman_1:
# 53 "data/maps/FirwealdCity_Mart/scripts.pory"
	applymovement 2, FirwealdCity_Mart_Movement_FishermanWalkToEmployee
# 54 "data/maps/FirwealdCity_Mart/scripts.pory"
	waitmovement 0
# 55 "data/maps/FirwealdCity_Mart/scripts.pory"
	loadspeechtail FALSE, 2
# 56 "data/maps/FirwealdCity_Mart/scripts.pory"
	msgbox FirwealdCity_Mart_EventScript_Fisherman_Text_1, MSGBOX_DEFAULT
# 58 "data/maps/FirwealdCity_Mart/scripts.pory"
	destroyspeechtail
# 59 "data/maps/FirwealdCity_Mart/scripts.pory"
	closemessage
# 60 "data/maps/FirwealdCity_Mart/scripts.pory"
	turnobject 1, DIR_SOUTH
# 61 "data/maps/FirwealdCity_Mart/scripts.pory"
	applymovement 2, FirwealdCity_Mart_Movement_FishermanWalkToExit
# 62 "data/maps/FirwealdCity_Mart/scripts.pory"
	waitmovement 0
# 63 "data/maps/FirwealdCity_Mart/scripts.pory"
	playse SE_EXIT
# 64 "data/maps/FirwealdCity_Mart/scripts.pory"
	removeobject 2, MAP_FIRWEALD_CITY_MART
# 65 "data/maps/FirwealdCity_Mart/scripts.pory"
	clearflag FLAG_HIDE_FIRWEALD_CITY_FISHERMAN
# 66 "data/maps/FirwealdCity_Mart/scripts.pory"
	release
	end

FirwealdCity_Mart_EventScript_Fisherman_2:
# 50 "data/maps/FirwealdCity_Mart/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_Mart_Movement_PlayerWalkDownBackwards
# 51 "data/maps/FirwealdCity_Mart/scripts.pory"
	waitmovement 0
	goto FirwealdCity_Mart_EventScript_Fisherman_1


FirwealdCity_Mart_EventScript_Triathlete::
# 71 "data/maps/FirwealdCity_Mart/scripts.pory"
	msgbox FirwealdCity_Mart_EventScript_Triathlete_Text_0, MSGBOX_NPC
	end


# 77 "data/maps/FirwealdCity_Mart/scripts.pory"
FirwealdCity_Mart_Movement_FishermanWalkToEmployee:
# 78 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_down
# 79 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_left
# 79 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_left
# 79 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_left
# 80 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_up
# 81 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_left
# 81 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_left
# 82 "data/maps/FirwealdCity_Mart/scripts.pory"
	face_up
	step_end

# 85 "data/maps/FirwealdCity_Mart/scripts.pory"
FirwealdCity_Mart_Movement_PlayerWalkDownBackwards:
# 86 "data/maps/FirwealdCity_Mart/scripts.pory"
	lock_facing_direction
# 87 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_down
	step_end

# 90 "data/maps/FirwealdCity_Mart/scripts.pory"
FirwealdCity_Mart_Movement_FishermanWalkToExit:
# 91 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_down
# 91 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_down
# 91 "data/maps/FirwealdCity_Mart/scripts.pory"
	walk_down
	step_end

FirwealdCity_Mart_EventScript_Fisherman_Text_0:
# 44 "data/maps/FirwealdCity_Mart/scripts.pory"
	.string "Ah, there it is!\p"
	.string "Some high quality fishing bait.\p"
	.string "Now I hope I can catch that GOLDEEN!$"

FirwealdCity_Mart_EventScript_Fisherman_Text_1:
# 56 "data/maps/FirwealdCity_Mart/scripts.pory"
	.string "Thanks a lot!\n"
	.string "Have a nice day!$"

FirwealdCity_Mart_EventScript_Triathlete_Text_0:
# 71 "data/maps/FirwealdCity_Mart/scripts.pory"
	.string "I love the new POKENERGY drink\n"
	.string "that's being sold now!\p"
	.string "It tastes so good!$"
