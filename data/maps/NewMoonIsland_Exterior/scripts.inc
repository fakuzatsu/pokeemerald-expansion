.set LOCALID_BRINEY, 2

NewMoonIsland_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewMoonIsland_Exterior_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, NewMoonIsland_Exterior_OnResume
	map_script MAP_SCRIPT_ON_RESUME, NewMoonIsland_Exterior_OnResume
	.byte 0

NewMoonIsland_Exterior_OnResume:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, NewMoonIsland_Exterior_OnResume_Night
	goto_if_eq VAR_RESULT, 0, NewMoonIsland_Exterior_OnResume_Day
	end

NewMoonIsland_Exterior_OnResume_Night:
	setvar VAR_DAYNIGHT, 1
	setweather WEATHER_SHADE
	end

NewMoonIsland_Exterior_OnResume_Day:
	setvar VAR_DAYNIGHT, 0
	setweather WEATHER_SUNNY
	end

NewMoonIsland_Exterior_OnFrame:
	map_script_2 VAR_WALDA_QUEST_STATE, 2, NewMoonIsland_Exterior_EventScript_FirstTimeOnIsland
	.2byte 0

NewMoonIsland_Exterior_EventScript_FirstTimeOnIsland::
	lock
	setvar VAR_WALDA_QUEST_STATE, 3
NewMoonIsland_Exterior_EventScript_IllKeepHerDockedHere::
	msgbox NewMoonIsland_Exterior_Text_IllKeepHerDockedHere, MSGBOX_DEFAULT
	release
	end

NewMoonIsland_Exterior_EventScript_Briney::
	lock
	faceplayer
	msgbox NewMoonIsland_Exterior_Text_DoYouWantToHeadBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewMoonIsland_Exterior_EventScript_IllKeepHerDockedHere
	goto NewMoonIsland_Exterior_EventScript_ReturnToPetalburg
	end

NewMoonIsland_Exterior_EventScript_ReturnToPetalburg::
	msgbox NewMoonIsland_Exterior_Text_PetalburgWereSettingSail, MSGBOX_DEFAULT
	applymovement LOCALID_BRINEY, NewMoonIsland_Exterior_Movement_BrineyEnterBoat
	waitmovement 0
	removeobject LOCALID_BRINEY
	switch VAR_FACING
	case DIR_SOUTH, NewMoonIsland_Exterior_EventScript_EnterBoatSouth
	case DIR_WEST, NewMoonIsland_Exterior_EventScript_EnterBoatWest
	case DIR_EAST, NewMoonIsland_Exterior_EventScript_EnterBoatEast
	end

NewMoonIsland_Exterior_EventScript_EnterBoatSouth::
	applymovement OBJ_EVENT_ID_PLAYER, NewMoonIsland_Exterior_Movement_PlayerEnterBoatSouth
	waitmovement 0
	goto NewMoonIsland_Exterior_EventScript_DoSailToPetalburg
	end

NewMoonIsland_Exterior_EventScript_EnterBoatEast::
	applymovement OBJ_EVENT_ID_PLAYER, NewMoonIsland_Exterior_Movement_PlayerEnterBoatEast
	waitmovement 0
	goto NewMoonIsland_Exterior_EventScript_DoSailToPetalburg
	end

NewMoonIsland_Exterior_EventScript_EnterBoatWest::
	applymovement OBJ_EVENT_ID_PLAYER, NewMoonIsland_Exterior_Movement_PlayerEnterBoatWest
	waitmovement 0
	goto NewMoonIsland_Exterior_EventScript_DoSailToPetalburg
	end

NewMoonIsland_Exterior_EventScript_DoSailToPetalburg::
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE109
	delay 20
	fadescreen FADE_TO_BLACK
	delay 20
	msgbox NewMoonIsland_Exterior_Text_BackToPetalburg, MSGBOX_DEFAULT
	delay 20
	setflag FLAG_SYS_REMOVE_WARP_FADE
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 4
	waitstate
	releaseall
	end

NewMoonIsland_Exterior_Movement_BrineyEnterBoat:
	walk_down
	step_end

NewMoonIsland_Exterior_Movement_PlayerEnterBoatSouth:
	walk_down
	walk_down
	step_end

NewMoonIsland_Exterior_Movement_PlayerEnterBoatEast:
	walk_right
	walk_down
	step_end

NewMoonIsland_Exterior_Movement_PlayerEnterBoatWest:
	walk_left
	walk_down
	step_end

NewMoonIsland_Exterior_Text_IllKeepHerDockedHere:
	.string "MR. BRINEY: I'll keep the old girl\n"
	.string "docked here until you return.$"

NewMoonIsland_Exterior_Text_DoYouWantToHeadBack:
	.string "MR. BRINEY: Do you want to head\n"
	.string "back to Petalburg?$"

NewMoonIsland_Exterior_Text_PetalburgWereSettingSail:
	.string "MR. BRINEY: PETALBURG it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"

NewMoonIsland_Exterior_Text_BackToPetalburg:
	.string "Hold on tight.$"
