```
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


void mistakeExercise()
{
    std::string path;
#ifdef _WIN32
    path = "data\\mistakes\\mistakes.data";
#else
    path = "data/mistakes/mistakes.data";
#endif

    loadSettings();
    // Beolvassuk a hibákat
    // Read the errors
    std::vector<WordPair> mistakeWords = loadWords(path);

    if (mistakeWords.empty()) {
        screenWipe();
        std::cout << getTranslation("HaveNoWords.haveNoWords") <<"\n" << std::flush;

        waitToEnter();
        return;
    }

    // Itt tároljuk az elrontott hibákat
    // This is where we store the corrupted errors
    std::vector<WordPair> stillMistakes;

    bool realExit = false;

    // Betöltjük a folytatási indexet
    // Load the continuation index

    if (resumeIndex>= mistakeWords.size()) { // Ha az index túl nagy, nullázzuk || If the index is too big, set it to 0
        resumeIndex = 0;
    }

    //  Lefuttatjuk a kvízt a hibalistán
    //  Run the quiz on the error list
    for (size_t i = resumeIndex; i < mistakeWords.size() && !realExit; ++i){
        const WordPair& word = mistakeWords[i]; // Az aktuális szó || The current word
        for (;;) {
            screenWipe();
            std::cout << getTranslation("QuizExplanation.quizExplanation1") << "\n" << std::flush;
            std::cout << getTranslation("QuizExplanation.quizExplanation2") << "\n" << std::flush;
            std::cout << getTranslation("QuizExplanation.quizExplanation3") << "\n" << std::flush;
            std::cout << getTranslation("MistakeExercise.practiceOfWrongWord") << "\n" << std::flush;
            std::cout << getTranslation("MistakeExercise.word") << word.motherLangMeaning << "\n" << std::flush;
            std::cout << getTranslation("MistakeExercise.answer");


            // Ha be van kapcsolva a súgó, akkor itt kiírjuk || If help is turned on, it will be displayed here
            if (showHelp) {
                std::cout << "CheatSheet: " << colors::GREY << word.targetLangMeaning << colors::RESET << std::endl;
            }

            InputResult inputResult = readLineWithHotkey(getTranslation("MistakeExercise.answer"));

            // Ha hotkey volt (Ctrl+Y) || If a hotkey was triggered (Ctrl+Y)
            if (inputResult.hotkeyTriggered) {
                showHelp = !showHelp; // Toggle a súgót
                if (showHelp) helperUsed = true;
                saveSettings();
                continue; // Újraindul a kör az új súgó állapottal || The round restarts with the new help status
            }

            std::string answer = inputResult.text; // A tényleges válasz || The actual answer
            std::string lowerAnswer = toLowerCase(trim(answer));

            if (lowerAnswer == "exit" || lowerAnswer == "e" || inputResult.exitTriggered)
            {
                stillMistakes.push_back(word);

                // Az összes hátralévő szót is hozzáadjuk a hibákhoz
                // Add all remaining words to the mistakes
                for (size_t j = i + 1; j < mistakeWords.size(); ++j) {
                    stillMistakes.push_back(mistakeWords[j]);
                }
                resumeIndex = i; // Mentjük az aktuális indexet || Save the current index
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

            if (cleanString(answer) == cleanString(word.targetLangMeaning)) {
                if (useColors) std::cout << colors::GREEN;
                std::cout << getTranslation("GoodAnswer1.goodAnswer1");
                
                if (useColors) std::cout << colors::RESET;
                waitToEnter();
                break;
            } else {
                if (useColors) std::cout << colors::RED;
                std::cout << getTranslation("BadlyAnswer.badlyAnswer");
                
                if (useColors) std::cout << colors::RESET;
                std::cout << "\n"<<getTranslation("GoodAnswer2.goodAnswer2") << word.targetLangMeaning << "\n" << std::flush;

                stillMistakes.push_back(word); // Benne hagyjuk a listában || Let's leave it on the list.
                waitToEnter();
            }
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
    std::cout << getTranslation("MistakeExercise.exerciseEnd") << stillMistakes.size() << "\n" << std::flush;
    saveSettings();
    waitToEnter();
}
```

