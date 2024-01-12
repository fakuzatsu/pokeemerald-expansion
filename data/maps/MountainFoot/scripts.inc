MountainFoot_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MountainFoot_OnResume
	map_script MAP_SCRIPT_ON_RESUME, MountainFoot_OnResume
	map_script MAP_SCRIPT_ON_LOAD, MountainFoot_OnLoad
	.byte 0

MountainFoot_OnLoad:
	call_if_set FLAG_HIDDEN_ITEM_ALAKAZITE, MountainFoot_Hide_Alakazite
	goto_if_set FLAG_SYS_GAME_CLEAR, MountainFoot_Open_LegendaryBirdCave
	end

MountainFoot_Open_LegendaryBirdCave::
	setmetatile 61, 2, METATILE_General_CaveEntrance_Bottom, FALSE
	setmetatile 61, 1, METATILE_General_CaveEntrance_Top, TRUE
	end

MountainFoot_Hide_Alakazite::
    setmetatile 57, 12, METATILE_General_Grass, FALSE
    return

MountainFoot_Alakazite::
	goto_if_set FLAG_HIDDEN_ITEM_ALAKAZITE, MountainFoot_End_Alakazite
	checkitemspace ITEM_ALAKAZITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call MountainFoot_Hide_Alakazite
	special DrawWholeMapView
	giveitem ITEM_ALAKAZITE
	setflag FLAG_HIDDEN_ITEM_ALAKAZITE
MountainFoot_End_Alakazite::
	release
	end	

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

