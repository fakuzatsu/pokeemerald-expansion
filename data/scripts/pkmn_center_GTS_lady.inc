Common_EventScript_PkmnCenterGTSLady::
    lock
    faceplayer
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterGTSLady_AreYouSure
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PkmnCenterGTSLady_DeclineGTS
    end

EventScript_PkmnCenterGTSLady_AreYouSure::
    msgbox gText_GTSLadyAreYouSure, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterGTSLady_DoGTS
    goto EventScript_PkmnCenterGTSLady_DeclineGTS
    end

EventScript_PkmnCenterGTSLady_DoGTS::
    special PutPokemonOnGTS
    msgbox gText_GTSLadyHeresCode, MSGBOX_DEFAULT

EventScript_PkmnCenterGTSLady_DeclineGTS::
    release
    end

Common_EventScript_PkmnCenterGTSLady2::
    lock
    special EnterGTSCode
    waitstate
    release
    end