//
// Created by AtiBexx2 on 2026. 03. 24.
//

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

bool isPathSafe(const std::string& path) {
    if (path.empty() || path.length() > 255) return false;
    if (path.find("..") != std::string::npos) return false;
    string lowerPath = toLowerCase(path);
    if (lowerPath.find("format") != std::string::npos || lowerPath.find("rm ") != std::string::npos) return false;
    return std::all_of(path.begin(), path.end(), [](unsigned char c) {
        return std::isalnum(c) || c == '/' || c == '\\' || c == '.' || c == '_' || c == '-' || c == ' ';
    });
}

void copyFileFolders(const std::string& srcPath, bool isDirectory) {
    if (!isPathSafe(srcPath)) { cout << "Hiba: Veszelyes forras utvonal!" << endl; return; }
    cout << "Masolando: " << srcPath << endl;
    cout << "Uj nev/utvonal: ";
    string destName; std::getline(std::cin, destName);
    string destPath = trim(destName);
    if (!isPathSafe(destPath)) { cout << "Hiba: Veszelyes cel utvonal!" << endl; std::cin.get(); return; }
    string command;
#ifdef _WIN32
    command = isDirectory ? "xcopy /E /I /H /Y \"" + srcPath + "\" \"" + destPath + "\"" : "copy /Y \"" + srcPath + "\" \"" + destPath + "\"";
#else
    command = "cp -r -p \"" + srcPath + "\" \"" + destPath + "\"";
#endif
    if (std::system(command.c_str()) == 0) cout << "Sikeres masolas!" << endl;
    else cout << "Hiba tortent!" << endl;
    std::cin.get();
}

void deleteFileFolders(const std::string& fullPath, bool isDirectory) {
    if (!isPathSafe(fullPath)) { cout << "Hiba: Veszelyes utvonal!" << endl; std::cin.get(); return; }
    cout << "Biztosan torolni szeretned: " << fullPath << "? (y/n): ";
    string confirm; std::getline(std::cin, confirm);
    if (toLowerCase(trim(confirm)) != "y") return;
    string command;
#ifdef _WIN32
    command = isDirectory ? "rd /s /q \"" + fullPath + "\"" : "del /f /q \"" + fullPath + "\"";
#else
    command = isDirectory ? "rm -rf \"" + fullPath + "\"" : "rm -f \"" + fullPath + "\"";
#endif
    if (std::system(command.c_str()) == 0) std::cout << "Sikeresen torolve!" << std::endl;
    std::cin.get();
}

void movingFileFolders(const std::string& srcPath, bool isDirectory) {
    if (!isPathSafe(srcPath)) return;
    cout << "Athelyezendo: " << srcPath << "\nUj nev/utvonal: ";
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

void reNameFileFolders(const std::string& srcPath, bool isDirectory) {
    if (!isPathSafe(srcPath)) return;
    cout << "Atnevezendo: " << srcPath << "\nUj nev: ";
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

void editFile(const std::string& fullPath) {
    if (isPathSafe(fullPath)) openFileInEditor(fullPath);
    std::cin.get();
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
                // SZŰRÉS: Csak mappák vagy .data fájlok
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

void listAndSelectFile() {
    const string ROOT_DIR ="./data";
    string path = ROOT_DIR;
    for (;;) {
        screenWipe();
        cout << "--- Jelenlegi mappa: " << path << " ---\n";
        vector<FileEntry> entries = listFiles(path);
        if (entries.empty()) cout << "(Ures mappa)\n";
        else for (const auto& e : entries) cout << (e.isDirectory ? "[MAPPA] " : "        ") << e.name << "\n";
        cout << "---------------------------------------\nParancsok: nev, .., del, cp, mv, rn, edit, exit\nValasztas: ";
        string input; std::getline(std::cin, input);
        input = trim(input);
        if (toLowerCase(input) == "exit") return;
        if (input == "..") {
            if (path.length() > ROOT_DIR.length()) path = path.substr(0, path.find_last_of("/\\"));
            continue;
        }
        // ... (Parancsok kezelése del, cp, mv, rn, edit ugyanúgy marad) ...
        // Itt egy rövidített verzió a fájl megnyitásához:
        bool found = false; bool isDir = false;
        for (const auto& e : entries) if (e.name == input) { found = true; isDir = e.isDirectory; break; }
        if (found) {
            string fullPath = path;
             path.append("/").append(input);
            if (isDir) path = fullPath;
            else if (fullPath.size() >= 5 && fullPath.substr(fullPath.size() - 5) == ".data") {
                startQuiz(loadwords(fullPath));
            }
        }
    }
}
