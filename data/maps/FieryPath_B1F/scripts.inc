FieryPath_B1F_MapScripts::
	.byte 0

FieryPath_B1F_EventScript_Alberto::
	trainerbattle_single TRAINER_YOSE, FieryPath_B1F_Text_YoseIntro, FieryPath_B1F_YoseDefeated
	msgbox FieryPath_B1F_Text_YosePostBattle, MSGBOX_AUTOCLOSE
	end

