.set LOCALID_ATTENDANT, 1
.set LOCALID_STEVEN, 3

Route112_CableCarStation_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_CableCarStation_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route112_CableCarStation_OnFrame
	.byte 0

Route112_CableCarStation_OnTransition:
	setescapewarp MAP_ROUTE112, 28, 28
	call_if_eq VAR_CABLE_CAR_STATION_STATE, 2, Route112_CableCarStation_EventScript_MoveAttendantAside
	goto_if_unset FLAG_HIDE_CABLECAR_STEVEN, Route112_CableCarStation_PrepareStevenGfx
	end

Route112_CableCarStation_EventScript_MoveAttendantAside::
	setobjectxyperm LOCALID_ATTENDANT, 7, 4
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_LEFT
	return

Route112_CableCarStation_PrepareStevenGfx::
	addobject LOCALID_STEVEN
	setobjectxy LOCALID_STEVEN, 6, 8
	return

Route112_CableCarStation_OnFrame:
	map_script_2 VAR_METEOR_FALLS_STATE, 1, Route112_CableCarStation_EventScript_Steven
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 2, Route112_CableCarStation_EventScript_ExitCableCar
	.2byte 0

Route112_CableCarStation_EventScript_Steven::
	lockall
	delay 30
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route112_CableCarStation_Text_StevenExclaim, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Route112_CableCarStation_Movement_Steven
	waitmovement 0
	msgbox Route112_CableCarStation_Text_StevenGiveMegaRing, MSGBOX_DEFAULT
	giveitem ITEM_MEGA_RING
	call EventScript_EnableAllMegaStones
	msgbox Route112_CableCarStation_Text_StevenAlsoHaveThis, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route112_CableCarStation_EventScript_StevenGiveSceptileite
	case 1, Route112_CableCarStation_EventScript_StevenGiveBlazikenite
	case 2, Route112_CableCarStation_EventScript_StevenGiveSwampertite
	end

Route112_CableCarStation_EventScript_StevenGiveSceptileite::
	giveitem ITEM_SCEPTILITE
	goto Route112_CableCarStation_EventScript_StevenAfterMegaStone
	end

Route112_CableCarStation_EventScript_StevenGiveBlazikenite::
	giveitem ITEM_BLAZIKENITE
	goto Route112_CableCarStation_EventScript_StevenAfterMegaStone
	end

Route112_CableCarStation_EventScript_StevenGiveSwampertite::
	giveitem ITEM_SWAMPERTITE
	goto Route112_CableCarStation_EventScript_StevenAfterMegaStone
	end

Route112_CableCarStation_EventScript_StevenAfterMegaStone::
	msgbox Route112_CableCarStation_Text_SorryICantStay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Route112_CableCarStation_Movement_StevenGoToLeave
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route112_CableCarStation_Text_YouAreARemarkableTrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setvar VAR_METEOR_FALLS_STATE, 2
	setflag FLAG_HIDE_CABLECAR_STEVEN
	removeobject LOCALID_STEVEN
	playse SE_DOOR
	releaseall
	end

Route112_CableCarStation_EventScript_ExitCableCar::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Route112_CableCarStation_Movement_ExitCableCar
	applymovement LOCALID_ATTENDANT, Route112_CableCarStation_Movement_FollowPlayerOutFromCableCar
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm LOCALID_ATTENDANT, 6, 7
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end

Route112_CableCarStation_EventScript_Attendant::
	lock
	faceplayer
	msgbox Route112_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route112_CableCarStation_EventScript_RideCableCar
	goto_if_eq VAR_RESULT, NO, Route112_CableCarStation_EventScript_DeclineRide
	end

Route112_CableCarStation_EventScript_RideCableCar::
	msgbox Route112_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Route112_CableCarStation_Movement_LeadPlayerToCableCar
	applymovement OBJ_EVENT_ID_PLAYER, Route112_CableCarStation_Movement_BoardCableCar
	waitmovement 0
	setvar VAR_0x8004, FALSE  @ Going up
	setvar VAR_CABLE_CAR_STATION_STATE, 1
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	special CableCarWarp
	special CableCar
	waitstate
	release
	end

Route112_CableCarStation_EventScript_DeclineRide::
	msgbox Route112_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
	release
	end

Route112_CableCarStation_Movement_LeadPlayerToCableCar:
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_left
	step_end

Route112_CableCarStation_Movement_FollowPlayerOutFromCableCar:
	delay_16
	walk_left
	walk_down
	walk_down
	step_end

Route112_CableCarStation_Movement_BoardCableCar:
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

Route112_CableCarStation_Movement_ExitCableCar:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

Route112_CableCarStation_Movement_Steven:
	walk_down
	walk_down
	step_end

Route112_CableCarStation_Movement_StevenGoToLeave:
	walk_right
	walk_down
	delay_16
	walk_in_place_faster_left
	step_end

Route112_CableCarStation_Text_CableCarReadyGetOn:
	.string "The CABLE CAR is ready to go up.\n"
	.string "Would you like to be on it?$"

Route112_CableCarStation_Text_StepThisWay:
	.string "Please step this way.$"

Route112_CableCarStation_Text_RideAnotherTime:
	.string "Please ride with us another time.$"

Route112_CableCarStation_Text_StevenExclaim:
	.string "{PLAYER}!$"

Route112_CableCarStation_Text_StevenGiveMegaRing:
	.string "I'm glad I was able to get ahead of\n"
	.string "of you on my SKARMORY.\p"
	.string "After I returned him to his lab,\n"
	.string "PROFESSOR COSMO gave me this…\l"
	.string "It's a device he made…\p"
	.string "It is capable of revealing and\n"
	.string "unlocking the potential of stones.\p"
	.string "These special stones have been\n"
	.string "appearing all around the region!\p"
	.string "…It seems Team Magma weren't aware of\n"
	.string "the PROFESSORS invention…\p"
	.string "He wants you to have it for coming\n"
	.string "to his rescue!$"

Route112_CableCarStation_Text_StevenAlsoHaveThis:
	.string "Although it can activate their power\n"
	.string "the gems themselves are worthless\l"
	.string "without the will of a trainer and their\l"
	.string "Pokémon!\p"
	.string "…Using that ring, I was able to find this\n"
	.string "amongst my collection.\p"
	.string "Here…$"

Route112_CableCarStation_Text_SorryICantStay:
	.string "It reminds me of you and your Pokémon!\p"
	.string "I hope you can unlock its full\n"
	.string "potential {PLAYER}!\p"
	.string "… … …\n"
	.string "Unfortunately I can't stay.\p"
	.string "After I beat those goons at the door\n"
	.string "they ran back towards Fallarbor!\p"
	.string "… … …\p"
	.string "… I would hate for COSMO to run into\n"
	.string "more trouble with Team Magma.\p"
	.string "So I must make sure he remains safe!$"

Route112_CableCarStation_Text_YouAreARemarkableTrainer:
	.string "I have a feeling Team Magma don't have\n"
	.string "a chance against you {PLAYER}!\p"
	.string "…You are a truly remarkable trainer.$"

