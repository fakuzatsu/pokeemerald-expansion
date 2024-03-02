CoronetHotsprings_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CoronetHotsprings_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CoronetHotsprings_OnResume
	.byte 0

CoronetHotsprings_OnTransition:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, CoronetHotsprings_OnResume_Night
	goto_if_eq VAR_RESULT, 0, CoronetHotsprings_OnTransition_Day
	end

CoronetHotsprings_OnTransition_Day:
	setweather WEATHER_SUNNY
	clearflag FLAG_HIDE_TRAINER_NIGHT
	end

CoronetHotsprings_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, CoronetHotsprings_OnResume_Night
	goto_if_eq VAR_RESULT, 0, CoronetHotsprings_OnResume_Day
	end

CoronetHotsprings_OnResume_Night:
	setweather WEATHER_SHADE
	setflag FLAG_HIDE_TRAINER_NIGHT
	end

CoronetHotsprings_OnResume_Day:
	setweather WEATHER_SUNNY
	end

CoronetHotsprings_EventScript_Flavia::
	lock
	faceplayer
	goto_if_set FLAG_BADGE04_GET, CoronetHotsprings_EventScript_GiveHoundoomiteOrEnd
	msgbox CoronetHotsprings_Text_Flavia, MSGBOX_DEFAULT
	release
	end

CoronetHotsprings_EventScript_GiveHoundoomiteOrEnd::
	goto_if_unset FLAG_HIDDEN_ITEM_HOUNDOOMINITE, CoronetHotsprings_EventScript_GiveHoundoomite
	msgbox CoronetHotsprings_Text_ThanksForHelpingHerOut, MSGBOX_DEFAULT
	release
	end

CoronetHotsprings_EventScript_GiveHoundoomite::
	msgbox CoronetHotsprings_Text_OhYouBeatFlannery, MSGBOX_DEFAULT
	giveitem ITEM_HOUNDOOMINITE
	goto_if_eq VAR_RESULT, CoronetHotsprings_EventScript_NotEnoughSpace
	msgbox CoronetHotsprings_Text_ThanksForHelpingHerOut, MSGBOX_DEFAULT
	setflag FLAG_HIDDEN_ITEM_HOUNDOOMINITE
	release
	end

CoronetHotsprings_EventScript_NotEnoughSpace::
	msgbox CoronetHotsprings_Text_YoullNeedToMakeSpace, MSGBOX_DEFAULT
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

CoronetHotsprings_Text_OhYouBeatFlannery:
	.string "Oh hey! That badge means you beat\n"
	.string "my sister Flannery.\p"
	.string "You must be one tough Lava Cookie.\p"
	.string "Here's something from me too.$"

CoronetHotsprings_Text_YoullNeedToMakeSpace:
	.string "Oh, but you'll need to make space\n"
	.string "in your bag if you want it.$"

CoronetHotsprings_Text_ThanksForHelpingHerOut:
	.string "I know my sister…\p"
	.string "She's a total hothead and she takes\n"
	.string "things way too seriously.\p"
	.string "I bet a fight with a trainer like\n"
	.string "you straightened her out a bit?\p"
	.string "Thanks for that.$"

CoronetHotsprings_Text_SometimesPokemon:
	.string "Hihi!\p"
	.string "Did you know that Pokémon sometimes\n"
	.string "come down here from the mountains!\p"
	.string "Cool, huh?$"

