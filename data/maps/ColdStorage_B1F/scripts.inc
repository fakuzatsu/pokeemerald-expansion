.set LOCALID_WALLACE, 1

ColdStorage_B1F_MapScripts::
	.byte 0

ColdStorage_EventScript_MeetWallace::
	lockall
	addobject LOCALID_WALLACE
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_WALLACE, 3, 16
	goto ColdStorage_EventScript_Wallace
	end

ColdStorage_EventScript_MeetWallace2::
	lockall
	addobject LOCALID_WALLACE
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_WALLACE, 3, 16
	goto ColdStorage_EventScript_Wallace
	end

ColdStorage_EventScript_Wallace::
	applymovement LOCALID_WALLACE, ColdStorage_Movement_WallaceStartWalkDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 1, ColdStorage_EventScript_WallaceApproachPlayer
	call_if_eq VAR_0x8008, 2, ColdStorage_EventScript_WallaceApproachPlayer2
	msgbox ColdStorage_Text_AreYouATrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox ColdStorage_Text_ImHereCatchingPokemon, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, ColdStorage_EventScript_WallaceExit
	call_if_eq VAR_0x8008, 2, ColdStorage_EventScript_WallaceExit2
	applymovement OBJ_EVENT_ID_PLAYER, ColdStorage_Movement_PlayerWatchWallaceExit
	waitmovement 0
	setvar VAR_WALLACE_COLD_STORAGE_ENCOUNTER, 1
	removeobject LOCALID_WALLACE
	playse SE_DOOR
	releaseall
	end

ColdStorage_EventScript_WallaceApproachPlayer::
	applymovement LOCALID_WALLACE, ColdStorage_Movement_WallaceApproachPlayer
	waitmovement 0
	return

ColdStorage_EventScript_WallaceApproachPlayer2::
	applymovement LOCALID_WALLACE, ColdStorage_Movement_WallaceApproachPlayer2
	waitmovement 0
	return

ColdStorage_EventScript_WallaceExit::
	applymovement LOCALID_WALLACE, ColdStorage_Movement_WallaceExit
	waitmovement 0
	return

ColdStorage_EventScript_WallaceExit2::
	applymovement LOCALID_WALLACE, ColdStorage_Movement_WallaceExit2
	waitmovement 0
	return

ColdStorage_Movement_WallaceStartWalkDown:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

ColdStorage_Movement_WallaceApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

ColdStorage_Movement_WallaceApproachPlayer2:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

ColdStorage_Movement_WallaceExit:
	walk_right
	walk_down
	walk_down
	step_end

ColdStorage_Movement_WallaceExit2:
	walk_left
	walk_down
	walk_down
	step_end

ColdStorage_Movement_PlayerWatchWallaceExit:
	walk_in_place_faster_down
	step_end

ColdStorage_Text_AreYouATrainer:
	.string "Ah. Hello there. You must be a\n"
	.string "trainer, correct?\p"
	.string "Few others would come to this place.$"

ColdStorage_Text_ImHereCatchingPokemon:
	.string "I'm here to catch Pokémon you see.\p"
	.string "During a power surge this place was\n"
	.string "completely frozen over.\p"
	.string "It's since been abandoned, but the\n"
	.string "POKeMON keep it cold.\p"
	.string "Brisk, no? \p"
	.string "Anyways, I am sure we will meet again\n"
	.string "trainer. The pleasure was mine.$"

