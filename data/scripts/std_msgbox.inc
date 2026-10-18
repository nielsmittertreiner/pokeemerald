Std_MsgboxNPC:
	lock
	faceplayer
	specialvar VAR_RESULT GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, Std_LoadSpeechTailTop
	call_if_ne VAR_RESULT, DIR_NORTH, Std_LoadSpeechTailBottom
	message NULL
	waitmessage
	waitbuttonpress
	destroyspeechtail
	release
	return

Std_LoadSpeechTailTop::
	loadspeechtail TRUE, VAR_LAST_TALKED
	setvar VAR_MSGBOX_POS, TRUE
	return

Std_LoadSpeechTailBottom::
	loadspeechtail FALSE, VAR_LAST_TALKED
	setvar VAR_MSGBOX_POS, FALSE
	return

Std_MsgboxSign:
	lockall
	signmsg NULL
	waitmessage
	releaseall
	return

Std_MsgboxDefault:
	message NULL
	waitmessage
	waitbuttonpress
	return

Std_MsgboxYesNo:
	message NULL
	waitmessage
	yesnobox 20, 8
	return

Std_MsgboxGetPoints:
	message NULL
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	waitmessage
	return

@ Never used, pokenavcall is always used directly instead
Std_MsgboxPokenav:
	pokenavcall NULL
	waitmessage
	return

EventScript_UnusedReturn:
	return

Common_EventScript_SaveGame::
	special SaveGame
	return
