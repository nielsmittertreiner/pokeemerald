AcrenForest_IllegalCabin_MapScripts::
# 10 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AcrenForest_IllegalCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AcrenForest_IllegalCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	map_script_2 VAR_ACREN_FOREST_STATE, 6, AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene
	.2byte 0


AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene::
# 16 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AcrenForest_IllegalCabin_Movement_PlayerWalkForward
# 17 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 18 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_PIN
# 19 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 20 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 12
# 21 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_PIN
# 22 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 23 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 12
# 24 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_PIN
# 25 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 3, Common_Movement_ExclamationMark
# 26 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 12
# 27 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_PIN
# 28 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 29 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 30 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 1, AcrenForest_IllegalCabin_Movement_Grunt1RunToPlayer
# 31 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 4
# 32 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 2, AcrenForest_IllegalCabin_Movement_Grunt2RunToPlayer
# 33 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 4
# 34 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 3, AcrenForest_IllegalCabin_Movement_Grunt3RunToPlayer
# 35 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 4
# 36 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 4, AcrenForest_IllegalCabin_Movement_Grunt4RunToPlayer
# 37 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 4
# 38 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 39 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	loadspeechtail FALSE, 1
# 40 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_0
# 45 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	destroyspeechtail
# 46 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 47 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 1, Common_Movement_QuestionMark
# 48 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 60
# 49 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 50 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	loadspeechtail FALSE, 1
# 51 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_1
# 52 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	destroyspeechtail
# 53 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 54 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 1, AcrenForest_IllegalCabin_Movement_Grunt1LookAround
# 55 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 56 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	loadspeechtail FALSE, 1
# 57 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_2
# 60 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	destroyspeechtail
# 61 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 62 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 16
# 63 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	addobject 5
# 64 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	setobjectxy 5, 14, 8
# 65 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_EXIT
# 66 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 8
# 67 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 5, AcrenForest_IllegalCabin_Movement_PhyllosWalkForward
# 68 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 69 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 70 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 71 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	loadspeechtail FALSE, 5
# 72 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_3
# 74 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	destroyspeechtail
# 75 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 76 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	loadspeechtail FALSE, 1
# 77 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_4
# 79 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	destroyspeechtail
# 80 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 81 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 5, Common_Movement_FaceLeft
# 82 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 83 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	loadspeechtail FALSE, 5
# 84 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_5
# 85 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	destroyspeechtail
# 86 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 87 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 5, Common_Movement_FaceUp
# 88 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 89 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	loadspeechtail FALSE, 5
# 90 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_6
# 92 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	destroyspeechtail
# 93 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 94 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
# 95 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 96 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_BALL_THROW
# 97 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 12
# 98 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	addobject 6
# 99 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	setobjectxy 6, 13, 6
# 100 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 12
# 101 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_BALL_OPEN
# 102 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, -1
# 103 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 12
# 104 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	removeobject 6
# 105 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_LEFT
# 106 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	addobject 7
# 107 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	setobjectxy 7, 13, 6
# 108 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, -1
# 109 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playmoncry SPECIES_KECLEON, 0
# 110 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmoncry
# 111 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 7, Common_Movement_WalkFastestLeft
# 112 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, -4
# 113 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 114 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_M_RAZOR_WIND
# 115 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 16
# 116 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_M_RAZOR_WIND
# 117 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 16
# 118 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_M_RAZOR_WIND
# 119 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 16
# 120 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_7
# 121 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 122 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 1
# 123 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 1, AcrenForest_IllegalCabin_Movement_GruntsFallBack
# 124 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 2, AcrenForest_IllegalCabin_Movement_GruntsFallBack
# 125 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 126 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	loadspeechtail FALSE, 1
# 127 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_8
# 129 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	destroyspeechtail
# 130 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 131 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 1, AcrenForest_IllegalCabin_Movement_Grunt1RunOut
# 132 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 8
# 133 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 2, AcrenForest_IllegalCabin_Movement_Grunt2RunOut
# 134 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 4
# 135 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 3, AcrenForest_IllegalCabin_Movement_Grunt3RunOut
# 136 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 16
# 137 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 4, AcrenForest_IllegalCabin_Movement_Grunt4RunOut
# 138 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 139 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	removeobject 1
# 140 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	removeobject 2
# 141 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	removeobject 3
# 142 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	removeobject 4
# 143 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	loadspeechtail FALSE, 5
# 144 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_9
# 145 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	destroyspeechtail
# 146 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 147 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	addobject 6
# 148 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	setobjectxy 6, 13, 6
# 149 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 16
# 150 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_BALL_OPEN
# 151 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, -1
# 152 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 4
# 153 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	removeobject 7
# 154 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, -1
# 155 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 5, AcrenForest_IllegalCabin_Movement_PhyllosPickUpPokeball
# 156 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay 12
# 157 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	removeobject 6
# 158 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 159 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	loadspeechtail FALSE, 5
# 160 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_10
# 164 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	destroyspeechtail
# 165 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	closemessage
# 166 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	applymovement 5, Common_Movement_WalkDown2
# 167 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	waitmovement 0
# 168 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	playse SE_EXIT
# 169 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	removeobject 5
# 170 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	setvar VAR_ACREN_FOREST_STATE, 7
# 171 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	setflag FLAG_HIDE_ACREN_FOREST_GRUNTS
# 172 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	setflag FLAG_HIDE_ACREN_FOREST_LOGGERS
# 173 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	setflag FLAG_HIDE_ACREN_FOREST_PHYLLOS
# 174 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	clearflag FLAG_PHYLLOS_LEFT_TOURNAMENT_HALL_LOBBY
# 175 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	release
	end


# 179 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_PlayerWalkForward:
# 180 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_up
# 180 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_up
# 180 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_up
# 181 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	face_left
	step_end

# 184 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_Grunt1RunToPlayer:
# 185 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_fast_right
	step_end

# 188 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_Grunt2RunToPlayer:
# 189 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_fast_right
	step_end

# 192 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_Grunt3RunToPlayer:
# 193 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_fast_left
# 193 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_fast_left
# 194 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_fast_down
	step_end

# 197 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_Grunt4RunToPlayer:
# 198 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_fast_right
# 199 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_fast_down
	step_end

# 202 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_Grunt1LookAround:
# 203 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	face_left
# 204 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay_16
# 205 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	face_right
# 206 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay_16
# 207 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	face_left
# 208 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay_16
# 209 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	face_right
# 210 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay_16
	step_end

# 213 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_PhyllosWalkForward:
# 214 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_up
# 214 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_up
	step_end

# 217 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_GruntsFallBack:
# 218 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	lock_facing_direction
# 219 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_in_place_faster_right
# 219 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_in_place_faster_right
# 220 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_left
# 221 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	unlock_facing_direction
	step_end

# 224 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_Grunt1RunOut:
# 225 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 226 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 226 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 226 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 226 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 227 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 228 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	set_invisible
	step_end

# 231 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_Grunt2RunOut:
# 232 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 232 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 233 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 233 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 233 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 233 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 234 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 235 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	set_invisible
	step_end

# 238 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_Grunt3RunOut:
# 239 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 240 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_left
# 241 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 241 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 242 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 242 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 242 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_right
# 243 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 244 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	set_invisible
	step_end

# 247 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_Grunt4RunOut:
# 248 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 249 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_left
# 250 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 250 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 251 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_left
# 252 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_faster_down
# 253 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	set_invisible
	step_end

# 256 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
AcrenForest_IllegalCabin_Movement_PhyllosPickUpPokeball:
# 257 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	lock_facing_direction
# 258 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_left
# 259 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	delay_8
# 260 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	walk_right
# 261 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	unlock_facing_direction
# 262 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	face_up
	step_end

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_0:
# 40 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "How- how did you get in here!\n"
	.string "Didn't the guards stop you?!\p"
	.string "Hrmph… Fine then…\n"
	.string "I guess the BOSS will have to\l"
	.string "get you out then.$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_1:
# 51 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "Huh? Where's the BOSS gone?$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_2:
# 57 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "Oh no!\n"
	.string "He must have left early!\p"
	.string "Well then-$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_3:
# 72 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "It looks like you've made it…\n"
	.string "I'm not intruding I hope.$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_4:
# 77 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "It's PHYLLOS! The city's\n"
	.string "TOURNAMENT MASTER!$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_5:
# 84 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "I sure am, yes…$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_6:
# 90 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "Now, let's round these boys up\n"
	.string "shall we?…$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_7:
# 120 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "Aaaaahhhh!$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_8:
# 127 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "Everyone! Get out of here!\n"
	.string "Get back to base quickly!$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_9:
# 144 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "Return, KECLEON!$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_10:
# 160 "data/maps/AcrenForest_IllegalCabin/scripts.pory"
	.string "Now that we have that done,\n"
	.string "I suppose you could visit and\l"
	.string "challenge me in FIRWEALD CITY.\p"
	.string "I'll be waiting for you.$"
