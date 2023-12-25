Grotto29_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto29_OnLoad
	.byte 0

Grotto29_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	end
