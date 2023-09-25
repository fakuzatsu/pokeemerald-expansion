BerryTreeScript::
	special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Sparkling
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_CheckSoil
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_CheckBerryFullyGrown
	end

BerryTree_EventScript_Sparkling::
	lockall
	message BerryTree_Text_ExclamationPoint
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_CheckSoil::
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_ChooseBerryToPlant
	message BerryTree_Text_ItsSoftLoamySoil
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ChooseBerryToPlant::
	fadescreen FADE_TO_BLACK
	closemessage
	special Bag_ChooseBerry
	waitstate
	goto_if_eq VAR_ITEM_ID, 0, BerryTree_EventScript_CancelPlanting
	removeitem VAR_ITEM_ID
	call BerryTree_EventScript_PlantBerry

BerryTree_EventScript_CancelPlanting::
	release
	end

BerryTree_EventScript_CheckBerryStage1::
	lockall
	special ObjectEventInteractionGetBerryCountString
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater
	

BerryTree_EventScript_CheckBerryStage2::
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage3::
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage4::
	call BerryTree_EventScript_GetCareAdverb
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater

@ VAR_0x8005 here is the number of times watered
@ Buffered by ObjectEventInteractionGetBerryTreeData
BerryTree_EventScript_GetCareAdverb::
	goto_if_eq VAR_0x8005, 0, BerryTree_EventScript_SetAdverbPoor
	goto_if_eq VAR_0x8005, 4, BerryTree_EventScript_SetAdverbGreat
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGood
	return

BerryTree_EventScript_SetAdverbGreat::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGreat
	return

BerryTree_EventScript_SetAdverbPoor::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbPoor
	return

@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	goto BerryTree_EventScript_PickBerry

BerryTree_EventScript_PickBerry::
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	release
	end

BerryTree_EventScript_BerryPocketFull::
	message BerryTree_Text_BerryPocketFull
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ItemUsePlantBerry::
	lockall
	special ObjectEventInteractionGetBerryTreeData
	call BerryTree_EventScript_PlantBerry
	releaseall
	end

BerryTree_EventScript_DontWater::
	releaseall
	end

BerryTree_EventScript_ItemUseWailmerPail::
	special ObjectEventInteractionGetBerryTreeData
	lockall

BerryTree_EventScript_WaterBerry::
	waitmessage
	special ObjectEventInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	waitstate
	releaseall
	end

BerryTree_EventScript_PlantBerry::
	special ObjectEventInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries
	return

BerryTree_Text_ItsSoftLoamySoil:
	.string "It's soft, loamy soil.$"

BerryTree_Text_BerryGrowthStage1:
	.string "One {STR_VAR_1} was planted here.\n"
	.string "Water it with the WAILMER PAIL?$"

BerryTree_Text_BerryGrowthStage2:
	.string "{STR_VAR_1} has sprouted.\n"
	.string "Water it with the WAILMER PAIL?$"

BerryTree_Text_BerryGrowthStage3:
	.string "This {STR_VAR_1} plant is growing taller.\n"
	.string "Water it with the WAILMER PAIL?$"

BerryTree_Text_BerryGrowthStage4:
	.string "These {STR_VAR_1} flowers are blooming\n"
	.string "{STR_VAR_2}. Water them?$"

BerryTree_Text_CareAdverbGreat:
	.string "very beautifully$"

BerryTree_Text_CareAdverbPoor:
	.string "cutely$"

BerryTree_Text_CareAdverbGood:
	.string "prettily$"

BerryTree_Text_PickedTheBerry:
	.string "{PLAYER} picked the {STR_VAR_2} {STR_VAR_1}.$"

BerryTree_Text_BerryPocketFull:
	.string "The Bag's Berries POCKET is full.\p"
	.string "The {STR_VAR_1} couldn't be taken.$"

BerryTree_Text_ExclamationPoint:
	.string "!$"
