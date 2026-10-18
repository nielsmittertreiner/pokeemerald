TentacoolSkewer_EventScript_ItemUseTentacoolSkewer::
# 4 "data/scripts/tentacool_skewer.pory"
	specialvar VAR_RESULT, IsPlayerInMurenaCity
# 5 "data/scripts/tentacool_skewer.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_2
# 23 "data/scripts/tentacool_skewer.pory"
	special TentacoolSkewerIncreaseFriendship
# 24 "data/scripts/tentacool_skewer.pory"
	msgbox TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_Text_1
# 27 "data/scripts/tentacool_skewer.pory"
	closemessage
	end

TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_2:
# 6 "data/scripts/tentacool_skewer.pory"
	fadescreenspeed FADE_TO_WHITE, -1
# 7 "data/scripts/tentacool_skewer.pory"
	fadescreenspeed FADE_FROM_WHITE, -1
# 8 "data/scripts/tentacool_skewer.pory"
	special SpawnMurenaCityWingullObject
# 9 "data/scripts/tentacool_skewer.pory"
	delay 24
# 10 "data/scripts/tentacool_skewer.pory"
	msgbox TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_Text_0
# 12 "data/scripts/tentacool_skewer.pory"
	closemessage
# 13 "data/scripts/tentacool_skewer.pory"
	playmoncry SPECIES_WINGULL, 1
# 14 "data/scripts/tentacool_skewer.pory"
	waitmoncry
# 15 "data/scripts/tentacool_skewer.pory"
	delay 10
# 16 "data/scripts/tentacool_skewer.pory"
	setwildbattle SPECIES_WINGULL, 15, ITEM_TENTACOOL_SKEWER
# 17 "data/scripts/tentacool_skewer.pory"
	dowildbattle
# 18 "data/scripts/tentacool_skewer.pory"
	fadescreen FADE_TO_BLACK
# 19 "data/scripts/tentacool_skewer.pory"
	removeobject 16
# 20 "data/scripts/tentacool_skewer.pory"
	fadescreen FADE_FROM_BLACK
	end


TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_Text_0:
# 10 "data/scripts/tentacool_skewer.pory"
	.string "A WINGULL swooped to snatch your\n"
	.string "TENTACOOL SKEWER!$"

TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_Text_1:
# 24 "data/scripts/tentacool_skewer.pory"
	.string "The TENTACOOL SKEWER tasted just\n"
	.string "like heaven!\p"
	.string "Your POKéMON feel delighted.$"
