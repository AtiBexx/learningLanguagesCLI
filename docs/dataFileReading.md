```
/**
 * @file dataFileReading.cpp
 * @author AtiBexx2
 * @date 2026-03-20
 *
 * @brief Implementation of file reading and word processing utilities.
 *        Fájlbeolvasó és szófeldolgozó segédfüggvények implementációja.
 *
 * @details
 * EN:
 * This source file contains the implementation of helper functions used for:
 * - Converting strings to lowercase
 * - Trimming whitespace from strings
 * - Checking user answers against multiple valid answers
 * - Loading word pairs from .data files
 *
 * The module is designed for CLI-based quiz applications where word pairs
 * (English -> Hungarian) are stored in text files and processed dynamically.
 *
 * It also supports:
 * - Optional pronunciation parsing using [brackets]
 * - Flexible separators (-> or >)
 * - Input normalization for reliable comparison
 *
 * HU:
 * Ez a forrásfájl tartalmazza a segédfüggvények implementációját, amelyek:
 * - Sztringek kisbetűssé alakítására szolgálnak
 * - Felesleges szóközök eltávolítását végzik (trim)
 * - Felhasználói válaszok összehasonlítását több lehetséges helyes válasszal
 * - Szópárok betöltését végzik .data fájlokból
 *
 * A modul kifejezetten parancssoros (CLI) kvíz alkalmazásokhoz készült,
 * ahol az angol-magyar szópárok fájlokban vannak tárolva.
 *
 * Támogatja továbbá:
 * - Kiejtés feldolgozását [zárójelek] között
 * - Rugalmas elválasztókat (-> vagy >)
 * - Bevitel normalizálást a pontos összehasonlításhoz
 */

#include "dataFileReading.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iostream>

#include "generalFunctions.h"
#include "translations.h"


//Régi stílus a röviditésre
//typedef std::string string;
//ez az uj stílus
using string = std::string;
using stringstream = std::stringstream;
using std::transform;
using std::vector;
using std::ifstream;
//Mivel a getline nem változó hanem függvény ezért
//using std::getline; vagy auto getline = std::getline;
using std::getline;


//kisbetüsítésre átalakítunk mindent kisbetűre
//convert everything to lowercase
string toLowerCase(string s) {
    //Nagybetűsítésre ::toupper a tolower helyett
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    return s;
}

// függvény a szóközök levágására (trim)
// function to trim spaces (trim)
string trim(const std::string& str) {
    //megkeressük az első karaktert ami nem szóköz
    size_t first = str.find_first_not_of(" \t\n\r");
    //std::string::npos az jelenti nincs megtalálva
    if (first == std::string::npos) {
        return("");
    }else {
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, (last - first + 1)); ////+1 a szöveg hossza miatt
    }
}

//függvény a helyes válaszok ellenőrzésére/összehasonlítására
//function to check/compare correct answers
bool checkMultipleAnswers(const std::string& userAnswer, const std::string& correctAnswersString) {
    string cleanedUserAnswer = cleanString(userAnswer);
    stringstream ss(trim(correctAnswersString));
    string slice;

    while (getline(ss, slice, ',')) {
        if (cleanString(slice) == cleanedUserAnswer) {
            return true;
        }
    }
    return false;
}

// A szavak betöltése a fájlból
// Load words from file
vector<WordPair> loadWords(const std::string &filename) {
    vector<WordPair> words;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        //const W_wordPair &wWordPair = wordPairErrorTranslations [static_cast<int>(programUiLanguage)];
        //logError("loadWords", wWordPair.ErrorOpenedFile);

        logError("loadWords", getTranslation("W_wordPair.ErrorOpenedFile"));
        std::cerr << getTranslation("W_wordPair.ErrorOpenedFile") << " " << filename << "\n" << std::flush;
        //std:: cerr << wWordPair.ErrorOpenedFile <<" "<<filename << std::endl;
        return words;
    }
    while (getline(file, line)) {
        if (line.empty()) continue;

        WordPair currentWord;

        //Megkeresük a kiejtést ha van [ ] között
        //Find the pronunciation if it is between [ ]
        size_t openBracket = line.find('[');
        size_t closeBracket = line.find(']' , openBracket);

        if (openBracket != string::npos && closeBracket != string::npos) {
            currentWord.pronunciation = line.substr(openBracket + 1, closeBracket - openBracket - 1);
            currentWord.pronunciation = trim(currentWord.pronunciation);
            line = line.substr(0, openBracket);
        }

        //Megkeresük az elválasztó vonalat
        //Find the dividing line
        size_t separatorPos = line.find("->");

        // 2 karaktert ugrunk mert"->" ez 2 karakter és ez után olvasunk
        // we skip 2 characters because "->" is 2 characters and we read after that
        int skipChars = 2;

        // Ha nincs meg megkeressük ezt '>' ez "->" helyett
        // If it doesn't exist, we'll look for this '>' instead of "->"
        if (separatorPos == string::npos) {
            separatorPos = line.find('>');
            skipChars = 1; //itt csak egyet ugrunk || just one jumping here
        }

        if (separatorPos != string::npos) {
            currentWord.targetLangMeaning = line.substr(0, separatorPos);

            size_t hungarianStart = separatorPos + skipChars;
            if (hungarianStart < line.length()) {
                currentWord.motherLangMeaning = line.substr(hungarianStart);
    }
            //Trim
            currentWord.targetLangMeaning = trim(currentWord.targetLangMeaning);
            currentWord.motherLangMeaning = trim(currentWord.motherLangMeaning);

            // Ha az angol szó és a magyar szó se üres akkor rakjuk be a vektorba
            // If neither the English word nor the Hungarian word is empty, insert it into the vector
            if (!currentWord.targetLangMeaning.empty() && !currentWord.motherLangMeaning.empty()) {
                words.push_back(currentWord);
            }
        }
    }
    file.close();
    return words;
}
```

