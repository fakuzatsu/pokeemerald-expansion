.set LOCALID_HEXLADY1, 2
.set LOCALID_HEXLADY2, 3

Grotto21_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto21_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Grotto21_OnTransition
	.byte 0

Grotto21_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout2_CloseEntranceLeftPath
	call Grotto_Layout2_ClosePathThroughMiddle
	call Grotto_Layout2_SetLeftEventStage
	end

Grotto21_OnTransition:
	call Grotto21_EventScript_HideHexLady
	goto_if_unset FLAG_ITEM_GROTTO_21_RELIC_CROWN, Grotto21_EventScript_SetupTriggers
	end

Grotto21_EventScript_HideHexLady::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return

Grotto21_EventScript_SetupTriggers::	
	cleartrainerflag TRAINER_GROTTO_HEX_LADY
	cleartrainerflag TRAINER_GROTTO_HEX_LADY2
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	end

Grotto21_EventScript_TriggerOne::
	lock
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, 0
	clearflag FLAG_TEMP_1
	delay 4
	msgbox Grotto21_Text_Boo, MSGBOX_DEFAULT
	addobject LOCALID_HEXLADY1
	fadescreen FADE_FROM_BLACK
	delay 4
	msgbox Grotto21_Text_WellDidIScareYou, MSGBOX_DEFAULT
	goto Grotto21_EventScript_HexLadyOneBattleOffer
	end

Grotto21_EventScript_HexLadyOne::
	lock
	faceplayer
	msgbox Grotto21_Text_RecoveredYet, MSGBOX_DEFAULT
	goto Grotto21_EventScript_HexLadyOneBattleOffer

Grotto21_EventScript_HexLadyOneBattleOffer::
	msgbox Grotto21_Text_HowAboutABattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Grotto21_EventScript_DenyBattle
	trainerbattle_no_intro TRAINER_GROTTO_HEX_LADY, Grotto21_Text_HexLadyDefeat
	goto Grotto21_EventScript_AfterBattle
	end

Grotto21_EventScript_TriggerTwo::
	lock
	fadescreen FADE_TO_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	setvar VAR_TEMP_2, 0
	clearflag FLAG_TEMP_2
	delay 4
	msgbox Grotto21_Text_Boo, MSGBOX_DEFAULT
	addobject LOCALID_HEXLADY2
	fadescreen FADE_FROM_BLACK
	delay 4
	msgbox Grotto21_Text_GetYouAgainHuh, MSGBOX_DEFAULT
	goto Grotto21_EventScript_HexLadyTwoBattleOffer
	end

Grotto21_EventScript_HexLadyTwo::
	lock
	faceplayer
	msgbox Grotto21_Text_RecoveredYet, MSGBOX_DEFAULT
	goto Grotto21_EventScript_HexLadyTwoBattleOffer

Grotto21_EventScript_HexLadyTwoBattleOffer::
	msgbox Grotto21_Text_HowAboutABattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Grotto21_EventScript_DenyBattle
	trainerbattle_no_intro TRAINER_GROTTO_HEX_LADY2, Grotto21_Text_HexLadyTwoDefeat
	goto Grotto21_EventScript_AfterBattle
	end

Grotto21_EventScript_DenyBattle::
	msgbox Grotto21_Text_SuitYourself, MSGBOX_DEFAULT
	release
	end

Grotto21_EventScript_AfterBattle::
	msgbox Grotto21_Text_WellADealIsADeal, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_2, 0, Grotto21_EventScript_EnjoyYourReward
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_HEXLADY1
	removeobject LOCALID_HEXLADY2
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	fadescreen FADE_FROM_BLACK
	release
	end

Grotto21_EventScript_EnjoyYourReward::
	msgbox Grotto21_Text_EnjoyYourReward, MSGBOX_DEFAULT
	return

Grotto21_Text_Boo:
	.string "Boo!$"

Grotto21_Text_WellDidIScareYou:
	.string "tee-hee.\p"
	.string "Did I scare you?$"

Grotto21_Text_HowAboutABattle:
	.string "If you want to pass through\n"
	.string "you'll have to battle me.\l"
	.string "How about it?$"

Grotto21_Text_RecoveredYet:
	.string "Recovered from that scare yet?$"

Grotto21_Text_GetYouAgainHuh:
	.string "Heh. Did I get you again?$"

Grotto21_Text_SuitYourself:
	.string "Hmph.\p"
	.string "Suit yourself.$"

Grotto21_Text_HexLadyDefeat:
	.string "Huh? No fair!$"

Grotto21_Text_HexLadyTwoDefeat:
	.string "You must be cheating!$"

Grotto21_Text_WellADealIsADeal:
	.string "Well… a deal is a deal, I\n"
	.string "suppose.$"

Grotto21_Text_EnjoyYourReward:
	.string "Enjoy your reward.\n"
	.string "tee-hee.$"
