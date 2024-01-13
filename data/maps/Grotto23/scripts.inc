Grotto23_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto23_OnLoad
	.byte 0

Grotto23_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout1_CloseBerryTreeArea
	end

Grotto23_EventScript_HexLady::
	lock
	faceplayer
	goto_if_set FLAG_EVENT_GROTTO_23_HEX_LADY, Grotto23_EventScript_GhostsAreMyFriends
	goto_if_set FLAG_TEMP_1, Grotto23_DontLikeGhostTypes
	goto_if_set FLAG_TEMP_2, Grotto23_LieAboutLikingGhostTypes
	msgbox Grotto23_Text_GhostTypesAreMyFavourite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Grotto23_EventScript_HexLadyCheckGhostTypeYes
	goto Grotto23_EventScript_HexLadyCheckGhostTypeNo
	end

Grotto23_EventScript_HexLadyCheckGhostTypeYes::
	special IsGhostTypeInParty
	goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGhostMons
	msgbox Grotto23_Text_RightGhostsAreAwesome, MSGBOX_DEFAULT
	msgbox Grotto23_Text_YouCanHaveThis, MSGBOX_DEFAULT
	setflag FLAG_EVENT_GROTTO_23_HEX_LADY
	giveitem ITEM_RELIC_STATUE
	release
	end

Grotto23_EventScript_HexLadyCheckGhostTypeNo::
	special IsGhostTypeInParty
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_HasGhostMons
	msgbox Grotto23_Text_HuhAtLeastYoureHonest, MSGBOX_DEFAULT
	msgbox Grotto23_Text_YouCanHaveThis, MSGBOX_DEFAULT
	setflag FLAG_EVENT_GROTTO_23_HEX_LADY
	giveitem ITEM_RELIC_STATUE
	release
	end

Route123_EventScript_NoGhostMons::
	msgbox Grotto23_Text_YouCantLikeThemThatMuch, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	release
	end

Route123_EventScript_HasGhostMons::
	msgbox Grotto23_Text_WowThatsRude, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Grotto23_EventScript_GhostsAreMyFriends::
	msgbox Grotto23_Text_GhostsAreMyFriends, MSGBOX_DEFAULT

Grotto23_DontLikeGhostTypes::
	msgbox Grotto23_Text_DontLikeGhostTypes, MSGBOX_DEFAULT
	release
	end

Grotto23_LieAboutLikingGhostTypes::
	msgbox Grotto23_Text_LieAboutLikingGhostTypes, MSGBOX_DEFAULT
	release
	end

Grotto23_Text_GhostTypesAreMyFavourite:
	.string "Ghost types are my favourite\n"
	.string "Pokémon.\p"
	.string "They get to go where they want and\n"
	.string "give people fights!\p"
	.string "Do you like Ghost Pokémon?$"

Grotto23_Text_YouCantLikeThemThatMuch:
	.string "You mustn't like them that much\n"
	.string "if you don't have any with you.$"

Grotto23_Text_WowThatsRude:
	.string "Huh? Then why are you travelling\n"
	.string "with a Ghost type Pokémon?$"

Grotto23_Text_RightGhostsAreAwesome:
	.string "Right? Ghosts are awesome.$"

Grotto23_Text_HuhAtLeastYoureHonest:
	.string "Huh… Well at least you're honest.$"

Grotto23_Text_YouCanHaveThis:
	.string "You can have this.$"

Grotto23_Text_GhostsAreMyFriends:
	.string "Ghosts are my friends because they\n"
	.string "are always there for me.\p"
	.string "tee-hee.$"

Grotto23_Text_DontLikeGhostTypes:
	.string "You mustn't like Ghost types if\n"
	.string "you don't have any with you.$"

Grotto23_Text_LieAboutLikingGhostTypes:
	.string "Kinda rude to say you don't like\n"
	.string "Ghost types when you have one.$"
