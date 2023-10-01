CoronetHotsprings_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CoronetHotsprings_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CoronetHotsprings_OnResume
	map_script MAP_SCRIPT_ON_LOAD, CoronetHotsprings_OnResume
	.byte 0

CoronetHotsprings_OnTransition:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, CoronetHotsprings_OnResume_Night
	goto_if_eq VAR_RESULT, 0, CoronetHotsprings_OnTransition_Day
	end

CoronetHotsprings_OnTransition_Day:
	setweather WEATHER_SUNNY
	clearflag FLAG_HIDE_TRAINER_DAYNIGHT
	end

CoronetHotsprings_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, CoronetHotsprings_OnResume_Night
	goto_if_eq VAR_RESULT, 0, CoronetHotsprings_OnResume_Day
	end

CoronetHotsprings_OnResume_Night:
	setweather WEATHER_SHADE
	setflag FLAG_HIDE_TRAINER_DAYNIGHT
	end

CoronetHotsprings_OnResume_Day:
	setweather WEATHER_SUNNY
	end

CoronetHotsprings_EventScript_Flavia::
	lock
	faceplayer
	msgbox CoronetHotsprings_Text_Flavia, MSGBOX_DEFAULT
	release
	end

CoronetHotsprings_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox CoronetHotsprings_Text_SometimesPokemon, MSGBOX_DEFAULT
	release
	end

CoronetHotsprings_Text_Flavia:
	.string "Hi! I'm Flavia!\p"
	.string "You're probably looking for my\n"
	.string "older sister!\p"
	.string "She's the new gym leader now\n"
	.string "that gramps is retired!$"

CoronetHotsprings_Text_SometimesPokemon:
	.string "Hihi!\p"
	.string "Did you know that Pokémon sometimes\n"
	.string "come down here from the mountains!\p"
	.string "Cool, huh?$"

