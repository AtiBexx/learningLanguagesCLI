//
// Created by AtiBexx2 on 2026. 04. 04.
//
#include "createVocab.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

#include "dataFileReading.h"
#include "generalFunctions.h"
#include "cliFileReading.h"

std::string fileName;

void wordsPairTotal(bool isExiting)
{
    // nyelvi fájlok
    const VocabWordsPairTotal &vwptSTR = vocabWordsPairTotalTranslations[static_cast<int>(programUiLanguage)];
    const CreateVocabFile &createVocabFile = createVocabFileTranslations[static_cast<int>(programUiLanguage)];
    // Összegzés
    screenWipe();
    if (isExiting)
    {
        std::cout << createVocabFile.fileSave2 << std::endl;
    }else {
        std::cout << createVocabFile.fileSave << std::endl;
    }

    std::cout << vwptSTR.vocabWordsPairTotal << wordCount << vwptSTR.vocabWordsPairTotal2 << fileName << vwptSTR.vocabWordsPairTotal3 << std::endl;
    waitToEnter();
}
// új szótár létrehozása
// Create a new vocabulary
void createVocab()
{
    screenWipe();
    for (;;)
    {
        //nyelvi fájlok
        const CreateVocabFile &createVocabFile = createVocabFileTranslations[static_cast<int>(programUiLanguage)];
        const CreateVocab &createVocab = createVocabTranslations[static_cast<int>(programUiLanguage)];
        const CreateVocabListsFileAndFolders &CVLFF = createVocabListsFileAndFoldersTranslations[static_cast<int>(programUiLanguage)];
        const VocabFileCommands &VFC = vocabFileCommandTranslate[static_cast<int>(programUiLanguage)];
        screenWipe();

        //nullázuk a szavak számát
        // Reset the word count
        wordCount = 0;

        // ki listázuk a fájlok és mappák nevét
        // list the names of files and folders
        std::cout << CVLFF.currentlyFileandFolders <<"\n";
        std::vector<FileEntry> entries = listFiles("./data");
        for (const auto& e : entries) {
            std::cout << (e.isDirectory ? CVLFF.folderName : "        ") << e.name << "\n";
        }
        std::cout << "----------------------------------------------\n\n";
        std::cout << VFC.commands1<<"\n";
        std::cout << VFC.commands2<<"\n";

        //=========================================================================================

        // bekérjük a fájl nevét
        // Input file name
        std::cout << createVocabFile.inputFileName;
        std::getline(std::cin, fileName);

        // Ellenőrzés || Control
        FileCreationAction fcStatus = handleFileCreationInput(fileName);
        if (fcStatus == FileCreationAction::EXIT) return; // Kilépés a főmenübe || Exit to the main menu
        if (fcStatus == FileCreationAction::COMMAND_EXECUTED) continue; // Újra töltjük a listát! || Reloading the list!

            // elérési út bekérése
            // Path input
            std::string folderName;
            std::cout << createVocabFile.folderName;
            std::getline(std::cin, folderName);

        // Ellenőrzés || Control
        fcStatus = handleFileCreationInput(folderName);
        if (fcStatus == FileCreationAction::EXIT) return;
        if (fcStatus == FileCreationAction::COMMAND_EXECUTED) continue;

        std::string targetDir = "./data/";
            if (!folderName.empty())
            {
                targetDir.append(folderName);
                if (!isDirectory(targetDir))
                {
                    std::cout << "\nHiba: A '" << folderName << "' mappa nem letezik.\n";
                    std::cout << "Szeretned letrehozni? (y/n): " << std::flush;

                    std::string answer;
                    std::getline(std::cin, answer);

                    if (toLowerCase(trim(answer)) == "y")
                    {
#ifdef _WIN32
                        // Windows-on a visszaperjel biztosabb a system parancsnál
                        std::string winPath = targetDir;
                        std::replace(winPath.begin(), winPath.end(), '/', '\\');
                        std::system(("mkdir \"" + winPath + "\"").c_str());
#else
                        std::system(("mkdir -p \"" + targetDir + "\"").c_str());
#endif
                    } else
                    {
                        std::cout << "Művelet megszakitva. Kerlek adj meg letezo mappat!\n";
                        waitToEnter();
                        continue;
                    }
                }
                targetDir.append("/"); // Hozzáadjuk a lezáró perjelet a fájlnév előtt
            }

        // MOST RAKJUK ÖSSZE A VÉGLEGES ÚTVONALAT
        fullPath = targetDir;
        fullPath.append(fileName);
        fullPath.append(".data");

            // Ellenőrizzük az útvonalat biztonsági szempontból
            // Check the route for security
            if (!isPathSafe(fullPath))
            {
                std::cerr << createVocabFile.fullPathError << std::endl;
                std::cin.get();
                return;
            }
            // bekérjük a kiválasztott módot
            choiceMenu();
            // Megnyitjuk a fájlt a kiválasztott módban
            // Open the file in the selected mode
            std::ofstream outFile(fullPath, mode); // Hozzáfűzés mód
            if (!outFile.is_open()) {
                std::cerr << createVocabFile.fullPathOpenError << std::endl;
                std::cin.get();
                return;
            }

            // itt továbblépünk amig 'exit'-et nem adunk meg
            // we move on here until we enter 'exit'
            for (;;)
            {
                // letöröljük a képernyőt
                screenWipe();

                std::cout << createVocab.createVocab << fileName << createVocab.createVocab2
                << wordCount << createVocab.createVocab3 << std::endl;
                std::cout << createVocab.createVocab4 << std::endl;

                // std::string englishWords, hungarianWords, pronunciation;
                //Bekérjük a használt strukturát nem írunk újat
                WordPair currentWords;

                //Bekérjük az angol mondatot vagy szót
                std::cout << createVocab.createVocab5;
                std::getline(std::cin, currentWords.targetLangMeaning);

                int vcStatus = handleInput(currentWords.targetLangMeaning, outFile,false);
                // Kilépés ,Vissza, Mentés
                // Exit, Undo, Save
                if (vcStatus == 2) break;
                if (vcStatus == 1) continue;

                // Bekérjük a jelentést
                std::cout << createVocab.createVocab6;
                std::getline(std::cin, currentWords.motherLangMeaning);

                vcStatus = handleInput(currentWords.motherLangMeaning, outFile, false);
                if (vcStatus == 2) break;
                if (vcStatus == 1) continue;

                //Bekérjük a kiejtést ha van
                std::cout << createVocab.createVocab7;
                std::getline(std::cin, currentWords.pronunciation);
                // true mert ha üres enged tovább menni
                vcStatus = handleInput(currentWords.pronunciation, outFile, true);
                if (vcStatus == 2) break;
                if (vcStatus == 1) continue;

                // Fájlba mentés formázva
                // Save to file formatted
                outFile << trim(currentWords.targetLangMeaning) << " -> " << trim(currentWords.motherLangMeaning);
                if (!trim(currentWords.pronunciation).empty()) {
                    outFile << " [" << trim(currentWords.pronunciation) << "]";
                }
                outFile << "\n";

                // Hozzáadjuk a szavak számát a wordCount változóba
                // Add the number of words to the wordCount variable
                wordCount++;
            }

            // Bezárjuk a fájlt és mentünk
            // Close the file and save
            outFile.close();
            return;
        }
    }

// Kezeli az "exit" parancsot a fájlnév és mappanevek bekérésekor
// Handles the "exit" command when prompted for file and folder names
FileCreationAction handleFileCreationInput(const std::string& input) {
    std::string cleanInput = toLowerCase(trim(input));
    if (cleanInput == "exit") {
        return FileCreationAction::EXIT;
    }
    // Megkeressük az első szóközt (pl. "del mappa" -> szóköz a 3. indexen)
    // Find the first space (e.g. "del folder" -> space at index 3)
    size_t spacePos = cleanInput.find(' ');

    if (spacePos != std::string::npos) {

        // A szóköz előtti rész a parancs (pl. "del")
        // The part before the space is the command
        std::string cmd = toLowerCase(trim(input.substr(0, spacePos)));

        // A szóköz utáni rész az útvonal (pl. "Uj mappa") - Ezt NEM toLowerCase-ezzük!
        // The part after the space is the path (e.g. "New folder") - We do NOT toLowerCase this!
        std::string rawPath = trim(input.substr(spacePos + 1));

        // ./data előtag hozzáadása
        // Add ./data prefix
        std::string path = "./data/";
        path.append(rawPath);

        // --- TÖRLÉS (del / rm) ---
        // DEL / RM
        if (cmd == "del" || cmd == "rm") {
            bool isDir = isDirectory(path); // A C++11-es stat alapú függvényed
            deleteFileFolders(path, isDir);  // A cliFileReading-ben lévő függvényed
            return FileCreationAction::COMMAND_EXECUTED;
        }
        // --- ÁTNEVEZÉS ---
        // REN / RN
        if (cmd == "rn") {
            bool isDir = isDirectory(path);
            reNameFileFolders(path, isDir);
            return FileCreationAction::COMMAND_EXECUTED;
        }
        // --- MÁSOLÁS / MOZGATÁS (hasonlóan...) ---
        // CP / MV
        if (cmd == "cp") {
            copyFileFolders(path, isDirectory(path));
            return FileCreationAction::COMMAND_EXECUTED;
        }
        // MOZGATÁS
        // MV --MOVE--
        if (cmd == "mv") {
            movingFileFolders(path, isDirectory(path));
            return FileCreationAction::COMMAND_EXECUTED;
        }
    }
    return FileCreationAction::CONTINUE;
}


int handleInput(const std::string& input, std::ofstream& file, bool allowEmpty) {

    // Kilépés kezelése
    // Exit handling
    if (input == "exit" || input == "Exit" || input == "EXIT" ) {
        file.flush();
        wordsPairTotal(true);
        return 2; // Jelzés a break-re
    }

    // Csak mentés kezelése
    // Only save handling
    if (input == "save" || input == "Save" || input == "SAVE") {
        file.flush();
        wordsPairTotal(false);
        return 1; // Jelzés a continue-ra
    }

    // VISSZA FUNKCIÓ (ha elrontotta az első szót)
    // UNDO FUNCTION (if you messed up the first word)
    if (input == "back" || input == "Back" || input == "BACK") {
        return 1;
    }

    // Ha üres ÉS nem engedélyezett az üres, akkor újrakezdjük
    // If empty AND empty is not allowed, then restart
    if (input.empty() && !allowEmpty) {
        return 1;
    }

    return 0; // Minden OK, mehetünk a következő bekérésre
}





