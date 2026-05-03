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

void settings();// beállítások || Settings
void choiceLanguage(); // nyelválasztás || language selection
void learningLanguage(); // tanulandó nyelv beállítása || set language to learn
void colorsOn(); //színek be ki kapcsolása || turn colors on and off
void saveSettings(); //Beállítások mentésére || Save settings
bool loadSettings(); //Beállítások betöltése || Load settings
void backgroundSets(); //háttér beállítása || set background color
std::string getLanguageNameByIndex(int index); // nyelvi index || language index
void soundOn(); //Hang be/ki || Sound on/off
void accentsToggle(); // Be- vagy kikapcsolja az ékezetek kezelését || // Turns accent handling on or off
void oneRoundQuizToggle(); // Egy körös kvíz be és ki kapcsolása || Toggle one round quiz on and off

//globális változó || global state
extern bool useSound; // a hang ki be kapcsolásához || to turn the sound on or off
extern size_t resumeIndex; // A folytatási index-hez a MistakExercise-ban || For the continuation index in MistakExercise
extern bool showHelp;    //
extern bool helperUsed;  //


#endif //ENGLISH_SETTINGS_H
