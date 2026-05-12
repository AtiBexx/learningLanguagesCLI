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
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "translations.h"
#include "cliFileReading.h"
#include <fstream>
#include "createVocab.h"
#include "osEditor.h"
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
        std::cout << menuStrs.Editor << "\n";
        std::cout << menuStrs.exit << "\n";
        std::cout << menuStrs.signs << "\n";

        int choice = 0;
        // nyelvi fájlok || language files 
        const NumberOutput &numStrs = chooseNumberMenuTranslations[static_cast<int>(programUiLanguage)];
        std::cout << numStrs.numberOutput << std::flush;

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
        }

        switch (choice) {
            case 0:
                 playBeep();
                 exiting();
                 return;
            case 1:
                pufferDelete();
                playBeep();
                explanation();
                break;
            case 2:
                pufferDelete();
                playBeep();
                listAndSelectFile();
                break;
            case 3:
                pufferDelete();
                playBeep();
                mistakeExercise();
                break;
            case 4:
                pufferDelete();
                playBeep();
                createVocab();
                break;
            case 5:
                pufferDelete();
                playBeep();
                settings();
                break;
            case 6:
                    pufferDelete();
                    playBeep();
                    screenWipe();
                    openFileInEditor("");
                break;
            default:
                screenWipe();
                const InvalidInput2 &invalidInput2 = invalidInputTranslations2[static_cast<int>(programUiLanguage)];

                logError("mainMenu", invalidInput2.invalidInput2);
                std::cerr << invalidInput2.invalidInput2 << "\n";

                pufferDelete();
                waitToEnter();
        }
    }
}
```

#### Puffer tőrlése függvényben 

```
// Letöröljük a bent maradt puffert ha szükséges
// Clear the remaining buffer if necessary it
void pufferDelete() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
```

