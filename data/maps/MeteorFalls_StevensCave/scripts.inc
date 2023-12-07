.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MeteorFalls_StevensCave_OnEntry
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MeteorFalls_StevensCave_OnEntry
	.byte 0

MeteorFalls_StevensCave_OnEntry::
	goto_if_ge VAR_STEVEN_STONE_METEOR_FALLS, 3, MeteorFalls_StevensCave_EventScript_SetObjectPostForStevenPostDeoxys
	goto_if_ge VAR_STEVEN_STONE_METEOR_FALLS, 2, MeteorFalls_StevensCave_EventScript_SetObjectPosForStevenPreDeoxys
	end

MeteorFalls_StevensCave_EventScript_SetObjectPosForStevenPreDeoxys::
	setobjectxy LOCALID_STEVEN, 20, 8
	turnobject LOCALID_STEVEN, DIR_NORTH
	end

MeteorFalls_StevensCave_EventScript_SetObjectPostForStevenPostDeoxys::
	setobjectxy LOCALID_STEVEN, 25, 8
	turnobject LOCALID_STEVEN, DIR_EAST
	end

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_ge VAR_STEVEN_STONE_METEOR_FALLS, 3, MeteorFalls_StevensCave_SoYouFacedIt
	goto_if_ge VAR_STEVEN_STONE_METEOR_FALLS, 2, MeteorFalls_StevensCave_GoodLuck
	goto_if_ge VAR_STEVEN_STONE_METEOR_FALLS, 1, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setvar VAR_STEVEN_STONE_METEOR_FALLS, 1
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, MeteorFalls_StevensCave_Movement_StepAside
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_GoodLuck, MSGBOX_DEFAULT
	setvar VAR_STEVEN_STONE_METEOR_FALLS, 2
	release
	end

MeteorFalls_StevensCave_GoodLuck::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_GoodLuck, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Movement_StepAside:
	walk_in_place_faster_down
	delay_8
	walk_down
	delay_8
	walk_in_place_faster_up

MeteorFalls_StevensCave_SoYouFacedIt::
	lock
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_SoYouFacedIt, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Oh, wow, {PLAYER}{KUN}.\n"
	.string "I'm amazed you knew where to find me.\p"
	.string "I sought this place out after everything\n"
	.string "settled down in SOOTOPOLIS.\p"
	.string "As you might know, this place is full of\n"
	.string "rarities from space thanks to meteors.\p"
	.string "But there is something else here.\p"
	.string "Other than just rare stones…\p"
	.string "I have to know that you are ready for it.\p"
	.string "Okay, {PLAYER}{KUN}, if you're going to mount\n"
	.string "a serious challenge, expect the worst!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "You…\n"
	.string "I had no idea you'd become so strong…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Come to think of it, ever since\n"
	.string "our paths first crossed in GRANITE\l"
	.string "CAVE in DEWFORD, I had this feeling.\p"
	.string "I thought that you would eventually\n"
	.string "become the Champion.\p"
	.string "My predictions usually come true.\p"
	.string "I suppose if anybody could face\n"
	.string "what lies ahead, it would be you.\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MeteorFalls_StevensCave_Text_GoodLuck:
	.string "STEVEN: Good luck.$"

MeteorFalls_StevensCave_Text_SoYouFacedIt:
	.string "STEVEN: So you faced the thing at\n"
	.string "the peak of the mountain?\p"
	.string "You truly are remarkable.\p"
	.string "The Pokémon itself reminds me of\n"
	.string "MOSSDEEP SPACE CENTER.\p"
	.string "Where battled together, a short\n"
	.string "while ago.\p"
	.string "Perhaps they would be interested\n"
	.string "in seeing it.$"

