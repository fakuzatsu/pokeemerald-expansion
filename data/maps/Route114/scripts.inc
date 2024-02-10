Route114_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, Route114_OnResume
	.byte 0

Route114_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route114_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route114_OnResume_Day
	end

Route114_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	setflag FLAG_HIDE_TRAINER_NIGHT
	end

Route114_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	end

Route114_OnTransition:
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	goto_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, AbnormalWeather_StartGroudonWeather
	goto_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, AbnormalWeather_StartGroudonWeather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route114_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route114_OnTransition_Day
	end

Route114_OnTransition_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	clearflag FLAG_HIDE_TRAINER_NIGHT
	end

Route114_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute114North
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute114South
	end

Route114_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route114_EventScript_Man::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_114_RECEIVED_BERRY, Route114_EventScript_ReceivedBerry
	msgbox Route114_Text_LoveUsingBerryCrushShareBerry, MSGBOX_DEFAULT
	random NUM_ROUTE_114_MAN_BERRIES
	addvar VAR_RESULT, NUM_ROUTE_114_MAN_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_114_RECEIVED_BERRY
	msgbox Route114_Text_TryBerryCrushWithFriends, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_ReceivedBerry::
	msgbox Route114_Text_FunToThinkAboutBerries, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RoarGentleman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ROAR, Route114_EventScript_ReceivedRoar
	msgbox Route114_Text_AllMyMonDoesIsRoarTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROAR
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_ReceivedRoar::
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
	msgbox Route114_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route114_EventScript_MeteorFallsSign::
	msgbox Route114_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route114_EventScript_FossilManiacsHouseSign::
	msgbox Route114_Text_FossilManiacsHouseSign, MSGBOX_SIGN
	end

Route114_EventScript_LanettesHouseSign::
	msgbox Route114_Text_LanettesHouse, MSGBOX_SIGN
	end

Route114_EventScript_Lenny::
	trainerbattle_single TRAINER_LENNY, Route114_Text_LennyIntro, Route114_Text_LennyDefeat
	msgbox Route114_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Lucas::
	trainerbattle_single TRAINER_LUCAS_1, Route114_Text_LucasIntro, Route114_Text_LucasDefeat
	msgbox Route114_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Shane::
	trainerbattle_single TRAINER_SHANE, Route114_Text_ShaneIntro, Route114_Text_ShaneDefeat
	msgbox Route114_Text_ShanePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Nancy::
	trainerbattle_single TRAINER_NANCY, Route114_Text_NancyIntro, Route114_Text_NancyDefeat
	msgbox Route114_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Steve::
	trainerbattle_single TRAINER_STEVE_1, Route114_Text_SteveIntro, Route114_Text_SteveDefeat, Route114_EventScript_RegisterSteve
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_RematchSteve
	msgbox Route114_Text_StevePostBattle, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RegisterSteve::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route114_Text_SteveRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_STEVE_1
	release
	end

Route114_EventScript_RematchSteve::
	trainerbattle_rematch TRAINER_STEVE_1, Route114_Text_SteveRematchIntro, Route114_Text_SteveRematchDefeat
	msgbox Route114_Text_StevePostRematch, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Bernie::
	trainerbattle_single TRAINER_BERNIE_1, Route114_Text_BernieIntro, Route114_Text_BernieDefeat, Route114_EventScript_RegisterBernie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_RematchBernie
	msgbox Route114_Text_BerniePostBattle, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RegisterBernie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route114_Text_BernieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BERNIE_1
	release
	end

Route114_EventScript_RematchBernie::
	trainerbattle_rematch TRAINER_BERNIE_1, Route114_Text_BernieRematchIntro, Route114_Text_BernieRematchDefeat
	msgbox Route114_Text_BerniePostRematch, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Claude::
	trainerbattle_single TRAINER_CLAUDE, Route114_Text_ClaudeIntro, Route114_Text_ClaudeDefeat
	msgbox Route114_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Nolan::
	trainerbattle_single TRAINER_NOLAN, Route114_Text_NolanIntro, Route114_Text_NolanDefeat
	msgbox Route114_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Tyra::
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_TyraIntro, Route114_Text_TyraDefeat, Route114_Text_TyraNotEnoughMons
	msgbox Route114_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Ivy::
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_IvyIntro, Route114_Text_IvyDefeat, Route114_Text_IvyNotEnoughMons
	msgbox Route114_Text_IvyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Angelina::
	trainerbattle_single TRAINER_ANGELINA, Route114_Text_AngelinaIntro, Route114_Text_AngelinaDefeat
	msgbox Route114_Text_AngelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Charlotte::
	trainerbattle_single TRAINER_CHARLOTTE, Route114_Text_CharlotteIntro, Route114_Text_CharlotteDefeat
	msgbox Route114_Text_CharlottePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Kai::
	trainerbattle_single TRAINER_KAI, Route114_Text_KaiIntro, Route114_Text_KaiDefeat
	msgbox Route114_Text_KaiPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Bruno::
	lock
	goto_if_gt VAR_0x8005, 100, Route114_EventScript_GiveTemporaryStoredItem
	goto_if_set FLAG_SYS_GAME_CLEAR, Route114_EventScript_BrunoPostGame
	checkitem ITEM_TM60
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_BrunoAfterBattle
	msgbox Route114_Text_BrunoIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route114_EventScript_RefuseBruno
	trainerbattle_no_intro TRAINER_BRUNO, Route114_Text_BrunoDefeat
Route114_EventScript_GiveDrainPunch::
	msgbox Route114_Text_BrunoPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_TM60
	msgbox Route114_Text_ThatTMContainsDrainPunch, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_BrunoAfterBattle::
	msgbox Route114_Text_BrunoAfterBattle, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RefuseBruno::
	msgbox Route114_Text_RefuseBruno, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_BrunoPostGame::
	goto_if_set FLAG_BRUNO_POSTGAME_BATTLE, Route114_EventScript_BrunoAfterBattle
	msgbox Route114_Text_BrunoPostGame, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route114_EventScript_RefuseBrunoPostGame
	trainerbattle_no_intro TRAINER_BRUNO_POSTGAME, Route114_Text_BrunoPostGameDefeat
	setflag FLAG_BRUNO_POSTGAME_BATTLE
	checkitem ITEM_TM60
	goto_if_eq VAR_RESULT, FALSE, Route114_EventScript_GiveDrainPunch
	msgbox Route114_Text_BrunoPostBattle, MSGBOX_DEFAULT
	checkitem ITEM_FIGHTINIUM_Z
	goto_if_eq VAR_RESULT, FALSE, Route114_EventScript_GiveFightiniumZ
Route114_EventScript_GiveNugget::
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route114_EventScript_BagFullStoreNuggetTemp
	msgbox Route114_Text_BrunoAfterBattle, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_BagFullStoreNuggetTemp::
	msgbox Route114_Text_OhYourBagIsFull, MSGBOX_DEFAULT
	setvar VAR_0x8005, ITEM_NUGGET
	release
	end

Route114_EventScript_RefuseBrunoPostGame::
	msgbox Route114_Text_RefuseBrunoPostGame, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_GiveFightiniumZ::
	giveitem ITEM_FIGHTINIUM_Z
	goto_if_eq VAR_RESULT, FALSE, Route114_EventScript_BagFullStoreFightiniumZTemp
	msgbox Route114_Text_ThatsFightiniumZ, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_BagFullStoreFightiniumZTemp::
	msgbox Route114_Text_OhYourBagIsFull, MSGBOX_DEFAULT
	setvar VAR_0x8005, ITEM_FIGHTINIUM_Z
	release
	end

Route114_EventScript_GiveTemporaryStoredItem::
	msgbox Route114_Text_HereTakeThis, MSGBOX_DEFAULT
	goto_if_eq VAR_0x8005, ITEM_PRETTY_FEATHER, Route114_EventScript_GiveNugget
	goto_if_eq VAR_0x8005, ITEM_FLYINIUM_Z, Route114_EventScript_GiveFightiniumZ
	end

Route114_Text_AllMyMonDoesIsRoarTakeThis:
	.string "All my Pokémon does is ROAR…\n"
	.string "No one dares to come near me…\p"
	.string "Sigh… If you would, please take\n"
	.string "this TM away…$"

Route114_Text_ExplainRoar:
	.string "TM05 contains ROAR.\n"
	.string "A ROAR sends Pokémon scurrying.$"

Route114_Text_Poochyena:
	.string "Bow! Bowwow!$"

Route114_Text_MeteorFallsSign:
	.string "METEOR FALLS\n"
	.string "RUSTBORO CITY THROUGH HERE$"

Route114_Text_FossilManiacsHouseSign:
	.string "FOSSIL MANIAC's HOUSE\n"
	.string "“Fossils gratefully accepted!”$"

Route114_Text_LanettesHouse:
	.string "Lanette's HOUSE$"

Route114_Text_BrunoIntro:
	.string "I am Bruno. As one of the elites of\n"
	.string "the Kanto and Johto regions, I must\l"
	.string "always train rigorously.\p"
	.string "Even when I travel to train my pupils,\n"
	.string "I remain vigilant with my own training.\p"
	.string "So what was it? Did you want to be\n"
	.string "ground down by our superior power?$"

Route114_Text_BrunoDefeat:
	.string "Why?! …How could we lose?$"

Route114_Text_BrunoPostBattle:
	.string "Having lost, I have no right to say\n"
	.string "anything more.\p"
	.string "Take this.$"

Route114_Text_ThatTMContainsDrainPunch:
	.string "That TM contains the move Drain Punch.\p"
	.string "A powerful hook that steals fortitude\n"
	.string "from your opponent.$"

Route114_Text_BrunoAfterBattle:
	.string "Having lost, I have no right to say\n"
	.string "anything more.$"

Route114_Text_RefuseBruno:
	.string "Through rigorous training, you too\n"
	.string "can become stronger.\p"
	.string "Come back when you think you have\n"
	.string "reached your limit, and I will show\l"
	.string "you how to go further.$"

Route114_Text_BrunoPostGame:
	.string "So you've come…\p"
	.string "You who have defeated the Hoenn Elites\n"
	.string "show me the depths of your power so\l"
	.string "that we might both become stronger.$"

Route114_Text_BrunoPostGameDefeat:
	.string "… … …\p"
	.string "…How could we lose?$"

Route114_Text_RefuseBrunoPostGame:
	.string "You must understand the real power of\n"
	.string "the Indigo Elites!\p"
	.string "…But you can't build yourself stronger\n"
	.string "without first being ground down.\p"
	.string "Come back when you are ready to learn\n"
	.string "how that feels.$"

Route114_Text_ThatsFightiniumZ:
	.string "That stone you now hold…\p"
	.string "With it, a Pokémon can unleash a killer\n"
	.string "blow, likely to knock out its opponent.$"

Route114_Text_OhYourBagIsFull:
	.string "… … …\p"
	.string "Seems you need to make some space\n"
	.string "in your bag.$"

Route114_Text_HereTakeThis:
	.string "Here take this.$"
