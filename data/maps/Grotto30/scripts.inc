Grotto30_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Grotto30_OnTransition
	.byte 0

Grotto30_OnTransition::
	call_if_set FLAG_CAUGHT_ZACIAN, Grotto30_RemoveZacian
	call_if_set FLAG_CAUGHT_ZAMAZENTA, Grotto30_RemoveZamazenta
	end

Grotto30_RemoveZacian::
	setflag FLAG_TEMP_1
	return

Grotto30_RemoveZamazenta::
	setflag FLAG_TEMP_2
	return

Grotto30_EventScript_Altar::
	lock
	msgbox Grotto_30_Text_AltarInteraction, MSGBOX_DEFAULT
	checkitem ITEM_RUSTED_SWORD
	goto_if_eq VAR_RESULT, TRUE, Grotto30_EventScript_HasSwordCheckShield
	checkitem ITEM_RUSTED_SHIELD
	goto_if_eq VAR_RESULT, TRUE, Grotto30_EventScript_HasOnlyShield
	release
	end

Grotto30_EventScript_HasSwordCheckShield::
	checkitem ITEM_RUSTED_SHIELD
	goto_if_eq VAR_RESULT, TRUE, Grotto30_EventScript_HasSwordAndShield
Grotto30_EventScript_SwordInterupt::
	goto_if_set FLAG_TEMP_1, Grotto30_EventScript_AfterLegendary
	msgbox Grotto30_Text_PlaceSwordOnAltar, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Grotto30_EventScript_Zacian
	release
	end

Grotto30_EventScript_HasOnlyShield::
	goto_if_set FLAG_TEMP_2, Grotto30_EventScript_AfterLegendary
	msgbox Grotto30_Text_PlaceShieldOnAltar, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Grotto30_EventScript_Zamazenta
	release
	end

Grotto30_EventScript_HasSwordAndShield::
	goto_if_set FLAG_TEMP_1, Grotto30_EventScript_HasOnlyShield
	goto_if_set FLAG_TEMP_2, Grotto30_EventScript_SwordInterupt
	message Grotto30_Text_SwordShieldMultichoice
	waitmessage
	multichoice 17, 6, MULTI_SWORD_OR_SHIELD, FALSE
	switch VAR_RESULT
	case 0, Grotto30_EventScript_Zacian
	case 1, Grotto30_EventScript_Zamazenta
	case 2, Grotto30_EventScript_AfterLegendary
	case MULTI_B_PRESSED, Grotto30_EventScript_AfterLegendary
	end

Grotto30_EventScript_Zacian::
	message Grotto30_Text_ZacianCry
	playmoncry SPECIES_ZACIAN, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	seteventmon SPECIES_ZACIAN, 60, ITEM_RUSTED_SWORD
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Grotto30_EventScript_ZacianDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Grotto30_EventScript_ZacianDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Grotto30_EventScript_ZacianDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, Grotto30_EventScript_ZacianDefeated
	removeitem ITEM_RUSTED_SWORD
	setflag FLAG_TEMP_1
	setflag FLAG_CAUGHT_ZACIAN
	release
	end

Grotto30_EventScript_Zamazenta::
	message Grotto30_Text_ZamazentaCry
	playmoncry SPECIES_ZAMAZENTA, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	seteventmon SPECIES_ZAMAZENTA, 60, ITEM_RUSTED_SHIELD
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Grotto30_EventScript_ZamazentaDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Grotto30_EventScript_ZamazentaDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Grotto30_EventScript_ZamazentaDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, Grotto30_EventScript_ZamazentaDefeated
	removeitem ITEM_RUSTED_SHIELD
	setflag FLAG_TEMP_2
	setflag FLAG_CAUGHT_ZAMAZENTA
	release
	end

Grotto30_EventScript_ZacianDefeated::
	setflag FLAG_TEMP_1
	bufferspeciesname STR_VAR_1, SPECIES_ZACIAN
	msgbox gText_LegendaryRanAway, MSGBOX_DEFAULT
	goto Grotto30_EventScript_AfterLegendary
	end

Grotto30_EventScript_ZamazentaDefeated::
	setflag FLAG_TEMP_2
	bufferspeciesname STR_VAR_1, SPECIES_ZAMAZENTA
	msgbox gText_LegendaryRanAway, MSGBOX_DEFAULT
	goto Grotto30_EventScript_AfterLegendary
	end

Grotto30_EventScript_AfterLegendary::
	release
	end

Grotto_30_Text_AltarInteraction:
	.string "The text on the altar has long\n"
	.string "since worn away.$"

Grotto30_Text_PlaceSwordOnAltar:
	.string "Place the Rusted Sword on the\n"
	.string "altar?$"

Grotto30_Text_PlaceShieldOnAltar:
	.string "Place the Rusted Shield on the\n"
	.string "altar?$"

Grotto30_Text_SwordShieldMultichoice:
	.string "Place a rusted item on the altar?$"

Grotto30_Text_ZacianCry:
	.string "Lrrroooaaarrrd$"

Grotto30_Text_ZamazentaCry:
	.string "Grrrrrriiieeeld$"
