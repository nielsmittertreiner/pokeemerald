NavireTown_FishingClub_MapScripts::
	.byte 0


NavireTown_FishingClub_EventScript_Fisherman1::
	msgbox NavireTown_FishingClub_EventScript_Fisherman1_Text_0, MSGBOX_NPC
	applymovement 1, Common_Movement_FaceUp
	waitmovement 0
	end


NavireTown_FishingClub_EventScript_Fisherman2::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, NavireTown_FishingClub_EventScript_Fisherman2_2
	load_speech_bubble 2
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_1, MSGBOX_YESNO
	destroy_speech_bubble
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq NavireTown_FishingClub_EventScript_Fisherman2_5
	load_speech_bubble 2
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_6
	destroy_speech_bubble
	closemessage
NavireTown_FishingClub_EventScript_Fisherman2_4:
	release
	end

NavireTown_FishingClub_EventScript_Fisherman2_2:
	load_speech_bubble 2
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_0
	destroy_speech_bubble
	closemessage
	release
	end

NavireTown_FishingClub_EventScript_Fisherman2_5:
	load_speech_bubble 2
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_2
	destroy_speech_bubble
	closemessage
	delay 30
	load_speech_bubble 2
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_3
	delay 60
	destroy_speech_bubble
	closemessage
	load_speech_bubble 2
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_4
	destroy_speech_bubble
	closemessage
	giveitem ITEM_OLD_ROD, 1
	closemessage
	load_speech_bubble 2
	msgbox NavireTown_FishingClub_EventScript_Fisherman2_Text_5
	destroy_speech_bubble
	closemessage
	setflag FLAG_RECEIVED_OLD_ROD
	goto NavireTown_FishingClub_EventScript_Fisherman2_4


NavireTown_FishingClub_EventScript_Fisherman3::
	msgbox NavireTown_FishingClub_EventScript_Fisherman3_Text_0, MSGBOX_NPC
	end


NavireTown_FishingClub_EventScript_Woman::
	msgbox NavireTown_FishingClub_EventScript_Woman_Text_0, MSGBOX_NPC
	end


NavireTown_FishingClub_EventScript_Painting::
	msgbox NavireTown_FishingClub_EventScript_Painting_Text_0, MSGBOX_SIGN
	end


NavireTown_FishingClub_EventScript_Fisherman1_Text_0:
	.string "Shhh, don't disturb me.\n"
	.string "I'm watching a documentary about the\l"
	.string "MAGIKARP mating season…$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_0:
	.string "If you notice a fish on your hook,\n"
	.string "quickly reel it in by pressing the\l"
	.string "{A_BUTTON} BUTTON!\p"
	.string "Good luck and have fun fishing!$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_1:
	.string "That beautiful lady right there\n"
	.string "is my wife. She loves fish just as\l"
	.string "much as I do. We're a perfect couple.\p"
	.string "Do you also like fish?$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_2:
	.string "Yes! That's the right answer!\p"
	.string "Hmmm, I see you don't have a fishing\n"
	.string "rod though…$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_3:
	.string "… … …$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_4:
	.string "You know what, take this one!\n"
	.string "It's yours now!$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_5:
	.string "Throw this rod out in open waters\n"
	.string "and who knows what you'll catch!$"

NavireTown_FishingClub_EventScript_Fisherman2_Text_6:
	.string "Oh, that's too bad for you.\n"
	.string "You're missing out on the fun!$"

NavireTown_FishingClub_EventScript_Fisherman3_Text_0:
	.string "I've tried both the SKEWERS of\n"
	.string "MURENA CITY and the dishes from here.\p"
	.string "I gotta say I like this better.$"

NavireTown_FishingClub_EventScript_Woman_Text_0:
	.string "I always try to make the most\n"
	.string "delicious meals with the fish the\l"
	.string "men gather during the day.\p"
	.string "I've heard some lady in MURENA CITY\n"
	.string "also cooks some wonderful dishes.$"

NavireTown_FishingClub_EventScript_Painting_Text_0:
	.string "It's a wonderfully drawn painting…$"
