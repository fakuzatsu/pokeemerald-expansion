InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_EventScript_YourBag::
	goto_if_set FLAG_SYS_ENFORCED_HARDMODE, InsideOfTruck_EventScript_YourBagHasCard
	msgbox InsideOfTruck_Text_ItsYourBag, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_TurnOverCard
	goto_if_eq VAR_RESULT, NO, InsideOfTruck_EventScript_PutCardBack
	end

InsideOfTruck_EventScript_TurnOverCard::
	msgbox InsideOfTruck_Text_AreYouSure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_AcceptChallenge
	goto_if_eq VAR_RESULT, NO, InsideOfTruck_EventScript_PutCardBack
	end

InsideOfTruck_EventScript_PutCardBack::
	msgbox InsideOfTruck_Text_YouPutItBack, MSGBOX_DEFAULT
	closemessage
	end

InsideOfTruck_EventScript_AcceptChallenge::
	setflag FLAG_SYS_ENFORCED_HARDMODE
	setflag FLAG_SYS_HARD_LEVEL_CAP
	msgbox InsideOfTruck_Text_YouPutItInYourBag, MSGBOX_DEFAULT
	closemessage
	end

InsideOfTruck_EventScript_YourBagHasCard::
	msgbox InsideOfTruck_Text_ItsYourBagWithCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_PutCardBack
	goto_if_eq VAR_RESULT, NO, InsideOfTruck_EventScript_LeaveCardInPocket
	end

InsideOfTruck_EventScript_LeaveCardInPocket::
	msgbox InsideOfTruck_Text_YouLeaveItThere, MSGBOX_DEFAULT
	closemessage
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo:
	.string "The box is printed with a Pokémon logo.\p"
	.string "It's a Pokémon brand moving and\n"
	.string "delivery service.$"

InsideOfTruck_Text_ItsYourBag:
	.string "It's your bag…\p"
	.string "The mover Pokémon will grab it with\n"
	.string "the rest of the stuff.\p"
	.string "…Huh?…\p"
	.string "Looks like there's a card on the floor\n"
	.string "next to it!\p"
	.string "The card reads:\n"
	.string "“Take my challenge?\l"
	.string " -Z”\p"
	.string "…Put the card in your bag?$"

InsideOfTruck_Text_AreYouSure:
	.string "{PLAYER} turned the card over.\p"
	.string "The backside reads:\n"
	.string "“Trainers and Pokémon who see this\l"
	.string "card will no longer go easy on you.”\p"
	.string "…Put the card in your bag anyways?$"

InsideOfTruck_Text_YouPutItBack:
	.string "{PLAYER} put the card back where\n"
	.string "it was.$"

InsideOfTruck_Text_YouPutItInYourBag:
	.string "{PLAYER} put the card in the bag…$"

InsideOfTruck_Text_ItsYourBagWithCard:
	.string "It's your bag…\p"
	.string "It has the strange card poking\n"
	.string "out of the front pocket.\p"
	.string "Take the strange card out?$"

InsideOfTruck_Text_YouLeaveItThere:
	.string "{PLAYER} left the strange card\n"
	.string "in the bag.$"

