/**
* @file cliFileReading.h
 * @author AtiBexx2
 *
 * @brief CLI-based file and directory management utilities.
 *        Parancssoros fájl- és mappakezelő segédfüggvények.
 *
 * @details
 * EN:
 * This module provides functions for listing, selecting, copying, deleting,
 * moving, renaming, and editing files and directories in a CLI environment.
 * It also includes basic path validation for safety.
 *
 * HU:
 * Ez a modul parancssoros környezetben biztosít függvényeket fájlok és mappák
 * listázására, kiválasztására, másolására, törlésére, áthelyezésére,
 * átnevezésére és szerkesztésére. Tartalmaz alapvető útvonal-ellenőrzést is
 * biztonsági célból.
 */


#ifndef ENGLISH_CLIFILEREADING_H
#define ENGLISH_CLIFILEREADING_H
#include <string>
#include <vector>

/*enum class FileSelectionMode {
    QUIZ,   // Fájl kiválasztása kvíz indításához
    EDIT    // Fájl kiválasztása szerkesztéshez
};*/


// Struktúra definíciók
struct FileEntry {
    std::string name;
    bool isDirectory;
};

// Segédfüggvény a fájlok és mappák listázására
// Helper function for listing files and folders
std::vector<FileEntry> listFiles(const std::string &directory);

// A fájlok kivalasztáshoz
// To select files
void listAndSelectFile();

//Fájlok és mappák tőrlésére
//To delete files and folders
void deleteFileFolders(const std::string& fullPath, bool isDirectory);

//Fájlok és mappák másolására
//For copying files and folders
void copyFileFolders(const std::string& srcPath, bool isDirectory);

//Fájlok és Vagy mappák áthelyezésére
//To move files and/or folders
void movingFileFolders(const std::string& srcPath, bool isDirectory);

//Fájlok vagy Mappák átnevezésére
//To rename files or folders
void reNameFileFolders(const std::string& srcPath, bool isDirectory);

// Fájl szerkesztésére
//To rename files or folders
void editFile(const std::string& fullPath);

//Karakterek engedélyezésére
//To enable characters
bool isPathSafe(const std::string& path);

// megvizsgálja, hogy a megadott útvonal egy létező mappa
// checks if the given path is an existing folder
bool isDirectory(const std::string& path);

/**
 * @brief Creates a new directory at the specified path. || Új könyvtárat hoz létre a megadott útvonalon.
 *
 * @details
 * EN:
 * This function attempts to create a new directory. It handles platform-specific
 * commands (mkdir on Linux/macOS, mkdir on Windows) and includes error handling.
 *
 * HU:
 * Ez a függvény megpróbál egy új könyvtárat létrehozni. Kezeli a platformspecifikus
 * parancsokat (mkdir Linux/macOS-en, mkdir Windows-on) és tartalmazza a hibakezelést.
 *
 * @param path The path of the directory to create. || A létrehozandó könyvtár útvonala.
 * @return True if the directory was created successfully or already exists, false otherwise. || Igaz, ha a könyvtár sikeresen létrejött vagy már létezik, egyébként hamis.
 */
bool createDirectory(const std::string& path);



#endif //ENGLISH_CLIFILEREADING_H
