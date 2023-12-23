Grotto17_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto17_OnLoad
	.byte 0

Grotto17_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout3_CloseRightPath
	call Grotto_Layout3_OpenMiddlePath
	call Grotto_Layout3_SetEventStage
	end

Grotto17_EventScript_Honedge::
	end
