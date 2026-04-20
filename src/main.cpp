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
    // Windows: UTF-8 kódlap beállítása a konzolhoz (hogy látszódjanak az ékezetek)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    // gyorsítás || speed up
    //std::ios_base::sync_with_stdio(false);
   // std::cin.tie(nullptr);


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


