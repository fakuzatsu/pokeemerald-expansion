.set LOCALID_CRESSELIA, 1
.set LOCALID_DARKRAI, 2

NewMoonIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewMoonIsland_Interior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NewMoonIsland_Interior_OnResume
	.byte 0

NewMoonIsland_Interior_OnTransition::
	goto_if_eq VAR_WALDA_QUEST_STATE, 3, NewMoonIsland_Interior_OnTransition_Day
	call_if_eq VAR_WALDA_QUEST_STATE, 4, NewMoonIsland_Interior_HideDarkraiAndCreselia
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, NewMoonIsland_Interior_OnTransition_Night
	goto_if_eq VAR_RESULT, 0, NewMoonIsland_Interior_OnTransition_Day
	end

NewMoonIsland_Interior_HideDarkraiAndCreselia::
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	return

NewMoonIsland_Interior_OnTransition_Night::
	setflag FLAG_TEMP_6
	call_if_set FLAG_CAUGHT_DARKRAI, NewMoonIsland_Interior_HideDarkraiAndCreselia
	call_if_set FLAG_DEFEATED_DARKRAI, NewMoonIsland_Interior_HideDarkraiAndCreselia
	setweather WEATHER_SHADE
	end

NewMoonIsland_Interior_OnTransition_Day::
	call NewMoonIsland_Interior_SetLayoutFullMoon
	setflag FLAG_TEMP_7
	call_if_set FLAG_CAUGHT_CRESSELIA, NewMoonIsland_Interior_HideDarkraiAndCreselia
	call_if_set FLAG_DEFEATED_CRESSELIA, NewMoonIsland_Interior_HideDarkraiAndCreselia
	setweather WEATHER_SUNNY
	end

NewMoonIsland_Interior_SetLayoutFullMoon::
	setmaplayoutindex LAYOUT_FULL_MOON_ISLAND_INTERIOR
	return

NewMoonIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMoonIsland_Interior_TryRemoveLegendary
	end

NewMoonIsland_Interior_TryRemoveLegendary::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

NewMoonIsland_Interior_EventScript_Cresselia::
	lock
	goto_if_eq VAR_WALDA_QUEST_STATE, 3, NewMoonIsland_Interior_EventScript_CresseliaGivesLunarWing
	message NewMoonIsland_Interior_Text_CresseliaCry
	setvar VAR_0x800A, SPECIES_CRESSELIA
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	seteventmon SPECIES_CRESSELIA, 60
	goto NewMoonIsland_Interior_EventScript_DoLegendary
	end

NewMoonIsland_Interior_EventScript_Darkrai::
	lock
	message NewMoonIsland_Interior_Text_DarkraiCry
	setvar VAR_0x800A, SPECIES_DARKRAI
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	seteventmon SPECIES_DARKRAI, 60
	goto NewMoonIsland_Interior_EventScript_DoLegendary
	end

NewMoonIsland_Interior_EventScript_DoLegendary::
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMoonIsland_Interior_EventScript_LegendaryDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMoonIsland_Interior_EventScript_PlayerOrLegendaryRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMoonIsland_Interior_EventScript_PlayerOrLegendaryRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, NewMoonIsland_Interior_EventScript_PlayerOrLegendaryRan
	call_if_eq VAR_0x800A, SPECIES_CRESSELIA, NewMoonIsland_Interior_EventScript_SetCresseliaCaught
	call_if_eq VAR_0x800A, SPECIES_DARKRAI, NewMoonIsland_Interior_EventScript_SetDarkraiCaught
	release
	end

NewMoonIsland_Interior_EventScript_LegendaryDefeated::
	call_if_eq VAR_0x800A, SPECIES_CRESSELIA, NewMoonIsland_Interior_EventScript_SetCresseliaDefeated
	call_if_eq VAR_0x800A, SPECIES_DARKRAI, NewMoonIsland_Interior_EventScript_SetDarkraiDefeated
	copyvar VAR_0x8004, VAR_0x800A
	goto Common_EventScript_LegendaryFlewAway
	release
	end

NewMoonIsland_Interior_EventScript_PlayerOrLegendaryRan::
	copyvar VAR_0x8004, VAR_0x800A
	goto Common_EventScript_LegendaryFlewAway
	release
	end

NewMoonIsland_Interior_EventScript_SetCresseliaCaught::
	setflag FLAG_CAUGHT_CRESSELIA
	return

NewMoonIsland_Interior_EventScript_SetDarkraiCaught::
	setflag FLAG_CAUGHT_DARKRAI
	return

NewMoonIsland_Interior_EventScript_SetCresseliaDefeated::
	setflag FLAG_DEFEATED_CRESSELIA
	return

NewMoonIsland_Interior_EventScript_SetDarkraiDefeated::
	setflag FLAG_DEFEATED_DARKRAI
	return

NewMoonIsland_Interior_EventScript_CresseliaGivesLunarWing::
	message NewMoonIsland_Interior_Text_CresseliaCry
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	delay 20
	removeobject LOCALID_CRESSELIA
	delay 20
	fadescreen FADE_FROM_BLACK
	delay 20
	playse SE_M_DETECT
	dofieldeffectsparkle 10, 9, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 16
	msgbox NewMoonIsland_Interior_Text_CresseliaLeftAFeather, MSGBOX_DEFAULT
	giveitem ITEM_LUNAR_FEATHER
	setvar VAR_WALDA_QUEST_STATE, 4
	release
	end

NewMoonIsland_Interior_Text_CresseliaCry:
	.string "Lunaaan$"

NewMoonIsland_Interior_Text_CresseliaLeftAFeather:
	.string "The Pokémon left a glowing feather.\p"
	.string "Simply touching it instills a sense\n"
	.string "of serenity.$"

NewMoonIsland_Interior_Text_DarkraiCry:
	.string "Raaiiiii$"
