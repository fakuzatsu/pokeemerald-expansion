Grotto7_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto7_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, Grotto7_OnResume
	.byte 0

Grotto7_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Grotto7_EventScript_TryRemovePawniard
	end

Grotto7_EventScript_TryRemovePawniard::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

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
	goto Common_EventScript_RemoveStaticPokemon
	end

Grotto7_Text_PawniardCry:
	.string "Paaawwiii$"
