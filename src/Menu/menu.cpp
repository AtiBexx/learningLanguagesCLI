/**
* @page menu_doc Main Menu System
 *
 * EN:
 * This page describes the main menu system of the application.
 * It handles user navigation, input processing, and module selection.
 *
 * HU:
 * Ez az oldal az alkalmazás főmenü rendszerét írja le.
 * Kezeli a navigációt, a bemenet feldolgozását és a modulválasztást.
 *
 * @details
 * EN:
 * The menu system is responsible for:
 * - displaying menu options
 * - reading user input
 * - switching between modules (settings, quiz, editor, etc.)
 *
 * HU:
 * A menürendszer feladata:
 * - menüpontok megjelenítése
 * - felhasználói input kezelése
 * - modulok közötti váltás (beállítások, kvíz, szerkesztő stb.)
 *
 * @code{.cpp}
 * mainMenu();
 * @endcode
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
        int width = getTerminalWidth();

        printWrapped(getTranslation("MenuStrings.titleAndSigns") + "\n\n" , width);
        printWrapped(getTranslation("MenuStrings.programExplanation") + "\n", width);
        printWrapped(getTranslation("MenuStrings.startProgram") + "\n", width);
        printWrapped(getTranslation("MenuStrings.mistakeExercise") +"\n", width);
        printWrapped(getTranslation("MenuStrings.newFile") + "\n", width);
        printWrapped(getTranslation("MenuStrings.settings") + "\n", width);
        printWrapped(getTranslation("MenuStrings.Editor") + "\n", width);
        printWrapped(getTranslation("MenuStrings.exit") + "\n\n", width);
        printWrapped(getTranslation("MenuStrings.signs") + "\n", width);

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
            size_t pos = 0;
            choice = std::stoi(inputStr, &pos);
            if (pos != inputStr.size())
            {
                screenWipe();
                logError("mainMenu", getTranslation("InvalidInput2.invalidInput"));
                throw std::invalid_argument(getTranslation("InvalidInput.invalidInput") + "\n\n");

            }
        } catch (...)
        {
            screenWipe();

            logError("mainMenu", getTranslation("InvalidInput.invalidInput"));
            std::cerr << getTranslation("InvalidInput.invalidInput") << "\n\n";
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
                std::cerr << getTranslation("InvalidInput2.invalidInput2") << "\n\n";
                waitToEnter();
        }
    }
}
