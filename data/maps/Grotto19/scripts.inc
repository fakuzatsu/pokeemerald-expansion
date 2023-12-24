Grotto19_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto19_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Grotto19_EnableCoins
	.byte 0

Grotto19_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout1_SetEventStage
	call Grotto_Layout1_CloseRightTreeArea
	end

Grotto19_EnableCoins::
	setvar VAR_TEMP_9, 3
	end
