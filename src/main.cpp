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

/**
 * @brief Sets up the console environment for proper display and interaction. || Konzol környezet beállítása a megfelelő megjelenítéshez és interakcióhoz.
 *
 * @details
 * EN:
 * This function initializes the Windows console to support UTF-8 character encoding
 * and ANSI escape sequences. This ensures that special characters (like Hungarian accents)
 * are displayed correctly, and screen clearing commands function as expected.
 * This setup is only applied on Windows platforms.
 *
 * HU:
 * Ez a függvény inicializálja a Windows konzolt az UTF-8 karakterkódolás
 * és az ANSI escape szekvenciák támogatására. Ez biztosítja, hogy a speciális karakterek
 * (például a magyar ékezetek) helyesen jelenjenek meg, és a képernyőtörlési parancsok
 * megfelelően működjenek. Ez a beállítás csak Windows platformokon alkalmazódik.
 */

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
/**
 * @brief Main entry point of the application. || Az alkalmazás fő belépési pontja.
 *
 * @details
 * EN:
 * This function initializes the console, loads or creates application settings,
 * and then starts the main menu loop.
 *
 * HU:
 * Ez a függvény inicializálja a konzolt, betölti vagy létrehozza az alkalmazás beállításait,
 * majd elindítja a főmenü ciklusát.
 *
 * @param argc The number of command-line arguments. || A parancssori argumentumok száma.
 * @param argv An array of command-line argument strings. || Parancssori argumentumok sztringjeinek tömbje.
 * @return 0 if the program exits successfully. || 0, ha a program sikeresen kilép.
 */

int main(int argc, char *argv[]) {

    setupConsole();

    // Create the settings.cfg file to save settings if it does not exist
    // If it exists, just load it
    // Létrehozzuk a settings.cf fájlt és elmentjük a beállításokat ha nem létezik
    // Ha létezik akkor betöltjük
    if (!loadSettings()) saveSettings();

    // Fordítások betöltése || Loading translations
    loadTranslationsFromFile(programUiLanguage);

    mainMenu();
    return 0;
}
