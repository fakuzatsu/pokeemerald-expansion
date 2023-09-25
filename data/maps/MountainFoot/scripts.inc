MountainFoot_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MountainFoot_OnResume
	map_script MAP_SCRIPT_ON_RESUME, MountainFoot_OnResume
	map_script MAP_SCRIPT_ON_LOAD, MountainFoot_OnResume
	.byte 0

MountainFoot_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, MountainFoot_OnResume_Night
	goto_if_eq VAR_RESULT, 0, MountainFoot_OnResume_Day
	end

MountainFoot_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	end

MountainFoot_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	end

MountainFoot_EventScript_Hex_Maniac::
	lock
	faceplayer
	msgbox MountainFoot_Text_GoToRustboro, MSGBOX_NPC
	release
	end

MountainFoot_Text_GoToRustboro:
	.string "I want to go to Rustboro. But this\n"
	.string "ledge is way too steep.\p"
	.string "I'd never be able to make it back\n"
	.string "home if I jumped down...$"

