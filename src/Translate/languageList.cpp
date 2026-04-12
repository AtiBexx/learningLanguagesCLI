//
// Created by AtiBexx2 on 2026. 04. 12.
//
#include <string>
#include "../Translate/translations.h"
#include "../Settings/settings.h"

std::string getLanguageNameByIndex(int index)
{
    // nyelvi fordításhoz függvények
    const TargetlanguageList& names = targetlanguagelistsTranslations[static_cast<int>(currentLanguage)];
    switch (index)
    {
        case 0:
            return names.Magyar;
        case 1:
            return names.English;
        case 2:
            return names.Chinese;
        case 3:
            return names.Japan;
        case 4:
            return names.Spanish;
        case 5:
            return names.German;
        case 6:
            return names.French;
        case 7:
            return names.Russian;
        case 8:
            return names.Ukrainian;
        case 9:
            return names.Korean;
        case 10:
            return names.Italian;
        case 11:
            return names.Polish;
        case 12:
            return names.Arabic;
        case 13:
            return names.Vietnamese;
        case 14:
            return names.Tagalog;
        case 15:
            return names.Greek;
        case 16:
            return names.Hebrew;
        case 17:
            return names.Portuguese;
        case 18:
            return names.Farsi;
        case 19:
            return names.Swedish;
        case 20:
            return names.Dutch;
        case 21:
            return names.Turkish;
        case 22:
            return names.Hindi;
        case 23:
            return names.Latin;
        default:
            return "UNKNOWN";

    }
}
