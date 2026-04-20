#include "generalFunctions.h"
#include "../Translate/translations.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <map>

#include "dataFileReading.h"
#include "settings.h"
#include "Settings/colors.h"


void explanation() {
    const ExplanationStrings& strings = explanationTranslations[static_cast<int>(programUiLanguage)];

    screenWipe();
    std::cout << strings.description << std::endl;
    std::cout << strings.instruction1 << std::endl;
    std::cout << strings.instruction2 << std::endl;
    std::cout << strings.goodLuck << std::endl;

    // delete Buffer
    // Buffer törlése
    pufferDelete();
    waitToEnter();
}
void waitToEnter()
{
    const EnteringBack& enteringback = continuationToEnterTranslations[static_cast<int>(programUiLanguage)];

    std::cout << enteringback.pressToEnter << std::endl;
    std::cin.get();
}

void exiting() {
    screenWipe();
    const ExitingStrings& strings = exitingTranslations[static_cast<int>(programUiLanguage)];
    std::cout << strings.exiting << std::endl;

    // Buffer törlése, hogy a cin.get() biztosan várjon
    // Clearing buffer to ensure cin.get() waits
    pufferDelete();
    std::cin.get();
}
void screenWipe () {

    std::cout << "\x1B[2J\x1B[H" << std::flush; // letöröljük a képernyő tartalmát || erase the contents of the screen
    // ha van beállítva háttérszín akkor festünk
    // if a background color is set then paint
    if (!currentBG.empty() && useColors)
    {
        std::cout << currentBG;
    } else
    {
        std::cout << colors::RESET;// Minden más esetben alaphelyzet (fekete)
    }
    // UTÁNA küldjük a törlés és kurzor-pozicionálás parancsot
    // (\x1B[2J törli az ablakot az AKTUÁLISAN beállított színnel)
    // AFTER sending the delete and cursor-positioning command
    // (\x1B[2J deletes the window with the CURRENTLY set color)
        std::cout << "\x1B[2J\x1B[H";
        std::cout << std::flush;
}
void pufferDelete() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
// rendszerhibák mentése
void logError(const std::string& functionName, const std::string& errorMessage) {

    std::ofstream logFile("error.log ", std::ios::app); //hozzáfűzés mód || append mode
    if (logFile.is_open()) {

        // az időbélyeg lekérése
        // get the timestamp
        std::time_t now = std::time(nullptr);
        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        //Mentés és hibakód/hibaüzenet [IDŐ SZERINT]
        //Save and error code/error message [BY TIME]
        logFile << "[" << timestamp << "] [" << functionName << "] " << errorMessage << std::endl;
        logFile.close();
    }
}

void logMistakeWriteFile(const WordPair& word)
{
    //ha WINDOWS
#ifdef _WIN32
    std::system("if not exist data\\mistakes mkdir data\\mistakes");
    std::string path = "data\\mistakes\\mistakes.data";

    //HA LINUX VAGY ANDROID VAGY MÁS
    //IF LINUX OR ANDROID OR ELSE SYSTEM
    #else
    std::system("mkdir -p data/mistakes");
    std::string path = "data/mistakes/mistakes.data";
#endif

    //Hozzafüzés módban nyitjuk meg hogy gyüljenek a hibák
    //Open in append mode to collect errors
    std::ofstream mistakeFile(path, std::ios::app);
    if (mistakeFile.is_open())
    {
        //elmentjük ugyanabban a formátumban a fájl
        //save the file in the same format
        mistakeFile << word.targetLangMeaning << " -> " << word.motherLangMeaning;
        if (!word.pronunciation.empty())
        {
            mistakeFile << " (" << word.pronunciation << ")";
        }
        mistakeFile << "\n";
        mistakeFile.close();
        }
    }

// a Hang
// the sound
void playBeep(int frequency , int duration ) {
    if (!useSound) return; // ha ki van kapcsolva || if it"s turned off

#ifdef _WIN32
    // Windowsos beep: frekvencia (Hz) és időtartam (ms)
    // Windows beep: frequency (Hz) and duration (ms)
    Beep(frequency, duration);
#else
    // Linux/Termux/macOS: ANSI Bell character
    std::cout << "\a" << std::flush;
#endif
}

//Az írásjelek eltávolítására ne vegy figyelembe '!' '?' stb
//To remove punctuation, ignore '!' '?' etc.
std::string removePunctuation(const std::string& s)
{
    std::string result;
    for (char c : s) {
        // Ha nem írásjel, akkor megtartjuk
        // If it's not a punctuation mark, we keep it
        if (c != '!' && c != '?' && c != '.' && c != ',' && c != ';') {
            result += c;
        }
    }
    return result;
}

std::string removeAccents(const std::string &s) {
    // UTF-8 ékezetes karakterek és párjaik
    static const std::map<std::string, std::string> accentMap = {
        {"á", "a"}, {"é", "e"}, {"í", "i"}, {"ó", "o"}, {"ö", "o"}, {"ő", "o"},
        {"ú", "u"}, {"ü", "u"}, {"ű", "u"},
        {"Á", "a"}, {"É", "e"}, {"Í", "i"}, {"Ó", "o"}, {"Ö", "o"}, {"Ő", "o"},
        {"Ú", "u"}, {"Ü", "u"}, {"Ű", "u"}
    };

    std::string result;
    for (size_t i = 0; i < s.length(); ) {
        bool found = false;
        // Megnézzük, hogy az aktuális pozíciótól kezdődik-e egy 2-bájtos ékezetes karakter
        // Check if the current position starts with a 2-byte accented character
        /*
        * Miért ilyen bonyolult a típus?
        std::pair: A map minden eleme egy pár (kulcs és érték).
        const std::string (az első): A map kulcsa sosem változhat meg utó lag.
        std::string (a második): Ez a sima betű , amit hozzáadunk.
        &: Referencia, hogy ne másoljuk le az elemeket minden körben.
         */
        // for (auto const& pair : accentMap)
        for (const std::pair<const std::string, std::string>& pair : accentMap) {
            const std::string& accent = pair.first;
            const std::string& plain = pair.second;

            if (s.compare(i, accent.length(), accent) == 0) {
                result += plain;
                i += accent.length();
                found = true;
                break;
            }
        }
        if (!found) {
            result += s[i]; //Hozzáadjuk az a betűt az eredményhez
            i++; // Továbblépünk a következő karakterre
        }
    }
    return result;
}

std::string cleanString(const std::string& s) {
    // Trim és kisbetű
    // Trim and lowercase
    //s = toLowerCase(trim(s));

    // Írásjelek leszedése
    // Remove punctuation
    //s = removePunctuation(s);
    std::string result = toLowerCase(trim(s));
    result = removePunctuation(result);

    // ÉKEZETEK figyelmen kívül hagyása  ha a felhasználó kérte !
    // Ignore ACCENTS if requested by the user!
    if (ignoreAccents) {
        //s = removeAccents(s);
        result = removeAccents(result);
    }

    //return s;
    return result;
}





