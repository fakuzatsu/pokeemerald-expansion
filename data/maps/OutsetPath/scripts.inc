OutsetPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OutsetPath_OnResume
	map_script MAP_SCRIPT_ON_RESUME, OutsetPath_OnResume
	map_script MAP_SCRIPT_ON_LOAD, OutsetPath_OnLoad
	.byte 0

OutsetPath_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, OutsetPath_OnResume_Night
	goto_if_eq VAR_RESULT, 0, OutsetPath_OnResume_Day
	end

OutsetPath_OnResume_Night:
	setweather WEATHER_SHADE
	end

OutsetPath_OnResume_Day:
	setweather WEATHER_SUNNY
	end

OutsetPath_OnLoad:
	call_if_set FLAG_HIDDEN_ITEM_SLOWBRONITE, OutsetPath_Hide_Slowbronite
	end

OutsetPath_Hide_Slowbronite::
    setmetatile 29, 9, METATILE_General_Grass, FALSE
    return

OutsetPath_Slowbronite::
	goto_if_set FLAG_HIDDEN_ITEM_SLOWBRONITE, OutsetPath_End_Slowbronite
	checkitemspace ITEM_SLOWBRONITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call OutsetPath_Hide_Slowbronite
	special DrawWholeMapView
	giveitem ITEM_SLOWBRONITE
	setflag FLAG_HIDDEN_ITEM_SLOWBRONITE
OutsetPath_End_Slowbronite::
	release
	end

