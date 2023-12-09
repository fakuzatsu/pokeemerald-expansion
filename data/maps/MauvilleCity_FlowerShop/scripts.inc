.set LOCALID_OWNER, 1

MauvilleCity_FlowerShop_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_FlowerShop_onLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_FlowerShop_onTransition
	.byte 0

MauvilleCity_FlowerShop_onLoad:
	call_if_unset FLAG_LORNA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_HideLorna
	call_if_unset FLAG_LYDIA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_HideLydia
	call_if_unset FLAG_LISLA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_HideLisla
	end

MauvilleCity_FlowerShop_HideLorna::
	setflag FLAG_TEMP_1
	return

MauvilleCity_FlowerShop_HideLydia::
	setflag FLAG_TEMP_2
	return

MauvilleCity_FlowerShop_HideLisla::
	setflag FLAG_TEMP_3
	return

MauvilleCity_FlowerShop_onTransition::
	goto_if_unset FLAG_LORNA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_StopCheck
	goto_if_unset FLAG_LORNA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_StopCheck
	goto_if_unset FLAG_LISLA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_StopCheck
	setvar VAR_MAUVILLE_FLOWER_SHOP_STATE, 4

MauvilleCity_FlowerShop_StopCheck::
	end

	@ State descriptions for VAR_MAUVILLE_FLOWER_SHOP_STATE
	@ 1: Flower Shop Quest is Availble due to meeting one of the Flower Sisters
	@ 2: Flower Shop Quest has been initiated by talking to the shop keeper
	@ 3: At least one sister present in the shop
	@ 4: All three sisters have been gathered at the shop
	@ 5: The shop keeper has given the player the Bouquet

MauvilleCity_FlowerShop_EventScript_ShopOwner::
	lock
	faceplayer
	call_if_unset FLAG_MAUVILLE_FLOWER_SHOP, MauvilleCity_FlowerShop_EventScript_DescribeShop
	goto_if_eq VAR_0x8002, 1, MauvilleCity_FlowerShop_EventScript_SkipQuestFirstTimeMet
	call_if_eq VAR_MAUVILLE_FLOWER_SHOP_STATE, 5, MauvilleCity_FlowerShop_EventScript_PersonalWelcome
	goto_if_eq VAR_MAUVILLE_FLOWER_SHOP_STATE, 4, MauvilleCity_FlowerShop_EventScript_QuestComplete
	call_if_eq VAR_MAUVILLE_FLOWER_SHOP_STATE, 3, MauvilleCity_FlowerShop_EventScript_ThankForQuest
	call_if_eq VAR_MAUVILLE_FLOWER_SHOP_STATE, 2, MauvilleCity_FlowerShop_EventScript_AskAboutQuest
	call_if_eq VAR_MAUVILLE_FLOWER_SHOP_STATE, 1, MauvilleCity_FlowerShop_EventScript_ActivateQuest
MauvilleCity_FlowerShop_EventScript_SkipQuestFirstTimeMet::
	showmoneybox 0, 0
	msgbox MauvilleCity_FlowerShop_Text_StrangeBerryFor5000, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_FlowerShop_EventScript_DeclineStrangeBerry
	checkmoney 5000
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_FlowerShop_EventScript_NotEnoughMoney
	msgbox MauvilleCity_FlowerShop_Text_ThankYouVeryMuch, MSGBOX_DEFAULT
	checkitemspace ITEM_ENIGMA_BERRY
	call_if_eq VAR_RESULT, TRUE, MauvilleCity_FlowerShop_EventScript_RemoveMoney
	giveitem ITEM_ENIGMA_BERRY
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_FlowerShop_EventScript_BagIsFull
	hidemoneybox
	release
	end

MauvilleCity_FlowerShop_EventScript_DescribeShop::
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox MauvilleCity_FlowerShop_Text_WelcomeToShop
	closemessage
	setvar VAR_0x8002, 1
	setflag FLAG_MAUVILLE_FLOWER_SHOP
	return

MauvilleCity_FlowerShop_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MauvilleCity_FlowerShop_EventScript_RemoveMoney::
	removemoney 5000
	updatemoneybox
	return

MauvilleCity_FlowerShop_EventScript_DeclineStrangeBerry::
	msgbox MauvilleCity_FlowerShop_Text_OhThatsOk, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MauvilleCity_FlowerShop_EventScript_NotEnoughMoney::
	msgbox MauvilleCity_FlowerShop_Text_OhThatsNotEnough, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MauvilleCity_FlowerShop_EventScript_SetQuestAvailable::
	setvar VAR_MAUVILLE_FLOWER_SHOP_STATE, 1
	return

MauvilleCity_FlowerShop_EventScript_ActivateQuest::
	setvar VAR_0x8002, 1
	setvar VAR_MAUVILLE_FLOWER_SHOP_STATE, 2
	msgbox MauvilleCity_FlowerShop_Text_LookingForCustomers, MSGBOX_DEFAULT
	return

MauvilleCity_FlowerShop_EventScript_AskAboutQuest::
	setvar VAR_0x8002, 1
	msgbox MauvilleCity_FlowerShop_Text_AnyLuckWithQuest, MSGBOX_DEFAULT
	return

MauvilleCity_FlowerShop_EventScript_ThankForQuest::
	setvar VAR_0x8002, 1
	msgbox MauvilleCity_FlowerShop_Text_ThankForQuest, MSGBOX_DEFAULT
	return

MauvilleCity_FlowerShop_EventScript_QuestComplete::
	setvar VAR_0x8002, 1
	setvar VAR_MAUVILLE_FLOWER_SHOP_STATE, 5
	msgbox MauvilleCity_FlowerShop_Text_TakeThisAsThanks, MSGBOX_DEFAULT
	giveitem ITEM_GRACIDEA
	msgbox MauvilleCity_FlowerShop_Text_HopeToKeepGrowing, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_FlowerShop_EventScript_PersonalWelcome::
	msgbox MauvilleCity_FlowerShop_Text_OhHiPlayer, MSGBOX_DEFAULT
	setvar VAR_0x8002, 1
	goto MauvilleCity_FlowerShop_EventScript_SkipQuestFirstTimeMet

MauvilleCity_FlowerShop_EventScript_Lorna::
	lock
	faceplayer
	goto_if_set FLAG_LYDIA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_EventScript_LornaSistersPresent
	goto_if_set FLAG_LISLA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_EventScript_LornaSistersPresent
	msgbox MauvilleCity_FlowerShop_Text_LornaInterestingPlace, MSGBOX_DEFAULT
	release
	end

MauvilleCity_FlowerShop_EventScript_LornaSistersPresent::
	msgbox MauvilleCity_FlowerShop_Text_LornaSistersPresent, MSGBOX_DEFAULT
	release
	end

MauvilleCity_FlowerShop_EventScript_Lydia::
	lock
	faceplayer
	goto_if_set FLAG_LORNA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_EventScript_LydiaSistersPresent
	goto_if_set FLAG_LISLA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_EventScript_LydiaSistersPresent
	msgbox MauvilleCity_FlowerShop_Text_LydiaInterestingPlace, MSGBOX_DEFAULT
	release
	end

MauvilleCity_FlowerShop_EventScript_LydiaSistersPresent::
	msgbox MauvilleCity_FlowerShop_Text_LydiaSistersPresent, MSGBOX_DEFAULT
	release
	end

MauvilleCity_FlowerShop_EventScript_Lisla::
	lock
	faceplayer
	goto_if_set FLAG_LORNA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_EventScript_LislaSistersPresent
	goto_if_set FLAG_LYDIA_MOVED_TO_SHOP, MauvilleCity_FlowerShop_EventScript_LislaSistersPresent
	msgbox MauvilleCity_FlowerShop_Text_LislaInterestingPlace, MSGBOX_DEFAULT
	release
	end

MauvilleCity_FlowerShop_EventScript_LislaSistersPresent::
	msgbox MauvilleCity_FlowerShop_Text_LislaSistersPresent, MSGBOX_DEFAULT
	release
	end

MauvilleCity_FlowerShop_Text_StrangeBerryFor5000:
	.string "Would you like to buy one of\n"
	.string "my strange Berries for ¥5000?$"

MauvilleCity_FlowerShop_Text_ThankYouVeryMuch:
	.string "Wow! thank you so much!$"

MauvilleCity_FlowerShop_Text_OhThatsOk:
	.string "Oh. That's ok!\p"
	.string "I'll keep trying to grow berries\n"
	.string "until I get it right!$"

MauvilleCity_FlowerShop_Text_OhThatsNotEnough:
	.string "Oh you don't have ¥5000?\p"
	.string "I would give you this berry for\n"
	.string "free. But…\p"
	.string "I need to make money so I can\n"
	.string "keep growing berries…$"

MauvilleCity_FlowerShop_Text_WelcomeToShop:
	.string "Hi there!\p"
	.string "…Welcome to my flower shop!\p"
	.string "… … …\p"
	.string "Sorry! I'm still setting up!\p"
	.string "I'm trying to make this place\n"
	.string "just as nice as the SHOP on\l"
	.string "ROUTE 104!\p"
	.string "But whenever I try to grow any\n"
	.string "Berries, they turn …strange.\p"
	.string "I still need money to set\n"
	.string "this place up though!\p"
	.string "… … …\n"
	.string "So…$"

MauvilleCity_FlowerShop_Text_LookingForCustomers:
	.string "Oh hey you!\p"
	.string "…I've been thinking…\p"
	.string "I need to draw a bigger\n"
	.string "audience to my little store…\p"
	.string "I don't suppose you happen\n"
	.string "to know anybody who would be\l"
	.string "interested in coming here?\p"
	.string "A few people would be nice!\p"
	.string "Maybe trainers who are very\n"
	.string "close to nature!…\p"
	.string "… … …\p"
	.string "I'd really appreciate it, if\n"
	.string "you helped draw them here!\p"
	.string "… … …\n"
	.string "Uh… but for now…$"

MauvilleCity_FlowerShop_Text_AnyLuckWithQuest:
	.string "Oh hey you!\p"
	.string "Any luck with finding more\n"
	.string "customers for the store?\p"
	.string "… … …\p"
	.string "Oh uh…$"

MauvilleCity_FlowerShop_Text_ThankForQuest:
	.string "Oh hey!\n"
	.string "Somebody came!\p"
	.string "Thank you so much for bringing\n"
	.string "trainers here!\p"
	.string "Maybe I can actually get this\n"
	.string "little store off the ground!$"

MauvilleCity_FlowerShop_Text_TakeThisAsThanks:
	.string "Wow you really did it!\p"
	.string "So many people have come by my\n"
	.string "little shop.\p"
	.string "The sisters over there have\n"
	.string "been telling me so much about\l"
	.string "growing actual plants!\p"
	.string "In fact…\p"
	.string "This here is one of the first\n"
	.string "I've been able to grow.\p"
	.string "I want you to have it!\p"
	.string "As thanks for keeping my\n"
	.string "dream alive!$"

MauvilleCity_FlowerShop_Text_HopeToKeepGrowing:
	.string "…I hope to keep growing my\n"
	.string "little shop…\p"
	.string "and myself too!\p"
	.string "Just like plants grow!$"

MauvilleCity_FlowerShop_Text_OhHiPlayer:
	.string "Oh! Hi, {PLAYER}!$"

MauvilleCity_FlowerShop_Text_LornaInterestingPlace:
MauvilleCity_FlowerShop_Text_LornaSistersPresent:
MauvilleCity_FlowerShop_Text_LydiaInterestingPlace:
MauvilleCity_FlowerShop_Text_LydiaSistersPresent:
MauvilleCity_FlowerShop_Text_LislaInterestingPlace:
MauvilleCity_FlowerShop_Text_LislaSistersPresent:
	.string "Unfinished.$"

