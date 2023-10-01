.set LOCALID_OWNER, 1

MauvilleCity_FlowerShop_MapScripts::
	.byte 0

MauvilleCity_FlowerShop_EventScript_ShopOwner::
	lock
	faceplayer
	call_if_unset FLAG_MAUVILLE_FLOWER_SHOP, MauvilleCity_FlowerShop_EventScript_DescribeShop
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
	.string "just as nice as the SHOP on\p"
	.string "ROUTE 104!\p"
	.string "But whenever I try to grow any\n"
	.string "Berries, they turn …strange.\p"
	.string "I still need money to set\n"
	.string "this place up though!\p"
	.string "… … …\n"
	.string "So…$"

