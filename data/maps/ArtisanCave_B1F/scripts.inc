ArtisanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, ArtisanCave_B1F_OnLoad
	.byte 0

ArtisanCave_B1F_OnTransition:
	setflag FLAG_LANDMARK_ARTISAN_CAVE
	end

ArtisanCave_B1F_OnLoad:
	call_if_set FLAG_HIDDEN_ITEM_KANGASKHANITE, ArtisanCave_B1F_Hide_Kangaskhanite
	end

ArtisanCave_B1F_Hide_Kangaskhanite::
    setmetatile 37, 17, METATILE_Cave_RockFloor, FALSE
    return

ArtisanCave_B1F_Kangaskhanite::
	goto_if_set FLAG_HIDDEN_ITEM_KANGASKHANITE, ArtisanCave_B1F_End_Kangaskhanite
	checkitemspace ITEM_KANGASKHANITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call ArtisanCave_B1F_Hide_Kangaskhanite
	special DrawWholeMapView
	giveitem ITEM_KANGASKHANITE
	setflag FLAG_HIDDEN_ITEM_KANGASKHANITE
ArtisanCave_B1F_End_Kangaskhanite::
	release
	end	

