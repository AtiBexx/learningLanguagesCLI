//
// Created by AtiBexx2 on 2026. 05. 03.
//

#include "platformInput.h"
#include <iostream>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#ifndef _WIN32
//LINUX OR ANDROID getch_linux()
static std::string readUtf8Char_linux()
{
    std::string utf8char;
    char c;

    if (read(STDIN_FILENO, &c, 1) != 1)
        return "";

    utf8char = c;

    //  UTF-8 MULTI-BYTE karakter
    if ((c & 0x80) != 0)
    {
        char extra[3];
        int len = 0;

        if ((c & 0xE0) == 0xC0) len = 1;
        else if ((c & 0xF0) == 0xE0) len = 2;
        else if ((c & 0xF8) == 0xF0) len = 3;

        if (len > 0)
        {
            read(STDIN_FILENO, extra, len);
            utf8char += std::string(extra, len);
        }
    }

    return utf8char;
}

#endif

#ifdef _WIN32
// wchar_t -> UTF-8 konverzió
static std::string wcharToUtf8(wchar_t wch)
{
    char utf8[4] = {0};

    int size = WideCharToMultiByte(
        CP_UTF8,
        0,
        &wch,
        1,
        utf8,
        sizeof(utf8),
        nullptr,
        nullptr
    );

    if (size <= 0)
        return {};

    return {utf8, static_cast<std::string::size_type>(size)};
}

#endif

InputResult readLineWithHotkey(const std::string& prompt)
{
    InputResult result;
    result.hotkeyTriggered = false;
    result.exitTriggered = false;

    std::string currentInput;

    std::cout << prompt << std::flush;
    //std::cout << prompt << currentInput;

#ifndef _WIN32
    struct termios oldt{}, newt{};
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif
    while (true)
    {
        // ----- NYOMTATHATÓ KARAKTEREK KEZELÉSE -----
        // ----- PRINTABLE CHARACTERS HANDLING -----
#ifdef _WIN32
        wchar_t ch = _getwch(); // Unicode karakter olvasás Windows-on || Read Unicode character on Windows

        //HOTKEY (Gyorsbillentyű) KEZELÉSE || HOTKEY MANAGEMENT
        // CTRL + Y ASCII = 25
        if (ch == 25)
        {
            result.hotkeyTriggered = true;
            result.text = currentInput;
            return result;
        }
        // ------AZ ENTER KEZELÉSE -----
        // ------MANAGING ENTER -----
        if (ch == 10 || ch == 13) // Enter (10 for Linux, 13 for Windows)
        {
            result.text = currentInput;
            std::cout << std::endl;
            return result;
        }
        // --- BACKSPACE KEZELÉSE -----
        // --- HANDLING BACKSPACE -----
        if (ch == 8)
        {
            if (!currentInput.empty())
            {
                do
                {
                    currentInput.pop_back();
                }
                while (!currentInput.empty() &&
                       (static_cast<unsigned char>(currentInput.back()) & 0xC0) == 0x80);

                //std::cout << "\b \b" << std::flush;
                // better version || jobb verzió
                std::cout << "\r\33[2K" << prompt << currentInput << std::flush;;
            }
            continue;
        }
        // --- KILÉPÉS HOTKEY KEZELÉS: Ctrl+C (ASCII 3) ---
        // --- EXIT HOTKEY HANDLING: Ctrl+C (ASCII 3) ---
        if (ch == 3) { // Ctrl+C
            result.exitTriggered = true;
            result.text = currentInput;
           // std::cout << "^C" << std::endl; // Visszajelzés a felhasználónak
            return result;
        }
        // UTF-8 konverzió
        if (ch >= 32)
        {
            std::string utf8 = wcharToUtf8(static_cast<wchar_t>(ch));
            currentInput += utf8;
            std::cout << utf8 << std::flush;
        }

#else

        // LINUX / ANDROID CHARACTER HANDLING
        // Linux / Android karakter kezelés
        std::string utf8 = readUtf8Char_linux();

        if (utf8.empty())
            continue;

        unsigned char ch = utf8[0];

        // CTRL + Y
        if (ch == 25)
        {
            result.hotkeyTriggered = true;
            result.text = currentInput;
#ifndef _WIN32
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
            return result;
        }

        // ENTER
        if (ch == 10 || ch == 13)
        {
            result.text = currentInput;
            std::cout << std::endl;
#ifndef _WIN32
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
            return result;
        }

        // BACKSPACE
        if (ch == 8 || ch == 127)
        {
            if (!currentInput.empty())
            {
                do
                {
                    currentInput.pop_back();
                }
                while (!currentInput.empty() &&
                       (static_cast<unsigned char>(currentInput.back()) & 0xC0) == 0x80);

                //std::cout << "\b \b" << std::flush;
                // jobb verzió
                std::cout << "\r\33[2K" << prompt << currentInput << std::flush;
            }
            continue;
        }

        // CTRL+C
        if (ch == 3)
        {
            result.exitTriggered = true;
            result.text = currentInput;
#ifndef _WIN32
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
            return result;
        }

        // PRINT UTF-8
        if (ch >= 32)
        {
            currentInput += utf8;
            std::cout << utf8 << std::flush;
        }

#endif

    }
}
