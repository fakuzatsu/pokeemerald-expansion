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
