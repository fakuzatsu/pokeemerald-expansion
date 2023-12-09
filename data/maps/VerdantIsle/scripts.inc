.set LOCALID_LISLA, 1

VerdantIsle_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdantIsle_OnResume
	map_script MAP_SCRIPT_ON_RESUME, VerdantIsle_OnResume
	.byte 0

VerdantIsle_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, VerdantIsle_OnResume_Night
	goto_if_eq VAR_RESULT, 0, VerdantIsle_OnResume_Day
	end

VerdantIsle_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	goto_if_set FLAG_DEFEATED_TRAINER_LISLA, VerdantIsle_EventScript_DisableTrigger
	end

VerdantIsle_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	goto_if_set FLAG_DEFEATED_TRAINER_LISLA, VerdantIsle_EventScript_DisableTrigger
	end

VerdantIsle_EventScript_DisableTrigger::
	setvar VAR_TEMP_0, 1
	end

VerdantIsle_EventScript_LislaTalk::
	lockall
	faceplayer
	call_if_eq VAR_MAUVILLE_FLOWER_SHOP_STATE, 0, MauvilleCity_FlowerShop_EventScript_SetQuestAvailable
	goto_if_set FLAG_DEFEATED_TRAINER_LISLA, VerdantIsle_EventScript_YouCanComeAndGo
	msgbox VerdantIsle_Text_OhYouWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VerdantIsle_EventScript_AreYouSure
	goto_if_eq VAR_RESULT, NO, VerdantIsle_EventScript_DontBattleLisla
	end

VerdantIsle_EventScript_LislaStop1::
	setvar VAR_0x8008, 1
	goto_if_unset FLAG_DEFEATED_TRAINER_LISLA, VerdantIsle_EventScript_LislaStopPlayer
	releaseall
	end

VerdantIsle_EventScript_LislaStop2::
	setvar VAR_0x8008, 2
	goto_if_unset FLAG_DEFEATED_TRAINER_LISLA, VerdantIsle_EventScript_LislaStopPlayer
	releaseall
	end

VerdantIsle_EventScript_LislaStop3::
	setvar VAR_0x8008, 3
	goto_if_unset FLAG_DEFEATED_TRAINER_LISLA, VerdantIsle_EventScript_LislaStopPlayer
	releaseall
	end

VerdantIsle_EventScript_AreYouSure::
	msgbox VerdantIsle_Text_OhUhAreYouSure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VerdantIsle_EventScript_BattleLisla
	goto_if_eq VAR_RESULT, NO, VerdantIsle_EventScript_DontBattleLisla
	end

VerdantIsle_EventScript_BattleLisla::
	msgbox VerdantIsle_Text_LislaIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LISLA, VerdantIsle_Text_LislaDefeat
	setflag FLAG_DEFEATED_TRAINER_LISLA
	setvar VAR_TEMP_0, 1
	goto_if_ge VAR_MAUVILLE_FLOWER_SHOP_STATE, 2, VerdantIsle_EventScript_HuhFlowerShopAfterBattle
	goto VerdantIsle_EventScript_YouCanComeAndGo
	end

VerdantIsle_EventScript_DontBattleLisla::
	msgbox VerdantIsle_Text_OhThankGoodness, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VerdantIsle_EventScript_YouCanComeAndGo::
	goto_if_ge VAR_MAUVILLE_FLOWER_SHOP_STATE, 2, VerdantIsle_EventScript_HuhFlowerShop
	msgbox VerdantIsle_Text_YouCanComeAndGo, MSGBOX_DEFAULT
	releaseall
	end

VerdantIsle_EventScript_LislaStopPlayer::
	applymovement LOCALID_LISLA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LISLA, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox VerdantIsle_Text_OhUhWait, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto_if_eq VAR_0x8008, 1, VerdantIsle_EventScript_LislaResetPlayer1
	goto_if_eq VAR_0x8008, 2, VerdantIsle_EventScript_LislaResetPlayer2
	goto_if_eq VAR_0x8008, 3, VerdantIsle_EventScript_LislaResetPlayer3
	end

VerdantIsle_EventScript_LislaResetPlayer1::
	applymovement LOCALID_LISLA, VerdantIsle_Movement_LislaApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call VerdantIsle_EventScript_LislaYouShouldntGo
	applymovement LOCALID_LISLA, VerdantIsle_Movement_LislaGoesBackToSpot1
	waitmovement 0
	releaseall
	end

VerdantIsle_EventScript_LislaResetPlayer2::
	applymovement LOCALID_LISLA, VerdantIsle_Movement_LislaApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call VerdantIsle_EventScript_LislaYouShouldntGo
	applymovement LOCALID_LISLA, VerdantIsle_Movement_LislaGoesBackToSpot2
	waitmovement 0
	releaseall
	end

VerdantIsle_EventScript_LislaResetPlayer3::
	applymovement LOCALID_LISLA, VerdantIsle_Movement_LislaApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call VerdantIsle_EventScript_LislaYouShouldntGo
	applymovement LOCALID_LISLA, VerdantIsle_Movement_LislaGoesBackToSpot3
	waitmovement 0
	releaseall
	end

VerdantIsle_EventScript_LislaYouShouldntGo::
	msgbox VerdantIsle_Text_YouShouldntGo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LISLA, VerdantIsle_Movement_LislaPullPlayer
	applymovement OBJ_EVENT_ID_PLAYER, VerdantIsle_Movement_PlayerPulled
	waitmovement 0
	msgbox VerdantIsle_Text_ItsMyDuty, MSGBOX_DEFAULT
	closemessage
	return

VerdantIsle_EventScript_HuhFlowerShop::
	msgbox VerdantIsle_Text_HuhFlowerShop, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LISLA
	setvar VAR_MAUVILLE_FLOWER_SHOP_STATE, 3
	setflag FLAG_LISLA_MOVED_TO_SHOP
	delay 16
	fadescreen FADE_FROM_BLACK
	releaseall
	end

VerdantIsle_EventScript_HuhFlowerShopAfterBattle::
	msgbox VerdantIsle_Text_YouCanComeAndGo, MSGBOX_DEFAULT
	goto VerdantIsle_EventScript_HuhFlowerShop

VerdantIsle_Movement_LislaApproachPlayer1:
	walk_down
	walk_in_place_faster_left
	step_end

VerdantIsle_Movement_LislaApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

VerdantIsle_Movement_LislaApproachPlayer3:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

VerdantIsle_Movement_LislaPullPlayer:
	walk_in_place_faster_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

VerdantIsle_Movement_PlayerPulled:
	walk_right
	step_end

VerdantIsle_Movement_LislaGoesBackToSpot1:
	walk_up
	walk_left
	walk_in_place_fast_down
	step_end

VerdantIsle_Movement_LislaGoesBackToSpot2:
	walk_up
	walk_up
	walk_left
	walk_in_place_fast_down
	step_end

VerdantIsle_Movement_LislaGoesBackToSpot3:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_fast_down
	step_end

VerdantIsle_Text_OhYouWantToBattle:
	.string "Oh… uh…\p"
	.string "Hello there…\p"
	.string "…I-I'm in charge of guarding\n"
	.string "this place…\p"
	.string "I'm not supposed to let anybody\n"
	.string "through unless they are strong\l"
	.string "enough to defeat me…\p"
	.string "… … …\p"
	.string "Oh… do y-you want to battle?$"

VerdantIsle_Text_OhUhAreYouSure:
	.string "Um!\p"
	.string "I'm the strongest of my sisters.\n"
	.string "I don't want you to feel bad…\p"
	.string "Are you sure you want to battle?…$"

VerdantIsle_Text_LislaIntro:
	.string "Oh goodness…\p"
	.string "Ok Lisla, here we go…$"

VerdantIsle_Text_OhThankGoodness:
	.string "Oh thank goodness…\p"
	.string "Battles are very scary…$"

VerdantIsle_Text_LislaDefeat:
	.string "… … …\p"
	.string "Huh?…$"

VerdantIsle_Text_YouCanComeAndGo:
	.string "Alright…\p"
	.string "Since you're so strong…\p"
	.string "I'll let you come and go\n"
	.string "through here…\p"
	.string "Please just be respectful\n"
	.string "of the Pokémon…$"

VerdantIsle_Text_OhUhWait:
	.string "Oh!…\p"
	.string "Uh… wait!$"

VerdantIsle_Text_YouShouldntGo:
	.string "Y-you shouldn't go any further\n"
	.string "than this.$"

VerdantIsle_Text_ItsMyDuty:
	.string "I promised my sisters I would\n"
	.string "keep people out of danger…\p"
	.string "S-sorry!$"

VerdantIsle_Text_HuhFlowerShop:
	.string "…Oh?\p"
	.string "…You want me to go to Mauville\n"
	.string "to see a new flower shop?\p"
	.string "Uh…\n"
	.string "Y-yeah ok. I'll go.\p"
	.string "Just be carefull around here,\n"
	.string "ok?$"

