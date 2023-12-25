Grotto28_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto28_OnLoad
	.byte 0

Grotto28_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout4_CloseLeftTreeArea
	end

Grotto28_EventScript_OldLady::
	faceplayer
	end
