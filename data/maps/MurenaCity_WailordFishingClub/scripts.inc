MurenaCity_WailordFishingClub_MapScripts::
	.byte 0


MurenaCity_WailordFishingClub_EventScript_ChairmanSign::
# 7 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	msgbox MurenaCity_WailordFishingClub_EventScript_ChairmanSign_Text_0, MSGBOX_SIGN
	end


MurenaCity_WailordFishingClub_EventScript_Chairman::
# 12 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	msgbox MurenaCity_WailordFishingClub_EventScript_Chairman_Text_0, MSGBOX_NPC
	end


MurenaCity_WailordFishingClub_EventScript_Sailor::
# 23 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	msgbox MurenaCity_WailordFishingClub_EventScript_Sailor_Text_0, MSGBOX_NPC
	end


MurenaCity_WailordFishingClub_EventScript_Fisherman::
# 32 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	lock
# 33 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	applymovement 3, Common_Movement_WalkInPlaceFastestRight
# 34 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	waitmovement 0
# 35 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	loadspeechtail FALSE, 3
# 36 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	msgbox MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_0
# 38 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	destroyspeechtail
# 39 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	closemessage
# 40 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	loadspeechtail FALSE, 4
# 41 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFastestLeft
# 42 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	waitmovement 0
# 43 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	msgbox MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_1
# 44 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	destroyspeechtail
# 45 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	closemessage
# 46 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	applymovement 3, Common_Movement_WalkInPlaceFastestRight
# 47 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	waitmovement 0
# 48 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	loadspeechtail FALSE, 3
# 49 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	msgbox MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_2
# 51 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	destroyspeechtail
# 52 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	closemessage
# 53 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFastestLeft
# 54 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	waitmovement 0
# 55 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	loadspeechtail FALSE, 4
# 56 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	msgbox MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_3
# 58 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	destroyspeechtail
# 59 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	closemessage
# 60 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	release
	end


MurenaCity_WailordFishingClub_EventScript_ChairmanSign_Text_0:
# 7 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	.string "It's a portrait of the CHAIRMAN…$"

MurenaCity_WailordFishingClub_EventScript_Chairman_Text_0:
# 12 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	.string "Hello there.\n"
	.string "I am the chairman of the\l"
	.string "WAILORD FISHING CLUB.\p"
	.string "Day and night, fishermen and\n"
	.string "sailors are searching for the\l"
	.string "almighty giant of the oceans!\p"
	.string "Hoping to find a WAILORD…$"

MurenaCity_WailordFishingClub_EventScript_Sailor_Text_0:
# 23 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	.string "Every day I use my ship to\n"
	.string "search for the aquatic giant.\p"
	.string "The ship I use is a big fisherman's\n"
	.string "ship with lots of gear to haul\l"
	.string "the big guy in!$"

MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_0:
# 36 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	.string "So, has anyone even seen a\n"
	.string "WAILORD here?$"

MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_1:
# 43 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	.string "Well, yes of course…$"

MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_2:
# 49 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	.string "How big is it then?\n"
	.string "I suppose you would know.$"

MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_3:
# 56 "data/maps/MurenaCity_WailordFishingClub/scripts.pory"
	.string "Oh uhm…\p"
	.string "It's just really big y'know.$"
