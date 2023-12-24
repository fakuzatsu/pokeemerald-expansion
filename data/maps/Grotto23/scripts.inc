Grotto23_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto23_OnLoad
	.byte 0

Grotto23_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout1_CloseBerryTreeArea
	end

Grotto23_EventScript_HexLady::
	end
