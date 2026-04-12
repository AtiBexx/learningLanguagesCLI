//
// Created by AtiBexx2 on 2026. 04. 06.
//

#ifndef ENGLISH_SETTINGS_H
#define ENGLISH_SETTINGS_H
#include <string>

void settings();//beállítások
void choiceLanguage(); // nyelválasztás
void learningLanguage(); //tanulandó nyelv beállítása
void colorsOn(); //színek be ki kapcsolása
void saveSettings(); //Beállítások mentésére
bool loadSettings(); //Beállítások betöltése
void backgroundSets(); //háttér beállítása
std::string getLanguageNameByIndex(int index);
void soundOn();

//globális változó
extern bool useSound;





#endif //ENGLISH_SETTINGS_H
