//
// Created by AtiBexx2 on 2026. 04. 04.
//
#include "createVocab.h"
#include <iostream>
#include <fstream>
#include <string>

#include "dataFileReading.h"
#include "generalFunctions.h"
#include "cliFileReading.h"

std::string fileName;

void wordsPairTotal(bool isExiting)
{
    // nyelvi fájlok
    const VocabWordsPairTotal &vwptSTR = vocabWordsPairTotalTranslations[static_cast<int>(programUiLanguage)];
    const EnteringBack &entering_back = continuationToEnterTranslations[static_cast<int>(programUiLanguage)];
    const CreateVocabFile &createVocabFile = createVocabFileTranslations[static_cast<int>(programUiLanguage)];
    // Összegzés
    screenWipe();
    if (isExiting)
    {
        std::cout << createVocabFile.fileSave2 << std::endl;
    }else {
        std::cout << createVocabFile.fileSave << std::endl;
    }

    std::cout << vwptSTR.vocabWordsPairTotal << wordCount << vwptSTR.vocabWordsPairTotal2 << fileName << vwptSTR.vocabWordsPairTotal3 << std::endl;
    std::cout << entering_back.pressToEnter << std::endl;
    std::cin.get();
}

void createVocab()
{
    //nyelvi fájlok
    const CreateVocabFile &createVocabFile = createVocabFileTranslations[static_cast<int>(programUiLanguage)];
    const CreateVocab &createVocab = createVocabTranslations[static_cast<int>(programUiLanguage)];

    //nullázuk a szavak számát
    wordCount = 0;

    //bekérjük a fájl nevét
    std::cout << createVocabFile.inputFileName;
    std::getline(std::cin, fileName);

    //elérési út bekérése
    std::string folderName;
    std::cout << createVocabFile.folderName;
    std::getline(std::cin, folderName);

    if (folderName.empty())
    {
        fullPath = "./data/" + fileName + ".data";
    }
    else
    {
        fullPath = "./data/" + folderName + "/" + fileName + ".data";
    }

    // Ellenőrizzük az útvonalat biztonsági szempontból
    if (!isPathSafe(fullPath))
    {
        std::cerr << createVocabFile.fullPathError << std::endl;
        std::cin.get();
        return;
    }
    // bekérjük a kiválasztott módot
    choiceMenu();
    // Megnyitjuk a fájlt a kiválasztott módban
    std::ofstream outFile(fullPath, mode); // Hozzáfűzés mód
    if (!outFile.is_open()) {
        std::cerr << createVocabFile.fullPathOpenError << std::endl;
        std::cin.get();
        return;
    }

    //itt továbblépünk amig 'exit'-et nem adunk meg
    for (;;)
    {
        // letöröljük a képernyőt
        screenWipe();

        std::cout << createVocab.createVocab << fileName << createVocab.createVocab2
        << wordCount << createVocab.createVocab3 << std::endl;
        std::cout << createVocab.createVocab4 << std::endl;

        // std::string englishWords, hungarianWords, pronunciation;
        //Bekérjük a használt strukturát nem írunk újat
        WordPair currentWords;
        //Bekérjük az angol mondatot vagy szót
        std::cout << createVocab.createVocab5;
        std::getline(std::cin, currentWords.targetLangMeaning);

        // Kilépés kezelése
        if (currentWords.targetLangMeaning == "exit")
        {
            outFile.flush();// Kényszerített mentés lemezre
            wordsPairTotal(true);
            break;
        }

        // Csak mentés kezelése
        if (currentWords.targetLangMeaning == "save") {
            outFile.flush(); // Kényszerített mentés lemezre
            wordsPairTotal(false);
            continue;
        }

        if (currentWords.targetLangMeaning.empty()) continue;

        std::cout << createVocab.createVocab6;
        std::getline(std::cin, currentWords.motherLangMeaning);

        std::cout << createVocab.createVocab7;
        std::getline(std::cin, currentWords.pronunciation);

        // Fájlba mentés formázva
        outFile << trim(currentWords.targetLangMeaning) << " -> " << trim(currentWords.motherLangMeaning);
        if (!trim(currentWords.pronunciation).empty()) {
            outFile << " [" << trim(currentWords.pronunciation) << "]";
        }
        outFile << "\n";

        // Hozzáadjuk a szavak számát a wordCount változóba
        wordCount++;
    }

    // Bezárjuk a fájlt és mentünk
    outFile.close();

    // Összegzés
    //wordsPairTotal(); nem kell mert az 'exit'és a 'save' kezeli...
}


