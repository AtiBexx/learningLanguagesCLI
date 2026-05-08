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
/*#include <cstdio>
#include <cstdlib>*/
#include <iostream>
#include <string>
#include <vector>
#include "translations.h"
#include "cliFileReading.h"
#include <fstream>
#include "createVocab.h"
#include "osEditor.h"
#include "newInput/platformInput.h"
#include "Settings/settings.h"


void mainMenu() {
    for (;;) {
        screenWipe();
        //const MenuStrings &menuStrs = mainMenuTranslations[static_cast<int>(programUiLanguage)];

        std::cout << getTranslation("MenuStrings.titleAndSigns") << "\n";
        std::cout << getTranslation("MenuStrings.programExplanation") << "\n";
        std::cout << getTranslation("MenuStrings.startProgram") << "\n";
        std::cout << getTranslation("MenuStrings.mistakeExercise") << "\n";
        std::cout << getTranslation("MenuStrings.newFile") << "\n";
        std::cout << getTranslation("MenuStrings.settings") << "\n";
        std::cout << getTranslation("MenuStrings.Editor") << "\n";
        std::cout << getTranslation("MenuStrings.exit") << "\n";
        std::cout << getTranslation("MenuStrings.signs") << "\n";

        /*
        std::cout << menuStrs.titleAndSigns <<"\n";
        std::cout << menuStrs.programExplanation << "\n";
        std::cout << menuStrs.startProgram << "\n";
        std::cout << menuStrs.mistakeExercise << "\n";
        std::cout << menuStrs.newFile << "\n";
        std::cout << menuStrs.settings << "\n";
        std::cout << menuStrs.Editor << "\n";
        std::cout << menuStrs.exit << "\n";
        std::cout << menuStrs.signs << "\n";*/

        int choice = 0;
        //const NumberOutput &numStrs = chooseNumberMenuTranslations[static_cast<int>(programUiLanguage)];
        //std::cout << numStrs.numberOutput << std::flush;
        // Az Input beolvasása || Read Input
        InputResult inputResult = readLineWithHotkey(getTranslation("NumberOutput.numberOutput"));
        //InputResult inputResult = readLineWithHotkey(numStrs.numberOutput);

        // -----CTRL + C Kezelése || CTRL + C Handling
        if (inputResult.exitTriggered)
        {
            playBeep();
            exiting();
            return; // Kilépünk az egész programból || We are exiting the entire program.
        }

        std::string inputStr = inputResult.text;
        std::string lowerInput = toLowerCase(trim(inputStr));

        // --- "exit" vagy "e" parancs kezelése ---
        if (lowerInput == "exit" || lowerInput == "e") {
            playBeep();
            exiting();
            return; // Kilép az egész programból
        }
        try
        {
            choice = std::stoi(inputStr);
        } catch (...)
        {
            screenWipe();
            //const InvalidInput &invalidinput = invalidInputTranslations[static_cast<int>(programUiLanguage)];
            //logError("mainMenu", invalidinput.invalidInput);
            logError("mainMenu", getTranslation("InvalidInput.invalidInput"));
            std::cerr << getTranslation("InvalidInput.invalidInput") << "\n";
            //std::cerr << invalidinput.invalidInput <<"\n";
            waitToEnter();
            continue;
        }
        /* ====== régi kód || old code ==========
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
        }*/

        switch (choice) {
            case 0:
                 playBeep();
                 exiting();
                 return;
            case 1:
                //pufferDelete();
                playBeep();
                explanation();
                break;
            case 2:
                //pufferDelete();
                playBeep();
                listAndSelectFile();
                break;
            case 3:
                //pufferDelete();
                playBeep();
                mistakeExercise();
                break;
            case 4:
                //pufferDelete();
                playBeep();
                createVocab();
                break;
            case 5:
                //pufferDelete();
                playBeep();
                settings();
                break;
            case 6:
                    //pufferDelete();
                    playBeep();
                    screenWipe();
                    openFileInEditor("");
                break;
            default:
                screenWipe();
                //const InvalidInput2 &invalidInput2 = invalidInputTranslations2[static_cast<int>(programUiLanguage)];

                //logError("mainMenu", invalidInput2.invalidInput2);
                //std::cerr << invalidInput2.invalidInput2 << "\n";
                logError("mainMenu" , "InvalidInput2.invalidInput2");
                //pufferDelete();
                waitToEnter();
        }
    }
}
