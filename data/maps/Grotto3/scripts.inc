Grotto3_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto3_OnLoad
	.byte 0

Grotto3_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout3_CloseRightPath
	call Grotto_Layout3_OpenMiddlePath
	end
