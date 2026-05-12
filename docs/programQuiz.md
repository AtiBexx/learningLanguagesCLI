```
//
// Created by AtiBexx2 on 2026. 03. 24.
//

#include "programQuiz.h"
#include "../FileIO/dataFileReading.h"
#include "../Translate/translations.h"
#include <iostream>
#include <string>
#include <vector>

#include "../Common/generalFunctions.h"
#include "newInput/platformInput.h"
#include "Settings/colors.h"
#include "Settings/settings.h"
#include "Settings/languageList.h"

void scoreSystem(int correct, int badly, unsigned long long total) {

    double percentAge = (total > 0) ? (static_cast<double>(correct) / static_cast<double>(total)) * 100.0 : 0.0;

    //Részletes pontszámstatisztikák megjelenítése
    //Show detailed score statistics
    std:: cout << getTranslation("ScoreSys.total") <<"\n" << std::flush;
    std:: cout << getTranslation("ScoreSys.allQuestion") << total <<"\n" << std::flush;
    std:: cout << getTranslation("ScoreSys.correct") << correct <<"\n" << std::flush;
    std:: cout << getTranslation("ScoreSys.badly") << badly <<"\n" << std::flush;
    std:: cout << getTranslation("ScoreSys.percent") << percentAge << "%" <<"\n" << std::flush;

    //Végső értékelő üzenet megjelenítése a százalékos arány alapján
    //Display final evaluation message based on percentage
    if (percentAge >= 99.9) {
        std::cout << getTranslation("PercentAge.percentAge100") <<"\n" << std::flush;

    } else if (percentAge >= 80.0 ) {
        std::cout << getTranslation("PercentAge.percentAge80") <<"\n" << std::flush;

    } else {
        std::cout << getTranslation("PercentAge.percentAgeElse") <<"\n" << std::flush;

    }
}

//Quiz kérdezős logika
//Quiz question logic
void startQuiz (const std::vector<WordPair>& words)
{

    loadSettings();
    // Ha üres a fájl
    // If file is empty
    if (words.empty()) {
        screenWipe();
        std::cout << getTranslation("HaveNoWords.haveNoWords") <<"\n" << std::flush;
        waitToEnter();
        return;
    }

    int badlyAnswers = 0;
    int firstTryCorrect = 0;
    unsigned long long totalQuestions;
    if (oneRoundQuiz) {
        totalQuestions = words.size();
    } else {
        totalQuestions = words.size() * 2;
    }

    for (const WordPair& word : words)
    {
        bool mistakeMade = false;

        // 1. KÖR: Magyar -> Angol kérdezés vagy ami az anyanyelved
        // ROUND 1: Hungarian -> English question or whatever your native language is
        for (;;) {
            screenWipe();
            std::cout <<getTranslation("QuizExplanation.quizExplanation1") << "\n" << std::flush;
            std::cout <<getTranslation("QuizExplanation.quizExplanation2") << "\n" << std::flush;
            std::cout <<getTranslation("QuizExplanation.quizExplanation3") << "\n" << std::flush;
            std::cout << getLanguageNameByIndex(programUiLanguage, motherLanguage) << ": " << word.motherLangMeaning << "\n" << std::flush;

            // A súgó be van kapcsolva , akkor itt kiírjuk
            if (showHelp) {
                std::cout << "CheatSheet: " << colors::GREY << word.targetLangMeaning << colors::RESET << std::endl;
            }
            // Használjuk a bilentyűzetfigyelő függvényt
            // Use the keyboard input checker function
            InputResult inputResult = readLineWithHotkey(getLanguageNameByIndex(programUiLanguage, targetLanguage) + ": ");

            // ha, a hotkey volt (Ctrl+Y)
            // if was hotkey (Ctrl + Y)
            if (inputResult.hotkeyTriggered)
            {
                showHelp = !showHelp;
                if (showHelp) helperUsed = true;
                saveSettings();
                continue;
            }

            std::string answer = inputResult.text;// A válasz || The Answer
            std::string lowerAnswer = toLowerCase(trim(answer));


            if (lowerAnswer == "exit" || lowerAnswer == "e" || inputResult.exitTriggered) return;

            // TOGGLE SÚGÓ BEKAPCSOLÁS
            // TOGGLE HELP ENABLE
            if (lowerAnswer == "h" || lowerAnswer == "help") {
                showHelp = true;
                helperUsed = true;
                saveSettings();
                continue; // Újraindul a kör, és mivel showHelp=true, kiírja a súgót
            }
            // TOGGLE SÚGÓ KIKAPCSOLÁS
            // TOGGLE HELP OFF
            if (lowerAnswer == "h off" || lowerAnswer == "help off") {
                showHelp = false;
                helperUsed = false;
                saveSettings();
                continue; // Újraindul a kör, és már nem írja ki
            }

            if (cleanString(answer) == cleanString(word.targetLangMeaning)) {
                //kiíratás színe(Helyesválasz)
                //printout color(Correct answer)
                if (useColors == true)
                {
                    std::cout << colors::GREEN;
                    std::cout << "\n" << getTranslation("GoodAnswer1.goodAnswer1");

                    std::cout << colors::RESET; //visszaállítjuk a színét || restore the color
                } else
                {
                    std::cout << "\n" << getTranslation("GoodAnswer1.goodAnswer1");
                }
                if (!word.pronunciation.empty()) {
                    std::cout << " " << getTranslation("PronunciationString.pronunciation2str") <<"[" << word.pronunciation << "]";
                }
                std::cout << std::endl;

                if (!mistakeMade) {
                    firstTryCorrect++;
                }

                waitToEnter();
                break;
            } else {
                if (!mistakeMade) {
                    badlyAnswers++;
                    logMistakeWriteFile(word); // Elmentjük a hibát az első rontásnál || save the error at the first crash
                }
                mistakeMade = true;

                //Helytelen válasz színe
                //csak a helytelen válasz írjuk ki pirosal ha true az useColors
                //Incorrect answer color
                //only print incorrect answers in red if useColors is true
                if (useColors) std::cout << colors::RED;
                std::cout << "\n" << getTranslation("BadlyAnswer.badlyAnswer") << "\n" << std::flush;

                if (useColors) std::cout << colors::RESET;
                std::cout << "\n" << getTranslation("GoodAnswer2.goodAnswer2") << " " << word.targetLangMeaning << "\n" << std::flush;

                std::cout << "\n" << getTranslation("ReTry.reTry");
                std::cin.get();
            }
        }

        mistakeMade = false;

        // 2. KÖR: Angol -> Magyar kérdezés vagy ami a célnyel
        // 2ND ROUND: English -> Hungarian questioning or anything related to the target language
        if (!oneRoundQuiz) {
            for (;;) {
                screenWipe();

                std::cout << getTranslation("QuizExplanation.quizExplanation1") << "\n" << std::flush;
                std::cout << getTranslation("QuizExplanation.quizExplanation2") << "\n" << std::flush;
                std::cout << getTranslation("QuizExplanation.quizExplanation3") << "\n" << std::flush;

                std::cout << getLanguageNameByIndex(programUiLanguage, targetLanguage) << ": " << word.targetLangMeaning << std::endl;

                // A súgó be van kapcsolva , akkor itt kiírjuk || If help is turned on, it will be displayed here
                if (showHelp) {
                    std::cout << "CheatSheet: " << colors::GREY << word.motherLangMeaning << colors::RESET << std::endl;
                }

                InputResult inputResult = readLineWithHotkey(getLanguageNameByIndex(programUiLanguage, motherLanguage) + ": ");

                // Ha hotkey volt (Ctrl+Y)
                if (inputResult.hotkeyTriggered) {
                    showHelp = !showHelp; // Toggle a súgót
                    if (showHelp) helperUsed = true;
                    saveSettings();
                    continue; // Újraindul a kör az új súgó állapottal || The round restarts with the new help status
                }

                std::string answer = inputResult.text; // A válasz || The Answer
                std::string lowerAnswer = toLowerCase(trim(answer));


                if (lowerAnswer == "exit" || lowerAnswer == "e" || inputResult.exitTriggered) return;

                // TOGGLE SÚGÓ BEKAPCSOLÁS
                // TOGGLE HELP ENABLE
                if (lowerAnswer == "h" || lowerAnswer == "help") {
                    showHelp = true;
                    helperUsed = true;
                    saveSettings();
                    continue;
                }
                // TOGGLE SÚGÓ KIKAPCSOLÁS
                // TOGGLE HELP DISABLE
                if (lowerAnswer == "h off" || lowerAnswer == "help off") {
                    showHelp = false;
                    helperUsed = false;
                    saveSettings();
                    continue;
                }

                if (checkMultipleAnswers(answer, word.motherLangMeaning)) {
                    // a helyes válasz színe ha az useColor == true
                    // the color of the correct answer if useColor == true

                    if (useColors) std::cout << colors::GREEN;
                    std::cout << "\n" << getTranslation ("GoodAnswer1.goodAnswer1");
                    if (useColors) std::cout << colors::RESET;

                    if (!word.pronunciation.empty()) {
                        std::cout << " " << getTranslation("PronunciationString.pronunciation2str") <<"["<< word.pronunciation << "]";

                    }
                    std::cout << std::endl;

                    if (!mistakeMade) {
                        firstTryCorrect++;
                    }

                    waitToEnter();
                    break;
                } else {
                    if (!mistakeMade) {
                        badlyAnswers++;
                    }
                    mistakeMade = true;

                    //Helytelen válasz színe
                    //csak a helytelen válasz írjuk ki pirosal ha true az useColors
                    //Incorrect answer color
                    //only print incorrect answers in red if useColors is true
                    if (useColors) std::cout << colors::RED;
                    std::cout << "\n" << getTranslation("BadlyAnswer.badlyAnswer") << "\n" << std::flush;

                    if (useColors) std::cout << colors::RESET;
                    std::cout << getTranslation("GoodAnswer2.goodAnswer2") << " " << word.motherLangMeaning << "\n" << std::flush;

                    std::cout << "\n" << getTranslation("ReTry.reTry");
                    std::cin.get();
                }
            }
        }
    }

    screenWipe();
    scoreSystem(firstTryCorrect, badlyAnswers, totalQuestions);

    std::cout << "\n" << getTranslation ("HaveFinished.haveFinished") << "\n" << std::flush;
    //std::cout << "\n" << haveFinished.haveFinished << std::endl;
    waitToEnter();
}

```

