Debug_EventScript_DoConfetti::
	special DoDomeConfetti
	waitstate
	return


Debug_EventScript_ShowEndOfCurrentBeta::
	lock
	special ShowEndOfCurrentBetaScreen
	waitbuttonpress
	special HideEndOfCurrentBetaScreen
	release
	end

