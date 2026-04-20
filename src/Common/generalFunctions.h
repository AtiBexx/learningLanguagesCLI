//
// Created by AtiBexx2 on 2026. 03. 18.
//

#ifndef ENGLISH_GENERALFUNCTIONS_H
#define ENGLISH_GENERALFUNCTIONS_H

#include "dataFileReading.h"
#include "../Translate/translations.h"


/**
 *@File generalFunctions.h/cpp
 * @brief General utility functions for the language learning application.
 * @details Általános segédfüggvények nyelvtanulási alkalmazásokhoz.
 */
//=============================================================
/**
 * @brief Displays program explanation
 * @details Megjeleníti a program magyarázatát.
 */
void explanation();

/**
 * @brief Handles exiting logic
 *@details Kilépési logikát kezel
 */
void exiting();

/**
 * @brief Clears the screen
 * @details Törli a képernyőt
 */
void screenWipe();

/**
 * @brief Clears input buffer
 * @details Törli a bemeneti puffert
 */
void pufferDelete();

/**
 * @brief Logs an error message || Hiba üzenetet naplóz
 * @param functionName Name of the function where the error occurred || A függvény neve, amelyben a hiba történt
 * @param errorMessage Description of the error || A hiba leírása
 */
void logError(const std::string& functionName, const std::string& errorMessage);

/**
 * @brief Writes a mistake to file || Hibát ír a fájlba
 * @param word The word pair that was answered incorrectly || A helytelenül megválaszolt szópár
 */
void logMistakeWriteFile(const WordPair& word);

/**
 * @brief Plays a beep sound || Sípoló hangot játszik le
 * @param frequency Sound frequency (default: 750 Hz)
 * @param duration Duration in milliseconds (default: 300 ms)
 */
void playBeep(int frequency = 750, int duration = 300);

/**
 * @brief Waits for user to press ENTER for continue
 * @details Várja, amíg a felhasználó megnyomja az ENTER billentyűt a folytatáshoz
 */
void waitToEnter();

/**
 * @brief Removes punctuation characters from a string
 * @details Eltávolítja az írásjeleket egy szövegből (pl. ! ? . , ;)
 * @param s Input string || Bemeneti szöveg
 * @return String without punctuation || Írásjelek nélküli szöveg
 */
std::string removePunctuation(const std::string& s);

/**
 * @brief Removes accented characters from a string
 *
 * EN: Replaces accented UTF-8 characters (e.g., á, é, ö) with their base equivalents (a, e, o).
 * HU: Lecseréli az ékezetes UTF-8 karaktereket (pl. á, é, ö) alap betűkre (a, e, o).
 *
 * @param s Input string || Bemeneti szöveg
 * @return String without accents || Ékezetek nélküli szöveg
 */
std::string removeAccents(const std::string &s);

/**
 * @brief Cleans and normalizes a string
 *
 * EN: Trims whitespace, converts to lowercase, removes punctuation,
 *     and optionally removes accents based on user settings.
 * HU: Levágja a szóközöket, kisbetűssé alakít, eltávolítja az írásjeleket,
 *     és opcionálisan eltávolítja az ékezeteket a felhasználói beállítás alapján.
 *
 * @param s Input string || Bemeneti szöveg
 * @return Cleaned string || Feldolgozott szöveg
 */
std::string cleanString(const std::string& s);


#endif //ENGLISH_GENERALFUNCTIONS_H