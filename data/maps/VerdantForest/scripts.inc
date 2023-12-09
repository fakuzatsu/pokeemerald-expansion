.set LOCALID_LYDIA, 2

VerdantForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdantForest_OnResume
	map_script MAP_SCRIPT_ON_RESUME, VerdantForest_OnResume
	.byte 0

VerdantForest_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, VerdantForest_OnResume_Night
	goto_if_eq VAR_RESULT, 0, VerdantForest_OnResume_Day
	end

VerdantForest_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	goto_if_set FLAG_DEFEATED_TRAINER_LYDIA, VerdantForest_EventScript_DisableTrigger
	end

VerdantForest_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	goto_if_set FLAG_DEFEATED_TRAINER_LYDIA, VerdantForest_EventScript_DisableTrigger
	end

VerdantForest_EventScript_DisableTrigger::
	setvar VAR_TEMP_0, 1
	end

VerdantForest_EventScript_LydiaTalk::
	lockall
	faceplayer
	call_if_eq VAR_MAUVILLE_FLOWER_SHOP_STATE, 0, MauvilleCity_FlowerShop_EventScript_SetQuestAvailable
	goto_if_set FLAG_DEFEATED_TRAINER_LYDIA, VerdantForest_EventScript_YoureStrongKid
	msgbox VerdantForest_Text_HeyKid, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VerdantForest_EventScript_LydiaStop1::
	setvar VAR_0x8008, 1
	goto_if_unset FLAG_DEFEATED_TRAINER_LYDIA, VerdantForest_EventScript_LydiaStopPlayer
	releaseall
	end

VerdantForest_EventScript_LydiaStop2::
	setvar VAR_0x8008, 2
	goto_if_unset FLAG_DEFEATED_TRAINER_LYDIA, VerdantForest_EventScript_LydiaStopPlayer
	releaseall
	end

VerdantForest_EventScript_LydiaStopPlayer::
	lockall
	playse SE_PIN
	applymovement LOCALID_LYDIA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LYDIA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox VerdantForest_Text_HeyKidShort, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call_if_eq VAR_0x8008, 1, VerdantForest_EventScript_LydiaApproachPlayer1
	call_if_eq VAR_0x8008, 2, VerdantForest_EventScript_LydiaApproachPlayer2
	msgbox VerdantForest_Text_DidntYouHear, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VerdantForest_EventScript_AreYouSure
	goto_if_eq VAR_RESULT, NO, VerdantForest_EventScript_DontBattleLydia
	end

VerdantForest_EventScript_LydiaApproachPlayer1::
	applymovement LOCALID_LYDIA, VerdantForest_Movement_LydiaApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

VerdantForest_EventScript_LydiaApproachPlayer2::
	applymovement LOCALID_LYDIA, VerdantForest_Movement_LydiaApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

VerdantForest_EventScript_AreYouSure::
	msgbox VerdantForest_Text_HeyAreYouSure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VerdantForest_EventScript_BattleLydia
	goto_if_eq VAR_RESULT, NO, VerdantForest_EventScript_DontBattleLydia
	end

VerdantForest_EventScript_BattleLydia::
	msgbox VerdantForest_Text_LydiaIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LYDIA, VerdantForest_Text_LydiaDefeat
	setflag FLAG_DEFEATED_TRAINER_LYDIA
	goto_if_ge VAR_MAUVILLE_FLOWER_SHOP_STATE, 2, VerdantForest_EventScript_HuhFlowerShopAfterBattle
	goto VerdantForest_EventScript_YoureStrongKid
	end

VerdantForest_EventScript_DontBattleLydia::
	msgbox VerdantForest_Text_HeyNoSweat, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_0x8008, 1, VerdantForest_EventScript_LydiaResetPlayer1
	goto_if_eq VAR_0x8008, 2, VerdantForest_EventScript_LydiaResetPlayer2
	end

VerdantForest_EventScript_LydiaResetPlayer1::
	applymovement LOCALID_LYDIA, VerdantForest_Movement_LydiaShovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, VerdantForest_Movement_PlayerGetShoved
	waitmovement 0
	applymovement LOCALID_LYDIA, VerdantForest_Movement_LydiaResetAfterShove1
	waitmovement 0
	releaseall
	end

VerdantForest_EventScript_LydiaResetPlayer2::
	applymovement LOCALID_LYDIA, VerdantForest_Movement_LydiaShovePlayer2
	applymovement OBJ_EVENT_ID_PLAYER, VerdantForest_Movement_PlayerGetShoved
	waitmovement 0
	applymovement LOCALID_LYDIA, VerdantForest_Movement_LydiaResetAfterShove2
	waitmovement 0
	releaseall
	end

VerdantForest_EventScript_YoureStrongKid::
	goto_if_ge VAR_MAUVILLE_FLOWER_SHOP_STATE, 2, VerdantForest_EventScript_HuhFlowerShop
	msgbox VerdantForest_Text_YoureStrongYouCanGoThrough, MSGBOX_DEFAULT
	releaseall
	end

VerdantForest_EventScript_HuhFlowerShop::
	msgbox VerdantForest_Text_HuhFlowerShop, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LYDIA
	setvar VAR_MAUVILLE_FLOWER_SHOP_STATE, 3
	setflag FLAG_LYDIA_MOVED_TO_SHOP
	delay 16
	fadescreen FADE_FROM_BLACK
	releaseall
	end

VerdantForest_EventScript_HuhFlowerShopAfterBattle::
	msgbox VerdantForest_Text_YoureStrongYouCanGoThrough, MSGBOX_DEFAULT
	goto VerdantForest_EventScript_HuhFlowerShop

VerdantForest_Movement_LydiaApproachPlayer1:
	walk_down
	walk_down
	walk_down
	walk_in_place_fast_left
	step_end

VerdantForest_Movement_LydiaApproachPlayer2:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_in_place_fast_right
	step_end

VerdantForest_Movement_LydiaShovePlayer1:
	walk_left
	walk_in_place_fast_up
	step_end

VerdantForest_Movement_LydiaShovePlayer2:
	walk_right
	walk_in_place_fast_up
	step_end

VerdantForest_Movement_PlayerGetShoved:
	walk_in_place_faster_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	walk_in_place_faster_down
	step_end

VerdantForest_Movement_LydiaResetAfterShove1:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

VerdantForest_Movement_LydiaResetAfterShove2:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_down
	step_end

VerdantForest_Text_HeyKid:
	.string "Oh… Hey Kid.\p"
	.string "Listen, the path up ahead is pretty\n"
	.string "dangerous so don't go venturing into\l"
	.string "that forest, kay?$"

VerdantForest_Text_HeyKidShort:
	.string "Hey Kid!$"

VerdantForest_Text_DidntYouHear:
	.string "Didn't you hear? It's dangerous over\n"
	.string "there. You'll get hurt!\p"
	.string "… … …\p"
	.string "Or is it that you think you're\n"
	.string "tougher than what's in the forest?\p"
	.string "… … …\p"
	.string "How about this?\p"
	.string "Battle me and prove that you can take\n"
	.string "take on the Pokémon beyond?$"

VerdantForest_Text_HeyAreYouSure:
	.string "Hey are you sure about this, kid?\p"
	.string "I've been handling places like this\n"
	.string "for ages.\p"
	.string "So I'm pretty tough.\p"
	.string "Still reckon you can handle it?$"

VerdantForest_Text_LydiaIntro:
	.string "Alright! Let's see what you've got!$"

VerdantForest_Text_LydiaDefeat:
	.string "Well… Not bad kid!\p"
	.string "You're stronger than you look!$"

VerdantForest_Text_HeyNoSweat:
	.string "Hey, no sweat kid.\p"
	.string "But if you don't think you can handle\n"
	.string "me. Then you definitely can't handle\l"
	.string "this place.$"

VerdantForest_Text_YoureStrongYouCanGoThrough:
	.string "Well… I'm satisfied.\p"
	.string "I reckon you've got what it takes to\n"
	.string "defeat anything ahead.\p"
	.string "Nice work kid.$"

VerdantForest_Text_HuhFlowerShop:
	.string "… … …\p"
	.string "Huh? What's this about a new flower\n"
	.string "shop in Mauville?\p"
	.string "… … …\p"
	.string "Selling mysterious berries, huh?\p"
	.string "Sounds cool.\n"
	.string "Guess I gotta check this out.\p"
	.string "Make sure nobody wanders into the\n"
	.string "woods for me kid.$"	

