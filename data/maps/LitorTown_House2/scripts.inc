LitorTown_House2_MapScripts::
	.byte 0


LitorTown_House2_EventScript_Lass::
	msgbox LitorTown_House2_EventScript_Lass_Text_0, MSGBOX_NPC
	end


LitorTown_House2_EventScript_Pikachu::
	playmoncry SPECIES_PIKACHU, 0
	waitmoncry
	end


LitorTown_House2_EventScript_Lass_Text_0:
	.string "My PIKACHU and I usually train on\n"
	.string "ROUTE 404 and 405, because\l"
	.string "ELECTRIC-type is super effective to\l"
	.string "FLYING- and WATER-type.$"
