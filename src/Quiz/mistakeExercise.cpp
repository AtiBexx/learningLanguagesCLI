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

//bool useColors;

void mistakeExercise() {
    std::string path;
#ifdef _WIN32
    path = "data\\mistakes\\mistakes.data";
#else
    path = "data/mistakes/mistakes.data";
#endif

    const GoodAnswer2& goodAns2 = goodAnswer2Translations[static_cast<int>(programUiLanguage)];
    const GoodAnswer1& goodAns = goodAnswer1Translations[static_cast<int>(programUiLanguage)];
    const BadlyAnswer& badAns = badlyAnswerTranslations[static_cast<int>(programUiLanguage)];
    const MistakeExercise& mistakeExercise = mistakeExerciseTranslations[static_cast<int>(programUiLanguage)];

    // Beolvassuk a hibákat
    // Read the errors
    std::vector<WordPair> mistakeWords = loadWords(path);

    if (mistakeWords.empty()) {
        const HaveNoWords& msg = haveNoWordsTranslations[static_cast<int>(programUiLanguage)];
        screenWipe();
        std::cout << msg.haveNoWords << std::endl;
        waitToEnter();
        return;
    }

    // Itt tároljuk az elrontott hibákat
    // This is where we store the corrupted errors
    std::vector<WordPair> stillMistakes;

    //  Lefuttatjuk a kvízt a hibalistán
    //  Run the quiz on the error list
    for (const WordPair& word : mistakeWords) {
        screenWipe();
        std::cout << mistakeExercise.practiceOfWrongWord << std::endl;
        std::cout << mistakeExercise.word << word.motherLangMeaning << std::endl;
        std::cout << mistakeExercise.answer;

        std::string answer;
        std::getline(std::cin, answer);

        //if (toLowerCase(removePunctuation(trim(answer))) == toLowerCase(removePunctuation(trim(word.targetLangMeaning)))){
        if (cleanString(answer) == cleanString(word.targetLangMeaning)) {
            if (useColors) std::cout << colors::GREEN;
            std::cout << goodAns.goodAnswer1;
            if (useColors) std::cout << colors::RESET;
            waitToEnter();
        } else {
            if (useColors) std::cout << colors::RED;
            std::cout << badAns.badlyAnswer;
            if (useColors) std::cout << colors::RESET;
            std::cout << "\n"<<goodAns2.goodAnswer2 << word.targetLangMeaning << std::endl;
            stillMistakes.push_back(word); // Benne hagyjuk a listában
            waitToEnter();
        }
    }

    // A FÁJL ÚJRAÍRÁSA a megmaradt hibákkal
    // OVERWRITE THE FILE with remaining errors
    std::ofstream outFile(path, std::ios::out | std::ios::trunc);
    if (outFile.is_open()) {
        for (const WordPair& word : stillMistakes) {
            outFile << word.targetLangMeaning << " -> " << word.motherLangMeaning;
            if (!word.pronunciation.empty()) outFile << " [" << word.pronunciation << "]";
            outFile << "\n";
        }
        outFile.close();
    }

    screenWipe();
    std::cout << mistakeExercise.exerciseEnd << stillMistakes.size() << std::endl;
    waitToEnter();
}
