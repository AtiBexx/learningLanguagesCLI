//
// Created by AtiBexx2 on 2026. 05. 08.
//

#include <iostream>

#include "translations.h"
#include <map>
#include <string>
#include "../Common/generalFunctions.h"
#include <fstream>


#include "settings.h"

std::map<std::string, std::string> loadedTranslations;
bool useLangIni = false;

// --- SEGÉDFÜGGVÉNY A STRING TRIMMELÉSÉHEZ ---
// --- HELPER FUNCTION FOR TRIMMING STRING ---
std::string trim_local(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
    {
        return str;
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

// --- ALAPÉRTELMEZETT (HARD-CODED) FORDÍTÁSOK (EZEK MARADNAK, MINT FALLBACK) ---
// Ezeket static const-ként definiáljuk, hogy csak ebben a fájlban legyenek láthatók
// és onnan töltsük fel a lang.ini-t, vagy használjuk fallback-ként.



//======Vectors===========

// Menu'sVector
static const std::vector<MenuStrings> mainMenuTranslations_hardcoded = {


    // HUNGARIAN (Index 0)
    {
        "============NYELVTANULÓ-APP============",
        "1. - A program magyarázata",
        "2. - A program indítása",
        "3. - A hibák gyakorlása",
        "4. - Új szókincs fájl létrehozása",
        "5. - Beállítások",
        "6. - A szerkesztő (EDITOR) megnyitása",
        "0. - Kilépés",
        "======================================="
    },

    // ENGLISH (Index 1)
    {
        "============LANGUAGE LEARNING APP============",
        "1. - Program explanation",
        "2. - Start program",
        "3. - Practice mistakes",
        "4. - Create new vocabulary file",
        "5. - Settings",
        "6. - Open editor",
        "0. - Exit",
        "============================================="
    },

    // CHINESE (Index 2)
    {
        "============语言学习应用============",
        "1. - 程序说明",
        "2. - 启动程序",
        "3. - 练习错误",
        "4. - 创建新词汇文件",
        "5. - 设置",
        "6. - 打开编辑器",
        "0. - 退出",
        "=================================="
    },

    // JAPANESE (Index 3)
    {
        "============言語学習アプリ============",
        "1. - プログラムの説明",
        "2. - プログラム開始",
        "3. - 間違いの練習",
        "4. - 新しい単語ファイル作成",
        "5. - 設定",
        "6. - エディターを開く",
        "0. - 終了",
        "=================================="
    },

    // SPANISH (Index 4)
    {
        "============APLICACIÓN DE IDIOMAS============",
        "1. - Explicación del programa",
        "2. - Iniciar programa",
        "3. - Practicar errores",
        "4. - Crear archivo de vocabulario",
        "5. - Configuración",
        "6. - Abrir editor",
        "0. - Salir",
        "============================================="
    },

    // GERMAN (Index 5)
    {
        "============SPRACHLERN-APP============",
        "1. - Programmerklärung",
        "2. - Programm starten",
        "3. - Fehler üben",
        "4. - Neue Vokabeldatei erstellen",
        "5. - Einstellungen",
        "6. - Editor öffnen",
        "0. - Beenden",
        "====================================="
    },

    // FRENCH (Index 6)
    {
        "============APPLICATION DE LANGUE============",
        "1. - Explication du programme",
        "2. - Démarrer le programme",
        "3. - Pratiquer les erreurs",
        "4. - Créer un fichier de vocabulaire",
        "5. - Paramètres",
        "6. - Ouvrir l'éditeur",
        "0. - Quitter",
        "============================================"
    },

    // RUSSIAN (Index 7)
    {
        "============ПРИЛОЖЕНИЕ ДЛЯ ЯЗЫКОВ============",
        "1. - Объяснение программы",
        "2. - Запустить программу",
        "3. - Практика ошибок",
        "4. - Создать файл словаря",
        "5. - Настройки",
        "6. - Открыть редактор",
        "0. - Выход",
        "============================================"
    },

    // UKRAINIAN (Index 8)
    {
        "============ДОДАТОК ДЛЯ МОВ============",
        "1. - Пояснення програми",
        "2. - Запустити програму",
        "3. - Практика помилок",
        "4. - Створити файл словника",
        "5. - Налаштування",
        "6. - Відкрити редактор",
        "0. - Вихід",
        "========================================"
    },

    // KOREAN (Index 9)
    {
        "============언어 학습 앱============",
        "1. - 프로그램 설명",
        "2. - 프로그램 시작",
        "3. - 오류 연습",
        "4. - 새 단어 파일 생성",
        "5. - 설정",
        "6. - 편집기 열기",
        "0. - 종료",
        "=================================="
    },

    // ITALIAN (Index 10)
    {
        "============APP DI LINGUE============",
        "1. - Spiegazione del programma",
        "2. - Avvia programma",
        "3. - Pratica errori",
        "4. - Crea file vocabolario",
        "5. - Impostazioni",
        "6. - Apri editor",
        "0. - Esci",
        "===================================="
    },

    // POLISH (Index 11)
    {
        "============APLIKACJA JĘZYKOWA============",
        "1. - Wyjaśnienie programu",
        "2. - Uruchom program",
        "3. - Ćwiczenie błędów",
        "4. - Utwórz plik słownictwa",
        "5. - Ustawienia",
        "6. - Otwórz edytor",
        "0. - Wyjście",
        "=========================================="
    },

    // ARABIC (Index 12)
    {
        "============تطبيق تعلم اللغات============",
        "1. - شرح البرنامج",
        "2. - بدء البرنامج",
        "3. - ممارسة الأخطاء",
        "4. - إنشاء ملف مفردات",
        "5. - الإعدادات",
        "6. - فتح المحرر",
        "0. - خروج",
        "========================================"
    },

    // VIETNAMESE (Index 13)
    {
        "============ỨNG DỤNG HỌC NGÔN NGỮ============",
        "1. - Giải thích chương trình",
        "2. - Bắt đầu chương trình",
        "3. - Luyện lỗi",
        "4. - Tạo file từ vựng",
        "5. - Cài đặt",
        "6. - Mở trình soạn thảo",
        "0. - Thoát",
        "============================================"
    },

    // TAGALOG (Index 14)
    {
        "============APP SA WIKA============",
        "1. - Paliwanag ng programa",
        "2. - Simulan ang programa",
        "3. - Pagsasanay sa mali",
        "4. - Gumawa ng vocabulary file",
        "5. - Settings",
        "6. - Buksan ang editor",
        "0. - Exit",
        "=================================="
    },

    // GREEK (Index 15)
    {
        "============ΕΦΑΡΜΟΓΗ ΓΛΩΣΣΑΣ============",
        "1. - Επεξήγηση προγράμματος",
        "2. - Εκκίνηση προγράμματος",
        "3. - Εξάσκηση λαθών",
        "4. - Δημιουργία αρχείου λεξιλογίου",
        "5. - Ρυθμίσεις",
        "6. - Άνοιγμα editor",
        "0. - Έξοδος",
        "========================================"
    },

    // HEBREW (Index 16)
    {
        "============אפליקציית שפות============",
        "1. - הסבר התוכנית",
        "2. - הפעלת התוכנית",
        "3. - תרגול טעויות",
        "4. - יצירת קובץ מילים",
        "5. - הגדרות",
        "6. - פתיחת עורך",
        "0. - יציאה",
        "======================================"
    },

    // PORTUGUESE (Index 17)
    {
        "============APP DE IDIOMAS============",
        "1. - Explicação do programa",
        "2. - Iniciar programa",
        "3. - Praticar erros",
        "4. - Criar arquivo de vocabulário",
        "5. - Configurações",
        "6. - Abrir editor",
        "0. - Sair",
        "======================================"
    },

    // FARSI (Index 18)
    {
        "============برنامه یادگیری زبان============",
        "1. - توضیح برنامه",
        "2. - شروع برنامه",
        "3. - تمرین خطاها",
        "4. - ایجاد فایل واژگان",
        "5. - تنظیمات",
        "6. - باز کردن ویرایشگر",
        "0. - خروج",
        "========================================="
    },

    // SWEDISH (Index 19)
    {
        "============SPRÅKINLÄRNINGSAPP============",
        "1. - Programförklaring",
        "2. - Starta program",
        "3. - Öva fel",
        "4. - Skapa vokabulärfil",
        "5. - Inställningar",
        "6. - Öppna editor",
        "0. - Avsluta",
        "=========================================="
    },

    // DUTCH (Index 20)
    {
        "============TAALAPP============",
        "1. - Program uitleg",
        "2. - Start programma",
        "3. - Fouten oefenen",
        "4. - Woordenbestand maken",
        "5. - Instellingen",
        "6. - Editor openen",
        "0. - Afsluiten",
        "================================"
    },

    // TURKISH (Index 21)
    {
        "============DİL ÖĞRENME UYGULAMASI============",
        "1. - Program açıklaması",
        "2. - Programı başlat",
        "3. - Hataları çalış",
        "4. - Kelime dosyası oluştur",
        "5. - Ayarlar",
        "6. - Editörü aç",
        "0. - Çıkış",
        "=============================================="
    },

    // HINDI (Index 22)
    {
        "============भाषा सीखने का ऐप============",
        "1. - प्रोग्राम विवरण",
        "2. - प्रोग्राम शुरू करें",
        "3. - गलतियों का अभ्यास",
        "4. - शब्दावली फ़ाइल बनाएं",
        "5. - सेटिंग्स",
        "6. - एडिटर खोलें",
        "0. - बाहर निकलें",
        "========================================"
    },

    // LATIN (Index 23)
    {
        "============APP LINGUAE============",
        "1. - Explicatio programmatis",
        "2. - Incipere programmam",
        "3. - Exercere errores",
        "4. - Creare fasciculum verborum",
        "5. - Optiones",
        "6. - Aperire editorem",
        "0. - Exire",
        "==================================="
    }
};
//const std::vector<MenuStrings> mainMenuTranslations = mainMenuTranslations_hardcoded;

//==========================================================================
// number output
static const std::vector<NumberOutput> chooseNumberMenuTranslations_hardcoded = {
//const std::vector<NumberOutput> chooseNumberMenuTranslations = {
    // HUNGARIAN (Index 0)
    {"Kérlek válassz egy menüpontot: "},

    // ENGLISH (Index 1)
    {"Please choose a menu option: "},

    // CHINESE (Index 2)
    {"请选择一个菜单选项: "},

    // JAPANESE (Index 3)
    {"メニュー項目を選択してください: "},

    // SPANISH (Index 4)
    {"Por favor, elige una opción del menú: "},

    // GERMAN (Index 5)
    {"Bitte wähle eine Menüoption: "},

    // FRENCH (Index 6)
    {"Veuillez choisir une option du menu: "},

    // RUSSIAN (Index 7)
    {"Пожалуйста, выберите пункт меню: "},

    // UKRAINIAN (Index 8)
    {"Будь ласка, оберіть пункт меню: "},

    // KOREAN (Index 9)
    {"메뉴 항목을 선택하세요: "},

    // ITALIAN (Index 10)
    {"Seleziona un'opzione del menu: "},

    // POLISH (Index 11)
    {"Wybierz opcję z menu: "},

    // ARABIC (Index 12)
    {"يرجى اختيار عنصر من القائمة: "},

    // VIETNAMESE (Index 13)
    {"Vui lòng chọn một mục menu: "},

    // TAGALOG (Index 14)
    {"Mangyaring pumili ng opsyon sa menu: "},

    // GREEK (Index 15)
    {"Παρακαλώ επιλέξτε μια επιλογή από το μενού: "},

    // HEBREW (Index 16)
    {"אנא בחר אפשרות מהתפריט: "},

    // PORTUGUESE (Index 17)
    {"Por favor, escolha uma opção do menu: "},

    // FARSI (Index 18)
    {"لطفاً یک گزینه از منو انتخاب کنید: "},

    // SWEDISH (Index 19)
    {"Välj ett menyalternativ: "},

    // DUTCH (Index 20)
    {"Kies een menu-optie: "},

    // TURKISH (Index 21)
    {"Lütfen bir menü seçeneği seçin: "},

    // HINDI (Index 22)
    {"कृपया एक मेनू विकल्प चुनें: "},

    // LATIN (Index 23)
    {"Quaeso elige optionem e menu: "}
};


//==========================================================================
//Explanations || magyarázat
static const std::vector<ExplanationStrings> explanationTranslations_hardcoded = {


    // Hungarian (0)
    {
        "Ez a program a nyelvi tudást fejleszti.",
        "A program szavakat és kifejezéseket kérdez.",
        "A fájlok .data kiterjesztéssel nyithatók és szerkeszthetők.",
        "A képernyő törléshez használd a 'cls' parancsot ha szükséges!",
        "A kilépéshez használd az 'exit' vagy 'e' parancsot vagy Ctrl + C-t.",
        "A segítséghez a 'help' vagy 'h' parancsot vagy Ctrl + Y-t.",
        "A segítség kikapcsolásához a 'help off' vagy 'h off' parancsot vagy Ctrl + N-t.",
        "A gyakorlás két körből áll: először anyanyelvről a tanult nyelvre,",
        "majd a tanult nyelvről az anyanyelvre kérdez.",
        "Beállítható az egy körös mód a BEÁLLÍTÁSOK menüben.",
        "Jó tanulást kívánok :)"
    },

    // English (1)
    {
        "This program improves language skills.",
        "The program asks words and expressions.",
        "Files can be opened and edited with .data extension.",
        "To clear the screen use the 'cls' command if needed.",
        "To quit use the 'exit' or 'e' command or Ctrl + C.",
        "For help use the 'help' or 'h' command or Ctrl + Y.",
        "To disable help use the 'help off' or 'h off' command or Ctrl + N.",
        "Practice has two rounds: first native to learning language,",
        "then learning language back to native.",
        "Single-round mode can be enabled in SETTINGS.",
        "Happy learning :)"
    },

    // Chinese (2)
    {
        "该程序用于提高语言能力。",
        "程序会提问单词和短语。",
        ".data 文件可以打开和编辑。",
        "需要时使用 'cls' 命令清屏。",
        "退出程序使用 'exit' 或 'e' 命令或 Ctrl + C。",
        "帮助使用 'help' 或 'h' 命令或 Ctrl + Y。",
        "关闭帮助使用 'help off' 或 'h off' 命令或 Ctrl + N。",
        "练习分两轮：母语 → 学习语言，",
        "然后学习语言 → 母语。",
        "可在设置中启用单轮模式。",
        "祝学习愉快 :)"
    },

    // Japanese (3)
    {
        "このプログラムは言語能力を向上させます。",
        "単語やフレーズを出題します。",
        ".dataファイルは開いて編集できます。",
        "必要なら 'cls' コマンドで画面をクリア。",
        "終了は 'exit' または 'e' コマンドまたは Ctrl + C。",
        "ヘルプは 'help' または 'h' コマンドまたは Ctrl + Y。",
        "ヘルプ無効は 'help off' または 'h off' コマンドまたは Ctrl + N。",
        "練習は2回：母語→学習言語、",
        "その後学習言語→母語。",
        "設定で1ラウンドモード可能。",
        "楽しく学びましょう :)"
    },

    // Spanish (4)
    {
        "Este programa mejora habilidades lingüísticas.",
        "El programa pregunta palabras y expresiones.",
        "Los archivos .data pueden abrirse y editarse.",
        "Para limpiar pantalla usa el comando 'cls' si es necesario.",
        "Para salir usa el 'exit' o 'e' comando o Ctrl + C.",
        "Para ayuda usa el 'help' o 'h' comando o Ctrl + Y.",
        "Para desactivar ayuda usa el 'help off' o 'h off' comando o Ctrl + N.",
        "La práctica tiene dos rondas: idioma nativo → aprendido,",
        "luego aprendido → nativo.",
        "Modo de una ronda en configuración.",
        "Feliz aprendizaje :)"
    },

    // German (5)
    {
        "Dieses Programm verbessert Sprachkenntnisse.",
        "Das Programm fragt Wörter und Ausdrücke ab.",
        ".data Dateien können geöffnet und bearbeitet werden.",
        "Zum Bildschirm löschen nutze den 'cls' Befehl falls nötig.",
        "Zum Beenden nutze den 'exit' oder 'e' Befehl oder Ctrl + C.",
        "Für Hilfe nutze den 'help' oder 'h' Befehl oder Ctrl + Y.",
        "Hilfe deaktivieren: 'help off' oder 'h off' Befehl oder Ctrl + N.",
        "Übung: Muttersprache → Lernsprache,",
        "dann zurück.",
        "Einrundenmodus in Einstellungen möglich.",
        "Viel Erfolg :)"
    },

    // French (6)
    {
        "Ce programme améliore les compétences linguistiques.",
        "Le programme pose des mots et expressions.",
        "Les fichiers .data peuvent être ouverts et modifiés.",
        "Pour nettoyer l'écran utilise la commande 'cls' si nécessaire.",
        "Quitter: 'exit' ou 'e' commande ou Ctrl + C.",
        "Aide: 'help' ou 'h' commande ou Ctrl + Y.",
        "Désactiver aide: 'help off' ou 'h off' commande ou Ctrl + N.",
        "Deux tours: langue maternelle → langue cible,",
        "puis inverse.",
        "Mode un tour dans paramètres.",
        "Bon apprentissage :)"
    },

    // Russian (7)
    {
        "Эта программа улучшает языковые навыки.",
        "Программа задаёт слова и выражения.",
        ".data файлы можно открывать и редактировать.",
        "Для очистки экрана используйте команду 'cls'.",
        "Выход: 'exit' или 'e' команда или Ctrl + C.",
        "Помощь: 'help' или 'h' команда или Ctrl + Y.",
        "Отключить помощь: 'help off' или 'h off' команда или Ctrl + N.",
        "Два раунда: родной язык → изучаемый,",
        "затем обратно.",
        "Один раунд в настройках.",
        "Удачи :)"
    },

    // Ukrainian (8)
    {
        "Ця програма покращує мовні навички.",
        "Програма задає слова і фрази.",
        ".data файли можна відкривати і редагувати.",
        "Для очищення екрана використовуйте команду 'cls'.",
        "Вихід: 'exit' або 'e' команда або Ctrl + C.",
        "Допомога: 'help' або 'h' команда або Ctrl + Y.",
        "Вимкнути допомогу: 'help off' або 'h off' команда або Ctrl + N.",
        "Два раунди: рідна → вивчена мова,",
        "потім назад.",
        "Один раунд у налаштуваннях.",
        "Успіхів :)"
    },

    // Korean (9)
    {
        "이 프로그램은 언어 능력을 향상시킵니다.",
        "단어와 표현을 질문합니다.",
        ".data 파일을 열고 수정할 수 있습니다.",
        "화면 지우기: 'cls' 명령어 사용.",
        "종료: 'exit' 또는 'e' 명령어 또는 Ctrl + C.",
        "도움말: 'help' 또는 'h' 명령어 또는 Ctrl + Y.",
        "도움말 끄기: 'help off' 또는 'h off' 명령어 또는 Ctrl + N.",
        "두 단계: 모국어 → 학습 언어,",
        "그 다음 반대로.",
        "설정에서 1라운드 가능.",
        "즐거운 학습 :)"
    },

    // Italian (10)
    {
        "Questo programma migliora le competenze linguistiche.",
        "Il programma chiede parole ed espressioni.",
        "I file .data possono essere modificati.",
        "Per pulire lo schermo usa il comando 'cls'.",
        "Esci: 'exit' o 'e' comando o Ctrl + C.",
        "Aiuto: 'help' o 'h' comando o Ctrl + Y.",
        "Disattiva aiuto: 'help off' o 'h off' comando o Ctrl + N.",
        "Due round: lingua madre → lingua studio,",
        "poi inverso.",
        "Modalità singola in impostazioni.",
        "Buono studio :)"
    },

    // Polish (11)
    {
        "Program rozwija umiejętności językowe.",
        "Zadaje słowa i wyrażenia.",
        "Pliki .data można edytować.",
        "Do czyszczenia ekranu użyj komendy 'cls'.",
        "Wyjście: 'exit' lub 'e' komenda lub Ctrl + C.",
        "Pomoc: 'help' lub 'h' komenda lub Ctrl + Y.",
        "Wyłącz pomoc: 'help off' lub 'h off' komenda lub Ctrl + N.",
        "Dwie rundy: ojczysty → nauka,",
        "potem odwrotnie.",
        "Tryb jednej rundy w ustawieniach.",
        "Miłej nauki :)"
    },

    // Arabic (12)
    {
        "هذا البرنامج يحسن مهارات اللغة.",
        "يسأل كلمات وعبارات.",
        "يمكن تعديل ملفات .data.",
        "استخدم أمر 'cls' لمسح الشاشة.",
        "الخروج: 'exit' أو 'e' أو Ctrl + C.",
        "المساعدة: 'help' أو 'h' أو Ctrl + Y.",
        "إيقاف المساعدة: 'help off' أو 'h off' أو Ctrl + N.",
        "جولتان: اللغة الأم → التعلم،",
        "ثم العكس.",
        "وضع جولة واحدة في الإعدادات.",
        "تعلم سعيد :)"
    },

    // Vietnamese (13)
    {
        "Chương trình giúp cải thiện ngôn ngữ.",
        "Hỏi từ và cụm từ.",
        "File .data có thể chỉnh sửa.",
        "Dùng lệnh 'cls' để xóa màn hình.",
        "Thoát: 'exit' hoặc 'e' hoặc Ctrl + C.",
        "Trợ giúp: 'help' hoặc 'h' hoặc Ctrl + Y.",
        "Tắt trợ giúp: 'help off' hoặc 'h off' hoặc Ctrl + N.",
        "2 vòng: mẹ đẻ → học,",
        "rồi ngược lại.",
        "Chế độ 1 vòng trong cài đặt.",
        "Chúc học tốt :)"
    },

    // Tagalog (14)
    {
        "Pinapabuti ng programang ito ang wika.",
        "Nagtatanong ng salita at parirala.",
        ".data file ay maaaring baguhin.",
        "Gamitin ang 'cls' command kung kailangan.",
        "Lumabas: 'exit' o 'e' o Ctrl + C.",
        "Tulong: 'help' o 'h' o Ctrl + Y.",
        "I-off ang tulong: 'help off' o 'h off' o Ctrl + N.",
        "2 round: native → learning,",
        "baliktad pagkatapos.",
        "1 round sa settings.",
        "Magandang pag-aaral :)"
    },

    // Greek (15)
    {
        "Το πρόγραμμα βελτιώνει γλωσσικές δεξιότητες.",
        "Ρωτά λέξεις και φράσεις.",
        ".data αρχεία επεξεργάζονται.",
        "Χρησιμοποίησε την εντολή 'cls' αν χρειάζεται.",
        "Έξοδος: 'exit' ή 'e' ή Ctrl + C.",
        "Βοήθεια: 'help' ή 'h' ή Ctrl + Y.",
        "Απενεργοποίηση: 'help off' ή 'h off' ή Ctrl + N.",
        "2 γύροι: μητρική → μάθηση,",
        "μετά αντίστροφα.",
        "1 γύρος στις ρυθμίσεις.",
        "Καλή μάθηση :)"
    },

    // Hebrew (16)
    {
        "התוכנית משפרת מיומנויות שפה.",
        "שואלת מילים וביטויים.",
        "קבצי .data ניתנים לעריכה.",
        "השתמש בפקודה 'cls' אם צריך.",
        "יציאה: 'exit' או 'e' או Ctrl + C.",
        "עזרה: 'help' או 'h' או Ctrl + Y.",
        "כיבוי עזרה: 'help off' או 'h off' או Ctrl + N.",
        "2 סבבים: שפת אם → לימוד,",
        "ואז הפוך.",
        "מצב סבב אחד בהגדרות.",
        "למידה נעימה :)"
    },

    // Portuguese (17)
    {
        "Este programa melhora habilidades linguísticas.",
        "Pergunta palavras e expressões.",
        "Arquivos .data podem ser editados.",
        "Use comando 'cls' se necessário.",
        "Sair: 'exit' ou 'e' ou Ctrl + C.",
        "Ajuda: 'help' ou 'h' ou Ctrl + Y.",
        "Desativar ajuda: 'help off' ou 'h off' ou Ctrl + N.",
        "2 rodadas: nativo → aprendizado,",
        "depois inverso.",
        "Modo 1 rodada nas configurações.",
        "Bom aprendizado :)"
    },

    // Farsi (18)
    {
        "این برنامه مهارت زبان را بهبود می‌دهد.",
        "کلمات و عبارات را می‌پرسد.",
        "فایل‌های .data قابل ویرایش هستند.",
        "از دستور 'cls' در صورت نیاز استفاده کنید.",
        "خروج: 'exit' یا 'e' یا Ctrl + C.",
        "راهنما: 'help' یا 'h' یا Ctrl + Y.",
        "خاموش کردن راهنما: 'help off' یا 'h off' یا Ctrl + N.",
        "۲ دور: زبان مادری → یادگیری،",
        "سپس برعکس.",
        "حالت یک دور در تنظیمات.",
        "یادگیری موفق :)"
    },

    // Swedish (19)
    {
        "Programmet förbättrar språkkunskaper.",
        "Frågar ord och uttryck.",
        ".data filer kan redigeras.",
        "Använd kommandot 'cls' vid behov.",
        "Avsluta: 'exit' eller 'e' eller Ctrl + C.",
        "Hjälp: 'help' eller 'h' eller Ctrl + Y.",
        "Stäng hjälp: 'help off' eller 'h off' eller Ctrl + N.",
        "2 rundor: modersmål → lärande,",
        "sedan tillbaka.",
        "1 runda i inställningar.",
        "Lycka till :)"
    },

    // Dutch (20)
    {
        "Dit programma verbetert taalvaardigheid.",
        "Stelt woorden en zinnen.",
        ".data bestanden bewerkbaar.",
        "Gebruik het 'cls' commando indien nodig.",
        "Afsluiten: 'exit' of 'e' of Ctrl + C.",
        "Help: 'help' of 'h' of Ctrl + Y.",
        "Help uit: 'help off' of 'h off' of Ctrl + N.",
        "2 rondes: moedertaal → leren,",
        "dan terug.",
        "1 ronde in instellingen.",
        "Succes :)"
    },

    // Turkish (21)
    {
        "Bu program dil becerilerini geliştirir.",
        "Kelimeler ve ifadeler sorar.",
        ".data dosyaları düzenlenebilir.",
        "Gerekirse 'cls' komutunu kullan.",
        "Çıkış: 'exit' veya 'e' veya Ctrl + C.",
        "Yardım: 'help' veya 'h' veya Ctrl + Y.",
        "Yardımı kapat: 'help off' veya 'h off' veya Ctrl + N.",
        "2 tur: ana dil → öğrenme,",
        "sonra geri.",
        "1 tur ayarlarda.",
        "İyi çalışmalar :)"
    },

    // Hindi (22)
    {
        "यह प्रोग्राम भाषा कौशल सुधारता है।",
        "शब्द और वाक्य पूछता है।",
        ".data फ़ाइल संपादन योग्य है।",
        "आवश्यक हो तो 'cls' कमांड का उपयोग करें।",
        "बाहर निकलें: 'exit' या 'e' या Ctrl + C।",
        "मदद: 'help' या 'h' या Ctrl + Y।",
        "मदद बंद: 'help off' या 'h off' या Ctrl + N।",
        "2 राउंड: मातृभाषा → सीखना,",
        "फिर उल्टा।",
        "1 राउंड सेटिंग्स में।",
        "शुभकामनाएं :)"
    },

    // Latin (23)
    {
        "Hoc programma linguam meliorat.",
        "Verba et locutiones rogat.",
        "Fasciculi .data mutari possunt.",
        "Utere 'cls' mandato si opus est.",
        "Exitus: 'exit' vel 'e' vel Ctrl + C.",
        "Auxilium: 'help' vel 'h' vel Ctrl + Y.",
        "Auxilium off: 'help off' vel 'h off' vel Ctrl + N.",
        "2 circuitus: lingua materna → discere,",
        "deinde retro.",
        "1 circuitus in optionibus.",
        "Bona fortuna :)"
    }
};


//==========================================================================
static const std::vector<ExitingStrings> exitingTranslations_hardcoded = {
//const std::vector<ExitingStrings> exitingTranslations = {
    //Hungarian (index 0)
    {"A kilépéshez kérlek nyomd meg az ENTER-T......"},

    //English (index 1)
    {"Please to exit press ENTER......"},

    // CHINESE ( INDEX 2)
    {"请按 ENTER 键退出......"},

    // JAPANESE ( INDEX 3)
    {"終了するには ENTER キーを押してください......"},

    // SPANISH ( INDEX 4)
    {"Para salir, presiona ENTER......"},

    // GERMAN ( INDEX 5)
    {"Drücke ENTER, um zu beenden......"},

    // FRENCH ( INDEX 6)
    {"Appuyez sur ENTER pour quitter......"},

    // RUSSIAN ( INDEX 7)
    {"Нажмите ENTER, чтобы выйти......"},

    // UKRAINIAN ( INDEX 8)
    {"Натисніть ENTER, щоб вийти......"},

    // KOREAN ( INDEX 9)
    {"종료하려면 ENTER 키를 누르세요......"},

    // ITALIAN ( INDEX 10)
    {"Premi ENTER per uscire......"},

    // POLISH ( INDEX 11)
    {"Naciśnij ENTER, aby wyjść......"},

    // ARABIC ( INDEX 12)
    {"اضغط ENTER للخروج......"},

    // VIETNAMESE ( INDEX 13)
    {"Nhấn ENTER để thoát......"},

    // TAGALOG ( INDEX 14)
    {"Pindutin ang ENTER upang lumabas......"},

    // GREEK ( INDEX 15)
    {"Πατήστε ENTER για έξοδο......"},

    // HEBREW ( INDEX 16)
    {"לחץ על ENTER כדי לצאת......"},

    // PORTUGUESE ( INDEX 17)
    {"Pressione ENTER para sair......"},

    // FARSI ( INDEX 18)
    {"برای خروج ENTER را فشار دهید......"},

    // SWEDISH ( INDEX 19)
    {"Tryck på ENTER för att avsluta......"},

    // DUTCH ( INDEX 20)
    {"Druk op ENTER om af te sluiten......"},

    // TURKISH ( INDEX 21)
    {"Çıkmak için ENTER tuşuna basın......"},

    // HINDI ( INDEX 22)
    {"बाहर निकलने के लिए ENTER दबाएँ......"},

    // LATIN ( INDEX 23)
    {"Preme ENTER ut exire......"}
};


//==========================================================================
static const std::vector<InvalidInput> invalidInputTranslations_hardcoded = {

    //hungarian (Index 0)
    {"Hibás bemenet, kérlek csak számot adj meg!" },

    //English (Index 1)
        {"Invalid input. Please only enter a number!"},
    // CHINESE (Index 2)
    {"输入无效，请只输入数字！"},

    // JAPANESE (Index 3)
    {"無効な入力です。数字のみ入力してください！"},

    // SPANISH (Index 4)
    {"Entrada inválida. ¡Por favor, introduce solo números!"},

    // GERMAN (Index 5)
    {"Ungültige Eingabe. Bitte nur Zahlen eingeben!"},

    // FRENCH (Index 6)
    {"Entrée invalide. Veuillez entrer uniquement des nombres !"},

    // RUSSIAN (Index 7)
    {"Неверный ввод. Пожалуйста, вводите только числа!"},

    // UKRAINIAN (Index 8)
    {"Неправильне введення. Будь ласка, вводьте лише числа!"},

    // KOREAN (Index 9)
    {"잘못된 입력입니다. 숫자만 입력하세요!"},

    // ITALIAN (Index 10)
    {"Input non valido. Inserisci solo numeri!"},

    // POLISH (Index 11)
    {"Nieprawidłowe dane. Wpisz tylko liczby!"},

    // ARABIC (Index 12)
    {"إدخال غير صالح. يرجى إدخال أرقام فقط!"},

    // VIETNAMESE (Index 13)
    {"Dữ liệu không hợp lệ. Vui lòng chỉ nhập số!"},

    // TAGALOG (Index 14)
    {"Di-wastong input. Mangyaring numero lamang ang ilagay!"},

    // GREEK (Index 15)
    {"Μη έγκυρη είσοδος. Παρακαλώ εισάγετε μόνο αριθμούς!"},

    // HEBREW (Index 16)
    {"קלט לא חוקי. אנא הזן מספרים בלבד!"},

    // PORTUGUESE (Index 17)
    {"Entrada inválida. Por favor, insira apenas números!"},

    // FARSI (Index 18)
    {"ورودی نامعتبر است. لطفاً فقط عدد وارد کنید!"},

    // SWEDISH (Index 19)
    {"Ogiltig inmatning. Ange endast siffror!"},

    // DUTCH (Index 20)
    {"Ongeldige invoer. Voer alleen cijfers in!"},

    // TURKISH (Index 21)
    {"Geçersiz giriş. Lütfen sadece sayı girin!"},

    // HINDI (Index 22)
    {"अमान्य इनपुट। कृपया केवल संख्या दर्ज करें!"},

    // LATIN (Index 23)
    {"Input non validus. Quaeso numeros tantum inserere!"}
};


//==========================================================================
static const std::vector<EnteringBack> continuationToEnterTranslations_hardcoded = {

    //hungarian (Index 0)
    {"A folytatáshoz kérlek nyomd meg az ENTER-T......"},

    //English (Index 1)
    {"Please to continue press ENTER......"},

    // CHINESE (Index 2)
    {"请按 ENTER 键继续......"},

    // JAPANESE (Index 3)
    {"続行するには ENTER キーを押してください......"},

    // SPANISH (Index 4)
    {"Para continuar, presiona ENTER......"},

    // GERMAN (Index 5)
    {"Drücke ENTER, um fortzufahren......"},

    // FRENCH (Index 6)
    {"Appuyez sur ENTER pour continuer......"},

    // RUSSIAN (Index 7)
    {"Нажмите ENTER, чтобы продолжить......"},

    // UKRAINIAN (Index 8)
    {"Натисніть ENTER, щоб продовжити......"},

    // KOREAN (Index 9)
    {"계속하려면 ENTER 키를 누르세요......"},

    // ITALIAN (Index 10)
    {"Premi ENTER per continuare......"},

    // POLISH (Index 11)
    {"Naciśnij ENTER, aby kontynuować......"},

    // ARABIC (Index 12)
    {"اضغط ENTER للمتابعة......"},

    // VIETNAMESE (Index 13)
    {"Nhấn ENTER để tiếp tục......"},

    // TAGALOG (Index 14)
    {"Pindutin ang ENTER upang magpatuloy......"},

    // GREEK (Index 15)
    {"Πατήστε ENTER για συνέχεια......"},

    // HEBREW (Index 16)
    {"לחץ על ENTER כדי להמשיך......"},

    // PORTUGUESE (Index 17)
    {"Pressione ENTER para continuar......"},

    // FARSI (Index 18)
    {"برای ادامه ENTER را فشار دهید......"},

    // SWEDISH (Index 19)
    {"Tryck på ENTER för att fortsätta......"},

    // DUTCH (Index 20)
    {"Druk op ENTER om door te gaan......"},

    // TURKISH (Index 21)
    {"Devam etmek için ENTER tuşuna basın......"},

    // HINDI (Index 22)
    {"जारी रखने के लिए ENTER दबाएँ......"},

    // LATIN (Index 23)
    {"Preme ENTER ut pergere......"}
};


//==========================================================================
static const std::vector<InvalidInput2>  invalidInputTranslations2_hardcoded = {

    //Hungarian (Index 0)
{"Érvénytelen választás! Kérlek próbáld újra és megfelelő számot adj meg!"},

    // english (Index 1)
    {"Invalid choice. Please try again and enter a valid number!"},

    // CHINESE (Index 2)
    {"无效选择！请重试并输入有效的数字！"},

    // JAPANESE (Index 3)
    {"無効な選択です！もう一度試して、有効な数字を入力してください！"},

    // SPANISH (Index 4)
    {"¡Elección inválida! Por favor, inténtalo de nuevo e introduce un número válido."},

    // GERMAN (Index 5)
    {"Ungültige Auswahl! Bitte versuche es erneut und gib eine gültige Zahl ein!"},

    // FRENCH (Index 6)
    {"Choix invalide ! Veuillez réessayer et entrer un nombre valide !"},

    // RUSSIAN (Index 7)
    {"Неверный выбор! Пожалуйста, попробуйте снова и введите корректное число!"},

    // UKRAINIAN (Index 8)
    {"Невірний вибір! Будь ласка, спробуйте ще раз і введіть правильне число!"},

    // KOREAN (Index 9)
    {"잘못된 선택입니다! 다시 시도하고 올바른 숫자를 입력하세요!"},

    // ITALIAN (Index 10)
    {"Scelta non valida! Riprova e inserisci un numero valido!"},

    // POLISH (Index 11)
    {"Nieprawidłowy wybór! Spróbuj ponownie i wpisz poprawną liczbę!"},

    // ARABIC (Index 12)
    {"اختيار غير صالح! يرجى المحاولة مرة أخرى وإدخال رقم صحيح!"},

    // VIETNAMESE (Index 13)
    {"Lựa chọn không hợp lệ! Vui lòng thử lại và nhập số hợp lệ!"},

    // TAGALOG (Index 14)
    {"Di-wastong pagpili! Subukan muli at maglagay ng tamang numero!"},

    // GREEK (Index 15)
    {"Μη έγκυρη επιλογή! Προσπαθήστε ξανά και εισάγετε έγκυρο αριθμό!"},

    // HEBREW (Index 16)
    {"בחירה לא חוקית! אנא נסה שוב והזן מספר תקין!"},

    // PORTUGUESE (Index 17)
    {"Escolha inválida! Por favor, tente novamente e insira um número válido!"},

    // FARSI (Index 18)
    {"انتخاب نامعتبر! لطفاً دوباره تلاش کنید و یک عدد معتبر وارد کنید!"},

    // SWEDISH (Index 19)
    {"Ogiltigt val! Försök igen och ange ett giltigt nummer!"},

    // DUTCH (Index 20)
    {"Ongeldige keuze! Probeer opnieuw en voer een geldig nummer in!"},

    // TURKISH (Index 21)
    {"Geçersiz seçim! Lütfen tekrar deneyin ve geçerli bir sayı girin!"},

    // HINDI (Index 22)
    {"अमान्य चयन! कृपया फिर से प्रयास करें और सही संख्या दर्ज करें!"},

    // LATIN (Index 23)
    {"Electio non valida! Quaeso iterum tenta et numerum validum inserere!"}
};


//==========================================================================
static const std::vector<HaveNoWords> haveNoWordsTranslations_hardcoded = {

    // HUNGARIAN (Index 0)
    { "Nincsenek szavak ebben a fájlban" },

    // ENGLISH (Index 1)
    { "There are no words in this file" },

    // CHINESE (Index 2)
    { "此文件中没有单词" },

    // JAPANESE (Index 3)
    { "このファイルには単語がありません" },

    // SPANISH (Index 4)
    { "No hay palabras en este archivo" },

    // GERMAN (Index 5)
    { "In dieser Datei sind keine Wörter vorhanden" },

    // FRENCH (Index 6)
    { "Il n'y a pas de mots dans ce fichier" },

    // RUSSIAN (Index 7)
    { "В этом файле нет слов" },

    // UKRAINIAN (Index 8)
    { "У цьому файлі немає слів" },

    // KOREAN (Index 9)
    { "이 파일에는 단어가 없습니다" },

    // ITALIAN (Index 10)
    { "Non ci sono parole in questo file" },

    // POLISH (Index 11)
    { "W tym pliku nie ma słów" },

    // ARABIC (Index 12)
    { "لا توجد كلمات في هذا الملف" },

    // VIETNAMESE (Index 13)
    { "Không có từ nào trong tệp này" },

    // TAGALOG (Index 14)
    { "Walang mga salita sa file na ito" },

    // GREEK (Index 15)
    { "Δεν υπάρχουν λέξεις σε αυτό το αρχείο" },

    // HEBREW (Index 16)
    { "אין מילים בקובץ הזה" },

    // PORTUGUESE (Index 17)
    { "Não há palavras neste arquivo" },

    // FARSI (Index 18)
    { "هیچ کلمه‌ای در این فایل وجود ندارد" },

    // SWEDISH (Index 19)
    { "Det finns inga ord i den här filen" },

    // DUTCH (Index 20)
    { "Er zijn geen woorden in dit bestand" },

    // TURKISH (Index 21)
    { "Bu dosyada kelime yok" },

    // HINDI (Index 22)
    { "इस फ़ाइल में कोई शब्द नहीं हैं" },

    // LATIN (Index 23)
    { "Nulla verba in hoc fasciculo sunt" }
};


//==========================================================================
static const std::vector<ReTry> reTryTranslations_hardcoded = {

    // Hungarian (Index 0)
    {"Kérlek nyomj Entert az újrapróbálkozáshoz..."},

    // ENGLISH (Index 1)
    {"Please press ENTER to try again..."},

    // CHINESE (Index 2)
    {"请按回车键重试..."},

    // JAPANESE (Index 3)
    {"もう一度試すにはEnterキーを押してください..."},

    // SPANISH (Index 4)
    {"Por favor presiona ENTER para intentarlo de nuevo..."},

    // GERMAN (Index 5)
    {"Bitte drücke ENTER, um es erneut zu versuchen..."},

    // FRENCH (Index 6)
    {"Veuillez appuyer sur ENTRÉE pour réessayer..."},

    // RUSSIAN (Index 7)
    {"Нажмите ENTER, чтобы попробовать снова..."},

    // UKRAINIAN (Index 8)
    {"Натисніть ENTER, щоб спробувати ще раз..."},

    // KOREAN (Index 9)
    {"다시 시도하려면 ENTER 키를 누르세요..."},

    // ITALIAN (Index 10)
    {"Premi ENTER per riprovare..."},

    // POLISH (Index 11)
    {"Naciśnij ENTER, aby spróbować ponownie..."},

    // ARABIC (Index 12)
    {"اضغط ENTER للمحاولة مرة أخرى..."},

    // VIETNAMESE (Index 13)
    {"Nhấn ENTER để thử lại..."},

    // TAGALOG (Index 14)
    {"Pindutin ang ENTER para subukan muli..."},

    // GREEK (Index 15)
    {"Πατήστε ENTER για να δοκιμάσετε ξανά..."},

    // HEBREW (Index 16)
    {"לחץ ENTER כדי לנסות שוב..."},

    // PORTUGUESE (Index 17)
    {"Pressione ENTER para tentar novamente..."},

    // FARSI (Index 18)
    {"برای تلاش مجدد ENTER را فشار دهید..."},

    // SWEDISH (Index 19)
    {"Tryck på ENTER för att försöka igen..."},

    // DUTCH (Index 20)
    {"Druk op ENTER om opnieuw te proberen..."},

    // TURKISH (Index 21)
    {"Tekrar denemek için ENTER tuşuna basın..."},

    // HINDI (Index 22)
    {"फिर से प्रयास करने के लिए ENTER दबाएँ..."},

    // LATIN (Index 23)
    {"Preme ENTER ut iterum coneris..."}
};


//==========================================================================
static const std::vector<BadlyAnswer> badlyAnswerTranslations_hardcoded ={

    // Hungarian (Index 0)
    {"Rossz válasz(ok)!"},

    // ENGLISH (Index 1)
    {"Wrong answer(s)!"},

    // CHINESE (Index 2)
    {"错误答案！"},

    // JAPANESE (Index 3)
    {"不正解！"},

    // SPANISH (Index 4)
    {"¡Respuesta(s) incorrecta(s)!"},

    // GERMAN (Index 5)
    {"Falsche Antwort(en)!"},

    // FRENCH (Index 6)
    {"Mauvaise(s) réponse(s) !"},

    // RUSSIAN (Index 7)
    {"Неправильный(е) ответ(ы)!"},

    // UKRAINIAN (Index 8)
    {"Неправильна(і) відповідь(і)!"},

    // KOREAN (Index 9)
    {"오답입니다!"},

    // ITALIAN (Index 10)
    {"Risposta/e sbagliata/e!"},

    // POLISH (Index 11)
    {"Błędna/e odpowiedź/odpowiedzi!"},

    // ARABIC (Index 12)
    {"إجابة/إجابات خاطئة!"},

    // VIETNAMESE (Index 13)
    {"Câu trả lời sai!"},

    // TAGALOG (Index 14)
    {"Maling sagot!"},

    // GREEK (Index 15)
    {"Λάθος απάντηση(εις)!"},

    // HEBREW (Index 16)
    {"תשובה/ות שגויה/ות!"},

    // PORTUGUESE (Index 17)
    {"Resposta(s) incorreta(s)!"},

    // FARSI (Index 18)
    {"پاسخ(های) نادرست!"},

    // SWEDISH (Index 19)
    {"Fel svar!"},

    // DUTCH (Index 20)
    {"Fout(e) antwoord(en)!"},

    // TURKISH (Index 21)
    {"Yanlış cevap(lar)!"},

    // HINDI (Index 22)
    {"गलत उत्तर!"},

    // LATIN (Index 23)
    {"Responsum/responsa falsa!"}
};


//==========================================================================
static const std::vector<GoodAnswer1> goodAnswer1Translations_hardcoded = {

    // Hungarian (Index 0)
    {"Helyes válasz!"},

    // ENGLISH (Index 1)
    {"Correct Answer!"},

    // CHINESE (Index 2)
    {"正确答案！"},

    // JAPANESE (Index 3)
    {"正解！"},

    // SPANISH (Index 4)
    {"¡Respuesta correcta!"},

    // GERMAN (Index 5)
    {"Richtige Antwort!"},

    // FRENCH (Index 6)
    {"Bonne réponse!"},

    // RUSSIAN (Index 7)
    {"Правильный ответ!"},

    // UKRAINIAN (Index 8)
    {"Правильна відповідь!"},

    // KOREAN (Index 9)
    {"정답입니다!"},

    // ITALIAN (Index 10)
    {"Risposta corretta!"},

    // POLISH (Index 11)
    {"Poprawna odpowiedź!"},

    // ARABIC (Index 12)
    {"إجابة صحيحة!"},

    // VIETNAMESE (Index 13)
    {"Câu trả lời đúng!"},

    // TAGALOG (Index 14)
    {"Tamang sagot!"},

    // GREEK (Index 15)
    {"Σωστή απάντηση!"},

    // HEBREW (Index 16)
    {"תשובה נכונה!"},

    // PORTUGUESE (Index 17)
    {"Resposta correta!"},

    // FARSI (Index 18)
    {"پاسخ صحیح!"},

    // SWEDISH (Index 19)
    {"Rätt svar!"},

    // DUTCH (Index 20)
    {"Correct antwoord!"},

    // TURKISH (Index 21)
    {"Doğru cevap!"},

    // HINDI (Index 22)
    {"सही उत्तर!"},

    // LATIN (Index 23)
    {"Responsum rectum!"}
};


//==========================================================================
static const std::vector<GoodAnswer2> goodAnswer2Translations_hardcoded = {

    // Hungarian (Index 0)
    {"A helyes válasz(ok): "},

    // ENGLISH (Index 1)
    {"The correct answer(s): "},

    // CHINESE (Index 2)
    {"正确答案: "},

    // JAPANESE (Index 3)
    {"正解: "},

    // SPANISH (Index 4)
    {"Respuesta(s) correcta(s): "},

    // GERMAN (Index 5)
    {"Richtige Antwort(en): "},

    // FRENCH (Index 6)
    {"Réponse(s) correcte(s) : "},

    // RUSSIAN (Index 7)
    {"Правильный(е) ответ(ы): "},

    // UKRAINIAN (Index 8)
    {"Правильна(і) відповідь(і): "},

    // KOREAN (Index 9)
    {"정답: "},

    // ITALIAN (Index 10)
    {"Risposta/e corretta/e: "},

    // POLISH (Index 11)
    {"Poprawna/e odpowiedź/odpowiedzi: "},

    // ARABIC (Index 12)
    {"الإجابة/الإجابات الصحيحة: "},

    // VIETNAMESE (Index 13)
    {"Câu trả lời đúng: "},

    // TAGALOG (Index 14)
    {"Tamang sagot: "},

    // GREEK (Index 15)
    {"Σωστή(ές) απάντηση(εις): "},

    // HEBREW (Index 16)
    {"התשובה/ות הנכונה/ות: "},

    // PORTUGUESE (Index 17)
    {"Resposta(s) correta(s): "},

    // FARSI (Index 18)
    {"پاسخ(های) صحیح: "},

    // SWEDISH (Index 19)
    {"Rätt svar: "},

    // DUTCH (Index 20)
    {"Correct(e) antwoord(en): "},

    // TURKISH (Index 21)
    {"Doğru cevap(lar): "},

    // HINDI (Index 22)
    {"सही उत्तर: "},

    // LATIN (Index 23)
    {"Responsum/responsa recta: "}
};
//const std::vector<GoodAnswer2> goodAnswer2Translations = goodAnswer2Translations_hardcoded;

//==========================================================================
static const std::vector<PronunciationString> pronunciationStringTranslations_hardcoded = {
// const std::vector<PronunciationString> pronunciationStringTranslations = {
    // Hungarian (Index 0)
    {"Kiejtés: "},

    // ENGLISH (Index 1)
    {"Pronunciation: "},

    // CHINESE (Index 2)
    {"发音: "},

    // JAPANESE (Index 3)
    {"発音: "},

    // SPANISH (Index 4)
    {"Pronunciación: "},

    // GERMAN (Index 5)
    {"Aussprache: "},

    // FRENCH (Index 6)
    {"Prononciation : "},

    // RUSSIAN (Index 7)
    {"Произношение: "},

    // UKRAINIAN (Index 8)
    {"Вимова: "},

    // KOREAN (Index 9)
    {"발음: "},

    // ITALIAN (Index 10)
    {"Pronuncia: "},

    // POLISH (Index 11)
    {"Wymowa: "},

    // ARABIC (Index 12)
    {"النطق: "},

    // VIETNAMESE (Index 13)
    {"Phát âm: "},

    // TAGALOG (Index 14)
    {"Pagbigkas: "},

    // GREEK (Index 15)
    {"Προφορά: "},

    // HEBREW (Index 16)
    {"הגייה: "},

    // PORTUGUESE (Index 17)
    {"Pronúncia: "},

    // FARSI (Index 18)
    {"تلفظ: "},

    // SWEDISH (Index 19)
    {"Uttal: "},

    // DUTCH (Index 20)
    {"Uitspraak: "},

    // TURKISH (Index 21)
    {"Telaffuz: "},

    // HINDI (Index 22)
    {"उच्चारण: "},

    // LATIN (Index 23)
    {"Pronuntiatio: "}
};


//==========================================================================
static const std::vector<HaveFinished> haveFinishedTranslations_hardcoded = {

    // Hungarian (Index 0)
    {"Vége a leckének! Szép munka!"},

    // ENGLISH (Index 1)
    {"The lesson is over! Good job!"},

    // CHINESE (Index 2)
    {"课程结束了！干得好！"},

    // JAPANESE (Index 3)
    {"レッスンは終了です！よくできました！"},

    // SPANISH (Index 4)
    {"¡La lección ha terminado! ¡Buen trabajo!"},

    // GERMAN (Index 5)
    {"Die Lektion ist vorbei! Gute Arbeit!"},

    // FRENCH (Index 6)
    {"La leçon est terminée ! Bon travail !"},

    // RUSSIAN (Index 7)
    {"Урок завершён! Отличная работа!"},

    // UKRAINIAN (Index 8)
    {"Урок завершено! Гарна робота!"},

    // KOREAN (Index 9)
    {"수업이 끝났습니다! 잘했어요!"},

    // ITALIAN (Index 10)
    {"La lezione è finita! Ottimo lavoro!"},

    // POLISH (Index 11)
    {"Lekcja zakończona! Dobra robota!"},

    // ARABIC (Index 12)
    {"انتهى الدرس! عمل رائع!"},

    // VIETNAMESE (Index 13)
    {"Bài học đã kết thúc! Làm tốt lắm!"},

    // TAGALOG (Index 14)
    {"Tapos na ang aralin! Magaling!"},

    // GREEK (Index 15)
    {"Το μάθημα τελείωσε! Καλή δουλειά!"},

    // HEBREW (Index 16)
    {"השיעור הסתיים! עבודה טובה!"},

    // PORTUGUESE (Index 17)
    {"A lição terminou! Bom trabalho!"},

    // FARSI (Index 18)
    {"درس تمام شد! کار عالی!"},

    // SWEDISH (Index 19)
    {"Lektionen är slut! Bra jobbat!"},

    // DUTCH (Index 20)
    {"De les is voorbij! Goed gedaan!"},

    // TURKISH (Index 21)
    {"Ders bitti! İyi iş!"},

    // HINDI (Index 22)
    {"पाठ समाप्त हो गया! अच्छा काम!"},

    // LATIN (Index 23)
    {"Lectio finita est! Bene fecisti!"}
};


//==========================================================================
static const std::vector<ScoreSys> totalTranslations_hardcoded = {

    // HUNGARIAN (Index 0)
    {
        "---=== Eredmény === ---",
        "A kérdések száma: ",
        "Helyes válaszok: ",
        "Helytelen válaszok: ",
        "Teljesítmény százalékban: "
    },

    // ENGLISH (Index 1)
    {
        "---=== Results ===---",
        "Number of questions: ",
        "Correct answers: ",
        "Wrong answers: ",
        "Performance percentage: "
    },

    // CHINESE (Index 2)
    {
        "---=== 结果 ===---",
        "问题数量: ",
        "正确答案: ",
        "错误答案: ",
        "表现百分比: "
    },

    // JAPANESE (Index 3)
    {
        "---=== 結果 ===---",
        "質問数: ",
        "正解数: ",
        "不正解数: ",
        "達成率: "
    },

    // SPANISH (Index 4)
    {
        "---=== Resultados ===---",
        "Número de preguntas: ",
        "Respuestas correctas: ",
        "Respuestas incorrectas: ",
        "Porcentaje de rendimiento: "
    },

    // GERMAN (Index 5)
    {
        "---=== Ergebnisse ===---",
        "Anzahl der Fragen: ",
        "Richtige Antworten: ",
        "Falsche Antworten: ",
        "Leistungsprozentsatz: "
    },

    // FRENCH (Index 6)
    {
        "---=== Résultats ===---",
        "Nombre de questions: ",
        "Réponses correctes: ",
        "Réponses incorrectes: ",
        "Pourcentage de performance: "
    },

    // RUSSIAN (Index 7)
    {
        "---=== Результаты ===---",
        "Количество вопросов: ",
        "Правильные ответы: ",
        "Неправильные ответы: ",
        "Процент выполнения: "
    },

    // UKRAINIAN (Index 8)
    {
        "---=== Результати ===---",
        "Кількість запитань: ",
        "Правильні відповіді: ",
        "Неправильні відповіді: ",
        "Відсоток виконання: "
    },

    // KOREAN (Index 9)
    {
        "---=== 결과 ===---",
        "문제 수: ",
        "정답 수: ",
        "오답 수: ",
        "성과 비율: "
    },

    // ITALIAN (Index 10)
    {
        "---=== Risultati ===---",
        "Numero di domande: ",
        "Risposte corrette: ",
        "Risposte sbagliate: ",
        "Percentuale di rendimento: "
    },

    // POLISH (Index 11)
    {
        "---=== Wyniki ===---",
        "Liczba pytań: ",
        "Poprawne odpowiedzi: ",
        "Błędne odpowiedzi: ",
        "Procent wydajności: "
    },

    // ARABIC (Index 12)
    {
        "---=== النتائج ===---",
        "عدد الأسئلة: ",
        "الإجابات الصحيحة: ",
        "الإجابات الخاطئة: ",
        "نسبة الأداء: "
    },

    // VIETNAMESE (Index 13)
    {
        "---=== Kết quả ===---",
        "Số câu hỏi: ",
        "Câu trả lời đúng: ",
        "Câu trả lời sai: ",
        "Phần trăm hiệu suất: "
    },

    // TAGALOG (Index 14)
    {
        "---=== Resulta ===---",
        "Bilang ng mga tanong: ",
        "Tamang sagot: ",
        "Maling sagot: ",
        "Porsyento ng performance: "
    },

    // GREEK (Index 15)
    {
        "---=== Αποτελέσματα ===---",
        "Αριθμός ερωτήσεων: ",
        "Σωστές απαντήσεις: ",
        "Λάθος απαντήσεις: ",
        "Ποσοστό απόδοσης: "
    },

    // HEBREW (Index 16)
    {
        "---=== תוצאות ===---",
        "מספר שאלות: ",
        "תשובות נכונות: ",
        "תשובות שגויות: ",
        "אחוז ביצועים: "
    },

    // PORTUGUESE (Index 17)
    {
        "---=== Resultados ===---",
        "Número de perguntas: ",
        "Respostas corretas: ",
        "Respostas erradas: ",
        "Percentagem de desempenho: "
    },

    // FARSI (Index 18)
    {
        "---=== نتایج ===---",
        "تعداد سوالات: ",
        "پاسخ‌های صحیح: ",
        "پاسخ‌های نادرست: ",
        "درصد عملکرد: "
    },

    // SWEDISH (Index 19)
    {
        "---=== Resultat ===---",
        "Antal frågor: ",
        "Rätta svar: ",
        "Felaktiga svar: ",
        "Prestandaprocent: "
    },

    // DUTCH (Index 20)
    {
        "---=== Resultaten ===---",
        "Aantal vragen: ",
        "Correcte antwoorden: ",
        "Foute antwoorden: ",
        "Prestatiepercentage: "
    },

    // TURKISH (Index 21)
    {
        "---=== Sonuçlar ===---",
        "Soru sayısı: ",
        "Doğru cevaplar: ",
        "Yanlış cevaplar: ",
        "Performans yüzdesi: "
    },

    // HINDI (Index 22)
    {
        "---=== परिणाम ===---",
        "प्रश्नों की संख्या: ",
        "सही उत्तर: ",
        "गलत उत्तर: ",
        "प्रदर्शन प्रतिशत: "
    },

    // LATIN (Index 23)
    {
        "---=== Eventus ===---",
        "Numerus quaestionum: ",
        "Responsa recta: ",
        "Responsa falsa: ",
        "Percentum performance: "
    }
};


//==========================================================================
static const std::vector<PercentAge> percentAgeTranslations_hardcoded = {

    // HUNGARIAN (Index 0)
    {
        "Tökéletes! Gratulálok, cool vagy!",
        "Majdnem tökéletes, szép munka!",
        "Gyakorolj még egy kicsit!"
    },

    // ENGLISH (Index 1)
    {
        "Perfect! Congratulations, you're cool!",
        "Almost perfect, nice job!",
        "Keep practicing a little more!"
    },

    // CHINESE (Index 2)
    {
        "完美！恭喜你，很棒！",
        "差一点完美，做得很好！",
        "再多练习一点吧！"
    },

    // JAPANESE (Index 3)
    {
        "完璧！おめでとう、すごいね！",
        "ほぼ完璧、よくできました！",
        "もう少し練習しましょう！"
    },

    // SPANISH (Index 4)
    {
        "¡Perfecto! ¡Felicidades, eres genial!",
        "Casi perfecto, ¡buen trabajo!",
        "¡Practica un poco más!"
    },

    // GERMAN (Index 5)
    {
        "Perfekt! Glückwunsch, du bist cool!",
        "Fast perfekt, gute Arbeit!",
        "Übe noch ein bisschen!"
    },

    // FRENCH (Index 6)
    {
        "Parfait ! Félicitations, tu es génial !",
        "Presque parfait, bon travail !",
        "Entraîne-toi encore un peu !"
    },

    // RUSSIAN (Index 7)
    {
        "Идеально! Поздравляю, ты крут!",
        "Почти идеально, отличная работа!",
        "Потренируйся ещё немного!"
    },

    // UKRAINIAN (Index 8)
    {
        "Ідеально! Вітаю, ти крутий!",
        "Майже ідеально, гарна робота!",
        "Потренуйся ще трохи!"
    },

    // KOREAN (Index 9)
    {
        "완벽해요! 축하해요, 멋져요!",
        "거의 완벽해요, 잘했어요!",
        "조금만 더 연습하세요!"
    },

    // ITALIAN (Index 10)
    {
        "Perfetto! Complimenti, sei fantastico!",
        "Quasi perfetto, ottimo lavoro!",
        "Continua a esercitarti un po’!"
    },

    // POLISH (Index 11)
    {
        "Perfekcyjnie! Gratulacje, jesteś świetny!",
        "Prawie perfekcyjnie, dobra robota!",
        "Poćwicz jeszcze trochę!"
    },

    // ARABIC (Index 12)
    {
        "ممتاز! تهانينا، أنت رائع!",
        "قريب من المثالي، عمل رائع!",
        "تدرب قليلاً أكثر!"
    },

    // VIETNAMESE (Index 13)
    {
        "Hoàn hảo! Chúc mừng, bạn thật tuyệt!",
        "Gần hoàn hảo, làm tốt lắm!",
        "Hãy luyện tập thêm một chút!"
    },

    // TAGALOG (Index 14)
    {
        "Perpekto! Binabati kita, astig ka!",
        "Halos perpekto, magandang trabaho!",
        "Magpraktis ka pa ng kaunti!"
    },

    // GREEK (Index 15)
    {
        "Τέλειο! Συγχαρητήρια, είσαι φοβερός!",
        "Σχεδόν τέλειο, καλή δουλειά!",
        "Εξασκήσου λίγο ακόμα!"
    },

    // HEBREW (Index 16)
    {
        "מושלם! כל הכבוד, אתה תותח!",
        "כמעט מושלם, עבודה יפה!",
        "תמשיך להתאמן עוד קצת!"
    },

    // PORTUGUESE (Index 17)
    {
        "Perfeito! Parabéns, você é incrível!",
        "Quase perfeito, bom trabalho!",
        "Continue praticando um pouco mais!"
    },

    // FARSI (Index 18)
    {
        "عالی! تبریک می‌گویم، تو فوق‌العاده‌ای!",
        "تقریباً عالی، کار خوبی بود!",
        "کمی بیشتر تمرین کن!"
    },

    // SWEDISH (Index 19)
    {
        "Perfekt! Grattis, du är grym!",
        "Nästan perfekt, bra jobbat!",
        "Öva lite till!"
    },

    // DUTCH (Index 20)
    {
        "Perfect! Gefeliciteerd, je bent geweldig!",
        "Bijna perfect, goed gedaan!",
        "Oefen nog een beetje!"
    },

    // TURKISH (Index 21)
    {
        "Mükemmel! Tebrikler, harikasın!",
        "Neredeyse mükemmel, iyi iş!",
        "Biraz daha pratik yap!"
    },

    // HINDI (Index 22)
    {
        "परफेक्ट! बधाई हो, तुम कमाल हो!",
        "लगभग परफेक्ट, अच्छा काम!",
        "थोड़ा और अभ्यास करो!"
    },

    // LATIN (Index 23)
    {
        "Perfectum! Gratulationes, es mirabilis!",
        "Fere perfectum, bene fecisti!",
        "Paulum adhuc exerce!"
    }
};


//==========================================================================
static const std::vector<QuizExplanation> quizExplanationTranslations_hardcoded = {


    // HUNGARIAN (Index 0)
    {
        "A kilépéshez használd az 'exit' vagy 'e' parancsot illetve használd a Ctrl + c -t .",
        "A segítséghez (a válasz kiírásához) írd be a 'h' vagy 'help' parancsot illetve használd a Ctrl + y (be).",
        "A segítség kikapcsolásához használd a 'h off' vagy 'help off' parancsot illetve használd a Ctrl + n -t(ki)."
    },

    // ENGLISH (Index 1)
    {
        "To exit use the 'exit' or 'e' command or Ctrl + C.",
        "To get help (show answer) use the 'h' or 'help' command or Ctrl + Y (on).",
        "To disable help use the 'h off' or 'help off' command or Ctrl + N (off)."
    },

    // CHINESE (Index 2)
    {
        "使用 'exit' 或 'e' 命令退出程序，或 Ctrl + C。",
        "使用 'h' 或 'help' 命令查看答案，或 Ctrl + Y（开启）。",
        "使用 'h off' 或 'help off' 命令关闭帮助，或 Ctrl + N（关闭）。"
    },

    // JAPANESE (Index 3)
    {
        "終了には 'exit' または 'e' コマンドを使用、または Ctrl + C。",
        "ヘルプには 'h' または 'help' コマンドを使用、または Ctrl + Y（オン）。",
        "ヘルプ無効には 'h off' または 'help off' コマンドを使用、または Ctrl + N（オフ）。"
    },

    // SPANISH (Index 4)
    {
        "Para salir usa el comando 'exit' o 'e' o Ctrl + C.",
        "Para ayuda usa el comando 'h' o 'help' o Ctrl + Y (activar).",
        "Para desactivar ayuda usa 'h off' o 'help off' o Ctrl + N."
    },

    // GERMAN (Index 5)
    {
        "Zum Beenden benutze 'exit' oder 'e' oder Ctrl + C.",
        "Für Hilfe benutze 'h' oder 'help' oder Ctrl + Y (ein).",
        "Zum Deaktivieren benutze 'h off' oder 'help off' oder Ctrl + N."
    },

    // FRENCH (Index 6)
    {
        "Pour quitter utilisez 'exit' ou 'e' ou Ctrl + C.",
        "Pour l'aide utilisez 'h' ou 'help' ou Ctrl + Y (activer).",
        "Pour désactiver utilisez 'h off' ou 'help off' ou Ctrl + N."
    },

    // RUSSIAN (Index 7)
    {
        "Для выхода используйте 'exit' или 'e' или Ctrl + C.",
        "Для помощи используйте 'h' или 'help' или Ctrl + Y (вкл).",
        "Для отключения используйте 'h off' или 'help off' или Ctrl + N."
    },

    // UKRAINIAN (Index 8)
    {
        "Для виходу використовуйте 'exit' або 'e' або Ctrl + C.",
        "Для допомоги використовуйте 'h' або 'help' або Ctrl + Y (увімк.).",
        "Для вимкнення використовуйте 'h off' або 'help off' або Ctrl + N."
    },

    // KOREAN (Index 9)
    {
        "종료: 'exit' 또는 'e' 또는 Ctrl + C.",
        "도움말: 'h' 또는 'help' 또는 Ctrl + Y.",
        "비활성화: 'h off' 또는 'help off' 또는 Ctrl + N."
    },

    // ITALIAN (Index 10)
    {
        "Per uscire usa 'exit' o 'e' o Ctrl + C.",
        "Per aiuto usa 'h' o 'help' o Ctrl + Y.",
        "Per disattivare usa 'h off' o 'help off' o Ctrl + N."
    },

    // POLISH (Index 11)
    {
        "Aby wyjść użyj 'exit' lub 'e' lub Ctrl + C.",
        "Aby pomoc użyj 'h' lub 'help' lub Ctrl + Y.",
        "Aby wyłączyć użyj 'h off' lub 'help off' lub Ctrl + N."
    },

    // ARABIC (Index 12)
    {
        "للخروج استخدم 'exit' أو 'e' أو Ctrl + C.",
        "للمساعدة استخدم 'h' أو 'help' أو Ctrl + Y.",
        "لإيقاف المساعدة استخدم 'h off' أو 'help off' أو Ctrl + N."
    },

    // VIETNAMESE (Index 13)
    {
        "Thoát: 'exit' hoặc 'e' hoặc Ctrl + C.",
        "Trợ giúp: 'h' hoặc 'help' hoặc Ctrl + Y.",
        "Tắt: 'h off' hoặc 'help off' hoặc Ctrl + N."
    },

    // TAGALOG (Index 14)
    {
        "Lumabas: 'exit' o 'e' o Ctrl + C.",
        "Tulong: 'h' o 'help' o Ctrl + Y.",
        "I-off: 'h off' o 'help off' o Ctrl + N."
    },

    // GREEK (Index 15)
    {
        "Έξοδος: 'exit' ή 'e' ή Ctrl + C.",
        "Βοήθεια: 'h' ή 'help' ή Ctrl + Y.",
        "Απενεργοποίηση: 'h off' ή 'help off' ή Ctrl + N."
    },

    // HEBREW (Index 16)
    {
        "יציאה: 'exit' או 'e' או Ctrl + C.",
        "עזרה: 'h' או 'help' או Ctrl + Y.",
        "כיבוי: 'h off' או 'help off' או Ctrl + N."
    },

    // PORTUGUESE (Index 17)
    {
        "Sair: 'exit' ou 'e' ou Ctrl + C.",
        "Ajuda: 'h' ou 'help' ou Ctrl + Y.",
        "Desativar: 'h off' ou 'help off' ou Ctrl + N."
    },

    // FARSI (Index 18)
    {
        "خروج: 'exit' یا 'e' یا Ctrl + C.",
        "راهنما: 'h' یا 'help' یا Ctrl + Y.",
        "خاموش: 'h off' یا 'help off' یا Ctrl + N."
    },

    // SWEDISH (Index 19)
    {
        "Avsluta: 'exit' eller 'e' eller Ctrl + C.",
        "Hjälp: 'h' eller 'help' eller Ctrl + Y.",
        "Stäng: 'h off' eller 'help off' eller Ctrl + N."
    },

    // DUTCH (Index 20)
    {
        "Afsluiten: 'exit' of 'e' of Ctrl + C.",
        "Hulp: 'h' of 'help' of Ctrl + Y.",
        "Uit: 'h off' of 'help off' of Ctrl + N."
    },

    // TURKISH (Index 21)
    {
        "Çıkış: 'exit' veya 'e' veya Ctrl + C.",
        "Yardım: 'h' veya 'help' veya Ctrl + Y.",
        "Kapat: 'h off' veya 'help off' veya Ctrl + N."
    },

    // HINDI (Index 22)
    {
        "बाहर निकलें: 'exit' या 'e' या Ctrl + C.",
        "मदद: 'h' या 'help' या Ctrl + Y.",
        "बंद: 'h off' या 'help off' या Ctrl + N."
    },

    // LATIN (Index 23)
    {
        "Exitus: 'exit' vel 'e' vel Ctrl + C.",
        "Auxilium: 'h' vel 'help' vel Ctrl + Y.",
        "Desine: 'h off' vel 'help off' vel Ctrl + N."
    }
};


//==========================================================================
static const std::vector<VocabWordsPairTotal> vocabWordsPairTotalTranslations_hardcoded = {


    // Hungarian (Index 0)
    {
        "Összesen ",
        " szó pár lett elmentve a(z) ",
        ".data fájlba."
    },

    // English (Index 1)
    {
        "A total of ",
        " word pairs were saved to the ",
        ".data file."
    },

    // Chinese (Index 2)
    {
        "总共 ",
        " 个词对已保存到 ",
        ".data 文件。"
    },

    // Japanese (Index 3)
    {
        "合計 ",
        " 個の単語ペアが ",
        ".data ファイルに保存されました。"
    },

    // Spanish (Index 4)
    {
        "Un total de ",
        " pares de palabras fueron guardados en ",
        ".data archivo."
    },

    // German (Index 5)
    {
        "Insgesamt ",
        " Wortpaare wurden in die Datei ",
        ".data gespeichert."
    },

    // French (Index 6)
    {
        "Un total de ",
        " paires de mots ont été enregistrées dans le fichier ",
        ".data."
    },

    // Russian (Index 7)
    {
        "Всего ",
        " пар слов сохранено в файл ",
        ".data."
    },

    // Ukrainian (Index 8)
    {
        "Всього ",
        " пар слів збережено у файл ",
        ".data."
    },

    // Korean (Index 9)
    {
        "총 ",
        " 개의 단어 쌍이 ",
        ".data 파일에 저장되었습니다."
    },

    // Italian (Index 10)
    {
        "Un totale di ",
        " coppie di parole sono state salvate nel file ",
        ".data."
    },

    // Polish (Index 11)
    {
        "Łącznie ",
        " par słów zapisano do pliku ",
        ".data."
    },

    // Arabic (Index 12)
    {
        "تم حفظ ",
        " من أزواج الكلمات في ملف ",
        ".data."
    },

    // Vietnamese (Index 13)
    {
        "Tổng cộng ",
        " cặp từ đã được lưu vào file ",
        ".data."
    },

    // Tagalog (Index 14)
    {
        "Kabuuang ",
        " pares ng salita ang na-save sa ",
        ".data file."
    },

    // Greek (Index 15)
    {
        "Συνολικά ",
        " ζεύγη λέξεων αποθηκεύτηκαν στο αρχείο ",
        ".data."
    },

    // Hebrew (Index 16)
    {
        "בסך הכל ",
        " זוגות מילים נשמרו בקובץ ",
        ".data."
    },

    // Portuguese (Index 17)
    {
        "Um total de ",
        " pares de palavras foram salvos no arquivo ",
        ".data."
    },

    // Persian (Index 18)
    {
        "در مجموع ",
        " جفت کلمه در فایل ",
        ".data ذخیره شد."
    },

    // Swedish (Index 19)
    {
        "Totalt ",
        " ordpar sparades i filen ",
        ".data."
    },

    // Dutch (Index 20)
    {
        "In totaal ",
        " woordparen zijn opgeslagen in het bestand ",
        ".data."
    },

    // Turkish (Index 21)
    {
        "Toplam ",
        " kelime çifti ",
        ".data dosyasına kaydedildi."
    },

    // Hindi (Index 22)
    {
        "कुल ",
        " शब्द युग्म ",
        ".data फ़ाइल में सहेजे गए।"
    },

    // Latin (Index 23)
    {
        "In summa ",
        " paria verborum in archivo ",
        ".data servata sunt."
    }
};


//==========================================================================
static const std::vector<CreateVocabFile> createVocabFileTranslations_hardcoded = {

    // HUNGARIAN (Index 0)
    { "Kérlek add meg a fájl nevét: ",
      "Melyik mappába mentsük? (Ha jó a jelenlegi, nyomj Enter-t): ",
      "Hiba: Érvénytelen vagy nem létező útvonal!",
      "Hiba: Nem sikerült létrehozni a fájlt! (Lehet, hogy nem létezik a mappa?)",
      "Fájl elmentve...",
      "Automatikusan elmentve!",
      "Hiba: A '",
      "' mappa nem létezik.",
      "Szeretnéd létrehozni? (y/n): ",
      "A művelet megszakítva. Kérlek adj meg létező mappát!" },

    // ENGLISH (Index 1)
    { "Please enter the file name: ",
      "Which folder should we save it to? (Press Enter to use current): ",
      "Error: Invalid or non-existing path!",
      "Error: Failed to create file!",
      "File saved...",
      "Saved automatically!",
      "Error: Folder '",
      "' does not exist.",
      "Would you like to create it? (y/n): ",
      "Operation cancelled. Please provide a valid folder!" },

    // CHINESE (Index 2)
    { "请输入文件名：",
      "保存到哪个文件夹？（回车使用当前路径）：",
      "错误：路径无效或不存在！",
      "错误：无法创建文件！",
      "文件已保存...",
      "已自动保存！",
      "错误：文件夹 '",
      "' 不存在。",
      "是否创建它？(y/n)：",
      "操作已取消。请输入有效的文件夹！" },

    // JAPANESE (Index 3)
    { "ファイル名を入力してください：",
      "どのフォルダに保存しますか？（Enterで現在）：",
      "エラー：無効または存在しないパスです！",
      "エラー：ファイルを作成できません！",
      "ファイルが保存されました...",
      "自動保存されました！",
      "エラー：フォルダ '",
      "' は存在しません。",
      "作成しますか？(y/n)：",
      "操作がキャンセルされました。有効なフォルダを入力してください！" },

    // SPANISH (Index 4)
    { "Introduce el nombre del archivo: ",
      "¿En qué carpeta guardar? (Enter = actual): ",
      "Error: Ruta inválida o inexistente!",
      "Error: No se pudo crear el archivo!",
      "Archivo guardado...",
      "Guardado automáticamente!",
      "Error: La carpeta '",
      "' no existe.",
      "¿Deseas crearla? (y/n): ",
      "Operación cancelada. Proporciona una carpeta válida!" },

    // GERMAN (Index 5)
    { "Bitte Dateinamen eingeben: ",
      "In welchen Ordner speichern? (Enter = aktuell): ",
      "Fehler: Ungültiger oder nicht existierender Pfad!",
      "Fehler: Datei konnte nicht erstellt werden!",
      "Datei gespeichert...",
      "Automatisch gespeichert!",
      "Fehler: Ordner '",
      "' existiert nicht.",
      "Möchtest du ihn erstellen? (y/n): ",
      "Vorgang abgebrochen. Bitte gültigen Ordner angeben!" },

    // FRENCH (Index 6)
    { "Entrez le nom du fichier : ",
      "Dans quel dossier enregistrer ? (Entrée = actuel) : ",
      "Erreur : chemin invalide ou inexistant !",
      "Erreur : impossible de créer le fichier !",
      "Fichier enregistré...",
      "Enregistré automatiquement !",
      "Erreur : dossier '",
      "' inexistant.",
      "Le créer ? (y/n) : ",
      "Opération annulée. Fournissez un dossier valide !" },

    // RUSSIAN (Index 7)
    { "Введите имя файла: ",
      "В какую папку сохранить? (Enter = текущая): ",
      "Ошибка: Неверный или несуществующий путь!",
      "Ошибка: Не удалось создать файл!",
      "Файл сохранён...",
      "Автосохранение выполнено!",
      "Ошибка: Папка '",
      "' не существует.",
      "Создать её? (y/n): ",
      "Операция отменена. Укажите существующую папку!" },

    // UKRAINIAN (Index 8)
    { "Введіть назву файлу: ",
      "У яку папку зберегти? (Enter = поточна): ",
      "Помилка: Невірний або неіснуючий шлях!",
      "Помилка: Не вдалося створити файл!",
      "Файл збережено...",
      "Автозбереження виконано!",
      "Помилка: Папка '",
      "' не існує.",
      "Створити її? (y/n): ",
      "Операцію скасовано. Вкажіть існуючу папку!" },

    // KOREAN (Index 9)
    { "파일 이름을 입력하세요: ",
      "어느 폴더에 저장할까요? (Enter = 현재): ",
      "오류: 잘못된 경로 또는 존재하지 않음!",
      "오류: 파일 생성 실패!",
      "파일 저장됨...",
      "자동 저장 완료!",
      "오류: 폴더 '",
      "' 존재하지 않음.",
      "생성하시겠습니까? (y/n): ",
      "작업 취소됨. 올바른 폴더를 입력하세요!" },

    // ITALIAN (Index 10)
    { "Inserisci il nome del file: ",
      "In quale cartella salvare? (Invio = attuale): ",
      "Errore: Percorso non valido o inesistente!",
      "Errore: Impossibile creare il file!",
      "File salvato...",
      "Salvato automaticamente!",
      "Errore: Cartella '",
      "' non esiste.",
      "Crearla? (y/n): ",
      "Operazione annullata. Specifica una cartella valida!" },

    // POLISH (Index 11)
    { "Podaj nazwę pliku: ",
      "Do którego folderu zapisać? (Enter = bieżący): ",
      "Błąd: Nieprawidłowa lub nieistniejąca ścieżka!",
      "Błąd: Nie udało się utworzyć pliku!",
      "Plik zapisany...",
      "Zapisano automatycznie!",
      "Błąd: Folder '",
      "' nie istnieje.",
      "Utworzyć go? (y/n): ",
      "Operacja anulowana. Podaj poprawny folder!" },

    // ARABIC (Index 12)
    { "أدخل اسم الملف: ",
      "في أي مجلد تريد الحفظ؟ (Enter = الحالي): ",
      "خطأ: مسار غير صالح أو غير موجود!",
      "خطأ: فشل إنشاء الملف!",
      "تم حفظ الملف...",
      "تم الحفظ تلقائيًا!",
      "خطأ: المجلد '",
      "' غير موجود.",
      "هل تريد إنشاءه؟ (y/n): ",
      "تم إلغاء العملية. أدخل مجلد صالح!" },

    // VIETNAMESE (Index 13)
    { "Nhập tên tệp: ",
      "Lưu vào thư mục nào? (Enter = hiện tại): ",
      "Lỗi: Đường dẫn không hợp lệ!",
      "Lỗi: Không thể tạo tệp!",
      "Đã lưu tệp...",
      "Đã tự động lưu!",
      "Lỗi: Thư mục '",
      "' không tồn tại.",
      "Bạn có muốn tạo không? (y/n): ",
      "Đã hủy. Hãy nhập thư mục hợp lệ!" },

    // TAGALOG (Index 14)
    { "Ilagay ang pangalan ng file: ",
      "Saang folder ise-save? (Enter = kasalukuyan): ",
      "Error: Invalid o walang path!",
      "Error: Hindi magawa ang file!",
      "Naka-save ang file...",
      "Auto-save na!",
      "Error: Ang folder '",
      "' ay wala.",
      "Gusto mo bang gawin ito? (y/n): ",
      "Kinansela. Magbigay ng tamang folder!" },

    // GREEK (Index 15)
    { "Εισάγετε όνομα αρχείου: ",
      "Σε ποιο φάκελο να αποθηκευτεί; (Enter = τρέχων): ",
      "Σφάλμα: Μη έγκυρη διαδρομή!",
      "Σφάλμα: Αποτυχία δημιουργίας αρχείου!",
      "Το αρχείο αποθηκεύτηκε...",
      "Αυτόματη αποθήκευση!",
      "Σφάλμα: Ο φάκελος '",
      "' δεν υπάρχει.",
      "Θέλετε να δημιουργηθεί; (y/n): ",
      "Η λειτουργία ακυρώθηκε. Δώστε έγκυρο φάκελο!" },

    // HEBREW (Index 16)
    { "הזן שם קובץ: ",
      "לאיזה תיקייה לשמור? (Enter = נוכחית): ",
      "שגיאה: נתיב לא חוקי!",
      "שגיאה: יצירת הקובץ נכשלה!",
      "הקובץ נשמר...",
      "נשמר אוטומטית!",
      "שגיאה: התיקייה '",
      "' לא קיימת.",
      "ליצור אותה? (y/n): ",
      "הפעולה בוטלה. הזן תיקייה חוקית!" },

    // PORTUGUESE (Index 17)
    { "Digite o nome do arquivo: ",
      "Salvar em qual pasta? (Enter = atual): ",
      "Erro: Caminho inválido!",
      "Erro: Falha ao criar arquivo!",
      "Arquivo salvo...",
      "Salvo automaticamente!",
      "Erro: Pasta '",
      "' não existe.",
      "Deseja criar? (y/n): ",
      "Operação cancelada. Informe uma pasta válida!" },

    // FARSI (Index 18)
    { "نام فایل را وارد کنید: ",
      "در کدام پوشه ذخیره شود؟ (Enter = فعلی): ",
      "خطا: مسیر نامعتبر!",
      "خطا: ایجاد فایل ناموفق!",
      "فایل ذخیره شد...",
      "ذخیره خودکار!",
      "خطا: پوشه '",
      "' وجود ندارد.",
      "می‌خواهید ایجاد شود؟ (y/n): ",
      "عملیات لغو شد. مسیر معتبر وارد کنید!" },

    // SWEDISH (Index 19)
    { "Ange filnamn: ",
      "Vilken mapp spara i? (Enter = nuvarande): ",
      "Fel: Ogiltig sökväg!",
      "Fel: Kunde inte skapa fil!",
      "Filen sparad...",
      "Autosparad!",
      "Fel: Mappen '",
      "' finns inte.",
      "Skapa den? (y/n): ",
      "Åtgärd avbruten. Ange giltig mapp!" },

    // DUTCH (Index 20)
    { "Voer bestandsnaam in: ",
      "In welke map opslaan? (Enter = huidige): ",
      "Fout: Ongeldig pad!",
      "Fout: Bestand kon niet worden gemaakt!",
      "Bestand opgeslagen...",
      "Automatisch opgeslagen!",
      "Fout: Map '",
      "' bestaat niet.",
      "Aanmaken? (y/n): ",
      "Actie geannuleerd. Geef geldige map!" },

    // TURKISH (Index 21)
    { "Dosya adını girin: ",
      "Hangi klasöre kaydedilsin? (Enter = mevcut): ",
      "Hata: Geçersiz yol!",
      "Hata: Dosya oluşturulamadı!",
      "Dosya kaydedildi...",
      "Otomatik kaydedildi!",
      "Hata: Klasör '",
      "' mevcut değil.",
      "Oluşturulsun mu? (y/n): ",
      "İşlem iptal edildi. Geçerli klasör girin!" },

    // HINDI (Index 22)
    { "फ़ाइल का नाम दर्ज करें: ",
      "किस फ़ोल्डर में सेव करें? (Enter = वर्तमान): ",
      "त्रुटि: अमान्य पथ!",
      "त्रुटि: फ़ाइल नहीं बन सकी!",
      "फ़ाइल सेव हो गई...",
      "स्वचालित रूप से सेव!",
      "त्रुटि: फ़ोल्डर '",
      "' मौजूद नहीं है।",
      "क्या बनाना चाहते हैं? (y/n): ",
      "ऑपरेशन रद्द। सही फ़ोल्डर दें!" },

    // LATIN (Index 23)
    { "Nomen fasciculi inseri: ",
      "In quo directorio servare? (Enter = currente): ",
      "Error: Via non valida!",
      "Error: Fasciculus creari non potest!",
      "Fasciculus servatus...",
      "Automatice servatus!",
      "Error: Directorium '",
      "' non existit.",
      "Vis creare? (y/n): ",
      "Operatio cancellata. Directorium validum da!" }

};


//==========================================================================
static const std::vector<CreateVocab> createVocabTranslations_hardcoded = {


    // Hungarian (0)
    {
        "Fájl: ",
        " (",
        " szó eddig) ---",
        "Parancsok: 'exit'(mentés és kilépés),'save'(mentés és folytatás),'back'(vissza ha elrontottad)",
        "A tanult nyelven a szó/mondat: ",
        "Az anyanyelveden a jelentése (vesszővel elválasztva ha több van): ",
        "Kiejtés (opcionális): "
    },

    // English (1)
    {
        "File: ",
        " (",
        " words so far) ---",
        "Commands: 'exit' (save & quit), 'save' (save & continue), 'back' (undo last)",
        "Word/sentence in learning language: ",
        "Meaning in your native language (comma separated if multiple): ",
        "Pronunciation (optional): "
    },

    // Chinese (2)
    {
        "文件: ",
        " (",
        " 当前词数) ---",
        "命令: 'exit'(保存并退出),'save'(保存继续),'back'(撤销)",
        "学习语言中的单词/句子: ",
        "母语含义（多个用逗号分隔）: ",
        "发音（可选）: "
    },

    // Japanese (3)
    {
        "ファイル: ",
        " (",
        " 単語数) ---",
        "コマンド: 'exit'(保存して終了),'save'(保存して続行),'back'(戻る)",
        "学習言語の単語/文: ",
        "母語での意味（複数はカンマ区切り）: ",
        "発音（任意）: "
    },

    // Spanish (4)
    {
        "Archivo: ",
        " (",
        " palabras hasta ahora) ---",
        "Comandos: 'exit'(guardar y salir),'save'(guardar y continuar),'back'(deshacer)",
        "Palabra/frase en idioma aprendido: ",
        "Significado en tu idioma (separado por comas): ",
        "Pronunciación (opcional): "
    },

    // German (5)
    {
        "Datei: ",
        " (",
        " Wörter bisher) ---",
        "Befehle: 'exit'(speichern & beenden),'save'(speichern & weiter),'back'(zurück)",
        "Wort/Satz in Lernsprache: ",
        "Bedeutung in Muttersprache (kommagetrennt): ",
        "Aussprache (optional): "
    },

    // French (6)
    {
        "Fichier: ",
        " (",
        " mots jusqu'à présent) ---",
        "Commandes: 'exit'(sauvegarder et quitter),'save'(sauvegarder et continuer),'back'(annuler)",
        "Mot/phrase dans la langue cible: ",
        "Signification dans votre langue (séparée par virgule): ",
        "Prononciation (optionnel): "
    },

    // Russian (7)
    {
        "Файл: ",
        " (",
        " слов) ---",
        "Команды: 'exit'(сохранить и выйти),'save'(сохранить и продолжить),'back'(назад)",
        "Слово/фраза на изучаемом языке: ",
        "Значение на родном языке (через запятую): ",
        "Произношение (опционально): "
    },

    // Ukrainian (8)
    {
        "Файл: ",
        " (",
        " слів) ---",
        "Команди: 'exit'(зберегти і вийти),'save'(зберегти і продовжити),'back'(назад)",
        "Слово/фраза мовою навчання: ",
        "Значення рідною мовою (через кому): ",
        "Вимова (опційно): "
    },

    // Korean (9)
    {
        "파일: ",
        " (",
        " 단어 수) ---",
        "명령어: 'exit'(저장 후 종료),'save'(저장 후 계속),'back'(되돌리기)",
        "학습 언어 단어/문장: ",
        "모국어 의미 (쉼표로 구분): ",
        "발음 (선택): "
    },

    // Italian (10)
    {
        "File: ",
        " (",
        " parole finora) ---",
        "Comandi: 'exit'(salva e esci),'save'(salva e continua),'back'(indietro)",
        "Parola/frase lingua studio: ",
        "Significato lingua madre (separato da virgole): ",
        "Pronuncia (opzionale): "
    },

    // Polish (11)
    {
        "Plik: ",
        " (",
        " słów) ---",
        "Komendy: 'exit'(zapisz i wyjdź),'save'(zapisz i kontynuuj),'back'(cofnij)",
        "Słowo/zdanie w języku nauki: ",
        "Znaczenie w języku ojczystym (oddzielone przecinkiem): ",
        "Wymowa (opcjonalnie): "
    },

    // Arabic (12)
    {
        "ملف: ",
        " (",
        " كلمات) ---",
        "أوامر: 'exit'(حفظ وخروج),'save'(حفظ ومتابعة),'back'(رجوع)",
        "الكلمة/الجملة بلغة التعلم: ",
        "المعنى باللغة الأم (مفصول بفواصل): ",
        "النطق (اختياري): "
    },

    // Vietnamese (13)
    {
        "Tệp: ",
        " (",
        " từ) ---",
        "Lệnh: 'exit'(lưu & thoát),'save'(lưu & tiếp),'back'(quay lại)",
        "Từ/câu ngôn ngữ học: ",
        "Nghĩa tiếng mẹ đẻ (phân cách dấu phẩy): ",
        "Phát âm (tùy chọn): "
    },

    // Tagalog (14)
    {
        "File: ",
        " (",
        " salita) ---",
        "Mga utos: 'exit'(save at labas),'save'(save at tuloy),'back'(balik)",
        "Salita/pangungusap sa learning language: ",
        "Kahulugan sa native language (comma separated): ",
        "Bigkas (optional): "
    },

    // Greek (15)
    {
        "Αρχείο: ",
        " (",
        " λέξεις) ---",
        "Εντολές: 'exit'(αποθήκευση & έξοδος),'save'(αποθήκευση & συνέχεια),'back'(πίσω)",
        "Λέξη/φράση στη γλώσσα εκμάθησης: ",
        "Σημασία στη μητρική (με κόμμα): ",
        "Προφορά (προαιρετικό): "
    },

    // Hebrew (16)
    {
        "קובץ: ",
        " (",
        " מילים) ---",
        "פקודות: 'exit'(שמור ויציאה),'save'(שמור והמשך),'back'(חזור)",
        "מילה/משפט בשפת הלמידה: ",
        "משמעות בשפת אם (מופרד בפסיקים): ",
        "הגייה (אופציונלי): "
    },

    // Portuguese (17)
    {
        "Arquivo: ",
        " (",
        " palavras) ---",
        "Comandos: 'exit'(salvar e sair),'save'(salvar e continuar),'back'(voltar)",
        "Palavra/frase idioma aprendizado: ",
        "Significado idioma nativo (separado por vírgula): ",
        "Pronúncia (opcional): "
    },

    // Farsi (18)
    {
        "فایل: ",
        " (",
        " کلمه) ---",
        "دستورات: 'exit'(ذخیره و خروج),'save'(ذخیره و ادامه),'back'(بازگشت)",
        "کلمه/جمله زبان یادگیری: ",
        "معنی زبان مادری (با ویرگول): ",
        "تلفظ (اختیاری): "
    },

    // Swedish (19)
    {
        "Fil: ",
        " (",
        " ord) ---",
        "Kommandon: 'exit'(spara & avsluta),'save'(spara & fortsätt),'back'(tillbaka)",
        "Ord/mening inlärningsspråk: ",
        "Betydelse modersmål (kommaseparerat): ",
        "Uttal (valfritt): "
    },

    // Dutch (20)
    {
        "Bestand: ",
        " (",
        " woorden) ---",
        "Commando's: 'exit'(opslaan & afsluiten),'save'(opslaan & doorgaan),'back'(terug)",
        "Woord/zin leertaal: ",
        "Betekenis moedertaal (komma gescheiden): ",
        "Uitspraak (optioneel): "
    },

    // Turkish (21)
    {
        "Dosya: ",
        " (",
        " kelime) ---",
        "Komutlar: 'exit'(kaydet & çık),'save'(kaydet & devam),'back'(geri)",
        "Öğrenilen dilde kelime/cümle: ",
        "Ana dil anlamı (virgülle ayır): ",
        "Telaffuz (opsiyonel): "
    },

    // Hindi (22)
    {
        "फ़ाइल: ",
        " (",
        " शब्द) ---",
        "कमांड: 'exit'(सेव और बाहर),'save'(सेव और जारी),'back'(वापस)",
        "सीखने वाली भाषा में शब्द/वाक्य: ",
        "मातृभाषा में अर्थ (कॉमा से अलग): ",
        "उच्चारण (वैकल्पिक): "
    },

    // Latin (23)
    {
        "Fasciculus: ",
        " (",
        " verba) ---",
        "Mandata: 'exit'(serva et exi),'save'(serva et continua),'back'(redi)",
        "Verbum/sententia lingua discenda: ",
        "Significatio lingua materna (commis separata): ",
        "Pronuntiatio (optionalis): "
    }

};


//==========================================================================
static const std::vector<VocabMenu> vocabMenuTranslations_hardcoded = {
    // HUNGARIAN (Index 0)
    {
        "FIGYELEM: Ez a fájl már létezik és ",
        " szópárt tartalmaz.",
        "1. Hozzáfűzés",
        "2. Felülírás",
        "3. Mégsem",
        "Választás: ",
        "Hiba: csak 1-3 közötti számot adj meg!",
        "Hiba: Csak számot adj meg!"
    },

    // ENGLISH (Index 1)
    {
        "WARNING: This file already exists and contains ",
        " word pairs.",
        "1. Append",
        "2. Overwrite",
        "3. Cancel",
        "Choice: ",
        "Error: Enter only numbers between 1-3!",
        "Error: Enter only numbers!"
    },

    // CHINESE (Index 2)
    {
        "警告：该文件已存在，并包含 ",
        " 个词对。",
        "1. 追加",
        "2. 覆盖",
        "3. 取消",
        "选择: ",
        "错误：请输入1到3之间的数字！",
        "错误：请输入数字！"
    },

    // JAPANESE (Index 3)
    {
        "警告：このファイルは既に存在し、",
        " 個の単語ペアがあります。",
        "1. 追加",
        "2. 上書き",
        "3. キャンセル",
        "選択: ",
        "エラー：1〜3の数字のみ入力してください！",
        "エラー：数字のみ入力してください！"
    },

    // SPANISH (Index 4)
{
    "ADVERTENCIA: Este archivo ya existe y contiene ",
    " pares de palabras.",
    "1. Añadir",
    "2. Sobrescribir",
    "3. Cancelar",
    "Opción: ",
    "Error: ¡Introduce solo números entre 1-3!",
    "Error: ¡Introduce solo números!"
},

// GERMAN (Index 5)
{
    "WARNUNG: Diese Datei existiert bereits und enthält ",
    " Wortpaare.",
    "1. Anhängen",
    "2. Überschreiben",
    "3. Abbrechen",
    "Auswahl: ",
    "Fehler: Nur Zahlen zwischen 1-3 eingeben!",
    "Fehler: Nur Zahlen eingeben!"
},

// FRENCH (Index 6)
{
    "ATTENTION : Ce fichier existe déjà et contient ",
    " paires de mots.",
    "1. Ajouter",
    "2. Écraser",
    "3. Annuler",
    "Choix : ",
    "Erreur : Entrez uniquement des nombres entre 1-3 !",
    "Erreur : Entrez uniquement des nombres !"
},

// RUSSIAN (Index 7)
{
    "ВНИМАНИЕ: Этот файл уже существует и содержит ",
    " пар слов.",
    "1. Добавить",
    "2. Перезаписать",
    "3. Отмена",
    "Выбор: ",
    "Ошибка: Введите число от 1 до 3!",
    "Ошибка: Введите только числа!"
},

// UKRAINIAN (Index 8)
{
    "УВАГА: Цей файл вже існує і містить ",
    " пар слів.",
    "1. Додати",
    "2. Перезаписати",
    "3. Скасувати",
    "Вибір: ",
    "Помилка: Введіть число від 1 до 3!",
    "Помилка: Вводьте лише числа!"
},

// KOREAN (Index 9)
{
    "경고: 이 파일은 이미 존재하며 ",
    " 개의 단어 쌍이 있습니다.",
    "1. 추가",
    "2. 덮어쓰기",
    "3. 취소",
    "선택: ",
    "오류: 1에서 3 사이의 숫자만 입력하세요!",
    "오류: 숫자만 입력하세요!"
},

// ITALIAN (Index 10)
{
    "ATTENZIONE: Questo file esiste già e contiene ",
    " coppie di parole.",
    "1. Aggiungi",
    "2. Sovrascrivi",
    "3. Annulla",
    "Scelta: ",
    "Errore: Inserisci solo numeri tra 1-3!",
    "Errore: Inserisci solo numeri!"
},

// POLISH (Index 11)
{
    "UWAGA: Ten plik już istnieje i zawiera ",
    " par słów.",
    "1. Dodaj",
    "2. Nadpisz",
    "3. Anuluj",
    "Wybór: ",
    "Błąd: Podaj liczbę od 1 do 3!",
    "Błąd: Podaj tylko liczby!"
},

// ARABIC (Index 12)
{
    "تحذير: هذا الملف موجود بالفعل ويحتوي على ",
    " أزواج كلمات.",
    "1. إضافة",
    "2. استبدال",
    "3. إلغاء",
    "اختيار: ",
    "خطأ: أدخل رقمًا بين 1 و3 فقط!",
    "خطأ: أدخل أرقامًا فقط!"
},

// VIETNAMESE (Index 13)
{
    "CẢNH BÁO: Tệp này đã tồn tại và chứa ",
    " cặp từ.",
    "1. Thêm",
    "2. Ghi đè",
    "3. Hủy",
    "Lựa chọn: ",
    "Lỗi: Chỉ nhập số từ 1-3!",
    "Lỗi: Chỉ nhập số!"
},

// TAGALOG (Index 14)
{
    "BABALA: Ang file na ito ay umiiral na at may ",
    " pares ng salita.",
    "1. Idagdag",
    "2. I-overwrite",
    "3. Kanselahin",
    "Piliin: ",
    "Error: Maglagay lamang ng numero 1-3!",
    "Error: Numero lamang ang ilagay!"
},

// GREEK (Index 15)
{
    "ΠΡΟΕΙΔΟΠΟΙΗΣΗ: Αυτό το αρχείο υπάρχει ήδη και περιέχει ",
    " ζεύγη λέξεων.",
    "1. Προσθήκη",
    "2. Αντικατάσταση",
    "3. Ακύρωση",
    "Επιλογή: ",
    "Σφάλμα: Εισάγετε αριθμό από 1 έως 3!",
    "Σφάλμα: Εισάγετε μόνο αριθμούς!"
},

// HEBREW (Index 16)
{
    "אזהרה: קובץ זה כבר קיים ומכיל ",
    " זוגות מילים.",
    "1. הוסף",
    "2. דרוס",
    "3. בטל",
    "בחירה: ",
    "שגיאה: הזן מספר בין 1 ל-3 בלבד!",
    "שגיאה: הזן מספרים בלבד!"
},

// PORTUGUESE (Index 17)
{
    "AVISO: Este arquivo já existe e contém ",
    " pares de palavras.",
    "1. Adicionar",
    "2. Sobrescrever",
    "3. Cancelar",
    "Escolha: ",
    "Erro: Digite apenas números entre 1-3!",
    "Erro: Digite apenas números!"
},

// FARSI (Index 18)
{
    "هشدار: این فایل از قبل وجود دارد و شامل ",
    " جفت کلمه است.",
    "1. افزودن",
    "2. بازنویسی",
    "3. لغو",
    "انتخاب: ",
    "خطا: فقط عدد بین 1 تا 3 وارد کنید!",
    "خطا: فقط عدد وارد کنید!"
},

// SWEDISH (Index 19)
{
    "VARNING: Denna fil finns redan och innehåller ",
    " ordpar.",
    "1. Lägg till",
    "2. Skriv över",
    "3. Avbryt",
    "Val: ",
    "Fel: Ange endast siffror mellan 1-3!",
    "Fel: Ange endast siffror!"
},

// DUTCH (Index 20)
{
    "WAARSCHUWING: Dit bestand bestaat al en bevat ",
    " woordparen.",
    "1. Toevoegen",
    "2. Overschrijven",
    "3. Annuleren",
    "Keuze: ",
    "Fout: Voer alleen cijfers tussen 1-3 in!",
    "Fout: Voer alleen cijfers in!"
},

// TURKISH (Index 21)
{
    "UYARI: Bu dosya zaten mevcut ve ",
    " kelime çifti içeriyor.",
    "1. Ekle",
    "2. Üzerine yaz",
    "3. İptal",
    "Seçim: ",
    "Hata: Sadece 1-3 arası sayı girin!",
    "Hata: Sadece sayı girin!"
},

// HINDI (Index 22)
{
    "चेतावनी: यह फ़ाइल पहले से मौजूद है और इसमें ",
    " शब्द जोड़े हैं।",
    "1. जोड़ें",
    "2. ओवरराइट",
    "3. रद्द करें",
    "चयन: ",
    "त्रुटि: केवल 1-3 के बीच संख्या दर्ज करें!",
    "त्रुटि: केवल संख्या दर्ज करें!"
},

// LATIN (Index 23)
{
    "MONITUM: Hic fasciculus iam existit et continet ",
    " paria verborum.",
    "1. Adde",
    "2. Rescribe",
    "3. Cancella",
    "Electio: ",
    "Error: Inseras solum numeros inter 1-3!",
    "Error: Inseras solum numeros!"
}
};


//==========================================================================
static const std::vector<SettingsMenu> settingsMenuTranslations_hardcoded {
// const std::vector<SettingsMenu> settingsMenuTranslations {

    // Hungarian (0)
    {
        "================BEÁLLÍTÁSOK-MENU================",
        "Kérlek válassz az alábbi menüpontok közül:",
        "1. Nyelv beállítása",
        "2. A tanulandó nyelv beállítása",
        "3. Színek beállítása",
        "4. Beep hang be/ki",
        "5. Ékezetek figyelmen kívül hagyása be/ki",
        "6. Egy körös kvíz be/ki",
        "7. INI fájlok beállítása be/ki",
        "0. Visszalépés a főmenübe",
        "================================================"
    },

    // English (1)
    {
        "================SETTINGS MENU================",
        "Please choose from the options below:",
        "1. Set language",
        "2. Set learning language",
        "3. Set colors",
        "4. Beep sound on/off",
        "5. Ignore accents on/off",
        "6. One round quiz on/off",
        "7. INI files on/off",
        "0. Back to main menu",
        "============================================="
    },

    // Chinese (2)
    {
        "================设置菜单================",
        "请选择以下选项:",
        "1. 设置语言",
        "2. 设置学习语言",
        "3. 设置颜色",
        "4. 蜂鸣声 开/关",
        "5. 忽略重音 开/关",
        "6. 单轮测验 开/关",
        "7. INI 文件 开/关",
        "0. 返回主菜单",
        "========================================"
    },

    // Japanese (3)
    {
        "================設定メニュー================",
        "以下の項目を選択してください:",
        "1. 言語設定",
        "2. 学習言語設定",
        "3. 色設定",
        "4. ビープ音 オン/オフ",
        "5. アクセント無視 オン/オフ",
        "6. 1ラウンドクイズ オン/オフ",
        "7. INIファイル オン/オフ",
        "0. メインメニューへ戻る",
        "=========================================="
    },

    // Spanish (4)
    {
        "================MENÚ DE CONFIGURACIÓN================",
        "Por favor elige una opción:",
        "1. Configurar idioma",
        "2. Configurar idioma de aprendizaje",
        "3. Configurar colores",
        "4. Sonido beep encendido/apagado",
        "5. Ignorar acentos encendido/apagado",
        "6. Quiz de una ronda encendido/apagado",
        "7. Archivos INI encendido/apagado",
        "0. Volver al menú principal",
        "===================================================="
    },

    // German (5)
    {
        "================EINSTELLUNGSMENÜ================",
        "Bitte wählen Sie eine Option:",
        "1. Sprache einstellen",
        "2. Lernsprache einstellen",
        "3. Farben einstellen",
        "4. Beep-Ton ein/aus",
        "5. Akzente ignorieren ein/aus",
        "6. Ein-Runden-Quiz ein/aus",
        "7. INI-Dateien ein/aus",
        "0. Zurück zum Hauptmenü",
        "================================================"
    },

    // French (6)
    {
        "================MENU PARAMÈTRES================",
        "Veuillez choisir une option:",
        "1. Définir la langue",
        "2. Définir la langue d'apprentissage",
        "3. Définir les couleurs",
        "4. Son beep activé/désactivé",
        "5. Ignorer les accents activé/désactivé",
        "6. Quiz un tour activé/désactivé",
        "7. Fichiers INI activé/désactivé",
        "0. Retour au menu principal",
        "==============================================="
    },

    // Russian (7)
    {
        "================МЕНЮ НАСТРОЕК================",
        "Пожалуйста выберите пункт:",
        "1. Настройка языка",
        "2. Настройка изучаемого языка",
        "3. Настройка цветов",
        "4. Звук beep вкл/выкл",
        "5. Игнорировать акценты вкл/выкл",
        "6. Однораундовый тест вкл/выкл",
        "7. INI файлы вкл/выкл",
        "0. Назад в главное меню",
        "============================================="
    },

    // Ukrainian (8)
    {
        "================МЕНЮ НАЛАШТУВАНЬ================",
        "Будь ласка виберіть пункт:",
        "1. Налаштування мови",
        "2. Налаштування мови навчання",
        "3. Налаштування кольорів",
        "4. Звук beep увімк/вимк",
        "5. Ігнорувати акценти увімк/вимк",
        "6. Однораундовий тест увімк/вимк",
        "7. INI файли увімк/вимк",
        "0. Назад до головного меню",
        "================================================"
    },

    // Korean (9)
    {
        "================설정 메뉴================",
        "옵션을 선택하세요:",
        "1. 언어 설정",
        "2. 학습 언어 설정",
        "3. 색상 설정",
        "4. 비프음 켜기/끄기",
        "5. 악센트 무시 켜기/끄기",
        "6. 한 라운드 퀴즈 켜기/끄기",
        "7. INI 파일 켜기/끄기",
        "0. 메인 메뉴로 돌아가기",
        "========================================"
    },

    // Italian (10)
    {
        "================MENU IMPOSTAZIONI================",
        "Seleziona un'opzione:",
        "1. Imposta lingua",
        "2. Imposta lingua di apprendimento",
        "3. Imposta colori",
        "4. Suono beep on/off",
        "5. Ignora accenti on/off",
        "6. Quiz a un round on/off",
        "7. File INI on/off",
        "0. Torna al menu principale",
        "================================================="
    },

    // Polish (11)
    {
        "================MENU USTAWIEŃ================",
        "Wybierz opcję:",
        "1. Ustaw język",
        "2. Ustaw język nauki",
        "3. Ustaw kolory",
        "4. Dźwięk beep włącz/wyłącz",
        "5. Ignorowanie akcentów włącz/wyłącz",
        "6. Quiz jednej rundy włącz/wyłącz",
        "7. Pliki INI włącz/wyłącz",
        "0. Powrót do menu głównego",
        "============================================="
    },

    // Arabic (12)
    {
        "================قائمة الإعدادات================",
        "يرجى اختيار أحد الخيارات:",
        "1. إعداد اللغة",
        "2. إعداد لغة التعلم",
        "3. إعداد الألوان",
        "4. صوت beep تشغيل/إيقاف",
        "5. تجاهل العلامات تشغيل/إيقاف",
        "6. اختبار جولة واحدة تشغيل/إيقاف",
        "7. ملفات INI تشغيل/إيقاف",
        "0. العودة إلى القائمة الرئيسية",
        "============================================"
    },

    // Vietnamese (13)
    {
        "================MENU CÀI ĐẶT================",
        "Vui lòng chọn một mục:",
        "1. Cài đặt ngôn ngữ",
        "2. Cài đặt ngôn ngữ học",
        "3. Cài đặt màu sắc",
        "4. Âm beep bật/tắt",
        "5. Bỏ qua dấu bật/tắt",
        "6. Quiz một vòng bật/tắt",
        "7. File INI bật/tắt",
        "0. Quay lại menu chính",
        "==========================================="
    },

    // Tagalog (14)
    {
        "================SETTINGS MENU================",
        "Pumili ng opsyon:",
        "1. Itakda ang wika",
        "2. Itakda ang wikang pag-aaralan",
        "3. Itakda ang kulay",
        "4. Beep sound on/off",
        "5. Ignore accents on/off",
        "6. One round quiz on/off",
        "7. INI files on/off",
        "0. Bumalik sa main menu",
        "=========================================="
    },

    // Greek (15)
    {
        "================ΜΕΝΟΥ ΡΥΘΜΙΣΕΩΝ================",
        "Παρακαλώ επιλέξτε:",
        "1. Ρύθμιση γλώσσας",
        "2. Ρύθμιση γλώσσας εκμάθησης",
        "3. Ρύθμιση χρωμάτων",
        "4. Ήχος beep on/off",
        "5. Αγνόηση τόνων on/off",
        "6. Quiz ενός γύρου on/off",
        "7. Αρχεία INI on/off",
        "0. Επιστροφή στο κύριο μενού",
        "================================================"
    },

    // Hebrew (16)
    {
        "================תפריט הגדרות================",
        "אנא בחר אפשרות:",
        "1. הגדרת שפה",
        "2. הגדרת שפת לימוד",
        "3. הגדרת צבעים",
        "4. צליל beep הפעלה/כיבוי",
        "5. התעלמות מניקוד הפעלה/כיבוי",
        "6. מבחן סבב אחד הפעלה/כיבוי",
        "7. קבצי INI הפעלה/כיבוי",
        "0. חזרה לתפריט הראשי",
        "==========================================="
    },

    // Portuguese (17)
    {
        "================MENU DE CONFIGURAÇÕES================",
        "Por favor escolha uma opção:",
        "1. Definir idioma",
        "2. Definir idioma de aprendizagem",
        "3. Definir cores",
        "4. Som beep ligado/desligado",
        "5. Ignorar acentos ligado/desligado",
        "6. Quiz de uma rodada ligado/desligado",
        "7. Arquivos INI ligado/desligado",
        "0. Voltar ao menu principal",
        "====================================================="
    },

    // Farsi (18)
    {
        "================منوی تنظیمات================",
        "لطفاً یکی از گزینه‌های زیر را انتخاب کنید:",
        "1. تنظیم زبان",
        "2. تنظیم زبان یادگیری",
        "3. تنظیم رنگ‌ها",
        "4. صدای beep روشن/خاموش",
        "5. نادیده گرفتن اعراب روشن/خاموش",
        "6. آزمون یک دور روشن/خاموش",
        "7. فایل‌های INI روشن/خاموش",
        "0. بازگشت به منوی اصلی",
        "=========================================="
    },

    // Swedish (19)
    {
        "================INSTÄLLNINGSMENY================",
        "Vänligen välj ett alternativ:",
        "1. Ställ in språk",
        "2. Ställ in inlärningsspråk",
        "3. Ställ in färger",
        "4. Beep-ljud på/av",
        "5. Ignorera accenter på/av",
        "6. En-runds quiz på/av",
        "7. INI-filer på/av",
        "0. Tillbaka till huvudmenyn",
        "================================================"
    },

    // Dutch (20)
    {
        "================INSTELLINGEN MENU================",
        "Kies een optie:",
        "1. Taal instellen",
        "2. Leertaal instellen",
        "3. Kleuren instellen",
        "4. Beep-geluid aan/uit",
        "5. Accenten negeren aan/uit",
        "6. Eén ronde quiz aan/uit",
        "7. INI-bestanden aan/uit",
        "0. Terug naar hoofdmenu",
        "================================================"
    },

    // Turkish (21)
    {
        "================AYARLAR MENÜSÜ================",
        "Lütfen aşağıdaki seçeneklerden birini seçin:",
        "1. Dil ayarla",
        "2. Öğrenme dili ayarla",
        "3. Renkleri ayarla",
        "4. Beep sesi aç/kapat",
        "5. Aksanları yok say aç/kapat",
        "6. Tek turlu quiz aç/kapat",
        "7. INI dosyaları aç/kapat",
        "0. Ana menüye dön",
        "=============================================="
    },

    // Hindi (22)
    {
        "================सेटिंग्स मेनू================",
        "कृपया नीचे दिए गए विकल्पों में से चुनें:",
        "1. भाषा सेट करें",
        "2. सीखने की भाषा सेट करें",
        "3. रंग सेट करें",
        "4. बीप ध्वनि चालू/बंद",
        "5. उच्चारण अनदेखा चालू/बंद",
        "6. एक राउंड क्विज चालू/बंद",
        "7. INI फाइलें चालू/बंद",
        "0. मुख्य मेनू पर वापस जाएँ",
        "==========================================="
    },

    // Latin (23)
    {
        "================MENU OPTIONUM================",
        "Quaeso optionem elige:",
        "1. Linguam configura",
        "2. Linguam discendam configura",
        "3. Colores configura",
        "4. Sonus beep activus/inactivus",
        "5. Accentus ignorare activus/inactivus",
        "6. Quiz unius rotationis activus/inactivus",
        "7. Limae INI activae/inactivae",
        "0. Redire ad menu principale",
        "============================================"
    }

};


//==========================================================================
static const std::vector<LanguageMenu> languageMenuTranslations_hardcoded {


    { // Hungarian (Index 0)
        "============NYELV_VÁLASZTÁSI_MENU============",
        "0. Visszalépés a beállításokba",
        "Kérlek válaszd ki a program nyelvét: ",
        "==============================================",
        "A nyelv sikeresen megváltoztatva"
    },

    // ENGLISH (Index 1)
    {
        "============LANGUAGE_SELECTION_MENU============",
        "0. Return to settings",
        "Please select the program language: ",
        "==============================================",
        "Language successfully changed"
    },

    // CHINESE (Index 2)
    {
        "============语言选择菜单============",
        "0. 返回设置",
        "请选择程序语言：",
        "==============================================",
        "语言修改成功"
    },

    // JAPANESE (Index 3)
    {
        "============言語選択メニュー============",
        "0. 設定に戻る",
        "プログラムの言語を選択してください：",
        "==============================================",
        "言語が正常に変更されました"
    },

    // SPANISH (Index 4)
    {
        "============MENÚ DE SELECCIÓN DE IDIOMA============",
        "0. Volver a configuración",
        "Por favor selecciona el idioma del programa: ",
        "==============================================",
        "Idioma cambiado correctamente"
    },

    // GERMAN (Index 5)
    {
        "============SPRACHAUSWAHLMENÜ============",
        "0. Zurück zu den Einstellungen",
        "Bitte wählen Sie die Programmsprache: ",
        "==============================================",
        "Sprache erfolgreich geändert"
    },

    // FRENCH (Index 6)
    {
        "============MENU DE SÉLECTION DE LANGUE============",
        "0. Retour aux paramètres",
        "Veuillez sélectionner la langue du programme : ",
        "==============================================",
        "Langue modifiée avec succès"
    },

    // RUSSIAN (Index 7)
    {
        "============МЕНЮ ВЫБОРА ЯЗЫКА============",
        "0. Вернуться в настройки",
        "Пожалуйста, выберите язык программы: ",
        "==============================================",
        "Язык успешно изменён"
    },

    // UKRAINIAN (Index 8)
    {
        "============МЕНЮ ВИБОРУ МОВИ============",
        "0. Повернутися до налаштувань",
        "Будь ласка, оберіть мову програми: ",
        "==============================================",
        "Мову успішно змінено"
    },

    // KOREAN (Index 9)
    {
        "============언어 선택 메뉴============",
        "0. 설정으로 돌아가기",
        "프로그램 언어를 선택하세요: ",
        "==============================================",
        "언어가 성공적으로 변경되었습니다"
    },

    // ITALIAN (Index 10)
    {
        "============MENU SELEZIONE LINGUA============",
        "0. Torna alle impostazioni",
        "Seleziona la lingua del programma: ",
        "==============================================",
        "Lingua modificata con successo"
    },

    // POLISH (Index 11)
    {
        "============MENU WYBORU JĘZYKA============",
        "0. Powrót do ustawień",
        "Wybierz język programu: ",
        "==============================================",
        "Język został zmieniony"
    },

    // ARABIC (Index 12)
    {
        "============قائمة اختيار اللغة============",
        "0. العودة إلى الإعدادات",
        "يرجى اختيار لغة البرنامج: ",
        "==============================================",
        "تم تغيير اللغة بنجاح"
    },

    // VIETNAMESE (Index 13)
    {
        "============MENU CHỌN NGÔN NGỮ============",
        "0. Quay lại cài đặt",
        "Vui lòng chọn ngôn ngữ chương trình: ",
        "==============================================",
        "Đã thay đổi ngôn ngữ thành công"
    },

    // TAGALOG (Index 14)
    {
        "============MENU NG PAGPILI NG WIKA============",
        "0. Bumalik sa settings",
        "Pumili ng wika ng programa: ",
        "==============================================",
        "Matagumpay na napalitan ang wika"
    },

    // GREEK (Index 15)
    {
        "============ΜΕΝΟΥ ΕΠΙΛΟΓΗΣ ΓΛΩΣΣΑΣ============",
        "0. Επιστροφή στις ρυθμίσεις",
        "Παρακαλώ επιλέξτε τη γλώσσα του προγράμματος: ",
        "==============================================",
        "Η γλώσσα άλλαξε επιτυχώς"
    },

    // HEBREW (Index 16)
    {
        "============תפריט בחירת שפה============",
        "0. חזרה להגדרות",
        "בחר את שפת התוכנית: ",
        "==============================================",
        "השפה שונתה בהצלחה"
    },

    // PORTUGUESE (Index 17)
    {
        "============MENU DE SELEÇÃO DE IDIOMA============",
        "0. Voltar para configurações",
        "Selecione o idioma do programa: ",
        "==============================================",
        "Idioma alterado com sucesso"
    },

    // FARSI (Index 18)
    {
        "============منوی انتخاب زبان============",
        "0. بازگشت به تنظیمات",
        "لطفاً زبان برنامه را انتخاب کنید: ",
        "==============================================",
        "زبان با موفقیت تغییر یافت"
    },

    // SWEDISH (Index 19)
    {
        "============SPRÅKVALSMENY============",
        "0. Tillbaka till inställningar",
        "Välj programspråk: ",
        "==============================================",
        "Språket ändrades framgångsrikt"
    },

    // DUTCH (Index 20)
    {
        "============TAALSELECTIEMENU============",
        "0. Terug naar instellingen",
        "Selecteer de programmat taal: ",
        "==============================================",
        "Taal succesvol gewijzigd"
    },

    // TURKISH (Index 21)
    {
        "============DİL SEÇİM MENÜSÜ============",
        "0. Ayarlara geri dön",
        "Program dilini seçin: ",
        "==============================================",
        "Dil başarıyla değiştirildi"
    },

    // HINDI (Index 22)
    {
        "============भाषा चयन मेनू============",
        "0. सेटिंग्स पर वापस जाएँ",
        "कृपया प्रोग्राम की भाषा चुनें: ",
        "==============================================",
        "भाषा सफलतापूर्वक बदली गई"
    },

    // LATIN (Index 23)
    {
        "============MENU LINGUAE SELECTIONIS============",
        "0. Redire ad configurationes",
        "Elige linguam programmatis: ",
        "==============================================",
        "Lingua feliciter mutata est"
    }
};


//==========================================================================
static const std::vector<ColorsOnset> colorsOSetTranslations_hardcoded {


    { // Hungarian (Index 0)
        "========A SZÍNEK BEÁLLÍTÁSA=========",
        "Jelenlegi állapot: ",
        "BE",
        "KI",
        "1. Be/ki kapcsolás...",
        "2. Háttérszín beállítása",
        "0. Vissza",
        "választás: ",
        "Színek bekapcsolva...",
        "Színek kikapcsolva...",
"Kérlek a háttér megváltoztatásához először engedélyezd a színeket!"
    },

    // ENGLISH (Index 1)
    {
        "========COLOR SETTINGS=========",
        "Current state: ",
        "ON",
        "OFF",
        "1. Toggle on/off...",
        "2. Set background color",
        "0. Back",
        "Choice: ",
        "Colors enabled...",
        "Colors disabled...",
        "Please enable colors first to change the background!"
    },

    // CHINESE (Index 2)
    {
        "========颜色设置=========",
        "当前状态：",
        "开",
        "关",
        "1. 开/关 切换...",
        "2. 设置背景颜色",
        "0. 返回",
        "选择: ",
        "颜色已开启...",
        "颜色已关闭...",
        "请先启用颜色以更改背景！"
    },

    // JAPANESE (Index 3)
    {
        "========カラー設定=========",
        "現在の状態：",
        "オン",
        "オフ",
        "1. オン/オフ切り替え...",
        "2. 背景色の設定",
        "0. 戻る",
        "選択：",
        "カラーが有効になりました...",
        "カラーが無効になりました...",
        "背景を変更するには、まず色を有効にしてください！"
    },

    // SPANISH (Index 4)
    {
        "========CONFIGURACIÓN DE COLORES=========",
        "Estado actual: ",
        "ENCENDIDO",
        "APAGADO",
        "1. Activar/desactivar...",
        "2. Configurar color de fondo",
        "0. Volver",
        "Opción: ",
        "Colores activados...",
        "Colores desactivados...",
        "¡Por favor, activa los colores primero para cambiar el fondo!"
    },

    // GERMAN (Index 5)
    {
        "========FARBEINSTELLUNGEN=========",
        "Aktueller Status: ",
        "AN",
        "AUS",
        "1. Ein/Aus umschalten...",
        "2. Hintergrundfarbe einstellen",
        "0. Zurück",
        "Auswahl: ",
        "Farben aktiviert...",
        "Farben deaktiviert...",
        "Bitte aktiviere zuerst die Farben, um den Hintergrund zu ändern!"
    },

    // FRENCH (Index 6)
    {
        "========PARAMÈTRES DE COULEUR=========",
        "État actuel : ",
        "ACTIVÉ",
        "DÉSACTIVÉ",
        "1. Activer/désactiver...",
        "2. Définir la couleur de fond",
        "0. Retour",
        "Choix : ",
        "Couleurs activées...",
        "Couleurs désactivées...",
        "Veuillez d'abord activer les couleurs pour changer l'arrière-plan !"
    },

    // RUSSIAN (Index 7)
    {
        "========НАСТРОЙКИ ЦВЕТА=========",
        "Текущее состояние: ",
        "ВКЛ",
        "ВЫКЛ",
        "1. Вкл/выкл...",
        "2. Установить цвет фона",
        "0. Назад",
        "Выбор: ",
        "Цвета включены...",
        "Цвета выключены...",
        "Пожалуйста, сначала включите цвета, чтобы изменить фон!"
    },

    // UKRAINIAN (Index 8)
    {
        "========НАЛАШТУВАННЯ КОЛЬОРІВ=========",
        "Поточний стан: ",
        "УВІМК",
        "ВИМК",
        "1. Увімк/вимк...",
        "2. Встановити колір фону",
        "0. Назад",
        "Вибір: ",
        "Кольори увімкнено...",
        "Кольори вимкнено...",
        "Будь ласка, спочатку увімкніть кольори, щоб змінити фон!"
    },

    // KOREAN (Index 9)
    {
        "========색상 설정=========",
        "현재 상태: ",
        "켜짐",
        "꺼짐",
        "1. 켜기/끄기 전환...",
        "2. 배경 색상 설정",
        "0. 뒤로",
        "선택: ",
        "색상이 활성화되었습니다...",
        "색상이 비활성화되었습니다...",
        "배경을 변경하려면 먼저 색상을 활성화하세요!"
    },

    // ITALIAN (Index 10)
    {
        "========IMPOSTAZIONI COLORE=========",
        "Stato attuale: ",
        "ON",
        "OFF",
        "1. Attiva/disattiva...",
        "2. Imposta colore di sfondo",
        "0. Indietro",
        "Scelta: ",
        "Colori attivati...",
        "Colori disattivati...",
        "Per favore, attiva prima i colori per cambiare lo sfondo!"
    },

    // POLISH (Index 11)
    {
        "========USTAWIENIA KOLORÓW=========",
        "Aktualny stan: ",
        "WŁ",
        "WYŁ",
        "1. Włącz/wyłącz...",
        "2. Ustaw kolor tła",
        "0. Powrót",
        "Wybór: ",
        "Kolory włączone...",
        "Kolory wyłączone...",
        "Najpierw włącz kolory, aby zmienić tło!"
    },

    // ARABIC (Index 12)
    {
        "========إعدادات الألوان=========",
        "الحالة الحالية: ",
        "تشغيل",
        "إيقاف",
        "1. تشغيل/إيقاف...",
        "2. تعيين لون الخلفية",
        "0. رجوع",
        "اختيار: ",
        "تم تفعيل الألوان...",
        "تم إيقاف الألوان...",
        "يرجى تفعيل الألوان أولاً لتغيير الخلفية!"
    },

    // VIETNAMESE (Index 13)
    {
        "========CÀI ĐẶT MÀU SẮC=========",
        "Trạng thái hiện tại: ",
        "BẬT",
        "TẮT",
        "1. Bật/tắt...",
        "2. Cài đặt màu nền",
        "0. Quay lại",
        "Lựa chọn: ",
        "Đã bật màu sắc...",
        "Đã tắt màu sắc...",
        "Vui lòng bật màu trước để thay đổi nền!"
    },

    // TAGALOG (Index 14)
    {
        "========SETTING NG KULAY=========",
        "Kasalukuyang estado: ",
        "BUKAS",
        "SARADO",
        "1. I-on/i-off...",
        "2. Itakda ang kulay ng background",
        "0. Bumalik",
        "Piliin: ",
        "Naka-on ang mga kulay...",
        "Naka-off ang mga kulay...",
        "Paki-enable muna ang mga kulay bago baguhin ang background!"
    },

    // GREEK (Index 15)
    {
        "========ΡΥΘΜΙΣΕΙΣ ΧΡΩΜΑΤΩΝ=========",
        "Τρέχουσα κατάσταση: ",
        "ΕΝΕΡΓΟ",
        "ΑΝΕΝΕΡΓΟ",
        "1. Ενεργοποίηση/Απενεργοποίηση...",
        "2. Ορισμός χρώματος φόντου",
        "0. Πίσω",
        "Επιλογή: ",
        "Τα χρώματα ενεργοποιήθηκαν...",
        "Τα χρώματα απενεργοποιήθηκαν...",
        "Παρακαλώ ενεργοποιήστε πρώτα τα χρώματα για να αλλάξετε το φόντο!"
    },

    // HEBREW (Index 16)
    {
        "========הגדרות צבעים=========",
        "מצב נוכחי: ",
        "פועל",
        "כבוי",
        "1. הפעלה/כיבוי...",
        "2. הגדרת צבע רקע",
        "0. חזרה",
        "בחירה: ",
        "הצבעים הופעלו...",
        "הצבעים כובו...",
        "אנא הפעל קודם את הצבעים כדי לשנות את הרקע!"
    },

    // PORTUGUESE (Index 17)
    {
        "========CONFIGURAÇÕES DE CORES=========",
        "Estado atual: ",
        "LIGADO",
        "DESLIGADO",
        "1. Ativar/desativar...",
        "2. Definir cor de fundo",
        "0. Voltar",
        "Escolha: ",
        "Cores ativadas...",
        "Cores desativadas...",
        "Por favor, ative as cores primeiro para alterar o fundo!"
    },

    // FARSI (Index 18)
    {
        "========تنظیمات رنگ=========",
        "وضعیت فعلی: ",
        "روشن",
        "خاموش",
        "1. روشن/خاموش...",
        "2. تنظیم رنگ پس‌زمینه",
        "0. بازگشت",
        "انتخاب: ",
        "رنگ‌ها فعال شدند...",
        "رنگ‌ها غیرفعال شدند...",
        "لطفاً ابتدا رنگ‌ها را فعال کنید تا پس‌زمینه را تغییر دهید!"
    },

    // SWEDISH (Index 19)
    {
        "========FÄRGINSTÄLLNINGAR=========",
        "Nuvarande status: ",
        "PÅ",
        "AV",
        "1. Slå på/av...",
        "2. Ställ in bakgrundsfärg",
        "0. Tillbaka",
        "Val: ",
        "Färger aktiverade...",
        "Färger inaktiverade...",
        "Aktivera färger först för att ändra bakgrunden!"
    },

    // DUTCH (Index 20)
    {
        "========KLEURINSTELLINGEN=========",
        "Huidige status: ",
        "AAN",
        "UIT",
        "1. Aan/uit schakelen...",
        "2. Achtergrondkleur instellen",
        "0. Terug",
        "Keuze: ",
        "Kleuren ingeschakeld...",
        "Kleuren uitgeschakeld...",
        "Schakel eerst kleuren in om de achtergrond te wijzigen!"
    },

    // TURKISH (Index 21)
    {
        "========RENK AYARLARI=========",
        "Mevcut durum: ",
        "AÇIK",
        "KAPALI",
        "1. Aç/Kapat...",
        "2. Arka plan rengi ayarla",
        "0. Geri",
        "Seçim: ",
        "Renkler etkinleştirildi...",
        "Renkler devre dışı bırakıldı...",
        "Arka planı değiştirmek için önce renkleri etkinleştirin!"
    },

    // HINDI (Index 22)
    {
        "========रंग सेटिंग्स=========",
        "वर्तमान स्थिति: ",
        "चालू",
        "बंद",
        "1. चालू/बंद करें...",
        "2. पृष्ठभूमि रंग सेट करें",
        "0. वापस",
        "चयन: ",
        "रंग सक्षम किए गए...",
        "रंग अक्षम किए गए...",
        "पृष्ठभूमि बदलने के लिए पहले रंग सक्षम करें!"
    },

    // LATIN (Index 23)
    {
        "========CONFIGURATIONES COLORUM=========",
        "Status praesens: ",
        "ACTIVUM",
        "INACTIVUM",
        "1. Activa/deactiva...",
        "2. Colorem fundi define",
        "0. Redire",
        "Electio: ",
        "Colores activati sunt...",
        "Colores deactivati sunt...",
        "Quaeso colores primum activa ut fundum mutare possis!"
    }
};


//==========================================================================
static const std::vector<SaveSettings> saveSettingsTranslations_hardcoded {

    { // Hungarian (Index 0)
        "Hiba: Nem sikerült menteni a beállításokat!"
    },

    // ENGLISH (Index 1)
    {
        "Error: Unable to save settings!"
    },

    // CHINESE (Index 2)
    {
        "错误：无法保存设置！"
    },

    // JAPANESE (Index 3)
    {
        "エラー：設定を保存できません！"
    },

    // SPANISH (Index 4)
    {
        "Error: ¡No se pudieron guardar los ajustes!"
    },

    // GERMAN (Index 5)
    {
        "Fehler: Einstellungen konnten nicht gespeichert werden!"
    },

    // FRENCH (Index 6)
    {
        "Erreur : impossible d'enregistrer les paramètres !"
    },

    // RUSSIAN (Index 7)
    {
        "Ошибка: Не удалось сохранить настройки!"
    },

    // UKRAINIAN (Index 8)
    {
        "Помилка: Не вдалося зберегти налаштування!"
    },

    // KOREAN (Index 9)
    {
        "오류: 설정을 저장할 수 없습니다!"
    },

    // ITALIAN (Index 10)
    {
        "Errore: Impossibile salvare le impostazioni!"
    },

    // POLISH (Index 11)
    {
        "Błąd: Nie można zapisać ustawień!"
    },

    // ARABIC (Index 12)
    {
        "خطأ: لا يمكن حفظ الإعدادات!"
    },

    // VIETNAMESE (Index 13)
    {
        "Lỗi: Không thể lưu cài đặt!"
    },

    // TAGALOG (Index 14)
    {
        "Error: Hindi ma-save ang settings!"
    },

    // GREEK (Index 15)
    {
        "Σφάλμα: Αδυναμία αποθήκευσης ρυθμίσεων!"
    },

    // HEBREW (Index 16)
    {
        "שגיאה: לא ניתן לשמור את ההגדרות!"
    },

    // PORTUGUESE (Index 17)
    {
        "Erro: Não foi possível salvar as configurações!"
    },

    // FARSI (Index 18)
    {
        "خطا: امکان ذخیره تنظیمات وجود ندارد!"
    },

    // SWEDISH (Index 19)
    {
        "Fel: Kunde inte spara inställningarna!"
    },

    // DUTCH (Index 20)
    {
        "Fout: Kan instellingen niet opslaan!"
    },

    // TURKISH (Index 21)
    {
        "Hata: Ayarlar kaydedilemedi!"
    },

    // HINDI (Index 22)
    {
        "त्रुटि: सेटिंग्स सहेजी नहीं जा सकीं!"
    },

    // LATIN (Index 23)
    {
        "Error: Configurationes servari non potuerunt!"
    }
};

//==========================================================================
static const std::vector<LearningLanguageSet> learningLanguageSetTranslations_hardcoded {

    { // Hungarian (Index 0)
        "==== A tanulandó nyelv beállítása ====",
        "A jelenlegi anyanyelv: ",
        "A jelenlegi tanult nyelv: ",
        "1. Az anyanyelv módosítása",
        "2. A tanult nyelv módosítása",
        "0. Visszalépés a beállításokba",
        "Kérlek válaszd ki az anyanyelved: ",
        "Választás (1-24): ",
        "Az anyanyelv sikeresen beállítva!",
        "Kérlek válaszd ki a tanult nyelvet: ",
        "Tanult nyelv sikeresen beállítva!",
        "Választás: ",
        "0.- visszalépés -",
        "Hiba: Az anyanyelv és a tanult nyelv nem lehet ugyanaz!",
        "============= Menü =============="
    },

    // ENGLISH (Index 1)
    {
        "==== Set Learning Language ====",
        "Current native language: ",
        "Current learning language: ",
        "1. Change native language",
        "2. Change learning language",
        "0. Back to settings",
        "Please select your native language: ",
        "Choice (1-24): ",
        "Native language successfully set!",
        "Please select the learning language: ",
        "Learning language successfully set!",
        "Choice: ",
        "0. - back -",
        "Error: Native language and learning language cannot be the same!",
        "============= Menu =============="
    },

    // CHINESE (Index 2)
    {
        "==== 设置学习语言 ====",
        "当前母语：",
        "当前学习语言：",
        "1. 修改母语",
        "2. 修改学习语言",
        "0. 返回设置",
        "请选择你的母语：",
        "选择 (1-24)：",
        "母语设置成功！",
        "请选择学习语言：",
        "学习语言设置成功！",
        "选择：",
        "0. - 返回 -",
        "错误：母语和学习语言不能相同！",
        "============= 菜单 =============="
    },

    // JAPANESE (Index 3)
    {
        "==== 学習言語の設定 ====",
        "現在の母国語：",
        "現在の学習言語：",
        "1. 母国語を変更",
        "2. 学習言語を変更",
        "0. 設定に戻る",
        "母国語を選択してください：",
        "選択 (1-24)：",
        "母国語が設定されました！",
        "学習言語を選択してください：",
        "学習言語が設定されました！",
        "選択：",
        "0. - 戻る -",
        "エラー：母語と学習言語は同じにできません！",
        "============= メニュー =============="
    },

    // SPANISH (Index 4)
    {
        "==== Configurar idioma de aprendizaje ====",
        "Idioma nativo actual: ",
        "Idioma de aprendizaje actual: ",
        "1. Cambiar idioma nativo",
        "2. Cambiar idioma de aprendizaje",
        "0. Volver a configuración",
        "Por favor selecciona tu idioma nativo: ",
        "Elección (1-24): ",
        "¡Idioma nativo configurado correctamente!",
        "Por favor selecciona el idioma de aprendizaje: ",
        "¡Idioma de aprendizaje configurado correctamente!",
        "Opción: ",
        "0. - volver -",
        "Error: ¡El idioma nativo y el idioma de aprendizaje no pueden ser iguales!",
        "============= Menú =============="
    },

    // GERMAN (Index 5)
    {
        "==== Lernsprache einstellen ====",
        "Aktuelle Muttersprache: ",
        "Aktuelle Lernsprache: ",
        "1. Muttersprache ändern",
        "2. Lernsprache ändern",
        "0. Zurück zu den Einstellungen",
        "Bitte wählen Sie Ihre Muttersprache: ",
        "Auswahl (1-24): ",
        "Muttersprache erfolgreich eingestellt!",
        "Bitte wählen Sie die Lernsprache: ",
        "Lernsprache erfolgreich eingestellt!",
        "Auswahl: ",
        "0. - zurück -",
        "Fehler: Muttersprache und Lernsprache dürfen nicht gleich sein!",
        "============= Menü =============="
    },

    // FRENCH (Index 6)
    {
        "==== Définir la langue d'apprentissage ====",
        "Langue maternelle actuelle : ",
        "Langue d'apprentissage actuelle : ",
        "1. Modifier la langue maternelle",
        "2. Modifier la langue d'apprentissage",
        "0. Retour aux paramètres",
        "Veuillez choisir votre langue maternelle : ",
        "Choix (1-24) : ",
        "Langue maternelle définie avec succès !",
        "Veuillez choisir la langue d'apprentissage : ",
        "Langue d'apprentissage définie avec succès !",
        "Choix : ",
        "0. - retour -",
        "Erreur : la langue maternelle et la langue d’apprentissage ne peuvent pas être identiques !",
        "============= Menu =============="
    },

    // RUSSIAN (Index 7)
    {
        "==== Настройка языка обучения ====",
        "Текущий родной язык: ",
        "Текущий изучаемый язык: ",
        "1. Изменить родной язык",
        "2. Изменить изучаемый язык",
        "0. Назад к настройкам",
        "Выберите ваш родной язык: ",
        "Выбор (1-24): ",
        "Родной язык успешно установлен!",
        "Выберите изучаемый язык: ",
        "Изучаемый язык успешно установлен!",
        "Выбор: ",
        "0. - назад -",
        "Ошибка: Родной язык и изучаемый язык не могут совпадать!",
        "============= Меню =============="
    },

    // UKRAINIAN (Index 8)
    {
        "==== Налаштування мови навчання ====",
        "Поточна рідна мова: ",
        "Поточна мова навчання: ",
        "1. Змінити рідну мову",
        "2. Змінити мову навчання",
        "0. Назад до налаштувань",
        "Оберіть вашу рідну мову: ",
        "Вибір (1-24): ",
        "Рідну мову успішно встановлено!",
        "Оберіть мову навчання: ",
        "Мову навчання успішно встановлено!",
        "Вибір: ",
        "0. - назад -",
        "Помилка: Рідна мова та мова навчання не можуть бути однаковими!",
        "============= Меню =============="
    },

    // KOREAN (Index 9)
    {
        "==== 학습 언어 설정 ====",
        "현재 모국어: ",
        "현재 학습 언어: ",
        "1. 모국어 변경",
        "2. 학습 언어 변경",
        "0. 설정으로 돌아가기",
        "모국어를 선택하세요: ",
        "선택 (1-24): ",
        "모국어가 설정되었습니다!",
        "학습 언어를 선택하세요: ",
        "학습 언어가 설정되었습니다!",
        "선택: ",
        "0. - 뒤로 -",
        "오류: 모국어와 학습 언어는 같을 수 없습니다!",
        "============= 메뉴 =============="
    },

    // ITALIAN (Index 10)
    {
        "==== Imposta lingua di apprendimento ====",
        "Lingua madre attuale: ",
        "Lingua di apprendimento attuale: ",
        "1. Cambia lingua madre",
        "2. Cambia lingua di apprendimento",
        "0. Torna alle impostazioni",
        "Seleziona la tua lingua madre: ",
        "Scelta (1-24): ",
        "Lingua madre impostata con successo!",
        "Seleziona la lingua di apprendimento: ",
        "Lingua di apprendimento impostata con successo!",
        "Scelta: ",
        "0. - indietro -",
        "Errore: La lingua madre e la lingua di apprendimento non possono essere uguali!",
        "============= Menu =============="
    },

    // POLISH (Index 11)
    {
        "==== Ustaw język nauki ====",
        "Aktualny język ojczysty: ",
        "Aktualny język nauki: ",
        "1. Zmień język ojczysty",
        "2. Zmień język nauki",
        "0. Powrót do ustawień",
        "Wybierz swój język ojczysty: ",
        "Wybór (1-24): ",
        "Język ojczysty ustawiony!",
        "Wybierz język nauki: ",
        "Język nauki ustawiony!",
        "Wybór: ",
        "0. - powrót -",
        "Błąd: Język ojczysty i język nauki nie mogą być takie same!",
        "============= Menu =============="
    },

    // ARABIC (Index 12)
    {
        "==== تعيين لغة التعلم ====",
        "اللغة الأم الحالية: ",
        "لغة التعلم الحالية: ",
        "1. تغيير اللغة الأم",
        "2. تغيير لغة التعلم",
        "0. العودة إلى الإعدادات",
        "يرجى اختيار لغتك الأم: ",
        "اختيار (1-24): ",
        "تم تعيين اللغة الأم بنجاح!",
        "يرجى اختيار لغة التعلم: ",
        "تم تعيين لغة التعلم بنجاح!",
        "اختيار: ",
        "0. - رجوع -",
        "خطأ: لا يمكن أن تكون اللغة الأم ولغة التعلم متطابقتين!",
        "============= القائمة =============="
    },

    // VIETNAMESE (Index 13)
    {
        "==== Cài đặt ngôn ngữ học ====",
        "Ngôn ngữ mẹ đẻ hiện tại: ",
        "Ngôn ngữ học hiện tại: ",
        "1. Thay đổi ngôn ngữ mẹ đẻ",
        "2. Thay đổi ngôn ngữ học",
        "0. Quay lại cài đặt",
        "Chọn ngôn ngữ mẹ đẻ của bạn: ",
        "Lựa chọn (1-24): ",
        "Đã đặt ngôn ngữ mẹ đẻ!",
        "Chọn ngôn ngữ học: ",
        "Đã đặt ngôn ngữ học!",
        "Lựa chọn: ",
        "0. - quay lại -",
        "Lỗi: Ngôn ngữ mẹ đẻ và ngôn ngữ học không thể giống nhau!",
        "============= Menu =============="
    },

    // TAGALOG (Index 14)
    {
        "==== Itakda ang wika ng pag-aaral ====",
        "Kasalukuyang katutubong wika: ",
        "Kasalukuyang pinag-aaralang wika: ",
        "1. Baguhin ang katutubong wika",
        "2. Baguhin ang pinag-aaralang wika",
        "0. Bumalik sa settings",
        "Piliin ang iyong katutubong wika: ",
        "Pili (1-24): ",
        "Matagumpay na na-set ang katutubong wika!",
        "Piliin ang pinag-aaralang wika: ",
        "Matagumpay na na-set ang pinag-aaralang wika!",
        "Piliin: ",
        "0. - bumalik -",
        "Error: Hindi maaaring pareho ang katutubong wika at wikang pinag-aaralan!",
        "============= Menu =============="
    },

    // GREEK (Index 15)
    {
        "==== Ρύθμιση γλώσσας εκμάθησης ====",
        "Τρέχουσα μητρική γλώσσα: ",
        "Τρέχουσα γλώσσα εκμάθησης: ",
        "1. Αλλαγή μητρικής γλώσσας",
        "2. Αλλαγή γλώσσας εκμάθησης",
        "0. Επιστροφή στις ρυθμίσεις",
        "Επιλέξτε τη μητρική σας γλώσσα: ",
        "Επιλογή (1-24): ",
        "Η μητρική γλώσσα ορίστηκε!",
        "Επιλέξτε τη γλώσσα εκμάθησης: ",
        "Η γλώσσα εκμάθησης ορίστηκε!",
        "Επιλογή: ",
        "0. - πίσω -",
        "Σφάλμα: Η μητρική γλώσσα και η γλώσσα εκμάθησης δεν μπορούν να είναι ίδιες!",
        "============= Μενού =============="
    },

    // HEBREW (Index 16)
    {
        "==== הגדרת שפת לימוד ====",
        "שפת אם נוכחית: ",
        "שפת לימוד נוכחית: ",
        "1. שינוי שפת אם",
        "2. שינוי שפת לימוד",
        "0. חזרה להגדרות",
        "בחר את שפת האם שלך: ",
        "בחירה (1-24): ",
        "שפת האם הוגדרה בהצלחה!",
        "בחר את שפת הלימוד: ",
        "שפת הלימוד הוגדרה בהצלחה!",
        "בחירה: ",
        "0. - חזרה -",
        "שגיאה: שפת האם ושפת הלימוד לא יכולות להיות זהות!",
        "============= תפריט =============="
    },

    // PORTUGUESE (Index 17)
    {
        "==== Definir idioma de aprendizagem ====",
        "Idioma nativo atual: ",
        "Idioma de aprendizagem atual: ",
        "1. Alterar idioma nativo",
        "2. Alterar idioma de aprendizagem",
        "0. Voltar às configurações",
        "Selecione seu idioma nativo: ",
        "Escolha (1-24): ",
        "Idioma nativo definido com sucesso!",
        "Selecione o idioma de aprendizagem: ",
        "Idioma de aprendizagem definido com sucesso!",
        "Escolha: ",
        "0. - voltar -",
        "Erro: O idioma nativo e o idioma de aprendizagem não podem ser iguais!",
        "============= Menu =============="
    },

    // FARSI (Index 18)
    {
        "==== تنظیم زبان یادگیری ====",
        "زبان مادری فعلی: ",
        "زبان در حال یادگیری: ",
        "1. تغییر زبان مادری",
        "2. تغییر زبان یادگیری",
        "0. بازگشت به تنظیمات",
        "لطفاً زبان مادری خود را انتخاب کنید: ",
        "انتخاب (1-24): ",
        "زبان مادری با موفقیت تنظیم شد!",
        "لطفاً زبان یادگیری را انتخاب کنید: ",
        "زبان یادگیری با موفقیت تنظیم شد!",
        "انتخاب: ",
        "0. - بازگشت -",
        "خطا: زبان مادری و زبان یادگیری نمی‌توانند یکسان باشند!",
        "============= منو =============="
    },

    // SWEDISH (Index 19)
    {
        "==== Ställ in inlärningsspråk ====",
        "Nuvarande modersmål: ",
        "Nuvarande inlärningsspråk: ",
        "1. Ändra modersmål",
        "2. Ändra inlärningsspråk",
        "0. Tillbaka till inställningar",
        "Välj ditt modersmål: ",
        "Val (1-24): ",
        "Modersmål inställt!",
        "Välj inlärningsspråk: ",
        "Inlärningsspråk inställt!",
        "Val: ",
        "0. - tillbaka -",
        "Fel: Modersmål och inlärningsspråk kan inte vara samma!",
        "============= Meny =============="
    },

    // DUTCH (Index 20)
    {
        "==== Leer taal instellen ====",
        "Huidige moedertaal: ",
        "Huidige leertaal: ",
        "1. Moedertaal wijzigen",
        "2. Leertaal wijzigen",
        "0. Terug naar instellingen",
        "Selecteer je moedertaal: ",
        "Keuze (1-24): ",
        "Moedertaal succesvol ingesteld!",
        "Selecteer de leertaal: ",
        "Leertaal succesvol ingesteld!",
        "Keuze: ",
        "0. - terug -",
        "Fout: Moedertaal en leertaal mogen niet hetzelfde zijn!",
        "============= Menu =============="
    },

    // TURKISH (Index 21)
    {
        "==== Öğrenme dili ayarla ====",
        "Mevcut ana dil: ",
        "Mevcut öğrenilen dil: ",
        "1. Ana dili değiştir",
        "2. Öğrenilen dili değiştir",
        "0. Ayarlara geri dön",
        "Ana dilinizi seçin: ",
        "Seçim (1-24): ",
        "Ana dil başarıyla ayarlandı!",
        "Öğrenilen dili seçin: ",
        "Öğrenilen dil başarıyla ayarlandı!",
        "Seçim: ",
        "0. - geri -",
        "Hata: Ana dil ve öğrenme dili aynı olamaz!",
        "============= Menü =============="
    },

    // HINDI (Index 22)
    {
        "==== सीखने की भाषा सेट करें ====",
        "वर्तमान मातृभाषा: ",
        "वर्तमान सीखने की भाषा: ",
        "1. मातृभाषा बदलें",
        "2. सीखने की भाषा बदलें",
        "0. सेटिंग्स पर वापस जाएँ",
        "अपनी मातृभाषा चुनें: ",
        "चयन (1-24): ",
        "मातृभाषा सफलतापूर्वक सेट की गई!",
        "सीखने की भाषा चुनें: ",
        "सीखने की भाषा सफलतापूर्वक सेट की गई!",
        "चयन: ",
        "0. - वापस -",
        "त्रुटि: मातृभाषा और सीखने की भाषा एक जैसी नहीं हो सकती!",
        "============= मेनू =============="
    },

    // LATIN (Index 23)
    {
        "==== Linguam discendam configura ====",
        "Lingua materna praesens: ",
        "Lingua discenda praesens: ",
        "1. Linguam maternnam muta",
        "2. Linguam discendam muta",
        "0. Redire ad configurationes",
        "Elige linguam maternam: ",
        "Electio (1-24): ",
        "Lingua materna feliciter configurata est!",
        "Elige linguam discendam: ",
        "Lingua discenda feliciter configurata est!",
        "Electio: ",
        "0. - redire -",
        "Error: Lingua materna et lingua discenda eadem esse non possunt!",
        "============= Menu =============="
    }
};


//==========================================================================
static const std::vector<TargetLanguageNameSet> targetLanguageSetTranslations_hardcoded {
    // Hungarian (Index 0)
    {
        "Angolul?",
        "Magyarul?",
        "Kínaiul?",
        "Japánul?",
        "Spanyolul?",
        "Németül?",
        "Franciául?",
        "Oroszul?",
        "Ukránul?",
        "Koreaiul?",
        "Olaszul?",
        "Lengyelül?",
        "Arabul?",
        "Vietnámiul?",
        "Filippínóul?",
        "Görögül?",
        "Héberül?",
        "Portugálul?",
        "Perzsául?",
        "Svédül?",
        "Hollandul?",
        "Törökül?",
        "Indiai-ul?",
        "Latinul?"
    },

    // ENGLISH (Index 1)
    {
        "in English?",
        "in Hungarian?",
        "in Chinese?",
        "in Japanese?",
        "in Spanish?",
        "in German?",
        "in French?",
        "in Russian?",
        "in Ukrainian?",
        "in Korean?",
        "in Italian?",
        "in Polish?",
        "in Arabic?",
        "in Vietnamese?",
        "in Tagalog?",
        "in Greek?",
        "in Hebrew?",
        "in Portuguese?",
        "in Persian?",
        "in Swedish?",
        "in Dutch?",
        "in Turkish?",
        "in Hindi?",
        "in Latin?"
    },

    // CHINESE (Index 2)
    {
        "用英语？",
        "用匈牙利语？",
        "用中文？",
        "用日语？",
        "用西班牙语？",
        "用德语？",
        "用法语？",
        "用俄语？",
        "用乌克兰语？",
        "用韩语？",
        "用意大利语？",
        "用波兰语？",
        "用阿拉伯语？",
        "用越南语？",
        "用他加禄语？",
        "用希腊语？",
        "用希伯来语？",
        "用葡萄牙语？",
        "用波斯语？",
        "用瑞典语？",
        "用荷兰语？",
        "用土耳其语？",
        "用印地语？",
        "用拉丁语？"
    },

    // JAPANESE (Index 3)
    {
        "英語で？",
        "ハンガリー語で？",
        "中国語で？",
        "日本語で？",
        "スペイン語で？",
        "ドイツ語で？",
        "フランス語で？",
        "ロシア語で？",
        "ウクライナ語で？",
        "韓国語で？",
        "イタリア語で？",
        "ポーランド語で？",
        "アラビア語で？",
        "ベトナム語で？",
        "タガログ語で？",
        "ギリシャ語で？",
        "ヘブライ語で？",
        "ポルトガル語で？",
        "ペルシャ語で？",
        "スウェーデン語で？",
        "オランダ語で？",
        "トルコ語で？",
        "ヒンディー語で？",
        "ラテン語で？"
    },

    // SPANISH (Index 4)
    {
        "¿En inglés?",
        "¿En húngaro?",
        "¿En chino?",
        "¿En japonés?",
        "¿En español?",
        "¿En alemán?",
        "¿En francés?",
        "¿En ruso?",
        "¿En ucraniano?",
        "¿En coreano?",
        "¿En italiano?",
        "¿En polaco?",
        "¿En árabe?",
        "¿En vietnamita?",
        "¿En tagalo?",
        "¿En griego?",
        "¿En hebreo?",
        "¿En portugués?",
        "¿En persa?",
        "¿En sueco?",
        "¿En holandés?",
        "¿En turco?",
        "¿En hindi?",
        "¿En latín?"
    },

    // GERMAN (Index 5)
    {
        "Auf Englisch?",
        "Auf Ungarisch?",
        "Auf Chinesisch?",
        "Auf Japanisch?",
        "Auf Spanisch?",
        "Auf Deutsch?",
        "Auf Französisch?",
        "Auf Russisch?",
        "Auf Ukrainisch?",
        "Auf Koreanisch?",
        "Auf Italienisch?",
        "Auf Polnisch?",
        "Auf Arabisch?",
        "Auf Vietnamesisch?",
        "Auf Tagalog?",
        "Auf Griechisch?",
        "Auf Hebräisch?",
        "Auf Portugiesisch?",
        "Auf Persisch?",
        "Auf Schwedisch?",
        "Auf Niederländisch?",
        "Auf Türkisch?",
        "Auf Hindi?",
        "Auf Latein?"
    },

    // FRENCH (Index 6)
    {
        "En anglais ?",
        "En hongrois ?",
        "En chinois ?",
        "En japonais ?",
        "En espagnol ?",
        "En allemand ?",
        "En français ?",
        "En russe ?",
        "En ukrainien ?",
        "En coréen ?",
        "En italien ?",
        "En polonais ?",
        "En arabe ?",
        "En vietnamien ?",
        "En tagalog ?",
        "En grec ?",
        "En hébreu ?",
        "En portugais ?",
        "En persan ?",
        "En suédois ?",
        "En néerlandais ?",
        "En turc ?",
        "En hindi ?",
        "En latin ?"
    },

    // RUSSIAN (Index 7)
    {
        "На английском?",
        "На венгерском?",
        "На китайском?",
        "На японском?",
        "На испанском?",
        "На немецком?",
        "На французском?",
        "На русском?",
        "На украинском?",
        "На корейском?",
        "На итальянском?",
        "На польском?",
        "На арабском?",
        "На вьетнамском?",
        "На тагальском?",
        "На греческом?",
        "На иврите?",
        "На португальском?",
        "На персидском?",
        "На шведском?",
        "На голландском?",
        "На турецком?",
        "На хинди?",
        "На латинском?"
    },
    // UKRAINIAN (Index 8)
    {
        "Англійською?",
        "Угорською?",
        "Китайською?",
        "Японською?",
        "Іспанською?",
        "Німецькою?",
        "Французькою?",
        "Російською?",
        "Українською?",
        "Корейською?",
        "Італійською?",
        "Польською?",
        "Арабською?",
        "В'єтнамською?",
        "Філіппінською?",
        "Грецькою?",
        "Івритом?",
        "Португальською?",
        "Перською?",
        "Шведською?",
        "Голландською?",
        "Турецькою?",
        "Гінді?",
        "Латиною?"
    },

    // KOREAN (Index 9)
    {
        "영어로?",
        "헝가리어로?",
        "중국어로?",
        "일본어로?",
        "스페인어로?",
        "독일어로?",
        "프랑스어로?",
        "러시아어로?",
        "우크라이나어로?",
        "한국어로?",
        "이탈리아어로?",
        "폴란드어로?",
        "아랍어로?",
        "베트남어로?",
        "타갈로그어로?",
        "그리스어로?",
        "히브리어로?",
        "포르투갈어로?",
        "페르시아어로?",
        "스웨덴어로?",
        "네덜란드어로?",
        "터키어로?",
        "힌디어로?",
        "라틴어로?"
    },

    // ITALIAN (Index 10)
    {
        "In inglese?",
        "In ungherese?",
        "In cinese?",
        "In giapponese?",
        "In spagnolo?",
        "In tedesco?",
        "In francese?",
        "In russo?",
        "In ucraino?",
        "In coreano?",
        "In italiano?",
        "In polacco?",
        "In arabo?",
        "In vietnamita?",
        "In tagalog?",
        "In greco?",
        "In ebraico?",
        "In portoghese?",
        "In persiano?",
        "In svedese?",
        "In olandese?",
        "In turco?",
        "In hindi?",
        "In latino?"
    },

    // POLISH (Index 11)
    {
        "Po angielsku?",
        "Po węgiersku?",
        "Po chińsku?",
        "Po japońsku?",
        "Po hiszpańsku?",
        "Po niemiecku?",
        "Po francusku?",
        "Po rosyjsku?",
        "Po ukraińsku?",
        "Po koreańsku?",
        "Po włosku?",
        "Po polsku?",
        "Po arabsku?",
        "Po wietnamsku?",
        "Po tagalsku?",
        "Po grecku?",
        "Po hebrajsku?",
        "Po portugalsku?",
        "Po persku?",
        "Po szwedzku?",
        "Po holendersku?",
        "Po turecku?",
        "Po hindi?",
        "Po łacinie?"
    },

    // ARABIC (Index 12)
    {
        "بالإنجليزية؟",
        "بالمجرية؟",
        "بالصينية؟",
        "بالأجنبية اليابانية؟",
        "بالإسبانية؟",
        "بالألمانية؟",
        "بالفرنسية؟",
        "بالروسية؟",
        "بالأوكرانية؟",
        "بالكورية؟",
        "بالإيطالية؟",
        "بالبولندية؟",
        "بالعربية؟",
        "بالفيتنامية؟",
        "بالتاغالوغ؟",
        "بالإغريقية؟",
        "بالعبرية؟",
        "بالبرتغالية؟",
        "بالفارسية؟",
        "بالسويدية؟",
        "بالهولندية؟",
        "بالتركية؟",
        "بالهندية؟",
        "باللاتينية؟"
    },

    // VIETNAMESE (Index 13)
    {
        "Bằng tiếng Anh?",
        "Bằng tiếng Hungary?",
        "Bằng tiếng Trung?",
        "Bằng tiếng Nhật?",
        "Bằng tiếng Tây Ban Nha?",
        "Bằng tiếng Đức?",
        "Bằng tiếng Pháp?",
        "Bằng tiếng Nga?",
        "Bằng tiếng Ukraina?",
        "Bằng tiếng Hàn?",
        "Bằng tiếng Ý?",
        "Bằng tiếng Ba Lan?",
        "Bằng tiếng Ả Rập?",
        "Bằng tiếng Việt?",
        "Bằng tiếng Tagalog?",
        "Bằng tiếng Hy Lạp?",
        "Bằng tiếng Do Thái?",
        "Bằng tiếng Bồ Đào Nha?",
        "Bằng tiếng Ba Tư?",
        "Bằng tiếng Thụy Điển?",
        "Bằng tiếng Hà Lan?",
        "Bằng tiếng Thổ Nhĩ Kỳ?",
        "Bằng tiếng Hindi?",
        "Bằng tiếng Latin?"
    },

    // TAGALOG (Index 14)
    {
        "Sa Ingles?",
        "Sa Hungarian?",
        "Sa Chinese?",
        "Sa Japanese?",
        "Sa Spanish?",
        "Sa German?",
        "Sa French?",
        "Sa Russian?",
        "Sa Ukrainian?",
        "Sa Korean?",
        "Sa Italian?",
        "Sa Polish?",
        "Sa Arabic?",
        "Sa Vietnamese?",
        "Sa Tagalog?",
        "Sa Greek?",
        "Sa Hebrew?",
        "Sa Portuguese?",
        "Sa Persian?",
        "Sa Swedish?",
        "Sa Dutch?",
        "Sa Turkish?",
        "Sa Hindi?",
        "Sa Latin?"
    },

    // GREEK (Index 15)
    {
        "Στα αγγλικά;",
        "Στα ουγγρικά;",
        "Στα κινεζικά;",
        "Στα ιαπωνικά;",
        "Στα ισπανικά;",
        "Στα γερμανικά;",
        "Στα γαλλικά;",
        "Στα ρωσικά;",
        "Στα ουκρανικά;",
        "Στα κορεατικά;",
        "Στα ιταλικά;",
        "Στα πολωνικά;",
        "Στα αραβικά;",
        "Στα βιετναμέζικα;",
        "Στα ταγκάλογκ;",
        "Στα ελληνικά;",
        "Στα εβραϊκά;",
        "Στα πορτογαλικά;",
        "Στα περσικά;",
        "Στα σουηδικά;",
        "Στα ολλανδικά;",
        "Στα τουρκικά;",
        "Στα χίντι;",
        "Στα λατινικά;"
    },

    // HEBREW (Index 16)
    {
        "באנגלית?",
        "בהונגרית?",
        "בסינית?",
        "ביפנית?",
        "בספרדית?",
        "בגרמנית?",
        "בצרפתית?",
        "ברוסית?",
        "באוקראינית?",
        "בקוריאנית?",
        "באיטלקית?",
        "בפולנית?",
        "בערבית?",
        "בוייטנאמית?",
        "בטגלוג?",
        "ביוונית?",
        "בעברית?",
        "בפורטוגזית?",
        "בפרסית?",
        "בשבדית?",
        "בהולנדית?",
        "בטורקית?",
        "בהינדי?",
        "בלטינית?"
    },

    // PORTUGUESE (Index 17)
    {
        "Em inglês?",
        "Em húngaro?",
        "Em chinês?",
        "Em japonês?",
        "Em espanhol?",
        "Em alemão?",
        "Em francês?",
        "Em russo?",
        "Em ucraniano?",
        "Em coreano?",
        "Em italiano?",
        "Em polonês?",
        "Em árabe?",
        "Em vietnamita?",
        "Em tagalo?",
        "Em grego?",
        "Em hebraico?",
        "Em português?",
        "Em persa?",
        "Em sueco?",
        "Em holandês?",
        "Em turco?",
        "Em hindi?",
        "Em latim?"
    },

    // FARSI (Index 18)
    {
        "به انگلیسی؟",
        "به مجاری؟",
        "به چینی؟",
        "به ژاپنی؟",
        "به اسپانیایی؟",
        "به آلمانی؟",
        "به فرانسوی؟",
        "به روسی؟",
        "به اوکراینی؟",
        "به کره‌ای؟",
        "به ایتالیایی؟",
        "به لهستانی؟",
        "به عربی؟",
        "به ویتنامی؟",
        "به تاگالوگ؟",
        "به یونانی؟",
        "به عبری؟",
        "به پرتغالی؟",
        "به فارسی؟",
        "به سوئدی؟",
        "به هلندی؟",
        "به ترکی؟",
        "به هندی؟",
        "به لاتین؟"
    },

    // SWEDISH (Index 19)
    {
        "På engelska?",
        "På ungerska?",
        "På kinesiska?",
        "På japanska?",
        "På spanska?",
        "På tyska?",
        "På franska?",
        "På ryska?",
        "På ukrainska?",
        "På koreanska?",
        "På italienska?",
        "På polska?",
        "På arabiska?",
        "På vietnamesiska?",
        "På tagalog?",
        "På grekiska?",
        "På hebreiska?",
        "På portugisiska?",
        "På persiska?",
        "På svenska?",
        "På nederländska?",
        "På turkiska?",
        "På hindi?",
        "På latin?"
    },

    // DUTCH (Index 20)
    {
        "In het Engels?",
        "In het Hongaars?",
        "In het Chinees?",
        "In het Japans?",
        "In het Spaans?",
        "In het Duits?",
        "In het Frans?",
        "In het Russisch?",
        "In het Oekraïens?",
        "In het Koreaans?",
        "In het Italiaans?",
        "In het Pools?",
        "In het Arabisch?",
        "In het Vietnamees?",
        "In het Tagalog?",
        "In het Grieks?",
        "In het Hebreeuws?",
        "In het Portugees?",
        "In het Perzisch?",
        "In het Zweeds?",
        "In het Nederlands?",
        "In het Turks?",
        "In het Hindi?",
        "In het Latijn?"
    },

    // TURKISH (Index 21)
    {
        "İngilizce?",
        "Macarca?",
        "Çince?",
        "Japonca?",
        "İspanyolca?",
        "Almanca?",
        "Fransızca?",
        "Rusça?",
        "Ukraynaca?",
        "Korece?",
        "İtalyanca?",
        "Lehçe?",
        "Arapça?",
        "Vietnamca?",
        "Tagalogca?",
        "Yunanca?",
        "İbranice?",
        "Portekizce?",
        "Farsça?",
        "İsveççe?",
        "Hollandaca?",
        "Türkçe?",
        "Hintçe?",
        "Latince?"
    },

    // HINDI (Index 22)
    {
        "अंग्रेज़ी में?",
        "हंगेरियन में?",
        "चीनी में?",
        "जापानी में?",
        "स्पेनिश में?",
        "जर्मन में?",
        "फ्रेंच में?",
        "रूसी में?",
        "यूक्रेनी में?",
        "कोरियाई में?",
        "इतालवी में?",
        "पोलिश में?",
        "अरबी में?",
        "वियतनामी में?",
        "तागालोग में?",
        "ग्रीक में?",
        "हिब्रू में?",
        "पुर्तगाली में?",
        "फ़ारसी में?",
        "स्वीडिश में?",
        "डच में?",
        "तुर्की में?",
        "हिंदी में?",
        "लैटिन में?"
    },

    // LATIN (Index 23)
    {
        "Anglice?",
        "Hungarice?",
        "Sinice?",
        "Iaponice?",
        "Hispanice?",
        "Germanice?",
        "Gallice?",
        "Russice?",
        "Ucrainice?",
        "Coreane?",
        "Italice?",
        "Polonice?",
        "Arabice?",
        "Vietnamice?",
        "Tagaloge?",
        "Graece?",
        "Hebraice?",
        "Lusitanice?",
        "Persice?",
        "Suecice?",
        "Batavice?",
        "Turcice?",
        "Hindice?",
        "Latine?"
    }
};
const std::vector<TargetLanguageNameSet> targetLanguageSetTranslations = targetLanguageSetTranslations_hardcoded;

//==========================================================================
static const std::vector<TargetLanguageList> targetLanguageListTranslations_hardcoded {

    // Hungarian (Index 0)
    {
        "Angol",
        "Magyar",
        "Kínai",
        "Japán",
        "Spanyol",
        "Német",
        "Francia",
        "Orosz",
        "Ukrán",
        "Koreai",
        "Olasz",
        "Lengyel",
        "Arab",
        "Vietnámi",
        "Filippínó",
        "Görög",
        "Héber",
        "Portugál",
        "Perzsa",
        "Svéd",
        "Holland",
        "Török",
        "Hindi",
        "Latin"
    },

    // English (Index 1)
    {
        "English",
        "Hungarian",
        "Chinese",
        "Japanese",
        "Spanish",
        "German",
        "French",
        "Russian",
        "Ukrainian",
        "Korean",
        "Italian",
        "Polish",
        "Arabic",
        "Vietnamese",
        "Filipino",
        "Greek",
        "Hebrew",
        "Portuguese",
        "Persian",
        "Swedish",
        "Dutch",
        "Turkish",
        "Hindi",
        "Latin"
    },

    // Chinese (Index 2)
    {
        "英语",
        "匈牙利语",
        "中文",
        "日语",
        "西班牙语",
        "德语",
        "法语",
        "俄语",
        "乌克兰语",
        "韩语",
        "意大利语",
        "波兰语",
        "阿拉伯语",
        "越南语",
        "菲律宾语",
        "希腊语",
        "希伯来语",
        "葡萄牙语",
        "波斯语",
        "瑞典语",
        "荷兰语",
        "土耳其语",
        "印地语",
        "拉丁语"
    },

    // Japanese (Index 3)
    {
        "英語",
        "ハンガリー語",
        "中国語",
        "日本語",
        "スペイン語",
        "ドイツ語",
        "フランス語",
        "ロシア語",
        "ウクライナ語",
        "韓国語",
        "イタリア語",
        "ポーランド語",
        "アラビア語",
        "ベトナム語",
        "フィリピン語",
        "ギリシャ語",
        "ヘブライ語",
        "ポルトガル語",
        "ペルシャ語",
        "スウェーデン語",
        "オランダ語",
        "トルコ語",
        "ヒンディー語",
        "ラテン語"
    },

    // Spanish (Index 4)
    {
        "Inglés",
        "Húngaro",
        "Chino",
        "Japonés",
        "Español",
        "Alemán",
        "Francés",
        "Ruso",
        "Ucraniano",
        "Coreano",
        "Italiano",
        "Polaco",
        "Árabe",
        "Vietnamita",
        "Filipino",
        "Griego",
        "Hebreo",
        "Portugués",
        "Persa",
        "Sueco",
        "Holandés",
        "Turco",
        "Hindi",
        "Latín"
    },

    // German (Index 5)
    {
        "Englisch",
        "Ungarisch",
        "Chinesisch",
        "Japanisch",
        "Spanisch",
        "Deutsch",
        "Französisch",
        "Russisch",
        "Ukrainisch",
        "Koreanisch",
        "Italienisch",
        "Polnisch",
        "Arabisch",
        "Vietnamesisch",
        "Philippinisch",
        "Griechisch",
        "Hebräisch",
        "Portugiesisch",
        "Persisch",
        "Schwedisch",
        "Niederländisch",
        "Türkisch",
        "Hindi",
        "Latein"
    },

    // French (Index 6)
    {
        "Anglais",
        "Hongrois",
        "Chinois",
        "Japonais",
        "Espagnol",
        "Allemand",
        "Français",
        "Russe",
        "Ukrainien",
        "Coréen",
        "Italien",
        "Polonais",
        "Arabe",
        "Vietnamien",
        "Philippin",
        "Grec",
        "Hébreu",
        "Portugais",
        "Persan",
        "Suédois",
        "Néerlandais",
        "Turc",
        "Hindi",
        "Latin"
    },

    // Russian (Index 7)
    {
        "Английский",
        "Венгерский",
        "Китайский",
        "Японский",
        "Испанский",
        "Немецкий",
        "Французский",
        "Русский",
        "Украинский",
        "Корейский",
        "Итальянский",
        "Польский",
        "Арабский",
        "Вьетнамский",
        "Филиппинский",
        "Греческий",
        "Иврит",
        "Португальский",
        "Персидский",
        "Шведский",
        "Голландский",
        "Турецкий",
        "Хинди",
        "Латынь"
    },

    // Ukrainian (Index 8)
    {
        "Англійська",
        "Угорська",
        "Китайська",
        "Японська",
        "Іспанська",
        "Німецька",
        "Французька",
        "Російська",
        "Українська",
        "Корейська",
        "Італійська",
        "Польська",
        "Арабська",
        "В'єтнамська",
        "Філіппінська",
        "Грецька",
        "Іврит",
        "Португальська",
        "Перська",
        "Шведська",
        "Голландська",
        "Турецька",
        "Гінді",
        "Латинь"
    },

    // Korean (Index 9)
    {
        "영어",
        "헝가리어",
        "중국어",
        "일본어",
        "스페인어",
        "독일어",
        "프랑스어",
        "러시아어",
        "우크라이나어",
        "한국어",
        "이탈리아어",
        "폴란드어",
        "아랍어",
        "베트남어",
        "필리핀어",
        "그리스어",
        "히브리어",
        "포르투갈어",
        "페르시아어",
        "스웨덴어",
        "네덜란드어",
        "터키어",
        "힌디어",
        "라틴어"
    },

    // Italian (Index 10)
    {
        "Inglese",
        "Ungherese",
        "Cinese",
        "Giapponese",
        "Spagnolo",
        "Tedesco",
        "Francese",
        "Russo",
        "Ucraino",
        "Coreano",
        "Italiano",
        "Polacco",
        "Arabo",
        "Vietnamita",
        "Filippino",
        "Greco",
        "Ebraico",
        "Portoghese",
        "Persiano",
        "Svedese",
        "Olandese",
        "Turco",
        "Hindi",
        "Latino"
    },

    // Polish (Index 11)
    {
        "Angielski",
        "Węgierski",
        "Chiński",
        "Japoński",
        "Hiszpański",
        "Niemiecki",
        "Francuski",
        "Rosyjski",
        "Ukraiński",
        "Koreański",
        "Włoski",
        "Polski",
        "Arabski",
        "Wietnamski",
        "Filipiński",
        "Grecki",
        "Hebrajski",
        "Portugalski",
        "Perski",
        "Szwedzki",
        "Holenderski",
        "Turecki",
        "Hindi",
        "Łacina"
    },

    // Arabic (Index 12)
    {
        "الإنجليزية",
        "المجرية",
        "الصينية",
        "اليابانية",
        "الإسبانية",
        "الألمانية",
        "الفرنسية",
        "الروسية",
        "الأوكرانية",
        "الكورية",
        "الإيطالية",
        "البولندية",
        "العربية",
        "الفيتنامية",
        "الفلبينية",
        "اليونانية",
        "العبرية",
        "البرتغالية",
        "الفارسية",
        "السويدية",
        "الهولندية",
        "التركية",
        "الهندية",
        "اللاتينية"
    },

    // Vietnamese (Index 13)
    {
        "Tiếng Anh",
        "Tiếng Hungary",
        "Tiếng Trung",
        "Tiếng Nhật",
        "Tiếng Tây Ban Nha",
        "Tiếng Đức",
        "Tiếng Pháp",
        "Tiếng Nga",
        "Tiếng Ukraina",
        "Tiếng Hàn",
        "Tiếng Ý",
        "Tiếng Ba Lan",
        "Tiếng Ả Rập",
        "Tiếng Việt",
        "Tiếng Philippines",
        "Tiếng Hy Lạp",
        "Tiếng Do Thái",
        "Tiếng Bồ Đào Nha",
        "Tiếng Ba Tư",
        "Tiếng Thụy Điển",
        "Tiếng Hà Lan",
        "Tiếng Thổ Nhĩ Kỳ",
        "Tiếng Hindi",
        "Tiếng Latinh"
    },

    // Tagalog (Index 14)
    {
        "Ingles",
        "Hungarian",
        "Chinese",
        "Japanese",
        "Spanish",
        "German",
        "French",
        "Russian",
        "Ukrainian",
        "Korean",
        "Italian",
        "Polish",
        "Arabic",
        "Vietnamese",
        "Filipino",
        "Greek",
        "Hebrew",
        "Portuguese",
        "Persian",
        "Swedish",
        "Dutch",
        "Turkish",
        "Hindi",
        "Latin"
    },

    // Greek (Index 15)
    {
        "Αγγλικά",
        "Ουγγρικά",
        "Κινέζικα",
        "Ιαπωνικά",
        "Ισπανικά",
        "Γερμανικά",
        "Γαλλικά",
        "Ρωσικά",
        "Ουκρανικά",
        "Κορεατικά",
        "Ιταλικά",
        "Πολωνικά",
        "Αραβικά",
        "Βιετναμέζικα",
        "Φιλιππινέζικα",
        "Ελληνικά",
        "Εβραϊκά",
        "Πορτογαλικά",
        "Περσικά",
        "Σουηδικά",
        "Ολλανδικά",
        "Τουρκικά",
        "Χίντι",
        "Λατινικά"
    },

    // Hebrew (Index 16)
    {
        "אנגלית",
        "הונגרית",
        "סינית",
        "יפנית",
        "ספרדית",
        "גרמנית",
        "צרפתית",
        "רוסית",
        "אוקראינית",
        "קוריאנית",
        "איטלקית",
        "פולנית",
        "ערבית",
        "וייטנאמית",
        "פיליפינית",
        "יוונית",
        "עברית",
        "פורטוגזית",
        "פרסית",
        "שוודית",
        "הולנדית",
        "טורקית",
        "הינדית",
        "לטינית"
    },

    // Portuguese (Index 17)
    {
        "Inglês",
        "Húngaro",
        "Chinês",
        "Japonês",
        "Espanhol",
        "Alemão",
        "Francês",
        "Russo",
        "Ucraniano",
        "Coreano",
        "Italiano",
        "Polonês",
        "Árabe",
        "Vietnamita",
        "Filipino",
        "Grego",
        "Hebraico",
        "Português",
        "Persa",
        "Sueco",
        "Holandês",
        "Turco",
        "Hindi",
        "Latim"
    },

    // Persian (Index 18)
    {
        "انگلیسی",
        "مجاری",
        "چینی",
        "ژاپنی",
        "اسپانیایی",
        "آلمانی",
        "فرانسوی",
        "روسی",
        "اوکراینی",
        "کره‌ای",
        "ایتالیایی",
        "لهستانی",
        "عربی",
        "ویتنامی",
        "فیلیپینی",
        "یونانی",
        "عبری",
        "پرتغالی",
        "فارسی",
        "سوئدی",
        "هلندی",
        "ترکی",
        "هندی",
        "لاتین"
    },

    // Swedish (Index 19)
    {
        "Engelska",
        "Ungerska",
        "Kinesiska",
        "Japanska",
        "Spanska",
        "Tyska",
        "Franska",
        "Ryska",
        "Ukrainska",
        "Koreanska",
        "Italienska",
        "Polska",
        "Arabiska",
        "Vietnamesiska",
        "Filippinska",
        "Grekiska",
        "Hebreiska",
        "Portugisiska",
        "Persiska",
        "Svenska",
        "Holländska",
        "Turkiska",
        "Hindi",
        "Latin"
    },

    // Dutch (Index 20)
    {
        "Engels",
        "Hongaars",
        "Chinees",
        "Japans",
        "Spaans",
        "Duits",
        "Frans",
        "Russisch",
        "Oekraïens",
        "Koreaans",
        "Italiaans",
        "Pools",
        "Arabisch",
        "Vietnamees",
        "Filipijns",
        "Grieks",
        "Hebreeuws",
        "Portugees",
        "Perzisch",
        "Zweeds",
        "Nederlands",
        "Turks",
        "Hindi",
        "Latijn"
    },

    // Turkish (Index 21)
    {
        "İngilizce",
        "Macarca",
        "Çince",
        "Japonca",
        "İspanyolca",
        "Almanca",
        "Fransızca",
        "Rusça",
        "Ukraynaca",
        "Korece",
        "İtalyanca",
        "Lehçe",
        "Arapça",
        "Vietnamca",
        "Filipince",
        "Yunanca",
        "İbranice",
        "Portekizce",
        "Farsça",
        "İsveççe",
        "Hollandaca",
        "Türkçe",
        "Hintçe",
        "Latince"
    },

    // Hindi (Index 22)
    {
        "अंग्रेज़ी",
        "हंगेरियन",
        "चीनी",
        "जापानी",
        "स्पेनिश",
        "जर्मन",
        "फ्रेंच",
        "रूसी",
        "यूक्रेनी",
        "कोरियाई",
        "इतालवी",
        "पोलिश",
        "अरबी",
        "वियतनामी",
        "फिलिपिनो",
        "ग्रीक",
        "हिब्रू",
        "पुर्तगाली",
        "फ़ारसी",
        "स्वीडिश",
        "डच",
        "तुर्की",
        "हिंदी",
        "लैटिन"
    },

    // Latin (Index 23)
    {
        "Anglice",
        "Hungarice",
        "Sinice",
        "Iaponice",
        "Hispanice",
        "Germanice",
        "Gallice",
        "Russice",
        "Ucrainice",
        "Coreane",
        "Italice",
        "Polonice",
        "Arabice",
        "Vietnamice",
        "Philippine",
        "Graece",
        "Hebraice",
        "Lusitanice",
        "Persice",
        "Suecice",
        "Batavice",
        "Turcice",
        "Hindice",
        "Latine"
    }
};
const std::vector<TargetLanguageList> targetLanguageListTranslations = targetLanguageListTranslations_hardcoded;

//==========================================================================
static const std::vector<ListAndSelectedFile> listAndSelectedFilesTranslations_hardcoded = {

    // HUNGARIAN (0)
    {
        "--- Jelenlegi mappa: ",
        "(Üres mappa)",
        "[MAPPA] ",
        "---------------------------------------",
        "Parancsok: név +",
        ".. -> kilépés a mappából, del -> törlés, cp -> másolás, mv -> áthelyezés,",
        "rn -> átnevezés, edit -> szerkesztés, md vagy mkdir -> új mappa, exit -> kilépés",
        "Választás: "
    },

    // ENGLISH (1)
    {
        "--- Current folder: ",
        "(Empty folder)",
        "[FOLDER] ",
        "---------------------------------------",
        "Commands: name +",
        ".. -> up, del -> delete, cp -> copy, mv -> move,",
        "rn -> rename, edit -> edit, md or mkdir -> new folder, exit -> exit",
        "Selection: "
    },

    // CHINESE (2)
    {
        "--- 当前目录: ",
        "(空文件夹)",
        "[文件夹] ",
        "---------------------------------------",
        "命令: 名称 +",
        ".. -> 返回上级, del -> 删除, cp -> 复制, mv -> 移动,",
        "rn -> 重命名, edit -> 编辑, md 或 mkdir -> 新建文件夹, exit -> 退出",
        "选择: "
    },

    // JAPANESE (3)
    {
        "--- 現在のフォルダ: ",
        "(空のフォルダ)",
        "[フォルダ] ",
        "---------------------------------------",
        "コマンド: 名前 +",
        ".. -> 上へ戻る, del -> 削除, cp -> コピー, mv -> 移動,",
        "rn -> 名前変更, edit -> 編集, md または mkdir -> 新しいフォルダ, exit -> 終了",
        "選択: "
    },

    // SPANISH (4)
    {
        "--- Carpeta actual: ",
        "(Carpeta vacía)",
        "[CARPETA] ",
        "---------------------------------------",
        "Comandos: nombre +",
        ".. -> subir, del -> eliminar, cp -> copiar, mv -> mover,",
        "rn -> renombrar, edit -> editar, md o mkdir -> nueva carpeta, exit -> salir",
        "Selección: "
    },

    // GERMAN (5)
    {
        "--- Aktueller Ordner: ",
        "(Leerer Ordner)",
        "[ORDNER] ",
        "---------------------------------------",
        "Befehle: Name +",
        ".. -> zurück, del -> löschen, cp -> kopieren, mv -> verschieben,",
        "rn -> umbenennen, edit -> bearbeiten, md oder mkdir -> neuer Ordner, exit -> beenden",
        "Auswahl: "
    },

    // FRENCH (6)
    {
        "--- Dossier actuel: ",
        "(Dossier vide)",
        "[DOSSIER] ",
        "---------------------------------------",
        "Commandes: nom +",
        ".. -> retour, del -> supprimer, cp -> copier, mv -> déplacer,",
        "rn -> renommer, edit -> éditer, md ou mkdir -> nouveau dossier, exit -> quitter",
        "Choix: "
    },

    // RUSSIAN (7)
    {
        "--- Текущая папка: ",
        "(Пустая папка)",
        "[ПАПКА] ",
        "---------------------------------------",
        "Команды: имя +",
        ".. -> назад, del -> удалить, cp -> копировать, mv -> переместить,",
        "rn -> переименовать, edit -> редактировать, md или mkdir -> новая папка, exit -> выход",
        "Выбор: "
    },

    // UKRAINIAN (8)
    {
        "--- Поточна папка: ",
        "(Порожня папка)",
        "[ПАПКА] ",
        "---------------------------------------",
        "Команди: ім'я +",
        ".. -> назад, del -> видалити, cp -> копіювати, mv -> перемістити,",
        "rn -> перейменувати, edit -> редагувати, md або mkdir -> нова папка, exit -> вихід",
        "Вибір: "
    },

    // KOREAN (9)
    {
        "--- 현재 폴더: ",
        "(빈 폴더)",
        "[폴더] ",
        "---------------------------------------",
        "명령어: 이름 +",
        ".. -> 상위로, del -> 삭제, cp -> 복사, mv -> 이동,",
        "rn -> 이름변경, edit -> 편집, md 또는 mkdir -> 새 폴더, exit -> 종료",
        "선택: "
    },

    // ITALIAN (10)
    {
        "--- Cartella corrente: ",
        "(Cartella vuota)",
        "[CARTELLA] ",
        "---------------------------------------",
        "Comandi: nome +",
        ".. -> su, del -> elimina, cp -> copia, mv -> sposta,",
        "rn -> rinomina, edit -> modifica, md o mkdir -> nuova cartella, exit -> esci",
        "Scelta: "
    },

    // POLISH (11)
    {
        "--- Bieżący folder: ",
        "(Pusty folder)",
        "[FOLDER] ",
        "---------------------------------------",
        "Komendy: nazwa +",
        ".. -> w górę, del -> usuń, cp -> kopiuj, mv -> przenieś,",
        "rn -> zmień nazwę, edit -> edytuj, md lub mkdir -> nowy folder, exit -> wyjście",
        "Wybór: "
    },

    // ARABIC (12)
    {
        "--- المجلد الحالي: ",
        "(مجلد فارغ)",
        "[مجلد] ",
        "---------------------------------------",
        "الأوامر: اسم +",
        ".. -> رجوع, del -> حذف, cp -> نسخ, mv -> نقل,",
        "rn -> إعادة تسمية, edit -> تحرير, md أو mkdir -> مجلد جديد, exit -> خروج",
        "اختيار: "
    },

    // VIETNAMESE (13)
    {
        "--- Thư mục hiện tại: ",
        "(Thư mục trống)",
        "[THƯ MỤC] ",
        "---------------------------------------",
        "Lệnh: tên +",
        ".. -> lên, del -> xóa, cp -> sao chép, mv -> di chuyển,",
        "rn -> đổi tên, edit -> chỉnh sửa, md hoặc mkdir -> thư mục mới, exit -> thoát",
        "Chọn: "
    },

    // TAGALOG (14)
    {
        "--- Kasalukuyang folder: ",
        "(Walang laman ang folder)",
        "[FOLDER] ",
        "---------------------------------------",
        "Mga utos: pangalan +",
        ".. -> pataas, del -> tanggal, cp -> kopya, mv -> lipat,",
        "rn -> palitan pangalan, edit -> edit, md o mkdir -> bagong folder, exit -> labas",
        "Piliin: "
    },

    // GREEK (15)
    {
        "--- Τρέχων φάκελος: ",
        "(Κενός φάκελος)",
        "[ΦΑΚΕΛΟΣ] ",
        "---------------------------------------",
        "Εντολές: όνομα +",
        ".. -> πίσω, del -> διαγραφή, cp -> αντιγραφή, mv -> μετακίνηση,",
        "rn -> μετονομασία, edit -> επεξεργασία, md ή mkdir -> νέος φάκελος, exit -> έξοδος",
        "Επιλογή: "
    },

    // HEBREW (16)
    {
        "--- תיקייה נוכחית: ",
        "(תיקייה ריקה)",
        "[תיקייה] ",
        "---------------------------------------",
        "פקודות: שם +",
        ".. -> חזרה, del -> מחיקה, cp -> העתקה, mv -> העברה,",
        "rn -> שינוי שם, edit -> עריכה, md או mkdir -> תיקייה חדשה, exit -> יציאה",
        "בחירה: "
    },

    // PORTUGUESE (17)
    {
        "--- Pasta atual: ",
        "(Pasta vazia)",
        "[PASTA] ",
        "---------------------------------------",
        "Comandos: nome +",
        ".. -> voltar, del -> excluir, cp -> copiar, mv -> mover,",
        "rn -> renomear, edit -> editar, md ou mkdir -> nova pasta, exit -> sair",
        "Seleção: "
    },

    // FARSI (18)
    {
        "--- پوشه فعلی: ",
        "(پوشه خالی)",
        "[پوشه] ",
        "---------------------------------------",
        "دستورات: نام +",
        ".. -> بازگشت, del -> حذف, cp -> کپی, mv -> انتقال,",
        "rn -> تغییر نام, edit -> ویرایش, md یا mkdir -> پوشه جدید, exit -> خروج",
        "انتخاب: "
    },

    // SWEDISH (19)
    {
        "--- Nuvarande mapp: ",
        "(Tom mapp)",
        "[MAPP] ",
        "---------------------------------------",
        "Kommandon: namn +",
        ".. -> upp, del -> radera, cp -> kopiera, mv -> flytta,",
        "rn -> byt namn, edit -> redigera, md eller mkdir -> ny mapp, exit -> avsluta",
        "Val: "
    },

    // DUTCH (20)
    {
        "--- Huidige map: ",
        "(Lege map)",
        "[MAP] ",
        "---------------------------------------",
        "Commando's: naam +",
        ".. -> omhoog, del -> verwijderen, cp -> kopiëren, mv -> verplaatsen,",
        "rn -> hernoemen, edit -> bewerken, md of mkdir -> nieuwe map, exit -> afsluiten",
        "Keuze: "
    },

    // TURKISH (21)
    {
        "--- Mevcut klasör: ",
        "(Boş klasör)",
        "[KLASÖR] ",
        "---------------------------------------",
        "Komutlar: isim +",
        ".. -> yukarı, del -> sil, cp -> kopyala, mv -> taşı,",
        "rn -> yeniden adlandır, edit -> düzenle, md veya mkdir -> yeni klasör, exit -> çıkış",
        "Seçim: "
    },

    // HINDI (22)
    {
        "--- वर्तमान फ़ोल्डर: ",
        "(खाली फ़ोल्डर)",
        "[फ़ोल्डर] ",
        "---------------------------------------",
        "कमांड: नाम +",
        ".. -> ऊपर, del -> हटाएँ, cp -> कॉपी, mv -> मूव,",
        "rn -> नाम बदलें, edit -> संपादित करें, md या mkdir -> नया फ़ोल्डर, exit -> बाहर",
        "चयन: "
    },

    // LATIN (23)
    {
        "--- Directorium currente: ",
        "(Directorium vacuum)",
        "[DIRECTORIUM] ",
        "---------------------------------------",
        "Mandata: nomen +",
        ".. -> retro, del -> delere, cp -> copiare, mv -> movere,",
        "rn -> renominare, edit -> recensere, md vel mkdir -> novum directorium, exit -> exire",
        "Electio: "
    }
};

//==========================================================================
static const std::vector<RenameFilesAndFolders> renameFilesAndFoldersTranslations_hardcoded {

    { // Hungarian (Index 0)
        "Átnevezendő: ",
        "Új név: ",
        "Veszélyes útvonal!: "
    },

    // ENGLISH (Index 1)
    {
        "Rename: ",
        "New name: ",
        "Dangerous path!: "
    },

    // CHINESE (Index 2)
    {
        "重命名: ",
        "新名称: ",
        "危险路径!: "
    },

    // JAPANESE (Index 3)
    {
        "名前変更: ",
        "新しい名前: ",
        "危険なパス!: "
    },

    // SPANISH (Index 4)
    {
        "Renombrar: ",
        "Nuevo nombre: ",
        "Ruta peligrosa!: "
    },

    // GERMAN (Index 5)
    {
        "Umbenennen: ",
        "Neuer Name: ",
        "Gefährlicher Pfad!: "
    },

    // FRENCH (Index 6)
    {
        "Renommer: ",
        "Nouveau nom: ",
        "Chemin dangereux!: "
    },

    // RUSSIAN (Index 7)
    {
        "Переименовать: ",
        "Новое имя: ",
        "Опасный путь!: "
    },

    // UKRAINIAN (Index 8)
    {
        "Перейменувати: ",
        "Нове ім'я: ",
        "Небезпечний шлях!: "
    },

    // KOREAN (Index 9)
    {
        "이름 변경: ",
        "새 이름: ",
        "위험한 경로!: "
    },

    // ITALIAN (Index 10)
    {
        "Rinomina: ",
        "Nuovo nome: ",
        "Percorso pericoloso!: "
    },

    // POLISH (Index 11)
    {
        "Zmień nazwę: ",
        "Nowa nazwa: ",
        "Niebezpieczna ścieżka!: "
    },

    // ARABIC (Index 12)
    {
        "إعادة تسمية: ",
        "اسم جديد: ",
        "مسار خطير!: "
    },

    // VIETNAMESE (Index 13)
    {
        "Đổi tên: ",
        "Tên mới: ",
        "Đường dẫn nguy hiểm!: "
    },

    // TAGALOG (Index 14)
    {
        "Palitan ang pangalan: ",
        "Bagong pangalan: ",
        "Mapanganib na landas!: "
    },

    // GREEK (Index 15)
    {
        "Μετονομασία: ",
        "Νέο όνομα: ",
        "Επικίνδυνη διαδρομή!: "
    },

    // HEBREW (Index 16)
    {
        "שנה שם: ",
        "שם חדש: ",
        "נתיב מסוכן!: "
    },

    // PORTUGUESE (Index 17)
    {
        "Renomear: ",
        "Novo nome: ",
        "Caminho perigoso!: "
    },

    // FARSI (Index 18)
    {
        "تغییر نام: ",
        "نام جدید: ",
        "مسیر خطرناک!: "
    },

    // SWEDISH (Index 19)
    {
        "Byt namn: ",
        "Nytt namn: ",
        "Farlig sökväg!: "
    },

    // DUTCH (Index 20)
    {
        "Hernoemen: ",
        "Nieuwe naam: ",
        "Gevaarlijk pad!: "
    },

    // TURKISH (Index 21)
    {
        "Yeniden adlandır: ",
        "Yeni ad: ",
        "Tehlikeli yol!: "
    },

    // HINDI (Index 22)
    {
        "नाम बदलें: ",
        "नया नाम: ",
        "खतरनाक पथ!: "
    },

    // LATIN (Index 23)
    {
        "Renominare: ",
        "Novum nomen: ",
        "Iter periculosum!: "
    }
};


//==========================================================================
static const std::vector<MovingFileFolders> movingFileFoldersTranslations_hardcoded {

    { //hungarian (index 0)
        "Áthelyezendő: ",
        "Új név/útvonal: ",
        "Veszélyes útvonal!: "
    },

    // ENGLISH (index 1)
    {
        "Move: ",
        "New name/path: ",
        "Dangerous path!: "
    },

    // CHINESE (index 2)
    {
        "移动: ",
        "新名称/路径: ",
        "危险路径!: "
    },

    // JAPANESE (index 3)
    {
        "移動: ",
        "新しい名前/パス: ",
        "危険なパス!: "
    },

    // SPANISH (index 4)
    {
        "Mover: ",
        "Nuevo nombre/ruta: ",
        "Ruta peligrosa!: "
    },

    // GERMAN (index 5)
    {
        "Verschieben: ",
        "Neuer Name/Pfad: ",
        "Gefährlicher Pfad!: "
    },

    // FRENCH (index 6)
    {
        "Déplacer: ",
        "Nouveau nom/chemin: ",
        "Chemin dangereux!: "
    },

    // RUSSIAN (index 7)
    {
        "Переместить: ",
        "Новое имя/путь: ",
        "Опасный путь!: "
    },

    // UKRAINIAN (index 8)
    {
        "Перемістити: ",
        "Нове ім'я/шлях: ",
        "Небезпечний шлях!: "
    },

    // KOREAN (index 9)
    {
        "이동: ",
        "새 이름/경로: ",
        "위험한 경로!: "
    },

    // ITALIAN (index 10)
    {
        "Sposta: ",
        "Nuovo nome/percorso: ",
        "Percorso pericoloso!: "
    },

    // POLISH (index 11)
    {
        "Przenieś: ",
        "Nowa nazwa/ścieżka: ",
        "Niebezpieczna ścieżka!: "
    },

    // ARABIC (index 12)
    {
        "نقل: ",
        "اسم/مسار جديد: ",
        "مسار خطير!: "
    },

    // VIETNAMESE (index 13)
    {
        "Di chuyển: ",
        "Tên/đường dẫn mới: ",
        "Đường dẫn nguy hiểm!: "
    },

    // TAGALOG (index 14)
    {
        "Ilipat: ",
        "Bagong pangalan/landas: ",
        "Mapanganib na landas!: "
    },

    // GREEK (index 15)
    {
        "Μετακίνηση: ",
        "Νέο όνομα/διαδρομή: ",
        "Επικίνδυνη διαδρομή!: "
    },

    // HEBREW (index 16)
    {
        "העבר: ",
        "שם/נתיב חדש: ",
        "נתיב מסוכן!: "
    },

    // PORTUGUESE (index 17)
    {
        "Mover: ",
        "Novo nome/caminho: ",
        "Caminho perigoso!: "
    },

    // FARSI (index 18)
    {
        "انتقال: ",
        "نام/مسیر جدید: ",
        "مسیر خطرناک!: "
    },

    // SWEDISH (index 19)
    {
        "Flytta: ",
        "Nytt namn/sökväg: ",
        "Farlig sökväg!: "
    },

    // DUTCH (index 20)
    {
        "Verplaatsen: ",
        "Nieuwe naam/pad: ",
        "Gevaarlijk pad!: "
    },

    // TURKISH (index 21)
    {
        "Taşı: ",
        "Yeni ad/yol: ",
        "Tehlikeli yol!: "
    },

    // HINDI (index 22)
    {
        "स्थानांतरित करें: ",
        "नया नाम/पथ: ",
        "खतरनाक पथ!: "
    },

    // LATIN (index 23)
    {
        "Transferre: ",
        "Novum nomen/iter: ",
        "Iter periculosum!: "
    }
};



//==========================================================================
static const std::vector<DeleteFileFolders> deleteFileFoldersTranslations_hardcoded {


    // Hungarian (0)
    {
        "Hiba: Veszélyes útvonal!",
        "Biztosan törölni szeretnéd: ",
        "Sikeresen törölve",
        "Megszakítva",
        "Hiba a törlésnél! Ellenőrizd az útvonalat."
    },

    // ENGLISH (1)
    {
        "Error: Dangerous path!",
        "Are you sure you want to delete: ",
        "Successfully deleted",
        "Cancelled",
        "Error during deletion! Check the path."
    },

    // CHINESE (2)
    {
        "错误：危险路径！",
        "你确定要删除吗: ",
        "删除成功",
        "已取消",
        "删除时出错！请检查路径。"
    },

    // JAPANESE (3)
    {
        "エラー：危険なパス！",
        "本当に削除しますか: ",
        "削除に成功しました",
        "キャンセルされました",
        "削除中にエラーが発生しました！パスを確認してください。"
    },

    // SPANISH (4)
    {
        "Error: ¡Ruta peligrosa!",
        "¿Seguro que deseas eliminar: ",
        "Eliminado correctamente",
        "Cancelado",
        "Error al eliminar. Verifica la ruta."
    },

    // GERMAN (5)
    {
        "Fehler: Gefährlicher Pfad!",
        "Möchten Sie wirklich löschen: ",
        "Erfolgreich gelöscht",
        "Abgebrochen",
        "Fehler beim Löschen! Pfad prüfen."
    },

    // FRENCH (6)
    {
        "Erreur : chemin dangereux !",
        "Êtes-vous sûr de vouloir supprimer : ",
        "Supprimé avec succès",
        "Annulé",
        "Erreur lors de la suppression ! Vérifiez le chemin."
    },

    // RUSSIAN (7)
    {
        "Ошибка: опасный путь!",
        "Вы уверены, что хотите удалить: ",
        "Успешно удалено",
        "Отменено",
        "Ошибка при удалении! Проверьте путь."
    },

    // UKRAINIAN (8)
    {
        "Помилка: небезпечний шлях!",
        "Ви впевнені, що хочете видалити: ",
        "Успішно видалено",
        "Скасовано",
        "Помилка при видаленні! Перевірте шлях."
    },

    // KOREAN (9)
    {
        "오류: 위험한 경로!",
        "정말 삭제하시겠습니까: ",
        "성공적으로 삭제됨",
        "취소됨",
        "삭제 중 오류 발생! 경로를 확인하세요."
    },

    // ITALIAN (10)
    {
        "Errore: percorso pericoloso!",
        "Sei sicuro di voler eliminare: ",
        "Eliminato con successo",
        "Annullato",
        "Errore durante l'eliminazione! Controlla il percorso."
    },

    // POLISH (11)
    {
        "Błąd: niebezpieczna ścieżka!",
        "Czy na pewno chcesz usunąć: ",
        "Pomyślnie usunięto",
        "Anulowano",
        "Błąd podczas usuwania! Sprawdź ścieżkę."
    },

    // ARABIC (12)
    {
        "خطأ: مسار خطير!",
        "هل أنت متأكد أنك تريد الحذف: ",
        "تم الحذف بنجاح",
        "تم الإلغاء",
        "خطأ أثناء الحذف! تحقق من المسار."
    },

    // VIETNAMESE (13)
    {
        "Lỗi: đường dẫn nguy hiểm!",
        "Bạn có chắc muốn xóa: ",
        "Đã xóa thành công",
        "Đã hủy",
        "Lỗi khi xóa! Kiểm tra đường dẫn."
    },

    // TAGALOG (14)
    {
        "Error: Delikadong landas!",
        "Sigurado ka bang gusto mong burahin: ",
        "Matagumpay na natanggal",
        "Nakansela",
        "Error sa pagtanggal! Suriin ang landas."
    },

    // GREEK (15)
    {
        "Σφάλμα: επικίνδυνη διαδρομή!",
        "Είστε σίγουροι ότι θέλετε να διαγράψετε: ",
        "Διαγράφηκε με επιτυχία",
        "Ακυρώθηκε",
        "Σφάλμα κατά τη διαγραφή! Ελέγξτε τη διαδρομή."
    },

    // HEBREW (16)
    {
        "שגיאה: נתיב מסוכן!",
        "האם אתה בטוח שברצונך למחוק: ",
        "נמחק בהצלחה",
        "בוטל",
        "שגיאה במחיקה! בדוק את הנתיב."
    },

    // PORTUGUESE (17)
    {
        "Erro: caminho perigoso!",
        "Tem certeza de que deseja excluir: ",
        "Excluído com sucesso",
        "Cancelado",
        "Erro ao excluir! Verifique o caminho."
    },

    // FARSI (18)
    {
        "خطا: مسیر خطرناک!",
        "آیا مطمئن هستید که می‌خواهید حذف کنید: ",
        "با موفقیت حذف شد",
        "لغو شد",
        "خطا در حذف! مسیر را بررسی کنید."
    },

    // SWEDISH (19)
    {
        "Fel: farlig sökväg!",
        "Är du säker på att du vill ta bort: ",
        "Raderades framgångsrikt",
        "Avbruten",
        "Fel vid borttagning! Kontrollera sökvägen."
    },

    // DUTCH (20)
    {
        "Fout: gevaarlijk pad!",
        "Weet je zeker dat je wilt verwijderen: ",
        "Succesvol verwijderd",
        "Geannuleerd",
        "Fout bij verwijderen! Controleer het pad."
    },

    // TURKISH (21)
    {
        "Hata: tehlikeli yol!",
        "Silmek istediğinizden emin misiniz: ",
        "Başarıyla silindi",
        "İptal edildi",
        "Silme hatası! Yolu kontrol et."
    },

    // HINDI (22)
    {
        "त्रुटि: खतरनाक पथ!",
        "क्या आप वाकई हटाना चाहते हैं: ",
        "सफलतापूर्वक हटाया गया",
        "रद्द किया गया",
        "हटाने में त्रुटि! पथ जांचें।"
    },

    // LATIN (23)
    {
        "Error: iter periculosum!",
        "Certus es te delere velle: ",
        "Feliciter deletum",
        "Abrogatum",
        "Error in deletione! Iter verifica."
    }

};


//==========================================================================
static const std::vector<CopyFileFolders> copyFileFoldersTranslations_hardcoded {

    { // Hungarian (Index 0)
        "Hiba: Veszélyes forrás útvonal!",
        "Másolandó: ",
        "Útvonal/Új név",
        "pl: (./data/mappaNeve/fajl.data): ",
        "Hiba: Veszélyes cél útvonal!",
        "Sikeres másolás!",
        "Hiba történt!"
    },

    { // English (Index 1)
        "Error: Dangerous source path!",
        "Copying: ",
        "Path/New name",
        "e.g.: (./data/folderName/file.data): ",
        "Error: Dangerous destination path!",
        "Copy successful!",
        "An error occurred!"
    },

    { // Chinese (Index 2)
        "错误：危险的源路径！",
        "正在复制：",
        "路径/新名称",
        "例如：(./data/文件夹/文件.data)：",
        "错误：危险的目标路径！",
        "复制成功！",
        "发生错误！"
    },

    { // Japanese (Index 3)
        "エラー：危険なソースパス！",
        "コピー中：",
        "パス/新しい名前",
        "例：(./data/フォルダ/ファイル.data)：",
        "エラー：危険な宛先パス！",
        "コピー成功！",
        "エラーが発生しました！"
    },

    { // Spanish (Index 4)
        "Error: ¡Ruta de origen peligrosa!",
        "Copiando: ",
        "Ruta/Nuevo nombre",
        "ej.: (./data/carpeta/archivo.data): ",
        "Error: ¡Ruta de destino peligrosa!",
        "¡Copia exitosa!",
        "¡Ocurrió un error!"
    },

    { // German (Index 5)
        "Fehler: Gefährlicher Quellpfad!",
        "Kopiere: ",
        "Pfad/Neuer Name",
        "z.B.: (./data/ordner/datei.data): ",
        "Fehler: Gefährlicher Zielpfad!",
        "Kopieren erfolgreich!",
        "Ein Fehler ist aufgetreten!"
    },

    { // French (Index 6)
        "Erreur : Chemin source dangereux !",
        "Copie : ",
        "Chemin/Nouveau nom",
        "ex : (./data/dossier/fichier.data) : ",
        "Erreur : Chemin de destination dangereux !",
        "Copie réussie !",
        "Une erreur est survenue !"
    },

    { // Russian (Index 7)
        "Ошибка: Опасный исходный путь!",
        "Копирование: ",
        "Путь/Новое имя",
        "напр.: (./data/папка/файл.data): ",
        "Ошибка: Опасный путь назначения!",
        "Копирование успешно!",
        "Произошла ошибка!"
    },

    { // Ukrainian (Index 8)
        "Помилка: Небезпечний шлях джерела!",
        "Копіювання: ",
        "Шлях/Нове ім'я",
        "напр.: (./data/папка/файл.data): ",
        "Помилка: Небезпечний шлях призначення!",
        "Копіювання успішне!",
        "Сталася помилка!"
    },

    { // Korean (Index 9)
        "오류: 위험한 원본 경로!",
        "복사 중: ",
        "경로/새 이름",
        "예: (./data/폴더/파일.data): ",
        "오류: 위험한 대상 경로!",
        "복사 성공!",
        "오류 발생!"
    },

    { // Italian (Index 10)
        "Errore: Percorso sorgente pericoloso!",
        "Copia in corso: ",
        "Percorso/Nuovo nome",
        "es.: (./data/cartella/file.data): ",
        "Errore: Percorso destinazione pericoloso!",
        "Copia riuscita!",
        "Si è verificato un errore!"
    },

    { // Polish (Index 11)
        "Błąd: Niebezpieczna ścieżka źródłowa!",
        "Kopiowanie: ",
        "Ścieżka/Nowa nazwa",
        "np.: (./data/folder/plik.data): ",
        "Błąd: Niebezpieczna ścieżka docelowa!",
        "Kopiowanie zakończone sukcesem!",
        "Wystąpił błąd!"
    },

    { // Arabic (Index 12)
        "خطأ: مسار مصدر خطير!",
        "جاري النسخ: ",
        "المسار/اسم جديد",
        "مثال: (./data/مجلد/ملف.data): ",
        "خطأ: مسار وجهة خطير!",
        "تم النسخ بنجاح!",
        "حدث خطأ!"
    },

    { // Vietnamese (Index 13)
        "Lỗi: Đường dẫn nguồn nguy hiểm!",
        "Đang sao chép: ",
        "Đường dẫn/Tên mới",
        "ví dụ: (./data/thumuc/tep.data): ",
        "Lỗi: Đường dẫn đích nguy hiểm!",
        "Sao chép thành công!",
        "Đã xảy ra lỗi!"
    },

    { // Tagalog (Index 14)
        "Error: Mapanganib na source path!",
        "Kinokopya: ",
        "Path/Bagong pangalan",
        "hal: (./data/folder/file.data): ",
        "Error: Mapanganib na destination path!",
        "Tagumpay ang pagkopya!",
        "May naganap na error!"
    },

    { // Greek (Index 15)
        "Σφάλμα: Επικίνδυνη διαδρομή πηγής!",
        "Αντιγραφή: ",
        "Διαδρομή/Νέο όνομα",
        "π.χ.: (./data/φάκελος/αρχείο.data): ",
        "Σφάλμα: Επικίνδυνη διαδρομή προορισμού!",
        "Επιτυχής αντιγραφή!",
        "Παρουσιάστηκε σφάλμα!"
    },

    { // Hebrew (Index 16)
        "שגיאה: נתיב מקור מסוכן!",
        "מעתיק: ",
        "נתיב/שם חדש",
        "לדוגמה: (./data/תיקיה/קובץ.data): ",
        "שגיאה: נתיב יעד מסוכן!",
        "ההעתקה הצליחה!",
        "אירעה שגיאה!"
    },

    { // Portuguese (Index 17)
        "Erro: Caminho de origem perigoso!",
        "Copiando: ",
        "Caminho/Novo nome",
        "ex.: (./data/pasta/arquivo.data): ",
        "Erro: Caminho de destino perigoso!",
        "Cópia bem-sucedida!",
        "Ocorreu um erro!"
    },

    { // Farsi (Index 18)
        "خطا: مسیر مبدأ خطرناک!",
        "در حال کپی: ",
        "مسیر/نام جدید",
        "مثال: (./data/پوشه/فایل.data): ",
        "خطا: مسیر مقصد خطرناک!",
        "کپی موفق!",
        "خطایی رخ داد!"
    },

    { // Swedish (Index 19)
        "Fel: Farlig källsökväg!",
        "Kopierar: ",
        "Sökväg/Nytt namn",
        "t.ex.: (./data/mapp/fil.data): ",
        "Fel: Farlig målsökväg!",
        "Kopiering lyckades!",
        "Ett fel uppstod!"
    },

    { // Dutch (Index 20)
        "Fout: Gevaarlijk bronpad!",
        "Kopiëren: ",
        "Pad/Nieuwe naam",
        "bijv.: (./data/map/bestand.data): ",
        "Fout: Gevaarlijk doelpad!",
        "Kopiëren gelukt!",
        "Er is een fout opgetreden!"
    },

    { // Turkish (Index 21)
        "Hata: Tehlikeli kaynak yolu!",
        "Kopyalanıyor: ",
        "Yol/Yeni ad",
        "örn.: (./data/klasor/dosya.data): ",
        "Hata: Tehlikeli hedef yolu!",
        "Kopyalama başarılı!",
        "Bir hata oluştu!"
    },

    { // Hindi (Index 22)
        "त्रुटि: खतरनाक स्रोत पथ!",
        "कॉपी हो रहा है: ",
        "पथ/नया नाम",
        "उदाहरण: (./data/folder/file.data): ",
        "त्रुटि: खतरनाक गंतव्य पथ!",
        "कॉपी सफल!",
        "एक त्रुटि हुई!"
    },

    { // Latin (Index 23)
        "Error: Via fontis periculosa!",
        "Copia: ",
        "Via/Nomen novum",
        "ex: (./data/folder/file.data): ",
        "Error: Via destinationis periculosa!",
        "Copia felix!",
        "Error accidit!"
    }

};

//==========================================================================
static const std::vector<W_wordPair> wordPairErrorTranslations_hardcoded {

        {
            "Hiba a fájlt nem sikerült megnyitni: "
        } ,
    // ENGLISH (Index 1)
    {
        "Error: Failed to open file: "
    },

    // CHINESE (Index 2)
    {
        "错误：无法打开文件："
    },

    // JAPANESE (Index 3)
    {
        "エラー：ファイルを開けませんでした："
    },

    // SPANISH (Index 4)
    {
        "Error: No se pudo abrir el archivo: "
    },

    // GERMAN (Index 5)
    {
        "Fehler: Datei konnte nicht geöffnet werden: "
    },

    // FRENCH (Index 6)
    {
        "Erreur : Impossible d'ouvrir le fichier : "
    },

    // RUSSIAN (Index 7)
    {
        "Ошибка: Не удалось открыть файл: "
    },

    // UKRAINIAN (Index 8)
    {
        "Помилка: Не вдалося відкрити файл: "
    },

    // KOREAN (Index 9)
    {
        "오류: 파일을 열 수 없습니다: "
    },

    // ITALIAN (Index 10)
    {
        "Errore: Impossibile aprire il file: "
    },

    // POLISH (Index 11)
    {
        "Błąd: Nie można otworzyć pliku: "
    },

    // ARABIC (Index 12)
    {
        "خطأ: فشل في فتح الملف: "
    },

    // VIETNAMESE (Index 13)
    {
        "Lỗi: Không thể mở tệp: "
    },

    // TAGALOG (Index 14)
    {
        "Error: Hindi mabuksan ang file: "
    },

    // GREEK (Index 15)
    {
        "Σφάλμα: Αδυναμία ανοίγματος αρχείου: "
    },

    // HEBREW (Index 16)
    {
        "שגיאה: לא ניתן לפתוח את הקובץ: "
    },

    // PORTUGUESE (Index 17)
    {
        "Erro: Falha ao abrir o arquivo: "
    },

    // FARSI (Index 18)
    {
        "خطا: باز کردن فایل ناموفق بود: "
    },

    // SWEDISH (Index 19)
    {
        "Fel: Kunde inte öppna filen: "
    },

    // DUTCH (Index 20)
    {
        "Fout: Kan bestand niet openen: "
    },

    // TURKISH (Index 21)
    {
        "Hata: Dosya açılamadı: "
    },

    // HINDI (Index 22)
    {
        "त्रुटि: फ़ाइल नहीं खोली जा सकी: "
    },

    // LATIN (Index 23)
    {
        "Error: File aperire non potuit: "
    }
};


//==========================================================================
static const std::vector<LlistAndSelectedFile> LlistAndSelectedFileTranslations_hardcoded {



    { // Hungarian (Index 0)
        "Hiba: Csak .data kiterjesztésű fájlokat tölthetsz be!"
    },

    // ENGLISH (Index 1)
    {
        "Error: Only .data files can be loaded!"
    },

    // CHINESE (Index 2)
    {
        "错误：只能加载 .data 文件！"
    },

    // JAPANESE (Index 3)
    {
        "エラー：.data ファイルのみ読み込めます！"
    },

    // SPANISH (Index 4)
    {
        "Error: ¡Solo se pueden cargar archivos .data!"
    },

    // GERMAN (Index 5)
    {
        "Fehler: Es können nur .data-Dateien geladen werden!"
    },

    // FRENCH (Index 6)
    {
        "Erreur : seuls les fichiers .data peuvent être chargés !"
    },

    // RUSSIAN (Index 7)
    {
        "Ошибка: можно загружать только файлы .data!"
    },

    // UKRAINIAN (Index 8)
    {
        "Помилка: можна завантажувати лише файли .data!"
    },

    // KOREAN (Index 9)
    {
        "오류: .data 파일만 불러올 수 있습니다!"
    },

    // ITALIAN (Index 10)
    {
        "Errore: È possibile caricare solo file .data!"
    },

    // POLISH (Index 11)
    {
        "Błąd: Można ładować tylko pliki .data!"
    },

    // ARABIC (Index 12)
    {
        "خطأ: يمكن تحميل ملفات .data فقط!"
    },

    // VIETNAMESE (Index 13)
    {
        "Lỗi: Chỉ có thể tải các tệp .data!"
    },

    // TAGALOG (Index 14)
    {
        "Error: Tanging mga .data file lamang ang maaaring i-load!"
    },

    // GREEK (Index 15)
    {
        "Σφάλμα: Μόνο αρχεία .data μπορούν να φορτωθούν!"
    },

    // HEBREW (Index 16)
    {
        "שגיאה: ניתן לטעון רק קבצי .data!"
    },

    // PORTUGUESE (Index 17)
    {
        "Erro: Apenas arquivos .data podem ser carregados!"
    },

    // FARSI (Index 18)
    {
        "خطا: فقط فایل‌های .data قابل بارگذاری هستند!"
    },

    // SWEDISH (Index 19)
    {
        "Fel: Endast .data-filer kan laddas!"
    },

    // DUTCH (Index 20)
    {
        "Fout: Alleen .data-bestanden kunnen worden geladen!"
    },

    // TURKISH (Index 21)
    {
        "Hata: Yalnızca .data dosyaları yüklenebilir!"
    },

    // HINDI (Index 22)
    {
        "त्रुटि: केवल .data फ़ाइलें ही लोड की जा सकती हैं!"
    },

    // LATIN (Index 23)
    {
        "Error: Solum fasciculi .data onerari possunt!"
    }
};

//==========================================================================
static const std::vector<OosEditor> OosEditorTranslations_hardcoded {

    { // Hungarian (Index 0)
        "A Szövegszerkesztő inditása...",
        "Az edit.com nem található vagy hiba törtent.A Notepad inditása...",
        "Hiba törtent a szövegSzerkesztő inditása küzben! (Hibakód: "
    },
    // ENGLISH (Index 1)
    {
        "Starting text editor...",
        "edit.com not found or error occurred. Starting Notepad...",
        "An error occurred while starting the text editor! (Error code: "
    },

    // CHINESE (Index 2)
    {
        "正在启动文本编辑器...",
        "未找到 edit.com 或发生错误。正在启动记事本...",
        "启动文本编辑器时发生错误！(错误代码："
    },

    // JAPANESE (Index 3)
    {
        "テキストエディタを起動しています...",
        "edit.com が見つからないかエラーが発生しました。メモ帳を起動します...",
        "テキストエディタの起動中にエラーが発生しました！(エラーコード: "
    },

    // SPANISH (Index 4)
    {
        "Iniciando el editor de texto...",
        "edit.com no encontrado o ocurrió un error. Iniciando Notepad...",
        "¡Ocurrió un error al iniciar el editor de texto! (Código de error: "
    },

    // GERMAN (Index 5)
    {
        "Texteditor wird gestartet...",
        "edit.com nicht gefunden oder Fehler aufgetreten. Notepad wird gestartet...",
        "Fehler beim Starten des Texteditors! (Fehlercode: "
    },

    // FRENCH (Index 6)
    {
        "Démarrage de l'éditeur de texte...",
        "edit.com introuvable ou erreur. Lancement de Notepad...",
        "Une erreur s'est produite lors du démarrage de l'éditeur de texte ! (Code d'erreur : "
    },

    // RUSSIAN (Index 7)
    {
        "Запуск текстового редактора...",
        "edit.com не найден или произошла ошибка. Запуск Блокнота...",
        "Ошибка при запуске текстового редактора! (Код ошибки: "
    },

    // UKRAINIAN (Index 8)
    {
        "Запуск текстового редактора...",
        "edit.com не знайдено або сталася помилка. Запуск Блокнота...",
        "Помилка під час запуску текстового редактора! (Код помилки: "
    },

    // KOREAN (Index 9)
    {
        "텍스트 편집기 시작 중...",
        "edit.com을 찾을 수 없거나 오류가 발생했습니다. 메모장을 시작합니다...",
        "텍스트 편집기 시작 중 오류가 발생했습니다! (오류 코드: "
    },

    // ITALIAN (Index 10)
    {
        "Avvio dell'editor di testo...",
        "edit.com non trovato o errore. Avvio del Blocco note...",
        "Si è verificato un errore durante l'avvio dell'editor di testo! (Codice errore: "
    },

    // POLISH (Index 11)
    {
        "Uruchamianie edytora tekstu...",
        "Nie znaleziono edit.com lub wystąpił błąd. Uruchamianie Notatnika...",
        "Wystąpił błąd podczas uruchamiania edytora tekstu! (Kod błędu: "
    },

    // ARABIC (Index 12)
    {
        "جارٍ تشغيل محرر النصوص...",
        "لم يتم العثور على edit.com أو حدث خطأ. جارٍ تشغيل المفكرة...",
        "حدث خطأ أثناء تشغيل محرر النصوص! (رمز الخطأ: "
    },

    // VIETNAMESE (Index 13)
    {
        "Đang khởi động trình soạn thảo văn bản...",
        "Không tìm thấy edit.com hoặc xảy ra lỗi. Đang mở Notepad...",
        "Đã xảy ra lỗi khi khởi động trình soạn thảo! (Mã lỗi: "
    },

    // TAGALOG (Index 14)
    {
        "Sinisimulan ang text editor...",
        "Hindi natagpuan ang edit.com o may error. Sinisimulan ang Notepad...",
        "Nagkaroon ng error habang sinisimulan ang text editor! (Error code: "
    },

    // GREEK (Index 15)
    {
        "Εκκίνηση επεξεργαστή κειμένου...",
        "Το edit.com δεν βρέθηκε ή προέκυψε σφάλμα. Εκκίνηση Σημειωματάριου...",
        "Παρουσιάστηκε σφάλμα κατά την εκκίνηση του επεξεργαστή κειμένου! (Κωδικός σφάλματος: "
    },

    // HEBREW (Index 16)
    {
        "הפעלת עורך הטקסט...",
        "edit.com לא נמצא או אירעה שגיאה. מפעיל את פנקס הרשימות...",
        "אירעה שגיאה בעת הפעלת עורך הטקסט! (קוד שגיאה: "
    },

    // PORTUGUESE (Index 17)
    {
        "Iniciando o editor de texto...",
        "edit.com não encontrado ou ocorreu erro. Iniciando o Bloco de Notas...",
        "Ocorreu um erro ao iniciar o editor de texto! (Código de erro: "
    },

    // FARSI (Index 18)
    {
        "در حال اجرای ویرایشگر متن...",
        "edit.com یافت نشد یا خطایی رخ داد. در حال اجرای Notepad...",
        "خطا در هنگام اجرای ویرایشگر متن! (کد خطا: "
    },

    // SWEDISH (Index 19)
    {
        "Startar textredigerare...",
        "edit.com hittades inte eller ett fel uppstod. Startar Anteckningar...",
        "Ett fel uppstod när textredigeraren startades! (Felkod: "
    },

    // DUTCH (Index 20)
    {
        "Teksteditor starten...",
        "edit.com niet gevonden of er is een fout opgetreden. Notepad starten...",
        "Er is een fout opgetreden bij het starten van de teksteditor! (Foutcode: "
    },

    // TURKISH (Index 21)
    {
        "Metin düzenleyici başlatılıyor...",
        "edit.com bulunamadı veya hata oluştu. Not Defteri başlatılıyor...",
        "Metin düzenleyici başlatılırken hata oluştu! (Hata kodu: "
    },

    // HINDI (Index 22)
    {
        "टेक्स्ट एडिटर शुरू किया जा रहा है...",
        "edit.com नहीं मिला या त्रुटि हुई। नोटपैड शुरू किया जा रहा है...",
        "टेक्स्ट एडिटर शुरू करते समय त्रुटि हुई! (त्रुटि कोड: "
    },

    // LATIN (Index 23)
    {
        "Editor textus incipitur...",
        "edit.com non inventum est aut error factus est. Notepad incipitur...",
        "Error factus est dum editor textus incipitur! (Codex erroris: "
    }
};

//==========================================================================
static const std::vector<BackgroundSets> backgroundSetsTranslations_hardcoded {

    { // Hungarian (Index 0)
        "--- A Háttérszín beállítása ---",
        "1. Alapértelmezett (fekete)",
        "2. Zöld",
        "3. Cián",
        "4. Piros",
        "5. Lila",
        "6. Kék",
        "7. Fehér",
        "8. Szürke",
        "9. Visszalépés",
        "A háttérszín sikeresen megváltoztatva!",
        "A háttér színe: "
    },

    // ENGLISH (Index 1)
    {
        "--- Background Color Settings ---",
        "1. Default (black)",
        "2. Green",
        "3. Cyan",
        "4. Red",
        "5. Purple",
        "6. Blue",
        "7. White",
        "8. Gray",
        "9. Back",
        "Background color successfully changed!",
        "Background color: "
    },

    // CHINESE (Index 2)
    {
        "--- 背景颜色设置 ---",
        "1. 默认（黑色）",
        "2. 绿色",
        "3. 青色",
        "4. 红色",
        "5. 紫色",
        "6. 蓝色",
        "7. 白色",
        "8. 灰色",
        "9. 返回",
        "背景颜色修改成功！",
        "背景颜色："
    },

    // JAPANESE (Index 3)
    {
        "--- 背景色設定 ---",
        "1. デフォルト（黒）",
        "2. 緑",
        "3. シアン",
        "4. 赤",
        "5. 紫",
        "6. 青",
        "7. 白",
        "8. 灰色",
        "9. 戻る",
        "背景色が正常に変更されました！",
        "背景色："
    },

    // SPANISH (Index 4)
    {
        "--- Configuración de color de fondo ---",
        "1. Predeterminado (negro)",
        "2. Verde",
        "3. Cian",
        "4. Rojo",
        "5. Morado",
        "6. Azul",
        "7. Blanco",
        "8. Gris",
        "9. Volver",
        "¡Color de fondo cambiado correctamente!",
        "Color de fondo: "
    },

    // GERMAN (Index 5)
    {
        "--- Hintergrundfarbe einstellen ---",
        "1. Standard (schwarz)",
        "2. Grün",
        "3. Cyan",
        "4. Rot",
        "5. Lila",
        "6. Blau",
        "7. Weiß",
        "8. Grau",
        "9. Zurück",
        "Hintergrundfarbe erfolgreich geändert!",
        "Hintergrundfarbe: "
    },

    // FRENCH (Index 6)
    {
        "--- Paramètres de couleur d'arrière-plan ---",
        "1. Par défaut (noir)",
        "2. Vert",
        "3. Cyan",
        "4. Rouge",
        "5. Violet",
        "6. Bleu",
        "7. Blanc",
        "8. Gris",
        "9. Retour",
        "Couleur d'arrière-plan modifiée avec succès !",
        "Couleur d'arrière-plan : "
    },

    // RUSSIAN (Index 7)
    {
        "--- Настройка цвета фона ---",
        "1. По умолчанию (чёрный)",
        "2. Зелёный",
        "3. Голубой",
        "4. Красный",
        "5. Фиолетовый",
        "6. Синий",
        "7. Белый",
        "8. Серый",
        "9. Назад",
        "Цвет фона успешно изменён!",
        "Цвет фона: "
    },

    // UKRAINIAN (Index 8)
    {
        "--- Налаштування кольору фону ---",
        "1. За замовчуванням (чорний)",
        "2. Зелений",
        "3. Блакитний",
        "4. Червоний",
        "5. Фіолетовий",
        "6. Синій",
        "7. Білий",
        "8. Сірий",
        "9. Назад",
        "Колір фону успішно змінено!",
        "Колір фону: "
    },

    // KOREAN (Index 9)
    {
        "--- 배경 색상 설정 ---",
        "1. 기본값 (검정)",
        "2. 초록",
        "3. 시안",
        "4. 빨강",
        "5. 보라",
        "6. 파랑",
        "7. 흰색",
        "8. 회색",
        "9. 뒤로",
        "배경 색상이 성공적으로 변경되었습니다!",
        "배경 색상: "
    },

    // ITALIAN (Index 10)
    {
        "--- Impostazioni colore sfondo ---",
        "1. Predefinito (nero)",
        "2. Verde",
        "3. Ciano",
        "4. Rosso",
        "5. Viola",
        "6. Blu",
        "7. Bianco",
        "8. Grigio",
        "9. Indietro",
        "Colore di sfondo modificato con successo!",
        "Colore di sfondo: "
    },

    // POLISH (Index 11)
    {
        "--- Ustawienia koloru tła ---",
        "1. Domyślny (czarny)",
        "2. Zielony",
        "3. Cyjan",
        "4. Czerwony",
        "5. Fioletowy",
        "6. Niebieski",
        "7. Biały",
        "8. Szary",
        "9. Powrót",
        "Kolor tła został zmieniony!",
        "Kolor tła: "
    },

    // ARABIC (Index 12)
    {
        "--- إعدادات لون الخلفية ---",
        "1. افتراضي (أسود)",
        "2. أخضر",
        "3. سماوي",
        "4. أحمر",
        "5. بنفسجي",
        "6. أزرق",
        "7. أبيض",
        "8. رمادي",
        "9. رجوع",
        "تم تغيير لون الخلفية بنجاح!",
        "لون الخلفية: "
    },

    // VIETNAMESE (Index 13)
    {
        "--- Cài đặt màu nền ---",
        "1. Mặc định (đen)",
        "2. Xanh lá",
        "3. Cyan",
        "4. Đỏ",
        "5. Tím",
        "6. Xanh dương",
        "7. Trắng",
        "8. Xám",
        "9. Quay lại",
        "Đã thay đổi màu nền thành công!",
        "Màu nền: "
    },

    // TAGALOG (Index 14)
    {
        "--- Setting ng kulay ng background ---",
        "1. Default (itim)",
        "2. Berde",
        "3. Cyan",
        "4. Pula",
        "5. Lila",
        "6. Asul",
        "7. Puti",
        "8. Abo",
        "9. Bumalik",
        "Matagumpay na nabago ang kulay ng background!",
        "Kulay ng background: "
    },

    // GREEK (Index 15)
    {
        "--- Ρυθμίσεις χρώματος φόντου ---",
        "1. Προεπιλογή (μαύρο)",
        "2. Πράσινο",
        "3. Κυανό",
        "4. Κόκκινο",
        "5. Μωβ",
        "6. Μπλε",
        "7. Λευκό",
        "8. Γκρι",
        "9. Πίσω",
        "Το χρώμα φόντου άλλαξε επιτυχώς!",
        "Χρώμα φόντου: "
    },

    // HEBREW (Index 16)
    {
        "--- הגדרות צבע רקע ---",
        "1. ברירת מחדל (שחור)",
        "2. ירוק",
        "3. ציאן",
        "4. אדום",
        "5. סגול",
        "6. כחול",
        "7. לבן",
        "8. אפור",
        "9. חזרה",
        "צבע הרקע שונה בהצלחה!",
        "צבע רקע: "
    },

    // PORTUGUESE (Index 17)
    {
        "--- Configurações de cor de fundo ---",
        "1. Padrão (preto)",
        "2. Verde",
        "3. Ciano",
        "4. Vermelho",
        "5. Roxo",
        "6. Azul",
        "7. Branco",
        "8. Cinza",
        "9. Voltar",
        "Cor de fundo alterada com sucesso!",
        "Cor de fundo: "
    },

    // FARSI (Index 18)
    {
        "--- تنظیم رنگ پس‌زمینه ---",
        "1. پیش‌فرض (مشکی)",
        "2. سبز",
        "3. فیروزه‌ای",
        "4. قرمز",
        "5. بنفش",
        "6. آبی",
        "7. سفید",
        "8. خاکستری",
        "9. بازگشت",
        "رنگ پس‌زمینه با موفقیت تغییر یافت!",
        "رنگ پس‌زمینه: "
    },

    // SWEDISH (Index 19)
    {
        "--- Inställningar för bakgrundsfärg ---",
        "1. Standard (svart)",
        "2. Grön",
        "3. Cyan",
        "4. Röd",
        "5. Lila",
        "6. Blå",
        "7. Vit",
        "8. Grå",
        "9. Tillbaka",
        "Bakgrundsfärgen ändrades!",
        "Bakgrundsfärg: "
    },

    // DUTCH (Index 20)
    {
        "--- Instellingen achtergrondkleur ---",
        "1. Standaard (zwart)",
        "2. Groen",
        "3. Cyaan",
        "4. Rood",
        "5. Paars",
        "6. Blauw",
        "7. Wit",
        "8. Grijs",
        "9. Terug",
        "Achtergrondkleur succesvol gewijzigd!",
        "Achtergrondkleur: "
    },

    // TURKISH (Index 21)
    {
        "--- Arka plan rengi ayarları ---",
        "1. Varsayılan (siyah)",
        "2. Yeşil",
        "3. Camgöbeği",
        "4. Kırmızı",
        "5. Mor",
        "6. Mavi",
        "7. Beyaz",
        "8. Gri",
        "9. Geri",
        "Arka plan rengi başarıyla değiştirildi!",
        "Arka plan rengi: "
    },

    // HINDI (Index 22)
    {
        "--- पृष्ठभूमि रंग सेटिंग्स ---",
        "1. डिफ़ॉल्ट (काला)",
        "2. हरा",
        "3. सियान",
        "4. लाल",
        "5. बैंगनी",
        "6. नीला",
        "7. सफेद",
        "8. ग्रे",
        "9. वापस",
        "पृष्ठभूमि रंग सफलतापूर्वक बदला गया!",
        "पृष्ठभूमि रंग: "
    },

    // LATIN (Index 23)
    {
        "--- Configurationes coloris fundi ---",
        "1. Default (niger)",
        "2. Viridis",
        "3. Cyanus",
        "4. Ruber",
        "5. Purpureus",
        "6. Caeruleus",
        "7. Albus",
        "8. Griseus",
        "9. Redire",
        "Color fundi feliciter mutatus est!",
        "Color fundi: "
    }
};

//==========================================================================
static const std::vector<SoundOnOff> soundOnOffTranslations_hardcoded {

    { // Hungarian (Index 0)
        "--- A hang beállítása ---",
        "Jelenlegi állapot: ",
        "BE",
        "KI",
        "1. Be/Ki kapcsolás",
        "0. Vissza",
        "Választás: ",
        "Hang bekapcsolva!",
        "Hang kikapcsolva!"
    },

    // ENGLISH (Index 1)
    {
        "--- Sound Settings ---",
        "Current state: ",
        "ON",
        "OFF",
        "1. Toggle On/Off",
        "0. Back",
        "Choice: ",
        "Sound enabled!",
        "Sound disabled!"
    },

    // CHINESE (Index 2)
    {
        "--- 声音设置 ---",
        "当前状态：",
        "开",
        "关",
        "1. 开/关切换",
        "0. 返回",
        "选择：",
        "声音已开启！",
        "声音已关闭！"
    },

    // JAPANESE (Index 3)
    {
        "--- サウンド設定 ---",
        "現在の状態：",
        "オン",
        "オフ",
        "1. オン/オフ切替",
        "0. 戻る",
        "選択：",
        "サウンドが有効になりました！",
        "サウンドが無効になりました！"
    },

    // SPANISH (Index 4)
    {
        "--- Configuración de sonido ---",
        "Estado actual: ",
        "ENCENDIDO",
        "APAGADO",
        "1. Activar/Desactivar",
        "0. Volver",
        "Elección: ",
        "¡Sonido activado!",
        "¡Sonido desactivado!"
    },

    // GERMAN (Index 5)
    {
        "--- Soundeinstellungen ---",
        "Aktueller Status: ",
        "AN",
        "AUS",
        "1. Ein/Aus umschalten",
        "0. Zurück",
        "Auswahl: ",
        "Sound eingeschaltet!",
        "Sound ausgeschaltet!"
    },

    // FRENCH (Index 6)
    {
        "--- Paramètres du son ---",
        "État actuel : ",
        "ACTIVÉ",
        "DÉSACTIVÉ",
        "1. Activer/Désactiver",
        "0. Retour",
        "Choix : ",
        "Son activé !",
        "Son désactivé !"
    },

    // RUSSIAN (Index 7)
    {
        "--- Настройки звука ---",
        "Текущее состояние: ",
        "ВКЛ",
        "ВЫКЛ",
        "1. Вкл/Выкл",
        "0. Назад",
        "Выбор: ",
        "Звук включён!",
        "Звук выключен!"
    },

    // UKRAINIAN (Index 8)
    {
        "--- Налаштування звуку ---",
        "Поточний стан: ",
        "УВІМК",
        "ВИМК",
        "1. Увімк/Вимк",
        "0. Назад",
        "Вибір: ",
        "Звук увімкнено!",
        "Звук вимкнено!"
    },

    // KOREAN (Index 9)
    {
        "--- 사운드 설정 ---",
        "현재 상태: ",
        "켜짐",
        "꺼짐",
        "1. 켜기/끄기",
        "0. 뒤로",
        "선택: ",
        "소리가 켜졌습니다!",
        "소리가 꺼졌습니다!"
    },

    // ITALIAN (Index 10)
    {
        "--- Impostazioni audio ---",
        "Stato attuale: ",
        "ON",
        "OFF",
        "1. Attiva/Disattiva",
        "0. Indietro",
        "Scelta: ",
        "Audio attivato!",
        "Audio disattivato!"
    },

    // POLISH (Index 11)
    {
        "--- Ustawienia dźwięku ---",
        "Aktualny stan: ",
        "WŁ",
        "WYŁ",
        "1. Włącz/Wyłącz",
        "0. Powrót",
        "Wybór: ",
        "Dźwięk włączony!",
        "Dźwięk wyłączony!"
    },

    // ARABIC (Index 12)
{
    "--- إعدادات الصوت ---",
    "الحالة الحالية: ",
    "تشغيل",
    "إيقاف",
    "1. تشغيل/إيقاف",
    "0. رجوع",
    "اختيار: ",
    "تم تشغيل الصوت!",
    "تم إيقاف الصوت!"
},

    // VIETNAMESE (Index 13)
    {
        "--- Cài đặt âm thanh ---",
        "Trạng thái hiện tại: ",
        "BẬT",
        "TẮT",
        "1. Bật/Tắt",
        "0. Quay lại",
        "Lựa chọn: ",
        "Âm thanh đã bật!",
        "Âm thanh đã tắt!"
    },

    // TAGALOG (Index 14)
    {
        "--- Setting ng tunog ---",
        "Kasalukuyang estado: ",
        "BUKAS",
        "SARADO",
        "1. On/Off",
        "0. Bumalik",
        "Pili: ",
        "Naka-on ang tunog!",
        "Naka-off ang tunog!"
    },

    // GREEK (Index 15)
    {
        "--- Ρυθμίσεις ήχου ---",
        "Τρέχουσα κατάσταση: ",
        "ΕΝΕΡΓΟ",
        "ΑΝΕΝΕΡΓΟ",
        "1. Ενεργοποίηση/Απενεργοποίηση",
        "0. Πίσω",
        "Επιλογή: ",
        "Ο ήχος ενεργοποιήθηκε!",
        "Ο ήχος απενεργοποιήθηκε!"
    },

    // HEBREW (Index 16)
{
    "--- הגדרות קול ---",
    "מצב נוכחי: ",
    "פועל",
    "כבוי",
    "1. הפעלה/כיבוי",
    "0. חזרה",
    "בחירה: ",
    "הקול הופעל!",
    "הקול כובה!"
},

    // PORTUGUESE (Index 17)
    {
        "--- Configurações de som ---",
        "Estado atual: ",
        "LIGADO",
        "DESLIGADO",
        "1. Ligar/Desligar",
        "0. Voltar",
        "Escolha: ",
        "Som ativado!",
        "Som desativado!"
    },

    // FARSI (Index 18)
{
    "--- تنظیمات صدا ---",
    "وضعیت فعلی: ",
    "روشن",
    "خاموش",
    "1. روشن/خاموش",
    "0. بازگشت",
    "انتخاب: ",
    "صدا روشن شد!",
    "صدا خاموش شد!"
},

    // SWEDISH (Index 19)
    {
        "--- Ljudinställningar ---",
        "Nuvarande status: ",
        "PÅ",
        "AV",
        "1. Slå på/av",
        "0. Tillbaka",
        "Val: ",
        "Ljudet är på!",
        "Ljudet är av!"
    },

    // DUTCH (Index 20)
    {
        "--- Geluidsinstellingen ---",
        "Huidige status: ",
        "AAN",
        "UIT",
        "1. Aan/Uit schakelen",
        "0. Terug",
        "Keuze: ",
        "Geluid ingeschakeld!",
        "Geluid uitgeschakeld!"
    },

    // TURKISH (Index 21)
    {
        "--- Ses ayarları ---",
        "Mevcut durum: ",
        "AÇIK",
        "KAPALI",
        "1. Aç/Kapat",
        "0. Geri",
        "Seçim: ",
        "Ses açıldı!",
        "Ses kapatıldı!"
    },

    // HINDI (Index 22)
    {
        "--- ध्वनि सेटिंग्स ---",
        "वर्तमान स्थिति: ",
        "चालू",
        "बंद",
        "1. चालू/बंद करें",
        "0. वापस",
        "चयन: ",
        "ध्वनि चालू की गई!",
        "ध्वनि बंद की गई!"
    },

    // LATIN (Index 23)
    {
        "--- Configurationes soni ---",
        "Status praesens: ",
        "ON",
        "OFF",
        "1. Accende/Extingue",
        "0. Redire",
        "Electio: ",
        "Sonus activatus est!",
        "Sonus deactivatus est!"
    }
};

//==========================================================================
static const std::vector<MistakeExercise> mistakeExerciseTranslations_hardcoded {

    // Hungarian (Index 0)
    {
        "--- A HIBÁS SZAVAK GYAKORLÁSA ---",
        "Szó vagy mondat: ",
        "Válasz: ",
        "A gyakorlás véget ért! A megmaradt hibák száma: "
    },

    // English (Index 1)
    {
        "--- ERROR WORD PRACTICE ---",
        "Word or sentence: ",
        "Answer: ",
        "Practice finished! Remaining mistakes: "
    },

    // Chinese (Index 2)
    {
        "--- 错误单词练习 ---",
        "单词或句子：",
        "答案：",
        "练习结束！剩余错误数量："
    },

    // Japanese (Index 3)
    {
        "--- 間違い単語の練習 ---",
        "単語または文：",
        "回答：",
        "練習終了！残りの間違い数："
    },

    // Spanish (Index 4)
    {
        "--- PRÁCTICA DE ERRORES ---",
        "Palabra o frase: ",
        "Respuesta: ",
        "¡Práctica terminada! Errores restantes: "
    },

    // German (Index 5)
    {
        "--- FEHLER-ÜBUNG ---",
        "Wort oder Satz: ",
        "Antwort: ",
        "Übung beendet! Verbleibende Fehler: "
    },

    // French (Index 6)
    {
        "--- EXERCICE DES ERREURS ---",
        "Mot ou phrase : ",
        "Réponse : ",
        "Exercice terminé ! Erreurs restantes : "
    },

    // Russian (Index 7)
    {
        "--- ПРАКТИКА ОШИБОК ---",
        "Слово или предложение: ",
        "Ответ: ",
        "Практика завершена! Осталось ошибок: "
    },

    // Ukrainian (Index 8)
    {
        "--- ПРАКТИКА ПОМИЛОК ---",
        "Слово або речення: ",
        "Відповідь: ",
        "Практику завершено! Залишилось помилок: "
    },

    // Korean (Index 9)
    {
        "--- 틀린 단어 연습 ---",
        "단어 또는 문장: ",
        "답변: ",
        "연습 종료! 남은 오류: "
    },

    // Italian (Index 10)
    {
        "--- ESERCIZIO ERRORI ---",
        "Parola o frase: ",
        "Risposta: ",
        "Esercizio terminato! Errori rimasti: "
    },

    // Polish (Index 11)
    {
        "--- ĆWICZENIE BŁĘDÓW ---",
        "Słowo lub zdanie: ",
        "Odpowiedź: ",
        "Ćwiczenie zakończone! Pozostałe błędy: "
    },

    // Arabic (Index 12)
    {
        "--- تدريب الأخطاء ---",
        "كلمة أو جملة: ",
        "الإجابة: ",
        "انتهى التدريب! الأخطاء المتبقية: "
    },

    // Vietnamese (Index 13)
    {
        "--- LUYỆN TẬP LỖI ---",
        "Từ hoặc câu: ",
        "Trả lời: ",
        "Kết thúc luyện tập! Lỗi còn lại: "
    },

    // Tagalog (Index 14)
    {
        "--- PAGPRAKTIS NG MALI ---",
        "Salita o pangungusap: ",
        "Sagot: ",
        "Natapos ang pagsasanay! Natitirang mali: "
    },

    // Greek (Index 15)
    {
        "--- ΕΞΑΣΚΗΣΗ ΛΑΘΩΝ ---",
        "Λέξη ή πρόταση: ",
        "Απάντηση: ",
        "Η εξάσκηση τελείωσε! Υπόλοιπα λάθη: "
    },

    // Hebrew (Index 16)
    {
        "--- תרגול טעויות ---",
        "מילה או משפט: ",
        "תשובה: ",
        "התרגול הסתיים! שגיאות שנותרו: "
    },

    // Portuguese (Index 17)
    {
        "--- PRÁTICA DE ERROS ---",
        "Palavra ou frase: ",
        "Resposta: ",
        "Prática concluída! Erros restantes: "
    },

    // Persian (Index 18)
    {
        "--- تمرین اشتباهات ---",
        "کلمه یا جمله: ",
        "پاسخ: ",
        "تمرین تمام شد! خطاهای باقی‌مانده: "
    },

    // Swedish (Index 19)
    {
        "--- FELÖVNING ---",
        "Ord eller mening: ",
        "Svar: ",
        "Övning avslutad! Kvarvarande fel: "
    },

    // Dutch (Index 20)
    {
        "--- FOUTEN OEFENING ---",
        "Woord of zin: ",
        "Antwoord: ",
        "Oefening voltooid! Resterende fouten: "
    },

    // Turkish (Index 21)
    {
        "--- HATA ALIŞTIRMASI ---",
        "Kelime veya cümle: ",
        "Cevap: ",
        "Alıştırma bitti! Kalan hatalar: "
    },

    // Hindi (Index 22)
    {
        "--- गलतियों का अभ्यास ---",
        "शब्द या वाक्य: ",
        "उत्तर: ",
        "अभ्यास समाप्त! बाकी गलतियाँ: "
    },

    // Latin (Index 23)
    {
        "--- EXERCITATIO ERRORUM ---",
        "Verbum vel sententia: ",
        "Responsum: ",
        "Exercitatio finita! Errores relicti: "
    }
};


//==========================================================================
static const std::vector<SpellingOutAccents> spellingOutAccentsTranslations_hardcoded {


    // Hungarian (Index 0)
    {
        "--- Ékezetek kezelése ---",
        "Jelenlegi állapot: ",
        "Ki",
        "Be",
        "1. Átkapcsolás",
        "0. Vissza",
        "Választás: "
    },

    // English (Index 1)
    {
        "--- Accent Handling ---",
        "Current state: ",
        "Off",
        "On",
        "1. Toggle",
        "0. Back",
        "Choice: "
    },

    // Chinese (Index 2)
    {
        "--- 重音符号处理 ---",
        "当前状态：",
        "关",
        "开",
        "1. 切换",
        "0. 返回",
        "选择: "
    },

    // Japanese (Index 3)
    {
        "--- アクセント処理 ---",
        "現在の状態：",
        "オフ",
        "オン",
        "1. 切り替え",
        "0. 戻る",
        "選択: "
    },

    // Spanish (Index 4)
    {
        "--- Gestión de acentos ---",
        "Estado actual: ",
        "Desactivado",
        "Activado",
        "1. Cambiar",
        "0. Volver",
        "Opción: "
    },

    // German (Index 5)
    {
        "--- Akzentverwaltung ---",
        "Aktueller Status: ",
        "Aus",
        "Ein",
        "1. Umschalten",
        "0. Zurück",
        "Auswahl: "
    },

    // French (Index 6)
    {
        "--- Gestion des accents ---",
        "État actuel : ",
        "Désactivé",
        "Activé",
        "1. Basculer",
        "0. Retour",
        "Choix: "
    },

    // Russian (Index 7)
    {
        "--- Обработка акцентов ---",
        "Текущее состояние: ",
        "Выкл",
        "Вкл",
        "1. Переключить",
        "0. Назад",
        "Выбор: "
    },

    // Ukrainian (Index 8)
    {
        "--- Обробка акцентів ---",
        "Поточний стан: ",
        "Вимкнено",
        "Увімкнено",
        "1. Перемкнути",
        "0. Назад",
        "Вибір: "
    },

    // Korean (Index 9)
    {
        "--- 악센트 처리 ---",
        "현재 상태: ",
        "꺼짐",
        "켜짐",
        "1. 전환",
        "0. 뒤로",
        "선택: "
    },

    // Italian (Index 10)
    {
        "--- Gestione accenti ---",
        "Stato attuale: ",
        "Disattivato",
        "Attivato",
        "1. Cambia",
        "0. Indietro",
        "Scelta: "
    },

    // Polish (Index 11)
    {
        "--- Obsługa akcentów ---",
        "Aktualny stan: ",
        "Wyłączone",
        "Włączone",
        "1. Przełącz",
        "0. Powrót",
        "Wybór: "
    },

    // Arabic (Index 12)
{
    "--- معالجة اللكنة ---",
    "الحالة الحالية: ",
    "إيقاف",
    "تشغيل",
    "1. تبديل",
    "0. رجوع",
    "اختيار: "
},

    // Vietnamese (Index 13)
    {
        "--- Xử lý dấu ---",
        "Trạng thái hiện tại: ",
        "Tắt",
        "Bật",
        "1. Chuyển đổi",
        "0. Quay lại",
        "Lựa chọn: "
    },

    // Tagalog (Index 14)
    {
        "--- Pamamahala ng accent ---",
        "Kasalukuyang estado: ",
        "Patay",
        "Bukas",
        "1. Palitan",
        "0. Bumalik",
        "Piliin: "
    },

    // Greek (Index 15)
    {
        "--- Διαχείριση τόνων ---",
        "Τρέχουσα κατάσταση: ",
        "Ανενεργό",
        "Ενεργό",
        "1. Εναλλαγή",
        "0. Πίσω",
        "Επιλογή: "
    },

    // Hebrew (Index 16)
{
    "--- ניהול מבטאים ---",
    "מצב נוכחי: ",
    "כבוי",
    "פועל",
    "1. החלף",
    "0. חזור",
    "בחירה: "
},

    // Portuguese (Index 17)
    {
        "--- Gestão de acentos ---",
        "Estado atual: ",
        "Desligado",
        "Ligado",
        "1. Alternar",
        "0. Voltar",
        "Escolha: "
    },

    // Persian (Index 18)
{
    "--- مدیریت علائم ---",
    "وضعیت فعلی: ",
    "خاموش",
    "روشن",
    "1. تغییر",
    "0. بازگشت",
    "انتخاب: "
},

    // Swedish (Index 19)
    {
        "--- Accenthantering ---",
        "Nuvarande status: ",
        "Av",
        "På",
        "1. Växla",
        "0. Tillbaka",
        "Val: "
    },

    // Dutch (Index 20)
    {
        "--- Accentbeheer ---",
        "Huidige status: ",
        "Uit",
        "Aan",
        "1. Wisselen",
        "0. Terug",
        "Keuze: "
    },

    // Turkish (Index 21)
    {
        "--- Aksan yönetimi ---",
        "Mevcut durum: ",
        "Kapalı",
        "Açık",
        "1. Değiştir",
        "0. Geri",
        "Seçim: "
    },

    // Hindi (Index 22)
    {
        "--- उच्चारण चिह्न प्रबंधन ---",
        "वर्तमान स्थिति: ",
        "बंद",
        "चालू",
        "1. बदलें",
        "0. वापस",
        "चयन: "
    },

    // Latin (Index 23)
    {
        "--- Administratio accentuum ---",
        "Status praesens: ",
        "Off",
        "On",
        "1. Commuta",
        "0. Redi",
        "Electio: "
    }
};


//==========================================================================
static const std::vector<CreateVocabListsFileAndFolders> createVocabListsFileAndFoldersTranslations_hardcoded {

    // Hungarian (0)
    {
        "--- A jelenlegi fájlok és mappák a /data-ban: ---",
        "[MAPPA]"
    },

    // English (1)
    {
        "--- Current files and folders in /data: ---",
        "[FOLDER]"
    },

    // Chinese (2)
    {
        "--- /data 中的当前文件和文件夹: ---",
        "[文件夹]"
    },

    // Japanese (3)
    {
        "--- /data 内の現在のファイルとフォルダ: ---",
        "[フォルダ]"
    },

    // Spanish (4)
    {
        "--- Archivos y carpetas actuales en /data: ---",
        "[CARPETA]"
    },

    // German (5)
    {
        "--- Aktuelle Dateien und Ordner in /data: ---",
        "[ORDNER]"
    },

    // French (6)
    {
        "--- Fichiers et dossiers actuels dans /data: ---",
        "[DOSSIER]"
    },

    // Russian (7)
    {
        "--- Текущие файлы и папки в /data: ---",
        "[ПАПКА]"
    },

    // Ukrainian (8)
    {
        "--- Поточні файли та папки в /data: ---",
        "[ПАПКА]"
    },

    // Korean (9)
    {
        "--- /data의 현재 파일 및 폴더: ---",
        "[폴더]"
    },

    // Italian (10)
    {
        "--- File e cartelle attuali in /data: ---",
        "[CARTELLA]"
    },

    // Polish (11)
    {
        "--- Aktualne pliki i foldery w /data: ---",
        "[FOLDER]"
    },

    // Arabic (12)
    {
        "--- الملفات والمجلدات الحالية في /data: ---",
        "[مجلد]"
    },

    // Vietnamese (13)
    {
        "--- Tệp và thư mục hiện tại trong /data: ---",
        "[THƯ MỤC]"
    },

    // Tagalog (14)
    {
        "--- Kasalukuyang files at folders sa /data: ---",
        "[FOLDER]"
    },

    // Greek (15)
    {
        "--- Τρέχοντα αρχεία και φάκελοι στο /data: ---",
        "[ΦΑΚΕΛΟΣ]"
    },

    // Hebrew (16)
    {
        "--- קבצים ותיקיות נוכחיים ב־/data: ---",
        "[תיקייה]"
    },

    // Portuguese (17)
    {
        "--- Arquivos e pastas atuais em /data: ---",
        "[PASTA]"
    },

    // Farsi (18)
    {
        "--- فایل‌ها و پوشه‌های فعلی در /data: ---",
        "[پوشه]"
    },

    // Swedish (19)
    {
        "--- Aktuella filer och mappar i /data: ---",
        "[MAPP]"
    },

    // Dutch (20)
    {
        "--- Huidige bestanden en mappen in /data: ---",
        "[MAP]"
    },

    // Turkish (21)
    {
        "--- /data içindeki mevcut dosyalar ve klasörler: ---",
        "[KLASÖR]"
    },

    // Hindi (22)
    {
        "--- /data में वर्तमान फ़ाइलें और फ़ोल्डर: ---",
        "[फ़ोल्डर]"
    },

    // Latin (23)
    {
        "--- Fasciculi et directoria in /data: ---",
        "[DIRECTORIUM]"
    }

};

//==========================================================================
static const std::vector<VocabFileCommands> vocabFileCommandTranslate_hardcoded {


    // Hungarian (0)
    {
        "Parancsok: 'exit' (kilépés), 'del' (törlés), 'rn' (átnevezés), 'cp' (másolás), 'mv' (mozgatás), 'md' vagy 'mkdir' (új mappa)",
        "Új mappa létrehozásához írd be a nevét, majd nyomd meg az ENTER-t."
    },

    // English (1)
    {
        "Commands: 'exit' (exit), 'del' (delete), 'rn' (rename), 'cp' (copy), 'mv' (move), 'md' or 'mkdir' (new folder)",
        "To create a new folder, type its name and press ENTER."
    },

    // Chinese (2)
    {
        "命令: 'exit' (退出), 'del' (删除), 'rn' (重命名), 'cp' (复制), 'mv' (移动), 'md' 或 'mkdir'（新建文件夹）",
        "要创建新文件夹，输入名称并按 ENTER。"
    },

    // Japanese (3)
    {
        "コマンド: 'exit' (終了), 'del' (削除), 'rn' (名前変更), 'cp' (コピー), 'mv' (移動), 'md' または 'mkdir'（新しいフォルダ）",
        "新しいフォルダを作成するには名前を入力してENTERを押してください。"
    },

    // Spanish (4)
    {
        "Comandos: 'exit' (salir), 'del' (eliminar), 'rn' (renombrar), 'cp' (copiar), 'mv' (mover), 'md' o 'mkdir' (nueva carpeta)",
        "Para crear una carpeta nueva, escribe el nombre y presiona ENTER."
    },

    // German (5)
    {
        "Befehle: 'exit' (beenden), 'del' (löschen), 'rn' (umbenennen), 'cp' (kopieren), 'mv' (verschieben), 'md' oder 'mkdir' (neuer Ordner)",
        "Um einen neuen Ordner zu erstellen, Namen eingeben und ENTER drücken."
    },

    // French (6)
    {
        "Commandes: 'exit' (quitter), 'del' (supprimer), 'rn' (renommer), 'cp' (copier), 'mv' (déplacer), 'md' ou 'mkdir' (nouveau dossier)",
        "Pour créer un dossier, tapez le nom puis appuyez sur ENTER."
    },

    // Russian (7)
    {
        "Команды: 'exit' (выход), 'del' (удалить), 'rn' (переименовать), 'cp' (копировать), 'mv' (переместить), 'md' или 'mkdir' (новая папка)",
        "Чтобы создать папку, введите имя и нажмите ENTER."
    },

    // Ukrainian (8)
    {
        "Команди: 'exit' (вихід), 'del' (видалити), 'rn' (перейменувати), 'cp' (копіювати), 'mv' (перемістити), 'md' або 'mkdir' (нова папка)",
        "Щоб створити папку, введіть назву і натисніть ENTER."
    },

    // Korean (9)
    {
        "명령어: 'exit' (종료), 'del' (삭제), 'rn' (이름변경), 'cp' (복사), 'mv' (이동), 'md' 또는 'mkdir' (새 폴더)",
        "새 폴더를 만들려면 이름 입력 후 ENTER."
    },

    // Italian (10)
    {
        "Comandi: 'exit' (esci), 'del' (elimina), 'rn' (rinomina), 'cp' (copia), 'mv' (sposta), 'md' o 'mkdir' (nuova cartella)",
        "Per creare una cartella, scrivi il nome e premi ENTER."
    },

    // Polish (11)
    {
        "Komendy: 'exit' (wyjście), 'del' (usuń), 'rn' (zmień nazwę), 'cp' (kopiuj), 'mv' (przenieś), 'md' lub 'mkdir' (nowy folder)",
        "Aby utworzyć folder, wpisz nazwę i naciśnij ENTER."
    },

    // Arabic (12)
    {
        "أوامر: 'exit' (خروج), 'del' (حذف), 'rn' (إعادة تسمية), 'cp' (نسخ), 'mv' (نقل), 'md' أو 'mkdir' (مجلد جديد)",
        "لإنشاء مجلد، اكتب الاسم واضغط ENTER."
    },

    // Vietnamese (13)
    {
        "Lệnh: 'exit' (thoát), 'del' (xóa), 'rn' (đổi tên), 'cp' (sao chép), 'mv' (di chuyển), 'md' hoặc 'mkdir' (thư mục mới)",
        "Để tạo thư mục mới, nhập tên và nhấn ENTER."
    },

    // Tagalog (14)
    {
        "Mga utos: 'exit' (labas), 'del' (tanggal), 'rn' (palitan pangalan), 'cp' (kopya), 'mv' (lipat), 'md' o 'mkdir' (bagong folder)",
        "Para gumawa ng folder, ilagay ang pangalan at pindutin ENTER."
    },

    // Greek (15)
    {
        "Εντολές: 'exit' (έξοδος), 'del' (διαγραφή), 'rn' (μετονομασία), 'cp' (αντιγραφή), 'mv' (μετακίνηση), 'md' ή 'mkdir' (νέος φάκελος)",
        "Για νέο φάκελο γράψε όνομα και πάτα ENTER."
    },

    // Hebrew (16)
    {
        "פקודות: 'exit' (יציאה), 'del' (מחיקה), 'rn' (שינוי שם), 'cp' (העתקה), 'mv' (העברה), 'md' או 'mkdir' (תיקייה חדשה)",
        "כדי ליצור תיקייה, הקלד שם ולחץ ENTER."
    },

    // Portuguese (17)
    {
        "Comandos: 'exit' (sair), 'del' (excluir), 'rn' (renomear), 'cp' (copiar), 'mv' (mover), 'md' ou 'mkdir' (nova pasta)",
        "Para criar pasta, digite o nome e pressione ENTER."
    },

    // Farsi (18)
    {
        "دستورات: 'exit' (خروج), 'del' (حذف), 'rn' (تغییر نام), 'cp' (کپی), 'mv' (انتقال), 'md' یا 'mkdir' (پوشه جدید)",
        "برای ساخت پوشه، نام را وارد کرده و ENTER بزنید."
    },

    // Swedish (19)
    {
        "Kommandon: 'exit' (avsluta), 'del' (radera), 'rn' (byt namn), 'cp' (kopiera), 'mv' (flytta), 'md' eller 'mkdir' (ny mapp)",
        "För ny mapp, skriv namn och tryck ENTER."
    },

    // Dutch (20)
    {
        "Commando's: 'exit' (afsluiten), 'del' (verwijderen), 'rn' (hernoemen), 'cp' (kopiëren), 'mv' (verplaatsen), 'md' of 'mkdir' (nieuwe map)",
        "Voor nieuwe map, typ naam en druk ENTER."
    },

    // Turkish (21)
    {
        "Komutlar: 'exit' (çıkış), 'del' (sil), 'rn' (yeniden adlandır), 'cp' (kopyala), 'mv' (taşı), 'md' veya 'mkdir' (yeni klasör)",
        "Yeni klasör için isim yaz ve ENTER bas."
    },

    // Hindi (22)
    {
        "कमांड: 'exit' (बाहर), 'del' (हटाएँ), 'rn' (नाम बदलें), 'cp' (कॉपी), 'mv' (मूव), 'md' या 'mkdir' (नया फ़ोल्डर)",
        "नया फ़ोल्डर बनाने के लिए नाम लिखें और ENTER दबाएँ।"
    },

    // Latin (23)
    {
        "Mandata: 'exit' (exire), 'del' (delere), 'rn' (renominare), 'cp' (copiare), 'mv' (movere), 'md' vel 'mkdir' (novum directorium)",
        "Ad novum directorium crea, nomen scribe et ENTER preme."
    }

};

//==========================================================================
const std::vector<CreateFolderStrings> createFolderTranslations_hardcoded {

    // Hungarian (0)
    {
        "Veszélyes(hibás) útvonal",
        "Mappa sikeresen létrehozva! Mappa neve: ",
        "Hiba a mappa létrehozásakor!"
    },

    // English (1)
    {
        "Invalid (dangerous) path",
        "Folder created successfully! Folder name: ",
        "Error creating folder!"
    },

    // Chinese (2)
    {
        "无效（危险）路径",
        "文件夹创建成功！文件夹名称：",
        "创建文件夹时出错！"
    },

    // Japanese (3)
    {
        "無効（危険な）パス",
        "フォルダが正常に作成されました！フォルダ名：",
        "フォルダ作成エラー！"
    },

    // Spanish (4)
    {
        "Ruta inválida (peligrosa)",
        "¡Carpeta creada con éxito! Nombre de la carpeta: ",
        "¡Error al crear la carpeta!"
    },

    // German (5)
    {
        "Ungültiger (gefährlicher) Pfad",
        "Ordner erfolgreich erstellt! Ordnername: ",
        "Fehler beim Erstellen des Ordners!"
    },

    // French (6)
    {
        "Chemin invalide (dangereux)",
        "Dossier créé avec succès ! Nom du dossier : ",
        "Erreur lors de la création du dossier !"
    },

    // Russian (7)
    {
        "Недопустимый (опасный) путь",
        "Папка успешно создана! Имя папки: ",
        "Ошибка при создании папки!"
    },

    // Ukrainian (8)
    {
        "Недійсний (небезпечний) шлях",
        "Папку успішно створено! Назва папки: ",
        "Помилка при створенні папки!"
    },

    // Korean (9)
    {
        "잘못된(위험한) 경로",
        "폴더가 성공적으로 생성되었습니다! 폴더 이름: ",
        "폴더 생성 오류!"
    },

    // Italian (10)
    {
        "Percorso non valido (pericoloso)",
        "Cartella creata con successo! Nome cartella: ",
        "Errore durante la creazione della cartella!"
    },

    // Polish (11)
    {
        "Nieprawidłowa (niebezpieczna) ścieżka",
        "Folder utworzony pomyślnie! Nazwa folderu: ",
        "Błąd podczas tworzenia folderu!"
    },

    // Arabic (12)
    {
        "مسار غير صالح (خطير)",
        "تم إنشاء المجلد بنجاح! اسم المجلد: ",
        "خطأ في إنشاء المجلد!"
    },

    // Vietnamese (13)
    {
        "Đường dẫn không hợp lệ (nguy hiểm)",
        "Tạo thư mục thành công! Tên thư mục: ",
        "Lỗi khi tạo thư mục!"
    },

    // Tagalog (14)
    {
        "Di-wastong (mapanganib) landas",
        "Matagumpay na nagawa ang folder! Pangalan ng folder: ",
        "Error sa paggawa ng folder!"
    },

    // Greek (15)
    {
        "Μη έγκυρη (επικίνδυνη) διαδρομή",
        "Ο φάκελος δημιουργήθηκε επιτυχώς! Όνομα φακέλου: ",
        "Σφάλμα κατά τη δημιουργία φακέλου!"
    },

    // Hebrew (16)
    {
        "נתיב לא חוקי (מסוכן)",
        "התיקייה נוצרה בהצלחה! שם התיקייה: ",
        "שגיאה ביצירת התיקייה!"
    },

    // Portuguese (17)
    {
        "Caminho inválido (perigoso)",
        "Pasta criada com sucesso! Nome da pasta: ",
        "Erro ao criar a pasta!"
    },

    // Farsi (18)
    {
        "مسیر نامعتبر (خطرناک)",
        "پوشه با موفقیت ایجاد شد! نام پوشه: ",
        "خطا در ایجاد پوشه!"
    },

    // Swedish (19)
    {
        "Ogiltig (farlig) sökväg",
        "Mappen skapades framgångsrikt! Mappnamn: ",
        "Fel vid skapande av mapp!"
    },

    // Dutch (20)
    {
        "Ongeldig (gevaarlijk) pad",
        "Map succesvol aangemaakt! Mapnaam: ",
        "Fout bij maken van map!"
    },

    // Turkish (21)
    {
        "Geçersiz (tehlikeli) yol",
        "Klasör başarıyla oluşturuldu! Klasör adı: ",
        "Klasör oluşturma hatası!"
    },

    // Hindi (22)
    {
        "अमान्य (खतरनाक) पथ",
        "फ़ोल्डर सफलतापूर्वक बनाया गया! फ़ोल्डर नाम: ",
        "फ़ोल्डर बनाने में त्रुटि!"
    },

    // Latin (23)
    {
        "Via invalida (periculosa)",
        "Directorium feliciter creatum! Nomen directorii: ",
        "Error in creando directorio!"
    }

};

//==========================================================================
static const std::vector<OneRoundQString> oneRoundQuizStringTranslations_hardcoded {

    // Hungarian (0)
    {
        "--- Egy körös kvíz beállítás ---",
        "Jelenlegi állapot: ",
        "BE",
        "KI",
        "1. Átkapcsolás",
        "0. Vissza",
        "Választás: ",
        "Egy körös kviz BEKAPCSOLVA!",
        "Egy körös kviz KIKAPCSOLVA!"
    },

    // English (1)
    {
        "--- One round quiz settings ---",
        "Current state: ",
        "ON",
        "OFF",
        "1. Toggle",
        "0. Back",
        "Choice: ",
        "One round quiz ENABLED!",
        "One round quiz DISABLED!"
    },

    // Chinese (2)
    {
        "--- 单轮测验设置 ---",
        "当前状态: ",
        "开启",
        "关闭",
        "1. 切换",
        "0. 返回",
        "选择: ",
        "单轮测验已开启！",
        "单轮测验已关闭！"
    },

    // Japanese (3)
    {
        "--- 1ラウンドクイズ設定 ---",
        "現在の状態: ",
        "オン",
        "オフ",
        "1. 切り替え",
        "0. 戻る",
        "選択: ",
        "1ラウンドクイズが有効になりました！",
        "1ラウンドクイズが無効になりました！"
    },

    // Spanish (4)
    {
        "--- Configuración de quiz de una ronda ---",
        "Estado actual: ",
        "ACTIVO",
        "INACTIVO",
        "1. Cambiar",
        "0. Volver",
        "Elección: ",
        "¡Quiz de una ronda ACTIVADO!",
        "¡Quiz de una ronda DESACTIVADO!"
    },

    // German (5)
    {
        "--- Einrunden-Quiz Einstellungen ---",
        "Aktueller Status: ",
        "AN",
        "AUS",
        "1. Umschalten",
        "0. Zurück",
        "Auswahl: ",
        "Einrunden-Quiz AKTIVIERT!",
        "Einrunden-Quiz DEAKTIVIERT!"
    },

    // French (6)
    {
        "--- Paramètres du quiz à un tour ---",
        "État actuel : ",
        "ACTIVÉ",
        "DÉSACTIVÉ",
        "1. Basculer",
        "0. Retour",
        "Choix : ",
        "Quiz à un tour ACTIVÉ !",
        "Quiz à un tour DÉSACTIVÉ !"
    },

    // Russian (7)
    {
        "--- Настройки одного раунда викторины ---",
        "Текущее состояние: ",
        "ВКЛ",
        "ВЫКЛ",
        "1. Переключить",
        "0. Назад",
        "Выбор: ",
        "Режим одного раунда ВКЛЮЧЕН!",
        "Режим одного раунда ВЫКЛЮЧЕН!"
    },

    // Ukrainian (8)
    {
        "--- Налаштування одного раунду ---",
        "Поточний стан: ",
        "УВІМК",
        "ВИМК",
        "1. Перемкнути",
        "0. Назад",
        "Вибір: ",
        "Режим одного раунду УВІМКНЕНО!",
        "Режим одного раунду ВИМКНЕНО!"
    },

    // Korean (9)
    {
        "--- 한 라운드 퀴즈 설정 ---",
        "현재 상태: ",
        "켜짐",
        "꺼짐",
        "1. 전환",
        "0. 뒤로",
        "선택: ",
        "한 라운드 퀴즈 활성화됨!",
        "한 라운드 퀴즈 비활성화됨!"
    },

    // Italian (10)
    {
        "--- Impostazioni quiz a un turno ---",
        "Stato attuale: ",
        "ATTIVO",
        "DISATTIVO",
        "1. Cambia",
        "0. Indietro",
        "Scelta: ",
        "Quiz a un turno ATTIVATO!",
        "Quiz a un turno DISATTIVATO!"
    },

    // Polish (11)
    {
        "--- Ustawienia quizu jednej rundy ---",
        "Aktualny stan: ",
        "WŁ",
        "WYŁ",
        "1. Przełącz",
        "0. Wróć",
        "Wybór: ",
        "Tryb jednej rundy WŁĄCZONY!",
        "Tryb jednej rundy WYŁĄCZONY!"
    },

    // Arabic (12)
    {
        "--- إعدادات اختبار جولة واحدة ---",
        "الحالة الحالية: ",
        "تشغيل",
        "إيقاف",
        "1. تبديل",
        "0. رجوع",
        "اختيار: ",
        "تم تفعيل وضع الجولة الواحدة!",
        "تم إيقاف وضع الجولة الواحدة!"
    },

    // Vietnamese (13)
    {
        "--- Cài đặt quiz một vòng ---",
        "Trạng thái hiện tại: ",
        "BẬT",
        "TẮT",
        "1. Chuyển đổi",
        "0. Quay lại",
        "Chọn: ",
        "Đã bật quiz một vòng!",
        "Đã tắt quiz một vòng!"
    },

    // Tagalog (14)
    {
        "--- Isang round na quiz setting ---",
        "Kasalukuyang estado: ",
        "BUKAS",
        "SARADO",
        "1. Palitan",
        "0. Bumalik",
        "Piliin: ",
        "Naka-ON ang isang round na quiz!",
        "Naka-OFF ang isang round na quiz!"
    },

    // Greek (15)
    {
        "--- Ρυθμίσεις κουίζ ενός γύρου ---",
        "Τρέχουσα κατάσταση: ",
        "ΕΝΕΡΓΟ",
        "ΑΝΕΝΕΡΓΟ",
        "1. Εναλλαγή",
        "0. Πίσω",
        "Επιλογή: ",
        "Το κουίζ ενός γύρου ΕΝΕΡΓΟΠΟΙΗΘΗΚΕ!",
        "Το κουίζ ενός γύρου ΑΠΕΝΕΡΓΟΠΟΙΗΘΗΚΕ!"
    },

    // Hebrew (16)
    {
        "--- הגדרות חידון סיבוב אחד ---",
        "מצב נוכחי: ",
        "פעיל",
        "כבוי",
        "1. החלף",
        "0. חזור",
        "בחירה: ",
        "חידון סיבוב אחד הופעל!",
        "חידון סיבוב אחד כובה!"
    },

    // Portuguese (17)
    {
        "--- Configuração de quiz de uma rodada ---",
        "Estado atual: ",
        "LIGADO",
        "DESLIGADO",
        "1. Alternar",
        "0. Voltar",
        "Escolha: ",
        "Quiz de uma rodada ATIVADO!",
        "Quiz de uma rodada DESATIVADO!"
    },

    // Farsi (18)
    {
        "--- تنظیمات آزمون یک دور ---",
        "وضعیت فعلی: ",
        "روشن",
        "خاموش",
        "1. تغییر",
        "0. بازگشت",
        "انتخاب: ",
        "حالت یک دور فعال شد!",
        "حالت یک دور غیرفعال شد!"
    },

    // Swedish (19)
    {
        "--- Inställningar för en omgång quiz ---",
        "Nuvarande status: ",
        "PÅ",
        "AV",
        "1. Växla",
        "0. Tillbaka",
        "Val: ",
        "En-runda quiz AKTIVERAD!",
        "En-runda quiz AVAKTIVERAD!"
    },

    // Dutch (20)
    {
        "--- Instellingen voor één ronde quiz ---",
        "Huidige status: ",
        "AAN",
        "UIT",
        "1. Wisselen",
        "0. Terug",
        "Keuze: ",
        "Eén ronde quiz INGESCHAKELD!",
        "Eén ronde quiz UITGESCHAKELD!"
    },

    // Turkish (21)
    {
        "--- Tek tur quiz ayarları ---",
        "Mevcut durum: ",
        "AÇIK",
        "KAPALI",
        "1. Değiştir",
        "0. Geri",
        "Seçim: ",
        "Tek tur quiz AKTİF!",
        "Tek tur quiz PASİF!"
    },

    // Hindi (22)
    {
        "--- एक राउंड क्विज सेटिंग ---",
        "वर्तमान स्थिति: ",
        "चालू",
        "बंद",
        "1. बदलें",
        "0. वापस",
        "चयन: ",
        "एक राउंड क्विज चालू हुआ!",
        "एक राउंड क्विज बंद हुआ!"
    },

    // Latin (23)
    {
        "--- Unius circuitus quiz configuratio ---",
        "Status currentis: ",
        "ACTIVUM",
        "INACTIVUM",
        "1. Mutare",
        "0. Retro",
        "Electio: ",
        "Quiz unius circuitus ACTIVATUM!",
        "Quiz unius circuitus DEACTIVATUM!"
    }
};

static const std::vector<IniStructToggle> iniStructTogglesTranslations_hardcoded {

    // Hungarian (0)
    {
        "--- INI vagy STRUCT beállítás ---",
        "Jelenlegi állapot: ",
        "BEKAPCSOLVA",
        "KIKAPCSOLVA",
        "1. Átkapcsolás",
        "0. Vissza",
        "Választás: ",
        "INI fájlok olvasása BEKAPCSOLVA!",
        "INI fájlok olvasása KIKAPCSOLVA!"
    },

    // English (1)
    {
        "--- INI or STRUCT settings ---",
        "Current state: ",
        "ON",
        "OFF",
        "1. Toggle",
        "0. Back",
        "Choice: ",
        "INI file reading ENABLED!",
        "INI file reading DISABLED!"
    },

    // Chinese (2)
    {
        "--- INI 或 STRUCT 设置 ---",
        "当前状态: ",
        "开启",
        "关闭",
        "1. 切换",
        "0. 返回",
        "选择: ",
        "INI 文件读取已开启！",
        "INI 文件读取已关闭！"
    },

    // Japanese (3)
    {
        "--- INI または STRUCT 設定 ---",
        "現在の状態: ",
        "オン",
        "オフ",
        "1. 切り替え",
        "0. 戻る",
        "選択: ",
        "INIファイル読み込みが有効になりました！",
        "INIファイル読み込みが無効になりました！"
    },

    // Spanish (4)
    {
        "--- Configuración INI o STRUCT ---",
        "Estado actual: ",
        "ACTIVADO",
        "DESACTIVADO",
        "1. Cambiar",
        "0. Volver",
        "Selección: ",
        "¡Lectura de archivos INI ACTIVADA!",
        "¡Lectura de archivos INI DESACTIVADA!"
    },

    // German (5)
    {
        "--- INI- oder STRUCT-Einstellungen ---",
        "Aktueller Status: ",
        "EINGESCHALTET",
        "AUSGESCHALTET",
        "1. Umschalten",
        "0. Zurück",
        "Auswahl: ",
        "INI-Dateien lesen AKTIVIERT!",
        "INI-Dateien lesen DEAKTIVIERT!"
    },

    // French (6)
    {
        "--- Paramètres INI ou STRUCT ---",
        "État actuel : ",
        "ACTIVÉ",
        "DÉSACTIVÉ",
        "1. Basculer",
        "0. Retour",
        "Choix: ",
        "Lecture des fichiers INI ACTIVÉE !",
        "Lecture des fichiers INI DÉSACTIVÉE !"
    },

    // Russian (7)
    {
        "--- Настройки INI или STRUCT ---",
        "Текущее состояние: ",
        "ВКЛЮЧЕНО",
        "ВЫКЛЮЧЕНО",
        "1. Переключить",
        "0. Назад",
        "Выбор: ",
        "Чтение INI файлов ВКЛЮЧЕНО!",
        "Чтение INI файлов ВЫКЛЮЧЕНО!"
    },

    // Ukrainian (8)
    {
        "--- Налаштування INI або STRUCT ---",
        "Поточний стан: ",
        "УВІМКНЕНО",
        "ВИМКНЕНО",
        "1. Перемкнути",
        "0. Назад",
        "Вибір: ",
        "Читання INI файлів УВІМКНЕНО!",
        "Читання INI файлів ВИМКНЕНО!"
    },

    // Korean (9)
    {
        "--- INI 또는 STRUCT 설정 ---",
        "현재 상태: ",
        "켜짐",
        "꺼짐",
        "1. 전환",
        "0. 뒤로",
        "선택: ",
        "INI 파일 읽기 활성화됨!",
        "INI 파일 읽기 비활성화됨!"
    },

    // Italian (10)
    {
        "--- Impostazioni INI o STRUCT ---",
        "Stato corrente: ",
        "ATTIVATO",
        "DISATTIVATO",
        "1. Cambia",
        "0. Indietro",
        "Scelta: ",
        "Lettura file INI ATTIVATA!",
        "Lettura file INI DISATTIVATA!"
    },

    // Polish (11)
    {
        "--- Ustawienia INI lub STRUCT ---",
        "Aktualny stan: ",
        "WŁĄCZONE",
        "WYŁĄCZONE",
        "1. Przełącz",
        "0. Powrót",
        "Wybór: ",
        "Odczyt plików INI WŁĄCZONY!",
        "Odczyt plików INI WYŁĄCZONY!"
    },

    // Arabic (12)
{
    "--- إعدادات INI أو STRUCT ---",
    "الحالة الحالية: ",
    "مفعل",
    "معطل",
    "1. تبديل",
    "0. رجوع",
    "اختيار: ",
    "تم تفعيل قراءة ملفات INI!",
    "تم تعطيل قراءة ملفات INI!"
},

    // Vietnamese (13)
    {
        "--- Cài đặt INI hoặc STRUCT ---",
        "Trạng thái hiện tại: ",
        "BẬT",
        "TẮT",
        "1. Chuyển đổi",
        "0. Quay lại",
        "Chọn: ",
        "Đã BẬT đọc file INI!",
        "Đã TẮT đọc file INI!"
    },

    // Tagalog (14)
    {
        "--- INI o STRUCT settings ---",
        "Kasalukuyang estado: ",
        "NAKA-ON",
        "NAKA-OFF",
        "1. Palitan",
        "0. Bumalik",
        "Piliin: ",
        "NAKA-ON ang pagbasa ng INI files!",
        "NAKA-OFF ang pagbasa ng INI files!"
    },

    // Greek (15)
    {
        "--- Ρυθμίσεις INI ή STRUCT ---",
        "Τρέχουσα κατάσταση: ",
        "ΕΝΕΡΓΟ",
        "ΑΝΕΝΕΡΓΟ",
        "1. Εναλλαγή",
        "0. Πίσω",
        "Επιλογή: ",
        "Η ανάγνωση αρχείων INI ΕΝΕΡΓΟΠΟΙΗΘΗΚΕ!",
        "Η ανάγνωση αρχείων INI ΑΠΕΝΕΡΓΟΠΟΙΗΘΗΚΕ!"
    },

    // Hebrew (16)
{
    "--- הגדרות INI או STRUCT ---",
    "מצב נוכחי: ",
    "מופעל",
    "כבוי",
    "1. החלף",
    "0. חזור",
    "בחירה: ",
    "קריאת קבצי INI הופעלה!",
    "קריאת קבצי INI בוטלה!"
},

    // Portuguese (17)
    {
        "--- Configurações INI ou STRUCT ---",
        "Estado atual: ",
        "ATIVADO",
        "DESATIVADO",
        "1. Alternar\n\n",
        "0. Voltar",
        "Seleção: ",
        "Leitura de arquivos INI ATIVADA!",
        "Leitura de arquivos INI DESATIVADA!"
    },

    // Farsi (18)
{
    "--- تنظیمات INI یا STRUCT ---",
    "وضعیت فعلی: ",
    "روشن",
    "خاموش",
    "1. تغییر",
    "0. بازگشت",
    "انتخاب: ",
    "خواندن فایل‌های INI فعال شد!",
    "خواندن فایل‌های INI غیرفعال شد!"
},

    // Swedish (19)
    {
        "--- INI- eller STRUCT-inställningar ---",
        "Nuvarande status: ",
        "PÅ",
        "AV",
        "1. Växla",
        "0. Tillbaka",
        "Val: ",
        "INI-filläsning AKTIVERAD!",
        "INI-filläsning INAKTIVERAD!"
    },

    // Dutch (20)
    {
        "--- INI- of STRUCT-instellingen ---",
        "Huidige status: ",
        "AAN",
        "UIT",
        "1. Wisselen",
        "0. Terug",
        "Keuze: ",
        "INI-bestanden lezen INGESCHAKELD!",
        "INI-bestanden lezen UITGESCHAKELD!"
    },

    // Turkish (21)
    {
        "--- INI veya STRUCT ayarları ---",
        "Geçerli durum: ",
        "AÇIK",
        "KAPALI",
        "1. Değiştir",
        "0. Geri",
        "Seçim: ",
        "INI dosyası okuma AÇILDI!",
        "INI dosyası okuma KAPATILDI!"
    },

    // Hindi (22)
    {
        "--- INI या STRUCT सेटिंग्स ---",
        "वर्तमान स्थिति: ",
        "चालू",
        "बंद",
        "1. बदलें",
        "0. वापस",
        "चयन: ",
        "INI फ़ाइल पढ़ना चालू किया गया!",
        "INI फ़ाइल पढ़ना बंद किया गया!"
    },

    // Latin (23)
    {
        "--- Optiones INI vel STRUCT ---",
        "Status currentis: ",
        "ACTIVUM",
        "INACTIVUM",
        "1. Commutare",
        "0. Redire",
        "Electio: ",
        "Lectio fasciculorum INI ACTIVATA!",
        "Lectio fasciculorum INI DEACTIVATA!"
    }
};
//======Vectors end =========

// Létrehozza a lang.ini fájlt az alapértelmezett (hard-coded) fordításokkal
void createDefaultLangIni() {
    // Létrehozzuk a "lang" mappát, ha nem létezik
    // Create the "lang" folder if it doesn't exist

#ifdef _WIN32
    std::system("if not exist lang mkdir lang"); // Windows
#else
    std::system("mkdir -p lang"); // Linux/macOS
#endif

    // Ez a függvény fogja létrehozni a lang_XX.ini fájlokat
    // Minden nyelvre külön fájlt generálunk
    for (int langIndex = 0; langIndex < static_cast<int>(Language::COUNT); ++langIndex) {
        //Nem dolgozzuk fel a 'COUNT'-ot || We do not process 'COUNT'
        if (static_cast<Language>(langIndex) == Language::COUNT) continue;

        auto currentLang = static_cast<Language>(langIndex);
        std::string langCode; // Pl. "hu", "en"

        // Itt kellene meghatározni a nyelvkódot az enum alapján
        // Ezt a részt ki kell egészíteni az összes nyelvhez!
        if (currentLang == Language::HUNGARIAN) langCode = "hu";
        else if (currentLang == Language::ENGLISH) langCode = "en";
        else if (currentLang == Language::CHINESE) langCode = "zh";
        else if (currentLang == Language::JAPANESE) langCode = "ja";
        else if (currentLang == Language::SPANISH) langCode = "es";
        else if (currentLang == Language::GERMAN) langCode = "de";
        else if (currentLang == Language::FRENCH) langCode = "fr";
        else if (currentLang == Language::RUSSIAN) langCode = "ru";
        else if (currentLang == Language::UKRAINIAN) langCode = "uk";
        else if (currentLang == Language::KOREAN) langCode = "ko";
        else if (currentLang == Language::ITALIAN) langCode = "it";
        else if (currentLang == Language::POLISH) langCode = "pl";
        else if (currentLang == Language::ARABIC) langCode = "ar";
        else if (currentLang == Language::VIETNAMESE) langCode = "vi";
        else if (currentLang == Language::TAGALOG) langCode = "tl";
        else if (currentLang == Language::GREEK) langCode = "el";
        else if (currentLang == Language::HEBREW) langCode = "he";
        else if (currentLang == Language::PORTUGUESE) langCode = "pt";
        else if (currentLang == Language::FARSI) langCode = "fa";
        else if (currentLang == Language::SWEDISH) langCode = "sv";
        else if (currentLang == Language::DUTCH) langCode = "nl";
        else if (currentLang == Language::TURKISH) langCode = "tr";
        else if (currentLang == Language::HINDI) langCode = "hi";
        else if (currentLang == Language::LATIN) langCode = "la";
        else
        {
            std::cerr << "Error: Unknown language code for enum value " << langIndex << ". Skipping INI creation." << std::endl;
            continue; // Ismeretlen nyelv kihagyása
        }
        std::string fileName = std::string("lang/") + "lang_" + langCode + ".ini";
        std::ofstream outFile(fileName);
        if (!outFile.is_open()) {
            std::cerr << "Error: Could not create " << fileName << std::endl;
            continue;
        }
        // --- MenuStrings ---
        outFile << "[MenuStrings]\n";
        outFile << "titleAndSigns=" << mainMenuTranslations_hardcoded[langIndex].titleAndSigns << "\n";
        outFile << "programExplanation=" << mainMenuTranslations_hardcoded[langIndex].programExplanation << "\n";
        outFile << "startProgram=" << mainMenuTranslations_hardcoded[langIndex].startProgram << "\n";
        outFile << "mistakeExercise=" << mainMenuTranslations_hardcoded[langIndex].mistakeExercise << "\n";
        outFile << "newFile=" << mainMenuTranslations_hardcoded[langIndex].newFile << "\n";
        outFile << "settings=" << mainMenuTranslations_hardcoded[langIndex].settings << "\n";
        outFile << "Editor=" << mainMenuTranslations_hardcoded[langIndex].Editor << "\n";
        outFile << "exit=" << mainMenuTranslations_hardcoded[langIndex].exit << "\n";
        outFile << "signs=" << mainMenuTranslations_hardcoded[langIndex].signs << "\n";

        // --- ExplanationStrings ---
        outFile << "\n[ExplanationStrings]\n";
        outFile << "description=" << explanationTranslations_hardcoded[langIndex].description << "\n";
        outFile << "instruction1=" << explanationTranslations_hardcoded[langIndex].instruction1 << "\n";
        outFile << "instruction2=" << explanationTranslations_hardcoded[langIndex].instruction2 << "\n";
        outFile << "instruction3=" << explanationTranslations_hardcoded[langIndex].instruction3 << "\n";
        outFile << "instruction4=" << explanationTranslations_hardcoded[langIndex].instruction4 << "\n";
        outFile << "instruction5=" << explanationTranslations_hardcoded[langIndex].instruction5 << "\n";
        outFile << "instruction6=" << explanationTranslations_hardcoded[langIndex].instruction6 << "\n";
        outFile << "instruction7=" << explanationTranslations_hardcoded[langIndex].instruction7 << "\n";
        outFile << "instruction8=" << explanationTranslations_hardcoded[langIndex].instruction8 << "\n";
        outFile << "instruction9=" << explanationTranslations_hardcoded[langIndex].instruction9 << "\n";
        outFile << "goodLuck=" << explanationTranslations_hardcoded[langIndex].goodLuck << "\n";

        // --- ExitingStrings ---
        outFile << "\n[ExitingStrings]\n";
        outFile << "exiting=" << exitingTranslations_hardcoded[langIndex].exiting << "\n";

        // --- NumberOutput ---
        outFile << "\n[NumberOutput]\n";
        outFile << "numberOutput=" << chooseNumberMenuTranslations_hardcoded[langIndex].numberOutput << "\n";

        // --- ListAndSelectedFile ---
        outFile << "\n[ListAndSelectedFile]\n";
        outFile << "currentlyFolder=" << listAndSelectedFilesTranslations_hardcoded[langIndex].currentlyFolder << "\n";
        outFile << "emptyFolder=" << listAndSelectedFilesTranslations_hardcoded[langIndex].emptyFolder << "\n";
        outFile << "isDirectory=" << listAndSelectedFilesTranslations_hardcoded[langIndex].isDirectory << "\n";
        outFile << "signs=" << listAndSelectedFilesTranslations_hardcoded[langIndex].signs << "\n";
        outFile << "commands=" << listAndSelectedFilesTranslations_hardcoded[langIndex].commands << "\n";
        outFile << "fullCommands=" << listAndSelectedFilesTranslations_hardcoded[langIndex].fullCommands << "\n";
        outFile << "fullCommands2=" << listAndSelectedFilesTranslations_hardcoded[langIndex].fullCommands2 << "\n";
        outFile << "choice=" << listAndSelectedFilesTranslations_hardcoded[langIndex].choice << "\n";

        // --- RenameFilesAndFolders ---
        outFile << "\n[RenameFilesAndFolders]\n";
        outFile << "toBeRenamed=" << renameFilesAndFoldersTranslations_hardcoded[langIndex].toBeRenamed << "\n";
        outFile << "newName=" << renameFilesAndFoldersTranslations_hardcoded[langIndex].newName << "\n";
        outFile << "errorDangerousPath=" << renameFilesAndFoldersTranslations_hardcoded[langIndex].errorDangerousPath << "\n";

        // --- MovingFileFolders ---
        outFile << "\n[MovingFileFolders]\n";
        outFile << "toBeMoved=" << movingFileFoldersTranslations_hardcoded[langIndex].toBeMoved << "\n";
        outFile << "newNameNewPath=" << movingFileFoldersTranslations_hardcoded[langIndex].newNameNewPath << "\n";
        outFile << "MFerrorDangerousPath=" << movingFileFoldersTranslations_hardcoded[langIndex].MFerrorDangerousPath << "\n";

        // --- DeleteFileFolders ---
        outFile << "\n[DeleteFileFolders]\n";
        outFile << "errorDfDangerousPath=" << deleteFileFoldersTranslations_hardcoded[langIndex].errorDfDangerousPath << "\n";
        outFile << "confirmationDelete=" << deleteFileFoldersTranslations_hardcoded[langIndex].confirmationDelete << "\n";
        outFile << "successDelete=" << deleteFileFoldersTranslations_hardcoded[langIndex].successDelete << "\n";
        outFile << "interrupted=" << deleteFileFoldersTranslations_hardcoded[langIndex].interrupted << "\n";
        outFile << "errorDelete=" << deleteFileFoldersTranslations_hardcoded[langIndex].errorDelete << "\n";

        // --- CopyFileFolders ---
        outFile << "\n[CopyFileFolders]\n";
        outFile << "errorDangerousPath=" << copyFileFoldersTranslations_hardcoded[langIndex].errorDangerousPath << "\n";
        outFile << "toBeCopied=" << copyFileFoldersTranslations_hardcoded[langIndex].toBeCopied << "\n";
        outFile << "newNameNewPath=" << copyFileFoldersTranslations_hardcoded[langIndex].newNameNewPath << "\n";
        outFile << "example=" << copyFileFoldersTranslations_hardcoded[langIndex].example << "\n";
        outFile << "errorDangerousGoalAndPath=" << copyFileFoldersTranslations_hardcoded[langIndex].errorDangerousGoalAndPath << "\n";
        outFile << "successCopying=" << copyFileFoldersTranslations_hardcoded[langIndex].successCopying << "\n";
        outFile << "anErrorOccurred=" << copyFileFoldersTranslations_hardcoded[langIndex].anErrorOccurred << "\n";

        // --- CreateFolderStrings ---
        outFile << "\n[CreateFolderStrings]\n";
        outFile << "errorDangerousPath=" << createFolderTranslations_hardcoded[langIndex].errorDangerousPath << "\n";
        outFile << "successCreate=" << createFolderTranslations_hardcoded[langIndex].successCreate << "\n";
        outFile << "errorCreate=" << createFolderTranslations_hardcoded[langIndex].errorCreate << "\n";

        // --- W_wordPair ---
        outFile << "\n[W_wordPair]\n";
        outFile << "ErrorOpenedFile=" << wordPairErrorTranslations_hardcoded[langIndex].ErrorOpenedFile << "\n";

        // --- InvalidInput ---
        outFile << "\n[InvalidInput]\n";
        outFile << "invalidInput=" << invalidInputTranslations_hardcoded[langIndex].invalidInput << "\n";

        // --- EnteringBack ---
        outFile << "\n[EnteringBack]\n";
        outFile << "pressToEnter=" << continuationToEnterTranslations_hardcoded[langIndex].pressToEnter << "\n";

        // --- InvalidInput2 ---
        outFile << "\n[InvalidInput2]\n";
        outFile << "invalidInput2=" << invalidInputTranslations2_hardcoded[langIndex].invalidInput2 << "\n";

        // --- HaveNoWords ---
        outFile << "\n[HaveNoWords]\n";
        outFile << "haveNoWords=" << haveNoWordsTranslations_hardcoded[langIndex].haveNoWords << "\n";

        // --- ReTry ---
        outFile << "\n[ReTry]\n";
        outFile << "reTry=" << reTryTranslations_hardcoded[langIndex].reTry << "\n";

        // --- BadlyAnswer ---
        outFile << "\n[BadlyAnswer]\n";
        outFile << "badlyAnswer=" << badlyAnswerTranslations_hardcoded[langIndex].badlyAnswer << "\n";

        // --- GoodAnswer1 ---
        outFile << "\n[GoodAnswer1]\n";
        outFile << "goodAnswer1=" << goodAnswer1Translations_hardcoded[langIndex].goodAnswer1 << "\n";

        // --- GoodAnswer2 ---
        outFile << "\n[GoodAnswer2]\n";
        outFile << "goodAnswer2=" << goodAnswer2Translations_hardcoded[langIndex].goodAnswer2 << "\n";

        // --- PronunciationString ---
        outFile << "\n[PronunciationString]\n";
        outFile << "pronunciation2str=" << pronunciationStringTranslations_hardcoded[langIndex].pronunciation2str << "\n";

        // --- HaveFinished ---
        outFile << "\n[HaveFinished]\n";
        outFile << "haveFinished=" << haveFinishedTranslations_hardcoded[langIndex].haveFinished << "\n";

        // --- ScoreSys ---
        outFile << "\n[ScoreSys]\n";
        outFile << "total=" << totalTranslations_hardcoded[langIndex].total << "\n";
        outFile << "allQuestion=" << totalTranslations_hardcoded[langIndex].allQuestion << "\n";
        outFile << "correct=" << totalTranslations_hardcoded[langIndex].correct << "\n";
        outFile << "badly=" << totalTranslations_hardcoded[langIndex].badly << "\n";
        outFile << "percent=" << totalTranslations_hardcoded[langIndex].percent << "\n";

        // --- PercentAge ---
        outFile << "\n[PercentAge]\n";
        outFile << "percentAge100=" << percentAgeTranslations_hardcoded[langIndex].percentAge100 << "\n";
        outFile << "percentAge80=" << percentAgeTranslations_hardcoded[langIndex].percentAge80 << "\n";
        outFile << "percentAgeElse=" << percentAgeTranslations_hardcoded[langIndex].percentAgeElse << "\n";

        // --- QuizExplanation ---
        outFile << "\n[QuizExplanation]\n";
        outFile << "quizExplanation1=" << quizExplanationTranslations_hardcoded[langIndex].quizExplanation1 << "\n";
        outFile << "quizExplanation2=" << quizExplanationTranslations_hardcoded[langIndex].quizExplanation2 << "\n";
        outFile << "quizExplanation3=" << quizExplanationTranslations_hardcoded[langIndex].quizExplanation3 << "\n";

        // --- VocabWordsPairTotal ---
        outFile << "\n[VocabWordsPairTotal]\n";
        outFile << "vocabWordsPairTotal=" << vocabWordsPairTotalTranslations_hardcoded[langIndex].vocabWordsPairTotal << "\n";
        outFile << "vocabWordsPairTotal2=" << vocabWordsPairTotalTranslations_hardcoded[langIndex].vocabWordsPairTotal2 << "\n";
        outFile << "vocabWordsPairTotal3=" << vocabWordsPairTotalTranslations_hardcoded[langIndex].vocabWordsPairTotal3 << "\n";

        // --- CreateVocabFile ---
        outFile << "\n[CreateVocabFile]\n";
        outFile << "inputFileName=" << createVocabFileTranslations_hardcoded[langIndex].inputFileName << "\n";
        outFile << "folderName=" << createVocabFileTranslations_hardcoded[langIndex].folderName << "\n";
        outFile << "fullPathError=" << createVocabFileTranslations_hardcoded[langIndex].fullPathError << "\n";
        outFile << "fullPathOpenError=" << createVocabFileTranslations_hardcoded[langIndex].fullPathOpenError << "\n";
        outFile << "fileSave=" << createVocabFileTranslations_hardcoded[langIndex].fileSave << "\n";
        outFile << "fileSave2=" << createVocabFileTranslations_hardcoded[langIndex].fileSave2 << "\n";
        outFile << "folderError=" << createVocabFileTranslations_hardcoded[langIndex].folderError << "\n";
        outFile << "folderDoesNotExist=" << createVocabFileTranslations_hardcoded[langIndex].folderDoesNotExist << "\n";
        outFile << "askingCreate=" << createVocabFileTranslations_hardcoded[langIndex].askingCreate << "\n";
        outFile << "folderOperationAborted=" << createVocabFileTranslations_hardcoded[langIndex].folderOperationAborted << "\n";

        // --- CreateVocab ---
        outFile << "\n[CreateVocab]\n";
        outFile << "createVocab=" << createVocabTranslations_hardcoded[langIndex].createVocab << "\n";
        outFile << "createVocab2=" << createVocabTranslations_hardcoded[langIndex].createVocab2 << "\n";
        outFile << "createVocab3=" << createVocabTranslations_hardcoded[langIndex].createVocab3 << "\n";
        outFile << "createVocab4=" << createVocabTranslations_hardcoded[langIndex].createVocab4 << "\n";
        outFile << "createVocab5=" << createVocabTranslations_hardcoded[langIndex].createVocab5 << "\n";
        outFile << "createVocab6=" << createVocabTranslations_hardcoded[langIndex].createVocab6 << "\n";
        outFile << "createVocab7=" << createVocabTranslations_hardcoded[langIndex].createVocab7 << "\n";

        // --- VocabMenu ---
        outFile << "\n[VocabMenu]\n";
        outFile << "vocabMenu1=" << vocabMenuTranslations_hardcoded[langIndex].vocabMenu1 << "\n";
        outFile << "vocabMenu2=" << vocabMenuTranslations_hardcoded[langIndex].vocabMenu2 << "\n";
        outFile << "vocabMenu3=" << vocabMenuTranslations_hardcoded[langIndex].vocabMenu3 << "\n";
        outFile << "vocabMenu4=" << vocabMenuTranslations_hardcoded[langIndex].vocabMenu4 << "\n";
        outFile << "vocabMenu5=" << vocabMenuTranslations_hardcoded[langIndex].vocabMenu5 << "\n";
        outFile << "vocabMenuChoice=" << vocabMenuTranslations_hardcoded[langIndex].vocabMenuChoice << "\n";
        outFile << "vocabError1=" << vocabMenuTranslations_hardcoded[langIndex].vocabError1 << "\n";
        outFile << "vocabError2=" << vocabMenuTranslations_hardcoded[langIndex].vocabError2 << "\n";

        // --- VocabFileCommands ---
        outFile << "\n[VocabFileCommands]\n";
        outFile << "commands1=" << vocabFileCommandTranslate_hardcoded[langIndex].commands1 << "\n";
        outFile << "commands2=" << vocabFileCommandTranslate_hardcoded[langIndex].commands2 << "\n";
        outFile << "commands3=" << vocabFileCommandTranslate_hardcoded[langIndex].commands3 << "\n";
        outFile << "commands4=" << vocabFileCommandTranslate_hardcoded[langIndex].commands4 << "\n";

        // --- SettingsMenu ---
        outFile << "\n[SettingsMenu]\n";
        outFile << "settingsMenuSign=" << settingsMenuTranslations_hardcoded[langIndex].settingsMenuSign << "\n";
        outFile << "chooseSettingsMenu=" << settingsMenuTranslations_hardcoded[langIndex].chooseSettingsMenu << "\n";
        outFile << "languageOptions=" << settingsMenuTranslations_hardcoded[langIndex].languageOptions << "\n";
        outFile << "targetLanguageOptions=" << settingsMenuTranslations_hardcoded[langIndex].targetLanguageOptions << "\n";
        outFile << "colorsOptions=" << settingsMenuTranslations_hardcoded[langIndex].colorsOptions << "\n";
        outFile << "soundOptions=" << settingsMenuTranslations_hardcoded[langIndex].soundOptions << "\n";
        outFile << "accentsOptions=" << settingsMenuTranslations_hardcoded[langIndex].accentsOptions << "\n";
        outFile << "oneRoundQuizOption=" << settingsMenuTranslations_hardcoded[langIndex].oneRoundQuizOption << "\n";
        outFile << "backMainMenu=" << settingsMenuTranslations_hardcoded[langIndex].backMainMenu << "\n";
        outFile << "settingsMenuSign2=" << settingsMenuTranslations_hardcoded[langIndex].settingsMenuSign2 << "\n";

        // --- LanguageMenu ---
        outFile << "\n[LanguageMenu]\n";
        outFile << "languageMenu1Sign=" << languageMenuTranslations_hardcoded[langIndex].languageMenu1Sign << "\n";
        outFile << "exiting=" << languageMenuTranslations_hardcoded[langIndex].exiting << "\n";
        outFile << "choiceStr=" << languageMenuTranslations_hardcoded[langIndex].choiceStr << "\n";
        outFile << "languageMenu2Sign=" << languageMenuTranslations_hardcoded[langIndex].languageMenu2Sign << "\n";
        outFile << "choiceSuccessProgramLanguage=" << languageMenuTranslations_hardcoded[langIndex].choiceSuccessProgramLanguage << "\n";

        // --- ColorsOnset ---
        outFile << "\n[ColorsOnset]\n";
        outFile << "colorsPrinting1=" << colorsOSetTranslations_hardcoded[langIndex].colorsPrinting1 << "\n";
        outFile << "colorsPrinting2=" << colorsOSetTranslations_hardcoded[langIndex].colorsPrinting2 << "\n";
        outFile << "useCLR_ON=" << colorsOSetTranslations_hardcoded[langIndex].useCLR_ON << "\n";
        outFile << "useCLR_OFF=" << colorsOSetTranslations_hardcoded[langIndex].useCLR_OFF << "\n";
        outFile << "colorsMenu1=" << colorsOSetTranslations_hardcoded[langIndex].colorsMenu1 << "\n";
        outFile << "colorsMenu2=" << colorsOSetTranslations_hardcoded[langIndex].colorsMenu2 << "\n";
        outFile << "colorsMenu3=" << colorsOSetTranslations_hardcoded[langIndex].colorsMenu3 << "\n";
        outFile << "choice=" << colorsOSetTranslations_hardcoded[langIndex].choice << "\n";
        outFile << "colorsOnOn=" << colorsOSetTranslations_hardcoded[langIndex].colorsOnOn << "\n";
        outFile << "colorsOffOff=" << colorsOSetTranslations_hardcoded[langIndex].colorsOffOff << "\n";
        outFile << "errorEntryDenied=" << colorsOSetTranslations_hardcoded[langIndex].errorEntryDenied << "\n";

        // --- SaveSettings ---
        outFile << "\n[SaveSettings]\n";
        outFile << "saveSettingsError=" << saveSettingsTranslations_hardcoded[langIndex].saveSettingsError << "\n";

        // --- LearningLanguageSet ---
        outFile << "\n[LearningLanguageSet]\n";
        outFile << "Menu=" << learningLanguageSetTranslations_hardcoded[langIndex].Menu << "\n";
        outFile << "CurrentlyMotherLanguage=" << learningLanguageSetTranslations_hardcoded[langIndex].CurrentlyMotherLanguage << "\n";
        outFile << "CurrentlyLearningLanguage=" << learningLanguageSetTranslations_hardcoded[langIndex].CurrentlyLearningLanguage << "\n";
        outFile << "option1=" << learningLanguageSetTranslations_hardcoded[langIndex].option1 << "\n";
        outFile << "option2=" << learningLanguageSetTranslations_hardcoded[langIndex].option2 << "\n";
        outFile << "option3=" << learningLanguageSetTranslations_hardcoded[langIndex].option3 << "\n";
        outFile << "choice1=" << learningLanguageSetTranslations_hardcoded[langIndex].choice1 << "\n";
        outFile << "allChoice=" << learningLanguageSetTranslations_hardcoded[langIndex].allChoice << "\n";
        outFile << "motherSuccess=" << learningLanguageSetTranslations_hardcoded[langIndex].motherSuccess << "\n";
        outFile << "choice2=" << learningLanguageSetTranslations_hardcoded[langIndex].choice2 << "\n";
        outFile << "targetSuccess=" << learningLanguageSetTranslations_hardcoded[langIndex].targetSuccess << "\n";
        outFile << "choice=" << learningLanguageSetTranslations_hardcoded[langIndex].choice << "\n";
        outFile << "back=" << learningLanguageSetTranslations_hardcoded[langIndex].back << "\n";
        outFile << "error=" << learningLanguageSetTranslations_hardcoded[langIndex].error << "\n";
        outFile << "menuSigns=" << learningLanguageSetTranslations_hardcoded[langIndex].menuSigns << "\n";

        // --- LlistAndSelectedFile ---
        outFile << "\n[LlistAndSelectedFile]\n";
        outFile << "errorFile=" << LlistAndSelectedFileTranslations_hardcoded[langIndex].errorFile << "\n";

        // --- OosEditor ---
        outFile << "\n[OosEditor]\n";
        outFile << "run=" << OosEditorTranslations_hardcoded[langIndex].run << "\n";
        outFile << "errorWin32=" << OosEditorTranslations_hardcoded[langIndex].errorWin32 << "\n";
        outFile << "errorLinux=" << OosEditorTranslations_hardcoded[langIndex].errorLinux << "\n";

        // --- BackgroundSets ---
        outFile << "\n[BackgroundSets]\n";
        outFile << "sign=" << backgroundSetsTranslations_hardcoded[langIndex].sign << "\n";
        outFile << "DefaultBlack=" << backgroundSetsTranslations_hardcoded[langIndex].DefaultBlack << "\n";
        outFile << "green=" << backgroundSetsTranslations_hardcoded[langIndex].green << "\n";
        outFile << "cian=" << backgroundSetsTranslations_hardcoded[langIndex].cian << "\n";
        outFile << "red=" << backgroundSetsTranslations_hardcoded[langIndex].red << "\n";
        outFile << "purple=" << backgroundSetsTranslations_hardcoded[langIndex].purple << "\n";
        outFile << "blue=" << backgroundSetsTranslations_hardcoded[langIndex].blue << "\n";
        outFile << "white=" << backgroundSetsTranslations_hardcoded[langIndex].white << "\n";
        outFile << "gray=" << backgroundSetsTranslations_hardcoded[langIndex].gray << "\n";
        outFile << "stepBack=" << backgroundSetsTranslations_hardcoded[langIndex].stepBack << "\n";
        outFile << "backgroundColorsChange=" << backgroundSetsTranslations_hardcoded[langIndex].backgroundColorsChange << "\n";
        outFile << "backGroundColor=" << backgroundSetsTranslations_hardcoded[langIndex].backGroundColor << "\n";

        // --- SoundOnOff ---
        outFile << "\n[SoundOnOff]\n";
        outFile << "soundSet=" << soundOnOffTranslations_hardcoded[langIndex].soundSet << "\n";
        outFile << "currentlyState=" << soundOnOffTranslations_hardcoded[langIndex].currentlyState << "\n";
        outFile << "useSoundOn=" << soundOnOffTranslations_hardcoded[langIndex].useSoundOn << "\n";
        outFile << "useSoundOff=" << soundOnOffTranslations_hardcoded[langIndex].useSoundOff << "\n";
        outFile << "option1=" << soundOnOffTranslations_hardcoded[langIndex].option1 << "\n";
        outFile << "option2=" << soundOnOffTranslations_hardcoded[langIndex].option2 << "\n";
        outFile << "option3=" << soundOnOffTranslations_hardcoded[langIndex].option3 << "\n";
        outFile << "useSoundOn2=" << soundOnOffTranslations_hardcoded[langIndex].useSoundOn2 << "\n";
        outFile << "useSoundOff2=" << soundOnOffTranslations_hardcoded[langIndex].useSoundOff2 << "\n";

        // --- MistakeExercise ---
        outFile << "\n[MistakeExercise]\n";
        outFile << "practiceOfWrongWord=" << mistakeExerciseTranslations_hardcoded[langIndex].practiceOfWrongWord << "\n";
        outFile << "word=" << mistakeExerciseTranslations_hardcoded[langIndex].word << "\n";
        outFile << "answer=" << mistakeExerciseTranslations_hardcoded[langIndex].answer << "\n";
        outFile << "exerciseEnd=" << mistakeExerciseTranslations_hardcoded[langIndex].exerciseEnd << "\n";

        // --- SpellingOutAccents ---
        outFile << "\n[SpellingOutAccents]\n";
        outFile << "accentsMenu=" << spellingOutAccentsTranslations_hardcoded[langIndex].accentsMenu << "\n";
        outFile << "accentsState=" << spellingOutAccentsTranslations_hardcoded[langIndex].accentsState << "\n";
        outFile << "accentsState1Off=" << spellingOutAccentsTranslations_hardcoded[langIndex].accentsState1Off << "\n";
        outFile << "accentsState2On=" << spellingOutAccentsTranslations_hardcoded[langIndex].accentsState2On << "\n";
        outFile << "accentsMenu1=" << spellingOutAccentsTranslations_hardcoded[langIndex].accentsMenu1 << "\n";
        outFile << "accentsMenu2=" << spellingOutAccentsTranslations_hardcoded[langIndex].accentsMenu2 << "\n";
        outFile << "accentsMenu3=" << spellingOutAccentsTranslations_hardcoded[langIndex].accentsMenu3 << "\n";

        // --- CreateVocabListsFileAndFolders ---
        outFile << "\n[CreateVocabListsFileAndFolders]\n";
        outFile << "currentlyFileandFolders=" << createVocabListsFileAndFoldersTranslations_hardcoded[langIndex].currentlyFileandFolders << "\n";
        outFile << "folderName=" << createVocabListsFileAndFoldersTranslations_hardcoded[langIndex].folderName << "\n";

        // --- OneRoundQString ---
        outFile << "\n[OneRoundQString]\n";
        outFile << "mainSigns=" << oneRoundQuizStringTranslations_hardcoded[langIndex].mainSigns << "\n";
        outFile << "currentlyState=" << oneRoundQuizStringTranslations_hardcoded[langIndex].currentlyState << "\n";
        outFile << "stateON=" << oneRoundQuizStringTranslations_hardcoded[langIndex].stateON << "\n";
        outFile << "stateOff=" << oneRoundQuizStringTranslations_hardcoded[langIndex].stateOff << "\n";
        outFile << "switching=" << oneRoundQuizStringTranslations_hardcoded[langIndex].switching << "\n";
        outFile << "back=" << oneRoundQuizStringTranslations_hardcoded[langIndex].back << "\n";
        outFile << "choose=" << oneRoundQuizStringTranslations_hardcoded[langIndex].choose << "\n";
        outFile << "OneRoundStateOn=" << oneRoundQuizStringTranslations_hardcoded[langIndex].OneRoundStateOn << "\n";
        outFile << "OneRoundStateOff=" << oneRoundQuizStringTranslations_hardcoded[langIndex].OneRoundStateOff << "\n";

        // --- IniStructToggle ---
        outFile << "\n[IniStructToggle]\n";
        outFile << "mainSigns=" << iniStructTogglesTranslations_hardcoded[langIndex].mainSigns << "\n";
        outFile << "currentlyState=" << iniStructTogglesTranslations_hardcoded[langIndex].currentlyState << "\n";
        outFile << "stateON=" << iniStructTogglesTranslations_hardcoded[langIndex].stateON << "\n";
        outFile << "stateOff=" << iniStructTogglesTranslations_hardcoded[langIndex].stateOff << "\n";
        outFile << "switchingMenu=" << iniStructTogglesTranslations_hardcoded[langIndex].switchingMenu << "\n";
        outFile << "switchingMenu2=" << iniStructTogglesTranslations_hardcoded[langIndex].switchingMenu2 << "\n";
        outFile << "switchingMenu3=" << iniStructTogglesTranslations_hardcoded[langIndex].switchingMenu3 << "\n";
        outFile << "cStateON=" << iniStructTogglesTranslations_hardcoded[langIndex].cStateON << "\n";
        outFile << "cStateOff=" << iniStructTogglesTranslations_hardcoded[langIndex].cStateOff << "\n";

        //---- CLOSING -----
        outFile.close();
        std::cout << "Created default language file: " << fileName << std::endl;
    }
}
// Megpróbálja betölteni a fordításokat a lang_XX.ini fájlból
bool loadTranslationsFromFile(Language lang) {
    loadedTranslations.clear();
    useLangIni = false;

    if (!preferIniTranslations) {
        std::cerr << "Info: INI translations are disabled in settings. Using hardcoded translations." << std::endl;
        return false;
    }

    std::string langCode;
    // Itt kellene meghatározni a nyelvkódot az enum alapján
    if (lang == Language::HUNGARIAN) langCode = "hu";
    else if (lang == Language::ENGLISH) langCode = "en";
    else if (lang == Language::CHINESE) langCode = "zh";
    else if (lang == Language::JAPANESE) langCode = "ja";
    else if (lang == Language::SPANISH) langCode = "es";
    else if (lang == Language::GERMAN) langCode = "de";
    else if (lang == Language::FRENCH) langCode = "fr";
    else if (lang == Language::RUSSIAN) langCode = "ru";
    else if (lang == Language::UKRAINIAN) langCode = "uk";
    else if (lang == Language::KOREAN) langCode = "ko";
    else if (lang == Language::ITALIAN) langCode = "it";
    else if (lang == Language::POLISH) langCode = "pl";
    else if (lang == Language::ARABIC) langCode = "ar";
    else if (lang == Language::VIETNAMESE) langCode = "vi";
    else if (lang == Language::TAGALOG) langCode = "tl";
    else if (lang == Language::GREEK) langCode = "el";
    else if (lang == Language::HEBREW) langCode = "he";
    else if (lang == Language::PORTUGUESE) langCode = "pt";
    else if (lang == Language::FARSI) langCode = "fa";
    else if (lang == Language::SWEDISH) langCode = "sv";
    else if (lang == Language::DUTCH) langCode = "nl";
    else if (lang == Language::TURKISH) langCode = "tr";
    else if (lang == Language::HINDI) langCode = "hi";
    else if (lang == Language::LATIN) langCode = "la";
    else {
        std::cerr << "Error: Unknown language code for " << static_cast<int>(lang) << ". Using hardcoded translations." << std::endl;
        return false;
    }

    std::string langFileName = std::string("lang/") + "lang_" + langCode + ".ini";
    std::ifstream inFile(langFileName);

    if (!inFile.is_open()) {
        std::cerr << "Warning: " << langFileName << " not found. Creating default and using hardcoded translations." << std::endl;
       // createDefaultLangIni(); // Létrehozzuk az összes alapértelmezettet
        return false; // Nem sikerült betölteni, marad a hard-coded
    }

    std::string line;
    std::string currentSection; // Pl. "[MenuStrings]"

    while (std::getline(inFile, line)) {
        line = trim_local(line);
        if (line.empty() || line[0] == '#') continue;

        if (line[0] == '[' && line.back() == ']') {
            currentSection = line.substr(1, line.length() - 2); // Levágjuk a []-t
            continue;
        }

        size_t eqPos = line.find('=');
        if (eqPos != std::string::npos) {
            std::string key = currentSection + "." + trim_local(line.substr(0, eqPos)); // Pl. "MenuStrings.titleAndSigns"
            std::string value = trim_local(line.substr(eqPos + 1));

            size_t pos = 0;
            while ((pos = value.find("\\n", pos)) != std::string::npos) {
                value.replace(pos, 2, "\n");
                pos += 1; // Az új újsor karakter után folytatjuk a keresést
            }
            // ÚJ: String csere a \t karakterekre (ha használsz tabulátort is)
            pos = 0;
            while ((pos = value.find("\\t", pos)) != std::string::npos) {
                value.replace(pos, 2, "\t");
                pos += 1;
            }
            loadedTranslations[key] = value;
        }
    }
    inFile.close();

    if (loadedTranslations.empty()) {
        std::cerr << "Warning: " << langFileName << " found but no translations loaded. Using hardcoded." << std::endl;
        return false;
    }

    useLangIni = true;
    return true;
}

// Központi függvény a fordítások lekéréséhez
std::string getTranslation(const std::string& key) {
    if (useLangIni && loadedTranslations.count(key)) {
        return loadedTranslations[key];
    }

    // --- FALLBACK: Ha nincs lang.ini, vagy a kulcs hiányzik a fájlból ---
    // MenuStrings
    if (key == "MenuStrings.titleAndSigns") return mainMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].titleAndSigns;
    else if (key == "MenuStrings.programExplanation") return mainMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].programExplanation;
    else if (key == "MenuStrings.startProgram") return mainMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].startProgram;
    else if (key == "MenuStrings.mistakeExercise") return mainMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].mistakeExercise;
    else if (key == "MenuStrings.newFile") return mainMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].newFile;
    else if (key == "MenuStrings.settings") return mainMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].settings;
    else if (key == "MenuStrings.Editor") return mainMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].Editor;
    else if (key == "MenuStrings.exit") return mainMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].exit;
    else if (key == "MenuStrings.signs") return mainMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].signs;

    // ExplanationStrings
    else if (key == "ExplanationStrings.description") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].description;
    else if (key == "ExplanationStrings.instruction1") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].instruction1;
    else if (key == "ExplanationStrings.instruction2") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].instruction2;
    else if (key == "ExplanationStrings.instruction3") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].instruction3;
    else if (key == "ExplanationStrings.instruction4") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].instruction4;
    else if (key == "ExplanationStrings.instruction5") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].instruction5;
    else if (key == "ExplanationStrings.instruction6") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].instruction6;
    else if (key == "ExplanationStrings.instruction7") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].instruction7;
    else if (key == "ExplanationStrings.instruction8") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].instruction8;
    else if (key == "ExplanationStrings.instruction9") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].instruction9;
    else if (key == "ExplanationStrings.goodLuck") return explanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].goodLuck;

    // ExitingStrings
    else if (key == "ExitingStrings.exiting") return exitingTranslations_hardcoded[static_cast<int>(programUiLanguage)].exiting;

    // NumberOutput
    else if (key == "NumberOutput.numberOutput") return chooseNumberMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].numberOutput;

    // ListAndSelectedFile
    else if (key == "ListAndSelectedFile.currentlyFolder") return listAndSelectedFilesTranslations_hardcoded[static_cast<int>(programUiLanguage)].currentlyFolder;
    else if (key == "ListAndSelectedFile.emptyFolder") return listAndSelectedFilesTranslations_hardcoded[static_cast<int>(programUiLanguage)].emptyFolder;
    else if (key == "ListAndSelectedFile.isDirectory") return listAndSelectedFilesTranslations_hardcoded[static_cast<int>(programUiLanguage)].isDirectory;
    else if (key == "ListAndSelectedFile.signs") return listAndSelectedFilesTranslations_hardcoded[static_cast<int>(programUiLanguage)].signs;
    else if (key == "ListAndSelectedFile.commands") return listAndSelectedFilesTranslations_hardcoded[static_cast<int>(programUiLanguage)].commands;
    else if (key == "ListAndSelectedFile.fullCommands") return listAndSelectedFilesTranslations_hardcoded[static_cast<int>(programUiLanguage)].fullCommands;
    else if (key == "ListAndSelectedFile.fullCommands2") return listAndSelectedFilesTranslations_hardcoded[static_cast<int>(programUiLanguage)].fullCommands2;
    else if (key == "ListAndSelectedFile.choice") return listAndSelectedFilesTranslations_hardcoded[static_cast<int>(programUiLanguage)].choice;

    // RenameFilesAndFolders
    else if (key == "RenameFilesAndFolders.toBeRenamed") return renameFilesAndFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].toBeRenamed;
    else if (key == "RenameFilesAndFolders.newName") return renameFilesAndFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].newName;
    else if (key == "RenameFilesAndFolders.errorDangerousPath") return renameFilesAndFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorDangerousPath;

    // MovingFileFolders
    else if (key == "MovingFileFolders.toBeMoved") return movingFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].toBeMoved;
    else if (key == "MovingFileFolders.newNameNewPath") return movingFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].newNameNewPath;
    else if (key == "MovingFileFolders.MFerrorDangerousPath") return movingFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].MFerrorDangerousPath;

    // DeleteFileFolders
    else if (key == "DeleteFileFolders.errorDfDangerousPath") return deleteFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorDfDangerousPath;
    else if (key == "DeleteFileFolders.confirmationDelete") return deleteFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].confirmationDelete;
    else if (key == "DeleteFileFolders.successDelete") return deleteFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].successDelete;
    else if (key == "DeleteFileFolders.interrupted") return deleteFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].interrupted;
    else if (key == "DeleteFileFolders.errorDelete") return deleteFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorDelete;

    // CopyFileFolders
    else if (key == "CopyFileFolders.errorDangerousPath") return copyFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorDangerousPath;
    else if (key == "CopyFileFolders.toBeCopied") return copyFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].toBeCopied;
    else if (key == "CopyFileFolders.newNameNewPath") return copyFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].newNameNewPath;
    else if (key == "CopyFileFolders.example") return copyFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].example;
    else if (key == "CopyFileFolders.errorDangerousGoalAndPath") return copyFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorDangerousGoalAndPath;
    else if (key == "CopyFileFolders.successCopying") return copyFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].successCopying;
    else if (key == "CopyFileFolders.anErrorOccurred") return copyFileFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].anErrorOccurred;

    // CreateFolderStrings
    else if (key == "CreateFolderStrings.errorDangerousPath") return createFolderTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorDangerousPath;
    else if (key == "CreateFolderStrings.successCreate") return createFolderTranslations_hardcoded[static_cast<int>(programUiLanguage)].successCreate;
    else if (key == "CreateFolderStrings.errorCreate") return createFolderTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorCreate;

    // W_wordPair
    else if (key == "W_wordPair.ErrorOpenedFile") return wordPairErrorTranslations_hardcoded[static_cast<int>(programUiLanguage)].ErrorOpenedFile;

    // InvalidInput
    else if (key == "InvalidInput.invalidInput") return invalidInputTranslations_hardcoded[static_cast<int>(programUiLanguage)].invalidInput;

    // EnteringBack
    else if (key == "EnteringBack.pressToEnter") return continuationToEnterTranslations_hardcoded[static_cast<int>(programUiLanguage)].pressToEnter;

    // InvalidInput2
    else if (key == "InvalidInput2.invalidInput2") return invalidInputTranslations2_hardcoded[static_cast<int>(programUiLanguage)].invalidInput2;

    // HaveNoWords
    else if (key == "HaveNoWords.haveNoWords") return haveNoWordsTranslations_hardcoded[static_cast<int>(programUiLanguage)].haveNoWords;

    // ReTry
    else if (key == "ReTry.reTry") return reTryTranslations_hardcoded[static_cast<int>(programUiLanguage)].reTry;

    // BadlyAnswer
    else if (key == "BadlyAnswer.badlyAnswer") return badlyAnswerTranslations_hardcoded[static_cast<int>(programUiLanguage)].badlyAnswer;

    // GoodAnswer1
    else if (key == "GoodAnswer1.goodAnswer1") return goodAnswer1Translations_hardcoded[static_cast<int>(programUiLanguage)].goodAnswer1;

    // GoodAnswer2
    else if (key == "GoodAnswer2.goodAnswer2") return goodAnswer2Translations_hardcoded[static_cast<int>(programUiLanguage)].goodAnswer2;

    // PronunciationString
    else if (key == "PronunciationString.pronunciation2str") return pronunciationStringTranslations_hardcoded[static_cast<int>(programUiLanguage)].pronunciation2str;

    // HaveFinished
    else if (key == "HaveFinished.haveFinished") return haveFinishedTranslations_hardcoded[static_cast<int>(programUiLanguage)].haveFinished;

    // ScoreSys
    else if (key == "ScoreSys.total") return totalTranslations_hardcoded[static_cast<int>(programUiLanguage)].total;
    else if (key == "ScoreSys.allQuestion") return totalTranslations_hardcoded[static_cast<int>(programUiLanguage)].allQuestion;
    else if (key == "ScoreSys.correct") return totalTranslations_hardcoded[static_cast<int>(programUiLanguage)].correct;
    else if (key == "ScoreSys.badly") return totalTranslations_hardcoded[static_cast<int>(programUiLanguage)].badly;
    else if (key == "ScoreSys.percent") return totalTranslations_hardcoded[static_cast<int>(programUiLanguage)].percent;

    // PercentAge
    else if (key == "PercentAge.percentAge100") return percentAgeTranslations_hardcoded[static_cast<int>(programUiLanguage)].percentAge100;
    else if (key == "PercentAge.percentAge80") return percentAgeTranslations_hardcoded[static_cast<int>(programUiLanguage)].percentAge80;
    else if (key == "PercentAge.percentAgeElse") return percentAgeTranslations_hardcoded[static_cast<int>(programUiLanguage)].percentAgeElse;

    // QuizExplanation
    else if (key == "QuizExplanation.quizExplanation1") return quizExplanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].quizExplanation1;
    else if (key == "QuizExplanation.quizExplanation2") return quizExplanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].quizExplanation2;
    else if (key == "QuizExplanation.quizExplanation3") return quizExplanationTranslations_hardcoded[static_cast<int>(programUiLanguage)].quizExplanation3;

    // VocabWordsPairTotal
    else if (key == "VocabWordsPairTotal.vocabWordsPairTotal") return vocabWordsPairTotalTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabWordsPairTotal;
    else if (key == "VocabWordsPairTotal.vocabWordsPairTotal2") return vocabWordsPairTotalTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabWordsPairTotal2;
    else if (key == "VocabWordsPairTotal.vocabWordsPairTotal3") return vocabWordsPairTotalTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabWordsPairTotal3;

    // CreateVocabFile
    else if (key == "CreateVocabFile.inputFileName") return createVocabFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].inputFileName;
    else if (key == "CreateVocabFile.folderName") return createVocabFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].folderName;
    else if (key == "CreateVocabFile.fullPathError") return createVocabFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].fullPathError;
    else if (key == "CreateVocabFile.fullPathOpenError") return createVocabFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].fullPathOpenError;
    else if (key == "CreateVocabFile.fileSave") return createVocabFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].fileSave;
    else if (key == "CreateVocabFile.fileSave2") return createVocabFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].fileSave2;
    else if (key == "CreateVocabFile.folderError") return createVocabFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].folderError;
    else if (key == "CreateVocabFile.folderDoesNotExist") return createVocabFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].folderDoesNotExist;
    else if (key == "CreateVocabFile.askingCreate") return createVocabFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].askingCreate;
    else if (key == "CreateVocabFile.folderOperationAborted") return createVocabFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].folderOperationAborted;

    // CreateVocab
    else if (key == "CreateVocab.createVocab") return createVocabTranslations_hardcoded[static_cast<int>(programUiLanguage)].createVocab;
    else if (key == "CreateVocab.createVocab2") return createVocabTranslations_hardcoded[static_cast<int>(programUiLanguage)].createVocab2;
    else if (key == "CreateVocab.createVocab3") return createVocabTranslations_hardcoded[static_cast<int>(programUiLanguage)].createVocab3;
    else if (key == "CreateVocab.createVocab4") return createVocabTranslations_hardcoded[static_cast<int>(programUiLanguage)].createVocab4;
    else if (key == "CreateVocab.createVocab5") return createVocabTranslations_hardcoded[static_cast<int>(programUiLanguage)].createVocab5;
    else if (key == "CreateVocab.createVocab6") return createVocabTranslations_hardcoded[static_cast<int>(programUiLanguage)].createVocab6;
    else if (key == "CreateVocab.createVocab7") return createVocabTranslations_hardcoded[static_cast<int>(programUiLanguage)].createVocab7;

    // VocabMenu
    else if (key == "VocabMenu.vocabMenu1") return vocabMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabMenu1;
    else if (key == "VocabMenu.vocabMenu2") return vocabMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabMenu2;
    else if (key == "VocabMenu.vocabMenu3") return vocabMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabMenu3;
    else if (key == "VocabMenu.vocabMenu4") return vocabMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabMenu4;
    else if (key == "VocabMenu.vocabMenu5") return vocabMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabMenu5;
    else if (key == "VocabMenu.vocabMenuChoice") return vocabMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabMenuChoice;
    else if (key == "VocabMenu.vocabError1") return vocabMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabError1;
    else if (key == "VocabMenu.vocabError2") return vocabMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].vocabError2;

    // VocabFileCommands
    else if (key == "VocabFileCommands.commands1") return vocabFileCommandTranslate_hardcoded[static_cast<int>(programUiLanguage)].commands1;
    else if (key == "VocabFileCommands.commands2") return vocabFileCommandTranslate_hardcoded[static_cast<int>(programUiLanguage)].commands2;
    else if (key == "VocabFileCommands.commands3") return vocabFileCommandTranslate_hardcoded[static_cast<int>(programUiLanguage)].commands3;
    else if (key == "VocabFileCommands.commands4") return vocabFileCommandTranslate_hardcoded[static_cast<int>(programUiLanguage)].commands4;

    // SettingsMenu
    else if (key == "SettingsMenu.settingsMenuSign") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].settingsMenuSign;
    else if (key == "SettingsMenu.chooseSettingsMenu") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].chooseSettingsMenu;
    else if (key == "SettingsMenu.languageOptions") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].languageOptions;
    else if (key == "SettingsMenu.targetLanguageOptions") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].targetLanguageOptions;
    else if (key == "SettingsMenu.colorsOptions") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].colorsOptions;
    else if (key == "SettingsMenu.soundOptions") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].soundOptions;
    else if (key == "SettingsMenu.accentsOptions") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].accentsOptions;
    else if (key == "SettingsMenu.oneRoundQuizOption") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].oneRoundQuizOption;
    else if (key == "SettingsMenu.preferIniTranslationsOption") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].preferIniTranslationsOption;
    else if (key == "SettingsMenu.backMainMenu") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].backMainMenu;
    else if (key == "SettingsMenu.settingsMenuSign2") return settingsMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].settingsMenuSign2;

    // LanguageMenu
    else if (key == "LanguageMenu.languageMenu1Sign") return languageMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].languageMenu1Sign;
    else if (key == "LanguageMenu.exiting") return languageMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].exiting;
    else if (key == "LanguageMenu.choiceStr") return languageMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].choiceStr;
    else if (key == "LanguageMenu.languageMenu2Sign") return languageMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].languageMenu2Sign;
    else if (key == "LanguageMenu.choiceSuccessProgramLanguage") return languageMenuTranslations_hardcoded[static_cast<int>(programUiLanguage)].choiceSuccessProgramLanguage;

    // ColorsOnset
    else if (key == "ColorsOnset.colorsPrinting1") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].colorsPrinting1;
    else if (key == "ColorsOnset.colorsPrinting2") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].colorsPrinting2;
    else if (key == "ColorsOnset.useCLR_ON") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].useCLR_ON;
    else if (key == "ColorsOnset.useCLR_OFF") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].useCLR_OFF;
    else if (key == "ColorsOnset.colorsMenu1") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].colorsMenu1;
    else if (key == "ColorsOnset.colorsMenu2") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].colorsMenu2;
    else if (key == "ColorsOnset.colorsMenu3") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].colorsMenu3;
    else if (key == "ColorsOnset.choice") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].choice;
    else if (key == "ColorsOnset.colorsOnOn") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].colorsOnOn;
    else if (key == "ColorsOnset.colorsOffOff") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].colorsOffOff;
    else if (key == "ColorsOnset.errorEntryDenied") return colorsOSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorEntryDenied;

    // SaveSettings
    else if (key == "SaveSettings.saveSettingsError") return saveSettingsTranslations_hardcoded[static_cast<int>(programUiLanguage)].saveSettingsError;

    // LearningLanguageSet
    else if (key == "LearningLanguageSet.Menu") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].Menu;
    else if (key == "LearningLanguageSet.CurrentlyMotherLanguage") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].CurrentlyMotherLanguage;
    else if (key == "LearningLanguageSet.CurrentlyLearningLanguage") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].CurrentlyLearningLanguage;
    else if (key == "LearningLanguageSet.option1") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].option1;
    else if (key == "LearningLanguageSet.option2") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].option2;
    else if (key == "LearningLanguageSet.option3") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].option3;
    else if (key == "LearningLanguageSet.choice1") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].choice1;
    else if (key == "LearningLanguageSet.allChoice") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].allChoice;
    else if (key == "LearningLanguageSet.motherSuccess") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].motherSuccess;
    else if (key == "LearningLanguageSet.choice2") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].choice2;
    else if (key == "LearningLanguageSet.targetSuccess") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].targetSuccess;
    else if (key == "LearningLanguageSet.choice") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].choice;
    else if (key == "LearningLanguageSet.back") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].back;
    else if (key == "LearningLanguageSet.error") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].error;
    else if (key == "LearningLanguageSet.menuSigns") return learningLanguageSetTranslations_hardcoded[static_cast<int>(programUiLanguage)].menuSigns;

    // LlistAndSelectedFile
    else if (key == "LlistAndSelectedFile.errorFile") return LlistAndSelectedFileTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorFile;

    // OosEditor
    else if (key == "OosEditor.run") return OosEditorTranslations_hardcoded[static_cast<int>(programUiLanguage)].run;
    else if (key == "OosEditor.errorWin32") return OosEditorTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorWin32;
    else if (key == "OosEditor.errorLinux") return OosEditorTranslations_hardcoded[static_cast<int>(programUiLanguage)].errorLinux;

    // BackgroundSets
    else if (key == "BackgroundSets.sign") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].sign;
    else if (key == "BackgroundSets.DefaultBlack") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].DefaultBlack;
    else if (key == "BackgroundSets.green") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].green;
    else if (key == "BackgroundSets.cian") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].cian;
    else if (key == "BackgroundSets.red") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].red;
    else if (key == "BackgroundSets.purple") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].purple;
    else if (key == "BackgroundSets.blue") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].blue;
    else if (key == "BackgroundSets.white") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].white;
    else if (key == "BackgroundSets.gray") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].gray;
    else if (key == "BackgroundSets.stepBack") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].stepBack;
    else if (key == "BackgroundSets.backgroundColorsChange") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].backgroundColorsChange;
    else if (key == "BackgroundSets.backGroundColor") return backgroundSetsTranslations_hardcoded[static_cast<int>(programUiLanguage)].backGroundColor;

    // SoundOnOff
    else if (key == "SoundOnOff.soundSet") return soundOnOffTranslations_hardcoded[static_cast<int>(programUiLanguage)].soundSet;
    else if (key == "SoundOnOff.currentlyState") return soundOnOffTranslations_hardcoded[static_cast<int>(programUiLanguage)].currentlyState;
    else if (key == "SoundOnOff.useSoundOn") return soundOnOffTranslations_hardcoded[static_cast<int>(programUiLanguage)].useSoundOn;
    else if (key == "SoundOnOff.useSoundOff") return soundOnOffTranslations_hardcoded[static_cast<int>(programUiLanguage)].useSoundOff;
    else if (key == "SoundOnOff.option1") return soundOnOffTranslations_hardcoded[static_cast<int>(programUiLanguage)].option1;
    else if (key == "SoundOnOff.option2") return soundOnOffTranslations_hardcoded[static_cast<int>(programUiLanguage)].option2;
    else if (key == "SoundOnOff.option3") return soundOnOffTranslations_hardcoded[static_cast<int>(programUiLanguage)].option3;
    else if (key == "SoundOnOff.useSoundOn2") return soundOnOffTranslations_hardcoded[static_cast<int>(programUiLanguage)].useSoundOn2;
    else if (key == "SoundOnOff.useSoundOff2") return soundOnOffTranslations_hardcoded[static_cast<int>(programUiLanguage)].useSoundOff2;

    // MistakeExercise
    else if (key == "MistakeExercise.practiceOfWrongWord") return mistakeExerciseTranslations_hardcoded[static_cast<int>(programUiLanguage)].practiceOfWrongWord;
    else if (key == "MistakeExercise.word") return mistakeExerciseTranslations_hardcoded[static_cast<int>(programUiLanguage)].word;
    else if (key == "MistakeExercise.answer") return mistakeExerciseTranslations_hardcoded[static_cast<int>(programUiLanguage)].answer;
    else if (key == "MistakeExercise.exerciseEnd") return mistakeExerciseTranslations_hardcoded[static_cast<int>(programUiLanguage)].exerciseEnd;

    // SpellingOutAccents
    else if (key == "SpellingOutAccents.accentsMenu") return spellingOutAccentsTranslations_hardcoded[static_cast<int>(programUiLanguage)].accentsMenu;
    else if (key == "SpellingOutAccents.accentsState") return spellingOutAccentsTranslations_hardcoded[static_cast<int>(programUiLanguage)].accentsState;
    else if (key == "SpellingOutAccents.accentsState1Off") return spellingOutAccentsTranslations_hardcoded[static_cast<int>(programUiLanguage)].accentsState1Off;
    else if (key == "SpellingOutAccents.accentsState2On") return spellingOutAccentsTranslations_hardcoded[static_cast<int>(programUiLanguage)].accentsState2On;
    else if (key == "SpellingOutAccents.accentsMenu1") return spellingOutAccentsTranslations_hardcoded[static_cast<int>(programUiLanguage)].accentsMenu1;
    else if (key == "SpellingOutAccents.accentsMenu2") return spellingOutAccentsTranslations_hardcoded[static_cast<int>(programUiLanguage)].accentsMenu2;
    else if (key == "SpellingOutAccents.accentsMenu3") return spellingOutAccentsTranslations_hardcoded[static_cast<int>(programUiLanguage)].accentsMenu3;

    // CreateVocabListsFileAndFolders
    else if (key == "CreateVocabListsFileAndFolders.currentlyFileandFolders") return createVocabListsFileAndFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].currentlyFileandFolders;
    else if (key == "CreateVocabListsFileAndFolders.folderName") return createVocabListsFileAndFoldersTranslations_hardcoded[static_cast<int>(programUiLanguage)].folderName;

    // OneRoundQString
    else if (key == "OneRoundQString.mainSigns") return oneRoundQuizStringTranslations_hardcoded[static_cast<int>(programUiLanguage)].mainSigns;
    else if (key == "OneRoundQString.currentlyState") return oneRoundQuizStringTranslations_hardcoded[static_cast<int>(programUiLanguage)].currentlyState;
    else if (key == "OneRoundQString.stateON") return oneRoundQuizStringTranslations_hardcoded[static_cast<int>(programUiLanguage)].stateON;
    else if (key == "OneRoundQString.stateOff") return oneRoundQuizStringTranslations_hardcoded[static_cast<int>(programUiLanguage)].stateOff;
    else if (key == "OneRoundQString.switching") return oneRoundQuizStringTranslations_hardcoded[static_cast<int>(programUiLanguage)].switching;
    else if (key == "OneRoundQString.back") return oneRoundQuizStringTranslations_hardcoded[static_cast<int>(programUiLanguage)].back;
    else if (key == "OneRoundQString.choose") return oneRoundQuizStringTranslations_hardcoded[static_cast<int>(programUiLanguage)].choose;
    else if (key == "OneRoundQString.OneRoundStateOn") return oneRoundQuizStringTranslations_hardcoded[static_cast<int>(programUiLanguage)].OneRoundStateOn;
    else if (key == "OneRoundQString.OneRoundStateOff") return oneRoundQuizStringTranslations_hardcoded[static_cast<int>(programUiLanguage)].OneRoundStateOff;

    // IniStructToggle
    else if (key == "IniStructToggle.mainSigns") return iniStructTogglesTranslations_hardcoded[static_cast<int>(programUiLanguage)].mainSigns;
    else if (key == "IniStructToggle.currentlyState") return iniStructTogglesTranslations_hardcoded[static_cast<int>(programUiLanguage)].currentlyState;
    else if (key == "IniStructToggle.stateON") return iniStructTogglesTranslations_hardcoded[static_cast<int>(programUiLanguage)].stateON;
    else if (key == "IniStructToggle.stateOff") return iniStructTogglesTranslations_hardcoded[static_cast<int>(programUiLanguage)].stateOff;
    else if (key == "IniStructToggle.switchingMenu") return iniStructTogglesTranslations_hardcoded[static_cast<int>(programUiLanguage)].switchingMenu;
    else if (key == "IniStructToggle.switchingMenu2") return iniStructTogglesTranslations_hardcoded[static_cast<int>(programUiLanguage)].switchingMenu2;
    else if (key == "IniStructToggle.switchingMenu3") return iniStructTogglesTranslations_hardcoded[static_cast<int>(programUiLanguage)].switchingMenu3;
    else if (key == "IniStructToggle.cStateON") return iniStructTogglesTranslations_hardcoded[static_cast<int>(programUiLanguage)].cStateON;
    else if (key == "IniStructToggle.cStateOff") return iniStructTogglesTranslations_hardcoded[static_cast<int>(programUiLanguage)].cStateOff;



    return "MISSING_TRANSLATION_FOR_" + key;
}
