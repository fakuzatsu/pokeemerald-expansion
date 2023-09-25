EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, EverGrandeCity_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_OnResume
	.byte 0

EverGrandeCity_OnResume:
	goto_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, EverGrandeCity_OnResume_Night
	goto_if_eq VAR_RESULT, 0, EverGrandeCity_OnResume_Day
	end

EverGrandeCity_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	end

EverGrandeCity_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	end

EverGrandeCity_OnTransition:
	goto_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, EverGrandeCity_OnResume_Night
	goto_if_eq VAR_RESULT, 0, EverGrandeCity_OnResume_Day
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "Entering Victory Road$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "Entering Pokémon League\n"
	.string "center gate$"

EverGrandeCity_Text_CitySign:
	.string "Ever Grande City\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and Pokémon.”$"

