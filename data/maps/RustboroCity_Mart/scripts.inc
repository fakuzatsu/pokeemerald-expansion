RustboroCity_Mart_MapScripts::
	.byte 0

RustboroCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

RustboroCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart RustboroCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_Basic:
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_NONE
	release
	end

RustboroCity_Mart_EventScript_PokefanF::
	msgbox RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_Boy::
 	goto_if_set FLAG_RECEIVED_TM_WATER_PULSE, RustboroCity_Mart_EventScript_ReceivedTM54
	msgbox RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead, MSGBOX_NPC
	giveitem ITEM_TM54
	end

RustboroCity_Mart_EventScript_ReceivedTM54::
	msgbox RustboroCity_Mart_Text_TM54, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_BugCatcher::
	msgbox RustboroCity_Mart_Text_GettingEscapeRopeJustInCase, MSGBOX_NPC
	end

RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish:
	.string "I'm buying some Parlyz Heals and\n"
	.string "Antidotes.\p"
	.string "Just in case I run into Shroomish\n"
	.string "in Petalburg Woods.$"

RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead:
	.string "Excuse me, trainer over there.\n"
	.string "Do you have a minute?\p"
	.string "You know moves are sometimes too\n"
	.string "strong to catch a Pokemon.\p"
	.string "You end up making a Pokemon faint\n"
	.string "even when you don't want to.\p"
	.string "For such a common problem, use this!$"

RustboroCity_Mart_Text_TM54: @ 8214FF1
	.string "False Swipe is a very handy move.\p"
	.string "No matter how many times it's used\n"
	.string "on the opposing Pokemon, it won't\l"
	.string "cause the Pokemon to faint!$"

RustboroCity_Mart_Text_GettingEscapeRopeJustInCase:
	.string "I'm getting an Escape Rope just in\n"
	.string "case I get lost in a cave.\p"
	.string "I just need to use it to get back to\n"
	.string "the entrance.$"

