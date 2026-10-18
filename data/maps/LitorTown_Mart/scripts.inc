LitorTown_Mart_MapScripts::
	.byte 0


LitorTown_Mart_EventScript_Clerk::
# 6 "data/maps/LitorTown_Mart/scripts.pory"
	lock
# 7 "data/maps/LitorTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/LitorTown_Mart/scripts.pory"
	loadspeechtail FALSE, 1
# 9 "data/maps/LitorTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 10 "data/maps/LitorTown_Mart/scripts.pory"
	waitmessage
# 11 "data/maps/LitorTown_Mart/scripts.pory"
	pokemart LitorTown_Mart_Pokemart
# 12 "data/maps/LitorTown_Mart/scripts.pory"
	destroyspeechtail
# 13 "data/maps/LitorTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_NPC
# 14 "data/maps/LitorTown_Mart/scripts.pory"
	release
	end


# 18 "data/maps/LitorTown_Mart/scripts.pory"

# 19 "data/maps/LitorTown_Mart/scripts.pory"
LitorTown_Mart_Pokemart:
# 20 "data/maps/LitorTown_Mart/scripts.pory"
    .2byte ITEM_POKE_BALL
# 21 "data/maps/LitorTown_Mart/scripts.pory"
    .2byte ITEM_GREAT_BALL
# 22 "data/maps/LitorTown_Mart/scripts.pory"
    .2byte ITEM_POTION
# 23 "data/maps/LitorTown_Mart/scripts.pory"
    .2byte ITEM_SUPER_POTION
# 24 "data/maps/LitorTown_Mart/scripts.pory"
    .2byte ITEM_REPEL
# 25 "data/maps/LitorTown_Mart/scripts.pory"
    .2byte ITEM_ANTIDOTE
# 26 "data/maps/LitorTown_Mart/scripts.pory"
    .2byte ITEM_PARALYZE_HEAL
# 27 "data/maps/LitorTown_Mart/scripts.pory"
    .2byte ITEM_AWAKENING
# 28 "data/maps/LitorTown_Mart/scripts.pory"
    .2byte ITEM_FLUFFY_TAIL
# 29 "data/maps/LitorTown_Mart/scripts.pory"
    .2byte ITEM_NONE
# 30 "data/maps/LitorTown_Mart/scripts.pory"
    release
# 31 "data/maps/LitorTown_Mart/scripts.pory"
    end

LitorTown_Mart_EventScript_Youngster::
# 35 "data/maps/LitorTown_Mart/scripts.pory"
	msgbox LitorTown_Mart_EventScript_Youngster_Text_0, MSGBOX_NPC
	end


LitorTown_Mart_EventScript_Youngster_Text_0:
# 35 "data/maps/LitorTown_Mart/scripts.pory"
	.string "Wow! Look at all the soda they\n"
	.string "sell here!\p"
	.string "It looks so delicious!$"
