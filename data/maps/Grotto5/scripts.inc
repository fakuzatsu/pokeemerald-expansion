Grotto5_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto5_OnLoad
	.byte 0

Grotto5_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout1_CloseBerryTreeArea
	call Grotto_Layout1_CloseRightTreeArea
	end
