AcornAcre_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AcornAcre_OnResume
	map_script MAP_SCRIPT_ON_RESUME, AcornAcre_OnResume
	.byte 0

AcornAcre_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, AcornAcre_OnResume_Night
	goto_if_eq VAR_RESULT, 0, AcornAcre_OnResume_Day
	end

AcornAcre_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	end

AcornAcre_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	end

AcornAcre_EventScript_Lara::
	trainerbattle_single TRAINER_LARA, AcornAcre_Text_LaraIntro, AcornAcre_Text_LaraDefeated
	msgbox AcornAcre_Text_LaraPostBattle, MSGBOX_AUTOCLOSE
	end

AcornAcre_EventScript_RouteSignAcornAcre::
	msgbox AcornAcre_Text_RouteSignAcornAcre, MSGBOX_SIGN
	end

AcornAcre_Text_RouteSignAcornAcre:
	.string "Route 102\n"
	.string "{UP_ARROW} ACORN ACRE$"

