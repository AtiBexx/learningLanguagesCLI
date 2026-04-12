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


Language currentLanguage = Language::HUNGARIAN;

void menu() {
    for (;;) {
        screenWipe();
        const MenuStrings &menuStrs = menuTranslations[static_cast<int>(currentLanguage)];

        std::cout << menuStrs.title << std::endl;
        std::cout << menuStrs.programExplanation << std::endl;
        std::cout << menuStrs.startProgram << std::endl;
        std::cout << menuStrs.mistakeExecise << std::endl;
        std::cout << menuStrs.newFile << std::endl;
        std::cout << menuStrs.settings << std::endl;
        std::cout << menuStrs.exit << std::endl;
        std::cout << menuStrs.signs << std::endl;

        choice = 5;
        const NumberOutput &numStrs = numberOutputTranslations[static_cast<int>(currentLanguage)];
        std::cout << numStrs.numberOutput;

        if (!(std::cin >> choice)) {
            screenWipe();
            const InvalidInput &invalidinput = invalidInputTranslations[static_cast<int>(currentLanguage)];
            const EnteringBack &enteringback = enteringBackTranslations[static_cast<int>(currentLanguage)];

            std::cin.clear();
            pufferDelete();

            std::cout << invalidinput.invalidInput << std::endl;
            std::cout << enteringback.enteringBack << std::endl;
            std::cin.get();
            continue;
        }

        switch (choice) {
            case 0:
                explanation();
                break;
            case 1:
                screenWipe();
                listAndSelectFile();
                break;
            case 2:
                mistakeExercise();
                break;
            case 3:
                createVocab();
                break;
            case 4:
                settings();
                break;
            case 5:
                exiting();
                return;
            default:
                screenWipe();
                const InvalidInput2 &invalidinput2 = invalidInputTranslations2[static_cast<int>(currentLanguage)];
                const EnteringBack &enteringback = enteringBackTranslations[static_cast<int>(currentLanguage)];
                std::cout << invalidinput2.invalidInput2 << std::endl;

                pufferDelete();//szükséges

                std::cout << enteringback.enteringBack << std::endl;
                std::cin.get();
        }
    }
}
