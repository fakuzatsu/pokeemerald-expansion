# Verdant-Emerald Changelog

# Version 1.0.0

### *CREATED FROM POKEMERALD-EXPANSION*
* See the bottom of the changelog for all Pokeemerald-Expanion changes. Note that Pokemerald-Expansion adds all Pokémon, Moves and Items froms Gen 1-8 *

## 🗡️ Battle changes 🗡️
* All trainers have been updated use Pokémon from generations 1 to 8, including their **movesets** from generations 7 & 8 (decided based on balance).
* Difficulty has been slightly boosted to accomidate the new veriety of Pokémon and moves made available throughout the game (this is not a difficulty hack).
* Level caps have been added to manage player experience. *Hard level caps* and *Soft level caps*. These are toggleable along with *canon (no) caps*.
* **Experience** gains have been slightly increased to reduce grinding.
* Challenge mode has been added.

## 📟 Menu changes 📟
* Stats associated with a Pokémon's **nature** are highlighted based on whether they increase or decrease the stat.
* **EVs and IVs** can now be displayed on the Pokémon Summary screen by pressing **A** to rotate through them.
* Quick switch has been added to the Pokémon Menu by pressing **Select** while hovering the Pokémon you wish to move.
* Both the **Name Rater** and the **Move Reminder** functions have been added to the Pokémon menu (the purpose of these trainer's has also been changed).
* Hidden Power now shows the type that it will become when used by the Pokémon in Battle (affects all summary screens).
* You can now press **R** to **run** from battle. The first press will move your cursor to the **Run** prompt. Pressing **R** again will preform the run action.

## 🎁 Item changes 🎁
* An Infinite Rare Candy has been added as a key item. Available from the Punk Guy at Rustboro.
* The Exp Share has become a Key Item, operating like the item in **Gen 6** (this change can be reverted in the config `include/config/item.h`).

## 🌾 Field changes 🌾
* All regular Pokémon are now avaialble in some capactiy across the overworld (can be found in regular encounters with some exceptions).
* **Move Tutors** have been added across the region and new moves are unlocked as you progress through the game.
### New Maps
* Many new maps have been added as you progress through the region (with approximately 1 new encounter area per Badge).
* New maps are loaded with events, trainers, and items like existing maps, and are made to fit into the Hoenn feel.

### DexNav
* The DexNav from Ghoulslash has been added to the game, replicating its features in *ORAS*. 
* The DexNav unlocks many Pokémon encounters that would otherwise not be seen in the wild, as well as **Hidden Abilities**.
* The DexNav can be chained to increase the odds of encountering **Hidden Abilities** and **Shinies**.

### Day/Night Cycle
* The DNS from Sierra has been added to the game, with dynamic palette changes occuring throughout the day.
* Certain Pokémon, events, and items can only be encountered at certain hours of the day.
* An Item has been added to allow the player to change the effective time of day at their convenience.
* A clock has been added to the start menu to allow players to tell the current time.

### Hidden Grottos
* Hidden Grottos similar to **Gen 5** have been added to the game.
* Grottos shift each day and certain Grottos will appear based on your progression through the story.
* Grottos feature special events and Pokémon with their **Hidden Abilties**.

### Key Item Wheel
* The Key Item Wheel by Merrp has been added to the game, replicating its features in *ORAS*.
* Register up to **4** items at once.

### Random Events
* **Decreased** the rarity of certain events.
* Shiny Odds have been **reduced** from **1/8192** to **1/4096**.
* Chances of running into Mirage Island have been substantially **increased** + added a **secret** way to further improve odds. Because, *Why not*.

## ✨ QOL changes ✨
* **Decapitalisation:** All strings have been decapitalised.
* **Sounds Good:** All audio samples have been improved, and the sound engine improved to later GBA-games quality.
* **Autorun:** An autorun option has been added to the option menu. When toggled on, hold **B** to walk.
* **Easy Medicine:** Using medicine will no longer boot you back to the item menu if you still have more of that item to use.
* **Obedience Fix:** Obedience is now scaled with *all* badges, instead of in large chunks rarely.
* **Faster Interactions:** Certain redundant interactions have been removed or shortened, like the double confirmation when saving.
* **Faster Nurse Joy:** Nurse Joy will heal your Pokémon without question, and you will be faced towards the door upon completion.
* **Better PC:** The Move option in the PC has been swapped to the first option.
* **EXP on Catch:** In-line with current generations, catching Pokémon will give you Exp.
* **Reusable TMs:** TMs are no longer consumed on use. PP is not healed when teaching a TM.
* **Reusable Tutors:** Much like TMs, tutors are no longer one-time only. Visit a tutor again the next day to learn again.
* **Immortal Berries:** Berry Trees no longer die once matured, and do not need to be watered when it is raining.
* **No Match Call Interuptions:** Random Match Calls no longer occur. Scripted calls still happen, and you can still call others.
* **Adaptive Gym Leaders:** Brawly and Watson will adapt their teams based on your current badge count.
* **Super Rod Feebas:** Feebas has an increased chance of appearing on one of its predetermined tiles when using better rods.
* **Friends Forever:** Pokémon friendship has a moderate effect on obedience. At max, a Pokémon acts as if you are it's OT.
* **Fortune Teller:** Replacing the Name Rater, the Fortune Teller will offer hints, guiding you to the next stop on your journey.


# Pokeemerald-Expansion Changelog

## Version 1.7.x
### [Version 1.7.3](docs/changelogs/1.7.3.md) - Bugfix Release
### [Version 1.7.2](docs/changelogs/1.7.2.md) - Bugfix Release
### [Version 1.7.1](docs/changelogs/1.7.1.md) - Bugfix Release
### [Version 1.7.0](docs/changelogs/1.7.0.md) - Feature Release

## [Version 1.7.0](docs/changelogs/1.7.0.md) - Feature Release

## 🌋 *IMPORTANT CHANGES* 🌋
### Battle changes
* Battler Types are now obtained via `GetBattlerType` instead of `gBattleMons[battlerId].type1/2/3` to better consider Roost. Be sure to update your custom battle effects to account for this change.

## 🧬 General 🧬
### Fixed
* Fixed Cheat Start not initiating time-based events by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3446

## 🐉 Pokémon 🐉
### Changed
* Updated Cresselia's base stats to Gen 9 by @LOuroboros in https://github.com/rh-hideout/pokeemerald-expansion/pull/3419
* Updated Zacian/Zamazenta base stats to Gen 9 by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3421
### Fixed
* Fixed Kleavor, Hisuian Sneasel and Sneasler missing their SV abilities  by @LOuroboros in https://github.com/rh-hideout/pokeemerald-expansion/pull/3391
* Fixed Bergmite/Avalugg old and updated egg groups being switched by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3380

## 🤹 Moves 🤹
### Changed
* Quick Draw now uses weighted RNG by @Bassoonian in https://github.com/rh-hideout/pokeemerald-expansion/pull/3399
* Added `IS_BATTLER_TYPELESS` macro that checks if the specified battler has no valid type by @LOuroboros in https://github.com/rh-hideout/pokeemerald-expansion/pull/3303
### Fixed
* Fixed Protect failing if the user flinched on the previous turn by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3345
* Fixed entry hazards not working properly being cleared on switch-in by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3316
    * This includes Toxic Spikes not working if Pecha Berry actived on the previous turn.
* Fixed Roost overwriting other type changing at the end of the turn (Soak, Forest's Curse, Color Change, etc.) by @BLourenco in https://github.com/rh-hideout/pokeemerald-expansion/pull/3258
    *  Now it suppresses the user's Flying-type rather than remove and re-add it.
* Fixes Salt Cure visual bug if mon fainted by direct attack by @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3388
* Fixed Purifying Salt not preventing the use of Rest by @Bassoonian in https://github.com/rh-hideout/pokeemerald-expansion/pull/3399
* Fixed Make it Rain lowering Sp. Attack twice if hitting 2 targets in double battles by @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3441
* Fixed Reflect Type not properly handle 3rd types by @LOuroboros in https://github.com/rh-hideout/pokeemerald-expansion/pull/3303
* Fixed form change triggered by switching not occuring when using moves like U-Turn or Baton Pass by @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3463
* Fixed Last Resort not counting Sleep Talk as used for its effect by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3378

## 🎭 Abilities 🎭
### Changed
* Removed unused `STATUS3_CANT_SCORE_A_CRIT` by @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3377
* Moved Beads of Ruin and Sword of Ruin damage to the appropiate damage modifier functions by @kittenchilly in https://github.com/rh-hideout/pokeemerald-expansion/pull/3415
### Fixed
* Fixed Intimidate increasing the attack of both opponents if one of them has Contrary in double battles by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3365
* Fixed Battle/Shell Armor not preventing critical hits by @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3377
* Fixed Rivalry's effect being reversed by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3381
* Fixed Rivalry lowering attack if either attacker or target were genderless by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3381
* Fixed missing Poison Heal Ability Popup by @Bassoonian in https://github.com/rh-hideout/pokeemerald-expansion/pull/3385
* Fixed Parental Bond not working at all by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3417
* Fixed Beads of Ruin and Sword of Ruin damage modifiers by @kittenchilly in https://github.com/rh-hideout/pokeemerald-expansion/pull/3415
* Fixed Sheer Force not negating effects that benefit the user (eg. Flame Charge, Power-Up Punch) by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3378
* Fixed Strength Sap not healing the user when used on a Substitute by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3486
* Fixed Substitute showing the "took damage for" message if Strength Sap was used on it by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3486
* Fixed Weak Armor interrupting Multi Hit moves by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3497

## 🧶 Items 🧶
### Fixed
* Fixed Shiny Charm doing too many rerolls by default by @kittenchilly in https://github.com/rh-hideout/pokeemerald-expansion/pull/3327
* Fixed Berserk Gene activating for the wrong Pokémon double battles by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3363
* Fixed Red Card not being consumed after opponent Sticky Web activation by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3364
* Fixed implementation of Gen6 that didn't allow for the Exp Share flag to be set via script without setting the item to the Gen 6+ version by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3384
* Fixed Kee Berry raising defense by 1 stage instead of 2 by @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3409
* Fixed Kee Berry incorrect stat raise message by @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3409
* Fixed Razor Fang not being able to be used directly even if `I_USE_EVO_HELD_ITEMS_FROM_BAG` was set to `TRUE` by @fdeblasio in https://github.com/rh-hideout/pokeemerald-expansion/pull/3456

## 🧹 Cleanup 🧹
* `AbilityBattleEffects` uses `B_MSG_TERRAIN` constants for field terrain intro text by @LOuroboros in https://github.com/rh-hideout/pokeemerald-expansion/pull/3410
* Removed all trailing whitespace by @kittenchilly in https://github.com/rh-hideout/pokeemerald-expansion/pull/3472

## 🧪 Test Runner 🧪
### Added
* Flinch tests by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3345
* Berserk Gene double battle tests by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3363
* More specific Toxic Spikes tests by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3316
* Red Card/Sticky Web test @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3364
* Intimidate/Contrary double battle test by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3365
* Critical Hit tests by @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3377
* Roost tests by @BLourenco in https://github.com/rh-hideout/pokeemerald-expansion/pull/3258
* Rivalry tests by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3381
* Various tests by @Bassoonian in https://github.com/rh-hideout/pokeemerald-expansion/pull/3385
    * Defeatist, Dragon's Maw, Earth Eater, Gale Wings, Poison Heal, Rocky Payload, Sap Sipper, Steelworker and Transistor.
* Various tests by @Bassoonian in https://github.com/rh-hideout/pokeemerald-expansion/pull/3399
    * Beast Boost, Ice Scales, Neuroforce, Purifying Salt, Quick Draw and Sharpness.
* Berry tests @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3409
    * Full: Apicot, Custap, Ganlon, Jaboca, Kee, Lansat, Liechi, Maranga, Micle, Petaya, Rowap and Salac Berries.
    * TODO: Starf Berry.
* Weather and type-specific tests by @kittenchilly in https://github.com/rh-hideout/pokeemerald-expansion/pull/3260
    * Full: Freezing, Hail, Moonlight, Morning Sun, Sandstorm, Snow, Solar Beam/Blade, Steel poisoning, Synthesis, Thunder and Weather Ball.
    * Partial: Prankster, Safety Goggles, Aurora Veil, Hurricane, Leech Seed and OHKO moves.
    * TODO: Harvest.
* Single Parental Bond test by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3417
* Several tests by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3378
    * Full: Weak Armor, Last Resort, Stealth Rock.
        * Completed Weak Armor tests by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3493
    * Partial: Defiant, Sheer Force, White Herb, Strength Sap.
### Changed
* Red Card tests now check if the item was consumed by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3364
* Tests now cannot use `i` in their cycles to avoid messing with `PARAMETRIZE` by @mrgriffin in https://github.com/rh-hideout/pokeemerald-expansion/pull/3408
* Moved battle tests off the heap by @mrgriffin in https://github.com/rh-hideout/pokeemerald-expansion/pull/3414
* Moved Powder/Grass test to `move_flags` folder by @kittenchilly in https://github.com/rh-hideout/pokeemerald-expansion/pull/3260
* Continuous `NOT x; NOT y;` are now not allowed in tests due to them not acting as one would expect by @mrgriffin in https://github.com/rh-hideout/pokeemerald-expansion/pull/3459
    * Test writers should use `NONE_OF { x; y; }` instead.
### Fixed
* Fixed CreateNPCTrainerPartyForTrainer test failing on modern by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3367
* Fixed `RNG_CRITICAL_HIT` by @mrgriffin and @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3377
* Fixed `ASSUMPTIONS` block not working by @DizzyEggg in https://github.com/rh-hideout/pokeemerald-expansion/pull/3368
    * Fixup by @mrgriffin in https://github.com/rh-hideout/pokeemerald-expansion/pull/3408
* Fixed Beads of Ruin and Sword of Ruin damage tests by @kittenchilly in https://github.com/rh-hideout/pokeemerald-expansion/pull/3415
* Fixes test RNG by @mrgriffin and @AlexOn1ine in https://github.com/rh-hideout/pokeemerald-expansion/pull/3433
* Fixed battle test estimateCost bug by @mrgriffin in https://github.com/rh-hideout/pokeemerald-expansion/pull/3448
* Test cleanup and improvements by @AsparagusEduardo in https://github.com/rh-hideout/pokeemerald-expansion/pull/3449
    * Removed duplicated Prankster TO_DO test.
    * Corrected Multi-hit test names (4 and 5 hits stated 35% instead of 15%).
    * Grouped Maranga Berry's Physical vs Special tests using PARAMETRIZE.
    * Improved Jaboca, Kee and Rowap tests by @AlexOn1ine
* Fixed `ModifyPersonalityForNature` by @mrgriffin in https://github.com/rh-hideout/pokeemerald-expansion/pull/3452
* Fixed test_runner.c modern warning by @mrgriffin in https://github.com/rh-hideout/pokeemerald-expansion/pull/3451

## New Contributors
* @BLourenco made their first contribution in https://github.com/rh-hideout/pokeemerald-expansion/pull/3258

## Full Changelog
https://github.com/rh-hideout/pokeemerald-expansion/compare/expansion/1.6.1...expansion/1.6.2

# Known Issues

* **Roxanne?:** Roxanne uses a different trainer model in the Desert Cavern. Roxanne animations weren't scoped for Verdant 1.0.
* **Steven is Light:** When moving across the Fortree Bridge, Steven does not trigger the bridge stepback animation or SE.
