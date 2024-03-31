PacifidlogTown_Resort_1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Pacifidlog_Resort_1_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Pacifidlog_Resort_1_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Pacifidlog_Resort_1_OnWarp
	.byte 0

Pacifidlog_Resort_1_OnTransition:
	call_if_set FLAG_PLAYER_OWNS_RESORT, Pacifidlog_Resort_1_DecorationFlags
	end

Pacifidlog_Resort_1_DecorationFlags:
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	return

Pacifidlog_Resort_1_OnLoad:
	call_if_unset FLAG_PLAYER_OWNS_RESORT, PacifidLog_Resort_1_HidePC
	end

PacifidLog_Resort_1_HidePC:
	setmetatile 7, 0, METATILE_GenericBuilding_Resort_EmptyTable_Top, TRUE
	setmetatile 7, 1, METATILE_GenericBuilding_Resort_EmptyTable_Bot, TRUE
	setflag FLAG_DECORATION_1
	setflag FLAG_DECORATION_2
	setflag FLAG_DECORATION_3
	setflag FLAG_DECORATION_4
	setflag FLAG_DECORATION_5
	setflag FLAG_DECORATION_6
	setflag FLAG_DECORATION_7
	setflag FLAG_DECORATION_8
	setflag FLAG_DECORATION_9
	setflag FLAG_DECORATION_10
	setflag FLAG_DECORATION_11
	setflag FLAG_DECORATION_12
	return

Pacifidlog_Resort_1_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, Pacifidlog_Resort_1_InitDecorations
	.2byte 0

Pacifidlog_Resort_1_InitDecorations:
	goto_if_set FLAG_PLAYER_OWNS_RESORT, SecretBase_EventScript_InitDecorations
	end

Pacifidlog_Resort_1_EventScript_PC::
	goto_if_unset FLAG_PLAYER_OWNS_RESORT, Pacifidlog_Resort_1_EventScript_SkipPC
	setvar VAR_0x8004, PC_LOCATION_RESORT
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
Pacifidlog_Resort_1_EventScript_SkipPC::
	releaseall
	end

Pacifidlog_Resort_1_EventScript_TurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_RESORT
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end
