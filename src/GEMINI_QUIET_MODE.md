# Gemini CLI Tisztább Felület & "Csendes" Mód

Ha a Gemini CLI túl sokat beszél, ismétli magát, vagy a CLion termináljában szétcsúszik a szöveg, az alábbi beállításokkal teheted professzionálisabbá és tisztábbá a felületet.

## 1. Beállítások módosítása (/settings)

Írd be a Gemini CLI-be a `/settings` parancsot, majd keresd meg az alábbi opciókat:

*   **`ui.hideContextSummary` -> `true`**: 
    Eltünteti a beszélgetés elején megjelenő hosszú fájllistát és környezeti összefoglalót. Csak a lényeg marad.
*   **`ui.loadingPhrases` -> `off`**: 
    Kikapcsolja a "vicces" vagy tájékoztató jellegű mondatokat, amiket az ágens ír ki, amíg a választ generálja.
*   **`ui.hideTips` -> `true`**: 
    Eltünteti a felület alján megjelenő véletlenszerű tippeket.
*   **`ui.inlineThinkingMode` -> `off`**: 
    Ha nem akarod látni, ahogy az ágens "gondolkodik" (a belső folyamatait listázza), itt kapcsolhatod ki.

## 2. A legtisztább mód: Screen Reader Mode

Ha a CLion terminálja nem kezeli jól a színeket vagy az animációkat, és emiatt duplázódik a szöveg:

*   **`ui.accessibility.screenReader` -> `true`**: 
    Ez a beállítás **Plain Text (egyszerű szöveges)** módba kényszeríti a CLI-t. 
    - Nincsenek animációk.
    - Nincsenek szétcsúszó keretek.
    - Csak a tiszta szöveges kérdés és válasz látszik.
    - **Ez a legjobb megoldás, ha a terminálod "szemetel".**

## 3. Hasznos parancsok a rendrakáshoz

*   **/compress**: Ha a beszélgetés már nagyon hosszú (több tucat kör), az ágens összezavarodhat. Ez a parancs tömöríti az előzményeket, így az ágens nem fog régi, már nem releváns dolgokat ismételgetni.
*   **Ctrl + L (vagy `/clear`)**: Letakarítja a terminál képernyőjét, de a beszélgetés emlékezete megmarad. Segít a fókuszálásban.

## 4. Headless mód (ha csak a választ akarod)

Ha egyáltalán nem akarsz interaktív felületet, csak egy kérdést akarsz feltenni a terminálból:
`gemini -p "Mit csinál ez a függvény? @main.cpp"`

Ez a mód nem nyit chat ablakot, csak kiírja a választ és kilép.
