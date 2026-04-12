//
// Created by AtiBexx2 on 2026. 03. 20.
//

#include "dataFileReading.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iostream>


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
string toLowerCase(string s) {
    //Nagybetűsítésre ::toupper a tolower helyett
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    return s;
}
/*
string toLowerCase(string s) {
    // Végigmegyünk a karaktereken egyenként
    for (size_t i = 0; i < s.length(); ++i) {
        // Minden karaktert átalakítunk kisbetűssé
        s[i] = std::tolower(s[i]);
    }
    return s;
}
 */ //vagy
/*
string toLowerCase(string s) {
    // Referenciával (&) megyünk végig, hogy módosíthassuk az eredeti karaktert
    for (char &c : s) {
        c = std::tolower(c);
    }
    return s;
}
 */


// függvény a szóközök levágására (trim)
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
bool checkMultipleAnswers(const std::string& userAnswer, const std::string& correctAnswersString) {
    string trimmedUserAnswer = toLowerCase(trim(userAnswer));
    stringstream ss(trim(correctAnswersString));
    string slice;

    while (getline(ss, slice, ',')) {
        if (toLowerCase(trim(slice)) == trimmedUserAnswer) {
            return true;
        }
    }
    return false;
}

// A szavak betöltése a fájlból
vector<WordPair> loadwords(const std::string &filename) {
    vector<WordPair> words;
    ifstream file(filename);
    string line;
// ha megnyitjuk a fájlt
    if (!file.is_open()) {
        std:: cerr << "Hiba a fájlt nem sikerült megnyitni:" <<filename << std::endl;
        return words;
    }
    while (getline(file, line)) {
        if (line.empty()) continue;

        WordPair currentWord;

        //Megkeresük a kiejtést ha van [ ] között
        size_t openBracket = line.find('[');
        size_t closeBracket = line.find(']' , openBracket);

        if (openBracket != string::npos && closeBracket != string::npos) {
            currentWord.pronunciation = line.substr(openBracket + 1, closeBracket - openBracket - 1);
            currentWord.pronunciation = trim(currentWord.pronunciation);
            line = line.substr(0, openBracket);
        }

        //Megkeresük az elválasztó vonalat
        size_t separatorPos = line.find("->");
        int skipChars = 2;// 2 karaktert ugrunk mert"->" ez 2 karakter és ez után olvasunk
        // Ha nincs meg megkerük ezt '>' ez "->" helyett
        if (separatorPos == string::npos) {
            separatorPos = line.find('>');
            skipChars = 1; //itt csak egyet ugrunk
        }

        if (separatorPos != string::npos) {
            currentWord.english = line.substr(0, separatorPos);

            size_t hungarianStart = separatorPos + skipChars;
            if (hungarianStart < line.length()) {
                currentWord.hungarian = line.substr(hungarianStart);
    }
            //Trim
            currentWord.english = trim(currentWord.english);
            currentWord.hungarian = trim(currentWord.hungarian);

            // Ha az angol szó és a magyar szó se üres akkor rakjuk be a vektorba
            if (!currentWord.english.empty() && !currentWord.hungarian.empty()) {
                words.push_back(currentWord);
            }
        }
    }
    file.close();
    return words;
}

