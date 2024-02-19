.set LOCALID_CRESSELIA, 1
.set LOCALID_DARKRAI, 2

NewMoonIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewMoonIsland_Interior_OnTransition
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
	setweather WEATHER_SHADE
	end

NewMoonIsland_Interior_OnTransition_Day::
	call NewMoonIsland_Interior_SetLayoutFullMoon
	setflag FLAG_TEMP_7
	setweather WEATHER_SUNNY
	end

NewMoonIsland_Interior_SetLayoutFullMoon::
	setmaplayoutindex LAYOUT_FULL_MOON_ISLAND_INTERIOR
	return

NewMoonIsland_Interior_EventScript_Cresselia::
	lockall
	goto_if_eq VAR_WALDA_QUEST_STATE, 3, NewMoonIsland_Interior_EventScript_CresseliaGivesLunarWing
	releaseall
	end

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
	releaseall
	end

NewMoonIsland_Interior_Text_CresseliaCry:
	.string "Lunaaan$"

NewMoonIsland_Interior_Text_CresseliaLeftAFeather:
	.string "The Pokémon left a glowing feather.\p"
	.string "Simply touching it instills a sense\n"
	.string "of serenity.$"
