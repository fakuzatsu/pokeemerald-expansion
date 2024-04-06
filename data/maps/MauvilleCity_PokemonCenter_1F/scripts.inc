.set LOCALID_NURSE, 1

MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_BattleMaster::
	goto Common_EventScript_PkmnCenterBattleMaster
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_EvolutionGuru::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_ImTheEvolutionGuru, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_EvolutionGuruInspect
MauvilleCity_PokemonCenter_1F_EventScript_RejectEvolutionGuru::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RejectEvolutionGuru, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_EvolutionGuruInspect::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WhichPokemonInspect, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_PokemonCenter_1F_EventScript_CheckEvolutionStone
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_PokemonCenter_1F_EventScript_RejectEvolutionGuru
	end

MauvilleCity_PokemonCenter_1F_EventScript_CheckEvolutionStone::
	specialvar VAR_0x8008, CheckEvolutionStone
	bufferitemname STR_VAR_2, VAR_0x8008
	goto_if_eq VAR_0x8008, ITEM_NONE, MauvilleCity_PokemonCenter_1F_EventScript_PokemonDoesntEvolveWithStone
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatPokemonEvolvesWithThisStone, MSGBOX_DEFAULT
	goto_if_set FLAG_DAILY_GURU_EVOLUTION_STONE, MauvilleCity_PokemonCenter_1F_EventScript_CannotPartWithAnotherStoneToday
	showmoneybox 0, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_EvolutionGuruSellStone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PayForEvolutionStone
	hidemoneybox
	msgbox MauvilleCity_PokemonCenter_1F_Text_EvolutionGuruForTheBest, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CannotPartWithAnotherStoneToday::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CannotPartWithAnotherStoneToday, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PokemonDoesntEvolveWithStone::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatPokemonDoesntEvolveWithStone
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PayForEvolutionStone::
	checkitemspace VAR_0x8008 
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForEvolutionStone
	removemoney 2000
	updatemoneybox
	giveitem VAR_0x8008
	hidemoneybox
	msgbox MauvilleCity_PokemonCenter_1F_Text_OhMyPoorXStone, MSGBOX_DEFAULT
	setflag FLAG_DAILY_GURU_EVOLUTION_STONE
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForEvolutionStone::
	hidemoneybox
	msgbox MauvilleCity_PokemonCenter_1F_Text_EvolutionGuruNoSpace, MSGBOX_DEFAULT
	msgbox MauvilleCity_PokemonCenter_1F_Text_EvolutionGuruForTheBest, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Kirlia::
	msgbox MauvilleCity_PokemonCenter_1F_Text_Kirlia, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "When I accessed the RECORD CORNER,\n"
	.string "the data for what's hot in DEWFORD\l"
	.string "got updated.\p"
	.string "Now that bit of data is the same\n"
	.string "as my friend's!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "A RECORD CORNER opened upstairs in\n"
	.string "the Pokémon CENTER.\p"
	.string "I don't know what it's about, but it\n"
	.string "sounds fun. I'll go check it out!$"

MauvilleCity_PokemonCenter_1F_Text_ImTheEvolutionGuru:
	.string "I collect many special stones that\n"
	.string "unlock the power of certain Pokémon.\p"
	.string "People call me the Evolution Guru.\p"
	.string "Would you like me to tell you which\n"
	.string "stone your Pokémon need to evolve?$"

MauvilleCity_PokemonCenter_1F_Text_RejectEvolutionGuru:
	.string "You have no interest in evolution\n"
	.string "stones?\p"
	.string "A pity…$"

MauvilleCity_PokemonCenter_1F_Text_WhichPokemonInspect:
	.string "Which Pokémon would you like me to\n"
	.string "inspect?$"

MauvilleCity_PokemonCenter_1F_Text_ThatPokemonEvolvesWithThisStone:
	.string "That Pokémon evolves with a\n"
	.string "{STR_VAR_2}.$"

MauvilleCity_PokemonCenter_1F_Text_ThatPokemonDoesntEvolveWithStone:
	.string "That Pokémon doesn't evolve using an\n"
	.string "evolution stone.\p"
	.string "It must feel so sad.$"

MauvilleCity_PokemonCenter_1F_Text_EvolutionGuruSellStone:
	.string "I happen to have one with me.\p"
	.string "Would you care to purchase one of my\n"
	.string "{STR_VAR_2}s for ¥2000?$"

MauvilleCity_PokemonCenter_1F_Text_EvolutionGuruForTheBest:
	.string "Probably for the best…\p"
	.string "I don't quite know if I could part\n"
	.string "with an item from my collection.$"

MauvilleCity_PokemonCenter_1F_Text_CannotPartWithAnotherStoneToday:
	.string "I happen to have one with me.\p"
	.string "Though, I couldn't bear to part with\n"
	.string "another item from my collection today.$"

MauvilleCity_PokemonCenter_1F_Text_OhMyPoorXStone:
	.string "Oh my poor {STR_VAR_2}…\p"
	.string "I can only bear to part with it\n"
	.string "knowing it is in good hands.$"

MauvilleCity_PokemonCenter_1F_Text_EvolutionGuruNoSpace:
	.string "Oh! You have no space for this stone.$"

MauvilleCity_PokemonCenter_1F_Text_Kirlia:
	.string "Kirliiii$"
