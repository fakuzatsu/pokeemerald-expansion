#include "global.h"
#include "main.h"
#include "text.h"
#include "task.h"
#include "data.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "scanline_effect.h"
#include "text_window.h"
#include "bg.h"
#include "window.h"
#include "strings.h"
#include "text_window.h"
#include "menu.h"
#include "palette.h"
#include "constants/songs.h"
#include "sound.h"
#include "global_trade_station.h"
#include "internet_options_menu.h"
#include "union_room.h"
#include "title_screen.h"
#include "ereader_screen.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "string_util.h"
#include "mystery_gift.h"
#include "mystery_gift_view.h"
#include "mystery_gift_menu.h"
#include "save.h"
#include "link.h"
#include "mystery_gift_client.h"
#include "mystery_gift_server.h"
#include "event_data.h"
#include "link_rfu.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokedex.h"
#include "wonder_news.h"
#include "constants/cable_club.h"
#include "constants/party_menu.h"
#include "field_weather.h"
#include "constants/rgb.h"
#include "field_screen_effect.h"
#include "trade.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"

#define LIST_MENU_TILE_NUM 10
#define LIST_MENU_PAL_NUM 224

#define LETTER_IN_RANGE_UPPER(letter, range) \
    ((letter) >= sLetterSearchRanges[range][0]                                  \
  && (letter) < sLetterSearchRanges[range][0] + sLetterSearchRanges[range][1])  \

#define LETTER_IN_RANGE_LOWER(letter, range) \
    ((letter) >= sLetterSearchRanges[range][2]                                  \
  && (letter) < sLetterSearchRanges[range][2] + sLetterSearchRanges[range][3])  \


static void LoadMysteryGiftTextboxBorder(u8 bgId);
static void CreateInternetOptionsTask(void);
static void Task_InternetOptions(u8 taskId);

EWRAM_DATA static u8 sDownArrowCounterAndYCoordIdx[8] = {};
EWRAM_DATA struct InternetOptionsPokedexView *sInternetOptionsPokedexView = NULL;

static const u16 sTextboxBorder_Pal[] = INCBIN_U16("graphics/interface/mystery_gift_textbox_border.gbapal");
static const u32 sTextboxBorder_Gfx[] = INCBIN_U32("graphics/interface/mystery_gift_textbox_border.4bpp.lz");

// const rom data
//#include "data/pokemon/pokedex_orders.h"
extern const u16 gPokedexOrder_Alphabetical[];

struct InternetOptionsTaskData
{
    u16 var; // Multipurpose
    u16 depositPokemon;
    u16 searchPokemon;
    u16 unused3;
    u8 state;
    u8 textState;
    u8 unused4;
    u8 unused5;
    bool8 isWonderNews;
    bool8 sourceIsFriend;
    u8 msgId;
    u8 * clientMsg;
};

static const struct BgTemplate sBGTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }, {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }
};

static const struct WindowTemplate sMainWindows[] = {
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 12,
        .baseBlock = 0x0013
    }, {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 12,
        .baseBlock = 0x004f
    }, {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 15,
        .width = 30,
        .height = 5,
        .paletteNum = 13,
        .baseBlock = 0x004f
    }, {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 2,
        .width = 12,
        .height = 12,
        .paletteNum = 12,
        .baseBlock = 0x00e5
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sWindowTemplate_YesNoMsg_Wide = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 28,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sWindowTemplate_YesNoMsg = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 20,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sWindowTemplate_GiftSelect = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 19,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sWindowTemplate_ABCSelect = {
    .bg = 0,
    .tilemapLeft = 13,
    .tilemapTop = 3,
    .width = 4,
    .height = 10,
    .paletteNum = 12,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sWindowTemplate_LevelSelect = {
    .bg = 0,
    .tilemapLeft = 17,
    .tilemapTop = 3,
    .width = 12,
    .height = 10,
    .paletteNum = 12,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sWindowTemplate_PokemonSelect = {
    .bg = 0,
    .tilemapLeft = 19,
    .tilemapTop = 3,
    .width = 10,
    .height = 10,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_ThreeOptions = {
    .bg = 0,
    .tilemapLeft = 8,
    .tilemapTop = 6,
    .width = 14,
    .height = 6,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_FiveOptions = {
    .bg = 0,
    .tilemapLeft = 8,
    .tilemapTop = 6,
    .width = 14,
    .height = 10,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_YesNoBox = {
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 15,
    .width = 6,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_GiftSelect_3Options = {
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 11,
    .width = 7,
    .height = 8,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_GiftSelect_2Options = {
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 13,
    .width = 7,
    .height = 6,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_GiftSelect_1Option = {
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 15,
    .width = 7,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct ListMenuItem sListMenuItems_SearchDeposit[] = {
    { gText_SearchPokemon,  0 },
    { gText_DepositPokemon,   1 },
    { gText_Exit3,        LIST_CANCEL }
};

static const struct ListMenuItem sListMenuItems_SearchWithdraw[] = {
    { gText_SearchPokemon,  0 },
    { gText_WithdrawPokemon,                1 },
    { gText_Exit3,                LIST_CANCEL }
};

static const struct ListMenuItem sListMenuItems_InternetOptions[] = {
    { gText_GiftDownload,  0 },
    { gText_Bank,   1 },
    { gText_Friends,   2 },
    { gText_Sync,   3 },
    { gText_Exit3,        LIST_CANCEL }
};

static const struct ListMenuItem sListMenuItems_ABC[] = {
    { gText_DexSearchAlphaABC,  0 },
    { gText_DexSearchAlphaDEF,  1 },
    { gText_DexSearchAlphaGHI,  2 },
    { gText_DexSearchAlphaJKL,  3 },
    { gText_DexSearchAlphaMNO,  4 },
    { gText_DexSearchAlphaPQR,  5 },
    { gText_DexSearchAlphaSTU,  6 },
    { gText_DexSearchAlphaVWX,  7 },
    { gText_DexSearchAlphaYZ,   8 },
    { gText_Exit3,                LIST_CANCEL }
};

static const struct ListMenuItem sListMenuItems_Levels[] = {
    { gText_AnyLevel,  0 },
    { gText_UnderLevel10,  1 },
    { gText_AboveLevel10,  2 },
    { gText_AboveLevel20,  3 },
    { gText_AboveLevel30,  4 },
    { gText_AboveLevel40,  5 },
    { gText_AboveLevel50,  6 },
    { gText_AboveLevel60,  7 },
    { gText_AboveLevel70,  8 },
    { gText_AboveLevel80,  9 },
    { gText_AboveLevel90, 10 },
    { gText_Exit3,                LIST_CANCEL }
};

static const struct ListMenuItem sListMenuItems_LevelsWanted[] = {
    { gText_AnyLevel,  0 },
    { gText_Level1to10,  1 },
    { gText_Level11to20,  2 },
    { gText_Level21to30,  3 },
    { gText_Level31to40,  4 },
    { gText_Level41to50,  5 },
    { gText_Level51to60,  6 },
    { gText_Level61to70,  7 },
    { gText_Level71to80,  8 },
    { gText_Level81to90,  9 },
    { gText_Level91to100, 10 },
    { gText_Exit3,                LIST_CANCEL }
};

static const struct ListMenuTemplate sListMenuTemplate_ThreeOptions = {
    .items = NULL,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = FONT_NORMAL,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenuTemplate_FiveOptions = {
    .items = NULL,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 5,
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = FONT_NORMAL,
    .cursorKind = 0
};

static const struct ListMenuItem sListMenuItems_ReceiveSendToss[] = {
    { gText_Receive,  0 },
    { gText_Send,     1 },
    { gText_Toss,     2 },
    { gText_Cancel2,  LIST_CANCEL }
};

static const struct ListMenuItem sListMenuItems_ReceiveToss[] = {
    { gText_Receive,  0 },
    { gText_Toss,     2 },
    { gText_Cancel2,  LIST_CANCEL }
};

static const struct ListMenuItem sListMenuItems_ReceiveSend[] = {
    { gText_Receive,  0 },
    { gText_Send,     1 },
    { gText_Cancel2,  LIST_CANCEL }
};

static const struct ListMenuItem sListMenuItems_Receive[] = {
    { gText_Receive,  0 },
    { gText_Cancel2,  LIST_CANCEL }
};

static const struct ListMenuTemplate sListMenu_ReceiveSendToss = {
    .items = sListMenuItems_ReceiveSendToss,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 4,
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = FONT_NORMAL,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_ReceiveToss = {
    .items = sListMenuItems_ReceiveToss,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = FONT_NORMAL,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_ABCMenu = {
    .items = sListMenuItems_ABC,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 9,
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = FONT_NORMAL,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_Levels = {
    .items = sListMenuItems_Levels,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 11,
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = FONT_NORMAL,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_LevelsWanted = {
    .items = sListMenuItems_LevelsWanted,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 11,
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = FONT_NORMAL,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_ReceiveSend = {
    .items = sListMenuItems_ReceiveSend,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = FONT_NORMAL,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_Receive = {
    .items = sListMenuItems_Receive,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 2,
    .maxShowed = 2,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = FONT_NORMAL,
    .cursorKind = 0
};

static const u8 *const sUnusedMenuTexts[] = {
    gText_VarietyOfEventsImportedWireless,
    gText_WonderCardsInPossession,
    gText_ReadNewsThatArrived,
    gText_ReturnToTitle
};

ALIGNED(2) static const u8 sTextColors_TopMenu[]      = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,     TEXT_COLOR_DARK_GRAY };
ALIGNED(2) static const u8 sTextColors_TopMenu_Copy[] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,     TEXT_COLOR_DARK_GRAY };
ALIGNED(2) static const u8 sInternetOptions_Ereader_TextColor_2[]  = { TEXT_COLOR_WHITE,       TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY };


struct SearchOptionText
{
    const u8 *title;
};


static void VBlankCB_MysteryGiftEReader(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

void CB2_InternetOptions(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static bool32 HandleInternetOptionsSetup()
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        //ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTasks();
        ScanlineEffect_Stop();
        ResetBgsAndClearDma3BusyFlags(0);

        InitBgsFromTemplates(0, sBGTemplates, ARRAY_COUNT(sBGTemplates));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);

        SetBgTilemapBuffer(3, Alloc(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(2, Alloc(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(1, Alloc(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(0, Alloc(BG_SCREEN_SIZE));

        LoadMysteryGiftTextboxBorder(3);
        InitWindows(sMainWindows);
        DeactivateAllTextPrinters();
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gMain.state++;
        break;
    case 1:
        LoadPalette(sTextboxBorder_Pal, 0, 0x20);
        LoadPalette(GetTextWindowPalette(2), 0xd0, 0x20);
        Menu_LoadStdPalAt(0xC0);
        LoadUserWindowBorderGfx(0, 0xA, 0xE0);
        LoadUserWindowBorderGfx_(0, 0x1, 0xF0);
        FillBgTilemapBufferRect(0, 0x000, 0, 0, 32, 32, 0x11);
        FillBgTilemapBufferRect(1, 0x000, 0, 0, 32, 32, 0x11);
        FillBgTilemapBufferRect(2, 0x000, 0, 0, 32, 32, 0x11);
        InternetOptions_DrawCheckerboardPattern(3);
        PrintInternetOptionsTopMenu(FALSE, FALSE);
        gMain.state++;
        break;
    case 2:
        CopyBgTilemapBufferToVram(3);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);
        gMain.state++;
        break;
    case 3:
        ShowBg(0);
        ShowBg(3);
        FadeInFromBlack();
        SetVBlankCallback(VBlankCB_MysteryGiftEReader);
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
        return TRUE;
    }

    return FALSE;
}

void CB2_InitInternetOptions(void)
{
    if (HandleInternetOptionsSetup())
    {
        FadeInNewBGM(MUS_RG_MYSTERY_GIFT,4);
        SetMainCallback2(CB2_InternetOptions);
        CreateInternetOptionsTask();
    }
    RunTasks();
}

void PrintInternetOptionsTopMenu(bool8 isEReader, bool32 useCancel)
{
    const u8 * header;
    const u8 * options;
    FillWindowPixelBuffer(0, 0);
    if (!isEReader)
    {
        header = gText_GlobalTradeStation;
        options = !useCancel ? gText_PickOKExit : gText_PickOKCancel;
    }
    else
    {
        header = gJPText_MysteryGift;
        options = gJPText_DecideStop;
    }

    AddTextPrinterParameterized4(0, FONT_NORMAL, 4, 1, 0, 0, sTextColors_TopMenu, TEXT_SKIP_DRAW, header);
    AddTextPrinterParameterized4(0, FONT_SMALL, GetStringRightAlignXOffset(FONT_SMALL, options, 0xDE), 1, 0, 0, sTextColors_TopMenu, TEXT_SKIP_DRAW, options);
    CopyWindowToVram(0, COPYWIN_GFX);
    PutWindowTilemap(0);
}

void InternetOptions_DrawTextBorder(u8 windowId)
{
    DrawTextBorderOuter(windowId, 0x01, 0xF);
}

void InternetOptions_DrawCheckerboardPattern(u32 bg)
{
    s32 i = 0, j;

    FillBgTilemapBufferRect(bg, 0x003, 0, 0, 32, 2, 0x11);

    for (i = 0; i < 18; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if ((i & 1) != (j & 1))
                FillBgTilemapBufferRect(bg, 1, j, i + 2, 1, 1, 0x11);
            else
                FillBgTilemapBufferRect(bg, 2, j, i + 2, 1, 1, 0x11);
        }
    }
}

void InternetOptionsAddTextPrinterToWindow1(const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    FillWindowPixelBuffer(1, 0x11);
    AddTextPrinterParameterized4(1, FONT_NORMAL, 0, 1, 0, 0, sInternetOptions_Ereader_TextColor_2, 0, gStringVar4);
    DrawTextBorderOuter(1, 0x001, 0xF);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static void ClearTextWindow(void)
{
    rbox_fill_rectangle(1);
    ClearWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_MAP);
}

#define DOWN_ARROW_X 208
#define DOWN_ARROW_Y 20

bool32 PrintInternetOptionsMenuMessage(u8 *textState, const u8 *str)
{
    switch (*textState)
    {
    case 0:
        InternetOptionsAddTextPrinterToWindow1(str);
        (*textState)++;
        break;
    case 1:
        DrawDownArrow(1, DOWN_ARROW_X, DOWN_ARROW_Y, 1, FALSE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        if (({JOY_NEW(A_BUTTON);}))
            (*textState)++;
        if (({JOY_NEW(B_BUTTON);}))
            //(*textState)==3;
            return TRUE;
        break;
    case 2:
        DrawDownArrow(1, DOWN_ARROW_X, DOWN_ARROW_Y, 1, TRUE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        *textState = 0;
        //ClearTextWindow();
        return TRUE;
    case 3:
        //DrawDownArrow(1, DOWN_ARROW_X, DOWN_ARROW_Y, 1, TRUE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        //*textState = 3;
        //ClearTextWindow();
        return TRUE;
    case 0xFF:
        *textState = 2;
        return FALSE;
    }
    return FALSE;
}

static void HideDownArrow(void)
{
    DrawDownArrow(1, DOWN_ARROW_X, DOWN_ARROW_Y, 1, FALSE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
}

static void ShowDownArrow(void)
{
    DrawDownArrow(1, DOWN_ARROW_X, DOWN_ARROW_Y, 1, TRUE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
}

// Unused
static bool32 UNUSED HideDownArrowAndWaitButton(u8 * textState)
{
    switch (*textState)
    {
    case 0:
        HideDownArrow();
        if (JOY_NEW(A_BUTTON | B_BUTTON))
            (*textState)++;
        break;
    case 1:
        ShowDownArrow();
        *textState = 0;
        return TRUE;
    }
    return FALSE;
}

static u32 InternetOptions_HandleThreeOptionMenu(u8 * unused0, u16 * unused1, u8 whichMenu)
{
    struct ListMenuTemplate listMenuTemplate = sListMenuTemplate_FiveOptions;
    struct WindowTemplate windowTemplate = sWindowTemplate_FiveOptions;
    s32 width;
    s32 response;

    if (whichMenu == 0)
        listMenuTemplate.items = sListMenuItems_InternetOptions;
    else
        listMenuTemplate.items = sListMenuItems_SearchWithdraw;

    width = Intl_GetListMenuWidth(&listMenuTemplate);
    if (width & 1)
        width++;

    windowTemplate.width = width;
    if (width < 30)
        windowTemplate.tilemapLeft = (30 - width) / 2;
    else
        windowTemplate.tilemapLeft = 0;

    response = DoMysteryGiftListMenu(&windowTemplate, &listMenuTemplate, 1, LIST_MENU_TILE_NUM, LIST_MENU_PAL_NUM);
    if (response != LIST_NOTHING_CHOSEN)
    {
        ClearWindowTilemap(2);
        CopyWindowToVram(2, COPYWIN_MAP);
    }
    return response;
}

s8 DoInternetOptionsYesNo(u8 * textState, u16 * windowId, bool8 yesNoBoxPlacement, const u8 * str)
{
    struct WindowTemplate windowTemplate;
    s8 input;

    switch (*textState)
    {
    case 0:
        // Print question message
        StringExpandPlaceholders(gStringVar4, str);
        if (yesNoBoxPlacement == 0)
            *windowId = AddWindow(&sWindowTemplate_YesNoMsg_Wide);
        else
            *windowId = AddWindow(&sWindowTemplate_YesNoMsg);
        FillWindowPixelBuffer(*windowId, 0x11);
        AddTextPrinterParameterized4(*windowId, FONT_NORMAL, 0, 1, 0, 0, sInternetOptions_Ereader_TextColor_2, 0, gStringVar4);
        DrawTextBorderOuter(*windowId, 0x001, 0x0F);
        CopyWindowToVram(*windowId, COPYWIN_GFX);
        PutWindowTilemap(*windowId);
        (*textState)++;
        break;
    case 1:
        // Create Yes/No
        windowTemplate = sWindowTemplate_YesNoBox;
        if (yesNoBoxPlacement == 0)
            windowTemplate.tilemapTop = 9;
        else
            windowTemplate.tilemapTop = 15;
        CreateYesNoMenu(&windowTemplate, 10, 14, 0);
        (*textState)++;
        break;
    case 2:
        // Handle Yes/No input
        input = Menu_ProcessInputNoWrapClearOnChoose();
        if (input == MENU_B_PRESSED || input == 0 || input == 1)
        {
            *textState = 0;
            rbox_fill_rectangle(*windowId);
            ClearWindowTilemap(*windowId);
            CopyWindowToVram(*windowId, COPYWIN_MAP);
            RemoveWindow(*windowId);
            return input;
        }
        break;
    case 0xFF:
        *textState = 0;
        rbox_fill_rectangle(*windowId);
        ClearWindowTilemap(*windowId);
        CopyWindowToVram(*windowId, COPYWIN_MAP);
        RemoveWindow(*windowId);
        return MENU_B_PRESSED;
    }

    return MENU_NOTHING_CHOSEN;
}


static bool32 PrintSuccessMessage(u8 * state, const u8 * msg, u16 * timer)
{
    switch (*state)
    {
    case 0:
        if (msg != NULL)
            InternetOptionsAddTextPrinterToWindow1(msg);
        PlayFanfare(MUS_OBTAIN_ITEM);
        *timer = 0;
        (*state)++;
        break;
    case 1:
        if (++(*timer) > 240)
            (*state)++;
        break;
    case 2:
        if (IsFanfareTaskInactive())
        {
            *state = 0;
            ClearTextWindow();
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static const u8 * GetServerResultMessage(bool32 * wonderSuccess, bool8 sourceIsFriend, u32 msgId)
{
    const u8 * result = gText_CommunicationError;
    *wonderSuccess = FALSE;
    switch (msgId)
    {
    case SVR_MSG_NOTHING_SENT:
        result = gText_NothingSentOver;
        break;
    case SVR_MSG_RECORD_UPLOADED:
        result = gText_RecordUploadedViaWireless;
        break;
    case SVR_MSG_CARD_SENT:
        result = gText_WonderCardSentTo;
        *wonderSuccess = TRUE;
        break;
    case SVR_MSG_NEWS_SENT:
        result = gText_WonderNewsSentTo;
        *wonderSuccess = TRUE;
        break;
    case SVR_MSG_STAMP_SENT:
        result = gText_StampSentTo;
        break;
    case SVR_MSG_HAS_CARD:
        result = gText_OtherTrainerHasCard;
        break;
    case SVR_MSG_HAS_STAMP:
        result = gText_OtherTrainerHasStamp;
        break;
    case SVR_MSG_HAS_NEWS:
        result = gText_OtherTrainerHasNews;
        break;
    case SVR_MSG_NO_ROOM_STAMPS:
        result = gText_NoMoreRoomForStamps;
        break;
    case SVR_MSG_CLIENT_CANCELED:
        result = gText_OtherTrainerCanceled;
        break;
    case SVR_MSG_CANT_SEND_GIFT_1:
        result = gText_CantSendGiftToTrainer;
        break;
    case SVR_MSG_COMM_ERROR:
        result = gText_CommunicationError;
        break;
    case SVR_MSG_GIFT_SENT_1:
        result = gText_GiftSentTo;
        break;
    case SVR_MSG_GIFT_SENT_2:
        result = gText_GiftSentTo;
        break;
    case SVR_MSG_CANT_SEND_GIFT_2:
        result = gText_CantSendGiftToTrainer;
        break;
    }
    return result;
}

static bool32 UNUSED PrintServerResultMessage(u8 * state, u16 * timer, bool8 sourceIsFriend, u32 msgId)
{
    bool32 wonderSuccess;
    const u8 * str = GetServerResultMessage(&wonderSuccess, sourceIsFriend, msgId);
    if (wonderSuccess)
        return PrintSuccessMessage(state, str, timer);
    else
        return PrintInternetOptionsMenuMessage(state, str);
}

// States for Task_MysteryGift.
// CLIENT states are for when the player is receiving a gift, and use mystery_gift_client.c link functions.
// SERVER states are for when the player is sending a gift, and use mystery_gift_server.c link functions.
// Other states handle the general Mystery Gift menu usage.
enum {
    InternetOptions_STATE_TO_MAIN_MENU,
    InternetOptions_STATE_MAIN_MENU,
    InternetOptions_STATE_SEEK_SETUP,
    InternetOptions_STATE_SEEKING,
    InternetOptions_STATE_SEARCH_POKEMON,
    InternetOptions_STATE_SEARCH_POKEMON_LIST,
    InternetOptions_STATE_SEARCH_POKEMON_LEVEL_LIST,
    InternetOptions_STATE_FETCHING_POKEMON,
    InternetOptions_STATE_SELECT_FETCHED_POKEMON,
    InternetOptions_STATE_START_SEARCH,
    InternetOptions_STATE_SUCCESSFUL_SEARCH,
    InternetOptions_STATE_UNSUCCESSFUL_SEARCH,
    InternetOptions_STATE_FIND_MATCH,
    InternetOptions_STATE_TRADE_MATCH,
    InternetOptions_STATE_DEPOSIT_POKEMON,
    InternetOptions_STATE_PICK_WANTED_POKEMON,
    InternetOptions_STATE_DEPOSITING_POKEMON,
    InternetOptions_STATE_POKEMON_LIST,
    InternetOptions_STATE_POKEMON_LEVEL_LIST,
    InternetOptions_STATE_RETURN_POKEMON_LIST,
    InternetOptions_STATE_CONFIRM_OFFER,
    InternetOptions_STATE_WAIT,
    InternetOptions_STATE_WITHDRAW_POKEMON,
    InternetOptions_STATE_CLIENT_LINK_START,
    InternetOptions_STATE_CLIENT_LINK_WAIT,
    InternetOptions_STATE_CLIENT_COMMUNICATING,
    InternetOptions_STATE_CLIENT_LINK,
    InternetOptions_STATE_CLIENT_YES_NO,
    InternetOptions_STATE_CLIENT_MESSAGE,
    InternetOptions_STATE_CLIENT_ASK_TOSS,
    InternetOptions_STATE_CLIENT_ASK_TOSS_UNRECEIVED,
    InternetOptions_STATE_CLIENT_LINK_END,
    InternetOptions_STATE_CLIENT_COMM_COMPLETED,
    InternetOptions_STATE_CLIENT_RESULT_MSG,
    InternetOptions_STATE_CLIENT_ERROR,
    InternetOptions_STATE_SAVE_LOAD_GIFT,
    InternetOptions_STATE_LOAD_GIFT,
    InternetOptions_STATE_UNUSED,
    InternetOptions_STATE_HANDLE_GIFT_INPUT,
    InternetOptions_STATE_HANDLE_GIFT_SELECT,
    InternetOptions_STATE_ASK_TOSS,
    InternetOptions_STATE_ASK_TOSS_UNRECEIVED,
    InternetOptions_STATE_TOSS,
    InternetOptions_STATE_TOSS_SAVE,
    InternetOptions_STATE_TOSSED,
    InternetOptions_STATE_GIFT_INPUT_EXIT,
    InternetOptions_STATE_RECEIVE,
    InternetOptions_STATE_SEND,
    InternetOptions_STATE_SERVER_LINK_WAIT,
    InternetOptions_STATE_SERVER_LINK_START,
    InternetOptions_STATE_SERVER_LINK,
    InternetOptions_STATE_SERVER_LINK_END,
    InternetOptions_STATE_SERVER_LINK_END_WAIT,
    InternetOptions_STATE_SERVER_RESULT_MSG,
    InternetOptions_STATE_SERVER_ERROR,
    InternetOptions_STATE_EXIT,
    InternetOptions_STATE_SOURCE_PROMPT,
    InternetOptions_STATE_SOURCE_PROMPT_INPUT,
};

static void CreateInternetOptionsTask(void)
{
    u8 taskId = CreateTask(Task_InternetOptions, 0);
    struct InternetOptionsTaskData * data = (void *)gTasks[taskId].data;
    data->state = InternetOptions_STATE_TO_MAIN_MENU;
    data->textState = 0;
    data->unused4 = 0;
    data->unused5 = 0;
    data->isWonderNews = 0;
    data->sourceIsFriend = 0;
    data->var = 0;
    data->depositPokemon = 0;
    data->searchPokemon = 0;
    data->unused3 = 0;
    data->msgId = 0;
    data->clientMsg = AllocZeroed(CLIENT_MAX_MSG_SIZE);
}


static void Task_InternetOptions(u8 taskId)
{
    struct InternetOptionsTaskData *data = (void *)gTasks[taskId].data;

    switch (data->state)
    {
    case InternetOptions_STATE_TO_MAIN_MENU:
        data->state = InternetOptions_STATE_MAIN_MENU;
        break;
    case InternetOptions_STATE_MAIN_MENU:
        // Main Mystery Gift menu, player can select Wonder Cards or News (or exit)
        switch (InternetOptions_HandleThreeOptionMenu(&data->textState, &data->var, VarGet(VAR_DEPOSIT_SPECIES)>0))
        {
        case 0: // "Search Pokemon"
            data->state = InternetOptions_STATE_SEEK_SETUP;
            PlaySE(SE_SELECT);

            break;
        case 1: // "Deposit Pokemon"
            if(VarGet(VAR_DEPOSIT_SPECIES)>0)
                data->state = InternetOptions_STATE_WITHDRAW_POKEMON;
            else
                data->state = InternetOptions_STATE_DEPOSIT_POKEMON;
            PlaySE(SE_SELECT);
            break;
        case LIST_CANCEL:
            data->state = InternetOptions_STATE_EXIT;
            break;
        }
        break;
    case InternetOptions_STATE_EXIT:
        CloseLink();
        Free(data->clientMsg);
        DestroyTask(taskId);
        SetMainCallback2(MainCB_FreeAllBuffersAndReturnToInitTitleScreen);
        break;
    }
}

u16 GetInternetOptionsBaseBlock(void)
{
    return 0x1A9;
}

static void LoadMysteryGiftTextboxBorder(u8 bgId)
{
    DecompressAndLoadBgGfxUsingHeap(bgId, sTextboxBorder_Gfx, 0x100, 0, 0);
}
