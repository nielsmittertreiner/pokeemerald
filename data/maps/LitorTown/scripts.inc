LitorTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LitorTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

LitorTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call FishermanFerry_EventScript_UpdateFerryLocation
	setrespawn HEAL_LOCATION_LITOR_TOWN
	setflag FLAG_VISITED_LITOR_TOWN
	return


LitorTown_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_unset FLAG_MET_SCOTT_ON_LITOR, LitorTown_EventScript_Fisherman_2
	goto_if_unset FLAG_MET_JULIA_ON_LITOR, LitorTown_EventScript_Fisherman_2
LitorTown_EventScript_Fisherman_1:
	load_speech_bubble 2
	message LitorTown_Text_WhereAreWeHeaded
	waitmessage
	multichoicedefault 21, 6, MULTI_FERRY_ON_LITOR, 1, 0
	switch VAR_RESULT
	case 0, LitorTown_EventScript_Fisherman_7
	case 1, LitorTown_EventScript_Fisherman_8
	case 2, LitorTown_EventScript_Fisherman_9
	case MULTI_B_PRESSED, LitorTown_EventScript_Fisherman_10
	return

LitorTown_EventScript_Fisherman_2:
	load_speech_bubble 2
	msgbox LitorTown_EventScript_Fisherman_Text_0, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LitorTown_EventScript_Fisherman_12
	case NO, LitorTown_EventScript_Fisherman_13
	case MULTI_B_PRESSED, LitorTown_EventScript_Fisherman_14
	goto LitorTown_EventScript_Fisherman_1

LitorTown_EventScript_Fisherman_7:
	goto LitorTown_EventScript_ChooseMurena
	return

LitorTown_EventScript_Fisherman_8:
	goto LitorTown_EventScript_ChooseNavire
	return

LitorTown_EventScript_Fisherman_9:
	goto LitorTown_EventScript_CancelFerrySelect
	return

LitorTown_EventScript_Fisherman_10:
	goto LitorTown_EventScript_CancelFerrySelect
	return

LitorTown_EventScript_Fisherman_12:
	goto LitorTown_EventScript_ChooseMurena
	goto LitorTown_EventScript_Fisherman_1

LitorTown_EventScript_Fisherman_13:
	goto LitorTown_EventScript_CancelFerrySelect
	goto LitorTown_EventScript_Fisherman_1

LitorTown_EventScript_Fisherman_14:
	goto LitorTown_EventScript_CancelFerrySelect
	goto LitorTown_EventScript_Fisherman_1


LitorTown_EventScript_ChooseMurena::
	msgbox LitorTown_EventScript_ChooseMurena_Text_0
	destroy_speech_bubble
	closemessage
	goto LitorTown_EventScript_SailToMurena
	return


LitorTown_EventScript_ChooseNavire::
	msgbox LitorTown_EventScript_ChooseNavire_Text_0
	destroy_speech_bubble
	closemessage
	goto LitorTown_EventScript_SailToNavire
	return


LitorTown_EventScript_CancelFerrySelect::
	msgbox LitorTown_EventScript_CancelFerrySelect_Text_0
	destroy_speech_bubble
	closemessage
	release
	end


LitorTown_EventScript_SailToMurena::
	call FishermanFerry_EventScript_BackupFerryLocation
	hideobjectat 10, MAP_MURENA_CITY
	setobjectpriority 2, MAP_LITOR_TOWN, 0
	setobjectpriority OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN, 0
	applymovement 2, Common_Movement_WalkRight
	waitmovement 0
	removeobject 2
	switch VAR_FACING
	case DIR_NORTH, LitorTown_EventScript_SailToMurena_3
	case DIR_EAST, LitorTown_EventScript_SailToMurena_4
	case DIR_SOUTH, LitorTown_EventScript_SailToMurena_5
LitorTown_EventScript_SailToMurena_1:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_SAILING, 0
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_SailToMurena
	applymovement 1, LitorTown_Movement_SailToMurena
	waitmovement 0
	setflag FLAG_HIDE_LITOR_TOWN_BOAT
	clearflag FLAG_DONT_TRANSITION_MUSIC
	fadedefaultbgm
	setvar VAR_FISHERMAN_FERRY_STATE, 3
	warpsilent MAP_MURENA_CITY_SHIPYARD, 0xFF, 8, 6
	waitstate
	end

LitorTown_EventScript_SailToMurena_3:
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatNorth
	waitmovement 0
	goto LitorTown_EventScript_SailToMurena_1

LitorTown_EventScript_SailToMurena_4:
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatEast
	waitmovement 0
	goto LitorTown_EventScript_SailToMurena_1

LitorTown_EventScript_SailToMurena_5:
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatSouth
	waitmovement 0
	goto LitorTown_EventScript_SailToMurena_1


LitorTown_EventScript_SailToNavire::
	call FishermanFerry_EventScript_BackupFerryLocation
	hideobjectat 1, MAP_NAVIRE_TOWN
	setobjectpriority 2, MAP_LITOR_TOWN, 0
	setobjectpriority OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN, 0
	applymovement 2, Common_Movement_WalkRight
	waitmovement 0
	removeobject 2
	switch VAR_FACING
	case DIR_NORTH, LitorTown_EventScript_SailToNavire_3
	case DIR_EAST, LitorTown_EventScript_SailToNavire_4
	case DIR_SOUTH, LitorTown_EventScript_SailToNavire_5
LitorTown_EventScript_SailToNavire_1:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
	delay 30
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_SAILING, 0
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_SailToNavire
	applymovement 1, LitorTown_Movement_SailToNavire
	waitmovement 0
	clearflag FLAG_DONT_TRANSITION_MUSIC
	fadedefaultbgm
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_NAVIRE_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerExitBoat
	waitmovement 0
	clearflag FLAG_HIDE_NAVIRE_TOWN_FISHERMAN
	setobjectxyperm 2, 8, 9
	addobject 2
	setobjectpriority 2, MAP_NAVIRE_TOWN, 0
	applymovement 2, LitorTown_Movement_FishermanExitBoat
	waitmovement 0
	clearflag FLAG_HIDE_NAVIRE_TOWN_FISHERMAN
	addobject 1
	setobjectpriority 1, MAP_NAVIRE_TOWN, 1
	clearflag FLAG_HIDE_NAVIRE_TOWN_BOAT
	setflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
	setflag FLAG_HIDE_MURENA_CITY_BOAT
	setflag FLAG_HIDE_LITOR_TOWN_BOAT
	hideobjectat 10, MAP_MURENA_CITY
	hideobjectat 1, MAP_MURENA_CITY_SHIPYARD
	hideobjectat 1, MAP_LITOR_TOWN
	load_speech_bubble 2
	msgbox LitorTown_EventScript_SailToNavire_Text_0
	destroy_speech_bubble
	closemessage
	resetobjectpriority OBJ_EVENT_ID_PLAYER, MAP_NAVIRE_TOWN
	resetobjectpriority 2, MAP_NAVIRE_TOWN
	copyobjectxytoperm 2
	call FishermanFerry_EventScript_RestoreFerryLocation
	release
	end

LitorTown_EventScript_SailToNavire_3:
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatNorth
	waitmovement 0
	goto LitorTown_EventScript_SailToNavire_1

LitorTown_EventScript_SailToNavire_4:
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatEast
	waitmovement 0
	goto LitorTown_EventScript_SailToNavire_1

LitorTown_EventScript_SailToNavire_5:
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerBoardBoatSouth
	waitmovement 0
	goto LitorTown_EventScript_SailToNavire_1


LitorTown_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_ON_LITOR, LitorTown_EventScript_Scott_1
	load_speech_bubble 7
	msgbox LitorTown_EventScript_Scott_Text_1
	destroy_speech_bubble
	closemessage
	playse SE_PIN
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	load_speech_bubble 7
	msgbox LitorTown_EventScript_Scott_Text_2
	destroy_speech_bubble
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_HAS_MATCH_CALL
	msgbox LitorTown_EventScript_Scott_Text_3
	waitfanfare
	closemessage
	load_speech_bubble 7
	msgbox LitorTown_EventScript_Scott_Text_4
	destroy_speech_bubble
	closemessage
	setflag FLAG_MET_SCOTT_ON_LITOR
	release
	end

LitorTown_EventScript_Scott_1:
	load_speech_bubble 7
	msgbox LitorTown_EventScript_Scott_Text_0
	destroy_speech_bubble
	closemessage
	release
	end


LitorTown_EventScript_JuliaEncounter::
	playse SE_EXIT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	addobject 13
	waitse
	applymovement 13, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, LitorTown_Movement_PlayerWalkDown
	waitmovement 0
	load_speech_bubble 13
	msgbox LitorTown_EventScript_JuliaEncounter_Text_0
	destroy_speech_bubble
	closemessage
	applymovement 13, Common_Movement_QuestionMark
	waitmovement 0
	load_speech_bubble 13
	msgbox LitorTown_EventScript_JuliaEncounter_Text_1
	destroy_speech_bubble
	closemessage
	applymovement 13, LitorTown_Movement_JuliaWalkOffscreen
	waitmovement 0
	removeobject 13
	setflag FLAG_MET_JULIA_ON_LITOR
	setvar VAR_JULIA_STATE, 2
	release
	end


LitorTown_EventScript_TuberM::
	msgbox LitorTown_EventScript_TuberM_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_TuberMSwimmer::
	msgbox LitorTown_EventScript_TuberMSwimmer_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_TuberF1::
	msgbox LitorTown_EventScript_TuberF1_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_TuberF2::
	msgbox LitorTown_EventScript_TuberF2_Text_0, MSGBOX_NPC
	compare VAR_JULIA_STATE, 2
	goto_if_lt LitorTown_EventScript_TuberF2_2
LitorTown_EventScript_TuberF2_1:
	end

LitorTown_EventScript_TuberF2_2:
	msgbox LitorTown_EventScript_TuberF2_Text_1, MSGBOX_NPC
	goto LitorTown_EventScript_TuberF2_1


LitorTown_EventScript_Youngster::
	msgbox LitorTown_EventScript_Youngster_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_Beauty::
	msgbox LitorTown_EventScript_Beauty_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_Sailor::
	msgbox LitorTown_EventScript_Sailor_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_Gentleman::
	msgbox LitorTown_EventScript_Gentleman_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_Boy::
	msgbox LitorTown_EventScript_Boy_Text_0, MSGBOX_NPC
	end


LitorTown_EventScript_TownSign::
	msgbox LitorTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


LitorTown_EventScript_BarSign::
	msgbox LitorTown_EventScript_BarSign_Text_0, MSGBOX_SIGN
	end


LitorTown_Movement_PlayerBoardBoatNorth:
	walk_up
	walk_right
	step_end

LitorTown_Movement_PlayerBoardBoatEast:
	walk_right
	walk_right
	step_end

LitorTown_Movement_PlayerBoardBoatSouth:
	walk_down
	walk_right
	step_end

LitorTown_Movement_SailToMurena:
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_down
	walk_fast_down
	walk_down
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	step_end

LitorTown_Movement_SailToNavire:
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LitorTown_Movement_PlayerExitBoat:
	walk_right
	walk_right
	face_left
	step_end

LitorTown_Movement_FishermanExitBoat:
	walk_right
	face_right
	step_end

LitorTown_Movement_PlayerWalkDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LitorTown_Movement_JuliaWalkOffscreen:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LitorTown_EventScript_Fisherman_Text_0:
	.string "Shall we head back to MURENA?$"

LitorTown_EventScript_ChooseMurena_Text_0:
	.string "We're headed to MURENA CITY!\n"
	.string "Let's set sail!$"

LitorTown_EventScript_ChooseNavire_Text_0:
	.string "We're headed to NAVIRE TOWN!\n"
	.string "Let's set sail!$"

LitorTown_EventScript_CancelFerrySelect_Text_0:
	.string "Tell me whenever you need me\n"
	.string "and my trusty boat.$"

LitorTown_EventScript_SailToNavire_Text_0:
	.string "These are the sands of NAVIRE!\n"
	.string "We've hit the mainland again!$"

LitorTown_EventScript_Scott_Text_0:
	.string "Boot up that new POKéNAV of yours now!\p"
	.string "And check out the map while you're at it,\n"
	.string "you can even check out city views!$"

LitorTown_EventScript_Scott_Text_1:
	.string "Hey there, my name is SCOTT.\n"
	.string "I'm the founder of the HOENN\l"
	.string "BATTLE FRONTIER.\p"
	.string "… … … … … …\p"
	.string "Hmmm, you seem familiar to me…$"

LitorTown_EventScript_Scott_Text_2:
	.string "Ah that's it!\n"
	.string "I saw you on TV!\p"
	.string "You won the FIRWEALD CITY TOURNAMENT,\n"
	.string "didn't you?\p"
	.string "I've always had an eye for\n"
	.string "talented TRAINERS.\p"
	.string "I think you're one of them.\p"
	.string "I'll be keeping an eye out for you.\p"
	.string "Let's register each other\n"
	.string "in our POKéNAVs!\l"
	.string "Wait, you don't have one?\p"
	.string "Well, I know a solution for that.\n"
	.string "Take this!$"

LitorTown_EventScript_Scott_Text_3:
	.string "{PLAYER} recieved the POKéNAV\n"
	.string "from SCOTT!$"

LitorTown_EventScript_Scott_Text_4:
	.string "A POKéNAV is the perfect device for\n"
	.string "any TRAINER!\p"
	.string "You can view the map of the EURUS\n"
	.string "REGION at any time you'd like.\p"
	.string "And you can use MATCH CALL to\n"
	.string "rematch registered TRAINERS.\p"
	.string "Pretty handy device, ey?\p"
	.string "I'll be staying here for a while, but\n"
	.string "perhaps our paths cross again.$"

LitorTown_EventScript_JuliaEncounter_Text_0:
	.string "Oh hey there {PLAYER}!\n"
	.string "I didn't expect you here on LITOR too.\p"
	.string "What a coincidence don't you agree?\n"
	.string "First I meet you while I'm buying\l"
	.string "flowers, and just now I bought a drink\l"
	.string "from here.\p"
	.string "Oh you should totally get a FRESH WATER!\n"
	.string "It's important to stay hydrated\l"
	.string "on an island like this!$"

LitorTown_EventScript_JuliaEncounter_Text_1:
	.string "What? You want to battle me?\p"
	.string "Oh no no, I'm not prepared for that now.\p"
	.string "Maybe when we meet again we'll battle.\n"
	.string "I promise, alright?!\p"
	.string "Anyway emm… I'll be going again hehe…$"

LitorTown_EventScript_TuberM_Text_0:
	.string "Hey! This is my floatie!$"

LitorTown_EventScript_TuberMSwimmer_Text_0:
	.string "I can't swim too far"
	.string "in the open sea.$"

LitorTown_EventScript_TuberF1_Text_0:
	.string "Did you know you can jump onto\n"
	.string "the floaties in the water?$"

LitorTown_EventScript_TuberF2_Text_0:
	.string "My daddy makes the best drinks of LITOR!\n"
	.string "I like his LEMONADE the most.$"

LitorTown_EventScript_TuberF2_Text_1:
	.string "Sometimes a particular girl buys our\n"
	.string "too. She says she likes flowers a lot,\l"
	.string "and our FRESH WATER too.$"

LitorTown_EventScript_Youngster_Text_0:
	.string "Sheesh, being in the hot sun all day\n"
	.string "is tiring…$"

LitorTown_EventScript_Beauty_Text_0:
	.string "Sunbathing in a chair like this…\n"
	.string "I can do it all day.$"

LitorTown_EventScript_Sailor_Text_0:
	.string "Ahh, finally some rest after a\n"
	.string "exhausting day…$"

LitorTown_EventScript_Gentleman_Text_0:
	.string "Renting a cottage at the beach really\n"
	.string "was the right choice after all!\p"
	.string "The grandkids love it!$"

LitorTown_EventScript_Boy_Text_0:
	.string "These beach umbrellas are everywhere\n"
	.string "to keep everyone from getting a\l"
	.string "nasty sunburn.$"

LitorTown_EventScript_TownSign_Text_0:
	.string "LITOR TOWN\n"
	.string "“A sunny, sandy palace.”$"

LitorTown_EventScript_BarSign_Text_0:
	.string "LITOR TOWN BAR\n"
	.string "“Come get a drink!”$"

LitorTown_Text_WhereAreWeHeaded::
	.string "Ahoy!\n"
	.string "Where shall we sail to next?$"
