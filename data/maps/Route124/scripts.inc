Route124_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route124_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Route124_OnLoad
	.byte 0

Route124_OnLoad:
	call_if_set FLAG_HIDDEN_ITEM_GYARADOSITE, Route124_Hide_Gyaradosite
	end

Route124_Hide_Gyaradosite::
    setmetatile 37, 63, METATILE_General_ShallowWater, FALSE
    return

Route124_Gyaradosite::
	goto_if_set FLAG_HIDDEN_ITEM_GYARADOSITE, Route124_End_Gyaradosite
	checkitemspace ITEM_GYARADOSITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call Route124_Hide_Gyaradosite
	special DrawWholeMapView
	giveitem ITEM_GYARADOSITE
	setflag FLAG_HIDDEN_ITEM_GYARADOSITE
Route124_End_Gyaradosite::
	release
	end	

Route124_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	setflag FLAG_HIDE_TRAINER_NIGHT
	return

Route124_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	return

Route124_OnResume:
	goto_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route124_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route124_OnResume_Day
	end

Route124_OnTransition:
	goto_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route124_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route124_OnTransition_Day
	end

Route124_OnTransition_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	clearflag FLAG_HIDE_TRAINER_NIGHT
	return

Route124_EventScript_HuntersHouseSign::
	msgbox Route124_Text_HuntersHouse, MSGBOX_SIGN
	end

Route124_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER, Route124_Text_SpencerIntro, Route124_Text_SpencerDefeat
	msgbox Route124_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roland::
	trainerbattle_single TRAINER_ROLAND, Route124_Text_RolandIntro, Route124_Text_RolandDefeat
	msgbox Route124_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Jenny::
	trainerbattle_single TRAINER_JENNY_1, Route124_Text_JennyIntro, Route124_Text_JennyDefeat, Route124_EventScript_RegisterJenny
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchJenny
	msgbox Route124_Text_JennyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterJenny::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route124_Text_JennyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JENNY_1
	release
	end

Route124_EventScript_RematchJenny::
	trainerbattle_rematch TRAINER_JENNY_1, Route124_Text_JennyRematchIntro, Route124_Text_JennyRematchDefeat
	msgbox Route124_Text_JennyPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE, Route124_Text_GraceIntro, Route124_Text_GraceDefeat
	msgbox Route124_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD, Route124_Text_ChadIntro, Route124_Text_ChadDefeat
	msgbox Route124_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Lila::
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaIntro, Route124_Text_LilaDefeat, Route124_Text_LilaNotEnoughMons, Route124_EventScript_RegisterLila
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchLila
	msgbox Route124_Text_LilaPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterLila::
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_RematchLila::
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaRematchIntro, Route124_Text_LilaRematchDefeat, Route124_Text_LilaRematchNotEnoughMons
	msgbox Route124_Text_LilaPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roy::
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyIntro, Route124_Text_RoyDefeat, Route124_Text_RoyNotEnoughMons, Route124_EventScript_RegisterRoy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchRoy
	msgbox Route124_Text_RoyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterRoy::
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_RematchRoy::
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyRematchIntro, Route124_Text_RoyRematchDefeat, Route124_Text_RoyRematchNotEnoughMons
	msgbox Route124_Text_RoyPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Declan::
	trainerbattle_single TRAINER_DECLAN, Route124_Text_DeclanIntro, Route124_Text_DeclanDefeat
	msgbox Route124_Text_DeclanPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Isabella::
	trainerbattle_single TRAINER_ISABELLA, Route124_Text_IsabellaIntro, Route124_Text_IsabellaDefeat
	msgbox Route124_Text_IsabellaPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_Text_HuntersHouse:
	.string "HUNTER's HOUSE$"

