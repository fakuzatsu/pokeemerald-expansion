FallarborTown_CozmosHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FallarborTown_CozmosHouse_OnLoad
	.byte 0

FallarborTown_CozmosHouse_OnLoad:
	goto_if_ne VAR_METEOR_FALLS_STATE, 2, FallarborTown_CozmosHouse_EventScript_HideSteven
	end

FallarborTown_CozmosHouse_EventScript_HideSteven::
	setflag FLAG_TEMP_5
	end

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_STARTER_MEGA_STONE_BACKUP, FallarborTown_CozmosHouse_EventScript_GiveStarterMegaStone
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GiveStarterMegaStone::
	msgbox FallarborTown_CosmosHouse_Text_GiveStarterMegaStone, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, FallarborTown_CozmosHouse_EventScript_CosmoGiveSceptileite
	case 1, FallarborTown_CozmosHouse_EventScript_CosmoGiveBlazikenite
	case 2, FallarborTown_CozmosHouse_EventScript_CosmoGiveSwampertite
	end

FallarborTown_CozmosHouse_EventScript_CosmoGiveSceptileite::
	giveitem ITEM_SCEPTILITE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_CozmosHouse_EventScript_NoMegaStoneSpaceInterupt
	clearflag FLAG_STARTER_MEGA_STONE_BACKUP
	release
	end

FallarborTown_CozmosHouse_EventScript_CosmoGiveBlazikenite::
	giveitem ITEM_BLAZIKENITE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_CozmosHouse_EventScript_NoMegaStoneSpaceInterupt
	clearflag FLAG_STARTER_MEGA_STONE_BACKUP
	release
	end

FallarborTown_CozmosHouse_EventScript_CosmoGiveSwampertite::
	giveitem ITEM_SWAMPERTITE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_CozmosHouse_EventScript_NoMegaStoneSpaceInterupt
	clearflag FLAG_STARTER_MEGA_STONE_BACKUP
	release
	end

FallarborTown_CozmosHouse_EventScript_NoMegaStoneSpaceInterupt::
	msgbox FallarborTown_CosmosHouse_Text_NoSpaceMegaStone, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_Steven::
	lock
	faceplayer
	msgbox FallarborTown_CozmosHouse_Text_Steven, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "Prof. COZMO: Oh…\n"
	.string "I never should have let myself be\l"
	.string "conned into telling Team Magma where\l"
	.string "you can find METEORITES…\p"
	.string "That METEORITE from METEOR FALLS…\n"
	.string "It's never going to be mine now…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh!\n"
	.string "Hah?\p"
	.string "That item…\p"
	.string "Could it be?\p"
	.string "Is it the METEORITE that Team Magma\n"
	.string "took from METEOR FALLS?\p"
	.string "Please, may I have it?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "Prof. COZMO: This TM, it represents\n"
	.string "my feeling of gratitude.\l"
	.string "Please use it!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "Prof. COZMO: Oh, I can't believe it.\n"
	.string "This is really, really great!\p"
	.string "This is really going to help my research!\p"
	.string "That Mega Stone I gave to you was found\n"
	.string "In a Meteorite just like this one.\p"
	.string "Perhaps I can unearth another discovery\n"
	.string "with this Meteorite too$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "Prof. COZMO: Oh, but…\n"
	.string "I'm crushed with disappointment…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "Prof. COZMO: Please, may I have that\n"
	.string "METEORITE?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "Prof. COZMO went off to METEOR FALLS\n"
	.string "on ROUTE 114 with some people from\l"
	.string "Team Magma.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Poor Prof. COZMO…\n"
	.string "He's so depressed… I feel sorry for him.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Look at Prof. COZMO…\n"
	.string "He's so happy! I think it's cute.$"

FallarborTown_CosmosHouse_Text_GiveStarterMegaStone:
	.string "Prof. COZMO: Oh hello {PLAYER}.\p"
	.string "Steven gave me this special stone back\n"
	.string "for safekeeping.\p"
	.string "Please take it with my thanks for \n"
	.string "saving me from Team Magma.$"

FallarborTown_CosmosHouse_Text_NoSpaceMegaStone:
	.string "Oh… You have no space for this\n"
	.string "special stone.$"

FallarborTown_CozmosHouse_Text_Steven:
	.string "Oh, {PLAYER}.\p"
	.string "Don't worry about Cosmo.\p"
	.string "I've already chased some Team\n"
	.string "Magma goons away.\p"
	.string "You should head up to Mt. Pyre.$"
