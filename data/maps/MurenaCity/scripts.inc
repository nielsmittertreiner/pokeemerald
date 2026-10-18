MurenaCity_MapScripts::
# 30 "data/maps/MurenaCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 23 "data/maps/MurenaCity/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MurenaCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 26 "data/maps/MurenaCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MurenaCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 31 "data/maps/MurenaCity/scripts.pory"
	compare VAR_MURENA_CITY_STATE, 1
	goto_if_lt MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 34 "data/maps/MurenaCity/scripts.pory"
	setrespawn HEAL_LOCATION_MURENA_CITY
# 35 "data/maps/MurenaCity/scripts.pory"
	setflag FLAG_VISITED_MURENA_CITY
# 36 "data/maps/MurenaCity/scripts.pory"
	call FishermanFerry_EventScript_UpdateFerryLocation
	return

MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 32 "data/maps/MurenaCity/scripts.pory"
	setobjectxyperm 12, 41, 20
	goto MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

MurenaCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 24 "data/maps/MurenaCity/scripts.pory"
	map_script_2 VAR_FISHERMAN_FERRY_STATE, 1, MurenaCity_EventScript_SetUpSailing
	.2byte 0

MurenaCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 27 "data/maps/MurenaCity/scripts.pory"
	map_script_2 VAR_FISHERMAN_FERRY_STATE, 2, MurenaCity_EventScript_SailToLitor
	.2byte 0


MurenaCity_EventScript_SetUpSailing::
# 41 "data/maps/MurenaCity/scripts.pory"
	setvar VAR_FISHERMAN_FERRY_STATE, 2
# 42 "data/maps/MurenaCity/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 43 "data/maps/MurenaCity/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_MURENA_CITY
	return


MurenaCity_EventScript_SailToLitor::
# 47 "data/maps/MurenaCity/scripts.pory"
	setvar VAR_FISHERMAN_FERRY_STATE, 0
# 48 "data/maps/MurenaCity/scripts.pory"
	playbgm MUS_SAILING, FALSE
# 49 "data/maps/MurenaCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MurenaCity_Movement_SailToLitor
# 50 "data/maps/MurenaCity/scripts.pory"
	applymovement 10, MurenaCity_Movement_SailToLitor
# 51 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 52 "data/maps/MurenaCity/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 53 "data/maps/MurenaCity/scripts.pory"
	fadedefaultbgm
# 54 "data/maps/MurenaCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 55 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 56 "data/maps/MurenaCity/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
# 57 "data/maps/MurenaCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MurenaCity_Movement_ExitBoatLitorTown
# 58 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 59 "data/maps/MurenaCity/scripts.pory"
	setobjectxyperm 2, 34, 22
# 60 "data/maps/MurenaCity/scripts.pory"
	addobject 2
# 61 "data/maps/MurenaCity/scripts.pory"
	setobjectsubpriority 2, MAP_LITOR_TOWN, 0
# 62 "data/maps/MurenaCity/scripts.pory"
	applymovement 2, Common_Movement_WalkLeft
# 63 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 64 "data/maps/MurenaCity/scripts.pory"
	clearflag FLAG_HIDE_LITOR_TOWN_FISHERMAN
# 65 "data/maps/MurenaCity/scripts.pory"
	addobject 1
# 66 "data/maps/MurenaCity/scripts.pory"
	setobjectsubpriority 1, MAP_LITOR_TOWN, 1
# 67 "data/maps/MurenaCity/scripts.pory"
	clearflag FLAG_HIDE_LITOR_TOWN_BOAT
# 68 "data/maps/MurenaCity/scripts.pory"
	setflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
# 69 "data/maps/MurenaCity/scripts.pory"
	setflag FLAG_HIDE_MURENA_CITY_BOAT
# 70 "data/maps/MurenaCity/scripts.pory"
	setflag FLAG_HIDE_NAVIRE_TOWN_BOAT
# 71 "data/maps/MurenaCity/scripts.pory"
	hideobjectat 10, MAP_MURENA_CITY
# 72 "data/maps/MurenaCity/scripts.pory"
	hideobjectat 1, MAP_MURENA_CITY_SHIPYARD
# 73 "data/maps/MurenaCity/scripts.pory"
	hideobjectat 1, MAP_NAVIRE_TOWN
# 74 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 2
# 75 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_SailToLitor_Text_0
# 77 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 78 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 79 "data/maps/MurenaCity/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_LITOR_TOWN
# 80 "data/maps/MurenaCity/scripts.pory"
	resetobjectsubpriority 2, MAP_LITOR_TOWN
# 81 "data/maps/MurenaCity/scripts.pory"
	copyobjectxytoperm 2
# 82 "data/maps/MurenaCity/scripts.pory"
	call FishermanFerry_EventScript_RestoreFerryLocation
# 83 "data/maps/MurenaCity/scripts.pory"
	release
	end


MurenaCity_EventScript_TeamAirlockEncounter::
# 88 "data/maps/MurenaCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 89 "data/maps/MurenaCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 90 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 91 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 20
# 92 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_0
# 96 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 97 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 98 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 18
# 99 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_1
# 102 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 103 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 104 "data/maps/MurenaCity/scripts.pory"
	applymovement 19, MurenaCity_Movement_Grunt2PunchFisherman
# 105 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 106 "data/maps/MurenaCity/scripts.pory"
	playse SE_M_COMET_PUNCH
# 107 "data/maps/MurenaCity/scripts.pory"
	waitse
# 108 "data/maps/MurenaCity/scripts.pory"
	applymovement 20, MurenaCity_Movement_FishermanStrugglesBack
# 109 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 110 "data/maps/MurenaCity/scripts.pory"
	delay 24
# 111 "data/maps/MurenaCity/scripts.pory"
	playse SE_PIN
# 112 "data/maps/MurenaCity/scripts.pory"
	applymovement 20, Common_Movement_ExclamationMark
# 113 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 114 "data/maps/MurenaCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 115 "data/maps/MurenaCity/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_2
# 118 "data/maps/MurenaCity/scripts.pory"
	compare VAR_TEMP_1, 29
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_3
MurenaCity_EventScript_TeamAirlockEncounter_1:
# 122 "data/maps/MurenaCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 123 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 124 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 20
# 125 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_2
# 129 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 130 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 131 "data/maps/MurenaCity/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_7
# 134 "data/maps/MurenaCity/scripts.pory"
	compare VAR_TEMP_1, 29
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_8
MurenaCity_EventScript_TeamAirlockEncounter_6:
# 138 "data/maps/MurenaCity/scripts.pory"
	applymovement 18, Common_Movement_FaceRight
# 139 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 140 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 18
# 141 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_3
# 147 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 148 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 149 "data/maps/MurenaCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MURENA_CITY_GRUNT, MurenaCity_Text_GruntDefeat
# 150 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 18
# 151 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_4
# 155 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 156 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 157 "data/maps/MurenaCity/scripts.pory"
	fadedefaultbgm
# 158 "data/maps/MurenaCity/scripts.pory"
	applymovement 18, MurenaCity_Movement_Grunt1RunAway
# 159 "data/maps/MurenaCity/scripts.pory"
	applymovement 19, MurenaCity_Movement_Grunt2RunAway
# 160 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 161 "data/maps/MurenaCity/scripts.pory"
	removeobject 18
# 162 "data/maps/MurenaCity/scripts.pory"
	removeobject 19
# 163 "data/maps/MurenaCity/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_12
# 166 "data/maps/MurenaCity/scripts.pory"
	compare VAR_TEMP_1, 29
	goto_if_eq MurenaCity_EventScript_TeamAirlockEncounter_13
MurenaCity_EventScript_TeamAirlockEncounter_11:
# 170 "data/maps/MurenaCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 171 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 172 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 20
# 173 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_TeamAirlockEncounter_Text_5
# 180 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 181 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 182 "data/maps/MurenaCity/scripts.pory"
	applymovement 20, MurenaCity_Movement_FishermanWalkToShipyard
# 183 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 184 "data/maps/MurenaCity/scripts.pory"
	playse SE_EXIT
# 185 "data/maps/MurenaCity/scripts.pory"
	removeobject 20
# 186 "data/maps/MurenaCity/scripts.pory"
	setvar VAR_MURENA_CITY_STATE, 1
	end

MurenaCity_EventScript_TeamAirlockEncounter_2:
# 116 "data/maps/MurenaCity/scripts.pory"
	applymovement 20, MurenaCity_Movement_FishermanRunToPlayer1
# 117 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_1

MurenaCity_EventScript_TeamAirlockEncounter_3:
# 119 "data/maps/MurenaCity/scripts.pory"
	applymovement 20, MurenaCity_Movement_FishermanRunToPlayer2
# 120 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_1

MurenaCity_EventScript_TeamAirlockEncounter_7:
# 132 "data/maps/MurenaCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MurenaCity_Movement_PlayerWalkToGrunt
# 133 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_6

MurenaCity_EventScript_TeamAirlockEncounter_8:
# 135 "data/maps/MurenaCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
# 136 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_6

MurenaCity_EventScript_TeamAirlockEncounter_12:
# 164 "data/maps/MurenaCity/scripts.pory"
	applymovement 20, MurenaCity_Movement_FishermanWalkToPlayer1
# 165 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_11

MurenaCity_EventScript_TeamAirlockEncounter_13:
# 167 "data/maps/MurenaCity/scripts.pory"
	applymovement 20, MurenaCity_Movement_FishermanWalkToPlayer2
# 168 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
	goto MurenaCity_EventScript_TeamAirlockEncounter_11


MurenaCity_EventScript_ArtistTrader::
# 191 "data/maps/MurenaCity/scripts.pory"
	lock
# 192 "data/maps/MurenaCity/scripts.pory"
	faceplayer
# 193 "data/maps/MurenaCity/scripts.pory"
	goto_if_set FLAG_MURENA_NPC_TRADE_COMPLETED, MurenaCity_EventScript_ArtistTrader_2
# 198 "data/maps/MurenaCity/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_SMEARGLE
# 199 "data/maps/MurenaCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 200 "data/maps/MurenaCity/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 201 "data/maps/MurenaCity/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 202 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 9
# 203 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_ArtistTrader_Text_1, MSGBOX_YESNO
# 210 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 211 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 212 "data/maps/MurenaCity/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MurenaCity_EventScript_ArtistTrader_5
MurenaCity_EventScript_ArtistTrader_4:
# 215 "data/maps/MurenaCity/scripts.pory"
	special ChoosePartyMon
# 216 "data/maps/MurenaCity/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 217 "data/maps/MurenaCity/scripts.pory"
	compare VAR_0x8004, 255
	goto_if_eq MurenaCity_EventScript_ArtistTrader_8
MurenaCity_EventScript_ArtistTrader_7:
# 220 "data/maps/MurenaCity/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 221 "data/maps/MurenaCity/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 222 "data/maps/MurenaCity/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 223 "data/maps/MurenaCity/scripts.pory"
	compare VAR_RESULT, VAR_0x8009
# 224 "data/maps/MurenaCity/scripts.pory"
	goto_if_ne MurenaCity_EventScript_ArtistTrader_NotRequestedMon
# 225 "data/maps/MurenaCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 226 "data/maps/MurenaCity/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 227 "data/maps/MurenaCity/scripts.pory"
	special CreateInGameTradePokemon
# 228 "data/maps/MurenaCity/scripts.pory"
	special DoInGameTradeScene
# 229 "data/maps/MurenaCity/scripts.pory"
	bufferspeciesname 0, VAR_0x8009
# 230 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 9
# 231 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_ArtistTrader_Text_2
# 233 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 234 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 235 "data/maps/MurenaCity/scripts.pory"
	setflag FLAG_MURENA_NPC_TRADE_COMPLETED
# 236 "data/maps/MurenaCity/scripts.pory"
	release
	end

MurenaCity_EventScript_ArtistTrader_2:
# 194 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_ArtistTrader_Text_0, MSGBOX_NPC
	end

MurenaCity_EventScript_ArtistTrader_5:
# 213 "data/maps/MurenaCity/scripts.pory"
	goto MurenaCity_EventScript_ArtistTrader_Decline
	goto MurenaCity_EventScript_ArtistTrader_4

MurenaCity_EventScript_ArtistTrader_8:
# 218 "data/maps/MurenaCity/scripts.pory"
	goto MurenaCity_EventScript_ArtistTrader_Decline
	goto MurenaCity_EventScript_ArtistTrader_7


MurenaCity_EventScript_ArtistTrader_Decline::
# 241 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 9
# 242 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_ArtistTrader_Decline_Text_0
# 245 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 246 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 247 "data/maps/MurenaCity/scripts.pory"
	release
	end


MurenaCity_EventScript_ArtistTrader_NotRequestedMon::
# 252 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_ArtistTrader_NotRequestedMon_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_FeebasSeller::
# 258 "data/maps/MurenaCity/scripts.pory"
	lock
# 259 "data/maps/MurenaCity/scripts.pory"
	faceplayer
# 260 "data/maps/MurenaCity/scripts.pory"
	goto_if_set FLAG_MURENA_BOUGHT_FEEBAS, MurenaCity_EventScript_FeebasSeller_2
# 269 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 4
# 270 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_FeebasSeller_Text_1
# 274 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 275 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 276 "data/maps/MurenaCity/scripts.pory"
	showmoneybox 0, 0, 0
# 277 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 4
# 278 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_FeebasSeller_Text_2, MSGBOX_YESNO
# 280 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 281 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 282 "data/maps/MurenaCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MurenaCity_EventScript_FeebasSeller_5
# 305 "data/maps/MurenaCity/scripts.pory"
	hidemoneybox
# 306 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 4
# 307 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_FeebasSeller_Text_5
# 309 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 310 "data/maps/MurenaCity/scripts.pory"
	closemessage
MurenaCity_EventScript_FeebasSeller_4:
# 312 "data/maps/MurenaCity/scripts.pory"
	release
	end

MurenaCity_EventScript_FeebasSeller_2:
# 261 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 4
# 262 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_FeebasSeller_Text_0
# 264 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 265 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 266 "data/maps/MurenaCity/scripts.pory"
	release
	end

MurenaCity_EventScript_FeebasSeller_5:
# 283 "data/maps/MurenaCity/scripts.pory"
	checkmoney 500, 0
# 284 "data/maps/MurenaCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MurenaCity_EventScript_FeebasSeller_9
# 292 "data/maps/MurenaCity/scripts.pory"
	delay 10
# 293 "data/maps/MurenaCity/scripts.pory"
	playse SE_SHOP
# 294 "data/maps/MurenaCity/scripts.pory"
	removemoney 500, 0
# 295 "data/maps/MurenaCity/scripts.pory"
	updatemoneybox 0
# 296 "data/maps/MurenaCity/scripts.pory"
	delay 30
# 297 "data/maps/MurenaCity/scripts.pory"
	hidemoneybox
# 298 "data/maps/MurenaCity/scripts.pory"
	givemon SPECIES_FEEBAS, 5, ITEM_NONE
# 299 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 4
# 300 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_FeebasSeller_Text_4
# 301 "data/maps/MurenaCity/scripts.pory"
	setflag FLAG_MURENA_BOUGHT_FEEBAS
# 302 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 303 "data/maps/MurenaCity/scripts.pory"
	closemessage
	goto MurenaCity_EventScript_FeebasSeller_4

MurenaCity_EventScript_FeebasSeller_9:
# 285 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 4
# 286 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_FeebasSeller_Text_3
# 287 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 288 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 289 "data/maps/MurenaCity/scripts.pory"
	release
	end


MurenaCity_EventScript_OldMan::
# 317 "data/maps/MurenaCity/scripts.pory"
	lock
# 318 "data/maps/MurenaCity/scripts.pory"
	faceplayer
# 319 "data/maps/MurenaCity/scripts.pory"
	goto_if_set FLAG_MURENA_SHOWN_RELICANTH, MurenaCity_EventScript_OldMan_2
# 330 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 15
# 331 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_OldMan_Text_1
# 336 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 337 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 338 "data/maps/MurenaCity/scripts.pory"
	delay 30
# 339 "data/maps/MurenaCity/scripts.pory"
	specialvar VAR_RESULT, CheckMurenaCityRelicanth
# 340 "data/maps/MurenaCity/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MurenaCity_EventScript_OldMan_5
# 366 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 15
# 367 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_OldMan_Text_4
# 372 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 373 "data/maps/MurenaCity/scripts.pory"
	closemessage
MurenaCity_EventScript_OldMan_4:
# 375 "data/maps/MurenaCity/scripts.pory"
	release
	end

MurenaCity_EventScript_OldMan_2:
# 320 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 15
# 321 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_OldMan_Text_0
# 325 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 326 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 327 "data/maps/MurenaCity/scripts.pory"
	release
	end

MurenaCity_EventScript_OldMan_5:
# 341 "data/maps/MurenaCity/scripts.pory"
	playse SE_PIN
# 342 "data/maps/MurenaCity/scripts.pory"
	applymovement 15, Common_Movement_ExclamationMark
# 343 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 344 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 15
# 345 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_OldMan_Text_2
# 350 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 351 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 352 "data/maps/MurenaCity/scripts.pory"
	showmoneybox 0, 0, 0
# 353 "data/maps/MurenaCity/scripts.pory"
	delay 30
# 354 "data/maps/MurenaCity/scripts.pory"
	playse SE_SHOP
# 355 "data/maps/MurenaCity/scripts.pory"
	addmoney 25000, 0
# 356 "data/maps/MurenaCity/scripts.pory"
	updatemoneybox 0
# 357 "data/maps/MurenaCity/scripts.pory"
	delay 30
# 358 "data/maps/MurenaCity/scripts.pory"
	hidemoneybox
# 359 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 15
# 360 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_OldMan_Text_3
# 362 "data/maps/MurenaCity/scripts.pory"
	setflag FLAG_MURENA_SHOWN_RELICANTH
# 363 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 364 "data/maps/MurenaCity/scripts.pory"
	closemessage
	goto MurenaCity_EventScript_OldMan_4


MurenaCity_EventScript_Wingull::
# 380 "data/maps/MurenaCity/scripts.pory"
	lock
# 381 "data/maps/MurenaCity/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 382 "data/maps/MurenaCity/scripts.pory"
	waitmoncry
# 383 "data/maps/MurenaCity/scripts.pory"
	release
	end


MurenaCity_EventScript_MarketSalesWoman::
# 388 "data/maps/MurenaCity/scripts.pory"
	lock
# 389 "data/maps/MurenaCity/scripts.pory"
	faceplayer
# 390 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 5
# 391 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_MarketSalesWoman_Text_0
# 394 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 395 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 396 "data/maps/MurenaCity/scripts.pory"
	showmoneybox 0, 0, 0
# 397 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 5
# 398 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_MarketSalesWoman_Text_1, MSGBOX_YESNO
# 399 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 400 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 401 "data/maps/MurenaCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MurenaCity_EventScript_MarketSalesWoman_2
# 428 "data/maps/MurenaCity/scripts.pory"
	hidemoneybox
# 429 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 5
# 430 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_MarketSalesWoman_Text_4
# 433 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 434 "data/maps/MurenaCity/scripts.pory"
	closemessage
MurenaCity_EventScript_MarketSalesWoman_1:
# 436 "data/maps/MurenaCity/scripts.pory"
	release
	end

MurenaCity_EventScript_MarketSalesWoman_2:
# 403 "data/maps/MurenaCity/scripts.pory"
	checkmoney 250, 0
# 404 "data/maps/MurenaCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MurenaCity_EventScript_MarketSalesWoman_6
# 414 "data/maps/MurenaCity/scripts.pory"
	delay 10
# 415 "data/maps/MurenaCity/scripts.pory"
	playse SE_SHOP
# 416 "data/maps/MurenaCity/scripts.pory"
	removemoney 250, 0
# 417 "data/maps/MurenaCity/scripts.pory"
	updatemoneybox 0
# 418 "data/maps/MurenaCity/scripts.pory"
	delay 30
# 419 "data/maps/MurenaCity/scripts.pory"
	hidemoneybox
# 420 "data/maps/MurenaCity/scripts.pory"
	giveitem ITEM_TENTACOOL_SKEWER, 1
# 421 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 5
# 422 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_MarketSalesWoman_Text_3
# 423 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 424 "data/maps/MurenaCity/scripts.pory"
	closemessage
	goto MurenaCity_EventScript_MarketSalesWoman_1

MurenaCity_EventScript_MarketSalesWoman_6:
# 406 "data/maps/MurenaCity/scripts.pory"
	loadspeechtail FALSE, 5
# 407 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_MarketSalesWoman_Text_2
# 409 "data/maps/MurenaCity/scripts.pory"
	destroyspeechtail
# 410 "data/maps/MurenaCity/scripts.pory"
	closemessage
# 411 "data/maps/MurenaCity/scripts.pory"
	release
	end


MurenaCity_EventScript_MarketSalesMan::
# 441 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_MarketSalesMan_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_RichBoy::
# 448 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_RichBoy_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_Sailor1::
# 456 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_Sailor1_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_Sailor2::
# 462 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_Sailor2_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_Sailor3::
# 469 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_Sailor3_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_BugCatcher::
# 475 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_Woman::
# 481 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_Woman_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_OldWoman::
# 487 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_OldWoman_Text_0, MSGBOX_NPC
# 489 "data/maps/MurenaCity/scripts.pory"
	delay 60
# 490 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_OldWoman_Text_1
# 492 "data/maps/MurenaCity/scripts.pory"
	delay 24
# 493 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_OldWoman_Text_2, MSGBOX_NPC
# 495 "data/maps/MurenaCity/scripts.pory"
	playse SE_PIN
# 496 "data/maps/MurenaCity/scripts.pory"
	applymovement 12, Common_Movement_ExclamationMark
# 497 "data/maps/MurenaCity/scripts.pory"
	waitmovement 0
# 498 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_OldWoman_Text_3, MSGBOX_NPC
	end


MurenaCity_EventScript_Fisherman::
# 503 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_Fisherman_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_LittleGirl::
# 509 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_LittleGirl_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_CitySign::
# 515 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_CitySign_Text_0, MSGBOX_SIGN
	end


MurenaCity_EventScript_FishMarketSign::
# 521 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_FishMarketSign_Text_0, MSGBOX_SIGN
	end


MurenaCity_EventScript_DockyardSign::
# 527 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_DockyardSign_Text_0, MSGBOX_SIGN
	end


MurenaCity_EventScript_WailordFishingClubSign::
# 532 "data/maps/MurenaCity/scripts.pory"
	msgbox MurenaCity_EventScript_WailordFishingClubSign_Text_0, MSGBOX_SIGN
	end


# 537 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_Grunt2PunchFisherman:
# 538 "data/maps/MurenaCity/scripts.pory"
	lock_facing_direction
# 539 "data/maps/MurenaCity/scripts.pory"
	walk_slow_up
# 540 "data/maps/MurenaCity/scripts.pory"
	unlock_facing_direction
# 541 "data/maps/MurenaCity/scripts.pory"
	walk_in_place_faster_down
# 541 "data/maps/MurenaCity/scripts.pory"
	walk_in_place_faster_down
# 541 "data/maps/MurenaCity/scripts.pory"
	walk_in_place_faster_down
# 542 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
	step_end

# 545 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_FishermanStrugglesBack:
# 546 "data/maps/MurenaCity/scripts.pory"
	walk_in_place_faster_up
# 546 "data/maps/MurenaCity/scripts.pory"
	walk_in_place_faster_up
# 547 "data/maps/MurenaCity/scripts.pory"
	lock_facing_direction
# 548 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 549 "data/maps/MurenaCity/scripts.pory"
	unlock_facing_direction
	step_end

# 552 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_FishermanRunToPlayer1:
# 553 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 553 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 553 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 554 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 555 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 556 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 557 "data/maps/MurenaCity/scripts.pory"
	face_left
	step_end

# 560 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_FishermanRunToPlayer2:
# 561 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 561 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 562 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 562 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 563 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 563 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 564 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 565 "data/maps/MurenaCity/scripts.pory"
	face_left
	step_end

# 568 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_PlayerWalkToGrunt:
# 569 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 570 "data/maps/MurenaCity/scripts.pory"
	walk_down
# 571 "data/maps/MurenaCity/scripts.pory"
	face_left
	step_end

# 574 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_Grunt1RunAway:
# 575 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 576 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 576 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 577 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 577 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 577 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 577 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 577 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 577 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
	step_end

# 580 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_Grunt2RunAway:
# 581 "data/maps/MurenaCity/scripts.pory"
	delay_16
# 582 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 582 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 582 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 583 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 583 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 583 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 583 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 583 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 583 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
	step_end

# 586 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_FishermanWalkToPlayer1:
# 587 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 587 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 588 "data/maps/MurenaCity/scripts.pory"
	face_down
	step_end

# 591 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_FishermanWalkToPlayer2:
# 592 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 593 "data/maps/MurenaCity/scripts.pory"
	walk_up
# 594 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 595 "data/maps/MurenaCity/scripts.pory"
	face_down
	step_end

# 598 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_FishermanWalkToShipyard:
# 599 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 599 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 600 "data/maps/MurenaCity/scripts.pory"
	walk_up
	step_end

# 603 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_SailToLitor:
# 604 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 605 "data/maps/MurenaCity/scripts.pory"
	walk_fast_left
# 605 "data/maps/MurenaCity/scripts.pory"
	walk_fast_left
# 605 "data/maps/MurenaCity/scripts.pory"
	walk_fast_left
# 606 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 607 "data/maps/MurenaCity/scripts.pory"
	walk_down
# 608 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 608 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 609 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 610 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 610 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 611 "data/maps/MurenaCity/scripts.pory"
	walk_down
# 612 "data/maps/MurenaCity/scripts.pory"
	walk_right
# 613 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 613 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 614 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 614 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 614 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 614 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 614 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 614 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 614 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 615 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 615 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 616 "data/maps/MurenaCity/scripts.pory"
	walk_right
# 617 "data/maps/MurenaCity/scripts.pory"
	walk_up
# 618 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 618 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 618 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 618 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 619 "data/maps/MurenaCity/scripts.pory"
	walk_up
# 620 "data/maps/MurenaCity/scripts.pory"
	walk_right
# 621 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 621 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 622 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 623 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 623 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 624 "data/maps/MurenaCity/scripts.pory"
	walk_right
# 625 "data/maps/MurenaCity/scripts.pory"
	walk_down
# 626 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 626 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 627 "data/maps/MurenaCity/scripts.pory"
	walk_down
# 628 "data/maps/MurenaCity/scripts.pory"
	walk_right
# 629 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 629 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 630 "data/maps/MurenaCity/scripts.pory"
	walk_right
# 631 "data/maps/MurenaCity/scripts.pory"
	walk_down
# 632 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 632 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 633 "data/maps/MurenaCity/scripts.pory"
	walk_faster_down
# 634 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 634 "data/maps/MurenaCity/scripts.pory"
	walk_fast_down
# 635 "data/maps/MurenaCity/scripts.pory"
	walk_down
# 636 "data/maps/MurenaCity/scripts.pory"
	walk_right
# 637 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 637 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 638 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 638 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 638 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 638 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 638 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 638 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 638 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 638 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 638 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 638 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 639 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 639 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 640 "data/maps/MurenaCity/scripts.pory"
	walk_right
# 641 "data/maps/MurenaCity/scripts.pory"
	walk_up
# 642 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 643 "data/maps/MurenaCity/scripts.pory"
	walk_up
# 644 "data/maps/MurenaCity/scripts.pory"
	walk_right
# 645 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 645 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 646 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 646 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 646 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 646 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 646 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 646 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 646 "data/maps/MurenaCity/scripts.pory"
	walk_faster_right
# 647 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 647 "data/maps/MurenaCity/scripts.pory"
	walk_fast_right
# 648 "data/maps/MurenaCity/scripts.pory"
	walk_right
# 649 "data/maps/MurenaCity/scripts.pory"
	walk_up
# 650 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 650 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 651 "data/maps/MurenaCity/scripts.pory"
	walk_faster_up
# 651 "data/maps/MurenaCity/scripts.pory"
	walk_faster_up
# 652 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 652 "data/maps/MurenaCity/scripts.pory"
	walk_fast_up
# 653 "data/maps/MurenaCity/scripts.pory"
	walk_up
# 654 "data/maps/MurenaCity/scripts.pory"
	face_down
	step_end

# 657 "data/maps/MurenaCity/scripts.pory"
MurenaCity_Movement_ExitBoatLitorTown:
# 658 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 658 "data/maps/MurenaCity/scripts.pory"
	walk_left
# 659 "data/maps/MurenaCity/scripts.pory"
	face_right
	step_end

MurenaCity_EventScript_SailToLitor_Text_0:
# 75 "data/maps/MurenaCity/scripts.pory"
	.string "Ahoy! We've arrived at LITOR TOWN!\n"
	.string "You can smell the salty sea here too.$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_0:
# 92 "data/maps/MurenaCity/scripts.pory"
	.string "Hey!\n"
	.string "Let me through!\p"
	.string "I've got to get an important TENTACOOL\n"
	.string "haul for the MARKET tomorrow!$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_1:
# 99 "data/maps/MurenaCity/scripts.pory"
	.string "Do not resist!\p"
	.string "We are impounding your boat for\n"
	.string "the greater good!$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_2:
# 125 "data/maps/MurenaCity/scripts.pory"
	.string "Hey kiddo, ya gotta help me out here!\p"
	.string "Those thugs are trying to\n"
	.string "steal my ship!\p"
	.string "Please do something!$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_3:
# 141 "data/maps/MurenaCity/scripts.pory"
	.string "So what are you gonna do?!\n"
	.string "Save him?\p"
	.string "Hahaha!\n"
	.string "I don't think so kid!\p"
	.string "You can't take the wind\n"
	.string "out of our sails!$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_4:
# 151 "data/maps/MurenaCity/scripts.pory"
	.string "Oh no!\n"
	.string "You're stronger than I thought!\p"
	.string "Quickly!\n"
	.string "Let's get out of here!$"

MurenaCity_EventScript_TeamAirlockEncounter_Text_5:
# 173 "data/maps/MurenaCity/scripts.pory"
	.string "Phew… Thank you.\p"
	.string "I don't know what I would've done\n"
	.string "without you…\p"
	.string "Y'know what, as a reward, I'll ferry you\n"
	.string "across the straits free of charge!\p"
	.string "I'll be right here in the SHIPYARD if\n"
	.string "you need me.$"

MurenaCity_EventScript_ArtistTrader_Text_0:
# 194 "data/maps/MurenaCity/scripts.pory"
	.string "Jusqu'ici I am able to understand\n"
	.string "the ocean blue.$"

MurenaCity_EventScript_ArtistTrader_Text_1:
# 203 "data/maps/MurenaCity/scripts.pory"
	.string "The ocean is a canvas…\p"
	.string "But to truly blend into it,\n"
	.string "that deep dark blue…\p"
	.string "Only one POKéMON knows the art…\n"
	.string "Can you bring me one.\p"
	.string "If you can find me a KECLEON,\n"
	.string "I will give you my SMEARGLE…$"

MurenaCity_EventScript_ArtistTrader_Text_2:
# 231 "data/maps/MurenaCity/scripts.pory"
	.string "Magnificent…\n"
	.string "Such color I have never seen.$"

MurenaCity_EventScript_ArtistTrader_Decline_Text_0:
# 242 "data/maps/MurenaCity/scripts.pory"
	.string "I see…\p"
	.string "I guess true culture is hard to\n"
	.string "come by in these parts…$"

MurenaCity_EventScript_ArtistTrader_NotRequestedMon_Text_0:
# 252 "data/maps/MurenaCity/scripts.pory"
	.string "What?! I was offering you a\n"
	.string "SMEARGLE, not a pair of glasses!$"

MurenaCity_EventScript_FeebasSeller_Text_0:
# 262 "data/maps/MurenaCity/scripts.pory"
	.string "SORRY KIDDO, I AIN'T GOT\n"
	.string "ANY MORE FISHES!$"

MurenaCity_EventScript_FeebasSeller_Text_1:
# 270 "data/maps/MurenaCity/scripts.pory"
	.string "HEY KID!\n"
	.string "WANNA BUY THIS MAGIKARP?!\p"
	.string "IT'S KINDA UGLY, SO IT'S\n"
	.string "ONLY ¥500!$"

MurenaCity_EventScript_FeebasSeller_Text_2:
# 278 "data/maps/MurenaCity/scripts.pory"
	.string "WHADDYA SAY?\n"
	.string "¥500 AIN'T MUCH!$"

MurenaCity_EventScript_FeebasSeller_Text_3:
# 286 "data/maps/MurenaCity/scripts.pory"
	.string "NO NO NO, THAT WON'T DO!$"

MurenaCity_EventScript_FeebasSeller_Text_4:
# 300 "data/maps/MurenaCity/scripts.pory"
	.string "HERE YA GO KIDDO!$"

MurenaCity_EventScript_FeebasSeller_Text_5:
# 307 "data/maps/MurenaCity/scripts.pory"
	.string "IF YA DON'T APPRECIATE THE UGLY,\n"
	.string "YA DON'T DESERVE THE BEAUTIFUL!$"

MurenaCity_EventScript_OldMan_Text_0:
# 321 "data/maps/MurenaCity/scripts.pory"
	.string "Thank you friend, for showing me\n"
	.string "the true beauty of a RELICANTH.\p"
	.string "Perhaps once I will catch one of\n"
	.string "my very own…$"

MurenaCity_EventScript_OldMan_Text_1:
# 331 "data/maps/MurenaCity/scripts.pory"
	.string "I am looking for a creature…\n"
	.string "Ancient in age.\l"
	.string "Aquatic in nature.\p"
	.string "Bring my aquatic anomaly…\n"
	.string "For you shall be rewarded handsomely.$"

MurenaCity_EventScript_OldMan_Text_2:
# 345 "data/maps/MurenaCity/scripts.pory"
	.string "Oh yes…\n"
	.string "It surpasses even the wildest\l"
	.string "of imaginations…\p"
	.string "Here you are… your reward.\n"
	.string "That will come down to ¥25000$"

MurenaCity_EventScript_OldMan_Text_3:
# 360 "data/maps/MurenaCity/scripts.pory"
	.string "Spend it wisely…\p"
	.string "Thanks again, good friend…$"

MurenaCity_EventScript_OldMan_Text_4:
# 367 "data/maps/MurenaCity/scripts.pory"
	.string "I see…\p"
	.string "What I'm looking for you do\n"
	.string "not possess…\p"
	.string "If you could find it for me…\n"
	.string "I shall be very grateful…$"

MurenaCity_EventScript_MarketSalesWoman_Text_0:
# 391 "data/maps/MurenaCity/scripts.pory"
	.string "Hey there!\n"
	.string "I make MURENA CITY's delicacy, the\l"
	.string "famous TENTACOOL SKEWERS!$"

MurenaCity_EventScript_MarketSalesWoman_Text_1:
# 398 "data/maps/MurenaCity/scripts.pory"
	.string "One delicious skewer for ¥250?$"

MurenaCity_EventScript_MarketSalesWoman_Text_2:
# 407 "data/maps/MurenaCity/scripts.pory"
	.string "I'm sorry, but that's not\n"
	.string "quite enough dear.$"

MurenaCity_EventScript_MarketSalesWoman_Text_3:
# 422 "data/maps/MurenaCity/scripts.pory"
	.string "Eat up dear!$"

MurenaCity_EventScript_MarketSalesWoman_Text_4:
# 430 "data/maps/MurenaCity/scripts.pory"
	.string "That's okay too dear,\n"
	.string "I'll be right here if you want to\l"
	.string "taste one.$"

MurenaCity_EventScript_MarketSalesMan_Text_0:
# 441 "data/maps/MurenaCity/scripts.pory"
	.string "If I sell anything?\n"
	.string "No no, talk to my wife for that.\l"
	.string "I just wanna grill for pete's sake.$"

MurenaCity_EventScript_RichBoy_Text_0:
# 448 "data/maps/MurenaCity/scripts.pory"
	.string "Tssk…\p"
	.string "You may've beat me at FIRWEALD,\n"
	.string "but once my daddy's boat arrives\l"
	.string "I'll show you who's boss.$"

MurenaCity_EventScript_Sailor1_Text_0:
# 456 "data/maps/MurenaCity/scripts.pory"
	.string "The breeze here is so nice.\n"
	.string "There truly is no place like MURENA.$"

MurenaCity_EventScript_Sailor2_Text_0:
# 462 "data/maps/MurenaCity/scripts.pory"
	.string "A WINGULL just took my fry…\p"
	.string "Why do we keep these pests\n"
	.string "around anyway?$"

MurenaCity_EventScript_Sailor3_Text_0:
# 469 "data/maps/MurenaCity/scripts.pory"
	.string "You should try a TENTACOOL skewer!\n"
	.string "They truly do taste like heaven!$"

MurenaCity_EventScript_BugCatcher_Text_0:
# 475 "data/maps/MurenaCity/scripts.pory"
	.string "I wonder what BUG-types live\n"
	.string "across the EURUS region.$"

MurenaCity_EventScript_Woman_Text_0:
# 481 "data/maps/MurenaCity/scripts.pory"
	.string "Just watching ships go to and\n"
	.string "from the SHIPYARD is oddly calming…$"

MurenaCity_EventScript_OldWoman_Text_0:
# 487 "data/maps/MurenaCity/scripts.pory"
	.string "Oh, how it's changed here.\n"
	.string "See, back in my day…$"

MurenaCity_EventScript_OldWoman_Text_1:
# 490 "data/maps/MurenaCity/scripts.pory"
	.string "(As you snap back to your senses\n"
	.string "you realize you zoned out…)$"

MurenaCity_EventScript_OldWoman_Text_2:
# 493 "data/maps/MurenaCity/scripts.pory"
	.string "And that's why you young\n"
	.string "whippasnappas…$"

MurenaCity_EventScript_OldWoman_Text_3:
# 498 "data/maps/MurenaCity/scripts.pory"
	.string "Hey, are you even listening to me?$"

MurenaCity_EventScript_Fisherman_Text_0:
# 503 "data/maps/MurenaCity/scripts.pory"
	.string "I'm warming up.\p"
	.string "It's cold out at sea y'know.$"

MurenaCity_EventScript_LittleGirl_Text_0:
# 509 "data/maps/MurenaCity/scripts.pory"
	.string "When I grow up, I want to be\n"
	.string "a fisher. Just like daddy!$"

MurenaCity_EventScript_CitySign_Text_0:
# 515 "data/maps/MurenaCity/scripts.pory"
	.string "MURENA CITY\n"
	.string "“Fishing hotspot turned shipping port.”$"

MurenaCity_EventScript_FishMarketSign_Text_0:
# 521 "data/maps/MurenaCity/scripts.pory"
	.string "MURENA FISHING MARKET\n"
	.string "“Get yer fish 'ere!”$"

MurenaCity_EventScript_DockyardSign_Text_0:
# 527 "data/maps/MurenaCity/scripts.pory"
	.string "MURENA DOCKYARD$"

MurenaCity_EventScript_WailordFishingClubSign_Text_0:
# 532 "data/maps/MurenaCity/scripts.pory"
	.string "WAILORD FISHING CLUB\n"
	.string "“In search of the oceanic giant!”$"

MurenaCity_Text_GruntDefeat::
# 662 "data/maps/MurenaCity/scripts.pory"
	.string "Well that backfired…$"
