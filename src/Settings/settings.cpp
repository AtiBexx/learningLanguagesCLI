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
#include "newInput/platformInput.h"

bool useColors = true;
int currentBG_Code = 1;
std:: string currentBG;
bool useSound = false;
bool ignoreAccents = false;
bool oneRoundQuiz = false;
bool showHelp = false;
bool helperUsed = false;
bool preferIniTranslations = true;
size_t resumeIndex = 0;



// fő beállítási menü
// main settings menu
void settings()
{
    for (;;)
    {
        //nyelvi hivatkozások
        /*const SettingsMenu& settingsMenu = settingsMenuTranslations[static_cast<int>(programUiLanguage)];
        const NumberOutput& numberoutput = chooseNumberMenuTranslations[static_cast<int>(programUiLanguage)];
        const InvalidInput &invalidIinput = invalidInputTranslations [static_cast<int>(programUiLanguage)];
        const InvalidInput2 &invalidIinput2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];*/

        screenWipe(); // töröljük a képernyőt

        std::cout << getTranslation("SettingsMenu.settingsMenuSign") << "\n";
        std::cout << getTranslation("SettingsMenu.chooseSettingsMenu") << "\n";
        std::cout << getTranslation("SettingsMenu.languageOptions") << "\n";
        std::cout << getTranslation("SettingsMenu.targetLanguageOptions") << "\n";
        std::cout << getTranslation("SettingsMenu.colorsOptions") << "\n";
        std::cout << getTranslation("SettingsMenu.soundOptions") << "\n";
        std::cout << getTranslation("SettingsMenu.accentsOptions") << "\n";
        std::cout << getTranslation("SettingsMenu.oneRoundQuizOption") << "\n";
        std::cout << getTranslation("SettingsMenu.preferIniTranslationsOption") << "\n";
        std::cout << getTranslation("SettingsMenu.backMainMenu") << "\n";
        std::cout << getTranslation("SettingsMenu.settingsMenuSign2") << "\n";

        /*std::cout << settingsMenu.settingsMenuSign << std::endl;
        std::cout << settingsMenu.chooseSettingsMenu << std::endl;
        std::cout << settingsMenu.languageOptions << std::endl;
        std::cout << settingsMenu.targetLanguageOptions << std::endl;
        std::cout << settingsMenu.colorsOptions << std::endl;
        std::cout << settingsMenu.soundOptions << std::endl;
        std::cout << settingsMenu.accentsOptions << std::endl;
        std::cout << settingsMenu.oneRoundQuizOption << std::endl;
        std::cout << settingsMenu.backMainMenu << std::endl;
        std::cout << settingsMenu.settingsMenuSign2 << std::endl;*/
        //std::cout << numberoutput.numberOutput;

        int choice = 0;
        //-------RÉGI KÓD || OLD CODE
        /*std::string inputSettings;
        std::getline(std::cin, inputSettings);*/

        // Input beolvasása readLineWithHotkey-jel || Read Input with readLineWithHotkey
        //InputResult inputResult = readLineWithHotkey(numberoutput.numberOutput);
        InputResult inputResult = readLineWithHotkey(getTranslation("NumberOutput.numberOutput"));


        // -----CTRL + C Kezelése || CTRL + C Handling
        if (inputResult.exitTriggered)
        {
            playBeep();
            return;
        }
        std::string inputSettings = inputResult.text;
        std::string lowerInput = toLowerCase(trim(inputSettings));

        if (lowerInput == "exit" || lowerInput == "e")
        {
            playBeep();
            return;
        }

        try
        {
            //itt számá alakítjuk a bevitt értéket
            //here convert the entered value to a number
            choice = std::stoi(inputSettings);
        }
        catch (...)
        {
            // Ha nem számot ír be akkor a 99-ra a default ágra ugrunk
            // If you enter a non-number, we jump to the default branch at 99
            choice = 99;
        }
        // A menü ugrásai
        // jumps of menu
        switch (choice)
        {
        case 0:
            playBeep();
            return; //visszalépünk a főmenübe
        case 1:
            playBeep();
            choiceLanguage();
            break;
        case 2:
            playBeep();
            learningLanguage();
            break;
        case 3:
            playBeep();
            colorsOn();
            break;
        case 4:
            playBeep();
            soundOn();
            break;
        case 5:
            playBeep();
            accentsToggle();
            break;
        case 6:
            playBeep();
            oneRoundQuizToggle();
            break;
        case 7:
            playBeep();
            preferIniTranslationsToggle();
            break;
        default:
            screenWipe();
            if (choice == 99)
            {
                screenWipe();
                logError("SettingsMenu", getTranslation("InvalidInput2.invalidInput2"));
                std::cerr << getTranslation("InvalidInput2.invalidInput2");
                //logError("SettingsMenu", invalidIinput2.invalidInput2);
                //std::cerr << invalidIinput2.invalidInput2;
            } else
            {
                screenWipe();
                logError("SettingsMenu", getTranslation("InvalidInput.invalidInput"));
                std::cerr << getTranslation("InvalidInput.invalidInput");
                //std::cerr << invalidIinput.invalidInput;
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
        /*const LanguageMenu& LMenu = languageMenuTranslations[static_cast<int>(programUiLanguage)];
        const InvalidInput &II1 = invalidInputTranslations [static_cast<int>(programUiLanguage)];
        const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];*/
        //std::string selectedLangName = getLanguageNameByIndex(static_cast<int>(programUiLanguage));

        screenWipe();
        std::cout << getTranslation("LanguageMenu.languageMenu1Sign") << "\n";
        //std::cout << LMenu.languageMenu1Sign << std::endl;

        // KILISTÁZZUK AZ ÖSSZES NYELVET DINAMIKUSAN || LIST ALL LANGUAGES DYNAMICALLY
        for (int i = 0; i <= static_cast<int>(Language::LATIN); i++) {
            std::cout << i + 1 << ". " << getLanguageNameByIndex(i) << std::endl;
        }

        std::cout << getTranslation("LanguageMenu.exiting") << "\n";
       // std::cout << "\n" << LMenu.exiting << std::endl;
        //std::cout << LMenu.choiceStr;

        //-------RÉGI KÓD || OLD CODE
        /*std::string input;
        std::getline(std::cin, input);*/

        // Input beolvasása readLineWithHotkey-jel || Read Input with readLineWithHotkey
        InputResult inputResult = readLineWithHotkey(getTranslation("LanguageMenu.choiceStr"));
        //InputResult inputResult = readLineWithHotkey(LMenu.choiceStr);

        // --- CTRL + C Kezelése || CTRL + C Handling
        if (inputResult.exitTriggered)
        {
            playBeep();
            return; // Kilépünk a menüből
        }
        std::string input = inputResult.text;
        std::string lowerInput = toLowerCase(trim(input));

        if (lowerInput == "exit" || lowerInput == "e") {
            playBeep();
            return; // Kilépünk a menüből
        }

        try {
            int localChoice = std::stoi(input);
            if (localChoice == 0) break; // Visszalépünk || stepBack

            if (localChoice >= 1 && localChoice <= 24) {
                programUiLanguage = static_cast<Language>(localChoice - 1);

                // ---Frissítjük a hivatkozást az ÚJ nyelvre ---
                // ---Update the link to the NEW language ---
                //const LanguageMenu& LMenuNew = languageMenuTranslations[static_cast<int>(programUiLanguage)];

                // Itt kérjük le az ÚJ nevet a már módosított programUiLanguage alapján!
                // Here we request the NEW name based on the already modified programUiLanguage!
                std::string newSelectedLangName = getLanguageNameByIndex(static_cast<int>(programUiLanguage));

                // LMenuNew fontos!
                std::cout << getTranslation("LanguageMenu.choiceSuccessProgramLanguage") << ": " << newSelectedLangName << std::endl;
                //std::cout << LMenuNew.choiceSuccessProgramLanguage << ": " << newSelectedLangName << std::endl;
                saveSettings();
                waitToEnter();
                break;

            } else {
                screenWipe();
                logError("choiceLanguage()", getTranslation("InvalidInput2.invalidInput2"));
                //logError("choiceLanguage()", II2.invalidInput2);
                std::cerr << getTranslation("InvalidInput2.invalidInput2");
                //std::cerr << II2.invalidInput2;
                waitToEnter();
            }
        } catch (...) {
            screenWipe();
            logError("choiceLanguage()", getTranslation("InvalidInput.invalidInput"));
            //logError("choiceLanguage()", II1.invalidInput);
            std::cerr << getTranslation("InvalidInput.invalidInput");
            //std::cerr << II1.invalidInput;
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
        //const ColorsOnset & clrSET = colorsOSetTranslations[static_cast<int>(programUiLanguage)];
        //const InvalidInput &II1 = invalidInputTranslations [static_cast<int>(programUiLanguage)];
        //const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];
        //===============================
        screenWipe();
        //std::cout << clrSET.colorsPrinting1 << std::endl;
        std::cout << getTranslation("ColorsOnset.colorsPrinting1") << "\n";
        std::cout <<getTranslation("ColorsOnset.colorsPrinting2") << (useColors ? getTranslation("ColorsOnset.useCLR_ON") : getTranslation("ColorsOnset.useCLR_OFF")) << "\n" << std::flush;
        //std::cout << clrSET.colorsPrinting2 << (useColors ? clrSET.useCLR_ON : clrSET.useCLR_OFF) << std::endl;
        std::cout << getTranslation("ColorsOnset.colorsMenu1") << getTranslation("ColorsOnset.colorsMenu2") << getTranslation("ColorsOnset.colorsMenu3");
        //std::cout << clrSET.colorsMenu1 << clrSET.colorsMenu2 << clrSET.colorsMenu3;
        //std::cout <<"\n"<< clrSET.choice << std::flush;
        InputResult inputResult = readLineWithHotkey("\n" + getTranslation("ColorsOnset.choice"));
        //InputResult inputResult = readLineWithHotkey("\n" + clrSET.choice);

        // --- CTRL + C Kezelése || CTRL + C Handling
        if (inputResult.exitTriggered)
        {
            playBeep();
            return;
        }
        std::string inputC = inputResult.text;
        std::string lowerInput = toLowerCase(trim(inputC));
        //std::string lowerInput = toLowerCase(trim(inputResult.text));

        if (lowerInput == "exit" || lowerInput == "e") {
            playBeep();
            return;
        }

        //-------RÉGI KÓD || OLD CODE-------
        /*std::string inputC;
        std::getline(std::cin, inputC);*/
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
                    std::cout << getTranslation("ColorsOnset.colorsOnOn") << "\n" << std::flush;
                    //std::cout << clrSET.colorsOnOn  <<std::endl;
                } else
                {
                    currentBG = "";       // Kiürítjük a háttérszín kódját
                    currentBG_Code = 1;   // Visszaállítjuk az alapértelmezett (fekete) kódra
                    std::cout << colors::RESET << std::flush;// visszaállítjuk az alapértelmezett színre
                    std::cout << getTranslation("ColorsOnset.colorsOffOff") << "\n" << std::flush;
                    //std::cout << clrSET.colorsOffOff << std::endl;
                }
                saveSettings(); //elmentjük a beállításokat
                playBeep();
                waitToEnter();
            }
            else if (choice == 2)
            {
                playBeep();
                backgroundSets();//Meghívjuk a háttérszín beállíto menüt
            }
            else if (choice == 3)
            {
                playBeep();
                break; //kilépünk a ciklusból
            }
            else
            {
                // Ha számot adotál meg, de az nem 1, 2 vagy 3 (pl. 5)
                screenWipe();
                //logError("colorsOn()", II2.invalidInput2);
                logError("colorsOn()" ,getTranslation("InvalidInput2.invalidInput2"));
                std::cerr << getTranslation("InvalidInput2.invalidInput2");
                //std::cerr << II2.invalidInput2;
                waitToEnter();
            }
        }
        catch (...)
        {
            // ha nem számot adtál meg
            screenWipe();
            logError("colorsOn()", getTranslation("InvalidInput.invalidInput"));
            //logError("colorsOn()", II1.invalidInput);
            std::cerr << getTranslation("InvalidInput.invalidInput");
            //std::cerr << II1.invalidInput;
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
    //const SaveSettings& saveSettings = saveSettingsTranslations[static_cast<int>(programUiLanguage)];
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
        outFile << "ProgramLanguage=" << static_cast<int>(programUiLanguage) << "\n";
        outFile << "MotherLanguage=" << static_cast<int>(motherLanguage) << "\n";
        outFile << "TargetLanguage=" << static_cast<int>(targetLanguage) << "\n";
        outFile << "UseColors=" << useColors << "\n";
        outFile <<"CurrentBGCode=" << currentBG_Code << "\n";
        outFile << "UseSound=" << useSound << "\n";
        outFile << "IgnoreAccents=" << ignoreAccents << "\n";
        outFile <<"OneRoundQuiz=" << oneRoundQuiz << "\n";
        outFile << "ResumeIndex=" << resumeIndex << "\n";
        outFile << "ShowHelp=" << showHelp << "\n";
        outFile << "HelperUsed=" << helperUsed << "\n";
        outFile << "PreferIniTranslations=" << preferIniTranslations << "\n";
        outFile.close();
    }
    else
    {
        screenWipe();
        logError("saveSettings()", getTranslation("SaveSettings.saveSettingsError"));
        //logError("saveSettings()", saveSettings.saveSettingsError);
        std::cerr << getTranslation("SaveSettings.saveSettingsError");
        //std::cerr << saveSettings.saveSettingsError << std::endl;
        waitToEnter();
    }
}

// Betölti a beállításokat a fájlból, ha az létezik
// Loads settings from file if it exists
bool loadSettings() {
    std::ifstream inFile("settings.cfg");
    if (inFile.is_open()) {
        std::string line;

        // Visszaállítjuk az alapértelmezett értékeket, ha valami hiányzik a fájlból
        // Reset to default values if something is missing from the file
        programUiLanguage = Language::HUNGARIAN;
        motherLanguage = Language::HUNGARIAN;
        targetLanguage = Language::ENGLISH;
        useColors = true;
        currentBG_Code = 1;
        useSound = false;
        ignoreAccents = false;
        oneRoundQuiz = false;
        resumeIndex = 0;
        showHelp = false;
        helperUsed = false;
        preferIniTranslations = true;
        currentBG = ""; // Alapértelmezett háttérszín || Default background color

        currentBG =""; //colors::RESET; Vagy ||or ""

        while (std::getline(inFile, line))
        {
            size_t eqPos = line.find('=');
            if (eqPos == std::string::npos) continue; // Kihagyjuk a hibás sorokat || Skip invalid lines

            std::string key = line.substr(0, eqPos);
            std::string valueStr = line.substr(eqPos + 1);

            if (key == "ProgramLanguage") programUiLanguage = static_cast<Language>(std::stoi(valueStr));
            else if (key == "MotherLanguage") motherLanguage = static_cast<Language>(std::stoi(valueStr));
            else if (key == "TargetLanguage") targetLanguage = static_cast<Language>(std::stoi(valueStr));
            else if (key == "UseColors") useColors = (valueStr == "1" || valueStr == "true");
            else if (key == "CurrentBGCode") currentBG_Code = std::stoi(valueStr);
            else if (key == "UseSound") useSound = (valueStr == "1" || valueStr == "true");
            else if (key == "IgnoreAccents") ignoreAccents = (valueStr == "1" || valueStr == "true");
            else if (key == "OneRoundQuiz") oneRoundQuiz = (valueStr == "1" || valueStr == "true");
            else if (key == "ResumeIndex") resumeIndex = std::stoul(valueStr);
            else if (key == "ShowHelp") showHelp = (valueStr == "1" || valueStr == "true");
            else if (key == "HelperUsed") helperUsed = (valueStr == "1" || valueStr == "true");
            else if (key == "PreferIniTranslations") preferIniTranslations = (valueStr == "1" || valueStr == "true");
        }
        inFile.close();

        // A fordítások betöltése || the Translations loading
        loadTranslationsFromFile(programUiLanguage);

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
    /*const NumberOutput& numberoutput = chooseNumberMenuTranslations[static_cast<int>(programUiLanguage)];
    const BackgroundSets &backgroundsets = backgroundSetsTranslations[static_cast<int>(programUiLanguage)];
    const InvalidInput &II1 = invalidInputTranslations [static_cast<int>(programUiLanguage)];
    const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];
    const ColorsOnset & clrSET = colorsOSetTranslations[static_cast<int>(programUiLanguage)];*/

    if (!useColors)
    {
        screenWipe();
        logError("backgroundSets()-!useColors" , getTranslation("ColorsOnset.errorEntryDenied"));
        std::cerr << getTranslation("ColorsOnset.errorEntryDenied")<< "\n" << std::flush;
        //std::cerr << clrSET.errorEntryDenied << std::endl;
        waitToEnter();
        return; // AZONNAL KILÉPÜNK
    }
    for (;;)
    {
        screenWipe(); // töröljük a képernyőt

        std::cout << getTranslation("BackgroundSets.sign") << "\n" << std::flush;
        std::cout << getTranslation("BackgroundSets.DefaultBlack");
        std::cout << getTranslation("BackgroundSets.green");
        std::cout << getTranslation("BackgroundSets.cian");
        std::cout << getTranslation("BackgroundSets.red");
        std::cout << getTranslation("BackgroundSets.purple");
        std::cout << getTranslation("BackgroundSets.blue");
        std::cout << getTranslation("BackgroundSets.white");
        std::cout << getTranslation("BackgroundSets.gray");
        std::cout << getTranslation("BackgroundSets.stepBack");

        InputResult inputResult = readLineWithHotkey(getTranslation("NumberOutput.numberOutput"));
        /*std::cout << backgroundsets.sign << std::endl;
        std::cout << backgroundsets.DefaultBlack;
        std::cout << backgroundsets.green;
        std::cout << backgroundsets.cian;
        std::cout << backgroundsets.red;
        std::cout << backgroundsets.purple;
        std::cout << backgroundsets.blue;
        std::cout << backgroundsets.white;
        std::cout << backgroundsets.gray;
        std::cout <<backgroundsets.stepBack;*/
        //std::cout << numberoutput.numberOutput << std::flush;
        //InputResult inputResult = readLineWithHotkey(numberoutput.numberOutput);

        //--------RÉGI KÓD || OLD CODE-------
       /* std::string inputBS;
        std::getline(std::cin, inputBS);*/

        // --- CTRL + C Kezelése || CTRL + C Handling
        if (inputResult.exitTriggered)
        {
            playBeep();
            return; // Kilépünk a menüből
        }
        std::string inputBS = inputResult.text;
        std::string lowerInput = toLowerCase(trim(inputBS));

        if (lowerInput == "exit" || lowerInput == "e") {
            playBeep();
            return; // Kilépünk a menüből
        }

        try
        {
            int choice = 0;
            //itt számá alakítjuk a bevitt értéket
            choice = std::stoi(inputBS);

            if (choice == 1)
            {
                playBeep();
                currentBG = colors::RESET;
                currentBG_Code = 1;
            }
            else if (choice == 2)
            {
                playBeep();
                currentBG = colors::BG_GREEN;
                currentBG_Code = 2;
            }
            else if (choice == 3)
            {
                playBeep();
                currentBG = colors::BG_CYAN;
                currentBG_Code = 3;
            }
            else if (choice == 4)
            {
                playBeep();
                currentBG = colors::BG_RED;
                currentBG_Code = 4;
            }
            else if (choice == 5)
            {
                playBeep();
                currentBG = colors::BG_MAGENTA;
                currentBG_Code = 5;

            }
            else if (choice == 6)
            {
                playBeep();
                currentBG = colors::BG_BLUE;
                currentBG_Code = 6;
            }
            else if (choice == 7)
            {
                playBeep();
                currentBG = colors::BG_WHITE;
                currentBG_Code = 7;

            }
            else if (choice == 8)
            {
                playBeep();
                currentBG = colors::BG_GREY;
                currentBG_Code = 8;
            }
            else if (choice == 9)
            {
                playBeep();
                break; //kilépünk
            }
            else
            {
                screenWipe();
                logError("backgroundSets()--try", getTranslation("InvalidInput2.invalidInput2"));
            //std::cerr << II2.invalidInput2;
                playBeep();
                std::cerr << getTranslation("InvalidInput2.invalidInput2");
                waitToEnter();
                continue; //ujraindul a ciklus
            }

        } catch (...) {

            // ha nem számot adtál meg
            screenWipe();
            //logError("backgroundSets()", II1.invalidInput);
            logError("backgroundSets()--catch", getTranslation("InvalidInput.invalidInput"));
            playBeep();
            std::cerr << getTranslation("InvalidInput.invalidInput");
            //std::cerr << II1.invalidInput;
            waitToEnter();
        }
        screenWipe();
        saveSettings(); //elmentjük a beállításokat || save the settings

        // KIVÁLASZTOTT SZÍN NEVÉNEK KIÍRÁSA
        // PRINT THE NAME OF THE SELECTED COLOR
        std::cout << getTranslation("BackgroundSets.backgroundColorsChange") << "\n" << std::flush;
        //std::cout << backgroundsets.backgroundColorsChange << std::endl;

        if (currentBG_Code == 1) std::cout << getTranslation("BackgroundSets.backGroundColor")
        << getTranslation("BackgroundSets.DefaultBlack");

        else if (currentBG_Code == 2)
            std::cout << getTranslation("BackgroundSets.backGroundColor")
                      << getTranslation("BackgroundSets.green");

        else if (currentBG_Code == 3)
            std::cout << getTranslation("BackgroundSets.backGroundColor")
                      << getTranslation("BackgroundSets.cian");

        else if (currentBG_Code == 4)
            std::cout << getTranslation("BackgroundSets.backGroundColor")
                      << getTranslation("BackgroundSets.red");

        else if (currentBG_Code == 5)
            std::cout << getTranslation("BackgroundSets.backGroundColor")
                      << getTranslation("BackgroundSets.purple");

        else if (currentBG_Code == 6)
            std::cout << getTranslation("BackgroundSets.backGroundColor")
                      << getTranslation("BackgroundSets.blue");

        else if (currentBG_Code == 7)
            std::cout << getTranslation("BackgroundSets.backGroundColor")
                      << getTranslation("BackgroundSets.white");

        else if (currentBG_Code == 8)
            std::cout << getTranslation("BackgroundSets.backGroundColor")
                      << getTranslation("BackgroundSets.gray");

        /*if (currentBG_Code == 1) std::cout << backgroundsets.DefaultBlack;
        else if (currentBG_Code == 2) std::cout << backgroundsets.backGroundColor << backgroundsets.green;
        else if (currentBG_Code == 3) std::cout << backgroundsets.backGroundColor << backgroundsets.cian;
        else if (currentBG_Code == 4) std::cout << backgroundsets.backGroundColor << backgroundsets.red;
        else if (currentBG_Code == 5) std::cout << backgroundsets.backGroundColor << backgroundsets.purple;
        else if (currentBG_Code == 6) std::cout << backgroundsets.backGroundColor << backgroundsets.blue;
        else if (currentBG_Code == 7) std::cout << backgroundsets.backGroundColor << backgroundsets.white;
        else if (currentBG_Code == 8) std::cout << backgroundsets.backGroundColor << backgroundsets.gray;*/

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
        /*const LearningLanguageSet& LLS = learningLanguageSetTranslations[static_cast<int>(programUiLanguage)];
        const InvalidInput &II1 = invalidInputTranslations [static_cast<int>(programUiLanguage)];
        const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];*/

        screenWipe(); //letöröljük a képernyőt

        std::cout << getTranslation("LearningLanguageSet.Menu") << "\n" << std::flush;
        std::cout << getTranslation("LearningLanguageSet.CurrentlyMotherLanguage") <<" "<< getLanguageNameByIndex(static_cast<int>(motherLanguage)) << "\n" << std::flush;
        std::cout << getTranslation("LearningLanguageSet.CurrentlyLearningLanguage") <<" "<< getLanguageNameByIndex(static_cast<int>(targetLanguage)) << "\n" << std::flush;
        std::cout << "\n"<< getTranslation("LearningLanguageSet.menuSigns") << "\n" << std::flush;
        std::cout << getTranslation("LearningLanguageSet..option1") << std::flush;
        std::cout << getTranslation("LearningLanguageSet.option2") << std::flush;
        std::cout << getTranslation("LearningLanguageSet.option3") << std::flush;

        InputResult inputResult = readLineWithHotkey("\n4." + getTranslation("LearningLanguageSet.choice"));


        /*std::cout << LLS.Menu << std::endl;
        std::cout << LLS.CurrentlyMotherLanguage <<" "<< getLanguageNameByIndex(static_cast<int>(motherLanguage)) << std::endl;
        std::cout << LLS.CurrentlyLearningLanguage <<" "<< getLanguageNameByIndex(static_cast<int>(targetLanguage)) << std::endl;
        std::cout << "\n"<< LLS.menuSigns <<"\n" << std::endl;
        std::cout << LLS.option1 ;
        std::cout << LLS.option2 ;
        std::cout << LLS.option3 ;*/
        //std::cout << "\n4. "<<LLS.choice << std::flush;
        //InputResult inputResult = readLineWithHotkey("\n4." + LLS.choice);

        // --- CTRL + C Kezelése || CTRL + C Handling
        if (inputResult.exitTriggered)
        {
            playBeep();
            return; // Kilépünk a menüből
        }

        std::string inputLLS = inputResult.text;
        std::string lowerInput = toLowerCase(trim(inputLLS));

        if (lowerInput == "exit" || lowerInput == "e")
        {
            playBeep();
            return;
        }

            //--------RÉGI KÓD || OLD CODE-------
            /*std::string inputLLS;
            std::getline(std::cin, inputLLS);*/

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
                        std::cout << getTranslation("LearningLanguageSet.choice1") << "\n" << std::flush;
                        //std::cout << LLS.choice1 <<std::endl;
                        //meghívjuk az enum listát a kiválasztáshoz
                        for (int i = 0; i <= static_cast<int>(Language::LATIN); i++)
                        {
                            std::cout << i + 1 << ". " << getLanguageNameByIndex(i) << std::endl;
                        }
                        std::cout << getTranslation("LearningLanguageSet.back") << "\n" << std::flush;
                        //std::cout << LLS.back <<std::endl;
                        //std::cout << LLS.allChoice;
                        InputResult mLangInputResult = readLineWithHotkey(getTranslation("LearningLanguageSet.allChoice"));

                        //InputResult mLangInputResult = readLineWithHotkey(LLS.allChoice);

                        // --- CTRL + C Kezelése || CTRL + C Handling
                        if (mLangInputResult.exitTriggered)
                        {
                            playBeep();
                            break; // Kilép a belső ciklusból
                        }

                        std::string mLangInput = mLangInputResult.text;
                        std::string lowerMLangInput = toLowerCase(trim(mLangInput));

                        if (lowerMLangInput == "exit" || lowerMLangInput == "e") {
                            playBeep();
                            break; // Kilép a belső ciklusból
                        }

                        //--------RÉGI KÓD || OLD CODE-------
                        /*std::string  mLangInput;
                        std::getline(std::cin, mLangInput);*/

                        try {
                            int langChoice = std::stoi(mLangInput);

                            if (langChoice == 0)
                            {
                                playBeep();
                                break; //visszalépünk
                            }
                            if (langChoice >= 1 && langChoice <= 24) {
                                auto tempMotherLanguage = static_cast<Language>(langChoice - 1);
                                if (tempMotherLanguage == targetLanguage) {

                                    playBeep();
                                    screenWipe();
                                    logError("learningLanguage()" , getTranslation("LearningLanguageSet.error"));

                                    std:: cerr << getTranslation("LearningLanguageSet.error") <<"\n" <<std::flush;
                                    //std::cerr << LLS.error << std::endl;
                                    waitToEnter();
                                    continue;
                                }
                                motherLanguage = tempMotherLanguage;
                                screenWipe();

                                // DINAMIKUS VISSZAJELZÉS:
                                std::string selectedName = getLanguageNameByIndex(static_cast<int>(motherLanguage));
                                std::cout << getTranslation("LearningLanguageSet.motherSuccess") << ": " << selectedName << "\n" << std::flush;
                                //std::cout << LLS.motherSuccess << ": " << selectedName << std::endl;
                                saveSettings();
                                waitToEnter();
                            } else
                            {
                                // Ha számot ír de tartományun kivül esik
                                // If you enter a number but it is out of range
                                playBeep();
                                //logError("learningLanguage()(choice1)",II2.invalidInput2);
                                logError("learningLanguage()(choice1)", getTranslation("InvalidInput2.invalidInput2"));
                                std::cerr << getTranslation("InvalidInput2.invalidInput2");
                                //std::cerr << II2.invalidInput2;
                                waitToEnter();
                            }
                        } catch (...) {
                            // HA NEM SZÁMOT ÍRT (pl. "abc")
                            // IF NOT A NUMBER (e.g. "abc")
                            playBeep();
                            logError ("learningLanguage()-(choice1)" , getTranslation("InvalidInput.invalidInput"));
                            //logError("learningLanguage()(choice1)",II1.invalidInput);

                            std::cerr << getTranslation("InvalidInput.invalidInput");
                            //std::cerr << II1.invalidInput;
                            waitToEnter();
                        }
                        break; //kilépünk ha minden jó és nincs hiba
                    }
                } else if (choice == 2)
                {
                    for (;;)
                    {
                        screenWipe();
                        std::cout << getTranslation("LearningLanguageSet.choice2") << "\n" << std::flush;
                        //std::cout << LLS.choice2 << std::endl;
                        for (int i = 0; i <= static_cast<int>(Language::LATIN); i++) {
                            std::cout << i + 1 << ". " << getLanguageNameByIndex(i) << std::endl;
                        }
                        std::cout << getTranslation("LearningLanguageSet.back") << "\n" << std::flush;
                        //std::cout << LLS.back <<std::endl;
                        //std::cout << LLS.allChoice;

                        InputResult tLangInputResult = readLineWithHotkey(getTranslation("LearningLanguageSet.allChoice"));
                        //InputResult tLangInputResult = readLineWithHotkey(LLS.allChoice);

                        // --- CTRL + C Kezelése || CTRL + C Handling
                        if (tLangInputResult.exitTriggered)
                        {
                            playBeep();
                            break; // Kilép a belső ciklusból
                        }

                        std::string tLangInput = tLangInputResult.text;
                        std::string lowerTLangInput = toLowerCase(trim(tLangInput));

                        if (lowerTLangInput == "exit" || lowerTLangInput == "e") {
                            playBeep();
                            break; // Kilép a belső ciklusból
                        }

                        // ------RÉGI KÓD || OLD CODE-------
                        /*std::string tLangInput;
                        std::getline(std::cin, tLangInput);*/

                        try {
                            int langChoice = std::stoi(tLangInput);
                            if (langChoice == 0) break; //kilépünk
                            if (langChoice >= 1 && langChoice <= 24) {
                                auto tempTargetLanguage = static_cast<Language>(langChoice - 1);

                                if (tempTargetLanguage == motherLanguage) {
                                    playBeep();
                                    screenWipe();
                                    logError("learningLanguage()" , getTranslation("LearningLanguageSet.error"));
                                    std::cerr << getTranslation("LearningLanguageSet.error") << "\n" << std::flush;
                                    //std::cerr << LLS.error << std::endl;
                                    waitToEnter();
                                    continue; // Vissza a learningLanguage menübe
                                }

                                targetLanguage = tempTargetLanguage;
                                screenWipe();

                                std::string selectedName = getLanguageNameByIndex(static_cast<int>(targetLanguage));

                                std::cout << getTranslation("LearningLanguageSet.targetSuccess") << ": " << selectedName << "\n" << std::flush;
                                //std::cout << LLS.targetSuccess << ": " << selectedName << std::endl;
                                saveSettings();
                                waitToEnter();
                            } else {
                                //logError("learningLanguage()(choice2)",II2.invalidInput2);
                                logError("learningLanguage()(choice2)", getTranslation("InvalidInput2.invalidInput2"));
                                playBeep();
                                std::cerr << getTranslation("InvalidInput2.invalidInput2");
                                //std::cerr << II2.invalidInput2;
                                waitToEnter();
                            }
                        } catch (...) {
                            //logError("learningLanguage()(choice1)",II1.invalidInput);
                            logError("learningLanguage()(choice1)", getTranslation("InvalidInput.invalidInput"));
                            playBeep();
                           std::cerr << getTranslation("InvalidInput.invalidInput");
                            //std::cerr << II1.invalidInput;
                            waitToEnter();
                        }
                        break;
                    }
                }
                //visszalépünk a főmenübe
                else if (choice ==3)
                {
                    playBeep();
                    return; //kilépünk a ciklusból
                }

            } catch (...)
            {
                //logError("learningLanguage()(mainMenu)",II2.invalidInput2);
                logError("learningLanguage()(mainMenu)", getTranslation("InvalidInput2.invalidInput2"));
                std::cerr << getTranslation("InvalidInput2.invalidInput2");
                //std::cerr << II2.invalidInput2;
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
        //const SoundOnOff &SOO = soundOnOffTranslations [static_cast<int>(programUiLanguage)];
        //const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];

        for (;;) {
            screenWipe();
            std::cout << getTranslation("SoundOnOff.soundSet") << "\n" << std::flush;
            std::cout << getTranslation ("SoundOnOff..currentlyState")
            << (useSound ? getTranslation("SoundOnOff.useSoundOn") : getTranslation("SoundOnOff.useSoundOff"))
            << "\n" << std::flush;
            /*std::cout << SOO.soundSet << std::endl;
            std::cout << SOO.currentlyState << (useSound ? SOO.useSoundOn : SOO.useSoundOff) << std::endl;*/
            //std::cout << SOO.option1;
            // Input beolvasása readLineWithHotkey-jel || Read input with readLineWithHotkey

            InputResult inputResult = readLineWithHotkey(getTranslation("SoundOnOff.option1"));
            //InputResult inputResult = readLineWithHotkey(SOO.option1);

            //-------RÉGI KÓD || OLD CODE
            /*std::string input;
            std::getline(std::cin, input);*/

            // --- CTRL + C Kezelése || CTRL + C Handling
            if (inputResult.exitTriggered)
            {
                playBeep();
                return; // Kilépünk a menüből
            }

            std::string input = inputResult.text;
            std::string lowerInput = toLowerCase(trim(input));

            // --- "exit" vagy "e" parancs kezelése ---
            if (lowerInput == "exit" || lowerInput == "e") {
                playBeep();
                return; // Kilépünk a menüből
            }

            try {
                int localChoice = std::stoi(input);
                if (localChoice == 1) {
                    useSound = !useSound; // Átkapcsolás
                    saveSettings();
                    // feedback for User
                    // visszajelzés a felhasználónak

                    std::cout << (useSound ? getTranslation("SoundOnOff.useSoundOn2") : getTranslation("SoundOnOff.useSoundOff2")) << "\n" << std::flush;
                    //std::cout << (useSound ? SOO.useSoundOn2 : SOO.useSoundOff2) << std::endl;
                    waitToEnter();
                } else if (localChoice == 0)
                {
                    playBeep();
                    break;
                }
            } catch (...) {
                logError("soundOn()" , getTranslation("InvalidInput2.invalidInput2"));
                //logError("soundOn()" , II2.invalidInput2);
                playBeep();
                std::cerr << getTranslation("InvalidInput2.invalidInput2") << "\n";
                //std::cerr << II2.invalidInput2 << "\n";
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
            //const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];
            //const SpellingOutAccents &SOA = spellingOutAccentsTranslations [static_cast<int>(programUiLanguage)];

            screenWipe();
            std::cout << getTranslation("SpellingOutAccents.accentsMenu") << "\n" << std::flush;
            //std::cout << SOA.accentsMenu << std::endl;
            std::cout << getTranslation("SpellingOutAccents.accentsState")
            << (ignoreAccents ? getTranslation("SpellingOutAccents.accentsState1Off") : getTranslation("SpellingOutAccents.accentsState2On"))
            << "\n" << std::flush;
            //std::cout << SOA.accentsState << (ignoreAccents ? SOA.accentsState1Off : SOA.accentsState2On) << std::endl;
            //std::cout << SOA.accentsMenu1;

            // Input beolvasása readLineWithHotkey-jel || Read input with readLineWithHotkey

            InputResult inputResult = readLineWithHotkey(getTranslation("SpellingOutAccents.accentsMenu1"));
            //InputResult inputResult = readLineWithHotkey(SOA.accentsMenu1);

            // --- CTRL + C Kezelése || CTRL + C Handling
            if (inputResult.exitTriggered)
            {
                playBeep();
                return; // Kilépünk a menüből
            }
            //-------RÉGI KÓD || OLD CODE
            /*std::string input;
            std::getline(std::cin, input);*/

            std::string input = inputResult.text;
            std::string lowerInput = toLowerCase(trim(input));

            // --- "exit" vagy "e" parancs kezelése ---
            if (lowerInput == "exit" || lowerInput == "e") {
                playBeep();
                return; // Kilépünk a menüből
            }

            try {
                int localChoice = std::stoi(input);
                if (localChoice == 1) {
                    ignoreAccents = !ignoreAccents;
                    saveSettings();

                    // VISSZAJELZÉS A FELHASZNÁLÓNAK
                    // FEEDBACK FOR USER
                    playBeep();
                    std::cout << (ignoreAccents ? getTranslation("SpellingOutAccents.accentsState1Off") : getTranslation("SpellingOutAccents.accentsState2On")) << "\n" << std::flush;
                    //std::cout << (ignoreAccents ? SOA.accentsState1Off : SOA.accentsState2On) << std::endl;
                    waitToEnter();
                } else if (localChoice == 0) break;
            } catch (...) {
                logError("accentsToggle()" , getTranslation("InvalidInput2.invalidInput2"));
                //logError("accentsToggle()" , II2.invalidInput2);
                playBeep();
                std::cerr << getTranslation("InvalidInput2.invalidInput2") << "\n";
                //std::cerr << II2.invalidInput2 << "\n";
                waitToEnter();
            }
        }
    }

    // Egy körös kvíz be és ki kapcsolása
    void oneRoundQuizToggle() {
        for (;;) {
            // Nyelvi hivatkozások || Language references
           // const InvalidInput2 &II2 = invalidInputTranslations2 [static_cast<int>(programUiLanguage)];
           // const OneRoundQString &ORQS = oneRoundQuizStringTranslations [static_cast<int>(programUiLanguage)];

            screenWipe();
            std::cout << getTranslation("OneRoundQString.mainSigns") <<"\n";
            std::cout << getTranslation("OneRoundQString.currentlyState") << (oneRoundQuiz ? getTranslation("OneRoundQString.stateON") : getTranslation("OneRoundQString.stateOff")) << "\n";
            std::cout << getTranslation("OneRoundQString.switching") << "\n";
            std::cout << getTranslation("OneRoundQString.back") << "\n";

            InputResult inputResult = readLineWithHotkey(getTranslation("OneRoundQString.choose"));

            /*std::cout << ORQS.mainSigns << "\n";
            std::cout << ORQS.currentlyState << (oneRoundQuiz ? ORQS.stateON : ORQS.stateOff) << "\n" << std::flush;
            std::cout << ORQS.switching << "\n";
            std::cout << ORQS.back << "\n";*/
            //std::cout << ORQS.choose;
            //InputResult inputResult = readLineWithHotkey(ORQS.choose);

            // --- CTRL + C Kezelése || CTRL + C Handling
            if (inputResult.exitTriggered)
            {
                playBeep();
                return; // Kilépünk a menüből
            }
            std::string input = inputResult.text;
            std::string lowerInput = toLowerCase(trim(input));

            // --- "exit" vagy "e" parancs kezelése || Handling the "exit" or "e" command  ---
            if (lowerInput == "exit" || lowerInput == "e") {
                playBeep();
                return; // Kilépünk a menüből || exit the menu
            }


            //-----RÉGI KÓD || OLD CODE------
            /*std::string input;
            std::getline(std::cin, input);*/

            try {
                int localChoice = std::stoi(input);
                if (localChoice == 1) {
                    oneRoundQuiz = !oneRoundQuiz;
                    saveSettings();
                    std::cout <<  (oneRoundQuiz ? getTranslation("OneRoundQString.OneRoundStateOn") : getTranslation("OneRoundQString.OneRoundStateOff")) << "\n" << std::flush;
                    //std::cout << (oneRoundQuiz ? ORQS.OneRoundStateOn : ORQS.OneRoundStateOff) << "\n" << std::flush;
                    playBeep();
                    waitToEnter();
                } else if (localChoice == 0)
                {
                    playBeep();
                    break;
                } else
                {
                    screenWipe();
                    logError("oneRoundQuizToggle()", getTranslation("InvalidInput2.invalidInput2"));
                    //logError("oneRoundQuizToggle()" , II2.invalidInput2);
                    std::cerr << getTranslation("InvalidInput2.invalidInput2") << "\n" << std::flush;
                    //std::cerr << II2.invalidInput2 << "\n" << std::flush;
                    playBeep();
                    waitToEnter();
                }
            } catch (...) {
                screenWipe();
                logError("oneRoundQuizToggle()", getTranslation("InvalidInput2.invalidInput2"));
                //logError("oneRoundQuizToggle()" , II2.invalidInput2);
                std::cerr << getTranslation("InvalidInput2.invalidInput2") << "\n" << std::flush;
                //std::cerr << II2.invalidInput2 << "\n" << std::flush;
                playBeep();
                waitToEnter();
            }
        }
    }

void preferIniTranslationsToggle()
{
    screenWipe();
    std::cout << getTranslation("IniStructToggle.mainSigns")  << "\n";
    std::cout << getTranslation("IniStructToggle.currentlyState") << (preferIniTranslations ? getTranslation("IniStructToggle.stateON") : getTranslation ("stateOff")) << "\n" << std::flush;

    InputResult inputResult = readLineWithHotkey(getTranslation("IniStructToggle.switchingMenu"));

    if (inputResult.exitTriggered) {
        playBeep();
        return;
    }
    std::string input = inputResult.text;
    std::string lowerInput = toLowerCase(trim(input));

    if (lowerInput == "exit" || lowerInput == "e") {
        playBeep();
        return;
    }
    try {
        int localChoice = std::stoi(input);
        if (localChoice == 1) {
            preferIniTranslations = !preferIniTranslations;
            saveSettings();
            // ÚJ: Fordítások újratöltése a preferIniTranslations alapján
            loadTranslationsFromFile(programUiLanguage);
            std::cout << (preferIniTranslations ? getTranslation("IniStructToggle.cStateON") : getTranslation("IniStructToggle.cStateOff")) << std::endl; 
            playBeep();
            waitToEnter();
        } else if (localChoice == 0) {
            playBeep();
            return;
        } else {
            screenWipe();
            logError("preferIniTranslationsToggle()" , getTranslation("InvalidInput2.invalidInput2"));
            std::cerr << getTranslation("InvalidInput2.invalidInput2") << "\n";
            waitToEnter();
        }
    } catch (...) {
        logError("preferIniTranslationsToggle()" , getTranslation("InvalidInput2.invalidInput2"));
        std::cerr << getTranslation("InvalidInput2.invalidInput2") << "\n";
        waitToEnter();
    }
}

