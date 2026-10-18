AcrenForest_PlantShop_MapScripts::
	.byte 0


AcrenForest_PlantShop_EventScript_ShopOwner::
# 8 "data/maps/AcrenForest_PlantShop/scripts.pory"
	compare VAR_JULIA_STATE, 0
	goto_if_eq AcrenForest_PlantShop_EventScript_ShopOwner_2
# 92 "data/maps/AcrenForest_PlantShop/scripts.pory"
	loadspeechtail FALSE, 1
# 93 "data/maps/AcrenForest_PlantShop/scripts.pory"
	message AcrenForest_PlantShop_EventScript_ShopOwner_Text_4
# 95 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmessage
# 96 "data/maps/AcrenForest_PlantShop/scripts.pory"
	pokemartdecoration AcrenForest_PlantShop_PokemartDecor_Plants
# 97 "data/maps/AcrenForest_PlantShop/scripts.pory"
	destroyspeechtail
# 98 "data/maps/AcrenForest_PlantShop/scripts.pory"
	msgbox AcrenForest_PlantShop_EventScript_ShopOwner_Text_5, MSGBOX_NPC
# 99 "data/maps/AcrenForest_PlantShop/scripts.pory"
	release
	end

AcrenForest_PlantShop_EventScript_ShopOwner_2:
# 9 "data/maps/AcrenForest_PlantShop/scripts.pory"
	lock
# 10 "data/maps/AcrenForest_PlantShop/scripts.pory"
	faceplayer
# 11 "data/maps/AcrenForest_PlantShop/scripts.pory"
	playse SE_EXIT
# 12 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
# 13 "data/maps/AcrenForest_PlantShop/scripts.pory"
	addobject 4
# 14 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setobjectxy 4, 2, 7
# 15 "data/maps/AcrenForest_PlantShop/scripts.pory"
	delay 45
# 16 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement 4, AcrenForest_PlantShop_Movement_JuliaWalkToPlayer
# 17 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmovement 0
# 18 "data/maps/AcrenForest_PlantShop/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 19 "data/maps/AcrenForest_PlantShop/scripts.pory"
	loadspeechtail FALSE, 4
# 20 "data/maps/AcrenForest_PlantShop/scripts.pory"
	msgbox AcrenForest_PlantShop_EventScript_ShopOwner_Text_0
# 25 "data/maps/AcrenForest_PlantShop/scripts.pory"
	destroyspeechtail
# 26 "data/maps/AcrenForest_PlantShop/scripts.pory"
	closemessage
# 27 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AcrenForest_PlantShop_Movement_PlayerWalkUpBackwards
# 28 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement 4, Common_Movement_WalkUp
# 29 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmovement 0
# 30 "data/maps/AcrenForest_PlantShop/scripts.pory"
	turnobject 4, DIR_WEST
# 31 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceLeft
# 32 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmovement 0
# 33 "data/maps/AcrenForest_PlantShop/scripts.pory"
	delay 15
# 34 "data/maps/AcrenForest_PlantShop/scripts.pory"
	turnobject 1, DIR_SOUTH
# 35 "data/maps/AcrenForest_PlantShop/scripts.pory"
	playse SE_DOOR
# 36 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setmetatile 0, 4, METATILE_PrettyPetalFlowerShop_Counter_OpenTop, 0
# 37 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setmetatile 0, 5, METATILE_PrettyPetalFlowerShop_Counter_OpenBottom, 0
# 38 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setmetatile 0, 6, METATILE_PrettyPetalFlowerShop_Shadow_Wall, 0
# 39 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setmetatile 1, 6, METATILE_PrettyPetalFlowerShop_Shadow_Angle, 0
# 40 "data/maps/AcrenForest_PlantShop/scripts.pory"
	special DrawWholeMapView
# 41 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement 1, AcrenForest_PlantShop_Movement_ShopOwnerWalkToJulia
# 42 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmovement 0
# 43 "data/maps/AcrenForest_PlantShop/scripts.pory"
	turnobject 4, DIR_SOUTH
# 44 "data/maps/AcrenForest_PlantShop/scripts.pory"
	delay 15
# 45 "data/maps/AcrenForest_PlantShop/scripts.pory"
	loadspeechtail FALSE, 4
# 46 "data/maps/AcrenForest_PlantShop/scripts.pory"
	msgbox AcrenForest_PlantShop_EventScript_ShopOwner_Text_1
# 48 "data/maps/AcrenForest_PlantShop/scripts.pory"
	destroyspeechtail
# 49 "data/maps/AcrenForest_PlantShop/scripts.pory"
	closemessage
# 50 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement 1, AcrenForest_PlantShop_Movement_ShopOwnerWalkBehindCounter
# 51 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmovement 0
# 52 "data/maps/AcrenForest_PlantShop/scripts.pory"
	turnobject 1, DIR_SOUTH
# 53 "data/maps/AcrenForest_PlantShop/scripts.pory"
	playse SE_DOOR
# 54 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setmetatile 0, 4, METATILE_PrettyPetalFlowerShop_Counter_ClosedTop, 0
# 55 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setmetatile 0, 5, METATILE_PrettyPetalFlowerShop_Counter_ClosedBottom, 1
# 56 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setmetatile 0, 6, METATILE_PrettyPetalFlowerShop_Shadow_Counter, 0
# 57 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setmetatile 1, 6, METATILE_PrettyPetalFlowerShop_Shadow_Top, 0
# 58 "data/maps/AcrenForest_PlantShop/scripts.pory"
	special DrawWholeMapView
# 59 "data/maps/AcrenForest_PlantShop/scripts.pory"
	turnobject 1, DIR_EAST
# 60 "data/maps/AcrenForest_PlantShop/scripts.pory"
	delay 15
# 61 "data/maps/AcrenForest_PlantShop/scripts.pory"
	turnobject 4, DIR_NORTH
# 62 "data/maps/AcrenForest_PlantShop/scripts.pory"
	loadspeechtail FALSE, 4
# 63 "data/maps/AcrenForest_PlantShop/scripts.pory"
	msgbox AcrenForest_PlantShop_EventScript_ShopOwner_Text_2
# 65 "data/maps/AcrenForest_PlantShop/scripts.pory"
	destroyspeechtail
# 66 "data/maps/AcrenForest_PlantShop/scripts.pory"
	closemessage
# 67 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
# 68 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement 4, Common_Movement_WalkDown
# 69 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmovement 0
# 70 "data/maps/AcrenForest_PlantShop/scripts.pory"
	turnobject 4, DIR_NORTH
# 71 "data/maps/AcrenForest_PlantShop/scripts.pory"
	playse SE_PIN
# 72 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 73 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmovement 0
# 74 "data/maps/AcrenForest_PlantShop/scripts.pory"
	loadspeechtail FALSE, 4
# 75 "data/maps/AcrenForest_PlantShop/scripts.pory"
	msgbox AcrenForest_PlantShop_EventScript_ShopOwner_Text_3
# 81 "data/maps/AcrenForest_PlantShop/scripts.pory"
	destroyspeechtail
# 82 "data/maps/AcrenForest_PlantShop/scripts.pory"
	closemessage
# 83 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement 4, AcrenForest_PlantShop_Movement_JuliaWalkToExit
# 84 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmovement 0
# 85 "data/maps/AcrenForest_PlantShop/scripts.pory"
	playse SE_EXIT
# 86 "data/maps/AcrenForest_PlantShop/scripts.pory"
	removeobject 4
# 87 "data/maps/AcrenForest_PlantShop/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 88 "data/maps/AcrenForest_PlantShop/scripts.pory"
	setvar VAR_JULIA_STATE, 1
# 89 "data/maps/AcrenForest_PlantShop/scripts.pory"
	release
	end


# 103 "data/maps/AcrenForest_PlantShop/scripts.pory"

# 104 "data/maps/AcrenForest_PlantShop/scripts.pory"
    .align 2
# 105 "data/maps/AcrenForest_PlantShop/scripts.pory"
AcrenForest_PlantShop_PokemartDecor_Plants:
# 106 "data/maps/AcrenForest_PlantShop/scripts.pory"
    .2byte DECOR_PRETTY_FLOWERS
# 107 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.2byte DECOR_TROPICAL_PLANT
# 108 "data/maps/AcrenForest_PlantShop/scripts.pory"
    .2byte DECOR_RED_PLANT
# 109 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.2byte DECOR_COLORFUL_PLANT
# 110 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.2byte DECOR_BIG_PLANT
# 111 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.2byte DECOR_GORGEOUS_PLANT
# 112 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.2byte DECOR_NONE
# 113 "data/maps/AcrenForest_PlantShop/scripts.pory"
	release
# 114 "data/maps/AcrenForest_PlantShop/scripts.pory"
	end

AcrenForest_PlantShop_EventScript_Kecleon::
# 118 "data/maps/AcrenForest_PlantShop/scripts.pory"
	lock
# 119 "data/maps/AcrenForest_PlantShop/scripts.pory"
	faceplayer
# 120 "data/maps/AcrenForest_PlantShop/scripts.pory"
	playmoncry SPECIES_KECLEON, 0
# 121 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmoncry
# 122 "data/maps/AcrenForest_PlantShop/scripts.pory"
	msgbox AcrenForest_PlantShop_EventScript_Kecleon_Text_0
# 124 "data/maps/AcrenForest_PlantShop/scripts.pory"
	release
	end


AcrenForest_PlantShop_EventScript_Lady::
# 129 "data/maps/AcrenForest_PlantShop/scripts.pory"
	playse SE_PIN
# 130 "data/maps/AcrenForest_PlantShop/scripts.pory"
	applymovement 2, Common_Movement_Heart
# 131 "data/maps/AcrenForest_PlantShop/scripts.pory"
	waitmovement 0
# 132 "data/maps/AcrenForest_PlantShop/scripts.pory"
	msgbox AcrenForest_PlantShop_EventScript_Lady_Text_0, MSGBOX_NPC
# 134 "data/maps/AcrenForest_PlantShop/scripts.pory"
	turnobject 2, DIR_SOUTH
	end


AcrenForest_PlantShop_EventScript_Camper::
# 139 "data/maps/AcrenForest_PlantShop/scripts.pory"
	msgbox AcrenForest_PlantShop_EventScript_Camper_Text_0, MSGBOX_NPC
	end


AcrenForest_PlantShop_EventScript_BerryExplanationStand::
	end


# 149 "data/maps/AcrenForest_PlantShop/scripts.pory"
AcrenForest_PlantShop_Movement_JuliaWalkToPlayer:
# 150 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_up
# 150 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_up
	step_end

# 153 "data/maps/AcrenForest_PlantShop/scripts.pory"
AcrenForest_PlantShop_Movement_PlayerWalkUpBackwards:
# 154 "data/maps/AcrenForest_PlantShop/scripts.pory"
	lock_facing_direction
# 155 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_up
	step_end

# 158 "data/maps/AcrenForest_PlantShop/scripts.pory"
AcrenForest_PlantShop_Movement_ShopOwnerWalkToJulia:
# 159 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_down
# 159 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_down
# 160 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_right
# 160 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_right
# 161 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_up
# 162 "data/maps/AcrenForest_PlantShop/scripts.pory"
	delay_16
# 163 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_in_place_faster_up
	step_end

# 166 "data/maps/AcrenForest_PlantShop/scripts.pory"
AcrenForest_PlantShop_Movement_ShopOwnerWalkBehindCounter:
# 167 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_down
# 168 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_left
# 168 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_left
# 169 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_up
# 169 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_up
	step_end

# 172 "data/maps/AcrenForest_PlantShop/scripts.pory"
AcrenForest_PlantShop_Movement_JuliaWalkToExit:
# 173 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_down
# 173 "data/maps/AcrenForest_PlantShop/scripts.pory"
	walk_down
	step_end

AcrenForest_PlantShop_EventScript_ShopOwner_Text_0:
# 20 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.string "Oh hi there, my name is Julia.\n"
	.string "I haven't seen you around here before…\p"
	.string "Uhm, I suppose you're here for\n"
	.string "some flowers, just like me.\p"
	.string "If you'll excuse me…$"

AcrenForest_PlantShop_EventScript_ShopOwner_Text_1:
# 46 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.string "Thanks a lot, Sir!\p"
	.string "The flowers look beautiful.$"

AcrenForest_PlantShop_EventScript_ShopOwner_Text_2:
# 63 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.string "Anyway, I'll be going again.\p"
	.string "I guess I'll see you later.$"

AcrenForest_PlantShop_EventScript_ShopOwner_Text_3:
# 75 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.string "Oh and…\n"
	.string "What's your name?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "{PLAYER}…\p"
	.string "I'll see you later then, {PLAYER}!$"

AcrenForest_PlantShop_EventScript_ShopOwner_Text_4:
# 93 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.string "Welcome to my GREENERY SHOP!\n"
	.string "How can I help you?$"

AcrenForest_PlantShop_EventScript_ShopOwner_Text_5:
# 98 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.string "Please visit my GREENERY SHOP again!$"

AcrenForest_PlantShop_EventScript_Kecleon_Text_0:
# 122 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.string "KECLEON seems to be having fun\n"
	.string "in the SHOP.$"

AcrenForest_PlantShop_EventScript_Lady_Text_0:
# 132 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.string "These flowers smell amazing!\n"
	.string "I think I'll buy these.$"

AcrenForest_PlantShop_EventScript_Camper_Text_0:
# 139 "data/maps/AcrenForest_PlantShop/scripts.pory"
	.string "Camping by the water is so nice.\n"
	.string "Sometimes you get to see some\l"
	.string "very pretty WATER-type POKéMON!$"
