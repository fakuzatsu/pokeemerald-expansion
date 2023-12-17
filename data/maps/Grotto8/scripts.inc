Grotto8_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto8_OnLoad
	.byte 0

Grotto8_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout4_CloseLeftTreeArea
	end
