Route119East_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119East_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Route119East_OnResume
	map_script MAP_SCRIPT_ON_RESUME, Route119East_OnResume
	.byte 0

Route119East_OnResume:
	special SetRoute119Weather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route119East_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route119East_OnResume_Day
	end

Route119East_OnResume_Night:
	setweather WEATHER_RAIN
	return

Route119East_OnResume_Day:
	setweather WEATHER_ROUTE119_CYCLE
	return

