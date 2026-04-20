/**
* @file osEditor.h
 * @author AtiBexx2
 * @date 2026-03-24
 *
 * @brief Platform-specific file editor launcher (CLI-based).
 *        Platformfüggő fájlszerkesztő indító (parancssoros).
 *
 * @details
 * EN:
 * This module provides a function to open files using a platform-specific
 * command-line text editor.
 *
 * On Windows, it first attempts to use "edit.com". If it fails, it falls
 * back to Notepad.
 *
 * On Linux/Unix systems, it uses "nano" as the default editor.
 *
 * HU:
 * Ez a modul egy függvényt biztosít fájlok megnyitására platformfüggő
 * parancssoros szövegszerkesztővel.
 *
 * Windows alatt először az "edit.com" kerül használatra, hiba esetén
 * visszaesik a Notepad-re.
 *
 * Linux/Unix rendszereken alapértelmezettként a "nano" szerkesztőt használja.
 */

#ifndef ENGLISH_OSEDITOR_H
#define ENGLISH_OSEDITOR_H

#include <string>

// Fájl megnyitása a platformfüggő CLI szerkesztőben
// Open file in platform-specific CLI editor
void openFileInEditor(const std::string& fullPath);

#endif //ENGLISH_OSEDITOR_H
