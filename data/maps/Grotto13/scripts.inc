Grotto13_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto13_OnLoad
	.byte 0

Grotto13_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout4_CloseRightTreeArea
	end
