//
// Created by AtiBexx2 on 2026. 04. 04.
//

#ifndef ENGLISH_CREATEVOCAB_H
#define ENGLISH_CREATEVOCAB_H
#include <string>
#include <fstream>

void createVocab();
void wordsPairTotal(bool isExiting = false);
void choiceMenu();

// Változók deklarálása
extern unsigned long long wordCount;
extern std::string fileName;
extern std::string fullPath;
//extern std::ios_base::openmode mode = std::ios::app;
//Az std::ios_base::openmode egy speciális típus a C++-ban,
//ami azt mondja meg a fájlkezelőnek (std::ofstream),
//hogy hogyan nyissa meg a fájlt.
extern std::ios_base::openmode mode;



#endif //ENGLISH_CREATEVOCAB_H
