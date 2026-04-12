//
// Created by AtiBexx2 on 2026. 04. 06.
//

#include "createVocab.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "dataFileReading.h"
#include "generalFunctions.h"
#include "Menu/menu.h"

// Itt definiáljuk a globális változókat, amik a .h-ban extern-ként vannak
std::ios_base::openmode mode;
int choice = 0;
std::string fullPath;
unsigned long long wordCount = 0;


void choiceMenu()
{
    // nyelvi fájlok
    const VocabMenu &vocabMenu = vocabMenuTranslations[static_cast<int>(currentLanguage)];

    // létező szavak viszgálata
    std::vector<WordPair> existingWords = loadwords(fullPath);
    mode = std::ios::app; // Alapértelmezett
    choice = 0;

    if (!existingWords.empty())
    {
        while (choice < 1 || choice > 3) {
            screenWipe();
            std::cout << vocabMenu.vocabMenu1 << existingWords.size() << vocabMenu.vocabMenu2 << std::endl;
            std::cout << vocabMenu.vocabMenu3 ;

            std::string inputCh;
            std::getline(std::cin, inputCh);

            try {
                choice = std::stoi(inputCh);
                if (choice < 1 || choice > 3) {
                    screenWipe();
                    std::cerr << vocabMenu.vocabError1<<"\n";
                    std::cin.get();
                }
            } catch (...) {
                screenWipe();
                std::cerr << vocabMenu.vocabError2 << "\n";
                choice = 0;
                std::cin.get();
            }
        }
    // Itt lesznek az if elágazások ha while ciklus nem talált hibát ide ugrik
        if (choice == 1) {
            mode = std::ios::app;
            wordCount = existingWords.size();
        } else if (choice == 2) {
            mode = std::ios::out | std::ios::trunc;
            wordCount = 0;

            // ha a választás 3-as(choice == 3)
            // a while ciklus miatt nem írjuk ki a 3-at mert egyértelmű
        } else {
            return; // ha 3-at adunk meg kilépünk
        }
    }
    // ha a fájl nem létezik létrehozuk
    else
    {
        wordCount = 0;
        mode = std::ios::out;
    }
}
