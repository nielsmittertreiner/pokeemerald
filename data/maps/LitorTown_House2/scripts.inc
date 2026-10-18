LitorTown_House2_MapScripts::
	.byte 0


LitorTown_House2_EventScript_Lass::
# 4 "data/maps/LitorTown_House2/scripts.pory"
	msgbox LitorTown_House2_EventScript_Lass_Text_0, MSGBOX_NPC
	end


LitorTown_House2_EventScript_Pikachu::
# 12 "data/maps/LitorTown_House2/scripts.pory"
	playmoncry SPECIES_PIKACHU, 0
# 13 "data/maps/LitorTown_House2/scripts.pory"
	waitmoncry
	end


LitorTown_House2_EventScript_Lass_Text_0:
# 4 "data/maps/LitorTown_House2/scripts.pory"
	.string "My PIKACHU and I usually train on\n"
	.string "ROUTE 404 and 405, because\l"
	.string "ELECTRIC-type is super effective to\l"
	.string "FLYING- and WATER-type.$"
