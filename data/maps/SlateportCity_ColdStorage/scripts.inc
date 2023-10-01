SlateportCity_ColdStorage_MapScripts::
	.byte 0

SlateportCity_Factory_EventScript_Scientist::
	lock
	faceplayer
	msgbox SlateportCity_Factory_Text_MaterialTesting, MSGBOX_NPC
	release
	end

SlateportCity_Factory_EventScript_Electrician::
	lock
	faceplayer
	msgbox SlateportCity_Factory_Text_DangerousWork, MSGBOX_NPC
	release
	end

SlateportCity_Factory_EventScript_Manager::
	lock
	faceplayer
	msgbox SlateportCity_Factory_Text_BikeFactory, MSGBOX_NPC
	release
	end

SlateportCity_Factory_Text_MaterialTesting:
	.string "I'm testing the material for our\n"
	.string "product in this machine.\p"
	.string "It's very delicate work.$"

SlateportCity_Factory_Text_DangerousWork:
	.string "Hey kid, give me some space.\p"
	.string "Wiring up the power is very\n"
	.string "dangerous work.$"

SlateportCity_Factory_Text_BikeFactory:
	.string "I'm the owner of this bike\n"
	.string "factory.\p"
	.string "I'm supervising my employees.$"

