//
// Created by AtiBexx2 on 2026. 03. 24.
//

#ifndef ENGLISH_CLIFILEREADING_H
#define ENGLISH_CLIFILEREADING_H
#include <string>
#include <vector>


// Struktúra definíciók
struct FileEntry {
    std::string name;
    bool isDirectory;
};

// Segédfüggvény a fájlok és mappák listázására
std::vector<FileEntry> listFiles(const std::string &directory);
// A fájlok kivalasztáshoz
void listAndSelectFile();
//Fájlok és mappák tőrlésére
void deleteFileFolders(const std::string& fullPath, bool isDirectory);
//Fájlok és mappák másolására
void copyFileFolders(const std::string& srcPath, bool isDirectory);
//Fájlok és Vagy mappák áthelyezésére
void movingFileFolders(const std::string& srcPath, bool isDirectory);
//Fájlok vagy Mappák átnevezésére
void reNameFileFolders(const std::string& srcPath, bool isDirectory);
// Fájl szerkesztésére
void editFile(const std::string& fullPath);
//Karakterek engedélyezésére
bool isPathSafe(const std::string& path);

#endif //ENGLISH_CLIFILEREADING_H
