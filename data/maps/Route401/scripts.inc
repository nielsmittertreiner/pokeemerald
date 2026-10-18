Route401_MapScripts::
# 2 "data/maps/Route401/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route401_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route401_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Route401/scripts.pory"
	compare VAR_SUNSET_TOWN_STATE, 3
	goto_if_eq Route401_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Route401_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 5 "data/maps/Route401/scripts.pory"
	setvar VAR_SUNSET_TOWN_FOLLOWER_STATE, 2
	return


Route401_EventScript_RouteSign::
# 11 "data/maps/Route401/scripts.pory"
	msgbox Route401_EventScript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route401_EventScript_Boy::
# 17 "data/maps/Route401/scripts.pory"
	msgbox Route401_EventScript_Boy_Text_0, MSGBOX_NPC
	end


Route401_EventScript_Youngster::
# 24 "data/maps/Route401/scripts.pory"
	msgbox Route401_EventScript_Youngster_Text_0, MSGBOX_NPC
	end


Route401_EventScript_RouteSign_Text_0:
# 11 "data/maps/Route401/scripts.pory"
	.string "{LEFT_ARROW} SUNSET TOWN\n"
	.string "{RIGHT_ARROW} CEDARRED TOWN$"

Route401_EventScript_Boy_Text_0:
# 17 "data/maps/Route401/scripts.pory"
	.string "You should always be prepared to\n"
	.string "encounter wild POKéMON in the\l"
	.string "tall grass of ROUTE 401!$"

Route401_EventScript_Youngster_Text_0:
# 24 "data/maps/Route401/scripts.pory"
	.string "You can skip some tall grass by jumping\n"
	.string "over these ledges right here!\p"
	.string "Try it out yourself!$"
