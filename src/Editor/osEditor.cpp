#include "osEditor.h"
#include <iostream>
#include <cstdlib> // system()
#include <string>

void openFileInEditor(const std::string& fullPath) {
    std::string command;

#ifdef _WIN32
    // Az edit.com-ot használjuk
    command = "edit.com \"" + fullPath + "\"";
    std::cout << "A Szovegszerkeszto inditasa:..." << command << std::endl;

    int result = std::system(command.c_str());

    // Ha a result nem 0, akkor valószínűleg nem található vagy hiba történt
    if (result != 0) {
        std::cout << "Az edit.com nem talalhato vagy hiba tortent. Notepad inditasa..." << std::endl;
        command = "notepad.exe \"" + fullPath + "\"";
        std::system(command.c_str());
    }
#else
    // Linux/Android/Termux: nano
    command = "nano \"" + fullPath + "\"";
    std::cout << "A Szovegszerkeszto inditasa... " << command << std::endl;
    int result = std::system(command.c_str());

    if (result != 0) {
        std::cerr << "Hiba tortent a szerkeszto inditasa kozben! (Hibakod: " << result << ")" << std::endl;
    }
#endif
}
