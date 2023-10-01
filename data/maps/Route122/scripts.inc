Route122_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route122_OnResume
	map_script MAP_SCRIPT_ON_RESUME, Route122_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Route122_OnResume
	.byte 0

Route122_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route122_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route122_OnResume_Day
	end

Route122_OnResume_Night:
	setweather WEATHER_SHADE
	end

Route122_OnResume_Day:
	setweather WEATHER_SUNNY
	end

