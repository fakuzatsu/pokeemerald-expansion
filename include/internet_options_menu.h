#ifndef GUARD_InternetOptions_MENU_H
#define GUARD_InternetOptions_MENU_H

void CB2_InitInternetOptions(void);
void InternetOptions_DrawCheckerboardPattern(u32 bg);

void PrintInternetOptionsTopMenu(bool8 isJapanese, bool32 usePickOkCancel);

//extern EWRAM_DATA struct GTSPokedexView *sGTSPokedexView;

#endif // GUARD_InternetOptions_MENU_H