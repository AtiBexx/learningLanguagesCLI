/**
 *@page cliFileReading.doc
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

    if (!isPathSafe(srcPath)) {
        logError("copyFileFolders", "Dangerous source path: " + srcPath);
        int width = getTerminalWidth();

        printWrapped(getTranslation("CopyFileFolders.errorDangerousPath") , width);
        cout<<"\n" << std::flush;
        waitToEnter();
        return;
    }
    int width = getTerminalWidth();

    printWrapped(getTranslation("CopyFileFolders.toBeCopied") + srcPath ,width);
    cout<< "\n" << std::flush;
    printWrapped(getTranslation("CopyFileFolders.newNameNewPath") ,width);
    cout <<"\n" << std::flush;

    InputResult inputResult = readLineWithHotkey(getTranslation("CopyFileFolders.example"));

    // -----CTRL + C Kezelése || CTRL + C Handling
    if (inputResult.exitTriggered)
    {
        playBeep();
        return;
    }

        string destName = inputResult.text;
        string destPath = trim(destName);

    if (!isPathSafe(destPath)) {
        logError("copyFileFolders", "Dangerous destination path: " + destPath);
        printWrapped(getTranslation("CopyFileFolders.errorDangerousGoalAndPath") , width);
        cout<<"\n" << std::flush;
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
    if (std::system(command.c_str()) == 0)
    {
        printWrapped(getTranslation("CopyFileFolders.successCopying"), width);
        cout <<"\n" << std::flush;
    }
    else
    {
        printWrapped(getTranslation("CopyFileFolders.anErrorOccurred") , width);
        cout <<"\n" << std::flush;
    }

    waitToEnter();
}

// Törli a fájlt vagy mappát
// Delete a file or folder
void deleteFileFolders(const std::string& fullPath, bool isDirectory) {

    if (!isPathSafe(fullPath)) {
        int width = getTerminalWidth();

        logError ("deleteFileFolders", getTranslation("DeleteFileFolders.errorDangerousPath") + fullPath);
        printWrapped( getTranslation("DeleteFileFolders.errorDangerousPath"), width);
        cout <<"\n" << std::flush;

        waitToEnter();
        return;
    }
    int width = getTerminalWidth();
    printWrapped(getTranslation("DeleteFileFolders.toBeDeleted") + fullPath + "? (y/n): ", width);
    cout << std::flush;

    InputResult inputResult = readLineWithHotkey("");

    // -----CTRL + C Kezelése || CTRL + C Handling
    if (inputResult.exitTriggered)
    {
        playBeep();
        return;
    }

    string confirm = inputResult.text;

    if (toLowerCase(trim(confirm)) != "y") {
        printWrapped(getTranslation("DeleteFileFolders.interrupted"), width );
        cout<<"\n"<< std::flush;

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
        printWrapped(getTranslation("DeleteFileFolders.successDelete"),width);
        cout <<"\n" << std::flush;

    } else {
        logError("deleteFileFolders", getTranslation("DeleteFileFolders.errorDelete") + fullPath);
        printWrapped(getTranslation("DeleteFileFolders.errorDelete") + fullPath, width);
        cout << "\n" << std::flush;

    }
    waitToEnter();
}

// Áthelyezi a fájlt vagy mappát
// Move a file or folder
void movingFileFolders(const std::string& srcPath, bool isDirectory) {

    if (!isPathSafe(srcPath))
    {
        logError("movingFileFolders", getTranslation("MovingFileFolders.MFerrorDangerousPath") + srcPath);
        int width = getTerminalWidth();

        printWrapped(getTranslation("MovingFileFolders.MFerrorDangerousPath") + srcPath, width);
        cout << "\n" << std::flush;
        waitToEnter();
        return;
    }
    int width = getTerminalWidth();

    printWrapped(getTranslation("MovingFileFolders.toBeMoved") + srcPath, width);
    cout << "\n";
    printWrapped(getTranslation("MovingFileFolders.newNameNewPath"), width);
    cout << std::flush;

    InputResult inputResult = readLineWithHotkey("");

    // -----CTRL + C Kezelése || CTRL + C Handling
    if (inputResult.exitTriggered)
    {
        playBeep();
        return;
    }

    string destName = inputResult.text;
    string destPath = trim(destName);


    if (!isPathSafe(destPath))
    {
        logError("movingFileFolders", getTranslation("MovingFileFolders.MFerrorDangerousPath") + srcPath);

        printWrapped(getTranslation("MovingFileFolders.MFerrorDangerousPath") + srcPath, width);
        cout << "\n" << std::flush;

        waitToEnter();
        return;
    }

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
// Rename a file or folder
void reNameFileFolders(const std::string& srcPath, bool isDirectory) {

    if (!isPathSafe(srcPath))
    {
        logError("reNameFileFolders", getTranslation("RenameFilesAndFolders.errorDangerousPath") + srcPath);
        int width = getTerminalWidth();
        printWrapped(getTranslation("RenameFilesAndFolders.errorDangerousPath") + srcPath, width),cout<<"\n" << std::flush;
        waitToEnter();
        return;
    }
    int width = getTerminalWidth();

    printWrapped(getTranslation("RenameFilesAndFolders.toBeRenamed") + srcPath, width);
    cout << "\n";
    printWrapped(getTranslation("RenameFilesAndFolders.newName"), width);
    cout << std::flush;
    // --- INPUT BEOLVASÁSA readLineWithHotkey-el ---
    // --- Input reading with readLineWithHotkey ---
    InputResult newNameInput = readLineWithHotkey(""); // A promptot már kiírtuk marad a promptnál || The prompt has already been written, it remains at the prompt.
    // --- Ctrl+C KEZELÉSE ---
    if (newNameInput.exitTriggered) {
        playBeep();
        return; // Kilép a függvényből || Exit the function
    }

    string newName = newNameInput.text;
    newName = trim(newName);


    size_t lastSlash = srcPath.find_last_of("/\\");
    string destPath = ((lastSlash == string::npos) ? "" : srcPath.substr(0, lastSlash + 1)) + newName;

    if (!isPathSafe(destPath))
    {
        logError("reNameFileFolders", getTranslation("RenameFilesAndFolders.errorDangerousPath") + srcPath);
        printWrapped(getTranslation("RenameFilesAndFolders.errorDangerousPath") + srcPath, width),cout<<"\n" << std::flush;
        waitToEnter();
        return;
    }

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
// Open a file in the editor
void editFile(const std::string& fullPath) {
    if (isPathSafe(fullPath)) openFileInEditor(fullPath);
}

// Segédfüggvény a fájlok és mappák listázására
// Helper function to list files and folders
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
// Command-line navigation in the "./data" folder
void listAndSelectFile() {

    const string ROOT_DIR ="./data";
    string path = ROOT_DIR;
    for (;;) {
        screenWipe();
        int width = getTerminalWidth();

        printWrapped(getTranslation("ListAndSelectedFile.currentlyFolder") + path + " ---", width);
        cout<< "\n" << std::flush;
        vector<FileEntry> entries = listFiles(path);

        if (entries.empty())
        {
            printWrapped(getTranslation("ListAndSelectedFile.emptyFolder"),width), cout<< "\n" << std::flush;
        }
        else
        {
            for (const FileEntry& e : entries)
            {
                printWrapped((e.isDirectory ? getTranslation("ListAndSelectedFile.isDirectory") : "        ") + e.name, width), cout << "\n" << std::flush;
            }
        }
        printWrapped(getTranslation("ListAndSelectedFile.signs"),width),cout <<"\n";
        printWrapped(getTranslation("ListAndSelectedFile.commands"),width),cout <<"\n";
        printWrapped(getTranslation("ListAndSelectedFile.fullCommands"),width),cout <<"\n";
        printWrapped(getTranslation("ListAndSelectedFile.fullCommands2"),width),cout <<"\n";

        InputResult inputResult = readLineWithHotkey("\n" + getTranslation("ListAndSelectedFile.choice"));

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

        // --- PARANCSOK KEZELÉSE (del, cp, mv, rn, edit) ---
        // --- HANDLING OF COMMANDS (del, cp, mv, rn, edit) ---
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
                logError("listAndSelectFile" , getTranslation("LlistAndSelectedFile.errorFile") + fullPath);
                printWrapped(getTranslation("LlistAndSelectedFile.errorFile"),width),cout <<"\n" << std::flush;

                waitToEnter();
            }
        }
    }
}

// Megvizsgálja, hogy mappa-e || Checks if it's a folder
bool isDirectory(const std::string& path) {
    struct stat path_stat{};
    if (stat(path.c_str(), &path_stat) != 0) return false;
    #ifdef _WIN32
    return (path_stat.st_mode & _S_IFDIR) != 0;
#else
    return S_ISDIR(path_stat.st_mode);
#endif
}

// új mappa létrehozás || New folder creation
bool createDirectory(const std::string& path)
{
    if (!isPathSafe(path)) {
        logError("createDirectory", getTranslation("CreateFolderStrings.errorDangerousPath") + path);
        int width = getTerminalWidth();

        printWrapped(getTranslation("CreateFolderStrings.errorDangerousPath") + path,width),cout <<"\n" << std::flush;
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
        int width = getTerminalWidth();

        printWrapped(getTranslation("CreateFolderStrings.successCreate") + nPath , width), cout<<"\n" << std::flush;
        waitToEnter();
        return true;
    } else {

        logError("createDirectory", getTranslation("CreateFolderStrings.errorCreate") + path);
        int width = getTerminalWidth();

        printWrapped(getTranslation("CreateFolderStrings.errorCreate"), width),cout <<"\n" << std::flush;
        waitToEnter();
        return false;
    }
}



