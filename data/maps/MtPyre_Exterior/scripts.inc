MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_Exterior_OnResume
	map_script MAP_SCRIPT_ON_LOAD, MtPyre_Exterior_OnResume
	.byte 0

MtPyre_Exterior_OnResume:
	special GetDayOrNight
	call_if_eq VAR_RESULT, 1, MtPyre_Exterior_OnResume_Night
	call_if_eq VAR_RESULT, 0, MtPyre_Exterior_OnResume_Day
	end

MtPyre_Exterior_OnResume_Night:
	setweather WEATHER_SHADE
	return

MtPyre_Exterior_OnResume_Day:
	setweather WEATHER_SUNNY
	return

MtPyre_Exterior_OnTransition:
	goto MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 12, MtPyre_Exterior_EventScript_EnterFromSummit
	special GetDayOrNight
	call_if_eq VAR_RESULT, 1, MtPyre_Exterior_OnResume_Night
	call_if_eq VAR_RESULT, 0, MtPyre_Exterior_OnResume_Day
	end

MtPyre_Exterior_EventScript_EnterFromSummit::
	setweather WEATHER_FOG_HORIZONTAL
	end

MtPyre_Exterior_EventScript_FogTrigger::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

MtPyre_Exterior_EventScript_SunTrigger::
	special GetDayOrNight
	call_if_eq VAR_RESULT, 1, MtPyre_Exterior_OnResume_Night
	call_if_eq VAR_RESULT, 0, MtPyre_Exterior_OnResume_Day
	doweather
	end

