//
// Created by AtiBexx2 on 2026. 04. 04.
//

#ifndef ENGLISH_CREATEVOCAB_H
#define ENGLISH_CREATEVOCAB_H
#include <string>
#include <fstream>

enum class FileAction {
    DELETE,
    RENAME,
    MOVE,
    COPY,
    NONE
};

enum class FileCreationAction {
    CONTINUE, // Mehet tovább a fájl/mappa bekérése || You can proceed to request the file/folder.
    EXIT, // Kilépés a createVocab() függvényből || Exit from the createVocab() function
    COMMAND_EXECUTED // Jelzi a programnak, hogy kezdje újra a bekérést || Tells the program to start the request again
};


void createVocab();
void wordsPairTotal(bool isExiting = false);
void choiceMenu();
int handleInput(const std::string& input, std::ofstream& file, bool allowEmpty);
FileCreationAction handleFileCreationInput(const std::string& input);
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
