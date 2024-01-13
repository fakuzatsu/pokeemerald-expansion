Grotto10_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto10_OnLoad
	.byte 0

Grotto10_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout3_CloseRightPath
	end
