DewfordHive_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordHive_OnResume
	map_script MAP_SCRIPT_ON_RESUME, DewfordHive_OnResume
	.byte 0

DewfordHive_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, DewfordHive_OnResume_Night
	goto_if_eq VAR_RESULT, 0, DewfordHive_OnResume_Day
	end

DewfordHive_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_RAIN
	end

DewfordHive_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	end

DewfordHive_EventScript_CluelessBugcatcher::
	lock
	goto_if_set FLAG_HIDDEN_ITEM_SCIZORITE, DewfordHive_EventScript_GivenMetalCoat
	msgbox DewfordHive_Text_NeedAMetalCoat, MSGBOX_DEFAULT
	checkitem ITEM_METAL_COAT
	goto_if_eq VAR_RESULT, TRUE, DewfordHive_EventScript_PlayerHasMetalCoat
	release
	end

DewfordHive_EventScript_PlayerHasMetalCoat::
	call_if_unset FLAG_TEMP_2, DewfordHive_EventScript_NoticeMetalCoat
	call_if_set FLAG_TEMP_2, DewfordHive_EventScript_AskForMetalCoat
	goto_if_eq VAR_RESULT, NO, DewfordHive_EventScript_DeclineGiveMetalCoat
	msgbox DewfordHive_Text_HehSureTakeThisStone, MSGBOX_DEFAULT
	giveitem ITEM_SCIZORITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METAL_COAT
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_HIDDEN_ITEM_SCIZORITE
	msgbox DewfordHive_Text_HehNice, MSGBOX_DEFAULT
	release
	end

DewfordHive_EventScript_NoticeMetalCoat::
	msgbox DewfordHive_Text_OhWhatsThatYouHaveThere, MSGBOX_DEFAULT
	msgbox DewfordHive_Text_GiveMeThatMetalCoat, MSGBOX_YESNO
	return

DewfordHive_EventScript_AskForMetalCoat::
	msgbox DewfordHive_Text_GiveMeThatMetalCoat, MSGBOX_YESNO
	return

DewfordHive_EventScript_DeclineGiveMetalCoat::
	setflag FLAG_TEMP_2
	msgbox DewfordHive_Text_HumphIllGetItMyself, MSGBOX_DEFAULT
	release
	end

DewfordHive_EventScript_GivenMetalCoat::
	msgbox DewfordHive_Text_ScizorAndIAreGoingToTheTop, MSGBOX_DEFAULT
	release
	end

DewfordHive_Text_NeedAMetalCoat:
	.string "I really need to find a Metal Coat so\n"
	.string "I can evolve my Scyther.$"

DewfordHive_Text_OhWhatsThatYouHaveThere:
	.string "Oh! That glimmer!\n"
	.string "Could it be?\p"
	.string "Is that a Metal Coat?$"

DewfordHive_Text_GiveMeThatMetalCoat:
	.string "If you give me your Metal Coat, I'll\n"
	.string "give you this weird stone.\p"
	.string "How about it?$"

DewfordHive_Text_HumphIllGetItMyself:
	.string "Humph.\p"
	.string "Fine. I'll find one myself.$"

DewfordHive_Text_HehSureTakeThisStone:
	.string "Heh.\p"
	.string "Here you go.$"

DewfordHive_Text_HehNice:
	.string "Heh heh.\p"
	.string "Nice!$"

DewfordHive_Text_ScizorAndIAreGoingToTheTop:
	.string "Scizor and I are going all teh way\n"
	.string "to the top.\p"
	.string "Just you wait.$"
