Grotto_OnLoad:
    call Grotto_EventScript_GetReturnWarp
    end

Grotto_EventScript_GrottoInteract::
	msgbox Grotto_Text_FollowThePath, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Grotto_EventScript_CancelGrotto
    special SetGrottoWarp
    releaseall
    end

Grotto_EventScript_CancelGrotto::
    releaseall
    end

Grotto_EventScript_GetGrottoWarp::
    special GetGrottoWarp
    return

Grotto_EventScript_GetReturnWarp::
    special GetGrottoReturnWarp
    return

Grotto_Layout1_CloseBerryTreeArea::
	setmetatile 6, 5, METATILE_Rustboro_Grass_GrottoTreeDown, TRUE
	setmetatile 6, 4, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 4, 3, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 5, 3, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 6, 3, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 3, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 8, 3, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 4, 2, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 5, 2, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 6, 2, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 2, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 8, 2, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 4, 1, METATILE_General_Grass_TreeUp, TRUE
    setmetatile 5, 1, METATILE_General_Grass_TreeUp, TRUE
    setmetatile 6, 1, METATILE_General_Grass_TreeUp, TRUE
    setmetatile 7, 1, METATILE_General_Grass_TreeUp, TRUE
    setmetatile 8, 1, METATILE_General_Grass_TreeUp, TRUE
	return

Grotto_Layout1_SetEventStage::
    setmetatile 6, 8, METATILE_General_Grass, FALSE
    return

Grotto_Layout1_CloseLeftTreeArea::
    setmetatile 1, 7, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 1, 8, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 1, 9, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 2, 8, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 2, 9, METATILE_General_Grass_TreeOverlap, TRUE
    return

Grotto_Layout1_CloseRightTreeArea::
    setmetatile 11, 7, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 11, 8, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 11, 9, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 10, 8, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 10, 9, METATILE_General_Grass_TreeOverlap, TRUE
    return

Grotto_Layout2_CloseEntranceLeftPath::
    setmetatile 7, 10, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 11, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 12, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 6, 11, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 6, 10, METATILE_Rustboro_Grass_GrottoTreeUp, FALSE
    return

Grotto_Layout2_ClosePathThroughMiddle::
    setmetatile 7, 8, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 9, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 8, 8, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 8, 9, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 9, 8, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 9, 9, METATILE_General_Grass_TreeOverlap, TRUE
    return

Grotto_Layout2_CloseLeftPathToTop::
    setmetatile 4, 4, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 4, 5, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 4, 6, METATILE_Rustboro_Grass_GrottoTreeDown, TRUE
    setmetatile 5, 5, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 5, 4, METATILE_Rustboro_Grass_GrottoTreeUp, FALSE
    return

Grotto_Layout2_CloseRightPathToTop::
    setmetatile 12, 4, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 12, 5, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 12, 6, METATILE_Rustboro_Grass_GrottoTreeDown, TRUE
    setmetatile 11, 5, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 11, 4, METATILE_Rustboro_Grass_GrottoTreeUp, FALSE
    return

Grotto_Layout2_SetLeftEventStage::
    setmetatile 3, 8, METATILE_General_Grass, FALSE
    return

Grotto_Layout2_SetMiddleEventStage::
    setmetatile 8, 2, METATILE_General_Grass, FALSE
    return

Grotto_Layout3_CloseRightPath::
    setmetatile 7, 3, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 4, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 5, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 6, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 7, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 8, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 9, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 7, 10, METATILE_General_Grass_TreeOverlap, TRUE
    return

Grotto_Layout3_OpenMiddlePath::
    setmetatile 3, 7, METATILE_General_DarkGrass, FALSE
    setmetatile 3, 8, METATILE_General_DarkGrass, FALSE
    setmetatile 3, 9, METATILE_General_DarkGrass, FALSE
    setmetatile 3, 10, METATILE_General_DarkGrass, FALSE
    return

Grotto_Layout3_SetEventStage::
    setmetatile 3, 3, METATILE_General_Grass, FALSE
    return

Grotto_Layout4_CloseLeftTreeArea::
    setmetatile 1, 4, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 1, 5, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 1, 6, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 1, 7, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 2, 6, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 2, 5, METATILE_General_Grass_TreeUp, FALSE
    return

Grotto_Layout4_CloseRightTreeArea::
    setmetatile 9, 4, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 9, 5, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 9, 6, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 9, 7, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 8, 6, METATILE_General_Grass_TreeOverlap, TRUE
    setmetatile 8, 5, METATILE_General_Grass_TreeUp, FALSE
    return

Grotto_Text_FollowThePath:
	.string "Look!\n"
	.string "You've found a narrow path!\p"
	.string "Will you follow it?$"

