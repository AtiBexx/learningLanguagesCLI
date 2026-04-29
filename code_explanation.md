# Code Explanation: Language Learning Application

This document serves as an overview of the application's structure and logic. Below is a breakdown of its primary responsibilities:

## Global Language State
The program maintains three global `Language` variables to manage the user interface and the translation logic:
- `programUiLanguage`: Determines the language of the menus and UI text.
- `motherLanguage`: Defines the user's native language for the quiz.
- `targetLanguage`: Defines the language the user is trying to learn.

## Initialization (Windows Specific)
Inside the `main` function, if the program is running on a Windows environment (`_WIN32`), it performs console configuration:
1. **UTF-8 Support**: Sets the console output and input code pages to UTF-8 (`CP_UTF8`) to ensure special characters and accents are displayed correctly.
2. **Virtual Terminal Processing**: Enables ANSI escape sequences. This is necessary for features like `screenWipe()` (which likely uses ANSI codes to clear the terminal) and colored text output via the `colors` namespace.

## Settings Management
The program attempts to load existing configurations using `loadSettings()`. If a settings file (`settings.cfg`) does not exist or fails to load, it calls `saveSettings()` to generate a default configuration file.

## Execution Flow
Finally, the program calls `mainMenu()`, transferring control to the interactive menu system where the user can start quizzes or modify settings. The program exits when the user leaves the main menu.

## Quiz System
The core logic resides in `programQuiz.cpp`, which handles the interactive learning process:
- **Two-Way Testing**: Depending on the `oneRoundQuiz` setting, the program tests both Native-to-Target and Target-to-Native translations.
- **Help/CheatSheet**: Users can toggle a "CheatSheet" during the quiz by typing `h` or `help`. This displays the correct answer in grey for the current word. It can be disabled with `h off`.
- **String Normalization**: User input is cleaned using `cleanString` and `checkMultipleAnswers` to ensure minor punctuation or casing differences don't result in false negatives.
- **Error Logging**: Incorrect answers are logged via `logMistakeWriteFile` to track difficult words for the user.

## Score System
At the end of a session, `scoreSystem()` calculates the success rate:
- **Statistics**: Displays total questions, correct first-try answers, and the final percentage.
- **Feedback**: Provides localized evaluation messages based on performance thresholds (e.g., 80% or 100%).

#### Main.cpp
```
/**
 * @File main.cpp
 * @brief Entry point of the Application
 * @details A program belépési pontja
 */

#include "settings.h"
#include "Menu/menu.h"
#include "Translate/translations.h"
#include <windows.h>
#include <iostream>


// Global state for language use
// Globális változók a nyelvi használatára
Language programUiLanguage = Language::HUNGARIAN;
Language motherLanguage = Language::HUNGARIAN;
Language targetLanguage = Language::ENGLISH;


int main(int argc, char *argv[]) {
#ifdef _WIN32
    // A Kódlap beállítása az ékezetekre windowson
    // Setting the Code Page for Accents on Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // A szabványos kimenet lekérése
    // Getting the standard output handle
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            // ANSI kódok engedélyezése a szabványos kimeneten a képernyőtőrléshez
            // Enable ANSI codes on standard output for screen clearing
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
    // Create the settings.cfg file to save settings if it does not exist
    // If it exists, just load it
    // Létrehozzuk a settings.cf fájlt és elmentjük a beállításokat ha nem létezik
    // Ha létezik akkor betöltjük
    if (!loadSettings()) saveSettings();

    // Entering the menu
    //Belépünk a menübe
    mainMenu();
    return 0;
}
```
#### menu.h
```
//
// Created by AtiBexx2 on 2026. 04. 04.
//

#ifndef ENGLISH_MENU_H
#define ENGLISH_MENU_H

/** @file menu.h /cpp
 *  @brief
 *  ENG: Entering the main menu
 *  HU: Belépés a főmenűbe
 */
void mainMenu();

// Global state for choice menu
// It is a very important and use for every menu
// Globális változó a menü számára
// Minden menüben ezt használjuk
//extern int choice;
#endif //ENGLISH_MENU_H

```
#### menu.cpp
```
/**
* @file menu.cpp
 * @brief Main menu system implementation / A főmenü rendszer megvalósítása
 *
 * @details
 * EN:
 * Processes the main menu options, including navigation to settings,
 * the text editor, the quiz module, and the program description.
 *
 * HU:
 * Ez a modul felel a főmenü megjelenítéséért és a menüpontok kezeléséért.
 * Lehetővé teszi a belépést a beállításokba, a szerkesztőbe,
 * a kvízbe és a program leírásába.
 */

#include "menu.h"

#include "Common/generalFunctions.h"
#include "Quiz/programQuiz.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "translations.h"
#include "cliFileReading.h"
#include <fstream>
#include "createVocab.h"
#include "osEditor.h"
#include "Settings/settings.h"


void mainMenu() {
    for (;;) {
        screenWipe();
        const MenuStrings &menuStrs = mainMenuTranslations[static_cast<int>(programUiLanguage)];

        std::cout << menuStrs.titleAndSigns <<"\n";
        std::cout << menuStrs.programExplanation << "\n";
        std::cout << menuStrs.startProgram << "\n";
        std::cout << menuStrs.mistakeExercise << "\n";
        std::cout << menuStrs.newFile << "\n";
        std::cout << menuStrs.settings << "\n";
        std::cout << menuStrs.Editor << "\n";
        std::cout << menuStrs.exit << "\n";
        std::cout << menuStrs.signs << "\n";

        int choice = 0;
        const NumberOutput &numStrs = chooseNumberMenuTranslations[static_cast<int>(programUiLanguage)];
        std::cout << numStrs.numberOutput << std::flush;

        // ha a cin nem szám
        // if cin is not a number
        if (!(std::cin >> choice)) {
            screenWipe();
            const InvalidInput &invalidinput = invalidInputTranslations[static_cast<int>(programUiLanguage)];

            // Clear input buffer
            // Megtisztitjuk a bemeneti buffert
            std::cin.clear();
            pufferDelete();

            logError("mainMenu", invalidinput.invalidInput);
            std::cerr << invalidinput.invalidInput <<"\n"; // Betöltjük az hibaüzeneteket || Load Error meassages
            waitToEnter();
            continue;
        }

        switch (choice) {
            case 0:
                 playBeep();
                 exiting();
                 return;
            case 1:
                pufferDelete();
                playBeep();
                explanation();
                break;
            case 2:
                pufferDelete();
                playBeep();
                listAndSelectFile();
                break;
            case 3:
                pufferDelete();
                playBeep();
                mistakeExercise();
                break;
            case 4:
                pufferDelete();
                playBeep();
                createVocab();
                break;
            case 5:
                pufferDelete();
                playBeep();
                settings();
                break;
            case 6:
                    pufferDelete();
                    playBeep();
                    screenWipe();
                    openFileInEditor("");
                break;
            default:
                screenWipe();
                const InvalidInput2 &invalidInput2 = invalidInputTranslations2[static_cast<int>(programUiLanguage)];

                logError("mainMenu", invalidInput2.invalidInput2);
                std::cerr << invalidInput2.invalidInput2 << "\n";

                pufferDelete();
                waitToEnter();
        }
    }
}
```
#### generalFunctions.cpp
```
/**
* @file generalFunctions.cpp
 * @brief Global utility functions / Globális segédfüggvények gyűjteménye
 *
 * @details
 * EN:
 * This module provides essential utility functions used across the application:
 * - Console management (screen wiping, beep sounds, user prompts)
 * - Logging and error reporting
 * - String normalization (trimming, lowercase, punctuation, and accent removal)
 * - File system operations for logging mistakes
 *
 * HU:
 * Ez a modul az alkalmazás egészében használt alapvető segédfüggvényeket biztosítja:
 * - Konzol kezelés (képernyőtörlés, hangjelzés, várakozás)
 * - Naplózás és hibajelentés
 * - Szöveg normalizálás (szóközök, kisbetűk, írásjelek és ékezetek eltávolítása)
 * - Fájlrendszer műveletek a hibás szavak naplózásához
 */

#include "generalFunctions.h"
#include "../Translate/translations.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <map>

#include "dataFileReading.h"
#include "settings.h"
#include "Settings/colors.h"

// a program leírása/magyarázata
// program explanation
void explanation() {
    const ExplanationStrings& strings = explanationTranslations[static_cast<int>(programUiLanguage)];

    screenWipe();
    std::cout << strings.description << "\n";
    std::cout << strings.instruction1 << "\n";
    std::cout << strings.instruction2 << "\n";
    std::cout << strings.instruction3 << "\n";
    std::cout << strings.instruction4 << "\n";
    std::cout << strings.instruction5 << "\n";
    std::cout << strings.instruction6 << "\n";
    std::cout << strings.instruction7 << "\n";
    std::cout << strings.instruction8 << "\n";
    std::cout << strings.goodLuck <<"\n";

    waitToEnter();
}
// várunk egy billentyűre (az enterre)
// wait for a keystroke (enter)
void waitToEnter()
{
    const EnteringBack& enteringBack = continuationToEnterTranslations[static_cast<int>(programUiLanguage)];

    std::cout << enteringBack.pressToEnter << std::endl;
    std::cin.get();
}

// Kilépünk az alkalmazásból
// Exit the application
void exiting() {
    screenWipe();
    const ExitingStrings& strings = exitingTranslations[static_cast<int>(programUiLanguage)];
    std::cout << strings.exiting << std::endl;

    // Buffer törlése, hogy a cin.get() biztosan várjon
    // Clearing buffer to ensure cin.get() waits
    pufferDelete();
    std::cin.get();
}
// képernyő Tőrlése
// screen wipe
void screenWipe() {
    // 1. Szín beállítása (ha kell)
    if (useColors && !currentBG.empty()) {
        std::cout << currentBG;
    } else {
        std::cout << colors::RESET;
    }

    // 2. Képernyő törlése és kurzor haza (egyszerre!)
   std::cout << "\x1B[2J\x1B[H\x1B[3J" << std::flush;
}
/*#ifdef _WIN32
    // Ez a Windows saját belső parancsa, ami
    // kényszeríti a konzolablakot a teljes törlésre.
    std::system("cls");
#else
    // Linux / Android / macOS (Termuxban ez tökéletes)
    std::cout << "\033[2J\033[H" << std::flush;
#endif

    // A törlés UTÁN állítjuk be a színt, hogy ne vesszen el
    if (useColors && !currentBG.empty()) {
        std::cout << currentBG << std::flush;
    } else {
        std::cout << colors::RESET << std::flush;
    }
}*/

// Letöröljük a bent maradt puffert ha szükséges
// Clear the remaining buffer if necessary it
void pufferDelete() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
// rendszerhibák mentése
void logError(const std::string& functionName, const std::string& errorMessage) {

    std::ofstream logFile("error.log ", std::ios::app); //hozzáfűzés mód || append mode
    if (logFile.is_open()) {

        // az időbélyeg lekérése
        // get the timestamp
        std::time_t now = std::time(nullptr);
        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        //Mentés és hibakód/hibaüzenet [IDŐ SZERINT]
        //Save and error code/error message [BY TIME]
        logFile << "[" << timestamp << "] [" << functionName << "] " << errorMessage << std::endl;
        logFile.close();
    }
}
// A hibák mentése fájlba
// Save errors to a file
void logMistakeWriteFile(const WordPair& word)
{
    //ha WINDOWS
#ifdef _WIN32
    std::system("if not exist data\\mistakes mkdir data\\mistakes");
    std::string path = "data\\mistakes\\mistakes.data";

    //HA LINUX VAGY ANDROID VAGY MÁS
    //IF LINUX OR ANDROID OR ELSE SYSTEM
    #else
    std::system("mkdir -p data/mistakes");
    std::string path = "data/mistakes/mistakes.data";
#endif

    //Hozzafüzés módban nyitjuk meg hogy gyüljenek a hibák
    //Open in append mode to collect errors
    std::ofstream mistakeFile(path, std::ios::app);
    if (mistakeFile.is_open())
    {
        //elmentjük ugyanabban a formátumban a fájl
        //save the file in the same format
        mistakeFile << word.targetLangMeaning << " -> " << word.motherLangMeaning;
        if (!word.pronunciation.empty())
        {
            mistakeFile << " (" << word.pronunciation << ")";
        }
        mistakeFile << "\n";
        mistakeFile.close();
        }
    }

// a Hang
// the sound
void playBeep(int frequency , int duration ) {
    if (!useSound) return; // ha ki van kapcsolva || if it"s turned off

#ifdef _WIN32
    // Windowsos beep: frekvencia (Hz) és időtartam (ms)
    // Windows beep: frequency (Hz) and duration (ms)
    Beep(frequency, duration);
#else
    // Linux/Termux/macOS: ANSI Bell character
    std::cout << "\a" << std::flush;
#endif
}

//Az írásjelek eltávolítására ne vegy figyelembe '!' '?' stb
//To remove punctuation, ignore '!' '?' etc.
std::string removePunctuation(const std::string& s)
{
    std::string result;
    for (char c : s) {
        // Ha nem írásjel, akkor megtartjuk
        // If it's not a punctuation mark, we keep it
        if (c != '!' && c != '?' && c != '.' && c != ',' && c != ';') {
            result += c;
        }
    }
    return result;
}
// Az Ékezetes karatkterek figyelmen kívül hagyása
// Ignore Accented Characters
std::string removeAccents(const std::string &s) {
    // UTF-8 ékezetes karakterek és párjaik
    static const std::map<std::string, std::string> accentMap = {
        {"á", "a"}, {"é", "e"}, {"í", "i"}, {"ó", "o"}, {"ö", "o"}, {"ő", "o"},
        {"ú", "u"}, {"ü", "u"}, {"ű", "u"},
        {"Á", "a"}, {"É", "e"}, {"Í", "i"}, {"Ó", "o"}, {"Ö", "o"}, {"Ő", "o"},
        {"Ú", "u"}, {"Ü", "u"}, {"Ű", "u"}
    };

    std::string result;
    for (size_t i = 0; i < s.length(); ) {
        bool found = false;
        // Megnézzük, hogy az aktuális pozíciótól kezdődik-e egy 2-bájtos ékezetes karakter
        // Check if the current position starts with a 2-byte accented character
        /*
        * Miért ilyen bonyolult a típus?
        std::pair: A map minden eleme egy pár (kulcs és érték).
        const std::string (az első): A map kulcsa sosem változhat meg utó lag.
        std::string (a második): Ez a sima betű , amit hozzáadunk.
        &: Referencia, hogy ne másoljuk le az elemeket minden körben.
         */
        // for (auto const& pair : accentMap)
        for (const std::pair<const std::string, std::string>& pair : accentMap) {
            const std::string& accent = pair.first;
            const std::string& plain = pair.second;

            if (s.compare(i, accent.length(), accent) == 0) {
                result += plain;
                i += accent.length();
                found = true;
                break;
            }
        }
        if (!found) {
            result += s[i]; //Hozzáadjuk az a betűt az eredményhez
            i++; // Továbblépünk a következő karakterre
        }
    }
    return result;
}
// Trimmelés és kisbetűsítés
// Trim and lowercase
std::string cleanString(const std::string& s) {
    // Trim és kisbetű
    // Trim and lowercase
    //s = toLowerCase(trim(s));

    // Írásjelek leszedése
    // Remove punctuation
    //s = removePunctuation(s);
    std::string result = toLowerCase(trim(s));
    result = removePunctuation(result);

    // ÉKEZETEK figyelmen kívül hagyása  ha a felhasználó kérte !
    // Ignore ACCENTS if requested by the user!
    if (ignoreAccents) {
        //s = removeAccents(s);
        result = removeAccents(result);
    }

    //return s;
    return result;
}
```
#### generalFunctions.h
```
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


#endif //ENGLISH_GENERALFUNCTIONS_H
```




