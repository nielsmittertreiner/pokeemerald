OureaCave_B4F_HiddenRoom_MapScripts::
# 2 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, OureaCave_B4F_HiddenRoom_MapScripts_MAP_SCRIPT_ON_LOAD
# 8 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OureaCave_B4F_HiddenRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

OureaCave_B4F_HiddenRoom_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	goto_if_set FLAG_RECIEVED_OUREA_CAVE_B3F_HIDDEN_ROOM_WATER_STONE, OureaCave_B4F_HiddenRoom_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

OureaCave_B4F_HiddenRoom_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	setmetatile 4, 4, METATILE_Cave_ShoalCave_BlueStone_Small, 1
# 5 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	special DrawWholeMapView
	return

OureaCave_B4F_HiddenRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 9 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	call OureaCaves_EventScript_SetCaveLights
	return


OureaCave_B4F_HiddenRoom_EventScript_WaterStone::
# 14 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	lock
# 15 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	goto_if_set FLAG_RECIEVED_OUREA_CAVE_B3F_HIDDEN_ROOM_WATER_STONE, OureaCave_B4F_HiddenRoom_EventScript_WaterStone_2
# 22 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	finditem ITEM_WATER_STONE
# 23 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	delay 10
# 24 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	setflag FLAG_RECIEVED_OUREA_CAVE_B3F_HIDDEN_ROOM_WATER_STONE
# 25 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	setmetatile 4, 4, METATILE_Cave_ShoalCave_BlueStone_Small, 1
# 26 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	special DrawWholeMapView
# 27 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	release
	end

OureaCave_B4F_HiddenRoom_EventScript_WaterStone_2:
# 16 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	msgbox OureaCave_B4F_HiddenRoom_EventScript_WaterStone_Text_0
# 18 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	release
	end


OureaCave_B4F_HiddenRoom_EventScript_WaterStone_Text_0:
# 16 "data/maps/OureaCave_B4F_HiddenRoom/scripts.pory"
	.string "There was a WATER STONE here once.\n"
	.string "Now there's nothing…$"
