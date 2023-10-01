Route130_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route130_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route130_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Route130_OnResume
	.byte 0

Route130_OnResume_Night:
	setweather WEATHER_RAIN
	return

Route130_OnResume_Day:
	setweather WEATHER_SUNNY
	return

Route130_OnResume:
	goto_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route130_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route130_OnResume_Day
	end

Route130_OnTransition:
	call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Route130_EventScript_CheckSetAbnormalWeather
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, Route130_EventScript_SetMirageIslandLayout
@ Mirage Island isn't currently visible, hide any objects on the island. Only the first flag is actually associated with anything.
	setflag FLAG_TEMP_HIDE_MIRAGE_ISLAND_BERRY_TREE
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	setflag FLAG_TEMP_19
	setflag FLAG_TEMP_1A
	setflag FLAG_TEMP_1B
	setflag FLAG_TEMP_1C
	setflag FLAG_TEMP_1D
	setflag FLAG_TEMP_1E
	setflag FLAG_TEMP_1F
	setmaplayoutindex LAYOUT_ROUTE130
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route130_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route130_OnResume_Day
	end

Route130_EventScript_SetMirageIslandLayout::
	setmaplayoutindex LAYOUT_ROUTE130_MIRAGE_ISLAND
	end

Route130_EventScript_CheckSetAbnormalWeather::
	goto_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

Route130_EventScript_Rodney::
	trainerbattle_single TRAINER_RODNEY, Route130_Text_RodneyIntro, Route130_Text_RodneyDefeat
	msgbox Route130_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Katie::
	trainerbattle_single TRAINER_KATIE, Route130_Text_KatieIntro, Route130_Text_KatieDefeat
	msgbox Route130_Text_KatiePostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Santiago::
	trainerbattle_single TRAINER_SANTIAGO, Route130_Text_SantiagoIntro, Route130_Text_SantiagoDefeat
	msgbox Route130_Text_SantiagoPostBattle, MSGBOX_AUTOCLOSE
	end

