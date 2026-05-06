//
// Created by AtiBexx2 on 2026. 05. 03.
//

#include "translations.h"
// languageList.cpp
// ...
std::string getLanguageNameByIndex(Language programLang, Language targetLang) {
    // A programLang az, hogy milyen nyelven jelenjen meg a kérdés (pl. Hungarian)
    // A targetLang az, hogy melyik nyelvre vonatkozik a kérdés (pl. English)

    // Ellenőrizzük, hogy az indexek érvényesek-e
    if (static_cast<int>(programLang) < 0 || static_cast<int>(programLang) >= targetLanguageSetTranslations.size()) {
        return "INVALID_PROGRAM_LANG";
    }
    if (static_cast<int>(targetLang) < 0 ||
    static_cast<int>(targetLang) >= static_cast<int>(Language::COUNT)) { // Language::LATIN a max enum érték
        return "INVALID_TARGET_LANG";
    }

    // A targetLanguageSetTranslations egy vector, aminek az indexe a program nyelve
    // A struct mezői pedig a célnyelvek
    const TargetLanguageNameSet& currentLangSet = targetLanguageSetTranslations[static_cast<int>(programLang)];

    // Most a targetLang alapján kell kiválasztani a megfelelő stringet a structból
    switch (targetLang) {
        case Language::HUNGARIAN: return currentLangSet.Magyar;
        case Language::ENGLISH: return currentLangSet.English;
        case Language::CHINESE: return currentLangSet.Chinese;
        case Language::JAPANESE: return currentLangSet.Japan;
        case Language::SPANISH: return currentLangSet.Spanish;
        case Language::GERMAN: return currentLangSet.German;
        case Language::FRENCH: return currentLangSet.French;
        case Language::RUSSIAN: return currentLangSet.Russian;
        case Language::UKRAINIAN: return currentLangSet.Ukrainian;
        case Language::KOREAN: return currentLangSet.Korean;
        case Language::ITALIAN: return currentLangSet.Italian;
        case Language::POLISH: return currentLangSet.Polish;
        case Language::ARABIC: return currentLangSet.Arabic;
        case Language::VIETNAMESE: return currentLangSet.Vietnamese;
        case Language::TAGALOG: return currentLangSet.Tagalog;
        case Language::GREEK: return currentLangSet.Greek;
        case Language::HEBREW: return currentLangSet.Hebrew;
        case Language::PORTUGUESE: return currentLangSet.Portuguese;
        case Language::FARSI: return currentLangSet.Farsi;
        case Language::SWEDISH: return currentLangSet.Swedish;
        case Language::DUTCH: return currentLangSet.Dutch;
        case Language::TURKISH: return currentLangSet.Turkish;
        case Language::HINDI: return currentLangSet.Hindi;
        case Language::LATIN: return currentLangSet.Latin;
        default: return "UNKNOWN_LANGUAGE";
    }
}
// ...
