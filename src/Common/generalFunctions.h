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

//Megjeleníti a program magyarázatát || Displays program explanation
void explanation();

// Kilépési logikát kezel || Handles exiting logic
void exiting();

//Törli a képernyőt || Clears the screen
void screenWipe();

// Törli a bemeneti puffert || Clears input buffer
void pufferDelete();

// Program Hibákat írja a fájlba || Writes program's mistakes to a file
void logError(const std::string& functionName, const std::string& errorMessage);

// Az elrontott szópárokat írja egy fájlba || writes the corrupted word pairs to a file
void logMistakeWriteFile(const WordPair& word);

// Sípoló hangot játszik le || Plays a beeping sound
void playBeep(int frequency = 750, int duration = 300);

// megáll és vár az enterre || stops and waits for the entrance
void waitToEnter();

// Eltávolítja az írásjeleket egy szövegből (pl. ! ? . , ;) || Removes punctuation from a string (e.g., ! ? . , ;)
std::string removePunctuation(const std::string& s);

// Lecseréli az ékezetes UTF-8 karaktereket (pl. á, é, ö) alap betűkre (a, e, o).
// Replaces accented UTF-8 characters (e.g. á, é, ö) with basic letters (a, e, o).
// Figyelmen kívül hagyja az ékezeteket
// Ignore accents
std::string removeAccents(const std::string &s);

// Levágja a szóközöket, kisbetűssé alakít, eltávolítja az írásjeleket
// Trim, lowercase, remove punctuation
std::string cleanString(const std::string& s);

// Dinamikusan a szélességhez igazítja a sorokat nem csúsznak el
// Dynamically adjusts the width of the rows so they don't slide
int getTerminalWidth();

// Tördeli a szöveget a terminál szélességéhez igazítva
// Wraps text to fit the width of the terminal
void printWrapped(const std::string& text, int width = 0);


#endif //ENGLISH_GENERALFUNCTIONS_H