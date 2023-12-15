.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 6
.set LOCALID_RIVAL, 15

Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition:
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	call Common_EventScript_SetupRivalGfxId
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

Route112_EventScript_MagmaGrunts::
	lockall
	delay 40
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker::
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route112_EventScript_RematchTrent
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RegisterTrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRENT_1
	release
	end

Route112_EventScript_RematchTrent::
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry::
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_RivalScene:: @ 81EF9CB
	lockall
	addobject LOCALID_RIVAL
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route112_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	call_if_eq Route112_EventScript_PlayBrendanMusic
	delay 65
	call Route112_EventScript_RivalApproachPlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route112_EventScript_May
	compare VAR_RESULT, FEMALE
	goto_if_eq Route112_EventScript_Brendan
	releaseall
	end

Route112_EventScript_PlayMayMusic:: @ 81EF7E1
	playbgm MUS_ENCOUNTER_MAY, 1
	return

Route112_EventScript_PlayBrendanMusic:: @ 81EF7E6
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	return

Route112_EventScript_RivalApproachPlayer1:: @ 81EF94E
	applymovement LOCALID_RIVAL, Route112_Movement_RivalApproachPlayer
	waitmovement 0
	return

Route112_Movement_RivalApproachPlayer: @ 81EF9A8
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route112_EventScript_May:: @ 81EF7EB
	msgbox Route112_Text_May, MSGBOX_DEFAULT
	giveitem ITEM_HM04_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
	msgbox Route112_Text_May2, MSGBOX_DEFAULT
	goto Route112_EventScript_RivalExit
	end

Route112_EventScript_Brendan:: @ 81EF7EB
	msgbox Route112_Text_Brendan, MSGBOX_DEFAULT
	giveitem ITEM_HM04_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
	msgbox Route112_Text_May2, MSGBOX_DEFAULT
	goto Route112_EventScript_RivalExit
	end

Route112_EventScript_RivalExit:: @ 81EF8EC
	closemessage
	delay 45
	call Route112_EventScript_RivalMove
	removeobject LOCALID_RIVAL
	setvar VAR_ROUTE112_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route112_EventScript_RivalMove:: @ 81EF94E
	applymovement 15, Route112_Movement_RivalLeavePlayer1
	waitmovement 0
	return

Route112_Movement_RivalLeavePlayer1: @ 81EF9A8
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route112_Text_May: @ 81EFC48
	.string "May: {PLAYER}{KUN}!\p"
	.string "Did you know we're right on the\n"
	.string "base of Mt. Chimney?\p"
	.string "I'd love to take a Cable Car\n"
	.string "right up to the top one day...\p"
	.string "Oh, sorry to start rambling off\n"
	.string "with you. Here, take this for\l"
	.string "your time.$"

Route112_Text_Brendan: @ 81EFC48
	.string "Brendan: {PLAYER}{KUN}!\p"
	.string "Did you know we're right on the\n"
	.string "base of Mt. Chimney?\p"
	.string "I'd love to take a Cable Car\n"
	.string "right up to the top one day...\p"
	.string "Oh, sorry to start rambling off\n"
	.string "with you. Here, take this for\l"
	.string "your time.$"

Route112_Text_May2: @ 81EFC48
	.string "I bet you can find all kinds of ways\n"
	.string "to use it in the mountains\l"
	.string "that lie ahead!\p"
	.string "But it won't work outside of\n"
	.string "battle if you don't have the\l"
	.string "Badge from Lavaridge Gym.\p"
	.string "Well I should head off and do\n"
	.string "some field research. We'll\l"
	.string "definitely have a battle next time!$"

Route112_Text_LeaderGoingToAwakenThing:
	.string "Hey, man, is our leader really going\n"
	.string "to awaken that thing?$"

Route112_Text_YeahWeNeedMeteorite:
	.string "Sounds like it, yeah. But I heard\n"
	.string "we need a Meteorite to do it.$"

Route112_Text_OhThatsWhyCrewWentToFallarbor:
	.string "Oh, I get it now. That's why the rest\n"
	.string "of the crew went out to Fallarbor.$"

Route112_Text_CantLetAnyonePassUntilTheyreBack:
	.string "You got it. And until they come back,\n"
	.string "we're not to let anyone pass, right.$"

Route112_Text_NotEasyToGetBackToLavaridge:
	.string "Eh, I'd like to get to Mauville, but if\n"
	.string "I went down these ledges, it'd be no\l"
	.string "easy matter to get back to Lavaridge.$"

Route112_Text_MtChimneyCableCarSign:
	.string "Mt. Chimney Cable Car\n"
	.string "“A short walk {UP_ARROW} way!”$"

Route112_Text_MtChimneySign:
	.string "Mt. Chimney\p"
	.string "“For Lavaridge Town or the summit,\n"
	.string "please take the Cable Car.”$"

Route112_Text_RouteSignLavaridge:
	.string "Route 112\n"
	.string "{LEFT_ARROW} Lavaridge Town$"

