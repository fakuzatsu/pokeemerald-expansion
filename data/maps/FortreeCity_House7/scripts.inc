FortreeCity_House7_MapScripts::
	.byte 0

	.set WISHING_PIECE_PRICE,	 5
	.set ABILITY_SHIELD_PRICE,	 10
	.set CLEAR_AMULET_PRICE,	 10
	.set AUSPICIOUS_ARMOR_PRICE, 15
	.set MALICIOUS_ARMOR_PRICE,  15
	.set RUSTED_SHIELD_PRICE,	 50
	.set RUSTED_SWORD_PRICE,	 50
	.set LOWEST_ITEM_PRICE,		 WISHING_PIECE_PRICE

FortreeCity_House7_EventScript_RelicTrader::
	lock
	faceplayer
	goto_if_eq VAR_RELIC_WORKSHOP_STATE, 0, FortreeCity_House7_EventScript_MeetRelicTrader
	goto_if_eq VAR_RELIC_WORKSHOP_STATE, 1, FortreeCity_House7_EventScript_MeetRelicTrader
	goto_if_ge VAR_RELIC_WORKSHOP_STATE, 10, FortreeCity_House7_EventScript_GiveItemAfterNoRoom
	goto FortreeCity_House7_EventScript_CraftOrExchange
	release
	end

FortreeCity_House7_EventScript_MeetRelicTrader::
	msgbox FortreeCity_House7_Text_RelicTraderIntroduction, MSGBOX_DEFAULT
	setvar VAR_RELIC_WORKSHOP_STATE, 2
	goto FortreeCity_House7_EventScript_CraftOrExchange
	end

FortreeCity_House7_EventScript_CraftOrExchange::
	message FortreeCity_House7_Text_CraftOrExchange
	waitmessage
	multichoice 18, 4, MULTI_RELIC_CRAFTER_SELECTION, FALSE
	switch VAR_RESULT
	case 0, FortreeCity_House7_EventScript_Craft
	case 1, FortreeCity_House7_EventScript_Exchange
	case 2, FortreeCity_House7_EventScript_Explain
	case 3, FortreeCity_House7_EventScript_CancelItemSelect
	case MULTI_B_PRESSED, FortreeCity_House7_EventScript_CancelItemSelect
	end

FortreeCity_House7_EventScript_Explain::
	msgbox FortreeCity_House7_Text_ExplainRelicCrafting, MSGBOX_DEFAULT
	goto FortreeCity_House7_EventScript_CraftOrExchange
	end

FortreeCity_House7_EventScript_Craft::
	msgbox FortreeCity_House7_Text_HowMuchRelicGold, MSGBOX_DEFAULT
	checkitem ITEM_RELIC_GOLD, LOWEST_ITEM_PRICE
	goto_if_eq VAR_RESULT, FALSE, FortreeCity_House7_EventScript_NotEnoughAsh
	bufferitemcount ITEM_RELIC_GOLD
	copyvar VAR_0x8009, VAR_RESULT
	buffernumberstring STR_VAR_2, VAR_0x8009
	message FortreeCity_House7_Text_WhichItemWoudYouLike
	waitmessage
	goto FortreeCity_House7_EventScript_ChooseItem
	end

FortreeCity_House7_EventScript_ChooseItem::
	setvar VAR_0x8004, SCROLL_MULTI_RELIC_WORKSHOP_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, FortreeCity_House7_EventScript_WishingPiece
	case 1, FortreeCity_House7_EventScript_AbilityShield
	case 2, FortreeCity_House7_EventScript_ClearAmulet
	case 3, FortreeCity_House7_EventScript_AuspiciousArmor
	case 4, FortreeCity_House7_EventScript_MaliciousArmor
	case 5, FortreeCity_House7_EventScript_RustedShield
	case 6, FortreeCity_House7_EventScript_RustedSword
	case 7, FortreeCity_House7_EventScript_CancelItemSelect
	case MULTI_B_PRESSED, FortreeCity_House7_EventScript_CancelItemSelect
	end

FortreeCity_House7_EventScript_WishingPiece::
	setvar VAR_0x8008, ITEM_WISHING_PIECE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, WISHING_PIECE_PRICE
	goto_if_lt VAR_0x8009, WISHING_PIECE_PRICE, FortreeCity_House7_EventScript_NotEnoughAshForItem
	msgbox FortreeCity_House7_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House7_EventScript_ChooseDifferentItem
	setvar VAR_RELIC_WORKSHOP_STATE, 10
	removeitem ITEM_RELIC_GOLD, WISHING_PIECE_PRICE
	goto FortreeCity_House7_EventScript_CraftItem
	end

FortreeCity_House7_EventScript_AbilityShield::
	setvar VAR_0x8008, ITEM_ABILITY_SHIELD
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, ABILITY_SHIELD_PRICE
	goto_if_lt VAR_0x8009, ABILITY_SHIELD_PRICE, FortreeCity_House7_EventScript_NotEnoughAshForItem
	msgbox FortreeCity_House7_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House7_EventScript_ChooseDifferentItem
	setvar VAR_RELIC_WORKSHOP_STATE, 11
	removeitem ITEM_RELIC_GOLD, ABILITY_SHIELD_PRICE
	goto FortreeCity_House7_EventScript_CraftItem
	end

FortreeCity_House7_EventScript_ClearAmulet::
	setvar VAR_0x8008, ITEM_CLEAR_AMULET
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, CLEAR_AMULET_PRICE
	goto_if_lt VAR_0x8009, CLEAR_AMULET_PRICE, FortreeCity_House7_EventScript_NotEnoughAshForItem
	msgbox FortreeCity_House7_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House7_EventScript_ChooseDifferentItem
	setvar VAR_RELIC_WORKSHOP_STATE, 12
	removeitem ITEM_RELIC_GOLD, CLEAR_AMULET_PRICE
	goto FortreeCity_House7_EventScript_CraftItem
	end

FortreeCity_House7_EventScript_AuspiciousArmor::
	setvar VAR_0x8008, ITEM_AUSPICIOUS_ARMOR
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, AUSPICIOUS_ARMOR_PRICE
	goto_if_lt VAR_0x8009, AUSPICIOUS_ARMOR_PRICE, FortreeCity_House7_EventScript_NotEnoughAshForItem
	msgbox FortreeCity_House7_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House7_EventScript_ChooseDifferentItem
	setvar VAR_RELIC_WORKSHOP_STATE, 13
	removeitem ITEM_RELIC_GOLD, AUSPICIOUS_ARMOR_PRICE
	goto FortreeCity_House7_EventScript_CraftItem
	end

FortreeCity_House7_EventScript_MaliciousArmor::
	setvar VAR_0x8008, ITEM_MALICIOUS_ARMOR
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, MALICIOUS_ARMOR_PRICE
	goto_if_lt VAR_0x8009, MALICIOUS_ARMOR_PRICE, FortreeCity_House7_EventScript_NotEnoughAshForItem
	msgbox FortreeCity_House7_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House7_EventScript_ChooseDifferentItem
	setvar VAR_RELIC_WORKSHOP_STATE, 14
	removeitem ITEM_RELIC_GOLD, MALICIOUS_ARMOR_PRICE
	goto FortreeCity_House7_EventScript_CraftItem
	end

FortreeCity_House7_EventScript_RustedShield::
	setvar VAR_0x8008, ITEM_RUSTED_SHIELD
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, RUSTED_SHIELD_PRICE
	goto_if_lt VAR_0x8009, RUSTED_SHIELD_PRICE, FortreeCity_House7_EventScript_NotEnoughAshForItem
	msgbox FortreeCity_House7_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House7_EventScript_ChooseDifferentItem
	setvar VAR_RELIC_WORKSHOP_STATE, 15
	removeitem ITEM_RELIC_GOLD, RUSTED_SHIELD_PRICE
	goto FortreeCity_House7_EventScript_CraftItem
	end

FortreeCity_House7_EventScript_RustedSword::
	setvar VAR_0x8008, ITEM_RUSTED_SWORD
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, RUSTED_SWORD_PRICE
	goto_if_lt VAR_0x8009, RUSTED_SWORD_PRICE, FortreeCity_House7_EventScript_NotEnoughAshForItem
	msgbox FortreeCity_House7_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House7_EventScript_ChooseDifferentItem
	setvar VAR_RELIC_WORKSHOP_STATE, 16
	removeitem ITEM_RELIC_GOLD, RUSTED_SWORD_PRICE
	goto FortreeCity_House7_EventScript_CraftItem
	end

FortreeCity_House7_EventScript_CancelItemSelect::
	msgbox FortreeCity_House7_Text_FineSoBeIt, MSGBOX_DEFAULT
	release
	end

FortreeCity_House7_EventScript_NotEnoughAsh::
	buffernumberstring STR_VAR_1, LOWEST_ITEM_PRICE
	msgbox FortreeCity_House7_Text_NotEnoughGoldToMakeAnything, MSGBOX_DEFAULT
	release
	end

FortreeCity_House7_EventScript_NotEnoughAshForItem::
	subvar VAR_0x800A, VAR_0x8009
	buffernumberstring STR_VAR_2, VAR_0x8009
	buffernumberstring STR_VAR_3, VAR_0x800A
	message FortreeCity_House7_Text_NotEnoughGoldToMakeItem
	waitmessage
	goto FortreeCity_House7_EventScript_ChooseItem
	end

FortreeCity_House7_EventScript_ChooseDifferentItem::
	buffernumberstring STR_VAR_2, VAR_0x8009
	message FortreeCity_House7_Text_WhichItemWoudYouLike
	waitmessage
	goto FortreeCity_House7_EventScript_ChooseItem
	end

FortreeCity_House7_EventScript_CraftItem::
	msgbox FortreeCity_House7_Text_IllCraftItemForYou, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_SELECT
	delay 30
	fadescreen FADE_FROM_BLACK
	msgbox FortreeCity_House7_Text_WorkIsDone, MSGBOX_DEFAULT
	call FortreeCity_House7_EventScript_GiveCraftedItem
	setvar VAR_RELIC_WORKSHOP_STATE, 2
	release
	end

FortreeCity_House7_EventScript_GiveCraftedItem::
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, FortreeCity_House7_EventScript_NoRoomForItem
	return

FortreeCity_House7_EventScript_NoRoomForItem::
	call Common_EventScript_BagIsFull
	msgbox FortreeCity_House7_Text_NoRoomInBag, MSGBOX_DEFAULT
	release
	end

FortreeCity_House7_EventScript_GiveItemAfterNoRoom::
	switch VAR_RELIC_WORKSHOP_STATE
	case 10, FortreeCity_House7_EventScript_GiveWishingPiece
	case 11, FortreeCity_House7_EventScript_GiveAbilityShield
	case 12, FortreeCity_House7_EventScript_GiveClearAmulet
	case 13, FortreeCity_House7_EventScript_GiveAuspiciousArmor
	case 14, FortreeCity_House7_EventScript_GiveMaliciousArmor
	case 15, FortreeCity_House7_EventScript_GiveRustedShield
	case 16, FortreeCity_House7_EventScript_GiveRustedSword
	end

FortreeCity_House7_EventScript_GiveWishingPiece::
	setvar VAR_0x8008, ITEM_WISHING_PIECE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto FortreeCity_House7_EventScript_TryGiveItemAgain
	end

FortreeCity_House7_EventScript_GiveAbilityShield::
	setvar VAR_0x8008, ITEM_ABILITY_SHIELD
	bufferitemname STR_VAR_1, VAR_0x8008
	goto FortreeCity_House7_EventScript_TryGiveItemAgain
	end

FortreeCity_House7_EventScript_GiveClearAmulet::
	setvar VAR_0x8008, ITEM_CLEAR_AMULET
	bufferitemname STR_VAR_1, VAR_0x8008
	goto FortreeCity_House7_EventScript_TryGiveItemAgain
	end

FortreeCity_House7_EventScript_GiveAuspiciousArmor::
	setvar VAR_0x8008, ITEM_AUSPICIOUS_ARMOR
	bufferitemname STR_VAR_1, VAR_0x8008
	goto FortreeCity_House7_EventScript_TryGiveItemAgain
	end

FortreeCity_House7_EventScript_GiveMaliciousArmor::
	setvar VAR_0x8008, ITEM_MALICIOUS_ARMOR
	bufferitemname STR_VAR_1, VAR_0x8008
	goto FortreeCity_House7_EventScript_TryGiveItemAgain
	end

FortreeCity_House7_EventScript_GiveRustedShield::
	setvar VAR_0x8008, ITEM_RUSTED_SHIELD
	bufferitemname STR_VAR_1, VAR_0x8008
	goto FortreeCity_House7_EventScript_TryGiveItemAgain
	end

FortreeCity_House7_EventScript_GiveRustedSword::
	setvar VAR_0x8008, ITEM_RUSTED_SWORD
	bufferitemname STR_VAR_1, VAR_0x8008
	goto FortreeCity_House7_EventScript_TryGiveItemAgain
	end

FortreeCity_House7_EventScript_TryGiveItemAgain::
	msgbox FortreeCity_House7_Text_ReadyToTakeYourItem, MSGBOX_DEFAULT
	call FortreeCity_House7_EventScript_GiveCraftedItem
	setvar VAR_RELIC_WORKSHOP_STATE, 2
	release
	end

FortreeCity_House7_EventScript_Exchange::
	specialvar VAR_RESULT, CheckRelicsForExchange
	goto_if_eq VAR_RESULT, FALSE, FortreeCity_House7_EventScript_NothingToExchange
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_House7_EventScript_ExchangeMultichoice
	end

FortreeCity_House7_EventScript_ExchangeMultichoice::
	msgbox FortreeCity_House7_Text_WhatToExchange, MSGBOX_DEFAULT
	special ScriptMenu_CreateRelicExchangeMultichoice
	waitstate
	goto FortreeCity_House7_EventScript_ExchangeInput
	end

FortreeCity_House7_EventScript_ExchangeInput::
	switch VAR_RESULT
	case 0, FortreeCity_House7_EventScript_DoExchange
	case 1, FortreeCity_House7_EventScript_DoExchange
	case 2, FortreeCity_House7_EventScript_DoExchange
	case 3, FortreeCity_House7_EventScript_DoExchange
	case 4, FortreeCity_House7_EventScript_DoExchange
	case 5, FortreeCity_House7_EventScript_DoExchange
	case MULTI_B_PRESSED, FortreeCity_House7_EventScript_CancelItemSelect
	end

FortreeCity_House7_EventScript_DoExchange::
	special DoRelicExchangeSelection
	bufferitemname STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x800A
	call_if_eq VAR_0x8009, ITEM_RELIC_SILVER, FortreeCity_House7_EventScript_BufferSilver
	call_if_ne VAR_0x8009, ITEM_RELIC_SILVER, FortreeCity_House7_EventScript_BufferGold
	msgbox FortreeCity_House7_Text_WouldYouLikeToExchange, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House7_EventScript_CancelItemSelect
	removeitem VAR_0x8008, VAR_0x8007
	additem VAR_0x8009, VAR_0x800A
	msgbox FortreeCity_House7_Text_ExchangeComplete, MSGBOX_DEFAULT
	specialvar VAR_RESULT, CheckRelicsForExchange
	goto_if_eq VAR_RESULT, FALSE, FortreeCity_House7_EventScript_NothingMoreToExchange
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_House7_EventScript_ExchangeMultichoice
	end

FortreeCity_House7_EventScript_NothingToExchange::
	msgbox FortreeCity_House7_Text_NothingToExchange
	release
	end

FortreeCity_House7_EventScript_NothingMoreToExchange::
	msgbox FortreeCity_House7_Text_NothingMoreToExchange
	release
	end

FortreeCity_House7_EventScript_BufferSilver::
	bufferstring STR_VAR_3, FortreeCity_House7_Text_Silver
	return

FortreeCity_House7_EventScript_BufferGold::
	bufferstring STR_VAR_3, FortreeCity_House7_Text_Gold
	return

FortreeCity_House7_Text_RelicTraderIntroduction:
	.string "Greetings. I am the Relic Craftsman.\p"
	.string "My family have carried the art of craft\n"
	.string "for centuries.\p"
	.string "I do not care for modern currency.\p"
	.string "I work for trade, and I trade only that\n"
	.string "which I know…\p"
	.string "Relics.$"

FortreeCity_House7_Text_CraftOrExchange:
	.string "Shall I craft something for you?\n"
	.string "Or do you wish to trade?$"

FortreeCity_House7_Text_ExplainRelicCrafting:
	.string "This art, passed down by my family\n"
	.string "for centuries, has been sharpened\l"
	.string "through the generations.\p"
	.string "In exchange for Relic materials, I\n"
	.string "will trade you currency.\p"
	.string "Bring me enough Relic Gold, and I\n"
	.string "will craft a masterpiece for you.\p"
	.string "So…$"

FortreeCity_House7_Text_HowMuchRelicGold:
	.string "Do you carry Relic Gold?$"

FortreeCity_House7_Text_NotEnoughGoldToMakeAnything:
	.string "Hmmm…\p"
	.string "Not enough gold.\p"
	.string "As my people once did, I work only for\n"
	.string "ancient gold.\p"
	.string "Come back with at least {STR_VAR_1} gold.$"

FortreeCity_House7_Text_WhichItemWoudYouLike:
	.string "You have {STR_VAR_2} Golden Relic Coins.\n"
	.string "What should I make?$"

FortreeCity_House7_Text_IsThatTheItemForYou:
	.string "You want a {STR_VAR_1}?$"

FortreeCity_House7_Text_IllCraftItemForYou:
	.string "A {STR_VAR_1} it is.\p"
	.string "I shall begin my work.$"

FortreeCity_House7_Text_NotEnoughGoldToMakeItem:
	.string "A {STR_VAR_1}?\p"
	.string "Hmph, you don't have enough Relic Gold.\p"
	.string "You'll need {STR_VAR_3} more gold\n"
	.string "if you want me to make that.\p"
	.string "Pick something else instead.\n"
	.string "You have {STR_VAR_2} Gold Relic Coins.$"

FortreeCity_House7_Text_FineSoBeIt:
	.string "Fine, so be it.$"

FortreeCity_House7_Text_WorkIsDone:
	.string "I have finished your {STR_VAR_1}.\n"
	.string "Take it.$"

FortreeCity_House7_Text_ReadyToTakeYourItem:
	.string "Are you ready to take your\n"
	.string "{STR_VAR_1}?$"

FortreeCity_House7_Text_NoRoomInBag:
	.string "You have no space in your bag.\p"
	.string "Toss something out so I can give\n"
	.string "this to you.$"

FortreeCity_House7_Text_WhatToExchange:
	.string "What would you like to give me\n"
	.string "in exchange for Relic coins?$"

FortreeCity_House7_Text_Silver:
	.string "Silver$"

FortreeCity_House7_Text_Gold:
	.string "Gold$"

FortreeCity_House7_Text_WouldYouLikeToExchange:
	.string "Would you like to exchange your\n"
	.string "{STR_VAR_1} for {STR_VAR_2} {STR_VAR_3}?$"

FortreeCity_House7_Text_ExchangeComplete:
	.string "{PLAYER} exchanged {STR_VAR_1}\n"
	.string "{STR_VAR_2} Relic {STR_VAR_3}$"

FortreeCity_House7_Text_NothingToExchange:
	.string "You have nothing I am interested in.\p"
	.string "I only exchange Relic Materials.$"

FortreeCity_House7_Text_NothingMoreToExchange:
	.string "You have nothing further to exchange.\p"
	.string "Please collect more Relic Materials.$"
