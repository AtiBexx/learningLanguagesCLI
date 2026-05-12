```
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

        std::cout << getTranslation("MenuStrings.titleAndSigns") << "\n\n";
        std::cout << getTranslation("MenuStrings.programExplanation") << "\n";
        std::cout << getTranslation("MenuStrings.startProgram") << "\n";
        std::cout << getTranslation("MenuStrings.mistakeExercise") << "\n";
        std::cout << getTranslation("MenuStrings.newFile") << "\n";
        std::cout << getTranslation("MenuStrings.settings") << "\n";
        std::cout << getTranslation("MenuStrings.Editor") << "\n";
        std::cout << getTranslation("MenuStrings.exit") << "\n\n";
        std::cout << getTranslation("MenuStrings.signs") << "\n";

        int choice = 0;

        // Az Input beolvasása || Read Input
        InputResult inputResult = readLineWithHotkey(getTranslation("NumberOutput.numberOutput"));

        // -----CTRL + C Kezelése || CTRL + C Handling
        if (inputResult.exitTriggered)
        {
            playBeep();
            exiting();
            return; // Kilépünk az egész programból || We are exiting the entire program.
        }

        std::string inputStr = inputResult.text;
        std::string lowerInput = toLowerCase(trim(inputStr));

        // --- "exit" vagy "e" parancs kezelése || "exit" or "e" command handling ---
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

            logError("mainMenu", getTranslation("InvalidInput.invalidInput"));
            std::cerr << getTranslation("InvalidInput.invalidInput") << "\n";
            //std::cerr << invalidinput.invalidInput <<"\n";
            waitToEnter();
            continue;
        }

        switch (choice) {
            case 0:
                 playBeep();
                 exiting();
                 return;
            case 1:
                playBeep();
                explanation();
                break;
            case 2:
                playBeep();
                listAndSelectFile();
                break;
            case 3:
                playBeep();
                mistakeExercise();
                break;
            case 4:
                playBeep();
                createVocab();
                break;
            case 5:
                playBeep();
                settings();
                break;
            case 6:
                    playBeep();
                    screenWipe();
                    openFileInEditor("");
                break;
            default:
                screenWipe();

                logError("mainMenu" , "InvalidInput2.invalidInput2");
                std::cerr << getTranslation("InvalidInput2.invalidInput2") << "\n";
                waitToEnter();
        }
    }
}
```

ITT  A pufferDelete(); függvény nem kell....

