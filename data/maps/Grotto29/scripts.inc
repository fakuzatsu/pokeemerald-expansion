.set LOCALID_HEXLADY, 1
.set LOCALID_HEXLADY_1, 2
.set LOCALID_HEXLADY_2, 3
.set LOCALID_HEXLADY_3, 4
.set LOCALID_HEXLADY_4, 5

Grotto29_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto29_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Grotto29_OnTransition
	.byte 0

Grotto29_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout2_SetLeftEventStage
	call Grotto_Layout2_CloseEntranceLeftPath
	call Grotto_Layout2_CloseRightPathToTop
	end

Grotto29_OnTransition::
	call Grotto29_EventScript_SetupHideAndSeek
	call_if_unset FLAG_EVENT_GROTTO_29_HEX_LADY, Grotto29_EventScript_SetDarkness
	call_if_set FLAG_EVENT_GROTTO_29_HEX_LADY, Grotto29_EventScript_SetLessDark
	end

Grotto29_EventScript_SetupHideAndSeek::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	return

Grotto29_EventScript_SetDarkness::
	clearflag FLAG_SYS_USE_FLASH
	setflashlevel 7
	return

Grotto29_EventScript_SetLessDark::
	setflag FLAG_SYS_USE_FLASH
	setflashlevel 1
	return

Grotto29_EventScript_HexLady::
	lock
	faceplayer
	goto_if_set FLAG_EVENT_GROTTO_29_HEX_LADY, Grotto29_EventScript_HexLadyLetsPlayAgainSometime
	goto_if_set FLAG_TEMP_6, Grotto29_EventScript_HexLadyGotoReward
	goto_if_set FLAG_SYS_USE_FLASH, Grotto29_EventScript_HexLadyComplainAboutFlash
	msgbox Grotto29_Text_HexLadyIntroduction, MSGBOX_DEFAULT
	msgbox Grotto29_Text_HowAboutAGame, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Grotto29_EventScript_HexLadyStartHideAndSeek
	goto Grotto29_EventScript_TurnDownHexLady
	end

Grotto29_EventScript_HexLadyLetsPlayAgainSometime::
	msgbox Grotto29_Text_NotTooBad, MSGBOX_DEFAULT
	release
	end

Grotto29_EventScript_HexLadyGotoReward::
	goto_if_set FLAG_TEMP_7, Grotto29_EventScript_HexLadyReluctantReward
	msgbox Grotto29_Text_NotTooBad, MSGBOX_DEFAULT
	msgbox Grotto29_Text_TakeThis, MSGBOX_DEFAULT
	giveitem ITEM_RELIC_CROWN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_EVENT_GROTTO_29_HEX_LADY
	release
	end

Grotto29_EventScript_HexLadyReluctantReward::
	msgbox Grotto29_Text_ThatLightWasUnfair, MSGBOX_DEFAULT
	msgbox Grotto29_Text_TakeThis, MSGBOX_DEFAULT
	giveitem ITEM_RELIC_CROWN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_EVENT_GROTTO_29_HEX_LADY
	release
	end

Grotto29_EventScript_HexLadyComplainAboutFlash::
	msgbox Grotto29_Text_WhatsWithTheLight, MSGBOX_DEFAULT
	msgbox Grotto29_Text_HowAboutAGame, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Grotto29_EventScript_HexLadyStartHideAndSeek
	goto Grotto29_EventScript_TurnDownHexLady
	end

Grotto29_EventScript_TurnDownHexLady::
	msgbox Grotto29_Text_SuitYourself, MSGBOX_DEFAULT
	release
	end

Grotto29_EventScript_HexLadyStartHideAndSeek::
	msgbox Grotto29_Text_TeeHee, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_TEMP_5
	removeobject LOCALID_HEXLADY
	call_if_set FLAG_SYS_USE_FLASH, Grotto29_EventScript_SetDarkness
	clearflag FLAG_TEMP_1
	fadescreen FADE_FROM_BLACK
	release
	end

Grotto29_EventScript_HexLadyFirstFind::
	lock
	faceplayer
	goto_if_set FLAG_SYS_USE_FLASH, Grotto29_EventScript_HexLadyWhyIsItLight
	msgbox Grotto29_Text_CatchMeIfYouCan, MSGBOX_DEFAULT
Grotto29_EventScript_ReturnToFirstFind::
	fadescreen FADE_TO_BLACK
	setflag FLAG_TEMP_1
	removeobject LOCALID_HEXLADY_1
	call_if_set FLAG_SYS_USE_FLASH, Grotto29_EventScript_SetDarkness
	clearflag FLAG_TEMP_2
	fadescreen FADE_FROM_BLACK
	release
	end

Grotto29_EventScript_HexLadyWhyIsItLight::
	msgbox Grotto29_Text_WhyIsItLight, MSGBOX_DEFAULT
	goto Grotto29_EventScript_ReturnToFirstFind
	end

Grotto29_EventScript_HexLadySecondFind::
	lock
	faceplayer
	msgbox Grotto29_Text_DoItAgain, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_TEMP_2
	removeobject LOCALID_HEXLADY_2
	call_if_set FLAG_SYS_USE_FLASH, Grotto29_EventScript_SetDarkness
	clearflag FLAG_TEMP_3
	fadescreen FADE_FROM_BLACK
	release
	end

Grotto29_EventScript_HexLadyThirdFind::
	lock
	faceplayer
	msgbox Grotto29_Text_HexLadyIntroduction, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_TEMP_3
	removeobject LOCALID_HEXLADY_3
	call_if_set FLAG_SYS_USE_FLASH, Grotto29_EventScript_SetDarkness
	clearflag FLAG_TEMP_4
	fadescreen FADE_FROM_BLACK
	release
	end

Grotto29_EventScript_HexLadyFourthFind::
	lock
	faceplayer
	call_if_set FLAG_SYS_USE_FLASH, Grotto29_EventScript_HexLadyCheatingArentYou
	msgbox Grotto29_Text_FindMeBackWhereWeStarted, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_TEMP_4
	removeobject LOCALID_HEXLADY_4
	setflag FLAG_TEMP_6
	call Grotto29_EventScript_SetLessDark
	clearflag FLAG_TEMP_5
	fadescreen FADE_FROM_BLACK
	release
	end

Grotto29_EventScript_HexLadyCheatingArentYou::
	setflag FLAG_TEMP_7
	msgbox Grotto29_Text_CheatingArentYou, MSGBOX_DEFAULT
	return

Grotto29_Text_HexLadyIntroduction:
	.string "Boo!\p"
	.string "Did I scare you?$"

Grotto29_Text_WhatsWithTheLight:
	.string "Hey what's with the lights?\p"
	.string "I was waiting to spook someone.\p"
	.string "… … …\p"
	.string "Hm, hey you.$"

Grotto29_Text_HowAboutAGame:
	.string "How about we play a game?\p"
	.string "If you can find me in the darkness\n"
	.string "I'll give you something special.\p"
	.string "How about it?$"

Grotto29_Text_SuitYourself:
	.string "Hmph!\p"
	.string "Suit yourself.$"

Grotto29_Text_TeeHee:
	.string "tee-hee.\p"
	.string "Let's see what you can do…$"

Grotto29_Text_CatchMeIfYouCan:
	.string "Catch me if you can!$"

Grotto29_Text_WhyIsItLight:
	.string "Hey what's the deal with that\n"
	.string "light?$"

Grotto29_Text_DoItAgain:
	.string "Try keep up!$"

Grotto29_Text_CheatingArentYou:
	.string "Hey that light is cheating!$"

Grotto29_Text_FindMeBackWhereWeStarted:
	.string "Meet me back where we started.$"

Grotto29_Text_NotTooBad:
	.string "tee-hee.\p"
	.string "That was pretty fun!\p"
	.string "We should play again sometime.$"

Grotto29_Text_TakeThis:
	.string "Here… take this.$"

Grotto29_Text_ThatLightWasUnfair:
	.string "That light was totally unfair!\p"
	.string "… … …\p"
	.string "But I guess it was still pretty\n"
	.string "fun to play…$"
