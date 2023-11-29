.set LOCALID_LUGIA, 1

NavelRock_Bottom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Bottom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Bottom_OnResume
	.byte 0

NavelRock_Bottom_OnTransition:
	call_if_set FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_HideLugia
	call_if_unset FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_TryShowLugia
	end

NavelRock_Bottom_EventScript_HideLugia::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_LUGIA
	return

NavelRock_Bottom_EventScript_TryShowLugia::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_LUGIA, Common_EventScript_NopReturn
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_LUGIA
	return

NavelRock_Bottom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Bottom_EventScript_TryRemoveLugia
	end

NavelRock_Bottom_EventScript_TryRemoveLugia::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LUGIA
	return

NavelRock_Bottom_EventScript_Lugia0::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_0x8008, 0
	playse SE_M_DETECT
	dofieldeffectsparkle 10, 13, 0
	waitfieldeffect FLDEFF_SPARKLE
	goto NavelRock_Bottom_EventScript_Lugia
	end

NavelRock_Bottom_EventScript_Lugia1::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_0x8008, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 11, 13, 0
	waitfieldeffect FLDEFF_SPARKLE
	goto NavelRock_Bottom_EventScript_Lugia
	end

NavelRock_Bottom_EventScript_Lugia2::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_0x8008, 2
	playse SE_M_DETECT
	dofieldeffectsparkle 12, 13, 0
	waitfieldeffect FLDEFF_SPARKLE
	goto NavelRock_Bottom_EventScript_Lugia
	end

NavelRock_Bottom_EventScript_Lugia::
	msgbox NavelRock_Bottom_Text_TheSilverWing, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	call_if_eq VAR_0x8008, 0, NavelRock_Bottom_Movement_MoveCameraRight
	call_if_eq VAR_0x8008, 2, NavelRock_Bottom_Movement_MoveCameraLeft
	applymovement LOCALID_LUGIA, NavelRock_Top_Movement_HoOhAppear
	applymovement OBJ_EVENT_ID_CAMERA, NavelRock_Top_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement OBJ_EVENT_ID_CAMERA, NavelRock_Top_Movement_CameraPanDown
	applymovement LOCALID_LUGIA, NavelRock_Top_Movement_HoOhApproach
	waitmovement 0
	special RemoveCameraObject
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	seteventmon SPECIES_LUGIA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Bottom_EventScript_DefeatedLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Bottom_EventScript_RanFromLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Bottom_EventScript_RanFromLugia
	setflag FLAG_CAUGHT_LUGIA
	release
	end

NavelRock_Bottom_Movement_MoveCameraRight::
	applymovement OBJ_EVENT_ID_CAMERA, NavelRock_Top_Movement_CameraPanRight
	waitmovement 0
	return

NavelRock_Bottom_Movement_MoveCameraLeft::
	applymovement OBJ_EVENT_ID_CAMERA, NavelRock_Top_Movement_CameraPanLeft
	waitmovement 0
	return

NavelRock_Bottom_EventScript_DefeatedLugia::
	setflag FLAG_DEFEATED_LUGIA
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Bottom_EventScript_RanFromLugia::
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Top_Movement_CameraPanRight:
	walk_right
	step_end

NavelRock_Top_Movement_CameraPanLeft:
	walk_left
	step_end

NavelRock_Bottom_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

NavelRock_Bottom_Movement_CameraPanDown:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

NavelRock_Bottom_Movement_HoOhApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

NavelRock_Bottom_Movement_HoOhAppear:
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

NavelRock_Bottom_Text_TheSilverWing:
	.string "The Silver Wing started\n"
	.string "to shimmer!$"

