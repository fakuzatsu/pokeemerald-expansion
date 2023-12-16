Common_EventScript_PkmnCenterGTSLady::
    lock
    faceplayer
    msgbox gText_GTSLadyDoYouWantToUse, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterGTSLady_DeclineGTS
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
    goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterWonderLady_DeclineWonderTrade
	getpartysize
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterWonderLady_DeclineWonderTrade
    msgbox gText_PleaseSelectAPokemon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PkmnCenterWonderLady_DeclineWonderTrade
	copyvar VAR_0x8005, VAR_0x8004
	special CreateWonderTradePokemon
	special DoInGameTradeScene
	waitstate
    goto EventScript_PkmnCenterWonderLady_DeclineWonderTrade
    end

EventScript_PkmnCenterWonderLady_DeclineWonderTrade:
    release
	end

EventScript_PkmnCenterGTSLady_PickPokemonForGTS::
    msgbox gText_PleaseSelectAPokemon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterGTSLady_AreYouSure
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterGTSLady_DeclineGTS
    end

EventScript_PkmnCenterGTSLady_AreYouSure::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	bufferspeciesname STR_VAR_1, VAR_RESULT
    msgbox gText_GTSLadyAreYouSure, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterGTSLady_DoGTS
    goto EventScript_PkmnCenterGTSLady_DeclineGTS
    end

EventScript_PkmnCenterGTSLady_DoGTS::
    special PutPokemonOnGTS
    msgbox gText_GTSLadyHeresCode, MSGBOX_DEFAULT
    msgbox gText_GTSLadyEnterCodeNow, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterGTSLady_EnterCode
    goto EventScript_PkmnCenterGTSLady_DeclineGTS
    end

EventScript_PkmnCenterGTSLady_AlreadyPutAMon::
    msgbox gText_GTSLadyHeresCode, MSGBOX_DEFAULT
    msgbox gText_GTSLadyEnterCodeNow, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterGTSLady_EnterCode
    goto EventScript_PkmnCenterGTSLady_DeclineGTS
    end

EventScript_PkmnCenterGTSLady_TooFewPokemon::
    msgbox gText_GTSLadyTooFewPokemon, MSGBOX_DEFAULT
    goto EventScript_PkmnCenterGTSLady_DeclineGTS
    end

EventScript_PkmnCenterGTSLady_EnterCode::
    bufferstring STR_VAR_2, gText_Blank
    special EnterGTSCode
    waitstate
    special ResetWaldaWallpaper
    release
    end

EventScript_PkmnCenterGTSLady_DeclineGTS::
    release
    end
