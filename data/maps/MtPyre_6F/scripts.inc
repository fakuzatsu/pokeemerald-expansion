MtPyre_6F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MtPyre_6F_OnLoad
	.byte 0

MtPyre_6F_OnLoad:
	goto_if_defeated TRAINER_PHOEBE_MT_PYRE, MtPyre_6F_EventScript_HidePhoebe
	goto_if_unset FLAG_RECEIVED_RED_OR_BLUE_ORB, MtPyre_6F_EventScript_HidePhoebe
	setflag FLAG_TEMP_6
	end

MtPyre_6F_EventScript_HidePhoebe:
	setflag FLAG_TEMP_5
	goto_if_unset FLAG_HIDE_PHOEBES_GRANDMA, MtPyre_6F_EventScript_ShowPhoebesGrandma
	setflag FLAG_TEMP_6
	end

MtPyre_6F_EventScript_ShowPhoebesGrandma:
	end

MtPyre_6F_EventScript_LaxIncenseArea::
	setvar VAR_DAYNIGHT, 1
	end

MtPyre_6F_EventScript_LeaveLaxIncenseArea::
	setvar VAR_DAYNIGHT, 0
	end

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Phoebe::
	lock
	faceplayer
	msgbox MtPyre_6F_Text_PhoebeIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtPyre_6F_EventScript_RefusePhoebe
	trainerbattle_no_intro TRAINER_PHOEBE_MT_PYRE, MtPyre_6F_Text_PhoebeDefeat
	msgbox MtPyre_6F_Text_PhoebePostBattle, MSGBOX_DEFAULT
	giveitem ITEM_TM60
	msgbox MtPyre_6F_Text_ThatTMContainsDrainPunch, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RefusePhoebe::
	msgbox MtPyre_6F_Text_RefusePhoebe, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_PhoebesGrandma::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_RED_OR_BLUE_ORB, MtPyre_6F_EventScript_PhoebesGrandmaPreOrb
	goto_if_gt VAR_0x8005, 100, MtPyre_6F_EventScript_GiveTemporaryStoredItem
	goto_if_set FLAG_PHOEBES_GRANDMA_BATTLE, MtPyre_6F_EventScript_PhoebesGrandmaAfterBattle
	msgbox MtPyre_6F_Text_PhoebesGrandmaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtPyre_6F_EventScript_RefusePhoebesGrandma
	trainerbattle_no_intro TRAINER_PHOEBES_GRANDMA, MtPyre_6F_Text_PhoebesGrandmaDefeat
	setflag FLAG_PHOEBES_GRANDMA_BATTLE
	msgbox MtPyre_6F_Text_PhoebesGrandmaPostBattle, MSGBOX_DEFAULT
	checkitem ITEM_GHOSTIUM_Z
	goto_if_eq VAR_RESULT, FALSE, MtPyre_6F_EventScript_GiveGhostiumZ
MtPyre_6F_EventScript_GiveNugget::
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, MtPyre_6F_EventScript_BagFullStoreNuggetTemp
MtPyre_6F_EventScript_PhoebesGrandmaAfterBattle::
	msgbox MtPyre_6F_Text_PhoebesGrandmaAfterBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_PhoebesGrandmaPreOrb::
	msgbox MtPyre_6F_Text_PhoebesGrandmaPreOrb
	release
	end

MtPyre_6F_EventScript_BagFullStoreNuggetTemp::
	msgbox MtPyre_6F_Text_OhYourBagIsFull, MSGBOX_DEFAULT
	setvar VAR_0x8005, ITEM_NUGGET
	release
	end

MtPyre_6F_EventScript_RefusePhoebesGrandma::
	msgbox MtPyre_6F_Text_RefusePhoebesGrandma, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_GiveGhostiumZ::
	giveitem ITEM_GHOSTIUM_Z
	goto_if_eq VAR_RESULT, FALSE, MtPyre_6F_EventScript_BagFullStoreGhostiumZTemp
	msgbox MtPyre_6F_Text_ThatsGhostiumZ, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_BagFullStoreGhostiumZTemp::
	msgbox MtPyre_6F_Text_OhYourBagIsFull, MSGBOX_DEFAULT
	setvar VAR_0x8005, ITEM_GHOSTIUM_Z
	release
	end

MtPyre_6F_EventScript_GiveTemporaryStoredItem::
	msgbox MtPyre_6F_Text_HereTakeThis, MSGBOX_DEFAULT
	goto_if_eq VAR_0x8005, ITEM_NUGGET, MtPyre_6F_EventScript_GiveNugget
	goto_if_eq VAR_0x8005, ITEM_GHOSTIUM_Z, MtPyre_6F_EventScript_GiveGhostiumZ
	end

MtPyre_6F_Text_PhoebeIntro:
MtPyre_6F_Text_PhoebeDefeat:
MtPyre_6F_Text_PhoebePostBattle:
MtPyre_6F_Text_ThatTMContainsDrainPunch:
MtPyre_6F_Text_RefusePhoebe:
MtPyre_6F_Text_PhoebesGrandmaPreOrb:
MtPyre_6F_Text_PhoebesGrandmaIntro:
MtPyre_6F_Text_PhoebesGrandmaDefeat:
MtPyre_6F_Text_PhoebesGrandmaPostBattle:
MtPyre_6F_Text_PhoebesGrandmaAfterBattle:
MtPyre_6F_Text_OhYourBagIsFull:
MtPyre_6F_Text_RefusePhoebesGrandma:
MtPyre_6F_Text_ThatsGhostiumZ:
MtPyre_6F_Text_HereTakeThis:
	.string "Placeholder.$"

MtPyre_6F_Text_ValerieIntro:
	.string "When I'm here…\n"
	.string "A curious power flows into me…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "The power is ebbing away…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Perhaps the power is from the spirits\n"
	.string "of Pokémon in fitful sleep here…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… I lost the match, but…\n"
	.string "I have this little ability…\p"
	.string "Without ever laying my hands on\n"
	.string "your PokéNav… Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Behind you…\n"
	.string "What is it…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Something faded away…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "The Pokémon at rest here…\n"
	.string "Sometimes, they play…$"

MtPyre_6F_Text_CedricIntro:
	.string "Have you lost your bearings?\n"
	.string "Have no fear for I am here!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Weren't you lost?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "I had this feeling that a lost Trainer\n"
	.string "would be panicked and easy to beat.\p"
	.string "It's dirty and I won't try it again…$"

