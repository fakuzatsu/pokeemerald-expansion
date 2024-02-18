.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	goto_if_eq VAR_TEMP_1, 1, RustboroCity_Flat1_2F_EventScript_ThoseWords
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, RustboroCity_Flat1_2F_EventScript_MurmuringAgain
	msgbox RustboroCity_Flat1_2F_Text_MyPoorDaughter, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_MurmuringAgain::
	setvar VAR_WALDA_QUEST_STATE, 1
	setvar VAR_TEMP_1, 1
	msgbox RustboroCity_Flat1_2F_Text_MurmuringAgain, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_ThoseWords::
	msgbox RustboroCity_Flat1_2F_Text_ThoseWords, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, it's so hard every day…\p"
	.string "What's hard?\n"
	.string "You need to ask?\p"
	.string "It's trying to make a meal for my\n"
	.string "daughter that will help make her\l"
	.string "feel better…\p"
	.string "Nothing works…$"

RustboroCity_Flat1_2F_Text_MyPoorDaughter:
	.string "Oh my poor daughter…\p"
	.string "She barely gets a wink of sleep\n"
	.string "at night, so she's always tired.\p"
	.string "…We spoke with a doctor but they\n"
	.string "said that her nightmares must be\l"
	.string "the work of a Pokémon…$"

RustboroCity_Flat1_2F_Text_MurmuringAgain:
	.string "Oh my poor daughter…\p"
	.string "She's murmuring those words\n"
	.string "again tonight…\p"
	.string "Dark… Rai…$"

RustboroCity_Flat1_2F_Text_ThoseWords:
	.string "Those words…\p"
	.string "Dark… Rai…\p"
	.string "Nobody has a clue what they mean\n"
	.string "but they seem to exude darkness…$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "It's a Pokémon plush DOLL!$"

