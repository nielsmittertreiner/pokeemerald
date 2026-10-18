FishermanFerry_EventScript_BackupFerryLocation::
# 2 "data/scripts/fisherman_ferry.pory"
	copyvar VAR_0x8008, VAR_FISHERMAN_FERRY_LOCATION
# 3 "data/scripts/fisherman_ferry.pory"
	setvar VAR_FISHERMAN_FERRY_LOCATION, 0
	return


FishermanFerry_EventScript_RestoreFerryLocation::
# 8 "data/scripts/fisherman_ferry.pory"
	copyvar VAR_FISHERMAN_FERRY_LOCATION, VAR_0x8008
# 9 "data/scripts/fisherman_ferry.pory"
	setvar VAR_0x8008, 0
	return


FishermanFerry_EventScript_ResetFerryLocation::
# 14 "data/scripts/fisherman_ferry.pory"
	compare VAR_FISHERMAN_FERRY_LOCATION, 1
	goto_if_eq FishermanFerry_EventScript_ResetFerryLocation_2
FishermanFerry_EventScript_ResetFerryLocation_1:
# 24 "data/scripts/fisherman_ferry.pory"
	compare VAR_FISHERMAN_FERRY_LOCATION, 2
	goto_if_eq FishermanFerry_EventScript_ResetFerryLocation_5
FishermanFerry_EventScript_ResetFerryLocation_4:
# 34 "data/scripts/fisherman_ferry.pory"
	compare VAR_FISHERMAN_FERRY_LOCATION, 3
	goto_if_eq FishermanFerry_EventScript_ResetFerryLocation_8
FishermanFerry_EventScript_ResetFerryLocation_7:
	return

FishermanFerry_EventScript_ResetFerryLocation_2:
# 16 "data/scripts/fisherman_ferry.pory"
	clearflag FLAG_HIDE_MURENA_CITY_SHIPYARD_FISHERMAN
# 17 "data/scripts/fisherman_ferry.pory"
	clearflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
# 18 "data/scripts/fisherman_ferry.pory"
	clearflag FLAG_HIDE_MURENA_CITY_BOAT
# 19 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_LITOR_TOWN_FISHERMAN
# 20 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_LITOR_TOWN_BOAT
# 21 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_NAVIRE_TOWN_FISHERMAN
# 22 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_NAVIRE_TOWN_BOAT
	goto FishermanFerry_EventScript_ResetFerryLocation_1

FishermanFerry_EventScript_ResetFerryLocation_5:
# 26 "data/scripts/fisherman_ferry.pory"
	clearflag FLAG_HIDE_LITOR_TOWN_FISHERMAN
# 27 "data/scripts/fisherman_ferry.pory"
	clearflag FLAG_HIDE_LITOR_TOWN_BOAT
# 28 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_MURENA_CITY_SHIPYARD_FISHERMAN
# 29 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
# 30 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_MURENA_CITY_BOAT
# 31 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_NAVIRE_TOWN_FISHERMAN
# 32 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_NAVIRE_TOWN_BOAT
	goto FishermanFerry_EventScript_ResetFerryLocation_4

FishermanFerry_EventScript_ResetFerryLocation_8:
# 36 "data/scripts/fisherman_ferry.pory"
	clearflag FLAG_HIDE_NAVIRE_TOWN_FISHERMAN
# 37 "data/scripts/fisherman_ferry.pory"
	clearflag FLAG_HIDE_NAVIRE_TOWN_BOAT
# 38 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_LITOR_TOWN_FISHERMAN
# 39 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_LITOR_TOWN_BOAT
# 40 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_MURENA_CITY_SHIPYARD_FISHERMAN
# 41 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
# 42 "data/scripts/fisherman_ferry.pory"
	setflag FLAG_HIDE_MURENA_CITY_BOAT
	goto FishermanFerry_EventScript_ResetFerryLocation_7


FishermanFerry_EventScript_UpdateFerryLocation::
# 48 "data/scripts/fisherman_ferry.pory"
	goto_if_unset FLAG_HIDE_MURENA_CITY_SHIPYARD_FISHERMAN, FishermanFerry_EventScript_UpdateFerryLocation_2
FishermanFerry_EventScript_UpdateFerryLocation_1:
# 51 "data/scripts/fisherman_ferry.pory"
	goto_if_unset FLAG_HIDE_LITOR_TOWN_FISHERMAN, FishermanFerry_EventScript_UpdateFerryLocation_5
FishermanFerry_EventScript_UpdateFerryLocation_4:
# 54 "data/scripts/fisherman_ferry.pory"
	goto_if_unset FLAG_HIDE_NAVIRE_TOWN_FISHERMAN, FishermanFerry_EventScript_UpdateFerryLocation_8
FishermanFerry_EventScript_UpdateFerryLocation_7:
	return

FishermanFerry_EventScript_UpdateFerryLocation_2:
# 49 "data/scripts/fisherman_ferry.pory"
	setvar VAR_FISHERMAN_FERRY_LOCATION, 1
	goto FishermanFerry_EventScript_UpdateFerryLocation_1

FishermanFerry_EventScript_UpdateFerryLocation_5:
# 52 "data/scripts/fisherman_ferry.pory"
	setvar VAR_FISHERMAN_FERRY_LOCATION, 2
	goto FishermanFerry_EventScript_UpdateFerryLocation_4

FishermanFerry_EventScript_UpdateFerryLocation_8:
# 55 "data/scripts/fisherman_ferry.pory"
	setvar VAR_FISHERMAN_FERRY_LOCATION, 3
	goto FishermanFerry_EventScript_UpdateFerryLocation_7

