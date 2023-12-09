.set LOCALID_LORNA, 1

PetalburgGrove_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgGrove_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PetalburgGrove_OnResume
	.byte 0

PetalburgGrove_OnTransition:
	call_if_set FLAG_DEFEATED_TRAINER_LORNA, PetalburgGrove_EventScript_MoveLorna
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, PetalburgGrove_OnResume_Night
	goto_if_eq VAR_RESULT, 0, PetalburgGrove_OnResume_Day
	end

PetalburgGrove_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, PetalburgGrove_OnResume_Night
	goto_if_eq VAR_RESULT, 0, PetalburgGrove_OnResume_Day
	end

PetalburgGrove_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	goto_if_set FLAG_DEFEATED_TRAINER_LORNA, PetalburgGrove_EventScript_DisableTrigger
	end

PetalburgGrove_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	goto_if_set FLAG_DEFEATED_TRAINER_LORNA, PetalburgGrove_EventScript_DisableTrigger
	end

PetalburgGrove_EventScript_DisableTrigger::
	setvar VAR_TEMP_0, 1
	end

PetalburgGrove_EventScript_MoveLorna::
	setobjectxyperm LOCALID_LORNA, 12, 15
	return

PetalburgGrove_EventScript_LornaStopPlayerTrigger::
	goto_if_unset FLAG_DEFEATED_TRAINER_LORNA, PetalburgGrove_EventScript_LornaStopPlayerTriggerGo
	releaseall
	end

PetalburgGrove_EventScript_LornaStopPlayerTriggerGo::
	lockall
	setvar VAR_0x8008, 2
	playse SE_PIN
	applymovement LOCALID_LORNA, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	applymovement LOCALID_LORNA, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PetalburgGrove_EventScript_LornaStopPlayer
	end

PetalburgGrove_EventScript_LornaStopPlayerTalk::
	lockall
	faceplayer
	setvar VAR_0x8008, 1
	goto PetalburgGrove_EventScript_LornaStopPlayer
	end

PetalburgGrove_EventScript_LornaStopPlayer::
	call_if_eq VAR_MAUVILLE_FLOWER_SHOP_STATE, 0, MauvilleCity_FlowerShop_EventScript_SetQuestAvailable
	goto_if_set FLAG_DEFEATED_TRAINER_LORNA, PetalburgGrove_EventScript_YoureStrongYouCanGoThrough
	msgbox PetalburgGrove_Text_HeyWait, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 2, PetalburgGrove_EventScript_LornaPushPlayerBack
	msgbox PetalburgGrove_Text_ItsDangerousUpAhead, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgGrove_EventScript_AreYouSure
	goto_if_eq VAR_RESULT, NO, PetalburgGrove_EventScript_DontBattleLorna
	end

PetalburgGrove_EventScript_LornaPushPlayerBack::
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgGrove_Movement_PlayerPushedBack
	applymovement LOCALID_LORNA, PetalburgGrove_Movement_LornaStepInTheWay
	waitmovement 0
	return

PetalburgGrove_EventScript_AreYouSure::
	msgbox PetalburgGrove_Text_AreYouSureAboutThis, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgGrove_EventScript_BattleLorna
	goto_if_eq VAR_RESULT, NO, PetalburgGrove_EventScript_DontBattleLorna
	end

PetalburgGrove_EventScript_BattleLorna::
	msgbox PetalburgGrove_Text_LornaIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_SHIRLEY, PetalburgGrove_Text_LornaDefeat
	setflag FLAG_DEFEATED_TRAINER_LORNA
	goto_if_ge VAR_MAUVILLE_FLOWER_SHOP_STATE, 2, PetalburgGrove_EventScript_HuhFlowerShopAfterBattle
	goto PetalburgGrove_EventScript_YoureStrongYouCanGoThrough
	end

PetalburgGrove_EventScript_DontBattleLorna::
	msgbox PetalburgGrove_Text_ProbablyForTheBest, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 2, PetalburgGrove_EventScript_LornaMoveBackIntoPlace
	releaseall
	end

PetalburgGrove_EventScript_YoureStrongYouCanGoThrough::
	goto_if_ge VAR_MAUVILLE_FLOWER_SHOP_STATE, 2, PetalburgGrove_EventScript_HuhFlowerShop
	msgbox PetalburgGrove_Text_YoureStrongYouCanGoThrough, MSGBOX_DEFAULT
	releaseall
	end

PetalburgGrove_EventScript_LornaMoveBackIntoPlace::
	applymovement LOCALID_LORNA, PetalburgGrove_Movement_LornaMoveBackIntoPlace
	waitmovement 0
	return

PetalburgGrove_EventScript_HuhFlowerShop::
	msgbox PetalburgGrove_Text_HuhFlowerShop, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LORNA
	setvar VAR_MAUVILLE_FLOWER_SHOP_STATE, 3
	setflag FLAG_LORNA_MOVED_TO_SHOP
	delay 16
	fadescreen FADE_FROM_BLACK
	releaseall
	end

PetalburgGrove_EventScript_HuhFlowerShopAfterBattle::
	msgbox PetalburgGrove_Text_YoureStrongYouCanGoThrough, MSGBOX_DEFAULT
	goto PetalburgGrove_EventScript_HuhFlowerShop

PetalburgGrove_Movement_PlayerPushedBack:
	walk_in_place_faster_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_up
	step_end

PetalburgGrove_Movement_LornaStepInTheWay:
	walk_left
	walk_in_place_faster_down
	step_end

PetalburgGrove_Movement_LornaMoveBackIntoPlace:
	walk_right
	walk_in_place_faster_down
	step_end

PetalburgGrove_Text_HeyWait:
	.string "Hey wait!$"

PetalburgGrove_Text_ItsDangerousUpAhead:
	.string "It's dangerous up ahead!\p"
	.string "I've seen some very mysterious\n"
	.string "Pokémon!\p"
	.string "… … …\p"
	.string "If you want to pass I'll have to\n"
	.string "make sure you are strong!\p"
	.string "Will you battle me to prove\n"
	.string "you that can handle the woods?$"

PetalburgGrove_Text_AreYouSureAboutThis:
	.string "The Pokémon in the woods are\n"
	.string "very strong!\p"
	.string "… … …\n"
	.string "I'm strong too!\p"
	.string "Are you sure about this?$"

PetalburgGrove_Text_LornaIntro:
	.string "Alright then! show me what you\n"
	.string "can do!$"

PetalburgGrove_Text_LornaDefeat:
	.string "Oh!\n"
	.string "You're very strong!$"

PetalburgGrove_Text_ProbablyForTheBest:
	.string "Right. That's probably for\n"
	.string "the best.\p"
	.string "Come back when you feel like\n"
	.string "you are get a bit stronger.$"

PetalburgGrove_Text_YoureStrongYouCanGoThrough:
	.string "You should be able to handle\n"
	.string "anything you find beyond here.\p"
	.string "Go ahead!$"

PetalburgGrove_Text_HuhFlowerShop:
	.string "Oh… huh?\p"
	.string "What's this about going to a\n"
	.string "new flower shop in Mauville?\p"
	.string "… … …\p"
	.string "It does sound interesting…\p"
	.string "Hm… sure!\n"
	.string "It couldn't hurt I guess.\p"
	.string "Not many can make it over that\n"
	.string "pond anyways.$"

