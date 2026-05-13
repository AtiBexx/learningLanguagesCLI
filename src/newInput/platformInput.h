//
// Created by AtiBexx2 on 2026. 05. 03.
//

#ifndef ENGLISH_PLATFORMINPUT_H
#define ENGLISH_PLATFORMINPUT_H
#include <string>

/**
 * @brief ENG: Result of reading a line with hotkey support.
 * HU: Gyorsbillentyű-támogatással rendelkező sor beolvasásának eredménye.
 */

struct InputResult
{
    std::string text;
    bool hotkeyTriggered;
    bool exitTriggered;
};

InputResult readLineWithHotkey(const std::string& prompt);

InputResult ideConsoleMod(const std::string& prompt);
bool isRealTerminal();



#endif //ENGLISH_PLATFORMINPUT_H
