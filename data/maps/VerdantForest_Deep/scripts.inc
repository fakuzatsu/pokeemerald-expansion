VerdantForest_Deep_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdantForest_Deep_OnResume
	map_script MAP_SCRIPT_ON_RESUME, VerdantForest_Deep_OnResume
	.byte 0

VerdantForest_Deep_OnResume:
	setflag FLAG_LANDMARK_ANCIENT_SHRINE
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, VerdantForest_Deep_OnResume_Night
	goto_if_eq VAR_RESULT, 0, VerdantForest_Deep_OnResume_Day
	end

VerdantForest_Deep_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	end

VerdantForest_Deep_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	end

