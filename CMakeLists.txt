cmake_minimum_required(VERSION 3.10)
project(English)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Az executable létrehozása az összes forrásfájllal
add_executable(English
    src/main.cpp
    src/Common/generalFunctions.cpp
    src/Editor/osEditor.cpp
    src/FileIO/cliFileReading.cpp
    src/FileIO/dataFileReading.cpp
    src/Quiz/programQuiz.cpp
        src/Translate/translations.txt
    src/Menu/menu.cpp
    src/CreateVocab/createVocab.cpp
    src/CreateVocab/vocabCmenu.cpp
        src/Settings/settings.cpp
        src/Settings/settings.h
        src/Settings/colors.h
        src/Translate/returnLanguageList.cpp
        src/Quiz/mistakeExercise.cpp
        src/newInput/platformInput.cpp
        src/newInput/platformInput.h
        src/Settings/languageList.h
        src/Settings/languageListParse.cpp
        src/Translate/translations.cpp
)

# Megadjuk az include útvonalakat a fordítónak
target_include_directories(English PRIVATE
    src
    src/Settings
    src/Common
    src/Editor
    src/FileIO
    src/Quiz
    src/Translate
    src/Menu
    src/CreateVocab
)
