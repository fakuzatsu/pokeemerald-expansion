SurgeCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SurgeCave_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SurgeCave_OnLoad
	.byte 0

SurgeCave_OnTransition:
	goto_if_set FLAG_CAUGHT_SUICUNE, SurgeCave_EventScript_DisableTrigger
	goto_if_set FLAG_DEFEATED_SUICUNE, SurgeCave_EventScript_DisableTrigger
	end

SurgeCave_OnLoad:
	call_if_set FLAG_HIDDEN_ITEM_SWAMPERTITE, SurgeCave_Hide_Swampertite
	end

SurgeCave_Hide_Swampertite::
    setmetatile 7, 7, METATILE_Cave_RockFloor, FALSE
    return

SurgeCave_Swampertite::
	goto_if_set FLAG_HIDDEN_ITEM_SWAMPERTITE, SurgeCave_End_Swampertite
	checkitemspace ITEM_SWAMPERTITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call SurgeCave_Hide_Swampertite
	special DrawWholeMapView
	setflag FLAG_HIDDEN_ITEM_SWAMPERTITE
	switch VAR_STARTER_MON
	case 0, SurgeCave_Give_Swampertite
	case 1, SurgeCave_Give_Swampertite
	case 2, SurgeCave_Give_RainbowWing
	end

SurgeCave_Give_RainbowWing::
	giveitem ITEM_RAINBOW_WING
	goto SurgeCave_End_Swampertite
	end

SurgeCave_Give_Swampertite::
	giveitem ITEM_SWAMPERTITE
	goto SurgeCave_End_Swampertite
	end

SurgeCave_End_Swampertite::
	release
	end	

SurgeCave_EventScript_DisableTrigger::
	setvar VAR_TEMP_0, 2
	end

SurgeCave_EventScript_SomethingWatches::
	lockall
	goto_if_set FLAG_DEFEATED_SUICUNE, SurgeCave_EventScript_AfterSuicune
	msgbox SurgeCave_Text_SomethingWatches, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

SurgeCave_EventScript_Suicune::
	lockall
	goto_if_set FLAG_DEFEATED_SUICUNE, SurgeCave_EventScript_AfterSuicune
	waitse
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 65
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SurgeCave_EventScript_DefeatedSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SurgeCave_EventScript_RanFromSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SurgeCave_EventScript_RanFromSuicune
	setflag FLAG_CAUGHT_SUICUNE
	setvar VAR_TEMP_0, 2
	goto SurgeCave_EventScript_AfterSuicune
	end

SurgeCave_EventScript_DefeatedSuicune::
	setflag FLAG_DEFEATED_SUICUNE
	bufferspeciesname STR_VAR_1, SPECIES_SUICUNE
	msgbox gText_LegendaryRanAway, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 2
	goto SurgeCave_EventScript_AfterSuicune
	end

SurgeCave_EventScript_RanFromSuicune::
	applymovement OBJ_EVENT_ID_PLAYER, SurgeCave_Movement_PlayerStumbleBack
	bufferspeciesname STR_VAR_1, SPECIES_SUICUNE
	msgbox SurgeCave_Text_PlayerStumbleBack, MSGBOX_DEFAULT
	goto SurgeCave_EventScript_AfterSuicune
	end

SurgeCave_EventScript_AfterSuicune::
	releaseall
	end

SurgeCave_Text_SomethingWatches:
	.string "You feel like you are\n"
	.string "being watched.$"

SurgeCave_Text_PlayerStumbleBack:
	.string "{PLAYER} stumbles away\n"
	.string "the {STR_VAR_1}.\p"
	.string "It leaps back onto the\n"
	.string "ledge in defence.$"

SurgeCave_Movement_PlayerStumbleBack:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	step_end

