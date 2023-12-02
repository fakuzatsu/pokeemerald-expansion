ThunderCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThunderCave_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, ThunderCave_OnLoad
	.byte 0

ThunderCave_OnTransition:
	goto_if_set FLAG_CAUGHT_RAIKOU, ThunderCave_EventScript_DisableTrigger
	goto_if_set FLAG_DEFEATED_RAIKOU, ThunderCave_EventScript_DisableTrigger
	end

ThunderCave_OnLoad:
	call_if_set FLAG_HIDDEN_ITEM_SCEPTILITE, ThunderCave_Hide_Sceptilite
	end

ThunderCave_Hide_Sceptilite::
    setmetatile 7, 7, METATILE_Cave_RockFloor, FALSE
    return

ThunderCave_Sceptilite::
	goto_if_set FLAG_HIDDEN_ITEM_SCEPTILITE, ThunderCave_End_Sceptilite
	call ThunderCave_Hide_Sceptilite
	special DrawWholeMapView
	setflag FLAG_HIDDEN_ITEM_SCEPTILITE
	switch VAR_STARTER_MON
	case 0, ThunderCave_Give_RainbowWing
	case 1, ThunderCave_Give_Sceptilite
	case 2, ThunderCave_Give_Sceptilite
	end

ThunderCave_Give_RainbowWing::
	giveitem ITEM_RAINBOW_WING
	goto ThunderCave_End_Sceptilite
	end

ThunderCave_Give_Sceptilite::
	giveitem ITEM_SCEPTILITE
	goto ThunderCave_End_Sceptilite
	end

ThunderCave_End_Sceptilite::
	release
	end	

ThunderCave_EventScript_DisableTrigger::
	setvar VAR_TEMP_0, 2
	end

ThunderCave_EventScript_SomethingWatches::
	lockall
	goto_if_set FLAG_DEFEATED_RAIKOU, ThunderCave_EventScript_AfterRaikou
	msgbox ThunderCave_Text_SomethingWatches, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

ThunderCave_EventScript_Raikou::
	lockall
	goto_if_set FLAG_DEFEATED_RAIKOU, ThunderCave_EventScript_AfterRaikou
	waitse
	playmoncry SPECIES_RAIKOU, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 65
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ThunderCave_EventScript_DefeatedRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ThunderCave_EventScript_RanFromRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ThunderCave_EventScript_RanFromRaikou
	setflag FLAG_CAUGHT_RAIKOU
	setvar VAR_TEMP_0, 2
	goto ThunderCave_EventScript_AfterRaikou
	end

ThunderCave_EventScript_DefeatedRaikou::
	setflag FLAG_DEFEATED_RAIKOU
	bufferspeciesname STR_VAR_1, SPECIES_RAIKOU
	msgbox gText_LegendaryRanAway, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 2
	goto ThunderCave_EventScript_AfterRaikou
	end

ThunderCave_EventScript_RanFromRaikou::
	applymovement OBJ_EVENT_ID_PLAYER, ThunderCave_Movement_PlayerStumbleBack
	bufferspeciesname STR_VAR_1, SPECIES_RAIKOU
	msgbox ThunderCave_Text_PlayerStumbleBack, MSGBOX_DEFAULT
	goto ThunderCave_EventScript_AfterRaikou
	end

ThunderCave_EventScript_AfterRaikou::
	releaseall
	end

ThunderCave_Text_SomethingWatches:
	.string "You feel like you are\n"
	.string "being watched.$"

ThunderCave_Text_PlayerStumbleBack:
	.string "{PLAYER} stumbles away\n"
	.string "the {STR_VAR_1}.\p"
	.string "It leaps back onto the\n"
	.string "ledge in defence.$"

ThunderCave_Movement_PlayerStumbleBack:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	step_end

