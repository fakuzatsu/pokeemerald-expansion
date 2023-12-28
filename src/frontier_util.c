#include "global.h"
#include "frontier_util.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"
#include "field_specials.h"
#include "battle.h"
#include "script_pokemon_util.h"
#include "main.h"
#include "window.h"
#include "menu.h"
#include "text.h"
#include "battle_records.h"
#include "international_string_util.h"
#include "string_util.h"
#include "new_game.h"
#include "link.h"
#include "tv.h"
#include "apprentice.h"
#include "pokedex.h"
#include "recorded_battle.h"
#include "data.h"
#include "record_mixing.h"
#include "strings.h"
#include "malloc.h"
#include "save.h"
#include "load_save.h"
#include "battle_dome.h"
#include "constants/battle_frontier.h"
#include "constants/battle_pike.h"
#include "constants/frontier_util.h"
#include "constants/trainers.h"
#include "constants/game_stat.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/event_objects.h"
#include "party_menu.h"

struct FrontierBrainMon
{
    u16 species;
    u16 heldItem;
    u8 fixedIV;
    u8 nature;
    u8 evs[NUM_STATS];
    u16 moves[MAX_MON_MOVES];
};

// This file's functions.
static void GetChallengeStatus(void);
static void GetFrontierData(void);
static void SetFrontierData(void);
static void SetSelectedPartyOrder(void);
static void DoSoftReset_(void);
static void SetFrontierTrainers(void);
static void SaveSelectedParty(void);
static void ShowFacilityResultsWindow(void);
static void CheckPutFrontierTVShowOnAir(void);
static void Script_GetFrontierBrainStatus(void);
static void IsTrainerFrontierBrain(void);
static void GiveBattlePoints(void);
static void GetFacilitySymbolCount(void);
static void GiveFacilitySymbol(void);
static void CheckBattleTypeFlag(void);
static void CheckPartyIneligibility(void);
static void ValidateVisitingTrainer(void);
static void IncrementWinStreak(void);
static void RestoreHeldItems(void);
static void SaveRecordBattle(void);
static void BufferFrontierTrainerName(void);
static void ResetSketchedMoves(void);
static void SetFacilityBrainObjectEvent(void);
static void ShowTowerResultsWindow(u8);
static void ShowDomeResultsWindow(u8);
static void ShowPalaceResultsWindow(u8);
static void ShowPikeResultsWindow(void);
static void ShowFactoryResultsWindow(u8);
static void ShowArenaResultsWindow(void);
static void ShowPyramidResultsWindow(void);
static void ShowLinkContestResultsWindow(void);
static void CopyFrontierBrainText(bool8 playerWonText);

// const rom data
static const u8 sFrontierBrainStreakAppearances[NUM_FRONTIER_FACILITIES][4] =
{
    [FRONTIER_FACILITY_TOWER]   = {35,  70, 35, 1},
    [FRONTIER_FACILITY_DOME]    = { 4,   9,  5, 0},
    [FRONTIER_FACILITY_PALACE]  = {21,  42, 21, 1},
    [FRONTIER_FACILITY_ARENA]   = {28,  56, 28, 1},
    [FRONTIER_FACILITY_FACTORY] = {21,  42, 21, 1},
    [FRONTIER_FACILITY_PIKE]    = {28, 140, 56, 1},
    [FRONTIER_FACILITY_PYRAMID] = {21,  70, 35, 0},
};

static const struct FrontierBrainMon sFrontierBrainsMons[][2][FRONTIER_PARTY_SIZE] =
{
    [FRONTIER_FACILITY_TOWER] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_ALAKAZAM,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 24,
                .nature = NATURE_MODEST,
                .evs = {106, 0, 152, 152, 100, 0},
                .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_DISABLE},
            },
            {
                .species = SPECIES_ENTEI,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = 24,
                .nature = NATURE_LONELY,
                .evs = {100, 152, 152, 0, 100, 6},
                .moves = {MOVE_FIRE_BLAST, MOVE_CALM_MIND, MOVE_RETURN, MOVE_ROAR},
            },
            {
                .species = SPECIES_SNORLAX,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 24,
                .nature = NATURE_ADAMANT,
                .evs = {152, 152, 0, 0, 106, 100},
                .moves = {MOVE_BODY_SLAM, MOVE_BELLY_DRUM, MOVE_YAWN, MOVE_SHADOW_BALL},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_RAIKOU,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MODEST,
                .evs = {158, 0, 252, 100, 0, 0},
                .moves = {MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_REFLECT, MOVE_REST},
            },
            {
                .species = SPECIES_LATIOS,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MODEST,
                .evs = {252, 0, 252, 6, 0, 0},
                .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_RECOVER, MOVE_DRAGON_CLAW},
            },
            {
                .species = SPECIES_SNORLAX,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_ADAMANT,
                .evs = {252, 252, 0, 0, 6, 0},
                .moves = {MOVE_CURSE, MOVE_RETURN, MOVE_REST, MOVE_SHADOW_BALL},
            },
        },
    },
    [FRONTIER_FACILITY_DOME] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_SWAMPERT,
                .heldItem = ITEM_FOCUS_BAND,
                .fixedIV = 20,
                .nature = NATURE_BRAVE,
                .evs = {152, 152, 106, 0, 100, 0},
                .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_COUNTER},
            },
            {
                .species = SPECIES_SALAMENCE,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = 20,
                .nature = NATURE_ADAMANT,
                .evs = {152, 152, 106, 100, 0, 0},
                .moves = {MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_DRAGON_CLAW, MOVE_AERIAL_ACE},
            },
            {
                .species = SPECIES_CHARIZARD,
                .heldItem = ITEM_WHITE_HERB,
                .fixedIV = 20,
                .nature = NATURE_QUIET,
                .evs = {100, 152, 106, 152, 0, 0},
                .moves = {MOVE_OVERHEAT, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE, MOVE_EARTHQUAKE},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_SWAMPERT,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BRAVE,
                .evs = {252, 252, 6, 0, 0, 0},
                .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_MIRROR_COAT},
            },
            {
                .species = SPECIES_METAGROSS,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BRAVE,
                .evs = {252, 252, 6, 0, 0, 0},
                .moves = {MOVE_PSYCHIC, MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_PROTECT},
            },
            {
                .species = SPECIES_LATIAS,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MODEST,
                .evs = {252, 0, 252, 6, 0, 0},
                .moves = {MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_REST},
            },
        },
    },
    [FRONTIER_FACILITY_PALACE] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_CROBAT,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 16,
                .nature = NATURE_ADAMANT,
                .evs = {152, 0, 0, 152, 100, 106},
                .moves = {MOVE_CONFUSE_RAY, MOVE_DOUBLE_TEAM, MOVE_TOXIC, MOVE_FLY},
            },
            {
                .species = SPECIES_SLAKING,
                .heldItem = ITEM_SCOPE_LENS,
                .fixedIV = 16,
                .nature = NATURE_HARDY,
                .evs = {152, 152, 0, 106, 100, 0},
                .moves = {MOVE_EARTHQUAKE, MOVE_SWAGGER, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK},
            },
            {
                .species = SPECIES_LAPRAS,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 16,
                .nature = NATURE_QUIET,
                .evs = {0, 0, 252, 0, 106, 152},
                .moves = {MOVE_ICE_BEAM, MOVE_HORN_DRILL, MOVE_CONFUSE_RAY, MOVE_PROTECT},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_ARCANINE,
                .heldItem = ITEM_WHITE_HERB,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_HASTY,
                .evs = {6, 252, 252, 0, 0, 0},
                .moves = {MOVE_OVERHEAT, MOVE_EXTREME_SPEED, MOVE_ROAR, MOVE_PROTECT},
            },
            {
                .species = SPECIES_SLAKING,
                .heldItem = ITEM_SCOPE_LENS,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_HARDY,
                .evs = {6, 252, 0, 252, 0, 0},
                .moves = {MOVE_HYPER_BEAM, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_YAWN},
            },
            {
                .species = SPECIES_SUICUNE,
                .heldItem = ITEM_KINGS_ROCK,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_HASTY,
                .evs = {252, 0, 252, 6, 0, 0},
                .moves = {MOVE_BLIZZARD, MOVE_SURF, MOVE_BITE, MOVE_CALM_MIND},
            },
        },
    },
    [FRONTIER_FACILITY_ARENA] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_HERACROSS,
                .heldItem = ITEM_SALAC_BERRY,
                .fixedIV = 20,
                .nature = NATURE_JOLLY,
                .evs = {106, 152, 0, 152, 0, 100},
                .moves = {MOVE_MEGAHORN, MOVE_ROCK_TOMB, MOVE_ENDURE, MOVE_REVERSAL},
            },
            {
                .species = SPECIES_UMBREON,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 20,
                .nature = NATURE_CALM,
                .evs = {152, 0, 100, 0, 152, 106},
                .moves = {MOVE_BODY_SLAM, MOVE_CONFUSE_RAY, MOVE_PSYCHIC, MOVE_FEINT_ATTACK},
            },
            {
                .species = SPECIES_SHEDINJA,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 20,
                .nature = NATURE_ADAMANT,
                .evs = {0, 252, 6, 252, 0, 0},
                .moves = {MOVE_SHADOW_BALL, MOVE_RETURN, MOVE_CONFUSE_RAY, MOVE_AERIAL_ACE},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_UMBREON,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_CALM,
                .evs = {252, 0, 0, 0, 252, 6},
                .moves = {MOVE_DOUBLE_EDGE, MOVE_CONFUSE_RAY, MOVE_REST, MOVE_PSYCHIC},
            },
            {
                .species = SPECIES_GENGAR,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MODEST,
                .evs = {252, 0, 252, 0, 6, 0},
                .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_DESTINY_BOND},
            },
            {
                .species = SPECIES_BRELOOM,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_JOLLY,
                .evs = {6, 252, 0, 252, 0, 0},
                .moves = {MOVE_SPORE, MOVE_FOCUS_PUNCH, MOVE_GIGA_DRAIN, MOVE_HEADBUTT},
            },
        },
    },
    [FRONTIER_FACILITY_FACTORY] =
    {
        // Because Factory's pokemon are random, this facility's Brain also uses random pokemon.
        // What is interesting, this team is actually the one Steven uses in the multi tag battle alongside the player.
        {
            {
                .species = SPECIES_METANG,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BRAVE,
                .evs = {0, 252, 252, 0, 6, 0},
                .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_METAL_CLAW},
            },
            {
                .species = SPECIES_SKARMORY,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_IMPISH,
                .evs = {252, 0, 0, 0, 6, 252},
                .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_PROTECT, MOVE_STEEL_WING},
            },
            {
                .species = SPECIES_AGGRON,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_ADAMANT,
                .evs = {0, 252, 0, 0, 252, 6},
                .moves = {MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_SOLAR_BEAM, MOVE_DRAGON_CLAW},
            },
        },
        {
            {
                .species = SPECIES_METANG,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BRAVE,
                .evs = {0, 252, 252, 0, 6, 0},
                .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_METAL_CLAW},
            },
            {
                .species = SPECIES_SKARMORY,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_IMPISH,
                .evs = {252, 0, 0, 0, 6, 252},
                .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_PROTECT, MOVE_STEEL_WING},
            },
            {
                .species = SPECIES_AGGRON,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_ADAMANT,
                .evs = {0, 252, 0, 0, 252, 6},
                .moves = {MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_SOLAR_BEAM, MOVE_DRAGON_CLAW},
            },
        },
    },
    [FRONTIER_FACILITY_PIKE] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_SEVIPER,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 16,
                .nature = NATURE_BRAVE,
                .evs = {252, 0, 252, 0, 6, 0},
                .moves = {MOVE_SWAGGER, MOVE_CRUNCH, MOVE_POISON_FANG, MOVE_GIGA_DRAIN},
            },
            {
                .species = SPECIES_SHUCKLE,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = 16,
                .nature = NATURE_BOLD,
                .evs = {252, 0, 0, 0, 106, 252},
                .moves = {MOVE_TOXIC, MOVE_SANDSTORM, MOVE_PROTECT, MOVE_REST},
            },
            {
                .species = SPECIES_MILOTIC,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 16,
                .nature = NATURE_MODEST,
                .evs = {152, 0, 100, 0, 152, 106},
                .moves = {MOVE_ICE_BEAM, MOVE_MIRROR_COAT, MOVE_SURF, MOVE_RECOVER},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_SEVIPER,
                .heldItem = ITEM_FOCUS_BAND,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BOLD,
                .evs = {252, 0, 0, 0, 252, 6},
                .moves = {MOVE_SWAGGER, MOVE_CRUNCH, MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN},
            },
            {
                .species = SPECIES_STEELIX,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BRAVE,
                .evs = {252, 0, 0, 0, 6, 252},
                .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_EXPLOSION, MOVE_SCREECH},
            },
            {
                .species = SPECIES_GYARADOS,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_ADAMANT,
                .evs = {252, 6, 0, 0, 0, 252},
                .moves = {MOVE_DRAGON_DANCE, MOVE_RETURN, MOVE_ROAR, MOVE_REST},
            },
        },
    },
    [FRONTIER_FACILITY_PYRAMID] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_REGIROCK,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 16,
                .nature = NATURE_ADAMANT,
                .evs = {152, 152, 0, 0, 106, 100},
                .moves = {MOVE_EXPLOSION, MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER},
            },
            {
                .species = SPECIES_REGISTEEL,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 16,
                .nature = NATURE_ADAMANT,
                .evs = {152, 152, 0, 0, 6, 200},
                .moves = {MOVE_EARTHQUAKE, MOVE_METAL_CLAW, MOVE_TOXIC, MOVE_IRON_DEFENSE},
            },
            {
                .species = SPECIES_REGICE,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = 16,
                .nature = NATURE_MODEST,
                .evs = {106, 0, 152, 0, 100, 152},
                .moves = {MOVE_ICE_BEAM, MOVE_AMNESIA, MOVE_THUNDER, MOVE_REST},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_ARTICUNO,
                .heldItem = ITEM_SCOPE_LENS,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MILD,
                .evs = {6, 0, 252, 252, 0, 0},
                .moves = {MOVE_BLIZZARD, MOVE_WATER_PULSE, MOVE_AERIAL_ACE, MOVE_REFLECT},
            },
            {
                .species = SPECIES_ZAPDOS,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MILD,
                .evs = {6, 0, 252, 252, 0, 0},
                .moves = {MOVE_THUNDER, MOVE_DETECT, MOVE_DRILL_PECK, MOVE_LIGHT_SCREEN},
            },
            {
                .species = SPECIES_MOLTRES,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MILD,
                .evs = {6, 0, 252, 252, 0, 0},
                .moves = {MOVE_FIRE_BLAST, MOVE_HYPER_BEAM, MOVE_AERIAL_ACE, MOVE_SAFEGUARD},
            },
        },
    },
};


static const struct FrontierBrainMon sFrontierGymLeaderMons[][2][6] =
{
    [TRAINER_FRONTIER_BROCK] =
    {
        {
        {
			.species = SPECIES_ONIX,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_SAND_TOMB, MOVE_PROTECT, MOVE_STEALTH_ROCK, MOVE_SANDSTORM},
		},
		{
			.species = SPECIES_GOLEM,
			.heldItem = ITEM_DARK_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 255, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH, MOVE_IRON_DEFENSE},
		},
		{
			.species = SPECIES_KABUTOPS,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_AQUA_JET, MOVE_SUPERPOWER, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_OMASTAR,
			.heldItem = ITEM_RINDO_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 255, 255},
			.moves = {MOVE_HYDRO_PUMP, MOVE_ANCIENT_POWER, MOVE_EARTH_POWER, MOVE_ICE_BEAM},
		},
		{
			.species = SPECIES_AERODACTYL,
			.heldItem = ITEM_CHARTI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_THUNDER_FANG, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_RELICANTH,
			.heldItem = ITEM_ROCK_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 0, 0, 255},
			.moves = {MOVE_ROCK_SLIDE, MOVE_WATERFALL, MOVE_ROCK_POLISH, MOVE_YAWN},
		},
        },

        {
            {
			.species = SPECIES_ONIX,
			.heldItem = ITEM_EVIOLITE,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_SANDSTORM},
		},
		{
			.species = SPECIES_GOLEM,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_POLISH, MOVE_SUCKER_PUNCH},
		},
		{
			.species = SPECIES_KABUTOPS,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WATERFALL, MOVE_ROCK_SLIDE, MOVE_X_SCISSOR, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_TYRANITAR,
			.heldItem = ITEM_CHOPLE_BERRY,
			.fixedIV = 25,
			.nature = NATURE_BRAVE,
			.evs = {127, 127, 0, 0, 127, 127},
			.moves = {MOVE_STONE_EDGE, MOVE_PAYBACK, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH},
		},
		{
			.species = SPECIES_AERODACTYL,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_ICE_FANG},
		},
		{
			.species = SPECIES_RHYPERIOR,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_AVALANCHE},
		},
        }
    },

    [TRAINER_FRONTIER_MISTY] =
    {
        {
        {
			.species = SPECIES_STARMIE,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
		},
		{
			.species = SPECIES_GOLDUCK,
			.heldItem = ITEM_WATER_GEM,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_AQUA_JET, MOVE_BLIZZARD, MOVE_FOCUS_BLAST, MOVE_HONE_CLAWS},
		},
		{
			.species = SPECIES_SEAKING,
			.heldItem = ITEM_WACAN_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WATERFALL, MOVE_MEGAHORN, MOVE_POISON_JAB, MOVE_AGILITY},
		},
		{
			.species = SPECIES_LAPRAS,
			.heldItem = ITEM_GANLON_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 255, 0, 255, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CONFUSE_RAY},
		},
		{
			.species = SPECIES_SLOWBRO,
			.heldItem = ITEM_APICOT_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_SLACK_OFF, MOVE_YAWN},
		},
		{
			.species = SPECIES_BLASTOISE,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_IRON_TAIL, MOVE_AVALANCHE, MOVE_IRON_DEFENSE},
		},
        },

        {
            {
			.species = SPECIES_STARMIE,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_GRASS_KNOT, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
		},
		{
			.species = SPECIES_LANTURN,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {0, 0, 0, 0, 255, 255},
			.moves = {MOVE_THUNDERBOLT, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_TOXIC},
		},
		{
			.species = SPECIES_JELLICENT,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_RECOVER, MOVE_SURF, MOVE_SHADOW_BALL, MOVE_WILL_O_WISP},
		},
		{
			.species = SPECIES_LAPRAS,
			.heldItem = ITEM_ZOOM_LENS,
			.fixedIV = 25,
			.nature = NATURE_SASSY,
			.evs = {127, 0, 127, 0, 127, 127},
			.moves = {MOVE_HYDRO_PUMP, MOVE_BLIZZARD, MOVE_ICE_SHARD, MOVE_SHEER_COLD},
		},
		{
			.species = SPECIES_QUAGSIRE,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_YAWN, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_RAIN_DANCE},
		},
		{
			.species = SPECIES_BLASTOISE,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_OUTRAGE, MOVE_AVALANCHE, MOVE_IRON_DEFENSE},
		},
        }
    },

    [TRAINER_FRONTIER_SURGE] =
    {
        {
        {
			.species = SPECIES_RAICHU,
			.heldItem = ITEM_ELECTRIC_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_SIGNAL_BEAM, MOVE_THUNDER_WAVE},
		},
		{
			.species = SPECIES_ELECTRODE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_RAIN_DANCE, MOVE_THUNDER, MOVE_MIRROR_COAT, MOVE_MAGNET_RISE},
		},
		{
			.species = SPECIES_MAGNEZONE,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 255, 255},
			.moves = {MOVE_DISCHARGE, MOVE_FLASH_CANNON, MOVE_SIGNAL_BEAM, MOVE_BARRIER},
		},
		{
			.species = SPECIES_ELECTIVIRE,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WILD_CHARGE, MOVE_LOW_KICK, MOVE_ROCK_TOMB, MOVE_FIRE_PUNCH},
		},
		{
			.species = SPECIES_JOLTEON,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDER, MOVE_SHADOW_BALL, MOVE_SIGNAL_BEAM, MOVE_RAIN_DANCE},
		},
		{
			.species = SPECIES_AMPHAROS,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 255, 0, 255, 0},
			.moves = {MOVE_DISCHARGE, MOVE_POWER_GEM, MOVE_CHARGE, MOVE_COTTON_GUARD},
		},
        },

        {
            {
			.species = SPECIES_RAICHU,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_VOLT_TACKLE, MOVE_FAKE_OUT, MOVE_FOCUS_PUNCH, MOVE_THUNDER_WAVE},
		},
		{
			.species = SPECIES_ELECTRODE,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_ELECTRO_BALL, MOVE_SIGNAL_BEAM, MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM},
		},
		{
			.species = SPECIES_MAGNEZONE,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_DISCHARGE, MOVE_FLASH_CANNON, MOVE_SIGNAL_BEAM, MOVE_MAGNET_RISE},
		},
		{
			.species = SPECIES_ELECTIVIRE,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WILD_CHARGE, MOVE_EARTHQUAKE, MOVE_CROSS_CHOP, MOVE_ICE_PUNCH},
		},
		{
			.species = SPECIES_JOLTEON,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_QUICK_ATTACK, MOVE_IRON_TAIL, MOVE_DOUBLE_TEAM, MOVE_VOLT_SWITCH},
		},
		{
			.species = SPECIES_LANTURN,
			.heldItem = ITEM_WIDE_LENS,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_THUNDER, MOVE_HYDRO_PUMP, MOVE_BLIZZARD, MOVE_SIGNAL_BEAM},
		},
        }
    },

    [TRAINER_FRONTIER_ERIKA] =
    {
        {
        {
			.species = SPECIES_VILEPLUME,
			.heldItem = ITEM_GRASS_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_PETAL_DANCE, MOVE_SLEEP_POWDER, MOVE_MOONLIGHT, MOVE_SUNNY_DAY},
		},
		{
			.species = SPECIES_VENUSAUR,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 255, 0, 255, 0},
			.moves = {MOVE_PETAL_DANCE, MOVE_TOXIC, MOVE_LIGHT_SCREEN, MOVE_SYNTHESIS},
		},
		{
			.species = SPECIES_VICTREEBEL,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_LEAF_BLADE, MOVE_SUCKER_PUNCH, MOVE_SWORDS_DANCE, MOVE_REFLECT},
		},
		{
			.species = SPECIES_EXEGGUTOR,
			.heldItem = ITEM_TANGA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 255, 255},
			.moves = {MOVE_SOLAR_BEAM, MOVE_PSYSHOCK, MOVE_HYPNOSIS, MOVE_SUNNY_DAY},
		},
		{
			.species = SPECIES_TANGROWTH,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 0, 0, 255},
			.moves = {MOVE_POWER_WHIP, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_BELLOSSOM,
			.heldItem = ITEM_FIGHTING_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_LEAF_BLADE, MOVE_DRAIN_PUNCH, MOVE_SWORDS_DANCE, MOVE_SUNNY_DAY},
		},
        },

        {
            {
			.species = SPECIES_VILEPLUME,
			.heldItem = ITEM_BLACK_SLUDGE,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_DRAIN_PUNCH, MOVE_SWORDS_DANCE, MOVE_SYNTHESIS, MOVE_SLEEP_POWDER},
		},
		{
			.species = SPECIES_VENUSAUR,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_BRAVE,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_LEAF_STORM, MOVE_POWER_WHIP, MOVE_EARTHQUAKE, MOVE_OUTRAGE},
		},
		{
			.species = SPECIES_CRADILY,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_SASSY,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_STONE_EDGE, MOVE_RECOVER, MOVE_SEED_BOMB, MOVE_CURSE},
		},
		{
			.species = SPECIES_EXEGGUTOR,
			.heldItem = ITEM_TANGA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_QUIET,
			.evs = {0, 0, 0, 0, 255, 255},
			.moves = {MOVE_PSYCHIC, MOVE_PSYSHOCK, MOVE_LEAF_STORM, MOVE_ANCIENT_POWER},
		},
		{
			.species = SPECIES_TANGROWTH,
			.heldItem = ITEM_POWER_HERB,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 255, 0, 255, 0},
			.moves = {MOVE_SOLAR_BEAM, MOVE_ANCIENT_POWER, MOVE_FOCUS_BLAST, MOVE_SYNTHESIS},
		},
		{
			.species = SPECIES_ABOMASNOW,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_BLIZZARD, MOVE_LEECH_SEED, MOVE_PROTECT, MOVE_SHEER_COLD},
		},
        }
    },

    [TRAINER_FRONTIER_JANINE] =
    {
        {
        {
			.species = SPECIES_VENOMOTH,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SLUDGE_BOMB, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN, MOVE_QUIVER_DANCE},
		},
		{
			.species = SPECIES_WEEZING,
			.heldItem = ITEM_FIRE_GEM,
			.fixedIV = 20,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_SLUDGE_BOMB, MOVE_FIRE_BLAST, MOVE_SHADOW_BALL, MOVE_PAIN_SPLIT},
		},
		{
			.species = SPECIES_ARIADOS,
			.heldItem = ITEM_PAYAPA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 0, 0, 255},
			.moves = {MOVE_POISON_JAB, MOVE_STRUGGLE_BUG, MOVE_ELECTROWEB, MOVE_SUCKER_PUNCH},
		},
		{
			.species = SPECIES_CROBAT,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_TOXIC, MOVE_SUPER_FANG, MOVE_HEAT_WAVE, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_ARBOK,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_IMPISH,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_GUNK_SHOT, MOVE_SUCKER_PUNCH, MOVE_COIL, MOVE_DRAGON_TAIL},
		},
		{
			.species = SPECIES_TENTACRUEL,
			.heldItem = ITEM_APICOT_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CALM,
			.evs = {0, 0, 0, 255, 0, 255},
			.moves = {MOVE_TOXIC_SPIKES, MOVE_SCALD, MOVE_GIGA_DRAIN, MOVE_BARRIER},
		},
        },

        {
            {
			.species = SPECIES_VENOMOTH,
			.heldItem = ITEM_WIDE_LENS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_BUG_BUZZ, MOVE_PSYCHIC},
		},
		{
			.species = SPECIES_WEEZING,
			.heldItem = ITEM_ROCKY_HELMET,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {170, 0, 170, 0, 0, 170},
			.moves = {MOVE_THUNDERBOLT, MOVE_WILL_O_WISP, MOVE_SLUDGE_BOMB, MOVE_FLAMETHROWER},
		},
		{
			.species = SPECIES_NIDOQUEEN,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 170, 170, 170},
			.moves = {MOVE_SLUDGE_WAVE, MOVE_ICE_BEAM, MOVE_EARTH_POWER, MOVE_THUNDERBOLT},
		},
		{
			.species = SPECIES_CROBAT,
			.heldItem = ITEM_BLACK_SLUDGE,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_HYPNOSIS, MOVE_TOXIC, MOVE_PROTECT},
		},
		{
			.species = SPECIES_ROSERADE,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_LEAF_STORM, MOVE_SLEEP_POWDER, MOVE_SUBSTITUTE, MOVE_LEECH_SEED},
		},
		{
			.species = SPECIES_TENTACRUEL,
			.heldItem = ITEM_CHESTO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_SLUDGE_BOMB, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_REST},
		},
        }
    },

    [TRAINER_FRONTIER_SABRINA] =
    {
        {
        {
			.species = SPECIES_ALAKAZAM,
			.heldItem = ITEM_COLBUR_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_CHARGE_BEAM},
		},
		{
			.species = SPECIES_HYPNO,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 255, 0, 255, 0},
			.moves = {MOVE_DREAM_EATER, MOVE_SHADOW_BALL, MOVE_HYPNOSIS, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_MR_MIME,
			.heldItem = ITEM_KASIB_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_PSYCHIC, MOVE_CHARGE_BEAM, MOVE_LIGHT_SCREEN, MOVE_REFLECT},
		},
		{
			.species = SPECIES_SLOWKING,
			.heldItem = ITEM_GANLON_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_PSYSHOCK, MOVE_ICE_BEAM, MOVE_SLACK_OFF, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_ESPEON,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_YAWN, MOVE_REFLECT},
		},
		{
			.species = SPECIES_JYNX,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_DREAM_EATER, MOVE_FROST_BREATH, MOVE_ENERGY_BALL, MOVE_LOVELY_KISS},
		},
        },

        {
            {
			.species = SPECIES_ALAKAZAM,
			.heldItem = ITEM_KASIB_BERRY,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_CHARGE_BEAM},
		},
		{
			.species = SPECIES_METAGROSS,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_SIGNAL_BEAM, MOVE_GRASS_KNOT},
		},
		{
			.species = SPECIES_EXEGGUTOR,
			.heldItem = ITEM_TANGA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_ENERGY_BALL, MOVE_SLEEP_POWDER, MOVE_DREAM_EATER},
		},
		{
			.species = SPECIES_SLOWKING,
			.heldItem = ITEM_CHOICE_SPECS,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {0, 0, 0, 0, 255, 255},
			.moves = {MOVE_SCALD, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST},
		},
		{
			.species = SPECIES_ESPEON,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYSHOCK, MOVE_SIGNAL_BEAM, MOVE_PSYCHIC, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_SIGILYPH,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_AIR_SLASH, MOVE_ICE_BEAM, MOVE_LIGHT_SCREEN},
		},
        }
    },

    [TRAINER_FRONTIER_BLAINE] =
    {
        {
        {
			.species = SPECIES_ARCANINE,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_FLARE_BLITZ, MOVE_WILD_CHARGE, MOVE_CLOSE_COMBAT, MOVE_EXTREME_SPEED},
		},
		{
			.species = SPECIES_NINETALES,
			.heldItem = ITEM_CHARTI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 255, 255, 0, 0},
			.moves = {MOVE_HEAT_WAVE, MOVE_ENERGY_BALL, MOVE_HYPNOSIS, MOVE_NASTY_PLOT},
		},
		{
			.species = SPECIES_CHARIZARD,
			.heldItem = ITEM_DRAGON_GEM,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_INFERNO, MOVE_DRAGON_RUSH, MOVE_FOCUS_BLAST, MOVE_HONE_CLAWS},
		},
		{
			.species = SPECIES_MAGMORTAR,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 255, 255, 0, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST},
		},
		{
			.species = SPECIES_FLAREON,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 255, 0, 0, 0},
			.moves = {MOVE_FLAME_CHARGE, MOVE_SUPERPOWER, MOVE_FLAIL, MOVE_YAWN},
		},
		{
			.species = SPECIES_RAPIDASH,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_FLARE_BLITZ, MOVE_MEGAHORN, MOVE_WILD_CHARGE, MOVE_HYPNOSIS},
		},
        },

        {
            {
			.species = SPECIES_ARCANINE,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_NAUGHTY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_OVERHEAT, MOVE_CLOSE_COMBAT, MOVE_EXTREME_SPEED, MOVE_BULLDOZE},
		},
		{
			.species = SPECIES_NINETALES,
			.heldItem = ITEM_CHARTI_BERRY,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_ENERGY_BALL, MOVE_PSYSHOCK, MOVE_WILL_O_WISP},
		},
		{
			.species = SPECIES_CHARIZARD,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_FLAMETHROWER, MOVE_AIR_SLASH, MOVE_FOCUS_BLAST, MOVE_DRAGON_PULSE},
		},
		{
			.species = SPECIES_MAGMORTAR,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ROCK_SLIDE},
		},
		{
			.species = SPECIES_FLAREON,
			.heldItem = ITEM_PASSHO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_HASTY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_SUPERPOWER, MOVE_QUICK_ATTACK, MOVE_OVERHEAT, MOVE_TOXIC},
		},
		{
			.species = SPECIES_ROTOM_HEAT,
			.heldItem = ITEM_FLAME_ORB,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_TRICK, MOVE_OVERHEAT, MOVE_THUNDERBOLT, MOVE_PAIN_SPLIT},
		},
        }
    },

    [TRAINER_FRONTIER_GIOVANNI] =
    {
        {
        {
			.species = SPECIES_RHYPERIOR,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 0, 0, 255},
			.moves = {MOVE_DRILL_RUN, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_HAMMER_ARM},
		},
		{
			.species = SPECIES_GOLEM,
			.heldItem = ITEM_RINDO_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_ROCK_BLAST, MOVE_ROAR},
		},
		{
			.species = SPECIES_MAROWAK,
			.heldItem = ITEM_YACHE_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_BONEMERANG, MOVE_STONE_EDGE, MOVE_OUTRAGE, MOVE_THUNDER_PUNCH},
		},
		{
			.species = SPECIES_SANDSLASH,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK, MOVE_SANDSTORM},
		},
		{
			.species = SPECIES_NIDOKING,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {0, 255, 0, 0, 255, 0},
			.moves = {MOVE_EARTH_POWER, MOVE_SLUDGE_WAVE, MOVE_MEGAHORN, MOVE_BLIZZARD},
		},
		{
			.species = SPECIES_NIDOQUEEN,
			.heldItem = ITEM_PASSHO_BERRY,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_EARTH_POWER, MOVE_POISON_JAB, MOVE_SUPERPOWER, MOVE_THUNDER},
		},
        },

        {
            {
			.species = SPECIES_RHYPERIOR,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_EARTHQUAKE, MOVE_ROCK_BLAST, MOVE_ICE_PUNCH, MOVE_HAMMER_ARM},
		},
		{
			.species = SPECIES_HIPPOWDON,
			.heldItem = ITEM_QUICK_CLAW,
			.fixedIV = 25,
			.nature = NATURE_BRAVE,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_GARCHOMP,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK},
		},
		{
			.species = SPECIES_KROOKODILE,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_SUPERPOWER, MOVE_FIRE_FANG, MOVE_GRASS_KNOT},
		},
		{
			.species = SPECIES_NIDOKING,
			.heldItem = ITEM_CHOICE_SPECS,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT},
		},
		{
			.species = SPECIES_GLISCOR,
			.heldItem = ITEM_FLYING_GEM,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ACROBATICS, MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_TAILWIND},
		},
        }
    },

    [TRAINER_FRONTIER_FALKNER] =
    {
        {
        {
			.species = SPECIES_PIDGEOT,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_HEAT_WAVE, MOVE_U_TURN, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_FEAROW,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DRILL_PECK, MOVE_DRILL_RUN, MOVE_HEAT_WAVE, MOVE_U_TURN},
		},
		{
			.species = SPECIES_DODRIO,
			.heldItem = ITEM_WACAN_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_THRASH, MOVE_PURSUIT, MOVE_ACUPRESSURE},
		},
		{
			.species = SPECIES_HONCHKROW,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_AIR_CUTTER, MOVE_DARK_PULSE, MOVE_ICY_WIND, MOVE_NASTY_PLOT},
		},
		{
			.species = SPECIES_XATU,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_HEAT_WAVE, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_NOCTOWL,
			.heldItem = ITEM_GANLON_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_AIR_SLASH, MOVE_DREAM_EATER, MOVE_HYPNOSIS, MOVE_REFLECT},
		},
        },

        {
            {
			.species = SPECIES_PIDGEOT,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_RETURN, MOVE_SWAGGER, MOVE_DOUBLE_TEAM, MOVE_AIR_SLASH},
		},
		{
			.species = SPECIES_CROBAT,
			.heldItem = ITEM_RED_CARD,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_SUPER_FANG, MOVE_TAUNT, MOVE_ACROBATICS, MOVE_CONFUSE_RAY},
		},
		{
			.species = SPECIES_AERODACTYL,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROCK_SLIDE, MOVE_PROTECT},
		},
		{
			.species = SPECIES_HONCHKROW,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_NAIVE,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_NIGHT_SLASH, MOVE_BRAVE_BIRD, MOVE_HEAT_WAVE, MOVE_ICY_WIND},
		},
		{
			.species = SPECIES_XATU,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_CALM_MIND, MOVE_PSYSHOCK, MOVE_STORED_POWER, MOVE_ROOST},
		},
		{
			.species = SPECIES_SWELLOW,
			.heldItem = ITEM_FLAME_ORB,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_FACADE, MOVE_PROTECT, MOVE_ENDEAVOR, MOVE_AERIAL_ACE},
		},
        }
    },

    [TRAINER_FRONTIER_BUGSY] =
    {
        {
        {
			.species = SPECIES_SCIZOR,
			.heldItem = ITEM_OCCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_BULLET_PUNCH, MOVE_X_SCISSOR, MOVE_AERIAL_ACE, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_SHUCKLE,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_STRUGGLE_BUG, MOVE_GYRO_BALL, MOVE_SUBSTITUTE, MOVE_POWER_SPLIT},
		},
		{
			.species = SPECIES_HERACROSS,
			.heldItem = ITEM_COBA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_MEGAHORN, MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_PINSIR,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_X_SCISSOR, MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_FORRETRESS,
			.heldItem = ITEM_APICOT_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_STRUGGLE_BUG, MOVE_GYRO_BALL, MOVE_PAIN_SPLIT, MOVE_STEALTH_ROCK},
		},
		{
			.species = SPECIES_YANMEGA,
			.heldItem = ITEM_CHARTI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_BUG_BUZZ, MOVE_PSYCHIC, MOVE_PROTECT, MOVE_HYPNOSIS},
		},
        },

        {
            {
			.species = SPECIES_SCIZOR,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_BULLET_PUNCH, MOVE_U_TURN, MOVE_SWORDS_DANCE, MOVE_ACROBATICS},
		},
		{
			.species = SPECIES_SHUCKLE,
			.heldItem = ITEM_ROCKY_HELMET,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_POWER_SPLIT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_TOXIC},
		},
		{
			.species = SPECIES_HERACROSS,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_MEGAHORN, MOVE_STONE_EDGE, MOVE_CLOSE_COMBAT, MOVE_SHADOW_CLAW},
		},
		{
			.species = SPECIES_PINSIR,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_X_SCISSOR, MOVE_BULLDOZE, MOVE_GUILLOTINE, MOVE_PROTECT},
		},
		{
			.species = SPECIES_ARMALDO,
			.heldItem = ITEM_QUICK_CLAW,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_X_SCISSOR, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_YANMEGA,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PROTECT, MOVE_BUG_BUZZ, MOVE_AIR_SLASH, MOVE_GIGA_DRAIN},
		},
        }
    },

    [TRAINER_FRONTIER_WHITNEY] =
    {
        {
        {
			.species = SPECIES_MILTANK,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_BODY_SLAM, MOVE_ZEN_HEADBUTT, MOVE_HAMMER_ARM, MOVE_MILK_DRINK},
		},
		{
			.species = SPECIES_WIGGLYTUFF,
			.heldItem = ITEM_NORMAL_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_HYPER_VOICE, MOVE_FIRE_BLAST, MOVE_BLIZZARD, MOVE_PERISH_SONG},
		},
		{
			.species = SPECIES_TAUROS,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_THRASH, MOVE_OUTRAGE, MOVE_STONE_EDGE, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_AMBIPOM,
			.heldItem = ITEM_FLYING_GEM,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DOUBLE_HIT, MOVE_ACROBATICS, MOVE_LOW_SWEEP, MOVE_U_TURN},
		},
		{
			.species = SPECIES_URSARING,
			.heldItem = ITEM_CHOPLE_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_THRASH, MOVE_HAMMER_ARM, MOVE_THUNDER_PUNCH, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_CLEFABLE,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_METRONOME, MOVE_COSMIC_POWER},
		},
        },

        {
            {
			.species = SPECIES_MILTANK,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_RETURN, MOVE_ZEN_HEADBUTT, MOVE_BRICK_BREAK, MOVE_MILK_DRINK},
		},
		{
			.species = SPECIES_BLISSEY,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_RELAXED,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_SOFT_BOILED, MOVE_FLAMETHROWER, MOVE_GRASS_KNOT, MOVE_TOXIC},
		},
		{
			.species = SPECIES_TAUROS,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_PROTECT},
		},
		{
			.species = SPECIES_AMBIPOM,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_FAKE_OUT, MOVE_DOUBLE_HIT, MOVE_LOW_SWEEP, MOVE_ICE_PUNCH},
		},
		{
			.species = SPECIES_URSARING,
			.heldItem = ITEM_TOXIC_ORB,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {170, 170, 0, 0, 0, 170},
			.moves = {MOVE_FACADE, MOVE_SWORDS_DANCE, MOVE_CRUNCH, MOVE_ROCK_SLIDE},
		},
		{
			.species = SPECIES_LOPUNNY,
			.heldItem = ITEM_CHOPLE_BERRY,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_ENTRAINMENT, MOVE_RETURN, MOVE_LOW_KICK, MOVE_ENCORE},
		},
        }
    },

    [TRAINER_FRONTIER_MORTY] =
    {
        {
        {
			.species = SPECIES_GENGAR,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_DARK_PULSE, MOVE_HYPNOSIS},
		},
		{
			.species = SPECIES_MISMAGIUS,
			.heldItem = ITEM_KASIB_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_POWER_GEM, MOVE_PERISH_SONG, MOVE_PAIN_SPLIT},
		},
		{
			.species = SPECIES_BANETTE,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_SHADOW_CLAW, MOVE_SUCKER_PUNCH, MOVE_CURSE, MOVE_WILL_O_WISP},
		},
		{
			.species = SPECIES_DUSKNOIR,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_SHADOW_PUNCH, MOVE_BULLDOZE, MOVE_THUNDER_PUNCH, MOVE_PAIN_SPLIT},
		},
		{
			.species = SPECIES_SABLEYE,
			.heldItem = ITEM_GANLON_BERRY,
			.fixedIV = 20,
			.nature = NATURE_IMPISH,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_OMINOUS_WIND, MOVE_FOUL_PLAY, MOVE_CALM_MIND, MOVE_RECOVER},
		},
		{
			.species = SPECIES_FROSLASS,
			.heldItem = ITEM_ICE_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_CONFUSE_RAY},
		},
        },

        {
            {
			.species = SPECIES_GENGAR,
			.heldItem = ITEM_WIDE_LENS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_GIGA_DRAIN, MOVE_THUNDERBOLT},
		},
		{
			.species = SPECIES_MISMAGIUS,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {170, 0, 170, 0, 170, 0},
			.moves = {MOVE_PERISH_SONG, MOVE_MEAN_LOOK, MOVE_WILL_O_WISP, MOVE_CONFUSE_RAY},
		},
		{
			.species = SPECIES_BANETTE,
			.heldItem = ITEM_GHOST_GEM,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_SHADOW_CLAW, MOVE_SUCKER_PUNCH, MOVE_DESTINY_BOND, MOVE_GUNK_SHOT},
		},
		{
			.species = SPECIES_DUSKNOIR,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_SHADOW_SNEAK, MOVE_WILL_O_WISP, MOVE_PROTECT, MOVE_FIRE_PUNCH},
		},
		{
			.species = SPECIES_CHANDELURE,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_OVERHEAT, MOVE_SHADOW_BALL, MOVE_ENERGY_BALL, MOVE_PSYCHIC},
		},
		{
			.species = SPECIES_FROSLASS,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_ICE_BEAM, MOVE_SHADOW_BALL, MOVE_THUNDER_WAVE, MOVE_DESTINY_BOND},
		},
        }
    },

    [TRAINER_FRONTIER_CHUCK] =
    {
        {
        {
			.species = SPECIES_POLIWRATH,
			.heldItem = ITEM_WATER_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 0, 0, 255},
			.moves = {MOVE_WATERFALL, MOVE_FOCUS_PUNCH, MOVE_HYPNOSIS, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_MACHAMP,
			.heldItem = ITEM_PAYAPA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 0, 0, 255},
			.moves = {MOVE_DYNAMIC_PUNCH, MOVE_ROCK_SLIDE, MOVE_DUAL_CHOP, MOVE_BULLDOZE},
		},
		{
			.species = SPECIES_HITMONTOP,
			.heldItem = ITEM_GROUND_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_CLOSE_COMBAT, MOVE_BULLET_PUNCH, MOVE_DRILL_RUN, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_HITMONCHAN,
			.heldItem = ITEM_ICE_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_MACH_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_HITMONLEE,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_JUMP_KICK, MOVE_SUCKER_PUNCH, MOVE_BLAZE_KICK, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_PRIMEAPE,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_CLOSE_COMBAT, MOVE_OUTRAGE, MOVE_STONE_EDGE, MOVE_U_TURN},
		},
        },

        {
            {
			.species = SPECIES_POLIWRATH,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 170, 0, 170, 0, 170},
			.moves = {MOVE_WATERFALL, MOVE_BELLY_DRUM, MOVE_ROCK_SLIDE, MOVE_HYPNOSIS},
		},
		{
			.species = SPECIES_MACHAMP,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_HITMONTOP,
			.heldItem = ITEM_WIDE_LENS,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_MACH_PUNCH, MOVE_FEINT, MOVE_TRIPLE_KICK, MOVE_BULLET_PUNCH},
		},
		{
			.species = SPECIES_HITMONCHAN,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_DRAIN_PUNCH, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_DOUBLE_TEAM},
		},
		{
			.species = SPECIES_HITMONLEE,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_HIGH_JUMP_KICK, MOVE_FAKE_OUT, MOVE_BULLDOZE, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_CONKELDURR,
			.heldItem = ITEM_FIGHTING_GEM,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE},
		},
        }
    },

    [TRAINER_FRONTIER_JASMINE] =
    {
        {
        {
			.species = SPECIES_STEELIX,
			.heldItem = ITEM_STEEL_GEM,
			.fixedIV = 20,
			.nature = NATURE_BRAVE,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_GYRO_BALL, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_CURSE},
		},
		{
			.species = SPECIES_MAGNEZONE,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {0, 0, 255, 0, 255, 0},
			.moves = {MOVE_FLASH_CANNON, MOVE_ZAP_CANNON, MOVE_THUNDER_WAVE, MOVE_GRAVITY},
		},
		{
			.species = SPECIES_FORRETRESS,
			.heldItem = ITEM_OCCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_GYRO_BALL, MOVE_EARTHQUAKE, MOVE_ZAP_CANNON, MOVE_GRAVITY},
		},
		{
			.species = SPECIES_SKARMORY,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_STEALTH_ROCK, MOVE_ROOST, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_METAGROSS,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_BULLET_PUNCH, MOVE_GRAVITY},
		},
		{
			.species = SPECIES_MAWILE,
			.heldItem = ITEM_DARK_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_IRON_HEAD, MOVE_SUCKER_PUNCH, MOVE_SUPER_FANG, MOVE_SWORDS_DANCE},
		},
        },

        {
            {
			.species = SPECIES_STEELIX,
			.heldItem = ITEM_ROCKY_HELMET,
			.fixedIV = 25,
			.nature = NATURE_BRAVE,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_GYRO_BALL, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK, MOVE_CURSE},
		},
		{
			.species = SPECIES_MAGNEZONE,
			.heldItem = ITEM_QUICK_CLAW,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_THUNDERBOLT, MOVE_FLASH_CANNON, MOVE_MIRROR_COAT, MOVE_MAGNET_RISE},
		},
		{
			.species = SPECIES_FORRETRESS,
			.heldItem = ITEM_IRON_BALL,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_EARTHQUAKE, MOVE_GYRO_BALL, MOVE_TOXIC, MOVE_EXPLOSION},
		},
		{
			.species = SPECIES_SKARMORY,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_CURSE, MOVE_ROOST, MOVE_AERIAL_ACE, MOVE_STEALTH_ROCK},
		},
		{
			.species = SPECIES_METAGROSS,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_METEOR_MASH, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
		},
		{
			.species = SPECIES_LUCARIO,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_HASTY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_EXTREME_SPEED, MOVE_CRUNCH, MOVE_AURA_SPHERE, MOVE_STONE_EDGE},
		},
        }
    },

    [TRAINER_FRONTIER_PRYCE] =
    {
        {
        {
			.species = SPECIES_MAMOSWINE,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ICICLE_CRASH, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE},
		},
		{
			.species = SPECIES_JYNX,
			.heldItem = ITEM_PSYCHIC_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL},
		},
		{
			.species = SPECIES_DEWGONG,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_BRINE, MOVE_PERISH_SONG, MOVE_HAIL},
		},
		{
			.species = SPECIES_CLOYSTER,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ICICLE_SPEAR, MOVE_RAZOR_SHELL, MOVE_ROCK_BLAST, MOVE_SHELL_SMASH},
		},
		{
			.species = SPECIES_LAPRAS,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_HYDRO_PUMP, MOVE_PSYCHIC, MOVE_HAIL},
		},
		{
			.species = SPECIES_WEAVILE,
			.heldItem = ITEM_DARK_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ICE_SHARD, MOVE_NIGHT_SLASH, MOVE_X_SCISSOR, MOVE_FAKE_OUT},
		},
        },

        {
            {
			.species = SPECIES_MAMOSWINE,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_ICICLE_SPEAR, MOVE_ENDEAVOR},
		},
		{
			.species = SPECIES_JYNX,
			.heldItem = ITEM_PSYCHIC_GEM,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_LOVELY_KISS},
		},
		{
			.species = SPECIES_DEWGONG,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_DIVE, MOVE_SHEER_COLD, MOVE_SLEEP_TALK, MOVE_REST},
		},
		{
			.species = SPECIES_CLOYSTER,
			.heldItem = ITEM_KINGS_ROCK,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ICICLE_SPEAR, MOVE_SHELL_SMASH, MOVE_EXPLOSION, MOVE_ROCK_BLAST},
		},
		{
			.species = SPECIES_LAPRAS,
			.heldItem = ITEM_CHESTO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_ICE_BEAM, MOVE_SURF, MOVE_THUNDERBOLT, MOVE_REST},
		},
		{
			.species = SPECIES_WEAVILE,
			.heldItem = ITEM_ICE_GEM,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ICE_PUNCH, MOVE_NIGHT_SLASH, MOVE_LOW_KICK, MOVE_FAKE_OUT},
		},
        }
    },

    [TRAINER_FRONTIER_CLAIR] =
    {
        {
        {
			.species = SPECIES_DRAGONITE,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DRAGON_RUSH, MOVE_HURRICANE, MOVE_STONE_EDGE, MOVE_HONE_CLAWS},
		},
		{
			.species = SPECIES_KINGDRA,
			.heldItem = ITEM_HABAN_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_DRAGON_PULSE, MOVE_HYDRO_PUMP, MOVE_YAWN, MOVE_AGILITY},
		},
		{
			.species = SPECIES_ALTARIA,
			.heldItem = ITEM_FIRE_GEM,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_DRAGON_BREATH, MOVE_FIRE_BLAST, MOVE_PERISH_SONG, MOVE_COTTON_GUARD},
		},
		{
			.species = SPECIES_SALAMENCE,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_DRAGON_PULSE, MOVE_HEAT_WAVE, MOVE_HYDRO_PUMP, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_DRUDDIGON,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_DRAGON_TAIL, MOVE_CRUNCH, MOVE_SUPERPOWER, MOVE_GLARE},
		},
		{
			.species = SPECIES_GARCHOMP,
			.heldItem = ITEM_YACHE_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DUAL_CHOP, MOVE_EARTHQUAKE, MOVE_AQUA_TAIL, MOVE_ROCK_SLIDE},
		},
        },

        {
            {
			.species = SPECIES_DRAGONITE,
			.heldItem = ITEM_YACHE_BERRY,
			.fixedIV = 25,
			.nature = NATURE_LONELY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DRACO_METEOR, MOVE_EARTHQUAKE, MOVE_EXTREME_SPEED, MOVE_OUTRAGE},
		},
		{
			.species = SPECIES_KINGDRA,
			.heldItem = ITEM_CHESTO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {170, 0, 0, 170, 170, 0},
			.moves = {MOVE_DRAGON_DANCE, MOVE_OUTRAGE, MOVE_WATERFALL, MOVE_REST},
		},
		{
			.species = SPECIES_ALTARIA,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_COTTON_GUARD, MOVE_TOXIC, MOVE_DOUBLE_TEAM, MOVE_FIRE_BLAST},
		},
		{
			.species = SPECIES_SALAMENCE,
			.heldItem = ITEM_DRAGON_GEM,
			.fixedIV = 25,
			.nature = NATURE_HASTY,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_DRACO_METEOR, MOVE_OUTRAGE, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_DRUDDIGON,
			.heldItem = ITEM_ROCKY_HELMET,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_REVENGE, MOVE_SUCKER_PUNCH, MOVE_GLARE, MOVE_DRAGON_CLAW},
		},
		{
			.species = SPECIES_GARCHOMP,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_DUAL_CHOP, MOVE_FIRE_FANG, MOVE_SWORDS_DANCE},
		},
        }
    },

    [TRAINER_FRONTIER_ROXANNE] =
    {
        {
        {
			.species = SPECIES_PROBOPASS,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_POWER_GEM, MOVE_FLASH_CANNON, MOVE_THUNDER_WAVE, MOVE_SANDSTORM},
		},
		{
			.species = SPECIES_ARMALDO,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_X_SCISSOR, MOVE_AQUA_TAIL, MOVE_CURSE},
		},
		{
			.species = SPECIES_CRADILY,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_ANCIENT_POWER, MOVE_GIGA_DRAIN, MOVE_STOCKPILE, MOVE_STEALTH_ROCK},
		},
		{
			.species = SPECIES_AGGRON,
			.heldItem = ITEM_CHOPLE_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_IRON_TAIL, MOVE_OUTRAGE, MOVE_THUNDER_WAVE},
		},
		{
			.species = SPECIES_RELICANTH,
			.heldItem = ITEM_RINDO_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_AQUA_TAIL, MOVE_AMNESIA, MOVE_YAWN},
		},
		{
			.species = SPECIES_GOLEM,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ROCK_SLIDE, MOVE_IRON_HEAD, MOVE_STEAMROLLER, MOVE_ROCK_POLISH},
		},
        },

        {
            {
			.species = SPECIES_PROBOPASS,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_POWER_GEM, MOVE_EARTH_POWER, MOVE_PAIN_SPLIT, MOVE_THUNDERBOLT},
		},
		{
			.species = SPECIES_ARMALDO,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ROCK_SLIDE, MOVE_ROCK_POLISH, MOVE_EARTHQUAKE, MOVE_X_SCISSOR},
		},
		{
			.species = SPECIES_CRADILY,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_TOXIC, MOVE_GIGA_DRAIN, MOVE_AMNESIA, MOVE_ROCK_SLIDE},
		},
		{
			.species = SPECIES_AGGRON,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_HEAD_SMASH, MOVE_IRON_HEAD, MOVE_METAL_BURST, MOVE_AVALANCHE},
		},
		{
			.species = SPECIES_CARRACOSTA,
			.heldItem = ITEM_WATER_GEM,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WATERFALL, MOVE_SHELL_SMASH, MOVE_ROCK_SLIDE, MOVE_AQUA_JET},
		},
		{
			.species = SPECIES_GOLEM,
			.heldItem = ITEM_GROUND_GEM,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {0, 255, 255, 0, 0, 0},
			.moves = {MOVE_FOCUS_PUNCH, MOVE_PROTECT, MOVE_EARTHQUAKE, MOVE_FIRE_PUNCH},
		},
        }
    },

    [TRAINER_FRONTIER_BRAWLY] =
    {
        {
        {
			.species = SPECIES_HARIYAMA,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_CLOSE_COMBAT, MOVE_BULLET_PUNCH, MOVE_EARTHQUAKE, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_MEDICHAM,
			.heldItem = ITEM_PSYCHIC_GEM,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_BRICK_BREAK, MOVE_PSYCHO_CUT, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH},
		},
		{
			.species = SPECIES_BRELOOM,
			.heldItem = ITEM_COBA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_FOCUS_PUNCH, MOVE_SPORE, MOVE_STONE_EDGE, MOVE_MACH_PUNCH},
		},
		{
			.species = SPECIES_MACHAMP,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_CLOSE_COMBAT, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_HITMONTOP,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_TRIPLE_KICK, MOVE_DRILL_RUN, MOVE_ROCK_SLIDE, MOVE_AGILITY},
		},
		{
			.species = SPECIES_HERACROSS,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_CLOSE_COMBAT, MOVE_MEGAHORN, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE},
		},
        },

        {
            {
			.species = SPECIES_HARIYAMA,
			.heldItem = ITEM_CHESTO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_BULK_UP, MOVE_REST, MOVE_REVENGE, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_SCRAFTY,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_BULK_UP, MOVE_DRAIN_PUNCH, MOVE_DRAGON_TAIL, MOVE_AMNESIA},
		},
		{
			.species = SPECIES_BRELOOM,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_SPORE, MOVE_FOCUS_PUNCH, MOVE_SEED_BOMB, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_MACHAMP,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_FIRE_PUNCH, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_MIENSHAO,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_HIGH_JUMP_KICK, MOVE_FAKE_OUT, MOVE_AERIAL_ACE, MOVE_DRAIN_PUNCH},
		},
		{
			.species = SPECIES_HERACROSS,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_MEGAHORN, MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_AERIAL_ACE},
		},
        }
    },

    [TRAINER_FRONTIER_WATTSON] =
    {
        {
        {
			.species = SPECIES_MANECTRIC,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_SIGNAL_BEAM, MOVE_CHARGE},
		},
		{
			.species = SPECIES_MAGNEZONE,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_DISCHARGE, MOVE_TRI_ATTACK, MOVE_MAGNET_RISE, MOVE_METAL_SOUND},
		},
		{
			.species = SPECIES_ELECTRODE,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_CHARGE_BEAM, MOVE_SIGNAL_BEAM, MOVE_LIGHT_SCREEN, MOVE_DOUBLE_TEAM},
		},
		{
			.species = SPECIES_PLUSLE,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 0, 255},
			.moves = {MOVE_DISCHARGE, MOVE_AGILITY, MOVE_NASTY_PLOT, MOVE_BATON_PASS},
		},
		{
			.species = SPECIES_MINUN,
			.heldItem = ITEM_ELECTRIC_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 0, 255},
			.moves = {MOVE_VOLT_SWITCH, MOVE_CHARM, MOVE_FAKE_TEARS, MOVE_THUNDER_WAVE},
		},
		{
			.species = SPECIES_RAICHU,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WILD_CHARGE, MOVE_BRICK_BREAK, MOVE_RETURN, MOVE_KNOCK_OFF},
		},
        },

        {
            {
			.species = SPECIES_MANECTRIC,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM},
		},
		{
			.species = SPECIES_MAGNEZONE,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_THUNDERBOLT, MOVE_TOXIC, MOVE_PROTECT, MOVE_FLASH_CANNON},
		},
		{
			.species = SPECIES_ELECTRODE,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDER, MOVE_SIGNAL_BEAM, MOVE_SWAGGER, MOVE_THUNDER_WAVE},
		},
		{
			.species = SPECIES_ROTOM_WASH,
			.heldItem = ITEM_WIDE_LENS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDER, MOVE_HYDRO_PUMP, MOVE_HEX, MOVE_WILL_O_WISP},
		},
		{
			.species = SPECIES_AMPHAROS,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_FIRE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_BULLDOZE, MOVE_BRICK_BREAK},
		},
		{
			.species = SPECIES_RAICHU,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDER, MOVE_FOCUS_BLAST, MOVE_GRASS_KNOT, MOVE_SWAGGER},
		},
        }
    },

    [TRAINER_FRONTIER_FLANNERY] =
    {
        {
        {
			.species = SPECIES_TORKOAL,
			.heldItem = ITEM_FIRE_GEM,
			.fixedIV = 20,
			.nature = NATURE_BRAVE,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_FIRE_BLAST, MOVE_STONE_EDGE, MOVE_GYRO_BALL, MOVE_YAWN},
		},
		{
			.species = SPECIES_CAMERUPT,
			.heldItem = ITEM_PASSHO_BERRY,
			.fixedIV = 20,
			.nature = NATURE_QUIET,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_EARTH_POWER, MOVE_ROCK_SLIDE, MOVE_YAWN},
		},
		{
			.species = SPECIES_MAGCARGO,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_LAVA_PLUME, MOVE_ANCIENT_POWER, MOVE_EARTH_POWER, MOVE_SHELL_SMASH},
		},
		{
			.species = SPECIES_BLAZIKEN,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_FLARE_BLITZ, MOVE_SKY_UPPERCUT, MOVE_BRAVE_BIRD, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_HOUNDOOM,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_WILL_O_WISP, MOVE_NASTY_PLOT},
		},
		{
			.species = SPECIES_MAGMORTAR,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_THUNDER_PUNCH},
		},
        },

        {
            {
			.species = SPECIES_TORKOAL,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_RELAXED,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_OVERHEAT, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_YAWN},
		},
		{
			.species = SPECIES_CAMERUPT,
			.heldItem = ITEM_PASSHO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {127, 127, 0, 127, 127, 0},
			.moves = {MOVE_EARTH_POWER, MOVE_FISSURE, MOVE_WILL_O_WISP, MOVE_FLAMETHROWER},
		},
		{
			.species = SPECIES_CHANDELURE,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_FLAMETHROWER, MOVE_FLAME_CHARGE, MOVE_SHADOW_BALL, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_BLAZIKEN,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_HIGH_JUMP_KICK, MOVE_EARTHQUAKE, MOVE_FLAME_CHARGE, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_HOUNDOOM,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_HASTY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_OVERHEAT, MOVE_SUCKER_PUNCH, MOVE_FLAME_CHARGE, MOVE_WILL_O_WISP},
		},
		{
			.species = SPECIES_MAGMORTAR,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_THUNDERBOLT, MOVE_FLAME_CHARGE, MOVE_PSYCHIC},
		},
        }
    },

    [TRAINER_FRONTIER_NORMAN] =
    {
        {
        {
			.species = SPECIES_SLAKING,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_GIGA_IMPACT, MOVE_HAMMER_ARM, MOVE_EARTHQUAKE, MOVE_SLACK_OFF},
		},
		{
			.species = SPECIES_SPINDA,
			.heldItem = ITEM_DARK_GEM,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_THRASH, MOVE_SUCKER_PUNCH, MOVE_TEETER_DANCE, MOVE_ASSIST},
		},
		{
			.species = SPECIES_KECLEON,
			.heldItem = ITEM_GANLON_BERRY,
			.fixedIV = 20,
			.nature = NATURE_IMPISH,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_FAKE_OUT, MOVE_SHADOW_CLAW, MOVE_RECOVER, MOVE_SKILL_SWAP},
		},
		{
			.species = SPECIES_CASTFORM,
			.heldItem = ITEM_ICE_GEM,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_HYDRO_PUMP, MOVE_ICY_WIND, MOVE_DISABLE},
		},
		{
			.species = SPECIES_EXPLOUD,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_HYPER_VOICE, MOVE_FOCUS_BLAST, MOVE_FIRE_BLAST, MOVE_ICE_BEAM},
		},
		{
			.species = SPECIES_ZANGOOSE,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_RETURN, MOVE_CLOSE_COMBAT, MOVE_ROCK_SLIDE, MOVE_NIGHT_SLASH},
		},
        },

        {
            {
			.species = SPECIES_SLAKING,
			.heldItem = ITEM_EJECT_BUTTON,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 170, 0, 170, 0, 170},
			.moves = {MOVE_GIGA_IMPACT, MOVE_NIGHT_SLASH, MOVE_EARTHQUAKE, MOVE_HAMMER_ARM},
		},
		{
			.species = SPECIES_AMBIPOM,
			.heldItem = ITEM_NORMAL_GEM,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_RETURN, MOVE_ACROBATICS, MOVE_FAKE_OUT, MOVE_FIRE_PUNCH},
		},
		{
			.species = SPECIES_BOUFFALANT,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_HEAD_CHARGE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_REVENGE},
		},
		{
			.species = SPECIES_STARAPTOR,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_CLOSE_COMBAT, MOVE_QUICK_ATTACK, MOVE_FINAL_GAMBIT},
		},
		{
			.species = SPECIES_EXPLOUD,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_HYPER_VOICE, MOVE_FIRE_BLAST, MOVE_BLIZZARD, MOVE_FOCUS_BLAST},
		},
		{
			.species = SPECIES_SAWSBUCK,
			.heldItem = ITEM_CHESTO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_HORN_LEECH, MOVE_RETURN, MOVE_SWORDS_DANCE, MOVE_REST},
		},
        }
    },

    [TRAINER_FRONTIER_WINONA] =
    {
        {
        {
			.species = SPECIES_ALTARIA,
			.heldItem = ITEM_APICOT_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_ROOST, MOVE_DREAM_EATER, MOVE_SING, MOVE_COTTON_GUARD},
		},
		{
			.species = SPECIES_PELIPPER,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_HURRICANE, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_SWELLOW,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_ENDEAVOR, MOVE_DOUBLE_TEAM, MOVE_U_TURN},
		},
		{
			.species = SPECIES_SKARMORY,
			.heldItem = ITEM_WACAN_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_ROOST, MOVE_WHIRLWIND, MOVE_STEALTH_ROCK},
		},
		{
			.species = SPECIES_TROPIUS,
			.heldItem = ITEM_YACHE_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_AIR_SLASH, MOVE_LEECH_SEED, MOVE_SUBSTITUTE, MOVE_ROOST},
		},
		{
			.species = SPECIES_HONCHKROW,
			.heldItem = ITEM_CHARTI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_NIGHT_SLASH, MOVE_HEAT_WAVE, MOVE_ICY_WIND},
		},
        },

        {
            {
			.species = SPECIES_ALTARIA,
			.heldItem = ITEM_POWER_HERB,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {170, 0, 170, 0, 0, 170},
			.moves = {MOVE_SKY_ATTACK, MOVE_COTTON_GUARD, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_SIGILYPH,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_AIR_SLASH, MOVE_ANCIENT_POWER, MOVE_THUNDER_WAVE},
		},
		{
			.species = SPECIES_GYARADOS,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_DRAGON_DANCE, MOVE_SUBSTITUTE, MOVE_WATERFALL, MOVE_ICE_FANG},
		},
		{
			.species = SPECIES_SKARMORY,
			.heldItem = ITEM_ROCKY_HELMET,
			.fixedIV = 25,
			.nature = NATURE_SASSY,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_WHIRLWIND, MOVE_SPIKES, MOVE_STEEL_WING, MOVE_AERIAL_ACE},
		},
		{
			.species = SPECIES_TROPIUS,
			.heldItem = ITEM_YACHE_BERRY,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {170, 0, 0, 170, 0, 170},
			.moves = {MOVE_SUNNY_DAY, MOVE_AIR_SLASH, MOVE_SOLAR_BEAM, MOVE_ATTRACT},
		},
		{
			.species = SPECIES_HONCHKROW,
			.heldItem = ITEM_DARK_GEM,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DRILL_PECK, MOVE_TAILWIND, MOVE_SUCKER_PUNCH, MOVE_ICY_WIND},
		},
        }
    },

    [TRAINER_FRONTIER_TATE] =
    {
        {
        {
			.species = SPECIES_SOLROCK,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BRAVE,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_ZEN_HEADBUTT, MOVE_ROCK_SLIDE, MOVE_FIRE_BLAST, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_XATU,
			.heldItem = ITEM_WACAN_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FEATHER_DANCE, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_CHIMECHO,
			.heldItem = ITEM_COLBUR_BERRY,
			.fixedIV = 20,
			.nature = NATURE_QUIET,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_DREAM_EATER, MOVE_ENERGY_BALL, MOVE_HYPNOSIS, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_GRUMPIG,
			.heldItem = ITEM_GANLON_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_PSYSHOCK, MOVE_REST, MOVE_SLEEP_TALK, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_GALLADE,
			.heldItem = ITEM_KASIB_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_PSYCHO_CUT, MOVE_STONE_EDGE, MOVE_NIGHT_SLASH, MOVE_LEAF_BLADE},
		},
		{
			.species = SPECIES_CLAYDOL,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_RELAXED,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_EARTH_POWER, MOVE_COSMIC_POWER, MOVE_TRICK_ROOM},
		},
        },

        {
            {
			.species = SPECIES_SOLROCK,
			.heldItem = ITEM_PASSHO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_ROCK_SLIDE, MOVE_ZEN_HEADBUTT, MOVE_TRICK_ROOM, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_XATU,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_LIGHT_SCREEN, MOVE_SHADOW_BALL, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_BRONZONG,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 25,
			.nature = NATURE_SASSY,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_GYRO_BALL, MOVE_EARTHQUAKE, MOVE_ZEN_HEADBUTT, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_REUNICLUS,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_QUIET,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_GALLADE,
			.heldItem = ITEM_SCOPE_LENS,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_PSYCHO_CUT, MOVE_NIGHT_SLASH, MOVE_CLOSE_COMBAT, MOVE_ICE_PUNCH},
		},
		{
			.species = SPECIES_CLAYDOL,
			.heldItem = ITEM_KASIB_BERRY,
			.fixedIV = 25,
			.nature = NATURE_RELAXED,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_TRICK_ROOM, MOVE_EXPLOSION, MOVE_PSYCHIC, MOVE_LIGHT_SCREEN},
		},
        }
    },

    [TRAINER_FRONTIER_LIZA] =
    {
        {
        {
			.species = SPECIES_LUNATONE,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_QUIET,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_DREAM_EATER, MOVE_HYPNOSIS, MOVE_ICE_BEAM, MOVE_COSMIC_POWER},
		},
		{
			.species = SPECIES_XATU,
			.heldItem = ITEM_CHARTI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYSHOCK, MOVE_HEAT_WAVE, MOVE_THUNDER_WAVE, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_CHIMECHO,
			.heldItem = ITEM_COLBUR_BERRY,
			.fixedIV = 20,
			.nature = NATURE_IMPISH,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_PSYCHIC, MOVE_YAWN, MOVE_LIGHT_SCREEN, MOVE_REFLECT},
		},
		{
			.species = SPECIES_GRUMPIG,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_POWER_GEM, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_GARDEVOIR,
			.heldItem = ITEM_GHOST_GEM,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 255, 255},
			.moves = {MOVE_DREAM_EATER, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_HYPNOSIS},
		},
		{
			.species = SPECIES_CLAYDOL,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_IMPISH,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_ZEN_HEADBUTT, MOVE_STONE_EDGE, MOVE_COSMIC_POWER, MOVE_BULLDOZE},
		},
        },

        {
            {
			.species = SPECIES_LUNATONE,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_GRASS_KNOT, MOVE_COSMIC_POWER, MOVE_TRICK_ROOM, MOVE_SIGNAL_BEAM},
		},
		{
			.species = SPECIES_XATU,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {170, 170, 0, 0, 170, 0},
			.moves = {MOVE_PAIN_SPLIT, MOVE_ZEN_HEADBUTT, MOVE_U_TURN, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_BRONZONG,
			.heldItem = ITEM_ROCKY_HELMET,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_IRON_HEAD, MOVE_HYPNOSIS, MOVE_EARTHQUAKE, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_GOTHITELLE,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_RELAXED,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_GARDEVOIR,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_DISABLE, MOVE_PSYCHIC, MOVE_WILL_O_WISP, MOVE_THUNDERBOLT},
		},
		{
			.species = SPECIES_CLAYDOL,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_TRICK_ROOM, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_PSYSHOCK},
		},
        }
    },

    [TRAINER_FRONTIER_WALLACE] =
    {
        {
        {
            .species = SPECIES_MILOTIC,
            .heldItem = ITEM_ROCKY_HELMET,
            .fixedIV = 20,
            .nature = NATURE_MODEST,
            .evs = {252, 0, 0, 0, 0, 252},
            .moves = {MOVE_SCALD, MOVE_ICY_WIND, MOVE_REST, MOVE_SLEEP_TALK},
        },
        {
            .species = SPECIES_SHARPEDO,
            .heldItem = ITEM_FOCUS_SASH,
            .fixedIV = 20,
            .nature = NATURE_LONELY,
            .evs = {0, 252, 0, 252, 0, 0},
            .moves = {MOVE_AQUA_JET, MOVE_ZEN_HEADBUTT, MOVE_HYDRO_PUMP, MOVE_CRUNCH},
        },
        {
            .species = SPECIES_WALREIN,
            .heldItem = ITEM_LEFTOVERS,
            .fixedIV = 20,
            .nature = NATURE_ADAMANT,
            .evs = {252, 0, 252, 0, 0, 0},
            .moves = {MOVE_YAWN, MOVE_BLIZZARD, MOVE_SURF, MOVE_SHEER_COLD},
        },
        {
            .species = SPECIES_LUDICOLO,
            .heldItem = ITEM_LIFE_ORB,
            .fixedIV = 20,
            .nature = NATURE_MODEST,
            .evs = {252, 252, 0, 0, 0, 0},
            .moves = {MOVE_GIGA_DRAIN, MOVE_SURF, MOVE_FOCUS_BLAST, MOVE_RAIN_DANCE},
        },
        {
            .species = SPECIES_SWAMPERT,
            .heldItem = ITEM_RINDO_BERRY,
            .fixedIV = 20,
            .nature = NATURE_LONELY,
            .evs = {252, 0, 0, 0, 252, 0},
            .moves = {MOVE_ICE_BEAM, MOVE_MUDDY_WATER, MOVE_EARTH_POWER, MOVE_FOCUS_BLAST},
        },
        {
            .species = SPECIES_STARMIE,
            .heldItem = ITEM_EXPERT_BELT,
            .fixedIV = 20,
            .nature = NATURE_ADAMANT,
            .evs = {0, 0, 0, 252, 252, 0},
            .moves = {MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_SURF, MOVE_SIGNAL_BEAM},
        },
        },

        {
            {
			.species = SPECIES_MILOTIC,
			.heldItem = ITEM_ROCKY_HELMET,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_SCALD, MOVE_ICY_WIND, MOVE_REST, MOVE_SLEEP_TALK},
		},
		{
			.species = SPECIES_SHARPEDO,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_HASTY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_AQUA_JET, MOVE_ZEN_HEADBUTT, MOVE_HYDRO_PUMP, MOVE_CRUNCH},
		},
		{
			.species = SPECIES_WALREIN,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_YAWN, MOVE_BLIZZARD, MOVE_SURF, MOVE_SHEER_COLD},
		},
		{
			.species = SPECIES_LUDICOLO,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_GIGA_DRAIN, MOVE_SURF, MOVE_FOCUS_BLAST, MOVE_RAIN_DANCE},
		},
		{
			.species = SPECIES_SWAMPERT,
			.heldItem = ITEM_RINDO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_QUIET,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_ICE_BEAM, MOVE_MUDDY_WATER, MOVE_EARTH_POWER, MOVE_FOCUS_BLAST},
		},
		{
			.species = SPECIES_STARMIE,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_SURF, MOVE_SIGNAL_BEAM},
		},
        }
    },

    [TRAINER_FRONTIER_ROARK] =
    {
        {
        {
			.species = SPECIES_RAMPARDOS,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_OUTRAGE},
		},
		{
			.species = SPECIES_PROBOPASS,
			.heldItem = ITEM_CHOPLE_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_POWER_GEM, MOVE_EARTH_POWER, MOVE_SANDSTORM, MOVE_STEALTH_ROCK},
		},
		{
			.species = SPECIES_SUDOWOODO,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_HAMMER_ARM, MOVE_WOOD_HAMMER, MOVE_SUCKER_PUNCH},
		},
		{
			.species = SPECIES_ONIX,
			.heldItem = ITEM_RINDO_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_STONE_EDGE, MOVE_ROAR, MOVE_SANDSTORM, MOVE_STEALTH_ROCK},
		},
		{
			.species = SPECIES_GOLEM,
			.heldItem = ITEM_PASSHO_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BRAVE,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_GYRO_BALL, MOVE_HAMMER_ARM, MOVE_CURSE},
		},
		{
			.species = SPECIES_RELICANTH,
			.heldItem = ITEM_GANLON_BERRY,
			.fixedIV = 20,
			.nature = NATURE_IMPISH,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_ROCK_SLIDE, MOVE_AMNESIA, MOVE_SLEEP_TALK, MOVE_REST},
		},
        },

        {
            {
			.species = SPECIES_RAMPARDOS,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_AVALANCHE},
		},
		{
			.species = SPECIES_PROBOPASS,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_STEALTH_ROCK, MOVE_EARTH_POWER, MOVE_DISCHARGE, MOVE_PAIN_SPLIT},
		},
		{
			.species = SPECIES_ARCHEOPS,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_HASTY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_FOCUS_BLAST, MOVE_QUICK_ATTACK},
		},
		{
			.species = SPECIES_CRUSTLE,
			.heldItem = ITEM_POWER_HERB,
			.fixedIV = 25,
			.nature = NATURE_NAIVE,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ROCK_SLIDE, MOVE_X_SCISSOR, MOVE_SOLAR_BEAM, MOVE_SHELL_SMASH},
		},
		{
			.species = SPECIES_GOLEM,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH, MOVE_EXPLOSION},
		},
		{
			.species = SPECIES_RELICANTH,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_HEAD_SMASH, MOVE_WATERFALL, MOVE_ROCK_POLISH, MOVE_YAWN},
		},
        }
    },

    [TRAINER_FRONTIER_GARDENIA] =
    {
        {
        {
			.species = SPECIES_ROSERADE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PETAL_DANCE, MOVE_SHADOW_BALL, MOVE_WEATHER_BALL, MOVE_SUNNY_DAY},
		},
		{
			.species = SPECIES_CARNIVINE,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_POWER_WHIP, MOVE_CRUNCH, MOVE_BUG_BITE, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_CHERRIM,
			.heldItem = ITEM_GRASS_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_SUBSTITUTE, MOVE_SUNNY_DAY},
		},
		{
			.species = SPECIES_TANGROWTH,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {0, 0, 255, 255, 0, 0},
			.moves = {MOVE_POWER_WHIP, MOVE_FOCUS_BLAST, MOVE_ANCIENT_POWER, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_LEAFEON,
			.heldItem = ITEM_OCCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_LEAF_BLADE, MOVE_X_SCISSOR, MOVE_QUICK_ATTACK, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_TORTERRA,
			.heldItem = ITEM_YACHE_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_CURSE},
		},
        },

        {
            {
			.species = SPECIES_ROSERADE,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PETAL_DANCE, MOVE_SHADOW_BALL, MOVE_WEATHER_BALL, MOVE_SLUDGE_BOMB},
		},
		{
			.species = SPECIES_TROPIUS,
			.heldItem = ITEM_HEAT_ROCK,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_SOLAR_BEAM, MOVE_AIR_SLASH, MOVE_SYNTHESIS, MOVE_SUNNY_DAY},
		},
		{
			.species = SPECIES_BRELOOM,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_SPORE, MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_TANGROWTH,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 25,
			.nature = NATURE_NAIVE,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_POWER_WHIP, MOVE_FOCUS_BLAST, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_LEAFEON,
			.heldItem = ITEM_YACHE_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_LEAF_BLADE, MOVE_X_SCISSOR, MOVE_QUICK_ATTACK, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_TORTERRA,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_STONE_EDGE},
		},
        }
    },

    [TRAINER_FRONTIER_MAYLENE] =
    {
        {
        {
			.species = SPECIES_LUCARIO,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_CROSS_CHOP, MOVE_BONE_RUSH, MOVE_EXTREME_SPEED, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_INFERNAPE,
			.heldItem = ITEM_FIRE_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_CLOSE_COMBAT, MOVE_FIRE_PUNCH, MOVE_MACH_PUNCH, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_TOXICROAK,
			.heldItem = ITEM_PAYAPA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_TORMENT, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_GALLADE,
			.heldItem = ITEM_COBA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_CLOSE_COMBAT, MOVE_PSYCHO_CUT, MOVE_SLASH, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_MEDICHAM,
			.heldItem = ITEM_KASIB_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_BRICK_BREAK, MOVE_ZEN_HEADBUTT, MOVE_BULLET_PUNCH, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_MACHAMP,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_ICE_PUNCH, MOVE_FOCUS_ENERGY},
		},
        },

        {
            {
			.species = SPECIES_LUCARIO,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ICE_PUNCH, MOVE_CLOSE_COMBAT, MOVE_EXTREME_SPEED, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_INFERNAPE,
			.heldItem = ITEM_FIRE_GEM,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_CLOSE_COMBAT, MOVE_FLARE_BLITZ, MOVE_MACH_PUNCH, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_TOXICROAK,
			.heldItem = ITEM_PAYAPA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_DRAIN_PUNCH, MOVE_SUCKER_PUNCH, MOVE_SUBSTITUTE, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_GALLADE,
			.heldItem = ITEM_COBA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_CLOSE_COMBAT, MOVE_PSYCHO_CUT, MOVE_LEAF_BLADE, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_MEDICHAM,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_HIGH_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH},
		},
		{
			.species = SPECIES_MACHAMP,
			.heldItem = ITEM_SCOPE_LENS,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_ICE_PUNCH, MOVE_BULLET_PUNCH},
		},
        }
    },

    [TRAINER_FRONTIER_WAKE] =
    {
        {
        {
			.species = SPECIES_FLOATZEL,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_AQUA_JET, MOVE_ICE_PUNCH, MOVE_FOCUS_BLAST, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_EMPOLEON,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CALM,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_GRASS_KNOT, MOVE_FEATHER_DANCE},
		},
		{
			.species = SPECIES_LUMINEON,
			.heldItem = ITEM_ICE_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_SCALD, MOVE_ICY_WIND, MOVE_U_TURN, MOVE_RAIN_DANCE},
		},
		{
			.species = SPECIES_GASTRODON,
			.heldItem = ITEM_APICOT_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_MUDDY_WATER, MOVE_EARTH_POWER, MOVE_STOCKPILE, MOVE_RECOVER},
		},
		{
			.species = SPECIES_QUAGSIRE,
			.heldItem = ITEM_RINDO_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 0, 0, 255},
			.moves = {MOVE_AQUA_TAIL, MOVE_EARTHQUAKE, MOVE_RAIN_DANCE, MOVE_CURSE},
		},
		{
			.species = SPECIES_GYARADOS,
			.heldItem = ITEM_WACAN_BERRY,
			.fixedIV = 20,
			.nature = NATURE_NAIVE,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_AQUA_TAIL, MOVE_STONE_EDGE, MOVE_OUTRAGE, MOVE_DRAGON_DANCE},
		},
        },

        {
            {
			.species = SPECIES_FLOATZEL,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_AQUA_JET, MOVE_ICE_PUNCH, MOVE_FOCUS_BLAST, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_EMPOLEON,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_HYDRO_PUMP, MOVE_BLIZZARD, MOVE_GRASS_KNOT, MOVE_FEATHER_DANCE},
		},
		{
			.species = SPECIES_LUDICOLO,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_GIGA_DRAIN, MOVE_FOCUS_BLAST, MOVE_RAIN_DANCE},
		},
		{
			.species = SPECIES_GASTRODON,
			.heldItem = ITEM_RINDO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_SURF, MOVE_EARTH_POWER, MOVE_BLIZZARD, MOVE_COUNTER},
		},
		{
			.species = SPECIES_POLIWRATH,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WATERFALL, MOVE_FOCUS_PUNCH, MOVE_ICE_PUNCH, MOVE_HYPNOSIS},
		},
		{
			.species = SPECIES_GYARADOS,
			.heldItem = ITEM_WACAN_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_AQUA_TAIL, MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_DRAGON_DANCE},
		},
        }
    },

    [TRAINER_FRONTIER_FANTINA] =
    {
        {
        {
			.species = SPECIES_MISMAGIUS,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_POWER_GEM},
		},
		{
			.species = SPECIES_DRIFBLIM,
			.heldItem = ITEM_FLYING_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_THUNDER, MOVE_ACROBATICS, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_SPIRITOMB,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_DARK_PULSE, MOVE_WILL_O_WISP, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_DUSKNOIR,
			.heldItem = ITEM_APICOT_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CAREFUL,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_SHADOW_SNEAK, MOVE_CURSE, MOVE_PAIN_SPLIT, MOVE_CONFUSE_RAY},
		},
		{
			.species = SPECIES_ROTOM,
			.heldItem = ITEM_ELECTRIC_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_CHARGE_BEAM, MOVE_SUBSTITUTE, MOVE_PAIN_SPLIT},
		},
		{
			.species = SPECIES_GENGAR,
			.heldItem = ITEM_PSYCHIC_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_HEX, MOVE_DREAM_EATER, MOVE_NIGHTMARE, MOVE_HYPNOSIS},
		},
        },

        {
            {
			.species = SPECIES_MISMAGIUS,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_PAIN_SPLIT},
		},
		{
			.species = SPECIES_DRIFBLIM,
			.heldItem = ITEM_FLYING_GEM,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_ACROBATICS, MOVE_WILL_O_WISP, MOVE_EXPLOSION, MOVE_SUCKER_PUNCH},
		},
		{
			.species = SPECIES_SPIRITOMB,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 25,
			.nature = NATURE_QUIET,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_SUCKER_PUNCH, MOVE_NASTY_PLOT},
		},
		{
			.species = SPECIES_DUSKNOIR,
			.heldItem = ITEM_APICOT_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CAREFUL,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_SHADOW_SNEAK, MOVE_CURSE, MOVE_PAIN_SPLIT, MOVE_WILL_O_WISP},
		},
		{
			.species = SPECIES_JELLICENT,
			.heldItem = ITEM_GHOST_GEM,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_BRINE, MOVE_RECOVER, MOVE_WATER_SPOUT},
		},
		{
			.species = SPECIES_GENGAR,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_NIGHTMARE, MOVE_HYPNOSIS},
		},
        }
    },

    [TRAINER_FRONTIER_BYRON] =
    {
        {
        {
			.species = SPECIES_BASTIODON,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_METAL_BURST, MOVE_FIRE_BLAST, MOVE_STEALTH_ROCK, MOVE_IRON_DEFENSE},
		},
		{
			.species = SPECIES_STEELIX,
			.heldItem = ITEM_PASSHO_BERRY,
			.fixedIV = 20,
			.nature = NATURE_SASSY,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_GYRO_BALL, MOVE_DRAGON_TAIL, MOVE_CURSE, MOVE_STEALTH_ROCK},
		},
		{
			.species = SPECIES_BRONZONG,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_SASSY,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_GYRO_BALL, MOVE_HYPNOSIS, MOVE_ZEN_HEADBUTT, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_MAGNEZONE,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 20,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_FLASH_CANNON, MOVE_CHARGE_BEAM, MOVE_BARRIER, MOVE_LIGHT_SCREEN},
		},
		{
			.species = SPECIES_AGGRON,
			.heldItem = ITEM_CHOPLE_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_OUTRAGE, MOVE_AUTOTOMIZE},
		},
		{
			.species = SPECIES_FORRETRESS,
			.heldItem = ITEM_OCCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CAREFUL,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_GYRO_BALL, MOVE_LIGHT_SCREEN, MOVE_IRON_DEFENSE, MOVE_SPIKES},
		},
        },

        {
            {
			.species = SPECIES_BASTIODON,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_METAL_BURST, MOVE_FIRE_BLAST, MOVE_STEALTH_ROCK, MOVE_IRON_DEFENSE},
		},
		{
			.species = SPECIES_EXCADRILL,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_X_SCISSOR, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SUBMISSION},
		},
		{
			.species = SPECIES_BRONZONG,
			.heldItem = ITEM_IRON_BALL,
			.fixedIV = 25,
			.nature = NATURE_BRAVE,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_GYRO_BALL, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_TRICK_ROOM},
		},
		{
			.species = SPECIES_MAGNEZONE,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_EXPLOSION, MOVE_MIRROR_COAT, MOVE_PROTECT, MOVE_REFLECT},
		},
		{
			.species = SPECIES_AGGRON,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 255, 0, 0, 0},
			.moves = {MOVE_HEAD_SMASH, MOVE_IRON_HEAD, MOVE_FIRE_PUNCH, MOVE_DRAGON_RUSH},
		},
		{
			.species = SPECIES_FORRETRESS,
			.heldItem = ITEM_LIGHT_CLAY,
			.fixedIV = 25,
			.nature = NATURE_SASSY,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_GYRO_BALL, MOVE_STEALTH_ROCK, MOVE_EARTHQUAKE, MOVE_REFLECT},
		},
        }
    },

    [TRAINER_FRONTIER_CANDICE] =
    {
        {
        {
			.species = SPECIES_FROSLASS,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_HAIL},
		},
		{
			.species = SPECIES_ABOMASNOW,
			.heldItem = ITEM_OCCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_NAUGHTY,
			.evs = {0, 255, 0, 0, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_GRASS_KNOT, MOVE_EARTHQUAKE, MOVE_INGRAIN},
		},
		{
			.species = SPECIES_WEAVILE,
			.heldItem = ITEM_CHOPLE_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ICE_PUNCH, MOVE_NIGHT_SLASH, MOVE_REVENGE, MOVE_TORMENT},
		},
		{
			.species = SPECIES_GLACEON,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 0, 255, 255},
			.moves = {MOVE_ICY_WIND, MOVE_SHADOW_BALL, MOVE_SIGNAL_BEAM, MOVE_YAWN},
		},
		{
			.species = SPECIES_MAMOSWINE,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_JOLLY,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_ICICLE_CRASH, MOVE_BULLDOZE, MOVE_SUPERPOWER, MOVE_ROCK_TOMB},
		},
		{
			.species = SPECIES_GLALIE,
			.heldItem = ITEM_ROCK_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_ICE_BEAM, MOVE_CRUNCH, MOVE_ROLLOUT, MOVE_HAIL},
		},
        },

        {
            {
			.species = SPECIES_FROSLASS,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_HAIL},
		},
		{
			.species = SPECIES_ABOMASNOW,
			.heldItem = ITEM_OCCA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_NAUGHTY,
			.evs = {0, 255, 0, 0, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_WOOD_HAMMER, MOVE_EARTHQUAKE, MOVE_INGRAIN},
		},
		{
			.species = SPECIES_WEAVILE,
			.heldItem = ITEM_CHOPLE_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ICE_PUNCH, MOVE_NIGHT_SLASH, MOVE_BRICK_BREAK, MOVE_TORMENT},
		},
		{
			.species = SPECIES_GLACEON,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 255, 0, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_SHADOW_BALL, MOVE_SIGNAL_BEAM, MOVE_ICE_SHARD},
		},
		{
			.species = SPECIES_MAMOSWINE,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_ICICLE_CRASH, MOVE_BULLDOZE, MOVE_SUPERPOWER, MOVE_ROCK_TOMB},
		},
		{
			.species = SPECIES_GLALIE,
			.heldItem = ITEM_ROCK_GEM,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_BLIZZARD, MOVE_CRUNCH, MOVE_ROLLOUT, MOVE_HAIL},
		},
        }
    },

    [TRAINER_FRONTIER_VOLKNER] =
    {
        {
        {
			.species = SPECIES_ELECTIVIRE,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WILD_CHARGE, MOVE_BRICK_BREAK, MOVE_ICE_PUNCH, MOVE_BULLDOZE},
		},
		{
			.species = SPECIES_LUXRAY,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_WILD_CHARGE, MOVE_CRUNCH, MOVE_SUPERPOWER, MOVE_THUNDER_WAVE},
		},
		{
			.species = SPECIES_RAICHU,
			.heldItem = ITEM_GRASS_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_CHARGE_BEAM, MOVE_FOCUS_BLAST, MOVE_GRASS_KNOT, MOVE_CHARGE},
		},
		{
			.species = SPECIES_ROTOM,
			.heldItem = ITEM_COLBUR_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CALM,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_DISCHARGE, MOVE_HEX, MOVE_PAIN_SPLIT, MOVE_WILL_O_WISP},
		},
		{
			.species = SPECIES_JOLTEON,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, MOVE_CHARM, MOVE_WISH},
		},
		{
			.species = SPECIES_ELECTRODE,
			.heldItem = ITEM_ELECTRIC_GEM,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_ELECTRO_BALL, MOVE_SIGNAL_BEAM, MOVE_TAUNT, MOVE_TORMENT},
		},
        },

        {
            {
			.species = SPECIES_ELECTIVIRE,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WILD_CHARGE, MOVE_CROSS_CHOP, MOVE_ICE_PUNCH, MOVE_BULLDOZE},
		},
		{
			.species = SPECIES_LUXRAY,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_WILD_CHARGE, MOVE_CRUNCH, MOVE_SUPERPOWER, MOVE_THUNDER_WAVE},
		},
		{
			.species = SPECIES_RAICHU,
			.heldItem = ITEM_GRASS_GEM,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_GRASS_KNOT, MOVE_CHARGE},
		},
		{
			.species = SPECIES_ROTOM_FAN,
			.heldItem = ITEM_KINGS_ROCK,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {0, 0, 255, 0, 0, 255},
			.moves = {MOVE_DISCHARGE, MOVE_AIR_SLASH, MOVE_PAIN_SPLIT, MOVE_SUBSTITUTE},
		},
		{
			.species = SPECIES_JOLTEON,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, MOVE_CHARM, MOVE_WISH},
		},
		{
			.species = SPECIES_ELECTRODE,
			.heldItem = ITEM_ELECTRIC_GEM,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_THUNDER, MOVE_SIGNAL_BEAM, MOVE_TAUNT, MOVE_TORMENT},
		},
        }
    },

    [TRAINER_FRONTIER_CILAN] =
    {
        {
        {
			.species = SPECIES_SIMISAGE,
			.heldItem = ITEM_GRASS_GEM,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_SEED_BOMB, MOVE_LOW_KICK, MOVE_ACROBATICS, MOVE_TICKLE},
		},
		{
			.species = SPECIES_FERROTHORN,
			.heldItem = ITEM_APICOT_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CAREFUL,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_POWER_WHIP, MOVE_GYRO_BALL, MOVE_BULLDOZE, MOVE_CURSE},
		},
		{
			.species = SPECIES_MARACTUS,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_PETAL_DANCE, MOVE_SUCKER_PUNCH, MOVE_SYNTHESIS, MOVE_COTTON_GUARD},
		},
		{
			.species = SPECIES_JUMPLUFF,
			.heldItem = ITEM_YACHE_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_LEECH_SEED, MOVE_COTTON_SPORE, MOVE_COTTON_SPORE, MOVE_SLEEP_POWDER},
		},
		{
			.species = SPECIES_WHIMSICOTT,
			.heldItem = ITEM_OCCA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_CALM,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_GIGA_DRAIN, MOVE_HURRICANE, MOVE_ENCORE, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_LILLIGANT,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_PETAL_DANCE, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_TEETER_DANCE},
		},
        },

        {
            {
			.species = SPECIES_SIMISAGE,
			.heldItem = ITEM_GRASS_GEM,
			.fixedIV = 25,
			.nature = NATURE_NAIVE,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_SEED_BOMB, MOVE_LOW_KICK, MOVE_ACROBATICS, MOVE_CRUNCH},
		},
		{
			.species = SPECIES_FERROTHORN,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_BRAVE,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_POWER_WHIP, MOVE_GYRO_BALL, MOVE_BULLDOZE, MOVE_EXPLOSION},
		},
		{
			.species = SPECIES_SERPERIOR,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {0, 0, 255, 255, 0, 0},
			.moves = {MOVE_LEECH_SEED, MOVE_PROTECT, MOVE_AERIAL_ACE, MOVE_LEAF_BLADE},
		},
		{
			.species = SPECIES_JUMPLUFF,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_LEECH_SEED, MOVE_COTTON_GUARD, MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER},
		},
		{
			.species = SPECIES_WHIMSICOTT,
			.heldItem = ITEM_MENTAL_HERB,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_GIGA_DRAIN, MOVE_SUBSTITUTE, MOVE_HURRICANE, MOVE_LEECH_SEED},
		},
		{
			.species = SPECIES_LILLIGANT,
			.heldItem = ITEM_MIRACLE_SEED,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PETAL_DANCE, MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_DREAM_EATER},
		},
        }
    },

    [TRAINER_FRONTIER_CHILI] =
    {
        {
        {
			.species = SPECIES_SIMISEAR,
			.heldItem = ITEM_FIRE_GEM,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_HEAT_WAVE, MOVE_LOW_KICK, MOVE_ROCK_SLIDE, MOVE_WORK_UP},
		},
		{
			.species = SPECIES_CAMERUPT,
			.heldItem = ITEM_PASSHO_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_LAVA_PLUME, MOVE_EARTH_POWER, MOVE_YAWN, MOVE_STOCKPILE},
		},
		{
			.species = SPECIES_HEATMOR,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_QUIRKY,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_HEAT_WAVE, MOVE_SUCKER_PUNCH, MOVE_FOCUS_BLAST, MOVE_STOCKPILE},
		},
		{
			.species = SPECIES_DARMANITAN,
			.heldItem = ITEM_FIGHTING_GEM,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_FLARE_BLITZ, MOVE_HAMMER_ARM, MOVE_ROCK_SLIDE, MOVE_U_TURN},
		},
		{
			.species = SPECIES_ARCANINE,
			.heldItem = ITEM_DRAGON_GEM,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_DRAGON_PULSE, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY},
		},
		{
			.species = SPECIES_MAGMORTAR,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_FLAME_CHARGE, MOVE_ROCK_SLIDE, MOVE_PSYCHIC, MOVE_THUNDERBOLT},
		},
        },

        {
            {
			.species = SPECIES_SIMISEAR,
			.heldItem = ITEM_FIRE_GEM,
			.fixedIV = 25,
			.nature = NATURE_NAIVE,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_OVERHEAT, MOVE_LOW_KICK, MOVE_ACROBATICS, MOVE_CRUNCH},
		},
		{
			.species = SPECIES_CAMERUPT,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_BRAVE,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_OVERHEAT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_EXPLOSION},
		},
		{
			.species = SPECIES_HEATMOR,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_SUCKER_PUNCH, MOVE_FOCUS_BLAST, MOVE_SUNNY_DAY},
		},
		{
			.species = SPECIES_DARMANITAN,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_FLARE_BLITZ, MOVE_HAMMER_ARM, MOVE_STONE_EDGE, MOVE_U_TURN},
		},
		{
			.species = SPECIES_ARCANINE,
			.heldItem = ITEM_POWER_HERB,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_OVERHEAT, MOVE_DRAGON_PULSE, MOVE_SOLAR_BEAM, MOVE_EXTREME_SPEED},
		},
		{
			.species = SPECIES_EMBOAR,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_LONELY,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_FLARE_BLITZ, MOVE_HEAD_SMASH, MOVE_HAMMER_ARM, MOVE_WILD_CHARGE},
		},
        }
    },

    [TRAINER_FRONTIER_CRESS] =
    {
        {
        {
			.species = SPECIES_SIMIPOUR,
			.heldItem = ITEM_WATER_GEM,
			.fixedIV = 20,
			.nature = NATURE_HARDY,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_GRASS_KNOT, MOVE_ACROBATICS, MOVE_WORK_UP},
		},
		{
			.species = SPECIES_GOLDUCK,
			.heldItem = ITEM_PETAYA_BERRY,
			.fixedIV = 20,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_FLOATZEL,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_WATERFALL, MOVE_ICE_PUNCH, MOVE_BRICK_BREAK, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_AZUMARILL,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_AQUA_TAIL, MOVE_BRICK_BREAK, MOVE_BULLDOZE, MOVE_ROLLOUT},
		},
		{
			.species = SPECIES_SLOWKING,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_BOLD,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_SCALD, MOVE_PSYCHIC, MOVE_YAWN, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_BASCULIN,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 20,
			.nature = NATURE_ADAMANT,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_AQUA_TAIL, MOVE_CRUNCH, MOVE_DOUBLE_EDGE, MOVE_FLAIL},
		},
        },

        {
            {
			.species = SPECIES_SIMIPOUR,
			.heldItem = ITEM_WATER_GEM,
			.fixedIV = 25,
			.nature = NATURE_NAIVE,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_LOW_KICK, MOVE_ACROBATICS, MOVE_CRUNCH},
		},
		{
			.species = SPECIES_CRAWDAUNT,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_CRUNCH, MOVE_WATERFALL, MOVE_BRICK_BREAK, MOVE_GUILLOTINE},
		},
		{
			.species = SPECIES_SAMUROTT,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_RAZOR_SHELL, MOVE_MEGAHORN, MOVE_AQUA_JET, MOVE_REVENGE},
		},
		{
			.species = SPECIES_AZUMARILL,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_AQUA_JET, MOVE_AQUA_TAIL, MOVE_SUPERPOWER, MOVE_GIGA_IMPACT},
		},
		{
			.species = SPECIES_SLOWKING,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_PSYCHIC, MOVE_BLIZZARD, MOVE_FIRE_BLAST, MOVE_NASTY_PLOT},
		},
		{
			.species = SPECIES_SEISMITOAD,
			.heldItem = ITEM_RINDO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_HASTY,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_POISON_JAB, MOVE_EARTH_POWER, MOVE_RAIN_DANCE},
		},
        }
    },

    [TRAINER_FRONTIER_LENORA] =
    {
        {
        {
			.species = SPECIES_WATCHOG,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_SUPER_FANG, MOVE_LOW_KICK, MOVE_CONFUSE_RAY, MOVE_HYPNOSIS},
		},
		{
			.species = SPECIES_AUDINO,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_BLIZZARD, MOVE_THUNDER, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_CLEFABLE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_METEOR_MASH, MOVE_THUNDER_PUNCH, MOVE_WISH, MOVE_COSMIC_POWER},
		},
		{
			.species = SPECIES_SAWSBUCK,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_RETALIATE, MOVE_HORN_LEECH, MOVE_WILD_CHARGE, MOVE_JUMP_KICK},
		},
		{
			.species = SPECIES_KANGASKHAN,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_FAKE_OUT, MOVE_OUTRAGE, MOVE_HAMMER_ARM, MOVE_AQUA_TAIL},
		},
		{
			.species = SPECIES_DUNSPARCE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_ROCK_SLIDE, MOVE_COIL, MOVE_ROOST, MOVE_GLARE},
		},
        },

        {
            {
			.species = SPECIES_WATCHOG,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {255, 0, 0, 255, 0, 0},
			.moves = {MOVE_SUPER_FANG, MOVE_FLAIL, MOVE_CONFUSE_RAY, MOVE_HYPNOSIS},
		},
		{
			.species = SPECIES_CINCCINO,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SWIFT, MOVE_FOCUS_BLAST, MOVE_GRASS_KNOT, MOVE_THUNDERBOLT},
		},
		{
			.species = SPECIES_BRAVIARY,
			.heldItem = ITEM_POWER_HERB,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 170, 0, 170, 0, 170},
			.moves = {MOVE_SKY_ATTACK, MOVE_SUPERPOWER, MOVE_U_TURN, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_SAWSBUCK,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_RETURN, MOVE_HORN_LEECH, MOVE_MEGAHORN, MOVE_WILD_CHARGE},
		},
		{
			.species = SPECIES_KANGASKHAN,
			.heldItem = ITEM_CHOPLE_BERRY,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 255, 0, 0, 0},
			.moves = {MOVE_FAKE_OUT, MOVE_ICE_PUNCH, MOVE_HAMMER_ARM, MOVE_SUCKER_PUNCH},
		},
		{
			.species = SPECIES_LICKILICKY,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_SURF, MOVE_THUNDERBOLT},
		},
        }
    },

    [TRAINER_FRONTIER_BURGH] =
    {
        {
        {
			.species = SPECIES_LEAVANNY,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_X_SCISSOR, MOVE_LEAF_BLADE, MOVE_AERIAL_ACE, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_VESPIQUEN,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_ATTACK_ORDER, MOVE_DEFEND_ORDER, MOVE_ROOST, MOVE_TOXIC},
		},
		{
			.species = SPECIES_CRUSTLE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_X_SCISSOR, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_SHELL_SMASH},
		},
		{
			.species = SPECIES_ESCAVALIER,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_MEGAHORN, MOVE_IRON_HEAD, MOVE_POISON_JAB, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_ACCELGOR,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_BUG_BUZZ, MOVE_SPIKES, MOVE_FOCUS_BLAST, MOVE_GUARD_SPLIT},
		},
		{
			.species = SPECIES_DURANT,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_X_SCISSOR, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_HONE_CLAWS},
		},
        },

        {
            {
			.species = SPECIES_LEAVANNY,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_X_SCISSOR, MOVE_LEAF_BLADE, MOVE_AERIAL_ACE, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_VESPIQUEN,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_ATTACK_ORDER, MOVE_DEFEND_ORDER, MOVE_ROOST, MOVE_TOXIC},
		},
		{
			.species = SPECIES_CRUSTLE,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_X_SCISSOR, MOVE_ROCK_BLAST, MOVE_EARTHQUAKE, MOVE_SHELL_SMASH},
		},
		{
			.species = SPECIES_HERACROSS,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_MEGAHORN, MOVE_CLOSE_COMBAT, MOVE_SHADOW_CLAW, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_ACCELGOR,
			.heldItem = ITEM_BRIGHT_POWDER,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_BUG_BUZZ, MOVE_FOCUS_BLAST, MOVE_GIGA_DRAIN, MOVE_DOUBLE_TEAM},
		},
		{
			.species = SPECIES_DURANT,
			.heldItem = ITEM_WIDE_LENS,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_X_SCISSOR, MOVE_IRON_HEAD, MOVE_STONE_EDGE, MOVE_GUILLOTINE},
		},
        }
    },

    [TRAINER_FRONTIER_ELESA] =
    {
        {
        {
			.species = SPECIES_ZEBSTRIKA,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_WILD_CHARGE, MOVE_FLAME_CHARGE, MOVE_THRASH, MOVE_ME_FIRST},
		},
		{
			.species = SPECIES_AMPHAROS,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_DISCHARGE, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM, MOVE_COTTON_GUARD},
		},
		{
			.species = SPECIES_GALVANTULA,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_THUNDER, MOVE_ENERGY_BALL, MOVE_BUG_BUZZ, MOVE_DISABLE},
		},
		{
			.species = SPECIES_EMOLGA,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_VOLT_SWITCH, MOVE_ACROBATICS, MOVE_ATTRACT, MOVE_THUNDER_WAVE},
		},
		{
			.species = SPECIES_EELEKTROSS,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_ZAP_CANNON, MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_COIL},
		},
		{
			.species = SPECIES_STUNFISK,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_DISCHARGE, MOVE_EARTH_POWER, MOVE_MUDDY_WATER, MOVE_STONE_EDGE},
		},
        },

        {
            {
			.species = SPECIES_ZEBSTRIKA,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WILD_CHARGE, MOVE_OVERHEAT, MOVE_RETURN, MOVE_QUICK_ATTACK},
		},
		{
			.species = SPECIES_AMPHAROS,
			.heldItem = ITEM_SHUCA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 255, 0, 255, 0},
			.moves = {MOVE_DISCHARGE, MOVE_SIGNAL_BEAM, MOVE_POWER_GEM, MOVE_FOCUS_BLAST},
		},
		{
			.species = SPECIES_LUXRAY,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 255, 0, 0, 0},
			.moves = {MOVE_WILD_CHARGE, MOVE_FIRE_FANG, MOVE_ICE_FANG, MOVE_QUICK_ATTACK},
		},
		{
			.species = SPECIES_EMOLGA,
			.heldItem = ITEM_FLYING_GEM,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_U_TURN, MOVE_WILD_CHARGE, MOVE_ACROBATICS, MOVE_CHARM},
		},
		{
			.species = SPECIES_EELEKTROSS,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_DRAGON_CLAW, MOVE_BRICK_BREAK},
		},
		{
			.species = SPECIES_STUNFISK,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_DISCHARGE, MOVE_EARTH_POWER, MOVE_SCALD, MOVE_FOUL_PLAY},
		},
        }
    },

    [TRAINER_FRONTIER_CLAY] =
    {
        {
        {
			.species = SPECIES_EXCADRILL,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_DRILL_RUN, MOVE_ROCK_SLIDE, MOVE_SUBMISSION, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_CLAYDOL,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_EARTH_POWER, MOVE_PSYCHIC, MOVE_COSMIC_POWER, MOVE_SANDSTORM},
		},
		{
			.species = SPECIES_KROOKODILE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_OUTRAGE, MOVE_ROCK_SLIDE},
		},
		{
			.species = SPECIES_SEISMITOAD,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_EARTH_POWER, MOVE_MUDDY_WATER, MOVE_DRAIN_PUNCH, MOVE_ICE_PUNCH},
		},
		{
			.species = SPECIES_MAMOSWINE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_STONE_EDGE, MOVE_SANDSTORM},
		},
		{
			.species = SPECIES_GOLURK,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_PUNCH, MOVE_STONE_EDGE, MOVE_HAMMER_ARM},
		},
        },

        {
            {
			.species = SPECIES_EXCADRILL,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DRILL_RUN, MOVE_ROCK_SLIDE, MOVE_SUBMISSION, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_FLYGON,
			.heldItem = ITEM_LIECHI_BERRY,
			.fixedIV = 25,
			.nature = NATURE_NAIVE,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_OUTRAGE, MOVE_EARTH_POWER, MOVE_FIRE_BLAST, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_KROOKODILE,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_STONE_EDGE, MOVE_AQUA_TAIL},
		},
		{
			.species = SPECIES_SEISMITOAD,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_EARTH_POWER, MOVE_HYDRO_PUMP, MOVE_FOCUS_BLAST, MOVE_GRASS_KNOT},
		},
		{
			.species = SPECIES_MAMOSWINE,
			.heldItem = ITEM_ICE_GEM,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_ICE_SHARD, MOVE_STONE_EDGE, MOVE_FISSURE},
		},
		{
			.species = SPECIES_GOLURK,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_SUBSTITUTE, MOVE_SHADOW_PUNCH, MOVE_EARTHQUAKE, MOVE_FOCUS_PUNCH},
		},
        }
    },

    [TRAINER_FRONTIER_SKYLA] =
    {
        {
        {
			.species = SPECIES_SWANNA,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_HURRICANE, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_UNFEZANT,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_AIR_SLASH, MOVE_U_TURN, MOVE_GIGA_IMPACT, MOVE_HYPNOSIS},
		},
		{
			.species = SPECIES_SWOOBAT,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_AIR_SLASH, MOVE_PSYCHIC, MOVE_ATTRACT, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_MANDIBUZZ,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_TOXIC, MOVE_DOUBLE_TEAM, MOVE_ROOST},
		},
		{
			.species = SPECIES_ARCHEOPS,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_ACROBATICS, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW},
		},
		{
			.species = SPECIES_BRAVIARY,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_ROCK_SLIDE, MOVE_CRUSH_CLAW, MOVE_BULK_UP},
		},
        },

        {
            {
			.species = SPECIES_SWANNA,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_HURRICANE, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_JUMPLUFF,
			.heldItem = ITEM_FLYING_GEM,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_SLEEP_POWDER, MOVE_ACROBATICS, MOVE_BULLET_SEED, MOVE_U_TURN},
		},
		{
			.species = SPECIES_DRIFBLIM,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_ICY_WIND},
		},
		{
			.species = SPECIES_MANDIBUZZ,
			.heldItem = ITEM_SALAC_BERRY,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_DARK_PULSE, MOVE_AIR_SLASH, MOVE_NASTY_PLOT, MOVE_ROOST},
		},
		{
			.species = SPECIES_ARCHEOPS,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ACROBATICS, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW},
		},
		{
			.species = SPECIES_BRAVIARY,
			.heldItem = ITEM_WHITE_HERB,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_SUPERPOWER, MOVE_ROCK_SLIDE, MOVE_U_TURN},
		},
        }
    },

    [TRAINER_FRONTIER_BRYCEN] =
    {
        {
        {
			.species = SPECIES_CRYOGONAL,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_BLIZZARD, MOVE_FLASH_CANNON, MOVE_CONFUSE_RAY, MOVE_DOUBLE_TEAM},
		},
		{
			.species = SPECIES_BEARTIC,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_ICICLE_CRASH, MOVE_SUPERPOWER, MOVE_STONE_EDGE, MOVE_BULK_UP},
		},
		{
			.species = SPECIES_VANILLUXE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_BLIZZARD, MOVE_FLASH_CANNON, MOVE_WEATHER_BALL, MOVE_HAIL},
		},
		{
			.species = SPECIES_WEAVILE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_ICE_PUNCH, MOVE_SHADOW_CLAW, MOVE_LOW_KICK, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_DEWGONG,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_FROST_BREATH, MOVE_BRINE, MOVE_SIGNAL_BEAM, MOVE_STOCKPILE},
		},
		{
			.species = SPECIES_WALREIN,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_FROST_BREATH, MOVE_SURF, MOVE_SUPER_FANG, MOVE_YAWN},
		},
        },

        {
            {
			.species = SPECIES_CRYOGONAL,
			.heldItem = ITEM_WIDE_LENS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_FLASH_CANNON, MOVE_SHEER_COLD, MOVE_ICE_SHARD},
		},
		{
			.species = SPECIES_BEARTIC,
			.heldItem = ITEM_BRIGHT_POWDER,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ICICLE_CRASH, MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_VANILLUXE,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_BLIZZARD, MOVE_PROTECT, MOVE_WEATHER_BALL, MOVE_HAIL},
		},
		{
			.species = SPECIES_WEAVILE,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_NIGHT_SLASH, MOVE_ICE_SHARD, MOVE_FAKE_OUT, MOVE_BRICK_BREAK},
		},
		{
			.species = SPECIES_DEWGONG,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_AQUA_JET, MOVE_FROST_BREATH, MOVE_DRILL_RUN, MOVE_FAKE_OUT},
		},
		{
			.species = SPECIES_WALREIN,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_BRAVE,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_AQUA_TAIL, MOVE_SUPER_FANG, MOVE_AVALANCHE},
		},
        }
    },

    [TRAINER_FRONTIER_DRAYDEN] =
    {
        {
        {
			.species = SPECIES_HAXORUS,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_DRAGON_DANCE},
		},
		{
			.species = SPECIES_DRUDDIGON,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_OUTRAGE, MOVE_FIRE_FANG, MOVE_SUCKER_PUNCH, MOVE_GLARE},
		},
		{
			.species = SPECIES_HYDREIGON,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_DRAGON_PULSE, MOVE_DARK_PULSE, MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST},
		},
		{
			.species = SPECIES_FLYGON,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_OUTRAGE, MOVE_EARTH_POWER, MOVE_FLAMETHROWER, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_ALTARIA,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_OUTRAGE, MOVE_ROOST, MOVE_DRAGON_DANCE, MOVE_COTTON_GUARD},
		},
		{
			.species = SPECIES_SALAMENCE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_DRAGON_RUSH, MOVE_THUNDER_FANG, MOVE_FIRE_BLAST, MOVE_HONE_CLAWS},
		},
        },

        {
            {
			.species = SPECIES_HAXORUS,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_DRAGON_DANCE},
		},
		{
			.species = SPECIES_DRUDDIGON,
			.heldItem = ITEM_ROCKY_HELMET,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_DRAGON_TAIL, MOVE_FIRE_FANG, MOVE_GLARE, MOVE_REST},
		},
		{
			.species = SPECIES_HYDREIGON,
			.heldItem = ITEM_CHOICE_SPECS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_DRAGON_PULSE, MOVE_DARK_PULSE, MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST},
		},
		{
			.species = SPECIES_FLYGON,
			.heldItem = ITEM_WIDE_LENS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_EARTH_POWER, MOVE_DRACO_METEOR, MOVE_FIRE_BLAST, MOVE_U_TURN},
		},
		{
			.species = SPECIES_ALTARIA,
			.heldItem = ITEM_YACHE_BERRY,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_DRACO_METEOR, MOVE_ROOST, MOVE_PERISH_SONG, MOVE_COTTON_GUARD},
		},
		{
			.species = SPECIES_SALAMENCE,
			.heldItem = ITEM_WHITE_HERB,
			.fixedIV = 25,
			.nature = NATURE_NAIVE,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_DRACO_METEOR, MOVE_HYDRO_PUMP, MOVE_FIRE_BLAST, MOVE_TAILWIND},
		},
        }
    },

    [TRAINER_FRONTIER_CHEREN] =
    {
        {
        {
			.species = SPECIES_STOUTLAND,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_TAKE_DOWN, MOVE_CRUNCH, MOVE_WILD_CHARGE, MOVE_REVERSAL},
		},
		{
			.species = SPECIES_ZANGOOSE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_CRUSH_CLAW, MOVE_CLOSE_COMBAT, MOVE_X_SCISSOR, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_CINCCINO,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_TAIL_SLAP, MOVE_ROCK_BLAST, MOVE_BULLET_SEED, MOVE_U_TURN},
		},
		{
			.species = SPECIES_LOPUNNY,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_DIZZY_PUNCH, MOVE_JUMP_KICK, MOVE_ICE_PUNCH, MOVE_CHARM},
		},
		{
			.species = SPECIES_CASTFORM,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_WEATHER_BALL, MOVE_HYDRO_PUMP, MOVE_FIRE_BLAST, MOVE_BLIZZARD},
		},
		{
			.species = SPECIES_BOUFFALANT,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_HEAD_CHARGE, MOVE_MEGAHORN, MOVE_WILD_CHARGE, MOVE_EARTHQUAKE},
		},
        },

        {
            {
			.species = SPECIES_STOUTLAND,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_RETURN, MOVE_CRUNCH, MOVE_ICE_FANG, MOVE_REVERSAL},
		},
		{
			.species = SPECIES_PORYGON_Z,
			.heldItem = ITEM_CHOPLE_BERRY,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_SIGNAL_BEAM, MOVE_THUNDER},
		},
		{
			.species = SPECIES_CINCCINO,
			.heldItem = ITEM_KINGS_ROCK,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_TAIL_SLAP, MOVE_ROCK_BLAST, MOVE_BULLET_SEED, MOVE_AQUA_TAIL},
		},
		{
			.species = SPECIES_LICKILICKY,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_NAUGHTY,
			.evs = {0, 255, 255, 0, 0, 0},
			.moves = {MOVE_HAMMER_ARM, MOVE_POWER_WHIP, MOVE_THUNDER, MOVE_ICE_PUNCH},
		},
		{
			.species = SPECIES_CASTFORM,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_WEATHER_BALL, MOVE_ICE_BEAM, MOVE_RAIN_DANCE, MOVE_THUNDER},
		},
		{
			.species = SPECIES_BOUFFALANT,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 255, 0, 0, 0},
			.moves = {MOVE_HEAD_CHARGE, MOVE_MEGAHORN, MOVE_WILD_CHARGE, MOVE_REVENGE},
		},
        }
    },

    [TRAINER_FRONTIER_ROXIE] =
    {
        {
        {
			.species = SPECIES_SCOLIPEDE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_TOXIC_SPIKES, MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
		},
		{
			.species = SPECIES_SEVIPER,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_SLUDGE_WAVE, MOVE_DARK_PULSE, MOVE_DRAGON_TAIL, MOVE_GLARE},
		},
		{
			.species = SPECIES_GARBODOR,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_GUNK_SHOT, MOVE_ROCK_BLAST, MOVE_CLEAR_SMOG, MOVE_STOCKPILE},
		},
		{
			.species = SPECIES_CROBAT,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_CROSS_POISON, MOVE_BRAVE_BIRD, MOVE_U_TURN, MOVE_TAILWIND},
		},
		{
			.species = SPECIES_DRAPION,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_CROSS_POISON, MOVE_NIGHT_SLASH, MOVE_FIRE_FANG, MOVE_ACUPRESSURE},
		},
		{
			.species = SPECIES_AMOONGUSS,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_TOXIC, MOVE_SPORE, MOVE_GIGA_DRAIN, MOVE_SUBSTITUTE},
		},
        },

        {
            {
			.species = SPECIES_SCOLIPEDE,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_POISON_JAB, MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
		},
		{
			.species = SPECIES_TOXICROAK,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_POISON_JAB, MOVE_SWORDS_DANCE, MOVE_DRAIN_PUNCH, MOVE_PROTECT},
		},
		{
			.species = SPECIES_GARBODOR,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 255, 0, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_PROTECT},
		},
		{
			.species = SPECIES_CROBAT,
			.heldItem = ITEM_PSYCHIC_GEM,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_CROSS_POISON, MOVE_ZEN_HEADBUTT, MOVE_TAILWIND, MOVE_BRAVE_BIRD},
		},
		{
			.species = SPECIES_DRAPION,
			.heldItem = ITEM_SCOPE_LENS,
			.fixedIV = 25,
			.nature = NATURE_IMPISH,
			.evs = {0, 0, 0, 0, 255, 255},
			.moves = {MOVE_CROSS_POISON, MOVE_NIGHT_SLASH, MOVE_ICE_FANG, MOVE_PROTECT},
		},
		{
			.species = SPECIES_AMOONGUSS,
			.heldItem = ITEM_BLACK_SLUDGE,
			.fixedIV = 25,
			.nature = NATURE_BOLD,
			.evs = {255, 0, 255, 0, 0, 0},
			.moves = {MOVE_FOUL_PLAY, MOVE_SPORE, MOVE_GIGA_DRAIN, MOVE_PROTECT},
		},
        }
    },

    [TRAINER_FRONTIER_MARLON] =
    {
        {
        {
			.species = SPECIES_JELLICENT,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_SCALD, MOVE_HEX, MOVE_ACID_ARMOR, MOVE_RECOVER},
		},
		{
			.species = SPECIES_CARRACOSTA,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_SHELL_SMASH},
		},
		{
			.species = SPECIES_STARMIE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_COSMIC_POWER, MOVE_RECOVER},
		},
		{
			.species = SPECIES_ALOMOMOLA,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_SCALD, MOVE_MIRROR_COAT, MOVE_WISH, MOVE_CALM_MIND},
		},
		{
			.species = SPECIES_MANTINE,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_SIGNAL_BEAM, MOVE_AGILITY},
		},
		{
			.species = SPECIES_WAILORD,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 20,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 0, 0, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_AVALANCHE, MOVE_AMNESIA, MOVE_AQUA_RING},
		},
        },

        {
            {
			.species = SPECIES_JELLICENT,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_HYDRO_PUMP, MOVE_ENERGY_BALL, MOVE_SHADOW_BALL, MOVE_PSYCHIC},
		},
		{
			.species = SPECIES_CARRACOSTA,
			.heldItem = ITEM_LUM_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WATERFALL, MOVE_ROCK_SLIDE, MOVE_AQUA_JET, MOVE_SHELL_SMASH},
		},
		{
			.species = SPECIES_STARMIE,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SCALD, MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_THUNDERBOLT},
		},
		{
			.species = SPECIES_QUAGSIRE,
			.heldItem = ITEM_RINDO_BERRY,
			.fixedIV = 25,
			.nature = NATURE_RELAXED,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_COUNTER},
		},
		{
			.species = SPECIES_CLOYSTER,
			.heldItem = ITEM_KINGS_ROCK,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_ICE_SHARD, MOVE_ROCK_BLAST, MOVE_ICICLE_SPEAR, MOVE_SHELL_SMASH},
		},
		{
			.species = SPECIES_WAILORD,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WATER_SPOUT, MOVE_FISSURE, MOVE_BLIZZARD, MOVE_BOUNCE},
		},
        }
    },
};

static const struct FrontierBrainMon sFrontierChampionMons[][6] =
{
    [TRAINER_FRONTIER_RED] =
    {
        {
			.species = SPECIES_VENUSAUR,
			.heldItem = ITEM_WHITE_HERB,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {255, 0, 0, 0, 255, 0},
			.moves = {MOVE_LEAF_STORM, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_SLEEP_POWDER},
		},
		{
			.species = SPECIES_CHARIZARD,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_AIR_SLASH, MOVE_DRAGON_PULSE},
		},
		{
			.species = SPECIES_BLASTOISE,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_WATER_SPOUT, MOVE_HYDRO_PUMP, MOVE_BLIZZARD, MOVE_FOCUS_BLAST},
		},
		{
			.species = SPECIES_PIKACHU,
			.heldItem = ITEM_LIGHT_BALL,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_VOLT_TACKLE, MOVE_IRON_TAIL, MOVE_BRICK_BREAK, MOVE_FAKE_OUT},
		},
		{
			.species = SPECIES_SNORLAX,
			.heldItem = ITEM_QUICK_CLAW,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 0, 0, 255},
			.moves = {MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SEED_BOMB},
		},
		{
			.species = SPECIES_LAPRAS,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 255, 0, 0, 0, 255},
			.moves = {MOVE_ICE_BEAM, MOVE_HYDRO_PUMP, MOVE_ICE_SHARD, MOVE_THUNDERBOLT},
		},
    },

    [TRAINER_FRONTIER_BLUE] =
    {
        {
			.species = SPECIES_AERODACTYL,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_NAIVE,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_FIRE_BLAST},
		},
		{
			.species = SPECIES_EXEGGUTOR,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_NAUGHTY,
			.evs = {0, 255, 0, 0, 255, 0},
			.moves = {MOVE_LEAF_STORM, MOVE_WOOD_HAMMER, MOVE_ZEN_HEADBUTT, MOVE_LEECH_SEED},
		},
		{
			.species = SPECIES_GYARADOS,
			.heldItem = ITEM_KINGS_ROCK,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_OUTRAGE},
		},
		{
			.species = SPECIES_ALAKAZAM,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_REFLECT},
		},
		{
			.species = SPECIES_ARCANINE,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_FLARE_BLITZ, MOVE_CLOSE_COMBAT, MOVE_WILD_CHARGE, MOVE_EXTREME_SPEED},
		},
		{
			.species = SPECIES_MACHAMP,
			.heldItem = ITEM_WHITE_HERB,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_SUPERPOWER, MOVE_STONE_EDGE, MOVE_FIRE_PUNCH, MOVE_BULLET_PUNCH},
		},
    },

    [TRAINER_FRONTIER_LANCE] =
    {
        {
			.species = SPECIES_DRAGONITE,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_LONELY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_EXTREME_SPEED, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH, MOVE_DRACO_METEOR},
		},
		{
			.species = SPECIES_SALAMENCE,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DRAGON_CLAW, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_KINGDRA,
			.heldItem = ITEM_SCOPE_LENS,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_DRAGON_PULSE, MOVE_FLASH_CANNON},
		},
		{
			.species = SPECIES_HYDREIGON,
			.heldItem = ITEM_WHITE_HERB,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_DRACO_METEOR, MOVE_FIRE_BLAST, MOVE_EARTH_POWER, MOVE_DARK_PULSE},
		},
		{
			.species = SPECIES_HAXORUS,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 0, 0, 0},
			.moves = {MOVE_OUTRAGE, MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
		},
		{
			.species = SPECIES_FLYGON,
			.heldItem = ITEM_POWER_HERB,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_SOLAR_BEAM, MOVE_DRACO_METEOR, MOVE_EARTH_POWER, MOVE_U_TURN},
		},
    },

    [TRAINER_FRONTIER_STEVEN] =
    {
        {
			.species = SPECIES_METAGROSS,
			.heldItem = ITEM_OCCA_BERRY,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_HAMMER_ARM, MOVE_BULLET_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_AGGRON,
			.heldItem = ITEM_AIR_BALLOON,
			.fixedIV = 25,
			.nature = NATURE_BRAVE,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_HEAD_SMASH, MOVE_METAL_BURST, MOVE_EARTHQUAKE, MOVE_AVALANCHE},
		},
		{
			.species = SPECIES_EXCADRILL,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_X_SCISSOR, MOVE_SANDSTORM},
		},
		{
			.species = SPECIES_ARCHEOPS,
			.heldItem = ITEM_SITRUS_BERRY,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_QUICK_ATTACK, MOVE_ACROBATICS, MOVE_HEAD_SMASH, MOVE_EARTHQUAKE},
		},
		{
			.species = SPECIES_CRADILY,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_STONE_EDGE, MOVE_SEED_BOMB, MOVE_EARTHQUAKE, MOVE_SANDSTORM},
		},
		{
			.species = SPECIES_ARMALDO,
			.heldItem = ITEM_WHITE_HERB,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_X_SCISSOR, MOVE_ROCK_BLAST, MOVE_EARTHQUAKE, MOVE_SUPERPOWER},
		},
    },

    [TRAINER_FRONTIER_CYNTHIA] =
    {
        {
			.species = SPECIES_GARCHOMP,
			.heldItem = ITEM_FOCUS_SASH,
			.fixedIV = 25,
			.nature = NATURE_JOLLY,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE},
		},
		{
			.species = SPECIES_SPIRITOMB,
			.heldItem = ITEM_ROCKY_HELMET,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_PAIN_SPLIT, MOVE_WILL_O_WISP, MOVE_PROTECT, MOVE_SUCKER_PUNCH},
		},
		{
			.species = SPECIES_TOGEKISS,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_AIR_SLASH, MOVE_AURA_SPHERE, MOVE_GRASS_KNOT, MOVE_SHADOW_BALL},
		},
		{
			.species = SPECIES_LUCARIO,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_NAIVE,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_CLOSE_COMBAT, MOVE_STONE_EDGE, MOVE_EXTREME_SPEED, MOVE_DARK_PULSE},
		},
		{
			.species = SPECIES_ROSERADE,
			.heldItem = ITEM_WHITE_HERB,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_LEAF_STORM, MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB, MOVE_SLEEP_POWDER},
		},
		{
			.species = SPECIES_GLACEON,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_TIMID,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_ICE_BEAM, MOVE_SIGNAL_BEAM, MOVE_SHADOW_BALL, MOVE_WATER_PULSE},
		},
    },

    [TRAINER_FRONTIER_ALDER] =
    {
        {
			.species = SPECIES_VOLCARONA,
			.heldItem = ITEM_CHARTI_BERRY,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_QUIVER_DANCE, MOVE_HEAT_WAVE, MOVE_BUG_BUZZ, MOVE_PSYCHIC},
		},
		{
			.species = SPECIES_CONKELDURR,
			.heldItem = ITEM_LIFE_ORB,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {255, 255, 0, 0, 0, 0},
			.moves = {MOVE_HAMMER_ARM, MOVE_MACH_PUNCH, MOVE_PAYBACK, MOVE_STONE_EDGE},
		},
		{
			.species = SPECIES_REUNICLUS,
			.heldItem = ITEM_LEFTOVERS,
			.fixedIV = 25,
			.nature = NATURE_CALM,
			.evs = {255, 0, 0, 0, 0, 255},
			.moves = {MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_TOXIC, MOVE_PSYCHIC},
		},
		{
			.species = SPECIES_KROOKODILE,
			.heldItem = ITEM_EXPERT_BELT,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_STONE_EDGE, MOVE_OUTRAGE},
		},
		{
			.species = SPECIES_CHANDELURE,
			.heldItem = ITEM_CHOICE_SCARF,
			.fixedIV = 25,
			.nature = NATURE_MODEST,
			.evs = {0, 0, 0, 255, 255, 0},
			.moves = {MOVE_FLAMETHROWER, MOVE_SHADOW_BALL, MOVE_ENERGY_BALL, MOVE_PSYCHIC},
		},
		{
			.species = SPECIES_BRAVIARY,
			.heldItem = ITEM_CHOICE_BAND,
			.fixedIV = 25,
			.nature = NATURE_ADAMANT,
			.evs = {0, 255, 0, 255, 0, 0},
			.moves = {MOVE_BRAVE_BIRD, MOVE_SUPERPOWER, MOVE_ROCK_SLIDE, MOVE_U_TURN},
		},
    },

    [TRAINER_FRONTIER_IRIS] =
    {
        {
            .species = SPECIES_HAXORUS,
            .heldItem = ITEM_FOCUS_SASH,
            .fixedIV = 25,
            .nature = NATURE_MODEST,
            .evs = {0, 252, 0, 252, 0, 0},
            .moves = {MOVE_EARTHQUAKE, MOVE_GUILLOTINE, MOVE_OUTRAGE, MOVE_DRAGON_DANCE},
        },
        {
            .species = SPECIES_HYDREIGON,
            .heldItem = ITEM_WISE_GLASSES,
            .fixedIV = 25,
            .nature = NATURE_LONELY,
            .evs = {0, 0, 0, 252, 252, 0},
            .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_DRAGON_PULSE, MOVE_SURF},
        },
        {
            .species = SPECIES_SALAMENCE,
            .heldItem = ITEM_LIFE_ORB,
            .fixedIV = 25,
            .nature = NATURE_ADAMANT,
            .evs = {0, 252, 0, 252, 0, 0},
            .moves = {MOVE_FIRE_BLAST, MOVE_EARTHQUAKE, MOVE_DRACO_METEOR, MOVE_CRUNCH},
        },
        {
            .species = SPECIES_ARCHEOPS,
            .heldItem = ITEM_FLYING_GEM,
            .fixedIV = 25,
            .nature = NATURE_MODEST,
            .evs = {0, 252, 0, 252, 0, 0},
            .moves = {MOVE_ACROBATICS, MOVE_DRAGON_CLAW, MOVE_STONE_EDGE, MOVE_ENDEAVOR},
        },
        {
            .species = SPECIES_AGGRON,
            .heldItem = ITEM_MUSCLE_BAND,
            .fixedIV = 25,
            .nature = NATURE_LONELY,
            .evs = {0, 252, 0, 252, 0, 0},
            .moves = {MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_HEAD_SMASH, MOVE_AUTOTOMIZE},
        },
        {
            .species = SPECIES_LAPRAS,
            .heldItem = ITEM_ZOOM_LENS,
            .fixedIV = 25,
            .nature = NATURE_ADAMANT,
            .evs = {252, 0, 0, 0, 0, 252},
            .moves = {MOVE_HYDRO_PUMP, MOVE_BLIZZARD, MOVE_THUNDER, MOVE_SING},
        },
    },    
};

static const u8 sBattlePointAwards[NUM_FRONTIER_FACILITIES][FRONTIER_MODE_COUNT][30] =
{
    /* facility, mode, tier */
    [FRONTIER_FACILITY_TOWER] = /* Tier: 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 */
    {
        [FRONTIER_MODE_SINGLES]     = {  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
        [FRONTIER_MODE_DOUBLES]     = {  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
        [FRONTIER_MODE_MULTIS]      = {  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
        [FRONTIER_MODE_LINK_MULTIS] = {  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
    },
    [FRONTIER_FACILITY_DOME] =
    {
        [FRONTIER_MODE_SINGLES]     = {  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15 },
        [FRONTIER_MODE_DOUBLES]     = {  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15 },
    },
    [FRONTIER_FACILITY_PALACE] =
    {
        [FRONTIER_MODE_SINGLES]     = {  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15 },
        [FRONTIER_MODE_DOUBLES]     = {  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
    },
    [FRONTIER_FACILITY_ARENA] =
    {
        [FRONTIER_MODE_SINGLES]     = {  1,  1,  1,  2,  2,  2,  3,  3,  4,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
    },
    [FRONTIER_FACILITY_FACTORY] =
    {
        [FRONTIER_MODE_SINGLES]     = {  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 15, 15 },
        [FRONTIER_MODE_DOUBLES]     = {  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15 },
    },
    [FRONTIER_FACILITY_PIKE] =
    {
        [FRONTIER_MODE_SINGLES]     = {  1,  1,  2,  2,  2,  4,  4,  4,  8,  8,  8,  8, 10, 10, 10, 10, 12, 12, 12, 12, 12, 14, 14, 14, 14, 15, 15, 15, 15, 15 },
    },
    [FRONTIER_FACILITY_PYRAMID] =
    {
        [FRONTIER_MODE_SINGLES]     = {  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
    },
};


// Flags to change the conversation when the Frontier Brain is encountered for a battle
// First bit is has battled them before and not won yet, second bit is has battled them and won (obtained a Symbol)
static const u16 sBattledBrainBitFlags[NUM_FRONTIER_FACILITIES][2] =
{
    [FRONTIER_FACILITY_TOWER]   = {1 << 0, 1 << 1},
    [FRONTIER_FACILITY_DOME]    = {1 << 2, 1 << 3},
    [FRONTIER_FACILITY_PALACE]  = {1 << 4, 1 << 5},
    [FRONTIER_FACILITY_ARENA]   = {1 << 6, 1 << 7},
    [FRONTIER_FACILITY_FACTORY] = {1 << 8, 1 << 9},
    [FRONTIER_FACILITY_PIKE]    = {1 << 10, 1 << 11},
    [FRONTIER_FACILITY_PYRAMID] = {1 << 12, 1 << 13},
};

static void (* const sFrontierUtilFuncs[])(void) =
{
    [FRONTIER_UTIL_FUNC_GET_STATUS]            = GetChallengeStatus,
    [FRONTIER_UTIL_FUNC_GET_DATA]              = GetFrontierData,
    [FRONTIER_UTIL_FUNC_SET_DATA]              = SetFrontierData,
    [FRONTIER_UTIL_FUNC_SET_PARTY_ORDER]       = SetSelectedPartyOrder,
    [FRONTIER_UTIL_FUNC_SOFT_RESET]            = DoSoftReset_,
    [FRONTIER_UTIL_FUNC_SET_TRAINERS]          = SetFrontierTrainers,
    [FRONTIER_UTIL_FUNC_SAVE_PARTY]            = SaveSelectedParty,
    [FRONTIER_UTIL_FUNC_RESULTS_WINDOW]        = ShowFacilityResultsWindow,
    [FRONTIER_UTIL_FUNC_CHECK_AIR_TV_SHOW]     = CheckPutFrontierTVShowOnAir,
    [FRONTIER_UTIL_FUNC_GET_BRAIN_STATUS]      = Script_GetFrontierBrainStatus,
    [FRONTIER_UTIL_FUNC_IS_BRAIN]              = IsTrainerFrontierBrain,
    [FRONTIER_UTIL_FUNC_GIVE_BATTLE_POINTS]    = GiveBattlePoints,
    [FRONTIER_UTIL_FUNC_GET_FACILITY_SYMBOLS]  = GetFacilitySymbolCount,
    [FRONTIER_UTIL_FUNC_GIVE_FACILITY_SYMBOL]  = GiveFacilitySymbol,
    [FRONTIER_UTIL_FUNC_CHECK_BATTLE_TYPE]     = CheckBattleTypeFlag,
    [FRONTIER_UTIL_FUNC_CHECK_INELIGIBLE]      = CheckPartyIneligibility,
    [FRONTIER_UTIL_FUNC_CHECK_VISIT_TRAINER]   = ValidateVisitingTrainer,
    [FRONTIER_UTIL_FUNC_INCREMENT_STREAK]      = IncrementWinStreak,
    [FRONTIER_UTIL_FUNC_RESTORE_HELD_ITEMS]    = RestoreHeldItems,
    [FRONTIER_UTIL_FUNC_SAVE_BATTLE]           = SaveRecordBattle,
    [FRONTIER_UTIL_FUNC_BUFFER_TRAINER_NAME]   = BufferFrontierTrainerName,
    [FRONTIER_UTIL_FUNC_RESET_SKETCH_MOVES]    = ResetSketchedMoves,
    [FRONTIER_UTIL_FUNC_SET_BRAIN_OBJECT]      = SetFacilityBrainObjectEvent,
};

static const struct WindowTemplate sFrontierResultsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 18,
    .paletteNum = 15,
    .baseBlock = 1
};

static const struct WindowTemplate sLinkContestResultsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 2,
    .width = 26,
    .height = 15,
    .paletteNum = 15,
    .baseBlock = 1
};

static const struct WindowTemplate sRankingHallRecordsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 1,
    .width = 26,
    .height = 17,
    .paletteNum = 15,
    .baseBlock = 1
};

// Second field - whether the character is female.
static const u16 sFrontierBrainObjEventGfx[NUM_FRONTIER_FACILITIES][2] =
{
    [FRONTIER_FACILITY_TOWER]   = {OBJ_EVENT_GFX_ANABEL,  TRUE},
    [FRONTIER_FACILITY_DOME]    = {OBJ_EVENT_GFX_TUCKER,  FALSE},
    [FRONTIER_FACILITY_PALACE]  = {OBJ_EVENT_GFX_SPENSER, FALSE},
    [FRONTIER_FACILITY_ARENA]   = {OBJ_EVENT_GFX_GRETA,   TRUE},
    [FRONTIER_FACILITY_FACTORY] = {OBJ_EVENT_GFX_NOLAND,  FALSE},
    [FRONTIER_FACILITY_PIKE]    = {OBJ_EVENT_GFX_LUCY,    TRUE},
    [FRONTIER_FACILITY_PYRAMID] = {OBJ_EVENT_GFX_BRANDON, FALSE},
};

static const u16 sFrontierLeaderObjEventGfx[] =
{
    [TRAINER_FRONTIER_BROCK]   = OBJ_EVENT_GFX_BROCK,
    [TRAINER_FRONTIER_MISTY]    = OBJ_EVENT_GFX_MISTY,
    [TRAINER_FRONTIER_SURGE]  = OBJ_EVENT_GFX_SURGE,
    [TRAINER_FRONTIER_ERIKA]   = OBJ_EVENT_GFX_ERIKA,
    [TRAINER_FRONTIER_JANINE] = OBJ_EVENT_GFX_JANINE,
    [TRAINER_FRONTIER_SABRINA]    = OBJ_EVENT_GFX_SABRINA,
    [TRAINER_FRONTIER_BLAINE] = OBJ_EVENT_GFX_BLAINE,
    [TRAINER_FRONTIER_GIOVANNI] = OBJ_EVENT_GFX_GIOVANNI,

    [TRAINER_FRONTIER_FALKNER]   = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_BUGSY]    = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_WHITNEY]  = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_MORTY]   = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_CHUCK] = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_JASMINE]    = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_PRYCE] = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_CLAIR] = OBJ_EVENT_GFX_TUCKER,

    [TRAINER_FRONTIER_ROXANNE]   = OBJ_EVENT_GFX_ROXANNE,
    [TRAINER_FRONTIER_BRAWLY]    = OBJ_EVENT_GFX_BRAWLY,
    [TRAINER_FRONTIER_WATTSON]  = OBJ_EVENT_GFX_WATTSON,
    [TRAINER_FRONTIER_FLANNERY]   = OBJ_EVENT_GFX_FLANNERY,
    [TRAINER_FRONTIER_NORMAN] = OBJ_EVENT_GFX_NORMAN,
    [TRAINER_FRONTIER_WINONA]    = OBJ_EVENT_GFX_WINONA,
    [TRAINER_FRONTIER_TATE] = OBJ_EVENT_GFX_TATE,
    [TRAINER_FRONTIER_LIZA] = OBJ_EVENT_GFX_LIZA,
    [TRAINER_FRONTIER_WALLACE] = OBJ_EVENT_GFX_WALLACE,

	[TRAINER_FRONTIER_ROARK]   = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_GARDENIA]    = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_MAYLENE]  = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_WAKE]   = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_FANTINA] = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_BYRON]    = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_CANDICE] = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_VOLKNER] = OBJ_EVENT_GFX_TUCKER,

	[TRAINER_FRONTIER_CILAN]   = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_CHILI]    = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_CRESS]  = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_LENORA]   = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_BURGH] = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_ELESA]    = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_CLAY] = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_SKYLA] = OBJ_EVENT_GFX_TUCKER,
	[TRAINER_FRONTIER_BRYCEN]   = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_DRAYDEN]    = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_CHEREN]  = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_ROXIE]   = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_MARLON] = OBJ_EVENT_GFX_TUCKER,

    [TRAINER_FRONTIER_RED]    = OBJ_EVENT_GFX_RED,
    [TRAINER_FRONTIER_BLUE] = OBJ_EVENT_GFX_BLUE,
    [TRAINER_FRONTIER_LANCE] = OBJ_EVENT_GFX_TUCKER,
	[TRAINER_FRONTIER_STEVEN]    = OBJ_EVENT_GFX_STEVEN,
    [TRAINER_FRONTIER_CYNTHIA] = OBJ_EVENT_GFX_TUCKER,
    [TRAINER_FRONTIER_ALDER] = OBJ_EVENT_GFX_TUCKER,
	[TRAINER_FRONTIER_IRIS]    = OBJ_EVENT_GFX_TUCKER,
};

const u16 gFrontierBannedSpecies[] =
{
    SPECIES_MEW, SPECIES_MEWTWO,
    SPECIES_HO_OH, SPECIES_LUGIA, SPECIES_CELEBI,
    SPECIES_KYOGRE, SPECIES_GROUDON, SPECIES_RAYQUAZA, SPECIES_JIRACHI, SPECIES_DEOXYS,
    SPECIES_DIALGA, SPECIES_PALKIA, SPECIES_GIRATINA, SPECIES_MANAPHY, SPECIES_PHIONE, SPECIES_DARKRAI, SPECIES_SHAYMIN, SPECIES_ARCEUS,
    SPECIES_VICTINI, SPECIES_RESHIRAM, SPECIES_ZEKROM, SPECIES_KYUREM, SPECIES_KELDEO, SPECIES_MELOETTA, SPECIES_GENESECT,
    SPECIES_XERNEAS, SPECIES_YVELTAL, SPECIES_ZYGARDE, SPECIES_DIANCIE, SPECIES_HOOPA, SPECIES_VOLCANION,
    SPECIES_COSMOG, SPECIES_COSMOEM, SPECIES_SOLGALEO, SPECIES_LUNALA, SPECIES_NECROZMA, SPECIES_MAGEARNA, SPECIES_MARSHADOW, SPECIES_ZERAORA, SPECIES_MELTAN, SPECIES_MELMETAL,
    SPECIES_ZACIAN, SPECIES_ZAMAZENTA, SPECIES_ETERNATUS, SPECIES_CALYREX, SPECIES_ZARUDE,
    SPECIES_KORAIDON, SPECIES_MIRAIDON,
    0xFFFF
};

static const u8 *const sRecordsWindowChallengeTexts[][2] =
{
    [RANKING_HALL_TOWER_SINGLES] = {gText_BattleTower2,  gText_FacilitySingle},
    [RANKING_HALL_TOWER_DOUBLES] = {gText_BattleTower2,  gText_FacilityDouble},
    [RANKING_HALL_TOWER_MULTIS]  = {gText_BattleTower2,  gText_FacilityMulti},
    [RANKING_HALL_DOME]          = {gText_BattleDome,    gText_FacilitySingle},
    [RANKING_HALL_PALACE]        = {gText_BattlePalace,  gText_FacilitySingle},
    [RANKING_HALL_ARENA]         = {gText_BattleArena,   gText_Facility},
    [RANKING_HALL_FACTORY]       = {gText_BattleFactory, gText_FacilitySingle},
    [RANKING_HALL_PIKE]          = {gText_BattlePike,    gText_Facility},
    [RANKING_HALL_PYRAMID]       = {gText_BattlePyramid, gText_Facility},
    [RANKING_HALL_TOWER_LINK]    = {gText_BattleTower2,  gText_FacilityLink},
};

static const u8 *const sLevelModeText[] =
{
    [FRONTIER_LVL_50]   = gText_RecordsLv50,
    [FRONTIER_LVL_OPEN] = gText_RecordsOpenLevel,
};

static const u8 *const sHallFacilityToRecordsText[] =
{
    [RANKING_HALL_TOWER_SINGLES] = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_TOWER_DOUBLES] = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_TOWER_MULTIS]  = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_DOME]          = gText_FrontierFacilityClearStreak,
    [RANKING_HALL_PALACE]        = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_ARENA]         = gText_FrontierFacilityKOsStreak,
    [RANKING_HALL_FACTORY]       = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_PIKE]          = gText_FrontierFacilityRoomsCleared,
    [RANKING_HALL_PYRAMID]       = gText_FrontierFacilityFloorsCleared,
    [RANKING_HALL_TOWER_LINK]    = gText_FrontierFacilityWinStreak,
};

static const u16 sFrontierBrainTrainerIds[NUM_FRONTIER_FACILITIES] =
{
    [FRONTIER_FACILITY_TOWER]   = TRAINER_ANABEL,
    [FRONTIER_FACILITY_DOME]    = TRAINER_TUCKER,
    [FRONTIER_FACILITY_PALACE]  = TRAINER_SPENSER,
    [FRONTIER_FACILITY_ARENA]   = TRAINER_GRETA,
    [FRONTIER_FACILITY_FACTORY] = TRAINER_NOLAND,
    [FRONTIER_FACILITY_PIKE]    = TRAINER_LUCY,
    [FRONTIER_FACILITY_PYRAMID] = TRAINER_BRANDON,
};

static const u8 *const sFrontierBrainPlayerLostSilverTexts[NUM_FRONTIER_FACILITIES] =
{
    [FRONTIER_FACILITY_TOWER]   = gText_AnabelWonSilver,
    [FRONTIER_FACILITY_DOME]    = gText_TuckerWonSilver,
    [FRONTIER_FACILITY_PALACE]  = gText_SpenserWonSilver,
    [FRONTIER_FACILITY_ARENA]   = gText_GretaWonSilver,
    [FRONTIER_FACILITY_FACTORY] = gText_NolandWonSilver,
    [FRONTIER_FACILITY_PIKE]    = gText_LucyWonSilver,
    [FRONTIER_FACILITY_PYRAMID] = gText_BrandonWonSilver,
};

static const u8 *const sFrontierBrainPlayerWonSilverTexts[NUM_FRONTIER_FACILITIES] =
{
    [FRONTIER_FACILITY_TOWER]   = gText_AnabelDefeatSilver,
    [FRONTIER_FACILITY_DOME]    = gText_TuckerDefeatSilver,
    [FRONTIER_FACILITY_PALACE]  = gText_SpenserDefeatSilver,
    [FRONTIER_FACILITY_ARENA]   = gText_GretaDefeatSilver,
    [FRONTIER_FACILITY_FACTORY] = gText_NolandDefeatSilver,
    [FRONTIER_FACILITY_PIKE]    = gText_LucyDefeatSilver,
    [FRONTIER_FACILITY_PYRAMID] = gText_BrandonDefeatSilver,
};

static const u8 *const sFrontierBrainPlayerLostGoldTexts[NUM_FRONTIER_FACILITIES] =
{
    [FRONTIER_FACILITY_TOWER]   = gText_AnabelWonGold,
    [FRONTIER_FACILITY_DOME]    = gText_TuckerWonGold,
    [FRONTIER_FACILITY_PALACE]  = gText_SpenserWonGold,
    [FRONTIER_FACILITY_ARENA]   = gText_GretaWonGold,
    [FRONTIER_FACILITY_FACTORY] = gText_NolandWonGold,
    [FRONTIER_FACILITY_PIKE]    = gText_LucyWonGold,
    [FRONTIER_FACILITY_PYRAMID] = gText_BrandonWonGold,
};

static const u8 *const sFrontierBrainPlayerWonGoldTexts[NUM_FRONTIER_FACILITIES] =
{
    [FRONTIER_FACILITY_TOWER]   = gText_AnabelDefeatGold,
    [FRONTIER_FACILITY_DOME]    = gText_TuckerDefeatGold,
    [FRONTIER_FACILITY_PALACE]  = gText_SpenserDefeatGold,
    [FRONTIER_FACILITY_ARENA]   = gText_GretaDefeatGold,
    [FRONTIER_FACILITY_FACTORY] = gText_NolandDefeatGold,
    [FRONTIER_FACILITY_PIKE]    = gText_LucyDefeatGold,
    [FRONTIER_FACILITY_PYRAMID] = gText_BrandonDefeatGold,
};

static const u8 *const sFrontierLeaderLoseTexts[] =
{
    [TRAINER_FRONTIER_BROCK]   = gText_BrockDefeat,
    [TRAINER_FRONTIER_MISTY]    = gText_MistyDefeat,
    [TRAINER_FRONTIER_SURGE]  = gText_SurgeDefeat,
    [TRAINER_FRONTIER_ERIKA]   = gText_ErikaDefeat,
    [TRAINER_FRONTIER_JANINE] = gText_JanineDefeat,
    [TRAINER_FRONTIER_SABRINA]    = gText_SabrinaDefeat,
    [TRAINER_FRONTIER_BLAINE] = gText_BlaineDefeat,
    [TRAINER_FRONTIER_GIOVANNI] = gText_GiovanniDefeat,

    [TRAINER_FRONTIER_FALKNER]   = gText_FalknerDefeat,
    [TRAINER_FRONTIER_BUGSY]    = gText_BugsyDefeat,
    [TRAINER_FRONTIER_WHITNEY]  = gText_WhitneyDefeat,
    [TRAINER_FRONTIER_MORTY]   = gText_MortyDefeat,
    [TRAINER_FRONTIER_CHUCK] = gText_ChuckDefeat,
    [TRAINER_FRONTIER_JASMINE]    = gText_JasmineDefeat,
    [TRAINER_FRONTIER_PRYCE] = gText_PryceDefeat,
    [TRAINER_FRONTIER_CLAIR] = gText_ClairDefeat,

    [TRAINER_FRONTIER_ROXANNE]   = gText_RoxanneDefeat,
    [TRAINER_FRONTIER_BRAWLY]    = gText_BrawlyDefeat,
    [TRAINER_FRONTIER_WATTSON]  = gText_WattsonDefeat,
    [TRAINER_FRONTIER_FLANNERY]   = gText_FlanneryDefeat,
    [TRAINER_FRONTIER_NORMAN] = gText_NormanDefeat,
    [TRAINER_FRONTIER_WINONA]    = gText_WinonaDefeat,
    [TRAINER_FRONTIER_TATE] = gText_TateDefeat,
    [TRAINER_FRONTIER_LIZA] = gText_LizaDefeat,
    [TRAINER_FRONTIER_WALLACE] = gText_WallaceDefeat,

    [TRAINER_FRONTIER_ROARK]   = gText_RoarkDefeat,
    [TRAINER_FRONTIER_GARDENIA]    = gText_GardeniaDefeat,
    [TRAINER_FRONTIER_MAYLENE]  = gText_MayleneDefeat,
    [TRAINER_FRONTIER_WAKE]   = gText_WakeDefeat,
    [TRAINER_FRONTIER_FANTINA] = gText_FantinaDefeat,
    [TRAINER_FRONTIER_BYRON]    = gText_ByronDefeat,
    [TRAINER_FRONTIER_CANDICE] = gText_CandiceDefeat,
    [TRAINER_FRONTIER_VOLKNER] = gText_VolknerDefeat,

    [TRAINER_FRONTIER_CILAN]   = gText_CilanDefeat,
    [TRAINER_FRONTIER_CHILI]    = gText_ChiliDefeat,
    [TRAINER_FRONTIER_CRESS]  = gText_CressDefeat,
    [TRAINER_FRONTIER_LENORA]   = gText_LenoraDefeat,
    [TRAINER_FRONTIER_BURGH] = gText_BurghDefeat,
    [TRAINER_FRONTIER_ELESA]    = gText_ElesaDefeat,
    [TRAINER_FRONTIER_CLAY] = gText_ClayDefeat,
    [TRAINER_FRONTIER_SKYLA] = gText_SkylaDefeat,
    [TRAINER_FRONTIER_BRYCEN]   = gText_BrycenDefeat,
    [TRAINER_FRONTIER_DRAYDEN] = gText_DraydenDefeat,
    [TRAINER_FRONTIER_CHEREN]    = gText_CherenDefeat,
    [TRAINER_FRONTIER_ROXIE] = gText_RoxieDefeat,
    [TRAINER_FRONTIER_MARLON] = gText_MarlonDefeat,

    [TRAINER_FRONTIER_RED]    = gText_RedDefeat,
    [TRAINER_FRONTIER_BLUE]  = gText_BlueDefeat,
    [TRAINER_FRONTIER_LANCE]   = gText_LanceDefeat,
    [TRAINER_FRONTIER_STEVEN] = gText_StevenDefeat,
    [TRAINER_FRONTIER_CYNTHIA]    = gText_CynthiaDefeat,
    [TRAINER_FRONTIER_ALDER] = gText_AlderDefeat,
    [TRAINER_FRONTIER_IRIS] = gText_IrisDefeat,
};

static const u8 *const sFrontierLeaderWonTexts[] =
{
    [TRAINER_FRONTIER_BROCK]   = gText_BrockWon,
    [TRAINER_FRONTIER_MISTY]    = gText_MistyWon,
    [TRAINER_FRONTIER_SURGE]  = gText_SurgeWon,
    [TRAINER_FRONTIER_ERIKA]   = gText_ErikaWon,
    [TRAINER_FRONTIER_JANINE] = gText_JanineWon,
    [TRAINER_FRONTIER_SABRINA]    = gText_SabrinaWon,
    [TRAINER_FRONTIER_BLAINE] = gText_BlaineWon,
    [TRAINER_FRONTIER_GIOVANNI] = gText_GiovanniWon,

    [TRAINER_FRONTIER_FALKNER]   = gText_FalknerWon,
    [TRAINER_FRONTIER_BUGSY]    = gText_BugsyWon,
    [TRAINER_FRONTIER_WHITNEY]  = gText_WhitneyWon,
    [TRAINER_FRONTIER_MORTY]   = gText_MortyWon,
    [TRAINER_FRONTIER_CHUCK] = gText_ChuckWon,
    [TRAINER_FRONTIER_JASMINE]    = gText_JasmineWon,
    [TRAINER_FRONTIER_PRYCE] = gText_PryceWon,
    [TRAINER_FRONTIER_CLAIR] = gText_ClairWon,

    [TRAINER_FRONTIER_ROXANNE]   = gText_RoxanneWon,
    [TRAINER_FRONTIER_BRAWLY]    = gText_BrawlyWon,
    [TRAINER_FRONTIER_WATTSON]  = gText_WattsonWon,
    [TRAINER_FRONTIER_FLANNERY]   = gText_FlanneryWon,
    [TRAINER_FRONTIER_NORMAN] = gText_NormanWon,
    [TRAINER_FRONTIER_WINONA]    = gText_WinonaWon,
    [TRAINER_FRONTIER_TATE] = gText_TateWon,
    [TRAINER_FRONTIER_LIZA] = gText_LizaWon,
    [TRAINER_FRONTIER_WALLACE] = gText_WallaceWon,

    [TRAINER_FRONTIER_ROARK]   = gText_RoarkWon,
    [TRAINER_FRONTIER_GARDENIA]    = gText_GardeniaWon,
    [TRAINER_FRONTIER_MAYLENE]  = gText_MayleneWon,
    [TRAINER_FRONTIER_WAKE]   = gText_WakeWon,
    [TRAINER_FRONTIER_FANTINA] = gText_FantinaWon,
    [TRAINER_FRONTIER_BYRON]    = gText_ByronWon,
    [TRAINER_FRONTIER_CANDICE] = gText_CandiceWon,
    [TRAINER_FRONTIER_VOLKNER] = gText_VolknerWon,

    [TRAINER_FRONTIER_CILAN]   = gText_CilanWon,
    [TRAINER_FRONTIER_CHILI]    = gText_ChiliWon,
    [TRAINER_FRONTIER_CRESS]  = gText_CressWon,
    [TRAINER_FRONTIER_LENORA]   = gText_LenoraWon,
    [TRAINER_FRONTIER_BURGH] = gText_BurghWon,
    [TRAINER_FRONTIER_ELESA]    = gText_ElesaWon,
    [TRAINER_FRONTIER_CLAY] = gText_ClayWon,
    [TRAINER_FRONTIER_SKYLA] = gText_SkylaWon,
    [TRAINER_FRONTIER_BRYCEN]   = gText_BrycenWon,
    [TRAINER_FRONTIER_DRAYDEN] = gText_DraydenWon,
    [TRAINER_FRONTIER_CHEREN]    = gText_CherenWon,
    [TRAINER_FRONTIER_ROXIE] = gText_RoxieWon,
    [TRAINER_FRONTIER_MARLON] = gText_MarlonWon,

    [TRAINER_FRONTIER_RED]    = gText_RedWon,
    [TRAINER_FRONTIER_BLUE]  = gText_BlueWon,
    [TRAINER_FRONTIER_LANCE]   = gText_LanceWon,
    [TRAINER_FRONTIER_STEVEN] = gText_StevenWon,
    [TRAINER_FRONTIER_CYNTHIA]    = gText_CynthiaWon,
    [TRAINER_FRONTIER_ALDER] = gText_AlderWon,
    [TRAINER_FRONTIER_IRIS] = gText_IrisWon,
};

static const u8 *const *const sFrontierBrainPlayerLostTexts[] =
{
    sFrontierBrainPlayerLostSilverTexts,
    sFrontierBrainPlayerLostGoldTexts,
};

static const u8 *const *const sFrontierBrainPlayerWonTexts[] =
{
    sFrontierBrainPlayerWonSilverTexts,
    sFrontierBrainPlayerWonGoldTexts,
};

// code
void CallFrontierUtilFunc(void)
{
    sFrontierUtilFuncs[gSpecialVar_0x8004]();
}

// VAR_TEMP_CHALLENGE_STATUS is used to react to the status in OnFrame map scripts
static void GetChallengeStatus(void)
{
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0xFF);
    switch (gSaveBlock1Ptr->frontier.challengeStatus)
    {
    case 0:
        break;
    case CHALLENGE_STATUS_SAVING:
        FrontierGamblerSetWonOrLost(FALSE);
        VarSet(VAR_TEMP_CHALLENGE_STATUS, gSaveBlock1Ptr->frontier.challengeStatus);
        break;
    case CHALLENGE_STATUS_LOST:
        FrontierGamblerSetWonOrLost(FALSE);
        VarSet(VAR_TEMP_CHALLENGE_STATUS, gSaveBlock1Ptr->frontier.challengeStatus);
        break;
    case CHALLENGE_STATUS_WON:
        FrontierGamblerSetWonOrLost(TRUE);
        VarSet(VAR_TEMP_CHALLENGE_STATUS, gSaveBlock1Ptr->frontier.challengeStatus);
        break;
    case CHALLENGE_STATUS_PAUSED:
        VarSet(VAR_TEMP_CHALLENGE_STATUS, gSaveBlock1Ptr->frontier.challengeStatus);
        break;
    }
}

static void GetFrontierData(void)
{
    u8 facility = VarGet(VAR_FRONTIER_FACILITY);
    u8 hasSymbol = GetPlayerSymbolCountForFacility(facility);
    if (hasSymbol == 2)
        hasSymbol = 1;

    switch (gSpecialVar_0x8005)
    {
    case FRONTIER_DATA_CHALLENGE_STATUS:
        gSpecialVar_Result = gSaveBlock1Ptr->frontier.challengeStatus;
        break;
    case FRONTIER_DATA_LVL_MODE:
        gSpecialVar_Result = gSaveBlock1Ptr->frontier.lvlMode;
        break;
    case FRONTIER_DATA_BATTLE_NUM:
        gSpecialVar_Result = gSaveBlock1Ptr->frontier.curChallengeBattleNum;
        break;
    case FRONTIER_DATA_PAUSED:
        gSpecialVar_Result = gSaveBlock1Ptr->frontier.challengePaused;
        break;
    case FRONTIER_DATA_BATTLE_OUTCOME:
        gSpecialVar_Result = gBattleOutcome;
        gBattleOutcome = 0;
        break;
    case FRONTIER_DATA_RECORD_DISABLED:
        gSpecialVar_Result = gSaveBlock1Ptr->frontier.disableRecordBattle;
        break;
    case FRONTIER_DATA_HEARD_BRAIN_SPEECH:
        gSpecialVar_Result = gSaveBlock1Ptr->frontier.battledBrainFlags & sBattledBrainBitFlags[facility][hasSymbol];
        break;
    }
}

static void SetFrontierData(void)
{
    s32 i;
    u8 facility = VarGet(VAR_FRONTIER_FACILITY);
    u8 hasSymbol = GetPlayerSymbolCountForFacility(facility);
    if (hasSymbol == 2)
        hasSymbol = 1;

    switch (gSpecialVar_0x8005)
    {
    case FRONTIER_DATA_CHALLENGE_STATUS:
        gSaveBlock1Ptr->frontier.challengeStatus = gSpecialVar_0x8006;
        break;
    case FRONTIER_DATA_LVL_MODE:
        gSaveBlock1Ptr->frontier.lvlMode = gSpecialVar_0x8006;
        break;
    case FRONTIER_DATA_BATTLE_NUM:
        gSaveBlock1Ptr->frontier.curChallengeBattleNum = gSpecialVar_0x8006;
        break;
    case FRONTIER_DATA_PAUSED:
        gSaveBlock1Ptr->frontier.challengePaused = gSpecialVar_0x8006;
        break;
    case FRONTIER_DATA_SELECTED_MON_ORDER:
        for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
            gSaveBlock1Ptr->frontier.selectedPartyMons[i] = gSelectedOrderFromParty[i];
        break;
    case FRONTIER_DATA_RECORD_DISABLED:
        gSaveBlock1Ptr->frontier.disableRecordBattle = gSpecialVar_0x8006;
        break;
    case FRONTIER_DATA_HEARD_BRAIN_SPEECH:
        gSaveBlock1Ptr->frontier.battledBrainFlags |= sBattledBrainBitFlags[facility][hasSymbol];
        break;
    }
}

static void SetSelectedPartyOrder(void)
{
    s32 i;

    ClearSelectedPartyOrder();
    for (i = 0; i < gSpecialVar_0x8005; i++)
        gSelectedOrderFromParty[i] = gSaveBlock1Ptr->frontier.selectedPartyMons[i];
    ReducePlayerPartyToSelectedMons();
}

static void DoSoftReset_(void)
{
    DoSoftReset();
}

static void SetFrontierTrainers(void)
{
    gFacilityTrainers = gBattleFrontierTrainers;
}

static void SaveSelectedParty(void)
{
    u8 i;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gSaveBlock1Ptr->frontier.selectedPartyMons[i] - 1;
        if (monId < PARTY_SIZE)
            gSaveBlock1Ptr->playerParty[gSaveBlock1Ptr->frontier.selectedPartyMons[i] - 1] = gPlayerParty[i];
    }
}

static void ShowFacilityResultsWindow(void)
{
    if (gSpecialVar_0x8006 >= FRONTIER_MODE_COUNT)
        gSpecialVar_0x8006 = 0;
    switch (gSpecialVar_0x8005)
    {
    case FRONTIER_FACILITY_TOWER:
        ShowTowerResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_DOME:
        ShowDomeResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_PALACE:
        ShowPalaceResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_PIKE:
        ShowPikeResultsWindow();
        break;
    case FRONTIER_FACILITY_FACTORY:
        ShowFactoryResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_ARENA:
        ShowArenaResultsWindow();
        break;
    case FRONTIER_FACILITY_PYRAMID:
        ShowPyramidResultsWindow();
        break;
    case FACILITY_LINK_CONTEST:
        ShowLinkContestResultsWindow();
        break;
    }
}

static bool8 IsWinStreakActive(u32 challenge)
{
    if (gSaveBlock1Ptr->frontier.winStreakActiveFlags & challenge)
        return TRUE;
    else
        return FALSE;
}

static void PrintAligned(const u8 *str, s32 y)
{
    s32 x = GetStringCenterAlignXOffset(FONT_NORMAL, str, DISPLAY_WIDTH - 16);
    y = (y * 8) + 1;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x, y, TEXT_SKIP_DRAW, NULL);
}

static void PrintHyphens(s32 y)
{
    s32 i;
    u8 text[37];

    for (i = 0; i < (int)ARRAY_COUNT(text) - 1; i++)
        text[i] = CHAR_HYPHEN;
    text[i] = EOS;

    y = (y * 8) + 1;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, text, 4, y, TEXT_SKIP_DRAW, NULL);
}

// Battle Tower records.
static void TowerPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x1, y, TEXT_SKIP_DRAW, NULL);
    if (num > MAX_STREAK)
        num = MAX_STREAK;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void TowerPrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock1Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode];
    TowerPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 TowerGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void TowerPrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = TowerGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_TOWER_SINGLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_TOWER_SINGLES_50);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_TOWER_DOUBLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_TOWER_DOUBLES_50);
        break;
    case FRONTIER_MODE_MULTIS:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_TOWER_MULTIS_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_TOWER_MULTIS_50);
        break;
    case FRONTIER_MODE_LINK_MULTIS:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_TOWER_LINK_MULTIS_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_TOWER_LINK_MULTIS_50);
        break;
    }

    if (isCurrent == TRUE)
        TowerPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        TowerPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowTowerResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleRoomResults);
    else if (battleMode == FRONTIER_MODE_DOUBLES)
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleRoomResults);
    else if (battleMode == FRONTIER_MODE_MULTIS)
        StringExpandPlaceholders(gStringVar4, gText_MultiBattleRoomResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_LinkMultiBattleRoomResults);

    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 16, 49, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 16, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    TowerPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 72, 132, 49);
    TowerPrintRecordStreak(battleMode, FRONTIER_LVL_50, 72, 132, 65);
    TowerPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 72, 132, 97);
    TowerPrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 72, 132, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Dome records.
static u16 DomeGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void PrintTwoStrings(const u8 *str1, const u8 *str2, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str1, x1, y, TEXT_SKIP_DRAW, NULL);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, str2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void DomePrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = DomeGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_DOME_SINGLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_DOME_SINGLES_50);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_DOME_DOUBLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_DOME_DOUBLES_50);
        break;
    }

    if (isCurrent == TRUE)
        PrintTwoStrings(gText_Current, gText_ClearStreak, winStreak, x1, x2, y);
    else
        PrintTwoStrings(gText_Prev, gText_ClearStreak, winStreak, x1, x2, y);
}

static void ShowDomeResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleTourneyResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleTourneyResults);

    PrintAligned(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 8, 33, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 8, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    DomePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 64, 121, 33);
    PrintTwoStrings(gText_Record, gText_ClearStreak, gSaveBlock1Ptr->frontier.domeRecordWinStreaks[battleMode][FRONTIER_LVL_50], 64, 121, 49);
    PrintTwoStrings(gText_Total, gText_Championships, gSaveBlock1Ptr->frontier.domeTotalChampionships[battleMode][FRONTIER_LVL_50], 64, 112, 65);
    DomePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 64, 121, 97);
    PrintTwoStrings(gText_Record, gText_ClearStreak, gSaveBlock1Ptr->frontier.domeRecordWinStreaks[battleMode][FRONTIER_LVL_OPEN], 64, 121, 113);
    PrintTwoStrings(gText_Total, gText_Championships, gSaveBlock1Ptr->frontier.domeTotalChampionships[battleMode][FRONTIER_LVL_OPEN], 64, 112, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Palace records.
static void PalacePrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x1, y, TEXT_SKIP_DRAW, NULL);
    if (num > MAX_STREAK)
        num = MAX_STREAK;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void PalacePrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock1Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode];
    PalacePrintStreak(gText_Record, num, x1, x2, y);
}

static u16 PalaceGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void PalacePrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PalaceGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_PALACE_SINGLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_PALACE_SINGLES_50);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_PALACE_DOUBLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_PALACE_DOUBLES_50);
    }

    if (isCurrent == TRUE)
        PalacePrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        PalacePrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowPalaceResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleHallResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleHallResults);

    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 16, 49, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 16, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    PalacePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 72, 131, 49);
    PalacePrintRecordStreak(battleMode, FRONTIER_LVL_50, 72, 131, 65);
    PalacePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 72, 131, 97);
    PalacePrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 72, 131, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Pike records.
static u16 PikeGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock1Ptr->frontier.pikeWinStreaks[lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void PikePrintCleared(const u8 *str1, const u8 *str2, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str1, x1, y, TEXT_SKIP_DRAW, NULL);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, str2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void PikePrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PikeGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = IsWinStreakActive(STREAK_PIKE_OPEN);
    else
        isCurrent = IsWinStreakActive(STREAK_PIKE_50);

    if (isCurrent == TRUE)
        PrintTwoStrings(gText_Current, gText_RoomsCleared, winStreak, x1, x2, y);
    else
        PrintTwoStrings(gText_Prev, gText_RoomsCleared, winStreak, x1, x2, y);
}

static void ShowPikeResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    StringExpandPlaceholders(gStringVar4, gText_BattleChoiceResults);
    PrintAligned(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 8, 33, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 8, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    PikePrintPrevOrCurrentStreak(FRONTIER_LVL_50, 64, 114, 33);
    PikePrintCleared(gText_Record, gText_RoomsCleared, gSaveBlock1Ptr->frontier.pikeRecordStreaks[FRONTIER_LVL_50], 64, 114, 49);
    PikePrintCleared(gText_Total, gText_TimesCleared, gSaveBlock1Ptr->frontier.pikeTotalStreaks[FRONTIER_LVL_50], 64, 114, 65);
    PikePrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 64, 114, 97);
    PikePrintCleared(gText_Record, gText_RoomsCleared, gSaveBlock1Ptr->frontier.pikeRecordStreaks[FRONTIER_LVL_OPEN], 64, 114, 113);
    PikePrintCleared(gText_Total, gText_TimesCleared, gSaveBlock1Ptr->frontier.pikeTotalStreaks[FRONTIER_LVL_OPEN], 64, 114, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Arena records.
static void ArenaPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x1, y, TEXT_SKIP_DRAW, NULL);
    if (num > MAX_STREAK)
        num = MAX_STREAK;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_KOsInARow);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void ArenaPrintRecordStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock1Ptr->frontier.arenaRecordStreaks[lvlMode];
    ArenaPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 ArenaGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock1Ptr->frontier.arenaWinStreaks[lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void ArenaPrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = ArenaGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = IsWinStreakActive(STREAK_ARENA_OPEN);
    else
        isCurrent = IsWinStreakActive(STREAK_ARENA_50);

    if (isCurrent == TRUE)
        ArenaPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        ArenaPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowArenaResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    PrintHyphens(10);
    StringExpandPlaceholders(gStringVar4, gText_SetKOTourneyResults);
    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 16, 49, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 16, 97, TEXT_SKIP_DRAW, NULL);
    ArenaPrintPrevOrCurrentStreak(FRONTIER_LVL_50, 72, 126, 49);
    ArenaPrintRecordStreak(FRONTIER_LVL_50, 72, 126, 65);
    ArenaPrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 72, 126, 97);
    ArenaPrintRecordStreak(FRONTIER_LVL_OPEN, 72, 126, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Factory records.
static void FactoryPrintStreak(const u8 *str, u16 num1, u16 num2, u8 x1, u8 x2, u8 x3, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x1, y, TEXT_SKIP_DRAW, NULL);
    if (num1 > MAX_STREAK)
        num1 = MAX_STREAK;
    ConvertIntToDecimalStringN(gStringVar1, num1, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);

    ConvertIntToDecimalStringN(gStringVar1, num2, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_TimesVar1);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x3, y, TEXT_SKIP_DRAW, NULL);
}

static void FactoryPrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 x3, u8 y)
{
    u16 num1 = gSaveBlock1Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode];
    u16 num2 = gSaveBlock1Ptr->frontier.factoryRecordRentsCount[battleMode][lvlMode];
    FactoryPrintStreak(gText_Record, num1, num2, x1, x2, x3, y);
}

static u16 FactoryGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static u16 FactoryGetRentsCount(u8 battleMode, u8 lvlMode)
{
    u16 rents = gSaveBlock1Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
    if (rents > MAX_STREAK)
        return MAX_STREAK;
    else
        return rents;
}

static void FactoryPrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 x3, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = FactoryGetWinStreak(battleMode, lvlMode);
    u16 rents = FactoryGetRentsCount(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_FACTORY_SINGLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_FACTORY_SINGLES_50);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_FACTORY_DOUBLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_FACTORY_DOUBLES_50);
        break;
    }

    if (isCurrent == TRUE)
        FactoryPrintStreak(gText_Current, winStreak, rents, x1, x2, x3, y);
    else
        FactoryPrintStreak(gText_Prev, winStreak, rents, x1, x2, x3, y);
}

static void ShowFactoryResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_BattleSwapSingleResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_BattleSwapDoubleResults);

    PrintAligned(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 8, 33, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_RentalSwap, 152, 33, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 8, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    FactoryPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 8, 64, 158, 49);
    FactoryPrintRecordStreak(battleMode, FRONTIER_LVL_50, 8, 64, 158, 65);
    FactoryPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 8, 64, 158, 113);
    FactoryPrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 8, 64, 158, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Pyramid records.
static void PyramidPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x1, y, TEXT_SKIP_DRAW, NULL);
    if (num > MAX_STREAK)
        num = MAX_STREAK;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_FloorsCleared);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void PyramidPrintRecordStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock1Ptr->frontier.pyramidRecordStreaks[lvlMode];
    PyramidPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 PyramidGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock1Ptr->frontier.pyramidWinStreaks[lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void PyramidPrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PyramidGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = IsWinStreakActive(STREAK_PYRAMID_OPEN);
    else
        isCurrent = IsWinStreakActive(STREAK_PYRAMID_50);

    if (isCurrent == TRUE)
        PyramidPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        PyramidPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowPyramidResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    StringExpandPlaceholders(gStringVar4, gText_BattleQuestResults);
    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 8, 49, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 8, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    PyramidPrintPrevOrCurrentStreak(FRONTIER_LVL_50, 64, 111, 49);
    PyramidPrintRecordStreak(FRONTIER_LVL_50, 64, 111, 65);
    PyramidPrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 64, 111, 97);
    PyramidPrintRecordStreak(FRONTIER_LVL_OPEN, 64, 111, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Link contest records. Why is it in this file?
static void ShowLinkContestResultsWindow(void)
{
    const u8 *str;
    s32 i, j;
    s32 x;

    gRecordsWindowId = AddWindow(&sLinkContestResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));

    StringExpandPlaceholders(gStringVar4, gText_LinkContestResults);
    x = GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, 208);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x, 1, TEXT_SKIP_DRAW, NULL);

    str = gText_1st;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 38) + 50;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x, 25, TEXT_SKIP_DRAW, NULL);

    str = gText_2nd;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 38) + 88;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x, 25, TEXT_SKIP_DRAW, NULL);

    str = gText_3rd;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 38) + 126;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x, 25, TEXT_SKIP_DRAW, NULL);

    str = gText_4th;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 38) + 164;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x, 25, TEXT_SKIP_DRAW, NULL);

    x = 6;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Cool, x, 41, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Beauty, x, 57, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Cute, x, 73, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Smart, x, 89, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Tough, x, 105, TEXT_SKIP_DRAW, NULL);

    for (i = 0; i < CONTEST_CATEGORIES_COUNT; i++)
    {
        for (j = 0; j < CONTESTANT_COUNT; j++)
        {
            ConvertIntToDecimalStringN(gStringVar4, gSaveBlock2Ptr->contestLinkResults[i][j], STR_CONV_MODE_RIGHT_ALIGN, 4);
            AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, (j * 38) + 64, (i * 16) + 41, TEXT_SKIP_DRAW, NULL);
        }
    }

    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

static void CheckPutFrontierTVShowOnAir(void)
{
    u8 name[32];
    s32 lvlMode = gSaveBlock1Ptr->frontier.lvlMode;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        if (gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode] > gSaveBlock1Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock1Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode] = gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
            if (battleMode == FRONTIER_MODE_LINK_MULTIS)
            {
                StringCopy(name, gLinkPlayers[gBattleScripting.multiplayerId ^ 1].name);
                StripExtCtrlCodes(name);
                StringCopy(gSaveBlock1Ptr->frontier.opponentNames[lvlMode], name);
                SetTrainerId(gLinkPlayers[gBattleScripting.multiplayerId ^ 1].trainerId, gSaveBlock1Ptr->frontier.opponentTrainerIds[lvlMode]);
            }
            if (gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                switch (battleMode)
                {
                case FRONTIER_MODE_SINGLES:
                    TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_TOWER_SINGLES);
                    break;
                case FRONTIER_MODE_DOUBLES:
                    TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_TOWER_DOUBLES);
                    break;
                case FRONTIER_MODE_MULTIS:
                    TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_TOWER_MULTIS);
                    break;
                case FRONTIER_MODE_LINK_MULTIS:
                    TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_TOWER_LINK_MULTIS);
                    break;
                }
            }
        }
        break;
    case FRONTIER_FACILITY_DOME:
        if (gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode] > gSaveBlock1Ptr->frontier.domeRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock1Ptr->frontier.domeRecordWinStreaks[battleMode][lvlMode] = gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
            if (gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_DOME_SINGLES);
                else
                    TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_DOME_DOUBLES);
            }
        }
        break;
    case FRONTIER_FACILITY_PALACE:
        if (gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] > gSaveBlock1Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock1Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode] = gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
            if (gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_PALACE_SINGLES);
                else
                    TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_PALACE_DOUBLES);
            }
        }
        break;
    case FRONTIER_FACILITY_ARENA:
        if (gSaveBlock1Ptr->frontier.arenaWinStreaks[lvlMode] > gSaveBlock1Ptr->frontier.arenaRecordStreaks[lvlMode])
        {
            gSaveBlock1Ptr->frontier.arenaRecordStreaks[lvlMode] = gSaveBlock1Ptr->frontier.arenaWinStreaks[lvlMode];
            if (gSaveBlock1Ptr->frontier.arenaWinStreaks[lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.arenaWinStreaks[lvlMode], FRONTIER_SHOW_ARENA);
            }
        }
        break;
    case FRONTIER_FACILITY_FACTORY:
        if (gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] > gSaveBlock1Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock1Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode] = gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
            gSaveBlock1Ptr->frontier.factoryRecordRentsCount[battleMode][lvlMode] = gSaveBlock1Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
            if (gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_FACTORY_SINGLES);
                else
                    TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_FACTORY_DOUBLES);
            }
        }
        break;
    case FRONTIER_FACILITY_PIKE:
        if (gSaveBlock1Ptr->frontier.pikeWinStreaks[lvlMode] > gSaveBlock1Ptr->frontier.pikeRecordStreaks[lvlMode])
        {
            gSaveBlock1Ptr->frontier.pikeRecordStreaks[lvlMode] = gSaveBlock1Ptr->frontier.pikeWinStreaks[lvlMode];
            if (gSaveBlock1Ptr->frontier.pikeWinStreaks[lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.pikeWinStreaks[lvlMode], FRONTIER_SHOW_PIKE);
            }
        }
        break;
    case FRONTIER_FACILITY_PYRAMID:
        if (gSaveBlock1Ptr->frontier.pyramidWinStreaks[lvlMode] > gSaveBlock1Ptr->frontier.pyramidRecordStreaks[lvlMode])
        {
            gSaveBlock1Ptr->frontier.pyramidRecordStreaks[lvlMode] = gSaveBlock1Ptr->frontier.pyramidWinStreaks[lvlMode];
            if (gSaveBlock1Ptr->frontier.pyramidWinStreaks[lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                TryPutFrontierTVShowOnAir(gSaveBlock1Ptr->frontier.pyramidWinStreaks[lvlMode], FRONTIER_SHOW_PYRAMID);
            }
        }
        break;
    }
}

static void Script_GetFrontierBrainStatus(void)
{
    VarGet(VAR_FRONTIER_FACILITY); // Unused return value.
    gSpecialVar_Result = GetFrontierBrainStatus();
}

u8 GetFrontierBrainStatus(void)
{
    s32 status = FRONTIER_BRAIN_NOT_READY;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u16 winStreakNoModifier = GetCurrentFacilityWinStreak();
    s32 winStreak = winStreakNoModifier + sFrontierBrainStreakAppearances[facility][3];
    s32 symbolsCount;

    if (battleMode != FRONTIER_MODE_SINGLES)
        return FRONTIER_BRAIN_NOT_READY;

    symbolsCount = GetPlayerSymbolCountForFacility(facility);
    switch (symbolsCount)
    {
    // Missing a symbol
    case 0:
    case 1:
        if (winStreak == sFrontierBrainStreakAppearances[facility][symbolsCount])
            status = symbolsCount + 1; // FRONTIER_BRAIN_SILVER and FRONTIER_BRAIN_GOLD
        break;
    // Already received both symbols
    case 2:
    default:
        // Silver streak is reached
        if (winStreak == sFrontierBrainStreakAppearances[facility][0])
            status = FRONTIER_BRAIN_STREAK;
        // Gold streak is reached
        else if (winStreak == sFrontierBrainStreakAppearances[facility][1])
            status = FRONTIER_BRAIN_STREAK_LONG;
        // Some increment of the gold streak is reached
        else if (winStreak > sFrontierBrainStreakAppearances[facility][1] && (winStreak - sFrontierBrainStreakAppearances[facility][1]) % sFrontierBrainStreakAppearances[facility][2] == 0)
            status = FRONTIER_BRAIN_STREAK_LONG;
        break;
    }

    return status;
}

void CopyFrontierTrainerText(u8 whichText, u16 trainerId)
{
    switch (whichText)
    {
    case FRONTIER_BEFORE_TEXT:
        if (trainerId == TRAINER_EREADER)
            FrontierSpeechToString(gSaveBlock1Ptr->frontier.ereaderTrainer[0].greeting);
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
            CopyFrontierBrainText(FALSE);
        else if (trainerId < FRONTIER_TRAINERS_COUNT)
            FrontierSpeechToString(gFacilityTrainers[trainerId].speechBefore);
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
            FrontierSpeechToString(gSaveBlock1Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].greeting);
        else
            BufferApprenticeChallengeText(trainerId - TRAINER_RECORD_MIXING_APPRENTICE);
        break;
    case FRONTIER_PLAYER_LOST_TEXT:
        if (trainerId == TRAINER_EREADER)
        {
            FrontierSpeechToString(gSaveBlock1Ptr->frontier.ereaderTrainer[0].farewellPlayerLost);
        }
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
        {
            CopyFrontierBrainText(FALSE);
        }
        else if (trainerId < FRONTIER_TRAINERS_COUNT)
        {
            FrontierSpeechToString(gFacilityTrainers[trainerId].speechWin);
        }
        else if (trainerId > 800 && trainerId < TRAINERS_COUNT)
        {
            StringCopy(gStringVar4, sFrontierLeaderWonTexts[trainerId]);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                FrontierSpeechToString(GetRecordedBattleEasyChatSpeech());
            else
                FrontierSpeechToString(gSaveBlock1Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].speechWon);
        }
		else if (trainerId > TRAINER_EREADER)
        {
            FrontierSpeechToString(gSaveBlock1Ptr->frontier.ereaderTrainer[trainerId-500].farewellPlayerLost);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                FrontierSpeechToString(GetRecordedBattleEasyChatSpeech());
            else
                FrontierSpeechToString(gSaveBlock1Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].speechWon);
        }
        break;
    case FRONTIER_PLAYER_WON_TEXT:
        if (trainerId == TRAINER_EREADER)
        {
            FrontierSpeechToString(gSaveBlock1Ptr->frontier.ereaderTrainer[0].farewellPlayerWon);
        }
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
        {
            CopyFrontierBrainText(TRUE);
        }
        else if (trainerId < FRONTIER_TRAINERS_COUNT)
        {
            FrontierSpeechToString(gFacilityTrainers[trainerId].speechLose);
        }
        else if (trainerId > 800 && trainerId < TRAINERS_COUNT)
        {
            StringCopy(gStringVar4, sFrontierLeaderLoseTexts[trainerId]);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                FrontierSpeechToString(GetRecordedBattleEasyChatSpeech());
            else
                FrontierSpeechToString(gSaveBlock1Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].speechLost);
        }
		else if (trainerId > TRAINER_EREADER)
        {
            FrontierSpeechToString(gSaveBlock1Ptr->frontier.ereaderTrainer[trainerId-500].farewellPlayerWon);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            {
                trainerId = GetRecordedBattleApprenticeId();
                FrontierSpeechToString(gApprentices[trainerId].speechLost);
            }
            else
            {
                trainerId = gSaveBlock1Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id;
                FrontierSpeechToString(gApprentices[trainerId].speechLost);
            }
        }
        break;
    }
}

void ResetWinStreaks(void)
{
    s32 battleMode, lvlMode;

    gSaveBlock1Ptr->frontier.winStreakActiveFlags = 0;
    for (battleMode = 0; battleMode < FRONTIER_MODE_COUNT; battleMode++)
    {
        for (lvlMode = 0; lvlMode < FRONTIER_LVL_TENT; lvlMode++)
        {
            gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode] = 0;
            if (battleMode < FRONTIER_MODE_MULTIS)
            {
                gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode] = 0;
                gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] = 0;
                gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = 0;
            }
            if (battleMode == FRONTIER_MODE_SINGLES)
            {
                gSaveBlock1Ptr->frontier.arenaWinStreaks[lvlMode] = 0;
                gSaveBlock1Ptr->frontier.pikeWinStreaks[lvlMode] = 0;
                gSaveBlock1Ptr->frontier.pyramidWinStreaks[lvlMode] = 0;
            }
        }
    }
    if (gSaveBlock1Ptr->frontier.challengeStatus != 0)
        gSaveBlock1Ptr->frontier.challengeStatus = CHALLENGE_STATUS_SAVING;
}

u32 GetCurrentFacilityWinStreak(void)
{
    s32 lvlMode = gSaveBlock1Ptr->frontier.lvlMode;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        return gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_DOME:
        return gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_PALACE:
        return gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_ARENA:
        return gSaveBlock1Ptr->frontier.arenaWinStreaks[lvlMode];
    case FRONTIER_FACILITY_FACTORY:
        return gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_PIKE:
        return gSaveBlock1Ptr->frontier.pikeWinStreaks[lvlMode];
    case FRONTIER_FACILITY_PYRAMID:
        return gSaveBlock1Ptr->frontier.pyramidWinStreaks[lvlMode];
    default:
        return 0;
    }
}

void ResetFrontierTrainerIds(void)
{
    s32 i;

    for (i = 0; i < (int)ARRAY_COUNT(gSaveBlock1Ptr->frontier.trainerIds); i++)
        gSaveBlock1Ptr->frontier.trainerIds[i] = 0xFFFF;
}

static void IsTrainerFrontierBrain(void)
{
    if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

u8 GetPlayerSymbolCountForFacility(u8 facility)
{
    return FlagGet(FLAG_SYS_TOWER_SILVER + facility * 2)
         + FlagGet(FLAG_SYS_TOWER_GOLD + facility * 2);
}

static void GiveBattlePoints(void)
{
    s32 challengeNum = 0;
    s32 lvlMode = gSaveBlock1Ptr->frontier.lvlMode;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 points;

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        challengeNum = gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_DOME:
        challengeNum = gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
        break;
    case FRONTIER_FACILITY_PALACE:
        challengeNum = gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_ARENA:
        challengeNum = gSaveBlock1Ptr->frontier.arenaWinStreaks[lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_FACTORY:
        challengeNum = gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_PIKE:
        challengeNum = gSaveBlock1Ptr->frontier.pikeWinStreaks[lvlMode] / 14;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        challengeNum = gSaveBlock1Ptr->frontier.pyramidWinStreaks[lvlMode] / 7;
        break;
    }

    if (challengeNum != 0)
        challengeNum--;
    if (challengeNum >= ARRAY_COUNT(sBattlePointAwards[0][0]))
        challengeNum = ARRAY_COUNT(sBattlePointAwards[0][0]) - 1;

    points = sBattlePointAwards[facility][battleMode][challengeNum];
    if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
        points += 10;
    gSaveBlock1Ptr->frontier.battlePoints += points;
    ConvertIntToDecimalStringN(gStringVar1, points, STR_CONV_MODE_LEFT_ALIGN, 2);
    if (gSaveBlock1Ptr->frontier.battlePoints > MAX_BATTLE_FRONTIER_POINTS)
        gSaveBlock1Ptr->frontier.battlePoints = MAX_BATTLE_FRONTIER_POINTS;

    points = gSaveBlock1Ptr->frontier.cardBattlePoints;
    points += sBattlePointAwards[facility][battleMode][challengeNum];
    IncrementDailyBattlePoints(sBattlePointAwards[facility][battleMode][challengeNum]);
    if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
    {
        points += 10;
        IncrementDailyBattlePoints(10);
    }
    if (points > 0xFFFF)
        points = 0xFFFF;
    gSaveBlock1Ptr->frontier.cardBattlePoints = points;
}

static void GetFacilitySymbolCount(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    gSpecialVar_Result = GetPlayerSymbolCountForFacility(facility);
}

static void GiveFacilitySymbol(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    if (GetPlayerSymbolCountForFacility(facility) == 0)
        FlagSet(FLAG_SYS_TOWER_SILVER + facility * 2);
    else
        FlagSet(FLAG_SYS_TOWER_GOLD + facility * 2);
}

static void CheckBattleTypeFlag(void)
{
    if (gBattleTypeFlags & gSpecialVar_0x8005)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

#define SPECIES_PER_LINE 3

static u8 AppendCaughtBannedMonSpeciesName(u16 species, u8 count, s32 numBannedMonsCaught)
{
    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(GET_BASE_SPECIES_ID(species)), FLAG_GET_CAUGHT))
    {
        count++;
        if (numBannedMonsCaught == count)
            StringAppend(gStringVar1, gText_SpaceAndSpace);
        else if (numBannedMonsCaught > count)
            StringAppend(gStringVar1, gText_CommaSpace);
        if ((count % SPECIES_PER_LINE) == 0)
        {
            if (count == SPECIES_PER_LINE)
                StringAppend(gStringVar1, gText_NewLine);
            else
                StringAppend(gStringVar1, gText_LineBreak);
        }
        StringAppend(gStringVar1, GetSpeciesName(species));
    }

    return count;
}

static void AppendIfValid(u16 species, u16 heldItem, u16 hp, u8 lvlMode, u8 monLevel, u16 *speciesArray, u16 *itemsArray, u8 *count)
{
    s32 i = 0;

    if (species == SPECIES_EGG || species == SPECIES_NONE)
        return;

    for (i = 0; gFrontierBannedSpecies[i] != 0xFFFF
      && gFrontierBannedSpecies[i] != GET_BASE_SPECIES_ID(species)
      && IsSpeciesEnabled(gFrontierBannedSpecies[i]); i++)
        ;

    if (gFrontierBannedSpecies[i] != 0xFFFF)
        return;
    if (lvlMode == FRONTIER_LVL_50 && monLevel > FRONTIER_MAX_LEVEL_50)
        return;

    for (i = 0; i < *count && speciesArray[i] != species; i++)
        ;
    if (i != *count)
        return;

    if (heldItem != 0)
    {
        for (i = 0; i < *count && itemsArray[i] != heldItem; i++)
            ;
        if (i != *count)
            return;
    }

    speciesArray[*count] = species;
    itemsArray[*count] = heldItem;
    (*count)++;
}

// gSpecialVar_Result is the level mode before and after calls to this function
// gSpecialVar_0x8004 is used to store the return value instead (TRUE if there are insufficient eligible mons)
// The names of ineligible pokemon that have been caught are also buffered to print
static void CheckPartyIneligibility(void)
{
    u16 speciesArray[PARTY_SIZE];
    u16 itemArray[PARTY_SIZE];
    s32 monId = 0;
    s32 toChoose = 0;
    u8 count = 0;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 monIdLooper;

    // count is re-used, define for clarity
    #define numEligibleMons count

    switch (battleMode)
    {
    case FRONTIER_MODE_SINGLES:
        toChoose = FRONTIER_PARTY_SIZE;
        break;
    case FRONTIER_MODE_MULTIS:
    case FRONTIER_MODE_LINK_MULTIS:
        toChoose = FRONTIER_MULTI_PARTY_SIZE;
        break;
    case FRONTIER_MODE_DOUBLES:
        if (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_TOWER)
            toChoose = FRONTIER_DOUBLES_PARTY_SIZE;
        else
            toChoose = FRONTIER_PARTY_SIZE;
        break;
    }

    monIdLooper = 0;
    do
    {
        monId = monIdLooper;
        numEligibleMons = 0;
        do
        {
            u16 species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES_OR_EGG);
            u16 heldItem = GetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM);
            u8 level = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
            u16 hp = GetMonData(&gPlayerParty[monId], MON_DATA_HP);
            if (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_PYRAMID)
            {
                if (heldItem == ITEM_NONE)
                    AppendIfValid(species, heldItem, hp, gSpecialVar_Result, level, speciesArray, itemArray, &numEligibleMons);
            }
            else
            {
                AppendIfValid(species, heldItem, hp, gSpecialVar_Result, level, speciesArray, itemArray, &numEligibleMons);
            }
            monId++;
            if (monId >= PARTY_SIZE)
                monId = 0;
        } while (monId != monIdLooper);

        monIdLooper++;
    } while (monIdLooper < PARTY_SIZE && numEligibleMons < toChoose);

    if (numEligibleMons < toChoose)
    {
        s32 i;
        s32 caughtBannedMons = 0;
        s32 species = gFrontierBannedSpecies[0];
        for (i = 0; species != 0xFFFF; i++, species = gFrontierBannedSpecies[i])
        {
            if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(GET_BASE_SPECIES_ID(species)), FLAG_GET_CAUGHT))
                caughtBannedMons++;
        }
        gStringVar1[0] = EOS;
        gSpecialVar_0x8004 = TRUE;
        count = 0;
        for (i = 0; gFrontierBannedSpecies[i] != 0xFFFF; i++)
            count = AppendCaughtBannedMonSpeciesName(gFrontierBannedSpecies[i], count, caughtBannedMons);

        if (count == 0)
        {
            StringAppend(gStringVar1, gText_Space2);
            StringAppend(gStringVar1, gText_Are);
        }
        else
        {
            if (count % SPECIES_PER_LINE == SPECIES_PER_LINE - 1)
                StringAppend(gStringVar1, gText_LineBreak);
            else
                StringAppend(gStringVar1, gText_Space2);
            StringAppend(gStringVar1, gText_Are2);
        }
    }
    else
    {
        gSpecialVar_0x8004 = FALSE;
        gSaveBlock1Ptr->frontier.lvlMode = gSpecialVar_Result;
    }
    #undef numEligibleMons
}

#undef SPECIES_PER_LINE

static void ValidateVisitingTrainer(void)
{
    ValidateEReaderTrainer();
}

static void IncrementWinStreak(void)
{
    s32 lvlMode = gSaveBlock1Ptr->frontier.lvlMode;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        if (gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode] < MAX_STREAK)
        {
            gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode]++;
            if (battleMode == FRONTIER_MODE_SINGLES)
            {
                SetGameStat(GAME_STAT_BATTLE_TOWER_SINGLES_STREAK, gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode]);
                gSaveBlock1Ptr->frontier.towerSinglesStreak = gSaveBlock1Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
            }
        }
        break;
    case FRONTIER_FACILITY_DOME:
        if (gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode] < MAX_STREAK)
            gSaveBlock1Ptr->frontier.domeWinStreaks[battleMode][lvlMode]++;
        if (gSaveBlock1Ptr->frontier.domeTotalChampionships[battleMode][lvlMode] < MAX_STREAK)
            gSaveBlock1Ptr->frontier.domeTotalChampionships[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_PALACE:
        if (gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] < MAX_STREAK)
            gSaveBlock1Ptr->frontier.palaceWinStreaks[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_ARENA:
        if (gSaveBlock1Ptr->frontier.arenaWinStreaks[lvlMode] < MAX_STREAK)
            gSaveBlock1Ptr->frontier.arenaWinStreaks[lvlMode]++;
        break;
    case FRONTIER_FACILITY_FACTORY:
        if (gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] < MAX_STREAK)
            gSaveBlock1Ptr->frontier.factoryWinStreaks[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_PIKE:
        if (gSaveBlock1Ptr->frontier.pikeWinStreaks[lvlMode] < MAX_STREAK)
            gSaveBlock1Ptr->frontier.pikeWinStreaks[lvlMode]++;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        if (gSaveBlock1Ptr->frontier.pyramidWinStreaks[lvlMode] < MAX_STREAK)
            gSaveBlock1Ptr->frontier.pyramidWinStreaks[lvlMode]++;
        break;
    }
}

static void RestoreHeldItems(void)
{
    u8 i;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (gSaveBlock1Ptr->frontier.selectedPartyMons[i] != 0)
        {
            u16 item = GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock1Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_HELD_ITEM, NULL);
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
        }
    }
}

static void SaveRecordBattle(void)
{
    gSpecialVar_Result = MoveRecordedBattleToSaveData();
    gSaveBlock1Ptr->frontier.disableRecordBattle = TRUE;
}

static void BufferFrontierTrainerName(void)
{
    switch (gSpecialVar_0x8005)
    {
    case 0:
        GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
        break;
    case 1:
        GetFrontierTrainerName(gStringVar2, gTrainerBattleOpponent_A);
        break;
    }
}

static void ResetSketchedMoves(void)
{
    u8 i, j, k;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gSaveBlock1Ptr->frontier.selectedPartyMons[i] - 1;
        if (monId < PARTY_SIZE)
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                for (k = 0; k < MAX_MON_MOVES; k++)
                {
                    if (GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock1Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_MOVE1 + k, NULL)
                        == GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j, NULL))
                        break;
                }
                if (k == MAX_MON_MOVES)
                    SetMonMoveSlot(&gPlayerParty[i], MOVE_SKETCH, j);
            }
            gSaveBlock1Ptr->playerParty[gSaveBlock1Ptr->frontier.selectedPartyMons[i] - 1] = gPlayerParty[i];
        }
    }
}

static void SetFacilityBrainObjectEvent(void)
{
    SetFrontierBrainObjEventGfx(VarGet(VAR_FRONTIER_FACILITY));
}

// Battle Frontier Ranking Hall records.
static void Print1PRecord(s32 position, s32 x, s32 y, struct RankingHall1P *hallRecord, s32 hallFacilityId)
{
    u8 text[32];
    u16 winStreak;

    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_123Dot[position], x * 8, (8 * (y + 5 * position)) + 1, TEXT_SKIP_DRAW, NULL);
    hallRecord->name[PLAYER_NAME_LENGTH] = EOS;
    if (hallRecord->winStreak)
    {
        TVShowConvertInternationalString(text, hallRecord->name, hallRecord->language);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, text, (x + 2) * 8, (8 * (y + 5 * position)) + 1, TEXT_SKIP_DRAW, NULL);
        winStreak = hallRecord->winStreak;
        if (winStreak > MAX_STREAK)
            winStreak = MAX_STREAK;
        ConvertIntToDecimalStringN(gStringVar2, winStreak, STR_CONV_MODE_RIGHT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, sHallFacilityToRecordsText[hallFacilityId]);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, GetStringRightAlignXOffset(FONT_NORMAL, sHallFacilityToRecordsText[hallFacilityId], 0xC8), (8 * (y + 5 * position)) + 1, TEXT_SKIP_DRAW, NULL);
    }
}

static void Print2PRecord(s32 position, s32 x, s32 y, struct RankingHall2P *hallRecord)
{
    u8 text[32];
    u16 winStreak;

    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_123Dot[position], x * 8, (8 * (y + 5 * position)) + 1, TEXT_SKIP_DRAW, NULL);
    if (hallRecord->winStreak)
    {
        hallRecord->name1[PLAYER_NAME_LENGTH] = EOS;
        hallRecord->name2[PLAYER_NAME_LENGTH] = EOS;
        TVShowConvertInternationalString(text, hallRecord->name1, hallRecord->language);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, text, (x + 2) * 8, (8 * (y + 5 * position - 1)) + 1, TEXT_SKIP_DRAW, NULL);
        if (IsStringJapanese(hallRecord->name2))
            TVShowConvertInternationalString(text, hallRecord->name2, LANGUAGE_JAPANESE);
        else
            StringCopy(text, hallRecord->name2);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, text, (x + 4) * 8, (8 * (y + 5 * position + 1)) + 1, TEXT_SKIP_DRAW, NULL);

        winStreak = hallRecord->winStreak;
        if (winStreak > MAX_STREAK)
            winStreak = MAX_STREAK;
        ConvertIntToDecimalStringN(gStringVar2, winStreak, STR_CONV_MODE_RIGHT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, sHallFacilityToRecordsText[RANKING_HALL_TOWER_LINK]);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, GetStringRightAlignXOffset(FONT_NORMAL, sHallFacilityToRecordsText[RANKING_HALL_TOWER_LINK], 0xC8), (8 * (y + 5 * position)) + 1, TEXT_SKIP_DRAW, NULL);
    }
}

static void Fill1PRecords(struct RankingHall1P *dst, s32 hallFacilityId, s32 lvlMode)
{
    s32 i, j;
    struct RankingHall1P record1P[HALL_RECORDS_COUNT + 1];
    struct PlayerHallRecords *playerHallRecords = AllocZeroed(sizeof(struct PlayerHallRecords));
    GetPlayerHallRecords(playerHallRecords);

    for (i = 0; i < HALL_RECORDS_COUNT; i++)
        record1P[i] = gSaveBlock2Ptr->hallRecords1P[hallFacilityId][lvlMode][i];

    record1P[HALL_RECORDS_COUNT] = playerHallRecords->onePlayer[hallFacilityId][lvlMode];

    for (i = 0; i < HALL_RECORDS_COUNT; i++)
    {
        s32 highestWinStreak = 0;
        s32 highestId = 0;
        for (j = 0; j < HALL_RECORDS_COUNT + 1; j++)
        {
            if (record1P[j].winStreak > highestWinStreak)
            {
                highestId = j;
                highestWinStreak = record1P[j].winStreak;
            }
        }
        if (record1P[HALL_RECORDS_COUNT].winStreak >= highestWinStreak)
            highestId = HALL_RECORDS_COUNT;

        dst[i] = record1P[highestId];
        record1P[highestId].winStreak = 0;
    }

    Free(playerHallRecords);
}

static void Fill2PRecords(struct RankingHall2P *dst, s32 lvlMode)
{
    s32 i, j;
    struct RankingHall2P record2P[HALL_RECORDS_COUNT + 1];
    struct PlayerHallRecords *playerHallRecords = AllocZeroed(sizeof(struct PlayerHallRecords));
    GetPlayerHallRecords(playerHallRecords);

    for (i = 0; i < HALL_RECORDS_COUNT; i++)
        record2P[i] = gSaveBlock2Ptr->hallRecords2P[lvlMode][i];

    record2P[HALL_RECORDS_COUNT] = playerHallRecords->twoPlayers[lvlMode];

    for (i = 0; i < HALL_RECORDS_COUNT; i++)
    {
        s32 highestWinStreak = 0;
        s32 highestId = 0;
        for (j = 0; j < HALL_RECORDS_COUNT; j++)
        {
            if (record2P[j].winStreak > highestWinStreak)
            {
                highestId = j;
                highestWinStreak = record2P[j].winStreak;
            }
        }
        if (record2P[HALL_RECORDS_COUNT].winStreak >= highestWinStreak)
            highestId = HALL_RECORDS_COUNT;

        dst[i] = record2P[highestId];
        record2P[highestId].winStreak = 0;
    }

    Free(playerHallRecords);
}

static void PrintHallRecords(s32 hallFacilityId, s32 lvlMode)
{
    s32 i;
    s32 x;
    struct RankingHall1P records1P[HALL_RECORDS_COUNT];
    struct RankingHall2P records2P[HALL_RECORDS_COUNT];

    StringCopy(gStringVar1, sRecordsWindowChallengeTexts[hallFacilityId][0]);
    StringExpandPlaceholders(gStringVar4, sRecordsWindowChallengeTexts[hallFacilityId][1]);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, 0, 1, TEXT_SKIP_DRAW, NULL);
    x = GetStringRightAlignXOffset(FONT_NORMAL, sLevelModeText[lvlMode], DISPLAY_WIDTH - 32);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, sLevelModeText[lvlMode], x, 1, TEXT_SKIP_DRAW, NULL);
    if (hallFacilityId == RANKING_HALL_TOWER_LINK)
    {
        gSaveBlock1Ptr->frontier.opponentNames[0][PLAYER_NAME_LENGTH] = EOS;
        gSaveBlock1Ptr->frontier.opponentNames[1][PLAYER_NAME_LENGTH] = EOS;
        Fill2PRecords(records2P, lvlMode);
        for (i = 0; i < HALL_RECORDS_COUNT; i++)
            Print2PRecord(i, 1, 4, &records2P[i]);
    }
    else
    {
        Fill1PRecords(records1P, hallFacilityId, lvlMode);
        for (i = 0; i < HALL_RECORDS_COUNT; i++)
            Print1PRecord(i, 1, 4, &records1P[i], hallFacilityId);
    }
}

void ShowRankingHallRecordsWindow(void)
{
    gRecordsWindowId = AddWindow(&sRankingHallRecordsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    PrintHallRecords(gSpecialVar_0x8005, FRONTIER_LVL_50);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

void ScrollRankingHallRecordsWindow(void)
{
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    PrintHallRecords(gSpecialVar_0x8005, FRONTIER_LVL_OPEN);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_GFX);
}

void ClearRankingHallRecords(void)
{
    s32 i, j, k;

    // UB: Passing 0 as a pointer instead of a pointer holding a value of 0.
#ifdef UBFIX
    u8 emptyId[TRAINER_ID_LENGTH] = {0};
    #define ZERO emptyId
#else
    #define ZERO 0
#endif

    for (i = 0; i < HALL_FACILITIES_COUNT; i++)
    {
        for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
        {
            for (k = 0; k < HALL_RECORDS_COUNT; k++)
            {
                CopyTrainerId(gSaveBlock2Ptr->hallRecords1P[i][j][k].id, ZERO);
                gSaveBlock2Ptr->hallRecords1P[i][j][k].name[0] = EOS;
                gSaveBlock2Ptr->hallRecords1P[i][j][k].winStreak = 0;
            }
        }
    }

    for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
    {
        for (k = 0; k < HALL_RECORDS_COUNT; k++)
        {
            CopyTrainerId(gSaveBlock2Ptr->hallRecords2P[j][k].id1, ZERO);
            CopyTrainerId(gSaveBlock2Ptr->hallRecords2P[j][k].id2, ZERO);
            gSaveBlock2Ptr->hallRecords2P[j][k].name1[0] = EOS;
            gSaveBlock2Ptr->hallRecords2P[j][k].name2[0] = EOS;
            gSaveBlock2Ptr->hallRecords2P[j][k].winStreak = 0;
        }
    }
}

void SaveGameFrontier(void)
{
    s32 i;
    struct Pokemon *monsParty = AllocZeroed(sizeof(struct Pokemon) * PARTY_SIZE);

    for (i = 0; i < PARTY_SIZE; i++)
        monsParty[i] = gPlayerParty[i];

    i = gPlayerPartyCount;
    LoadPlayerParty();
    SetContinueGameWarpStatusToDynamicWarp();
    TrySavingData(SAVE_LINK);
    ClearContinueGameWarpStatus2();
    gPlayerPartyCount = i;

    for (i = 0; i < PARTY_SIZE; i++)
        gPlayerParty[i] = monsParty[i];

    Free(monsParty);
}

// Frontier Brain functions.
u8 GetFrontierBrainTrainerPicIndex(void)
{
    s32 facility;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        facility = GetRecordedBattleFrontierFacility();
    else
        facility = VarGet(VAR_FRONTIER_FACILITY);

    return gTrainers[sFrontierBrainTrainerIds[facility]].trainerPic;
}

u8 GetFrontierBrainTrainerClass(void)
{
    s32 facility;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        facility = GetRecordedBattleFrontierFacility();
    else
        facility = VarGet(VAR_FRONTIER_FACILITY);

    return gTrainers[sFrontierBrainTrainerIds[facility]].trainerClass;
}

void CopyFrontierBrainTrainerName(u8 *dst)
{
    s32 i;
    s32 facility;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        facility = GetRecordedBattleFrontierFacility();
    else
        facility = VarGet(VAR_FRONTIER_FACILITY);

    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        dst[i] = gTrainers[sFrontierBrainTrainerIds[facility]].trainerName[i];

    dst[i] = EOS;
}

bool8 IsFrontierBrainFemale(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    return sFrontierBrainObjEventGfx[facility][1];
}

void SetFrontierBrainObjEventGfx_2(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    VarSet(VAR_OBJ_GFX_ID_0, sFrontierBrainObjEventGfx[facility][0]);
}

void SetFrontierLeaderObjEventGfx(u16 trainerID)
{
    VarSet(VAR_OBJ_GFX_ID_0, sFrontierLeaderObjEventGfx[trainerID]);
}

#define FRONTIER_BRAIN_OTID 61226

void CreateFrontierBrainPokemon(void)
{
    s32 i, j;
    s32 selectedMonBits;
    s32 monPartyId;
    s32 monLevel = 0;
    u8 friendship;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    if (facility == FRONTIER_FACILITY_DOME)
        selectedMonBits = GetDomeTrainerSelectedMons(TrainerIdToDomeTournamentId(TRAINER_FRONTIER_BRAIN));
    else
        selectedMonBits = (1 << FRONTIER_PARTY_SIZE) - 1; // all 3 mons selected

    ZeroEnemyPartyMons();
    monPartyId = 0;
    monLevel = SetFacilityPtrsGetLevel();
    for (i = 0; i < FRONTIER_PARTY_SIZE; selectedMonBits >>= 1, i++)
    {
        if (!(selectedMonBits & 1))
            continue;

        do
        {
            do
            {
                j = Random32(); //should just be one while loop, but that doesn't match
            } while (IsShinyOtIdPersonality(FRONTIER_BRAIN_OTID, j));
        } while (sFrontierBrainsMons[facility][symbol][i].nature != GetNatureFromPersonality(j));
        CreateMon(&gEnemyParty[monPartyId],
                  sFrontierBrainsMons[facility][symbol][i].species,
                  monLevel,
                  sFrontierBrainsMons[facility][symbol][i].fixedIV,
                  TRUE, j,
                  OT_ID_PRESET, FRONTIER_BRAIN_OTID);
        SetMonData(&gEnemyParty[monPartyId], MON_DATA_HELD_ITEM, &sFrontierBrainsMons[facility][symbol][i].heldItem);
        for (j = 0; j < NUM_STATS; j++)
            SetMonData(&gEnemyParty[monPartyId], MON_DATA_HP_EV + j, &sFrontierBrainsMons[facility][symbol][i].evs[j]);
        friendship = MAX_FRIENDSHIP;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            SetMonMoveSlot(&gEnemyParty[monPartyId], sFrontierBrainsMons[facility][symbol][i].moves[j], j);
            if (sFrontierBrainsMons[facility][symbol][i].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;
        }
        SetMonData(&gEnemyParty[monPartyId], MON_DATA_FRIENDSHIP, &friendship);
        CalculateMonStats(&gEnemyParty[monPartyId]);
        monPartyId++;
    }
}

void CreateFrontierGymLeaderPokemon(u16 trainerId)
{
    s32 i, j, k = 0;
    //s32 selectedMonBits;
    s32 monPartyId;
    s32 monLevel = 0;
    u8 friendship;
    u8 partysize = 3;
    u16 randomOrdering[4] = {99};

    if(VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        partysize = 4;

    if(VarGet(VAR_PWT_MODE) == PWT_MODE_WORLD_LEADERS)
        k = 1;

    randomOrdering[0] = 0;
    for (i = 1; i < partysize; i++)
    {
        randomOrdering[i] = (Random() % 5) + 1;

        // Loop through all the numbers generated so far.
        for (j = 0; j < i; j++)
        {
            if (randomOrdering[i] == randomOrdering[j])
            {
                // This number isn't unique; try generating again.
                i--;
                break;
            }
        }
    }

    ZeroEnemyPartyMons();
    monPartyId = 0;
    monLevel = SetFacilityPtrsGetLevel();
    for (i = 0; i < partysize; i++)
    {
        do
        {
            do
            {
                j = Random32(); //should just be one while loop, but that doesn't match
            } while (IsShinyOtIdPersonality(FRONTIER_BRAIN_OTID, j));
        } while (sFrontierGymLeaderMons[trainerId][k][randomOrdering[i]].nature != GetNatureFromPersonality(j));
        CreateMon(&gEnemyParty[monPartyId],
                  sFrontierGymLeaderMons[trainerId][k][randomOrdering[i]].species,
                  monLevel,
                  sFrontierGymLeaderMons[trainerId][k][randomOrdering[i]].fixedIV,
                  TRUE, j,
                  OT_ID_PRESET, FRONTIER_BRAIN_OTID);
        SetMonData(&gEnemyParty[monPartyId], MON_DATA_HELD_ITEM, &sFrontierGymLeaderMons[trainerId][k][randomOrdering[i]].heldItem);
        for (j = 0; j < NUM_STATS; j++)
            SetMonData(&gEnemyParty[monPartyId], MON_DATA_HP_EV + j, &sFrontierGymLeaderMons[trainerId][k][randomOrdering[i]].evs[j]);
        friendship = MAX_FRIENDSHIP;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            SetMonMoveSlot(&gEnemyParty[monPartyId], sFrontierGymLeaderMons[trainerId][k][randomOrdering[i]].moves[j], j);
            if (sFrontierGymLeaderMons[trainerId][k][randomOrdering[i]].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;
        }
        SetMonData(&gEnemyParty[monPartyId], MON_DATA_FRIENDSHIP, &friendship);
        CalculateMonStats(&gEnemyParty[monPartyId]);
        monPartyId++;

    }
}

void CreateFrontierChampionPokemon(u16 trainerId)
{
    s32 i, j;
    //s32 selectedMonBits;
    s32 monPartyId;
    s32 monLevel = 0;
    u8 friendship;
    u8 partysize = 3;
    u16 randomOrdering[4] = {99};

    if(VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        partysize = 4;

    randomOrdering[0] = 0;
    for (i = 1; i < partysize; i++)
    {
        randomOrdering[i] = (Random() % 5) + 1;

        // Loop through all the numbers generated so far.
        for (j = 0; j < i; j++)
        {
            if (randomOrdering[i] == randomOrdering[j])
            {
                // This number isn't unique; try generating again.
                i--;
                break;
            }
        }
    }

    ZeroEnemyPartyMons();
    monPartyId = 0;
    monLevel = SetFacilityPtrsGetLevel();
    for (i = 0; i < partysize; i++)
    {
        do
        {
            do
            {
                j = Random32(); //should just be one while loop, but that doesn't match
            } while (IsShinyOtIdPersonality(FRONTIER_BRAIN_OTID, j));
        } while (sFrontierChampionMons[trainerId][randomOrdering[i]].nature != GetNatureFromPersonality(j));
        CreateMon(&gEnemyParty[monPartyId],
                  sFrontierChampionMons[trainerId][randomOrdering[i]].species,
                  monLevel,
                  sFrontierChampionMons[trainerId][randomOrdering[i]].fixedIV,
                  TRUE, j,
                  OT_ID_PRESET, FRONTIER_BRAIN_OTID);
        SetMonData(&gEnemyParty[monPartyId], MON_DATA_HELD_ITEM, &sFrontierChampionMons[trainerId][randomOrdering[i]].heldItem);
        for (j = 0; j < NUM_STATS; j++)
            SetMonData(&gEnemyParty[monPartyId], MON_DATA_HP_EV + j, &sFrontierChampionMons[trainerId][randomOrdering[i]].evs[j]);
        friendship = MAX_FRIENDSHIP;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            SetMonMoveSlot(&gEnemyParty[monPartyId], sFrontierChampionMons[trainerId][randomOrdering[i]].moves[j], j);
            if (sFrontierChampionMons[trainerId][randomOrdering[i]].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;
        }
        SetMonData(&gEnemyParty[monPartyId], MON_DATA_FRIENDSHIP, &friendship);
        CalculateMonStats(&gEnemyParty[monPartyId]);
        monPartyId++;

    }
}

u16 GetFrontierBrainMonSpecies(u8 monId)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    return sFrontierBrainsMons[facility][symbol][monId].species;
}
/*
u16 GetFrontierGymLeaderMonSpecies(u16 trainerId, u8 monId)
{
    return sFrontierGymLeaderMons[trainerId][monId].species;
}*/

void SetFrontierBrainObjEventGfx(u8 facility)
{
    gTrainerBattleOpponent_A = TRAINER_FRONTIER_BRAIN;
    VarSet(VAR_OBJ_GFX_ID_0, sFrontierBrainObjEventGfx[facility][0]);
}

u16 GetFrontierBrainMonMove(u8 monId, u8 moveSlotId)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    return sFrontierBrainsMons[facility][symbol][monId].moves[moveSlotId];
}

u8 GetFrontierBrainMonNature(u8 monId)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    return sFrontierBrainsMons[facility][symbol][monId].nature;
}

u8 GetFrontierBrainMonEvs(u8 monId, u8 evStatId)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    return sFrontierBrainsMons[facility][symbol][monId].evs[evStatId];
}

s32 GetFronterBrainSymbol(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetPlayerSymbolCountForFacility(facility);

    if (symbol == 2)
    {
        u16 winStreak = GetCurrentFacilityWinStreak();
        if (winStreak + sFrontierBrainStreakAppearances[facility][3] == sFrontierBrainStreakAppearances[facility][0])
            symbol = 0;
        else if (winStreak + sFrontierBrainStreakAppearances[facility][3] == sFrontierBrainStreakAppearances[facility][1])
            symbol = 1;
        else if (winStreak + sFrontierBrainStreakAppearances[facility][3] > sFrontierBrainStreakAppearances[facility][1]
                 && (winStreak + sFrontierBrainStreakAppearances[facility][3] - sFrontierBrainStreakAppearances[facility][1]) % sFrontierBrainStreakAppearances[facility][2] == 0)
            symbol = 1;
    }
    return symbol;
}

// Called for intro speech as well despite the fact that its handled in the map scripts files instead
static void CopyFrontierBrainText(bool8 playerWonText)
{
    s32 facility;
    s32 symbol;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
    {
        facility = GetRecordedBattleFrontierFacility();
        symbol = GetRecordedBattleFronterBrainSymbol();
    }
    else
    {
        facility = VarGet(VAR_FRONTIER_FACILITY);
        symbol = GetFronterBrainSymbol();
    }

    switch (playerWonText)
    {
    case FALSE:
        StringCopy(gStringVar4, sFrontierBrainPlayerLostTexts[symbol][facility]);
        break;
    case TRUE:
        StringCopy(gStringVar4, sFrontierBrainPlayerWonTexts[symbol][facility]);
        break;
    }
}
