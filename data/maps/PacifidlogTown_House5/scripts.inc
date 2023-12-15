PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, PacifidlogTown_House5_EventScript_GiveTM03
	end

PacifidlogTown_House5_EventScript_GiveTM03::
	giveitem ITEM_TM03
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "I can't see Mirage Island today…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Oh! Oh my!\n"
	.string "I can see Mirage Island today!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "I've been to a Mirage spot…\n"
	.string "I'm sure of it. But I forgot where\l"
	.string "it is…\p"
	.string "I used to be very good at\n"
	.string "remembering things…\p"
	.string "I'm so shocked that I can't\n"
	.string "remember…$"

