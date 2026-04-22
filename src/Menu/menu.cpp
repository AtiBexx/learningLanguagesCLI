//
// Created by AtiBexx2 on 2026. 04. 04.
//
#include "menu.h"

#include "Common/generalFunctions.h"
#include "Quiz/programQuiz.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "translations.h"
#include "cliFileReading.h"
#include <fstream>
#include "createVocab.h"
#include "Settings/settings.h"


void mainMenu() {
    for (;;) {
        screenWipe();
        const MenuStrings &menuStrs = mainMenuTranslations[static_cast<int>(programUiLanguage)];

        std::cout << menuStrs.titleAndSigns <<"\n";
        std::cout << menuStrs.programExplanation << "\n";
        std::cout << menuStrs.startProgram << "\n";
        std::cout << menuStrs.mistakeExercise << "\n";
        std::cout << menuStrs.newFile << "\n";
        std::cout << menuStrs.settings << "\n";
        std::cout << menuStrs.exit << "\n";
        std::cout << menuStrs.signs << "\n";

        choice = 5;
        const NumberOutput &numStrs = chooseNumberMenuTranslations[static_cast<int>(programUiLanguage)];
        std::cout << numStrs.numberOutput << std::flush;

        // ha a cin nem szám
        // if cin is not a number
        if (!(std::cin >> choice)) {
            screenWipe();

            // Load error messages
            // Betöltjük az hibaüzeneteket
            const InvalidInput &invalidinput = invalidInputTranslations[static_cast<int>(programUiLanguage)];

            // Clear input buffer
            // Megtisztitjuk a bemeneti buffert
            std::cin.clear();
            pufferDelete();

            logError("mainMenu", invalidinput.invalidInput);
            std::cerr << invalidinput.invalidInput <<"\n";
            waitToEnter();
            continue;
        }

        switch (choice) {
            case 0:
                 playBeep();
                 exiting();
                 return;
            case 1:
                pufferDelete();
                explanation();
                break;
            case 2:
                pufferDelete();
                listAndSelectFile();
                break;
            case 3:
                pufferDelete();
                mistakeExercise();
                break;
            case 4:
                pufferDelete();
                createVocab();
                break;
            case 5:
                pufferDelete();
                settings();
                break;
            case 6:
                pufferDelete();
                void openFileInEditor(); //TODO
                break;
            default:
                screenWipe();
                const InvalidInput2 &invalidinput2 = invalidInputTranslations2[static_cast<int>(programUiLanguage)];

                logError("mainMenu", invalidinput2.invalidInput2);
                std::cerr << invalidinput2.invalidInput2 << "\n";

                pufferDelete();
                waitToEnter();
        }
    }
}
