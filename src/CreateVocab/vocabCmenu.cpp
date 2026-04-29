/**
* @file vocabCmenu.cpp
 * @brief Handles file open mode selection and existing vocabulary logic.
 * @brief Fájl megnyitási mód kiválasztása és meglévő szótár kezelése.
 *
 * @details
 * EN:
 * This module manages how a vocabulary file is opened depending on whether
 * it already contains data. It allows the user to:
 * - Append to existing file
 * - Overwrite existing file
 * - Exit operation
 *
 * It also initializes the word counter based on the selected mode and
 * existing file content.
 *
 * HU:
 * Ez a modul kezeli, hogy egy szótár fájl milyen módban legyen megnyitva,
 * attól függően, hogy tartalmaz-e már adatot. A felhasználó:
 * - Hozzáfűzhet a meglévő fájlhoz
 * - Felülírhatja a fájlt
 * - Kiléphet a műveletből
 *
 * Emellett beállítja a szavak számát a kiválasztott mód és a meglévő
 * tartalom alapján.
 *
 * @author AtiBexx2
 * @date 2026-04-06
 */

#include "createVocab.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "dataFileReading.h"
#include "generalFunctions.h"


// Itt definiáljuk a globális változókat, amik a .h-ban extern-ként vannak
std::ios_base::openmode mode;
std::string fullPath;
unsigned long long wordCount = 0;


bool choiceMenu()
{
    // nyelvi fájlok
    const VocabMenu &vocabMenu = vocabMenuTranslations[static_cast<int>(programUiLanguage)];

    // létező szavak vizsgálata
    std::vector<WordPair> existingWords = loadWords(fullPath);
    mode = std::ios::app; // Alapértelmezett


    if (!existingWords.empty())
    {
        int choice = 0;
        while (true) {
            screenWipe();
            std::cout << vocabMenu.vocabMenu1 << existingWords.size() << vocabMenu.vocabMenu2 << std::endl;
            std::cout << vocabMenu.vocabMenu3 ;

            std::string inputCh;
            std::getline(std::cin, inputCh);

            try {
                choice = std::stoi(inputCh);
                if (choice >= 1 && choice <= 3)
                {
                    break;
                }
                else {
                    screenWipe();
                    std::cerr << vocabMenu.vocabError1<<"\n";
                    waitToEnter();
                }
            } catch (...) {
                screenWipe();
                std::cerr << vocabMenu.vocabError2 << "\n";
                waitToEnter();
                continue;
            }
        }
    // Itt lesznek az if elágazások ha while ciklus nem talált hibát ide ugrik
    // This is where the if branches will be, if the while loop does not find an error it will jump here
        if (choice == 1)
        {
            mode = std::ios::app;
            wordCount = existingWords.size();

            // --- BÓNUSZ: Tartalom kilistázása ---
            // BONUS: Display content
            std::cout << "\n--- Jelenlegi tartalom ---\n";
            for (const auto& w : existingWords) {
                std::cout << "  " << w.targetLangMeaning << " -> " << w.motherLangMeaning << "\n";
            }

        } else if (choice == 2) {
            mode = std::ios::out | std::ios::trunc;
            wordCount = 0;

            // ha a választás 3-as(choice == 3)
            // a while ciklus miatt nem írjuk ki a 3-at mert egyértelmű
        } else {
            return false;
        }
    }
    // ha a fájl nem létezik létrehozuk
    else
    {
        wordCount = 0;
        mode = std::ios::out;
    }
    return true;
}
