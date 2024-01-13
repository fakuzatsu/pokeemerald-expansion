.set LOCALID_ZAPDOS, 1
.set LOCALID_MOLTRES, 2
.set LOCALID_ARTICUNO, 3

RusturfCliff_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfCliff_OnTransition
	.byte 0

RusturfCliff_OnTransition:
	goto_if_unset FLAG_LEGENDARY_BIRDS_ENCOUNTERED, RusturfCliff_EventScript_LegendariesNotEncountered
	setflag FLAG_TEMP_1
	end

RusturfCliff_EventScript_LegendariesNotEncountered::
	setvar VAR_TEMP_1, 1
	end

RusturfCliff_EventScript_LegendaryBirdTrigger::
	playse SE_PIN
	applymovement LOCALID_ZAPDOS, Common_Movement_ExclamationMark
	applymovement LOCALID_MOLTRES, Common_Movement_ExclamationMark
	applymovement LOCALID_ARTICUNO, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOLTRES, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_ARTICUNO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 32
	message RusturfCliff_Text_LegendaryBirdCry
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	waitmoncry
	closemessage
	fadescreen FADE_TO_BLACK
	delay 16
	setvar VAR_0x8004, 4  @ num loops
	setvar VAR_0x8005, 20 @ delay
	special LoopWingFlapSE
	removeobject LOCALID_ZAPDOS
	removeobject LOCALID_MOLTRES
	removeobject LOCALID_ARTICUNO
	setflag FLAG_TEMP_1
	setflag FLAG_LEGENDARY_BIRDS_ENCOUNTERED
	delay 64
	fadescreen FADE_FROM_BLACK
	delay 32
	playse SE_M_DETECT
	dofieldeffectsparkle 17, 13, 0
	waitfieldeffect FLDEFF_SPARKLE
	release
	end

RusturfCliff_Text_LegendaryBirdCry:
	.string "Kyyuuu$"
