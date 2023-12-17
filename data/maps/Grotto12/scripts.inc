Grotto12_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto12_OnLoad
	.byte 0

Grotto12_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout2_CloseEntranceLeftPath
	call Grotto_Layout2_CloseLeftPathToTop
	call Grotto_Layout2_CloseRightPathToTop
	call Grotto_Layout2_SetLeftEventStage
	end

Grotto12_EventScript_Falinks::
	faceplayer
	end
