.set LOCALID_OLDLADY, 1

Grotto28_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto28_OnLoad
	.byte 0

Grotto28_OnLoad::
	call Grotto_EventScript_GetReturnWarp
	call Grotto_Layout4_CloseLeftTreeArea
	end

Grotto28_EventScript_OldLady::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_1, Grotto28_EventScript_OldLadyIntroduction
	goto_if_set FLAG_EVENT_GROTTO_28_OLD_LADY, Grotto28_EventScript_OldLadyThankForListening
	goto_if_eq VAR_HIDDEN_GROTTO_QUEST_STATE, 0, Grotto28_EventScript_OldLadySpeakOfPast
	goto Grotto28_EventScript_OldLadyTellRandomOldStory
	end

Grotto28_EventScript_OldLadyIntroduction::
	msgbox Grotto28_Text_OhHelloDearie, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	return

Grotto28_EventScript_OldLadySpeakOfPast::
	goto_if_set FLAG_TEMP_2, Grotto28_EventScript_OldLadyAskAboutBackstory
	msgbox Grotto28_Text_NotManyPeopleComeHere, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto Grotto28_EventScript_OldLadyAskAboutBackstory
	end

Grotto28_EventScript_OldLadyAskAboutBackstory::
	msgbox Grotto28_Text_WouldYouLikeToHearAStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Grotto28_EventScript_OldLadyTellBackstory
	goto Grotto28_EventScript_OldLadyDeclineStory
	end

Grotto28_EventScript_OldLadyTellBackstory::
	applymovement LOCALID_OLDLADY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Grotto28_Text_TellBackstory, MSGBOX_DEFAULT
	delay 20
	faceplayer
	msgbox Grotto28_Text_ThankYouForListening, MSGBOX_DEFAULT
	msgbox Grotto28_Text_PleaseTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_OLD_WORN_SCARF
	setflag FLAG_EVENT_GROTTO_28_OLD_LADY
	setvar VAR_HIDDEN_GROTTO_QUEST_STATE, 1
	release
	end

Grotto28_EventScript_OldLadyTellRandomOldStory::
	msgbox Grotto28_Text_WouldYouLikeToHearAStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Grotto28_EventScript_OldLadyDeclineStory
	random 5
	switch VAR_RESULT
	case 0, Grotto28_EventScript_OldLadyTellStoryOne
	case 1, Grotto28_EventScript_OldLadyTellStoryTwo
	case 2, Grotto28_EventScript_OldLadyTellStoryThree
	case 3, Grotto28_EventScript_OldLadyTellStoryFour
	case 4, Grotto28_EventScript_OldLadyTellStoryFive
	end

Grotto28_EventScript_OldLadyTellStoryOne::
	applymovement LOCALID_OLDLADY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Grotto28_Text_TellStoryOne, MSGBOX_DEFAULT
	faceplayer
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, Grotto28_EventScript_OldLadyThankForListening
	msgbox Grotto28_Text_ThankYouForListening, MSGBOX_DEFAULT
	msgbox Grotto28_Text_PleaseTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_RED_SCARF
	setflag FLAG_EVENT_GROTTO_28_OLD_LADY
	release
	end

Grotto28_EventScript_OldLadyTellStoryTwo::
	applymovement LOCALID_OLDLADY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Grotto28_Text_TellStoryTwo, MSGBOX_DEFAULT
	faceplayer
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, Grotto28_EventScript_OldLadyThankForListening
	msgbox Grotto28_Text_ThankYouForListening, MSGBOX_DEFAULT
	msgbox Grotto28_Text_PleaseTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_BLUE_SCARF
	setflag FLAG_EVENT_GROTTO_28_OLD_LADY
	release
	end

Grotto28_EventScript_OldLadyTellStoryThree::
	applymovement LOCALID_OLDLADY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Grotto28_Text_TellStoryThree, MSGBOX_DEFAULT
	faceplayer
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Grotto28_EventScript_OldLadyThankForListening
	msgbox Grotto28_Text_ThankYouForListening, MSGBOX_DEFAULT
	msgbox Grotto28_Text_PleaseTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_PINK_SCARF
	setflag FLAG_EVENT_GROTTO_28_OLD_LADY
	release
	end

Grotto28_EventScript_OldLadyTellStoryFour::
	applymovement LOCALID_OLDLADY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Grotto28_Text_TellStoryFour, MSGBOX_DEFAULT
	faceplayer
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, Grotto28_EventScript_OldLadyThankForListening
	msgbox Grotto28_Text_ThankYouForListening, MSGBOX_DEFAULT
	msgbox Grotto28_Text_PleaseTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GREEN_SCARF
	setflag FLAG_EVENT_GROTTO_28_OLD_LADY
	release
	end

Grotto28_EventScript_OldLadyTellStoryFive::
	applymovement LOCALID_OLDLADY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Grotto28_Text_TellStoryFive, MSGBOX_DEFAULT
	faceplayer
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, Grotto28_EventScript_OldLadyThankForListening
	msgbox Grotto28_Text_ThankYouForListening, MSGBOX_DEFAULT
	msgbox Grotto28_Text_PleaseTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_YELLOW_SCARF
	setflag FLAG_EVENT_GROTTO_28_OLD_LADY
	release
	end

Grotto28_EventScript_OldLadyDeclineStory::
	msgbox Grotto28_Text_NiceToTakeInScenery, MSGBOX_DEFAULT
	release
	end

Grotto28_EventScript_OldLadyThankForListening::
	msgbox Grotto28_Text_ThankYouForListening, MSGBOX_DEFAULT
	release
	end

Grotto28_Text_OhHelloDearie:
	.string "Oh…\p"
	.string "Hello there dearie.$"

Grotto28_Text_NotManyPeopleComeHere:
	.string "You surprised me…\p"
	.string "Not many people come here\n"
	.string "you see…\p"
	.string "It's dangerous.\p"
	.string "… … …\p"
	.string "I can tell that you are more than\n"
	.string "capable though.\p"
	.string "You have a strong bond with your\n"
	.string "Pokémon, don't you?$"

Grotto28_Text_WouldYouLikeToHearAStory:
	.string "Would you care to hear a story\n"
	.string "about this place?$"

Grotto28_Text_NiceToTakeInScenery:
	.string "You're right.\p"
	.string "Sometimes it's nice to just take\n"
	.string "in the scenery.$"

Grotto28_Text_TellBackstory:
	.string "You see…\p"
	.string "This place is home to a mysterious\n"
	.string "and powerful stone that warps the\l" 
	.string "forest around it.$"
	.string "When you enter the forest, you\n"
	.string "rarely end up at the same place.\p"
	.string "Not unless you are familiar\n"
	.string "with the place you are going…\p"
	.string "It's easy to get lost…\p"
	.string "…or to lose somebody you are\n"
	.string "travelling with…\p"
	.string "The guardians of this forest would\n"
	.string "once guide those who passed through\l"
	.string "but they became weak…\p"
	.string "Who can say what happened to them.\p"
	.string "… … …\p"
	.string "I come here to pay for their\n"
	.string "strength every day.$"

Grotto28_Text_TellStoryOne:
	.string "The guardians of this forest.\p"
	.string "They were said to be protectors\n"
	.string "of people and Pokémon alike.\p"
	.string "Once, they would guide people\n"
	.string "through these woods…\p"
	.string "But suddenly, without warning\n"
	.string "they stopped showing up…\p"
	.string "Without them…\n"
	.string "Many people were lost to the woods.\p"
	.string "Some say the guardians passed away\n"
	.string "protecting those in need.\p"
	.string "… … …\p"
	.string "They must have had a reason.$"

Grotto28_Text_TellStoryTwo:
	.string "Much as Meteor Falls is the site\n"
	.string "of fallen stars, it is said that\l"
	.string "once too did a star fall here.\p"
	.string "In this very forest.\p"
	.string "It is said that once, this place\n"
	.string "was the site of a great tribe.\p"
	.string "But when the star fell, it brough\n"
	.string "with it a curse.\p"
	.string "A curse that warped the woods to\n"
	.string "be as they are now…\p"
	.string "Whether you believe this true or not\n"
	.string "is up to you.\p"
	.string "But the curse of the forest is\n"
	.string "apparent…$"

Grotto28_Text_TellStoryThree:
	.string "Some say that this forest connects\n"
	.string "to another land.\p"
	.string "One far away, and much different to\n"
	.string "our own.\p"
	.string "Those few souls who become lost in\n"
	.string "the forest but find their way home\l"
	.string "claim to have seen giants.\p"
	.string "Pokémon the size of buildings…\p"
	.string "or even larger…\p"
	.string "Of course, giants are just creatures\n"
	.string "of legend, are they not?\p"
	.string "Perhaps…$"

Grotto28_Text_TellStoryFour:
	.string "The tribe that lived here before the\n"
	.string "forest became so dangerous…\p"
	.string "What do you think they were like?\p"
	.string "They are said to have been legendary\n"
	.string "crafters.\p"
	.string "In fact, the tales say that they were\n"
	.string "the ones who crafted the weapons of\l"
	.string "the guardians.\p"
	.string "You can find many scattered remnants\n"
	.string "of their work around these woods.\p"
	.string "Metalwork, sculpting, pottery…$"

Grotto28_Text_TellStoryFive:
	.string "These winding woods.\p"
	.string "If you are familiar with your\n"
	.string "destination, you can eventually find\l"
	.string "your way.\p"
	.string "But what if you lose something dear\n"
	.string "to you?…\p"
	.string "Do you think the woods would ever let\n"
	.string "you find it again?\p"
	.string "There are explorers who have tried.\p"
	.string "But those who wander deep into the\n"
	.string "forest in search of valuables\l"
	.string "rarely ever return.\p"
	.string "One can only hope to find it in\n"
	.string "passing I suppose…$"

Grotto28_Text_ThankYouForListening:
	.string "Thank you for listening to an old\n"
	.string "lady's musing.$"

Grotto28_Text_PleaseTakeThis:
	.string "Please. Take this.$"
