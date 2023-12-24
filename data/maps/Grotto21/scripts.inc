.set LOCALID_HEXLADY1, 2
.set LOCALID_HEXLADY2, 3

Grotto21_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto21_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Grotto21_OnTransition
	.byte 0

Grotto21_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout2_CloseEntranceLeftPath
	call Grotto_Layout2_ClosePathThroughMiddle
	call Grotto_Layout2_SetLeftEventStage
	end

Grotto21_OnTransition::
	call Grotto21_EventScript_HideHexLady
	goto_if_unset FLAG_ITEM_GROTTO_21_RELIC_CROWN, Grotto21_EventScript_SetupTriggers
	end

Grotto21_EventScript_HideHexLady::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return

Grotto21_EventScript_SetupTriggers::
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	end
