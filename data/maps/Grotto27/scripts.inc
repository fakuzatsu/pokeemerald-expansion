Grotto27_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto27_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, Grotto27_OnResume
	.byte 0

Grotto27_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Grotto27_EventScript_TryRemoveBisharp
	end

Grotto27_EventScript_TryRemoveBisharp::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

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
	goto Common_EventScript_RemoveStaticPokemon
	end

Grotto27_Text_BisharpCry:
	.string "Biiishaaa$"
