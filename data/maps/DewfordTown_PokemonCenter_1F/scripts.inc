.set LOCALID_NURSE, 1

DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Dewford_PokemonCenter_1F_EventScript_BattleMaster::
	goto Common_EventScript_PkmnCenterBattleMaster
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_MoveTutor::
	lock
	goto_if_set FLAG_RELEARN_AVAILABLE, DewfordTown_PokemonCenter_1F_EventScript_Explain
	msgbox DewfordTown_PokemonCenter_1F_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_PokemonCenter_1F_EventScript_YesToBattle
	msgbox DewfordTown_PokemonCenter_1F_Text_OhMaybeNextTime, MSGBOX_DEFAULT
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_Explain::
	msgbox DewfordTown_PokemonCenter_1F_Text_ExplainPower, MSGBOX_DEFAULT
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_YesToBattle::
	msgbox DewfordTown_PokemonCenter_1F_Text_TeachIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_EDWARD_TEACH, VerdantIsle_Text_TeachDefeat
	goto DewfordTown_PokemonCenter_1F_EventScript_WellIllTeachYou
	end

DewfordTown_PokemonCenter_1F_EventScript_WellIllTeachYou::
	msgbox DewfordTown_PokemonCenter_1F_Text_BeatMeFairAndSquare, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	playfanfare MUS_OBTAIN_ITEM
	message DewfordTown_PokemonCenter_1F_EventScript_YouCanTeachPokemon
	waitmessage
	waitfanfare
	setflag FLAG_RELEARN_AVAILABLE
	fadescreen FADE_FROM_BLACK
	msgbox DewfordTown_PokemonCenter_1F_Text_NowBackToWaiting, MSGBOX_DEFAULT
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_EventScript_Man::
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_Text_WouldYouLikeToBattle:
	.string "Ahoy! I be marooned here after I\n"
	.string "grounded me' ship on a rock over\l"
	.string "on Route 107.\p"
	.string "There be little to do here\n"
	.string "compared to Slateport.\p"
	.string "Yarrgh!\n"
	.string "I'm itching for a battle.\p"
	.string "How about it? If ye beat me, I'll\n"
	.string "teach ye a special power.$"

DewfordTown_PokemonCenter_1F_Text_ExplainPower::
	.string "That power I've given ye…\p"
	.string "Ye'll be able to teach Pokémon\n"
	.string "moves they had forgotten.\p"
	.string "Yarrgh!\p"
	.string "No need to find ye a Pokémon center,\n"
	.string "just interact with ye squad.\p"
	.string "… … …\p"
	.string "Just bear ye in mind, that Pokémon\n"
	.string "can't relearn TMs moves.$"

DewfordTown_PokemonCenter_1F_Text_OhMaybeNextTime::
	.string "Yarrgh!\p"
	.string "Well maybe next time.$"

DewfordTown_PokemonCenter_1F_Text_TeachIntro::
	.string "Yarrgh!\p"
	.string "Prepare yerself!$"

VerdantIsle_Text_TeachDefeat::
	.string "Ohohoh.\p"
	.string "There's more to ye than meet the\n"
	.string "eye, ain't there?$"

DewfordTown_PokemonCenter_1F_Text_BeatMeFairAndSquare::
	.string "Well ye beat me fair and square.\p"
	.string "As promised. I'll share me power\n"
	.string "with ye.\p"
	.string "So what ye do is…$"

DewfordTown_PokemonCenter_1F_EventScript_YouCanTeachPokemon::
	.string "{PLAYER} can now teach Pokémon\n"
	.string "forgotten moves.$"

DewfordTown_PokemonCenter_1F_Text_NowBackToWaiting::
	.string "Well ye gave me a good time.\p"
	.string "Back to me waiting I suppose…$"

DewfordTown_PokemonCenter_1F_Text_StoneCavern:
	.string "There's a stone cavern at the edge\n"
	.string "of town.\p"
	.string "I've heard you can find rare stones\n"
	.string "there.$"

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
	.string "Even if a Pokémon faints and can't\n"
	.string "battle, it can still use a move learned\l"
	.string "from a Hidden Machine (HM).$"

