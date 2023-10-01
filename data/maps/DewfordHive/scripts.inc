DewfordHive_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordHive_OnResume
	map_script MAP_SCRIPT_ON_RESUME, DewfordHive_OnResume
	map_script MAP_SCRIPT_ON_LOAD, DewfordHive_OnResume
	.byte 0

DewfordHive_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, DewfordHive_OnResume_Night
	goto_if_eq VAR_RESULT, 0, DewfordHive_OnResume_Day
	end

DewfordHive_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_RAIN
	end

DewfordHive_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	end
