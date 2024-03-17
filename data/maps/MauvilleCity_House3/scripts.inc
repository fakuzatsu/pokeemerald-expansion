.set LOCALID_COURTNEY, 1

MauvilleCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_House3_OnTransition
	.byte 0

MauvilleCity_House3_OnTransition::
	goto_if_unset FLAG_DEFEATED_POSTGAME_COURTNEY, MauvilleCity_House3_Exclimation
	end

MauvilleCity_House3_Exclimation::
	delay 8
	playse SE_PIN
	applymovement LOCALID_COURTNEY, Common_Movement_ExclamationMark
	waitmovement 0
	end

MauvilleCity_House3_Courtney::
	lock
	goto_if_gt VAR_0x8005, 100, MauvilleCity_EventScript_GiveTemporaryStoredItem
	goto_if_set FLAG_TEMP_1, MauvilleCity_EventScript_SpeakCourtneyAfterBattle
	goto_if_set FLAG_DEFEATED_POSTGAME_COURTNEY, MauvilleCity_EventScript_WantToBattleAgain
	msgbox MauvilleCity_Text_CourtneyIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_RefuseCourtney
	trainerbattle_no_intro TRAINER_COURTNEY_POSTGAME, MauvilleCity_Text_CourtneyDefeat
	setflag FLAG_DEFEATED_POSTGAME_COURTNEY
	msgbox MauvilleCity_Text_HereTakeThis, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_10
	setflag FLAG_TEMP_1
	goto MauvilleCity_EventScript_GiveFiriumZ
	release
	end

MauvilleCity_EventScript_WantToBattleAgain::
	msgbox MauvilleCity_Text_WantToBattleAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_RefuseCourtney
	trainerbattle_no_intro TRAINER_COURTNEY_POSTGAME, MauvilleCity_Text_CourtneyDefeat
	setflag FLAG_TEMP_1
	checkitem ITEM_FIRIUM_Z
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_EventScript_GiveFiriumZAgain
	goto MauvilleCity_EventScript_SpeakCourtneyAfterBattle
	end

MauvilleCity_EventScript_GiveFiriumZAgain::
	msgbox MauvilleCity_Text_TakeAnotherOneOfThese
	setflag FLAG_TEMP_10
	goto MauvilleCity_EventScript_GiveFiriumZ
	end

MauvilleCity_EventScript_RefuseCourtney::
	msgbox MauvilleCity_Text_RefuseCourtney, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_GiveFiriumZ::
	giveitem ITEM_FIRIUM_Z
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_EventScript_BagFullStoreFiriumZTemp
	goto_if_set FLAG_TEMP_10, MauvilleCity_EventScript_SkipExplination
	msgbox MauvilleCity_Text_ThatsFiriumZ, MSGBOX_DEFAULT
MauvilleCity_EventScript_SkipExplination::
	release
	end

MauvilleCity_EventScript_SpeakCourtneyAfterBattle::
	random 50
	goto_if_eq VAR_RESULT 1, MauvilleCity_EventScript_CourtneyRareText
	msgbox MauvilleCity_Text_CourtneyAfterBattle
	release
	end

MauvilleCity_EventScript_BagFullStoreFiriumZTemp::
	msgbox MauvilleCity_Text_OhYourBagIsFull, MSGBOX_DEFAULT
	setvar VAR_0x8005, ITEM_FIRIUM_Z
	release
	end

MauvilleCity_EventScript_GiveTemporaryStoredItem::
	msgbox MauvilleCity_Text_HereTakeThis, MSGBOX_DEFAULT
	goto_if_eq VAR_0x8005, ITEM_FIRIUM_Z, MauvilleCity_EventScript_GiveFiriumZ
	end

MauvilleCity_EventScript_CourtneyRareText::
	msgbox MauvilleCity_Text_AnybodyImportantToYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Text_CourtneyIntro:
	.string "Courtney: Ahahahah…\n"
	.string "So you found me… even here?\p"
	.string "Unanticipated…\p"
	.string "But Team Magma… Disbanded…\p"
	.string "If I eliminate you… Leader Maxie…\n"
	.string "Mission… Complete.\p"
	.string "Prepared for… elimination?$"

MauvilleCity_Text_CourtneyDefeat:
	.string "Wha… Errgh!$"

MauvilleCity_Text_HereTakeThis:
	.string "Battling you…\p"
	.string "There is much about you that is…\n"
	.string "unanticipated.\p"
	.string "I want to… know more.\n"
	.string "Much more.\p"
	.string "You. Take… this present.$"

MauvilleCity_Text_WantToBattleAgain:
	.string "Courtney: Aha. You're here!\p"
    .string "You… Today, I want to analyze…\n" 
	.string "Again!\p"
	.string "Target locked.\n"
	.string "Prepared for… battle?$"

MauvilleCity_Text_TakeAnotherOneOfThese:
	.string "…Just barely!\p"
	.string "This. I found it…\p"
    .string "I'll give it… to you.\n"
	.string "This present.$"

MauvilleCity_Text_RefuseCourtney:
	.string "Wha… Target lost.$"

MauvilleCity_Text_ThatsFiriumZ:
	.string "That stone…\p"
	.string "-Fragment of Pokémon life energy from\n"
	.string "a great weapon.$"

MauvilleCity_Text_CourtneyAfterBattle:
	.string "Thank… you. I understand…\n"
	.string "thanks to you…\p"
	.string "I want to… experiment…\n"
	.string "forever… ahahah…$"

MauvilleCity_Text_AnybodyImportantToYou:
	.string "Is there anyone… important to you?\p"
	.string "If there's someone who's important\n"
	.string "to you… Target… lock!$"

MauvilleCity_Text_OhYourBagIsFull:
	.string "Your bag…\p"
	.string "Create space… for this.$"
