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
#include "newInput/platformInput.h"

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
    //const VocabWordsPairTotal &vwptSTR = vocabWordsPairTotalTranslations[static_cast<int>(programUiLanguage)];
    //const CreateVocabFile &createVocabFile = createVocabFileTranslations[static_cast<int>(programUiLanguage)];
    screenWipe();
    if (isExiting) std::cout << getTranslation("CreateVocabFile.fileSave2") <<"\n" << std::flush;
        //std::cout << createVocabFile.fileSave2 << std::endl;
    else std::cout << getTranslation("CreateVocabFile.fileSave") <<"\n" << std::flush;
        //std::cout << createVocabFile.fileSave << std::endl;

    std::cout <<getTranslation("VocabWordsPairTotal.vocabWordsPairTotal")
    << wordCount << getTranslation("VocabWordsPairTotal.vocabWordsPairTotal2")
    << fileName << getTranslation("VocabWordsPairTotal.vocabWordsPairTotal3") <<"\n" << std::flush;
    //std::cout << vwptSTR.vocabWordsPairTotal << wordCount << vwptSTR.vocabWordsPairTotal2 << fileName << vwptSTR.vocabWordsPairTotal3 << std::endl;
    waitToEnter();
}

void createVocab() {
    for (;;) {
        /*const CreateVocabFile &createVocabFile = createVocabFileTranslations[static_cast<int>(programUiLanguage)];
        const CreateVocab &createVocabStr = createVocabTranslations[static_cast<int>(programUiLanguage)];
        const CreateVocabListsFileAndFolders &CVLFF = createVocabListsFileAndFoldersTranslations[static_cast<int>(programUiLanguage)];
        const VocabFileCommands &VFC = vocabFileCommandTranslate[static_cast<int>(programUiLanguage)];*/

        screenWipe();
        wordCount = 0;

        std::cout << getTranslation("CreateVocabListsFileAndFolders.currentlyFileandFolders") <<"\n" << std::flush;
        //std::cout << CVLFF.currentlyFileandFolders << "\n";
        std::cout << "ROOT: ./data\n";
        listFlat("./data");
        std::cout << "----------------------------------------------\n\n";
        std::cout << getTranslation("VocabFileCommands.commands1") << getTranslation("VocabFileCommands.commands2") <<"\n" << std::flush;
        //std::cout << VFC.commands1 << "\n" << VFC.commands2 << "\n";

        // 1. Fájlnév bekérése || File name input
        //InputResult fileNameInput = readLineWithHotkey(createVocabFile.inputFileName);
        InputResult fileNameInput = readLineWithHotkey(getTranslation("CreateVocabFile.inputFileName"));


        // --- CTRL + C KEZELÉSE || CTRL + C HANDLING
        if (fileNameInput.exitTriggered)
        {
            return;
        }
        fileName = fileNameInput.text;
        if (toLowerCase(trim(fileName)) == "exit" || toLowerCase(trim(fileName)) == "e") return;

        // ------RÉGI KÓD || OLD CODE ------
        /*std::cout << createVocabFile.inputFileName;
        std::getline(std::cin, fileName);
        if (toLowerCase(trim(fileName)) == "exit") return;*/

        FileCreationAction fcStatus = handleFileCreationInput(fileName);
        if (fcStatus == FileCreationAction::EXIT) return;
        if (fcStatus == FileCreationAction::COMMAND_EXECUTED) continue;

        // 2. Mappanév bekérése || Folder name input
        std::string folderName;
        InputResult folderNameInput = readLineWithHotkey(getTranslation("CreateVocabFile.folderName"));

        //InputResult folderNameInput = readLineWithHotkey(createVocabFile.folderName);

        // --- CTRL + C KEZELÉSE || CTRL + C HANDLING
        if (folderNameInput.exitTriggered)
        {
            return;
        }
        folderName = folderNameInput.text;

        //-----RÉGI KÓD || OLD CODE ------
        /*std::cout << createVocabFile.folderName;
        std::getline(std::cin, folderName);*/

        if (toLowerCase(trim(folderName)) == "exit" || toLowerCase(trim(folderName)) == "e") return;

        fcStatus = handleFileCreationInput(folderName);
        if (fcStatus == FileCreationAction::EXIT) return;
        if (fcStatus == FileCreationAction::COMMAND_EXECUTED) continue;

        std::string defaultDir = "./data/";
        if (!folderName.empty()) {
            defaultDir.append(folderName);
            if (!isDirectory(defaultDir)) {

                std::cout << "\n" << getTranslation ("CreateVocabFile.folderError") << folderName << getTranslation( "CreateVocabFile.folderDoesNotExist") << "\n";
                //std::cout << "\n" << createVocabFile.folderError << folderName << createVocabFile.folderDoesNotExist << "\n";

                std::cout << getTranslation ("CreateVocabFile.askingCreate") << std::flush;
                //std::cout << createVocabFile.askingCreate << std::flush;
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
                    std::cout << getTranslation ("CreateVocabFile.folderOperationAborted") << "\n";

                    //std::cout << createVocabFile.folderOperationAborted << "\n";
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
            logError("createVocab()" , getTranslation("CreateVocabFile.fullPathError"));
            std::cerr << getTranslation("CreateVocabFile.fullPathError") <<"\n" << std::flush;

            //std::cerr << createVocabFile.fullPathError << std::endl;
            waitToEnter();
            continue;
        }

        // Fájl mód választás || Choose FILE MODE
        if (!choiceMenu()) continue;

        std::ofstream outFile(fullPath, mode);
        if (!outFile.is_open()) {
            logError("createVocab()" , getTranslation("CreateVocabFile.fullPathOpenError"));
            std::cerr << getTranslation("CreateVocabFile.fullPathOpenError") <<"\n" << std::flush;

            //std::cerr << createVocabFile.fullPathOpenError << std::endl;
            waitToEnter();
            continue;
        }

        // Szavak bekérése || Words input
        for (;;) {
            screenWipe();
            std::cout << getTranslation("CreateVocab.createVocab") << fileName << getTranslation("CreateVocab.createVocab2") << wordCount << getTranslation("CreateVocab.createVocab3") << "\n";
            //std::cout << createVocabStr.createVocab << fileName << createVocabStr.createVocab2 << wordCount << createVocabStr.createVocab3 << "\n";

            //std::cout << createVocabStr.createVocab4 << "\n";

            WordPair currentWords;
            int vcStatus;
            std::cout << getTranslation("CreateVocab.createVocab5");
            //std::cout << createVocabStr.createVocab5;

            //std::getline(std::cin, currentWords.targetLangMeaning);
            InputResult targetLangInput = readLineWithHotkey(getTranslation("CreateVocab.createVocab5"));
            if (targetLangInput.exitTriggered) {
                vcStatus = 2; // Ctrl+C esetén kilépés
            } else {
                currentWords.targetLangMeaning = targetLangInput.text;
                vcStatus = handleInput(currentWords.targetLangMeaning, outFile, false);
            }
            if (vcStatus == 2) break; // Kilép a szavak bekéréséből
            if (vcStatus == 1) continue; // Újra kéri az első szót


            std::cout << getTranslation("CreateVocab.createVocab6");
            //std::cout << createVocabStr.createVocab6;
            //std::getline(std::cin, currentWords.motherLangMeaning);

            InputResult motherLangInput = readLineWithHotkey(getTranslation("CreateVocab.createVocab6"));
            if (motherLangInput.exitTriggered) {
                vcStatus = 2; // Ctrl+C esetén kilépés
            } else {
                currentWords.motherLangMeaning = motherLangInput.text;
                vcStatus = handleInput(currentWords.motherLangMeaning, outFile, false);
            }
            if (vcStatus == 2) break; // Kilép a szavak bekéréséből
            if (vcStatus == 1) continue; // Újra kéri az első szót

            std::cout << getTranslation("CreateVocab.createVocab7");
            //std::cout << createVocabStr.createVocab7;
            //std::getline(std::cin, currentWords.pronunciation);
            InputResult pronunciationInput = readLineWithHotkey(getTranslation("CreateVocab.createVocab7"));
            if (pronunciationInput.exitTriggered) {
                vcStatus = 2; // Ctrl+C esetén kilépés
            } else {
                currentWords.pronunciation = pronunciationInput.text;
                vcStatus = handleInput(currentWords.pronunciation, outFile, true); // true, mert lehet üres
            }
            if (vcStatus == 2) break; // Kilép a szavak bekéréséből
            if (vcStatus == 1) continue; // Újra kéri az első szót

            // Fájlba mentés formázva || Save to file formatted
            outFile << trim(currentWords.targetLangMeaning) << " -> " << trim(currentWords.motherLangMeaning);
            if (!trim(currentWords.pronunciation).empty()) {
                outFile << " [" << trim(currentWords.pronunciation) << "]";
            }
            outFile << "\n";
            wordCount++;
        }
        outFile.close();
        // A ciklus vége jön, automatikusan újraindul az elejétől a fájlnév bekéréssel.
        // The cycle ends, it automatically restarts from the beginning by asking for the file name.
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
        if (cmd == "mkdir" || cmd == "md")
        {
            createDirectory(path);
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
