GraniteCave_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GraniteCave_B2F_OnLoad
	.byte 0

GraniteCave_B2F_OnLoad:
	call_if_set FLAG_HIDDEN_ITEM_STEELIXITE, GraniteCave_B2F_Hide_Steelixite
	end

GraniteCave_B2F_Hide_Steelixite::
    setmetatile 23, 3, METATILE_Cave_RockFloor, FALSE
    return

GraniteCave_B2F_Steelixite::
	goto_if_set FLAG_HIDDEN_ITEM_STEELIXITE, GraniteCave_B2F_End_Steelixite
	checkitemspace ITEM_STEELIXITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call GraniteCave_B2F_Hide_Steelixite
	special DrawWholeMapView
	giveitem ITEM_STEELIXITE
	setflag FLAG_HIDDEN_ITEM_STEELIXITE
GraniteCave_B2F_End_Steelixite::
	release
	end	

