Grotto1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto1_OnLoad
	.byte 0

Grotto1_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout1_CloseBerryTreeArea
	call Grotto_Layout1_CloseLeftTreeArea
	call Grotto_Layout1_CloseRightTreeArea
	end
