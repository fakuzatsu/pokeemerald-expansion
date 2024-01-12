.set LOCALID_FOSSIL_1, 1
.set LOCALID_FOSSIL_2, 2
.set LOCALID_ROXANNE, 3

DesertCavern_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DesertCavern_1F_OnLoad
	.byte 0

DesertCavern_1F_OnLoad:
	call_if_eq VAR_FOSSIL_OBTAINED, 1, DesertCavern_1F_EventScript_RemoveLedge
	call_if_eq VAR_FOSSIL_OBTAINED, 2, DesertCavern_1F_EventScript_RemoveLedge
	call_if_set FLAG_HIDDEN_ITEM_AERODACTYLITE, DesertCavern_1F_Hide_Aerodactylite
	end

DesertCavern_1F_Hide_Aerodactylite::
    setmetatile 3, 11, METATILE_Cave_RockFloor, FALSE
    return

DesertCavern_1F_Aerodactylite::
	goto_if_set FLAG_HIDDEN_ITEM_AERODACTYLITE, DesertCavern_1F_End_Aerodactylite
	checkitemspace ITEM_AERODACTYLITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call DesertCavern_1F_Hide_Aerodactylite
	special DrawWholeMapView
	giveitem ITEM_AERODACTYLITE
	setflag FLAG_HIDDEN_ITEM_AERODACTYLITE
DesertCavern_1F_End_Aerodactylite::
	release
	end	

DesertCavern_1F_EventScript_PrepareStartEvent1::
	lockall
	setvar VAR_0x8008, 1
	goto DesertCavern_1F_EventScript_StartEvent
	end

DesertCavern_1F_EventScript_PrepareStartEvent2::
	lockall
	setvar VAR_0x8008, 2
	goto DesertCavern_1F_EventScript_StartEvent
	end

DesertCavern_1F_EventScript_PrepareStartEvent3::
	lockall
	setvar VAR_0x8008, 3
	goto DesertCavern_1F_EventScript_StartEvent
	end

DesertCavern_1F_EventScript_StartEvent::
	addobject LOCALID_ROXANNE
	applymovement LOCALID_ROXANNE, Common_Movement_WalkInPlaceFasterUp
	playse SE_DOOR
	setobjectxy LOCALID_ROXANNE, 49, 28
	delay 30
	playse SE_PIN
	applymovement LOCALID_ROXANNE, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox DesertCavern_1F_Text_OhHiPlayer, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	call_if_eq VAR_0x8008, 1, DesertCavern_1F_RoxanneApproachPlayer1
	call_if_eq VAR_0x8008, 3, DesertCavern_1F_RoxanneApproachPlayer3
	msgbox DesertCavern_1F_Text_WhatAreYouDoingHere, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, DesertCavern_1F_RoxanneLeavePlayer1
	call_if_eq VAR_0x8008, 2, DesertCavern_1F_RoxanneLeavePlayer2
	call_if_eq VAR_0x8008, 3, DesertCavern_1F_RoxanneLeavePlayer3
	setvar VAR_FOSSIL_OBTAINED, 3
	setobjectxy LOCALID_ROXANNE, 9, 14
	setobjectxyperm LOCALID_ROXANNE, 9, 14
	releaseall
	end

DesertCavern_1F_RoxanneApproachPlayer1::
	applymovement LOCALID_ROXANNE, DesertCavern_1F_Movement_RoxanneApproachPlayer1
	waitmovement 0
	return

DesertCavern_1F_RoxanneApproachPlayer3::
	applymovement LOCALID_ROXANNE, DesertCavern_1F_Movement_RoxanneApproachPlayer3
	waitmovement 0
	return

DesertCavern_1F_RoxanneLeavePlayer1::
	applymovement LOCALID_ROXANNE, DesertCavern_1F_Movement_RoxanneLeavePlayer1
	waitmovement 0
	return

DesertCavern_1F_RoxanneLeavePlayer2::
	applymovement LOCALID_ROXANNE, DesertCavern_1F_Movement_RoxanneLeavePlayer2
	waitmovement 0
	return

DesertCavern_1F_RoxanneLeavePlayer3::
	applymovement LOCALID_ROXANNE, DesertCavern_1F_Movement_RoxanneLeavePlayer1
	waitmovement 0
	return

DesertCavern_1F_EventScript_RemoveLedge::
	setmetatile 4, 18, METATILE_Cave_CaveFloor_Rock, TRUE
	setmetatile 4, 17, METATILE_Cave_RockFloor, TRUE
	setmetatile 4, 16, METATILE_Cave_RockFloor_BigRock, TRUE
	setmetatile 4, 15, METATILE_Cave_CaveFloor_Rock, TRUE
	setmetatile 4, 14, METATILE_Cave_RockFloor, TRUE
	setmetatile 5, 18, METATILE_Cave_RockWall_Right, TRUE
	setmetatile 5, 17, METATILE_Cave_RockWall_Right, TRUE
	setmetatile 5, 16, METATILE_Cave_RockWall_Right, TRUE
	setmetatile 5, 15, METATILE_Cave_RockWall_Right, TRUE
	setmetatile 5, 14, METATILE_Cave_RockWall_Right, TRUE
	setmetatile 6, 18, METATILE_Cave_RockWall_Right, TRUE
	setmetatile 6, 17, METATILE_Cave_RockWall_Right, TRUE
	setmetatile 6, 16, METATILE_Cave_RockWall_Right, TRUE
	setmetatile 6, 15, METATILE_Cave_RockWall_Right, TRUE
	setmetatile 6, 14, METATILE_Cave_RockWall_Right, TRUE
	setobjectxyperm LOCALID_FOSSIL_1, 3, 16
	setobjectxyperm LOCALID_FOSSIL_2, 3, 17
	return

DesertCavern_1F_EventScript_RoxanneFossilConversation::
	lockall
	setvar VAR_FOSSIL_OBTAINED, 4
	playse SE_PIN
	applymovement LOCALID_ROXANNE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROXANNE, Common_Movement_WalkInPlaceFasterDown
	msgbox DesertCavern_1F_Text_CheckOutTheseFossils, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROXANNE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_ROXANNE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox DesertCavern_1F_Text_LetsBattleForFirstPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DesertCavern_1F_EventScript_BattleRoxanne
	goto_if_eq VAR_RESULT, NO, DesertCavern_1F_EventScript_DontBattleRoxanne
	end

@needs a battle
DesertCavern_1F_EventScript_BattleRoxanne::
	msgbox DesertCavern_1F_Text_RoxanneIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_SHIRLEY, DesertCavern_1F_Text_RoxanneDefeat
	setvar VAR_FOSSIL_OBTAINED, 5
	goto DesertCavern_1F_EventScript_AlrightYouPickFirst
	end

DesertCavern_1F_EventScript_DontBattleRoxanne::
	msgbox DesertCavern_1F_Text_IllWaitHereForYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

DesertCavern_1F_EventScript_AlrightYouPickFirst::
	msgbox DesertCavern_1F_Text_AlrightGoAhead, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

DesertCavern_1F_EventScript_InteractWithRoxanne::
	lockall
	faceplayer
	goto_if_eq VAR_FOSSIL_OBTAINED, 1, DesertCavern_1F_EventScript_WoahThatWasACloseOne
	goto_if_eq VAR_FOSSIL_OBTAINED, 2, DesertCavern_1F_EventScript_WoahThatWasACloseOne
	goto_if_eq VAR_FOSSIL_OBTAINED, 5, DesertCavern_1F_EventScript_AlrightYouPickFirst
	msgbox DesertCavern_1F_Text_LetsBattleForFirstPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DesertCavern_1F_EventScript_BattleRoxanne
	goto_if_eq VAR_RESULT, NO, DesertCavern_1F_EventScript_DontBattleRoxanne
	end

DesertCavern_1F_EventScript_TryGetFossilBeforeBattle::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROXANNE, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox DesertCavern_1F_Text_HeyWaitLetsBattle, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, DesertCavern_1F_MovePlayerBackToRoxanne
	waitmovement 0
	releaseall
	end

DesertCavern_1F_EventScript_JawFossil::
	lock
	faceplayer
	msgbox DesertCavern_1F_Text_TakeJawFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DesertCavern_1F_EventScript_LeaveJawFossil
	giveitem ITEM_JAW_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	closemessage
	removeobject LOCALID_FOSSIL_1
	delay 30
	setflag FLAG_OBTAINED_JAW_FOSSIL
	setvar VAR_FOSSIL_OBTAINED, 1
	goto DesertCavern_1F_EventScript_CollapseLedge
	end

DesertCavern_1F_EventScript_LeaveJawFossil::
	msgbox DesertCavern_1F_Text_LeftJawFossilAlone, MSGBOX_DEFAULT
	release
	end

DesertCavern_1F_EventScript_SailFossil::
	lock
	faceplayer
	msgbox DesertCavern_1F_Text_TakeSailFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DesertCavern_1F_EventScript_LeaveSailFossil
	giveitem ITEM_SAIL_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	closemessage
	removeobject LOCALID_FOSSIL_2
	delay 30
	setflag FLAG_OBTAINED_SAIL_FOSSIL
	setvar VAR_FOSSIL_OBTAINED, 2
	goto DesertCavern_1F_EventScript_CollapseLedge
	end

DesertCavern_1F_EventScript_LeaveSailFossil::
	msgbox DesertCavern_1F_Text_LeftSailFossilAlone, MSGBOX_DEFAULT
	release
	end

DesertCavern_1F_EventScript_CollapseLedge::
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 32  @ num shakes
	setvar VAR_0x8007, 2   @ shake delay
	special ShakeCamera
	waitstate
	special DoMirageTowerCeilingCrumble
	waitstate
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 8, 16
	setobjectxy LOCALID_FOSSIL_1, 3, 16
	setobjectxy LOCALID_FOSSIL_2, 3, 17
	waitmovement 0
	call DesertCavern_1F_EventScript_RemoveLedge
	special DrawWholeMapView
	msgbox DesertCavern_1F_Text_YouJumpedBackFromTheLedge, MSGBOX_AUTOCLOSE
	fadescreen FADE_FROM_BLACK
	delay 30
	playse SE_PIN
	applymovement LOCALID_ROXANNE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_ROXANNE, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	applymovement LOCALID_ROXANNE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox DesertCavern_1F_Text_PlayerAreYouAlright, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_MET_DESERT_CAVERN_ROXANNE
	releaseall
	end

DesertCavern_1F_EventScript_WoahThatWasACloseOne::
	msgbox DesertCavern_1F_Text_WoahThatWasACloseOne, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

DesertCavern_1F_Movement_RoxanneApproachPlayer1:
	walk_up
	walk_in_place_faster_left
	step_end

DesertCavern_1F_Movement_RoxanneApproachPlayer3:
	walk_up
	walk_in_place_faster_right
	step_end

DesertCavern_1F_Movement_RoxanneLeavePlayer1:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

DesertCavern_1F_Movement_RoxanneLeavePlayer2:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

DesertCavern_1F_MovePlayerBackToRoxanne:
	walk_right
	step_end

DesertCavern_1F_Text_OhHiPlayer:
	.string "ROXANNE: Oh!…\p"
	.string "Hi there, {PLAYER}{KUN}!$"

DesertCavern_1F_Text_WhatAreYouDoingHere:
	.string "Pleasure to meet again!\p"
	.string "… … …\p"
	.string "Oh… I'm here chasing some\n"
	.string "Information from a book of mine.\p"
	.string "Supposedly this area was once the\n"
	.string "location of an ancient civilisation.\p"
	.string "…Exciting right!?\p"
	.string "You can still find traces of that\n"
	.string "Civilisation in the earth!\p"
	.string "…I'm going to go on ahead. You\n"
	.string "should come along!$"

DesertCavern_1F_Text_CheckOutTheseFossils:
	.string "ROXANNE: Hey {PLAYER}{KUN}!\p"
	.string "I've been checking out all of the\n"
	.string "minerals here!\p"
	.string "…You can tell a lot from the age of\n"
	.string "the stone in the walls…\p"
	.string "Oh!\n"
	.string "and check out these stones here…\p"
	.string "I think they might be fossils!$"

DesertCavern_1F_Text_LetsBattleForFirstPick:
	.string "Since there are two fossils we\n"
	.string "can both have one!\p"
	.string "But lets battle to see who gets\n"
	.string "first pick!\p"
	.string "… … …\n"
	.string "Are you ready?$"

DesertCavern_1F_Text_IllWaitHereForYou:
	.string "Oh!\n"
	.string "That's ok!\p"
	.string "You can go and prepare and I'll\n"
	.string "wait here…\p"
	.string "We're in this together after all.$"

DesertCavern_1F_Text_HeyWaitLetsBattle:
	.string "ROXANNE: Hey wait {PLAYER}{KUN}!\p"
	.string "What if I want that one!\p"
	.string "It's only fair if we battle\n"
	.string "to see who picks first…$"

DesertCavern_1F_Text_RoxanneIntro:
	.string "Alright! Let's do this!\p"
	.string "I've studied since our last battle!\n"
	.string "I won't lose again…$"

DesertCavern_1F_Text_RoxanneDefeat:
	.string "Again?\p"
	.string "Your Pokémon knowledge is unmatched…$"

DesertCavern_1F_Text_AlrightGoAhead:
	.string "Alright…\n"
	.string "You beat me fair and square.\p"
	.string "You can go ahead and pick which\n"
	.string "fossil you want to keep.$"

DesertCavern_1F_Text_TakeJawFossil:
	.string "You found the JAW FOSSIL.\p"
	.string "Take the JAW FOSSIL?$"

DesertCavern_1F_Text_TakeSailFossil:
	.string "You found the SAIL FOSSIL.\p"
	.string "Take the SAIL FOSSIL?$"

DesertCavern_1F_Text_LeftJawFossilAlone:
	.string "{PLAYER} left the JAW FOSSIL alone.$"

DesertCavern_1F_Text_LeftSailFossilAlone:
	.string "{PLAYER} left the SAIL FOSSIL alone.$"

DesertCavern_1F_Text_YouJumpedBackFromTheLedge:
	.string "{PLAYER} jumped away from the edge.$"

DesertCavern_1F_Text_PlayerAreYouAlright:
	.string "{PLAYER}{KUN}!\n"
	.string "Are you alright!?\p"
	.string "That was a close one!\p"
	.string "… … …\n"
	.string "Good thinking on your feet!\p"
	.string "You could have ended up in\n"
	.string "that pit!$"

DesertCavern_1F_Text_WoahThatWasACloseOne:
	.string "I'm glad you're safe after\n"
	.string "that close call!\p"
	.string "I don't know what I would have\n"
	.string "done if you'd gone in!\p"
	.string "… … …\p"
	.string "Don't worry about the fossil!\p"
	.string "I'm just glad that you are safe.\p"
	.string "You can keep that one, you won\n"
	.string "it fair and square…$"

