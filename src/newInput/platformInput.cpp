//
// Created by AtiBexx2 on 2026. 05. 03.
//

#include "platformInput.h"

#include <iostream>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#ifndef _WIN32
//LINUX OR ANDROID getch_linux()
int getch_linux()
{
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);// Save current terminal settings || elmentjük az aktuális terminálBeállításokat

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical

    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings

    int ch = getchar(); // Read character
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings

    return ch;
}
#endif

InputResult readLineWithHotkey(const std::string& prompt)
{
    InputResult result;
    result.hotkeyTriggered = false;
    result.exitTriggered = false;

    std::string currentInput;
    int ch;

    std::cout << prompt << currentInput;

    while (true)
    {
#ifdef _WIN32
        ch= _getch();
#else
        ch= getch_linux();
#endif

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
        if (ch == 8 || ch == 127) // Backspace (8 for Windows, 127 for Linux)
        {
            if (!currentInput.empty())
            {
                currentInput.pop_back();
                std::cout << "\b \b"; // Erase the last character || Töröljük az utolsó karaktert
            }
        }
        // --- KILÉPÉS HOTKEY KEZELÉS: Ctrl+C (ASCII 3) ---
        // --- EXIT HOTKEY HANDLING: Ctrl+C (ASCII 3) ---
        if (ch == 3) { // Ctrl+C
            result.exitTriggered = true;
            result.text = currentInput;
           // std::cout << "^C" << std::endl; // Visszajelzés a felhasználónak
            return result;
        }
        // ----- NYOMTATHATÓ KARAKTEREK KEZELÉSE -----
        // ----- PRINTABLE CHARACTERS HANDLING -----
        else if (ch >= 32 && ch <= 126) {// Printable characters

            // C-s verzió
            /*currentInput += (char)ch;
            std::cout << (char)ch << std::flush; // Print the character || kiírjuk a charactert*/
            // C++ verzió
            currentInput += static_cast<char>(ch);
            std::cout << static_cast<char>(ch) << std::flush; // Print the character || kiírjuk a charactert
        }
        // Nyilakat egyéb eseteket figyelmen kívül hagyjuk
        // Arrows other cases are ignored
    }
}
