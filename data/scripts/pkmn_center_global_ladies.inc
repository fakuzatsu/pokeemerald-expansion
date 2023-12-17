Common_EventScript_PkmnCenterGTSLady::
    lock
    faceplayer
    msgbox gText_GTSLadyDoYouWantToUse, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterGlobalLady_DeclineTrade
    specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterGTSLady_AlreadyPutAMon
    getpartysize
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterGTSLady_TooFewPokemon
    goto_if_eq VAR_RESULT, 1, EventScript_PkmnCenterGTSLady_TooFewPokemon
    goto EventScript_PkmnCenterGTSLady_PickPokemonForGTS
    end

Common_EventScript_PkmnCenterWonderLady::
    lock
    faceplayer
    msgbox gText_WonderLadyDoYouWantToUse, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterGlobalLady_DeclineTrade
	getpartysize
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterGlobalLady_DeclineTrade
    goto EventScript_PkmnCenterWonderLady_PickPokemonForWonderTrade
    end

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
    msgbox gText_GTSLadyEnterCodeNow, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterGTSLady_EnterCode
    goto EventScript_PkmnCenterGlobalLady_DeclineTrade
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

EventScript_PkmnCenterGTSLady_AlreadyPutAMon::
    specialvar VAR_RESULT, getSpeciesFromWaldaStruct
    bufferspeciesname STR_VAR_2, VAR_RESULT
    msgbox gText_GTSLadyAlreadyOnTheGTS, MSGBOX_DEFAULT
    msgbox gText_GTSLadyHeresCode, MSGBOX_DEFAULT
    msgbox gText_GTSLadyEnterCodeNow, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterGTSLady_EnterCode
    goto EventScript_PkmnCenterGlobalLady_DeclineTrade
    end

EventScript_PkmnCenterGTSLady_TooFewPokemon::
    msgbox gText_GTSLadyTooFewPokemon, MSGBOX_DEFAULT
    goto EventScript_PkmnCenterGlobalLady_DeclineTrade
    end

EventScript_PkmnCenterGTSLady_EnterCode::
    bufferstring STR_VAR_2, gText_Blank
    special EnterGTSCode
    waitstate
    goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterGlobalLady_FinishTrade
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
