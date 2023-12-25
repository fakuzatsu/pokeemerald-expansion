.set LOCALID_HEXLADY, 1

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

Grotto29_EventScript_HexLady::
	call_if_set FLAG_SYS_USE_FLASH, Grotto29_EventScript_HexLadyComplainAboutFlash
	call_if_set FLAG_SYS_USE_FLASH, Grotto29_EventScript_SetDarkness
	end

Grotto29_EventScript_HexLadyComplainAboutFlash::
	end