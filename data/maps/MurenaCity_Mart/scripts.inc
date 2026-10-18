MurenaCity_Mart_MapScripts::
	.byte 0


MurenaCity_Mart_EventScript_Clerk::
# 6 "data/maps/MurenaCity_Mart/scripts.pory"
	lock
# 7 "data/maps/MurenaCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/MurenaCity_Mart/scripts.pory"
	loadspeechtail FALSE, 1
# 9 "data/maps/MurenaCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 10 "data/maps/MurenaCity_Mart/scripts.pory"
	waitmessage
# 11 "data/maps/MurenaCity_Mart/scripts.pory"
	pokemart MurenaCity_Mart_Pokemart
# 12 "data/maps/MurenaCity_Mart/scripts.pory"
	destroyspeechtail
# 13 "data/maps/MurenaCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_NPC
# 14 "data/maps/MurenaCity_Mart/scripts.pory"
	release
	end


# 18 "data/maps/MurenaCity_Mart/scripts.pory"

# 19 "data/maps/MurenaCity_Mart/scripts.pory"
MurenaCity_Mart_Pokemart:
# 20 "data/maps/MurenaCity_Mart/scripts.pory"
    .2byte ITEM_POKE_BALL
# 21 "data/maps/MurenaCity_Mart/scripts.pory"
    .2byte ITEM_GREAT_BALL
# 22 "data/maps/MurenaCity_Mart/scripts.pory"
    .2byte ITEM_POTION
# 23 "data/maps/MurenaCity_Mart/scripts.pory"
    .2byte ITEM_SUPER_POTION
# 24 "data/maps/MurenaCity_Mart/scripts.pory"
    .2byte ITEM_ANTIDOTE
# 25 "data/maps/MurenaCity_Mart/scripts.pory"
    .2byte ITEM_PARALYZE_HEAL
# 26 "data/maps/MurenaCity_Mart/scripts.pory"
    .2byte ITEM_HARBOR_MAIL
# 27 "data/maps/MurenaCity_Mart/scripts.pory"
    .2byte ITEM_NONE
# 28 "data/maps/MurenaCity_Mart/scripts.pory"
    release
# 29 "data/maps/MurenaCity_Mart/scripts.pory"
    end

MurenaCity_Mart_EventScript_Gentleman::
# 33 "data/maps/MurenaCity_Mart/scripts.pory"
	msgbox MurenaCity_Mart_EventScript_Gentleman_Text_0, MSGBOX_NPC
	end


MurenaCity_Mart_EventScript_Gentleman_Text_0:
# 33 "data/maps/MurenaCity_Mart/scripts.pory"
	.string "The people who work in these\n"
	.string "shops truly work very hard.\l"
	.string "The shelves are always stocked.$"
