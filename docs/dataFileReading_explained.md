# dataFileReading.cpp — Részletes magyarázat / Detailed Explanation

---

## A fájl célja / Purpose of the file

Ez a fájl felelős a `.data` fájlokból való **szópár-beolvasásért** és a bevitt szöveg **előfeldolgozásáért** (kisbetűsítés, szóközök levágása, összehasonlítás). A kvíz alkalmazás ebből a modulból tölti be a kérdés-válasz párokat.

This file is responsible for **reading word pairs** from `.data` files and **preprocessing** typed text (lowercase conversion, whitespace trimming, comparison). The quiz application loads its question-answer pairs from this module.

---

## Fejlécek / Headers

```cpp
#include "dataFileReading.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "generalFunctions.h"
#include "translations.h"
```

| Include | Mit csinál / What it does |
|---|---|
| `<string>` | `std::string` típus. |
| `<sstream>` | `std::stringstream`: stringből csinál streamet, amelyből sorokat/szavakat lehet kiolvasni. / Creates a stream from a string, from which lines or words can be read. |
| `<algorithm>` | `std::transform`: karaktereken végzett tömeges átalakításhoz. / For bulk character transformation. |
| `<fstream>` | `std::ifstream`: fájlból olvasáshoz. / For reading from files. |
| `<iostream>` | `std::cerr`: hibakiíráshoz a standard hibakimenetre. / For writing errors to standard error output. |

---

## `using` deklarációk / declarations

```cpp
using string = std::string;
using stringstream = std::stringstream;
using std::transform;
using std::vector;
using std::ifstream;
using std::getline;
```

### `using string = std::string;`

Ez egy **típus-alias**: mostantól a `string` szó pontosan ugyanazt jelenti, mint az `std::string`. Ez az újabb C++ stílus (C++11 óta). A régi stílus: `typedef std::string string;` — funkcionalitásban teljesen azonosak, csak a szintaxis más.

This is a **type alias**: from now on the word `string` means exactly the same as `std::string`. This is the modern C++ style (since C++11). The old style: `typedef std::string string;` — they are functionally identical, only the syntax differs.

### Miért nem `using std::getline;`-ként kommentálják? / Why is `using std::getline` commented?

A megjegyzés ezt írja: "Mivel a getline nem változó hanem függvény..." — A `using std::getline` valójában teljesen helyes és működne. A megjegyzés arra utal, hogy a fordítók egyes régebbi verzióinál túlterhelési (overload) konfliktusokat okozhatott, ezért néhányan óvatosak vele. A modern C++-ban nincs ezzel gond.

The comment says: "Since getline is not a variable but a function..." — `using std::getline` is actually perfectly correct and would work. The comment hints that in some older compiler versions it could cause overload resolution conflicts, so some developers are cautious with it. In modern C++ this is not an issue.

---

## `toLowerCase` függvény / function

```cpp
string toLowerCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
```

### Miért `string s` és nem `const string& s`?

Ez szándékos. Mivel a függvény módosítja a stringet (kisbetűsíti), és vissza is adja, **értékmásolatot** kap paraméterként. Az `s` a hívó oldalon lévő eredeti string másolata. Így az eredeti nem változik meg, a másolatot pedig szabadon módosíthatjuk.

This is intentional. Since the function modifies the string (lowercases it) and returns it, it receives a **copy by value**. `s` is a copy of the caller's original string. This way the original is not changed, and the copy can be freely modified.

### `std::transform(first, last, output, func)`

Ez az `<algorithm>` könyvtárból jövő függvény. Végigmegy a `[first, last)` tartomány minden elemén, minden elemre meghívja a `func` függvényt, és az eredményt az `output` iterátortól kezdve tárolja.

This function comes from the `<algorithm>` library. It iterates over every element in the range `[first, last)`, calls `func` on each element, and stores the result starting from the `output` iterator.

- `s.begin()` — Az első karakter pozíciója (forrás kezdete). / Position of the first character (source start).
- `s.end()` — Az utolsó karakter utáni pozíció (forrás vége). / Position past the last character (source end).
- `s.begin()` (harmadikként / third) — Az eredmény ide kerül vissza, azaz helyben módosítja a stringet. / The result is stored back here, i.e. it modifies the string in-place.
- `::tolower` — Lásd lent. / See below.

### `::tolower`

A `::` a **globális névtér** előtagja. A `tolower` egy C standard könyvtárbeli függvény (az `<cctype>` fejlécből), amely egy karaktert kisbetűssé alakít. Az `int`-et vár és `int`-et ad vissza (C örökség).

`::` is the **global namespace** prefix. `tolower` is a C standard library function (from `<cctype>`) that converts a character to lowercase. It takes an `int` and returns an `int` (C heritage).

Miért `::tolower` és nem `std::tolower`? Mert az `std::tolower` egy túlterhelt (overloaded) sablon, amelynek átadva egy iterátort a fordító nem tudja egyértelműen kikövetkeztetni a típust, és fordítási hibát ad. A `::tolower` a globális, egyszerű C-s változat, amely egyértelműen működik `transform`-mal.

Why `::tolower` and not `std::tolower`? Because `std::tolower` is an overloaded template; passing it to an iterator makes the compiler unable to unambiguously deduce the type, resulting in a compile error. `::tolower` is the plain global C-style version that works unambiguously with `transform`.

### A kommentált alternatívák / The commented-out alternatives

A fájlban két másik megvalósítás is látható kommentben:

Two other implementations are also shown in comments in the file:

**1. Indexeléses ciklus / Index-based loop:**
```cpp
for (size_t i = 0; i < s.length(); ++i) {
    s[i] = std::tolower(s[i]);
}
```
Klasszikus C stílusú megközelítés. A `++i` (pre-increment) egy hajszálnyival hatékonyabb, mint az `i++` (post-increment), mert az utóbbi létrehoz egy ideiglenes másolatot a régi értékről. Stringeknél ez elhanyagolható, de jó szokás.

Classic C-style approach. `++i` (pre-increment) is marginally more efficient than `i++` (post-increment) because the latter creates a temporary copy of the old value. For strings this is negligible, but it is good practice.

**2. Referenciás range-based for / Reference-based range-based for:**
```cpp
for (char &c : s) {
    c = std::tolower(c);
}
```
A `char &c` egy **referencia** az aktuális karakterre — azaz közvetlenül a string belső bájtját módosítja, nem egy másolatot. Ha `char c` lenne (referencia nélkül), a módosítás nem hatna az eredeti stringre.

`char &c` is a **reference** to the current character — it directly modifies the internal byte of the string, not a copy. If it were `char c` (without reference), the modification would not affect the original string.

---

## `trim` függvény / function

```cpp
string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) {
        return ("");
    } else {
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, (last - first + 1));
    }
}
```

### Mit csinál? / What does it do?

Eltávolítja a string elejéről és végéről a felesleges **whitespace karaktereket** (szóközök, tabulátorok, sortörések).

Removes unnecessary **whitespace characters** (spaces, tabs, line breaks) from the beginning and end of a string.

### `str.find_first_not_of(" \t\n\r")`

Végigmegy a string elejétől, és megadja az **első olyan karakter pozícióját**, amely nem szóköz (`' '`), tabulátor (`'\t'`), újsor (`'\n'`), vagy Windows-os kocsivisszatérés (`'\r'`). Ha az egész string ilyen karakterekből áll, `npos`-t ad vissza.

Scans from the beginning of the string and returns the **position of the first character** that is not a space (`' '`), tab (`'\t'`), newline (`'\n'`), or Windows carriage return (`'\r'`). If the entire string consists of such characters, it returns `npos`.

### A whitespace karakterek / Whitespace characters

| Karakter | Neve / Name | Kód / Code | Mikor fordul elő / When it appears |
|---|---|---|---|
| `' '` | Space / Szóköz | 32 | Normál szóköz billentyű / Normal space key |
| `'\t'` | Tab | 9 | Tab billentyű / Tab key |
| `'\n'` | Newline / Újsor | 10 | Sorvég Unix/Linux rendszeren / Line end on Unix/Linux |
| `'\r'` | Carriage return | 13 | Windows sorvég első karaktere / First character of Windows line ending |

A Windows szövegfájlokban a sorvég `\r\n` (két karakter), Linuxon csak `\n`. Ha egy Windows-on készült fájlt Linux-on olvasunk, a `\r` benne maradhat a sor végén — ezért kell a `\r`-t is kezelni a trimben.

In Windows text files the line ending is `\r\n` (two characters), on Linux it is just `\n`. If a file created on Windows is read on Linux, the `\r` may remain at the end of lines — this is why `\r` must also be handled in trim.

### `str.find_last_not_of(" \t\n\r")`

Ugyanez, de **hátulról** keresi az utolsó nem-whitespace karakter pozícióját.

The same, but searches **from the end** for the position of the last non-whitespace character.

### `str.substr(first, (last - first + 1))`

- `str.substr(pos, len)` — Kivágja a string `pos` pozíciótól induló, `len` hosszú részét.
- `last - first` — A két pozíció különbsége a hossz mínusz egy (mert az indexelés 0-tól indul).
- `+ 1` — Azért kell, mert a `last` pozíción lévő karakter is beletartozik a kívánt részbe. Ha nem adnánk hozzá, az utolsó karakter kimaradna.

- `str.substr(pos, len)` — Extracts the substring starting at position `pos` with length `len`.
- `last - first` — The difference of the two positions is the length minus one (because indexing starts at 0).
- `+ 1` — Needed because the character at position `last` is also part of the desired substring. Without it the last character would be omitted.

**Példa / Example:**
```
str    = "  hello  "
indexek:  0123456789
first  = 2  (az 'h' pozíciója / position of 'h')
last   = 6  (az 'o' pozíciója / position of 'o')
substr(2, 6-2+1) = substr(2, 5) = "hello"
```

---

## `checkMultipleAnswers` függvény / function

```cpp
bool checkMultipleAnswers(const std::string& userAnswer, const std::string& correctAnswersString) {
    string cleanedUserAnswer = cleanString(userAnswer);
    stringstream ss(trim(correctAnswersString));
    string slice;

    while (getline(ss, slice, ',')) {
        if (cleanString(slice) == cleanedUserAnswer) {
            return true;
        }
    }
    return false;
}
```

### Mit csinál? / What does it do?

Ellenőrzi, hogy a felhasználó válasza megegyezik-e a **vesszővel elválasztott helyes válaszok** valamelyikével. Például ha a helyes válasz `"alma, apple, Apfel"`, akkor az `"apple"`, `"alma"` és `"Apfel"` mind helyesek lesznek.

Checks whether the user's answer matches any of the **comma-separated correct answers**. For example if the correct answer field is `"alma, apple, Apfel"`, then `"apple"`, `"alma"`, and `"Apfel"` are all accepted.

### `stringstream ss(trim(correctAnswersString))`

Egy `std::stringstream` objektum, amelyet a helyes válaszok stringjével inicializálunk. A `stringstream` úgy viselkedik, mint egy fájlstream, csak nem fájlból, hanem egy stringből olvas. Ez lehetővé teszi, hogy a `getline`-t és más stream-műveleteket használjuk rajta.

A `std::stringstream` object initialized with the correct answers string. A `stringstream` behaves like a file stream, but reads from a string instead of a file. This allows us to use `getline` and other stream operations on it.

### `getline(ss, slice, ',')`

Ez a `getline` egy **három paraméteres** változata:
- `ss` — A forrás stream (itt a stringstream).
- `slice` — Ide kerül a kiolvasott szövegdarab.
- `','` — Ez az **elválasztó karakter** (delimiter). A `getline` addig olvas, amíg ezt a karaktert meg nem találja, vagy a stream végére nem ér.

This is the **three-parameter** version of `getline`:
- `ss` — The source stream (here the stringstream).
- `slice` — The extracted text piece is stored here.
- `','` — This is the **delimiter character**. `getline` reads until it finds this character or reaches the end of the stream.

**Működés lépésről lépésre / Step-by-step operation:**
```
correctAnswersString = "alma, apple, Apfel"

1. getline olvas ',' -ig → slice = "alma"
2. getline olvas ',' -ig → slice = " apple"
3. getline olvas stream végéig → slice = " Apfel"
4. stream vége, getline false-t ad → while kilép
```

### `while (getline(ss, slice, ','))`

A `getline` visszatérési értéke maga a stream referenciája, amelyet `bool`-ra lehet konvertálni: `true`, ha sikeres olvasás történt; `false`, ha a stream végére értünk vagy hiba volt. Ez teszi lehetővé, hogy a `while` feltételként használja.

The return value of `getline` is the stream reference itself, which can be converted to `bool`: `true` if a successful read occurred; `false` if the end of stream was reached or an error occurred. This is what makes it usable as a `while` condition.

### `cleanString(slice) == cleanedUserAnswer`

Mindkét oldalt `cleanString`-gel normalizáljuk (kisbetű, trim, írásjelek, ékezetek) az összehasonlítás előtt. Ez biztosítja, hogy a `"  Apple! "` és az `"apple"` egyenlőnek számítson.

Both sides are normalized with `cleanString` (lowercase, trim, punctuation, accents) before comparison. This ensures that `"  Apple! "` and `"apple"` count as equal.

### Korai visszatérés (early return)

Ha megtaláljuk az egyezést, azonnal `return true`-val kilépünk — nem futtatjuk végig a ciklust feleslegesen. Ha a ciklus végigfutott anélkül, hogy egyezést talált volna, `return false` az eredmény.

If a match is found, we immediately exit with `return true` — we do not run through the rest of the loop needlessly. If the loop completes without finding a match, the result is `return false`.

---

## `loadWords` függvény / function

```cpp
vector<WordPair> loadWords(const std::string &filename) {
    vector<WordPair> words;
    ifstream file(filename);
    string line;
    ...
    return words;
}
```

### `vector<WordPair> words`

Egy üres, dinamikus tömb, amelybe a beolvasott szópárokat gyűjtjük. A függvény végén ezt adjuk vissza.

An empty dynamic array into which the read word pairs are collected. This is returned at the end of the function.

### `ifstream file(filename)`

Megnyit egy fájlt **olvasásra**. Az `ifstream` = "input file stream". Ha a fájl nem létezik vagy nem olvasható, a stream hibás állapotba kerül, és a `file.is_open()` `false`-t ad vissza.

Opens a file for **reading**. `ifstream` = "input file stream". If the file does not exist or is not readable, the stream enters an error state and `file.is_open()` returns `false`.

### `if (!file.is_open())`

Ha a fájl nem nyílt meg, naplózzuk a hibát, kiírjuk a hibaüzenetet a `std::cerr`-re (standard hibakimenet — általában szintén a terminálban jelenik meg, de elkülönül a normál kimenettől), majd visszaadjuk az üres vektort.

If the file did not open, we log the error, print the error message to `std::cerr` (standard error output — typically also visible in the terminal, but separate from normal output), then return the empty vector.

### `while (getline(file, line))`

Soronként olvassa be a fájlt. Minden iterációban a következő sor kerül a `line` stringbe. Ha a fájl végére érünk, `getline` `false`-t ad, a ciklus megáll.

Reads the file line by line. In each iteration the next line goes into the `line` string. When the end of file is reached, `getline` returns `false` and the loop stops.

### `if (line.empty()) continue;`

Ha az aktuális sor üres (pl. üres sor a fájlban), átugorjuk és a következő sorral folytatjuk. A `continue` utasítás a ciklus következő iterációjára ugrik, kihagyva a maradék törzset.

If the current line is empty (e.g. a blank line in the file), we skip it and continue with the next line. The `continue` statement jumps to the next iteration of the loop, skipping the rest of the body.

### `WordPair currentWord`

Egy saját struktúra (valószínűleg a `dataFileReading.h`-ban definiálva), amely három mezőt tartalmaz:
- `targetLangMeaning` — A célnyelvi szó (pl. angol). / The target language word (e.g. English).
- `motherLangMeaning` — Az anyanyelvi szó (pl. magyar). / The mother tongue word (e.g. Hungarian).
- `pronunciation` — Opcionális kiejtési útmutató. / Optional pronunciation guide.

A custom struct (likely defined in `dataFileReading.h`) with three fields.

---

### Kiejtés feldolgozása / Pronunciation parsing

```cpp
size_t openBracket  = line.find('[');
size_t closeBracket = line.find(']', openBracket);

if (openBracket != string::npos && closeBracket != string::npos) {
    currentWord.pronunciation = line.substr(openBracket + 1, closeBracket - openBracket - 1);
    currentWord.pronunciation = trim(currentWord.pronunciation);
    line = line.substr(0, openBracket);
}
```

**Mit csinál? / What does it do?**

Ha a sor tartalmaz szögletes zárójeleket (pl. `"apple -> alma [aepl]"`), kivágja a köztük lévő szöveget kiejtésként, majd az eredeti sorból eltávolítja a zárójelekkel együtt.

If the line contains square brackets (e.g. `"apple -> alma [aepl]"`), it extracts the text between them as pronunciation, then removes the brackets and their content from the original line.

**`line.find(']', openBracket)`**

A `find` kétparaméteres változata: a második paraméter a keresés kezdőpozíciója. Így nem az első `]`-t keresi a string elejétől, hanem az `openBracket` pozíciójától kezdve — ez biztosítja, hogy a nyitó és záró zárójel összetartozzon.

The two-parameter version of `find`: the second parameter is the starting position for the search. This does not search for the first `]` from the beginning of the string but from the `openBracket` position — ensuring that the opening and closing brackets are matched together.

**`line.substr(openBracket + 1, closeBracket - openBracket - 1)`**

Kivágja a `[` és `]` közé eső szöveget:
- `openBracket + 1` — A `[` utáni pozíció (magát a `[`-t kihagyjuk).
- `closeBracket - openBracket - 1` — A kívánt rész hossza: a két zárójel távolsága mínusz 1, hogy a `]` maga ne kerüljön bele.

Extracts the text between `[` and `]`:
- `openBracket + 1` — The position after `[` (we skip the `[` itself).
- `closeBracket - openBracket - 1` — The length of the desired section: the distance between the two brackets minus 1, so the `]` itself is not included.

**Példa / Example:**
```
line        = "apple -> alma [aepl]"
openBracket = 15  (a '[' pozíciója / position of '[')
closeBracket= 19  (a ']' pozíciója / position of ']')

substr(16, 19-15-1) = substr(16, 3) = "aep"
```
Helyes: `closeBracket - openBracket - 1 = 19 - 15 - 1 = 3`, ami az `"aep"` — de valójában `[aepl]` esetén:
```
openBracket = 15, closeBracket = 20
substr(16, 20-15-1) = substr(16, 4) = "aepl"  ✓
```

**`line = line.substr(0, openBracket)`**

A sort lecseréljük arra, ami a `[` előtt volt. Tehát a `"apple -> alma [aepl]"` sorból `"apple -> alma "` lesz, majd a separator keresés ezen a rövidített soron fut le.

The line is replaced with everything before `[`. So `"apple -> alma [aepl]"` becomes `"apple -> alma "`, and the separator search then runs on this shortened line.

---

### Elválasztó (separator) keresés / Separator search

```cpp
size_t separatorPos = line.find("->");
int skipChars = 2;

if (separatorPos == string::npos) {
    separatorPos = line.find('>');
    skipChars = 1;
}
```

Először a `"->"` elválasztót keresi. Ha nincs meg, visszaesik a csak `">"` karakterre. A `skipChars` változó azt tárolja, hány karaktert kell átugorni az elválasztó után, hogy a célnyelvi szó következzen.

First it searches for the `"->"` separator. If not found, it falls back to just `">"`. The `skipChars` variable stores how many characters to skip after the separator to reach the target language word.

**Miért két elválasztó? / Why two separators?**

Rugalmasság: a felhasználó kézzel is írhat adatfájlokat, és előfordulhat, hogy elfelejtik a kötőjelet. A `>` rövidebb, kevésbé fáradságos gépelni.

Flexibility: users may write data files by hand and might forget the hyphen. `>` is shorter and less effort to type.

### Az elválasztó utáni szöveg kinyerése / Extracting text after the separator

```cpp
if (separatorPos != string::npos) {
    currentWord.targetLangMeaning = line.substr(0, separatorPos);

    size_t hungarianStart = separatorPos + skipChars;
    if (hungarianStart < line.length()) {
        currentWord.motherLangMeaning = line.substr(hungarianStart);
    }
    currentWord.targetLangMeaning = trim(currentWord.targetLangMeaning);
    currentWord.motherLangMeaning = trim(currentWord.motherLangMeaning);

    if (!currentWord.targetLangMeaning.empty() && !currentWord.motherLangMeaning.empty()) {
        words.push_back(currentWord);
    }
}
```

**`line.substr(0, separatorPos)`**

Az elválasztó **előtti** rész — ez a célnyelvi szó (pl. `"apple"`).

The part **before** the separator — this is the target language word (e.g. `"apple"`).

**`line.substr(hungarianStart)`**

A `substr` egypAraméteres változata: a megadott pozíciótól a **string végéig** ad vissza mindent. Ez a magyar (anyanyelvi) szó.

The one-parameter version of `substr`: returns everything from the given position to the **end of the string**. This is the Hungarian (mother tongue) word.

**`hungarianStart < line.length()`**

Biztonsági ellenőrzés: ha az elválasztó pontosan a sor végén van, és utána nincs semmi, a `hungarianStart` egyenlő lenne `line.length()`-gel, és a `substr` üres stringet adna vissza — de a `substr` túlindexelés esetén kivételt dob. Ez az ellenőrzés ezt akadályozza meg.

A safety check: if the separator is exactly at the end of the line with nothing after it, `hungarianStart` would equal `line.length()`, and `substr` would return an empty string — but `substr` with an out-of-range position throws an exception. This check prevents that.

**`words.push_back(currentWord)`**

Hozzáadja az aktuális szópárt a vektorhoz. A `push_back` a vektor végéhez fűzi az elemet; ha szükséges, a vektor automatikusan növeli a belső tárterületét.

Adds the current word pair to the vector. `push_back` appends the element to the end of the vector; if necessary, the vector automatically grows its internal storage.

**`file.close()`**

Explicit lezárja a fájlt. Az `ifstream` destruktora ugyan automatikusan lezárná, de explicit lezárás jó szokás: jelzi az olvasónak, hogy itt véget ér a fájlmunka.

Explicitly closes the file. The `ifstream` destructor would close it automatically, but explicit closing is good practice: it signals to the reader that file work ends here.

---

## Egy teljes beolvasási példa / A complete parsing example

**Fájlsor / File line:**
```
apple -> alma [aepl]
```

**Feldolgozás lépései / Processing steps:**

```
1. line = "apple -> alma [aepl]"

2. openBracket  = 15  ('[' pozíciója)
   closeBracket = 20  (']' pozíciója)
   pronunciation = "aepl"
   line = "apple -> alma "           (zárójelek kivágva)

3. separatorPos = 6  ("->")
   skipChars = 2

4. targetLangMeaning = "apple "      → trim → "apple"
   motherLangMeaning = " alma "      → trim → "alma"

5. Egyik sem üres → words.push_back(currentWord)
```

**Eredmény / Result:**
```
currentWord.targetLangMeaning = "apple"
currentWord.motherLangMeaning = "alma"
currentWord.pronunciation     = "aepl"
```

---

## Összefoglalás / Summary

| Függvény / Function | Szerepe / Role |
|---|---|
| `toLowerCase` | Stringet kisbetűssé alakít. / Converts string to lowercase. |
| `trim` | Levágja a vezető és záró whitespace-t. / Trims leading and trailing whitespace. |
| `checkMultipleAnswers` | Vesszős válaszlistában keres egyezést. / Checks for match in comma-separated answer list. |
| `loadWords` | `.data` fájlból szópárokat tölt be. / Loads word pairs from a `.data` file. |

**`using string = std::string` vs `typedef`** — Teljesen ugyanaz az eredmény, csak a szintaxis más. A `using` az újabb, olvashatóbb C++11-es forma. A régi `typedef std::string string` örökség a C-ből.

**Miért `::tolower` és nem `std::tolower`?** — Az `std::tolower` sablon (template), és amikor a `transform`-nak átadjuk, a fordító nem tudja eldönteni, melyik overloadot kell használni — fordítási hiba lesz. A `::tolower` a régi C-s egységes változat, ezzel nem akad ki a fordító.

**A `getline` háromparaméteres változata** — Normál esetben `\n`-ig olvas. Ha harmadik paraméterként `','`-t adunk, addig olvas. Így vágjuk szét a `"alma, apple, Apfel"` stringet darabokra egy igazi stream-olvasóval, anélkül, hogy kézzel keresnénk vesszőket.

**`substr(openBracket + 1, closeBracket - openBracket - 1)`** — Ez az a rész, ami elsőre ijesztőnek tűnik. Az `+ 1` azért kell, hogy a `[` maga ne kerüljön bele. A `- 1` a végén azért kell, hogy a `]` maga se kerüljön bele. Ha ezek valamelyike hiányozna, a kimenetben benne lenne az egyik zárójel karakter is.