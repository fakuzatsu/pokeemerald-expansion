Grotto7_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto7_OnLoad
	.byte 0

Grotto7_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout1_CloseBerryTreeArea
	call Grotto_Layout1_CloseLeftTreeArea
	call Grotto_Layout1_SetEventStage
	end

Grotto7_EventScript_Pawniard::
	lock
	faceplayer
	message Grotto7_Text_PawniardCry
	playmoncry SPECIES_PAWNIARD, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	setwildbattle SPECIES_PAWNIARD, 15
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_EVENT_GROTTO_7_PAWNIARD
	release
	end

Grotto7_Text_PawniardCry:
	.string "Paaawwiii$"
