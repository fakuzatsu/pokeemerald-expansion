DewfordTown_HolidayHome_MapScripts::
	.byte 0

DewfordTown_HolidayHome_EventScript_Kahili::
	lock
	goto_if_gt VAR_0x8005, 100, DewfordTown_HolidayHome_EventScript_GiveTemporaryStoredItem
	goto_if_set FLAG_SYS_GAME_CLEAR, DewfordTown_HolidayHome_EventScript_KahiliPostGame
	checkitem ITEM_TM51
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_HolidayHome_EventScript_KahiliAfterBattle
	msgbox DewfordTown_HolidayHome_Text_KahiliIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordTown_HolidayHome_EventScript_RefuseKahili
	trainerbattle_no_intro TRAINER_KAHILI, DewfordTown_HolidayHome_Text_KahiliDefeat
DewfordTown_HolidayHome_EventScript_GiveRoost::
	msgbox DewfordTown_HolidayHome_Text_KahiliPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_TM51
	msgbox DewfordTown_HolidayHome_Text_ThatTMContainsRoost, MSGBOX_DEFAULT
	release
	end

DewfordTown_HolidayHome_EventScript_KahiliAfterBattle::
	msgbox DewfordTown_HolidayHome_Text_KahiliAfterBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_HolidayHome_EventScript_RefuseKahili::
	msgbox DewfordTown_HolidayHome_Text_RefuseKahili, MSGBOX_DEFAULT
	release
	end

DewfordTown_HolidayHome_EventScript_KahiliPostGame::
	goto_if_set FLAG_KAHILI_POSTGAME_BATTLE, DewfordTown_HolidayHome_EventScript_KahiliAfterBattle
	msgbox DewfordTown_HolidayHome_Text_KahiliPostGame, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordTown_HolidayHome_EventScript_RefuseKahiliPostGame
	trainerbattle_no_intro TRAINER_KAHILI_POSTGAME, DewfordTown_HolidayHome_Text_KahiliPostGameDefeat
	setflag FLAG_KAHILI_POSTGAME_BATTLE
	checkitem ITEM_TM51
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_HolidayHome_EventScript_GiveRoost
	msgbox DewfordTown_HolidayHome_Text_KahiliPostBattle, MSGBOX_DEFAULT
	checkitem ITEM_FLYINIUM_Z
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_HolidayHome_EventScript_GiveFlyiniumZ
DewfordTown_HolidayHome_EventScript_GivePrettyFeather::
	giveitem ITEM_PRETTY_FEATHER
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_HolidayHome_EventScript_BagFullStorePrettyFeatherTemp
	msgbox DewfordTown_HolidayHome_Text_KahiliAfterBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_HolidayHome_EventScript_BagFullStorePrettyFeatherTemp::
	msgbox DewfordTown_HolidayHome_Text_OhYourBagIsFull, MSGBOX_DEFAULT
	setvar VAR_0x8005, ITEM_PRETTY_FEATHER
	release
	end

DewfordTown_HolidayHome_EventScript_RefuseKahiliPostGame::
	msgbox DewfordTown_HolidayHome_Text_RefuseKahiliPostGame, MSGBOX_DEFAULT
	release
	end

DewfordTown_HolidayHome_EventScript_GiveFlyiniumZ::
	giveitem ITEM_FLYINIUM_Z
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_HolidayHome_EventScript_BagFullStoreFlyiniumZTemp
	msgbox DewfordTown_HolidayHome_Text_ThatsFlyiniumZ, MSGBOX_DEFAULT
	release
	end

DewfordTown_HolidayHome_EventScript_BagFullStoreFlyiniumZTemp::
	msgbox DewfordTown_HolidayHome_Text_OhYourBagIsFull, MSGBOX_DEFAULT
	setvar VAR_0x8005, ITEM_FLYINIUM_Z
	release
	end

DewfordTown_HolidayHome_EventScript_GiveTemporaryStoredItem::
	msgbox DewfordTown_HolidayHome_Text_HereTakeThis, MSGBOX_DEFAULT
	goto_if_eq VAR_0x8005, ITEM_PRETTY_FEATHER, DewfordTown_HolidayHome_EventScript_GivePrettyFeather
	goto_if_eq VAR_0x8005, ITEM_FLYINIUM_Z, DewfordTown_HolidayHome_EventScript_GiveFlyiniumZ
	end

DewfordTown_HolidayHome_EventScript_Butler::
	lock
	faceplayer
	msgbox DewfordTown_HolidayHome_Text_HereToAssit, MSGBOX_DEFAULT
	release
	end

DewfordTown_HolidayHome_Text_KahiliIntro:
	.string "Alola! Alola!\p"
	.string "My name is Kahili.\p"
	.string "I'm travelling the world improving\n"
	.string "skills as a Trainer and golfer.\p"
	.string "Although, Dewford feels a lot like\n"
	.string "my home region.\p"
	.string "I'm in my element!\p"
	.string "How about a Pokémon Battle?$"

DewfordTown_HolidayHome_Text_RefuseKahili:
	.string "No? That's a shame.\p"
	.string "I can sense that you have top rank\n"
	.string "potential in you.\p"
	.string "Keep training and maybe we can\n"
	.string "battle sometime.$"

DewfordTown_HolidayHome_Text_KahiliDefeat:
	.string "The frustration of losing…\p"
	.string "I'll use it to propel my growth.$"

DewfordTown_HolidayHome_Text_KahiliPostBattle:
	.string "I may have lost, but that battle\n"
	.string "was a breath of fresh air.\p"
	.string "Please take this as thanks for\n"
	.string "helping me train.$"

DewfordTown_HolidayHome_Text_ThatTMContainsRoost:
	.string "That TM contains the move Roost.\p"
	.string "It's a strong move for Flying type\n"
	.string "Pokémon that recovers damage taken.$"

DewfordTown_HolidayHome_Text_KahiliAfterBattle:
	.string "Your strength is the real deal.\p"
	.string "But next time, I'll win.\n"
	.string "You'll see!$"

DewfordTown_HolidayHome_Text_KahiliPostGame:
	.string "You came to battle again?\p"
	.string "I was just looking for some\n"
	.string "training.\p"
	.string "If I beat you, I'll be the number\n"
	.string "one ranked Trainer in Hoenn!\p"
	.string "Want to get started?$"

DewfordTown_HolidayHome_Text_RefuseKahiliPostGame:
	.string "No? That's a shame.\p"
	.string "Come back soon, so we can see\n"
	.string "who the winds favor in battle.$"

DewfordTown_HolidayHome_Text_KahiliPostGameDefeat:
	.string "A battle worth of a champion!$"

DewfordTown_HolidayHome_Text_ThatsFlyiniumZ:
	.string "The glistening Flyinium Z…\n"
	.string "It's yours now.\p"
	.string "Supersonic Skystrike is a\n"
	.string "devastating blow from the sky!\p"
	.string "Use it well.$"

DewfordTown_HolidayHome_Text_HereToAssit:
	.string "I work for the Hano Estate.\p"
	.string "I am here to assist Kahili\n"
	.string "In any matters that suit her.$"

DewfordTown_HolidayHome_Text_OhYourBagIsFull:
	.string "Oh. Your bag is full.\p"
	.string "I'll hold onto this while you\n"
	.string "make some space.$"

DewfordTown_HolidayHome_Text_HereTakeThis:
	.string "Please take this as thanks for\n"
	.string "helping me train.$"
