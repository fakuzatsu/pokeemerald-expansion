Grotto25_MapScripts::
	.byte 0

Grotto25_EventScript_Meteorite::
	goto_if_ge VAR_ETERNATUS_STATE, 6, Grotto25_EventScript_InertMeteorite
	msgbox Grotto25_Text_Meteorite, MSGBOX_DEFAULT
	goto_if_set FLAG_TEMP_1, Grotto25_EventScript_AfterEternatus
	goto_if_eq VAR_ETERNATUS_STATE, 5, Grotto25_EventScript_Eternatus
	goto_if_lt VAR_ETERNATUS_STATE, 5, Grotto25_EventScript_UseWishingPieces
	release
	end

Grotto25_EventScript_UseWishingPieces::
	checkitem ITEM_WISHING_PIECE
	goto_if_eq VAR_RESULT, FALSE, Grotto25_EventScript_AfterEternatus
	goto_if_eq VAR_ETERNATUS_STATE, 4, Grotto25_EventScript_UseFinalPiece
	call_if_unset FLAG_TEMP_2, Grotto25_EventScript_UseFirstPiece
	call_if_set FLAG_TEMP_2, Grotto25_EventScript_UseAnotherPiece
	goto_if_eq VAR_RESULT, NO, Grotto25_EventScript_AfterEternatus
	call_if_lt VAR_ETERNATUS_STATE, 4, Grotto25_EventScript_UseFirstWishingPieces
	end

Grotto25_EventScript_UseFirstPiece::
	msgbox Grotto25_Text_TakeOutWishingPiece, MSGBOX_YESNO
	return

Grotto25_EventScript_UseAnotherPiece::
	msgbox Grotto25_Text_TakeOutAnother, MSGBOX_YESNO
	return

Grotto25_EventScript_UseFirstWishingPieces::
	addvar VAR_ETERNATUS_STATE, 1
	call Grotto25_EventScript_RemoveWishingPiece
	goto Grotto25_EventScript_UseWishingPieces

Grotto25_EventScript_UseFinalPiece::
	msgbox Grotto25_Text_FinalPiece, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Grotto25_EventScript_AfterEternatus
	setvar VAR_ETERNATUS_STATE, 5
	call Grotto25_EventScript_RemoveWishingPiece
	goto Grotto25_EventScript_Eternatus
	end

Grotto25_EventScript_RemoveWishingPiece::
	msgbox Grotto25_Text_TheWishingPieceJumped, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	removeitem ITEM_WISHING_PIECE
	return

Grotto25_EventScript_Eternatus::
	message Grotto30_Text_EternatusCry
	playmoncry SPECIES_ETERNATUS, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	seteventmon SPECIES_ETERNATUS, 70
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Grotto30_EventScript_EternatusDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Grotto30_EventScript_EternatusDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Grotto30_EventScript_EternatusDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, Grotto30_EventScript_EternatusDefeated
	setflag FLAG_TEMP_1
	setvar VAR_ETERNATUS_STATE, 6
	release
	end

Grotto30_EventScript_EternatusDefeated::
	setflag FLAG_TEMP_1
	bufferspeciesname STR_VAR_1, SPECIES_ETERNATUS
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	goto Grotto25_EventScript_AfterEternatus
	end

Grotto25_EventScript_AfterEternatus::
	release
	end

Grotto25_EventScript_InertMeteorite::
	msgbox Grotto25_Text_InertMeteorite, MSGBOX_DEFAULT
	release
	end

Grotto25_Text_Meteorite:
	.string "The dark rock radiates an eerie\n"
	.string "purple glow.$"

Grotto25_Text_TakeOutWishingPiece:
	.string "The Wishing Piece in your bag hums\n"
	.string "with power.\p" 
	.string "Take the Wishing Piece out of\n"
	.string "your bag?$"

Grotto25_Text_TakeOutAnother:
	.string "Take another Wishing Piece out of\n"
	.string "your bag?$"

Grotto25_Text_TheWishingPieceJumped:
	.string "The Wishing Piece lept from your\n"
	.string "hand and merged with the rock.$"

Grotto25_Text_FinalPiece:
	.string "The final Wishing Piece is humming\n"
	.string "with power.\p"
	.string "Take the final Wishing Piece out of\n"
	.string "your bag?$"

Grotto30_Text_EternatusCry:
	.string "Tyyyuuurrrn!$"

Grotto25_Text_InertMeteorite:
	.string "The dark rock lies inert$"
