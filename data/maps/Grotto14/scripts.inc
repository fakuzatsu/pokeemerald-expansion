Grotto14_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto14_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Grotto14_DoRemoveCoins
	.byte 0

Grotto14_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	end

Grotto14_DoRemoveCoins::
	goto_if_set FLAG_EVENT_GROTTO_14_COINS, Grotto14_EventScript_RemoveCoins
	end

Grotto14_EventScript_RemoveCoins::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	end

Grotto14_EventScript_TriggerCoinEvent::
	goto_if_set FLAG_EVENT_GROTTO_14_COINS, Grotto14_EventScript_StopScript
	setflag FLAG_EVENT_GROTTO_14_COINS
	setflag FLAG_TEMP_7
	random 2
	goto_if_eq VAR_RESULT, 1, Grotto14_EventScript_HideHalfCoins
	goto Grotto14_EventScript_HideOtherHalfCoins
	end

Grotto14_EventScript_StopScript::
	end

Grotto14_EventScript_HideHalfCoins::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	end

Grotto14_EventScript_HideOtherHalfCoins::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_6
	end

Grotto15_EventScipt_TalkHexLady::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_7, Grotto15_EventScipt_TalkHexLadyFirstTime
	msgbox Grotto15_Text_DidYouFindThemAll, MSGBOX_DEFAULT
	release
	end

Grotto15_EventScipt_TalkHexLadyFirstTime::
	clearflag FLAG_TEMP_7
	msgbox Grotto15_Text_CoinsScatteredAround, MSGBOX_DEFAULT
	release
	end

Grotto15_Text_DidYouFindThemAll:
	.string "So?\p"
	.string "Did you find all the treasures\n"
	.string "I scattered for you?\p"
	.string "tee-hee.$"

Grotto15_Text_CoinsScatteredAround:
	.string "tee-hee.\p"
	.string "Can't you sense them?\p"
	.string "Items of old scattered around\n"
	.string "this grove…$"
