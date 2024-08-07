#include "global.h"
#include "json_util.h"
#include "alphabetical_species.h"
#include "string_util.h"
#include "text.h"

/**
* @brief Searches for the first occurence of a substring in a string
*
* @param[in] haystack string to search
* @param[in] needle substring to search for
* @return pointer to the first character of the substring in string
* if substring does not exist, returns NULL
*/
const char *strstr(const char *haystack, const char *needle)
{
    const char *h;
    const char *n;

    if (*needle == '\0') {
        return haystack;
    }

    while (*haystack != '\0') {
        h = haystack;
        n = needle;
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {
            return haystack;
        }
        haystack++;
    }
    return NULL;
}


/**
 * @brief Locate first occurrence of character in string
 *
 * @param[in] str string
 * @param[in] chr character
 * @return pointer to character if found, NULL otherwise
 */
const char *strchr(const char *str, int chr)
{
    while (*str != '\0' && *str != (char)chr) str++;
    if (*str == (char)chr) return str;
    return NULL;
}

/**
* @brief Binary search function that optimises string comparison to speciesNamesWithID
*
* @param[in] name string to search the array for
* @param[in] size number of objects in the array to compare
* @return associated Pokemon ID
*/
u16 BinarySearchSpeciesArray(const u8 *name, u16 size)
{
    s16 low = 0;
    s16 high = size - 1;

    while (low <= high)
    {
        u16 mid = (low + high) / 2;
        s8 cmp = StringCompare(name, speciesNamesWithID[mid].name);

        if (cmp == 0)
        {
            return speciesNamesWithID[mid].id;  // Found the species
        }
        else if (cmp < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return SPECIES_NONE;  // Species not found
}

/**
* @brief Extracts a field value from the JSON string
*
* @param[in] json the JSON to be extracted from
* @param[in] field the field to get data for
* @param[in] value value to be modified to result
* @param[in] maxLen the max possible length of the field
*/
void ExtractFieldValue(const u8 *json, const u8 *field, u8 *value, u16 maxLen)
{
    u8 *pos;
    u8 *start;
    u8 *end;
    u16 length;

    // Find the field in the JSON string
    pos = strstr(json, field);
    if (pos != NULL)
    {
        // Move pos to the start of the value
        pos = strchr(pos, ':');
        if (pos != NULL)
        {
            pos++;  // Move past the ':'
            pos++;  // Move past the first quote

            // Find the start and end of the value
            start = pos;
            end = strchr(start, '"');
            if (end != NULL)
            {
                length = end - start;
                if (length > maxLen - 1)
                {
                    length = maxLen - 1;  // Truncate if value is too long
                }

                // Copy the value to the output buffer
                memcpy(value, start, length);
                value[length] = EOS;  // Null-terminate the string
            }
        }
    }
}

/**
* @brief parse the API JSON response into a Pokémon
*
* @param[in] json the JSON to be extracted from
* @param[in] data the remaining params are data for creating the Pokémon
*/
void ParsePokemonJSON(const u8 *json, u8 *species, u8 *item)
{
    ExtractFieldValue(json, "species", species, POKEMON_NAME_LENGTH);
    ExtractFieldValue(json, "item", item, ITEM_NAME_LENGTH);

    // Reassign species from name to ID
    u16 species = BinarySearchSpeciesArray(species, NUM_SPECIES);
}