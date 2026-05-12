```c++
/**
* @file generalFunctions.cpp
 * @brief Global utility functions / Globális segédfüggvények gyűjteménye
 *
 * @details
 * EN:
 * This module provides essential utility functions used across the application:
 * - Console management (screen wiping, beep sounds, user prompts)
 * - Logging and error reporting
 * - String normalization (trimming, lowercase, punctuation, and accent removal)
 * - File system operations for logging mistakes
 *
 * HU:
 * Ez a modul az alkalmazás egészében használt alapvető segédfüggvényeket biztosítja:
 * - Konzol kezelés (képernyőtörlés, hangjelzés, várakozás)
 * - Naplózás és hibajelentés
 * - Szöveg normalizálás (szóközök, kisbetűk, írásjelek és ékezetek eltávolítása)
 * - Fájlrendszer műveletek a hibás szavak naplózásához
 */

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

/**
 * @brief Displays an explanation of the program's functionality. || Megjeleníti a program működésének magyarázatát.
 *
 * @details
 * EN:
 * This function clears the screen and prints a series of instructions and descriptions
 * about how to use the application, its features, and basic commands.
 * It then waits for user input before returning.
 *
 * HU:
 * Ez a függvény letörli a képernyőt, és kiír egy sor utasítást és leírást
 * az alkalmazás használatáról, funkcióiról és alapvető parancsairól.
 * Ezután felhasználói bevitelre vár, mielőtt visszatérne.
 */
// a program leírása/magyarázata
// program explanation
void explanation() {
    //const ExplanationStrings& strings = explanationTranslations[static_cast<int>(programUiLanguage)];

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

/**
 * @brief Pauses program execution until the user presses Enter. || Szünetelteti a program futását, amíg a felhasználó Entert nem nyom.
 *
 * @details
 * EN:
 * This function displays a prompt asking the user to press Enter to continue.
 * It first clears any pending input in the buffer to ensure a fresh read.
 *
 * HU:
 * Ez a függvény egy üzenetet jelenít meg, amely arra kéri a felhasználót, hogy nyomja meg az Entert a folytatáshoz.
 * Először törli a pufferben lévő függőben lévő bemenetet, hogy biztosítsa a friss olvasást.
 */
// várunk egy billentyűre (az enterre)
// wait for a keystroke (enter)
void waitToEnter()
{
    //const EnteringBack& enteringBack = continuationToEnterTranslations[static_cast<int>(programUiLanguage)];

    std::cout << getTranslation("EnteringBack.pressToEnter") <<"\n"<< std::flush;
    //std::cout << enteringBack.pressToEnter << std::endl;
    std::cin.get();
}

/**
 * @brief Displays an exit message and waits for user confirmation. || Kilépési üzenetet jelenít meg és felhasználói megerősítésre vár.
 *
 * @details
 * EN:
 * Clears the screen, displays a farewell message, and then waits for the user
 * to press Enter before the program fully terminates.
 *
 * HU:
 * Letörli a képernyőt, búcsúüzenetet jelenít meg, majd megvárja, hogy a felhasználó
 * Entert nyomjon, mielőtt a program teljesen leállna.
 */
// Kilépünk az alkalmazásból
// Exit the application
void exiting() {
    screenWipe();
    //const ExitingStrings& strings = exitingTranslations[static_cast<int>(programUiLanguage)];
    std::cout << getTranslation("ExitingStrings.exiting") <<"\n" << std::flush;
    //std::cout << strings.exiting << std::endl;

    // Buffer törlése, hogy a cin.get() biztosan várjon
    // Clearing buffer to ensure cin.get() waits
    //pufferDelete();
    std::cin.get();
}

/**
 * @brief Clears the console screen and applies background color. || Letörli a konzol képernyőjét és háttérszínt alkalmaz.
 *
 * @details
 * EN:
 * This function uses ANSI escape codes to clear the entire console display,
 * move the cursor to the home position, and then applies the currently selected
 * background color if colors are enabled.
 *
 * HU:
 * Ez a függvény ANSI escape kódokat használ a teljes konzol kijelzőjének törlésére,
 * a kurzor alaphelyzetbe állítására, majd alkalmazza az aktuálisan kiválasztott
 * háttérszínt, ha a színek engedélyezve vannak.
 */
// képernyötőrlés || screen wipe
void screenWipe() {
    // Szín beállítása (ha kell)
    // Set color if necessary
    if (useColors && !currentBG.empty()) {
        std::cout << currentBG;
    } else {
        std::cout << colors::RESET;
    }
    // A Képernyő törlése és kurzor haza (egyszerre!)
    // Clear Screen and Cursor Home (at the same time!)
   std::cout << "\x1B[2J\x1B[H\x1B[3J" << std::flush;
}
/*#ifdef _WIN32
    // Ez a Windows saját belső parancsa, ami
    // kényszeríti a konzolablakot a teljes törlésre.
    std::system("cls");
#else
    // Linux / Android / macOS (Termuxban ez tökéletes)
    std::cout << "\033[2J\033[H" << std::flush;
#endif

    // A törlés UTÁN állítjuk be a színt, hogy ne vesszen el
    if (useColors && !currentBG.empty()) {
        std::cout << currentBG << std::flush;
    } else {
        std::cout << colors::RESET << std::flush;
    }
}*/

/**
 * @brief Clears the input buffer. || Törli a bemeneti puffert.
 *
 * @details
 * EN:
 * This function discards all characters currently in the standard input buffer
 * up to and including the next newline character. This is used to prevent
 * unwanted input from affecting subsequent reads.
 *
 * HU:
 * Ez a függvény eldobja az összes karaktert, amely jelenleg a szabványos bemeneti pufferben van,
 * egészen a következő újsor karakterig bezárólag. Ezt arra használják, hogy megakadályozzák
 * a nem kívánt bemenet hatását a későbbi olvasásokra.
 */
// Letöröljük a bent maradt puffert ha szükséges
// Clear the remaining buffer if necessary it
void pufferDelete() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Logs an error message to a file. || Hibaüzenetet naplóz egy fájlba.
 *
 * @details
 * EN:
 * Appends a timestamped error message to "error.log". This helps in debugging
 * and tracking unexpected issues during program execution.
 *
 * HU:
 * Időbélyeggel ellátott hibaüzenetet fűz az "error.log" fájlhoz. Ez segít a hibakeresésben
 * és a váratlan problémák nyomon követésében a program futása során.
 *
 * @param functionName The name of the function where the error occurred. || Annak a függvénynek a neve, ahol a hiba történt.
 * @param errorMessage The detailed error message. || A részletes hibaüzenet.
 */
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

/**
 * @brief Logs a word pair that was answered incorrectly to a mistake file. || Hibásan megválaszolt szópárt naplóz egy hiba fájlba.
 *
 * @details
 * EN:
 * This function creates a "data/mistakes" directory if it doesn't exist,
 * and appends the given WordPair (including pronunciation if available)
 * to "data/mistakes/mistakes.data".
 *
 * HU:
 * Ez a függvény létrehoz egy "data/mistakes" könyvtárat, ha nem létezik,
 * és hozzáfűzi a megadott WordPair-t (beleértve a kiejtést is, ha elérhető)
 * a "data/mistakes/mistakes.data" fájlhoz.
 *
 * @param word The WordPair to be logged as a mistake. || A hibaként naplózandó WordPair.
 */
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

/**
 * @brief Plays a system beep sound. || Rendszer hangjelzést játszik le.
 *
 * @details
 * EN:
 * Plays a beep sound with a specified frequency and duration on Windows.
 * On other platforms (Linux/macOS), it outputs the ANSI bell character.
 * The sound is only played if the global 'useSound' setting is true.
 *
 * HU:
 * Hangjelzést játszik le megadott frekvenciával és időtartammal Windows-on.
 * Más platformokon (Linux/macOS) az ANSI csengő karaktert adja ki.
 * A hang csak akkor játszódik le, ha a globális 'useSound' beállítás igaz.
 *
 * @param frequency The frequency of the beep in Hz (Windows only). || A hangjelzés frekvenciája Hz-ben (csak Windows).
 * @param duration The duration of the beep in milliseconds (Windows only). || A hangjelzés időtartama milliszekundumban (csak Windows).
 */
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

/**
 * @brief Removes punctuation from a string. || Eltávolítja az írásjeleket egy sztringből.
 *
 * @details
 * EN:
 * Iterates through the input string and removes common punctuation marks
 * (exclamation mark, question mark, period, comma, semicolon).
 *
 * HU:
 * Végigmegy a bemeneti sztringen, és eltávolítja a gyakori írásjeleket
 * (felkiáltójel, kérdőjel, pont, vessző, pontosvessző).
 *
 * @param s The input string. || A bemeneti sztring.
 * @return The string without punctuation. || Az írásjelek nélküli sztring.
 */
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

/**
 * @brief Removes accented characters from a string, replacing them with their base equivalents. || Eltávolítja az ékezetes karaktereket egy sztringből, alap megfelelőikre cserélve.
 *
 * @details
 * EN:
 * This function converts common Hungarian accented UTF-8 characters to their
 * non-accented ASCII equivalents (e.g., 'á' to 'a'). It uses a static map
 * for efficient lookup.
 *
 * HU:
 * Ez a függvény a gyakori magyar ékezetes UTF-8 karaktereket
 * ékezet nélküli ASCII megfelelőikre alakítja (pl. 'á' -> 'a').
 * Statikus térképet használ a hatékony kereséshez.
 *
 * @param s The input string. || A bemeneti sztring.
 * @return The string with accents removed. || Az ékezetek nélküli sztring.
 */
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
// Trimmelés és kisbetűsítés
// Trim and lowercase
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
```