# cliFileReading.cpp — Részletes magyarázat / Detailed Explanation

---

## A fájl célja / Purpose of the file

Ez a fájl egy **parancssori fájlkezelő rendszer** megvalósítása C++ nyelven.
Lehetővé teszi fájlok és mappák listázását, másolását, törlését, áthelyezését, átnevezését és szerkesztését egy szöveges felületen (terminálban) keresztül.

This file implements a **command-line file management system** in C++.
It allows listing, copying, deleting, moving, renaming, and editing files and folders through a text-based terminal interface.

---

## Fejlécek (include-ok) / Headers (includes)

```cpp
#include "cliFileReading.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../Editor/osEditor.h"
#include "dataFileReading.h"
#include "../Common/generalFunctions.h"
#include "../Quiz/programQuiz.h"
#include <sys/stat.h>
#include "newInput/platformInput.h"
```

Minden `#include` egy **könyvtárat** (library) vagy **saját fájlt** von be a fordításba.

Every `#include` pulls in a **library** or **own source file** into the compilation.

| Include | Mit csinál / What it does |
|---|---|
| `"cliFileReading.h"` | Saját fejlécfájl, amely deklarálja az ebben a .cpp-ben definiált függvényeket. / Own header that declares the functions defined in this .cpp. |
| `<algorithm>` | STL algoritmusok: pl. `std::all_of`, `std::replace`. / STL algorithms: e.g. `std::all_of`, `std::replace`. |
| `<iostream>` | Standard bemenet/kimenet: `std::cout`, `std::cin`, `std::cerr`. / Standard input/output. |
| `<string>` | `std::string` típus és metódusok. / The `std::string` type and its methods. |
| `<vector>` | `std::vector` dinamikus tömb. / `std::vector` dynamic array. |
| `<cstdlib>` | `std::system()` függvény (shell parancsok futtatásához). / `std::system()` function (for running shell commands). |
| `<sys/stat.h>` | `stat()` rendszerhívás: fájl/mappa tulajdonságainak lekérdezése. / `stat()` system call: querying file/folder properties. |
| `"newInput/platformInput.h"` | Saját billentyűzet-kezelő modul (pl. Ctrl+C figyelés). / Own keyboard input module (e.g. Ctrl+C detection). |

### Platform-specifikus fejlécek / Platform-specific headers

```cpp
#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#endif
```

A `#ifdef _WIN32` egy **preprocesszor feltétel**: ha Windows-on fordítják a kódot, a `<windows.h>` töltődik be (Win32 API), egyébként UNIX/Linux fejlécek (`<dirent.h>` könyvtárlistázáshoz, `<sys/types.h>` típusdefiníciókhoz).

`#ifdef _WIN32` is a **preprocessor conditional**: if compiled on Windows, `<windows.h>` is included (Win32 API); otherwise UNIX/Linux headers are used (`<dirent.h>` for directory listing, `<sys/types.h>` for type definitions).

---

## `using` deklarációk / `using` declarations

```cpp
using std::vector;
using std::string;
using std::cout;
using std::endl;
```

Ezek azt mondják a fordítónak: amikor `string`-et írunk, az `std::string`-et jelent, nem kell minden alkalommal kiírni az `std::` előtagot.

These tell the compiler: when we write `string`, it means `std::string`, so we don't have to write the `std::` prefix every time.

---

## `normalizePath` függvény / function

```cpp
std::string normalizePath(const std::string& path) {
    std::string normalizedPath = path;
#ifdef _WIN32
    std::replace(normalizedPath.begin(), normalizedPath.end(), '/', '\\');
#endif
    return normalizedPath;
}
```

### Mit csinál? / What does it do?

Windows-on a `/` (perjel) helyett `\` (fordított perjel) a könyvtárelválasztó. Ez a függvény az összes `/` karaktert `\`-re cseréli, de csak Windows-on.

On Windows, the directory separator is `\` (backslash) instead of `/` (forward slash). This function replaces all `/` characters with `\`, but only on Windows.

### Paraméter magyarázat / Parameter explanation

- `const std::string& path` — A `const` azt jelenti: a függvény nem módosítja az eredeti értéket. A `&` (referencia) azt jelenti: nem másolja le a stringet, hanem az eredetire mutat, ami gyorsabb és kevesebb memóriát igényel.

- `const std::string& path` — `const` means the function will not modify the original value. The `&` (reference) means it does not copy the string but points to the original, which is faster and uses less memory.

### `normalizedPath.begin()` és `normalizedPath.end()`

- **`.begin()`** — Egy iterátort ad vissza, amely a string **első karakterére** mutat.
- **`.end()`** — Egy iterátort ad vissza, amely a string **utolsó karaktere utáni pozícióra** mutat (nem az utolsóra, hanem a "vége után").
- Az `std::replace(begin, end, régi, új)` végigmegy a begin-től end-ig, és minden `régi` karaktert kicserél `új`-ra.

- **`.begin()`** — Returns an iterator pointing to the **first character** of the string.
- **`.end()`** — Returns an iterator pointing to the position **past the last character** (not the last one itself, but one beyond the end).
- `std::replace(begin, end, old_char, new_char)` iterates from begin to end and replaces every `old_char` with `new_char`.

---

## `isPathSafe` függvény / function

```cpp
bool isPathSafe(const std::string& path) {
    if (path.empty() || path.length() > 255) return false;
    if (path.find("..") != std::string::npos) return false;

    string lowerPath = toLowerCase(path);
    if (lowerPath.find("format") != std::string::npos || lowerPath.find("rm ") != std::string::npos) return false;

    return std::all_of(path.begin(), path.end(), [](unsigned char c) {
        return c != ';' && c != '&' && c != '|' && c != '>' &&
               c != '<' && c != '*' && c != '?' && c != '"';
    });
}
```

### Mit csinál? / What does it do?

Megvizsgálja, hogy egy fájlútvonal **biztonságos-e** (nem tartalmaz veszélyes karaktereket vagy parancsinjekciót).

It checks whether a file path is **safe** (does not contain dangerous characters or command injection attempts).

### `path.empty()`

Visszaadja `true`-t, ha a string hossza 0, azaz üres. Ha üres az útvonal, nincs mit kezelni, visszatérünk `false`-szal.

Returns `true` if the string has length 0, i.e. it is empty. If the path is empty, there is nothing to handle, so we return `false`.

### `path.length() > 255`

A legtöbb operációs rendszer (különösen régebbi Windows verziók) **255 karakterben korlátozza** a fájlneveket. Ha az útvonal hosszabb, valószínűleg érvénytelen vagy rosszindulatú bemenet.

Most operating systems (especially older Windows versions) **limit filenames to 255 characters**. If the path is longer, it is likely invalid or malicious input.

### `path.find("..")`

A `..` egy speciális könyvtárnév, amely az **egy szinttel feljebb lévő könyvtárra** mutat. Ha egy útvonal tartalmaz `..`-t, valaki megpróbálhat kilépni az engedélyezett könyvtárból (pl. `../../etc/passwd`). Ezt **directory traversal támadásnak** nevezik.

`..` is a special directory name meaning the **parent directory**. If a path contains `..`, someone might be trying to escape the allowed directory (e.g. `../../etc/passwd`). This is called a **directory traversal attack**.

### `std::string::npos`

Ez egy speciális konstans érték, amelyet az `std::string::find()` ad vissza, ha **nem találta meg** a keresett szöveget. Neve a "no position" rövidítése. Értéke általában `size_t` típusú maximális érték (pl. `18446744073709551615` 64 bites rendszereken).

This is a special constant value returned by `std::string::find()` when the searched text **was not found**. Its name is short for "no position". Its value is typically the maximum value of `size_t` (e.g. `18446744073709551615` on 64-bit systems).

### `lowerPath.find("format")` és `"rm "`

Ellenőrzi, hogy az útvonal nem tartalmaz-e veszélyes parancsokat szövegként:
- `format` — Windows lemezformázó parancs
- `rm ` — UNIX/Linux törlő parancs (a szóközzel együtt, hogy ne legyen téves találat pl. egy `programs` nevű mappán)

Checks that the path does not contain dangerous command strings as text:
- `format` — Windows disk format command
- `rm ` — UNIX/Linux remove command (with space, to avoid false matches e.g. on a folder named `programs`)

### `std::all_of` és a lambda függvény / lambda function

```cpp
return std::all_of(path.begin(), path.end(), [](unsigned char c) {
    return c != ';' && c != '&' && c != '|' && c != '>' &&
           c != '<' && c != '*' && c != '?' && c != '"';
});
```

Az `std::all_of` végigmegy a string minden karakterén, és **minden karakterre** meghívja az átadott függvényt. Ha minden karakterre `true`-t ad vissza a függvény, `std::all_of` is `true`-t ad vissza.

`std::all_of` iterates over every character in the string and calls the provided function **for each character**. If the function returns `true` for every character, `std::all_of` also returns `true`.

A `[](unsigned char c) { ... }` egy **lambda kifejezés** — névtelen (anonim) függvény, amelyet közvetlenül a kódban definiálunk. A `[]` a "capture list" (itt üres, mert nincs külső változóra szükség). Az `unsigned char` azért szerepel `char` helyett, mert a negatív `char` értékek undefined behavior-t okozhatnak a karakterek összehasonlításakor.

`[](unsigned char c) { ... }` is a **lambda expression** — an anonymous function defined inline. The `[]` is the "capture list" (empty here because no external variables are needed). `unsigned char` is used instead of `char` because negative `char` values can cause undefined behavior when comparing characters.

A tiltott karakterek és miért veszélyesek / The banned characters and why they are dangerous:

| Karakter | Miért veszélyes / Why dangerous |
|---|---|
| `;` | Shell-ben parancsok elválasztója (pl. `ls; rm -rf /`) |
| `&` | Shell háttérben futtatás, parancsok láncolása |
| `\|` | Pipe: parancs kimenetét a következőnek adja |
| `>` | Kimenet átirányítása fájlba (felülírja) |
| `<` | Bemenet átirányítása fájlból |
| `*` | Wildcard: minden fájlra illeszkedik |
| `?` | Egykarakteres wildcard |
| `"` | Idézőjel: shell parancsokban különleges jelentés |

---

## `copyFileFolders` függvény / function

```cpp
void copyFileFolders(const std::string& srcPath, bool isDirectory) { ... }
```

### Mit csinál? / What does it do?

Fájlt vagy mappát másol egy megadott forrásból egy megadott célba.

Copies a file or folder from a specified source to a specified destination.

### `bool isDirectory`

Egy `bool` (boolean) paraméter: `true`, ha mappáról van szó, `false`, ha fájlról. Ez azért fontos, mert a másolási parancs különböző Windowson és Linuxon attól függően, hogy fájlt vagy mappát kell másolni.

A `bool` (boolean) parameter: `true` if it is a directory, `false` if it is a file. This matters because the copy command differs depending on whether we are copying a file or a folder, and differs between Windows and Linux.

### `std::getline(std::cin, destName)`

Beolvas egy teljes sort a standard bemenetről (billentyűzetről) a `destName` stringbe. A sima `std::cin >> destName` megállna az első szóköznel, a `getline` viszont a teljes sort (szóközökkel együtt) beolvassa.

Reads an entire line from standard input (keyboard) into the `destName` string. Plain `std::cin >> destName` would stop at the first space, whereas `getline` reads the entire line including spaces.

### `string command` és `std::system()` / and `std::system()`

```cpp
#ifdef _WIN32
command = isDirectory ? "xcopy /E /I /H /Y \"" + nSrc + "\" \"" + nDest + "\"" : "copy /Y \"" + nSrc + "\" \"" + nDest + "\"";
#else
command = "cp -r -p \"" + nSrc + "\" \"" + nDest + "\"";
#endif
if (std::system(command.c_str()) == 0) { ... }
```

A program egy shell parancsot épít fel stringként, majd az `std::system()` segítségével futtatja azt az operációs rendszer parancsértelmezőjében. Ha a visszatérési értéke `0`, a parancs sikeresen lefutott.

The program constructs a shell command as a string and then runs it in the operating system's command interpreter using `std::system()`. If the return value is `0`, the command completed successfully.

- Windowson: `xcopy` (mapparekurzív másolás) vagy `copy` (fájlmásolás)
- Linuxon: `cp -r -p` (rekurzív, jogosultságok megőrzésével)

- On Windows: `xcopy` (recursive folder copy) or `copy` (file copy)
- On Linux: `cp -r -p` (recursive, preserving permissions)

A `command.c_str()` a C++ stringből C-stílusú (null-terminált) karaktertömböt ad vissza, amit `std::system()` elvár.

`command.c_str()` converts the C++ string to a C-style (null-terminated) character array, which `std::system()` requires.

---

## `deleteFileFolders` függvény / function

```cpp
void deleteFileFolders(const std::string& fullPath, bool isDirectory) { ... }
```

Megkérdezi a felhasználót megerősítésképpen (`y/n`), majd törli a fájlt vagy mappát.

Asks the user for confirmation (`y/n`), then deletes the file or folder.

A `toLowerCase(trim(confirm)) != "y"` biztosítja, hogy csak az egyértelmű `y` (kis- vagy nagybetűs) legyen elfogadva, szóközök nélkül. Ha nem `y`, megszakítja a törlést.

`toLowerCase(trim(confirm)) != "y"` ensures that only an unambiguous `y` (any case) is accepted, with surrounding whitespace stripped. If not `y`, deletion is cancelled.

---

## `movingFileFolders` és `reNameFileFolders` függvények / functions

Mindkettő hasonlóan működik a `copyFileFolders`-hez, de:
- `movingFileFolders`: az `mv` (Linux) vagy `move` (Windows) parancsot használja.
- `reNameFileFolders`: ugyanazt a parancsot (`mv`/`move`) használja, de csak a nevet változtatja, az útvonal elejét megtartja.

Both work similarly to `copyFileFolders`, but:
- `movingFileFolders`: uses the `mv` (Linux) or `move` (Windows) command.
- `reNameFileFolders`: uses the same command (`mv`/`move`), but only changes the name, keeping the path prefix the same.

### Az új név meghatározása átnevezésnél / Determining the new name during rename

```cpp
size_t lastSlash = srcPath.find_last_of("/\\");
string destPath = ((lastSlash == string::npos) ? "" : srcPath.substr(0, lastSlash + 1)) + newName;
```

- `find_last_of("/\\")` — megkeresi az utolsó `/` vagy `\` pozícióját, azaz a fájlnév kezdetét.
- `srcPath.substr(0, lastSlash + 1)` — kivágja az útvonal elejét (mappanév + `/`), és hozzáfűzi az új nevet.
- Ha nincs perjel (`npos`), az útvonal csak egy fájlnév, könyvtárprefixum nélkül.

- `find_last_of("/\\")` — finds the position of the last `/` or `\`, i.e. the start of the filename.
- `srcPath.substr(0, lastSlash + 1)` — extracts the path prefix (folder name + `/`), then appends the new name.
- If there is no slash (`npos`), the path is just a filename with no directory prefix.

### `InputResult` és `readLineWithHotkey`

```cpp
InputResult newNameInput = readLineWithHotkey("");
if (newNameInput.exitTriggered) { playBeep(); return; }
```

A saját `platformInput.h` modulból jövő `readLineWithHotkey` egy speciális szövegbeolvasó, amely figyeli a **Ctrl+C** billentyűkombinációt is. Ha a felhasználó Ctrl+C-t nyom, az `exitTriggered` mező `true` lesz, és a függvény megszakad (hangjelzést ad, majd visszalép).

The `readLineWithHotkey` function from the custom `platformInput.h` module is a special text-reading function that also monitors the **Ctrl+C** key combination. If the user presses Ctrl+C, the `exitTriggered` field is `true` and the function exits (plays a beep and returns).

---

## `listFiles` függvény / function

```cpp
vector<FileEntry> listFiles(const std::string &directory) { ... }
```

### Mit csinál? / What does it do?

Visszaad egy listát (`vector<FileEntry>`) az adott könyvtárban lévő fájlokról és almappákról. Csak `.data` kiterjesztésű fájlokat és mappákat listáz (más fájlokat kihagyja).

Returns a list (`vector<FileEntry>`) of files and subdirectories in the given directory. Only `.data` extension files and folders are listed (other files are skipped).

### `vector<FileEntry>`

A `vector` egy **dinamikus tömb**: automatikusan növekszik, ahogy elemeket adunk hozzá. A `FileEntry` egy saját struct (valószínűleg tartalmaz egy `name` stringet és egy `isDirectory` bool-t).

A `vector` is a **dynamic array**: it automatically grows as elements are added. `FileEntry` is a custom struct (likely containing a `name` string and an `isDirectory` bool).

### Windows-os ág / Windows branch

```cpp
#ifdef _WIN32
string searchPath = directory + "\\*";
WIN32_FIND_DATA findFileData;
HANDLE hFind = FindFirstFile(searchPath.c_str(), &findFileData);
if (hFind != INVALID_HANDLE_VALUE) {
    do {
        string filename = findFileData.cFileName;
        if (filename != "." && filename != "..") { ... }
    } while (FindNextFile(hFind, &findFileData));
    FindClose(hFind);
}
```

- `WIN32_FIND_DATA` — Win32 struktúra, amely az aktuálisan talált fájl/mappa adatait tartalmazza.
- `HANDLE` — Windows rendszerobjektum-hivatkozás (handle), amelyet a fájlkereső visszaad.
- `FindFirstFile` / `FindNextFile` / `FindClose` — Win32 API függvények a könyvtár bejárásához.
- `"."` és `".."` — Minden könyvtárban létező speciális bejegyzések (saját mappa és szülő mappa). Ezeket ki kell hagyni.
- `INVALID_HANDLE_VALUE` — A Win32 hibát jelző konstans, ha a könyvtár nem nyitható meg.

- `WIN32_FIND_DATA` — Win32 structure containing the data of the currently found file/folder.
- `HANDLE` — A Windows system object reference returned by the file finder.
- `FindFirstFile` / `FindNextFile` / `FindClose` — Win32 API functions for traversing a directory.
- `"."` and `".."` — Special entries present in every directory (current folder and parent folder). These must be skipped.
- `INVALID_HANDLE_VALUE` — Win32 constant indicating an error if the directory cannot be opened.

### Linux/UNIX ág / Linux/UNIX branch

```cpp
DIR *dir = opendir(directory.c_str());
if (dir != NULL) {
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        string filename = ent->d_name;
        if (filename != "." && filename != "..") {
            string fullPath = directory + "/" + filename;
            struct stat path_stat;
            bool isDir = (stat(fullPath.c_str(), &path_stat) == 0) ? S_ISDIR(path_stat.st_mode) : false;
            ...
        }
    }
    closedir(dir);
}
```

- `DIR *` — Mutatón keresztül hivatkozott könyvtárfolyam-struktúra.
- `opendir()` / `readdir()` / `closedir()` — POSIX könyvtárbejáró függvények.
- `struct dirent` — Az aktuálisan olvasott bejegyzés adatait tartalmazza; a `d_name` mező tartalmazza a fájlnevet.
- `struct stat` — Fájl metaadatait tároló struktúra (méret, típus, jogosultságok stb.).
- `stat(fullPath.c_str(), &path_stat)` — Lekéri a fájl metaadatait. Ha `0`-t ad vissza, sikerült.
- `S_ISDIR(path_stat.st_mode)` — Makró: `true`-t ad, ha a `st_mode` mező mappa típust jelez.

- `DIR *` — A directory stream structure referenced through a pointer.
- `opendir()` / `readdir()` / `closedir()` — POSIX directory traversal functions.
- `struct dirent` — Contains the data of the currently read entry; the `d_name` field holds the filename.
- `struct stat` — Structure storing file metadata (size, type, permissions, etc.).
- `stat(fullPath.c_str(), &path_stat)` — Retrieves file metadata. Returns `0` on success.
- `S_ISDIR(path_stat.st_mode)` — Macro: returns `true` if the `st_mode` field indicates a directory type.

---

## `listAndSelectFile` függvény / function

```cpp
void listAndSelectFile() {
    const string ROOT_DIR = "./data";
    string path = ROOT_DIR;
    for (;;) { ... }
}
```

### Mit csinál? / What does it do?

Ez a fő navigációs hurok. A felhasználó böngészhet a `./data` könyvtárban, megnyithat almappákat, futtathat parancsokat (del, cp, mv, rn, edit, mkdir).

This is the main navigation loop. The user can browse within the `./data` directory, open subfolders, and run commands (del, cp, mv, rn, edit, mkdir).

### `const string ROOT_DIR = "./data"`

A `./data` a program futtatási könyvtárához képest relatív útvonal. A `const` jelöli, hogy ez az érték nem változik a program futása során (védelem véletlen felülírás ellen).

`./data` is a path relative to the program's working directory. `const` marks that this value will not change during program execution (protection against accidental overwriting).

### `for (;;)`

Végtelen ciklus — ugyanaz, mint `while (true)`. A kilépést a `return` utasítás biztosítja, amelyet az `exit` parancs vagy a Ctrl+C vált ki.

An infinite loop — the same as `while (true)`. Exiting is done via the `return` statement, triggered by the `exit` command or Ctrl+C.

### Parancsok feldolgozása / Command processing

```cpp
size_t spacePos = input.find(' ');
if (spacePos != string::npos) {
    string cmd = toLowerCase(trim(input.substr(0, spacePos)));
    string targetName = trim(input.substr(spacePos + 1));
    ...
}
```

- `input.find(' ')` — Megkeresi az első szóköz pozícióját a bevitelben.
- `input.substr(0, spacePos)` — A szóköz előtti rész a parancs (pl. `del`, `cp`).
- `input.substr(spacePos + 1)` — A szóköz utáni rész a célfájl neve.

- `input.find(' ')` — Finds the position of the first space in the input.
- `input.substr(0, spacePos)` — The part before the space is the command (e.g. `del`, `cp`).
- `input.substr(spacePos + 1)` — The part after the space is the target filename.

### `..` kezelése / handling

```cpp
if (lowerInput == "..") {
    if (path.length() > ROOT_DIR.length()) {
        size_t lastSlash = path.find_last_of("/\\");
        if (lastSlash != string::npos) path = path.substr(0, lastSlash);
    }
    continue;
}
```

Ha a felhasználó `..`-t gépel és az aktuális útvonal hosszabb a gyökérkönyvtárnál, visszalép egy szinttel. A gyökérkönyvtáron (`./data`) túl nem lehet visszalépni — ez megakadályozza, hogy a felhasználó kikerüljön az engedélyezett területről.

If the user types `..` and the current path is longer than the root directory, the code moves one level up. You cannot go above the root directory (`./data`) — this prevents the user from escaping the allowed area.

---

## `isDirectory` függvény / function

```cpp
bool isDirectory(const std::string& path) {
    struct stat path_stat{};
    if (stat(path.c_str(), &path_stat) != 0) return false;
    return S_ISDIR(path_stat.st_mode);
}
```

A `struct stat path_stat{}` a struktúrát nullával inicializálja (`{}` value-initialization). Ha a `stat()` hívás `0`-tól eltérő értéket ad vissza, a fájl nem létezik vagy nem érhető el, és `false`-t ad vissza. Egyébként az `S_ISDIR` makróval ellenőrzi, hogy mappa-e.

`struct stat path_stat{}` initializes the struct to zero (`{}` value-initialization). If `stat()` returns a non-zero value, the file does not exist or is inaccessible, and the function returns `false`. Otherwise, `S_ISDIR` macro checks whether it is a directory.

---

## `createDirectory` függvény / function

```cpp
bool createDirectory(const std::string& path) { ... }
```

Új mappát hoz létre:
- Windowson: `mkdir "útvonal"`
- Linuxon: `mkdir -p "útvonal"` (a `-p` jelző azt jelenti: hozza létre az összes hiányzó szülőkönyvtárat is, és ne hibázzon, ha már létezik)

Creates a new directory:
- On Windows: `mkdir "path"`
- On Linux: `mkdir -p "path"` (the `-p` flag means: create all missing parent directories too, and do not error if it already exists)

---

## Összefoglalás / Summary

| Függvény / Function | Szerepe / Role |
|---|---|
| `normalizePath` | Perjel → fordított perjel Windowson / Forward slash to backslash on Windows |
| `isPathSafe` | Biztonsági ellenőrzés az útvonalra / Security check on the path |
| `copyFileFolders` | Fájl/mappa másolása / Copy file or folder |
| `deleteFileFolders` | Fájl/mappa törlése megerősítéssel / Delete file or folder with confirmation |
| `movingFileFolders` | Fájl/mappa áthelyezése / Move file or folder |
| `reNameFileFolders` | Fájl/mappa átnevezése / Rename file or folder |
| `editFile` | Fájl megnyitása szerkesztőben / Open file in editor |
| `listFiles` | Könyvtár tartalmának listázása / List contents of a directory |
| `listAndSelectFile` | Interaktív navigációs hurok / Interactive navigation loop |
| `isDirectory` | Mappa-e az útvonal? / Is the path a directory? |
| `createDirectory` | Új mappa létrehozása / Create a new directory |

