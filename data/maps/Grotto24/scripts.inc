Grotto24_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto24_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Grotto24_OnTransition
	.byte 0

Grotto24_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout2_SetLeftEventStage
	call Grotto_Layout2_SetMiddleEventStage
	end

Grotto24_OnTransition:
	goto_if_set FLAG_EVENT_GROTTO_24_TREASURE_TROVE, Grotto24_EventScript_HideAllTreasure
	setflag FLAG_EVENT_GROTTO_24_TREASURE_TROVE
	end

Grotto24_EventScript_HideAllTreasure::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	end
