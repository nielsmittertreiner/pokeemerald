Std_MsgboxNPC: @ 8271315
	lock
	faceplayer
	specialvar VAR_RESULT, IsPlayerInFlashCave
	compare VAR_RESULT, 1
	call_if_eq Std_MsgboxLoadSpeechBubble
	message 0x0
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, IsPlayerInFlashCave
	compare VAR_RESULT, 1
	call_if_eq Std_MsgboxDestroySpeechBubble
	release
	return

Std_MsgboxLoadSpeechBubble:
	load_speech_bubble VAR_LAST_TALKED
	return

Std_MsgboxDestroySpeechBubble:
	destroy_speech_bubble
	return

Std_MsgboxSign: @ 8271320
	lockall
	message 0x0
	waitmessage
	waitbuttonpress
	releaseall
	return

Std_MsgboxDefault: @ 827132A
	message 0x0
	waitmessage
	waitbuttonpress
	return

Std_MsgboxYesNo: @ 8271332
	message 0x0
	waitmessage
	yesnobox 20, 8
	return

Std_MsgboxGetPoints: @ 827133C
	message 0x0
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	waitmessage
	return

Std_10: @ 8271347
	pokenavcall 0x0
	waitmessage
	return

EventScript_UnusedReturn: @ 827134E
	return

Common_EventScript_SaveGame:: @ 827134F
	special SaveGame
	waitstate
	return
