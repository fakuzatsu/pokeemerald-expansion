PacifidlogTown_Resort_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_Resort_OnResume
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_Resort_OnResume
	.byte 0

PacifidlogTown_Resort_OnResume_Night:
	setweather WEATHER_SHADE
	return

PacifidlogTown_Resort_OnResume_Day:
	setweather WEATHER_SUNNY
	return

PacifidlogTown_Resort_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, PacifidlogTown_Resort_OnResume_Night
	goto_if_eq VAR_RESULT, 0, PacifidlogTown_Resort_OnResume_Day
	end

PacifidlogTown_Resort_EventScript_Woman::
	msgbox PacifidlogTown_Resort_Text_ExpandedTown, MSGBOX_NPC
	end

PacifidlogTown_Resort_EventScript_Girl::
	msgbox PacifidlogTown_Text_CultivatingFlowers, MSGBOX_NPC
	end

PacifidlogTown_Resort_EventScript_HotTub::
	lock
	goto_if_set FLAG_PLAYER_OWNS_RESORT, PacifidlogTown_Resort_EventScript_WantToUseHotTub
	msgbox PacifidlogTown_Text_ItsAHotTub, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_Resort_EventScript_WantToUseHotTub::
	msgbox PacifidlogTown_Text_WantToUseHotTub, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_Resort_EventScript_UseHotTub
	release
	end

PacifidlogTown_Resort_EventScript_UseHotTub::
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

PacifidlogTown_Resort_Text_ExpandedTown:
	.string "Pacifidlog has expanded greatly over\n"
	.string "the the last few months!\p"
	.string "Everything you see up here was made\n"
	.string "to bring more people to our town!$"

PacifidlogTown_Text_CultivatingFlowers:
	.string "All the flowers you see around us were\n"
	.string "brought from other places.\p"
	.string "It takes a lot of attention to raise\n"
	.string "flowers outside their natural habitat.$"

PacifidlogTown_Text_ItsAHotTub:
	.string "It's somebody's hot tub.$"

PacifidlogTown_Text_WantToUseHotTub:
	.string "Use your hot tub?$"
