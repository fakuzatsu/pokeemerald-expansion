# Verdant Pokeemerald Base
*The Pokeemerald base with Verdant Emerald changes*

A fork of Pokeemerald that breathes extra life into Pokemon Emerald. With new ways to adventure through the game: alternate paths on existing routes, brand new areas with the same Hoenn feel, and new Pokemon encounters never before seen in the region.

## Installation

1. Follow this guide to download and install the linux subsystem and get Ubuntu working on your Windows machine: https://github.com/pret/pokeemerald/blob/master/INSTALL.md#windows-1011-wsl1

> **ONLY FOLLOW UP TO THE INSTALLATION STEPS. DO NOT CLONE POKEEMERALD**

2. Instead of cloning the standard pokeemerald, clone our fork:

```
git clone https://github.com/fakuzatsu/verdantemerald
```

> Cloning our base should also link your local repo to the remote repo and keep you up to date with our changes.

3. Make sure you are in the root directory and can see our pokeemerald file (`ls` to see files in the current directory). Then, run the following:

```
git clone https://github.com/pret/agbcc
cd agbcc
./build.sh
./install.sh ../pokeemerald
```

## VSCode and Extensions

It is recommended to use VSCode to edit and add new files to our decomp, as well as Git. This will create a link between your own and the remote directory, which will let you push your changes for everyone to see using the Git tab on your VSCode. It will also let you pull changes that others have made, keeping us all up to date on development.

- [**VSCode**](https://code.visualstudio.com/) - An open source IDE for editing in multiple languages.
- [**Git**](https://git-scm.com/downloads) - An engine for syncing your directory with ours.
- [**Portscript**](https://marketplace.visualstudio.com/items?itemName=karathan.poryscript) - An extension for VSCode for decomp file compatibility.

## Additional tools

Tools for editing the decomp in order to add additional features, make changes to the world, impliment story and much more.

- [**Porymap**](https://github.com/huderlem/porymap) - A map editor for the Pokémon generation 3 decompilation projects (pokeruby, pokeemerald, and pokefirered).
    - And a [**Guide**](https://huderlem.github.io/porymap/)
- [**Tilemap-Studio**](https://github.com/Rangi42/tilemap-studio) - A tilemap editor for Game Boy, GBC, GBA, NDS, SNES, Genesis, or TG16 projects.
- [**Poryscript**](https://github.com/huderlem/poryscript) - Poryscript is a higher-level scripting language that compiles into the scripting language used in pokeemerald.
    - Install by following [these steps](https://github.com/huderlem/poryscript#local-development). Ensuring you [install go](http://golang.org/) and are cloning the repo into the directory which contains your 'Pokeemerald' folder. ***Do not clone into the Pokeemerald folder***

## Features of Pokemmerald-Expansion

- Configuration files that allows you to choose generation-specific behaviors. Full contents here:
    - [Battle configurations](/include/config/battle.h)
    - [Pokémon configurations](/include/config/pokemon.h)
    - [Item configurations](/include/config/item.h)
    - [Overworld configurations](/include/config/overworld.h)
    - [Debug configurations](/include/config/debug.h)
- Upgraded battle engine.
    - Gen5+ damage calculation.
    - 2v2 Wild battles support.
    - 1v2/2v1 battles support.
    - Fairy Type (configurable).
    - Physical/Special/Status Category Split (configurable).
    - New moves and abilities up to Scarlet and Violet.
        - Custom Contest data up to SwSh, newer moves are WIP. ([source](https://pokemonurpg.com/info/contests/rse-move-list/))
    - [Form change tables](/src/data/pokemon/form_change_tables.h) that allow customizing most form changes.
    - Mega Evolution, Primal Reversion and Ultra Burst.
    - Z-Moves
        - Gen 8+ damaging moves are given power extrapolated from Gen 7.
        - Gen 8+ status moves have no additional effects, like Healing Wish.
    - Initial battle parameters
        - Queueing stat boosts (aka, Totem Boosts)
        - Setting Terrains.
    - Mid-turn speed recalculation.
    - Quick Poké Ball selection in Wild Battles
        - Press `R` to use last selected Poké Ball.
        - Hold `R` to change selection with the D-Pad.
    - Faster battle intro
        - Message and animation/cry happens at the same time.
    - Faster HP drain.
    - Battle Debug menu.
        - Accessed by pressing `Select` on the "Fight/Bag/Pokémon/Run" menu.
    - Option to use AI flags in wild Pokémon battles.
    - FRLG/Gen4+ whiteout money calculation.
    - Configurable experience settings
        - Experience on catch.
        - Splitting experience.
        - Trainer experience.
        - Scaled experience.
        - Unevolved experience boost.
    - Frostbite.
        - Doesn't replace freezing unless a config is enabled, so you can mix and match.
    - Critical capture.
    - Removed badge boosts (configurable).
    - Recalculating stats at the end of every battle.
    - Level 100 Pokémon can earn EVs.
    - Inverse battle support.
    - TONS of other features listed [here](/include/config/battle.h).
- Full Trainer customization
    - Nickname, EVs, IVs, moves, ability, ball, friendship, nature, gender, shininess.
    - Custom tag battle support (teaming up an NPC in a double battle).
    - Sliding trainer messages.
    - Upgraded Trainer AI
        - Considers newer move effects.
        - New flag options to let you customize the intelligence of your trainers.
        - Faster calculations.
    - Specify Poké Balls by Trainer class.
- Pokémon Species from Generations 1-8.
    - Option to disable unwanted generations.
    - Updated sprites to DS style.
    - Updated stats, types, abilities and egg groups (configurable).
    - Updated Hoenn's Regional Dex to match ORAS'.
    - Updated National Dex incorporating the new species.
    - Sprite and animation visualizer.
        - Accesible by pressing `Select` on a Pokémon's Summary screen.
    - Gen4+ evolution methods, with some changes:
        - Mossy Rock, Icy Rock and Magnetic Field locations match ORAS'.
            - Leaf, Ice and Thunder Stones may also be used.
        - Inkay just needs level 30 to evolve.
            - You can't physically have both the RTC and gyroscope, so we skip this requirement.
        - Sylveon uses Gen8+'s evolution method (friendship + Fairy Move).
        - Option to use hold evolution items directly like stones.
    - Hidden Abilities.
        - Available via Ability Patch.
        - Compatible with Ghoul's DexNav branch.
    - All gender differences.
        - Different icons for female Hippopotas and Hippowdon
    - 3 Perfect IVs on Legendaries, Mythicals and Ultra Beasts
- Breeding
    - Incense Baby Pokémon now happen automatically (configurable).
    - Level 1 eggs.
    - Poké Ball inheriting.
    - Egg Move Transfer, including Mirror Herb.
    - Nature inheriting 100% of the time with Everstone
    - Gen6+ Ability inheriting.
- Items from newer Generations. Full list [here](/include/constants/items.h).
    - ***Gen 6+ Exp. Share*** (configurable)
    - Existing item data but missing effects:
        - Mints
        - Dynamax Candy
        - Mulches
        - Rotom Catalog
        - DNA Splicers
        - Zygarde Cube
        - N Solarizer/Lunarizer
        - Reins of Unity
        - Dynamax Band
        - Gimmighoul Coin
        - Booster Energy
        - Tera Shards
        - Tera Orb
- Feature branches incorporated:
    - [RHH intro credits](https://github.com/Xhyzi/pokeemerald/tree/rhh-intro-credits) by Xhyzi.
        - A small signature from all of us to show the collective effort in the project :)
    - [Overworld debug]() by TheXaman
        - Accesible by pressing `R + Start` in the overworld by default.
        - **Additional features**:
            - *Clear Boxes*: cleans every Pokémon from the Boxes.
            - *Hatch an Egg*: lets you choose an Egg in your party and immediatly hatch it.
- Other features
    - Pressing B while holding a Pokémon drops them like in modern games (configurable).
    - Running indoors (configurable).
    - Configurable overworld poison damage.
    - Configurable flags for disabling Wild encounters and Trainer battles.
    - Configurable flags for forcing or disabling Shinies.
    - Reusable TM (configurable).
    - B2W2+ Repel system that also supports LGPE's Lures
    - Gen6+'s EV cap.
    - All bugfixes from pret included.
    - Fixed overworld snow effect.

There are some mechanics, moves and abilities that are missing and being developed. Check [the project's milestones](https://github.com/rh-hideout/pokeemerald-expansion/milestones) to see which ones.