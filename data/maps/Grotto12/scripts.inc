Grotto12_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto12_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, Grotto12_OnResume
	.byte 0

Grotto12_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Grotto12_EventScript_TryRemoveFalinks
	end

Grotto12_EventScript_TryRemoveFalinks::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

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
	goto Common_EventScript_RemoveStaticPokemon
	end

Grotto12_Text_FalinksCry:
	.string "Fa-fa-faliii$"
