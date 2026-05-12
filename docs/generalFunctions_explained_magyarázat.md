# generalFunctions.cpp — Részletes magyarázat / Detailed Explanation

---

## A fájl célja / Purpose of the file

Ez a fájl az alkalmazás **globális segédfüggvényeit** tartalmazza: konzolkezelés, naplózás, szövegfeldolgozás, ékezetkezelés, hang.

This file contains the application's **global utility functions**: console handling, logging, text processing, accent normalization, and sound.

---

## Fejlécek (include-ok) / Headers (includes)

```cpp
#include "generalFunctions.h"
#include "../Translate/translations.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <map>
#include "dataFileReading.h"
#include "settings.h"
#include "Settings/colors.h"
```

| Include | Mit csinál / What it does |
|---|---|
| `<iostream>` | Standard be/kimenet: `cout`, `cin`, `cerr`. / Standard I/O. |
| `<limits>` | `std::numeric_limits`: típusok határértékei (pl. int max, streamsize max). / Type boundary values. |
| `<string>` | `std::string` típus. |
| `<fstream>` | Fájl olvasás/írás: `std::ofstream`, `std::ifstream`. / File reading and writing. |
| `<ctime>` | Időfüggvények: `std::time()`, `std::strftime()`, `std::localtime()`. / Time functions. |
| `<windows.h>` | Win32 API: a `Beep()` függvényhez kell. / Win32 API: needed for `Beep()`. |
| `<map>` | `std::map`: rendezett kulcs-érték párokat tároló konténer. / Ordered key-value container. |

---

## `explanation` függvény / function

```cpp
void explanation() {
    screenWipe();
    std::cout << getTranslation("ExplanationStrings.description") << "\n";
    ...
    waitToEnter();
}
```

Egyszerű leírást jelenít meg: letörli a képernyőt, kiírja a fordított szövegeket, majd vár az Enter lenyomásáig. Semmi rejtett logika nincs benne.

Displays a simple description: clears the screen, prints translated texts, then waits for Enter. There is no hidden logic here.

---

## `waitToEnter` függvény / function

```cpp
void waitToEnter() {
    std::cout << getTranslation("EnteringBack.pressToEnter") << "\n" << std::flush;
    std::cin.get();
}
```

### `std::flush`

A `std::cout` pufferelt: a karaktereket nem mindig küldi azonnal a képernyőre, hanem összegyűjti őket egy belső pufferben (gyorsabb így). A `std::flush` **azonnal kiküldi** a puffer tartalmát a kimenetre. Ez fontos, mert ha a felhasználó bevitelre vár (`cin.get()`), a szövegnek már meg kell jelennie előtte.

`std::cout` is buffered: characters are not always sent to the screen immediately but are collected in an internal buffer (this is faster). `std::flush` **immediately sends** the buffer contents to the output. This matters because if the user is waiting for input (`cin.get()`), the prompt text must already be visible.

### `std::cin.get()`

Egyetlen karaktert olvas be a standard bemenetről (általában az Enter lenyomását). A program addig megáll, amíg a felhasználó nem nyom Entert.

Reads a single character from standard input (typically the Enter key press). The program pauses until the user presses Enter.

---

## `exiting` függvény / function

```cpp
void exiting() {
    screenWipe();
    std::cout << getTranslation("ExitingStrings.exiting") << "\n" << std::flush;
    std::cin.get();
}
```

Letörli a képernyőt, kiírja a kilépési üzenetet, majd vár egyet, hogy a felhasználó láthassa. A `cin.get()` itt is egy véletlen Enter-ütés elnyelésére is szolgálhat (puffertisztítás).

Clears the screen, prints the exit message, then waits so the user can see it. The `cin.get()` here can also absorb an accidental buffered Enter keystroke (buffer flushing).

---

## `screenWipe` függvény / function

```cpp
void screenWipe() {
    if (useColors && !currentBG.empty()) {
        std::cout << currentBG;
    } else {
        std::cout << colors::RESET;
    }
    std::cout << "\x1B[2J\x1B[H\x1B[3J" << std::flush;
}
```

### `"\x1B[2J\x1B[H\x1B[3J"`

Ez egy **ANSI escape szekvencia** — speciális karaktersorozat, amelyet a terminál nem szövegként jelenít meg, hanem **parancsként** értelmez.

This is an **ANSI escape sequence** — a special character sequence that the terminal does not display as text but interprets as a **command**.

- `\x1B` — Az Escape karakter hexadecimális kódja (decimálisan 27). Ez indítja az escape szekvenciát. / The hexadecimal code for the Escape character (decimal 27). This starts the escape sequence.
- `[2J` — Törli az egész látható képernyőt. / Clears the entire visible screen.
- `[H` — A kurzort a bal felső sarokba (1,1 pozícióba) viszi. / Moves the cursor to the top-left corner (position 1,1).
- `[3J` — Törli a görgetési előzményeket is (scrollback buffer). / Clears the scrollback buffer (terminal history) as well.

Ez hatékonyabb, mint a `system("cls")` vagy `system("clear")` hívása, mert nem indít el egy külön shell folyamatot, közvetlenül a terminálnak szól.

This is more efficient than calling `system("cls")` or `system("clear")` because it does not launch a separate shell process; it speaks directly to the terminal.

### `!currentBG.empty()`

A `!` a logikai NEM operátor. `currentBG.empty()` igaz, ha a háttérszín string üres. Tehát `!currentBG.empty()` igaz, ha a háttérszín be van állítva (nem üres). A feltétel csak akkor állítja be a háttérszínt, ha valóban létezik beállított szín.

`!` is the logical NOT operator. `currentBG.empty()` is true when the background color string is empty. So `!currentBG.empty()` is true when a background color is set. The condition only applies the background color if one is actually configured.

---

## `pufferDelete` függvény / function

```cpp
void pufferDelete() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
```

### Miért kell ez? / Why is this needed?

Amikor a felhasználó valamilyen adatot gépel be és Entert nyom, az Enter (`\n`) benn marad a `cin` belső pufferében. Ha ezután egy `cin.get()` vagy `getline()` hívás következik, az rögtön "elolvassa" azt a bentmaradt `\n`-t, és a felhasználónak nem lesz lehetősége gépelni — a program mintha átugrotta volna a bevitelt.

When the user types something and presses Enter, the Enter (`\n`) remains in `cin`'s internal buffer. If a subsequent `cin.get()` or `getline()` call follows, it immediately "reads" that leftover `\n` and the user has no chance to type — the program appears to skip the input.

A `pufferDelete` ezt a bent maradt tartalmat dobja el.

`pufferDelete` discards this leftover content.

### `std::cin.ignore(n, delim)`

A `cin` pufferéből **figyelmen kívül hagy** (kihajít) legfeljebb `n` karaktert, vagy addig, amíg el nem éri a `delim` karaktert (azt is kihajítja).

**Ignores** (discards) at most `n` characters from the `cin` buffer, or until the `delim` character is reached (which is also discarded).

### `std::numeric_limits<std::streamsize>::max()`

Ez az egész sor azt jelenti: "dobd el az összes karaktert egészen a `\n`-ig".

This entire expression means: "discard all characters up to and including `\n`".

Bontsuk szét részekre / Breaking it down:

**`std::numeric_limits`** — Egy **sablon osztály** (template class) a `<limits>` fejlécből. Bármilyen numerikus típushoz megmondja annak határértékeit (minimum, maximum, stb.). Például: `std::numeric_limits<int>::max()` az `int` típus maximális értéke (2,147,483,647).

**`std::numeric_limits`** — A **template class** from the `<limits>` header. For any numeric type, it provides its boundary values (min, max, etc.). For example: `std::numeric_limits<int>::max()` is the maximum value of `int` (2,147,483,647).

**`std::streamsize`** — Speciális egész típus, amelyet a C++ standard könyvtár stream műveleteknél használ a méret/darabszám jelölésére (pl. hány karaktert olvasson). Általában `long` vagy `long long` méretű, platformtól függően.

**`std::streamsize`** — A special integer type used by the C++ standard library for stream operations to denote size/count (e.g. how many characters to read). It is typically `long` or `long long` in size, depending on the platform.

**`::max()`** — A `numeric_limits` statikus tagfüggvénye, amely visszaadja az adott típus legnagyobb lehetséges értékét. `std::streamsize` esetén ez egy nagyon nagy szám (pl. 9,223,372,036,854,775,807 64 bites rendszeren).

**`::max()`** — A static member function of `numeric_limits` that returns the largest possible value of that type. For `std::streamsize` this is a very large number (e.g. 9,223,372,036,854,775,807 on a 64-bit system).

Miért nem írunk egyszerűen egy nagy számot, pl. `9999`? Mert ha a pufferben véletlenül 10000 karakter lenne, csak 9999-et hagynánk el, és az utolsó benn maradna. A `max()` garantálja, hogy tényleg minden kidobódik.

Why not just write a large number like `9999`? Because if the buffer happened to contain 10,000 characters, only 9,999 would be discarded and one would remain. Using `max()` guarantees that everything is truly discarded.

---

## `logError` függvény / function

```cpp
void logError(const std::string& functionName, const std::string& errorMessage) {
    std::ofstream logFile("error.log ", std::ios::app);
    if (logFile.is_open()) {
        std::time_t now = std::time(nullptr);
        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        logFile << "[" << timestamp << "] [" << functionName << "] " << errorMessage << std::endl;
        logFile.close();
    }
}
```

### `std::ofstream`

Az "output file stream" rövidítése. Fájlba íráshoz használjuk. Megnyitáskor ha a fájl nem létezik, létrehozza; ha létezik, a megadott módtól függően kezeli.

Short for "output file stream". Used to write to files. When opened, if the file does not exist it is created; if it exists, it is handled according to the specified mode.

### `std::ios::app`

Az "append" (hozzáfűzés) mód. Ahelyett, hogy törölné a fájl tartalmát és elölről kezdené, **a végéhez fűzi** az új tartalmat. Ez azért fontos naplófájlnál, mert minden hiba megmarad, nem csak a legutóbbi.

"Append" mode. Instead of erasing the file contents and starting over, it **appends** new content to the end. This is essential for a log file because every error is preserved, not just the most recent one.

### `logFile.is_open()`

Ellenőrzi, hogy a fájl sikeresen megnyílt-e. Ha pl. a program nem rendelkezik írási joggal, vagy a lemez tele van, a megnyitás meghiúsul. Ebben az esetben nem kell hibaüzenetet írni (azt hova írnánk?), egyszerűen nem csinálunk semmit.

Checks whether the file was opened successfully. If, for example, the program lacks write permission or the disk is full, the open fails. In that case there is nothing to write to, so we simply do nothing.

### `std::time_t now = std::time(nullptr)`

- `std::time_t` — Egy egész típus, amely az időt **Unix timestamp** formájában tárolja: az 1970. január 1. 00:00:00 UTC óta eltelt másodpercek száma.
- `std::time(nullptr)` — Lekéri az aktuális időt. A `nullptr` azt jelenti, hogy nem kell sehova menteni az eredményt, csak visszaadni.

- `std::time_t` — An integer type storing time as a **Unix timestamp**: the number of seconds elapsed since January 1, 1970, 00:00:00 UTC.
- `std::time(nullptr)` — Retrieves the current time. `nullptr` means the result does not need to be stored anywhere else, just returned.

### `char timestamp[20]`

Egy 20 karakteres **C-stílusú karaktertömb** (nem `std::string`). Azért 20: a `"YYYY-MM-DD HH:MM:SS"` formátum 19 karakter + 1 null-termináló karakter (`\0`). A `\0` egy speciális karakter, amely jelzi a string végét C-ben.

A 20-character **C-style character array** (not `std::string`). Why 20: the `"YYYY-MM-DD HH:MM:SS"` format is 19 characters + 1 null-terminating character (`\0`). `\0` is a special character signalling the end of a string in C.

### `std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now))`

- `std::strftime` — Időt formáz szöveggé egy adott formátum szerint.
- `sizeof(timestamp)` — A tömb mérete bájtban (20). Ez biztonsági korlát: nem írhat többet ennél.
- `"%Y-%m-%d %H:%M:%S"` — Formátumkód: év-hónap-nap óra:perc:másodperc.
- `std::localtime(&now)` — A Unix timestamp-et `struct tm` struktúrává alakítja (év, hónap, nap stb. mezőkkel), a **helyi időzóna** szerint.

- `std::strftime` — Formats time into a text string according to a given format.
- `sizeof(timestamp)` — The size of the array in bytes (20). This is a safety limit: it cannot write more than this.
- `"%Y-%m-%d %H:%M:%S"` — Format code: year-month-day hour:minute:second.
- `std::localtime(&now)` — Converts the Unix timestamp into a `struct tm` structure (with year, month, day, etc. fields), according to the **local time zone**.

### `logFile.close()`

Explicit lezárja a fájlt. Technikailag az `ofstream` destruktora is lezárná, amikor a változó kimegy a hatókörből, de jó szokás azonnal lezárni, hogy más folyamatok is hozzáférhessenek a fájlhoz.

Explicitly closes the file. Technically the `ofstream` destructor would also close it when the variable goes out of scope, but it is good practice to close it immediately so that other processes can also access the file.

---

## `logMistakeWriteFile` függvény / function

```cpp
void logMistakeWriteFile(const WordPair& word) {
#ifdef _WIN32
    std::system("if not exist data\\mistakes mkdir data\\mistakes");
    std::string path = "data\\mistakes\\mistakes.data";
#else
    std::system("mkdir -p data/mistakes");
    std::string path = "data/mistakes/mistakes.data";
#endif
    std::ofstream mistakeFile(path, std::ios::app);
    if (mistakeFile.is_open()) {
        mistakeFile << word.targetLangMeaning << " -> " << word.motherLangMeaning;
        if (!word.pronunciation.empty()) {
            mistakeFile << " (" << word.pronunciation << ")";
        }
        mistakeFile << "\n";
        mistakeFile.close();
    }
}
```

### `const WordPair& word`

A `WordPair` egy saját struktúra, amely egy szópárt tárol (célnyelvi szó, anyanyelvi szó, kiejtés). A `const &` azt jelenti: nem másoljuk le, csak hivatkozunk rá, és nem módosítjuk.

`WordPair` is a custom structure storing a word pair (target language word, mother tongue word, pronunciation). `const &` means it is not copied, only referenced, and it will not be modified.

### `"if not exist data\\mistakes mkdir data\\mistakes"` (Windows)

Ez egy Windows `cmd.exe` parancs: ha a `data\mistakes` mappa nem létezik, hozza létre. Az `if not exist` feltétel azért kell, mert `mkdir` hibát dob, ha a mappa már létezik.

This is a Windows `cmd.exe` command: if the `data\mistakes` folder does not exist, create it. The `if not exist` condition is needed because `mkdir` throws an error if the folder already exists.

### `"mkdir -p data/mistakes"` (Linux)

A `-p` kapcsoló azt jelenti: "parents" — hozza létre az összes hiányzó szülőkönyvtárat is, és ne hibázzon, ha már létezik a mappa.

The `-p` flag means "parents" — create all missing parent directories as well, and do not error if the folder already exists.

---

## `playBeep` függvény / function

```cpp
void playBeep(int frequency, int duration) {
    if (!useSound) return;
#ifdef _WIN32
    Beep(frequency, duration);
#else
    std::cout << "\a" << std::flush;
#endif
}
```

### `int frequency`, `int duration`

Alapértelmezett értékek valószínűleg a fejlécfájlban vannak megadva (pl. `frequency = 750`, `duration = 200`). Az `int` egész típus, itt a hangfrekvenciát (Hz-ben) és a hang időtartamát (milliszekundumban) jelöli.

Default values are likely defined in the header file (e.g. `frequency = 750`, `duration = 200`). `int` is an integer type; here it denotes the sound frequency (in Hz) and duration (in milliseconds).

### `if (!useSound) return;`

Korai kilépés (early return): ha a hang ki van kapcsolva, azonnal visszatér, nem csinál semmit. Ez egy szokásos mintázat C++-ban a felesleges munka elkerülésére.

Early return: if sound is disabled, the function returns immediately without doing anything. This is a common C++ pattern for avoiding unnecessary work.

### `Beep(frequency, duration)` — Windows

A Win32 API `Beep()` függvénye közvetlen rendszerhangot játszik le a megadott frekvencián és időtartamon. Ezért kell a `<windows.h>`.

The Win32 API `Beep()` function plays a direct system sound at the given frequency and duration. This is why `<windows.h>` is needed.

### `"\a"` — Linux/macOS

A `\a` az ASCII **Bell karakter** (kód: 7). A legtöbb terminál emulátorban vagy rendszerhangot játszik le, vagy villogtatja az ablakot.

`\a` is the ASCII **Bell character** (code: 7). Most terminal emulators either play a system sound or flash the window in response.

---

## `removePunctuation` függvény / function

```cpp
std::string removePunctuation(const std::string& s) {
    std::string result;
    for (char c : s) {
        if (c != '!' && c != '?' && c != '.' && c != ',' && c != ';') {
            result += c;
        }
    }
    return result;
}
```

### `for (char c : s)`

Ez egy **range-based for loop** (tartományalapú ciklus). Végigmegy a string minden karakterén sorban. A `c` az aktuális karakter.

This is a **range-based for loop**. It iterates over every character in the string in order. `c` is the current character.

### `result += c`

A `+=` operátor egy karaktert fűz a string végéhez. Ez ugyanaz, mint `result.push_back(c)` vagy `result = result + c`, de hatékonyabb az utóbbinál, mert az nem hoz létre felesleges ideiglenes stringet.

The `+=` operator appends a character to the end of the string. This is the same as `result.push_back(c)` or `result = result + c`, but more efficient than the latter because it does not create an unnecessary temporary string.

Miért csak ezeket az írásjeleket veszi ki? Mert a kvíz összehasonlításánál nem akarjuk, hogy pl. "hello!" és "hello" különbözőnek számítson.

Why only these punctuation marks? Because during quiz comparison we do not want "hello!" and "hello" to count as different.

---

## `removeAccents` függvény / function

```cpp
std::string removeAccents(const std::string &s) {
    static const std::map<std::string, std::string> accentMap = {
        {"á", "a"}, {"é", "e"}, {"í", "i"}, {"ó", "o"}, {"ö", "o"}, {"ő", "o"},
        {"ú", "u"}, {"ü", "u"}, {"ű", "u"},
        {"Á", "a"}, {"É", "e"}, {"Í", "i"}, {"Ó", "o"}, {"Ö", "o"}, {"Ő", "o"},
        {"Ú", "u"}, {"Ü", "u"}, {"Ű", "u"}
    };

    std::string result;
    for (size_t i = 0; i < s.length(); ) {
        bool found = false;
        for (const std::pair<const std::string, std::string>& pair : accentMap) {
            const std::string& accent = pair.first;
            const std::string& plain = pair.second;
            if (s.compare(i, accent.length(), accent) == 0) {
                result += plain;
                i += accent.length();
                found = true;
                break;
            }
        }
        if (!found) {
            result += s[i];
            i++;
        }
    }
    return result;
}
```

### Miért van szükség erre? / Why is this needed?

A Magyar ékezetes betűk **UTF-8** kódolásban nem egy, hanem **két bájtot** foglalnak el. Például az `á` karakter nem egyetlen bájt, hanem a `0xC3 0xA1` bájtszekvencia. Ezért nem lehet egyszerűen karakterenként (`char`) dolgozni velük, mint az ASCII betűkkel.

Hungarian accented characters in **UTF-8** encoding do not occupy one byte but **two bytes**. For example, the character `á` is not a single byte but the byte sequence `0xC3 0xA1`. This means they cannot be handled simply character by character (`char`) the way ASCII letters can.

### Mi az az UTF-8? / What is UTF-8?

A **UTF-8** (Unicode Transformation Format, 8-bit) egy karakterkódolási szabvány, amely a világ szinte összes írásjelét képes tárolni. Az ASCII karakterek (a-z, 0-9 stb.) egy bájtot foglalnak, a legtöbb ékezetes latin betű két bájtot, a kínai karakterek három-négy bájtot.

**UTF-8** (Unicode Transformation Format, 8-bit) is a character encoding standard capable of storing virtually every writing system in the world. ASCII characters (a-z, 0-9, etc.) occupy one byte, most accented Latin letters occupy two bytes, and Chinese characters occupy three or four bytes.

### `static const std::map<std::string, std::string> accentMap`

#### `static`

Ez a kulcsszó itt azt jelenti: **a térkép csak egyszer jön létre**, az első függvényhíváskor, és utána mindig ugyanaz az objektum él a memóriában a program futásának végéig. Nem jön létre és nem semmisül meg minden egyes függvényhíváskor.

This keyword here means: **the map is created only once**, on the first function call, and the same object lives in memory until the program ends. It is not created and destroyed on every function call.

Miért fontos ez? Mert egy `std::map` megépítése (minden bejegyzés beillesztése és rendezése) időbe kerül. Ha a `static` nem lenne ott, minden `removeAccents` híváskor újra fel kellene építeni az egész térképet — feleslegesen.

Why does this matter? Because building a `std::map` (inserting and sorting all entries) takes time. Without `static`, the entire map would need to be rebuilt on every `removeAccents` call — needlessly.

#### `const`

A térkép tartalma soha nem változik — mindig ugyanazok az ékezet-csere párok. A `const` biztosítja, hogy senki ne módosíthassa véletlenül.

The map's content never changes — the same accent replacement pairs always apply. `const` ensures nobody can accidentally modify it.

#### `std::map<std::string, std::string>`

A `std::map` egy **rendezett, asszociatív konténer**: kulcs-érték párokat tárol, ahol minden kulcs egyedi, és a párok a kulcs szerint rendezve vannak (alapértelmezés szerint ábécérendben). Keresés: O(log n) — belső bináris fa alapján.

`std::map` is an **ordered associative container**: it stores key-value pairs where every key is unique and pairs are sorted by key (alphabetically by default). Lookup: O(log n) — based on an internal binary tree.

Itt a kulcs az ékezetes karakter (pl. `"á"`), az érték az ékezet nélküli változata (pl. `"a"`).

Here the key is the accented character (e.g. `"á"`) and the value is its unaccented version (e.g. `"a"`).

### `for (size_t i = 0; i < s.length(); )`

#### `size_t`

Előjel nélküli egész típus (unsigned integer), amelyet indexelésre és méretekre használnak. A `string::length()` is `size_t`-t ad vissza. Ha sima `int`-et használnánk, a fordító figyelmeztetést adna, mert `int` előjeles, `size_t` viszont nem.

An unsigned integer type used for indices and sizes. `string::length()` also returns `size_t`. If we used plain `int`, the compiler would warn because `int` is signed while `size_t` is not.

#### Miért nincs `i++` a ciklus fejlécben? / Why is there no `i++` in the loop header?

Mert `i` léptetése a ciklustörzsben történik, és a lépés mértéke változó: ha ékezetes karaktert találunk (2 bájt), `i += 2`; ha normál karaktert, `i += 1`. Ha a fejlécbe írnánk `i++`, az felülírná ezt a logikát.

Because `i` is incremented inside the loop body and the step size varies: if an accented character is found (2 bytes), `i += 2`; if a normal character, `i += 1`. Writing `i++` in the header would override this logic.

### `s.compare(i, accent.length(), accent) == 0`

- `s.compare(pos, len, str)` — Összehasonlítja az `s` string `pos`-tól kezdődő, `len` hosszú részét a `str` stringgel.
- Ha egyenlők, `0`-t ad vissza (C örökség: `strcmp` konvenció).
- Tehát: megnézi, hogy az `s` string `i`-edik pozíciójától kezdve pontosan az `accent` karakter (pl. `"á"`, 2 bájt) szerepel-e.

- `s.compare(pos, len, str)` — Compares the substring of `s` starting at `pos` with length `len` against `str`.
- Returns `0` if they are equal (C heritage: `strcmp` convention).
- So: it checks whether, starting at position `i` in `s`, exactly the `accent` character (e.g. `"á"`, 2 bytes) appears.

### `pair.first` és `pair.second`

A `std::map` bejegyzéseinek típusa `std::pair<const Key, Value>`. A `pair.first` a kulcsot (ékezetes karakter), a `pair.second` az értéket (ékezet nélküli karakter) adja vissza.

The type of `std::map` entries is `std::pair<const Key, Value>`. `pair.first` gives the key (accented character), `pair.second` gives the value (unaccented character).

### `break`

Amikor megtaláljuk az egyező ékezetes karaktert, a belső `for` ciklust azonnal megszakítjuk, mert nincs értelme tovább keresni — már megvan az eredmény.

When the matching accented character is found, the inner `for` loop is immediately broken, because there is no point searching further — the result is already found.

---

## `cleanString` függvény / function

```cpp
std::string cleanString(const std::string& s) {
    std::string result = toLowerCase(trim(s));
    result = removePunctuation(result);
    if (ignoreAccents) {
        result = removeAccents(result);
    }
    return result;
}
```

### Mit csinál? / What does it do?

Ez egy **összesítő függvény**: egymás után alkalmazza az összes szövegtisztító lépést.

This is a **compositor function**: it applies all text-cleaning steps in sequence.

1. `trim(s)` — Eltávolítja a vezető és záró szóközöket. / Removes leading and trailing spaces.
2. `toLowerCase(...)` — Kisbetűssé alakítja az eredményt. / Converts the result to lowercase.
3. `removePunctuation(...)` — Eltávolítja az írásjeleket. / Removes punctuation.
4. Ha `ignoreAccents` igaz: `removeAccents(...)` — Eltávolítja az ékezeteket. / If `ignoreAccents` is true: removes accents.

### `if (ignoreAccents)`

Az `ignoreAccents` egy globális beállítás (valószínűleg a `settings.h`-ban definiált `bool`). Ha a felhasználó bekapcsolta, hogy "ékezetek figyelmen kívül hagyása", ez `true` lesz. A függvény ezt a beállítást tiszteli.

`ignoreAccents` is a global setting (likely a `bool` defined in `settings.h`). If the user has enabled "ignore accents", this will be `true`. The function respects this setting.

---

## Összefoglalás / Summary

| Függvény / Function | Szerepe / Role |
|---|---|
| `explanation` | Leírást jelenít meg a képernyőn. / Displays a description on screen. |
| `waitToEnter` | Vár az Enter lenyomásáig. / Waits for the Enter key. |
| `exiting` | Kilépési képernyő megjelenítése. / Shows the exit screen. |
| `screenWipe` | ANSI szekvenciával törli a képernyőt. / Clears screen with ANSI escape sequence. |
| `pufferDelete` | Kitakarítja a `cin` puffert. / Cleans the `cin` buffer. |
| `logError` | Hibát ment fájlba időbélyeggel. / Saves an error to file with timestamp. |
| `logMistakeWriteFile` | Tévesztett szópárt ment fájlba. / Saves a mistaken word pair to file. |
| `playBeep` | Hangot játszik le (platformfüggően). / Plays a beep sound (platform-dependent). |
| `removePunctuation` | Írásjeleket távolít el. / Removes punctuation characters. |
| `removeAccents` | UTF-8 ékezetes karaktereket távolít el. / Removes UTF-8 accented characters. |
| `cleanString` | Összesített szövegtisztítás. / Combined text cleaning. |

