//
// Created by AtiBexx2 on 2026. 04. 07.
//

#ifndef ENGLISH_COLORS_H
#define ENGLISH_COLORS_H

#include <string>

extern bool useColors; // "extern" = valahol létezik egy ilyen változó
extern std::string currentBG;
extern int currentBG_Code; //háttérszín kód


namespace colors {
    //========SZÖVEGSZÍNEK===========

    const std::string RESET = "\033[0m"; //eredeti szövegszín
    const std::string RED   = "\033[31m"; //piros
    const std::string GREEN = "\033[32m"; //zöld
    const std::string YELLOW = "\033[33m"; //sárga
    const std::string BLUE = "\033[34m"; //kék
    const std::string MAGENTA = "\033[35m"; //lila
    const std::string CYAN = "\033[36m"; //türkiz
    const std::string WHITE = "\033[37m"; //fehér
    const std::string BLACK = "\033[30m"; //fekete
    const std::string ORANGE = "\033[38;5;208m"; //Narancssárga
    const std::string GREY = "\033[90m"; //HalványSzürke a cheatSheet-hez


    //===========SZÖVEG TÍPUSOK==============

    const std::string BOLD = "\033[1m"; //félkövér szöveg
    const std::string UNDERLINE = "\033[4m"; //aláhúzott szöveg
    const std::string BLINK = "\033[5m"; //villogó (nem minden terminál támogatja)
    const std::string REVERSE = "\033[7m"; //háttér és szöveg szín felcserélése
    const std::string HIDDEN = "\033[8m"; // láthatatlan szöveg

    //========HÁTTÉRSZÍNEK===============

    const std::string BG_RED = "\033[41m"; //piros
    const std::string BG_GREEN = "\033[42m"; //zöld
    const std::string BG_YELLOW = "\033[43m"; //sárga
    const std::string BG_BLUE = "\033[44m"; // Kék
    const std::string BG_MAGENTA = "\033[45m"; //lila
    const std::string BG_CYAN = "\033[46m"; // türkiz
    const std::string BG_WHITE = "\033[47m"; //fehér
    const std::string BG_BLACK = "\033[40m"; //fekete
    const std::string BG_ORANGE = "\033[48;5;208m"; // narancssárga
    const std::string BG_GREY = "\033[100m";

    //=========világos (bright) verziók========

    const std::string BRIGHT_RED = "\033[91m"; // piros
    const std::string BRIGHT_GREEN = "\033[92m"; // zöld
    const std::string BRIGHT_YELLOW = "\033[93m"; // sárga
    const std::string BRIGHT_BLUE = "\033[94m"; // Kék
    const std::string BRIGHT_MAGENTA = "\033[95m";// lila
    const std::string BRIGHT_CYAN = "\033[96m"; // türkiz
    const std::string BRIGHT_WHITE = "\033[97m"; // fehér
    const std::string BRIGHT_BLACK = "\033[90m"; // fekete
    const std::string BRIGHT_ORANGE = "\033[98;5;208m"; // narancssárga

}
#endif //ENGLISH_COLORS_H
