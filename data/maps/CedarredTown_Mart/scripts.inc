CedarredTown_Mart_MapScripts::
	.byte 0


CedarredTown_Mart_EventScript_Clerk::
# 6 "data/maps/CedarredTown_Mart/scripts.pory"
	lock
# 7 "data/maps/CedarredTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/CedarredTown_Mart/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, CedarredTown_Mart_EventScript_Clerk_3
# 14 "data/maps/CedarredTown_Mart/scripts.pory"
	loadspeechtail FALSE, 1
# 15 "data/maps/CedarredTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 16 "data/maps/CedarredTown_Mart/scripts.pory"
	waitmessage
# 17 "data/maps/CedarredTown_Mart/scripts.pory"
	pokemart CedarredTown_Mart_Pokemart
# 18 "data/maps/CedarredTown_Mart/scripts.pory"
	destroyspeechtail
# 19 "data/maps/CedarredTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_NPC
# 20 "data/maps/CedarredTown_Mart/scripts.pory"
	release
	end

CedarredTown_Mart_EventScript_Clerk_3:
# 9 "data/maps/CedarredTown_Mart/scripts.pory"
	msgbox CedarredTown_Mart_EventScript_Clerk_Text_0, MSGBOX_NPC
	end


# 24 "data/maps/CedarredTown_Mart/scripts.pory"

# 25 "data/maps/CedarredTown_Mart/scripts.pory"
CedarredTown_Mart_Pokemart:
# 26 "data/maps/CedarredTown_Mart/scripts.pory"
    .2byte ITEM_POKE_BALL
# 27 "data/maps/CedarredTown_Mart/scripts.pory"
    .2byte ITEM_POTION
# 28 "data/maps/CedarredTown_Mart/scripts.pory"
    .2byte ITEM_ANTIDOTE
# 29 "data/maps/CedarredTown_Mart/scripts.pory"
    .2byte ITEM_PARALYZE_HEAL
# 30 "data/maps/CedarredTown_Mart/scripts.pory"
    .2byte ITEM_AWAKENING
# 31 "data/maps/CedarredTown_Mart/scripts.pory"
    .2byte ITEM_NONE
# 32 "data/maps/CedarredTown_Mart/scripts.pory"
    release
# 33 "data/maps/CedarredTown_Mart/scripts.pory"
    end

CedarredTown_Mart_EventScript_Gentleman::
# 37 "data/maps/CedarredTown_Mart/scripts.pory"
	msgbox CedarredTown_Mart_EventScript_Gentleman_Text_0, MSGBOX_NPC
	end


CedarredTown_Mart_EventScript_Clerk_Text_0:
# 9 "data/maps/CedarredTown_Mart/scripts.pory"
	.string "It's seems that you don't have\n"
	.string "any POKéMON…\p"
	.string "Come back when you have one.$"

CedarredTown_Mart_EventScript_Gentleman_Text_0:
# 37 "data/maps/CedarredTown_Mart/scripts.pory"
	.string "Did you know CEDARRED TOWN is\n"
	.string "renowned in the far away region\l"
	.string "of SINNOH?\p"
	.string "It reminds me of SANDGEM TOWN in\n"
	.string "a way…$"
