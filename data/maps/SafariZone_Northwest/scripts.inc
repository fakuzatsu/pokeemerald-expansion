SafariZone_Northwest_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SafariZone_Northwest_On_Load
	.byte 0

SafariZone_Northwest_On_Load:
	call_if_set FLAG_HIDDEN_ITEM_PINSIRITE, SafariZone_Northwest_Hide_Pinsirite
	end

SafariZone_Northwest_Hide_Pinsirite::
    setmetatile 31, 32, METATILE_General_Grass, FALSE
    return

SafariZone_Northwest_Pinsirite::
	goto_if_set FLAG_HIDDEN_ITEM_PINSIRITE, SafariZone_Northwest_End_Pinsirite
	checkitemspace ITEM_PINSIRITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call SafariZone_Northwest_Hide_Pinsirite
	special DrawWholeMapView
	giveitem ITEM_PINSIRITE
	setflag FLAG_HIDDEN_ITEM_PINSIRITE
SafariZone_Northwest_End_Pinsirite::
	release
	end	

SafariZone_Northwest_EventScript_Man::
	msgbox SafariZone_Northwest_Text_Man, MSGBOX_NPC
	end

