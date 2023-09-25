SpringPeak_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SpringPeak_OnResume
	map_script MAP_SCRIPT_ON_RESUME, SpringPeak_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SpringPeak_OnLoad
	.byte 0

SpringPeak_OnResume:
	setweather WEATHER_RAIN_THUNDERSTORM
	end

SpringPeak_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, SpringPeak_EventScript_CloseThunderCave
	setweather WEATHER_RAIN_THUNDERSTORM
	end

SpringPeak_EventScript_CloseThunderCave::
	setmetatile 7, 6, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 7, 5, METATILE_General_RockWall_SandBase, TRUE
	return

