Grotto27_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto27_OnLoad
	.byte 0

Grotto27_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout1_CloseBerryTreeArea
	call Grotto_Layout1_CloseLeftTreeArea
	call Grotto_Layout1_SetEventStage
	end

Grotto27_EventScript_Bisharp::
	end
