#include "translations.h"

//======Vectors===========

// Menu'sVector
const std::vector<MenuStrings> menuTranslations = {
    // HUNGARIAN (Index 0)
    {
        "============LANGUAGE-LEARNING-APP============",
        "\n0. - A program magyarázata",
        "1. - A program indítása",
        "2. - A Hibák gyakorlása"
        "3. - Új vocab fájl létrehozása",
        "4. - Beállítások",
        "5. - Kilépés",
        "\n============================================="
    },
    // ENGLISH (Index 1)
    {
        "============LANGUAGE-LEARNING-APP============",
        "\n0. - the Program of explanation",
        "1. - Start Program",
        "2. - The Mistake Exercise",
        "3. - Create a new vocab file",
        "4. - Settings",
        "5. - Exit",
        "\n==========================================="
    }
};

// number output
const std::vector<NumberOutput> numberOutputTranslations = {
    // HUNGARIAN (Index 0)
    {"Kérlek válassz egy menüpontot: "},
    // ENGLISH (Index 1)
    {"Please choose a menu option: "}
};

//Explanation's vector
const std::vector<ExplanationStrings> explanationTranslations ={
    // HUNGARIAN (Index 0)
    {"Ez a program az Angol tudást fejleszti",
     "kérdez angol szavak,és kifejezéseket\nAmire elsőnek angolul majd magyarul kell válaszólni",
     "A képernyő törléshez használd a 'cls' parancsot\nA kilépéshez pedig az 'exit' parancsot",
     "Jó tanulást kívánok :) !"},
    // ENGLISH (Index 1)
    {"This program improves your English knowledge",
     "It asks for English words and phrases,\nwhich you must first answer in English and then in Hungarian",
     "Use the 'cls' command to clear the screen\nand the 'exit' command to quit",
     "Good luck with your studies :) !"}
};

const std::vector<ExitingStrings> exitingTranslations = {
    //Hungarian
    {"A kilépéshez kérlek nyomd meg az ENTER-T......"},
    //English
    {"Please to exit press ENTER......"}
};
const std::vector<BackStrings> backbackTranslations = {
    //Hungarian
    {"A visszalépéshez kérlek nyomd meg az ENTER-T......"},
    //English
    {"Please to return press ENTER......"}
};
const std::vector<InvalidInput> invalidInputTranslations = {
    //hungarian
    {"Hibás bemenet, kérlek csak számot adj meg!\n" },
    //English
        {"Invalid input. Please only enter a number!\n"}
};
const std::vector<EnteringBack> enteringBackTranslations = {
    //hungarian
    {"A folytatáshoz kérlek nyomd meg az ENTER-T......"},
    //English
    {"Please to continue press ENTER......"}
};
const std::vector<InvalidInput2>  invalidInputTranslations2 = { // 's' hozzáadva
    //Hungarian
{"Érvénytelen választás! Kérlek próbáld újra és megfelelő számot adj meg..."},
    // english
    {"Invalid choice. Please try again and enter a valid number....."}
};
const std::vector<HaveNoWords> haveNoWordsTranslations = {
    //Hungarian
    {"Nincsenek szavak ebben a fájlban"},
    //English
    {"There are no words in this file"}
};
const std::vector<Question1> question1Translations = {
    //Hungarian
    {"Magyarul ?: "},
    //English
    {"English ?: "}
};
const std::vector<Question2> question2Translations = { // HIÁNYZÓ DEFINÍCIÓ HOZZÁADVA
    //Hungarian
    {"in English ?: "},
    //English
    {"in Hungarian ?: "}
};
const std::vector<ReTry> reTryTranslations = {
    //Hungarian
    {"Kérlek nyomj egy Enter az újraprobálkozáshoz..."},
    //English
    {"Please press ENTER to try again..."}
};
const std::vector<BadlyAnswer> badlyAnswerTranslations ={
    //Hungarian
    {"Rossz válasz(ok)!"},
    //English
    {"Wrong answer(s)!"}
};
const std::vector<GoodAnswer1> goodAnswer1Translations = {
    //Hungarian
    {"Helyes Válasz!"},
    //English
    {"Correct Answer!"}
};
const std::vector<GoodAnswer2> goodAnswer2Translations = {
    //Hungarian
    {"A helyes válasz(ok): "},
    //English
    {"The correct answer(s): "}
};
const std::vector<PronunciationString> pronunciationStringTranslations = {
    //Hungarian
    {"Kiejtés: "},
    //English
    {"Pronunciation: "}
};
const std::vector<HaveFinished> haveFinishedTranslations = {
    //hungarian
    {"Vége a leckének! Szép munka!"},
    //English
    {"The lesson is over! Good job!"}
};
const std::vector<ScoreSys> totalTranslations = {
    //hungarian
    {
        "\n---=== Eredmény === ---",
        "A kérdések száma: ", // Itt volt egy elírás, összefolyt a következő sorral
        "Helyes válaszok: ",
        "Helytelen válaszok: ",
        "Teljesítmény százalékban"
    },
    {
        "\n---=== Results ===---",
        "Number of questions: ",
        "Correct answers: ",
        "Wrong answers: ",
        "Performance percentage: "
    }
};
const std::vector<PercentAge> percentAgeTranslations = {
    {
        "Tőkéletes Gratulálok cool vagy !",
        "Majdnem jó szép munka!",
        "Gyakorolj még egy kicsit!"
    },
    {"Perfect Congratulations you're cool!",
        "Almost perfect, nice job!" ,
        "Keep practicing a little more!"
    }
};
const std::vector<QuizExplanation> quizExplanationTranslations = {
    {"A kilépéshez használd az 'exit' parancsot",
        "A segítséghez (Válasz kíirásához) írd be a 'h' vagy 'help' parancsot.",
    "A segítség kikapcsolásához használd a 'h off' vagy 'help off' parancsot."} ,

    {"To quit the program, use the 'exit' command.",
        "Type 'h' or 'help' to show the answer (Cheat Sheet).",
        "Type 'h off' or 'help off' to disable help."
        }
};
const std::vector<VocabWordsPairTotal> vocabWordsPairTotalTranslations = {
    {
        "Összesen ",
        " szópar lett elmentve a(z) ",
        ".data fajlba."
    } ,

    {
    "A total of ",
        " words pairs were saved to the ",
        ".data file."
    }
};
const std::vector<CreateVocabFile> createVocabFileTranslations = {
    {
        "Kérlek add meg a fájl nevét: ",
        "Melyik mappába mentsük? (Ha jó a jelenlegi, nyomj Enter-t): ",
        "Hiba: Ervenytelen nincs ilyen útvonal!",
        "Hiba: Nem sikerult letrehozni a fajlt! (Lehet, hogy nem letezik a mappa?)",
        "Fájl elmentve....",
        "Automatikusan elmentve!"
    },
    {
        "Please enter the file name: ",
        "Which folder should we save it to? (If the current one is fine, press Enter): ",
        "Error: Indirect route does not exist!",
        "Error: Failed to create file! (Maybe the folder doesn't exist?)",
        "File saved...",
        "Automatically saved!"
    }

};
const std::vector<CreateVocab> createVocabTranslations = {
    {
        "Fájl: ",
        " (",
        " szó eddig) ---",
        "Parancsok: 'exit' (mentés es kilépes), 'save' (mentés és folytatás)\n",
        "Angol szó/kifejezés: ",
        "Magyar jelentese (vesszovel elvalasztva ha több van): ",
        "Kiejtes (opcionális): "
    },
{
    "File: ",
    " (",
    " words so far) ---",
    "Commands: 'exit' (save and exit), 'save' (save and continue)\n",
    "English word/phrase",
    "Hungarian meaning (separated by commas if there are more): ",
"Pronunciation (optional): "
}

};
const std::vector<VocabMenu> vocabMenuTranslations = {
    {
        "FIGYELEM: Ez a fájl már létezik és ",
        " szópárt tartalmaz.",
        "1. Hozzafuzes\n2. Feluliras\n3. Megsem\nValasztas: ",
        "Hiba:csak 1-3 közötti számot adj meg!",
        "Hiba: Csak számot adj meg!"
    },
    {
        "WARNING: This file already exists and contains ",
        " word pairs.",
        "1. Append\n2. Overwrite\n3. Delete\nOptions: ",
        "Error: Enter only numbers between 1-3!",
        "Error: Enter only numbers!"
    }
};
const std::vector<SettingsMenu> settingsMenuTranslations {
    {
        "Hiba:csak 1-4 közötti számot adj meg!",
        "Nem számot adtél meg.\nKérlek csak számot adj meg!",
        "================BEÁLLÍTÁSOK-MENU================",
        "Kérlek válasz az alábbi menüpontok közül:",
        "1.Nyelv beállítása",
        "2.A tanulandó nyelv beállítása",
        "3.Színek beállítása",
        "4. Beep hang be/ki"
        "5.Visszalépés a főmenübe",
        "\n================================================"
    },
    {
        "Error: Please enter only numbers between 1-4!",
        "You have not entered a number.\nPlease enter only a number!"
    }
};
const std::vector<LanguageMenu> languageMenuTranslations {
    {
        "============NYELV_VALASZTAÁSI-MENU============",
        "1. Magyar / Hungarian",
        "2. Angol / English",
        "3. Visszalépés a beállításokba",
        "\nVálasztás: ",
        "\n=============================================="
    },
    {
        "============LANGUAGE-MENU============",
        "1. Hungarian /Magyar",
        "2. English / Angol",
        "3. Return to settings",
        "\nChoice: ",
        "\n====================================="
    }
};
const std::vector<LanguageMenu2> languageMenu2Translations {

    {
        "Hiba csak 1-3.-ig adj meg számot",
        "Hba csak számot adj meg!",
        "A Nyelv sikeresen megvaltoztatva Magyarra !"
    },
    {
    "Error, only enter numbers 1-3.",
        "Please just give me a number!",
        "Language successfully changed to English !"
    }
};
const std::vector<ColorsOnset> colorsOSetTranslations {
    {
        "========A SZÍNEK BEÁLLÍTÁSA=========",
        "Jelenlegi állapot: ",
        "BE",
        "KI",
        "1. Be/ ki - kapcsolás....",
        "\n2.Háttérszín_beállítása",
        "\n3.Vissza",
        "Színek bekapcsolva...",
        "Színek kikapcsolva..."
    },
    {
        "========COLOR SETTINGS=========",
        "Current state: ",
        "ON",
        "OFF",
        "1. On/off - switching....",
"\n2.Set background color",
        "\n3.Back",
        "Colors turned on...",
        "Colors turned off..."
    }
};
const std::vector<SaveSettings> saveSettingsTranslations {
    {
        "Hiba: Nem sikerult menteni a beallitasokat!"
    },
    {
        "Error: Unable to save settings!"
    }
};
const std::vector<LearningLanguageSet> learningLanguageSetTranslations {
    {
        "==== A Tanulandó nyelv beállítása ====",
        "A jelenlegi Anyanyelv: ",
        "A jelenlegi tanult nyelv: ",
        "\n1. Az anyanyelv módosítása",
        "\n2. A tanult nyelv módosítása",
        "\n3.Visszalépés a beállításokba"
    }, {
        "==== Setting the Learning Language ====",
    "Current Native Language: ",
    "Current Learned Language: ",
    "\n1. Change Native Language",
    "\n2. Change Learned Language",
    "\n3. Return to Settings"
    }
};
const std::vector<TargetLanguageNameSet> mmotherLanguageSetTranslations {
    {
        "Angolul?",
        "Magyarul?",
        "Kínaiul?",
        "Japánul?",
        "Spanyolul?",
        "Németül?",
        "Franciául?",
        "Oroszul?",
        "Ukránul?",
        "Koreaiul?",
        "Olaszul?",
        "Lengyelül?",
        "Arabul?",
        "Vietnámiul?",
        "Fillipinóiul?",
        "Görögül?",
        "Héberül?",
        "Portugálul?",
        "Perzsaiul?",
        "Svédül?",
        "Hollandul?",
        "Törökül?",
        "Indiaiul?",
        "Olaszul?"
    },
    {
        "in English?",
        " in Hungarian?",
        "in Chinese?",
        "in Japanese?",
        "in Spanish?",
        "in German?",
        "in French?",
        "in Russian?",
        "in Ukrainian?",
        "in Korean?",
        "in Italian?",
        "in Polish?",
        "in Arabic?",
        "in Vietnamese?",
        "in Tagalog?",
        "in Greek?",
        "in Hebrew?",
        "in Portuguese?",
        "in Persian?",
        "in Swedish?",
        "in Dutch?",
        "in Turkish?",
        "in Hindi?",
        "in Latin?"
    }

};
const std::vector<TargetlanguageList> targetlanguagelistsTranslations {

    {
        "Angol",
        "Magyar",
        "Kínai",
        "Japán",
        "Spanyol",
        "Német",
        "Francia",
        "Orosz",
        "Ukrán",
        "Koreai",
        "Olasz",
        "Lengyel",
        "Arab",
        "Vietnámi",
        "Fillipinó",
        "Görög",
        "Héber",
        "Portugál",
        "Perzsa",
        "Svéd",
        "Holland",
        "Török",
        "Indiai",
        "Latin"
    },
    {
        "English",
        "Hungarian",
        "Chinese",
        "Japanese",
        "Spanish",
        "German",
        "French",
        "Russian",
        "Ukrainian",
        "Korean",
        "Italian",
        "Polish",
        "Arabic",
        "Vietnamese",
        "Tagalog",
        "Greek",
        "Hebrew",
        "Portuguese",
        "Persian",
        "Swedish",
        "Dutch",
        "Turkish",
        "Hindi",
        "Latin"
    }
};

//======Vectors end =========