AcornHouse_MapScripts:: 
	.byte 0

AcornHouse_EventScript_BonzaiMaster::
	lock
	faceplayer
	goto_if_set FLAG_ACORNHOUSE_NPC_TRADE_COMPLETED, AcornHouse_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_BELLSPROUT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox AcornHouse_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, AcornHouse_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, AcornHouse_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, AcornHouse_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox AcornHouse_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_ACORNHOUSE_NPC_TRADE_COMPLETED
	release
	end

AcornHouse_EventScript_DeclineTrade::
	msgbox AcornHouse_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

AcornHouse_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox AcornHouse_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

AcornHouse_EventScript_TradeCompleted::
	msgbox AcornHouse_Text_ThankYouForTheSeedot, MSGBOX_DEFAULT
	release
	end

AcornHouse_Text_YouWillTradeWontYou:
	.string "Welcome!\n"
	.string "People call me the BONZAI Master.\p"
	.string "I came here from far across the\n"
	.string "region to plant beautiful trees!\p"
	.string "Would you like to trade a SEEDOT\n"
	.string "for my BELLSPROUT?$"

AcornHouse_Text_MonYouTakeCare:
	.string "Fantastic!\p"
	.string "{STR_VAR_1}, welcome!\n"
	.string "{STR_VAR_2}, you take care!$"

AcornHouse_Text_ThisIsntAMon:
	.string "Oh. That isn't a {STR_VAR_1}.\n"
	.string "I need a {STR_VAR_1} to help me.$"

AcornHouse_Text_YouWontTradeMe:
	.string "No? Guess I'll have to put down\n"
	.string "my tools, and get my PokéBALLS.$"

AcornHouse_Text_ThankYouForTheSeedot:
	.string "That BELLSPROUT came with me\n"
	.string "all the way from my home\p"
	.string "It loves to adventure, so I\n"
	.string "think it's best off with you.$"

