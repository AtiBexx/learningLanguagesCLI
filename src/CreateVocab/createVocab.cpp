/**
 * @file createVocab.cpp
 * @brief Vocabulary file creation and management module.
 */

#include "createVocab.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "dataFileReading.h"
#include "generalFunctions.h"
#include "cliFileReading.h"

std::string fileName;

/**
 * @brief Helper for recursive directory listing / Segédfüggvény a rekurzív listázáshoz
 */
void listFlat(const std::string& root)
{
    std::vector<std::string> directories;
    std::vector<FileEntry> rootEntries = listFiles(root);

    // --- ROOT fájlok ---
    for (const auto& e : rootEntries)
    {
        if (!e.isDirectory)
        {
            std::cout << "    - " << e.name << "\n";
        }
        else
        {
            directories.push_back(root + "/" + e.name);
        }
    }

    // --- MAPPÁK BEJÁRÁSA (BFS) ---
    while (!directories.empty())
    {
        std::string current = directories.back();
        directories.pop_back();

        std::cout << "[DIR] " << current << "\n";

        std::vector<FileEntry> entries = listFiles(current);

        for (const auto& e : entries)
        {
            if (!e.isDirectory)
            {
                std::cout << "    - " << e.name << "\n";
            }
            else
            {
                directories.push_back(current + "/" + e.name);
            }
        }
        std::cout <<"----\n";

    }
}

void wordsPairTotal(bool isExiting) {
    const VocabWordsPairTotal &vwptSTR = vocabWordsPairTotalTranslations[static_cast<int>(programUiLanguage)];
    const CreateVocabFile &createVocabFile = createVocabFileTranslations[static_cast<int>(programUiLanguage)];
    screenWipe();
    if (isExiting) std::cout << createVocabFile.fileSave2 << std::endl;
    else std::cout << createVocabFile.fileSave << std::endl;

    std::cout << vwptSTR.vocabWordsPairTotal << wordCount << vwptSTR.vocabWordsPairTotal2 << fileName << vwptSTR.vocabWordsPairTotal3 << std::endl;
    waitToEnter();
}

void createVocab() {
    for (;;) {
        const CreateVocabFile &createVocabFile = createVocabFileTranslations[static_cast<int>(programUiLanguage)];
        const CreateVocab &createVocabStr = createVocabTranslations[static_cast<int>(programUiLanguage)];
        const CreateVocabListsFileAndFolders &CVLFF = createVocabListsFileAndFoldersTranslations[static_cast<int>(programUiLanguage)];
        const VocabFileCommands &VFC = vocabFileCommandTranslate[static_cast<int>(programUiLanguage)];

        screenWipe();
        wordCount = 0;

        std::cout << CVLFF.currentlyFileandFolders << "\n";
        std::cout << "ROOT: ./data\n";
        listFlat("./data");
        std::cout << "----------------------------------------------\n\n";
        std::cout << VFC.commands1 << "\n" << VFC.commands2 << "\n";

        // 1. Fájlnév bekérése
        std::cout << createVocabFile.inputFileName;
        std::getline(std::cin, fileName);
        if (toLowerCase(trim(fileName)) == "exit") return;

        FileCreationAction fcStatus = handleFileCreationInput(fileName);
        if (fcStatus == FileCreationAction::EXIT) return;
        if (fcStatus == FileCreationAction::COMMAND_EXECUTED) continue;

        // 2. Mappanév bekérése
        std::string folderName;
        std::cout << createVocabFile.folderName;
        std::getline(std::cin, folderName);
        if (toLowerCase(trim(folderName)) == "exit") return;

        fcStatus = handleFileCreationInput(folderName);
        if (fcStatus == FileCreationAction::EXIT) return;
        if (fcStatus == FileCreationAction::COMMAND_EXECUTED) continue;

        std::string defaultDir = "./data/";
        if (!folderName.empty()) {
            defaultDir.append(folderName);
            if (!isDirectory(defaultDir)) {
                std::cout << "\n" << createVocabFile.folderError << folderName << createVocabFile.folderDoesNotExist << "\n";
                std::cout << createVocabFile.askingCreate << std::flush;
                std::string answer;
                std::getline(std::cin, answer);
                if (toLowerCase(trim(answer)) == "y") {
                    #ifdef _WIN32
                        std::string winPath = defaultDir;
                        std::replace(winPath.begin(), winPath.end(), '/', '\\');
                        std::system(("mkdir \"" + winPath + "\"").c_str());
                    #else
                        std::system(("mkdir -p \"" + defaultDir + "\"").c_str());
                    #endif
                } else {
                    std::cout << createVocabFile.folderOperationAborted << "\n";
                    waitToEnter();
                    continue;
                }
            }
            defaultDir.append("/");
        }

        fullPath = defaultDir + fileName;
        if (fileName.size() < 5 || fileName.substr(fileName.size() - 5) != ".data") {
            fullPath.append(".data");
        }

        if (!isPathSafe(fullPath)) {
            std::cerr << createVocabFile.fullPathError << std::endl;
            waitToEnter();
            continue;
        }

        // Fájl mód választás
        if (!choiceMenu()) continue;

        std::ofstream outFile(fullPath, mode);
        if (!outFile.is_open()) {
            std::cerr << createVocabFile.fullPathOpenError << std::endl;
            waitToEnter();
            continue;
        }

        // Szavak bekérése
        for (;;) {
            screenWipe();
            std::cout << createVocabStr.createVocab << fileName << createVocabStr.createVocab2 << wordCount << createVocabStr.createVocab3 << "\n";
            std::cout << createVocabStr.createVocab4 << "\n";

            WordPair currentWords;
            std::cout << createVocabStr.createVocab5;
            std::getline(std::cin, currentWords.targetLangMeaning);
            int vcStatus = handleInput(currentWords.targetLangMeaning, outFile, false);
            if (vcStatus == 2) break;
            if (vcStatus == 1) continue;

            std::cout << createVocabStr.createVocab6;
            std::getline(std::cin, currentWords.motherLangMeaning);
            vcStatus = handleInput(currentWords.motherLangMeaning, outFile, false);
            if (vcStatus == 2) break;
            if (vcStatus == 1) continue;

            std::cout << createVocabStr.createVocab7;
            std::getline(std::cin, currentWords.pronunciation);
            vcStatus = handleInput(currentWords.pronunciation, outFile, true);
            if (vcStatus == 2) break;
            if (vcStatus == 1) continue;

            outFile << trim(currentWords.targetLangMeaning) << " -> " << trim(currentWords.motherLangMeaning);
            if (!trim(currentWords.pronunciation).empty()) {
                outFile << " [" << trim(currentWords.pronunciation) << "]";
            }
            outFile << "\n";
            wordCount++;
        }
        outFile.close();
        // A ciklus vége jön, automatikusan újraindul az elejétől a fájlnév bekéréssel
    }
}

FileCreationAction handleFileCreationInput(const std::string& input) {
    std::string cleanInput = toLowerCase(trim(input));
    if (cleanInput == "exit") return FileCreationAction::EXIT;
    size_t spacePos = cleanInput.find(' ');

    if (spacePos != std::string::npos) {
        std::string cmd = toLowerCase(trim(input.substr(0, spacePos)));
        std::string rawPath = trim(input.substr(spacePos + 1));
        std::string path = "./data/" + rawPath;

        if (cmd == "del" || cmd == "rm") {
            deleteFileFolders(path, isDirectory(path));
            return FileCreationAction::COMMAND_EXECUTED;
        }
        if (cmd == "rn") {
            reNameFileFolders(path, isDirectory(path));
            return FileCreationAction::COMMAND_EXECUTED;
        }
        if (cmd == "cp") {
            copyFileFolders(path, isDirectory(path));
            return FileCreationAction::COMMAND_EXECUTED;
        }
        if (cmd == "mv") {
            movingFileFolders(path, isDirectory(path));
            return FileCreationAction::COMMAND_EXECUTED;
        }
    }
    return FileCreationAction::CONTINUE;
}

int handleInput(const std::string& input, std::ofstream& file, bool allowEmpty) {
    std::string cleanInput = toLowerCase(trim(input));
    if (cleanInput == "exit") {
        file.flush();
        wordsPairTotal(true);
        return 2;
    }
    if (cleanInput == "save") {
        file.flush();
        wordsPairTotal(false);
        return 1;
    }
    if (cleanInput == "back") return 1;
    if (cleanInput.empty() && !allowEmpty) return 1;
    return 0;
}
