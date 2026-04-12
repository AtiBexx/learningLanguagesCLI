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
    const ScoreSys &scoresys = totalTranslations[static_cast<int>(currentLanguage)];
    const PercentAge &percentAgeStr = percentAgeTranslations[static_cast<int>(currentLanguage)];

    double percentAge = (total > 0) ? (static_cast<double>(correct) / static_cast<double>(total)) * 100.0 : 0.0;
    //Részletes pontszámstatisztikák megjelenítése
    std::cout << scoresys.total << std::endl;
    std::cout << scoresys.allQuestion << total << std::endl;
    std::cout << scoresys.correct << correct << std::endl;
    std::cout << scoresys.badly << badly << std::endl;
    std::cout << scoresys.percent << percentAge << "%" << std::endl;

    //Végső értékelő üzenet megjelenítése a százalékos arány alapján
    if (percentAge >= 99.9) {
        std::cout << percentAgeStr.percentAge100 << std::endl;
    } else if (percentAge >= 80.0 ) {
        std:: cout << percentAgeStr.percentAge80 << std::endl;
    } else {
        std::cout << percentAgeStr.percentAgeElse << std::endl;
    }
}

//Quiz kérdezős logika
void startQuiz (const std::vector<WordPair>& words) {
    const EnteringBack &enteringback = enteringBackTranslations[static_cast<int>(currentLanguage)];
    const HaveNoWords &haveNoWords = haveNoWordsTranslations[static_cast<int>(currentLanguage)];
    const ReTry &reTry = reTryTranslations[static_cast<int>(currentLanguage)];
    const BadlyAnswer &badlyAnswer = badlyAnswerTranslations[static_cast<int>(currentLanguage)];
    const GoodAnswer1 &goodAnswer1 = goodAnswer1Translations[static_cast<int>(currentLanguage)];
    const GoodAnswer2 &goodAnswer2 = goodAnswer2Translations[static_cast<int>(currentLanguage)];
    const PronunciationString &pronunciation2str = pronunciationStringTranslations[static_cast<int>(currentLanguage)];
    const HaveFinished &haveFinished = haveFinishedTranslations[static_cast<int>(currentLanguage)];
    const QuizExplanation &quizExplanation = quizExplanationTranslations[static_cast<int>(currentLanguage)];


    if (words.empty()) {
        std::cout << haveNoWords.haveNoWords << std::endl;
        std::cout << enteringback.enteringBack << std::endl ;
        std::cin.get();
        return;
    }

    int badlyAnswers = 0;
    int firstTryCorrect = 0;
    unsigned long long totalQuestions = words.size() * 2;

    // Globális változó a kvízen belül a súgó állapotának
    bool showHelp = false;

    for (const WordPair& word : words) {
        bool mistakeMade = false;

        // 1. KÖR: Magyar -> Angol kérdezés
        for (;;) {
            screenWipe();
            std::cout << quizExplanation.quizExplanation1 << std::endl;
            std::cout << quizExplanation.quizExplanation2 << std::endl;
            std::cout << quizExplanation.quizExplanation3 << std::endl;
            std::cout << getLanguageNameByIndex(static_cast<int>(motherLanguage)) << ": " << word.hungarian << std::endl;

            // Ha be van kapcsolva a súgó, akkor itt kiírjuk
            if (showHelp) {
                std::cout << "CheatSheet: " << colors::GREY << word.english << colors::RESET << std::endl;
            }

            std::cout <<  getLanguageNameByIndex(static_cast<int>(targetLanguage)) << ": ";  // "Angolul? "

            std::string answer;
            std::getline(std::cin, answer);

            if (answer == "exit") return;

            // TOGGLE SÚGÓ BEKAPCSOLÁS
            if (answer == "h" || answer == "help") {
                showHelp = true;
                continue; // Újraindul a kör, és mivel showHelp=true, kiírja a súgót
            }
            // TOGGLE SÚGÓ KIKAPCSOLÁS
            if (answer == "h off" || answer == "help off") {
                showHelp = false;
                continue; // Újraindul a kör, és már nem írja ki
            }

            if (toLowerCase(trim(answer)) == toLowerCase(word.english)) {
                //kiíratás színe(Helyesválasz)
                if (useColors == true)
                {
                    std::cout << colors::GREEN;
                    std::cout << "\n" << goodAnswer1.goodAnswer1;
                    std::cout << colors::RESET; //visszaállítjuk a színét
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

                std::cout << enteringback.enteringBack;
                std::cin.get();
                break;
            } else {
                if (!mistakeMade) {
                    badlyAnswers++;
                    logMistake(word); // Elmentjük a hibát az első rontásnál
                }
                mistakeMade = true;

                //Helytelen válasz színe
                //csak a helytelen válasz írjuk ki pirosal ha true az useColors
                if (useColors) std::cout << colors::RED;
                std::cout << "\n" << badlyAnswer.badlyAnswer << std::endl;
                if (useColors) std::cout << colors::RESET;

                std::cout << goodAnswer2.goodAnswer2 << " " << word.english << std::endl;
                std::cout << "\n" << reTry.reTry;
                std::cin.get();
            }
        }

        mistakeMade = false;

        // 2. KÖR: Angol -> Magyar kérdezés
        for (;;) {
            screenWipe();
            std::cout << quizExplanation.quizExplanation1 << std::endl;
            std::cout << quizExplanation.quizExplanation2 << std::endl;
            std::cout << quizExplanation.quizExplanation3 << std::endl;
            std::cout << getLanguageNameByIndex(static_cast<int>(motherLanguage)) << ": " << word.english << std::endl;

            // Ha be van kapcsolva a súgó, akkor itt kiírjuk
            if (showHelp) {
                std::cout << "CheatSheet: " << colors::GREY << word.hungarian << colors::RESET << std::endl;
            }

            std::cout <<  getLanguageNameByIndex(static_cast<int>(targetLanguage)) << ": ";  // "Magyarul? "

            std::string answer;
            std::getline(std::cin, answer);

            if (answer == "exit") return;

            // TOGGLE SÚGÓ BEKAPCSOLÁS
            if (answer == "h" || answer == "help") {
                showHelp = true;
                continue;
            }
            // TOGGLE SÚGÓ KIKAPCSOLÁS
            if (answer == "h off" || answer == "help off") {
                showHelp = false;
                continue;
            }

            if (checkMultipleAnswers(answer, word.hungarian)) {
               // a helyes válasz színe ha az useColor == true
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

                std::cout << enteringback.enteringBack;
                std::cin.get();
                break;
            } else {
                if (!mistakeMade) {
                    badlyAnswers++;
                }
                mistakeMade = true;

                //Helytelen válasz színe
                //csak a helytelen válasz írjuk ki pirosal ha true az useColors
                if (useColors) std::cout << colors::RED;
                std::cout << "\n" << badlyAnswer.badlyAnswer << std::endl;
                if (useColors) std::cout << colors::RESET;

                std::cout << goodAnswer2.goodAnswer2 << " " << word.hungarian << std::endl;
                std::cout << "\n" << reTry.reTry;
                std::cin.get();
            }
        }
    }

    screenWipe();
    scoreSystem(firstTryCorrect, badlyAnswers, totalQuestions);

    std::cout << "\n" << haveFinished.haveFinished << std::endl;
    std::cout << enteringback.enteringBack;
    std::cin.get();
}
