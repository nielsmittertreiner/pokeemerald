ForestTunnel_MapScripts::
# 2 "data/maps/ForestTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ForestTunnel_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

ForestTunnel_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/ForestTunnel/scripts.pory"
	goto_if_unset FLAG_EVENT_CELEBI_ACTIVE, ForestTunnel_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

ForestTunnel_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/ForestTunnel/scripts.pory"
	setmetatile 4, 1, METATILE_RusturfTunnel_EntranceCover, 1
# 5 "data/maps/ForestTunnel/scripts.pory"
	setmetatile 5, 1, METATILE_RusturfTunnel_EntranceCover, 1
# 6 "data/maps/ForestTunnel/scripts.pory"
	setmetatile 6, 1, METATILE_RusturfTunnel_EntranceCover, 1
# 7 "data/maps/ForestTunnel/scripts.pory"
	setmetatile 4, 2, METATILE_RusturfTunnel_EntranceCover, 1
# 8 "data/maps/ForestTunnel/scripts.pory"
	setmetatile 5, 2, METATILE_RusturfTunnel_EntranceCover, 1
# 9 "data/maps/ForestTunnel/scripts.pory"
	setmetatile 6, 2, METATILE_RusturfTunnel_EntranceCover, 1
	return

