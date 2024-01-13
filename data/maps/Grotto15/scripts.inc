Grotto15_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto15_OnLoad
	.byte 0

Grotto15_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout1_CloseBerryTreeArea
	call Grotto_Layout1_SetEventStage
	end
