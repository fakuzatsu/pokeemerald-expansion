#include "global.h"
#include "event_data.h"
#include "script_menu.h"
#include "strings.h"
#include "constants/items.h"
#include "item.h"
#include "script_menu.h"
#include "menu.h"

#define SPRAY_COUNT 0
#define SPRAY_GET 1

#define NUM_SPRAY_STRENGTH 3
#define SPRAY_MENU_Y_COORD 8

#define LOCAL_VAR_SPRAY gSpecialVar_0x8004
#define LOCAL_VAR_SPRAY_CONST VAR_0x8004

u32 CountOrGetSprays(u32);
u32 GetNumberSprayStrength(void);
u32 GetSprayId(void);
u32 GetLastUsedSprayType(void);
u32 SetSprayMenuCursorPosition(int, int);
#if I_REPEL_LURE_MENU == TRUE
void DrawSprayMenu(void);
#endif

u32 CountOrGetSprays(u32 func)
{
    u32 i, currentSpray, sprayCount = 0;
    u32 spray = GetLastUsedSprayType();

    for (i = 0; i < NUM_SPRAY_STRENGTH; i++)
    {
        currentSpray = spray + i;

        if (!CheckBagHasItem(currentSpray,1))
            continue;

        if (func == SPRAY_COUNT)
            sprayCount++;
        else
            return (currentSpray);
    }
    return sprayCount;
}

u32 GetNumberSprayStrength(void)
{
    return CountOrGetSprays(SPRAY_COUNT);
}

u32 GetSprayId(void)
{
    return CountOrGetSprays(SPRAY_GET);
}

u32 GetLastUsedSprayType(void)
{
    if (IS_LAST_USED_LURE(VarGet(VAR_REPEL_STEP_COUNT)))
        return ITEM_LURE;
    else
        return ITEM_REPEL;
}

u32 SetSprayMenuCursorPosition(int currentSpray, int count)
{
    if (VarGet(VAR_LAST_REPEL_LURE_USED) == currentSpray)
        return count;

    return 0;
}
