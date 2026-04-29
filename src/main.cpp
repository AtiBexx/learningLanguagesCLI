/**
 * @file main.cpp
 * @brief Application entry point / Az alkalmazás belépési pontja
 *
 * @details
 * EN:
 * Initializes terminal settings (UTF-8, ANSI support on Windows),
 * loads user settings, and launches the main menu.
 *
 * HU:
 * Beállítja a terminált (UTF-8, ANSI támogatás Windows-on),
 * betölti a felhasználói beállításokat, és elindítja a főmenüt.
 */

#include "settings.h"
#include "Menu/menu.h"
#include "Translate/translations.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif


//Current UI language
//A jelenlegi felhasználói felületnek a nyelve
Language programUiLanguage = Language::HUNGARIAN;
// User's native language || felhasználó anyanyelve
Language motherLanguage = Language::HUNGARIAN;

//Stores the language the user is currently learning.
//A felhasználó által éppen tanult nyelvet tárolja.
Language targetLanguage = Language::ENGLISH;

void setupConsole() {
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
            // ANSI kódok engedélyezése a szabványos kimeneten a képernyőtörléshez
            // Enable ANSI codes on standard output for screen clearing
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
}

int main(int argc, char *argv[]) {

    setupConsole();

    // Create the settings.cfg file to save settings if it does not exist
    // If it exists, just load it
    // Létrehozzuk a settings.cf fájlt és elmentjük a beállításokat ha nem létezik
    // Ha létezik akkor betöltjük
    if (!loadSettings()) saveSettings();

    mainMenu();
    return 0;
}
