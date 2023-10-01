AbandonedShip_Deck_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_Deck_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Deck_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Deck_OnResume
	.byte 0

AbandonedShip_Deck_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, AbandonedShip_Deck_OnResume_Night
	goto_if_eq VAR_RESULT, 0, AbandonedShip_Deck_OnResume_Day
	end

AbandonedShip_Deck_OnResume_Night:
	setweather WEATHER_SHADE
	end

AbandonedShip_Deck_OnResume_Day:
	setweather WEATHER_SUNNY
	end

AbandonedShip_Deck_OnTransition:
	setflag FLAG_LANDMARK_ABANDONED_SHIP
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, AbandonedShip_Deck_OnResume_Night
	goto_if_eq VAR_RESULT, 0, AbandonedShip_Deck_OnResume_Day
	end

