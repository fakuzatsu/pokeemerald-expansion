.set LOCALID_SHELLY, 1

LilycoveCity_House5_MapScripts::
	.byte 0

LilycoveCity_House5_Shelly::
	lock
	goto_if_gt VAR_0x8005, 100, LilycoveCity_EventScript_GiveTemporaryStoredItem
	goto_if_set FLAG_TEMP_1, LilycoveCity_EventScript_SpeakShellyAfterBattle
	goto_if_set FLAG_DEFEATED_POSTGAME_SHELLY, LilycoveCity_EventScript_WantToBattleAgain
	msgbox LilycoveCity_Text_ShellyIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_RefuseShelly
	msgbox LilycoveCity_Text_HappyToOblidge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SHELLY_POSTGAME, LilycoveCity_Text_ShellyDefeat
	setflag FLAG_DEFEATED_POSTGAME_SHELLY
	msgbox LilycoveCity_Text_HereTakeThis, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_10
	setflag FLAG_TEMP_1
	goto LilycoveCity_EventScript_GiveWateriumZ
	release
	end

LilycoveCity_EventScript_WantToBattleAgain::
	msgbox LilycoveCity_Text_WantToBattleAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_RefuseShelly2
	trainerbattle_no_intro TRAINER_SHELLY_POSTGAME, LilycoveCity_Text_ShellyDefeat
	setflag FLAG_TEMP_1
	checkitem ITEM_WATERIUM_Z
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_GiveWateriumZAgain
	release
	end

LilycoveCity_EventScript_GiveWateriumZAgain::
	msgbox LilycoveCity_Text_TakeAnotherOneOfThese
	setflag FLAG_TEMP_10
	goto LilycoveCity_EventScript_GiveWateriumZ
	end

LilycoveCity_EventScript_RefuseShelly::
	msgbox LilycoveCity_Text_RefuseShelly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RefuseShelly2::
	msgbox LilycoveCity_Text_RefuseShelly2, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GiveWateriumZ::
	giveitem ITEM_WATERIUM_Z
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BagFullStoreWateriumZTemp
	goto_if_set FLAG_TEMP_10, LilycoveCity_EventScript_SkipExplination
	msgbox LilycoveCity_Text_ThatsWateriumZ, MSGBOX_DEFAULT
LilycoveCity_EventScript_SkipExplination::
	release
	end

LilycoveCity_EventScript_SpeakShellyAfterBattle::
	msgbox LilycoveCity_Text_ShellyAfterBattle
	release
	end

LilycoveCity_EventScript_BagFullStoreWateriumZTemp::
	msgbox LilycoveCity_Text_OhYourBagIsFull, MSGBOX_DEFAULT
	setvar VAR_0x8005, ITEM_WATERIUM_Z
	release
	end

LilycoveCity_EventScript_GiveTemporaryStoredItem::
	msgbox LilycoveCity_Text_HereTakeThis, MSGBOX_DEFAULT
	goto_if_eq VAR_0x8005, ITEM_WATERIUM_Z, LilycoveCity_EventScript_GiveWateriumZ
	end

LilycoveCity_Text_ShellyIntro:
	.string "Don't you think you've done enough\n"
	.string "already, kiddy?"
	.string "Or… What? did you come to let me\n"
	.string "pummel you into the ground?$"

LilycoveCity_Text_HappyToOblidge:
	.string "Ahahahaha!\p"
	.string "I'd be happy to oblidge!$"

LilycoveCity_Text_ShellyDefeat:
	.string "Hah… hah…$"

LilycoveCity_Text_HereTakeThis:
	.string "The way you and your Pokémon battle\n" 
	.string "so straightforwardly and sincerely…\p" 
	.string "With such hope.\p"
	.string "It's maddening.\p"
	.string "… … …\p"
	.string "Well I'm feeling more upbeat now at\n"
	.string "least.\p"
	.string "Here take this.$"

LilycoveCity_Text_WantToBattleAgain:
	.string "Oh, hey!\p"
	.string "Did you come to give me another shot\n"
	.string "at destroying you?$"

LilycoveCity_Text_TakeAnotherOneOfThese:
	.string "Looks like you could use another one\n"
	.string "of these…\p"
	.string "Go ahead and take it as a token of\n"
	.string "my gratitude.$"

LilycoveCity_Text_RefuseShelly:
	.string "…It wouldn't change anything\n"
	.string "anyways…$"

LilycoveCity_Text_RefuseShelly2:
	.string "Well…\p"
	.string "Thanks for coming anyways…$"

LilycoveCity_Text_ThatsWateriumZ:
	.string "That's a fragment of a special\n"
	.string "stone that we found.\p"
	.string "Make sure a water Pokémon holds onto\n"
	.string "it… ok?$"

LilycoveCity_Text_ShellyAfterBattle:
	.string "The way you battle…\p"
	.string "You're so sure of yourself…\p"
	.string "I still haven't figured out for myself\n"
	.string "what's wrong and what's right…$"

LilycoveCity_Text_OhYourBagIsFull:
	.string "Where did you get a hold of so\n"
	.string "much junk?\p"
	.string "You need to make some space in your\n"
	.string "bag for this.$"
