//
// Created by AtiBexx2 on 2026. 04. 06.
//

#include "settings.h"
#include <iostream>
#include <fstream>

#include "colors.h"
#include "generalFunctions.h"
#include "menu.h"

bool useColors = true;
int currentBG_Code = 1;
// nem kell az üres string mert redunáns = "";
std:: string currentBG;
bool useSound = false;

void settings()
{
    //nyelvi hivatkozások
    const SettingsMenu& settingsMenu = settingsMenuTranslations[static_cast<int>(currentLanguage)];
    const BackStrings& backSTR = backbackTranslations[static_cast<int>(currentLanguage)];
    const NumberOutput& numberoutput = numberOutputTranslations[static_cast<int>(currentLanguage)];
    for (;;)
    {
        screenWipe(); // töröljük a képernyőt
        std::cout << settingsMenu.settingsMenu1 << std::endl;
        std::cout << settingsMenu.settingsMenu2 << std::endl;
        std::cout << settingsMenu.settingsMenu3 << std::endl;
        std::cout << settingsMenu.settingsMenu4 << std::endl;
        std::cout << settingsMenu.settingsMenu5 << std::endl;
        std::cout << settingsMenu.settingsMenu6 << std::endl;
        std::cout << settingsMenu.settingsMenu7 << std::endl;
        std::cout << settingsMenu.settingsMenu8 << std::endl;
        std::cout << numberoutput.numberOutput;

        choice = 0;
        std::string inputSettings;
        std::getline(std::cin, inputSettings);
        try
        {
            //itt számá alakítjuk a bevitt értéket
            choice = std::stoi(inputSettings);
        }
        catch (...)
        {
            //Ha nem számot ír be akkor a 0-ra a default ágra ugrunk
            choice = 0;
        }

        // A menü ugrásai
        switch (choice)
        {
        case 1:
            choiceLanguage();
            break;
        case 2:
            learningLanguage();
            break;
        case 3:
            colorsOn();
            break;
        case 4:
            soundOn();
            break;
        case 5:
            return; //visszalépünk a főmenübe
        default:
            screenWipe();
            if (choice == 0)
            {
                screenWipe();
                logError("SettingsMenu", settingsMenu.settingsMenuError1);
                std::cerr << settingsMenu.settingsMenuError2 << "\n";
            }
            else
            {
                screenWipe();
                std::cerr << settingsMenu.settingsMenuError1 << "\n";
            }
            std::cout << backSTR.backStrings << std::endl;
            std::cin.get(); // bekérjük az entert
        }
    }
}

void choiceLanguage()
{
    // Nyelvi hivatkozások
    const LanguageMenu& LMenu = languageMenuTranslations[static_cast<int>(currentLanguage)];
    const LanguageMenu2& LMenu2 = languageMenu2Translations[static_cast<int>(currentLanguage)];
    const EnteringBack& enteringBack = enteringBackTranslations[static_cast<int>(currentLanguage)];

    for (;;)
    {
        screenWipe();
        std::cout << LMenu.languageMenu1Sign << std::endl;

        // KILISTÁZZUK AZ ÖSSZES NYELVET DINAMIKUSAN
        for (int i = 0; i <= static_cast<int>(Language::LATIN); i++) {
            std::cout << i + 1 << ". " << getLanguageNameByIndex(i) << std::endl;
        }

        std::cout << "\n0. " << LMenu.exiting << std::endl;
        std::cout << LMenu.choiceStr;

        std::string input;
        std::getline(std::cin, input);
        try {
            int localChoice = std::stoi(input);
            if (localChoice == 0) break; // Vissza

            if (localChoice >= 1 && localChoice <= 24) {
                currentLanguage = static_cast<Language>(localChoice - 1);
                std::cout << LMenu2.choiceSucess1 << std::endl;
                saveSettings();
                std::cout << enteringBack.enteringBack << std::endl;
                std::cin.get();
                break;
            } else {
                std::cerr << LMenu2.Error1 << "\n";
                std::cout << enteringBack.enteringBack << std::endl;
                std::cin.get();
            }
        } catch (...) {
            std::cerr << LMenu2.Error2 << "\n";
            std::cout << enteringBack.enteringBack << std::endl;
            std::cin.get();
        }
    }
}

void colorsOn()
{
    // Nyelvi hivatkozások
    const LanguageMenu2& LMenu2 = languageMenu2Translations[static_cast<int>(currentLanguage)];
    const EnteringBack& enteringBack = enteringBackTranslations[static_cast<int>(currentLanguage)];
    const ColorsOnset & clrSET = colorsOSetTranslations[static_cast<int>(currentLanguage)];

    for (;;)
    {
        std::cout << clrSET.colorsPrinting1 << std::endl;
        std::cout << clrSET.colorsPrinting2 << (useColors ? clrSET.useCLR_ON : clrSET.useCLR_OFF) << std::endl;
        std::cout << clrSET.colorsMenu1 << clrSET.colorsMenu2 << clrSET.colorsMenu3;

        choice = 0;
        std::string inputC;
        std::getline(std::cin, inputC);
        try
        {
            //itt számá alakítjuk a bevitt értéket
            choice = std::stoi(inputC);
            if (choice == 1)
            {
                //egyszer be és egyszer ki
                //useColors = (useColors && true) || (!useColors && false);
                // vagy így useColors = !useColors;
                useColors = !useColors;
                if (useColors == true)
                {
                    std::cout << clrSET.colorsONON  <<std::endl;
                } else
                {
                    std::cout << clrSET.colorsOFFOFF << std::endl;
                }
                std::cout << enteringBack.enteringBack << std::endl;
                std::cin.get();

                saveSettings(); //elmentjük a beállításokat
                break; //kilépünk a ciklusból
            }
            else if (choice == 2)
            {
                backgroundSets();//Meghívjuk a háttérszín beállíto menüt
            }
            else if (choice == 3)
            {
                break; //kilépünk a ciklusból
            }
            else
            {
                // Ha számot adotál meg, de az nem 1, 2 vagy 3 (pl. 5)
                screenWipe();
                std::cerr << LMenu2.Error1 << "\n";
                std::cout << enteringBack.enteringBack << std::endl;
                std::cin.get();
            }
        }
        catch (...)
        {
            // ha nem számot adtál meg
            screenWipe();
            std::cerr << LMenu2.Error2 << "\n";
            std::cout << enteringBack.enteringBack << std::endl;
            std::cin.get();
        }
    }
}


// Beállítások mentési logika
// Elmenti a jelenlegi beállításokat egy fájlba
void saveSettings()
{
    // nyelvi fájl
    const SaveSettings& saveSettings = saveSettingsTranslations[static_cast<int>(currentLanguage)];

    // Biztonsági létrehozás
#ifndef _WIN32
    // Windows: Üres fájl létrehozása, ha nem létezik
    std::system("if not exist settings.cfg type nul > settings.cfg");
#else
    // Linux / Android / Termux: A jól bevált touch parancs
    std::system ("touch settings.cfg");
#endif
std::ofstream outFile("settings.cfg"); //include <fstream>
    if (outFile.is_open())
    {
        // elmentjük a nyelvet és a színek állapotát számként
        outFile << static_cast<int>(currentLanguage) << "\n";
        outFile << static_cast<int>(motherLanguage) << "\n";
        outFile << static_cast<int>(targetLanguage) << "\n";
        outFile << useColors << "\n";
        outFile << currentBG_Code << "\n";
        outFile << useSound << "\n";
        outFile.close();
    }
    else
    {
        std::cerr << saveSettings.saveSettingsError << std::endl;
    }
}

// Betölti a beállításokat a fájlból, ha az létezik
bool loadSettings() {
    std::ifstream inFile("settings.cfg");
    if (inFile.is_open()) {
        int lang , bgCode, tLang, mLang;;

        bool color;
        currentBG = "";
        if (inFile >> lang >> mLang >> tLang >> color >> bgCode >> useSound) {
            currentLanguage = static_cast<Language>(lang);
            motherLanguage = static_cast<Language>(mLang);
            targetLanguage = static_cast<Language>(tLang);
            useColors = color;
            currentBG_Code = bgCode;

            //visszaállítjuk a számot színné
            if (currentBG_Code == 1) currentBG = "";
            else if (currentBG_Code == 2) currentBG = colors::BG_GREEN;
            else if (currentBG_Code == 3) currentBG = colors::BG_CYAN;
            else if (currentBG_Code == 4) currentBG = colors::BG_RED;
            else if (currentBG_Code == 5) currentBG = colors::BG_BLUE;
            else if (currentBG_Code == 6) currentBG = colors::BG_MAGENTA;
            else if (currentBG_Code == 7) currentBG = colors::BG_WHITE;
            else if (currentBG_Code == 8) currentBG = colors::BG_GREY;

        }
        inFile.close();
        return true;
    }
    return false;
}

void backgroundSets()
{
    // Nyelvi hivatkozások
    const EnteringBack& enteringBack = enteringBackTranslations[static_cast<int>(currentLanguage)];
    const NumberOutput& numberoutput = numberOutputTranslations[static_cast<int>(currentLanguage)];
    const LanguageMenu2& LMenu2 = languageMenu2Translations[static_cast<int>(currentLanguage)];

    for (;;)
    {
        screenWipe(); // töröljük a képernyőt
        std::cout << "--- A Háttérszin beallitása ---" << std::endl;
        std::cout << "1.Alapértelmezet(fekete)\n" ;
        std::cout << "2.Zöld\n" ;
        std::cout << "3.Cián\n" ;
        std::cout << "4.Piros\n" ;
        std::cout << "5.Lila\n" ;
        std::cout << "6.KÉK\n" ;
        std::cout << "7.Fehér\n" ;
        std::cout << "8.szürke\n" ;
        std::cout <<"Visszalépés....\n";
        std::cout << numberoutput.numberOutput << std::endl;


        choice = 0;
        std::string inputBS;
        std::getline(std::cin, inputBS);

        try
        {
            //itt számá alakítjuk a bevitt értéket
            choice = std::stoi(inputBS);

            if (choice == 1)
            {
                currentBG = "";
                currentBG_Code = 1;
            }
            else if (choice == 2)
            {
                currentBG = colors::BG_GREEN;
                currentBG_Code = 2;
            }
            else if (choice == 3)
            {
                currentBG = colors::BG_CYAN;
                currentBG_Code = 3;
            }
            else if (choice == 4)
            {
                currentBG = colors::BG_RED;
                currentBG_Code = 4;
            }
            else if (choice == 5)
            {
                currentBG = colors::BG_MAGENTA;
                currentBG_Code = 5;

            }
            else if (choice == 6)
            {
                currentBG = colors::BG_BLUE;
                currentBG_Code = 6;
            }
            else if (choice == 7)
            {
                currentBG = colors::BG_WHITE;
                currentBG_Code = 7;

            }
            else if (choice == 8)
            {
                currentBG = colors::BG_GREY;
                currentBG_Code = 8;
            }
            else if (choice == 9) break; //kilépünk
            else
            {
                screenWipe();
            std::cerr << "HIBA SZÁMOT ADJ MEG 1-9-ig!\n";
                std::cout << enteringBack.enteringBack << std::endl;
                std::cin.get();
                continue; //ujraindul a ciklus
            }

        } catch (...) {

            // ha nem számot adtál meg
            screenWipe();
            std::cerr << LMenu2.Error2 << "\n";
            std::cout << enteringBack.enteringBack << std::endl;
            std::cin.get();
        }
        screenWipe();
        saveSettings(); //elmentjük a beállításokat
        std::cout << "A HáttérSzín sikeresen megvaltoztatva!" << std::endl;
        std::cout << "A háttér színe: " << currentBG << std::endl;
        std::cout << enteringBack.enteringBack << std::endl;
        std::cin.get();

    }
}

void learningLanguage()
{
    // Nyelvi hivatkozások
const LearningLanguageSet& LLS = learningLanguageSetTranslations[static_cast<int>(currentLanguage)];
    const EnteringBack& enteringBack = enteringBackTranslations[static_cast<int>(currentLanguage)];


    screenWipe(); //letöröljük a képernyőt
    std::cout << LLS.Menu << std::endl;
    std::cout << LLS.CurrentlyMotherLanguage << std::endl;
    std::cout << LLS.CurrentlyLearningLanguage << std::endl;
    std::cout << LLS.option1 ;
    std::cout << LLS.option2 ;
    std::cout << LLS.option3 ;

    choice = 0;
    std::string inputLLS;
    std::getline(std::cin, inputLLS);

    try
    {
        //itt számá alakítjuk a bevitt értéket
        choice = std::stoi(inputLLS);

        //Beállítjuk az anyanyelvet
        if (choice == 1)
        {
            std::cout << "Kérlek válaszd ki az anyanyelved->" <<std::endl;
            //meghívjuk az enum listát a kiválasztáshoz
            for (int i = 0; i <= static_cast<int>(Language::LATIN); i++)
            {
                std::cout << i << ". " << getLanguageNameByIndex(i) << std::endl;
            }
            std::cout << "\nValasztas (1-24): ";
            choice = 0;
            std::string  mLangInput;
            std::getline(std::cin, mLangInput);

            try {

                int langChoice = std::stoi(mLangInput);
                if (langChoice >= 1 && langChoice <= 24) {
                    motherLanguage = static_cast<Language>(langChoice - 1);
                    screenWipe();

                    std::cout << "Sikeresen beallitva!" << std::endl;
                    saveSettings();
                    std::cout << enteringBack.enteringBack << std::endl;
                    std::cin.get();
                } else
                {
                    std::cerr << "HIBA : csak számot adj meg!(1-24.-ig)\n";
                    std::cout << enteringBack.enteringBack << std::endl;
                    std::cin.get();
                }
            } catch (...) {
                // HA NEM SZÁMOT ÍRT (pl. "abc")
                std::cerr << "Hiba: Ervenytelen bemenet! Csak szamot adj meg!\n";
                std::cout << enteringBack.enteringBack << std::endl;
                std::cin.get();
            }
        } else if (choice == 2)
        {
            std::cout << "Kerlek valaszd ki a tanult nyelvet:" << std::endl;
            for (int i = 0; i <= static_cast<int>(Language::LATIN); i++) {
                std::cout << i + 1 << ". " << getLanguageNameByIndex(i) << std::endl;
            }
            std::cout << "\nValasztas (1-24): ";
            std::string tLangInput;
            std::getline(std::cin, tLangInput);

            try {
                int langChoice = std::stoi(tLangInput);
                if (langChoice >= 1 && langChoice <= 24) {
                    targetLanguage = static_cast<Language>(langChoice - 1);
                    screenWipe();
                    std::cout << "Tanult nyelv sikeresen beallitva!" << std::endl;
                    saveSettings();
                    std::cout << enteringBack.enteringBack << std::endl;
                    std::cin.get();
                } else {
                    std::cerr << "HIBA: csak szamot adj meg 1-24-ig!\n";
                    std::cin.get();
                }
            } catch (...) {
                std::cerr << "Hiba: Ervenytelen bemenet!\n";
                std::cin.get();
            }

        }
        //visszalépünk a főmenübe
        else if (choice ==3) return; //kilépünk a ciklusból


    } catch (...)
    {
        std::cerr << "Hiba: Ervenytelen bemenet a fomenuben!\n";
        std::cerr << "Csak számot adj meg 1-3-ig\n";
        std::cout << enteringBack.enteringBack << std::endl;
        std::cin.get();
        }
    }

void soundOn() {
    const EnteringBack& enteringBack = enteringBackTranslations[static_cast<int>(currentLanguage)];
    const LanguageMenu2& LMenu2 = languageMenu2Translations[static_cast<int>(currentLanguage)];

    for (;;) {
        screenWipe();
        std::cout << "--- Hang beallitasa ---" << std::endl;
        std::cout << "Jelenlegi allapot: " << (useSound ? "BE" : "KI") << std::endl;
        std::cout << "1. Be/Ki kapcsolás\n0. Vissza\nValasztas: ";

        std::string input;
        std::getline(std::cin, input);
        try {
            int localChoice = std::stoi(input);
            if (localChoice == 1) {
                useSound = !useSound; // Átkapcsolás
                std::cout << (useSound ? "Hang bekapcsolva!" : "Hang kikapcsolva!") << std::endl;
                saveSettings();
                std::cout << enteringBack.enteringBack << std::endl;
                std::cin.get();
                break;
            } else if (localChoice == 0) break;
        } catch (...) {
            std::cerr << LMenu2.Error2 << "\n";
            std::cin.get();
        }
    }
}




