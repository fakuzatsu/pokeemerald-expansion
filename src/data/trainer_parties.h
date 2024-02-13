static const struct TrainerMon sParty_Sawyer1[] = {
    {
    .lvl = 24,
    .species = SPECIES_GEODUDE,
    }
};

static const struct TrainerMon sParty_GruntAquaHideout1[] = {
    {
    .lvl = 35,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_GruntAquaHideout2[] = {
    {
    .lvl = 35,
    .species = SPECIES_GOLBAT,
    },
    {
    .lvl = 35,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_GruntAquaHideout3[] = {
    {
    .lvl = 36,
    .species = SPECIES_GOLBAT,
    }
};

static const struct TrainerMon sParty_GruntAquaHideout4[] = {
    {
    .lvl = 36,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_GruntSeafloorCavern1[] = {
    {
    .lvl = 41,
    .species = SPECIES_MUK,
    }
};

static const struct TrainerMon sParty_GruntSeafloorCavern2[] = {
    {
    .lvl = 42,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_GruntSeafloorCavern3[] = {
    #ifdef CANON_MODE
    {
    .lvl = 42,
    .species = SPECIES_GOLBAT,
    }
    #else // CANON_MODE
    {
    .lvl = 42,
    .species = SPECIES_WISHIWASHI,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Gabrielle1[] = {
    {
    .lvl = 29,
    .species = SPECIES_SKITTY,
    },
    {
    .lvl = 29,
    .species = SPECIES_POOCHYENA,
    },
    {
    .lvl = 29,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .lvl = 29,
    .species = SPECIES_LOTAD,
    },
    {
    .lvl = 29,
    .species = SPECIES_SEEDOT,
    },
    {
    .lvl = 29,
    .species = SPECIES_TAILLOW,
    }
};

static const struct TrainerMon sParty_GruntPetalburgWoods[] = {
    {
    .lvl = 10,
    .species = SPECIES_POOCHYENA,
    }
};

static const struct TrainerMon sParty_Marcel[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 32,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 32,
    .species = SPECIES_SHIFTRY,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 32,
    .species = SPECIES_FLETCHINDER,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 32,
    .species = SPECIES_MAWILE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Alberto[] = {
    #ifdef CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_PELIPPER,
    },
    {
    .lvl = 33,
    .species = SPECIES_XATU,
    }
    #else // CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_PELIPPER,
    },
    {
    .lvl = 33,
    .species = SPECIES_HONCHKROW,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Ed[] = {
    #ifdef CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_ZANGOOSE,
    },
    {
    .lvl = 33,
    .species = SPECIES_SEVIPER,
    }
    #else // CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_PURUGLY,
    },
    {
    .lvl = 33,
    .species = SPECIES_SKUNTANK,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_GruntSeafloorCavern4[] = {
    {
    .lvl = 43,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Declan[] = {
    #ifdef CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_GYARADOS,
    }
    #else // CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_WISHIWASHI,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_GruntRusturfTunnel[] = {
    {
    .lvl = 13,
    .species = SPECIES_POOCHYENA,
    }
};

static const struct TrainerMon sParty_GruntWeatherInst1[] = {
    {
    .lvl = 30,
    .species = SPECIES_GOLBAT,
    },
    {
    .lvl = 31,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_GruntWeatherInst2[] = {
    {
    .lvl = 31,
    .species = SPECIES_GRIMER,
    },
    {
    .lvl = 32,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_GruntWeatherInst3[] = {
    {
    .lvl = 31,
    .species = SPECIES_POOCHYENA,
    },
    {
    .lvl = 32,
    .species = SPECIES_GOLBAT,
    },
    {
    .lvl = 32,
    .species = SPECIES_CARVANHA,
    }
};

static const struct TrainerMon sParty_GruntMuseum1[] = {
    {
    .lvl = 17,
    .species = SPECIES_CARVANHA,
    }
};

static const struct TrainerMon sParty_GruntMuseum2[] = {
    #ifdef CANON_MODE
    {
    .lvl = 16,
    .species = SPECIES_ZUBAT,
    },
    {
    .lvl = 16,
    .species = SPECIES_CARVANHA,
    }
    #else // CANON_MODE
    {
    .lvl = 16,
    .species = SPECIES_WISHIWASHI,
    },
    {
    .lvl = 16,
    .species = SPECIES_CARVANHA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_GruntSpaceCenter1[] = {
    {
    .lvl = 36,
    .species = SPECIES_CAMERUPT,
    }
};

static const struct TrainerMon sParty_GruntMtPyre1[] = {
    {
    .lvl = 37,
    .species = SPECIES_GOLBAT,
    }
};

static const struct TrainerMon sParty_GruntMtPyre2[] = {
    {
    .lvl = 37,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_GruntMtPyre3[] = {
    {
    .lvl = 35,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .lvl = 35,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_GruntWeatherInst4[] = {
    {
    .lvl = 34,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_GruntAquaHideout5[] = {
    {
    .lvl = 36,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_GruntAquaHideout6[] = {
    {
    .lvl = 37,
    .species = SPECIES_GOLBAT,
    }
};

static const struct TrainerMon sParty_Fredrick[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 33,
    .species = SPECIES_MAKUHITA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 33,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Matt[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 39,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 40,
    .species = SPECIES_CROBAT,
    }
};

static const struct TrainerMon sParty_Zander[] = {
    #ifdef CANON_MODE
    {
    .lvl = 34,
    .species = SPECIES_HARIYAMA,
    }
    #else // CANON_MODE
    {
    .lvl = 34,
    .species = SPECIES_PANGORO,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_ShellyWeatherInstitute[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 34,
    .species = SPECIES_SHARPEDO,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 35,
    .species = SPECIES_MUK,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 36,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_ShellySeafloorCavern[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 43,
    .species = SPECIES_SHARPEDO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 44,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_Archie[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 46,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 46,
    .species = SPECIES_MUK,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 47,
    .species = SPECIES_CROBAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 48,
    .species = SPECIES_SHARPEDO,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 46,
    .species = SPECIES_WISHIWASHI,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 46,
    .species = SPECIES_MUK,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 47,
    .species = SPECIES_CROBAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 48,
    .species = SPECIES_SHARPEDO,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Leah[] = {
    {
    .lvl = 34,
    .species = SPECIES_SPOINK,
    }
};

static const struct TrainerMon sParty_Daisy[] = {
    #ifdef CANON_MODE
    {
    .lvl = 16,
    .species = SPECIES_SHROOMISH,
    },
    {
    .lvl = 16,
    .species = SPECIES_ROSELIA,
    }
    #else // CANON_MODE
    {
    .lvl = 16,
    .species = SPECIES_PETILIL,
    },
    {
    .lvl = 16,
    .species = SPECIES_ROSELIA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Rose1[] = {
    {
    .lvl = 16,
    .species = SPECIES_ROSELIA,
    },
    {
    .lvl = 16,
    .species = SPECIES_SHROOMISH,
    },
    {
    .lvl = 17,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Felix[] = {
    #ifdef CANON_MODE
    {
    .lvl = 54,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_NONE, MOVE_NONE, MOVE_NONE}
    },
    {
    .lvl = 56,
    .species = SPECIES_CLAYDOL,
    .moves = {MOVE_SKILL_SWAP, MOVE_EARTHQUAKE, MOVE_NONE, MOVE_NONE}
    }
    #else // CANON_MODE
    {
    .lvl = 54,
    .species = SPECIES_GOTHITELLE,
    .moves = {MOVE_PSYCHIC, MOVE_NONE, MOVE_NONE, MOVE_NONE}
    },
    {
    .lvl = 56,
    .species = SPECIES_CLAYDOL,
    .moves = {MOVE_SKILL_SWAP, MOVE_EARTHQUAKE, MOVE_NONE, MOVE_NONE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Violet[] = {
    {
    .lvl = 29,
    .species = SPECIES_ROSELIA,
    },
    {
    .lvl = 29,
    .species = SPECIES_GLOOM,
    }
};

static const struct TrainerMon sParty_Rose2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Rose3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Rose4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Rose5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Dusty1[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 26,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_Chip[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 30,
    .species = SPECIES_BALTOY,
    .moves = {MOVE_PSYBEAM, MOVE_SELF_DESTRUCT, MOVE_SANDSTORM, MOVE_ANCIENT_POWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 30,
    .species = SPECIES_SANDSHREW,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 30,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_Foster[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 28,
    .species = SPECIES_SANDSHREW,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 28,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_Dusty2[] = {
    {
    .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
    .lvl = 30,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_Dusty3[] = {
    {
    .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
    .lvl = 33,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_Dusty4[] = {
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 36,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_Dusty5[] = {
    {
    .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
    .lvl = 39,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_GabbyAndTy1[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 19,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 19,
    .species = SPECIES_WHISMUR,
    }
};

static const struct TrainerMon sParty_GabbyAndTy2[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 30,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 30,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_GabbyAndTy3[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 33,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 33,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_GabbyAndTy4[] = {
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 36,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 36,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_GabbyAndTy5[] = {
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 39,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 39,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_GabbyAndTy6[] = {
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 42,
    .species = SPECIES_MAGNETON,
    .moves = {MOVE_SONIC_BOOM, MOVE_THUNDER_WAVE, MOVE_METAL_SOUND, MOVE_THUNDERBOLT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 42,
    .species = SPECIES_EXPLOUD,
    .moves = {MOVE_ASTONISH, MOVE_STOMP, MOVE_SUPERSONIC, MOVE_HYPER_VOICE}
    }
};

static const struct TrainerMon sParty_Lola1[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 14,
    .species = SPECIES_AZURILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 14,
    .species = SPECIES_AZURILL,
    }
};

static const struct TrainerMon sParty_Austina[] = {
    {
    .lvl = 29,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Gwen[] = {
    {
    .lvl = 29,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Lola2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_MARILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Lola3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_MARILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Lola4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_MARILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Lola5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_AZUMARILL,
    }
};

static const struct TrainerMon sParty_Ricky1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 15,
    .species = SPECIES_ZIGZAGOON,
    .moves = {MOVE_SAND_ATTACK, MOVE_HEADBUTT, MOVE_TAIL_WHIP, MOVE_SURF}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 15,
    .species = SPECIES_SANDYGAST,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Simon[] = {
    {
    .lvl = 14,
    .species = SPECIES_AZURILL,
    },
    {
    .lvl = 14,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Charlie[] = {
    {
    .lvl = 29,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Ricky2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 30,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_SAND_ATTACK, MOVE_PIN_MISSILE, MOVE_TAIL_WHIP, MOVE_SURF}
    }
};

static const struct TrainerMon sParty_Ricky3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 33,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_SAND_ATTACK, MOVE_PIN_MISSILE, MOVE_TAIL_WHIP, MOVE_SURF}
    }
};

static const struct TrainerMon sParty_Ricky4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 36,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_SAND_ATTACK, MOVE_PIN_MISSILE, MOVE_TAIL_WHIP, MOVE_SURF}
    }
};

static const struct TrainerMon sParty_Ricky5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 39,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_SAND_ATTACK, MOVE_PIN_MISSILE, MOVE_TAIL_WHIP, MOVE_SURF}
    }
};

static const struct TrainerMon sParty_Randall[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 33,
    .species = SPECIES_SWELLOW,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_QUICK_ATTACK, MOVE_AGILITY, MOVE_WING_ATTACK, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Parker[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 33,
    .species = SPECIES_SPINDA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TEETER_DANCE, MOVE_DIZZY_PUNCH, MOVE_FOCUS_PUNCH, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_George[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 32,
    .species = SPECIES_SLAKOTH,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SLACK_OFF, MOVE_COUNTER, MOVE_SHADOW_BALL, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Berke[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 33,
    .species = SPECIES_VIGOROTH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FOCUS_ENERGY, MOVE_SLASH, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Braxton[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 31,
    .species = SPECIES_SWELLOW,
    .moves = {MOVE_FOCUS_ENERGY, MOVE_QUICK_ATTACK, MOVE_WING_ATTACK, MOVE_ENDEAVOR}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 31,
    .species = SPECIES_TRAPINCH,
    .moves = {MOVE_BITE, MOVE_DIG, MOVE_FEINT_ATTACK, MOVE_SAND_TOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 31,
    .species = SPECIES_WAILMER,
    .moves = {MOVE_ROLLOUT, MOVE_WHIRLPOOL, MOVE_ASTONISH, MOVE_WATER_PULSE}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 31,
    .species = SPECIES_MAGNETON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUPERSONIC, MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 31,
    .species = SPECIES_SHIFTRY,
    .moves = {MOVE_GIGA_DRAIN, MOVE_FEINT_ATTACK, MOVE_FAKE_OUT, MOVE_SWAGGER}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 31,
    .species = SPECIES_TRANQUILL,
    .moves = {MOVE_FOCUS_ENERGY, MOVE_QUICK_ATTACK, MOVE_WING_ATTACK, MOVE_ENDEAVOR}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 31,
    .species = SPECIES_TRAPINCH,
    .moves = {MOVE_BITE, MOVE_DIG, MOVE_FEINT_ATTACK, MOVE_SAND_TOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 31,
    .species = SPECIES_WAILMER,
    .moves = {MOVE_ROLLOUT, MOVE_WHIRLPOOL, MOVE_ASTONISH, MOVE_WATER_PULSE}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 31,
    .species = SPECIES_TOXTRICITY,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUPERSONIC, MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 31,
    .species = SPECIES_SHIFTRY,
    .moves = {MOVE_GIGA_DRAIN, MOVE_FEINT_ATTACK, MOVE_FAKE_OUT, MOVE_SWAGGER}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Vincent[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 48,
    .species = SPECIES_SABLEYE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 48,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 48,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Leroy[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 50,
    .species = SPECIES_MAWILE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 50,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Wilton1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_MAKUHITA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_LUXIO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_MIENFOO,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Edgar[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_CACTURNE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_PELIPPER,
    }
};

static const struct TrainerMon sParty_Albert[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 53,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_MUK,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 53,
    .species = SPECIES_TOXTRICITY,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_MUK,
    }
    #endif // CANON_MODE  
};

static const struct TrainerMon sParty_Samuel[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 53,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_MAWILE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_KADABRA,
    }
};

static const struct TrainerMon sParty_Vito[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_DODRIO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_ELECTRODE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_SHIFTRY,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_DODRIO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_PYROAR,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_SHIFTRY,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Owen[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_KECLEON,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_GOLEM,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_WAILORD,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_SCYTHER,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_GOLEM,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_WAILORD,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Wilton2[] = {
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Wilton3[] = {
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Wilton4[] = {
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Wilton5[] = {
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 38,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 38,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 38,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Warren[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 36,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 36,
    .species = SPECIES_LUDICOLO,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 36,
    .species = SPECIES_BARBARACLE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 36,
    .species = SPECIES_LUDICOLO,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Mary[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 32,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FEINT_ATTACK, MOVE_SHOCK_WAVE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Alexia[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 33,
    .species = SPECIES_WIGGLYTUFF,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DEFENSE_CURL, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Jody[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 33,
    .species = SPECIES_ZANGOOSE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_SLASH, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Wendy[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 32,
    .species = SPECIES_MAWILE,
    .moves = {MOVE_BATON_PASS, MOVE_FEINT_ATTACK, MOVE_FAKE_TEARS, MOVE_BITE}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 32,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_MEGA_DRAIN, MOVE_MAGICAL_LEAF, MOVE_GRASS_WHISTLE, MOVE_LEECH_SEED}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 32,
    .species = SPECIES_PELIPPER,
    .moves = {MOVE_FLY, MOVE_WATER_GUN, MOVE_MIST, MOVE_PROTECT}
    }
};

static const struct TrainerMon sParty_Keira[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 50,
    .species = SPECIES_LAIRON,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 50,
    .species = SPECIES_MANECTRIC,
    }
};

static const struct TrainerMon sParty_Brooke1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_ROSELIA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_DRIFLOON,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_FLOETTE_ORANGE_FLOWER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jennifer[] = {
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 33,
    .species = SPECIES_SABLEYE,
    }
};

static const struct TrainerMon sParty_Hope[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Shannon[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_CLAYDOL,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_FLORGES,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Michelle[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_TORKOAL,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_LUDICOLO,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_TORKOAL,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_LUCARIO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_GIGALITH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Caroline[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_SKARMORY,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_SABLEYE,
    }
};

static const struct TrainerMon sParty_Julie[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_SANDSLASH,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_NINETALES,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_TROPIUS,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_SANDSLASH,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_NINETALES,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_SHIINOTIC,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brooke2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_ROSELIA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_DRIFLOON,
    },
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_FLORGES_ORANGE_FLOWER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brooke3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_ROSELIA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_DRIFBLIM,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_FLORGES_ORANGE_FLOWER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brooke4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_ROSELIA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_DRIFBLIM,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_CAMERUPT,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_FLORGES_ORANGE_FLOWER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brooke5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 37,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 37,
    .species = SPECIES_CAMERUPT,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 37,
    .species = SPECIES_ROSELIA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 37,
    .species = SPECIES_DRIFBLIM,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 37,
    .species = SPECIES_CAMERUPT,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 37,
    .species = SPECIES_FLORGES_ORANGE_FLOWER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Patricia[] = {
    {
    .lvl = 45,
    .species = SPECIES_BANETTE,
    },
    {
    .lvl = 45,
    .species = SPECIES_LUNATONE,
    }
};

static const struct TrainerMon sParty_Kindra[] = {
    #ifdef CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_DUSKULL,
    },
    {
    .lvl = 33,
    .species = SPECIES_SHUPPET,
    }
    #else // CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_MIMIKYU,
    },
    {
    .lvl = 33,
    .species = SPECIES_SHUPPET,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Tammy[] = {
    {
    .lvl = 32,
    .species = SPECIES_DUSKULL,
    },
    {
    .lvl = 32,
    .species = SPECIES_SHUPPET,
    }
};

static const struct TrainerMon sParty_Valerie1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 35,
    .species = SPECIES_SABLEYE,
    }
    #else // CANON_MODE
    {
    .lvl = 35,
    .species = SPECIES_POLTEAGEIST,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Tasha[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 35,
    .species = SPECIES_SHUPPET,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 35,
    .species = SPECIES_MIMIKYU,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Valerie2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 35,
    .species = SPECIES_SABLEYE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 35,
    .species = SPECIES_SPOINK,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 35,
    .species = SPECIES_POLTEAGEIST,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 35,
    .species = SPECIES_LAMPENT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Valerie3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 38,
    .species = SPECIES_SPOINK,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 38,
    .species = SPECIES_SABLEYE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 38,
    .species = SPECIES_POLTEAGEIST,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 38,
    .species = SPECIES_CHANDELURE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Valerie4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 44,
    .species = SPECIES_SPOINK,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 44,
    .species = SPECIES_SABLEYE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 44,
    .species = SPECIES_POLTEAGEIST,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 44,
    .species = SPECIES_CHANDELURE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Valerie5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 46,
    .species = SPECIES_DUSKULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 46,
    .species = SPECIES_SABLEYE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 46,
    .species = SPECIES_GRUMPIG,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 46,
    .species = SPECIES_POLTEAGEIST,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 46,
    .species = SPECIES_CHANDELURE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 46,
    .species = SPECIES_AEGISLASH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Cindy1[] = {
    {
    .lvl = 8,
    .species = SPECIES_ZIGZAGOON,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Daphne[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_LUVDISC,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_ATTRACT, MOVE_SWEET_KISS, MOVE_FLAIL, MOVE_WATER_PULSE}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_LUVDISC,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_ATTRACT, MOVE_SAFEGUARD, MOVE_TAKE_DOWN, MOVE_WATER_PULSE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_GOREBYSS,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_ATTRACT, MOVE_SWEET_KISS, MOVE_FLAIL, MOVE_WATER_PULSE}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_HUNTAIL,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_ATTRACT, MOVE_SAFEGUARD, MOVE_TAKE_DOWN, MOVE_WATER_PULSE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_GruntSpaceCenter2[] = {
    {
    .lvl = 31,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .lvl = 32,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .lvl = 34,
    .species = SPECIES_CAMERUPT,
    }
};

static const struct TrainerMon sParty_Cindy2[] = {
    {
    .lvl = 12,
    .species = SPECIES_ZIGZAGOON,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Brianna[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 53,
    .species = SPECIES_SEAKING,
    .heldItem = ITEM_NUGGET
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 53,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NUGGET
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Naomi[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 50,
    .species = SPECIES_ROSELIA,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Cindy3[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 30,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Cindy4[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 33,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Cindy5[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 36,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Cindy6[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 39,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_FURY_SWIPES, MOVE_MUD_SPORT, MOVE_ODOR_SLEUTH, MOVE_SAND_ATTACK}
    }
};

static const struct TrainerMon sParty_Melissa[] = {
    {
    .lvl = 24,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Sheila[] = {
    {
    .lvl = 24,
    .species = SPECIES_SHROOMISH,
    }
};

static const struct TrainerMon sParty_Shirley[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 39,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 39,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 39,
    .species = SPECIES_SCEPTILE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 39,
    .species = SPECIES_SERPERIOR,
    }
};

static const struct TrainerMon sParty_Lydia[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 9,
    .species = SPECIES_ELDEGOSS,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 41,
    .species = SPECIES_ROSERADE,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 41,
    .species = SPECIES_RILLABOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 41,
    .species = SPECIES_CHESNAUGHT,
    }
};

static const struct TrainerMon sParty_Lisla[] = {
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 54,
    .species = SPECIES_VILEPLUME,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 54,
    .species = SPECIES_EXEGGUTOR_ALOLAN,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 54,
    .species = SPECIES_INTELEON,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 54,
    .species = SPECIES_PRIMARINA,
    }
};

static const struct TrainerMon sParty_Teach[] = {
    {
    .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
    .lvl = 18,
    .species = SPECIES_CHATOT,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 18,
    .species = SPECIES_DHELMISE,
    }
};

static const struct TrainerMon sParty_Jessica1[] = {
    {
    .lvl = 32,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_BIND, MOVE_LICK, MOVE_FURY_SWIPES, MOVE_FEINT_ATTACK}
    },
    {
    .lvl = 32,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_TAIL, MOVE_SCREECH, MOVE_GLARE, MOVE_CRUNCH}
    }
};

static const struct TrainerMon sParty_Connie[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_GOLDEEN,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_MARILL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Bridget[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 54,
    .species = SPECIES_AZUMARILL,
    }
};

static const struct TrainerMon sParty_Olivia[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 53,
    .species = SPECIES_CLAMPERL,
    .moves = {MOVE_IRON_DEFENSE, MOVE_WHIRLPOOL, MOVE_RAIN_DANCE, MOVE_WATER_PULSE}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_CORPHISH,
    .moves = {MOVE_TAUNT, MOVE_CRABHAMMER, MOVE_WATER_PULSE, MOVE_NONE}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_LOMBRE,
    .moves = {MOVE_UPROAR, MOVE_FURY_SWIPES, MOVE_FAKE_OUT, MOVE_WATER_PULSE}
    }
};

static const struct TrainerMon sParty_Tiffany[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 52,
    .species = SPECIES_CARVANHA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 52,
    .species = SPECIES_SHARPEDO,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 52,
    .species = SPECIES_WIMPOD,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 52,
    .species = SPECIES_SHARPEDO,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jessica2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 38,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_BIND, MOVE_LICK, MOVE_FURY_SWIPES, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 38,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_TAIL, MOVE_SCREECH, MOVE_GLARE, MOVE_CRUNCH}
    }
};

static const struct TrainerMon sParty_Jessica3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 41,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_BIND, MOVE_LICK, MOVE_FURY_SWIPES, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 41,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_TAIL, MOVE_SCREECH, MOVE_GLARE, MOVE_CRUNCH}
    }
};

static const struct TrainerMon sParty_Jessica4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_BIND, MOVE_LICK, MOVE_FURY_SWIPES, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_TAIL, MOVE_SCREECH, MOVE_GLARE, MOVE_CRUNCH}
    }
};

static const struct TrainerMon sParty_Jessica5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 48,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_BIND, MOVE_LICK, MOVE_FURY_SWIPES, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 48,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_TAIL, MOVE_SCREECH, MOVE_GLARE, MOVE_CRUNCH}
    }
};

static const struct TrainerMon sParty_Winston1[] = {
    {
    .lvl = 8,
    .species = SPECIES_ZIGZAGOON,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Mollie[] = {
    {
    .lvl = 36,
    .species = SPECIES_WHISCASH,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 36,
    .species = SPECIES_MEDITITE,
    }
};

static const struct TrainerMon sParty_Garret[] = {
    {
    .lvl = 50,
    .species = SPECIES_AZUMARILL,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Winston2[] = {
    {
    .lvl = 30,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Winston3[] = {
    {
    .lvl = 33,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Winston4[] = {
    {
    .lvl = 36,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Winston5[] = {
    {
    .lvl = 39,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_FURY_SWIPES, MOVE_MUD_SPORT, MOVE_ODOR_SLEUTH, MOVE_SAND_ATTACK}
    }
};

static const struct TrainerMon sParty_Steve1[] = {
    {
    .lvl = 22,
    .species = SPECIES_ARON,
    }
};

static const struct TrainerMon sParty_Thalia1[] = {
    {
    .lvl = 28,
    .species = SPECIES_WAILMER,
    },
    {
    .lvl = 28,
    .species = SPECIES_HORSEA,
    }
};

static const struct TrainerMon sParty_Mark[] = {
    #ifdef CANON_MODE
    {
    .lvl = 34,
    .species = SPECIES_RHYHORN,
    }
    #else // CANON_MODE
    {
    .lvl = 34,
    .species = SPECIES_TOGETIC,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_GruntMtChimney1[] = {
    {
    .lvl = 25,
    .species = SPECIES_NUMEL,
    }
};

static const struct TrainerMon sParty_Steve2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 30,
    .species = SPECIES_LAIRON,
    }
};

static const struct TrainerMon sParty_Steve3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_LAIRON,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_RHYHORN,
    }
};

static const struct TrainerMon sParty_Steve4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_LAIRON,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_RHYHORN,
    }
};

static const struct TrainerMon sParty_Steve5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_AGGRON,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_RHYDON,
    }
};

static const struct TrainerMon sParty_Luis[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_CARVANHA,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_FRILLISH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Dominik[] = {
    {
    .lvl = 29,
    .species = SPECIES_TENTACOOL,
    }
};

static const struct TrainerMon sParty_Douglas[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_TENTACOOL,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_STARYU,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_TENTACOOL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Darrin[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_TENTACOOL,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_BASCULIN_BLUE_STRIPED,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_TENTACOOL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Tony1[] = {
    {
    .lvl = 29,
    .species = SPECIES_CARVANHA,
    }
};

static const struct TrainerMon sParty_Jerome[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_TENTACRUEL,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_FRILLISH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Matthew[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_CARVANHA,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_SHELLOS_WEST_SEA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_David[] = {
    {
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 28,
    .species = SPECIES_CARVANHA,
    }
};

static const struct TrainerMon sParty_Spencer[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 36,
    .species = SPECIES_WINGULL,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_SHELLOS_EAST_SEA,
    },
    {
    .lvl = 36,
    .species = SPECIES_WINGULL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Roland[] = {
    #ifdef CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_CARVANHA,
    }
    #else // CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_SWANNA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nolen[] = {
    #ifdef CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_TENTACRUEL,
    }
    #else // CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_GASTRODON_EAST_SEA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Stan[] = {
    {
    .lvl = 37,
    .species = SPECIES_HORSEA,
    }
};

static const struct TrainerMon sParty_Barry[] = {
    {
    .lvl = 37,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Dean[] = {
    #ifdef CANON_MODE
    {
    .lvl = 34,
    .species = SPECIES_CARVANHA,
    },
    {
    .lvl = 34,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 34,
    .species = SPECIES_CARVANHA,
    }
    #else // CANON_MODE
    {
    .lvl = 34,
    .species = SPECIES_CARVANHA,
    },
    {
    .lvl = 34,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 34,
    .species = SPECIES_WISHIWASHI,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Rodney[] = {
    {
    .lvl = 37,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Richard[] = {
    {
    .lvl = 37,
    .species = SPECIES_PELIPPER,
    }
};

static const struct TrainerMon sParty_Herman[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 36,
    .species = SPECIES_TENTACRUEL,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_MANTINE,
    },
    {
    .lvl = 36,
    .species = SPECIES_TENTACRUEL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Santiago[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .lvl = 36,
    .species = SPECIES_WAILMER,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .lvl = 36,
    .species = SPECIES_WISHIWASHI,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Gilbert[] = {
    {
    .lvl = 37,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Franklin[] = {
    #ifdef CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_SEALEO,
    }
    #else // CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_LUMINEON,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Kevin[] = {
    {
    .lvl = 37,
    .species = SPECIES_SPHEAL,
    }
};

static const struct TrainerMon sParty_Jack[] = {
    {
    .lvl = 37,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Dudley[] = {
    {
    .lvl = 36,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 36,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 36,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Chad[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 36,
    .species = SPECIES_WAILMER,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_ALOMOMOLA,
    },
    {
    .lvl = 36,
    .species = SPECIES_WAILMER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Tony2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Tony3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Tony4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_STARYU,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Tony5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_STARMIE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 42,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Takao[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 18,
    .species = SPECIES_MACHOP,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 18,
    .species = SPECIES_PANCHAM,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Hitoshi[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 35,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 35,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Kiyo[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 37,
    .species = SPECIES_HARIYAMA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 37,
    .species = SPECIES_PANGORO,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Koichi[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 27,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 31,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Nob1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 22,
    .species = SPECIES_MACHOP,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 22,
    .species = SPECIES_CROAGUNK,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nob2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 30,
    .species = SPECIES_MACHOKE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 30,
    .species = SPECIES_TOXICROAK,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nob3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_MACHOKE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_TOXICROAK,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_MACHOKE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nob4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 34,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 34,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 34,
    .species = SPECIES_MACHOKE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_TOXICROAK,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_MACHOKE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nob5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 36,
    .species = SPECIES_MACHOP,
    .heldItem = ITEM_NONE
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 36,
    .species = SPECIES_MACHOKE,
    .heldItem = ITEM_NONE
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 36,
    .species = SPECIES_MACHOKE,
    .heldItem = ITEM_NONE
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 36,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_BLACK_BELT
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 36,
    .species = SPECIES_TOXICROAK,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 36,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_BLACK_BELT
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Yuji[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_MAKUHITA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Daisuke[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 22,
    .species = SPECIES_MACHOP,
    }
};

static const struct TrainerMon sParty_Atsushi[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_HARIYAMA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_MIENSHAO,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Kirk[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_ELECTRIKE,
    .moves = {MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_SPARK, MOVE_LEER}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 25,
    .species = SPECIES_VOLTORB,
    .moves = {MOVE_CHARGE, MOVE_SHOCK_WAVE, MOVE_SCREECH, MOVE_NONE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_ELECTRIKE,
    .moves = {MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_SPARK, MOVE_LEER}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 25,
    .species = SPECIES_SHINX,
    .moves = {MOVE_CHARGE, MOVE_SHOCK_WAVE, MOVE_SCREECH, MOVE_NONE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_GruntAquaHideout7[] = {
    {
    .lvl = 35,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .lvl = 36,
    .species = SPECIES_GOLBAT,
    }
};

static const struct TrainerMon sParty_GruntAquaHideout8[] = {
    {
    .lvl = 37,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Shawn[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_VOLTORB,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 25,
    .species = SPECIES_MAGNEMITE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_SHINX,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 25,
    .species = SPECIES_MAGNEMITE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Fernando1[] = {
    {
    .lvl = 33,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .lvl = 33,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_Dalton1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 17,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .lvl = 17,
    .species = SPECIES_WHISMUR,
    }
    #else // CANON_MODE
    {
    .lvl = 17,
    .species = SPECIES_YAMPER,
    },
    {
    .lvl = 17,
    .species = SPECIES_TOXEL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Dalton2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_WHISMUR,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_MAGNEMITE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_TOXEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_WHISMUR,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Dalton3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_MAGNEMITE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_TOXTRICITY,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_LOUDRED,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Dalton4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_LOUDRED,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_TOXTRICITY,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_LOUDRED,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Dalton5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_EXPLOUD,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_MAGNETON,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_TOXTRICITY,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_EXPLOUD,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Cole[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_NUMEL,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_DARUMAKA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jeff[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 28,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 28,
    .species = SPECIES_SLUGMA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 28,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 28,
    .species = SPECIES_LITLEO,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Axle[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_NUMEL,
    }
};

static const struct TrainerMon sParty_Jace[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_SLUGMA,
    }
};

static const struct TrainerMon sParty_Keegan[] = {
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 29,
    .species = SPECIES_SLUGMA,
    }
};

static const struct TrainerMon sParty_Bernie1[] = {
    {
    .lvl = 20,
    .species = SPECIES_SLUGMA,
    },
    {
    .lvl = 20,
    .species = SPECIES_WINGULL,
    }
};

static const struct TrainerMon sParty_Bernie2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_WINGULL,
    }
};

static const struct TrainerMon sParty_Bernie3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_PELIPPER,
    }
};

static const struct TrainerMon sParty_Bernie4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_PELIPPER,
    }
};

static const struct TrainerMon sParty_Bernie5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_PELIPPER,
    }
};

static const struct TrainerMon sParty_Drew[] = {
    #ifdef CANON_MODE
    {
    .lvl = 26,
    .species = SPECIES_SANDSHREW,
    .moves = {MOVE_DIG, MOVE_SAND_ATTACK, MOVE_POISON_STING, MOVE_SLASH}
    }
    #else // CANON_MODE
    {
    .lvl = 25,
    .species = SPECIES_YAMASK,
    },
    {
    .lvl = 25,
    .species = SPECIES_SANDSHREW,
    .moves = {MOVE_DIG, MOVE_SAND_ATTACK, MOVE_POISON_STING, MOVE_SLASH}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Beau[] = {
    #ifdef CANON_MODE
    {
    .lvl = 24,
    .species = SPECIES_BALTOY,
    .moves = {MOVE_RAPID_SPIN, MOVE_MUD_SLAP, MOVE_PSYBEAM, MOVE_ROCK_TOMB}
    },
    {
    .lvl = 24,
    .species = SPECIES_SANDSHREW,
    .moves = {MOVE_POISON_STING, MOVE_SAND_ATTACK, MOVE_SCRATCH, MOVE_DIG}
    },
    {
    .lvl = 24,
    .species = SPECIES_BALTOY,
    .moves = {MOVE_RAPID_SPIN, MOVE_MUD_SLAP, MOVE_PSYBEAM, MOVE_ROCK_TOMB}
    }
    #else // CANON_MODE
    {
    .lvl = 24,
    .species = SPECIES_DWEBBLE,
    },
    {
    .lvl = 24,
    .species = SPECIES_SANDSHREW,
    .moves = {MOVE_POISON_STING, MOVE_SAND_ATTACK, MOVE_SCRATCH, MOVE_DIG}
    },
    {
    .lvl = 24,
    .species = SPECIES_BALTOY,
    .moves = {MOVE_RAPID_SPIN, MOVE_MUD_SLAP, MOVE_PSYBEAM, MOVE_ROCK_TOMB}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Larry[] = {
    {
    .lvl = 20,
    .species = SPECIES_NUZLEAF,
    }
};

static const struct TrainerMon sParty_Shane[] = {
    {
    .lvl = 20,
    .species = SPECIES_SANDSHREW,
    },
    {
    .lvl = 20,
    .species = SPECIES_NUZLEAF,
    }
};

static const struct TrainerMon sParty_Justin[] = {
    {
    .lvl = 27,
    .species = SPECIES_KECLEON,
    }
};

static const struct TrainerMon sParty_Ethan1[] = {
    {
    .lvl = 23,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .lvl = 23,
    .species = SPECIES_TAILLOW,
    }
};

static const struct TrainerMon sParty_Autumn[] = {
    #ifdef CANON_MODE
    {
    .lvl = 24,
    .species = SPECIES_SHROOMISH,
    }
    #else // CANON_MODE
    {
    .lvl = 24,
    .species = SPECIES_STEENEE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Travis[] = {
    {
    .lvl = 20,
    .species = SPECIES_SANDSHREW,
    }
};

static const struct TrainerMon sParty_Ethan2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_TAILLOW,
    }
};

static const struct TrainerMon sParty_Ethan3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Ethan4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_SANDSHREW,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_LINOONE,
    }
};

static const struct TrainerMon sParty_Ethan5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_SANDSLASH,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_LINOONE,
    }
};

static const struct TrainerMon sParty_Brent[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_SURSKIT,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_MASQUERAIN,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Donald[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 27,
    .species = SPECIES_WURMPLE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 27,
    .species = SPECIES_SILCOON,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 27,
    .species = SPECIES_BEAUTIFLY,
    }
};

static const struct TrainerMon sParty_Taylor[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 30,
    .species = SPECIES_WURMPLE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 30,
    .species = SPECIES_CASCOON,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 30,
    .species = SPECIES_DUSTOX,
    }
};

static const struct TrainerMon sParty_Jeffrey1[] = {
    {
    .lvl = 30,
    .species = SPECIES_SURSKIT,
    },
    {
    .lvl = 30,
    .species = SPECIES_SURSKIT,
    },
    {
    .lvl = 30,
    .species = SPECIES_SURSKIT,
    }
};

static const struct TrainerMon sParty_Derek[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 18,
    .species = SPECIES_DUSTOX,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 18,
    .species = SPECIES_BEAUTIFLY,
    }
};

static const struct TrainerMon sParty_Jeffrey2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_SURSKIT,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_SURSKIT,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_SURSKIT,
    }
};

static const struct TrainerMon sParty_Jeffrey3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 37,
    .species = SPECIES_SURSKIT,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 37,
    .species = SPECIES_SURSKIT,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 37,
    .species = SPECIES_MASQUERAIN,
    }
};

static const struct TrainerMon sParty_Jeffrey4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_SURSKIT,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_WURMPLE,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_SURSKIT,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_MASQUERAIN,
    }
};

static const struct TrainerMon sParty_Jeffrey5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 41,
    .species = SPECIES_SURSKIT,
    .heldItem = ITEM_NONE
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 41,
    .species = SPECIES_DUSTOX,
    .heldItem = ITEM_NONE
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 41,
    .species = SPECIES_SURSKIT,
    .heldItem = ITEM_NONE
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 41,
    .species = SPECIES_MASQUERAIN,
    .heldItem = ITEM_SILVER_POWDER
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 41,
    .species = SPECIES_BEAUTIFLY,
    .heldItem = ITEM_NONE
    }
};

static const struct TrainerMon sParty_Edward[] = {
    #ifdef CANON_MODE
    {
    .lvl = 17,
    .species = SPECIES_ABRA,
    .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE}
    }
    #else // CANON_MODE
    {
    .lvl = 17,
    .species = SPECIES_HATENNA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Preston[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 40,
    .species = SPECIES_GARDEVOIR,
    }
};

static const struct TrainerMon sParty_Virgil[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 41,
    .species = SPECIES_GARDEVOIR,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 41,
    .species = SPECIES_GALLADE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Blake[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 41,
    .species = SPECIES_GIRAFARIG,
    }
};

static const struct TrainerMon sParty_William[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_RALTS,
    },
    {
    .lvl = 29,
    .species = SPECIES_RALTS,
    },
    {
    .lvl = 29,
    .species = SPECIES_KIRLIA,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_MUNNA,
    },
    {
    .lvl = 29,
    .species = SPECIES_GOTHORITA,
    },
    {
    .lvl = 29,
    .species = SPECIES_KIRLIA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Joshua[] = {
    {
    .lvl = 45,
    .species = SPECIES_KADABRA,
    },
    {
    .lvl = 45,
    .species = SPECIES_SOLROCK,
    }
};

static const struct TrainerMon sParty_Cameron1[] = {
    {
    .lvl = 34,
    .species = SPECIES_SOLROCK,
    }
};

static const struct TrainerMon sParty_Cameron2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 36,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 36,
    .species = SPECIES_SOLROCK,
    }
};

static const struct TrainerMon sParty_Cameron3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 41,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 41,
    .species = SPECIES_SOLROCK,
    }
};

static const struct TrainerMon sParty_Cameron4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_SOLROCK,
    }
};

static const struct TrainerMon sParty_Cameron5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 50,
    .species = SPECIES_SOLROCK,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 50,
    .species = SPECIES_ALAKAZAM,
    }
};

static const struct TrainerMon sParty_Jaclyn[] = {
    {
    .lvl = 18,
    .species = SPECIES_ABRA,
    .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Hannah[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 41,
    .species = SPECIES_GARDEVOIR,
    }
};

static const struct TrainerMon sParty_Samantha[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 41,
    .species = SPECIES_XATU,
    }
};

static const struct TrainerMon sParty_Maura[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 40,
    .species = SPECIES_ALAKAZAM,
    }
};

static const struct TrainerMon sParty_Kayla[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_WOBBUFFET,
    },
    {
    .lvl = 29,
    .species = SPECIES_NATU,
    },
    {
    .lvl = 29,
    .species = SPECIES_KADABRA,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_WOBBUFFET,
    },
    {
    .lvl = 29,
    .species = SPECIES_HATENNA,
    },
    {
    .lvl = 29,
    .species = SPECIES_MUNNA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Alexis[] = {
    {
    .lvl = 45,
    .species = SPECIES_KIRLIA,
    },
    {
    .lvl = 45,
    .species = SPECIES_XATU,
    }
};

static const struct TrainerMon sParty_Jacki1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_KADABRA,
    },
    {
    .lvl = 33,
    .species = SPECIES_LUNATONE,
    }
    #else // CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_HATTREM,
    },
    {
    .lvl = 33,
    .species = SPECIES_KADABRA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jacki2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 37,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 37,
    .species = SPECIES_LUNATONE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 37,
    .species = SPECIES_HATTREM,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 37,
    .species = SPECIES_KADABRA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jacki3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 40,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 40,
    .species = SPECIES_LUNATONE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 40,
    .species = SPECIES_HATTREM,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 40,
    .species = SPECIES_KADABRA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jacki4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 44,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 44,
    .species = SPECIES_LUNATONE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 44,
    .species = SPECIES_HATTREM,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 44,
    .species = SPECIES_ALAKAZAM,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jacki5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_LUNATONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_ALAKAZAM,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_HATTERENE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_ALAKAZAM,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Walter1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 32,
    .species = SPECIES_MANECTRIC,
    }
    #else // CANON_MODE
    {
    .lvl = 32,
    .species = SPECIES_BOUFFALANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Micah[] = {
    {
    .lvl = 48,
    .species = SPECIES_MANECTRIC,
    },
    {
    .lvl = 48,
    .species = SPECIES_MANECTRIC,
    }
};

static const struct TrainerMon sParty_Thomas[] = {
    {
    .lvl = 50,
    .species = SPECIES_ZANGOOSE,
    }
};

static const struct TrainerMon sParty_Walter2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 37,
    .species = SPECIES_MANECTRIC,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 37,
    .species = SPECIES_BOUFFALANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Walter3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 39,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_ODOR_SLEUTH, MOVE_FURY_SWIPES}
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 39,
    .species = SPECIES_MANECTRIC,
    .moves = {MOVE_QUICK_ATTACK, MOVE_SPARK, MOVE_ODOR_SLEUTH, MOVE_ROAR}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 39,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_ODOR_SLEUTH, MOVE_FURY_SWIPES}
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 39,
    .species = SPECIES_BOUFFALANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Walter4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 42,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_ODOR_SLEUTH, MOVE_FURY_SWIPES}
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 42,
    .species = SPECIES_MANECTRIC,
    .moves = {MOVE_QUICK_ATTACK, MOVE_SPARK, MOVE_ODOR_SLEUTH, MOVE_NONE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 42,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_ODOR_SLEUTH, MOVE_FURY_SWIPES}
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 42,
    .species = SPECIES_BOUFFALANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Walter5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_ODOR_SLEUTH, MOVE_FURY_SWIPES}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_GOLDUCK,
    .moves = {MOVE_FURY_SWIPES, MOVE_DISABLE, MOVE_CONFUSION, MOVE_PSYCH_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_MANECTRIC,
    .moves = {MOVE_QUICK_ATTACK, MOVE_SPARK, MOVE_ODOR_SLEUTH, MOVE_ROAR}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_ODOR_SLEUTH, MOVE_FURY_SWIPES}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_DIGGERSBY,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_BOUFFALANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Sidney[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 66,
    .species = SPECIES_MIGHTYENA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROAR, MOVE_DOUBLE_EDGE, MOVE_SAND_ATTACK, MOVE_CRUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 66,
    .species = SPECIES_SHIFTRY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TORMENT, MOVE_FAKE_OUT, MOVE_SWAGGER, MOVE_EXTRASENSORY}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_CACTURNE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LEECH_SEED, MOVE_FEINT_ATTACK, MOVE_NEEDLE_ARM, MOVE_COTTON_SPORE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 68,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_FACADE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 69,
    .species = SPECIES_ABSOL,
    .heldItem = ITEM_ABSOLITE,
    .moves = {MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_SLASH}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 66,
    .species = SPECIES_SCRAFTY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CRUNCH, MOVE_BRICK_BREAK, MOVE_POISON_JAB, MOVE_DRAGON_CLAW}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 66,
    .species = SPECIES_SHIFTRY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TORMENT, MOVE_FAKE_OUT, MOVE_SWAGGER, MOVE_EXTRASENSORY}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_ZOROARK,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_NIGHT_SHADE, MOVE_SHADOW_CLAW, MOVE_DARK_PULSE, MOVE_FLAMETHROWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 68,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_FACADE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 69,
    .species = SPECIES_ABSOL,
    .heldItem = ITEM_ABSOLITE,
    .moves = {MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_SLASH}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Phoebe[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 66,
    .species = SPECIES_DUSCLOPS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHADOW_PUNCH, MOVE_CONFUSE_RAY, MOVE_CURSE, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_BANETTE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHADOW_BALL, MOVE_GRUDGE, MOVE_WILL_O_WISP, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_SABLEYE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHADOW_BALL, MOVE_FAKE_OUT, MOVE_NIGHT_SHADE, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 69,
    .species = SPECIES_DUSCLOPS,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SHADOW_BALL, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 69,
    .species = SPECIES_BANETTE,
    .heldItem = ITEM_BANETTITE,
    .moves = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_FACADE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 66,
    .species = SPECIES_DRIFBLIM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PHANTOM_FORCE, MOVE_PSYCHIC, MOVE_ACROBATICS, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_SABLEYE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHADOW_BALL, MOVE_FAKE_OUT, MOVE_NIGHT_SHADE, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 68,
    .species = SPECIES_CHANDELURE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HEX, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_DARK_PULSE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 68,
    .species = SPECIES_DUSKNOIR,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SHADOW_BALL, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 69,
    .species = SPECIES_BANETTE,
    .heldItem = ITEM_BANETTITE,
    .moves = {MOVE_SHADOW_BALL, MOVE_GRUDGE, MOVE_WILL_O_WISP, MOVE_FEINT_ATTACK}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Glacia[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 66,
    .species = SPECIES_SEALEO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ENCORE, MOVE_BODY_SLAM, MOVE_HAIL, MOVE_ICE_BALL}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_GLALIE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LIGHT_SCREEN, MOVE_CRUNCH, MOVE_ICY_WIND, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_SEALEO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ATTRACT, MOVE_DOUBLE_EDGE, MOVE_HAIL, MOVE_BLIZZARD}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 69,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SURF, MOVE_BODY_SLAM, MOVE_ICE_BEAM, MOVE_SHEER_COLD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 70,
    .species = SPECIES_GLALIE,
    .heldItem = ITEM_GLALITITE,
    .moves = {MOVE_SHADOW_BALL, MOVE_EXPLOSION, MOVE_HAIL, MOVE_ICE_BEAM}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 66,
    .species = SPECIES_ABOMASNOW,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BLIZZARD, MOVE_WOOD_HAMMER, MOVE_ICE_SHARD, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_BEARTIC,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ICICLE_CRASH, MOVE_SLASH, MOVE_SHADOW_CLAW, MOVE_HAIL}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_FROSLASS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAINING_KISS, MOVE_BLIZZARD, MOVE_HAIL, MOVE_SHADOW_BALL}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 69,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SURF, MOVE_BODY_SLAM, MOVE_ICE_BEAM, MOVE_SHEER_COLD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 70,
    .species = SPECIES_GLALIE,
    .heldItem = ITEM_GLALITITE,
    .moves = {MOVE_LIGHT_SCREEN, MOVE_CRUNCH, MOVE_EXPLOSION, MOVE_ICE_BEAM}
    },
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Drake[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_SHELGON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_TOMB, MOVE_DRAGON_CLAW, MOVE_PROTECT, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 68,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SMOKESCREEN, MOVE_DRAGON_DANCE, MOVE_SURF, MOVE_BODY_SLAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 69,
    .species = SPECIES_FLYGON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_DRAGON_BREATH, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 70,
    .species = SPECIES_SALAMENCE,
    .heldItem = ITEM_SALAMENCITE,
    .moves = {MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_ROCK_SLIDE, MOVE_CRUNCH}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_DRAGALGE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAGON_PULSE, MOVE_HYDRO_PUMP, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 67,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 68,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SMOKESCREEN, MOVE_DRAGON_DANCE, MOVE_SURF, MOVE_BODY_SLAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 69,
    .species = SPECIES_FLYGON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_DRAGON_BREATH, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 70,
    .species = SPECIES_SALAMENCE,
    .heldItem = ITEM_SALAMENCITE,
    .moves = {MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_ROCK_SLIDE, MOVE_CRUNCH}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_SidneyRematch[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_MIGHTYENA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROAR, MOVE_DOUBLE_EDGE, MOVE_SAND_ATTACK, MOVE_CRUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_SHIFTRY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TORMENT, MOVE_FAKE_OUT, MOVE_SWAGGER, MOVE_EXTRASENSORY}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_CACTURNE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LEECH_SEED, MOVE_FEINT_ATTACK, MOVE_NEEDLE_ARM, MOVE_COTTON_SPORE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_FACADE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_ABSOL,
    .heldItem = ITEM_ABSOLITE,
    .moves = {MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_SLASH}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_SCRAFTY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CRUNCH, MOVE_BRICK_BREAK, MOVE_POISON_JAB, MOVE_DRAGON_CLAW}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_SHIFTRY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FEINT_ATTACK, MOVE_FAKE_OUT, MOVE_EXTRASENSORY, MOVE_LEAF_BLADE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_ZOROARK,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_NASTY_PLOT, MOVE_FOCUS_BLAST, MOVE_DARK_PULSE, MOVE_FLAMETHROWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_BISHARP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KNOCK_OFF, MOVE_IRON_HEAD, MOVE_SUCKER_PUNCH, MOVE_LOW_KICK}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_HYDREIGON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRACO_METEOR, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_ROOST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_ABSOL,
    .heldItem = ITEM_ABSOLITE,
    .moves = {MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_SLASH}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_PhoebeRematch[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_DUSCLOPS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHADOW_PUNCH, MOVE_CONFUSE_RAY, MOVE_CURSE, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_SABLEYE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHADOW_BALL, MOVE_FAKE_OUT, MOVE_NIGHT_SHADE, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_BANETTE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_FACADE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_DUSCLOPS,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SHADOW_BALL, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_BANETTE,
    .heldItem = ITEM_BANETTITE,
    .moves = {MOVE_SHADOW_BALL, MOVE_GRUDGE, MOVE_WILL_O_WISP, MOVE_FEINT_ATTACK}
    },
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_DRIFBLIM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HEX, MOVE_WILL_O_WISP, MOVE_STRENGTH_SAP, MOVE_AIR_SLASH}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_SABLEYE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHADOW_CLAW, MOVE_FOUL_PLAY, MOVE_POWER_GEM, MOVE_FAKE_OUT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_CHANDELURE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HEX, MOVE_FLAMETHROWER, MOVE_WILL_O_WISP, MOVE_DARK_PULSE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_DUSKNOIR,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HEX, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_DHELMISE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ANCHOR_SHOT, MOVE_RAPID_SPIN, MOVE_POLTERGEIST, MOVE_SYNTHESIS}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_BANETTE,
    .heldItem = ITEM_BANETTITE,
    .moves = {MOVE_POLTERGEIST, MOVE_GUNK_SHOT, MOVE_WILL_O_WISP, MOVE_ENCORE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_GlaciaRematch[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_SEALEO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ENCORE, MOVE_BODY_SLAM, MOVE_HAIL, MOVE_ICE_BALL}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_GLALIE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LIGHT_SCREEN, MOVE_CRUNCH, MOVE_ICY_WIND, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_SEALEO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ATTRACT, MOVE_DOUBLE_EDGE, MOVE_HAIL, MOVE_BLIZZARD}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SURF, MOVE_BODY_SLAM, MOVE_ICE_BEAM, MOVE_SHEER_COLD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_GLALIE,
    .heldItem = ITEM_GLALITITE,
    .moves = {MOVE_SHADOW_BALL, MOVE_EXPLOSION, MOVE_HAIL, MOVE_ICE_BEAM}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_MAMOSWINE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_ICICLE_CRASH, MOVE_STEALTH_ROCK}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_ABOMASNOW,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BLIZZARD, MOVE_WOOD_HAMMER, MOVE_ICE_SHARD, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_WEAVILE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TRIPLE_AXEL, MOVE_ICE_SHARD, MOVE_KNOCK_OFF, MOVE_LOW_KICK}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_FROSLASS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAINING_KISS, MOVE_BLIZZARD, MOVE_SPIKES, MOVE_SHADOW_BALL}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SURF, MOVE_SUPER_FANG, MOVE_BLIZZARD, MOVE_ROAR}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_GLALIE,
    .heldItem = ITEM_GLALITITE,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_ICE_SHARD, MOVE_EXPLOSION, MOVE_FREEZE_DRY}
    },
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_DrakeRematch[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_SHELGON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_TOMB, MOVE_DRAGON_CLAW, MOVE_PROTECT, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SMOKESCREEN, MOVE_DRAGON_DANCE, MOVE_SURF, MOVE_BODY_SLAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_FLYGON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_DRAGON_BREATH, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_SALAMENCE,
    .heldItem = ITEM_SALAMENCITE,
    .moves = {MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_ROCK_SLIDE, MOVE_CRUNCH}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_DRAGALGE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAGON_PULSE, MOVE_HYDRO_PUMP, MOVE_SLUDGE_WAVE, MOVE_THUNDERBOLT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_MOONBLAST, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRACO_METEOR, MOVE_YAWN, MOVE_SURF, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_FLYGON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_BOOMBURST, MOVE_DRAGON_PULSE, MOVE_SCREECH}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 75,
    .species = SPECIES_DRAGAPULT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAGON_DANCE, MOVE_DRAGON_DARTS, MOVE_PHANTOM_FORCE, MOVE_FLAMETHROWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_SALAMENCE,
    .heldItem = ITEM_SALAMENCITE,
    .moves = {MOVE_THUNDER_FANG, MOVE_DRAGON_RUSH, MOVE_ZEN_HEADBUTT, MOVE_CRUNCH}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Roxanne1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 14,
    .species = SPECIES_GEODUDE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_ROCK_THROW, MOVE_ROCK_TOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 14,
    .species = SPECIES_GEODUDE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_ROCK_THROW, MOVE_ROCK_TOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 15,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_BLOCK, MOVE_HARDEN, MOVE_TACKLE, MOVE_ROCK_TOMB}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 14,
    .species = SPECIES_GEODUDE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_ROCK_THROW, MOVE_ROCK_TOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 15,
    .species = SPECIES_ROCKRUFF,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TACKLE, MOVE_LEER, MOVE_ROCK_THROW, MOVE_MUD_SLAP}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 15,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_BLOCK, MOVE_HARDEN, MOVE_TACKLE, MOVE_ROCK_TOMB}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brawly1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 18,
    .species = SPECIES_MACHOP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KARATE_CHOP, MOVE_LOW_KICK, MOVE_SEISMIC_TOSS, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 19,
    .species = SPECIES_MEDITITE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 22,
    .species = SPECIES_MAKUHITA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_ARM_THRUST, MOVE_VITAL_THROW, MOVE_REVERSAL, MOVE_BULK_UP}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 18,
    .species = SPECIES_MACHOP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KARATE_CHOP, MOVE_LOW_KICK, MOVE_SEISMIC_TOSS, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 18,
    .species = SPECIES_MEDITITE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LOW_KICK, MOVE_PSYBEAM, MOVE_SWIFT, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 21,
    .species = SPECIES_MAKUHITA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ARM_THRUST, MOVE_VITAL_THROW, MOVE_REVERSAL, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 21,
    .species = SPECIES_TYROGUE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BULLET_PUNCH, MOVE_FAKE_OUT, MOVE_MACH_PUNCH, MOVE_BULK_UP}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_BrawlyAlt[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 28,
    .species = SPECIES_MACHOP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KARATE_CHOP, MOVE_LOW_KICK, MOVE_SEISMIC_TOSS, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 29,
    .species = SPECIES_MEDITITE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 29,
    .species = SPECIES_MAKUHITA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_ARM_THRUST, MOVE_VITAL_THROW, MOVE_REVERSAL, MOVE_BULK_UP}
    }
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 31,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_ARM_THRUST, MOVE_VITAL_THROW, MOVE_REVERSAL, MOVE_BULK_UP}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 28,
    .species = SPECIES_MACHOP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KARATE_CHOP, MOVE_LOW_KICK, MOVE_SEISMIC_TOSS, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 28,
    .species = SPECIES_MEDITITE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LOW_KICK, MOVE_PSYBEAM, MOVE_SWIFT, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 30,
    .species = SPECIES_HITMONTOP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BULLET_PUNCH, MOVE_FAKE_OUT, MOVE_MACH_PUNCH, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 31,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ARM_THRUST, MOVE_VITAL_THROW, MOVE_REVERSAL, MOVE_BULK_UP}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Wattson1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 27,
    .species = SPECIES_VOLTORB,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROLLOUT, MOVE_SPARK, MOVE_SELF_DESTRUCT, MOVE_SHOCK_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 27,
    .species = SPECIES_ELECTRIKE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHOCK_WAVE, MOVE_LEER, MOVE_QUICK_ATTACK, MOVE_HOWL}
    },
    {
    .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
    .lvl = 28,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUPERSONIC, MOVE_SHOCK_WAVE, MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 31,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_SHOCK_WAVE, MOVE_HOWL}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 27,
    .species = SPECIES_VOLTORB,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROLLOUT, MOVE_SPARK, MOVE_SELF_DESTRUCT, MOVE_SHOCK_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 27,
    .species = SPECIES_MAREEP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER_SHOCK, MOVE_COTTON_SPORE, MOVE_TAKE_DOWN, MOVE_THUNDER_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 29,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUPERSONIC, MOVE_SHOCK_WAVE, MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 31,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_QUICK_ATTACK, MOVE_BITE, MOVE_THUNDER_FANG, MOVE_HOWL}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_WattsonAlt[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 21,
    .species = SPECIES_VOLTORB,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROLLOUT, MOVE_SPARK, MOVE_SELF_DESTRUCT, MOVE_SHOCK_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 21,
    .species = SPECIES_ELECTRIKE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHOCK_WAVE, MOVE_LEER, MOVE_QUICK_ATTACK, MOVE_HOWL}
    },
    {
    .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
    .lvl = 22,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUPERSONIC, MOVE_SHOCK_WAVE, MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM}
    },
    {
    .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
    .lvl = 22,
    .species = SPECIES_ELECTRIKE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_SHOCK_WAVE, MOVE_HOWL}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 21,
    .species = SPECIES_VOLTORB,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROLLOUT, MOVE_SPARK, MOVE_SELF_DESTRUCT, MOVE_SHOCK_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 21,
    .species = SPECIES_MAREEP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER_SHOCK, MOVE_COTTON_SPORE, MOVE_TAKE_DOWN, MOVE_THUNDER_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 22,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUPERSONIC, MOVE_SHOCK_WAVE, MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 22,
    .species = SPECIES_ELECTRIKE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_QUICK_ATTACK, MOVE_BITE, MOVE_THUNDER_FANG, MOVE_HOWL}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Flannery1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 34,
    .species = SPECIES_NUMEL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_TAKE_DOWN, MOVE_MAGNITUDE, MOVE_SUNNY_DAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 34,
    .species = SPECIES_SLUGMA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_SMOG, MOVE_LIGHT_SCREEN, MOVE_SUNNY_DAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 35,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_TACKLE, MOVE_SUNNY_DAY, MOVE_ATTRACT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 36,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_BODY_SLAM, MOVE_ATTRACT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 34,
    .species = SPECIES_SLUGMA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_SMOG, MOVE_CLEAR_SMOG, MOVE_SUNNY_DAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 34,
    .species = SPECIES_HOUNDOUR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRE_FANG, MOVE_BITE, MOVE_THUNDER_FANG, MOVE_HOWL}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 35,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_TACKLE, MOVE_SUNNY_DAY, MOVE_ATTRACT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 36,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_BODY_SLAM, MOVE_ATTRACT}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Norman1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 36,
    .species = SPECIES_SPINDA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TEETER_DANCE, MOVE_PSYBEAM, MOVE_FACADE, MOVE_ENCORE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 37,
    .species = SPECIES_VIGOROTH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SLASH, MOVE_FACADE, MOVE_ENCORE, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 37,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SLASH, MOVE_BELLY_DRUM, MOVE_FACADE, MOVE_HEADBUTT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 38,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_COUNTER, MOVE_YAWN, MOVE_FACADE, MOVE_FEINT_ATTACK}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 36,
    .species = SPECIES_SPINDA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TEETER_DANCE, MOVE_PSYBEAM, MOVE_FACADE, MOVE_ENCORE}
    },
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 37,
    .species = SPECIES_VIGOROTH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SLASH, MOVE_FACADE, MOVE_ENCORE, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 37,
    .species = SPECIES_STARAVIA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TAKE_DOWN, MOVE_AIR_SLASH, MOVE_U_TURN, MOVE_FACADE}
    },
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 37,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SLASH, MOVE_BELLY_DRUM, MOVE_FACADE, MOVE_HEADBUTT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 38,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_COUNTER, MOVE_YAWN, MOVE_FACADE, MOVE_FEINT_ATTACK}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Winona1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 42,
    .species = SPECIES_SWABLU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PERISH_SONG, MOVE_MIRROR_MOVE, MOVE_SAFEGUARD, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 42,
    .species = SPECIES_TROPIUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUNNY_DAY, MOVE_AERIAL_ACE, MOVE_SOLAR_BEAM, MOVE_SYNTHESIS}
    },
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 43,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_GUN, MOVE_SUPERSONIC, MOVE_PROTECT, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
    .lvl = 44,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SAND_ATTACK, MOVE_FURY_ATTACK, MOVE_STEEL_WING, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 45,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_ALTARIANITE,
    .moves = {MOVE_BULLDOZE, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE, MOVE_AERIAL_ACE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 42,
    .species = SPECIES_RUFFLET,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TAKE_DOWN, MOVE_SHADOW_CLAW, MOVE_TAILWIND, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 42,
    .species = SPECIES_TROPIUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAZOR_LEAF, MOVE_AERIAL_ACE, MOVE_LEECH_SEED, MOVE_ROOST}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 43,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_SUPERSONIC, MOVE_TAILWIND, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 44,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SAND_ATTACK, MOVE_FURY_ATTACK, MOVE_STEEL_WING, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 45,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_ALTARIANITE,
    .moves = {MOVE_BULLDOZE, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE, MOVE_AERIAL_ACE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_TateAndLiza1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 52,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_PSYCHIC, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 52,
    .species = SPECIES_XATU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC, MOVE_SUNNY_DAY, MOVE_CONFUSE_RAY, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 54,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 54,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_PSYCHIC, MOVE_FLAMETHROWER}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 52,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_PSYCHIC, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 52,
    .species = SPECIES_XATU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC, MOVE_SUNNY_DAY, MOVE_CONFUSE_RAY, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 53,
    .species = SPECIES_CHIMECHO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_ENERGY_BALL, MOVE_DAZZLING_GLEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 53,
    .species = SPECIES_BRONZONG,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_GYRO_BALL, MOVE_FUTURE_SIGHT}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 54,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 54,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_PSYCHIC, MOVE_FLAMETHROWER}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Juan1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 57,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_AMNESIA, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 57,
    .species = SPECIES_SEALEO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ENCORE, MOVE_BODY_SLAM, MOVE_AURORA_BEAM, MOVE_WATER_PULSE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 58,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_CRABHAMMER, MOVE_TAUNT, MOVE_LEER}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 58,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_BRINE, MOVE_DRAGON_PULSE, MOVE_ICE_BEAM, MOVE_REST}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 60,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_GYARADOSITE,
    .moves = {MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_AQUA_TAIL}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 57,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_AMNESIA, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 57,
    .species = SPECIES_SEALEO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ENCORE, MOVE_BODY_SLAM, MOVE_AURORA_BEAM, MOVE_WATER_PULSE}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 59,
    .species = SPECIES_BASCULEGION,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_SHADOW_BALL, MOVE_ICE_BEAM, MOVE_AQUA_JET}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 59,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_BRINE, MOVE_DRAGON_PULSE, MOVE_ICE_BEAM, MOVE_REST}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 60,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_GYARADOSITE,
    .moves = {MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_AQUA_TAIL}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jerry1[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 10,
    .species = SPECIES_RALTS,
    }
};

static const struct TrainerMon sParty_Ted[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 19,
    .species = SPECIES_RALTS,
    }
};

static const struct TrainerMon sParty_Paul[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 17,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 17,
    .species = SPECIES_ODDISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 17,
    .species = SPECIES_WINGULL,
    }
};

static const struct TrainerMon sParty_Jerry2[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 29,
    .species = SPECIES_RALTS,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 29,
    .species = SPECIES_MEDITITE,
    }
};

static const struct TrainerMon sParty_Jerry3[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 32,
    .species = SPECIES_KIRLIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 32,
    .species = SPECIES_MEDITITE,
    }
};

static const struct TrainerMon sParty_Jerry4[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 35,
    .species = SPECIES_KIRLIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 35,
    .species = SPECIES_MEDICHAM,
    }
};

static const struct TrainerMon sParty_Jerry5[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 37,
    .species = SPECIES_KIRLIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 37,
    .species = SPECIES_BANETTE,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 37,
    .species = SPECIES_MEDICHAM,
    }
};

static const struct TrainerMon sParty_Karen1[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 10,
    .species = SPECIES_SHROOMISH,
    }
};

static const struct TrainerMon sParty_Georgia[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 18,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 18,
    .species = SPECIES_BEAUTIFLY,
    }
};

static const struct TrainerMon sParty_Karen2[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 29,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 29,
    .species = SPECIES_WHISMUR,
    }
};

static const struct TrainerMon sParty_Karen3[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 32,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 32,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_Karen4[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 35,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 35,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_Karen5[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 38,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 38,
    .species = SPECIES_EXPLOUD,
    }
};

static const struct TrainerMon sParty_KateAndJoy[] = {
    #ifdef CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_SPINDA,
    .moves = {MOVE_HYPNOSIS, MOVE_PSYBEAM, MOVE_DIZZY_PUNCH, MOVE_TEETER_DANCE}
    },
    {
    .lvl = 35,
    .species = SPECIES_SLAKING,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_YAWN, MOVE_SLACK_OFF, MOVE_FEINT_ATTACK}
    }
    #else // CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_FLOATZEL,
    },
    {
    .lvl = 33,
    .species = SPECIES_LOPUNNY,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_AnnaAndMeg1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 17,
    .species = SPECIES_ZIGZAGOON,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .lvl = 19,
    .species = SPECIES_MAKUHITA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
    #else // CANON_MODE
    {
    .lvl = 17,
    .species = SPECIES_GOTHORITA,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .lvl = 19,
    .species = SPECIES_MAKUHITA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
    #endif // CANON_MODE   
};

static const struct TrainerMon sParty_AnnaAndMeg2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 31,
    .species = SPECIES_ZIGZAGOON,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_MAKUHITA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 31,
    .species = SPECIES_GOTHORITA,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_MAKUHITA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_AnnaAndMeg3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 35,
    .species = SPECIES_ZIGZAGOON,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_MAKUHITA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 35,
    .species = SPECIES_GOTHORITA,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_MAKUHITA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_AnnaAndMeg4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_MAKUHITA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_GOTHORITA,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_MAKUHITA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_AnnaAndMeg5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 41,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 41,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 41,
    .species = SPECIES_GOTHITELLE,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 41,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Victor[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 18,
    .species = SPECIES_TAILLOW,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 18,
    .species = SPECIES_ZIGZAGOON,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Miguel1[] = {
    {
    .lvl = 17,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Colton[] = {
    {
    .lvl = 25,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK, MOVE_HEAL_BELL}
    },
    {
    .lvl = 39,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK, MOVE_HEAL_BELL}
    },
    {
    .lvl = 44,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK, MOVE_HEAL_BELL}
    },
    {
    .lvl = 14,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK, MOVE_HEAL_BELL}
    },
    {
    .lvl = 33,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK, MOVE_HEAL_BELL}
    },
    {
    .lvl = 46,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK, MOVE_HEAL_BELL}
    }
};

static const struct TrainerMon sParty_Miguel2[] = {
    {
    .lvl = 32,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Miguel3[] = {
    {
    .lvl = 35,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Miguel4[] = {
    {
    .lvl = 38,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Miguel5[] = {
    {
    .lvl = 41,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_SITRUS_BERRY
    }
};

static const struct TrainerMon sParty_Victoria[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 19,
    .species = SPECIES_ROSELIA,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Vanessa[] = {
    {
    .lvl = 33,
    .species = SPECIES_PIKACHU,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Bethany[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 53,
    .species = SPECIES_AZURILL,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_MARILL,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_AZUMARILL,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Isabel1[] = {
    {
    .lvl = 16,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .lvl = 16,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Isabel2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Isabel3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Isabel4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Isabel5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_SITRUS_BERRY
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_SITRUS_BERRY
    }
};

static const struct TrainerMon sParty_Timothy1[] = {
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 30,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Timothy2[] = {
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 36,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_ARM_THRUST, MOVE_KNOCK_OFF, MOVE_SAND_ATTACK, MOVE_DIG}
    }
};

static const struct TrainerMon sParty_Timothy3[] = {
    {
    .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
    .lvl = 39,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_ARM_THRUST, MOVE_KNOCK_OFF, MOVE_SAND_ATTACK, MOVE_DIG}
    }
};

static const struct TrainerMon sParty_Timothy4[] = {
    {
    .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
    .lvl = 42,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_ARM_THRUST, MOVE_BELLY_DRUM, MOVE_SAND_ATTACK, MOVE_DIG}
    }
};

static const struct TrainerMon sParty_Timothy5[] = {
    {
    .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
    .lvl = 46,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_ARM_THRUST, MOVE_BELLY_DRUM, MOVE_SAND_ATTACK, MOVE_DIG}
    }
};

static const struct TrainerMon sParty_Vicky[] = {
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 20,
    .species = SPECIES_MEDITITE,
    .moves = {MOVE_HIGH_JUMP_KICK, MOVE_MEDITATE, MOVE_CONFUSION, MOVE_DETECT}
    }
};

static const struct TrainerMon sParty_Shelby1[] = {
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 24,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 24,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Shelby2[] = {
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 33,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 33,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Shelby3[] = {
    {
    .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
    .lvl = 36,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
    .lvl = 36,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Shelby4[] = {
    {
    .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
    .lvl = 39,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
    .lvl = 39,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Shelby5[] = {
    {
    .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
    .lvl = 42,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
    .lvl = 42,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Calvin1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 6,
    .species = SPECIES_POOCHYENA,
    }
    #else // CANON_MODE
    {
    .lvl = 6,
    .species = SPECIES_ROOKIDEE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Billy[] = {
    {
    .lvl = 5,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .lvl = 8,
    .species = SPECIES_SEEDOT,
    }
};

static const struct TrainerMon sParty_Josh[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 13,
    .species = SPECIES_GEODUDE,
    .moves = {MOVE_TACKLE, MOVE_NONE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Tommy[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 10,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 10,
    .species = SPECIES_GEODUDE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 10,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 10,
    .species = SPECIES_ROGGENROLA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Joey[] = {
    #ifdef CANON_MODE
    {
    .lvl = 10,
    .species = SPECIES_MACHOP,
    }
    #else // CANON_MODE
    {
    .lvl = 10,
    .species = SPECIES_HELIOPTILE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Ben[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 24,
    .species = SPECIES_ZIGZAGOON,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_GROWL, MOVE_THUNDERBOLT}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 25,
    .species = SPECIES_GULPIN,
    .moves = {MOVE_AMNESIA, MOVE_SLUDGE, MOVE_YAWN, MOVE_POUND}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 24,
    .species = SPECIES_TOXEL,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_GROWL, MOVE_THUNDERBOLT}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 25,
    .species = SPECIES_GULPIN,
    .moves = {MOVE_AMNESIA, MOVE_SLUDGE, MOVE_YAWN, MOVE_POUND}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Quincy[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_SLAKING,
    .moves = {MOVE_ATTRACT, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_DUSCLOPS,
    .moves = {MOVE_SKILL_SWAP, MOVE_PROTECT, MOVE_WILL_O_WISP, MOVE_TOXIC}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_BEWEAR,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_DUSCLOPS,
    .moves = {MOVE_SKILL_SWAP, MOVE_PROTECT, MOVE_WILL_O_WISP, MOVE_TOXIC}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Katelynn[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_GARDEVOIR,
    .moves = {MOVE_SKILL_SWAP, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_SLAKING,
    .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK}
    }
};

static const struct TrainerMon sParty_Jaylen[] = {
    #ifdef CANON_MODE
    {
    .lvl = 22,
    .species = SPECIES_TRAPINCH,
    }
    #else // CANON_MODE
    {
    .lvl = 22,
    .species = SPECIES_SALANDIT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Dillon[] = {
    #ifdef CANON_MODE
    {
    .lvl = 22,
    .species = SPECIES_ARON,
    }
    #else // CANON_MODE
    {
    .lvl = 22,
    .species = SPECIES_SANDYGAST,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Calvin2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 30,
    .species = SPECIES_MIGHTYENA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 30,
    .species = SPECIES_CORVISQUIRE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Calvin3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 33,
    .species = SPECIES_MIGHTYENA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 33,
    .species = SPECIES_CORVISQUIRE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Calvin4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 32,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 36,
    .species = SPECIES_MIGHTYENA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 32,
    .species = SPECIES_CORVISQUIRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 36,
    .species = SPECIES_MIGHTYENA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Calvin5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 35,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 39,
    .species = SPECIES_MIGHTYENA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_CORVIKNIGHT,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 39,
    .species = SPECIES_MIGHTYENA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Eddie[] = {
    {
    .lvl = 16,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .lvl = 18,
    .species = SPECIES_ZIGZAGOON,
    }
};

static const struct TrainerMon sParty_Allen[] = {
    {
    .lvl = 4,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .lvl = 4,
    .species = SPECIES_TAILLOW,
    }
};

static const struct TrainerMon sParty_Timmy[] = {
    {
    .lvl = 17,
    .species = SPECIES_ARON,
    },
    {
    .lvl = 15,
    .species = SPECIES_ELECTRIKE,
    }
};

static const struct TrainerMon sParty_Wallace[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_WAILORD,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_SPOUT, MOVE_DOUBLE_EDGE, MOVE_BLIZZARD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_TENTACRUEL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TOXIC, MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_LUDICOLO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_GIGA_DRAIN, MOVE_SURF, MOVE_LEECH_SEED, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 69,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_SURF, MOVE_AMNESIA, MOVE_HYPER_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 69,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_HYPER_BEAM, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 70,
    .species = SPECIES_MILOTIC,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_RECOVER, MOVE_SURF, MOVE_ICE_BEAM, MOVE_TOXIC}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_WAILORD,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_SPOUT, MOVE_DOUBLE_EDGE, MOVE_BLIZZARD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_CLOYSTER,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ICICLE_SPEAR, MOVE_RAZOR_SHELL, MOVE_ICE_SPINNER, MOVE_RAPID_SPIN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BODY_SLAM, MOVE_SURF, MOVE_BLIZZARD, MOVE_SHEER_COLD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 69,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_SURF, MOVE_AMNESIA, MOVE_HYPER_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 69,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_HYPER_BEAM, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 70,
    .species = SPECIES_MILOTIC,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_RECOVER, MOVE_SURF, MOVE_ICE_BEAM, MOVE_TOXIC}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_WallaceRematch[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_WAILORD,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_SPOUT, MOVE_DOUBLE_EDGE, MOVE_BLIZZARD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_TENTACRUEL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TOXIC, MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_LUDICOLO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_GIGA_DRAIN, MOVE_SURF, MOVE_LEECH_SEED, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_SURF, MOVE_AMNESIA, MOVE_HYPER_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_HYPER_BEAM, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_MILOTIC,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_RECOVER, MOVE_SURF, MOVE_ICE_BEAM, MOVE_TOXIC}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_SLOWKING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CHILLY_RECEPTION, MOVE_SLACK_OFF, MOVE_THUNDER_WAVE, MOVE_SCALD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_CLOYSTER,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ICICLE_SPEAR, MOVE_RAZOR_SHELL, MOVE_ICE_SPINNER, MOVE_RAPID_SPIN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BODY_SLAM, MOVE_SURF, MOVE_BLIZZARD, MOVE_AURORA_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTH_POWER, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_STONE_EDGE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_WATERFALL}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_MILOTIC,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_RECOVER, MOVE_SURF, MOVE_AURORA_BEAM, MOVE_BLIZZARD}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Andrew[] = {
    #ifdef CANON_MODE
    {
    .lvl = 5,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 11,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 17,
    .species = SPECIES_MAGIKARP,
    }
    #else // CANON_MODE
    {
    .lvl = 5,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 11,
    .species = SPECIES_WISHIWASHI,
    },
    {
    .lvl = 17,
    .species = SPECIES_CLAUNCHER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Ivan[] = {
    {
    .lvl = 5,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 6,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 8,
    .species = SPECIES_MAGIKARP,
    }
};

static const struct TrainerMon sParty_Claude[] = {
    {
    .lvl = 18,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 19,
    .species = SPECIES_GOLDEEN,
    },
    {
    .lvl = 20,
    .species = SPECIES_BARBOACH,
    }
};

static const struct TrainerMon sParty_Elliot1[] = {
    {
    .lvl = 11,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 8,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 11,
    .species = SPECIES_MAGIKARP,
    }
};

static const struct TrainerMon sParty_Ned[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 12,
    .species = SPECIES_TENTACOOL,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 12,
    .species = SPECIES_SHELLOS_WEST_SEA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Dale[] = {
    #ifdef CANON_MODE
    {
    .lvl = 12,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 16,
    .species = SPECIES_WAILMER,
    },
    {
    .lvl = 12,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 16,
    .species = SPECIES_WAILMER,
    }
    #else // CANON_MODE
    {
    .lvl = 12,
    .species = SPECIES_WISHIWASHI,
    },
    {
    .lvl = 16,
    .species = SPECIES_WAILMER,
    },
    {
    .lvl = 12,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 16,
    .species = SPECIES_WAILMER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nolan[] = {
    {
    .lvl = 22,
    .species = SPECIES_BARBOACH,
    }
};

static const struct TrainerMon sParty_Barny[] = {
    #ifdef CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 28,
    .species = SPECIES_CARVANHA,
    }
    #else // CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_BASCULIN_RED_STRIPED,
    },
    {
    .lvl = 28,
    .species = SPECIES_CARVANHA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Wade[] = {
    #ifdef CANON_MODE
    {
    .lvl = 18,
    .species = SPECIES_TENTACOOL,
    }
    #else // CANON_MODE
    {
    .lvl = 18,
    .species = SPECIES_BASCULIN_RED_STRIPED,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Carter[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Elliot2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 30,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 30,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Elliot3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 29,
    .species = SPECIES_CARVANHA,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 29,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Elliot4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_CARVANHA,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Elliot5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_SHARPEDO,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Ronald[] = {
    #ifdef CANON_MODE
    {
    .lvl = 22,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 24,
    .species = SPECIES_GYARADOS,
    },
    {
    .lvl = 26,
    .species = SPECIES_GYARADOS,
    },
    {
    .lvl = 29,
    .species = SPECIES_GYARADOS,
    },
    {
    .lvl = 33,
    .species = SPECIES_GYARADOS,
    },
    {
    .lvl = 38,
    .species = SPECIES_GYARADOS,
    }
    #else // CANON_MODE
    {
    .lvl = 23,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 27,
    .species = SPECIES_GYARADOS,
    },
    {
    .lvl = 30,
    .species = SPECIES_WISHIWASHI,
    },
    {
    .lvl = 34,
    .species = SPECIES_GYARADOS,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jacob[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 7,
    .species = SPECIES_VOLTORB,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 7,
    .species = SPECIES_VOLTORB,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 16,
    .species = SPECIES_MAGNEMITE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 7,
    .species = SPECIES_VOLTORB,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 7,
    .species = SPECIES_SHINX,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 16,
    .species = SPECIES_MAGNEMITE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Anthony[] = {
    #ifdef CANON_MODE
    {
    .lvl = 16,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .lvl = 16,
    .species = SPECIES_MAGNEMITE,
    }
    #else // CANON_MODE
    {
    .lvl = 16,
    .species = SPECIES_PACHIRISU,
    },
    {
    .lvl = 16,
    .species = SPECIES_MAGNEMITE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Benjamin1[] = {
    {
    .lvl = 18,
    .species = SPECIES_MAGNEMITE,
    }
};

static const struct TrainerMon sParty_Benjamin2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_MAGNEMITE,
    }
};

static const struct TrainerMon sParty_Benjamin3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_MAGNEMITE,
    }
};

static const struct TrainerMon sParty_Benjamin4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_MAGNETON,
    }
};

static const struct TrainerMon sParty_Benjamin5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 42,
    .species = SPECIES_MAGNETON,
    }
};

static const struct TrainerMon sParty_Abigail1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 18,
    .species = SPECIES_MAGNEMITE,
    }
    #else // CANON_MODE
    {
    .lvl = 18,
    .species = SPECIES_YAMPER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jasmine[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 16,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 16,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .lvl = 7,
    .species = SPECIES_VOLTORB,
    }
    #else // CANON_MODE
        {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 16,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 16,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .lvl = 7,
    .species = SPECIES_TOXEL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Abigail2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 31,
    .species = SPECIES_MAGNEMITE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 31,
    .species = SPECIES_YAMPER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Abigail3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 34,
    .species = SPECIES_MAGNEMITE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 34,
    .species = SPECIES_BOLTUND,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Abigail4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_MAGNETON,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_BOLTUND,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Abigail5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_MAGNETON,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_BOLTUND,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Dylan1[] = {
    {
    .lvl = 19,
    .species = SPECIES_DODUO,
    }
};

static const struct TrainerMon sParty_Dylan2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 31,
    .species = SPECIES_DODUO,
    }
};

static const struct TrainerMon sParty_Dylan3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 34,
    .species = SPECIES_DODUO,
    }
};

static const struct TrainerMon sParty_Dylan4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_DODRIO,
    }
};

static const struct TrainerMon sParty_Dylan5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_DODRIO,
    }
};

static const struct TrainerMon sParty_Maria1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 19,
    .species = SPECIES_DODUO,
    }
    #else // CANON_MODE
    {
    .lvl = 19,
    .species = SPECIES_FURFROU,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Maria2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 31,
    .species = SPECIES_DODUO,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 31,
    .species = SPECIES_FURFROU,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Maria3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 34,
    .species = SPECIES_DODUO,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 34,
    .species = SPECIES_FURFROU,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Maria4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_DODRIO,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_FURFROU,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Maria5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_DODRIO,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_FURFROU,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Camden[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_STARYU,
    },
    {
    .lvl = 36,
    .species = SPECIES_STARYU,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_STARYU,
    },
    {
    .lvl = 36,
    .species = SPECIES_SWANNA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Demetrius[] = {
    {
    .lvl = 28,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .lvl = 28,
    .species = SPECIES_ELECTRIKE,
    }
};

static const struct TrainerMon sParty_Isaiah1[] = {
    {
    .lvl = 38,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Pablo1[] = {
    {
    .lvl = 36,
    .species = SPECIES_STARYU,
    },
    {
    .lvl = 36,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Chase[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 37,
    .species = SPECIES_STARYU,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 37,
    .species = SPECIES_GASTRODON_EAST_SEA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Isaiah2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 42,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Isaiah3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 46,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Isaiah4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 50,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Isaiah5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 52,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Isobel[] = {
    {
    .lvl = 37,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Donny[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
    .lvl = 37,
    .species = SPECIES_STARYU,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_MAREANIE,
    },
    {
    .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
    .lvl = 37,
    .species = SPECIES_STARYU,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Talia[] = {
    {
    .lvl = 37,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Katelyn1[] = {
    {
    .lvl = 38,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Allison[] = {
    #ifdef CANON_MODE
    {
    .lvl = 30,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
    .lvl = 36,
    .species = SPECIES_STARYU,
    }
    #else // CANON_MODE
    {
    .lvl = 30,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
    .lvl = 36,
    .species = SPECIES_CRAMORANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Katelyn2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 42,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Katelyn3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 46,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Katelyn4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 50,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Katelyn5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 52,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Nicolas1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 40,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 40,
    .species = SPECIES_ALTARIA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 40,
    .species = SPECIES_FRAXURE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 40,
    .species = SPECIES_ALTARIA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nicolas2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 45,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 45,
    .species = SPECIES_ALTARIA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 45,
    .species = SPECIES_FRAXURE,
    },
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 45,
    .species = SPECIES_ALTARIA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nicolas3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 48,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 48,
    .species = SPECIES_ALTARIA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 48,
    .species = SPECIES_HAXORUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 48,
    .species = SPECIES_ALTARIA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nicolas4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 50,
    .species = SPECIES_BAGON,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 50,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 50,
    .species = SPECIES_ALTARIA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 48,
    .species = SPECIES_SHELGON,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 50,
    .species = SPECIES_HAXORUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 50,
    .species = SPECIES_ALTARIA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nicolas5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 53,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_NONE
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 53,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_NONE
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 53,
    .species = SPECIES_SHELGON,
    .heldItem = ITEM_DRAGON_FANG
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 53,
    .species = SPECIES_HAXORUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 53,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 53,
    .species = SPECIES_SALAMENCE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Aaron[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 37,
    .species = SPECIES_BAGON,
    .moves = {MOVE_DRAGON_BREATH, MOVE_HEADBUTT, MOVE_FOCUS_ENERGY, MOVE_EMBER}
    }
};

static const struct TrainerMon sParty_Perry[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_WINGULL,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_CRAMORANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Hugh[] = {
    #ifdef CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 28,
    .species = SPECIES_TROPIUS,
    }
    #else // CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_ROOKIDEE,
    },
    {
    .lvl = 28,
    .species = SPECIES_TROPIUS,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Phil[] = {
    {
    .lvl = 29,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Jared[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 39,
    .species = SPECIES_DODUO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 39,
    .species = SPECIES_SKARMORY,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 40,
    .species = SPECIES_TROPIUS,
    }
};

static const struct TrainerMon sParty_Humberto[] = {
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 39,
    .species = SPECIES_SKARMORY,
    }
};

static const struct TrainerMon sParty_Presley[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_TROPIUS,
    },
    {
    .lvl = 36,
    .species = SPECIES_XATU,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_TRANQUILL,
    },
    {
    .lvl = 36,
    .species = SPECIES_XATU,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Edwardo[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 39,
    .species = SPECIES_DODUO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 40,
    .species = SPECIES_PELIPPER,
    }
};

static const struct TrainerMon sParty_Colin[] = {
    #ifdef CANON_MODE
    {
    .lvl = 31,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 31,
    .species = SPECIES_NATU,
    }
    #else // CANON_MODE
    {
    .lvl = 31,
    .species = SPECIES_STARAVIA,
    },
    {
    .lvl = 31,
    .species = SPECIES_NATU,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Robert1[] = {
    {
    .lvl = 32,
    .species = SPECIES_SWABLU,
    }
};

static const struct TrainerMon sParty_Benny[] = {
    {
    .lvl = 39,
    .species = SPECIES_SWELLOW,
    },
    {
    .lvl = 39,
    .species = SPECIES_PELIPPER,
    },
    {
    .lvl = 39,
    .species = SPECIES_XATU,
    }
};

static const struct TrainerMon sParty_Chester[] = {
    {
    .lvl = 28,
    .species = SPECIES_TAILLOW,
    },
    {
    .lvl = 28,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Robert2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 35,
    .species = SPECIES_NATU,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 35,
    .species = SPECIES_SWABLU,
    }
};

static const struct TrainerMon sParty_Robert3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 38,
    .species = SPECIES_NATU,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 38,
    .species = SPECIES_ALTARIA,
    }
};

static const struct TrainerMon sParty_Robert4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 41,
    .species = SPECIES_NATU,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 41,
    .species = SPECIES_ALTARIA,
    }
};

static const struct TrainerMon sParty_Robert5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_XATU,
    }
};

static const struct TrainerMon sParty_Alex[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_NATU,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Beck[] = {
    #ifdef CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_TROPIUS,
    }
    #else // CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_TOUCANNON,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Yasu[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_NINJASK,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_ACCELGOR,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Takashi[] = {
    #ifdef CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_NINJASK,
    },
    {
    .lvl = 28,
    .species = SPECIES_KOFFING,
    }
    #else // CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_NINJASK,
    },
    {
    .lvl = 28,
    .species = SPECIES_SALANDIT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Dianne[] = {
    {
    .lvl = 54,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SKILL_SWAP, MOVE_EARTHQUAKE, MOVE_NONE, MOVE_NONE}
    },
    {
    .lvl = 56,
    .species = SPECIES_LANTURN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDERBOLT, MOVE_EARTHQUAKE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Jani[] = {
    {
    .lvl = 29,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Lao1[] = {
    {
    .lvl = 19,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SMOG, MOVE_SELF_DESTRUCT}
    },
    {
    .lvl = 19,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SMOG, MOVE_SELF_DESTRUCT}
    },
    {
    .lvl = 19,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    }
};

static const struct TrainerMon sParty_Lung[] = {
    {
    .lvl = 20,
    .species = SPECIES_KOFFING,
    },
    {
    .lvl = 20,
    .species = SPECIES_NINJASK,
    }
};

static const struct TrainerMon sParty_Lao2[] = {
    {
    .lvl = 27,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .lvl = 27,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .lvl = 27,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .lvl = 29,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Lao3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 30,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 30,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 30,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Lao4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Lao5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_KOFFING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_KOFFING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_KOFFING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 38,
    .species = SPECIES_WEEZING,
    .heldItem = ITEM_SMOKE_BALL,
    .moves = {MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Jocelyn[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 18,
    .species = SPECIES_MEDITITE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 18,
    .species = SPECIES_PANCHAM,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Laura[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 17,
    .species = SPECIES_MEDITITE,
    }
};

static const struct TrainerMon sParty_Cyndy1[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 20,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 20,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Cora[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 30,
    .species = SPECIES_MEDITITE,
    }
};

static const struct TrainerMon sParty_Paula[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 30,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Cyndy2[] = {
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 29,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Cyndy3[] = {
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 32,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Cyndy4[] = {
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 35,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Cyndy5[] = {
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 38,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 38,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Madeline1[] = {
    {
    .lvl = 22,
    .species = SPECIES_NUMEL,
    .moves = {MOVE_EMBER, MOVE_TACKLE, MOVE_MAGNITUDE, MOVE_SUNNY_DAY}
    }
};

static const struct TrainerMon sParty_Clarissa[] = {
    #ifdef CANON_MODE
    {
    .lvl = 31,
    .species = SPECIES_ROSELIA,
    },
    {
    .lvl = 31,
    .species = SPECIES_WAILMER,
    }
    #else // CANON_MODE
    {
    .lvl = 31,
    .species = SPECIES_ROSELIA,
    },
    {
    .lvl = 31,
    .species = SPECIES_LILLIGANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Angelica[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 33,
    .species = SPECIES_CASTFORM_NORMAL,
    .moves = {MOVE_RAIN_DANCE, MOVE_WEATHER_BALL, MOVE_THUNDER, MOVE_WATER_PULSE}
    }
};

static const struct TrainerMon sParty_Madeline2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 32,
    .species = SPECIES_NUMEL,
    .moves = {MOVE_EMBER, MOVE_TACKLE, MOVE_MAGNITUDE, MOVE_SUNNY_DAY}
    }
};

static const struct TrainerMon sParty_Madeline3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 35,
    .species = SPECIES_NUMEL,
    .moves = {MOVE_EMBER, MOVE_TAKE_DOWN, MOVE_MAGNITUDE, MOVE_SUNNY_DAY}
    }
};

static const struct TrainerMon sParty_Madeline4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_LEECH_SEED, MOVE_MEGA_DRAIN, MOVE_GRASS_WHISTLE, MOVE_SUNNY_DAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_NUMEL,
    .moves = {MOVE_FLAMETHROWER, MOVE_TAKE_DOWN, MOVE_MAGNITUDE, MOVE_SUNNY_DAY}
    }
};

static const struct TrainerMon sParty_Madeline5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_CAMERUPT,
    .moves = {MOVE_FLAMETHROWER, MOVE_TAKE_DOWN, MOVE_EARTHQUAKE, MOVE_SUNNY_DAY}
    }
};

static const struct TrainerMon sParty_Beverly[] = {
    #ifdef CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 28,
    .species = SPECIES_WAILMER,
    }
    #else // CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_SHELLOS_WEST_SEA,
    },
    {
    .lvl = 28,
    .species = SPECIES_WAILMER,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Imani[] = {
    {
    .lvl = 29,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Kyla[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_WAILMER,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_BASCULIN_BLUE_STRIPED
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Denise[] = {
    #ifdef CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 28,
    .species = SPECIES_GOLDEEN,
    }
    #else // CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_DUCKLETT,
    },
    {
    .lvl = 28,
    .species = SPECIES_GOLDEEN,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Beth[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_GOLDEEN,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_MANTYKE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Tara[] = {
    {
    .lvl = 28,
    .species = SPECIES_HORSEA,
    },
    {
    .lvl = 28,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Missy[] = {
    {
    .lvl = 29,
    .species = SPECIES_GOLDEEN,
    }
};

static const struct TrainerMon sParty_Alice[] = {
    #ifdef CANON_MODE
    {
    .lvl = 27,
    .species = SPECIES_GOLDEEN,
    },
    {
    .lvl = 27,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 27,
    .species = SPECIES_GOLDEEN,
    }
    #else // CANON_MODE
    {
    .lvl = 27,
    .species = SPECIES_DUCKLETT,
    },
    {
    .lvl = 27,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 27,
    .species = SPECIES_GOLDEEN,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jenny1[] = {
    {
    .lvl = 37,
    .species = SPECIES_WAILMER,
    }
};

static const struct TrainerMon sParty_Grace[] = {
    {
    .lvl = 37,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Tanya[] = {
    {
    .lvl = 37,
    .species = SPECIES_LUVDISC,
    }
};

static const struct TrainerMon sParty_Sharon[] = {
    #ifdef CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_SEAKING,
    }
    #else // CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_BRUXISH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nikki[] = {
    {
    .lvl = 36,
    .species = SPECIES_MARILL,
    },
    {
    .lvl = 36,
    .species = SPECIES_SPHEAL,
    }
};

static const struct TrainerMon sParty_Brenda[] = {
    #ifdef CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_GOLDEEN,
    }
    #else // CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_BRUXISH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Katie[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_GOLDEEN,
    },
    {
    .lvl = 36,
    .species = SPECIES_SPHEAL,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_MANTYKE,
    },
    {
    .lvl = 36,
    .species = SPECIES_SPHEAL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Susie[] = {
    {
    .lvl = 37,
    .species = SPECIES_LUVDISC,
    }
};

static const struct TrainerMon sParty_Kara[] = {
    #ifdef CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_SEAKING,
    }
    #else // CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_ALOMOMOLA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Dana[] = {
    {
    .lvl = 37,
    .species = SPECIES_AZUMARILL,
    }
};

static const struct TrainerMon sParty_Sienna[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_LUVDISC,
    },
    {
    .lvl = 36,
    .species = SPECIES_LUVDISC,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_LUVDISC,
    },
    {
    .lvl = 36,
    .species = SPECIES_ALOMOMOLA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Debra[] = {
    {
    .lvl = 37,
    .species = SPECIES_SEAKING,
    }
};

static const struct TrainerMon sParty_Linda[] = {
    {
    .lvl = 36,
    .species = SPECIES_HORSEA,
    },
    {
    .lvl = 36,
    .species = SPECIES_SEADRA,
    }
};

static const struct TrainerMon sParty_Kaylee[] = {
    {
    .lvl = 37,
    .species = SPECIES_LANTURN,
    },
    {
    .lvl = 37,
    .species = SPECIES_PELIPPER,
    }
};

static const struct TrainerMon sParty_Laurel[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_LUVDISC,
    },
    {
    .lvl = 36,
    .species = SPECIES_LUVDISC,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_LUVDISC,
    },
    {
    .lvl = 36,
    .species = SPECIES_ALOMOMOLA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Carlee[] = {
    {
    .lvl = 38,
    .species = SPECIES_SEAKING,
    }
};

static const struct TrainerMon sParty_Jenny2[] = {
    {
    .lvl = 41,
    .species = SPECIES_WAILMER,
    }
};

static const struct TrainerMon sParty_Jenny3[] = {
    {
    .lvl = 45,
    .species = SPECIES_WAILMER,
    }
};

static const struct TrainerMon sParty_Jenny4[] = {
    {
    .lvl = 47,
    .species = SPECIES_STARYU,
    },
    {
    .lvl = 47,
    .species = SPECIES_WAILMER,
    }
};

static const struct TrainerMon sParty_Jenny5[] = {
    {
    .lvl = 50,
    .species = SPECIES_LUVDISC,
    },
    {
    .lvl = 50,
    .species = SPECIES_WAILMER,
    },
    {
    .lvl = 50,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Heidi[] = {
    {
    .lvl = 25,
    .species = SPECIES_SANDSHREW,
    .moves = {MOVE_DIG, MOVE_SAND_ATTACK, MOVE_POISON_STING, MOVE_SLASH}
    },
    {
    .lvl = 25,
    .species = SPECIES_BALTOY,
    .moves = {MOVE_RAPID_SPIN, MOVE_MUD_SLAP, MOVE_PSYBEAM, MOVE_ROCK_TOMB}
    }
};

static const struct TrainerMon sParty_Becky[] = {
    #ifdef CANON_MODE
    {
    .lvl = 25,
    .species = SPECIES_SANDSHREW,
    .moves = {MOVE_SAND_ATTACK, MOVE_POISON_STING, MOVE_SLASH, MOVE_DIG}
    },
    {
    .lvl = 25,
    .species = SPECIES_MARILL,
    .moves = {MOVE_ROLLOUT, MOVE_BUBBLE_BEAM, MOVE_TAIL_WHIP, MOVE_DEFENSE_CURL}
    }
    #else // CANON_MODE
    {
    .lvl = 25,
    .species = SPECIES_HIPPOPOTAS,
    },
    {
    .lvl = 25,
    .species = SPECIES_MARACTUS,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Carol[] = {
    #ifdef CANON_MODE
    {
    .lvl = 19,
    .species = SPECIES_TAILLOW,
    },
    {
    .lvl = 19,
    .species = SPECIES_LOMBRE,
    }
    #else // CANON_MODE
    {
    .lvl = 19,
    .species = SPECIES_FLETCHINDER,
    },
    {
    .lvl = 19,
    .species = SPECIES_CACNEA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nancy[] = {
    #ifdef CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_MARILL,
    },
    {
    .lvl = 20,
    .species = SPECIES_LOMBRE,
    }
    #else // CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_WHIMSICOTT,
    },
    {
    .lvl = 20,
    .species = SPECIES_LOMBRE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Martha[] = {
    {
    .lvl = 26,
    .species = SPECIES_SKITTY,
    },
    {
    .lvl = 26,
    .species = SPECIES_SWABLU,
    }
};

static const struct TrainerMon sParty_Diana1[] = {
    {
    .lvl = 22,
    .species = SPECIES_SHROOMISH,
    },
    {
    .lvl = 22,
    .species = SPECIES_ODDISH,
    },
    {
    .lvl = 22,
    .species = SPECIES_SWABLU,
    }
};

static const struct TrainerMon sParty_Cedric[] = {
    {
    .lvl = 35,
    .species = SPECIES_WOBBUFFET,
    .moves = {MOVE_DESTINY_BOND, MOVE_SAFEGUARD, MOVE_COUNTER, MOVE_MIRROR_COAT}
    }
};

static const struct TrainerMon sParty_Irene[] = {
    #ifdef CANON_MODE
    {
    .lvl = 19,
    .species = SPECIES_SHROOMISH,
    },
    {
    .lvl = 19,
    .species = SPECIES_MARILL,
    }
    #else // CANON_MODE
    {
    .lvl = 19,
    .species = SPECIES_HIPPOPOTAS,
    },
    {
    .lvl = 19,
    .species = SPECIES_MARILL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Diana2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_SWABLU,
    }
};

static const struct TrainerMon sParty_Diana3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_SWABLU,
    }
};

static const struct TrainerMon sParty_Diana4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_SWABLU,
    }
};

static const struct TrainerMon sParty_Diana5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 44,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 44,
    .species = SPECIES_VILEPLUME,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 44,
    .species = SPECIES_ALTARIA,
    }
};

static const struct TrainerMon sParty_AmyAndLiv1[] = {
    {
    .lvl = 17,
    .species = SPECIES_PLUSLE,
    },
    {
    .lvl = 17,
    .species = SPECIES_MINUN,
    }
};

static const struct TrainerMon sParty_AmyAndLiv2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 30,
    .species = SPECIES_PLUSLE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 30,
    .species = SPECIES_MINUN,
    }
};

static const struct TrainerMon sParty_GinaAndMia1[] = {
    {
    .lvl = 6,
    .species = SPECIES_SEEDOT,
    },
    {
    .lvl = 6,
    .species = SPECIES_LOTAD,
    }
};

static const struct TrainerMon sParty_MiuAndYuki[] = {
    {
    .lvl = 29,
    .species = SPECIES_BEAUTIFLY,
    },
    {
    .lvl = 29,
    .species = SPECIES_DUSTOX,
    }
};

static const struct TrainerMon sParty_AmyAndLiv3[] = {
    {
    .lvl = 10,
    .species = SPECIES_PLUSLE,
    },
    {
    .lvl = 10,
    .species = SPECIES_MINUN,
    }
};

static const struct TrainerMon sParty_GinaAndMia2[] = {
    {
    .lvl = 11,
    .species = SPECIES_DUSKULL,
    .moves = {MOVE_NIGHT_SHADE, MOVE_DISABLE, MOVE_NONE, MOVE_NONE}
    },
    {
    .lvl = 11,
    .species = SPECIES_SHROOMISH,
    .moves = {MOVE_ABSORB, MOVE_LEECH_SEED, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_AmyAndLiv4[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 33,
    .species = SPECIES_PLUSLE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 33,
    .species = SPECIES_MINUN,
    }
};

static const struct TrainerMon sParty_AmyAndLiv5[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 36,
    .species = SPECIES_PLUSLE,
    .moves = {MOVE_SPARK, MOVE_CHARGE, MOVE_FAKE_TEARS, MOVE_HELPING_HAND}
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 36,
    .species = SPECIES_MINUN,
    .moves = {MOVE_SPARK, MOVE_CHARGE, MOVE_CHARM, MOVE_HELPING_HAND}
    }
};

static const struct TrainerMon sParty_AmyAndLiv6[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 39,
    .species = SPECIES_PLUSLE,
    .moves = {MOVE_THUNDER, MOVE_CHARGE, MOVE_FAKE_TEARS, MOVE_HELPING_HAND}
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 39,
    .species = SPECIES_MINUN,
    .moves = {MOVE_THUNDER, MOVE_CHARGE, MOVE_CHARM, MOVE_HELPING_HAND}
    }
};

static const struct TrainerMon sParty_Huey[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 14,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 14,
    .species = SPECIES_MACHOP,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 14,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 14,
    .species = SPECIES_TIMBURR,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Edmond[] = {
    {
    .lvl = 15,
    .species = SPECIES_WINGULL,
    }
};

static const struct TrainerMon sParty_Ernest1[] = {
    {
    .lvl = 36,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 36,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Dwayne[] = {
    {
    .lvl = 12,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 12,
    .species = SPECIES_MACHOP,
    },
    {
    .lvl = 12,
    .species = SPECIES_TENTACOOL,
    }
};

static const struct TrainerMon sParty_Phillip[] = {
    {
    .lvl = 48,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .lvl = 48,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Leonard[] = {
    {
    .lvl = 47,
    .species = SPECIES_MACHOP,
    },
    {
    .lvl = 47,
    .species = SPECIES_PELIPPER,
    },
    {
    .lvl = 47,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Duncan[] = {
    {
    .lvl = 28,
    .species = SPECIES_SPHEAL,
    },
    {
    .lvl = 28,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Ernest2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 39,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 39,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 39,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Ernest3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Ernest4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 46,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 46,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 46,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Ernest5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 50,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 50,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 50,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Eli[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_NUMEL,
    }
};

static const struct TrainerMon sParty_Annika[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_FEEBAS,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_FLAIL, MOVE_WATER_PULSE, MOVE_RETURN, MOVE_ATTRACT}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_FEEBAS,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_FLAIL, MOVE_WATER_PULSE, MOVE_RETURN, MOVE_ATTRACT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 54,
    .species = SPECIES_WIMPOD,
    .heldItem = ITEM_ORAN_BERRY,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 55,
    .species = SPECIES_GOLISOPOD,
    .heldItem = ITEM_ORAN_BERRY,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jazmyn[] = {
    {
    .lvl = 30,
    .species = SPECIES_ABSOL,
    }
};

static const struct TrainerMon sParty_Jonas[] = {
    {
    .lvl = 34,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TOXIC, MOVE_THUNDER, MOVE_SELF_DESTRUCT, MOVE_SLUDGE_BOMB}
    }
};

static const struct TrainerMon sParty_Kayley[] = {
    {
    .lvl = 34,
    .species = SPECIES_CASTFORM_NORMAL,
    .moves = {MOVE_SUNNY_DAY, MOVE_WEATHER_BALL, MOVE_FLAMETHROWER, MOVE_SOLAR_BEAM}
    }
};

static const struct TrainerMon sParty_Auron[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_MANECTRIC,
    },
    {
    .lvl = 36,
    .species = SPECIES_MACHAMP,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_HONCHKROW,
    },
    {
    .lvl = 36,
    .species = SPECIES_MISMAGIUS,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Kelvin[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SPHEAL,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_GURDURR,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SPHEAL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Marley[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 37,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BITE, MOVE_ROAR, MOVE_THUNDER_WAVE, MOVE_THUNDERBOLT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 37,
    .species = SPECIES_ARAQUANID,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Reyna[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 36,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 36,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Hudson[] = {
    #ifdef CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_WAILMER,
    }
    #else // CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_GASTRODON_EAST_SEA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Conor[] = {
    {
    .lvl = 36,
    .species = SPECIES_CHINCHOU,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 36,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Edwin1[] = {
    {
    .lvl = 16,
    .species = SPECIES_LOMBRE,
    },
    {
    .lvl = 16,
    .species = SPECIES_NUZLEAF,
    }
};

static const struct TrainerMon sParty_Hector[] = {
    {
    .lvl = 20,
    .species = SPECIES_ZANGOOSE,
    },
    {
    .lvl = 20,
    .species = SPECIES_SEVIPER,
    }
};

static const struct TrainerMon sParty_CourtneyMossdeep[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 41,
    .species = SPECIES_CAMERUPT,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 43,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 44,
    .species = SPECIES_WEEZING,
    }
};

static const struct TrainerMon sParty_Edwin2[] = {
    {
    .lvl = 29,
    .species = SPECIES_LOMBRE,
    },
    {
    .lvl = 29,
    .species = SPECIES_NUZLEAF,
    }
};

static const struct TrainerMon sParty_Edwin3[] = {
    {
    .lvl = 32,
    .species = SPECIES_LOMBRE,
    },
    {
    .lvl = 32,
    .species = SPECIES_NUZLEAF,
    }
};

static const struct TrainerMon sParty_Edwin4[] = {
    {
    .lvl = 35,
    .species = SPECIES_LOMBRE,
    },
    {
    .lvl = 35,
    .species = SPECIES_NUZLEAF,
    }
};

static const struct TrainerMon sParty_Edwin5[] = {
    {
    .lvl = 38,
    .species = SPECIES_LUDICOLO,
    },
    {
    .lvl = 38,
    .species = SPECIES_SHIFTRY,
    }
};

static const struct TrainerMon sParty_WallyVR1[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 56,
    .species = SPECIES_ALTARIA,
    .moves = {MOVE_AERIAL_ACE, MOVE_SAFEGUARD, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 57,
    .species = SPECIES_DELCATTY,
    .moves = {MOVE_SING, MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 58,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_MAGICAL_LEAF, MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 58,
    .species = SPECIES_MAGNETON,
    .moves = {MOVE_SUPERSONIC, MOVE_THUNDERBOLT, MOVE_TRI_ATTACK, MOVE_SCREECH}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 60,
    .species = SPECIES_GARDEVOIR,
    .moves = {MOVE_MOONBLAST, MOVE_CALM_MIND, MOVE_PSYCHIC, MOVE_FUTURE_SIGHT}
    }
};

static const struct TrainerMon sParty_Kahili[] = {
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 25,
    .species = SPECIES_RUFFLET,
    .heldItem = ITEM_EVIOLITE,
    .moves = {MOVE_AERIAL_ACE, MOVE_FACADE, MOVE_BULK_UP, MOVE_ROOST}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 26,
    .species = SPECIES_ORICORIO,
    .heldItem = ITEM_SHARP_BEAK,
    .moves = {MOVE_REVELATION_DANCE, MOVE_AIR_CUTTER, MOVE_FEATHER_DANCE, MOVE_TAILWIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 26,
    .species = SPECIES_HAWLUCHA,
    .heldItem = ITEM_IAPAPA_BERRY,
    .moves = {MOVE_ACROBATICS, MOVE_LOW_SWEEP, MOVE_BULK_UP, MOVE_ROOST}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 28,
    .species = SPECIES_TRUMBEAK,
    .heldItem = ITEM_SHELL_BELL,
    .moves = {MOVE_BULLET_SEED, MOVE_BRICK_BREAK, MOVE_BEAK_BLAST, MOVE_U_TURN}
    }
};

static const struct TrainerMon sParty_KahiliPostGame[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 76,
    .species = SPECIES_ORICORIO,
    .heldItem = ITEM_SHARP_BEAK,
    .moves = {MOVE_REVELATION_DANCE, MOVE_TEETER_DANCE, MOVE_AIR_SLASH, MOVE_TAILWIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 76,
    .species = SPECIES_HAWLUCHA,
    .heldItem = ITEM_IAPAPA_BERRY,
    .moves = {MOVE_ACROBATICS, MOVE_FLYING_PRESS, MOVE_DUAL_CHOP, MOVE_POISON_JAB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 77,
    .species = SPECIES_BRAVIARY,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_CRUSH_CLAW, MOVE_BRAVE_BIRD, MOVE_SUPERPOWER, MOVE_ROOST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 77,
    .species = SPECIES_MANDIBUZZ,
    .heldItem = ITEM_HEAVY_DUTY_BOOTS,
    .moves = {MOVE_SNARL, MOVE_AIR_SLASH, MOVE_TOXIC, MOVE_ROOST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 78,
    .species = SPECIES_TOUCANNON,
    .heldItem = ITEM_FLYINIUM_Z,
    .moves = {MOVE_BULLET_SEED, MOVE_BRICK_BREAK, MOVE_BEAK_BLAST, MOVE_ROCK_BLAST}
    }
};

static const struct TrainerMon sParty_Bruno[] = {
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 43,
    .species = SPECIES_HITMONCHAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_RAPID_SPIN, MOVE_THROAT_CHOP}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 43,
    .species = SPECIES_HITMONLEE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BULK_UP, MOVE_DOUBLE_KICK, MOVE_KNOCK_OFF, MOVE_POISON_JAB}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 44,
    .species = SPECIES_FALINKS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRST_IMPRESSION, MOVE_BRICK_BREAK, MOVE_ROCK_SLIDE, MOVE_IRON_HEAD}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 44,
    .species = SPECIES_TOXICROAK,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 45,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAIN_PUNCH, MOVE_FACADE, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH}
    }
};

static const struct TrainerMon sParty_BrunoPostGame[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 76,
    .species = SPECIES_HITMONCHAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_RAPID_SPIN, MOVE_THROAT_CHOP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 76,
    .species = SPECIES_HITMONLEE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BULK_UP, MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_POISON_JAB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 77,
    .species = SPECIES_FALINKS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRST_IMPRESSION, MOVE_CLOSE_COMBAT, MOVE_ROCK_SLIDE, MOVE_IRON_HEAD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 77,
    .species = SPECIES_TOXICROAK,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_GUNK_SHOT, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 77,
    .species = SPECIES_HAWLUCHA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CLOSE_COMBAT, MOVE_ACROBATICS, MOVE_FIRE_PUNCH, MOVE_SUBSTITUTE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 78,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_FLAME_ORB,
    .moves = {MOVE_CLOSE_COMBAT, MOVE_FACADE, MOVE_KNOCK_OFF, MOVE_BULLET_PUNCH}
    }
};

static const struct TrainerMon sParty_PhoebeMtPyre[] = {
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 58,
    .species = SPECIES_SABLEYE,
    .heldItem = ITEM_NONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 58,
    .species = SPECIES_BANETTE,
    .heldItem = ITEM_NONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 59,
    .species = SPECIES_ZOROARK_HISUIAN,
    .heldItem = ITEM_NONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 59,
    .species = SPECIES_SHEDINJA,
    .heldItem = ITEM_NONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 60,
    .species = SPECIES_DUSCLOPS,
    .heldItem = ITEM_NONE,
    }
};

static const struct TrainerMon sParty_PhoebesGrandma[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_BANETTE,
    .heldItem = ITEM_NONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_ZOROARK_HISUIAN,
    .heldItem = ITEM_NONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_SHEDINJA,
    .heldItem = ITEM_NONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 75,
    .species = SPECIES_CHANDELURE,
    .heldItem = ITEM_NONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 76,
    .species = SPECIES_DUSCLOPS,
    .heldItem = ITEM_EVIOLITE,
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 76,
    .species = SPECIES_SPIRITOMB,
    .heldItem = ITEM_NONE,
    }
};

static const struct TrainerMon sParty_BrendanRoute103Mudkip[] = {
    {
    .lvl = 5,
    .species = SPECIES_TREECKO,
    }
};

static const struct TrainerMon sParty_BrendanRoute110Mudkip[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_GROVYLE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 20,
    .species = SPECIES_STUFFUL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 23,
    .species = SPECIES_GROVYLE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_BrendanRoute119Mudkip[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SCEPTILE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_BEWEAR,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SCEPTILE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_BrendanRoute103Treecko[] = {
    {
    .lvl = 5,
    .species = SPECIES_TORCHIC,
    }
};

static const struct TrainerMon sParty_BrendanRoute110Treecko[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_COMBUSKEN,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 20,
    .species = SPECIES_STUFFUL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 23,
    .species = SPECIES_COMBUSKEN,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_BrendanRoute119Treecko[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_BLAZIKEN,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_BEWEAR,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_BLAZIKEN,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_BrendanRoute103Torchic[] = {
    {
    .lvl = 5,
    .species = SPECIES_MUDKIP,
    }
};

static const struct TrainerMon sParty_BrendanRoute110Torchic[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_MARSHTOMP,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 20,
    .species = SPECIES_STUFFUL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 23,
    .species = SPECIES_MARSHTOMP,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_BrendanRoute119Torchic[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SWAMPERT,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_BEWEAR,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SWAMPERT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_MayRoute103Mudkip[] = {
    {
    .lvl = 5,
    .species = SPECIES_TREECKO,
    }
};

static const struct TrainerMon sParty_MayRoute110Mudkip[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_GROVYLE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 20,
    .species = SPECIES_STUFFUL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 23,
    .species = SPECIES_GROVYLE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_MayRoute119Mudkip[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SCEPTILE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_BEWEAR,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SCEPTILE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_MayRoute103Treecko[] = {
    {
    .lvl = 5,
    .species = SPECIES_TORCHIC,
    }
};

static const struct TrainerMon sParty_MayRoute110Treecko[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_COMBUSKEN,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 20,
    .species = SPECIES_STUFFUL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 23,
    .species = SPECIES_COMBUSKEN,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_MayRoute119Treecko[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_BLAZIKEN,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_BEWEAR,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_BLAZIKEN,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_MayRoute103Torchic[] = {
    {
    .lvl = 5,
    .species = SPECIES_MUDKIP,
    }
};

static const struct TrainerMon sParty_MayRoute110Torchic[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 22,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_MARSHTOMP,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 20,
    .species = SPECIES_STUFFUL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 21,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 23,
    .species = SPECIES_MARSHTOMP,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_MayRoute119Torchic[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SWAMPERT,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_BEWEAR,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 34,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 36,
    .species = SPECIES_SWAMPERT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Isaac1[] = {
    {
    .lvl = 12,
    .species = SPECIES_WHISMUR,
    },
    {
    .lvl = 12,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .lvl = 12,
    .species = SPECIES_ARON,
    },
    {
    .lvl = 12,
    .species = SPECIES_POOCHYENA,
    },
    {
    .lvl = 12,
    .species = SPECIES_TAILLOW,
    },
    {
    .lvl = 12,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Davis[] = {
    {
    .lvl = 30,
    .species = SPECIES_PINSIR,
    }
};

static const struct TrainerMon sParty_Mitchell[] = {
    {
    .lvl = 55,
    .species = SPECIES_LUNATONE,
    .moves = {MOVE_EXPLOSION, MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_PSYCHIC}
    },
    {
    .lvl = 56,
    .species = SPECIES_SOLROCK,
    .moves = {MOVE_EXPLOSION, MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_SHADOW_BALL}
    }
};

static const struct TrainerMon sParty_Isaac2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_ARON,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Isaac3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_ARON,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Isaac4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_ARON,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Isaac5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_LAIRON,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Lydia1[] = {
    {
    .lvl = 12,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 12,
    .species = SPECIES_SHROOMISH,
    },
    {
    .lvl = 12,
    .species = SPECIES_MARILL,
    },
    {
    .lvl = 12,
    .species = SPECIES_ROSELIA,
    },
    {
    .lvl = 12,
    .species = SPECIES_SKITTY,
    },
    {
    .lvl = 12,
    .species = SPECIES_GOLDEEN,
    }
};

static const struct TrainerMon sParty_Halle[] = {
    #ifdef CANON_MODE
    {
    .lvl = 55,
    .species = SPECIES_SABLEYE,
    },
    {
    .lvl = 56,
    .species = SPECIES_ABSOL,
    }
    #else // CANON_MODE
    {
    .lvl = 55,
    .species = SPECIES_SABLEYE,
    },
    {
    .lvl = 56,
    .species = SPECIES_MALAMAR,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Garrison[] = {
    {
    .lvl = 29,
    .species = SPECIES_SANDSLASH,
    }
};

static const struct TrainerMon sParty_Lydia2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_MARILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_SKITTY,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 25,
    .species = SPECIES_GOLDEEN,
    }
};

static const struct TrainerMon sParty_Lydia3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_MARILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_DELCATTY,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 28,
    .species = SPECIES_GOLDEEN,
    }
};

static const struct TrainerMon sParty_Lydia4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_MARILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_DELCATTY,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 31,
    .species = SPECIES_GOLDEEN,
    }
};

static const struct TrainerMon sParty_Lydia5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_DELCATTY,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 34,
    .species = SPECIES_SEAKING,
    }
};

static const struct TrainerMon sParty_Jackson1[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 30,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Lorenzo[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 31,
    .species = SPECIES_SEEDOT,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 31,
    .species = SPECIES_NUZLEAF,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 31,
    .species = SPECIES_LOMBRE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 30,
    .species = SPECIES_SHINX,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 32,
    .species = SPECIES_LUXIO,
    },
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Sebastian[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 42,
    .species = SPECIES_CACTURNE,
    }
};

static const struct TrainerMon sParty_Jackson2[] = {
    {
    .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
    .lvl = 34,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Jackson3[] = {
    {
    .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
    .lvl = 37,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Jackson4[] = {
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 40,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Jackson5[] = {
    {
    .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
    .lvl = 42,
    .species = SPECIES_KECLEON,
    },
    {
    .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
    .lvl = 42,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Catherine1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 29,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 29,
    .species = SPECIES_ROSELIA,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 29,
    .species = SPECIES_STEENEE,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 29,
    .species = SPECIES_LEAVANNY,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jenna[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 31,
    .species = SPECIES_LOTAD,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 31,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 31,
    .species = SPECIES_NUZLEAF,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 30,
    .species = SPECIES_AIPOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 32,
    .species = SPECIES_AMBIPOM,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Sophia[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 41,
    .species = SPECIES_SWABLU,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 41,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Catherine2[] = {
    {
    .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
    .lvl = 33,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
    .lvl = 33,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Catherine3[] = {
    {
    .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
    .lvl = 36,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
    .lvl = 36,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Catherine4[] = {
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 39,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 39,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Catherine5[] = {
    {
    .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
    .lvl = 42,
    .species = SPECIES_BELLOSSOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
    .lvl = 42,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Julio[] = {
    {
    .lvl = 24,
    .species = SPECIES_MAGNEMITE,
    }
};

static const struct TrainerMon sParty_GruntSeafloorCavern5[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 38,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 38,
    .species = SPECIES_GOLBAT,
    }
};

static const struct TrainerMon sParty_GruntUnused[] = {
    {
    .lvl = 34,
    .species = SPECIES_WAILMER,
    },
    {
    .lvl = 34,
    .species = SPECIES_ZUBAT,
    }
};

static const struct TrainerMon sParty_GruntMtPyre4[] = {
    {
    .lvl = 35,
    .species = SPECIES_WAILMER,
    },
    {
    .lvl = 36,
    .species = SPECIES_GOLBAT,
    }
};

static const struct TrainerMon sParty_GruntJaggedPass[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 25,
    .species = SPECIES_POOCHYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 25,
    .species = SPECIES_NUMEL,
    }
};

static const struct TrainerMon sParty_Marc[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 10,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 10,
    .species = SPECIES_GEODUDE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 10,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 10,
    .species = SPECIES_ROCKRUFF,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brenden[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 18,
    .species = SPECIES_MACHOP,
    }
};

static const struct TrainerMon sParty_Lilith[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 17,
    .species = SPECIES_MEDITITE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 17,
    .species = SPECIES_MIENFOO,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Cristian[] = {
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 18,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Sylvia[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 42,
    .species = SPECIES_MEDITITE,
    }
};

static const struct TrainerMon sParty_Leonardo[] = {
    {
    .lvl = 37,
    .species = SPECIES_CARVANHA,
    }
};

static const struct TrainerMon sParty_Athena[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER, MOVE_THUNDER_WAVE, MOVE_QUICK_ATTACK, MOVE_NONE}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 35,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_THIEF, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Harrison[] = {
    #ifdef CANON_MODE
    {
    .lvl = 38,
    .species = SPECIES_TENTACRUEL,
    }
    #else // CANON_MODE
    {
    .lvl = 38,
    .species = SPECIES_JELLICENT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_GruntMtChimney2[] = {
    #ifdef CANON_MODE
    {
    .lvl = 25,
    .species = SPECIES_ZUBAT,
    }
    #else // CANON_MODE
    {
    .lvl = 25,
    .species = SPECIES_SIZZLIPEDE,
    } 
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Clarence[] = {
    {
    .lvl = 37,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Terry[] = {
    {
    .lvl = 40,
    .species = SPECIES_GIRAFARIG,
    }
};

static const struct TrainerMon sParty_Nate[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 42,
    .species = SPECIES_SPOINK,
    }
};

static const struct TrainerMon sParty_Kathleen[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 42,
    .species = SPECIES_ALAKAZAM,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 42,
    .species = SPECIES_GOTHITELLE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Clifford[] = {
    #ifdef CANON_MODE
    {
    .lvl = 42,
    .species = SPECIES_GIRAFARIG,
    }
    #else // CANON_MODE
    {
    .lvl = 42,
    .species = SPECIES_GOTHITELLE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Nicholas[] = {
    {
    .lvl = 41,
    .species = SPECIES_WOBBUFFET,
    }
};

static const struct TrainerMon sParty_GruntSpaceCenter3[] = {
    {
    .lvl = 34,
    .species = SPECIES_GOLBAT,
    },
    {
    .lvl = 35,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_GruntSpaceCenter4[] = {
    {
    .lvl = 36,
    .species = SPECIES_CLAYDOL,
    }
};

static const struct TrainerMon sParty_GruntSpaceCenter5[] = {
    {
    .lvl = 36,
    .species = SPECIES_CROBAT,
    }
};

static const struct TrainerMon sParty_GruntSpaceCenter6[] = {
    {
    .lvl = 37,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_GruntSpaceCenter7[] = {
    {
    .lvl = 37,
    .species = SPECIES_CLAYDOL,
    }
};

static const struct TrainerMon sParty_Macey[] = {
    #ifdef CANON_MODE
    {
    .lvl = 39,
    .species = SPECIES_NATU,
    }
    #else // CANON_MODE
    {
    .lvl = 39,
    .species = SPECIES_GALLADE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_BrendanRustboroTreecko[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 15,
    .species = SPECIES_LOTAD,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 17,
    .species = SPECIES_TORCHIC,
    }
};

static const struct TrainerMon sParty_BrendanRustboroMudkip[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 15,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 17,
    .species = SPECIES_TREECKO,
    }
};

static const struct TrainerMon sParty_Paxton[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_SWELLOW,
    },
    {
    .lvl = 36,
    .species = SPECIES_BRELOOM,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_FEAROW,
    },
    {
    .lvl = 36,
    .species = SPECIES_GRAPPLOCT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Isabella[] = {
    {
    .lvl = 37,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_GruntWeatherInst5[] = {
    {
    .lvl = 30,
    .species = SPECIES_ZUBAT,
    },
    {
    .lvl = 30,
    .species = SPECIES_GRIMER,
    }
};

static const struct TrainerMon sParty_CourtneyMtChimney[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 27,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 28,
    .species = SPECIES_KOFFING,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 29,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 29,
    .species = SPECIES_GOLBAT,
    }
};

static const struct TrainerMon sParty_Jonathan[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_KECLEON,
    },
    {
    .lvl = 36,
    .species = SPECIES_LOUDRED,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_KECLEON,
    },
    {
    .lvl = 36,
    .species = SPECIES_BOUFFALANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_BrendanRustboroTorchic[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 15,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 17,
    .species = SPECIES_MUDKIP,
    }
};

static const struct TrainerMon sParty_MayRustboroMudkip[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 15,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 17,
    .species = SPECIES_TREECKO,
    }
};

static const struct TrainerMon sParty_MaxieMagmaHideout[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 41,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 42,
    .species = SPECIES_CROBAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 43,
    .species = SPECIES_CAMERUPT,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 41,
    .species = SPECIES_CENTISKORCH,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 42,
    .species = SPECIES_CROBAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 43,
    .species = SPECIES_CAMERUPT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_MaxieMtChimney[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 30,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 30,
    .species = SPECIES_GOLBAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 32,
    .species = SPECIES_CAMERUPT,
    }
};

static const struct TrainerMon sParty_Tiana[] = {
    #ifdef CANON_MODE
    {
    .lvl = 4,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .lvl = 5,
    .species = SPECIES_SHROOMISH,
    }
    #else // CANON_MODE
    {
    .lvl = 4,
    .species = SPECIES_BUNEARY,
    },
    {
    .lvl = 5,
    .species = SPECIES_SHROOMISH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Haley1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 6,
    .species = SPECIES_LOTAD,
    },
    {
    .lvl = 7,
    .species = SPECIES_SHROOMISH,
    }
    #else // CANON_MODE
    {
    .lvl = 6,
    .species = SPECIES_LOTAD,
    },
    {
    .lvl = 7,
    .species = SPECIES_COTTONEE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Janice[] = {
    {
    .lvl = 10,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Vivi[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 17,
    .species = SPECIES_MARILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 17,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 17,
    .species = SPECIES_NUMEL,
    }
};

static const struct TrainerMon sParty_Haley2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_SHROOMISH,
    }
};

static const struct TrainerMon sParty_Haley3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Haley4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 35,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Haley5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 37,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Sally[] = {
    {
    .lvl = 18,
    .species = SPECIES_ODDISH,
    }
};

static const struct TrainerMon sParty_Robin[] = {
    {
    .lvl = 16,
    .species = SPECIES_SKITTY,
    },
    {
    .lvl = 16,
    .species = SPECIES_SHROOMISH,
    },
    {
    .lvl = 16,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Andrea[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_LUVDISC,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 56,
    .species = SPECIES_WHISCASH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Crissy[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 52,
    .species = SPECIES_GOLDEEN,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 52,
    .species = SPECIES_WAILMER,
    }
};

static const struct TrainerMon sParty_Lara[] = {
    #ifdef CANON_MODE
    {
    .lvl = 5,
    .species = SPECIES_SHROOMISH,
    },
    {
    .lvl = 5,
    .species = SPECIES_SEEDOT,
    }
    #else // CANON_MODE
    {
    .lvl = 5,
    .species = SPECIES_COTTONEE,
    },
    {
    .lvl = 5,
    .species = SPECIES_FLABEBE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Yose[] = {
    #ifdef CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_DODRIO,
    },
    {
    .lvl = 20,
    .species = SPECIES_TAUROS,
    }
    #else // CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_DODRIO,
    },
    {
    .lvl = 20,
    .species = SPECIES_BOUFFALANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Rick[] = {
    {
    .lvl = 4,
    .species = SPECIES_WURMPLE,
    },
    {
    .lvl = 5,
    .species = SPECIES_WURMPLE,
    }
};

static const struct TrainerMon sParty_Lyle[] = {
    #ifdef CANON_MODE
    {
    .lvl = 3,
    .species = SPECIES_WURMPLE,
    },
    {
    .lvl = 3,
    .species = SPECIES_WURMPLE,
    },
    {
    .lvl = 3,
    .species = SPECIES_WURMPLE,
    },
    {
    .lvl = 3,
    .species = SPECIES_WURMPLE,
    }
    #else // CANON_MODE
    {
    .lvl = 3,
    .species = SPECIES_WURMPLE,
    },
    {
    .lvl = 3,
    .species = SPECIES_SCATTERBUG,
    },
    {
    .lvl = 3,
    .species = SPECIES_WURMPLE,
    },
    {
    .lvl = 3,
    .species = SPECIES_SCATTERBUG,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jose[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 9,
    .species = SPECIES_WURMPLE,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 9,
    .species = SPECIES_NINCADA,
    }
};

static const struct TrainerMon sParty_Doug[] = {
    #ifdef CANON_MODE
    {
    .lvl = 31,
    .species = SPECIES_NINCADA,
    },
    {
    .lvl = 31,
    .species = SPECIES_NINJASK,
    }
    #else // CANON_MODE
    {
    .lvl = 31,
    .species = SPECIES_SWADLOON,
    },
    {
    .lvl = 31,
    .species = SPECIES_LEAVANNY,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Greg[] = {
    #ifdef CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_VOLBEAT,
    },
    {
    .lvl = 28,
    .species = SPECIES_ILLUMISE,
    }
    #else // CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_WORMADAM_PLANT_CLOAK,
    },
    {
    .lvl = 28,
    .species = SPECIES_MOTHIM,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Kent[] = {
    {
    .lvl = 28,
    .species = SPECIES_NINJASK,
    }
};

static const struct TrainerMon sParty_James1[] = {
    {
    .lvl = 6,
    .species = SPECIES_NINCADA,
    },
    {
    .lvl = 7,
    .species = SPECIES_NINCADA,
    }
};

static const struct TrainerMon sParty_James2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 30,
    .species = SPECIES_NINJASK,
    }
};

static const struct TrainerMon sParty_James3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_DUSTOX,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 32,
    .species = SPECIES_NINJASK,
    }
};

static const struct TrainerMon sParty_James4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_SURSKIT,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_DUSTOX,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 34,
    .species = SPECIES_NINJASK,
    }
};

static const struct TrainerMon sParty_James5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_SURSKIT,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_NINJASK,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_DUSTOX,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_NINJASK,
    }
};

static const struct TrainerMon sParty_Brice[] = {
    #ifdef CANON_MODE
    {
    .lvl = 19,
    .species = SPECIES_NUMEL,
    },
    {
    .lvl = 19,
    .species = SPECIES_MACHOP,
    }
    #else // CANON_MODE
    {
    .lvl = 19,
    .species = SPECIES_LITLEO,
    },
    {
    .lvl = 19,
    .species = SPECIES_MACHOP,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Trent1[] = {
    {
    .lvl = 18,
    .species = SPECIES_GEODUDE,
    },
    {
    .lvl = 19,
    .species = SPECIES_GEODUDE,
    },
    {
    .lvl = 18,
    .species = SPECIES_GEODUDE,
    }
};

static const struct TrainerMon sParty_Lenny[] = {
    #ifdef CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_GEODUDE,
    },
    {
    .lvl = 20,
    .species = SPECIES_MACHOP,
    }
    #else // CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_CARBINK,
    },
    {
    .lvl = 20,
    .species = SPECIES_MACHOP,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Lucas1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 21,
    .species = SPECIES_GEODUDE,
    },
    {
    .lvl = 22,
    .species = SPECIES_NUMEL,
    }
    #else // CANON_MODE
    {
    .lvl = 21,
    .species = SPECIES_CARKOL,
    },
    {
    .lvl = 22,
    .species = SPECIES_NUMEL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Alan[] = {
    {
    .lvl = 25,
    .species = SPECIES_GEODUDE,
    },
    {
    .lvl = 25,
    .species = SPECIES_NOSEPASS,
    },
    {
    .lvl = 25,
    .species = SPECIES_GRAVELER,
    }
};

static const struct TrainerMon sParty_Clark[] = {
    #ifdef CANON_MODE
    {
    .lvl = 9,
    .species = SPECIES_GEODUDE,
    }
    #else // CANON_MODE
    {
    .lvl = 9,
    .species = SPECIES_DRILBUR,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Eric[] = {
    #ifdef CANON_MODE
    {
    .lvl = 23,
    .species = SPECIES_GEODUDE,
    },
    {
    .lvl = 23,
    .species = SPECIES_BALTOY,
    }
    #else // CANON_MODE
    {
    .lvl = 23,
    .species = SPECIES_GLIGAR,
    },
    {
    .lvl = 23,
    .species = SPECIES_BALTOY,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Lucas2[] = {
    {
    .lvl = 10,
    .species = SPECIES_WAILMER,
    .moves = {MOVE_SPLASH, MOVE_WATER_GUN, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Mike1[] = {
    {
    .lvl = 11,
    .species = SPECIES_PELIPPER,
    .moves = {MOVE_GUST, MOVE_GROWL, MOVE_NONE, MOVE_NONE}
    },
    {
    .lvl = 11,
    .species = SPECIES_POOCHYENA,
    .moves = {MOVE_BITE, MOVE_SCARY_FACE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Mike2[] = {
    {
    .lvl = 18,
    .species = SPECIES_GEODUDE,
    },
    {
    .lvl = 18,
    .species = SPECIES_GEODUDE,
    },
    {
    .lvl = 18,
    .species = SPECIES_MACHOP,
    }
};

static const struct TrainerMon sParty_Trent2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 27,
    .species = SPECIES_GRAVELER,
    }
};

static const struct TrainerMon sParty_Trent3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 30,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 30,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 30,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 30,
    .species = SPECIES_GRAVELER,
    }
};

static const struct TrainerMon sParty_Trent4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_GRAVELER,
    }
};

static const struct TrainerMon sParty_Trent5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_GOLEM,
    }
};

static const struct TrainerMon sParty_DezAndLuke[] = {
    {
    .lvl = 34,
    .species = SPECIES_DELCATTY,
    },
    {
    .lvl = 34,
    .species = SPECIES_MANECTRIC,
    }
};

static const struct TrainerMon sParty_LeaAndJed[] = {
    {
    .lvl = 50,
    .species = SPECIES_LUVDISC,
    },
    {
    .lvl = 50,
    .species = SPECIES_LUVDISC,
    }
};

static const struct TrainerMon sParty_KiraAndDan1[] = {
    {
    .lvl = 28,
    .species = SPECIES_VOLBEAT,
    },
    {
    .lvl = 28,
    .species = SPECIES_ILLUMISE,
    }
};

static const struct TrainerMon sParty_KiraAndDan2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_VOLBEAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_ILLUMISE,
    }
};

static const struct TrainerMon sParty_KiraAndDan3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_VOLBEAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_ILLUMISE,
    }
};

static const struct TrainerMon sParty_KiraAndDan4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_VOLBEAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 39,
    .species = SPECIES_ILLUMISE,
    }
};

static const struct TrainerMon sParty_KiraAndDan5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 42,
    .species = SPECIES_VOLBEAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 42,
    .species = SPECIES_ILLUMISE,
    }
};

static const struct TrainerMon sParty_Johanna[] = {
    {
    .lvl = 15,
    .species = SPECIES_GOLDEEN,
    }
};

static const struct TrainerMon sParty_Gerald[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_FLAMETHROWER, MOVE_FURY_SWIPES, MOVE_FEINT_ATTACK, MOVE_BIND}
    }
};

static const struct TrainerMon sParty_Vivian[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_MEDITITE,
    .moves = {MOVE_BIDE, MOVE_DETECT, MOVE_CONFUSION, MOVE_THUNDER_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 25,
    .species = SPECIES_MEDITITE,
    .moves = {MOVE_THUNDER_PUNCH, MOVE_DETECT, MOVE_CONFUSION, MOVE_MEDITATE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_MEDITITE,
    .moves = {MOVE_BIDE, MOVE_DETECT, MOVE_CONFUSION, MOVE_THUNDER_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 25,
    .species = SPECIES_MIENFOO,
    .moves = {MOVE_THUNDER_PUNCH, MOVE_DETECT, MOVE_CONFUSION, MOVE_MEDITATE}
    }
    #endif //CANON_MODE
};

static const struct TrainerMon sParty_Danielle[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 29,
    .species = SPECIES_MEDITITE,
    .moves = {MOVE_BIDE, MOVE_DETECT, MOVE_CONFUSION, MOVE_FIRE_PUNCH}
    }
};

static const struct TrainerMon sParty_Hideo[] = {
    {
    .lvl = 28,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_SELF_DESTRUCT, MOVE_SLUDGE, MOVE_SMOKESCREEN}
    },
    {
    .lvl = 28,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_POISON_GAS, MOVE_SLUDGE, MOVE_SMOKESCREEN}
    }
};

static const struct TrainerMon sParty_Keigo[] = {
    {
    .lvl = 31,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_SELF_DESTRUCT, MOVE_SLUDGE, MOVE_SMOKESCREEN}
    },
    {
    .lvl = 31,
    .species = SPECIES_NINJASK,
    .moves = {MOVE_SAND_ATTACK, MOVE_FAKE_OUT, MOVE_FURY_CUTTER, MOVE_SWORDS_DANCE}
    }
};

static const struct TrainerMon sParty_Riley[] = {
    {
    .lvl = 31,
    .species = SPECIES_NINCADA,
    .moves = {MOVE_LEECH_LIFE, MOVE_FURY_SWIPES, MOVE_MIND_READER, MOVE_DIG}
    },
    {
    .lvl = 31,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_SELF_DESTRUCT, MOVE_SLUDGE, MOVE_SMOKESCREEN}
    }
};

static const struct TrainerMon sParty_Flint[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 39,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 40,
    .species = SPECIES_XATU,
    }
};

static const struct TrainerMon sParty_Ashley[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 39,
    .species = SPECIES_SWABLU,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 39,
    .species = SPECIES_SWABLU,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 40,
    .species = SPECIES_SWABLU,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 39,
    .species = SPECIES_RUFFLET,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 39,
    .species = SPECIES_VULLABY,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 40,
    .species = SPECIES_SWABLU,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_WallyMauville[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 20,
    .species = SPECIES_SKITTY,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 21,
    .species = SPECIES_KIRLIA,
    }
};

static const struct TrainerMon sParty_WallyVR2[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 51,
    .species = SPECIES_ALTARIA,
    .moves = {MOVE_AERIAL_ACE, MOVE_SAFEGUARD, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 50,
    .species = SPECIES_DELCATTY,
    .moves = {MOVE_SING, MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 51,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_MAGICAL_LEAF, MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 48,
    .species = SPECIES_MAGNETON,
    .moves = {MOVE_SUPERSONIC, MOVE_THUNDERBOLT, MOVE_TRI_ATTACK, MOVE_SCREECH}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 52,
    .species = SPECIES_GARDEVOIR,
    .moves = {MOVE_MOONBLAST, MOVE_CALM_MIND, MOVE_PSYCHIC, MOVE_FUTURE_SIGHT}
    }
};

static const struct TrainerMon sParty_WallyVR3[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 54,
    .species = SPECIES_ALTARIA,
    .moves = {MOVE_AERIAL_ACE, MOVE_SAFEGUARD, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 53,
    .species = SPECIES_DELCATTY,
    .moves = {MOVE_SING, MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 54,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_MAGICAL_LEAF, MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 51,
    .species = SPECIES_MAGNETON,
    .moves = {MOVE_SUPERSONIC, MOVE_THUNDERBOLT, MOVE_TRI_ATTACK, MOVE_SCREECH}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 55,
    .species = SPECIES_GARDEVOIR,
    .moves = {MOVE_MOONBLAST, MOVE_CALM_MIND, MOVE_PSYCHIC, MOVE_FUTURE_SIGHT}
    }
};

static const struct TrainerMon sParty_WallyVR4[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 57,
    .species = SPECIES_ALTARIA,
    .moves = {MOVE_AERIAL_ACE, MOVE_SAFEGUARD, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 56,
    .species = SPECIES_DELCATTY,
    .moves = {MOVE_SING, MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 57,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_MAGICAL_LEAF, MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 54,
    .species = SPECIES_MAGNETON,
    .moves = {MOVE_SUPERSONIC, MOVE_THUNDERBOLT, MOVE_TRI_ATTACK, MOVE_SCREECH}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 58,
    .species = SPECIES_GARDEVOIR,
    .moves = {MOVE_MOONBLAST, MOVE_CALM_MIND, MOVE_PSYCHIC, MOVE_FUTURE_SIGHT}
    }
};

static const struct TrainerMon sParty_WallyVR5[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 60,
    .species = SPECIES_ALTARIA,
    .moves = {MOVE_AERIAL_ACE, MOVE_SAFEGUARD, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 60,
    .species = SPECIES_DELCATTY,
    .moves = {MOVE_SING, MOVE_ASSIST, MOVE_CHARM, MOVE_FEINT_ATTACK}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 60,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_MAGICAL_LEAF, MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 57,
    .species = SPECIES_MAGNETON,
    .moves = {MOVE_SUPERSONIC, MOVE_THUNDERBOLT, MOVE_TRI_ATTACK, MOVE_SCREECH}
    },
    {
    .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
    .lvl = 61,
    .species = SPECIES_GARDEVOIR,
    .moves = {MOVE_MOONBLAST, MOVE_CALM_MIND, MOVE_PSYCHIC, MOVE_FUTURE_SIGHT}
    }
};

static const struct TrainerMon sParty_BrendanLilycoveMudkip[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 34,
    .species = SPECIES_TROPIUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 37,
    .species = SPECIES_GROVYLE,
    }
};

static const struct TrainerMon sParty_BrendanLilycoveTreecko[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 34,
    .species = SPECIES_TROPIUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 37,
    .species = SPECIES_COMBUSKEN,
    }
};

static const struct TrainerMon sParty_BrendanLilycoveTorchic[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 34,
    .species = SPECIES_TROPIUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 37,
    .species = SPECIES_MARSHTOMP,
    }
};

static const struct TrainerMon sParty_MayLilycoveMudkip[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 34,
    .species = SPECIES_TROPIUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 37,
    .species = SPECIES_GROVYLE,
    }
};

static const struct TrainerMon sParty_MayLilycoveTreecko[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 34,
    .species = SPECIES_TROPIUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 37,
    .species = SPECIES_COMBUSKEN,
    }
};

static const struct TrainerMon sParty_MayLilycoveTorchic[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 34,
    .species = SPECIES_TROPIUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 35,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 37,
    .species = SPECIES_MARSHTOMP,
    }
};

static const struct TrainerMon sParty_Jonah[] = {
    #ifdef CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_WAILMER,
    },
    {
    .lvl = 34,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 35,
    .species = SPECIES_SHARPEDO,
    }
    #else // CANON_MODE
    {
    .lvl = 33,
    .species = SPECIES_WAILMER,
    },
    {
    .lvl = 34,
    .species = SPECIES_GASTRODON_EAST_SEA,
    },
    {
    .lvl = 35,
    .species = SPECIES_SHARPEDO,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Henry[] = {
    #ifdef CANON_MODE
    {
    .lvl = 34,
    .species = SPECIES_CARVANHA,
    },
    {
    .lvl = 37,
    .species = SPECIES_TENTACRUEL,
    }
    #else // CANON_MODE
    {
    .lvl = 34,
    .species = SPECIES_BARRASKEWDA,
    },
    {
    .lvl = 37,
    .species = SPECIES_TENTACRUEL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Roger[] = {
    {
    .lvl = 17,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 28,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 38,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Alexa[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 37,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 37,
    .species = SPECIES_AZUMARILL,
    }
};

static const struct TrainerMon sParty_Ruben[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 37,
    .species = SPECIES_SHIFTRY,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 37,
    .species = SPECIES_NOSEPASS,
    }
};

static const struct TrainerMon sParty_Koji1[] = {
    #ifdef CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_MACHOKE,
    }
    #else // CANON_MODE
    {
    .lvl = 37,
    .species = SPECIES_TOXICROAK,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Wayne[] = {
    {
    .lvl = 34,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 34,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 39,
    .species = SPECIES_WAILMER,
    }
};

static const struct TrainerMon sParty_Aidan[] = {
    #ifdef CANON_MODE
    {
    .lvl = 35,
    .species = SPECIES_SWELLOW,
    },
    {
    .lvl = 35,
    .species = SPECIES_SKARMORY,
    }
    #else // CANON_MODE
    {
    .lvl = 35,
    .species = SPECIES_TOUCANNON,
    },
    {
    .lvl = 35,
    .species = SPECIES_SKARMORY,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Reed[] = {
    {
    .lvl = 36,
    .species = SPECIES_SPHEAL,
    },
    {
    .lvl = 36,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Tisha[] = {
    {
    .lvl = 37,
    .species = SPECIES_CHINCHOU,
    }
};

static const struct TrainerMon sParty_ToriAndTia[] = {
    #ifdef CANON_MODE
    {
    .lvl = 22,
    .species = SPECIES_SPINDA,
    },
    {
    .lvl = 22,
    .species = SPECIES_SPINDA,
    }
    #else // CANON_MODE
        {
    .lvl = 22,
    .species = SPECIES_LOTAD,
    },
    {
    .lvl = 22,
    .species = SPECIES_TYMPOLE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_KimAndIris[] = {
    #ifdef CANON_MODE
    {
    .lvl = 35,
    .species = SPECIES_SWABLU,
    .moves = {MOVE_SING, MOVE_FURY_ATTACK, MOVE_SAFEGUARD, MOVE_AERIAL_ACE}
    },
    {
    .lvl = 38,
    .species = SPECIES_NUMEL,
    .moves = {MOVE_FLAMETHROWER, MOVE_TAKE_DOWN, MOVE_REST, MOVE_EARTHQUAKE}
    }
    #else // CANON_MODE
    {
    .lvl = 35,
    .species = SPECIES_ORICORIO_BAILE,
    },
    {
    .lvl = 38,
    .species = SPECIES_ORICORIO_POM_POM,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_TyraAndIvy[] = {
    #ifdef CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_GROWTH, MOVE_STUN_SPORE, MOVE_MEGA_DRAIN, MOVE_LEECH_SEED}
    },
    {
    .lvl = 23,
    .species = SPECIES_GRAVELER,
    .moves = {MOVE_DEFENSE_CURL, MOVE_ROLLOUT, MOVE_MUD_SPORT, MOVE_ROCK_THROW}
    }
    #else // CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_STEENEE,
    },
    {
    .lvl = 23,
    .species = SPECIES_CLEFAIRY,
    }
    #endif // CANON_MODE 
};

static const struct TrainerMon sParty_MelAndPaul[] = {
    {
    .lvl = 30,
    .species = SPECIES_DUSTOX,
    .moves = {MOVE_GUST, MOVE_PSYBEAM, MOVE_TOXIC, MOVE_PROTECT}
    },
    {
    .lvl = 30,
    .species = SPECIES_BEAUTIFLY,
    .moves = {MOVE_GUST, MOVE_MEGA_DRAIN, MOVE_ATTRACT, MOVE_STUN_SPORE}
    }
};

static const struct TrainerMon sParty_JohnAndJay1[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 42,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_PSYCH_UP, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 42,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 42,
    .species = SPECIES_GARDEVOIR,
    },
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 42,
    .species = SPECIES_GALLADE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_JohnAndJay2[] = {
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 47,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_PSYCH_UP, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
    .lvl = 47,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    }
};

static const struct TrainerMon sParty_JohnAndJay3[] = {
    {
    .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
    .lvl = 50,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_PSYCH_UP, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
    .lvl = 50,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    }
};

static const struct TrainerMon sParty_JohnAndJay4[] = {
    {
    .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
    .lvl = 53,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_PSYCH_UP, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
    .lvl = 53,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    }
};

static const struct TrainerMon sParty_JohnAndJay5[] = {
    {
    .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
    .lvl = 56,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_PSYCH_UP, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
    .lvl = 56,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    }
};

static const struct TrainerMon sParty_ReliAndIan[] = {
    #ifdef CANON_MODE
    {
    .lvl = 38,
    .species = SPECIES_AZUMARILL,
    },
    {
    .lvl = 36,
    .species = SPECIES_WINGULL,
    }
    #else // CANON_MODE
    {
    .lvl = 38,
    .species = SPECIES_AZUMARILL,
    },
    {
    .lvl = 36,
    .species = SPECIES_LUMINEON,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_LilaAndRoy1[] = {
    {
    .lvl = 37,
    .species = SPECIES_CHINCHOU,
    },
    {
    .lvl = 36,
    .species = SPECIES_CARVANHA,
    }
};

static const struct TrainerMon sParty_LilaAndRoy2[] = {
    {
    .lvl = 46,
    .species = SPECIES_CHINCHOU,
    },
    {
    .lvl = 44,
    .species = SPECIES_CARVANHA,
    }
};

static const struct TrainerMon sParty_LilaAndRoy3[] = {
    {
    .lvl = 50,
    .species = SPECIES_LANTURN,
    },
    {
    .lvl = 47,
    .species = SPECIES_CARVANHA,
    }
};

static const struct TrainerMon sParty_LilaAndRoy4[] = {
    {
    .lvl = 52,
    .species = SPECIES_LANTURN,
    },
    {
    .lvl = 50,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_LilaAndRoy5[] = {
    {
    .lvl = 55,
    .species = SPECIES_LANTURN,
    },
    {
    .lvl = 53,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_LisaAndRay[] = {
    #ifdef CANON_MODE
    {
    .lvl = 30,
    .species = SPECIES_GOLDEEN,
    },
    {
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    }
    #else // CANON_MODE
    {
    .lvl = 30,
    .species = SPECIES_GOLDEEN,
    },
    {
    .lvl = 28,
    .species = SPECIES_FRILLISH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Chris[] = {
    {
    .lvl = 32,
    .species = SPECIES_MAGIKARP,
    },
    {
    .lvl = 23,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 29,
    .species = SPECIES_FEEBAS,
    },
    {
    .lvl = 26,
    .species = SPECIES_CARVANHA,
    }
};

static const struct TrainerMon sParty_Dawson[] = {
    {
    .lvl = 9,
    .species = SPECIES_ZIGZAGOON,
    .heldItem = ITEM_NUGGET
    },
    {
    .lvl = 9,
    .species = SPECIES_POOCHYENA,
    .heldItem = ITEM_NONE
    }
};

static const struct TrainerMon sParty_Sarah[] = {
    {
    .lvl = 9,
    .species = SPECIES_LOTAD,
    .heldItem = ITEM_NONE
    },
    {
    .lvl = 9,
    .species = SPECIES_ZIGZAGOON,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Darian[] = {
    {
    .lvl = 10,
    .species = SPECIES_MAGIKARP,
    }
};

static const struct TrainerMon sParty_Hailey[] = {
    {
    .lvl = 15,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Chandler[] = {
    {
    .lvl = 14,
    .species = SPECIES_TENTACOOL,
    },
    {
    .lvl = 14,
    .species = SPECIES_TENTACOOL,
    }
};

static const struct TrainerMon sParty_Kaleb[] = {
    {
    .lvl = 16,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .lvl = 16,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Joseph[] = {
    #ifdef CANON_MODE
    {
    .lvl = 16,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .lvl = 16,
    .species = SPECIES_VOLTORB,
    }
    #else // CANON_MODE
    {
    .lvl = 16,
    .species = SPECIES_ELEKID,
    },
    {
    .lvl = 16,
    .species = SPECIES_VOLTORB,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Alyssa[] = {
    {
    .lvl = 17,
    .species = SPECIES_MAGNEMITE,
    }
};

static const struct TrainerMon sParty_Marcos[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 17,
    .species = SPECIES_VOLTORB,
    }
};

static const struct TrainerMon sParty_Rhett[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 17,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Tyron[] = {
    {
    .lvl = 22,
    .species = SPECIES_SANDSHREW,
    }
};

static const struct TrainerMon sParty_Celina[] = {
    #ifdef CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_ROSELIA,
    }
    #else // CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_CHERRIM,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Bianca[] = {
    #ifdef CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_SHROOMISH,
    }
    #else // CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_MARACTUS,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Hayden[] = {
    {
    .lvl = 20,
    .species = SPECIES_NUMEL,
    }
};

static const struct TrainerMon sParty_Sophie[] = {
    {
    .lvl = 19,
    .species = SPECIES_MARILL,
    },
    {
    .lvl = 22,
    .species = SPECIES_LOMBRE,
    }
};

static const struct TrainerMon sParty_Coby[] = {
    {
    .lvl = 19,
    .species = SPECIES_SKARMORY,
    },
    {
    .lvl = 22,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Lawrence[] = {
    {
    .lvl = 20,
    .species = SPECIES_BALTOY,
    },
    {
    .lvl = 20,
    .species = SPECIES_SANDSHREW,
    }
};

static const struct TrainerMon sParty_Wyatt[] = {
    {
    .lvl = 20,
    .species = SPECIES_ARON,
    },
    {
    .lvl = 20,
    .species = SPECIES_ARON,
    }
};

static const struct TrainerMon sParty_Angelina[] = {
    {
    .lvl = 20,
    .species = SPECIES_LOMBRE,
    },
    {
    .lvl = 20,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Kai[] = {
    #ifdef CANON_MODE
    {
    .lvl = 22,
    .species = SPECIES_ARROKUDA,
    }
    #else // CANON_MODE
    {
    .lvl = 22,
    .species = SPECIES_BARBOACH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Charlotte[] = {
    #ifdef CANON_MODE
    {
    .lvl = 22,
    .species = SPECIES_NUZLEAF,
    }
    #else // CANON_MODE
    {
    .lvl = 22,
    .species = SPECIES_MASQUERAIN,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Deandre[] = {
    {
    .lvl = 16,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .lvl = 16,
    .species = SPECIES_ARON,
    },
    {
    .lvl = 17,
    .species = SPECIES_ELECTRIKE,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout1[] = {
    {
    .lvl = 34,
    .species = SPECIES_GOLBAT,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout2[] = {
    {
    .lvl = 34,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout3[] = {
    {
    .lvl = 34,
    .species = SPECIES_CAMERUPT,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout4[] = {
    {
    .lvl = 33,
    .species = SPECIES_BALTOY,
    },
    {
    .lvl = 34,
    .species = SPECIES_GOLBAT,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout5[] = {
    {
    .lvl = 33,
    .species = SPECIES_KOFFING,
    },
    {
    .lvl = 34,
    .species = SPECIES_CAMERUPT,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout6[] = {
    {
    .lvl = 35,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout7[] = {
    {
    .lvl = 35,
    .species = SPECIES_GOLBAT,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout8[] = {
    {
    .lvl = 35,
    .species = SPECIES_KOFFING,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout9[] = {
    #ifdef CANON_MODE 
    {
    .lvl = 34,
    .species = SPECIES_GOLBAT,
    }
    #else // CANON_MODE
    {
    .lvl = 34,
    .species = SPECIES_SIZZLIPEDE,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_GruntMagmaHideout10[] = {
    {
    .lvl = 35,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout11[] = {
    {
    .lvl = 36,
    .species = SPECIES_CLAYDOL,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout12[] = {
    {
    .lvl = 36,
    .species = SPECIES_CAMERUPT,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout13[] = {
    {
    .lvl = 36,
    .species = SPECIES_WEEZING,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout14[] = {
    {
    .lvl = 35,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout15[] = {
    {
    .lvl = 36,
    .species = SPECIES_CAMERUPT,
    }
};

static const struct TrainerMon sParty_GruntMagmaHideout16[] = {
    {
    .lvl = 36,
    .species = SPECIES_CLAYDOL,
    }
};

static const struct TrainerMon sParty_CourtneyMagmaHideout[] = {
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 34,
    .species = SPECIES_KOFFING,
    },
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 35,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 35,
    .species = SPECIES_GOLBAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
    .lvl = 36,
    .species = SPECIES_CAMERUPT,
    }
};

static const struct TrainerMon sParty_Darcy[] = {
    {
    .lvl = 36,
    .species = SPECIES_PELIPPER,
    },
    {
    .lvl = 36,
    .species = SPECIES_CAMERUPT,
    }
};

static const struct TrainerMon sParty_MaxieMossdeep[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 46,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 47,
    .species = SPECIES_CROBAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 48,
    .species = SPECIES_CAMERUPT,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 46,
    .species = SPECIES_CENTISKORCH,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 47,
    .species = SPECIES_CROBAT,
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 48,
    .species = SPECIES_CAMERUPT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Pete[] = {
    {
    .lvl = 17,
    .species = SPECIES_TENTACOOL,
    }
};

static const struct TrainerMon sParty_Isabelle[] = {
    {
    .lvl = 17,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Andres1[] = {
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 28,
    .species = SPECIES_SANDSHREW,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 28,
    .species = SPECIES_SANDSHREW,
    }
};

static const struct TrainerMon sParty_Josue[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 28,
    .species = SPECIES_TAILLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 28,
    .species = SPECIES_WINGULL,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 28,
    .species = SPECIES_CRAMORANT,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 28,
    .species = SPECIES_WINGULL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Camron[] = {
    {
    .lvl = 29,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Cory1[] = {
    {
    .lvl = 27,
    .species = SPECIES_WINGULL,
    },
    {
    .lvl = 27,
    .species = SPECIES_MACHOP,
    },
    {
    .lvl = 27,
    .species = SPECIES_TENTACOOL,
    }
};

static const struct TrainerMon sParty_Carolina[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 27,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 27,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 27,
    .species = SPECIES_MANECTRIC,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 27,
    .species = SPECIES_RAICHU_ALOLAN,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 27,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 27,
    .species = SPECIES_MANECTRIC,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Elijah[] = {
    {
    .lvl = 28,
    .species = SPECIES_SKARMORY,
    },
    {
    .lvl = 28,
    .species = SPECIES_SKARMORY,
    }
};

static const struct TrainerMon sParty_Celia[] = {
    {
    .lvl = 25,
    .species = SPECIES_MARILL,
    },
    {
    .lvl = 25,
    .species = SPECIES_LOMBRE,
    }
};

static const struct TrainerMon sParty_Bryan[] = {
    #ifdef CANON_MODE
    {
    .lvl = 25,
    .species = SPECIES_SANDSHREW,
    },
    {
    .lvl = 25,
    .species = SPECIES_SANDSLASH,
    }
    #else // CANON_MODE
    {
    .lvl = 25,
    .species = SPECIES_YAMASK,
    },
    {
    .lvl = 25,
    .species = SPECIES_SANDSLASH,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Branden[] = {
    {
    .lvl = 25,
    .species = SPECIES_TAILLOW,
    },
    {
    .lvl = 25,
    .species = SPECIES_NUZLEAF,
    }
};

static const struct TrainerMon sParty_Bryant[] = {
    #ifdef CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_NUMEL,
    },
    {
    .lvl = 20,
    .species = SPECIES_SLUGMA,
    }
    #else // CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_DARUMAKA,
    },
    {
    .lvl = 20,
    .species = SPECIES_SLUGMA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Shayla[] = {
    #ifdef CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_SHROOMISH,
    },
    {
    .lvl = 20,
    .species = SPECIES_ROSELIA,
    }
    #else // CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_FOONGUS,
    },
    {
    .lvl = 20,
    .species = SPECIES_ROSELIA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Kyra[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_DODUO,
    },
    {
    .lvl = 29,
    .species = SPECIES_DODRIO,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_DODUO,
    },
    {
    .lvl = 29,
    .species = SPECIES_LOPUNNY,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Jaiden[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_NINJASK,
    },
    {
    .lvl = 29,
    .species = SPECIES_GULPIN,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_NINJASK,
    },
    {
    .lvl = 29,
    .species = SPECIES_ACCELGOR,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Alix[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_KADABRA,
    },
    {
    .lvl = 29,
    .species = SPECIES_KIRLIA,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_GOTHORITA,
    },
    {
    .lvl = 29,
    .species = SPECIES_KIRLIA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Helene[] = {
    {
    .lvl = 29,
    .species = SPECIES_MEDITITE,
    },
    {
    .lvl = 29,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Marlene[] = {
    #ifdef CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_MEDITITE,
    },
    {
    .lvl = 20,
    .species = SPECIES_SPOINK,
    }
    #else // CANON_MODE
    {
    .lvl = 20,
    .species = SPECIES_HATENNA,
    },
    {
    .lvl = 20,
    .species = SPECIES_SPOINK,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Devan[] = {
    {
    .lvl = 9,
    .species = SPECIES_GEODUDE,
    },
    {
    .lvl = 10,
    .species = SPECIES_GEODUDE,
    }
};

static const struct TrainerMon sParty_Johnson[] = {
    {
    .lvl = 9,
    .species = SPECIES_SHROOMISH,
    },
    {
    .lvl = 9,
    .species = SPECIES_LOTAD,
    }
};

static const struct TrainerMon sParty_Melina[] = {
    #ifdef CANON_MODE
    {
    .lvl = 19,
    .species = SPECIES_DODUO,
    }
    #else // CANON_MODE
    {
    .lvl = 19,
    .species = SPECIES_CRAMORANT,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brandi[] = {
    {
    .lvl = 19,
    .species = SPECIES_RALTS,
    }
};

static const struct TrainerMon sParty_Aisha[] = {
    {
    .lvl = 19,
    .species = SPECIES_MEDITITE,
    }
};

static const struct TrainerMon sParty_Makayla[] = {
    #ifdef CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_ROSELIA,
    },
    {
    .lvl = 36,
    .species = SPECIES_MEDICHAM,
    }
    #else // CANON_MODE
    {
    .lvl = 36,
    .species = SPECIES_TSAREENA,
    },
    {
    .lvl = 36,
    .species = SPECIES_MEDICHAM,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Fabian[] = {
    {
    .lvl = 29,
    .species = SPECIES_MANECTRIC,
    }
};

static const struct TrainerMon sParty_Dayton[] = {
    #ifdef CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_SLUGMA,
    },
    {
    .lvl = 28,
    .species = SPECIES_NUMEL,
    }
    #else // CANON_MODE
    {
    .lvl = 28,
    .species = SPECIES_SIZZLIPEDE,
    },
    {
    .lvl = 28,
    .species = SPECIES_NUMEL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Rachel[] = {
    #ifdef CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_GOLDEEN,
    }
    #else // CANON_MODE
    {
    .lvl = 29,
    .species = SPECIES_SHELLOS_WEST_SEA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Leonel[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 33,
    .species = SPECIES_MANECTRIC,
    .moves = {MOVE_THUNDER, MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_NONE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 33,
    .species = SPECIES_SWANNA,
    .moves = {MOVE_RAIN_DANCE, MOVE_FEATHER_DANCE, MOVE_AIR_SLASH, MOVE_CHILLING_WATER}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Callie[] = {
    #ifdef CANON_MODE
    {
    .lvl = 31,
    .species = SPECIES_MEDITITE,
    },
    {
    .lvl = 31,
    .species = SPECIES_MAKUHITA,
    }
    #else // CANON_MODE
    {
    .lvl = 31,
    .species = SPECIES_THROH,
    },
    {
    .lvl = 31,
    .species = SPECIES_SAWK,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Cale[] = {
    {
    .lvl = 32,
    .species = SPECIES_DUSTOX,
    },
    {
    .lvl = 32,
    .species = SPECIES_BEAUTIFLY,
    }
};

static const struct TrainerMon sParty_Myles[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_MAKUHITA,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_TROPIUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_NUMEL,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_MAKUHITA,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_STARLY,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_TROPIUS,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_SHINX,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_NUMEL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Pat[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_POOCHYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_MARILL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_SANDSHREW,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_GULPIN,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_POOCHYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_BUIZEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_MINCCINO,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_SANDSHREW,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 28,
    .species = SPECIES_GULPIN,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Cristin1[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 32,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 32,
    .species = SPECIES_VIGOROTH,
    }
};

static const struct TrainerMon sParty_MayRustboroTreecko[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 15,
    .species = SPECIES_LOTAD,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 17,
    .species = SPECIES_TORCHIC,
    }
};

static const struct TrainerMon sParty_MayRustboroTorchic[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 15,
    .species = SPECIES_TORKOAL,
    },
    {
    .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
    .lvl = 17,
    .species = SPECIES_MUDKIP,
    }
};

static const struct TrainerMon sParty_DragonMaster[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 62,
    .species = SPECIES_HAXORUS,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_SWORDS_DANCE, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 62,
    .species = SPECIES_HYDREIGON,
    .heldItem = ITEM_CHOICE_SPECS,
    .moves = {MOVE_DRAGON_PULSE, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_U_TURN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 62,
    .species = SPECIES_DRAGALGE,
    .heldItem = ITEM_BLACK_SLUDGE,
    .moves = {MOVE_DRACO_METEOR, MOVE_SLUDGE_BOMB, MOVE_FLIP_TURN, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 62,
    .species = SPECIES_SALAMENCE,
    .heldItem = ITEM_WIDE_LENS,
    .moves = {MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_DRAGON_DANCE}
    }
};

static const struct TrainerMon sParty_FightingMaster[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 62,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_FLAME_ORB,
    .moves = {MOVE_SUPERPOWER, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_BULLET_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 62,
    .species = SPECIES_PANGORO,
    .heldItem = ITEM_LIFE_ORB,
    .moves = {MOVE_SWORDS_DANCE, MOVE_KNOCK_OFF, MOVE_DRAIN_PUNCH, MOVE_BULLET_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 62,
    .species = SPECIES_TOXICROAK,
    .heldItem = ITEM_CHOICE_SCARF,
    .moves = {MOVE_GUNK_SHOT, MOVE_LOW_KICK, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 62,
    .species = SPECIES_LUCARIO,
    .heldItem = ITEM_CHOPLE_BERRY,
    .moves = {MOVE_NASTY_PLOT, MOVE_AURA_SPHERE, MOVE_FLASH_CANNON, MOVE_DARK_PULSE}
    }
};

static const struct TrainerMon sParty_HexLady[] = {
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 41,
    .species = SPECIES_GOURGEIST,
    .heldItem = ITEM_PINK_SCARF,
    .friendship = 200,
    .moves = {MOVE_SEED_BOMB, MOVE_SHADOW_BALL, MOVE_SHADOW_SNEAK, MOVE_RETURN}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 41,
    .species = SPECIES_RUNERIGUS,
    .heldItem = ITEM_RED_SCARF,
    .friendship = 200,
    .moves = {MOVE_EARTHQUAKE, MOVE_BODY_PRESS, MOVE_POLTERGEIST, MOVE_REST}
    },
};

static const struct TrainerMon sParty_HexLady2[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 41,
    .species = SPECIES_MIMIKYU,
    .heldItem = ITEM_YELLOW_SCARF,
    .friendship = 200,
    .moves = {MOVE_PLAY_ROUGH, MOVE_SHADOW_SNEAK, MOVE_SHADOW_CLAW, MOVE_DRAIN_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
    .lvl = 44,
    .species = SPECIES_GENGAR,
    .heldItem = ITEM_BLUE_SCARF,
    .friendship = 200,
    .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_ICY_WIND, MOVE_SUBSTITUTE}
    },
};

static const struct TrainerMon sParty_Roxanne2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_GOLEM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PROTECT, MOVE_ROLLOUT, MOVE_MAGNITUDE, MOVE_EXPLOSION}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_KABUTO,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SWORDS_DANCE, MOVE_ICE_BEAM, MOVE_SURF, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_ONIX,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_IRON_TAIL, MOVE_EXPLOSION, MOVE_ROAR, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_THUNDER_WAVE, MOVE_EXPLOSION, MOVE_PROTECT, MOVE_ROCK_SLIDE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_AGGRON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_STEALTH_ROCK, MOVE_HEAVY_SLAM, MOVE_HEAD_SMASH, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_LYCANROC_DUSK,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC_FANGS, MOVE_STONE_EDGE, MOVE_FIRE_FANG, MOVE_ACCELEROCK}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_CARRACOSTA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHELL_SMASH, MOVE_STONE_EDGE, MOVE_HYDRO_PUMP, MOVE_SUPERPOWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_CRADILY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_BLAST, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_RECOVER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_PROBOPASS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SMACK_DOWN, MOVE_EARTH_POWER, MOVE_VOLT_SWITCH, MOVE_FLASH_CANNON}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_AERODACTYL,
    .heldItem = ITEM_AERODACTYLITE,
    .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROOST}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Roxanne3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_OMANYTE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PROTECT, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_GOLEM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PROTECT, MOVE_ROLLOUT, MOVE_MAGNITUDE, MOVE_EXPLOSION}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_KABUTOPS,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SWORDS_DANCE, MOVE_ICE_BEAM, MOVE_SURF, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_ONIX,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_IRON_TAIL, MOVE_EXPLOSION, MOVE_ROAR, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_THUNDER_WAVE, MOVE_EXPLOSION, MOVE_PROTECT, MOVE_ROCK_SLIDE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_AGGRON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_STEALTH_ROCK, MOVE_HEAVY_SLAM, MOVE_HEAD_SMASH, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_LYCANROC_DUSK,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC_FANGS, MOVE_STONE_EDGE, MOVE_FIRE_FANG, MOVE_ACCELEROCK}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CARRACOSTA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHELL_SMASH, MOVE_STONE_EDGE, MOVE_HYDRO_PUMP, MOVE_SUPERPOWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CRADILY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_BLAST, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_RECOVER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_PROBOPASS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SMACK_DOWN, MOVE_EARTH_POWER, MOVE_VOLT_SWITCH, MOVE_FLASH_CANNON}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_AERODACTYL,
    .heldItem = ITEM_AERODACTYLITE,
    .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROOST}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Roxanne4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_OMASTAR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PROTECT, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_GOLEM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PROTECT, MOVE_ROLLOUT, MOVE_EARTHQUAKE, MOVE_EXPLOSION}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_KABUTOPS,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SWORDS_DANCE, MOVE_ICE_BEAM, MOVE_SURF, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_ONIX,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_IRON_TAIL, MOVE_EXPLOSION, MOVE_ROAR, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_THUNDER_WAVE, MOVE_EXPLOSION, MOVE_PROTECT, MOVE_ROCK_SLIDE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_AGGRON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_STEALTH_ROCK, MOVE_HEAVY_SLAM, MOVE_HEAD_SMASH, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_LYCANROC_DUSK,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC_FANGS, MOVE_STONE_EDGE, MOVE_FIRE_FANG, MOVE_ACCELEROCK}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_CARRACOSTA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHELL_SMASH, MOVE_STONE_EDGE, MOVE_HYDRO_PUMP, MOVE_SUPERPOWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_CRADILY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_BLAST, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_RECOVER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_PROBOPASS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SMACK_DOWN, MOVE_EARTH_POWER, MOVE_VOLT_SWITCH, MOVE_FLASH_CANNON}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_AERODACTYL,
    .heldItem = ITEM_AERODACTYLITE,
    .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROOST}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Roxanne5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_AERODACTYL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_SLIDE, MOVE_HYPER_BEAM, MOVE_SUPERSONIC, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_GOLEM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_ROLLOUT, MOVE_EARTHQUAKE, MOVE_EXPLOSION}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_OMASTAR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PROTECT, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_KABUTOPS,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SWORDS_DANCE, MOVE_ICE_BEAM, MOVE_SURF, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_STEELIX,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_IRON_TAIL, MOVE_EXPLOSION, MOVE_ROAR, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_THUNDER_WAVE, MOVE_EXPLOSION, MOVE_PROTECT, MOVE_ROCK_SLIDE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_AGGRON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_STEALTH_ROCK, MOVE_HEAVY_SLAM, MOVE_HEAD_SMASH, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_LYCANROC_DUSK,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC_FANGS, MOVE_STONE_EDGE, MOVE_FIRE_FANG, MOVE_ACCELEROCK}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_CARRACOSTA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHELL_SMASH, MOVE_STONE_EDGE, MOVE_HYDRO_PUMP, MOVE_SUPERPOWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_CRADILY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_BLAST, MOVE_STEALTH_ROCK, MOVE_TOXIC, MOVE_RECOVER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_PROBOPASS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SMACK_DOWN, MOVE_EARTH_POWER, MOVE_VOLT_SWITCH, MOVE_FLASH_CANNON}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_AERODACTYL,
    .heldItem = ITEM_AERODACTYLITE,
    .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROOST}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brawly2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_KARATE_CHOP, MOVE_ROCK_SLIDE, MOVE_FOCUS_PUNCH, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MEDITITE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC, MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_FOCUS_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_HITMONTOP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PURSUIT, MOVE_COUNTER, MOVE_PROTECT, MOVE_TRIPLE_KICK}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_FAKE_OUT, MOVE_FOCUS_PUNCH, MOVE_BELLY_DRUM, MOVE_EARTHQUAKE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_BULLET_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BULK_UP, MOVE_DRAIN_PUNCH, MOVE_HEAVY_SLAM, MOVE_ZEN_HEADBUTT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_GRAPPLOCT,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_OCTOLOCK, MOVE_DRAIN_PUNCH, MOVE_ICE_PUNCH, MOVE_SUBSTITUTE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SPORE, MOVE_MACH_PUNCH, MOVE_BULLET_SEED, MOVE_ROCK_TOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MIENSHAO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HIGH_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_U_TURN, MOVE_FAKE_OUT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HIGH_JUMP_KICK, MOVE_ICE_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_THUNDER_PUNCH}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brawly3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_KARATE_CHOP, MOVE_ROCK_SLIDE, MOVE_FOCUS_PUNCH, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC, MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_FOCUS_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_HITMONTOP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PURSUIT, MOVE_COUNTER, MOVE_PROTECT, MOVE_TRIPLE_KICK}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_FAKE_OUT, MOVE_FOCUS_PUNCH, MOVE_BELLY_DRUM, MOVE_EARTHQUAKE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_BULLET_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BULK_UP, MOVE_DRAIN_PUNCH, MOVE_HEAVY_SLAM, MOVE_ZEN_HEADBUTT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_GRAPPLOCT,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_OCTOLOCK, MOVE_DRAIN_PUNCH, MOVE_ICE_PUNCH, MOVE_SUBSTITUTE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SPORE, MOVE_MACH_PUNCH, MOVE_BULLET_SEED, MOVE_ROCK_TOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MIENSHAO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HIGH_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_U_TURN, MOVE_FAKE_OUT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HIGH_JUMP_KICK, MOVE_ICE_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_THUNDER_PUNCH}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brawly4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_HITMONCHAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SKY_UPPERCUT, MOVE_PROTECT, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_KARATE_CHOP, MOVE_ROCK_SLIDE, MOVE_FOCUS_PUNCH, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_PSYCHIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_HITMONTOP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PURSUIT, MOVE_COUNTER, MOVE_PROTECT, MOVE_TRIPLE_KICK}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_FAKE_OUT, MOVE_FOCUS_PUNCH, MOVE_BELLY_DRUM, MOVE_EARTHQUAKE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_BULLET_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BULK_UP, MOVE_DRAIN_PUNCH, MOVE_HEAVY_SLAM, MOVE_ZEN_HEADBUTT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_GRAPPLOCT,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_OCTOLOCK, MOVE_DRAIN_PUNCH, MOVE_ICE_PUNCH, MOVE_SUBSTITUTE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SPORE, MOVE_MACH_PUNCH, MOVE_BULLET_SEED, MOVE_ROCK_TOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MIENSHAO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HIGH_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_U_TURN, MOVE_FAKE_OUT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HIGH_JUMP_KICK, MOVE_ICE_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_THUNDER_PUNCH}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Brawly5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_HITMONLEE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_MEGA_KICK, MOVE_FOCUS_PUNCH, MOVE_EARTHQUAKE, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_HITMONCHAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SKY_UPPERCUT, MOVE_PROTECT, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_FOCUS_PUNCH, MOVE_BULK_UP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_PSYCHIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_HITMONTOP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PURSUIT, MOVE_COUNTER, MOVE_PROTECT, MOVE_TRIPLE_KICK}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_FAKE_OUT, MOVE_FOCUS_PUNCH, MOVE_BELLY_DRUM, MOVE_EARTHQUAKE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CLOSE_COMBAT, MOVE_KNOCK_OFF, MOVE_FACADE, MOVE_BULLET_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BULK_UP, MOVE_DRAIN_PUNCH, MOVE_HEAVY_SLAM, MOVE_ZEN_HEADBUTT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_GRAPPLOCT,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_OCTOLOCK, MOVE_DRAIN_PUNCH, MOVE_ICE_PUNCH, MOVE_SUBSTITUTE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SPORE, MOVE_MACH_PUNCH, MOVE_BULLET_SEED, MOVE_ROCK_TOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MIENSHAO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HIGH_JUMP_KICK, MOVE_KNOCK_OFF, MOVE_U_TURN, MOVE_FAKE_OUT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HIGH_JUMP_KICK, MOVE_ICE_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_THUNDER_PUNCH}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Wattson2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MAREEP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER, MOVE_PROTECT, MOVE_THUNDER_WAVE, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_ELECTRODE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROLLOUT, MOVE_THUNDER, MOVE_EXPLOSION, MOVE_RAIN_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SUPERSONIC, MOVE_PROTECT, MOVE_THUNDER, MOVE_RAIN_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BITE, MOVE_THUNDER_WAVE, MOVE_THUNDER, MOVE_PROTECT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_BOLTUND,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER_FANG, MOVE_FIRE_FANG, MOVE_VOLT_SWITCH, MOVE_CRUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_RAICHU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_NASTY_PLOT, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MAGNEZONE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_FLASH_CANNON, MOVE_MIRROR_COAT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_ELECTRODE_HISUIAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_GIGA_DRAIN, MOVE_FOUL_PLAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_ELECTIVIRE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WILD_CHARGE, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_CROSS_CHOP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_MANECTITE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_HYPER_VOICE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Wattson3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_PIKACHU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER, MOVE_SLAM, MOVE_RAIN_DANCE, MOVE_SHOCK_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_FLAAFFY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER, MOVE_PROTECT, MOVE_THUNDER_WAVE, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_ELECTRODE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROLLOUT, MOVE_THUNDER, MOVE_EXPLOSION, MOVE_RAIN_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SUPERSONIC, MOVE_PROTECT, MOVE_THUNDER, MOVE_RAIN_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BITE, MOVE_THUNDER_WAVE, MOVE_THUNDER, MOVE_PROTECT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_BOLTUND,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER_FANG, MOVE_FIRE_FANG, MOVE_VOLT_SWITCH, MOVE_CRUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_RAICHU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_NASTY_PLOT, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MAGNEZONE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_FLASH_CANNON, MOVE_MIRROR_COAT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_ELECTRODE_HISUIAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_GIGA_DRAIN, MOVE_FOUL_PLAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_ELECTIVIRE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WILD_CHARGE, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_CROSS_CHOP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_MANECTITE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_HYPER_VOICE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Wattson4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_RAICHU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER, MOVE_SLAM, MOVE_RAIN_DANCE, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_AMPHAROS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER, MOVE_PROTECT, MOVE_THUNDER_WAVE, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_ELECTRODE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROLLOUT, MOVE_THUNDER, MOVE_EXPLOSION, MOVE_RAIN_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SUPERSONIC, MOVE_PROTECT, MOVE_THUNDER, MOVE_RAIN_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BITE, MOVE_THUNDER_WAVE, MOVE_THUNDER, MOVE_PROTECT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_BOLTUND,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER_FANG, MOVE_FIRE_FANG, MOVE_VOLT_SWITCH, MOVE_CRUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_RAICHU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_NASTY_PLOT, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MAGNEZONE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_FLASH_CANNON, MOVE_MIRROR_COAT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_ELECTRODE_HISUIAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_GIGA_DRAIN, MOVE_FOUL_PLAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_ELECTIVIRE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WILD_CHARGE, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_CROSS_CHOP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_MANECTITE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_HYPER_VOICE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Wattson5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_ELECTABUZZ,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWIFT, MOVE_FOCUS_PUNCH, MOVE_THUNDER_PUNCH, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_RAICHU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER, MOVE_SLAM, MOVE_RAIN_DANCE, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_AMPHAROS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER, MOVE_PROTECT, MOVE_THUNDER_WAVE, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_ELECTRODE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROLLOUT, MOVE_THUNDER, MOVE_EXPLOSION, MOVE_RAIN_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SUPERSONIC, MOVE_PROTECT, MOVE_THUNDER, MOVE_RAIN_DANCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BITE, MOVE_THUNDER_WAVE, MOVE_THUNDER, MOVE_PROTECT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_BOLTUND,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER_FANG, MOVE_FIRE_FANG, MOVE_VOLT_SWITCH, MOVE_CRUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_RAICHU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_NASTY_PLOT, MOVE_THUNDERBOLT, MOVE_FOCUS_BLAST, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MAGNEZONE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_FLASH_CANNON, MOVE_MIRROR_COAT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_ELECTRODE_HISUIAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_GIGA_DRAIN, MOVE_FOUL_PLAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_ELECTIVIRE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WILD_CHARGE, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_CROSS_CHOP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_MANECTITE,
    .moves = {MOVE_VOLT_SWITCH, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_HYPER_VOICE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Flannery2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MAGCARGO,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_ATTRACT, MOVE_LIGHT_SCREEN, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_PONYTA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_ATTRACT, MOVE_SOLAR_BEAM, MOVE_BOUNCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_EARTHQUAKE, MOVE_ATTRACT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_EXPLOSION, MOVE_ATTRACT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_HEAT_ROCK,
    .moves = {MOVE_STEALTH_ROCK, MOVE_LAVA_PLUME, MOVE_RAPID_SPIN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MAGMORTAR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_THUNDERBOLT, MOVE_SCORCHING_SANDS}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_TALONFLAME,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BRAVE_BIRD, MOVE_FLARE_BLITZ, MOVE_ROOST, MOVE_U_TURN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_DARMANITAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLARE_BLITZ, MOVE_U_TURN, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_CENTISKORCH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRE_LASH, MOVE_LEECH_LIFE, MOVE_POWER_WHIP, MOVE_KNOCK_OFF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_HOUNDOOM,
    .heldItem = ITEM_HOUNDOOMINITE,
    .moves = {MOVE_NASTY_PLOT, MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_SLUDGE_BOMB}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Flannery3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_GROWLITHE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HELPING_HAND, MOVE_FLAMETHROWER, MOVE_ROAR, MOVE_SUNNY_DAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MAGCARGO,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_ATTRACT, MOVE_LIGHT_SCREEN, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_PONYTA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_ATTRACT, MOVE_SOLAR_BEAM, MOVE_BOUNCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_EARTHQUAKE, MOVE_ATTRACT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_EXPLOSION, MOVE_ATTRACT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_HEAT_ROCK,
    .moves = {MOVE_STEALTH_ROCK, MOVE_LAVA_PLUME, MOVE_RAPID_SPIN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MAGMORTAR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_THUNDERBOLT, MOVE_SCORCHING_SANDS}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_TALONFLAME,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BRAVE_BIRD, MOVE_FLARE_BLITZ, MOVE_ROOST, MOVE_U_TURN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_DARMANITAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLARE_BLITZ, MOVE_U_TURN, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CENTISKORCH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRE_LASH, MOVE_LEECH_LIFE, MOVE_POWER_WHIP, MOVE_KNOCK_OFF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_HOUNDOOM,
    .heldItem = ITEM_HOUNDOOMINITE,
    .moves = {MOVE_NASTY_PLOT, MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_SLUDGE_BOMB}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Flannery4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_HOUNDOUR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROAR, MOVE_SOLAR_BEAM, MOVE_TAUNT, MOVE_SUNNY_DAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_GROWLITHE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HELPING_HAND, MOVE_FLAMETHROWER, MOVE_SUNNY_DAY, MOVE_ROAR}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MAGCARGO,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_ATTRACT, MOVE_LIGHT_SCREEN, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_RAPIDASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_ATTRACT, MOVE_SOLAR_BEAM, MOVE_BOUNCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_EARTHQUAKE, MOVE_ATTRACT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_EXPLOSION, MOVE_ATTRACT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_HEAT_ROCK,
    .moves = {MOVE_STEALTH_ROCK, MOVE_LAVA_PLUME, MOVE_RAPID_SPIN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MAGMORTAR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_THUNDERBOLT, MOVE_SCORCHING_SANDS}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_TALONFLAME,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BRAVE_BIRD, MOVE_FLARE_BLITZ, MOVE_ROOST, MOVE_U_TURN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_DARMANITAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLARE_BLITZ, MOVE_U_TURN, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_CENTISKORCH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRE_LASH, MOVE_LEECH_LIFE, MOVE_POWER_WHIP, MOVE_KNOCK_OFF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_HOUNDOOM,
    .heldItem = ITEM_HOUNDOOMINITE,
    .moves = {MOVE_NASTY_PLOT, MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_SLUDGE_BOMB}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Flannery5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_ARCANINE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HELPING_HAND, MOVE_FLAMETHROWER, MOVE_SUNNY_DAY, MOVE_ROAR}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MAGCARGO,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_ATTRACT, MOVE_LIGHT_SCREEN, MOVE_ROCK_SLIDE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_HOUNDOOM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROAR, MOVE_SOLAR_BEAM, MOVE_TAUNT, MOVE_SUNNY_DAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_RAPIDASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_ATTRACT, MOVE_SOLAR_BEAM, MOVE_BOUNCE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_EARTHQUAKE, MOVE_ATTRACT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_EXPLOSION, MOVE_ATTRACT}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_HEAT_ROCK,
    .moves = {MOVE_STEALTH_ROCK, MOVE_LAVA_PLUME, MOVE_RAPID_SPIN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MAGMORTAR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRE_BLAST, MOVE_FOCUS_BLAST, MOVE_THUNDERBOLT, MOVE_SCORCHING_SANDS}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_TALONFLAME,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BRAVE_BIRD, MOVE_FLARE_BLITZ, MOVE_ROOST, MOVE_U_TURN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_DARMANITAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLARE_BLITZ, MOVE_U_TURN, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_CENTISKORCH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FIRE_LASH, MOVE_LEECH_LIFE, MOVE_POWER_WHIP, MOVE_KNOCK_OFF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_HOUNDOOM,
    .heldItem = ITEM_HOUNDOOMINITE,
    .moves = {MOVE_NASTY_PLOT, MOVE_FIRE_BLAST, MOVE_DARK_PULSE, MOVE_SLUDGE_BOMB}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Norman2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_CHANSEY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LIGHT_SCREEN, MOVE_SING, MOVE_SKILL_SWAP, MOVE_FOCUS_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BLIZZARD, MOVE_SHADOW_BALL, MOVE_DOUBLE_EDGE, MOVE_FIRE_BLAST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_SPINDA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TEETER_DANCE, MOVE_SKILL_SWAP, MOVE_FACADE, MOVE_HYPNOSIS}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HYPER_BEAM, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SHADOW_BALL}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_SAWSBUCK,
    .heldItem = ITEM_CHOICE_SCARF,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_HORN_LEECH, MOVE_HIGH_JUMP_KICK, MOVE_HEADBUTT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_BEWEAR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_DOUBLE_EDGE, MOVE_SUPERPOWER, MOVE_SHADOW_CLAW}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_BOUFFALANT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HEAD_CHARGE, MOVE_EARTHQUAKE, MOVE_SUBSTITUTE, MOVE_THROAT_CHOP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_STARAPTOR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_FINAL_GAMBIT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RETALIATE, MOVE_SUCKER_PUNCH, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_KANGASKHAN,
    .heldItem = ITEM_KANGASKHANITE,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_FAKE_OUT, MOVE_BODY_SLAM}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Norman3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BLIZZARD, MOVE_SHADOW_BALL, MOVE_DOUBLE_EDGE, MOVE_FIRE_BLAST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CHANSEY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LIGHT_SCREEN, MOVE_SING, MOVE_SKILL_SWAP, MOVE_FOCUS_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_KANGASKHAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FAKE_OUT, MOVE_DIZZY_PUNCH, MOVE_ENDURE, MOVE_REVERSAL}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_SPINDA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TEETER_DANCE, MOVE_SKILL_SWAP, MOVE_FACADE, MOVE_HYPNOSIS}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HYPER_BEAM, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SHADOW_BALL}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_SAWSBUCK,
    .heldItem = ITEM_CHOICE_SCARF,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_HORN_LEECH, MOVE_HIGH_JUMP_KICK, MOVE_HEADBUTT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_BEWEAR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_DOUBLE_EDGE, MOVE_SUPERPOWER, MOVE_SHADOW_CLAW}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_BOUFFALANT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HEAD_CHARGE, MOVE_EARTHQUAKE, MOVE_SUBSTITUTE, MOVE_THROAT_CHOP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_STARAPTOR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_FINAL_GAMBIT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RETALIATE, MOVE_SUCKER_PUNCH, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_KANGASKHAN,
    .heldItem = ITEM_KANGASKHANITE,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_FAKE_OUT, MOVE_BODY_SLAM}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Norman4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BLIZZARD, MOVE_SHADOW_BALL, MOVE_DOUBLE_EDGE, MOVE_FIRE_BLAST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_BLISSEY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LIGHT_SCREEN, MOVE_SING, MOVE_SKILL_SWAP, MOVE_FOCUS_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_KANGASKHAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FAKE_OUT, MOVE_DIZZY_PUNCH, MOVE_ENDURE, MOVE_REVERSAL}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_SPINDA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TEETER_DANCE, MOVE_SKILL_SWAP, MOVE_FACADE, MOVE_HYPNOSIS}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HYPER_BEAM, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SHADOW_BALL}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_SAWSBUCK,
    .heldItem = ITEM_CHOICE_SCARF,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_HORN_LEECH, MOVE_HIGH_JUMP_KICK, MOVE_HEADBUTT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_BEWEAR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_DOUBLE_EDGE, MOVE_SUPERPOWER, MOVE_SHADOW_CLAW}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_BOUFFALANT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HEAD_CHARGE, MOVE_EARTHQUAKE, MOVE_SUBSTITUTE, MOVE_THROAT_CHOP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_STARAPTOR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_FINAL_GAMBIT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RETALIATE, MOVE_SUCKER_PUNCH, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_KANGASKHAN,
    .heldItem = ITEM_KANGASKHANITE,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_FAKE_OUT, MOVE_BODY_SLAM}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Norman5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BLIZZARD, MOVE_SHADOW_BALL, MOVE_DOUBLE_EDGE, MOVE_FIRE_BLAST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_BLISSEY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PROTECT, MOVE_SING, MOVE_SKILL_SWAP, MOVE_FOCUS_PUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_KANGASKHAN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FAKE_OUT, MOVE_DIZZY_PUNCH, MOVE_ENDURE, MOVE_REVERSAL}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_TAUROS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TAKE_DOWN, MOVE_PROTECT, MOVE_FIRE_BLAST, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_SPINDA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TEETER_DANCE, MOVE_SKILL_SWAP, MOVE_FACADE, MOVE_HYPNOSIS}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HYPER_BEAM, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SHADOW_BALL}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_SAWSBUCK,
    .heldItem = ITEM_CHOICE_SCARF,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_HORN_LEECH, MOVE_HIGH_JUMP_KICK, MOVE_HEADBUTT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_BEWEAR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_DOUBLE_EDGE, MOVE_SUPERPOWER, MOVE_SHADOW_CLAW}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_BOUFFALANT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HEAD_CHARGE, MOVE_EARTHQUAKE, MOVE_SUBSTITUTE, MOVE_THROAT_CHOP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_STARAPTOR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BRAVE_BIRD, MOVE_DOUBLE_EDGE, MOVE_CLOSE_COMBAT, MOVE_FINAL_GAMBIT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RETALIATE, MOVE_SUCKER_PUNCH, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_KANGASKHAN,
    .heldItem = ITEM_KANGASKHANITE,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_FAKE_OUT, MOVE_BODY_SLAM}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Winona2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_DRATINI,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_THUNDER_WAVE, MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_TROPIUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUNNY_DAY, MOVE_AERIAL_ACE, MOVE_SOLAR_BEAM, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_SUPERSONIC, MOVE_PROTECT, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WHIRLWIND, MOVE_SPIKES, MOVE_STEEL_WING, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_AERIAL_ACE, MOVE_REST, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_MURKROW,
    .heldItem = ITEM_EJECT_BUTTON,
    .moves = {MOVE_TAILWIND, MOVE_DARK_PULSE, MOVE_HURRICANE, MOVE_HEAT_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_DAMP_ROCK,
    .moves = {MOVE_SCALD, MOVE_U_TURN, MOVE_ROOST, MOVE_DEFOG}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_CROBAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUPER_FANG, MOVE_BRAVE_BIRD, MOVE_U_TURN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_CORVIKNIGHT,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BODY_PRESS, MOVE_IRON_HEAD, MOVE_IRON_DEFENSE, MOVE_BRAVE_BIRD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_COUNTER, MOVE_BODY_PRESS, MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 50,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_ALTARIANITE,
    .moves = {MOVE_FIRE_BLAST, MOVE_HYPER_VOICE, MOVE_ROOST, MOVE_DRAGON_PULSE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Winona3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_HOOTHOOT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_DREAM_EATER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_TROPIUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUNNY_DAY, MOVE_AERIAL_ACE, MOVE_SOLAR_BEAM, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_DRAGONAIR,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_THUNDER_WAVE, MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_SUPERSONIC, MOVE_PROTECT, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WHIRLWIND, MOVE_SPIKES, MOVE_STEEL_WING, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_AERIAL_ACE, MOVE_REST, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_MURKROW,
    .heldItem = ITEM_EJECT_BUTTON,
    .moves = {MOVE_TAILWIND, MOVE_DARK_PULSE, MOVE_HURRICANE, MOVE_HEAT_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_DAMP_ROCK,
    .moves = {MOVE_SCALD, MOVE_U_TURN, MOVE_ROOST, MOVE_DEFOG}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CROBAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUPER_FANG, MOVE_BRAVE_BIRD, MOVE_U_TURN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CORVIKNIGHT,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BODY_PRESS, MOVE_IRON_HEAD, MOVE_IRON_DEFENSE, MOVE_BRAVE_BIRD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_COUNTER, MOVE_BODY_PRESS, MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_ALTARIANITE,
    .moves = {MOVE_FIRE_BLAST, MOVE_HYPER_VOICE, MOVE_ROOST, MOVE_DRAGON_PULSE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Winona4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_NOCTOWL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_DREAM_EATER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_TROPIUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUNNY_DAY, MOVE_AERIAL_ACE, MOVE_SOLAR_BEAM, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_DRAGONAIR,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_THUNDER_WAVE, MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_SUPERSONIC, MOVE_PROTECT, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WHIRLWIND, MOVE_SPIKES, MOVE_STEEL_WING, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_AERIAL_ACE, MOVE_REST, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_MURKROW,
    .heldItem = ITEM_EJECT_BUTTON,
    .moves = {MOVE_TAILWIND, MOVE_DARK_PULSE, MOVE_HURRICANE, MOVE_HEAT_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_DAMP_ROCK,
    .moves = {MOVE_SCALD, MOVE_U_TURN, MOVE_ROOST, MOVE_DEFOG}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_CROBAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUPER_FANG, MOVE_BRAVE_BIRD, MOVE_U_TURN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_CORVIKNIGHT,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BODY_PRESS, MOVE_IRON_HEAD, MOVE_IRON_DEFENSE, MOVE_BRAVE_BIRD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_COUNTER, MOVE_BODY_PRESS, MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 66,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_ALTARIANITE,
    .moves = {MOVE_FIRE_BLAST, MOVE_HYPER_VOICE, MOVE_ROOST, MOVE_DRAGON_PULSE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Winona5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_NOCTOWL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_DREAM_EATER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_TROPIUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUNNY_DAY, MOVE_AERIAL_ACE, MOVE_SOLAR_BEAM, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_SUPERSONIC, MOVE_PROTECT, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_DRAGONITE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HYPER_BEAM, MOVE_THUNDERBOLT, MOVE_EARTHQUAKE, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WHIRLWIND, MOVE_SPIKES, MOVE_STEEL_WING, MOVE_AERIAL_ACE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_SKY_ATTACK, MOVE_REST, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_MURKROW,
    .heldItem = ITEM_EJECT_BUTTON,
    .moves = {MOVE_TAILWIND, MOVE_DARK_PULSE, MOVE_HURRICANE, MOVE_HEAT_WAVE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_DAMP_ROCK,
    .moves = {MOVE_SCALD, MOVE_U_TURN, MOVE_ROOST, MOVE_DEFOG}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_CROBAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUPER_FANG, MOVE_BRAVE_BIRD, MOVE_U_TURN, MOVE_TOXIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_CORVIKNIGHT,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BODY_PRESS, MOVE_IRON_HEAD, MOVE_IRON_DEFENSE, MOVE_BRAVE_BIRD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_COUNTER, MOVE_BODY_PRESS, MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_ALTARIANITE,
    .moves = {MOVE_FIRE_BLAST, MOVE_HYPER_VOICE, MOVE_ROOST, MOVE_DRAGON_PULSE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_TateAndLiza2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_SLOWPOKE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_YAWN, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_PSYCHIC, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_XATU,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_REST, MOVE_CONFUSE_RAY, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_REST, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_PSYCHIC, MOVE_FLAMETHROWER}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAPID_SPIN, MOVE_STEALTH_ROCK, MOVE_PSYCHIC, MOVE_EARTH_POWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_BRONZONG,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_GYRO_BALL, MOVE_STEALTH_ROCK, MOVE_PSYWAVE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_REUNICLUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CALM_MIND, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_RECOVER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_GOTHITELLE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CONFIDE, MOVE_CHARM, MOVE_THUNDERBOLT, MOVE_PSYCHIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_GARDEVOIR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_MOONBLAST, MOVE_PSYCHIC, MOVE_MYSTICAL_FIRE, MOVE_HEALING_WISH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_GALLADE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_TateAndLiza3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_DROWZEE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_HEADBUTT, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_SLOWPOKE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_YAWN, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_PSYCHIC, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_XATU,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_REST, MOVE_CONFUSE_RAY, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_REST, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_PSYCHIC, MOVE_FLAMETHROWER}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAPID_SPIN, MOVE_STEALTH_ROCK, MOVE_PSYCHIC, MOVE_EARTH_POWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_BRONZONG,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_GYRO_BALL, MOVE_STEALTH_ROCK, MOVE_PSYWAVE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_REUNICLUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CALM_MIND, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_RECOVER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_GOTHITELLE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CONFIDE, MOVE_CHARM, MOVE_THUNDERBOLT, MOVE_PSYCHIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_GARDEVOIR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_MOONBLAST, MOVE_PSYCHIC, MOVE_MYSTICAL_FIRE, MOVE_HEALING_WISH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_GALLADE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_TateAndLiza4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_HYPNO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_HEADBUTT, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_PSYCHIC, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_SLOWPOKE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_YAWN, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_XATU,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_REST, MOVE_CONFUSE_RAY, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_REST, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_PSYCHIC, MOVE_FLAMETHROWER}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAPID_SPIN, MOVE_STEALTH_ROCK, MOVE_PSYCHIC, MOVE_EARTH_POWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_BRONZONG,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_GYRO_BALL, MOVE_STEALTH_ROCK, MOVE_PSYWAVE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_REUNICLUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CALM_MIND, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_RECOVER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_GOTHITELLE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CONFIDE, MOVE_CHARM, MOVE_THUNDERBOLT, MOVE_PSYCHIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_GARDEVOIR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_MOONBLAST, MOVE_PSYCHIC, MOVE_MYSTICAL_FIRE, MOVE_HEALING_WISH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_GALLADE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_TateAndLiza5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_HYPNO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_HEADBUTT, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_PSYCHIC, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_SLOWKING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_YAWN, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_PROTECT}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_XATU,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_REST, MOVE_CONFUSE_RAY, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_REST, MOVE_CALM_MIND}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_PSYCHIC, MOVE_FLAMETHROWER}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAPID_SPIN, MOVE_STEALTH_ROCK, MOVE_PSYCHIC, MOVE_EARTH_POWER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_BRONZONG,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_GYRO_BALL, MOVE_STEALTH_ROCK, MOVE_PSYWAVE, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_REUNICLUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CALM_MIND, MOVE_PSYSHOCK, MOVE_FOCUS_BLAST, MOVE_RECOVER}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_GOTHITELLE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CONFIDE, MOVE_CHARM, MOVE_THUNDERBOLT, MOVE_PSYCHIC}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_GARDEVOIR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_MOONBLAST, MOVE_PSYCHIC, MOVE_MYSTICAL_FIRE, MOVE_HEALING_WISH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_GALLADE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Juan2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_POLIWAG,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_RAIN_DANCE, MOVE_PROTECT, MOVE_HYDRO_PUMP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_BOUNCE, MOVE_FISSURE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_BODY_SLAM, MOVE_PROTECT, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_REST, MOVE_CRABHAMMER, MOVE_TAUNT, MOVE_AQUA_JET}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_WATER_PULSE, MOVE_DRACO_METEOR, MOVE_ICE_BEAM, MOVE_REST}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROAR, MOVE_ICE_BEAM, MOVE_SUPER_FANG, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYDRO_PUMP, MOVE_DRACO_METEOR, MOVE_ICE_BEAM, MOVE_SCALD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_BASCULEGION,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WAVE_CRASH, MOVE_AGILITY, MOVE_PSYCHIC_FANGS, MOVE_FLIP_TURN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KNOCK_OFF, MOVE_CRABHAMMER, MOVE_AQUA_JET, MOVE_CRUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_TOXAPEX,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BANEFUL_BUNKER, MOVE_RECOVER, MOVE_SCALD, MOVE_SLUDGE_BOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 58,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_GYARADOSITE,
    .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Juan3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_POLIWHIRL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_RAIN_DANCE, MOVE_PROTECT, MOVE_HYDRO_PUMP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_BOUNCE, MOVE_FISSURE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_BODY_SLAM, MOVE_PROTECT, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_REST, MOVE_GUILLOTINE, MOVE_TAUNT, MOVE_AQUA_JET}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_WATER_PULSE, MOVE_DRACO_METEOR, MOVE_ICE_BEAM, MOVE_REST}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROAR, MOVE_ICE_BEAM, MOVE_SUPER_FANG, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYDRO_PUMP, MOVE_DRACO_METEOR, MOVE_ICE_BEAM, MOVE_SCALD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_BASCULEGION,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WAVE_CRASH, MOVE_AGILITY, MOVE_PSYCHIC_FANGS, MOVE_FLIP_TURN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KNOCK_OFF, MOVE_CRABHAMMER, MOVE_AQUA_JET, MOVE_CRUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_TOXAPEX,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BANEFUL_BUNKER, MOVE_RECOVER, MOVE_SCALD, MOVE_SLUDGE_BOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 64,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_GYARADOSITE,
    .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Juan4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_LAPRAS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYDRO_PUMP, MOVE_PERISH_SONG, MOVE_ICE_BEAM, MOVE_CONFUSE_RAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_BOUNCE, MOVE_FISSURE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_POLIWHIRL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_RAIN_DANCE, MOVE_PROTECT, MOVE_HYDRO_PUMP}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_BODY_SLAM, MOVE_PROTECT, MOVE_ICE_BEAM}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_REST, MOVE_GUILLOTINE, MOVE_TAUNT, MOVE_AQUA_JET}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_WATER_PULSE, MOVE_DRACO_METEOR, MOVE_ICE_BEAM, MOVE_REST}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROAR, MOVE_ICE_BEAM, MOVE_SUPER_FANG, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYDRO_PUMP, MOVE_DRACO_METEOR, MOVE_ICE_BEAM, MOVE_SCALD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_BASCULEGION,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WAVE_CRASH, MOVE_AGILITY, MOVE_PSYCHIC_FANGS, MOVE_FLIP_TURN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KNOCK_OFF, MOVE_CRABHAMMER, MOVE_AQUA_JET, MOVE_CRUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_TOXAPEX,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BANEFUL_BUNKER, MOVE_RECOVER, MOVE_SCALD, MOVE_SLUDGE_BOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 68,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_GYARADOSITE,
    .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Juan5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_LAPRAS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYDRO_PUMP, MOVE_PERISH_SONG, MOVE_ICE_BEAM, MOVE_CONFUSE_RAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_BOUNCE, MOVE_FISSURE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_POLITOED,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYPNOSIS, MOVE_RAIN_DANCE, MOVE_HYDRO_PUMP, MOVE_PERISH_SONG}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_BODY_SLAM, MOVE_PROTECT, MOVE_SHEER_COLD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_REST, MOVE_GUILLOTINE, MOVE_TAUNT, MOVE_AQUA_JET}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_WATER_PULSE, MOVE_DRACO_METEOR, MOVE_ICE_BEAM, MOVE_REST}
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROAR, MOVE_ICE_BEAM, MOVE_SUPER_FANG, MOVE_SURF}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HYDRO_PUMP, MOVE_DRACO_METEOR, MOVE_ICE_BEAM, MOVE_SCALD}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_BASCULEGION,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WAVE_CRASH, MOVE_AGILITY, MOVE_PSYCHIC_FANGS, MOVE_FLIP_TURN}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KNOCK_OFF, MOVE_CRABHAMMER, MOVE_AQUA_JET, MOVE_CRUNCH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_TOXAPEX,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BANEFUL_BUNKER, MOVE_RECOVER, MOVE_SCALD, MOVE_SLUDGE_BOMB}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 74,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_GYARADOSITE,
    .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE}
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Angelo[] = {
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 24,
    .species = SPECIES_ILLUMISE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHOCK_WAVE, MOVE_QUICK_ATTACK, MOVE_CHARM, MOVE_NONE}
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 25,
    .species = SPECIES_VOLBEAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHOCK_WAVE, MOVE_QUICK_ATTACK, MOVE_CONFUSE_RAY, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Darius[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 40,
    .species = SPECIES_TROPIUS,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
    .lvl = 40,
    .species = SPECIES_SWANNA,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Steven[] = {
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 80,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_SPIKES, MOVE_STEEL_WING}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 78,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_ANCIENT_POWER, MOVE_EARTHQUAKE}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 79,
    .species = SPECIES_AGGRON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER, MOVE_EARTHQUAKE, MOVE_SOLAR_BEAM, MOVE_DRAGON_CLAW}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 79,
    .species = SPECIES_CRADILY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_GIGA_DRAIN, MOVE_ANCIENT_POWER, MOVE_INGRAIN, MOVE_CONFUSE_RAY}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 79,
    .species = SPECIES_ARMALDO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_ANCIENT_POWER, MOVE_AERIAL_ACE, MOVE_SLASH}
    },
    {
    .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
    .lvl = 78,
    .species = SPECIES_METAGROSS,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_METEOR_MASH, MOVE_SHADOW_BALL}
    }
};

static const struct TrainerMon sParty_Anabel[] = {
    {
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Tucker[] = {
    {
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Spenser[] = {
    {
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Greta[] = {
    {
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Noland[] = {
    {
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Lucy[] = {
    {
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Brandon[] = {
    {
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Andres2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_SANDSHREW,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_SANDSHREW,
    }
};

static const struct TrainerMon sParty_Andres3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_NOSEPASS,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_SANDSHREW,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_SANDSHREW,
    }
};

static const struct TrainerMon sParty_Andres4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 38,
    .species = SPECIES_NOSEPASS,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 38,
    .species = SPECIES_SANDSHREW,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 38,
    .species = SPECIES_SANDSHREW,
    }
};

static const struct TrainerMon sParty_Andres5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_NOSEPASS,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_SANDSLASH,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_SANDSLASH,
    }
};

static const struct TrainerMon sParty_Cory2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_TENTACOOL,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_CRAMORANT,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 33,
    .species = SPECIES_TENTACOOL,
    }
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Cory3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 35,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 35,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 35,
    .species = SPECIES_TENTACOOL,
    }
};

static const struct TrainerMon sParty_Cory4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 37,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Cory5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 39,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 39,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 39,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Pablo2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 40,
    .species = SPECIES_STARYU,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 40,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Pablo3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_STARYU,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Pablo4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_STARYU,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_STARYU,
    }
};

static const struct TrainerMon sParty_Pablo5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_STARMIE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Koji2[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 40,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 40,
    .species = SPECIES_MACHOKE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 40,
    .species = SPECIES_TOXICROAK,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 40,
    .species = SPECIES_MACHOKE,
    },
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Koji3[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_MAKUHITA,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_MACHOKE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_TOXICROAK,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_MAKUHITA,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 42,
    .species = SPECIES_MACHOKE,
    },
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Koji4[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_MACHOKE,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_TOXICROAK,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_MAKUHITA,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 45,
    .species = SPECIES_MACHOKE,
    },
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Koji5[] = {
    #ifdef CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_MACHAMP,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_MACHAMP,
    }
    #else // CANON_MODE
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_TOXICROAK,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_MAKUHITA,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 47,
    .species = SPECIES_MACHOKE,
    },
    #endif // CANON_MODE
};

static const struct TrainerMon sParty_Cristin2[] = {
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 38,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
    .lvl = 38,
    .species = SPECIES_VIGOROTH,
    }
};

static const struct TrainerMon sParty_Cristin3[] = {
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 40,
    .species = SPECIES_SPINDA,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 40,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
    .lvl = 40,
    .species = SPECIES_VIGOROTH,
    }
};

static const struct TrainerMon sParty_Cristin4[] = {
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 42,
    .species = SPECIES_SPINDA,
    },
    {
    .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
    .lvl = 42,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
    .lvl = 42,
    .species = SPECIES_VIGOROTH,
    }
};

static const struct TrainerMon sParty_Cristin5[] = {
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 45,
    .species = SPECIES_SPINDA,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 45,
    .species = SPECIES_EXPLOUD,
    },
    {
    .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
    .lvl = 45,
    .species = SPECIES_SLAKING,
    }
};

static const struct TrainerMon sParty_Fernando2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 38,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 38,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 38,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_Fernando3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 40,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 40,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 40,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_Fernando4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 42,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 42,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 42,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_Fernando5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 45,
    .species = SPECIES_EXPLOUD,
    }
};

static const struct TrainerMon sParty_Sawyer2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 29,
    .species = SPECIES_NUMEL,
    }
};

static const struct TrainerMon sParty_Sawyer3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 31,
    .species = SPECIES_GRAVELER,
    }
};

static const struct TrainerMon sParty_Sawyer4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 33,
    .species = SPECIES_GRAVELER,
    }
};

static const struct TrainerMon sParty_Sawyer5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_CAMERUPT,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 36,
    .species = SPECIES_GOLEM,
    }
};

static const struct TrainerMon sParty_Gabrielle2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_SKITTY,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_LOTAD,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_SEEDOT,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 34,
    .species = SPECIES_TAILLOW,
    }
};

static const struct TrainerMon sParty_Gabrielle3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_SKITTY,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_NUZLEAF,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 36,
    .species = SPECIES_TAILLOW,
    }
};

static const struct TrainerMon sParty_Gabrielle4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 38,
    .species = SPECIES_DELCATTY,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 38,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 38,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 38,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 38,
    .species = SPECIES_NUZLEAF,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 38,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Gabrielle5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_DELCATTY,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_SHIFTRY,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 40,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Thalia2[] = {
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 37,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
    .lvl = 37,
    .species = SPECIES_HORSEA,
    }
};

static const struct TrainerMon sParty_Thalia3[] = {
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 39,
    .species = SPECIES_LUVDISC,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 39,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
    .lvl = 39,
    .species = SPECIES_SEADRA,
    }
};

static const struct TrainerMon sParty_Thalia4[] = {
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 41,
    .species = SPECIES_LUVDISC,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 41,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
    .lvl = 41,
    .species = SPECIES_SEADRA,
    }
};

static const struct TrainerMon sParty_Thalia5[] = {
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 44,
    .species = SPECIES_LUVDISC,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 44,
    .species = SPECIES_WAILORD,
    },
    {
    .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
    .lvl = 44,
    .species = SPECIES_KINGDRA,
    }
};

static const struct TrainerMon sParty_Mariela[] = {
    {
    .lvl = 45,
    .species = SPECIES_CHIMECHO,
    }
};

static const struct TrainerMon sParty_Alvaro[] = {
    {
    .lvl = 45,
    .species = SPECIES_BANETTE,
    },
    {
    .lvl = 45,
    .species = SPECIES_KADABRA,
    }
};

static const struct TrainerMon sParty_Everett[] = {
    {
    .lvl = 45,
    .species = SPECIES_WOBBUFFET,
    }
};

static const struct TrainerMon sParty_GruntMeteorFalls [] = {
    {
    .lvl = 22,
    .species = SPECIES_POOCHYENA,
    },
    {
    .lvl = 22,
    .species = SPECIES_NUMEL,
    }
};

static const struct TrainerMon sParty_Red[] = {
    {
    .lvl = 5,
    .species = SPECIES_CHARMANDER,
    }
};

static const struct TrainerMon sParty_Leaf[] = {
    {
    .lvl = 5,
    .species = SPECIES_BULBASAUR,
    }
};

static const struct TrainerMon sParty_BrendanLinkPlaceholder[] = {
    {
    .lvl = 5,
    .species = SPECIES_GROUDON,
    }
};

static const struct TrainerMon sParty_MayLinkPlaceholder[] = {
    {
    .lvl = 5,
    .species = SPECIES_KYOGRE,
    }
};
