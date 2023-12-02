AshveilCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AshveilCave_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, AshveilCave_OnLoad
	.byte 0

AshveilCave_OnTransition:
	goto_if_set FLAG_CAUGHT_ENTEI, AshveilCave_EventScript_DisableTrigger
	goto_if_set FLAG_DEFEATED_ENTEI, AshveilCave_EventScript_DisableTrigger
	end

AshveilCave_OnLoad:
	call_if_set FLAG_HIDDEN_ITEM_BLAZIKENITE, AshveilCave_Hide_Blazikenite
	end

AshveilCave_Hide_Blazikenite::
    setmetatile 7, 7, METATILE_Cave_RockFloor, FALSE
    return

AshveilCave_Blazikenite::
	goto_if_set FLAG_HIDDEN_ITEM_BLAZIKENITE, AshveilCave_End_Blazikenite
	call AshveilCave_Hide_Blazikenite
	special DrawWholeMapView
	setflag FLAG_HIDDEN_ITEM_BLAZIKENITE
	switch VAR_STARTER_MON
	case 0, AshveilCave_Give_Blazikenite
	case 1, AshveilCave_Give_RainbowWing
	case 2, AshveilCave_Give_Blazikenite
	end

AshveilCave_Give_RainbowWing::
	giveitem ITEM_RAINBOW_WING
	goto AshveilCave_End_Blazikenite
	end

AshveilCave_Give_Blazikenite::
	giveitem ITEM_BLAZIKENITE
	goto AshveilCave_End_Blazikenite
	end

AshveilCave_End_Blazikenite::
	release
	end	

AshveilCave_EventScript_DisableTrigger::
	setvar VAR_TEMP_0, 2
	end

AshveilCave_EventScript_SomethingWatches::
	lockall
	goto_if_set FLAG_DEFEATED_ENTEI, AshveilCave_EventScript_AfterEntei
	msgbox AshveilCave_Text_SomethingWatches, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

AshveilCave_EventScript_Entei::
	lockall
	goto_if_set FLAG_DEFEATED_ENTEI, AshveilCave_EventScript_AfterEntei
	waitse
	playmoncry SPECIES_ENTEI, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	setwildbattle SPECIES_ENTEI, 65
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AshveilCave_EventScript_DefeatedEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AshveilCave_EventScript_RanFromEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AshveilCave_EventScript_RanFromEntei
	setflag FLAG_CAUGHT_ENTEI
	setvar VAR_TEMP_0, 2
	goto AshveilCave_EventScript_AfterEntei
	end

AshveilCave_EventScript_DefeatedEntei::
	setflag FLAG_DEFEATED_ENTEI
	bufferspeciesname STR_VAR_1, SPECIES_ENTEI
	msgbox gText_LegendaryRanAway, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 2
	goto AshveilCave_EventScript_AfterEntei
	end

AshveilCave_EventScript_RanFromEntei::
	applymovement OBJ_EVENT_ID_PLAYER, AshveilCave_Movement_PlayerStumbleBack
	bufferspeciesname STR_VAR_1, SPECIES_ENTEI
	msgbox AshveilCave_Text_PlayerStumbleBack, MSGBOX_DEFAULT
	goto AshveilCave_EventScript_AfterEntei
	end

AshveilCave_EventScript_AfterEntei::
	releaseall
	end

AshveilCave_Text_SomethingWatches:
	.string "You feel like you are\n"
	.string "being watched.$"

AshveilCave_Text_PlayerStumbleBack:
	.string "{PLAYER} stumbles away\n"
	.string "the {STR_VAR_1}.\p"
	.string "It leaps back onto the\n"
	.string "ledge in defence.$"

AshveilCave_Movement_PlayerStumbleBack:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	step_end

