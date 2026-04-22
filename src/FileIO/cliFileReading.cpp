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
    std::string normalized = path;
#ifdef _WIN32
    std::replace(normalized.begin(), normalized.end(), '/', '\\');
#endif
    return normalized;
}

// Ellenőrzi az útvonal biztonságosságát.
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
        std::cout << "Megszakitva.\n";
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
        std::cout << "Hiba a torlesnel! Ellenorizd az utvonalat.\n";
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
        else for (const FileEntry& e : entries) cout << (e.isDirectory ? LASFile.isDirectory : "        ") << e.name << "\n";
        cout << LASFile.commands;
        string input; std::getline(std::cin, input);
        input = trim(input);
        if (toLowerCase(input) == "exit") return;
        if (input == "..") {
            if (path.length() > ROOT_DIR.length()) path = path.substr(0, path.find_last_of("/\\"));
            continue;
        }
        bool found = false; bool isDir = false;
        for (const auto& e : entries) if (e.name == input) { found = true; isDir = e.isDirectory; break; }
        if (found) {
            string fullPath = path;
            fullPath.append("/").append(input);
            if (isDir) path = fullPath;
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

// Megvizsgálja, hogy mappa-e
bool isDirectory(const std::string& path) {
    struct stat path_stat{};
    if (stat(path.c_str(), &path_stat) != 0) return false;
    return S_ISDIR(path_stat.st_mode);
}
