.set LOCALID_LANETTE, 1

Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_SYS_DETECTOR_MODE, Route114_LanettesHouse_EventScript_DetectorModeDescription
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_LANETTE, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route114_LanettesHouse_Text_OhIsThatDexNav, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LANETTE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_LANETTE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_LANETTE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox Route114_LanettesHouse_Text_UpgradeThisForYou, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message Route114_LanettesHouse_Text_DetectorModeUpgrade
	waitfanfare
	setflag FLAG_SYS_DETECTOR_MODE
	msgbox Route114_LanettesHouse_Text_DetectorModeDescription, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_DetectorModeDescription::
	msgbox Route114_LanettesHouse_Text_DetectorModeDescription, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "Lanette: Oh! {PLAYER}{KUN}!\p"
	.string "I'm sorry everything is so cluttered…\n"
	.string "When I get engrossed in research,\p"
	.string "things end up this way…$"

Route114_LanettesHouse_Text_OhIsThatDexNav:
	.string "Lanette: Is that?…\p"
	.string "A DexNav you say?…\p"
	.string "A fellow scientist showed me something\n"
	.string "like this once.\p"
	.string "I'd drafted some some plans to improve\n"
	.string "the device a back then.$"

Route114_LanettesHouse_Text_UpgradeThisForYou:
	.string "Lanette: Here they are!\p"
	.string "Now if I just…\p"
	.string "… … … … … … …\p"
	.string "There!$"

Route114_LanettesHouse_Text_DetectorModeUpgrade:
	.string "{PLAYER}'s DexNav was upgraded\n"
	.string "to include DETECTOR Mode!$"

Route114_LanettesHouse_Text_DetectorModeDescription:
	.string "With DETECTOR Mode. You will be able\n"
	.string "to find even more Pokémon!\p"
	.string "It searches for Pokémon passively as\n"
	.string "you wander around.\p"
	.string "You might even be able to find\n"
	.string "rare Pokémon you couldn't before!$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "It's Lanette's research notes.\n"
	.string "There's information about Boxes.\p"
	.string "Design Boxes to hold 30 Pokémon each.\p"
	.string "Each Trainer should be able to store\n"
	.string "420 Pokémon on the PC system.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "A marking system should be added to\n"
	.string "make Pokémon easier to organize.\p"
	.string "The name and wallpaper design of each\n"
	.string "Box will be made changeable to please\l"
	.string "the stored Pokémon.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "When storing a Pokémon, it should be\n"
	.string "sent to the Box inspected last.\p"
	.string "If that Box is full, the received\n"
	.string "Pokémon is stored in the next Box.\p"
	.string "In other words, when a Box is examined,\n"
	.string "it is automatically selected as the Box\l"
	.string "to which Pokémon are sent.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} closed the notebook.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "There's an e-mail from someone on\n"
	.string "the PC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played\n"
	.string "a part in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From BILL\n"
	.string "… … … … … … … …”$"

