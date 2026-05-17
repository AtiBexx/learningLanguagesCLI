#include "osEditor.h"
#include <iostream>
//#include <cstdlib> // system()
#include <string>

#include "generalFunctions.h"
#include "translations.h"

void openFileInEditor(const std::string& fullPath) {
    std::string command;
    std::string pathArg;

    //const OosEditor &OoE = OosEditorTranslations [static_cast<int>(programUiLanguage)];

    // Idézőjelek kezelése: ha van elérési út, tegyük köré, ha nincs, maradjon üres

#ifdef _WIN32
    std::string fixedPath = fullPath;
    for(auto &c : fixedPath) if(c == '/') c = '\\';
#endif


    pathArg = fullPath.empty() ? "" : " \"" + fullPath + "\"";
#ifdef _WIN32
    // Az edit.com-ot használjuk
    // use edit.com
    command = "edit" + pathArg;
    std::cout << getTranslation("OosEditor.run") << command << "\n" << std::flush;
    //std::cout << OoE.run << command << std::endl;

    int result = std::system(command.c_str());

    // Ha a result nem 0, akkor valószínűleg nem található vagy hiba történt
    // If result is not 0, it is probably not found or an error occurred.
    if (result != 0) {
        logError("osEditor" , getTranslation("OosEditor.errorWin32"));
        std::cout << getTranslation("OosEditor.errorWin32") << "\n" << std::flush;
        //std::cout << OoE.errorWin32 << std::endl;
        command = "notepad.exe" + pathArg;
        std::system(command.c_str());
    }
#else
    // Linux/Android/Termux: nano
    command = "nano" + pathArg;
    std::cout << "Nano is loading"<< command << std::endl;
    int result = std::system(command.c_str());

    if (result != 0) {
        std::cerr << "Nano run error "<< result << ")" << std::endl;
    }
#endif
}
