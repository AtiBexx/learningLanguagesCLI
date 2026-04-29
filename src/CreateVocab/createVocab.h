/**
* @file createVocab.h
 * @brief Header for vocabulary file creation and command handling.
 * @brief Szótár fájl létrehozásához és parancskezeléshez tartozó fejléc.
 *
 * @details
 * EN:
 * This header defines the core structures, enums, and function declarations
 * used for creating and managing vocabulary files in a CLI application.
 *
 * It includes:
 * - File operation enums (delete, rename, move, copy)
 * - File creation flow control enums
 * - Function declarations for vocabulary creation and input handling
 * - External global variables used across the module
 *
 * HU:
 * Ez a fejléc definiálja azokat az alapvető struktúrákat, enumokat és
 * függvény deklarációkat, amelyek a szótár fájlok létrehozásához és
 * kezeléséhez szükségesek egy parancssoros alkalmazásban.
 *
 * Tartalmazza:
 * - Fájlműveletek enumjait (törlés, átnevezés, mozgatás, másolás)
 * - Fájl létrehozási folyamat vezérlését szolgáló enumokat
 * - Függvény deklarációkat a szótár kezeléshez
 * - Globális változók deklarációit
 *
 * @author AtiBexx2
 * @date 2026-04-04
 */

/**
 * @enum FileAction
 * @brief File operation types.
 * @brief Fájlműveletek típusai.
 */

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
bool choiceMenu();
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
