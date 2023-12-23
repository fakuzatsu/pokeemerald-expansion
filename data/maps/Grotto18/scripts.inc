Grotto18_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto18_OnLoad
	.byte 0

Grotto18_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	end

Grotto18_EventScript_HexLady::
	lock
	faceplayer
	release
	end
