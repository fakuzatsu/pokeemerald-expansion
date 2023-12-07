Slateport_Left_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Slateport_Left_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Slateport_Left_OnResume
	.byte 0

Slateport_Left_OnTransition:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Slateport_Left_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Slateport_Left_OnTransition_Day
	end

Slateport_Left_OnTransition_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	clearflag FLAG_HIDE_TRAINER_NIGHT
	end

Slateport_Left_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Slateport_Left_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Slateport_Left_OnResume_Day
	end

Slateport_Left_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	setflag FLAG_HIDE_TRAINER_NIGHT
	end

Slateport_Left_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	end

SlateportCity_Left_EventScript_OldMan::
	lock
	faceplayer
	msgbox SlateportCity__Left_Text_TakingABreak, MSGBOX_DEFAULT
	release
	end

SlateportCity_Left_EventScript_RelaxedGirl::
	lock
	faceplayer
	msgbox SlateportCity_Left_Text_ItsNiceHere, MSGBOX_DEFAULT
	release
	end

SlateportCity_Left_EventScript_ShedMan::
	lock
	faceplayer
	msgbox SlateportCity_Left_Text_ThisIsTheShed, MSGBOX_DEFAULT
	release
	end

SlateportCity_Left_EventScript_ColdStorage::
	msgbox SlateportCity_Left_Text_ColdStorage, MSGBOX_SIGN
	end

SlateportCity__Left_Text_TakingABreak:
	.string "Whew… It's been a long day\n"
	.string "working in the factory so far.\p"
	.string "Thank goodness it's my break.$"

SlateportCity_Left_Text_ItsNiceHere:
	.string "It's nice to relax over here\n"
	.string "away from all of the hustle.\p"
	.string "I think the Pokémon like it too!$"

SlateportCity_Left_Text_ThisIsTheShed:
	.string "This is the shed for the Market.\p"
	.string "All of our event props and spare\n"
	.string "materials are in here.$"

SlateportCity_Left_Text_ColdStorage:
	.string "SLATEPORT Cold Storage\n"
	.string "“ABANDONED”$"

