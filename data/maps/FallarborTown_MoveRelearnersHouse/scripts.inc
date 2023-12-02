.set LOCALID_MOVE_RELEARNER, 1

FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskForgetExperience
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImForgetful, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskForgetExperience
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskForgetExperience::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantAMonToForget, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_EggsCantForget
	goto FallarborTown_MoveRelearnersHouse_EventScript_ForgetEVs
	end

FallarborTown_MoveRelearnersHouse_EventScript_ForgetEVs::
	fadescreen FADE_TO_BLACK
	delay 8
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	setvar VAR_0x8000, 0
	special SetHpEvs
	setvar VAR_0x8001, 0
	special SetAtkEvs
	setvar VAR_0x8002, 0
	special SetDefEvs
	setvar VAR_0x8003, 0
	special SetSpdEvs
	setvar VAR_0x8005, 0
	special SetSpAtkEvs
	setvar VAR_0x8006, 0
	special SetSpDefEvs
	delay 20
	fadescreen FADE_FROM_BLACK
	msgbox FallarborTown_MoveRelearnersHouse_Text_AndDone, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_EggsCantForget::
	msgbox FallarborTown_MoveRelearnersHouse_Text_EggsCantForget, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImForgetful:
	.string "I've been collecting Heart Scales\n"
	.string "for so long, I've forgotten why!\p"
	.string "It's blissfully refreshing!\p"
	.string "Say… do you have any Heart Scales\n"
	.string "to give me?\p"
	.string "If you do, I can help a Pokémon\n"
	.string "forget their combat training so\l"
	.string "they can feel refreshed too!\p"
	.string "How about it?$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantAMonToForget:
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness Heart Scale!\p"
	.string "So, you want me to help a Pokémon\n"
	.string "forget their combat training?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Which Pokémon needs to forget?$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one Heart Scale\n"
	.string "in exchange.$"

FallarborTown_MoveRelearnersHouse_Text_AndDone:
	.string "…And… Done!$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "If your Pokémon need to feel refreshed,\n"
	.string "come back with a Heart Scale.$"

FallarborTown_MoveRelearnersHouse_Text_EggsCantForget:
	.string "Hunh? There's no way I can make an\n"
	.string "egg forget anything!$"

