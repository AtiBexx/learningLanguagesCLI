/**
 * @file cliFileReading.cpp
 * @brief CLI file and folder management implementation / CLI fájl- és mappakezelő megvalósítás
 *
 * @details
 * EN:
 * Implements command-line file and directory operations such as:
 * - Safe path validation
 * - Copying, deleting, moving, renaming
 * - File editing using external editor
 * - Directory listing (cross-platform: Windows / Linux)
 * - Interactive navigation and selection
 *
 * HU:
 * Parancssoros fájl- és mappakezelő műveletek megvalósítása:
 * - Biztonságos útvonal ellenőrzés
 * - Másolás, törlés, áthelyezés, átnevezés
 * - Fájl szerkesztése külső editorral
 * - Könyvtár listázás (Windows / Linux támogatás)
 * - Interaktív navigáció és kiválasztás
 */

#include "cliFileReading.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>   // system()
#include <cctype>    // isalnum()
#include <algorithm> // std::all_of()
#include "../Editor/osEditor.h"
#include "dataFileReading.h"
#include "../Common/generalFunctions.h"
#include "../Quiz/programQuiz.h"


// Platform választás a fájlkezeléshez
#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h> // stat() függvényhez
#endif

using std::vector;
using std::string;
using std::cout;
using std::endl;

// --- BIZTONSÁGI ÉS FÁJLKEZELŐ SEGÉDFÜGGVÉNYEK ---
// --- SECURITY AND FILE HANDLING UTILITIES ---

/**
 * @brief Path safety validation / Útvonal biztonsági ellenőrzés
 *
 * @param path Input file or directory path
 * @return true if safe, false otherwise
 *
 * @details
 * EN:
 * Validates the given path to prevent dangerous operations.
 * Blocks:
 * - Empty or too long paths
 * - ".." directory traversal
 * - Dangerous commands (e.g. rm, format)
 * - Invalid characters
 *
 * HU:
 * Ellenőrzi az útvonal biztonságosságát.
 * Tiltja:
 * - Üres vagy túl hosszú útvonalakat
 * - ".." könyvtár visszalépést
 * - Veszélyes parancsokat (pl. rm, format)
 * - Érvénytelen karaktereket
 */
bool isPathSafe(const std::string& path) {
    if (path.empty() || path.length() > 255) return false;
    if (path.find("..") != std::string::npos) return false;
    string lowerPath = toLowerCase(path);
    if (lowerPath.find("format") != std::string::npos || lowerPath.find("rm ") != std::string::npos) return false;
    return std::all_of(path.begin(), path.end(), [](unsigned char c) {
        return std::isalnum(c) || c == '/' || c == '\\' || c == '.' || c == '_' || c == '-' || c == ' ';
    });
}

/**
 * @brief Copy file or folder / Fájl vagy mappa másolása
 *
 * @param srcPath Source path
 * @param isDirectory True if directory
 *
 * @details
 * EN:
 * Copies a file or directory using system commands.
 * Uses platform-specific commands (Windows/Linux).
 *
 * HU:
 * Fájlt vagy mappát másol rendszerparancsok segítségével.
 * Platformfüggő megoldást használ (Windows/Linux).
 */
void copyFileFolders(const std::string& srcPath, bool isDirectory) {
    const struct CopyFileFolders &CFF = copyFileFoldersTranslations [static_cast<int>(programUiLanguage)];

    if (!isPathSafe(srcPath))
    {
        logError("copyFileFolders", "Dangerous source path: " + srcPath);

        cout << CFF.errorDangerousPath << endl;
        return;
    }
    cout << CFF.toBeCopied << srcPath << endl;
    cout << CFF.newNameNewPath;
    string destName; std::getline(std::cin, destName);
    string destPath = trim(destName);
    if (!isPathSafe(destPath)) { cout << CFF.errorDangerousGoalAndPath << endl; std::cin.get(); return; }
    string command;
#ifdef _WIN32
    command = isDirectory ? "xcopy /E /I /H /Y \"" + srcPath + "\" \"" + destPath + "\"" : "copy /Y \"" + srcPath + "\" \"" + destPath + "\"";
#else
    command = "cp -r -p \"" + srcPath + "\" \"" + destPath + "\"";
#endif
    if (std::system(command.c_str()) == 0) cout << CFF.successCopying << endl;
    else cout << CFF.anErrorOccurred << endl;
    std::cin.get();
}

/**
 * @brief Delete file or folder / Fájl vagy mappa törlése
 *
 * @param fullPath Target path
 * @param isDirectory True if directory
 *
 * @details
 * EN:
 * Deletes file or directory after user confirmation.
 *
 * HU:
 * Törli a fájlt vagy mappát felhasználói megerősítés után.
 */
void deleteFileFolders(const std::string& fullPath, bool isDirectory) {
    const struct DeleteFileFolders &DDFF = deleteFileFoldersTranslations [static_cast<int>(programUiLanguage)];

    if (!isPathSafe(fullPath))
    {
        logError("deleteFileFolders", DDFF.errorDfDangerousPath + fullPath);
        cout << DDFF.errorDfDangerousPath << endl; std::cin.get();
        return;
    }
    cout << DDFF.confirmationDelete << fullPath << "? (y/n): ";
    string confirm; std::getline(std::cin, confirm);
    if (toLowerCase(trim(confirm)) != "y") return;
    string command;
#ifdef _WIN32
    command = isDirectory ? "rd /s /q \"" + fullPath + "\"" : "del /f /q \"" + fullPath + "\"";
#else
    command = isDirectory ? "rm -rf \"" + fullPath + "\"" : "rm -f \"" + fullPath + "\"";
#endif
    if (std::system(command.c_str()) == 0) std::cout << DDFF.successDelete << std::endl;
    std::cin.get();
}

/**
 * @brief Move file or folder / Fájl vagy mappa áthelyezése
 *
 * @param srcPath Source path
 * @param isDirectory True if directory
 *
 * @details
 * EN:
 * Moves file or directory to a new location.
 *
 * HU:
 * Áthelyezi a fájlt vagy mappát egy új helyre.
 */
void movingFileFolders(const std::string& srcPath, bool isDirectory) {
    const struct MovingFileFolders &MFF = movingFileFoldersTranslations [static_cast<int>(programUiLanguage)];

    if (!isPathSafe(srcPath)) return;
    cout << MFF.toBeMoved << srcPath << MFF.newNameNewPath;
    string destName; std::getline(std::cin, destName);
    string destPath = trim(destName);
    if (!isPathSafe(destPath)) return;
    string command;
#ifdef _WIN32
    command = "move /Y \"" + srcPath + "\" \"" + destPath + "\"";
#else
    command = "mv -f \"" + srcPath + "\" \"" + destPath + "\"";
#endif
    std::system(command.c_str());
    std::cin.get();
}

/**
 * @brief Rename file or folder / Fájl vagy mappa átnevezése
 *
 * @param srcPath Original path
 * @param isDirectory True if directory
 *
 * @details
 * EN:
 * Renames a file or directory while preserving its location.
 *
 * HU:
 * Átnevezi a fájlt vagy mappát a hely megtartásával.
 */
void reNameFileFolders(const std::string& srcPath, bool isDirectory) {
    const RenameFilesAndFolders &RFAF = renameFilesAndFoldersTranslations [static_cast<int>(programUiLanguage)];

    if (!isPathSafe(srcPath)) return;
    cout << RFAF.toBeRenamed << srcPath << RFAF.newName;

    string newName; std::getline(std::cin, newName);
    newName = trim(newName);
    size_t lastSlash = srcPath.find_last_of("/\\");
    string destPath = ((lastSlash == string::npos) ? "" : srcPath.substr(0, lastSlash + 1)) + newName;
    if (!isPathSafe(destPath)) return;
    string command;
#ifdef _WIN32
    command = "move /Y \"" + srcPath + "\" \"" + destPath + "\"";
#else
    command = "mv -f \"" + srcPath + "\" \"" + destPath + "\"";
#endif
    std::system(command.c_str());
    std::cin.get();
}

/**
 * @brief Open file in editor / Fájl megnyitása szerkesztőben
 *
 * @param fullPath File path
 *
 * @details
 * EN:
 * Opens file using platform-specific CLI editor.
 *
 * HU:
 * Megnyitja a fájlt platformfüggő parancssoros szerkesztővel.
 */
void editFile(const std::string& fullPath) {
    if (isPathSafe(fullPath)) openFileInEditor(fullPath);
    std::cin.get();
}

/**
 * @brief List directory contents / Könyvtár tartalmának listázása
 *
 * @param directory Target directory
 * @return vector of FileEntry
 *
 * @details
 * EN:
 * Lists files and folders in a directory.
 * Filters only:
 * - directories
 * - ".data" files
 *
 * Supports Windows and Linux.
 *
 * HU:
 * Kilistázza a könyvtár tartalmát.
 * Csak:
 * - mappák
 * - ".data" fájlok
 *
 * Windows és Linux támogatással.
 */
// Segédfüggvény a fájlok és mappák listázására
vector<FileEntry> listFiles(const std::string &directory) {
    vector<FileEntry> entriesFolderAndFiles;
#ifdef _WIN32
    string searchPath = directory + "\\*";
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(searchPath.c_str(), &findFileData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            string filename = findFileData.cFileName;
            if (filename != "." && filename != "..") {
                bool isDir = (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
                // SZŰRÉS: Csak mappák vagy .data fájlok
                // FILTER: Only folders or .data files
                if (isDir || (filename.size() >= 5 && filename.substr(filename.size() - 5) == ".data")) {
                    FileEntry entry; entry.name = filename; entry.isDirectory = isDir;
                    entriesFolderAndFiles.push_back(entry);
                }
            }
        } while (FindNextFile(hFind, &findFileData));
        FindClose(hFind);
    }
#else
    DIR *dir = opendir(directory.c_str());
    if (dir != NULL) {
        struct dirent *ent;
        while ((ent = readdir(dir)) != NULL) {
            string filename = ent->d_name;
            if (filename != "." && filename != "..") {
                string fullPath = directory + "/" + filename;
                struct stat path_stat;
                bool isDir = (stat(fullPath.c_str(), &path_stat) == 0) ? S_ISDIR(path_stat.st_mode) : false;
                // SZŰRÉS: Csak mappák vagy .data fájlok
                if (isDir || (filename.size() >= 5 && filename.substr(filename.size() - 5) == ".data")) {
                    FileEntry entry; entry.name = filename; entry.isDirectory = isDir;
                    entriesFolderAndFiles.push_back(entry);
                }
            }
        }
        closedir(dir);
    }
#endif
    return entriesFolderAndFiles;
}

/**
 * @brief Interactive file navigator / Interaktív fájlböngésző
 *
 * @details
 * EN:
 * Provides CLI navigation inside "./data" directory.
 * Features:
 * - Navigate folders
 * - Select files
 * - Start quiz for ".data" files
 * - Basic command handling
 *
 * HU:
 * Parancssoros navigációt biztosít a "./data" mappában.
 * Funkciók:
 * - Mappák közötti lépkedés
 * - Fájl kiválasztás
 * - ".data" fájl esetén quiz indítás
 * - Alap parancskezelés
 */
void listAndSelectFile() {
    const ListAndSelectedFile &LASFile = listAndSelectedFilesTranslations [static_cast<int>(programUiLanguage)];

    const string ROOT_DIR ="./data";
    string path = ROOT_DIR;
    for (;;) {
        screenWipe();
        cout << LASFile.currentlyFolder << path << " ---\n";
        vector<FileEntry> entries = listFiles(path);
        if (entries.empty()) cout << LASFile.emptyFolder;
        else for (const FileEntry& e : entries) cout << (e.isDirectory ? LASFile.isDirectory : "        ") << e.name << "\n";
        cout << LASFile.commands;
        string input; std::getline(std::cin, input);
        input = trim(input);
        if (toLowerCase(input) == "exit") return;
        if (input == "..") {
            if (path.length() > ROOT_DIR.length()) path = path.substr(0, path.find_last_of("/\\"));
            continue;
        }
        // ... (Parancsok kezelése del, cp, mv, rn, edit ugyanúgy marad) ...
        // a fájl megnyitásához
        // ... (Command handling del, cp, mv, rn, edit remains the same) ...
        // to open the file
        bool found = false; bool isDir = false;
        for (const auto& e : entries) if (e.name == input) { found = true; isDir = e.isDirectory; break; }
        if (found) {
            string fullPath = path;
             fullPath.append("/").append(input);
            if (isDir) path = fullPath;
            else if (fullPath.size() >= 5 && fullPath.substr(fullPath.size() - 5) == ".data") {
                startQuiz(loadWords(fullPath));
            }else {
                const LlistAndSelectedFile &LlSF = LlistAndSelectedFileTranslations [static_cast<int>(programUiLanguage)];

                logError("listAndSelectFile", LlSF.errorFile  + fullPath);
                cout << LlSF.errorFile << endl;
                waitToEnter();
            }
        }
    }
}
