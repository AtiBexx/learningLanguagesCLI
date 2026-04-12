#include "settings.h"
#include "Menu/menu.h"
#include "Translate/translations.h"


Language currentLanguage = Language::HUNGARIAN; // A program nyelve
Language motherLanguage = Language::HUNGARIAN; // Alapértelmezett anyanyelv
Language targetLanguage = Language::ENGLISH; // Alapértelmezett tanult nyelv


int main(int argc, char *argv[]) {

    //Létrehozuk a settings.cfg fájl a beállításokhoz
    // ha nem létezik ha létezik akkor csak beolvassuk
    if (!loadSettings()) saveSettings();

    menu();
    return 0;
}


