Common_EventScript_PkmnCenterGTSLady::
    lock
    faceplayer
EventScript_PkmnCenterGTSLady_ReturnToStart::
    message gText_GTSLadyDoYouWantToUse
    waitmessage
    multichoice 18, 6, MULTI_GTS_USE_OR_EXPLAIN, FALSE
	switch VAR_RESULT
    case 0, EventScript_PkmnCenterGTSLady_TryUse
    case 1, EventScript_PkmnCenterGTSLady_Explain
    case 2, EventScript_PkmnCenterGlobalLady_DeclineTrade
    case MULTI_B_PRESSED, EventScript_PkmnCenterGlobalLady_DeclineTrade
    end

Common_EventScript_PkmnCenterWonderLady::
    lock
    faceplayer
EventScript_PkmnCenterWonderLady_ReturnToStart::
    message gText_WonderLadyDoYouWantToUse
    waitmessage
    multichoice 18, 6, MULTI_WONDER_USE_OR_EXPLAIN, FALSE
	switch VAR_RESULT
    case 0, EventScript_PkmnCenterWonderLady_TryUse
    case 1, EventScript_PkmnCenterWonderLady_Explain
    case 2, EventScript_PkmnCenterGlobalLady_DeclineTrade
    case MULTI_B_PRESSED, EventScript_PkmnCenterGlobalLady_DeclineTrade
    end

EventScript_PkmnCenterGTSLady_TryUse::
    specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterGTSLady_AlreadyPutAMon
    getpartysize
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterGTSLady_TooFewPokemon
    goto_if_eq VAR_RESULT, 1, EventScript_PkmnCenterGTSLady_TooFewPokemon
    goto EventScript_PkmnCenterGTSLady_PickPokemonForGTS
    end

EventScript_PkmnCenterWonderLady_TryUse::
	getpartysize
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterGlobalLady_DeclineTrade
    goto EventScript_PkmnCenterWonderLady_PickPokemonForWonderTrade
    end

EventScript_PkmnCenterGTSLady_Explain::
    msgbox gText_GTSLadyExplainService, MSGBOX_DEFAULT
    goto EventScript_PkmnCenterGTSLady_ReturnToStart

EventScript_PkmnCenterWonderLady_Explain::
    msgbox gText_WonderLadyExplainService, MSGBOX_DEFAULT
    goto EventScript_PkmnCenterWonderLady_ReturnToStart

EventScript_PkmnCenterGTSLady_PickPokemonForGTS::
    msgbox gText_PleaseSelectAPokemon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
    goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PkmnCenterGlobalLady_DeclineTrade
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterGTSLady_AreYouSure
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterGlobalLady_DeclineTrade
    end

EventScript_PkmnCenterWonderLady_PickPokemonForWonderTrade::
    msgbox gText_PleaseSelectAPokemon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PkmnCenterGlobalLady_DeclineTrade
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterWonderLady_AreYouSure
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterGlobalLady_DeclineTrade
    end

EventScript_PkmnCenterGTSLady_AreYouSure::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	bufferspeciesname STR_VAR_2, VAR_RESULT
    msgbox gText_GTSLadyAreYouSure, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterGTSLady_DoGTS
    goto EventScript_PkmnCenterGlobalLady_DeclineTrade
    end

EventScript_PkmnCenterWonderLady_AreYouSure::
    specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	bufferspeciesname STR_VAR_2, VAR_RESULT
    msgbox gText_WonderLadyAreYouSure, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterWonderLady_DoWonder
    goto EventScript_PkmnCenterGlobalLady_DeclineTrade
    end

EventScript_PkmnCenterGTSLady_DoGTS::
    message gText_ConnectingToGlobalNetwork
    waitmessage
    delay 120
    playse SE_SAVE
    delay 20
    special PutPokemonOnGTS
    msgbox gText_GTSLadyWasDeposited, MSGBOX_DEFAULT
    msgbox gText_GTSLadyHeresCode, MSGBOX_DEFAULT
    goto EventScript_PkmnCenterGTSLady_ReturnToMultichoice
    end

EventScript_PkmnCenterWonderLady_DoWonder::
    message gText_ConnectingToGlobalNetwork
    waitmessage
    delay 120
    playse SE_SAVE
    delay 20
	copyvar VAR_0x8005, VAR_0x8004
	special CreateWonderTradePokemon
	special DoInGameTradeScene
	waitstate
    goto EventScript_PkmnCenterGlobalLady_FinishTrade
    end

EventScript_PkmnCenterGTSLady_TooFewPokemon::
    msgbox gText_GTSLadyTooFewPokemon, MSGBOX_DEFAULT
    goto EventScript_PkmnCenterGlobalLady_DeclineTrade
    end

EventScript_PkmnCenterGTSLady_AlreadyPutAMon::
    specialvar VAR_RESULT, getSpeciesFromWaldaStruct
    bufferspeciesname STR_VAR_2, VAR_RESULT
    msgbox gText_GTSLadyAlreadyOnTheGTS, MSGBOX_DEFAULT
EventScript_PkmnCenterGTSLady_ReturnToMultichoice::
    message gText_GTSWhatWouldYouLikeToDo
    waitmessage
    multichoice 17, 4, MULTI_GTS_CODE_OR_TAKE_BACK, FALSE
	switch VAR_RESULT
    case 0, EventScript_PkmnCenterGTSLady_SeeCode
    case 1, EventScript_PkmnCenterGTSLady_EnterCode
    case 2, EventScript_PkmnCenterGTSLady_TakeBack
    case 3, EventScript_PkmnCenterGlobalLady_DeclineTrade
    case MULTI_B_PRESSED, EventScript_PkmnCenterGlobalLady_DeclineTrade
    end

EventScript_PkmnCenterGTSLady_SeeCode::
    msgbox gText_GTSLadyHeresCode, MSGBOX_DEFAULT
    goto EventScript_PkmnCenterGTSLady_ReturnToMultichoice
    end

EventScript_PkmnCenterGTSLady_EnterCode::
    bufferstring STR_VAR_2, gText_Blank
    special EnterGTSCode
    waitstate
    goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterGTSLady_ReturnToMultichoice
    special ResetWaldaWallpaper
    message gText_ConnectingToGlobalNetwork
    waitmessage
    delay 120
    playse SE_SAVE
    delay 20
    msgbox gText_GTSLadyPokemonRecieved, MSGBOX_DEFAULT
    release
    end

EventScript_PkmnCenterGTSLady_TakeBack::
    specialvar VAR_RESULT, TryBufferWaldaPhrase
    goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterGlobalLady_DeclineTrade
    special GetPokemonFromStringVarOne
    special ResetWaldaWallpaper
    message gText_ConnectingToGlobalNetwork
    waitmessage
    delay 120
    playse SE_SAVE
    delay 20
    msgbox gText_GTSLadyPokemonRecieved, MSGBOX_DEFAULT
    release
    end

EventScript_PkmnCenterGlobalLady_DeclineTrade::
    msgbox gText_GlobalPleaseComeAgain, MSGBOX_DEFAULT
EventScript_PkmnCenterGlobalLady_FinishTrade::
    release
    end
