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
#include "Settings/colors.h"
#include "Settings/settings.h"


void scoreSystem(int correct, int badly, unsigned long long total) {
    //Fordítások betöltése és a sikerességi százalék kiszámítása
    const ScoreSys &scoresys = totalTranslations[static_cast<int>(programUiLanguage)];
    const PercentAge &percentAgeStr = percentAgeTranslations[static_cast<int>(programUiLanguage)];

    double percentAge = (total > 0) ? (static_cast<double>(correct) / static_cast<double>(total)) * 100.0 : 0.0;

    //Részletes pontszámstatisztikák megjelenítése
    //Show detailed score statistics
    std::cout << scoresys.total << std::endl;
    std::cout << scoresys.allQuestion << total << std::endl;
    std::cout << scoresys.correct << correct << std::endl;
    std::cout << scoresys.badly << badly << std::endl;
    std::cout << scoresys.percent << percentAge << "%" << std::endl;

    //Végső értékelő üzenet megjelenítése a százalékos arány alapján
    //Display final evaluation message based on percentage
    if (percentAge >= 99.9) {
        std::cout << percentAgeStr.percentAge100 << std::endl;
    } else if (percentAge >= 80.0 ) {
        std:: cout << percentAgeStr.percentAge80 << std::endl;
    } else {
        std::cout << percentAgeStr.percentAgeElse << std::endl;
    }
}

//Quiz kérdezős logika
//Quiz question logic
void startQuiz (const std::vector<WordPair>& words)
{
    const HaveNoWords &haveNoWords = haveNoWordsTranslations[static_cast<int>(programUiLanguage)];
    const ReTry &reTry = reTryTranslations[static_cast<int>(programUiLanguage)];
    const BadlyAnswer &badlyAnswer = badlyAnswerTranslations[static_cast<int>(programUiLanguage)];
    const GoodAnswer1 &goodAnswer1 = goodAnswer1Translations[static_cast<int>(programUiLanguage)];
    const GoodAnswer2 &goodAnswer2 = goodAnswer2Translations[static_cast<int>(programUiLanguage)];
    const PronunciationString &pronunciation2str = pronunciationStringTranslations[static_cast<int>(programUiLanguage)];
    const HaveFinished &haveFinished = haveFinishedTranslations[static_cast<int>(programUiLanguage)];
    const QuizExplanation &quizExplanation = quizExplanationTranslations[static_cast<int>(programUiLanguage)];

    // Ha üres a fájl
    // If file is empty
    if (words.empty()) {
        std::cout << haveNoWords.haveNoWords << std::endl;
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

    // Globális változó a kvízen belül a súgó állapotának
    // Global variable within the quiz to store the help status
    bool showHelp = false;

    for (const WordPair& word : words)
    {
        bool mistakeMade = false;

        // 1. KÖR: Magyar -> Angol kérdezés vagy ami az anyanyelved
        // ROUND 1: Hungarian -> English question or whatever your native language is
        for (;;) {
            screenWipe();
            std::cout << quizExplanation.quizExplanation1 << std::endl;
            std::cout << quizExplanation.quizExplanation2 << std::endl;
            std::cout << quizExplanation.quizExplanation3 << std::endl;
            std::cout << getLanguageNameByIndex(static_cast<int>(motherLanguage)) << ": " << word.motherLangMeaning << std::endl;

            // Ha be van kapcsolva a súgó, akkor itt kiírjuk
            if (showHelp) {
                std::cout << "CheatSheet: " << colors::GREY << word.targetLangMeaning << colors::RESET << std::endl;
            }

            std::cout <<  getLanguageNameByIndex(static_cast<int>(targetLanguage)) << ": ";  // "Angolul? "

            std::string answer;
            std::getline(std::cin, answer);

            if (answer == "exit") return;

            // TOGGLE SÚGÓ BEKAPCSOLÁS
            // TOGGLE HELP ENABLE
            if (answer == "h" || answer == "help") {
                showHelp = true;
                continue; // Újraindul a kör, és mivel showHelp=true, kiírja a súgót
            }
            // TOGGLE SÚGÓ KIKAPCSOLÁS
            // TOGGLE HELP OFF
            if (answer == "h off" || answer == "help off") {
                showHelp = false;
                continue; // Újraindul a kör, és már nem írja ki
            }

            //if (toLowerCase(removePunctuation(trim(answer))) == toLowerCase(removePunctuation(word.targetLangMeaning))) {
            if (cleanString(answer) == cleanString(word.targetLangMeaning)) {
                //kiíratás színe(Helyesválasz)
                //printout color(Correct answer)
                if (useColors == true)
                {
                    std::cout << colors::GREEN;
                    std::cout << "\n" << goodAnswer1.goodAnswer1;
                    std::cout << colors::RESET; //visszaállítjuk a színét || restore the color
                } else
                {
                    std::cout << "\n" << goodAnswer1.goodAnswer1;
                }
                if (!word.pronunciation.empty()) {
                    std::cout << " " << pronunciation2str.pronunciation2str <<"[" << word.pronunciation << "]";
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
                std::cout << "\n" << badlyAnswer.badlyAnswer << std::endl;
                if (useColors) std::cout << colors::RESET;

                std::cout << goodAnswer2.goodAnswer2 << " " << word.targetLangMeaning << std::endl;
                std::cout << "\n" << reTry.reTry;
                std::cin.get();
            }
        }

        mistakeMade = false;

        // 2. KÖR: Angol -> Magyar kérdezés vagy ami a célnyel
        // 2ND ROUND: English -> Hungarian questioning or anything related to the target language
        if (!oneRoundQuiz) {
            for (;;) {
                screenWipe();
                std::cout << quizExplanation.quizExplanation1 << std::endl;
                std::cout << quizExplanation.quizExplanation2 << std::endl;
                std::cout << quizExplanation.quizExplanation3 << std::endl;
                std::cout << getLanguageNameByIndex(static_cast<int>(targetLanguage)) << ": " << word.targetLangMeaning << std::endl;

                // Ha be van kapcsolva a súgó, akkor itt kiírjuk
                if (showHelp) {
                    std::cout << "CheatSheet: " << colors::GREY << word.motherLangMeaning << colors::RESET << std::endl;
                }

                std::cout <<  getLanguageNameByIndex(static_cast<int>(motherLanguage)) << ": ";  // "Magyarul? "

                std::string answer;
                std::getline(std::cin, answer);

                if (answer == "exit") return;

                // TOGGLE SÚGÓ BEKAPCSOLÁS
                // TOGGLE HELP ENABLE
                if (answer == "h" || answer == "help") {
                    showHelp = true;
                    continue;
                }
                // TOGGLE SÚGÓ KIKAPCSOLÁS
                // TOGGLE HELP DISABLE
                if (answer == "h off" || answer == "help off") {
                    showHelp = false;
                    continue;
                }

                if (checkMultipleAnswers(answer, word.motherLangMeaning)) {
                    // a helyes válasz színe ha az useColor == true
                    // // the color of the correct answer if useColor == true

                    if (useColors) std::cout << colors::GREEN;
                    std::cout << "\n" << goodAnswer1.goodAnswer1;
                    if (useColors) std::cout << colors::RESET;

                    if (!word.pronunciation.empty()) {
                        std::cout << " " << pronunciation2str.pronunciation2str <<"["<< word.pronunciation << "]";
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
                    std::cout << "\n" << badlyAnswer.badlyAnswer << std::endl;
                    if (useColors) std::cout << colors::RESET;

                    std::cout << goodAnswer2.goodAnswer2 << " " << word.motherLangMeaning << std::endl;
                    std::cout << "\n" << reTry.reTry;
                    std::cin.get();
                }
            }
        }
    }

    screenWipe();
    scoreSystem(firstTryCorrect, badlyAnswers, totalQuestions);

    std::cout << "\n" << haveFinished.haveFinished << std::endl;
    waitToEnter();
}
