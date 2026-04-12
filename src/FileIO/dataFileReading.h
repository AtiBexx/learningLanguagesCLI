//
// Created by AtiBexx2 on 2026. 03. 20.
//

#ifndef ENGLISH_FILEREADING_H
#define ENGLISH_FILEREADING_H
#include <string>
#include <vector>

// változók a szavak betöltésehez/párosításához
struct WordPair {
    std::string english;
    std::string hungarian;
    std::string pronunciation;
};


//Szavak betöltésére a fájlból
std::vector<WordPair> loadwords(const std::string& filename);
// Szöveg levágására a felesleges szóközök eltávolítására
std::string trim(const std::string& str);
// a helyes válasz(ok) ellenőrzésére összehasonlítására
bool checkMultipleAnswers(const std::string& userAnswer, const std::string& correctAnswersString);
// kisbetüsítésre azaz kisbetűs átalakításra
std::string toLowerCase(std::string s);
// A szavak betöltésére


#endif //ENGLISH_FILEREADING_H
