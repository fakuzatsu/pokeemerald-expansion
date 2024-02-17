.set LOCALID_RECEPTIONIST, 1
.set LOCALID_LINK_RECEPTIONIST, 2

VerdanturfTown_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_BattleTentLobby_SetContestAsVerdanturf
	.byte 0

VerdanturfTown_BattleTentLobby_SetContestAsVerdanturf:
	setflag FLAG_CONTEST_IS_VERDANTURF
	end

VerdanturfTown_BattleTentLobby_EventScript_AttractGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ATTRACT, VerdanturfTown_BattleTentLobby_EventScript_ReceivedAttract
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionRunsDeep, MSGBOX_DEFAULT
	giveitem ITEM_TM_ATTRACT
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ATTRACT
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_ReceivedAttract::
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_Boy1::
	msgbox VerdanturfTown_BattleTentLobby_Text_NoHyperOrMaster, MSGBOX_NPC
	end

VerdanturfTown_BattleTentLobby_EventScript_Boy2::
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_PickAWorthyPokemon, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_LittleBoy::
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_QuickAttackIsCool, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_BlendingLady::
	lock
	faceplayer
	msgbox VerdanturfTown_BattleTentLobby_Text_ContestHallIntense, MSGBOX_DEFAULT
	release
	end


VerdanturfTown_BattleTentLobby_Text_PickAWorthyPokemon:
	.string "If you're entering a cool contest,\n"
	.string "a cool Pokémon has to be the one!\p"
	.string "Pick a Pokémon worthy of the contest\n"
	.string "theme, and make sure it has the\l"
	.string "right set of moves to match.\p"
	.string "That's fundamental!$"

VerdanturfTown_BattleTentLobby_Text_QuickAttackIsCool:
	.string "Quick Attack strikes in an instant.\p"
	.string "Now that's a cool move!$"

VerdanturfTown_BattleTentLobby_Text_AttractionRunsDeep:
	.string "My feelings toward my Pokémon…\n"
	.string "The attraction runs deep…\p"
	.string "Oh, hi, you didn't see that, did you?\n"
	.string "Well, it doesn't matter.\p"
	.string "If you're entering a CONTEST, try this\n"
	.string "move on for size.$"

VerdanturfTown_BattleTentLobby_Text_AttractionMutual:
	.string "My feelings toward my Pokémon…\n"
	.string "I'm sure the attraction is mutual!\p"
	.string "They battle exactly the way I want\n"
	.string "them to!$"

VerdanturfTown_BattleTentLobby_Text_NoHyperOrMaster:
	.string "The contest hall here in Verdanturf\n"
	.string "is great, but you should see the one\l"
	.string "in Lilycove!\p"
	.string "They hold a much higher level of\n"
	.string "contest there!$"

VerdanturfTown_BattleTentLobby_Text_ContestHallIntense:
	.string "I went in through the entrance and\n"
	.string "took a look around the contest hall.\p"
	.string "Getting up on that big stage…\n"
	.string "I'd rather just make {POKEBLOCK}S!$"
