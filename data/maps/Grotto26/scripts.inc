Grotto26_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto26_OnLoad
	.byte 0

Grotto26_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout3_CloseRightPath
	call Grotto_Layout3_OpenMiddlePath
	end
