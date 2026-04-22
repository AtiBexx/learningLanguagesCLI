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
    // 1. Kódlap beállítása
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 2. A szabványos kimenet lekérése
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            // 3. ANSI kódok engedélyezése a SZABVÁNYOS kimeneten
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


