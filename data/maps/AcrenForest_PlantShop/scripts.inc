AcrenForest_PlantShop_MapScripts::
	.byte 0


AcrenForest_PlantShop_EventScript_ShopOwner::
	compare VAR_JULIA_STATE, 0
	goto_if_eq AcrenForest_PlantShop_EventScript_ShopOwner_2
	load_speech_bubble 1
	message AcrenForest_PlantShop_EventScript_ShopOwner_Text_4
	waitmessage
	pokemartdecoration AcrenForest_PlantShop_PokemartDecor_Plants
	destroy_speech_bubble
	msgbox AcrenForest_PlantShop_EventScript_ShopOwner_Text_5, MSGBOX_NPC
	release
	end

AcrenForest_PlantShop_EventScript_ShopOwner_2:
	lock
	faceplayer
	playse SE_EXIT
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
	addobject 4
	setobjectxy 4, 2, 7
	delay 45
	applymovement 4, AcrenForest_PlantShop_Movement_JuliaWalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	load_speech_bubble 4
	msgbox AcrenForest_PlantShop_EventScript_ShopOwner_Text_0
	destroy_speech_bubble
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AcrenForest_PlantShop_Movement_PlayerWalkUpBackwards
	applymovement 4, Common_Movement_WalkUp
	waitmovement 0
	turnobject 4, DIR_WEST
	applymovement 4, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 15
	turnobject 1, DIR_SOUTH
	playse SE_DOOR
	setmetatile 0, 4, METATILE_PrettyPetalFlowerShop_Counter_OpenTop, 0
	setmetatile 0, 5, METATILE_PrettyPetalFlowerShop_Counter_OpenBottom, 0
	setmetatile 0, 6, METATILE_PrettyPetalFlowerShop_Shadow_Wall, 0
	setmetatile 1, 6, METATILE_PrettyPetalFlowerShop_Shadow_Angle, 0
	special DrawWholeMapView
	applymovement 1, AcrenForest_PlantShop_Movement_ShopOwnerWalkToJulia
	waitmovement 0
	turnobject 4, DIR_SOUTH
	delay 15
	load_speech_bubble 4
	msgbox AcrenForest_PlantShop_EventScript_ShopOwner_Text_1
	destroy_speech_bubble
	closemessage
	applymovement 1, AcrenForest_PlantShop_Movement_ShopOwnerWalkBehindCounter
	waitmovement 0
	turnobject 1, DIR_SOUTH
	playse SE_DOOR
	setmetatile 0, 4, METATILE_PrettyPetalFlowerShop_Counter_ClosedTop, 0
	setmetatile 0, 5, METATILE_PrettyPetalFlowerShop_Counter_ClosedBottom, 1
	setmetatile 0, 6, METATILE_PrettyPetalFlowerShop_Shadow_Counter, 0
	setmetatile 1, 6, METATILE_PrettyPetalFlowerShop_Shadow_Top, 0
	special DrawWholeMapView
	turnobject 1, DIR_EAST
	delay 15
	turnobject 4, DIR_NORTH
	load_speech_bubble 4
	msgbox AcrenForest_PlantShop_EventScript_ShopOwner_Text_2
	destroy_speech_bubble
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	applymovement 4, Common_Movement_WalkDown
	waitmovement 0
	turnobject 4, DIR_NORTH
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	load_speech_bubble 4
	msgbox AcrenForest_PlantShop_EventScript_ShopOwner_Text_3
	destroy_speech_bubble
	closemessage
	applymovement 4, AcrenForest_PlantShop_Movement_JuliaWalkToExit
	waitmovement 0
	playse SE_EXIT
	removeobject 4
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	setvar VAR_JULIA_STATE, 1
	release
	end


    .align 2
AcrenForest_PlantShop_PokemartDecor_Plants:
    .2byte DECOR_PRETTY_FLOWERS
	.2byte DECOR_TROPICAL_PLANT
    .2byte DECOR_RED_PLANT
	.2byte DECOR_COLORFUL_PLANT
	.2byte DECOR_BIG_PLANT
	.2byte DECOR_GORGEOUS_PLANT
	.2byte DECOR_NONE
	release
	end

AcrenForest_PlantShop_EventScript_Kecleon::
	lock
	faceplayer
	playmoncry SPECIES_KECLEON, 0
	waitmoncry
	msgbox AcrenForest_PlantShop_EventScript_Kecleon_Text_0
	release
	end


AcrenForest_PlantShop_EventScript_Lady::
	playse SE_PIN
	applymovement 2, Common_Movement_Heart
	waitmovement 0
	msgbox AcrenForest_PlantShop_EventScript_Lady_Text_0, MSGBOX_NPC
	turnobject 2, DIR_SOUTH
	end


AcrenForest_PlantShop_EventScript_Camper::
	msgbox AcrenForest_PlantShop_EventScript_Camper_Text_0, MSGBOX_NPC
	end


AcrenForest_PlantShop_EventScript_BerryExplanationStand::
	end


AcrenForest_PlantShop_Movement_JuliaWalkToPlayer:
	walk_up
	walk_up
	step_end

AcrenForest_PlantShop_Movement_PlayerWalkUpBackwards:
	lock_facing_direction
	walk_up
	step_end

AcrenForest_PlantShop_Movement_ShopOwnerWalkToJulia:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_up
	delay_16
	walk_in_place_fastest_up
	step_end

AcrenForest_PlantShop_Movement_ShopOwnerWalkBehindCounter:
	walk_down
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

AcrenForest_PlantShop_Movement_JuliaWalkToExit:
	walk_down
	walk_down
	step_end

AcrenForest_PlantShop_EventScript_ShopOwner_Text_0:
	.string "Oh hi there, my name is Julia.\n"
	.string "I haven't seen you around here before…\p"
	.string "Uhm, I suppose you're here for\n"
	.string "some flowers, just like me.\p"
	.string "If you'll excuse me…$"

AcrenForest_PlantShop_EventScript_ShopOwner_Text_1:
	.string "Thanks a lot, Sir!\p"
	.string "The flowers look beautiful.$"

AcrenForest_PlantShop_EventScript_ShopOwner_Text_2:
	.string "Anyway, I'll be going again.\p"
	.string "I guess I'll see you later.$"

AcrenForest_PlantShop_EventScript_ShopOwner_Text_3:
	.string "Oh and…\n"
	.string "What's your name?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "{PLAYER}…\p"
	.string "I'll see you later then, {PLAYER}!$"

AcrenForest_PlantShop_EventScript_ShopOwner_Text_4:
	.string "Welcome to my GREENERY SHOP!\n"
	.string "How can I help you?$"

AcrenForest_PlantShop_EventScript_ShopOwner_Text_5:
	.string "Please visit my GREENERY SHOP again!$"

AcrenForest_PlantShop_EventScript_Kecleon_Text_0:
	.string "KECLEON seems to be having fun\n"
	.string "in the SHOP.$"

AcrenForest_PlantShop_EventScript_Lady_Text_0:
	.string "These flowers smell amazing!\n"
	.string "I think I'll buy these.$"

AcrenForest_PlantShop_EventScript_Camper_Text_0:
	.string "Camping by the water is so nice.\n"
	.string "Sometimes you get to see some\l"
	.string "very pretty WATER-type POKéMON!$"
