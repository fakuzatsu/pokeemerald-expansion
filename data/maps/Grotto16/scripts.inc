Grotto16_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto16_OnLoad
	.byte 0

Grotto16_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout2_ClosePathThroughMiddle
	call Grotto_Layout2_SetMiddleEventStage
	end
