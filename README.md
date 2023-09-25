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