#include "global.h"
#include "task.h"
#include "window.h"
#include "string_util.h"
#include "naming_screen.h"
#include "field_screen_effect.h"
#include "constants/species.h"
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
#include "pokemon.h"
#include "random.h"
#include "pokeball.h"
#include "pokedex.h"

static void CB2_HandleGivenCode(void);
static void CB2_HandleGTSCode(void);
static void MapPostLoadHook_ReturnToCodeActivation(void);
static void MapPostLoadHook_ReturnToGTSActivation(void);
static void MapPostLoadHook_ReturnToShopMenu(void);
static void Task_ReturnToCodeActivation(u8 taskId);
static void Task_ReturnToGTSActivation(u8 taskId);
static u8 ScriptGiveCustomMon(u16 species, u8 level, u16 item, u8 ball, u8 nature, u8 abilityNum, u8 *evs, u8 *ivs, u16 *moves, bool8 isShiny);
static void ConvertPokemonToString(u16 species, u8 level, u8 nature, u8 shininess, u8 abilitynum, u8 ball, u8 *ivs);
static u8 ConvertStringToPokemon(u8 *string);

//--------------------------------------------------
// Codes and Effects
//--------------------------------------------------

// -------------------TEMPLATE----------------------

// Activation Code:
const u8 gText_Code0[] = _("None");

// Code Execution:
static void Task_DontActivateCode(u8 taskId)
{
    DestroyTask(taskId);
    ScriptContext_Enable();
}

// Response:
const u8 gText_NoCodeActivated[] = _("No known code.{PAUSE_UNTIL_PRESS}");

// -------------------------------------------------

// --------------------CODE 1-----------------------

const u8 gText_Code1[] = _("Ultima");

static void Task_ActivateCode1(u8 taskId)
{
    u8 evs[NUM_STATS] = {0, 0, 0, 0, 0, 0};
    u8 ivs[NUM_STATS] = {31, 31, 31, 31, 31, 31};
    u16 moves[4] = {MOVE_LIGHT_OF_RUIN, MOVE_MAGICAL_LEAF, MOVE_SAFEGUARD, MOVE_WISH};
    int sentToPc = ScriptGiveCustomMon(SPECIES_FLOETTE_ETERNAL_FLOWER, 17, ITEM_NONE, ITEM_CHERISH_BALL, 0, 1, evs, ivs, moves, 0);
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

const u8 gText_Code1Activated[] = _("Code “Ultima” activated!{PAUSE_UNTIL_PRESS}");
const u8 gText_Code1AlreadyActivated[] = _("Code “Ultima” already claimed!{PAUSE_UNTIL_PRESS}");

// -------------------------------------------------

// --------------------CODE 2-----------------------

const u8 gText_Code2[] = _("RED");

static void Task_ActivateCode2(u8 taskId)
{
    // input effect of Code 2 here.
    DestroyTask(taskId);
    ScriptContext_Enable();
}

const u8 gText_Code2Activated[] = _("RED code activated!{PAUSE_UNTIL_PRESS}");
const u8 gText_Code2AlreadyActivated[] = _("Code “RED” already claimed!{PAUSE_UNTIL_PRESS}");

//--------------------------------------------------
// End of Codes and Effects
//--------------------------------------------------

void EnterCode(void)
{
    DoNamingScreen(NAMING_SCREEN_CODE, gStringVar2, 0, 0, 0, CB2_HandleGivenCode);
}

static void CB2_HandleGivenCode(void)
{
    if (gStringVar2[1] == EOS)
        gSpecialVar_Result = 0;
    else {
    if (StringCompare(gStringVar2, gText_Code1) == 0)
        gSpecialVar_Result = 1;
    else if (StringCompare(gStringVar2, gText_Code2) == 0)
        gSpecialVar_Result = 2;
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

static void Task_ReturnToCodeActivation(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        if (gSpecialVar_Result == 1) {
            if (FlagGet(FLAG_CHEAT_CODE_1))
            DisplayItemMessageOnField(taskId, gText_Code1AlreadyActivated, Task_DontActivateCode);
            else
            DisplayItemMessageOnField(taskId, gText_Code1Activated, Task_ActivateCode1);
        }
        else if (gSpecialVar_Result == 2) {
            if (FlagGet(FLAG_CHEAT_CODE_2))
            DisplayItemMessageOnField(taskId, gText_Code2AlreadyActivated, Task_DontActivateCode);
            else
            DisplayItemMessageOnField(taskId, gText_Code2Activated, Task_ActivateCode2);
        }
        else
            DisplayItemMessageOnField(taskId, gText_NoCodeActivated, Task_DontActivateCode);
    }
}

//--------------------------------------------------
// Beginning of GTS Codes
//--------------------------------------------------

void PutPokemonOnGTS(void)
{
    u16 species = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES);
    u8 level = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_LEVEL);
    u8 nature = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_PERSONALITY);
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

    VarSet(VAR_SPECIES_IN_GTS, species);
    ZeroMonData(&gPlayerParty[gSpecialVar_0x8004]);

    ConvertPokemonToString(species, level, nature, shininess, abilitynum, ball, ivs);
}

void EnterGTSCode(void)
{
    DoNamingScreen(NAMING_SCREEN_GTS, gStringVar2, 0, 0, 0, CB2_HandleGTSCode);
}

static void CB2_HandleGTSCode(void)
{
    if (gStringVar2[1] == EOS)
        gSpecialVar_Result = 0;
    else
        gSpecialVar_Result = 1;

    gFieldCallback = MapPostLoadHook_ReturnToGTSActivation;
    SetMainCallback2(CB2_ReturnToField);
}

static void MapPostLoadHook_ReturnToGTSActivation(void)
{
    FadeInFromBlack();
    CreateTask(Task_ReturnToGTSActivation, 8);
}

static void Task_ReturnToGTSActivation(u8 taskId)
{
    if (gSpecialVar_Result == 1) {
        int sentToPc = ConvertStringToPokemon(gStringVar2);
        StringCopy(gStringVar2, GetSpeciesName(SPECIES_FLOETTE_ETERNAL_FLOWER));

        if (sentToPc == MON_GIVEN_TO_PARTY) {
        DisplayItemMessageOnField(taskId, gText_WasAddedToParty, Task_DontActivateCode);
        }
        else if (sentToPc == MON_GIVEN_TO_PC) {
        DisplayItemMessageOnField(taskId, gText_WasTransfered, Task_DontActivateCode);
        }
        else
        DisplayItemMessageOnField(taskId, gText_FailedToAddMon, Task_DontActivateCode);
    }
    else {
        DisplayItemMessageOnField(taskId, gText_FailedToAddMon, Task_DontActivateCode);
    }
}

//--------------------------------------------------
// Helper Functions for Codes
//--------------------------------------------------

//Give Custom Mon by Ghoulslash: https://github.com/ghoulslash/pokeemerald/tree/custom-givemon
static u8 ScriptGiveCustomMon(u16 species, u8 level, u16 item, u8 ball, u8 nature, u8 abilityNum, u8 *evs, u8 *ivs, u16 *moves, bool8 isShiny)
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
        } while (nature != GetNatureFromPersonality(personality));

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
        sentToPc = SendMonToPC(&mon);
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
    u8 charIndex;
    u8 segments[13];
    u16 species;
    u8 level;
    u8 nature;
    u8 shininess;
    u8 abilitynum;
    u8 ball;
    u8 ivs[NUM_STATS] = {0, 0, 0, 0, 0, 0};
    u8 evs[NUM_STATS] = {0, 0, 0, 0, 0, 0};
    const u8 customCharMap[] = _("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const u8 segmentIndices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for (i = 0; i < 13; ++i) {
        while (customCharMap[charIndex] != string[segmentIndices[i]]) {
            ++charIndex;
        }
        segments[i] = charIndex;
    }

    // Combine the two u8 values to create the species identifier
    species = ((segments[0] << 6) | segments[1]) % NUM_SPECIES;
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

    sentToPc = ScriptGiveCustomMon(species, level + 1, ITEM_NONE, ball + 1, nature, abilitynum, evs, ivs, 0, shininess);

    return sentToPc;
}

// Call with StringCopy(gStringVarX, ConvertPokemonToString(species, level, nature, shininess, abilitynum, ball, ivs));
static void ConvertPokemonToString(u16 species, u8 level, u8 nature, u8 shininess, u8 abilitynum, u8 ball, u8 *ivs) {
    u8 i;
    const u8 customCharMap[] = _("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    u8 segments[13];
    u8 outputString[14];

    // Convert each attribute to the corresponding segment value, seperating species into two
    segments[0] = (species >> 6) & 0x3F;
    segments[1] = species & 0x3F;
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

    for (i = 0; i < 13; ++i) {
        outputString[i] = customCharMap[segments[i] & 0x3F];
    }

    outputString[13] = EOS;

    StringCopy(gStringVar2, outputString);
}