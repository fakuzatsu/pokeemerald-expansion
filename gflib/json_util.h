#ifndef GUARD_JSON_UTIL_H
#define GUARD_JSON_UTIL_H

const char *strstr(const char *haystack, const char *needle);
const char *strchr(const char *str, int chr);
void ExtractFieldValue(const u8 *json, const u8 *field, u8 *value, u16 maxLen);
void ParsePokemonJSON(const u8 *json, u8 *species, u8 *item);

#endif // GUARD_JSON_UTIL_H