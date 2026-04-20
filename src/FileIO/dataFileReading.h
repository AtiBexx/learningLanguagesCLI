/**
* @file dataFileReading.h
 * @author AtiBexx2
 * @date 2026-03-20
 *
 * @brief File reading and word processing utilities.
 *        Fájlbeolvasó és szófeldolgozó segédfüggvények.
 *
 * @details
 * EN:
 * This module provides helper functions for loading word pairs from files,
 * processing strings (trimming, lowercase conversion), and validating user
 * input against multiple possible correct answers. It is mainly used for
 * quiz-based applications.
 *
 * HU:
 * Ez a modul segédfüggvényeket biztosít szópárok fájlból történő betöltéséhez,
 * szövegfeldolgozáshoz (levágás, kisbetűsítés), valamint felhasználói válaszok
 * ellenőrzéséhez több lehetséges helyes válasz esetén. Főként kvíz alapú
 * alkalmazásokhoz készült.
 */

#ifndef ENGLISH_FILEREADING_H
#define ENGLISH_FILEREADING_H
#include <string>
#include <vector>

// változók a szavak betöltésehez/párosításához
// variables for loading/matching words
struct WordPair {
    std::string targetLangMeaning;
    std::string motherLangMeaning;
    std::string pronunciation;
};


//Szavak betöltésére a fájlból
//Load words from the file
std::vector<WordPair> loadWords(const std::string& filename);

// Szöveg levágására a felesleges szóközök eltávolítására
// To trim text to remove unnecessary spaces
std::string trim(const std::string& str);

// a helyes válasz(ok) ellenőrzésére összehasonlítására
// compare to check for correct answer(s)
bool checkMultipleAnswers(const std::string& userAnswer, const std::string& correctAnswersString);

// kisbetüsítésre azaz kisbetűs átalakításra
// for lowercase conversion
std::string toLowerCase(std::string s);




#endif //ENGLISH_FILEREADING_H
