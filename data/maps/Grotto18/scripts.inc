Grotto18_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Grotto18_OnLoad
	.byte 0

Grotto18_OnLoad:
	call Grotto_EventScript_GetReturnWarp
	end

Grotto18_EventScript_HexLady::
	lock
	faceplayer
	msgbox Grotto18_Text_DontGetLost, MSGBOX_DEFAULT
	release
	end

Grotto18_Text_DontGetLost:
	.string "Make sure you don't get lost.\p"
	.string "tee-hee…$"
