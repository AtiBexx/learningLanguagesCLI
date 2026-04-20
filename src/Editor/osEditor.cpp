#include "osEditor.h"
#include <iostream>
#include <cstdlib> // system()
#include <string>

#include "translations.h"

void openFileInEditor(const std::string& fullPath) {
    std::string command;

    const OosEditor &OoE = OosEditorTranslations [static_cast<int>(programUiLanguage)];

#ifdef _WIN32
    // Az edit.com-ot használjuk
    // use edit.com
    command = "edit.com \"" + fullPath + "\"";
    std::cout << OoE.run << command << std::endl;

    int result = std::system(command.c_str());

    // Ha a result nem 0, akkor valószínűleg nem található vagy hiba történt
    // If result is not 0, it is probably not found or an error occurred.
    if (result != 0) {
        std::cout << OoE.errorWin32 << std::endl;
        command = "notepad.exe \"" + fullPath + "\"";
        std::system(command.c_str());
    }
#else
    // Linux/Android/Termux: nano
    command = "nano \"" + fullPath + "\"";
    std::cout << OoE.run << command << std::endl;
    int result = std::system(command.c_str());

    if (result != 0) {
        std::cerr << OoE.errorLinux << result << ")" << std::endl;
    }
#endif
}
