FirwealdCity_Duplex_MapScripts::
	.byte 0


FirwealdCity_Duplex_EventScript_Man::
# 4 "data/maps/FirwealdCity_Duplex/scripts.pory"
	msgbox FirwealdCity_Duplex_EventScript_Man_Text_0, MSGBOX_NPC
	end


FirwealdCity_Duplex_EventScript_Lass::
# 11 "data/maps/FirwealdCity_Duplex/scripts.pory"
	msgbox FirwealdCity_Duplex_EventScript_Lass_Text_0, MSGBOX_NPC
	end


FirwealdCity_Duplex_EventScript_Wingull::
# 17 "data/maps/FirwealdCity_Duplex/scripts.pory"
	lock
# 18 "data/maps/FirwealdCity_Duplex/scripts.pory"
	faceplayer
# 19 "data/maps/FirwealdCity_Duplex/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 20 "data/maps/FirwealdCity_Duplex/scripts.pory"
	waitmoncry
# 21 "data/maps/FirwealdCity_Duplex/scripts.pory"
	release
	end


FirwealdCity_Duplex_EventScript_Man_Text_0:
# 4 "data/maps/FirwealdCity_Duplex/scripts.pory"
	.string "Hrmph…\p"
	.string "I can hear that WINGULL of the\n"
	.string "girl nextdoor all day long.$"

FirwealdCity_Duplex_EventScript_Lass_Text_0:
# 11 "data/maps/FirwealdCity_Duplex/scripts.pory"
	.string "Oh I love reading!\p"
	.string "I even have a book about WINGULL.$"
