#include "generalFunctions.h"
#include "../Translate/translations.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>

#include "dataFileReading.h"
#include "settings.h"
#include "Settings/colors.h"


void explanation() {
    const ExplanationStrings& strings = explanationTranslations[static_cast<int>(currentLanguage)];
    const BackStrings& back = backbackTranslations[static_cast<int>(currentLanguage)];

    screenWipe();//letöröljük a képernyőt
    std::cout << strings.description << std::endl;
    std::cout << strings.instruction1 << std::endl;
    std::cout << strings.instruction2 << std::endl;
    std::cout << strings.goodluck << std::endl;
    std::cout << "\n" << back.backStrings << std::endl;

    // Buffer törlése, hogy a cin.get() biztosan várjon
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void exiting() {
    screenWipe();
    const ExitingStrings& strings = exitingTranslations[static_cast<int>(currentLanguage)];
    std::cout << strings.exiting << std::endl;

    // Buffer törlése, hogy a cin.get() biztosan várjon
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
void screenWipe () {
    std::cout << "\x1B[2J\x1B[H" << std::flush; //letöröljük a képernyő tartalmát
    //ha van beállítva háttérszín akkor festünk
    if (!currentBG.empty())
    {
        std::cout << currentBG;
    }
        std::cout << std::flush;
}
void pufferDelete() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
// rendszerhibák mentése
void logError(const std::string& functionName, const std::string& errorMessage) {

    std::ofstream logFile("error.log , std::ios::app"); //hozzáfűzés mód
    if (logFile.is_open()) {

        //az időbélyeg lekérése
        std::time_t now = std::time(nullptr);
        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        //Mentés és hibakód/hibaüzenet [IDŐ SZERINT]
        logFile << "[" << timestamp << "] [" << functionName << "] " << errorMessage << std::endl;
        logFile.close();
    }
}

// Az elrontot szópárok írása fájlba
void logMistake(const WordPair& word)
{
    //ha WINDOWS
#ifdef _WIN32
    std::system("if not exist data\\mistakes mkdir data\\mistakes");
    std::string path = "data\\mistakes\\mistakes.data";

    //HA LINUX VAGY ANDROID VAGY MÁS
    #else
    std::system("mkdir -p data/mistakes");
    std::string path = "data/mistakes/mistakes.data";
#endif

    //Hozzafüzés módban nyitjuk meg hogy gyüljenek a hibák
    std::ofstream mistakeFile(path, std::ios::app);
    if (mistakeFile.is_open())
    {
        //elmentjük ugyanabban a formátumban a fájl
        mistakeFile << word.english << " -> " << word.hungarian;
        if (!word.pronunciation.empty())
        {
            mistakeFile << " (" << word.pronunciation << ")";
        }
        mistakeFile << "\n";
        mistakeFile.close();
        }
    }

void playBeep(int frequency , int duration ) {
    if (!useSound) return; // ha ki van kapcsolva

#ifdef _WIN32
    // Windowsos beep: frekvencia (Hz) és időtartam (ms)
    Beep(frequency, duration);
#else
    // Linux/Termux/macOS: ANSI Bell karakter
    std::cout << "\a" << std::flush;
#endif
}



