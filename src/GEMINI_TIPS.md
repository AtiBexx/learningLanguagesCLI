# Gemini CLI Kezelési Útmutató & Tippek

Ez a fájl összefoglalja, hogyan kezelheted hatékonyan a Gemini CLI-t, ha elakadna, ismételné magát, vagy túl nagy fájlokkal dolgozol.

## 1. Mit tegyél, ha az ágens ismétli magát?

Ha úgy érzed, hogy a Gemini CLI "beragadt" vagy olyan feladatot akar elvégezni, amivel már készen vagy:

*   **/rewind (vagy dupla `Esc`):** A leghasznosabb parancs. Visszatekeri a beszélgetést egy korábbi pontra. Választhatod, hogy csak a chat előzményeket törölje, vagy a fájlokat is állítsa vissza. Ezzel "elfelejteti" vele a hibás/ismétlődő köröket.
*   **/compress:** Ha a beszélgetés túl hosszú, az ágens összezavarodhat a sok régi információtól. Ez a parancs egy tömör összefoglalóvá alakítja az előzményeket, így tisztább lesz a fókusza.
*   **Ctrl + C:** Azonnal megszakítja az aktuális folyamatot, ha látod, hogy rossz irányba indulna.

## 2. Hogyan jelezd, hogy egy feladattal már végeztél?

Mivel az ágens a teljes chat-előzményt látja, néha a korábbi utasítások (Instruction Context) miatt hiheti azt, hogy még dolga van.

**Így "tájékoztasd" az ágenst:**
1.  **Konkrét tiltás:** *"Ezt a részt (pl. a vektorok static-ra írását) már megcsináltam, ne nyúlj hozzá többet!"*
2.  **Szkóp szűkítése:** *"A kutatási fázisnak vége, most csak a getTranslation függvény implementálására koncentrálj."*
3.  **Állapot frissítése:** *"A translations.cpp már static const-okat használ, ezt tekintsd véglegesnek."*
4.  **Rewind használata:** Ha látod, hogy egy régi tervet akar újra végrehajtani, használd a `/rewind` parancsot a terv kiadása előtti pontig, és adj új, frissített utasítást.

## 3. Tippek nagy fájlokhoz (pl. translations.cpp)

A nagy fájlok (200KB+) indexelése lassíthatja a rendszert, és az ágens néha "elveszik" bennük.

*   **Részletekben dolgozz:** Ne kérd meg egyszerre 1000 sor módosítására. Mondd azt: *"Most csak a MenuStrings részt add hozzá a getTranslation-höz."*
*   **Plain Text trükk:** Ha a CLion indexelése lassít, állítsd a fájl típusát átmenetileg **Plain Text**-re (jobb klikk a fájlon -> Override File Type -> Plain Text).
*   **Highlighting Level:** A CLion jobb alsó sarkában az "emberke" ikonra kattintva vedd le az elemzési szintet "Syntax"-ra vagy "None"-ra a nagy fájloknál.

## 4. Ha az "Instruction Context" ellentmondásos

Ha több fájlt is megnyitottál (@ fájlnév), az ágens az összes tartalmát próbálja figyelembe venni. Ha ezekben régi tervek vannak, megzavarodhat. 
**Megoldás:** Csak azokat a fájlokat csatold a kérésedhez, amikre tényleg szükség van az aktuális lépéshez.
