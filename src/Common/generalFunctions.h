//
// Created by AtiBexx2 on 2026. 03. 18.
//

#ifndef ENGLISH_GENERALFUNCTIONS_H
#define ENGLISH_GENERALFUNCTIONS_H

#include "dataFileReading.h"
#include "../Translate/translations.h"


//Prototype declarations
void explanation();
void exiting();
void screenWipe();
void pufferDelete();
void logError(const std::string& functionName, const std::string& errorMessage);
void logMistake(const WordPair& word);
void playBeep(int frequency = 750, int duration = 300);


#endif //ENGLISH_GENERALFUNCTIONS_H