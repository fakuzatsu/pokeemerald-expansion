Route126_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route126_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route126_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Route126_OnResume
	.byte 0

Route126_OnResume_Night:
	setweather WEATHER_RAIN
	return

Route126_OnResume_Day:
	setweather WEATHER_SUNNY
	return

Route126_OnResume:
	goto_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route126_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route126_OnResume_Day
	end

Route126_OnTransition:
	goto_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route126_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route126_OnResume_Day
	end

Route126_EventScript_Barry::
	trainerbattle_single TRAINER_BARRY, Route126_Text_BarryIntro, Route126_Text_BarryDefeat
	msgbox Route126_Text_BarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN, Route126_Text_DeanIntro, Route126_Text_DeanDefeat
	msgbox Route126_Text_DeanPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Nikki::
	trainerbattle_single TRAINER_NIKKI, Route126_Text_NikkiIntro, Route126_Text_NikkiDefeat
	msgbox Route126_Text_NikkiPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Brenda::
	trainerbattle_single TRAINER_BRENDA, Route126_Text_BrendaIntro, Route126_Text_BrendaDefeat
	msgbox Route126_Text_BrendaPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Leonardo::
	trainerbattle_single TRAINER_LEONARDO, Route126_Text_LeonardoIntro, Route126_Text_LeonardoDefeat
	msgbox Route126_Text_LeonardoPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Isobel::
	trainerbattle_single TRAINER_ISOBEL, Route126_Text_IsobelIntro, Route126_Text_IsobelDefeat
	msgbox Route126_Text_IsobelPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Sienna::
	trainerbattle_single TRAINER_SIENNA, Route126_Text_SiennaIntro, Route126_Text_SiennaDefeat
	msgbox Route126_Text_SiennaPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Pablo::
	trainerbattle_single TRAINER_PABLO_1, Route126_Text_PabloIntro, Route126_Text_PabloDefeat, Route126_EventScript_RegisterPablo
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route126_EventScript_RematchPablo
	msgbox Route126_Text_PabloPostBattle, MSGBOX_DEFAULT
	release
	end

Route126_EventScript_RegisterPablo::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route126_Text_PabloRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PABLO_1
	release
	end

Route126_EventScript_RematchPablo::
	trainerbattle_rematch TRAINER_PABLO_1, Route126_Text_PabloRematchIntro, Route126_Text_PabloRematchDefeat
	msgbox Route126_Text_PabloPostRematch, MSGBOX_AUTOCLOSE
	end

