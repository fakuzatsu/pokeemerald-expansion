.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MossdeepCity_OnResume
	.byte 0

MossdeepCity_OnResume_Night:
	setweather WEATHER_SHADE
	setflag FLAG_HIDE_TRAINER_NIGHT
	return

MossdeepCity_OnResume_Day:
	setweather WEATHER_SUNNY
	return

MossdeepCity_OnResume:
	goto_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, MossdeepCity_OnResume_Night
	goto_if_eq VAR_RESULT, 0, MossdeepCity_OnResume_Day
	end

MossdeepCity_OnTransition:
	goto_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, MossdeepCity_OnResume_Night
	goto_if_eq VAR_RESULT, 0, MossdeepCity_OnTransition_Day
	end

MossdeepCity_OnTransition_Day:
	setweather WEATHER_SUNNY
	clearflag FLAG_HIDE_TRAINER_NIGHT
	return

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_HyperTrainer::
	lockall
	msgbox MossdeepCity_Text_HyperTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_EventScript_HyperTrainerCheckBottleCaps
MossdeepCity_EventScript_DeclineHyperTrain::
	msgbox MossdeepCity_Text_RejectHyperTrainer, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_EventScript_HyperTrainerCheckBottleCaps::
	setvar VAR_0x8008, 0
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_EventScript_HyperTrainWhichPokemon
	setvar VAR_0x8008, 1
	checkitem ITEM_GOLD_BOTTLE_CAP
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_EventScript_HyperTrainWhichPokemon
	msgbox MossdeepCity_Text_NoBottleCapsForHyperTrainer, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_EventScript_HyperTrainWhichPokemon::
	msgbox MossdeepCity_Text_HyperTrainWhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, MossdeepCity_EventScript_WhichBottleCapHyperTrain
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MossdeepCity_EventScript_DeclineHyperTrain
	end

MossdeepCity_EventScript_WhichBottleCapHyperTrain::
	specialvar VAR_RESULT, CheckIfPokemonIsFullyTrained
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_EventScript_ThisPokemonCanLearnNoMore
	goto_if_eq VAR_0x8008, 1, MossdeepCity_EventScript_GoldBottleCapPrepareHyperTrain
	checkitem ITEM_GOLD_BOTTLE_CAP
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_EventScript_BothBottleCapsHyperTrain
	goto MossdeepCity_EventScript_RegularBottleCapPrepareHyperTrain
	end

MossdeepCity_EventScript_RegularBottleCapPrepareHyperTrain::
	msgbox MossdeepCity_Text_WhichStatToTrain, MSGBOX_DEFAULT
	special ScriptMenu_CreateHyperTrainingMultichoice
	waitstate
	goto MossdeepCity_EventScript_DoStatInput
	end

MossdeepCity_EventScript_DoStatInput::
	switch VAR_RESULT
	case 0, MossdeepCity_EventScript_RegularBottleCapDoHyperTrain
	case 1, MossdeepCity_EventScript_RegularBottleCapDoHyperTrain
	case 2, MossdeepCity_EventScript_RegularBottleCapDoHyperTrain
	case 3, MossdeepCity_EventScript_RegularBottleCapDoHyperTrain
	case 4, MossdeepCity_EventScript_RegularBottleCapDoHyperTrain
	case 5, MossdeepCity_EventScript_RegularBottleCapDoHyperTrain
	case MULTI_B_PRESSED, MossdeepCity_EventScript_DeclineHyperTrain
	end

MossdeepCity_EventScript_GoldBottleCapPrepareHyperTrain::
	msgbox MossdeepCity_Text_UseGoldCapIsThisOk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_EventScript_GoldBottleCapDoHyperTrain
	goto MossdeepCity_EventScript_DeclineHyperTrain
	end

MossdeepCity_EventScript_BothBottleCapsHyperTrain::
    message MossdeepCity_Text_WhichCapToUse
	waitmessage
	multichoice 16, 6, MULTI_CHOOSE_BOTTLE_CAP, FALSE
	switch VAR_RESULT
	case 0, MossdeepCity_EventScript_RegularBottleCapPrepareHyperTrain
	case 1, MossdeepCity_EventScript_GoldBottleCapDoHyperTrain
	case 2, MossdeepCity_EventScript_DeclineHyperTrain
	case MULTI_B_PRESSED, MossdeepCity_EventScript_DeclineHyperTrain
	end

MossdeepCity_EventScript_GoldBottleCapDoHyperTrain::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	bufferspeciesname STR_VAR_1, VAR_RESULT
	msgbox MossdeepCity_Text_HyperTrainerOkLetsDoThis, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_Text_PokemonWasHyperTrained
	waitmessage
	waitfanfare
	special DoGoldHyperTraining
	removeitem ITEM_GOLD_BOTTLE_CAP
	fadescreen FADE_FROM_BLACK
	goto MossdeepCity_EventScript_HyperTrainingFinished
	end

MossdeepCity_EventScript_RegularBottleCapDoHyperTrain::
	special DoRegularHyperTraining
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	bufferspeciesname STR_VAR_1, VAR_RESULT
	msgbox MossdeepCity_Text_HyperTrainerOkLetsDoThis, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_Text_PokemonWasHyperTrained
	waitmessage
	waitfanfare
	removeitem ITEM_BOTTLE_CAP
	fadescreen FADE_FROM_BLACK
	goto MossdeepCity_EventScript_HyperTrainingFinished
	end

MossdeepCity_EventScript_HyperTrainingFinished::
	msgbox MossdeepCity_Text_HyperTrainerFinished, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_EventScript_ThisPokemonCanLearnNoMore::
	msgbox MossdeepCity_Text_ThisPokemonCanLearnNoMore, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "I got this from STEVEN, but I don't\n"
	.string "know what it's good for.\p"
	.string "I think it's called KING's ROCK.\n"
	.string "Do you want it?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Why would you want it?\n"
	.string "You're weird.\p"
	.string "You can keep it, but keep it a secret\n"
	.string "from STEVEN.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "STEVEN's house is right over there!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Yeah, you think so, too! What are you\n"
	.string "supposed to do with some weird rock?$"

MossdeepCity_Text_WailmerWatching:
	.string "Around MOSSDEEP, you can see wild\n"
	.string "WAILMER.\p"
	.string "It's called, uh…\n"
	.string "What was it now…\p"
	.string "WAI, WAI, WAI…\p"
	.string "WAILMER watching!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.\p"
	.string "There's been some kind of an uproar\n"
	.string "over a letter they received recently.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "I heard from a Sailor buddy that\n"
	.string "Team Aqua set up shop in LILYCOVE.\p"
	.string "I also heard that someone came along\n"
	.string "and wiped the floor with them!\p"
	.string "But MOSSDEEP here's been targeted\n"
	.string "by that Team Magma.\p"
	.string "If you want to know what they're up to,\n"
	.string "go visit the SPACE CENTER.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "I'm a Sailor, so the sea's obviously\n"
	.string "more important to me.\p"
	.string "But you know? When I get back on land\n"
	.string "after a long voyage, I do feel relief!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Wouldn't it be nice?\p"
	.string "If the whole world was covered in\n"
	.string "plants and flowers like this island?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "All life needs the sea to live, even\n"
	.string "though it makes its home on the land.\p"
	.string "Life, having run its course, becomes\n"
	.string "soil and returns to the land.\p"
	.string "And the sea is always connected to\n"
	.string "the land.\p"
	.string "Yes, like the very shoreline here.$"

MossdeepCity_Text_SurfExhilarating:
	.string "A voyage on a ship is fine.\p"
	.string "But crossing the sea with Pokémon\n"
	.string "using SURF…\p"
	.string "Now that's an exhilarating trip!\n"
	.string "Wouldn't you agree, youngster?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "This rock has a special meaning to\n"
	.string "the people at the SPACE CENTER.\p"
	.string "They put it here as their wish for\n"
	.string "their rockets to fly safely.\p"
	.string "When you make a wish, what do you use?\n"
	.string "Do you wish upon a star?\p"
	.string "I use a wish tag to make it happen.\n"
	.string "That's what I do.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "It's a white rock.$"

MossdeepCity_Text_GymSign:
	.string "MOSSDEEP CITY Pokémon Gym\n"
	.string "Leaders: LIZA & TATE\p"
	.string "“The mystic combination!”$"

MossdeepCity_Text_CitySign:
	.string "MOSSDEEP CITY\n"
	.string "“Our slogan: Cherish Pokémon!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "MOSSDEEP SPACE CENTER\n"
	.string "“The closest place to space.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
	.string "I'm doing great!\p"
	.string "I'd heard MOSSDEEP's Gym Leader is\n"
	.string "pretty strong, so I decided to come\l"
	.string "take a look-see for myself.\p"
	.string "But there's something wrong about\n"
	.string "this town.\p"
	.string "People are going on about a warning\n"
	.string "letter and the SPACE CENTER…\p"
	.string "I don't think it concerns me in any\n"
	.string "way, though.$"

MossdeepCity_Text_HyperTrainer:
	.string "I'm training my Pokémon on the\n"
	.string "crashing waves, beneath the stars.\p"
	.string "…What do you say?\p"
	.string "For a Bottle Cap, I'll train your\n"
	.string "Pokémon with my Hyper technique?$"

MossdeepCity_Text_RejectHyperTrainer:
	.string "You know where to find me\n"
	.string "if you change your mind!$"

MossdeepCity_Text_NoBottleCapsForHyperTrainer:
	.string "You don't have any Bottle Caps!\p"
	.string "I'll train your Pokémon in\n"
	.string "exchange for a Bottle Cap.$"

MossdeepCity_Text_HyperTrainWhichMon:
	.string "Which Pokémon should I train?$"

MossdeepCity_Text_WhichCapToUse:
	.string "I'll train a single stat for a\n"
	.string "Bottle Cap or all stats for a\l"
	.string "Golden Cap.$"

MossdeepCity_Text_WhichStatToTrain:
	.string "Which stat do you want me\n"
	.string "to train?$"

MossdeepCity_Text_UseGoldCapIsThisOk:
	.string "I'll train all stats for your\n"
	.string "Golden Cap. Is this ok?$"

MossdeepCity_Text_HyperTrainerOkLetsDoThis:
	.string "Alright!\p"
	.string "Let's do this!$"

MossdeepCity_Text_PokemonWasHyperTrained:
	.string "{PLAYER}'s {STR_VAR_1} recieved\n"
	.string "Hyper training.$"

MossdeepCity_Text_HyperTrainerFinished:
	.string "Huff-puff\p"
	.string "Our training is complete!\n"
	.string "Huff-puff\p"
	.string "Come back with another Cap\n"
	.string "if you want to train again!$"

MossdeepCity_Text_ThisPokemonCanLearnNoMore:
	.string "Oh…\n"
	.string "This Pokémon…\p"
	.string "There is nothing more I can\n"
	.string "teach it!\p"
	.string "It's already perfect!$"

