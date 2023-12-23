#include "config/item.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"
#include "constants/field_weather.h"

	.section script_data, "aw", %progbits

	.align 2
gFieldEffectScriptPointers::
	.4byte gFieldEffectScript_ExclamationMarkIcon1      @ FLDEFF_EXCLAMATION_MARK_ICON 0
	.4byte gFieldEffectScript_UseCutOnTallGrass         @ FLDEFF_USE_CUT_ON_GRASS 1
	.4byte gFieldEffectScript_UseCutOnTree              @ FLDEFF_USE_CUT_ON_TREE 2
	.4byte gFieldEffectScript_Shadow                    @ FLDEFF_SHADOW 3
	.4byte gFieldEffectScript_TallGrass                 @ FLDEFF_TALL_GRASS 4
	.4byte gFieldEffectScript_Ripple                    @ FLDEFF_RIPPLE 5
	.4byte gFieldEffectScript_FieldMoveShowMon          @ FLDEFF_FIELD_MOVE_SHOW_MON 6
	.4byte gFieldEffectScript_Ash                       @ FLDEFF_ASH 7
	.4byte gFieldEffectScript_SurfBlob                  @ FLDEFF_SURF_BLOB 8
	.4byte gFieldEffectScript_UseSurf                   @ FLDEFF_USE_SURF 9
	.4byte gFieldEffectScript_GroundImpactDust          @ FLDEFF_DUST 10
	.4byte gFieldEffectScript_UseSecretPowerCave        @ FLDEFF_USE_SECRET_POWER_CAVE 11
	.4byte gFieldEffectScript_JumpTallGrass             @ FLDEFF_JUMP_TALL_GRASS 12
	.4byte gFieldEffectScript_SandFootprints            @ FLDEFF_SAND_FOOTPRINTS 13
	.4byte gFieldEffectScript_JumpBigSplash             @ FLDEFF_JUMP_BIG_SPLASH 14
	.4byte gFieldEffectScript_Splash                    @ FLDEFF_SPLASH 15
	.4byte gFieldEffectScript_JumpSmallSplash           @ FLDEFF_JUMP_SMALL_SPLASH 16
	.4byte gFieldEffectScript_LongGrass                 @ FLDEFF_LONG_GRASS 17
	.4byte gFieldEffectScript_JumpLongGrass             @ FLDEFF_JUMP_LONG_GRASS 18
	.4byte gFieldEffectScript_ShakingGrass              @ FLDEFF_SHAKING_GRASS 19
	.4byte gFieldEffectScript_ShakingGrass2             @ FLDEFF_SHAKING_LONG_GRASS 20
	.4byte gFieldEffectScript_UnusedSand                @ FLDEFF_SAND_HOLE 21
	.4byte gFieldEffectScript_WaterSurfacing            @ FLDEFF_WATER_SURFACING 22
	.4byte gFieldEffectScript_BerryTreeGrowthSparkle    @ FLDEFF_BERRY_TREE_GROWTH_SPARKLE 23
	.4byte gFieldEffectScript_DeepSandFootprints        @ FLDEFF_DEEP_SAND_FOOTPRINTS 24
	.4byte gFieldEffectScript_PokeCenterHeal            @ FLDEFF_POKECENTER_HEAL 25
	.4byte gFieldEffectScript_UseSecretPowerTree        @ FLDEFF_USE_SECRET_POWER_TREE 26
	.4byte gFieldEffectScript_UseSecretPowerShrub       @ FLDEFF_USE_SECRET_POWER_SHRUB 27
	.4byte gFieldEffectScript_TreeDisguise              @ FLDEFF_TREE_DISGUISE 28
	.4byte gFieldEffectScript_MountainDisguise          @ FLDEFF_MOUNTAIN_DISGUISE 29
	.4byte gFieldEffectScript_NPCUseFly                 @ FLDEFF_NPCFLY_OUT 30
	.4byte gFieldEffectScript_UseFly                    @ FLDEFF_USE_FLY 31
	.4byte gFieldEffectScript_FlyIn                     @ FLDEFF_FLY_IN 32
	.4byte gFieldEffectScript_QuestionMarkIcon          @ FLDEFF_QUESTION_MARK_ICON 33
	.4byte gFieldEffectScript_FeetInFlowingWater        @ FLDEFF_FEET_IN_FLOWING_WATER 34
	.4byte gFieldEffectScript_BikeTireTracks            @ FLDEFF_BIKE_TIRE_TRACKS 35
	.4byte gFieldEffectScript_SandDisguisePlaceholder   @ FLDEFF_SAND_DISGUISE 36
	.4byte gFieldEffectScript_UseRockSmash              @ FLDEFF_USE_ROCK_SMASH 37
	.4byte gFieldEffectScript_UseDig                    @ FLDEFF_USE_DIG 38
	.4byte gFieldEffectScript_SandPile                  @ FLDEFF_SAND_PILE 39
	.4byte gFieldEffectScript_UseStrength               @ FLDEFF_USE_STRENGTH 40
	.4byte gFieldEffectScript_ShortGrass                @ FLDEFF_SHORT_GRASS 41
	.4byte gFieldEffectScript_HotSpringsWater           @ FLDEFF_HOT_SPRINGS_WATER 42
	.4byte gFieldEffectScript_UseWaterfall              @ FLDEFF_USE_WATERFALL 43
	.4byte gFieldEffectScript_UseDive                   @ FLDEFF_USE_DIVE 44
	.4byte gFieldEffectScript_PokeballTrail             @ FLDEFF_POKEBALL_TRAIL 45
	.4byte gFieldEffectScript_HeartIcon                 @ FLDEFF_HEART_ICON 46
	.4byte gFieldEffectScript_Nop47                     @ FLDEFF_NOP_47
	.4byte gFieldEffectScript_Nop48                     @ FLDEFF_NOP_48
	.4byte gFieldEffectScript_AshPuff                   @ FLDEFF_ASH_PUFF 49
	.4byte gFieldEffectScript_AshLaunch                 @ FLDEFF_ASH_LAUNCH 50
	.4byte gFieldEffectScript_SweetScent                @ FLDEFF_SWEET_SCENT 51 
	.4byte gFieldEffectScript_SandPillar                @ FLDEFF_SAND_PILLAR 52
	.4byte gFieldEffectScript_Bubbles                   @ FLDEFF_BUBBLES 53
	.4byte gFieldEffectScript_Sparkle                   @ FLDEFF_SPARKLE 54
	.4byte gFieldEffectScript_ShowSecretPowerCave       @ FLDEFF_SECRET_POWER_CAVE 55
	.4byte gFieldEffectScript_ShowSecretPowerTree       @ FLDEFF_SECRET_POWER_TREE 56
	.4byte gFieldEffectScript_ShowSecretPowerShrub      @ FLDEFF_SECRET_POWER_SHRUB 57
	.4byte gFieldEffectScript_ShowCutGrass              @ FLDEFF_CUT_GRASS 58
	.4byte gFieldEffectScript_FieldMoveShowMonInit      @ FLDEFF_FIELD_MOVE_SHOW_MON_INIT 59
	.4byte gFieldEffectScript_UsePuzzleEffect           @ FLDEFF_USE_TOMB_PUZZLE_EFFECT 60
	.4byte gFieldEffectScript_SecretBaseBootPC          @ FLDEFF_PCTURN_ON 61
	.4byte gFieldEffectScript_HallOfFameRecord          @ FLDEFF_HALL_OF_FAME_RECORD 62
	.4byte gFieldEffectScript_UseTeleport               @ FLDEFF_USE_TELEPORT 63
	.4byte gFieldEffectScript_RayquazaSpotlight         @ FLDEFF_RAYQUAZA_SPOTLIGHT 64
	.4byte gFieldEffectScript_DestroyDeoxysRock         @ FLDEFF_DESTROY_DEOXYS_ROCK 65
	.4byte gFieldEffectScript_MoveDeoxysRock            @ FLDEFF_MOVE_DEOXYS_ROCK 66
	.4byte gFldEffScript_UseVsSeeker                    @ FLDEFF_USE_VS_SEEKER 67
	.4byte gFldEffScript_XIcon                          @ FLDEFF_X_ICON 68
	.4byte gFldEffScript_DoubleExclMarkIcon             @ FLDEFF_DOUBLE_EXCL_MARK_ICON 69
	.4byte gFieldEffectScript_CaveDust                  @ FLDEFF_CAVE_DUST 70

gFieldEffectScript_ExclamationMarkIcon1::
	field_eff_loadfadedpal_callnative gSpritePalette_ArrowEmotionsFieldEffect, FALSE, COLOR_MAP_NONE, FldEff_ExclamationMarkIcon
	field_eff_end

gFieldEffectScript_UseCutOnTallGrass::
	field_eff_callnative FldEff_UseCutOnGrass
	field_eff_end

gFieldEffectScript_UseCutOnTree::
	field_eff_callnative FldEff_UseCutOnTree
	field_eff_end

gFieldEffectScript_Shadow::
	field_eff_callnative FldEff_Shadow
	field_eff_end

gFieldEffectScript_TallGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_TallGrass
	field_eff_end

gFieldEffectScript_Ripple::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_Ripple
	field_eff_end

gFieldEffectScript_FieldMoveShowMon::
	field_eff_callnative FldEff_FieldMoveShowMon
	field_eff_end

gFieldEffectScript_Ash::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_Ash
	field_eff_end

gFieldEffectScript_SurfBlob::
	field_eff_callnative FldEff_SurfBlob
	field_eff_end

gFieldEffectScript_UseSurf::
	field_eff_callnative FldEff_UseSurf
	field_eff_end

gFieldEffectScript_GroundImpactDust::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_Dust
	field_eff_end

gFieldEffectScript_UseSecretPowerCave::
	field_eff_callnative FldEff_UseSecretPowerCave
	field_eff_end

gFieldEffectScript_JumpTallGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_JumpTallGrass
	field_eff_end

gFieldEffectScript_SandFootprints::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_SandFootprints
	field_eff_end

gFieldEffectScript_JumpBigSplash::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_JumpBigSplash
	field_eff_end

gFieldEffectScript_Splash::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_Splash
	field_eff_end

gFieldEffectScript_JumpSmallSplash::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_JumpSmallSplash
	field_eff_end

gFieldEffectScript_LongGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_LongGrass
	field_eff_end

gFieldEffectScript_JumpLongGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_WaterSurfacing
	field_eff_end

gFieldEffectScript_ShakingGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_ShakingGrass
	field_eff_end

gFieldEffectScript_ShakingGrass2::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_ShakingGrass2
	field_eff_end

gFieldEffectScript_UnusedSand::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_UnusedSand
	field_eff_end

gFieldEffectScript_WaterSurfacing::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_WaterSurfacing
	field_eff_end

gFieldEffectScript_BerryTreeGrowthSparkle::
	field_eff_callnative FldEff_BerryTreeGrowthSparkle
	field_eff_end

gFieldEffectScript_DeepSandFootprints::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_DeepSandFootprints
	field_eff_end

gFieldEffectScript_PokeCenterHeal::
	field_eff_loadfadedpal gSpritePalette_PokeballGlow, FALSE, COLOR_MAP_NONE
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FALSE, COLOR_MAP_NONE, FldEff_PokecenterHeal
	field_eff_end

gFieldEffectScript_UseSecretPowerTree::
	field_eff_callnative FldEff_UseSecretPowerTree
	field_eff_end

gFieldEffectScript_UseSecretPowerShrub::
	field_eff_callnative FldEff_UseSecretPowerShrub
	field_eff_end

gFieldEffectScript_TreeDisguise::
	field_eff_callnative ShowTreeDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_MountainDisguise::
	field_eff_callnative ShowMountainDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_NPCUseFly::
	field_eff_callnative FldEff_NPCFlyOut
	field_eff_end

gFieldEffectScript_UseFly::
	field_eff_callnative FldEff_UseFly
	field_eff_end

gFieldEffectScript_FlyIn::
	field_eff_callnative FldEff_FlyIn
	field_eff_end

gFieldEffectScript_QuestionMarkIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_ArrowEmotionsFieldEffect, FALSE, COLOR_MAP_NONE, FldEff_QuestionMarkIcon
	field_eff_end

gFieldEffectScript_FeetInFlowingWater::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_FeetInFlowingWater
	field_eff_end

gFieldEffectScript_BikeTireTracks::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_BikeTireTracks
	field_eff_end

gFieldEffectScript_SandDisguisePlaceholder::
	field_eff_callnative ShowSandDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_UseRockSmash::
	field_eff_callnative FldEff_UseRockSmash
	field_eff_end

gFieldEffectScript_UseStrength::
	field_eff_callnative FldEff_UseStrength
	field_eff_end

gFieldEffectScript_UseDig::
	field_eff_callnative FldEff_UseDig
	field_eff_end

gFieldEffectScript_SandPile::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_SandPile
	field_eff_end

gFieldEffectScript_ShortGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_ShortGrass
	field_eff_end

gFieldEffectScript_HotSpringsWater::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_HotSpringsWater
	field_eff_end

gFieldEffectScript_UseWaterfall::
	field_eff_callnative FldEff_UseWaterfall
	field_eff_end

gFieldEffectScript_UseDive::
	field_eff_callnative FldEff_UseDive
	field_eff_end

gFieldEffectScript_PokeballTrail::
	field_eff_loadpal gSpritePalette_Pokeball, FALSE
	field_eff_callnative FldEff_PokeballTrail
	field_eff_end

gFieldEffectScript_HeartIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FALSE, COLOR_MAP_NONE, FldEff_HeartIcon
	field_eff_end

gFieldEffectScript_Nop47::
	field_eff_callnative FldEff_Nop47
	field_eff_end

gFieldEffectScript_Nop48::
	field_eff_callnative FldEff_Nop48
	field_eff_end

gFieldEffectScript_AshPuff::
	field_eff_loadfadedpal_callnative gSpritePalette_Ash, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_AshPuff
	field_eff_end

gFieldEffectScript_AshLaunch::
	field_eff_loadfadedpal_callnative gSpritePalette_Ash, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_AshLaunch
	field_eff_end

gFieldEffectScript_SweetScent::
	field_eff_callnative FldEff_SweetScent
	field_eff_end

gFieldEffectScript_SandPillar::
	field_eff_loadfadedpal_callnative gSpritePalette_SandPillar, FALSE, COLOR_MAP_DARK_CONTRAST, FldEff_SandPillar
	field_eff_end

gFieldEffectScript_Bubbles::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_Bubbles
	field_eff_end

gFieldEffectScript_Sparkle::
	field_eff_loadfadedpal_callnative gSpritePalette_SmallSparkle, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_Sparkle
	field_eff_end

gFieldEffectScript_ShowSecretPowerCave::
	field_eff_loadfadedpal_callnative gSpritePalette_SecretPower_Cave, TRUE, COLOR_MAP_CONTRAST, FldEff_SecretPowerCave
	field_eff_end

gFieldEffectScript_ShowSecretPowerTree::
	field_eff_loadfadedpal_callnative gSpritePalette_SecretPower_Plant, TRUE, COLOR_MAP_CONTRAST, FldEff_SecretPowerTree
	field_eff_end

gFieldEffectScript_ShowSecretPowerShrub::
	field_eff_loadfadedpal_callnative gSpritePalette_SecretPower_Plant, TRUE, COLOR_MAP_CONTRAST, FldEff_SecretPowerShrub
	field_eff_end

gFieldEffectScript_ShowCutGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_CutGrass, TRUE, COLOR_MAP_DARK_CONTRAST, FldEff_CutGrass
	field_eff_end

gFieldEffectScript_FieldMoveShowMonInit::
	field_eff_callnative FldEff_FieldMoveShowMonInit
	field_eff_end

gFieldEffectScript_UsePuzzleEffect::
	field_eff_callnative FldEff_UsePuzzleEffect
	field_eff_end

gFieldEffectScript_SecretBaseBootPC::
	field_eff_callnative FldEff_SecretBasePCTurnOn
	field_eff_end

gFieldEffectScript_HallOfFameRecord::
	field_eff_loadfadedpal gSpritePalette_PokeballGlow, FALSE, COLOR_MAP_NONE
	field_eff_loadfadedpal_callnative gSpritePalette_HofMonitor, FALSE, COLOR_MAP_NONE, FldEff_HallOfFameRecord
	field_eff_end

gFieldEffectScript_UseTeleport::
	field_eff_callnative FldEff_UseTeleport
	field_eff_end

gFieldEffectScript_RayquazaSpotlight::
	field_eff_callnative FldEff_RayquazaSpotlight
	field_eff_end

gFieldEffectScript_DestroyDeoxysRock::
	field_eff_callnative FldEff_DestroyDeoxysRock
	field_eff_end

gFieldEffectScript_MoveDeoxysRock::
	field_eff_callnative FldEff_MoveDeoxysRock
	field_eff_end

gFldEffScript_UseVsSeeker::
	field_eff_callnative FldEff_UseVsSeeker
	field_eff_end

gFldEffScript_XIcon::
	field_eff_callnative FldEff_XIcon
	field_eff_end

gFldEffScript_DoubleExclMarkIcon::
	field_eff_callnative FldEff_DoubleExclMarkIcon
	field_eff_end

gFieldEffectScript_CaveDust::
    field_eff_loadfadedpal_callnative gSpritePalette_CaveDust, FALSE, COLOR_MAP_NONE, FldEff_CaveDust
    field_eff_end
