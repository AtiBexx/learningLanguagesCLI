/**
* @page general_functions_doc General Functions Module
 * @tableofcontents
 *
 * EN:
 * This page documents the global utility functions used
 * across the entire application.
 *
 * HU:
 * Ez az oldal az alkalmazásban használt globális segédfüggvényeket dokumentálja.
 *
 * @details
 *
 * EN:
 * This module includes:
 * - Console utilities (screen wipe, beep, input pause)
 * - Logging system (error + mistake logging)
 * - String processing (trim, lowercase, punctuation removal)
 * - Accent normalization (Hungarian text handling)
 * - File system helpers
 *
 * HU:
 * Ez a modul tartalmazza:
 * - Konzol segédfüggvények (képernyőtörlés, hang, várakozás)
 * - Naplózási rendszer (hiba + hibaszó mentés)
 * - Szövegfeldolgozás (trim, kisbetű, írásjelek)
 * - Ékezetkezelés (magyar szöveg normalizálás)
 * - Fájlrendszer segédfüggvények
 */

#include "generalFunctions.h"
#include "../Translate/translations.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <ctime>
#include <map>
#ifdef _WIN32
#include <windows.h>
#endif


#include "dataFileReading.h"
#include "settings.h"
#include "Settings/colors.h"
#include "newInput/platformInput.h"


// a program leírása/magyarázata
// program explanation
void explanation() {

    screenWipe();
    std::cout << getTranslation("ExplanationStrings.description") << "\n";
    std::cout << getTranslation("ExplanationStrings.instruction1") << "\n";
    std::cout << getTranslation("ExplanationStrings.instruction2") << "\n";
    std::cout << getTranslation("ExplanationStrings.instruction3") << "\n";
    std::cout << getTranslation("ExplanationStrings.instruction4") << "\n";
    std::cout << getTranslation("ExplanationStrings.instruction5") << "\n";
    std::cout << getTranslation("ExplanationStrings.instruction6") << "\n";
    std::cout << getTranslation("ExplanationStrings.instruction7") << "\n";
    std::cout << getTranslation("ExplanationStrings.instruction8") << "\n";
    std::cout << getTranslation("ExplanationStrings.instruction9") << "\n";
    std::cout << getTranslation("ExplanationStrings.goodLuck") << "\n";

    waitToEnter();
}

// Várunk egy billentyűre (az enterre)
// wait for a keystroke (enter)
void waitToEnter()
{

    std::cout << getTranslation("EnteringBack.pressToEnter") <<"\n"<< std::flush;
    //std::cout << enteringBack.pressToEnter << std::endl;
    std::cin.get();
}

// Kilépünk az alkalmazásból
// Exit the application
void exiting() {
    screenWipe();
    std::cout << getTranslation("ExitingStrings.exiting") <<"\n" << std::flush;

    // Buffer törlése, hogy a cin.get() biztosan várjon
    // Clearing buffer to ensure cin.get() waits
    std::cin.get();
}

// képernyötőrlés || screen wipe
void screenWipe()
/*{
    if (useColors && !currentBG.empty()) {
        std::cout << currentBG;
    } else {
        std::cout << colors::RESET;
    }
    // A Képernyő törlése és kurzor haza (egyszerre!)
    // Clear Screen and Cursor Home (at the same time!)
    std::cout << "\x1B[2J\x1B[H\x1B[3J" << std::flush;
}*/
    // Szín beállítása (ha kell)
    // Set color if necessary
    {if (useColors && !currentBG.empty()) {
        std::cout << currentBG;
    } else {
        std::cout << colors::RESET;
    }
    if (!isRealTerminal())
    {
        std::cout << std::string(80, '\n') << std::flush;
    }
    else {
        // A Képernyő törlése és kurzor haza (egyszerre!)
        // Clear Screen and Cursor Home (at the same time!)
        std::cout << "\x1B[2J\x1B[H\x1B[3J" << std::flush;
    }
}

// Letöröljük a bent maradt puffert ha szükséges
// Clear the remaining buffer if necessary it
void pufferDelete() {
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    // a plusz zárojel megakadályoza hogy a Windows #define max(a,b) makró beleszóljon windowson a müködésbe.	
}

// rendszerhibák mentése
// log errors save
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

// A hibák mentése fájlba
// Save errors to a file
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

// Az Ékezetes karatkterek figyelmen kívül hagyása
// Ignore Accented Characters
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
// Trimmelés és kisbetűsítés
// Trim and lowercase
std::string cleanString(const std::string& s) {
    // Trim és kisbetű
    // Trim and lowercase
    // Írásjelek leszedése
    // Remove punctuation
    std::string result = toLowerCase(trim(s));
    result = removePunctuation(result);

    // ÉKEZETEK figyelmen kívül hagyása  ha a felhasználó kérte !
    // Ignore ACCENTS if requested by the user!
    if (ignoreAccents) {
        //s = removeAccents(s);
        result = removeAccents(result);
    }

    return result;
}





