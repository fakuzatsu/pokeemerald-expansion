.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 6

Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route112_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Route112_OnLoad
	.byte 0

Route112_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route112_OnResume_Night
	goto_if_eq VAR_RESULT, 0, Route112_OnResume_Day
	end

Route112_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	setflag FLAG_HIDE_TRAINER_NIGHT
	end

Route112_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	setflag FLAG_HIDE_TRAINER_DAY
	end

Route112_OnTransition:
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route112_OnTransition_Night
	goto_if_eq VAR_RESULT, 0, Route112_OnResume_Day
	end

Route112_OnTransition_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	clearflag FLAG_HIDE_TRAINER_NIGHT
	end

Route112_OnLoad:
	call Grotto_EventScript_GetGrottoWarp
	goto_if_eq VAR_HIDDEN_GROTTO_ROUTE_112, 0, Route112_EventScript_CloseGrotto
	end

Route112_EventScript_CloseGrotto::
	setmetatile 35, 6, METATILE_General_Grass, FALSE
	setmetatile 36, 6, METATILE_General_Grass, FALSE
	return

Route112_EventScript_MagmaGrunts::
	lockall
	delay 40
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Cook::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE112_NPC_TRADE_COMPLETED, Route112_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_APPLIN
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Route112_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route112_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route112_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, Route112_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route112_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_ROUTE112_NPC_TRADE_COMPLETED
	release
	end

Route112_EventScript_DeclineTrade::
	msgbox Route112_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route112_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_TradeCompleted::
	msgbox Route112_Text_ThanksForTheMunchlax, MSGBOX_DEFAULT
	end

Route112_EventScript_Hiker::
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route112_EventScript_RematchTrent
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RegisterTrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRENT_1
	release
	end

Route112_EventScript_RematchTrent::
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry::
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_YouWillTradeWontYou:
	.string "Ho there!\p"
	.string "I'm off-shift looking for Pokémon\n"
	.string "to share my passions!\p"
	.string "Say, do you happen to have a\n"
	.string "MUNCHLAX?\p"
	.string "Would you be willing to TRADE in\n"
	.string "return for my APPLIN?$"

Route112_Text_MonYouTakeCare:
	.string "How exciting!\p"
	.string "{STR_VAR_1}, welcome!\n"
	.string "{STR_VAR_2}, you take care!$"

Route112_Text_ThisIsntAMon:
	.string "Oh. That isn't a {STR_VAR_1}.\p"
	.string "I need a Pokémon like {STR_VAR_1}\n"
	.string "to share in my passion for food!$"

Route112_Text_YouWontTradeMe:
	.string "No? Perhaps I'll never find anyone\n"
	.string "who loves food as much as me…$"

Route112_Text_ThanksForTheMunchlax:
	.string "Thank you for trading me a\n"
	.string "MUNCHLAX!\p"
	.string "I finally found somebody who loves\n"
	.string "my cooking as much as me!$"

Route112_Text_LeaderGoingToAwakenThing:
	.string "Hey, man, is our leader really going\n"
	.string "to awaken that thing?$"

Route112_Text_YeahWeNeedMeteorite:
	.string "Sounds like it, yeah. But I heard\n"
	.string "we need a METEORITE to do it.$"

Route112_Text_OhThatsWhyCrewWentToFallarbor:
	.string "Oh, I get it now. That's why the rest\n"
	.string "of the crew went out to FALLARBOR.$"

Route112_Text_CantLetAnyonePassUntilTheyreBack:
	.string "You got it. And until they come back,\n"
	.string "we're not to let anyone pass, right.$"

Route112_Text_NotEasyToGetBackToLavaridge:
	.string "Eh, I'd like to get to MAUVILLE, but if\n"
	.string "I went down these ledges, it'd be no\l"
	.string "easy matter to get back to LAVARIDGE.$"

Route112_Text_MtChimneyCableCarSign:
	.string "MT. CHIMNEY CABLE CAR\n"
	.string "“A short walk {UP_ARROW} way!”$"

Route112_Text_MtChimneySign:
	.string "MT. CHIMNEY\p"
	.string "“For LAVARIDGE TOWN or the summit,\n"
	.string "please take the CABLE CAR.”$"

Route112_Text_RouteSignLavaridge:
	.string "Route 112\n"
	.string "{LEFT_ARROW} LAVARIDGE TOWN$"

