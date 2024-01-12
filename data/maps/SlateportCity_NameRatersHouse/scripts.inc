SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_FortuneTeller::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_LikeToHearYourFortune, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_YesToFortune
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_YesToFortune::
	msgbox SlateportCity_NameRatersHouse_Text_LetsSeeThen, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, SlateportCity_NameRatersHouse_EventScript_NoKnuckleBadge
	goto_if_unset FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_NameRatersHouse_EventScript_HaventMetDock
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_NameRatersHouse_EventScript_HaventMetStern
	goto_if_unset FLAG_DEFEATED_WALLY_MAUVILLE, SlateportCity_NameRatersHouse_EventScript_RivalFightUpcoming
	goto_if_unset FLAG_BADGE03_GET, SlateportCity_NameRatersHouse_EventScript_NoDynamoBadge
	goto_if_unset FLAG_RECEIVED_HM_ROCK_SMASH, SlateportCity_NameRatersHouse_EventScript_HaventGotRockSmash
	goto_if_unset FLAG_MET_ARCHIE_METEOR_FALLS, SlateportCity_NameRatersHouse_EventScript_MeteorFallsUncleared
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, SlateportCity_NameRatersHouse_EventScript_TeamMagmaAtMtChimney
	goto_if_unset FLAG_BADGE04_GET, SlateportCity_NameRatersHouse_EventScript_NoHeatBadge
	goto_if_unset FLAG_BADGE05_GET, SlateportCity_NameRatersHouse_EventScript_NoBalanceBadge
	goto_if_eq VAR_ROUTE118_STATE, 0, SlateportCity_NameRatersHouse_EventScript_HaventMetStevenAtRoute118
	goto_if_unset FLAG_HIDE_ROUTE_119_TEAM_AQUA, SlateportCity_NameRatersHouse_EventScript_TeamAquaAtWeatherInstitute
	goto_if_unset FLAG_BADGE06_GET, SlateportCity_NameRatersHouse_EventScript_NoFeatherBadge
	goto_if_unset FLAG_RECEIVED_DEVON_SCOPE, SlateportCity_NameRatersHouse_EventScript_NoDevonScope
	goto_if_unset FLAG_RECEIVED_RED_OR_BLUE_ORB, SlateportCity_NameRatersHouse_EventScript_TeamAquaAtMtPyre
	goto_if_unset FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, SlateportCity_NameRatersHouse_EventScript_HaventAwokenGroudon
	goto_if_unset FLAG_MET_TEAM_AQUA_HARBOR, SlateportCity_NameRatersHouse_EventScript_TeamAquaStealSub
	goto_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_NameRatersHouse_EventScript_TeamAquaUseSub
	goto_if_unset FLAG_BADGE07_GET, SlateportCity_NameRatersHouse_EventScript_NoMindBadge
	goto_if_unset FLAG_DEFEATED_MAGMA_SPACE_CENTER, SlateportCity_NameRatersHouse_EventScript_TeamMagmaAtSpaceCenter
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SlateportCity_NameRatersHouse_EventScript_HaventAwokenKyogre
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SlateportCity_NameRatersHouse_EventScript_HaventSeenLegendaryBattle
	goto_if_unset FLAG_WALLACE_GOES_TO_SKY_PILLAR, SlateportCity_NameRatersHouse_EventScript_HaventMetWallace
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SlateportCity_NameRatersHouse_EventScript_HaventAwokenRayquaza
	goto_if_set FLAG_LEGENDARIES_IN_SOOTOPOLIS, SlateportCity_NameRatersHouse_EventScript_LegendariesStillPresent
	goto_if_unset FLAG_BADGE08_GET, SlateportCity_NameRatersHouse_EventScript_NoRainBadge
	goto_if_unset FLAG_VISITED_EVER_GRANDE_CITY, SlateportCity_NameRatersHouse_EventScript_NeverBeenToEverGrande
	goto_if_unset FLAG_DEFEATED_WALLY_VICTORY_ROAD, SlateportCity_NameRatersHouse_EventScript_HaventBeatenWally
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_NameRatersHouse_EventScript_HaventBeatenLeague
	goto_if_unset FLAG_HIDDEN_ITEM_SABLENITE, SlateportCity_NameRatersHouse_EventScript_GiveSablenite
	goto SlateportCity_NameRatersHouse_EventScript_ChooseRandomPostGameEvent

SlateportCity_NameRatersHouse_EventScript_NoKnuckleBadge::
	msgbox SlateportCity_NameRatersHouse_Text_NoKnuckleBadge, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventMetDock::
	msgbox SlateportCity_NameRatersHouse_Text_HaventMetDock, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventMetStern::
	msgbox SlateportCity_NameRatersHouse_Text_HaventMetStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RivalFightUpcoming::
	msgbox SlateportCity_NameRatersHouse_Text_RivalFightUpcoming, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NoDynamoBadge::
	msgbox SlateportCity_NameRatersHouse_Text_NoDynamoBadge, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventGotRockSmash::
	msgbox SlateportCity_NameRatersHouse_Text_HaventGotRockSmash, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_MeteorFallsUncleared::
	msgbox SlateportCity_NameRatersHouse_Text_MeteorFallsUncleared, MSGBOX_DEFAULT
	release

	end
SlateportCity_NameRatersHouse_EventScript_TeamMagmaAtMtChimney::
	msgbox SlateportCity_NameRatersHouse_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NoHeatBadge::
	msgbox SlateportCity_NameRatersHouse_Text_NoHeatBadge, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NoBalanceBadge::
	msgbox SlateportCity_NameRatersHouse_Text_NoBalanceBadge, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventMetStevenAtRoute118::
	msgbox SlateportCity_NameRatersHouse_Text_HaventMetStevenAtRoute118, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_TeamAquaAtWeatherInstitute::
	msgbox SlateportCity_NameRatersHouse_Text_TeamAquaAtWeatherInstitute, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NoFeatherBadge::
	msgbox SlateportCity_NameRatersHouse_Text_NoFeatherBadge, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NoDevonScope::
	msgbox SlateportCity_NameRatersHouse_Text_NoDevonScope, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_TeamAquaAtMtPyre::
	msgbox SlateportCity_NameRatersHouse_Text_TeamAquaAtMtPyre, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventAwokenGroudon::
	msgbox SlateportCity_NameRatersHouse_Text_HaventAwokenGroudon, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_TeamAquaStealSub::
	msgbox SlateportCity_NameRatersHouse_Text_TeamAquaStealSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_TeamAquaUseSub::
	msgbox SlateportCity_NameRatersHouse_Text_TeamAquaUseSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NoMindBadge::
	msgbox SlateportCity_NameRatersHouse_Text_NoMindBadge, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_TeamMagmaAtSpaceCenter::
	msgbox SlateportCity_NameRatersHouse_Text_TeamMagmaAtSpaceCenter, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventAwokenKyogre::
	msgbox SlateportCity_NameRatersHouse_Text_HaventAwokenKyogre, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventSeenLegendaryBattle::
	msgbox SlateportCity_NameRatersHouse_Text_HaventSeenLegendaryBattle, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventMetWallace::
	msgbox SlateportCity_NameRatersHouse_Text_HaventMetWallace, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventAwokenRayquaza::
	msgbox SlateportCity_NameRatersHouse_Text_HaventAwokenRayquaza, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_LegendariesStillPresent::
	msgbox SlateportCity_NameRatersHouse_Text_LegendariesStillPresent, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NoRainBadge::
	msgbox SlateportCity_NameRatersHouse_Text_NoRainBadge, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NeverBeenToEverGrande::
	msgbox SlateportCity_NameRatersHouse_Text_NeverBeenToEverGrande, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventBeatenWally::
	msgbox SlateportCity_NameRatersHouse_Text_HaventBeatenWally, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_HaventBeatenLeague::
	msgbox SlateportCity_NameRatersHouse_Text_HaventBeatenLeague, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_GiveSablenite::
	msgbox SlateportCity_NameRatersHouse_Text_ImpressiveFortune, MSGBOX_DEFAULT
	checkitemspace ITEM_SABLENITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_SABLENITE
	setflag FLAG_HIDDEN_ITEM_SABLENITE
	msgbox SlateportCity_NameRatersHouse_Text_AnywaysWhereWasI, MSGBOX_DEFAULT
	goto SlateportCity_NameRatersHouse_EventScript_ChooseRandomPostGameEvent

SlateportCity_NameRatersHouse_EventScript_ChooseRandomPostGameEvent::
	msgbox SlateportCity_NameRatersHouse_EventScript_PostGameTextLead, MSGBOX_DEFAULT
	random 9
	goto_if_eq VAR_RESULT, 0, SlateportCity_NameRatersHouse_EventScript_PostGameBattleFrontier
	goto_if_eq VAR_RESULT, 1, SlateportCity_NameRatersHouse_EventScript_PostGameEliteFourRematch
	goto_if_eq VAR_RESULT, 2, SlateportCity_NameRatersHouse_EventScript_PostGameGymLeaderRematch
	goto_if_eq VAR_RESULT, 3, SlateportCity_NameRatersHouse_EventScript_PostGameCatchPokemon
	goto_if_eq VAR_RESULT, 4, SlateportCity_NameRatersHouse_EventScript_PostGamePreformInContest
	goto_if_eq VAR_RESULT, 5, SlateportCity_NameRatersHouse_EventScript_PostGameSpecialSootopolisBattle
	goto_if_eq VAR_RESULT, 6, SlateportCity_NameRatersHouse_EventScript_PostGameStevenBattle
	goto_if_eq VAR_RESULT, 7, SlateportCity_NameRatersHouse_EventScript_PostGameCourtneyBattle
	goto_if_eq VAR_RESULT, 8, SlateportCity_NameRatersHouse_EventScript_PostGameShellyBattle
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PostGameBattleFrontier:
	msgbox SlateportCity_NameRatersHouse_Text_PostGameBattleFrontier, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PostGameEliteFourRematch:
	msgbox SlateportCity_NameRatersHouse_Text_PostGameEliteFourRematch, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PostGameGymLeaderRematch:
	msgbox SlateportCity_NameRatersHouse_Text_PostGameGymLeaderRematch, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PostGameCatchPokemon:
	msgbox SlateportCity_NameRatersHouse_Text_PostGameCatchPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PostGamePreformInContest:
	msgbox SlateportCity_NameRatersHouse_Text_PostGamePreformInContest, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PostGameSpecialSootopolisBattle:
	msgbox SlateportCity_NameRatersHouse_Text_PostGameSpecialSootopolisBattle, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PostGameStevenBattle:
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, SlateportCity_NameRatersHouse_EventScript_PostGameCatchPokemon
	release
	end

SlateportCity_NameRatersHouse_EventScript_PostGameCourtneyBattle:
	goto_if_set FLAG_DEFEATED_POSTGAME_COURTNEY, SlateportCity_NameRatersHouse_EventScript_PostGameBattleFrontier
	msgbox SlateportCity_NameRatersHouse_Text_PostGameCourtneyBattle, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PostGameShellyBattle:
	goto_if_set FLAG_DEFEATED_POSTGAME_SHELLY, SlateportCity_NameRatersHouse_EventScript_PostGameEliteFourRematch
	msgbox SlateportCity_NameRatersHouse_Text_PostGameShellyBattle, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_LikeToHearYourFortune:
	.string "Hi, hi! I'm the Fortune Teller!\p"
	.string "I shall be pleased to tell you\n"
	.string "your future.$"

SlateportCity_NameRatersHouse_Text_LetsSeeThen:
	.string "Let's see then…\p"
	.string "… … …\p"
	.string "Hm…$"

SlateportCity_NameRatersHouse_Text_NoKnuckleBadge:
	.string "It seems you have a lot ahead\n"
	.string "of you.\p"
	.string "I see rolling waves and a\n"
	.string "dark room.\p"
	.string "A fight for a badge.\p"
	.string "You will find success within\n"
	.string "your mind.$"

SlateportCity_NameRatersHouse_Text_HaventMetDock:
	.string "It seems you have a lot ahead\n"
	.string "of you.\p"
	.string "A room bustling with action\p"
	.string "I hear the rolling of the\n"
	.string "Ocean waves.\p"
	.string "Someone important awaits you\p"
	.string "to the South-East.$"

SlateportCity_NameRatersHouse_Text_HaventMetStern:
	.string "It seems you have a lot ahead\n"
	.string "of you.\p"
	.string "You are someplace filled with\n"
	.string "plenty of history.\p"
	.string "An important person awaits you\n"
	.string "there… but…\p"
	.string "Be cautious. As there are those\n"
	.string "who would oppose you.$"

SlateportCity_NameRatersHouse_Text_RivalFightUpcoming:
	.string "It seems you have a lot ahead\n"
	.string "of you.\p"
	.string "There is something important…\p"
	.string "Friend or foe?\p"
	.string "Perhaps both?\p"
	.string "I see a challenge from somebody\n"
	.string "familiar.\p"
	.string "Prepare accordingly.$"

SlateportCity_NameRatersHouse_Text_NoDynamoBadge:
	.string "I see some experience within.\n"
	.string "But maturing still.\p"
	.string "I see an astounding energy\n"
	.string "crackling around you.\p"
	.string "A fight for a badge\p"
	.string "You will find success within\n"
	.string "the ground.$"

SlateportCity_NameRatersHouse_Text_HaventGotRockSmash:
	.string "I see some experience within.\n"
	.string "But maturing still.\p"
	.string "A power lies before you. Just\n"
	.string "within reach.\p"
	.string "In a bustling place of progress.\p"
	.string "You must merely reach out and\n"
	.string "take it.$"

SlateportCity_NameRatersHouse_Text_MeteorFallsUncleared:
	.string "I see some experience within.\n"
	.string "But maturing still.\p"
	.string "There is a danger ahead.\p"
	.string "Awaiting you in a place bathed\n"
	.string "by the stars.\p"
	.string "Be careful how you proceed\n"
	.string "on your journey.$"

SlateportCity_NameRatersHouse_Text_TeamMagmaAtMtChimney:
	.string "I see some experience within.\n"
	.string "But maturing still.\p"
	.string "Yet more danger awaits you.\p"
	.string "To be found in a place filled\n"
	.string "with nature's fury.\p"
	.string "Will you match the burning power\n"
	.string "of this place?\p"
	.string "Or will you flee from destiny?$"

SlateportCity_NameRatersHouse_Text_NoHeatBadge:
	.string "You have much experience\n"
	.string "behind you now.\p"
	.string "But further challenge awaits\n"
	.string "you still.\p"
	.string "You will find it in a place\n"
	.string "up high.\p"
	.string "But covered in ash as well.\p"
	.string "A badge perhaps?$"

SlateportCity_NameRatersHouse_Text_NoBalanceBadge:
	.string "You have much experience\n"
	.string "behind you now.\p"
	.string "But will it be enough?\p"
	.string "I see that you have something\n"
	.string "to prove to someone.\p"
	.string "A guiding figure awaits.\p"
	.string "A badge as proof of growth.$"

SlateportCity_NameRatersHouse_Text_HaventMetStevenAtRoute118:
	.string "You have much strength and\n"
	.string "have faced many trials.\p"
	.string "The next will take you to a\n"
	.string "place unfamiliar.\p"
	.string "Use your newfound power and\n"
	.string "travel east.\p"
	.string "There you will find luck.$"

SlateportCity_NameRatersHouse_Text_TeamAquaAtWeatherInstitute:
	.string "You have much strength and\n"
	.string "have faced many trials.\p"
	.string "I see before you now, a\n"
	.string "place amongst green.\p"
	.string "For those who study.\p"
	.string "They will need your help\n"
	.string "if they are to continue.$"

SlateportCity_NameRatersHouse_Text_NoFeatherBadge:
	.string "You have much strength and\n"
	.string "have faced many trials.\p"
	.string "The next will bring you\n"
	.string "another treasure.\p"
	.string "A badge again.\p"
	.string "You will find success\n"
	.string "amongst the rocks.$"

SlateportCity_NameRatersHouse_Text_NoDevonScope:
	.string "My… your fortune is burning\n"
	.string "bright as a flame.\p"
	.string "It will illuminate your path.\n"
	.string "As will something else.\p"
	.string "To proceed you will need to\n"
	.string "find power from a friend.\p"
	.string "Go east for luck.$"

SlateportCity_NameRatersHouse_Text_TeamAquaAtMtPyre:
	.string "My… your fortune is burning\n"
	.string "bright as a flame.\p"
	.string "But fire is quenched by water,\n"
	.string "so watch how you tread.\p"
	.string "In the future I see you\n"
	.string "encounter a familiar wave.\p"
	.string "Face your future in a place\n"
	.string "full of graves.$"

SlateportCity_NameRatersHouse_Text_HaventAwokenGroudon:
	.string "My… your fortune is burning\n"
	.string "bright as a flame.\p"
	.string "But there is something else\n"
	.string "with a flame just as bright.\p"
	.string "Deep within the earth and\n"
	.string "amongst the ash.\p"
	.string "Will you face this legend?$"

SlateportCity_NameRatersHouse_Text_TeamAquaStealSub:
	.string "It's hard to focus.\p"
	.string "There is a strong energy\n"
	.string "within this very city.\p"
	.string "Or perhaps my senses have found\n"
	.string "your future true.\p"
	.string "Seek out this power.$"

SlateportCity_NameRatersHouse_Text_TeamAquaUseSub:
	.string "My… your fortune is burning\n"
	.string "bright as a flame.\p"
	.string "You still have unfinished\n"
	.string "work, I sense.\p"
	.string "You will find success in seeking\n"
	.string "out this venture.\p"
	.string "Somewhere where sand meets sea.$"

SlateportCity_NameRatersHouse_Text_NoMindBadge:
	.string "I sense you are reaching the\n"
	.string "height of your journey.\p"
	.string "Ahead of you is another familar\n"
	.string "challenge.\p"
	.string "A badge?\p"
	.string "For this one, you will find\n"
	.string "success in the darkness.$"

SlateportCity_NameRatersHouse_Text_TeamMagmaAtSpaceCenter:
	.string "My… your fortune is burning\n"
	.string "bright as a flame.\p"
	.string "In your future I see many stars.\p"
	.string "A place where one might go to\n"
	.string "reach out to them perhaps.\p"
	.string "And an all too familiar foe who\n"
	.string "you will find there.$"

SlateportCity_NameRatersHouse_Text_HaventAwokenKyogre:
	.string "I can sense your indomitable\n"
	.string "spirit burning like a blaze!\p"
	.string "There is another force rising\n"
	.string "to match it however!\p"
	.string "How exciting!\p"
	.string "A legendary beast of the waves\p"
	.string "awaits your arrival below.$"

SlateportCity_NameRatersHouse_Text_HaventSeenLegendaryBattle:
	.string "I can sense your indomitable\n"
	.string "spirit burning like a blaze!\p"
	.string "You aught to rush to the scene\n"
	.string "of the legendary battle ignited\l"
	.string "before you!\p"
	.string "Hurry now, don't you dawdle\n"
	.string "with an old man like me!$"

SlateportCity_NameRatersHouse_Text_HaventMetWallace:
	.string "My my… it seems as though you\n"
	.string "missed something in your search.\p"
	.string "Yes, I sense it.\p"
	.string "You must return to the scene\n"
	.string "of your battle post-haste!\p"
	.string "A ray of hope shines from above!$"

SlateportCity_NameRatersHouse_Text_HaventAwokenRayquaza:
	.string "I can feel the inbalance beyond.\p"
	.string "I can see you on a very important\n"
	.string "quest.\p"
	.string "Yes. One that will decide the\n"
	.string "very fate of Hoenn!\p"
	.string "Your hope lies at the highest\n"
	.string "peak in the south east.$"

SlateportCity_NameRatersHouse_Text_LegendariesStillPresent:
	.string "I see it within you!\p"
	.string "You have already attained the\n"
	.string "power you need to overcome your\l"
	.string "great battle!\p"
	.string "Go now and claim your victory!\p"
	.string "To the scene of the battle.$"

SlateportCity_NameRatersHouse_Text_NoRainBadge:
	.string "I can sense your indomitable\n"
	.string "spirit burning like a blaze!\p"
	.string "Just a single badge left to\n"
	.string "claim!\p"
	.string "You will find your victory\n"
	.string "in a shocking strike!$"

SlateportCity_NameRatersHouse_Text_NeverBeenToEverGrande:#
	.string "Your resolve is astounding!\p"
	.string "All badges claimed!\p"
	.string "There is but one place for you\n"
	.string "to go now!\p"
	.string "To battle against champions\n"
	.string "you must head east!$"

SlateportCity_NameRatersHouse_Text_HaventBeatenWally:
	.string "I can sense your indomitable\n"
	.string "spirit burning like a blaze!\p"
	.string "But be careful not to burn all\n"
	.string "around you.\p"
	.string "As an inferno knows not friend\n"
	.string "or foe.\p"
	.string "A friend awaits you in a dark\n"
	.string "place along your path.$"

SlateportCity_NameRatersHouse_Text_HaventBeatenLeague:
	.string "I can sense your indomitable\n"
	.string "spirit burning like a blaze!\p"
	.string "I see but one more obstacle\n"
	.string "in your path now.\p"
	.string "A stairway to victory, you\n"
	.string "must climb.\p"
	.string "Four steps to the top.\p"
	.string "Another to the heavens!$"

SlateportCity_NameRatersHouse_Text_ImpressiveFortune:
	.string "Your life has been very exciting\n"
	.string "hasn't it?\p"
	.string "My my…\p"
	.string "A fortune this deep, and a spirit\n" 
	.string "so bright commands a reward!\p"
	.string "Take this crystal.$"

SlateportCity_NameRatersHouse_Text_AnywaysWhereWasI:
	.string "Now where was I?\p"
	.string "Ah yes…$"

SlateportCity_NameRatersHouse_EventScript_PostGameTextLead:
	.string "I can sense your indomitable\n"
	.string "spirit burning like a blaze!\p"
	.string "Truly, you could do anything\n"
	.string "you pleased.\p"
	.string "A future in such flux, I\n"
	.string "think I see…$"

SlateportCity_NameRatersHouse_Text_PostGameBattleFrontier:
	.string "A place where many battles\n"
	.string "occur.\p"
	.string "You fight your way through a\n"
	.string "gauntlet to face off against\l"
	.string "those above all.\p"
	.string "A true frontier!$"

SlateportCity_NameRatersHouse_Text_PostGameEliteFourRematch:
	.string "Somewhere familiar.\p"
	.string "You fought your way to the\n"
	.string "top before.\p"
	.string "The challenge is much more\n"
	.string "more tough this time.\p"
	.string "Can you defeat these elites?$"

SlateportCity_NameRatersHouse_Text_PostGameGymLeaderRematch:
	.string "A place for trainers to\n"
	.string "prove their worth!\p"
	.string "One in most towns.\p"
	.string "Their power has been rising\n"
	.string "to meet your own.\p"
	.string "Can you defeat them again?$"

SlateportCity_NameRatersHouse_Text_PostGameCatchPokemon:
	.string "You are amongst the wild.\p"
	.string "You have picked up many\n"
	.string "companions on your travels.\p"
	.string "But can you face the task\n"
	.string "handed to you when you first\l"
	.string "set out.\p"
	.string "To find them all?$"

SlateportCity_NameRatersHouse_Text_PostGamePreformInContest:
	.string "You are on a stage.\p"
	.string "Showered in the affection\n"
	.string "of your peers.\p"
	.string "Your reward is not just\n"
	.string "fame, but fortune!\p"
	.string "It will take preperation\n"
	.string "to make this dream true.$"

SlateportCity_NameRatersHouse_Text_PostGameSpecialSootopolisBattle:
	.string "Somewhere fire and water unite\n"
	.string "you will find…\p"
	.string "A place for spirits to clash.\p"
	.string "From regions beyond, their\n"
	.string "power equal to yours.\p"
	.string "To face them, you will need to\n"
	.string "seek their secrets.$"

SlateportCity_NameRatersHouse_Text_PostGameCourtneyBattle:
	.string "In a city of progress, where\n"
	.string "spirits are healed.\p"
	.string "You will find…\p"
	.string "The flickering ember of a fire\n"
	.string "already extinguished.\p"
	.string "They will need you to guide\n"
	.string "them now.$"

SlateportCity_NameRatersHouse_Text_PostGameShellyBattle:
	.string "In a town where people live\n"
	.string "as one with the waves.\p"
	.string "You will find…\p"
	.string "The shrinking ripple of a\n"
	.string "wave upon the shore.\p"
	.string "They will need you to guide\n"
	.string "them now.$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "I see.\n"
	.string "Do come visit again.$"

