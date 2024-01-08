DewfordTown_HolidayHome_MapScripts::
	.byte 0

DewfordTown_HolidayHome_EventScript_Kahili::
	lock
	checkitem ITEM_TM51
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_HolidayHome_EventScript_KahiliAfterBattle
	msgbox DewfordTown_HolidayHome_Text_KahiliIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordTown_HolidayHome_EventScript_RefuseKahili
	trainerbattle_no_intro TRAINER_KAHILI, DewfordTown_HolidayHome_Text_KahiliDefeat
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
