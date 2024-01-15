Grotto17_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto17_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, Grotto17_OnResume
	.byte 0

Grotto17_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Grotto17_EventScript_TryRemoveHonedge
	end

Grotto17_EventScript_TryRemoveHonedge::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

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
	goto Common_EventScript_RemoveStaticPokemon
	end

Grotto17_Text_HonedgeCry:
	.string "Swiiishh$"
