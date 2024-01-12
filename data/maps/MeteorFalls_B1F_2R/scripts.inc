MeteorFalls_B1F_2R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_B1F_2R_OnLoad
	.byte 0

MeteorFalls_B1F_2R_OnLoad:
	call_if_set FLAG_HIDDEN_ITEM_SALAMENCITE, MeteorFalls_B1F_2R_Hide_Salamencite
	end

MeteorFalls_B1F_2R_Hide_Salamencite::
    setmetatile 6, 3, METATILE_MeteorFalls_meteorFloor, FALSE
    return

MeteorFalls_B1F_2R_Salamencite::
	goto_if_set FLAG_HIDDEN_ITEM_SALAMENCITE, MeteorFalls_B1F_2R_End_Salamencite
	checkitemspace ITEM_SALAMENCITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call MeteorFalls_B1F_2R_Hide_Salamencite
	special DrawWholeMapView
	giveitem ITEM_SALAMENCITE
	setflag FLAG_HIDDEN_ITEM_SALAMENCITE
MeteorFalls_B1F_2R_End_Salamencite::
	release
	end	

