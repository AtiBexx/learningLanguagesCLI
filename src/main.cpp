/**
* @page main_doc Main Application
 *
 * EN:
 * This page describes the main entry point of the application.
 *
 * HU:
 * Ez az oldal az alkalmazás belépési pontját írja le.
 */

#include "settings.h"
#include "Menu/menu.h"
#include "Translate/translations.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <string>


#ifdef _WIN32
#include <windows.h>
#include <fcntl.h>
#include <io.h>
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
    // ÚJ: Locale beállítása UTF-8-ra a széles karakterekhez
    // NEW: Set locale to UTF-8 for wide characters
    std::locale::global(std::locale("")); // Vagy "" a rendszer alapértelmezettjéhez
    std::wcout.imbue(std::locale());
    std::wcin.imbue(std::locale());

}

int main(int argc, char *argv[]) {

    setupConsole();

    // Create the settings.cfg file to save settings if it does not exist
    // If it exists, just load it
    // Létrehozzuk a settings.cf fájlt és elmentjük a beállításokat ha nem létezik
    // Ha létezik akkor betöltjük
    if (!loadSettings()) saveSettings();
    //if (preferIniTranslations && !inFile.is_open() )
    if (preferIniTranslations)
    {
        std::string fileFolder = "lang/lang_hu.ini";

        std::ifstream check(fileFolder);
        if (!check.is_open())
        {
            createDefaultLangIni();
        }
    }

    // Fordítások betöltése || Loading translations
    loadTranslationsFromFile(programUiLanguage);

    mainMenu();
    return 0;
}
