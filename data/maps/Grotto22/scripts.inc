Grotto22_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto22_OnLoad
	.byte 0

Grotto22_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	end

Grotto22_EventScript_Stonjourner::
	lock
	faceplayer
	message Grotto22_Text_StonjournerCry
	playmoncry SPECIES_STONJOURNER, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	setwildbattle SPECIES_STONJOURNER, 42
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_EVENT_GROTTO_22_STONJOURNER
	release
	end

Grotto22_Text_StonjournerCry:
	.string "Jooouuuurrr$"
