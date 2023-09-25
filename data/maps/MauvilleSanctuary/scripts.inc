MauvilleSanctuary_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleSanctuary_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MauvilleSanctuary_OnResume
	map_script MAP_SCRIPT_ON_LOAD, MauvilleSanctuary_OnResume
	.byte 0

MauvilleSanctuary_OnTransition:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, MauvilleSanctuary_OnResume_Night
	goto_if_eq VAR_RESULT, 0, MauvilleSanctuary_OnTransition_Day
	end

MauvilleSanctuary_OnTransition_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	clearflag FLAG_HIDE_TRAINER_DAYNIGHT
	end

MauvilleSanctuary_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, MauvilleSanctuary_OnResume_Night
	goto_if_eq VAR_RESULT, 0, MauvilleSanctuary_OnResume_Day
	end

MauvilleSanctuary_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	setflag FLAG_HIDE_TRAINER_DAYNIGHT
	end

MauvilleSanctuary_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	end

MauvilleSanctuary_EventScript_Camper::
	lock
	faceplayer
	msgbox MauvilleSanctuary_Text_PreferQuiet, MSGBOX_NPC
	release
	end

MauvilleSanctuary_Text_PreferQuiet:
	.string "The Pokémon seem to prefer it over here\p"
	.string "where it's more quiet.\n"
	.string "Even the the Pokémon in the pond seem\l"
	.string "happier on this side.$"

