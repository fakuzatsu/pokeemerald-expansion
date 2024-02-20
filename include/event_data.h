#ifndef GUARD_EVENT_DATA_H
#define GUARD_EVENT_DATA_H

#define NUM_PROGRESSION_FLAGS 9 // Set to the number of flags in the sProgressionFlags array

/* The number of level caps should always be 1 more than your progression flags because we need
a level cap for when there are 0 progression flags are set, all the way up to when all of the
progression flags are set. */
#define NUM_LEVEL_CAPS NUM_PROGRESSION_FLAGS + 1

#define NUM_GROTTO_VARS 10 // Each Grotto entrance should have it's own unique var in `include/vars.h`.

#define NUM_GROTTOS_PER_FLAG 3 // Determines how many new Grottos become available per progression flag set.

/* The number of avaialble Grotto maps should be equal to the number of progression flags + 1 multiplied 
by the number of available grottos per flag. Since we also want Grotto's to be avaialble when none of the
progression flags are set.*/
#define NUM_GROTTO_MAPS (NUM_PROGRESSION_FLAGS + 1) * NUM_GROTTOS_PER_FLAG

#define NUM_RANDOM_EGG_SPECIES 49
#define NUM_SPECIAL_EGG_SPECIES 37

void InitEventData(void);
void ClearTempFieldEventData(void);
void ClearDailyFlags(void);
void ClearGrottoVars(void);
void IncrementTrophyGardenVar(void);
void DisableNationalPokedex(void);
void EnableNationalPokedex(void);
bool32 IsNationalPokedexEnabled(void);
void DisableMysteryEvent(void);
void EnableMysteryEvent(void);
bool32 IsMysteryEventEnabled(void);
void DisableMysteryGift(void);
void EnableMysteryGift(void);
bool32 IsMysteryGiftEnabled(void);
void ClearMysteryGiftFlags(void);
void ClearMysteryGiftVars(void);
void DisableResetRTC(void);
void EnableResetRTC(void);
bool32 CanResetRTC(void);
u16 *GetVarPointer(u16 id);
u16 VarGet(u16 id);
u16 VarGetIfExist(u16 id);
bool8 VarSet(u16 id, u16 value);
u16 VarGetObjectEventGraphicsId(u8 id);
u8 *GetFlagPointer(u16 id);
u8 FlagSet(u16 id);
u8 FlagToggle(u16 id);
u8 FlagClear(u16 id);
bool8 FlagGet(u16 id);

extern u16 gSpecialVar_0x8000;
extern u16 gSpecialVar_0x8001;
extern u16 gSpecialVar_0x8002;
extern u16 gSpecialVar_0x8003;
extern u16 gSpecialVar_0x8004;
extern u16 gSpecialVar_0x8005;
extern u16 gSpecialVar_0x8006;
extern u16 gSpecialVar_0x8007;
extern u16 gSpecialVar_0x8008;
extern u16 gSpecialVar_0x8009;
extern u16 gSpecialVar_0x800A;
extern u16 gSpecialVar_0x800B;
extern u16 gSpecialVar_Result;
extern u16 gSpecialVar_LastTalked;
extern u16 gSpecialVar_Facing;
extern u16 gSpecialVar_MonBoxId;
extern u16 gSpecialVar_MonBoxPos;
extern u16 gSpecialVar_BattlePointReward;
extern const u16 sProgressionFlags[NUM_PROGRESSION_FLAGS];
extern const u16 sLevelCaps[NUM_LEVEL_CAPS];
extern const u16 sSoftLevelCaps[NUM_LEVEL_CAPS];
extern const u16 sHiddenGrottoVars[NUM_GROTTO_VARS];

#endif // GUARD_EVENT_DATA_H
