Grotto22_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto22_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, Grotto22_OnResume
	.byte 0

Grotto22_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Grotto22_EventScript_TryRemoveStonjourner
	end

Grotto22_EventScript_TryRemoveStonjourner::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

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
	goto Common_EventScript_RemoveStaticPokemon
	end

Grotto22_Text_StonjournerCry:
	.string "Jooouuuurrr$"
