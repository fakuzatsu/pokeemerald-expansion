Common_EventScript_PkmnCenterBattleMaster::
    lock
    faceplayer
    goto_if_unset FLAG_RECEIVED_EXP_SHARE, Common_EventScript_PkmnCenterBattleMaster_Introduction
    goto_if_set FLAG_SYS_ENFORCED_HARDMODE, Common_EventScript_PkmnCenterBattleMaster_OhChallengeCard
	message gText_ImTheBattleMaster
	waitmessage
    waitbuttonpress
    goto_if_set FLAG_SYS_HARD_LEVEL_CAP, Common_EventScript_PkmnCenterBattleMaster_EffectiveHardCap
    goto_if_set FLAG_SYS_SOFT_LEVEL_CAP, Common_EventScript_PkmnCenterBattleMaster_EffectiveSoftCap
    message gText_NoEffectiveCap
    waitmessage
    waitbuttonpress
    goto Common_EventScript_PkmnCenterBattleMaster_WouldYouLikeToChange
    end

Common_EventScript_PkmnCenterBattleMaster_EffectiveHardCap::
    special SetLevelCapStringVar
    message gText_EffectiveHardCap
    waitmessage
    waitbuttonpress
    goto Common_EventScript_PkmnCenterBattleMaster_WouldYouLikeToChange
    end

Common_EventScript_PkmnCenterBattleMaster_EffectiveSoftCap::
    special SetLevelCapStringVar
    message gText_EffectiveSoftCap
    waitmessage
    waitbuttonpress
    goto Common_EventScript_PkmnCenterBattleMaster_WouldYouLikeToChange
    end 

Common_EventScript_PkmnCenterBattleMaster_WouldYouLikeToChange::
    message gText_WouldYouLikeMeToChange
    waitmessage
	multichoice 16, 6, MULTI_CHOOSE_LEVEL_CAP, FALSE
	switch VAR_RESULT
	case 0, Common_EventScript_PkmnCenterBattleMaster_SoftLevelCaps
	case 1, Common_EventScript_PkmnCenterBattleMaster_HardLevelCaps
	case 2, Common_EventScript_PkmnCenterBattleMaster_Cancel
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterBattleMaster_Cancel
    end

Common_EventScript_PkmnCenterBattleMaster_OhChallengeCard::
    goto_if_set FLAG_SYS_GAME_CLEAR, Common_EventScript_PkmnCenterBattleMaster_ExcellentWork
    message gText_ImTheBattleMasterOhCard
    waitmessage
    waitbuttonpress
    release
    end

Common_EventScript_PkmnCenterBattleMaster_ExcellentWork::
    message gText_YouDidItIncredible
    waitmessage
    waitbuttonpress
    checkitem ITEM_EXP_CHARM
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_PkmnCenterBattleMaster_TakeThisCharm
    release
    end

Common_EventScript_PkmnCenterBattleMaster_TakeThisCharm::
    message gText_TakeThisToCommemorate
    waitmessage
    waitbuttonpress
    giveitem ITEM_EXP_CHARM
    message gText_MoreChallengesAwait
    waitmessage
    waitbuttonpress
    release
    end

Common_EventScript_PkmnCenterBattleMaster_CancelBack::
	message gText_AnythingElseHm
	waitmessage
	multichoice 16, 6, MULTI_CHOOSE_LEVEL_CAP, FALSE
	switch VAR_RESULT
	case 0, Common_EventScript_PkmnCenterBattleMaster_SoftLevelCaps
	case 1, Common_EventScript_PkmnCenterBattleMaster_HardLevelCaps
	case 2, Common_EventScript_PkmnCenterBattleMaster_Cancel
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterBattleMaster_Cancel
    end

Common_EventScript_PkmnCenterBattleMaster_SoftLevelCaps::
    setvar VAR_0x8004, 1
	message gText_WouldYouLikeMeToDo
	waitmessage
	multichoice 21, 6, MULTI_EXPLAIN_OR_TOGGLE, FALSE
	switch VAR_RESULT
	case 0, Common_EventScript_PkmnCenterBattleMaster_ToggleSoftCap
	case 1, Common_EventScript_PkmnCenterBattleMaster_ExplainSoftCap
	case 2, Common_EventScript_PkmnCenterBattleMaster_CancelBack
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterBattleMaster_CancelBack
    end

Common_EventScript_PkmnCenterBattleMaster_ToggleSoftCap::
    goto_if_unset FLAG_SYS_SOFT_LEVEL_CAP, Common_EventScript_PkmnCenterBattleMaster_ToggleSoftCapOn
    clearflag FLAG_SYS_SOFT_LEVEL_CAP
    playse SE_PC_OFF
    message gText_OkItIsOff
    waitmessage
    waitbuttonpress
    goto Common_EventScript_PkmnCenterBattleMaster_SoftLevelCaps
    end

Common_EventScript_PkmnCenterBattleMaster_ToggleSoftCapOn::
    setflag FLAG_SYS_SOFT_LEVEL_CAP
    playse SE_PC_LOGIN
    message gText_OkItIsOn
    waitmessage
    waitbuttonpress
    goto Common_EventScript_PkmnCenterBattleMaster_SoftLevelCaps
    end

Common_EventScript_PkmnCenterBattleMaster_ExplainSoftCap::
    message gText_ExplainSoftCap
    waitmessage
    waitbuttonpress
    goto Common_EventScript_PkmnCenterBattleMaster_SoftLevelCaps
    end

Common_EventScript_PkmnCenterBattleMaster_HardLevelCaps::
    setvar VAR_0x8004, 2
	message gText_WouldYouLikeMeToDo
	waitmessage
	multichoice 21, 6, MULTI_EXPLAIN_OR_TOGGLE, FALSE
	switch VAR_RESULT
	case 0, Common_EventScript_PkmnCenterBattleMaster_ToggleHardCap
	case 1, Common_EventScript_PkmnCenterBattleMaster_ExplainHardCap
	case 2, Common_EventScript_PkmnCenterBattleMaster_CancelBack
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterBattleMaster_CancelBack
    end

Common_EventScript_PkmnCenterBattleMaster_ToggleHardCap::
    goto_if_unset FLAG_SYS_HARD_LEVEL_CAP, Common_EventScript_PkmnCenterBattleMaster_ToggleHardCapOn
    clearflag FLAG_SYS_HARD_LEVEL_CAP
    playse SE_PC_OFF
    message gText_OkItIsOff
    waitmessage
    waitbuttonpress
    goto Common_EventScript_PkmnCenterBattleMaster_HardLevelCaps
    end

Common_EventScript_PkmnCenterBattleMaster_ToggleHardCapOn::
    setflag FLAG_SYS_HARD_LEVEL_CAP
    playse SE_PC_LOGIN
    message gText_OkItIsOn
    waitmessage
    waitbuttonpress
    goto Common_EventScript_PkmnCenterBattleMaster_HardLevelCaps
    end

Common_EventScript_PkmnCenterBattleMaster_ExplainHardCap::
    message gText_ExplainHardCap
    waitmessage
    waitbuttonpress
    goto Common_EventScript_PkmnCenterBattleMaster_HardLevelCaps
    end

Common_EventScript_PkmnCenterBattleMaster_Cancel::
	message gText_ReturnToChangeExperience
    waitmessage
    waitbuttonpress
    release
	end

Common_EventScript_PkmnCenterBattleMaster_Introduction::
    message gText_BattleMasterIntroduction
    waitmessage
    waitbuttonpress
    call Common_EventScript_PkmnCenterBattleMaster_GiveExpShare
    goto Common_EventScript_PkmnCenterBattleMaster

Common_EventScript_PkmnCenterBattleMaster_GiveExpShare::
    message gText_BattleMasterGiveExpShare
    waitmessage
    waitbuttonpress
    giveitem ITEM_EXP_SHARE
    setflag FLAG_RECEIVED_EXP_SHARE
    message gText_BattleMasterPostExpShare
    waitmessage
    waitbuttonpress
    return

