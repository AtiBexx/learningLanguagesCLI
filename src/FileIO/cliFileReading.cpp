/**
 * @file cliFileReading.cpp
 * @brief CLI file and folder management implementation / CLI fájl- és mappakezelő megvalósítás
 */

#include "cliFileReading.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>   // system()
#include "../Editor/osEditor.h"
#include "dataFileReading.h"
#include "../Common/generalFunctions.h"
#include "../Quiz/programQuiz.h"
#include <sys/stat.h>

#include "newInput/platformInput.h"

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

// Segédfüggvény az útvonalak Windows-kompatibilisre alakításához
// Helper function to make paths Windows-compatible
std::string normalizePath(const std::string& path) {
    std::string normalizedPath = path;
#ifdef _WIN32
    std::replace(normalizedPath.begin(), normalizedPath.end(), '/', '\\');
#endif
    return normalizedPath;
}

// Ellenőrzi az útvonal biztonságosságát.
// Checks the safety of the path.
bool isPathSafe(const std::string& path) {
    if (path.empty() || path.length() > 255) return false;
    if (path.find("..") != std::string::npos) return false;

    string lowerPath = toLowerCase(path);
    if (lowerPath.find("format") != std::string::npos || lowerPath.find("rm ") != std::string::npos) return false;

    return std::all_of(path.begin(), path.end(), [](unsigned char c) {
        return c != ';' && c != '&' && c != '|' && c != '>' &&
               c != '<' && c != '*' && c != '?' && c != '"';
    });
}

// Fájlt vagy mappát másol
// Copy a file or folder
void copyFileFolders(const std::string& srcPath, bool isDirectory) {
    const struct CopyFileFolders &CFF = copyFileFoldersTranslations [static_cast<int>(programUiLanguage)];

    if (!isPathSafe(srcPath)) {
        logError("copyFileFolders", "Dangerous source path: " + srcPath);
        cout << CFF.errorDangerousPath << endl;
        waitToEnter();
        return;
    }
    cout << CFF.toBeCopied << srcPath << endl;
    cout << CFF.newNameNewPath;
    string destName; std::getline(std::cin, destName);
    string destPath = trim(destName);
    if (!isPathSafe(destPath)) {
        cout << CFF.errorDangerousGoalAndPath << endl;
        waitToEnter();
        return;
    }

    std::string nSrc = normalizePath(srcPath);
    std::string nDest = normalizePath(destPath);
    string command;
#ifdef _WIN32
    command = isDirectory ? "xcopy /E /I /H /Y \"" + nSrc + "\" \"" + nDest + "\"" : "copy /Y \"" + nSrc + "\" \"" + nDest + "\"";
#else
    command = "cp -r -p \"" + nSrc + "\" \"" + nDest + "\"";
#endif
    if (std::system(command.c_str()) == 0) cout << CFF.successCopying << endl;
    else cout << CFF.anErrorOccurred << endl;
    waitToEnter();
}

// Törli a fájlt vagy mappát
void deleteFileFolders(const std::string& fullPath, bool isDirectory) {
    const struct DeleteFileFolders &DDFF = deleteFileFoldersTranslations [static_cast<int>(programUiLanguage)];

    if (!isPathSafe(fullPath)) {
        logError("deleteFileFolders", DDFF.errorDfDangerousPath + fullPath);
        cout << DDFF.errorDfDangerousPath << endl;
        waitToEnter();
        return;
    }
    cout << DDFF.confirmationDelete << fullPath << "? (y/n): ";
    string confirm; std::getline(std::cin, confirm);

    if (toLowerCase(trim(confirm)) != "y") {
        std::cout << DDFF.interrupted <<"\n";
        waitToEnter();
        return;
    }

    std::string nPath = normalizePath(fullPath);
    string command;
#ifdef _WIN32
    command = isDirectory ? "rd /s /q \"" + nPath + "\"" : "del /f /q \"" + nPath + "\"";
#else
    command = isDirectory ? "rm -rf \"" + nPath + "\"" : "rm -f \"" + nPath + "\"";
#endif

    if (std::system(command.c_str()) == 0) {
        std::cout << DDFF.successDelete << std::endl;
    } else {
        std::cout << DDFF.errorDelete <<"\n";
    }
    waitToEnter();
}

// Áthelyezi a fájlt vagy mappát
void movingFileFolders(const std::string& srcPath, bool isDirectory) {
    const struct MovingFileFolders &MFF = movingFileFoldersTranslations [static_cast<int>(programUiLanguage)];
    if (!isPathSafe(srcPath)) { waitToEnter(); return; }

    cout << MFF.toBeMoved << srcPath << MFF.newNameNewPath;
    string destName; std::getline(std::cin, destName);
    string destPath = trim(destName);
    if (!isPathSafe(destPath)) { waitToEnter(); return; }

    std::string nSrc = normalizePath(srcPath);
    std::string nDest = normalizePath(destPath);
    string command;
#ifdef _WIN32
    command = "move /Y \"" + nSrc + "\" \"" + nDest + "\"";
#else
    command = "mv -f \"" + nSrc + "\" \"" + nDest + "\"";
#endif
    std::system(command.c_str());
    waitToEnter();
}

// Fájl vagy mappa átnevezése
void reNameFileFolders(const std::string& srcPath, bool isDirectory) {
    const RenameFilesAndFolders &RFAF = renameFilesAndFoldersTranslations [static_cast<int>(programUiLanguage)];
    if (!isPathSafe(srcPath)) { waitToEnter(); return; }

    cout << RFAF.toBeRenamed << srcPath << RFAF.newName;
    string newName; std::getline(std::cin, newName);
    newName = trim(newName);

    size_t lastSlash = srcPath.find_last_of("/\\");
    string destPath = ((lastSlash == string::npos) ? "" : srcPath.substr(0, lastSlash + 1)) + newName;
    if (!isPathSafe(destPath)) { waitToEnter(); return; }

    std::string nSrc = normalizePath(srcPath);
    std::string nDest = normalizePath(destPath);
    string command;
#ifdef _WIN32
    command = "move /Y \"" + nSrc + "\" \"" + nDest + "\"";
#else
    command = "mv -f \"" + nSrc + "\" \"" + nDest + "\"";
#endif
    std::system(command.c_str());
    waitToEnter();
}

// Fájl megnyitása szerkesztőben
void editFile(const std::string& fullPath) {
    if (isPathSafe(fullPath)) openFileInEditor(fullPath);
}

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

// Parancssoros navigáció a "./data" mappában
void listAndSelectFile() {
    const ListAndSelectedFile &LASFile = listAndSelectedFilesTranslations [static_cast<int>(programUiLanguage)];
    const string ROOT_DIR ="./data";
    string path = ROOT_DIR;
    for (;;) {
        screenWipe();
        cout << LASFile.currentlyFolder << path << " ---\n";
        vector<FileEntry> entries = listFiles(path);
        if (entries.empty()) cout << LASFile.emptyFolder;
        else
        {
            for (const FileEntry& e : entries)
                cout << (e.isDirectory ? LASFile.isDirectory : "        ") << e.name << "\n";
        }

        //cout << LASFile.commands;
        cout << LASFile.commands <<"\n";
        cout << LASFile.fullCommands <<"\n";

        InputResult inputResult = readLineWithHotkey(LASFile.choice);

        //---CTRL + C KEZELÉSE || CTRL + C HANDLING
        if (inputResult.exitTriggered)
        {
            return;
        }
        string input = inputResult.text;
        input = trim(input);
        string lowerInput = toLowerCase(input);

        if (lowerInput == "exit" || lowerInput == "e" ) return;

        if (lowerInput == "..") {
            if (path.length() > ROOT_DIR.length())
            {
                size_t lastSlash = path.find_last_of("/\\");
                if (lastSlash != string::npos) path = path.substr(0, lastSlash);
            }
            continue;
        }
        // ------RÉGI KÓD || OLD CODE ------
        /*string input;
        std::getline(std::cin, input);
        input = trim(input);
        string lowerInput = toLowerCase(input);

        if (lowerInput == "exit") return;
        if (lowerInput == "..") {
            if (path.length() > ROOT_DIR.length())
            {
                size_t lastSlash = path.find_last_of("/\\");
                if (lastSlash != string::npos) path = path.substr(0, lastSlash);
            }
            continue;
        }*/

        // --- PARANCSOK KEZELÉSE (del, cp, mv, rn, edit) ---
        size_t spacePos = input.find(' ');
        if (spacePos != string::npos) {
            string cmd = toLowerCase(trim(input.substr(0, spacePos)));
            string targetName = trim(input.substr(spacePos + 1));
            string targetPath = path;
            targetPath.append("/").append(targetName);

            if (cmd == "del") {
                deleteFileFolders(targetPath, isDirectory(targetPath));
                continue;
            }
            else if (cmd == "cp") {
                copyFileFolders(targetPath, isDirectory(targetPath));
                continue;
            }
            else if (cmd == "mv") {
                movingFileFolders(targetPath, isDirectory(targetPath));
                continue;
            }
            else if (cmd == "rn") {
                reNameFileFolders(targetPath, isDirectory(targetPath));
                continue;
            }
            else if (cmd == "edit") {
                openFileInEditor(targetPath);
                continue;
            }
            else if (cmd == "mkdir" || cmd == "md") { // ÚJ: Mappa létrehozása
                createDirectory(targetPath);
                continue;
            }
        }

        if (lowerInput == "edit") {
            openFileInEditor("");
            continue;
        }

        bool found = false;
        bool isDir = false;
        for (const auto& e : entries)
        {
            if (e.name == input)
            {
                found = true;
                isDir = e.isDirectory;
                break;
            }
        }

        if (found) {
            string fullPath = path;
            fullPath.append("/").append(input);

            if (isDir)
            {
                path = fullPath;
            }
            else if (fullPath.size() >= 5 && fullPath.substr(fullPath.size() - 5) == ".data") {
                startQuiz(loadWords(fullPath));
            } else {
                const LlistAndSelectedFile &LlSF = LlistAndSelectedFileTranslations [static_cast<int>(programUiLanguage)];
                logError("listAndSelectFile", LlSF.errorFile  + fullPath);
                cout << LlSF.errorFile << endl;
                waitToEnter();
            }
        }
    }
}

// Megvizsgálja, hogy mappa-e || Checks if it's a folder
bool isDirectory(const std::string& path) {
    struct stat path_stat{};
    if (stat(path.c_str(), &path_stat) != 0) return false;
    return S_ISDIR(path_stat.st_mode);
}

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
// új mappa létrehozás || New folder creation
bool createDirectory(const std::string& path)
{
    const struct CreateFolderStrings &CFS = createFolderTranslations[static_cast<int>(programUiLanguage)];
    if (!isPathSafe(path)) {
        logError("createDirectory", CFS.errorDangerousPath + path);
        std::cerr << CFS.errorDangerousPath << std::endl;
        waitToEnter();
        return false;
    }

    std::string nPath = normalizePath(path);
    std::string command;
#ifdef _WIN32
    command = "mkdir \"" + nPath + "\"";
#else
    command = "mkdir -p \"" + nPath + "\"";
#endif

    if (std::system(command.c_str()) == 0) {
        std::cout << CFS.successCreate << nPath << std::endl;
        waitToEnter();
        return true;
    } else {
        std::cerr << CFS.errorCreate << std::endl;
        waitToEnter();
        return false;
    }
}



