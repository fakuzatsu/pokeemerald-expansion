VerdantIsle_Deep_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdantIsle_Deep_OnResume
	map_script MAP_SCRIPT_ON_RESUME, VerdantIsle_Deep_OnResume
	.byte 0

VerdantIsle_Deep_OnResume:
	setflag FLAG_LANDMARK_LOST_LIGHTHOUSE
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, VerdantIsle_Deep_OnResume_Night
	goto_if_eq VAR_RESULT, 0, VerdantIsle_Deep_OnResume_Day
	end

VerdantIsle_Deep_OnResume_Night:
	setweather WEATHER_SHADE
	end

VerdantIsle_Deep_OnResume_Day:
	setweather WEATHER_SUNNY
	end
