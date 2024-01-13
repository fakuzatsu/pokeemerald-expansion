Grotto11_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto11_OnLoad
	.byte 0

Grotto11_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout1_CloseRightTreeArea
	call Grotto_Layout1_CloseLeftTreeArea
	end
