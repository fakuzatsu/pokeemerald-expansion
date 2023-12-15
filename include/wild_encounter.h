#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "constants/day_night.h"
#include "constants/wild_encounter.h"

#define LAND_WILD_COUNT     12
#define WATER_WILD_COUNT    5
#define ROCK_WILD_COUNT     5
#define FISH_WILD_COUNT     10
#define HIDDEN_WILD_COUNT   3

struct WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    u16 species;
};

struct WildPokemonInfo
{
    u8 encounterRate;
    const struct WildPokemon *wildPokemon;
};

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *landMonsMorningInfo;
    const struct WildPokemonInfo *landMonsNightInfo;
    const struct WildPokemonInfo *landMonsNatInfo;
    const struct WildPokemonInfo *landMonsNatMorningInfo;
    const struct WildPokemonInfo *landMonsNatNightInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *waterMonsMorningInfo;
    const struct WildPokemonInfo *waterMonsNightInfo;
    const struct WildPokemonInfo *waterMonsNatInfo;
    const struct WildPokemonInfo *waterMonsNatMorningInfo;
    const struct WildPokemonInfo *waterMonsNatNightInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsMorningInfo;
    const struct WildPokemonInfo *rockSmashMonsNightInfo;
    const struct WildPokemonInfo *rockSmashMonsNatInfo;
    const struct WildPokemonInfo *rockSmashMonsNatMorningInfo;
    const struct WildPokemonInfo *rockSmashMonsNatNightInfo;
    const struct WildPokemonInfo *fishingMonsInfo;
    const struct WildPokemonInfo *fishingMonsMorningInfo;
    const struct WildPokemonInfo *fishingMonsNightInfo;
    const struct WildPokemonInfo *fishingMonsNatInfo;
    const struct WildPokemonInfo *fishingMonsNatMorningInfo;
    const struct WildPokemonInfo *fishingMonsNatNightInfo;
    const struct WildPokemonInfo *hiddenMonsInfo;
};

extern const struct WildPokemonHeader gWildMonHeaders[];
extern bool8 gIsFishingEncounter;
extern bool8 gIsSurfingEncounter;

void DisableWildEncounters(bool8 disabled);
bool8 StandardWildEncounter(u16 currMetaTileBehavior, u16 previousMetaTileBehavior);
bool8 SweetScentWildEncounter(void);
bool8 DoesCurrentMapHaveFishingMons(void);
void FishingWildEncounter(u8 rod);
u16 GetLocalWildMon(bool8 *isWaterMon);
u16 GetLocalWaterMon(void);
bool8 UpdateRepelCounter(void);
bool8 TryDoDoubleWildBattle(void);
void CreateWildMon(u16 species, u8 level);
u16 GetCurrentMapWildMonHeaderId(void);
u8 ChooseWildMonIndex_Land(void);
u8 ChooseWildMonIndex_WaterRock(void);
u8 ChooseHiddenMonIndex(void);
bool8 StandardWildEncounter_Debug(void);

#endif // GUARD_WILD_ENCOUNTER_H
