//
// Created by AtiBexx2 on 2026. 04. 12.
//

#include "programQuiz.h"
#include "../FileIO/dataFileReading.h"
#include "../Translate/translations.h"
#include "../Common/generalFunctions.h"
#include "../Settings/colors.h"
#include <iostream>
#include <vector>
#include <fstream>

extern bool useColors;

void mistakeExercise() {
    std::string path;
#ifdef _WIN32
    path = "data\\mistakes\\mistakes.data";
#else
    path = "data/mistakes/mistakes.data";
#endif

    const EnteringBack& back = enteringBackTranslations[static_cast<int>(currentLanguage)];
    const GoodAnswer1& goodAns = goodAnswer1Translations[static_cast<int>(currentLanguage)];
    const BadlyAnswer& badAns = badlyAnswerTranslations[static_cast<int>(currentLanguage)];

    // 1. Beolvassuk a hibákat
    std::vector<WordPair> mistakeWords = loadwords(path);

    if (mistakeWords.empty()) {
        const HaveNoWords& msg = haveNoWordsTranslations[static_cast<int>(currentLanguage)];
        screenWipe();
        std::cout << msg.haveNoWords << std::endl;
        std::cout << back.enteringBack << std::endl;
        std::cin.get();
        return;
    }

    // 2. Itt fogjuk tárolni azokat, amiket MOST is elrontasz
    std::vector<WordPair> stillMistakes;

    // 3. Lefuttatjuk a kvízt a hibalistán
    for (const auto& word : mistakeWords) {
        screenWipe();
        std::cout << "--- HIBÁS SZAVAK GYAKORLÁSA ---" << std::endl;
        std::cout << "Szo: " << word.hungarian << std::endl;
        std::cout << "Valasz: ";

        std::string answer;
        std::getline(std::cin, answer);

        if (toLowerCase(trim(answer)) == toLowerCase(word.english)) {
            if (useColors) std::cout << colors::GREEN;
            std::cout << goodAns.goodAnswer1;
            if (useColors) std::cout << colors::RESET;
            std::cout << "\n" << back.enteringBack << std::endl;
            std::cin.get();
        } else {
            if (useColors) std::cout << colors::RED;
            std::cout << badAns.badlyAnswer;
            if (useColors) std::cout << colors::RESET;
            std::cout << "\nA helyes: " << word.english << std::endl;
            stillMistakes.push_back(word); // Benne hagyjuk a listában
            std::cout << back.enteringBack << std::endl;
            std::cin.get();
        }
    }

    // 4. A FÁJL ÚJRAÍRÁSA a megmaradt hibákkal
    std::ofstream outFile(path, std::ios::out | std::ios::trunc);
    if (outFile.is_open()) {
        for (const auto& word : stillMistakes) {
            outFile << word.english << " -> " << word.hungarian;
            if (!word.pronunciation.empty()) outFile << " [" << word.pronunciation << "]";
            outFile << "\n";
        }
        outFile.close();
    }

    screenWipe();
    std::cout << "A gyakorlas veget ert! Megmaradt hibak szama: " << stillMistakes.size() << std::endl;
    std::cout << back.enteringBack << std::endl;
    std::cin.get();
}
