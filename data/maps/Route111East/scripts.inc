Route111East_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111East_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route111East_OnResume
	.byte 0

Route111East_OnResume:
	call Route111East_EventScript_CheckSetSandstorm
	end

Route111East_OnTransition:
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	call Route111East_EventScript_CheckSetSandstorm
	end

Route111East_EventScript_CheckSetSandstorm::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_0, 10, Route111East_EventScript_SetSandstorm
	goto_if_gt VAR_TEMP_0, 2000, Route111East_EventScript_SetSandstorm
	goto_if_ge VAR_TEMP_0, 10, Route111East_EventScript_StopSandstorm
Route111East_EventScript_SetSandstorm::
	setweather WEATHER_SANDSTORM
	doweather
	return

Route111East_EventScript_StopSandstorm::
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route111East_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route111East_OnResume_Day
	end

Route111East_OnResume_Night:
	setweather WEATHER_SHADE
	return

Route111East_OnResume_Day:
	setweather WEATHER_SUNNY
	return

Route111East_EventScript_SunTrigger::
	special GetDayOrNight
	call_if_eq VAR_RESULT, 1, Route111_OnResume_Night
	call_if_eq VAR_RESULT, 0, Route111_OnResume_Day
	fadenewbgm MUS_ROUTE110
	doweather
	end

Route111East_EventScript_CheckVars::
	lock
	faceplayer
	buffernumberstring STR_VAR_1, VAR_TEMP_2
	buffernumberstring STR_VAR_2, VAR_TEMP_3
	msgbox Route111East_Text_CheckVars, MSGBOX_DEFAULT
	release
	end

Route111East_Text_CheckVars:
	.string "VAR_TEMP_2 is {STR_VAR_1}\n"
	.string "VAR_TEMP_3 is {STR_VAR_2}$"
