#ifndef GUARD_CONSTANTS_DAY_NIGHT_H
#define GUARD_CONSTANTS_DAY_NIGHT_H

#define HOUR_MORNING 6
#define HOUR_DAY 8
#define HOUR_NIGHT 20

// not real times of day but useful for specifying override times
#define HOUR_AFTERNOON 18
#define HOUR_MIDNIGHT_0 0
#define HOUR_MIDNIGHT_24 24

#define DMTIME_MORNING 0
#define DMTIME_DAY 1
#define DNTIME_NIGHT 2

#define TINT_PERIODS_PER_HOUR 60
#define MINUTES_PER_TINT_PERIOD (60 / TINT_PERIODS_PER_HOUR)

// combined with the code in field_specials.c the following periods are included in the game:
// Morning: 6am to 8am (mechinically night)
// Day: 8am to 8pm
// Noon: 6pm to 8pm (mechanically day)
// Night: 8pm to 6am

#endif  // GUARD_CONSTANTS_DAY_NIGHT_H