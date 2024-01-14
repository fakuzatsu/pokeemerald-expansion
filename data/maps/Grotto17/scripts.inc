Grotto17_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto17_OnLoad
	.byte 0

Grotto17_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout3_CloseRightPath
	call Grotto_Layout3_OpenMiddlePath
	call Grotto_Layout3_SetEventStage
	end

Grotto17_EventScript_Honedge::
	lock
	faceplayer
	message Grotto17_Text_HonedgeCry
	playmoncry SPECIES_HONEDGE, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	setwildbattle SPECIES_HONEDGE, 32
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_EVENT_GROTTO_17_HONEDGE
	release
	end

Grotto17_Text_HonedgeCry:
	.string "Swiiishh$"
