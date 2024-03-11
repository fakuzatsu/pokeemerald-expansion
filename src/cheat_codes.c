#include "global.h"
#include "task.h"
#include "window.h"
#include "string_util.h"
#include "naming_screen.h"
#include "field_screen_effect.h"
#include "pokemon_storage_system.h"
#include "constants/species.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "field_weather.h"
#include "event_data.h"
#include "item_menu.h"
#include "overworld.h"
#include "data.h"
#include "script.h"
#include "strings.h"
#include "main.h"
#include "text.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "pokeball.h"
#include "pokedex.h"

static void CB2_HandleGivenCode(void);
static void CB2_HandleGTSCode(void);
static void MapPostLoadHook_ReturnToCodeActivation(void);
static void Task_ReturnToCodeActivation(u8 taskId);
static u8 ScriptGiveCustomMon(u16 species, u8 level, u16 item, u8 ball, u8 nature, u8 abilityNum, u8 *evs, u8 *ivs, u16 *moves, bool8 isShiny, u8 gender);
static void ConvertPokemonToString(u16 species, u8 level, u32 personality, u8 shininess, u8 abilitynum, u8 ball, u8 *ivs);
static u8 ConvertStringToPokemon(u8 *string);

//--------------------------------------------------
// Codes and Effects
//--------------------------------------------------

// -------------------TEMPLATE----------------------

// Activation Code:
const u8 sText_Code0[] = _("None");

// Code Execution:
static void Task_DontActivateCode(u8 taskId)
{
    DestroyTask(taskId);
    ScriptContext_Enable();
}

// Response:
const u8 sText_NoCodeActivated[] = _("No known code.{PAUSE_UNTIL_PRESS}");

// -------------------------------------------------

// --------------------CODE 1-----------------------

const u8 sText_FloetteCode[] = _("UltiWep");

static void Task_GiveEternalFloette(u8 taskId)
{
    u8 evs[NUM_STATS] = {0, 0, 0, 0, 0, 0};
    u8 ivs[NUM_STATS] = {31, 31, 31, 31, 31, 31};
    u16 moves[4] = {MOVE_LIGHT_OF_RUIN, MOVE_MAGICAL_LEAF, MOVE_SAFEGUARD, MOVE_WISH};
    int sentToPc = ScriptGiveCustomMon(SPECIES_FLOETTE_ETERNAL_FLOWER, 17, ITEM_NONE, ITEM_CHERISH_BALL, 0, 1, evs, ivs, moves, 0, MON_FEMALE);
    StringCopy(gStringVar2, GetSpeciesName(SPECIES_FLOETTE_ETERNAL_FLOWER));

    if (sentToPc == MON_GIVEN_TO_PARTY) {
        DisplayItemMessageOnField(taskId, gText_WasAddedToParty, Task_DontActivateCode);
        FlagSet(FLAG_CHEAT_CODE_1);
    }
    else if (sentToPc == MON_GIVEN_TO_PC) {
        DisplayItemMessageOnField(taskId, gText_WasTransfered, Task_DontActivateCode);
        FlagSet(FLAG_CHEAT_CODE_1);
    }
    else
        DisplayItemMessageOnField(taskId, gText_FailedToAddMon, Task_DontActivateCode);
}

const u8 sText_FloetteCodeActivated[] = _("Code “UltiWep” activated!{PAUSE_UNTIL_PRESS}");
const u8 sText_FloetteCodeAlreadyActivated[] = _("Code “UltiWep” already claimed!{PAUSE_UNTIL_PRESS}");

// -------------------------------------------------

// --------------------CODE 2-----------------------

const u8 sText_ReRandomiseCode[] = _("ReRand");

static void Task_ActivateReRandomiseCode(u8 taskId)
{
    VarSet(VAR_RANDOMISER_SEED, Random());
    DestroyTask(taskId);
    ScriptContext_Enable();
}

const u8 sText_AbilityRandomiserActivated[] = _("Seed has been re-randomised. {PAUSE_UNTIL_PRESS}");

// -------------------------------------------------

// --------------------CODE 3-----------------------

const u8 sText_AllDexFlagsCode[] = _("DexAll");

static void Task_ActivateAllDexFlagsCode(u8 taskId)
{
    u16 i;
    for (i = 0; i < NATIONAL_DEX_ENAMORUS; i++)
    {
        GetSetPokedexFlag(i + 1, FLAG_SET_SEEN);
    }
    DestroyTask(taskId);
    ScriptContext_Enable();
}

const u8 sText_AllDexFlagsActivated[] = _("All Pokémon marked as seen. {PAUSE_UNTIL_PRESS}");

// -------------------------------------------------

// --------------------CODE 4-----------------------

const u8 sText_StunkyModeCode[] = _("Smellie");

static void Task_ToggleStunkyModeCode(u8 taskId)
{
    if (FlagGet(FLAG_CHEAT_CODE_2))
        FlagClear(FLAG_CHEAT_CODE_2);
    else
        FlagSet(FLAG_CHEAT_CODE_2);
}

const u8 sText_StunkyModeActivated[] = _("Stunky mode activated! {PAUSE_UNTIL_PRESS}");
const u8 sText_StunkyModeDectivated[] = _("Stunky mode deactivated. {PAUSE_UNTIL_PRESS}");

//--------------------------------------------------
// End of Codes and Effects
//--------------------------------------------------

void EnterCode(void)
{
    DoNamingScreen(NAMING_SCREEN_CODE, gStringVar2, 0, 0, 0, CB2_HandleGivenCode);
}

static void CB2_HandleGivenCode(void)
{
    if (gStringVar2[0] == EOS)
        gSpecialVar_Result = 0;
    else if (gSpecialVar_0x8004 == 9)
        gSpecialVar_Result = 99;
    else {
    if (StringCompare(gStringVar2, sText_FloetteCode) == 0)
        gSpecialVar_Result = 1;
    else if (StringCompare(gStringVar2, sText_ReRandomiseCode) == 0)
        gSpecialVar_Result = 2;
    else if (StringCompare(gStringVar2, sText_AllDexFlagsCode) == 0)
        gSpecialVar_Result = 3;
    else if (StringCompare(gStringVar2, sText_StunkyModeCode) == 0)
        gSpecialVar_Result = 4;
    else 
        gSpecialVar_Result = 0;
    }

    gFieldCallback = MapPostLoadHook_ReturnToCodeActivation;
    SetMainCallback2(CB2_ReturnToField);
}

static void MapPostLoadHook_ReturnToCodeActivation(void)
{
    FadeInFromBlack();
    CreateTask(Task_ReturnToCodeActivation, 8);
}

const u8 sText_ChangedSeed[] = _("Changed randomiser seed.{PAUSE_UNTIL_PRESS}");
const u8 sText_InvalidSeed[] = _("Invalid seed.{PAUSE_UNTIL_PRESS}");

static void Task_ReturnToCodeActivation(u8 taskId)
{
    u32 seed;

    if (IsWeatherNotFadingIn() == TRUE)
    {
        // First check if piggybacking code to set randomiser seed.
        if (gSpecialVar_Result == 99) {
            if (ParseWholeUnsigned(gStringVar2, &seed)) {
                VarSet(VAR_RANDOMISER_SEED, seed);
                FlagSet(FLAG_SYS_INVALID_CHALLENGE);
                DisplayItemMessageOnField(taskId, sText_ChangedSeed, Task_DontActivateCode);
            } else {
                DisplayItemMessageOnField(taskId, sText_InvalidSeed, Task_DontActivateCode);
            }
        }
        else if (gSpecialVar_Result == 1) {
            if (FlagGet(FLAG_CHEAT_CODE_1))
                DisplayItemMessageOnField(taskId, sText_FloetteCodeAlreadyActivated, Task_DontActivateCode);
            else
                DisplayItemMessageOnField(taskId, sText_FloetteCodeActivated, Task_GiveEternalFloette);
        }
        else if (gSpecialVar_Result == 2) {
            DisplayItemMessageOnField(taskId, sText_AbilityRandomiserActivated, Task_ActivateReRandomiseCode);
        }
        else if (gSpecialVar_Result == 3) {
            DisplayItemMessageOnField(taskId, sText_AllDexFlagsActivated, Task_ActivateAllDexFlagsCode);
        }
        else if (gSpecialVar_Result == 4) {
            if (FlagGet(FLAG_CHEAT_CODE_2))
                DisplayItemMessageOnField(taskId, sText_StunkyModeDectivated, Task_ToggleStunkyModeCode);
            else
                DisplayItemMessageOnField(taskId, sText_StunkyModeActivated, Task_ToggleStunkyModeCode);
        }
        else
            DisplayItemMessageOnField(taskId, sText_NoCodeActivated, Task_DontActivateCode);
    }
}

//--------------------------------------------------
// Beginning of GTS Codes
//--------------------------------------------------

void PutPokemonOnGTS(void)
{
    u16 species = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES);
    u8 level = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_LEVEL);
    u32 personality = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_PERSONALITY);
    u8 shininess = 0;
    u8 abilitynum = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ABILITY_NUM);
    u8 ball = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_POKEBALL);
    u8 ivs[NUM_STATS] = {
    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_IV),
    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_IV),
    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_IV),
    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_IV),
    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_IV),
    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_IV)};

    ZeroMonData(&gPlayerParty[gSpecialVar_0x8004]);
    CompactPartySlots();
    CompactPartySprites();
    ConvertPokemonToString(species, level, personality, shininess, abilitynum, ball, ivs);

    StringCopy(gSaveBlock1Ptr->waldaPhrase.text, gStringVar1);
    gSaveBlock1Ptr->waldaPhrase.colors[0] = species;
}

void EnterGTSCode(void)
{
    DoNamingScreen(NAMING_SCREEN_GTS, gStringVar2, 0, 0, 0, CB2_HandleGTSCode);
}

static void CB2_HandleGTSCode(void)
{
    int sentToPc;

    if (IsStringLengthAtLeast(gStringVar2, 14)) {
        if (gStringVar2[0] == EOS)
            gSpecialVar_Result = 0;
        else {
            gSpecialVar_Result = 1;
            sentToPc = ConvertStringToPokemon(gStringVar2);
            if (sentToPc == MON_CANT_GIVE)
                gSpecialVar_Result = 0;
        }
    }
    else {
        gSpecialVar_Result = 0;
    }

    gFieldCallback = FieldCB_ContinueScriptHandleMusic;
    SetMainCallback2(CB2_ReturnToField);
}

void GetPokemonFromStringVarOne(void)
{
    int sentToPc;
    sentToPc = ConvertStringToPokemon(gStringVar1);
    if (sentToPc == MON_CANT_GIVE)
        gSpecialVar_Result = 0;
}

//--------------------------------------------------
// Helper Functions for Codes
//--------------------------------------------------

//Give Custom Mon by Ghoulslash: https://github.com/ghoulslash/pokeemerald/tree/custom-givemon
static u8 ScriptGiveCustomMon(u16 species, u8 level, u16 item, u8 ball, u8 nature, u8 abilityNum, u8 *evs, u8 *ivs, u16 *moves, bool8 isShiny, u8 gender)
{
    u16 nationalDexNum;
    int sentToPc;
    u8 heldItem[2];
    struct Pokemon mon;
    u8 i;
    u8 evTotal = 0;
    
    if (nature == NUM_NATURES || nature == 0xFF)
        nature = Random() % NUM_NATURES;
    
    // shininess
    if (isShiny == 1)
    {
        u32 personality;
        u32 otid = gSaveBlock2Ptr->playerTrainerId[0]
            | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
            | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
            | (gSaveBlock2Ptr->playerTrainerId[3] << 24);

        do
        {
            personality = Random32();
            personality = ((((Random() % 8) ^ (HIHALF(otid) ^ LOHALF(otid))) ^ LOHALF(personality)) << 16) | LOHALF(personality);
        } while (nature != GetNatureFromPersonality(personality)
            || gender != GetGenderFromSpeciesAndPersonality(species, personality));

        CreateMon(&mon, species, level, 32, 1, personality, OT_ID_PRESET, otid);
    }
    else
        CreateMonWithNature(&mon, species, level, 32, nature);
    
    for (i = 0; i < NUM_STATS; i++)
    {
        // ev
        if (evs[i] != 0xFF && evTotal < 510)
        {
            // only up to 510 evs
            if ((evTotal + evs[i]) > 510)
                evs[i] = (510 - evTotal);
            
            evTotal += evs[i];
            SetMonData(&mon, MON_DATA_HP_EV + i, &evs[i]);
        }
        
        // iv
        if (ivs[i] != 32 && ivs[i] != 0xFF)
            SetMonData(&mon, MON_DATA_HP_IV + i, &ivs[i]);
    }
    CalculateMonStats(&mon);
    
    // moves
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] == 0 || moves[i] == 0xFF || moves[i] > MOVES_COUNT)
            continue;
        
        SetMonMoveSlot(&mon, moves[i], i);
    }
    
    // ability
    if (abilityNum == 0xFF || GetAbilityBySpecies(species, abilityNum) == 0)
    {
        do {
            abilityNum = Random() % 3;  // includes hidden abilities
        } while (GetAbilityBySpecies(species, abilityNum) == 0);
    }
    
    SetMonData(&mon, MON_DATA_ABILITY_NUM, &abilityNum);
    
    // ball
    if (ball <= POKEBALL_COUNT)
        SetMonData(&mon, MON_DATA_POKEBALL, &ball);
    
    // item
    heldItem[0] = item;
    heldItem[1] = item >> 8;
    SetMonData(&mon, MON_DATA_HELD_ITEM, heldItem);
    
    // give player the mon
    SetMonData(&mon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetMonData(&mon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;
    }

    if (i >= PARTY_SIZE)
    {
        sentToPc = CopyMonToPC(&mon);
    }
    else
    {
        sentToPc = MON_GIVEN_TO_PARTY;
        CopyMon(&gPlayerParty[i], &mon, sizeof(mon));
        gPlayerPartyCount = i + 1;
    }
    
    // Pokedex entry
    nationalDexNum = SpeciesToNationalPokedexNum(species); 
    switch(sentToPc)
    {
    case MON_GIVEN_TO_PARTY:
    case MON_GIVEN_TO_PC:
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
        break;
    case MON_CANT_GIVE:
        break;
    }
    
    return sentToPc;
}

static u8 ConvertStringToPokemon(u8 *string) {
    u8 i;
    int sentToPc;
    u8 charIndex = 0;
    u8 segments[14];
    u16 species;
    u8 level;
    u8 nature;
    u8 shininess;
    u8 abilitynum;
    u8 ball;
    u8 gender;
    u8 ivs[NUM_STATS] = {0, 0, 0, 0, 0, 0};
    u8 evs[NUM_STATS] = {0, 0, 0, 0, 0, 0};
    const u8 customCharMap[] = _("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?");
    const u8 segmentIndices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    for (i = 0; i < 14; ++i) {
        while (customCharMap[charIndex] != string[segmentIndices[i]]) {
            ++charIndex;
        }
        segments[i] = charIndex;
    }

    // Combine the two u8 values to create the species identifier.
    // Bitshift by 6 because we only have 62 total characters. So we essentially take the first value as base 6.
    species = segments[0];
    species <<= 6;
    species |= segments[1];
    ivs[0] = segments[2] % (MAX_IV_MASK + 1);
    ivs[1] = segments[3] % (MAX_IV_MASK + 1);
    ivs[2] = segments[4] % (MAX_IV_MASK + 1);
    ivs[3] = segments[5] % (MAX_IV_MASK + 1);
    ivs[4] = segments[6] % (MAX_IV_MASK + 1);
    ivs[5] = segments[7] % (MAX_IV_MASK + 1);
    level = segments[8] % MAX_LEVEL;
    nature = segments[9] % NUM_NATURES;
    shininess = segments[10] % 2;
    abilitynum = segments[11] % 3;
    ball = segments[12] % (LAST_BALL + 1);
    gender = segments[13];

    switch (gender) {
        case 1:
        gender = MON_MALE;
        break;
        case 2:
        gender = MON_FEMALE;
        break;
        case 3:
        gender = MON_GENDERLESS;
        break;
        default:
        gender = MON_MALE;
        break;
    }

    if (species > GIGANTAMAX_START)
        species = Random() % GIGANTAMAX_START;

    sentToPc = ScriptGiveCustomMon(species, level, ITEM_NONE, ball, nature, abilitynum, evs, ivs, 0, shininess, gender);

    StringCopy(gStringVar2, GetSpeciesName(species));

    return sentToPc;
}

// Call with StringCopy(gStringVarX, ConvertPokemonToString(species, level, nature, shininess, abilitynum, ball, ivs));
static void ConvertPokemonToString(u16 species, u8 level, u32 personality, u8 shininess, u8 abilitynum, u8 ball, u8 *ivs) {
    u8 i;
    const u8 customCharMap[] = _("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?");
    u8 segments[14];
    u8 outputString[15];
    u8 nature = GetNatureFromPersonality(personality);
    u8 gender = GetGenderFromSpeciesAndPersonality(species, personality);

    switch (gender) {
        case MON_MALE:
        gender = 1;
        break;
        case MON_FEMALE:
        gender = 2;
        break;
        case MON_GENDERLESS:
        gender = 3;
        break;
        default:
        gender = 1;
        break;
    }

    // Convert each attribute to the corresponding segment value, seperating species into two
    segments[1] = species & 0x3F;
    species >>= 6;
    segments[0] = species & 0x3F;
    segments[2] = ivs[0];
    segments[3] = ivs[1];
    segments[4] = ivs[2];
    segments[5] = ivs[3];
    segments[6] = ivs[4];
    segments[7] = ivs[5];
    segments[8] = level;
    segments[9] = nature;
    segments[10] = shininess;
    segments[11] = abilitynum;
    segments[12] = ball;
    segments[13] = gender;

    for (i = 0; i < 14; ++i) {
        outputString[i] = customCharMap[segments[i] & 0x3F];
    }

    outputString[14] = EOS;

    StringCopy(gStringVar1, outputString);
}
