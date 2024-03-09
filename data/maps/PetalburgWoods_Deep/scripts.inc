PetalburgWoods_Deep_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgWoods_Deep_OnResume
	map_script MAP_SCRIPT_ON_RESUME, PetalburgWoods_Deep_OnResume
	.byte 0

PetalburgWoods_Deep_OnResume:
	setflag FLAG_LANDMARK_FARAWAY_ISLAND
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, PetalburgWoods_Deep_OnResume_Night
	goto_if_eq VAR_RESULT, 0, PetalburgWoods_Deep_OnResume_Day
	end

PetalburgWoods_Deep_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	end

PetalburgWoods_Deep_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	end

