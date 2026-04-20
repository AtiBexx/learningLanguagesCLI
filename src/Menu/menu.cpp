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

        std::cout << menuStrs.titleAndSigns << std::endl;
        std::cout << menuStrs.programExplanation << std::endl;
        std::cout << menuStrs.startProgram << std::endl;
        std::cout << menuStrs.mistakeExercise << std::endl;
        std::cout << menuStrs.newFile << std::endl;
        std::cout << menuStrs.settings << std::endl;
        std::cout << menuStrs.exit << std::endl;
        std::cout << menuStrs.signs << std::endl;

        choice = 5;
        const NumberOutput &numStrs = chooseNumberMenuTranslations[static_cast<int>(programUiLanguage)];
        std::cout << numStrs.numberOutput;

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
            pufferDelete();
                explanation();
                break;
            case 1:
                pufferDelete();
                listAndSelectFile();
                break;
            case 2:
                pufferDelete();
                mistakeExercise();
                break;
            case 3:
                pufferDelete();
                createVocab();
                break;
            case 4:
                pufferDelete();
                settings();
                break;
            case 5:
                exiting();
                return;
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
