Grotto7_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto7_OnLoad
	.byte 0

Grotto7_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout1_CloseBerryTreeArea
	call Grotto_Layout1_CloseLeftTreeArea
	call Grotto_Layout1_SetEventStage
	end

Grotto7_EventScript_Pawniard::
	faceplayer
	end
