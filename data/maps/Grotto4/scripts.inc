Grotto4_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto4_OnLoad
	.byte 0

Grotto4_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout4_CloseLeftTreeArea
	call Grotto_Layout4_CloseRightTreeArea
	end
