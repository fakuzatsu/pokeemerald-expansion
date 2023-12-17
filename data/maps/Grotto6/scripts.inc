Grotto6_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto6_OnLoad
	.byte 0

Grotto6_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	end
