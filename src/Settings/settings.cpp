/**
* @file settings.cpp
 * @brief Settings system implementation / Beállításkezelő megvalósítás
 *
 * @details
 * EN:
 * This file contains the implementation of the application settings system.
 * It handles menu navigation, user input, language switching,
 * color configuration, background selection, sound toggling,
 * and persistent storage using a configuration file.
 *
 * HU:
 * Ez a fájl tartalmazza az alkalmazás beállításkezelő rendszerének megvalósítását.
 * Kezeli a menü navigációt, felhasználói bemenetet, nyelvváltást,
 * színbeállításokat, háttér kiválasztást, hang kezelést,
 * valamint a beállítások mentését és betöltését fájlból.
 */

#include "settings.h"
#include <iostream>
#include <fstream>

#include "Settings/colors.h"
#include "Common/generalFunctions.h"
#include "Translate/translations.h"

bool useColors = true;
int currentBG_Code = 1;
// nem kell az üres string mert redunáns = "";
std:: string currentBG;
bool useSound = false;
bool ignoreAccents = false;
bool oneRoundQuiz = false;


// fő beállítási menü
// main settings menu
void settings()
{
    for (;;)
    {
        //nyelvi hivatkozások
        const SettingsMenu& settingsMenu = settingsMenuTranslations[static_cast<int>(programUiLanguage)];
        const NumberOutput& numberoutput = chooseNumberMenuTranslations[static_cast<int>(programUiLanguage)];
        const InvalidInput &invalidIinput = invalidInputTranslations [static_cast<int>(programUiLanguage)];
        const InvalidInput2 &invalidIinput2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];

        screenWipe(); // töröljük a képernyőt
        std::cout << settingsMenu.settingsMenuSign << std::endl;
        std::cout << settingsMenu.chooseSettingsMenu << std::endl;
        std::cout << settingsMenu.languageOptions << std::endl;
        std::cout << settingsMenu.targetLanguageOptions << std::endl;
        std::cout << settingsMenu.colorsOptions << std::endl;
        std::cout << settingsMenu.soundOptions << std::endl;
        std::cout << settingsMenu.accentsOptions << std::endl;
        std::cout << settingsMenu.oneRoundQuizOption << std::endl;
        std::cout << settingsMenu.backMainMenu << std::endl;
        std::cout << settingsMenu.settingsMenuSign2 << std::endl;
        std::cout << numberoutput.numberOutput;

        int choice = 0;
        std::string inputSettings;
        std::getline(std::cin, inputSettings);
        try
        {
            //itt számá alakítjuk a bevitt értéket
            //here convert the entered value to a number
            choice = std::stoi(inputSettings);
        }
        catch (...)
        {
            //Ha nem számot ír be akkor a 99-ra a default ágra ugrunk
            //If you enter a non-number, we jump to the default branch at 99
            choice = 99;
        }
        // A menü ugrásai
        // jumps of menu
        switch (choice)
        {
        case 0:
            return; //visszalépünk a főmenübe
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
            accentsToggle();
            break;
        case 6:
            oneRoundQuizToggle();
        default:
            screenWipe();
            if (choice == 99)
            {
                screenWipe();
                logError("SettingsMenu", invalidIinput2.invalidInput2);
                std::cerr << invalidIinput2.invalidInput2;
            }
            else
            {
                screenWipe();
                std::cerr << invalidIinput.invalidInput;
            }
            waitToEnter();
        }
    }
}

/**
 * @brief UI language selection / Program nyelv kiválasztása
 *
 * @details
 * EN:
 * Lists all available languages and allows the user to select one.
 * Updates the global UI language and saves the settings.
 *
 * HU:
 * Kilistázza az összes elérhető nyelvet és lehetővé teszi a választást.
 * Frissíti a program nyelvét és elmenti a beállításokat.
 */
void choiceLanguage()
{
    for (;;){
        // Nyelvi hivatkozások
        const LanguageMenu& LMenu = languageMenuTranslations[static_cast<int>(programUiLanguage)];
        const InvalidInput &II1 = invalidInputTranslations [static_cast<int>(programUiLanguage)];
        const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];
        //std::string selectedLangName = getLanguageNameByIndex(static_cast<int>(programUiLanguage));

        screenWipe();
        std::cout << LMenu.languageMenu1Sign << std::endl;

        // KILISTÁZZUK AZ ÖSSZES NYELVET DINAMIKUSAN
        for (int i = 0; i <= static_cast<int>(Language::LATIN); i++) {
            std::cout << i + 1 << ". " << getLanguageNameByIndex(i) << std::endl;
        }

        std::cout << "\n" << LMenu.exiting << std::endl;
        std::cout << LMenu.choiceStr;

        std::string input;
        std::getline(std::cin, input);
        try {
            int localChoice = std::stoi(input);
            if (localChoice == 0) break; // Visszalépünk || stepBack

            if (localChoice >= 1 && localChoice <= 24) {
                programUiLanguage = static_cast<Language>(localChoice - 1);

                // ---Frissítjük a hivatkozást az ÚJ nyelvre ---
                // ---Update the link to the NEW language ---
                // Fontos! || important!
                const LanguageMenu& LMenuNew = languageMenuTranslations[static_cast<int>(programUiLanguage)];

                // Itt kérjük le az ÚJ nevet a már módosított programUiLanguage alapján!
                // Here we request the NEW name based on the already modified programUiLanguage!
                std::string newSelectedLangName = getLanguageNameByIndex(static_cast<int>(programUiLanguage));

                // LMenuNew fontos!
                std::cout << LMenuNew.choiceSuccessProgramLanguage << ": " << newSelectedLangName << std::endl;
                saveSettings();
                waitToEnter();
                break;

            } else {
                screenWipe();
                logError("choiceLanguage()", II2.invalidInput2);
                std::cerr << II2.invalidInput2;
                waitToEnter();
            }
        } catch (...) {
            screenWipe();
            logError("choiceLanguage()", II1.invalidInput);
            std::cerr << II1.invalidInput;
            waitToEnter();
        }
    }
}

/**
 * @brief Color settings menu / Szín beállítás menü
 *
 * @details
 * EN:
 * Allows enabling/disabling colors and navigating to background settings.
 *
 * HU:
 * Lehetővé teszi a színek be- és kikapcsolását,
 * valamint a háttérszín beállító menü elérését.
 */
void colorsOn()
{
    for (;;)
    {
        //==== Nyelvi hivatkozások=====
        const ColorsOnset & clrSET = colorsOSetTranslations[static_cast<int>(programUiLanguage)];
        const InvalidInput &II1 = invalidInputTranslations [static_cast<int>(programUiLanguage)];
        const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];
        //===============================
        screenWipe();
        std::cout << clrSET.colorsPrinting1 << std::endl;
        std::cout << clrSET.colorsPrinting2 << (useColors ? clrSET.useCLR_ON : clrSET.useCLR_OFF) << std::endl;
        std::cout << clrSET.colorsMenu1 << clrSET.colorsMenu2 << clrSET.colorsMenu3;
        std::cout <<"\n"<< clrSET.choice << std::flush;


        std::string inputC;
        std::getline(std::cin, inputC);
        try
        {
            //itt számá alakítjuk a bevitt értéket
            //here we convert the entered value to a number
            int choice = 0;
            choice = std::stoi(inputC);
            if (choice == 1)
            {
                //egyszer be és egyszer ki || once in and once out
                //useColors = (useColors && true) || (!useColors && false);
                // vagy így useColors = !useColors;
                useColors = !useColors;
                if (useColors == true)
                {
                    std::cout << clrSET.colorsOnOn  <<std::endl;
                } else
                {
                    currentBG = "";       // Kiürítjük a háttérszín kódját
                    currentBG_Code = 1;   // Visszaállítjuk az alapértelmezett (fekete) kódra
                    std::cout << colors::RESET << std::flush;// visszaállítjuk az alapértelmezett színre
                    std::cout << clrSET.colorsOffOff << std::endl;
                }
                saveSettings(); //elmentjük a beállításokat
                waitToEnter();
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
                logError("colorsOn()", II2.invalidInput2);
                std::cerr << II2.invalidInput2;
                waitToEnter();
            }
        }
        catch (...)
        {
            // ha nem számot adtál meg
            screenWipe();
            logError("colorsOn()", II1.invalidInput);
            std::cerr << II1.invalidInput;
            waitToEnter();
        }
    }
}


// Beállítások mentési logika
// Elmenti a jelenlegi beállításokat egy fájlba
// Felülírja a meglévő fájlt
// Settings save logic
// Saves the current settings to a file
// Overwrites the existing file
void saveSettings()
{
    // nyelvi fájl
    const SaveSettings& saveSettings = saveSettingsTranslations[static_cast<int>(programUiLanguage)];
    // Biztonsági létrehozás
    // Security creation
#ifdef _WIN32
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
        // save the language and color state as a number
        outFile << static_cast<int>(programUiLanguage) << "\n";
        outFile << static_cast<int>(motherLanguage) << "\n";
        outFile << static_cast<int>(targetLanguage) << "\n";
        outFile << useColors << "\n";
        outFile << currentBG_Code << "\n";
        outFile << useSound << "\n";
        outFile << ignoreAccents << "\n";
        outFile << oneRoundQuiz << "\n";
        outFile.close();
    }
    else
    {
        logError("saveSettings()", saveSettings.saveSettingsError);
        std::cerr << saveSettings.saveSettingsError << std::endl;
        waitToEnter();
    }
}

// Betölti a beállításokat a fájlból, ha az létezik
// Loads settings from file if it exists
bool loadSettings() {
    std::ifstream inFile("settings.cfg");
    if (inFile.is_open()) {
        int lang , bgCode, tLang, mLang;
        bool IACode, color, oneRoundCode;

        currentBG =""; //colors::RESET; // Vagy ""
        if (inFile >> lang >> mLang >> tLang >> color >> bgCode >> useSound >> IACode >> oneRoundCode) {
            programUiLanguage = static_cast<Language>(lang);
            motherLanguage = static_cast<Language>(mLang);
            targetLanguage = static_cast<Language>(tLang);
            useColors = color;
            currentBG_Code = bgCode;
            ignoreAccents = IACode;
            oneRoundQuiz = oneRoundCode;

            //visszaállítjuk a számot színné
            //reset the number to color
            if (currentBG_Code == 1) currentBG = colors::RESET;
            else if (currentBG_Code == 2) currentBG = colors::BG_GREEN;
            else if (currentBG_Code == 3) currentBG = colors::BG_CYAN;
            else if (currentBG_Code == 4) currentBG = colors::BG_RED;
            else if (currentBG_Code == 5) currentBG = colors::BG_MAGENTA;
            else if (currentBG_Code == 6) currentBG = colors::BG_BLUE;
            else if (currentBG_Code == 7) currentBG = colors::BG_WHITE;
            else if (currentBG_Code == 8) currentBG = colors::BG_GREY;

        }
        inFile.close();
        return true;
    }
    return false;
}

/**
 * @brief Background color selection / Háttérszín kiválasztása
 *
 * @details
 * EN:
 * Provides options to select different background colors.
 * Updates internal state and saves configuration.
 *
 * HU:
 * Különböző háttérszínek kiválasztását teszi lehetővé.
 * Frissíti az állapotot és elmenti a beállításokat.
 */
void backgroundSets()
{
    // Nyelvi hivatkozások
    const NumberOutput& numberoutput = chooseNumberMenuTranslations[static_cast<int>(programUiLanguage)];
    const BackgroundSets &backgroundsets = backgroundSetsTranslations[static_cast<int>(programUiLanguage)];
    const InvalidInput &II1 = invalidInputTranslations [static_cast<int>(programUiLanguage)];
    const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];
    const ColorsOnset & clrSET = colorsOSetTranslations[static_cast<int>(programUiLanguage)];

    if (!useColors)
    {
        screenWipe();
        std::cerr << clrSET.errorEntryDenied << std::endl;
        waitToEnter();
        return; // AZONNAL KILÉPÜNK
    }
    for (;;)
    {
        screenWipe(); // töröljük a képernyőt

        std::cout << backgroundsets.sign << std::endl;
        std::cout << backgroundsets.DefaultBlack;
        std::cout << backgroundsets.green;
        std::cout << backgroundsets.cian;
        std::cout << backgroundsets.red;
        std::cout << backgroundsets.purple;
        std::cout << backgroundsets.blue;
        std::cout << backgroundsets.white;
        std::cout << backgroundsets.gray;
        std::cout <<backgroundsets.stepBack;
        std::cout << numberoutput.numberOutput << std::flush;



        std::string inputBS;
        std::getline(std::cin, inputBS);

        try
        {
            int choice = 0;
            //itt számá alakítjuk a bevitt értéket
            choice = std::stoi(inputBS);

            if (choice == 1)
            {
                currentBG = colors::RESET;
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
            std::cerr << II2.invalidInput2;
                waitToEnter();
                continue; //ujraindul a ciklus
            }

        } catch (...) {

            // ha nem számot adtál meg
            screenWipe();
            std::cerr << II1.invalidInput;
            waitToEnter();
        }
        screenWipe();
        saveSettings(); //elmentjük a beállításokat || save the settings

        // KIVÁLASZTOTT SZÍN NEVÉNEK KIÍRÁSA
        // PRINT THE NAME OF THE SELECTED COLOR
        std::cout << backgroundsets.backgroundColorsChange << std::endl;

        if (currentBG_Code == 1) std::cout << backgroundsets.DefaultBlack;
        else if (currentBG_Code == 2) std::cout << backgroundsets.backGroundColor << backgroundsets.green;
        else if (currentBG_Code == 3) std::cout << backgroundsets.backGroundColor << backgroundsets.cian;
        else if (currentBG_Code == 4) std::cout << backgroundsets.backGroundColor << backgroundsets.red;
        else if (currentBG_Code == 5) std::cout << backgroundsets.backGroundColor << backgroundsets.purple;
        else if (currentBG_Code == 6) std::cout << backgroundsets.backGroundColor << backgroundsets.blue;
        else if (currentBG_Code == 7) std::cout << backgroundsets.backGroundColor << backgroundsets.white;
        else if (currentBG_Code == 8) std::cout << backgroundsets.backGroundColor << backgroundsets.gray;

        waitToEnter();
    }
}

/**
 * @brief Learning language configuration / Tanulandó nyelv beállítása
 *
 * @details
 * EN:
 * Allows the user to set:
 * - Mother language
 * - Target learning language
 *
 * HU:
 * Lehetővé teszi az alábbiak beállítását:
 * - Anyanyelv
 * - Tanult nyelv
 */
void learningLanguage()
{
    for (;;) {
        // Nyelvi hivatkozások
        const LearningLanguageSet& LLS = learningLanguageSetTranslations[static_cast<int>(programUiLanguage)];
        const InvalidInput &II1 = invalidInputTranslations [static_cast<int>(programUiLanguage)];
        const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];

        screenWipe(); //letöröljük a képernyőt
        std::cout << LLS.Menu << std::endl;
        std::cout << LLS.CurrentlyMotherLanguage <<" "<< getLanguageNameByIndex(static_cast<int>(motherLanguage)) << std::endl;
        std::cout << LLS.CurrentlyLearningLanguage <<" "<< getLanguageNameByIndex(static_cast<int>(targetLanguage)) << std::endl;
        std::cout << "\n"<< LLS.menuSigns <<"\n" << std::endl;
        std::cout << LLS.option1 ;
        std::cout << LLS.option2 ;
        std::cout << LLS.option3 ;
        std::cout << "\n4. "<<LLS.choice << std::flush;


        std::string inputLLS;
        std::getline(std::cin, inputLLS);

        try
        {
            int choice = 0;
            //itt számá alakítjuk a bevitt értéket
            choice = std::stoi(inputLLS);

            if (choice == 1)
            {
                for (;;)
                {
                    screenWipe();
                    std::cout << LLS.choice1 <<std::endl;
                    //meghívjuk az enum listát a kiválasztáshoz
                    for (int i = 0; i <= static_cast<int>(Language::LATIN); i++)
                    {
                        std::cout << i + 1 << ". " << getLanguageNameByIndex(i) << std::endl;
                    }
                    std::cout << LLS.back <<std::endl;
                    std::cout << LLS.allChoice;

                    std::string  mLangInput;
                    std::getline(std::cin, mLangInput);

                    try {
                        int langChoice = std::stoi(mLangInput);

                        if (langChoice == 0) break; //visszalépünk
                        if (langChoice >= 1 && langChoice <= 24) {
                            auto tempMotherLanguage = static_cast<Language>(langChoice - 1);
                            if (tempMotherLanguage == targetLanguage) {
                                screenWipe();
                                // Itt használd a fordított hibaüzenetedet!
                                std::cerr << LLS.error << std::endl;
                                waitToEnter();
                                continue;
                            }
                            motherLanguage = tempMotherLanguage;
                            screenWipe();

                            // DINAMIKUS VISSZAJELZÉS:
                            std::string selectedName = getLanguageNameByIndex(static_cast<int>(motherLanguage));
                            std::cout << LLS.motherSuccess << ": " << selectedName << std::endl;
                            saveSettings();
                            waitToEnter();
                        } else
                        {
                            // Ha számot ír de tartományun kivül esik
                            // If you enter a number but it is out of range
                            logError("learningLanguage()(choice1)",II2.invalidInput2);
                            std::cerr << II2.invalidInput2;
                            waitToEnter();
                        }
                    } catch (...) {
                        // HA NEM SZÁMOT ÍRT (pl. "abc")
                        // IF NOT A NUMBER (e.g. "abc")
                        logError("learningLanguage()(choice1)",II1.invalidInput);
                        std::cerr << II1.invalidInput;
                        waitToEnter();
                    }
                    break; //kilépünk ha minden jó és nincs hiba
                }
            } else if (choice == 2)
            {
                for (;;)
                {
                    screenWipe();
                    std::cout << LLS.choice2 << std::endl;
                    for (int i = 0; i <= static_cast<int>(Language::LATIN); i++) {
                        std::cout << i + 1 << ". " << getLanguageNameByIndex(i) << std::endl;
                    }
                    std::cout << LLS.back <<std::endl;
                    std::cout << LLS.allChoice;

                    std::string tLangInput;
                    std::getline(std::cin, tLangInput);

                    try {
                        int langChoice = std::stoi(tLangInput);
                        if (langChoice == 0) break; //kilépünk
                        if (langChoice >= 1 && langChoice <= 24) {
                            auto tempTargetLanguage = static_cast<Language>(langChoice - 1);

                            if (tempTargetLanguage == motherLanguage) {
                                screenWipe();
                                // Itt használd a fordított hibaüzenetedet!
                                std::cerr << LLS.error << std::endl;
                                waitToEnter();
                                continue; // Vissza a learningLanguage menübe
                            }

                            targetLanguage = tempTargetLanguage;
                            screenWipe();

                            std::string selectedName = getLanguageNameByIndex(static_cast<int>(targetLanguage));
                            std::cout << LLS.targetSuccess << ": " << selectedName << std::endl;
                            saveSettings();
                            waitToEnter();
                        } else {
                            logError("learningLanguage()(choice2)",II2.invalidInput2);
                            std::cerr << II2.invalidInput2;
                            waitToEnter();
                        }
                    } catch (...) {
                        logError("learningLanguage()(choice1)",II1.invalidInput);
                        std::cerr << II1.invalidInput;
                        waitToEnter();
                    }
                    break;
                }
            }
            //visszalépünk a főmenübe
            else if (choice ==3) return; //kilépünk a ciklusból

        } catch (...)
        {
            logError("learningLanguage()(mainMenu)",II2.invalidInput2);
            std::cerr << II2.invalidInput2;
            waitToEnter();
        }
    }
}

/**
 * @brief Sound toggle / Hang be- és kikapcsolása
 *
 * @details
 * EN:
 * Toggles sound state (ON/OFF) and saves configuration.
 *
 * HU:
 * A hang állapotát váltja (BE/KI) és elmenti a beállítást.
 */
void soundOn() {
    // Nyelvi hivatkozások
    // Language references
    const SoundOnOff &SOO = soundOnOffTranslations [static_cast<int>(programUiLanguage)];
    const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];

    for (;;) {
        screenWipe();
        std::cout << SOO.soundSet << std::endl;
        std::cout << SOO.currentlyState << (useSound ? SOO.useSoundOn : SOO.useSoundOff) << std::endl;
        std::cout << SOO.option1;

        std::string input;
        std::getline(std::cin, input);
        try {
            int localChoice = std::stoi(input);
            if (localChoice == 1) {
                useSound = !useSound; // Átkapcsolás
                saveSettings();
                // feedback for User
                // visszajelzés a felhasználónak
                std::cout << (useSound ? SOO.useSoundOn2 : SOO.useSoundOff2) << std::endl;
                waitToEnter();
            } else if (localChoice == 0) break;
        } catch (...) {
            logError("soundOn()" , II2.invalidInput2);
            std::cerr << II2.invalidInput2 << "\n";
            waitToEnter();
        }
    }
}

// ékezetek be és ki kapcsolása
// turning accents on and off
void accentsToggle() {
    for (;;) {
        // Nyelvi hivatkozások
        // Language references
        const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];
        const SpellingOutAccents &SOA = spellingOutAccentsTranslations [static_cast<int>(programUiLanguage)];

        screenWipe();
        std::cout << SOA.accentsMenu << std::endl;
        std::cout << SOA.accentsState << (ignoreAccents ? SOA.accentsState1Off : SOA.accentsState2On) << std::endl;
        std::cout << SOA.accentsMenu1;

        std::string input;
        std::getline(std::cin, input);
        try {
            int localChoice = std::stoi(input);
            if (localChoice == 1) {
                ignoreAccents = !ignoreAccents;
                saveSettings();

                // VISSZAJELZÉS A FELHASZNÁLÓNAK
                // FEEDBACK FOR USER
                std::cout << (ignoreAccents ? SOA.accentsState1Off : SOA.accentsState2On) << std::endl;
                waitToEnter();
            } else if (localChoice == 0) break;
        } catch (...) {
            logError("accentsToggle()" , II2.invalidInput2);
            std::cerr << II2.invalidInput2 << "\n";
            waitToEnter();
        }
    }
}

// Egy körös kvíz be és ki kapcsolása
void oneRoundQuizToggle() {
    for (;;) {
        // Nyelvi hivatkozások
        const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];
        // Itt kell egy új struct a translations.h-ba, pl. OneRoundQuizToggle
        // const OneRoundQuizToggle &ORQT = oneRoundQuizToggleTranslations [static_cast<int>(programUiLanguage)];
        // Egyelőre használjunk placeholder szöveget, amíg nem hozod létre a fordítást

        screenWipe();
        std::cout << "--- Egy koros kviz beallitas ---" << std::endl;
        std::cout << "Jelenlegi allapot: " << (oneRoundQuiz ? "BEKAPCSOLVA" : "KIKAPCSOLVA") << std::endl;
        std::cout << "1. Atkapcsolas\n0. Vissza\nValasztas: ";

        std::string input;
        std::getline(std::cin, input);
        try {
            int localChoice = std::stoi(input);
            if (localChoice == 1) {
                oneRoundQuiz = !oneRoundQuiz;
                saveSettings();
                std::cout << (oneRoundQuiz ? "Egy koros kviz BEKAPCSOLVA!" : "Egy koros kviz KIKAPCSOLVA!") << std::endl;
                waitToEnter();
            } else if (localChoice == 0) break;
        } catch (...) {
            logError("oneRoundQuizToggle()" , II2.invalidInput2);
            std::cerr << II2.invalidInput2 << "\n";
            waitToEnter();
        }
    }
}





