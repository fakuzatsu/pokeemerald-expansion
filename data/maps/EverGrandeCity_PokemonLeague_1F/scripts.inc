.set LOCALID_NURSE, 1
.set LOCALID_GUARD_1, 3
.set LOCALID_GUARD_2, 4

EverGrandeCity_PokemonLeague_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonLeague_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
	setobjectxyperm LOCALID_GUARD_1, 9, 2
	setobjectxyperm LOCALID_GUARD_2, 10, 2
	return

EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_BattleMaster::
	lock
	faceplayer
	call_if_unset FLAG_SYS_GAME_CLEAR, EverGrandeCity_PokemonLeague_1F_EventScript_BattleMaster_SoCloseNow
	goto Common_EventScript_PkmnCenterBattleMaster
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_BattleMaster_SoCloseNow::
	msgbox EverGrandeCity_PokemonLeague_1F_Text_SoCloseNow
	return

EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_PokemonLeague_1F_EventScript_ExpandedMart
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_ExpandedMart::
	pokemart EverGrandeCity_PokemonLeague_1F_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EverGrandeCity_PokemonLeague_1F_Mart_Pokemart:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
    .2byte ITEM_POTION
    .2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
    .2byte ITEM_REPEL
    .2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
@ Its assumed the player has the remaining badges
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
	lockall
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
	call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
	waitmessage
	delay 120
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	closemessage
	applymovement LOCALID_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
	applymovement LOCALID_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
	waitmovement 0
	delay 10
	playfanfare MUS_OBTAIN_BADGE
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
	waitmessage
	waitfanfare
	closemessage
	copyobjectxytoperm LOCALID_GUARD_1
	copyobjectxytoperm LOCALID_GUARD_2
	setflag FLAG_ENTERED_ELITE_FOUR
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
	playse SE_FAILURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_PokemonLeague_1F_EventScript_WomanTried
	msgbox EverGrandeCity_PokemonLeague_1F_Text_PhewImExhausted, MSGBOX_DEFAULT
	closemessage
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_WomanTried::
	msgbox EverGrandeCity_PokemonLeague_1F_Text_ICouldntHandleThem, MSGBOX_DEFAULT
	closemessage
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_EVERGRANDE_BOTTLECAP_READY, EverGrandeCity_PokemonLeague_1F_EventScript_GiveBottleCap
	msgbox EverGrandeCity_PokemonLeague_1F_Text_ILovePokemonLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GiveBottleCap::
	msgbox EverGrandeCity_PokemonLeague_1F_Text_IncredibleBattles, MSGBOX_DEFAULT
	giveitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, EverGrandeCity_PokemonLeague_1F_EventScript_BagIsFull
	clearflag FLAG_EVERGRANDE_BOTTLECAP_READY
	msgbox EverGrandeCity_PokemonLeague_1F_Text_FightAgainForMore, MSGBOX_DEFAULT
	closemessage
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
	walk_down
	walk_left
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
	walk_down
	walk_right
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
	walk_left
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
	walk_right
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Text_SoCloseNow:
	.string "You're so close now. Let's do this\n"
	.string "one more time, before you become\l"
	.string "the champion…$"

EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges:
	.string "Beyond this point, only those TRAINERS\n"
	.string "who have collected all the Gym Badges\l"
	.string "are permitted to enter.\p"
	.string "Trainer, let us confirm that you have\n"
	.string "all the Gym Badges.$"

EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges:
	.string "You haven't obtained all the Badges.\p"
	.string "If you're bound for the Pokémon\n"
	.string "LEAGUE, you must return with them.$"

EverGrandeCity_PokemonLeague_1F_Text_GoForth:
	.string "Trainer! Believe in yourself and your\n"
	.string "Pokémon, and go forth!$"

EverGrandeCity_PokemonLeague_1F_Text_PhewImExhausted:
	.string "huff-puff!\p"
	.string "I came all the way through Victory Road…\p"
	.string "I'm exhausted!$"

EverGrandeCity_PokemonLeague_1F_Text_ICouldntHandleThem:
	.string "huff-puff!\p"
	.string "The Pokémon League is no joke! I couldn't\n"
	.string "even beat Sidney…$"

EverGrandeCity_PokemonLeague_1F_Text_ILovePokemonLeague:
	.string "Nnn… Roar!\p"
	.string "The Pokémon League is the ultimate\n"
	.string "fighting gauntlet!\p"
	.string "I want to watch some fights!\p"
	.string "Nnn… Roar!\p"
	.string "Fight for me and I'll give you a\n"
	.string "Bottlecap!$"

EverGrandeCity_PokemonLeague_1F_Text_IncredibleBattles:
	.string "Nnn… Roar!\p"
	.string "Your battles!… They were incredible!…\p"
	.string "Here, have this!$"

EverGrandeCity_PokemonLeague_1F_Text_FightAgainForMore:
	.string "…I want to see more battles!\p"
	.string "Fight for me and I'll give you more\n"
	.string "Bottlecaps!$"

