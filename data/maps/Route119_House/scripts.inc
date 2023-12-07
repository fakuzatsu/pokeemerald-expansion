Route119_House_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_House_OnTransition
	.byte 0

Route119_House_OnTransition:
	special GetDayOrNight
	goto_if_eq VAR_RESULT, 1, Route119_House_OnTransition_Night
	goto_if_eq VAR_RESULT, 0, Route119_House_OnTransition_Day
	end

Route119_House_OnTransition_Night:
	clearflag FLAG_HIDE_TRAINER_NIGHT
	return

Route119_House_OnTransition_Day:
	setflag FLAG_HIDE_TRAINER_NIGHT
	return

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_EventScript_Boy1::
	msgbox Route119_House_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "I heard about a cave called the CAVE\n"
	.string "OF ORIGIN.\p"
	.string "People rumor that the spirits of\n"
	.string "Pokémon are revived there. Could\l"
	.string "something like that really happen?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

Route119_House_Text_ThoughtFlyByCatchingBirdMons:
	.string "I thought you FLY by catching a whole\n"
	.string "flock of Bird Pokémon, and then\l"
	.string "hanging on to them somehow.\p"
	.string "But it turns out there's an HM move\n"
	.string "called FLY!\p"
	.string "I wish I'd known about that a long\n"
	.string "time ago…$"

