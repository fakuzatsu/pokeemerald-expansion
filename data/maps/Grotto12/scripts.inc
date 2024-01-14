Grotto12_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto12_OnLoad
	.byte 0

Grotto12_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout2_CloseEntranceLeftPath
	call Grotto_Layout2_CloseLeftPathToTop
	call Grotto_Layout2_CloseRightPathToTop
	call Grotto_Layout2_SetLeftEventStage
	end

Grotto12_EventScript_Falinks::
	lock
	faceplayer
	message Grotto12_Text_FalinksCry
	playmoncry SPECIES_FALINKS, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	setwildbattle SPECIES_FALINKS, 22
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_EVENT_GROTTO_12_FALINKS
	release
	end

Grotto12_Text_FalinksCry:
	.string "Fa-fa-faliii$"
