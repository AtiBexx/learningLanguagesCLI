# `toLowerCase` függvény – mit csinál?

A célja:
 minden betűt kisbetűvé alakít

Példa:

```
"HellO WoRLD" → "hello world"
```

Ez azért kell, mert így könnyebb összehasonlítani szövegeket (pl. "Exit", "EXIT", "exit" mind ugyanaz lesz).

------

# 1. verzió (LEGJOBB és leggyakoribb)

```cpp
string toLowerCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
```

## Mi történik itt?

### `string toLowerCase(string s)`

- kap egy szöveget (`s`)
- visszaad egy átalakított szöveget

------

### `transform(...)`

Ez a kulcs.

```cpp
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

Ez azt jelenti:

| rész                       | jelentés                       |
| -------------------------- | ------------------------------ |
| `s.begin()`                | a string első karaktere        |
| `s.end()`                  | a string utolsó után lévő hely |
| `s.begin()` (3. paraméter) | ide írja vissza az eredményt   |
| `::tolower`                | minden karaktert kisbetűsít    |

------

## Egyszerűen:

 végigmegy a szövegen
 minden karaktert kisbetűvé alakít
 ugyanabba a stringbe visszaírja

------

# 2. verzió (hagyományos C++ ciklussal)

```cpp
string toLowerCase(string s) {
    for (size_t i = 0; i < s.length(); ++i) {
        s[i] = std::tolower(s[i]);
    }
    return s;
}
```

## Mi történik itt?

### `for (size_t i = 0; i < s.length(); ++i)`

- végigmegyünk a stringen indexekkel
- `i` = aktuális karakter pozíciója

------

### `s[i] = std::tolower(s[i]);`

Ez történik:

- kivesszük a karaktert
- kisbetűvé alakítjuk
- visszaírjuk ugyanarra a helyre

------

## Példa:

```
"H" → "h"
"E" → "e"
"L" → "l"
```

------

# 3. verzió (range-based for, modern C++)

```cpp
string toLowerCase(string s) {
    for (char &c : s) {
        c = std::tolower(c);
    }
    return s;
}
```

## Mi ez?

Ez ugyanaz, csak egyszerűbb.

------

### `for (char &c : s)`

Ez azt jelenti:

- menj végig minden karakteren
- `c` mindig az aktuális karakter
- `&` = referencia → NEM másolat, hanem az eredeti karakter

------

### `c = std::tolower(c);`

- átalakítja kisbetűvé
- és rögtön módosítja az eredeti stringet

------

# Összefoglalás (nagyon fontos)

| verzió      | mit csinál        | mikor jó      |
| ----------- | ----------------- | ------------- |
| `transform` | gyors, modern     | ajánlott      |
| indexes for | klasszikus        | tanuláshoz jó |
| range for   | tiszta, olvasható | modern C++    |

------

# Fontos megjegyzés (amit sokan nem tudnak)

A `tolower()`:

- csak angol betűkre biztos
- ékezetes karaktereknél (á, é, ő) nem mindig tökéletes

Ezért nálad külön van:

```cpp
removeAccents()
```

------

Ha akarod, a következő lépésben elmagyarázom:

- mi az a `transform` belül (algoritmus szinten)
- vagy hogyan működik karakterenként a string memória szinten
- vagy hogyan lehet ezt Unicode-barát módon csinálni (ez már advanced)

### FULL kód

```
//kisbetüsítésre átalakítunk mindent kisbetűre
//convert everything to lowercase
string toLowerCase(string s) {
    //Nagybetűsítésre ::toupper a tolower helyett
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    return s;
}
/*
string toLowerCase(string s) {
    // Végigmegyünk a karaktereken egyenként
    for (size_t i = 0; i < s.length(); ++i) {
        // Minden karaktert átalakítunk kisbetűssé
        s[i] = std::tolower(s[i]);
    }
    return s;
}
 */ //vagy
/*
string toLowerCase(string s) {
    // Referenciával (&) megyünk végig, hogy módosíthassuk az eredeti karaktert
    for (char &c : s) {
        c = std::tolower(c);
    }
    return s;
}
```

