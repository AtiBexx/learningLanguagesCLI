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

#include "settings.h"
#include "newInput/platformInput.h"

//bool useColors;

void mistakeExercise()
{
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
    const QuizExplanation &quizExplanation = quizExplanationTranslations[static_cast<int>(programUiLanguage)];

    loadSettings();
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

    bool realExit = false;

    // Betöltjük a folytatási indexet
    // Load the continuation index

    if (resumeIndex>= mistakeWords.size()) { // Ha az index túl nagy, nullázzuk
        resumeIndex = 0;
    }

    //  Lefuttatjuk a kvízt a hibalistán
    //  Run the quiz on the error list
    for (size_t i = resumeIndex; i < mistakeWords.size() && !realExit; ++i){
        const WordPair& word = mistakeWords[i]; // Az aktuális szó || The current word
        for (;;) {
            screenWipe();
            std::cout << quizExplanation.quizExplanation1 << std::endl;
            std::cout << quizExplanation.quizExplanation2 << std::endl;
            std::cout << quizExplanation.quizExplanation3 << std::endl;

            std::cout << mistakeExercise.practiceOfWrongWord << std::endl;
            std::cout << mistakeExercise.word << word.motherLangMeaning << std::endl;
            std::cout << mistakeExercise.answer;

            // Ha be van kapcsolva a súgó, akkor itt kiírjuk
            if (showHelp) {
                std::cout << "CheatSheet: " << colors::GREY << word.targetLangMeaning << colors::RESET << std::endl;
            }

            InputResult inputResult = readLineWithHotkey(mistakeExercise.answer);

            // Ha hotkey volt (Ctrl+Y)
            if (inputResult.hotkeyTriggered) {
                showHelp = !showHelp; // Toggle a súgót
                if (showHelp) helperUsed = true;
                saveSettings();
                continue; // Újraindul a kör az új súgó állapottal
            }

            std::string answer = inputResult.text; // A tényleges válasz
            std::string lowerAnswer = toLowerCase(trim(answer));

            if (lowerAnswer == "exit" || lowerAnswer == "e" || inputResult.exitTriggered)
            {
                stillMistakes.push_back(word);

                // Az összes hátralévő szót is hozzáadjuk a hibákhoz
                for (size_t j = i + 1; j < mistakeWords.size(); ++j) {
                    stillMistakes.push_back(mistakeWords[j]);
                }
                resumeIndex = i; // Mentjük az aktuális indexet
                realExit = true;
                break;
            }

            if (lowerAnswer == "h" || lowerAnswer == "help") {
                showHelp = true;
                helperUsed = true;
                saveSettings();
                continue;
            }
            if (lowerAnswer == "h off" || lowerAnswer == "help off") {
                showHelp = false;
                helperUsed = false;
                saveSettings();
                continue;
            }

            //if (toLowerCase(removePunctuation(trim(answer))) == toLowerCase(removePunctuation(trim(word.targetLangMeaning)))){
            if (cleanString(answer) == cleanString(word.targetLangMeaning)) {
                if (useColors) std::cout << colors::GREEN;
                std::cout << goodAns.goodAnswer1;
                if (useColors) std::cout << colors::RESET;
                waitToEnter();
                break;
            } else {
                if (useColors) std::cout << colors::RED;
                std::cout << badAns.badlyAnswer;
                if (useColors) std::cout << colors::RESET;
                std::cout << "\n"<<goodAns2.goodAnswer2 << word.targetLangMeaning << std::endl;
                stillMistakes.push_back(word); // Benne hagyjuk a listában
                waitToEnter();
            }
        }
    }
    /*if (realExit)
    {
        return;
    }*/

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
    saveSettings();
    waitToEnter();
}
