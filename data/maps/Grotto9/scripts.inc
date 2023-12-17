Grotto9_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto9_OnLoad
	.byte 0

Grotto9_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout2_CloseEntranceLeftPath
	call Grotto_Layout2_CloseLeftPathToTop
	call Grotto_Layout2_ClosePathThroughMiddle
	end
