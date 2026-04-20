/**
* @file settings.h
 * @brief Application settings management (EN) / Alkalmazás beállításkezelés (HU)
 *
 * @details
 * EN:
 * This module handles all application settings such as:
 * - UI language selection
 * - Learning (target) language configuration
 * - Color and background settings
 * - Sound on/off
 * - Saving and loading settings from file
 *
 * HU:
 * Ez a modul kezeli az alkalmazás összes beállítását:
 * - Program nyelvének kiválasztása
 * - Tanulandó nyelv beállítása
 * - Színek és háttér beállítása
 * - Hang be/ki kapcsolása
 * - Beállítások mentése és betöltése fájlból
 */

#ifndef ENGLISH_SETTINGS_H
#define ENGLISH_SETTINGS_H
#include <string>

/**
 * @brief Open settings menu / Beállítások menü megnyitása
 *
 * EN: Displays the main settings menu and handles user interaction.
 * HU: Megjeleníti a beállítások főmenüt és kezeli a felhasználói választásokat.
 */
void settings();// beállítások || Settings

/**
 * @brief Language selection / Nyelvválasztás
 *
 * EN: Allows the user to select the UI language.
 * HU: Lehetővé teszi a program nyelvének kiválasztását.
 */
void choiceLanguage(); // nyelválasztás || language selection

/**
 * @brief Set learning language / Tanulandó nyelv beállítása
 *
 * EN: Configure native and target learning languages.
 * HU: Az anyanyelv és a tanult nyelv beállítása.
 */
void learningLanguage(); // tanulandó nyelv beállítása || set language to learn

/**
 * @brief Toggle colors / Színek be- és kikapcsolása
 *
 * EN: Enables or disables colored output.
 * HU: Be- vagy kikapcsolja a színes megjelenítést.
 */
void colorsOn(); //színek be ki kapcsolása || turn colors on and off

/**
 * @brief Save settings / Beállítások mentése
 *
 * EN: Saves current configuration into a file.
 * HU: Elmenti az aktuális beállításokat fájlba.
 */
void saveSettings(); //Beállítások mentésére || Save settings

/**
 * @brief Load settings / Beállítások betöltése
 *
 * @return true if successful, false otherwise
 *
 * EN: Loads configuration from file if it exists.
 * HU: Betölti a beállításokat fájlból, ha az létezik.
 */
bool loadSettings(); //Beállítások betöltése || Load settings

/**
 * @brief Set background color / Háttérszín beállítása
 *
 * EN: Allows selecting background color.
 * HU: Lehetővé teszi a háttérszín kiválasztását.
 */
void backgroundSets(); //háttér beállítása || set background color

/**
 * @brief Get language name by index / Nyelv neve index alapján
 *
 * @param index Language enum index
 * @return std::string Language name
 *
 * EN: Returns the name of the language based on index.
 * HU: Visszaadja a nyelv nevét az index alapján.
 */
std::string getLanguageNameByIndex(int index); // nyelvi index || language index

/**
 * @brief Toggle sound / Hang be- és kikapcsolása
 *
 * EN: Enables or disables sound.
 * HU: Be- vagy kikapcsolja a hangot.
 */
void soundOn(); //Hang be/ki || Sound on/off

/**
 * @brief Global sound flag / Globális hang kapcsoló
 *
 * EN: Indicates whether sound is enabled.
 * HU: Meghatározza, hogy a hang be van-e kapcsolva.
 */
//globális változó || global state
extern bool useSound;

/**
 * @brief Toggle accent handling / Ékezetek be- és kikapcsolása
 *
 * EN: Enables or disables accent handling (e.g., ignores accents in comparisons).
 * HU: Be- vagy kikapcsolja az ékezetek kezelését (pl. összehasonlításkor figyelmen kívül hagyja az ékezeteket).
 */
void accentsToggle();


#endif //ENGLISH_SETTINGS_H
