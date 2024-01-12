ColdStorage_1F_MapScripts::
	.byte 0

ColdStorage_1F_EventScript_Bin::
	goto_if_set FLAG_CHECKED_COLDSTORAGE_BIN, EventScript_EmptyTrashCan
	random 9
	goto_if_eq VAR_RESULT, 0, ColdStorage_1F_EventScript_Trubbish
	goto_if_eq VAR_RESULT, 1, ColdStorage_1F_EventScript_Trubbish
	goto_if_eq VAR_RESULT, 2, ColdStorage_1F_EventScript_Trubbish
	goto_if_eq VAR_RESULT, 3, ColdStorage_1F_EventScript_EscapeRope
	goto_if_eq VAR_RESULT, 4, ColdStorage_1F_EventScript_EscapeRope
	goto_if_eq VAR_RESULT, 5, ColdStorage_1F_EventScript_MaxEther
	goto_if_eq VAR_RESULT, 6, ColdStorage_1F_EventScript_MaxEther
	goto_if_eq VAR_RESULT, 7, ColdStorage_1F_EventScript_Calcium
	goto_if_eq VAR_RESULT, 8, ColdStorage_1F_EventScript_Iron
	goto EventScript_EmptyTrashCan
	release
	end

ColdStorage_1F_EventScript_Trubbish::
	setwildbattle SPECIES_TRUBBISH, 12
	waitse
	playmoncry SPECIES_TRUBBISH, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	dowildbattle
	setflag FLAG_CHECKED_COLDSTORAGE_BIN
	release
	end

ColdStorage_1F_EventScript_EscapeRope::
	giveitem ITEM_ESCAPE_ROPE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_CHECKED_COLDSTORAGE_BIN
	release
	end

ColdStorage_1F_EventScript_MaxEther::
	giveitem ITEM_MAX_ETHER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_CHECKED_COLDSTORAGE_BIN
	release
	end

ColdStorage_1F_EventScript_Calcium::
	giveitem ITEM_CALCIUM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_CHECKED_COLDSTORAGE_BIN
	release
	end

ColdStorage_1F_EventScript_Iron::
	giveitem ITEM_IRON
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_CHECKED_COLDSTORAGE_BIN
	release
	end

