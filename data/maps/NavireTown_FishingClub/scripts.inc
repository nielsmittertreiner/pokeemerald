NavireTown_FishingClub_MapScripts::
	.byte 0


NavireTown_FishingClub_EventScript_Fisherman1::
# 7 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Fisherman1_Text_0, MSGBOX_NPC
# 10 "data/maps/NavireTown_FishingClub/scripts.pory"
	applymovement 1, Common_Movement_FaceUp
# 11 "data/maps/NavireTown_FishingClub/scripts.pory"
	waitmovement 0
	end


NavireTown_FishingClub_EventScript_Fisherman2::
# 16 "data/maps/NavireTown_FishingClub/scripts.pory"
	lock
# 17 "data/maps/NavireTown_FishingClub/scripts.pory"
	faceplayer
# 19 "data/maps/NavireTown_FishingClub/scripts.pory"
	goto_if_set FLAG_RECEIVED_OLD_ROD, NavireTown_FishingClub_EventScript_Fisherman2_2
# 31 "data/maps/NavireTown_FishingClub/scripts.pory"
	loadspeechtail FALSE, 2
# 32 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_1, MSGBOX_YESNO
# 36 "data/maps/NavireTown_FishingClub/scripts.pory"
	destroyspeechtail
# 37 "data/maps/NavireTown_FishingClub/scripts.pory"
	closemessage
# 39 "data/maps/NavireTown_FishingClub/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NavireTown_FishingClub_EventScript_Fisherman2_5
# 69 "data/maps/NavireTown_FishingClub/scripts.pory"
	loadspeechtail FALSE, 2
# 70 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_6
# 72 "data/maps/NavireTown_FishingClub/scripts.pory"
	destroyspeechtail
# 73 "data/maps/NavireTown_FishingClub/scripts.pory"
	closemessage
NavireTown_FishingClub_EventScript_Fisherman2_4:
# 75 "data/maps/NavireTown_FishingClub/scripts.pory"
	release
	end

NavireTown_FishingClub_EventScript_Fisherman2_2:
# 21 "data/maps/NavireTown_FishingClub/scripts.pory"
	loadspeechtail FALSE, 2
# 22 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_0
# 26 "data/maps/NavireTown_FishingClub/scripts.pory"
	destroyspeechtail
# 27 "data/maps/NavireTown_FishingClub/scripts.pory"
	closemessage
# 28 "data/maps/NavireTown_FishingClub/scripts.pory"
	release
	end

NavireTown_FishingClub_EventScript_Fisherman2_5:
# 41 "data/maps/NavireTown_FishingClub/scripts.pory"
	loadspeechtail FALSE, 2
# 42 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_2
# 45 "data/maps/NavireTown_FishingClub/scripts.pory"
	destroyspeechtail
# 46 "data/maps/NavireTown_FishingClub/scripts.pory"
	closemessage
# 47 "data/maps/NavireTown_FishingClub/scripts.pory"
	delay 30
# 48 "data/maps/NavireTown_FishingClub/scripts.pory"
	loadspeechtail FALSE, 2
# 49 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_3
# 50 "data/maps/NavireTown_FishingClub/scripts.pory"
	delay 60
# 51 "data/maps/NavireTown_FishingClub/scripts.pory"
	destroyspeechtail
# 52 "data/maps/NavireTown_FishingClub/scripts.pory"
	closemessage
# 53 "data/maps/NavireTown_FishingClub/scripts.pory"
	loadspeechtail FALSE, 2
# 54 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_4
# 56 "data/maps/NavireTown_FishingClub/scripts.pory"
	destroyspeechtail
# 57 "data/maps/NavireTown_FishingClub/scripts.pory"
	closemessage
# 58 "data/maps/NavireTown_FishingClub/scripts.pory"
	giveitem ITEM_OLD_ROD, 1
# 59 "data/maps/NavireTown_FishingClub/scripts.pory"
	closemessage
# 60 "data/maps/NavireTown_FishingClub/scripts.pory"
	loadspeechtail FALSE, 2
# 61 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_5
# 63 "data/maps/NavireTown_FishingClub/scripts.pory"
	destroyspeechtail
# 64 "data/maps/NavireTown_FishingClub/scripts.pory"
	closemessage
# 65 "data/maps/NavireTown_FishingClub/scripts.pory"
	setflag FLAG_RECEIVED_OLD_ROD
	goto NavireTown_FishingClub_EventScript_Fisherman2_4


NavireTown_FishingClub_EventScript_Fisherman3::
# 80 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Fisherman3_Text_0, MSGBOX_NPC
	end


NavireTown_FishingClub_EventScript_Woman::
# 87 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Woman_Text_0, MSGBOX_NPC
	end


NavireTown_FishingClub_EventScript_Painting::
# 96 "data/maps/NavireTown_FishingClub/scripts.pory"
	msgbox NavireTown_FishingClub_EventScript_Painting_Text_0, MSGBOX_SIGN
	end


NavireTown_FishingClub_EventScript_Fisherman1_Text_0:
# 7 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "Shhh, don't disturb me.\n"
	.string "I'm watching a documentary about the\l"
	.string "MAGIKARP mating season…$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_0:
# 22 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "If you notice a fish on your hook,\n"
	.string "quickly reel it in by pressing the\l"
	.string "{A_BUTTON} BUTTON!\p"
	.string "Good luck and have fun fishing!$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_1:
# 32 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "That beautiful lady right there\n"
	.string "is my wife. She loves fish just as\l"
	.string "much as I do. We're a perfect couple.\p"
	.string "Do you also like fish?$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_2:
# 42 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "Yes! That's the right answer!\p"
	.string "Hmmm, I see you don't have a fishing\n"
	.string "rod though…$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_3:
# 49 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "… … …$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_4:
# 54 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "You know what, take this one!\n"
	.string "It's yours now!$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_5:
# 61 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "Throw this rod out in open waters\n"
	.string "and who knows what you'll catch!$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_6:
# 70 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "Oh, that's too bad for you.\n"
	.string "You're missing out on the fun!$"

NavireTown_FishingClub_EventScript_Fisherman3_Text_0:
# 80 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "I've tried both the SKEWERS of\n"
	.string "MURENA CITY and the dishes from here.\p"
	.string "I gotta say I like this better.$"

NavireTown_FishingClub_EventScript_Woman_Text_0:
# 87 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "I always try to make the most\n"
	.string "delicious meals with the fish the\l"
	.string "men gather during the day.\p"
	.string "I've heard some lady in MURENA CITY\n"
	.string "also cooks some wonderful dishes.$"

NavireTown_FishingClub_EventScript_Painting_Text_0:
# 96 "data/maps/NavireTown_FishingClub/scripts.pory"
	.string "It's a wonderfully drawn painting…$"
