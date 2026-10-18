SunsetTown_PlayerHouse_2F_MapScripts::
	.byte 0


SunsetTown_PlayerHouse_2F_EventScript_CheckPlayersPC::
# 6 "data/maps/SunsetTown_PlayerHouse_2F/scripts.pory"
	setvar VAR_0x8004, 1
# 7 "data/maps/SunsetTown_PlayerHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 8 "data/maps/SunsetTown_PlayerHouse_2F/scripts.pory"
	playse SE_PC_ON
# 9 "data/maps/SunsetTown_PlayerHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC
# 10 "data/maps/SunsetTown_PlayerHouse_2F/scripts.pory"
	special BedroomPC
# 11 "data/maps/SunsetTown_PlayerHouse_2F/scripts.pory"
	release
	end


SunsetTown_PlayerHouse_2F_EventScript_TurnOffPlayerPC::
# 16 "data/maps/SunsetTown_PlayerHouse_2F/scripts.pory"
	setvar VAR_0x8004, 1
# 17 "data/maps/SunsetTown_PlayerHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 18 "data/maps/SunsetTown_PlayerHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 19 "data/maps/SunsetTown_PlayerHouse_2F/scripts.pory"
	releaseall
	end

