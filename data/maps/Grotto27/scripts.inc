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
	lock
	faceplayer
	message Grotto27_Text_BisharpCry
	playmoncry SPECIES_BISHARP, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	setwildbattle SPECIES_BISHARP, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_EVENT_GROTTO_27_BISHARP
	release
	end

Grotto27_Text_BisharpCry:
	.string "Biiishaaa$"
