.set LOCALID_STEVEN, 13
.set LOCALID_WINONA, 12
.set LOCALID_LITTLEBOY, 11
.set LOCALID_AMAZEDBOY, 10
.set LOCALID_LADY, 9
.set LOCALID_SHOCKEDWOMAN, 8

FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnResume_Night:
	setweather WEATHER_SHADE
	setflag FLAG_HIDE_TRAINER_NIGHT
	return

FortreeCity_OnResume_Day:
	setweather WEATHER_SUNNY
	return

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, FortreeCity_OnResume_Night
	goto_if_eq VAR_RESULT, 0, FortreeCity_OnTransition_Day
	end

FortreeCity_OnTransition_Day:
	setweather WEATHER_SUNNY
	clearflag FLAG_HIDE_TRAINER_NIGHT
	return

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, FortreeCity_OnResume_Night
	goto_if_eq VAR_RESULT, 0, FortreeCity_OnResume_Day
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

@needs changed use this flag for the man
FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

@change to complain about the Kecleon
FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_EventScript_MegaCutsceneTrigger::
	lockall
	playbgm MUS_CONTEST_LOBBY, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, FortreeCity_Movement_PlayerTakePlace
	waitmovement 0
	applymovement LOCALID_SHOCKEDWOMAN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LOCALID_SHOCKEDWOMAN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox FortreeCity_Text_IsItTrue, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WINONA, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox FortreeCity_Text_ThatsRight, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEBOY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_LITTLEBOY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox FortreeCity_Text_WowSoCool, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WINONA, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox FortreeCity_Text_RemainEnthused, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadedefaultbgm
	applymovement LOCALID_WINONA, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	removeobject LOCALID_WINONA
	playse SE_DOOR
	waitse
	applymovement LOCALID_LADY, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_LADY, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox FortreeCity_Text_MegaEvolutionHuh, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LITTLEBOY
	removeobject LOCALID_AMAZEDBOY
	removeobject LOCALID_SHOCKEDWOMAN
	removeobject LOCALID_LADY
	setflag FLAG_HIDE_WINONA_CUSTSCENE_ACTORS
	fadescreen FADE_FROM_BLACK
	setvar VAR_FORTREE_CITY_STATE, 1
	goto FortreeCity_EventScript_MegaCutsceneSteven
	end

FortreeCity_EventScript_MegaCutsceneSteven::
	addobject LOCALID_STEVEN
	setobjectxy LOCALID_STEVEN, 29, 14
	applymovement LOCALID_STEVEN, FortreeCity_Movement_StevenApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox FortreeCity_Text_YouSawThatTooHuh, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox FortreeCity_Text_YouShouldBattleWinona, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, FortreeCity_Movement_StevenDepart
	waitmovement 0
	removeobject LOCALID_STEVEN
	releaseall
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Movement_PlayerTakePlace:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

FortreeCity_Movement_StevenApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

FortreeCity_Movement_StevenDepart:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "No one believes me, but I saw this\n"
	.string "gigantic Pokémon in the sky.\p"
	.string "It seemed to squirm as it flew toward\n"
	.string "ROUTE 131.\p"
	.string "By the way… Sniff…\n"
	.string "Um… You, uh…smell singed.\p"
	.string "Were you at a volcano or something?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "I want to go to the Pokémon GYM,\n"
	.string "but something's blocking the way.\p"
	.string "After all the bother I went through\n"
	.string "training on ROUTE 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "I've got my pride-and-joy Pokémon\n"
	.string "with me. This time, I'll beat WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "The ground absorbs rainwater, and\n"
	.string "trees grow by drinking that water…\p"
	.string "Our FORTREE CITY exists because\n"
	.string "there's both water and soil.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "The CITY consists of homes built on\n"
	.string "trees.\p"
	.string "Perhaps because of that lifestyle,\n"
	.string "everyone is healthy and lively.\p"
	.string "Why, even myself--I feel as if I've\n"
	.string "grown thirty years younger.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Living on top of trees is okay.\p"
	.string "But sometimes BUG Pokémon come in\n"
	.string "through windows.\l"
	.string "It can be really startling.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "There are Pokémon that evolve when\n"
	.string "you trade them! That's what I heard.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Something unseeable is in the way.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible Pokémon became completely\n"
	.string "visible!\p"
	.string "The startled Pokémon fled!$"

FortreeCity_Text_CitySign:
	.string "FORTREE CITY\n"
	.string "“The treetop city that frolics with\l"
	.string "nature.”$"

FortreeCity_Text_GymSign:
	.string "FORTREE CITY Pokémon GYM\n"
	.string "Leader: WINONA\p"
	.string "“The bird user taking flight into\n"
	.string "the world.”$"

FortreeCity_Text_IsItTrue:
	.string "Is it true lady Winona?\p"
	.string "That you have a brand new power?$"

FortreeCity_Text_ThatsRight:
	.string "WINONA: That's right!\p"
	.string "By the grace of the Pokémon\n"
	.string "League, we have unlocked the\l"
	.string "potential of Trainers and\l"
	.string "Pokémon working in tandem!\p"
	.string "With these mysterious stones, we can\n"
	.string "unlock further evolution potential\l"
	.string "with the trust of our companions!\p"
	.string "With the power of our bonds we will\n"
	.string "unleash Mega Evolution!\p"
	.string "Together!\p"
	.string "My BIRD Pokémon and I will soar\n"
	.string "to the very heavens!$"

FortreeCity_Text_WowSoCool:
	.string "That's so cool!$"

FortreeCity_Text_RemainEnthused:
	.string "WINONA: I hope that we can share this\n"
	.string "power with all Trainers and Pokémon\p"
	.string "So that we all may soar together!\p"
	.string "Please look forward to that future!$"

FortreeCity_Text_MegaEvolutionHuh:
	.string "Mega Evolution huh?\n"
	.string "That sounds awesome!\p"
	.string "I wonder what it's like…$"

FortreeCity_Text_YouSawThatTooHuh:
	.string "STEVEN: Greetings, {PLAYER}.\p"
	.string "I saw you coming as Winona gave\n"
	.string "her speech.\p"
	.string "It seems that Prof. Cosmo isn't\n"
	.string "the only one who discovered the\l"
	.string "power of the Mega Stones.\p"
	.string "The Pokémon League must have found\n"
	.string "and researched some too…$"

FortreeCity_Text_YouShouldBattleWinona:
	.string "…Perhaps you should challenge the\n"
	.string "gym here and see how your own\l"
	.string "power compares.\p"
	.string "In the meanwhile, I will be exploring\n"
	.string "an interesting phenomena on Route 120.\p"
	.string "We should meet again on Route 120\n"
	.string "after you have battled Winona!\p"
	.string "…Until then {PLAYER}!$"

