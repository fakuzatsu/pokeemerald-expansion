#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_LIGHT_OF_RUIN].effect == EFFECT_MEGA_DOUBLE_DMG);
}

SINGLE_BATTLE_TEST("Mega Pokemon take double damage from Light of Ruin", s16 damage)
{
    bool32 megaEvolved;
    PARAMETRIZE { megaEvolved = FALSE; }
    PARAMETRIZE { megaEvolved = TRUE; }
    GIVEN {
        PLAYER(SPECIES_BEEDRILL) { Item(ITEM_BEEDRILLITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, megaEvolve: megaEvolved); MOVE(opponent, MOVE_LIGHT_OF_RUIN); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}
