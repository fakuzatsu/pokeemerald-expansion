SafariZone_North_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SafariZone_North_On_Load
	.byte 0

SafariZone_North_On_Load:
	call_if_set FLAG_HIDDEN_ITEM_HERACRONITE, SafariZone_North_Hide_Heracronite
	end

SafariZone_North_Hide_Heracronite::
    setmetatile 5, 38, METATILE_General_Grass, FALSE
    return

SafariZone_North_Heracronite::
	goto_if_set FLAG_HIDDEN_ITEM_HERACRONITE, SafariZone_North_End_Heracronite
	checkitemspace ITEM_HERACRONITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call SafariZone_North_Hide_Heracronite
	special DrawWholeMapView
	giveitem ITEM_HERACRONITE
	setflag FLAG_HIDDEN_ITEM_HERACRONITE
SafariZone_North_End_Heracronite::
	release
	end	

SafariZone_North_EventScript_Fisherman::
	msgbox SafariZone_North_Text_Fisherman, MSGBOX_NPC
	end

SafariZone_North_EventScript_Man::
	msgbox SafariZone_North_Text_Man, MSGBOX_NPC
	end

