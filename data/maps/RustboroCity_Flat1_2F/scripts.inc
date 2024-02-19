.set LOCALID_WALDA, 2
.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

	@ State descriptions for VAR_WALDA_QUEST_STATE
	@ 1: Spoke to Walda's Dad at Night. Began quest
	@ 2: Slept in bed and defeated Darkrai
	@ 3: Visited NewMoon Island for the first time
	@ 4: Spoke to Cresselia and got the Lunar Feather
	@ 5: Cured Walda but didnt have room for reward
	@ 6: Cured Walda and claimed the reward

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	goto_if_eq VAR_WALDA_QUEST_STATE, 6, RustboroCity_Flat1_2F_EventScript_WaldaIsBetter
	goto_if_eq VAR_WALDA_QUEST_STATE, 5, RustboroCity_Flat1_2F_EventScript_GiveReward
	goto_if_eq VAR_WALDA_QUEST_STATE, 4, RustboroCity_Flat1_2F_EventScript_UseLunarWing
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

RustboroCity_Flat1_2F_EventScript_UseLunarWing::
	faceplayer
	msgbox RustboroCity_Flat1_2F_Text_WhatsThatFeather, MSGBOX_DEFAULT
	closemessage
	delay 20
	call_if_eq VAR_FACING, DIR_SOUTH, RustboroCity_Flat1_2F_EventScript_DoSparkleUp
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_Flat1_2F_EventScript_DoSparkleLeft
	delay 20
	playse SE_ORB
	delay 60
	applymovement LOCALID_WALDAS_DAD, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 160
	special FadeOutOrbEffect
	msgbox RustboroCity_Flat1_2F_Text_WhyShesFallenAsleep, MSGBOX_DEFAULT
	setvar VAR_WALDA_QUEST_STATE, 5
RustboroCity_Flat1_2F_EventScript_GiveReward::
	faceplayer
	msgbox RustboroCity_Flat1_2F_Text_IDontKnowHowToThankYou, MSGBOX_DEFAULT
	giveitem ITEM_CLEAR_AMULET
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_StoreClearAmulet
	applymovement LOCALID_WALDAS_DAD, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_WALDA_QUEST_STATE, 6
RustboroCity_Flat1_2F_EventScript_WaldaIsBetter::
	msgbox RustboroCity_Flat1_2F_Text_MyLittleGirlIsBack, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_DoSparkleUp::
	playse SE_M_DETECT
	dofieldeffectsparkle 8, 4, 0
	waitfieldeffect FLDEFF_SPARKLE
	return

RustboroCity_Flat1_2F_EventScript_DoSparkleLeft::
	playse SE_M_DETECT
	dofieldeffectsparkle 7, 5, 0
	waitfieldeffect FLDEFF_SPARKLE
	return

RustboroCity_Flat1_2F_EventScript_StoreClearAmulet::
	msgbox RustboroCity_Flat1_2F_Text_OhNoSpace, MSGBOX_DEFAULT
	release
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

RustboroCity_Flat1_2F_Text_WhatsThatFeather:
	.string "Huh?\p"
	.string "What's this feather?\p"
	.string "You're saying it'll help my\n"
	.string "little girl?\p"
	.string "Please go right ahead!$"

RustboroCity_Flat1_2F_Text_WhyShesFallenAsleep:
	.string "Why… she's fallen into a restful\n"
	.string "slumber!\p"
	.string "It really worked!$"

RustboroCity_Flat1_2F_Text_IDontKnowHowToThankYou:
	.string "Oh I could just jump for joy!\p"
	.string "Nothing could ever make up for this…\p"
	.string "but please, take this as my thanks.$"

RustboroCity_Flat1_2F_Text_MyLittleGirlIsBack:
	.string "Look at that smile on her face.\p"
	.string "…My little girl is back.$"

RustboroCity_Flat1_2F_Text_OhNoSpace:
	.string "Oh… you don't have any space.\p"
	.string "I'll hold onto this for you.\p" 
	.string "Please visit us again soon.$"

