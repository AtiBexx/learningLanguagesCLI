#include "translations.h"

//======Vectors===========

// Menu'sVector
const std::vector<MenuStrings> mainMenuTranslations = {

    // HUNGARIAN (Index 0)
    {
        "============NYELVTANULÓ-APP============",
        "\n1. - A program magyarázata",
        "2. - A program indítása",
        "3. - A hibák gyakorlása",
        "4. - Új szókincs fájl létrehozása",
        "5. - Beállítások",
        "6. - A szerkesztő (EDITOR) megnyitása",
        "0. - Kilépés",
        "\n======================================="
    },

    // ENGLISH (Index 1)
    {
        "============LANGUAGE LEARNING APP============",
        "\n1. - Program explanation",
        "2. - Start program",
        "3. - Practice mistakes",
        "4. - Create new vocabulary file",
        "5. - Settings",
        "6. - Open editor",
        "0. - Exit",
        "\n============================================="
    },

    // CHINESE (Index 2)
    {
        "============语言学习应用============",
        "\n1. - 程序说明",
        "2. - 启动程序",
        "3. - 练习错误",
        "4. - 创建新词汇文件",
        "5. - 设置",
        "6. - 打开编辑器",
        "0. - 退出",
        "\n=================================="
    },

    // JAPANESE (Index 3)
    {
        "============言語学習アプリ============",
        "\n1. - プログラムの説明",
        "2. - プログラム開始",
        "3. - 間違いの練習",
        "4. - 新しい単語ファイル作成",
        "5. - 設定",
        "6. - エディターを開く",
        "0. - 終了",
        "\n=================================="
    },

    // SPANISH (Index 4)
    {
        "============APLICACIÓN DE IDIOMAS============",
        "\n1. - Explicación del programa",
        "2. - Iniciar programa",
        "3. - Practicar errores",
        "4. - Crear archivo de vocabulario",
        "5. - Configuración",
        "6. - Abrir editor",
        "0. - Salir",
        "\n============================================="
    },

    // GERMAN (Index 5)
    {
        "============SPRACHLERN-APP============",
        "\n1. - Programmerklärung",
        "2. - Programm starten",
        "3. - Fehler üben",
        "4. - Neue Vokabeldatei erstellen",
        "5. - Einstellungen",
        "6. - Editor öffnen",
        "0. - Beenden",
        "\n====================================="
    },

    // FRENCH (Index 6)
    {
        "============APPLICATION DE LANGUE============",
        "\n1. - Explication du programme",
        "2. - Démarrer le programme",
        "3. - Pratiquer les erreurs",
        "4. - Créer un fichier de vocabulaire",
        "5. - Paramètres",
        "6. - Ouvrir l'éditeur",
        "0. - Quitter",
        "\n============================================"
    },

    // RUSSIAN (Index 7)
    {
        "============ПРИЛОЖЕНИЕ ДЛЯ ЯЗЫКОВ============",
        "\n1. - Объяснение программы",
        "2. - Запустить программу",
        "3. - Практика ошибок",
        "4. - Создать файл словаря",
        "5. - Настройки",
        "6. - Открыть редактор",
        "0. - Выход",
        "\n============================================"
    },

    // UKRAINIAN (Index 8)
    {
        "============ДОДАТОК ДЛЯ МОВ============",
        "\n1. - Пояснення програми",
        "2. - Запустити програму",
        "3. - Практика помилок",
        "4. - Створити файл словника",
        "5. - Налаштування",
        "6. - Відкрити редактор",
        "0. - Вихід",
        "\n========================================"
    },

    // KOREAN (Index 9)
    {
        "============언어 학습 앱============",
        "\n1. - 프로그램 설명",
        "2. - 프로그램 시작",
        "3. - 오류 연습",
        "4. - 새 단어 파일 생성",
        "5. - 설정",
        "6. - 편집기 열기",
        "0. - 종료",
        "\n=================================="
    },

    // ITALIAN (Index 10)
    {
        "============APP DI LINGUE============",
        "\n1. - Spiegazione del programma",
        "2. - Avvia programma",
        "3. - Pratica errori",
        "4. - Crea file vocabolario",
        "5. - Impostazioni",
        "6. - Apri editor",
        "0. - Esci",
        "\n===================================="
    },

    // POLISH (Index 11)
    {
        "============APLIKACJA JĘZYKOWA============",
        "\n1. - Wyjaśnienie programu",
        "2. - Uruchom program",
        "3. - Ćwiczenie błędów",
        "4. - Utwórz plik słownictwa",
        "5. - Ustawienia",
        "6. - Otwórz edytor",
        "0. - Wyjście",
        "\n=========================================="
    },

    // ARABIC (Index 12)
    {
        "============تطبيق تعلم اللغات============",
        "\n1. - شرح البرنامج",
        "2. - بدء البرنامج",
        "3. - ممارسة الأخطاء",
        "4. - إنشاء ملف مفردات",
        "5. - الإعدادات",
        "6. - فتح المحرر",
        "0. - خروج",
        "\n========================================"
    },

    // VIETNAMESE (Index 13)
    {
        "============ỨNG DỤNG HỌC NGÔN NGỮ============",
        "\n1. - Giải thích chương trình",
        "2. - Bắt đầu chương trình",
        "3. - Luyện lỗi",
        "4. - Tạo file từ vựng",
        "5. - Cài đặt",
        "6. - Mở trình soạn thảo",
        "0. - Thoát",
        "\n============================================"
    },

    // TAGALOG (Index 14)
    {
        "============APP SA WIKA============",
        "\n1. - Paliwanag ng programa",
        "2. - Simulan ang programa",
        "3. - Pagsasanay sa mali",
        "4. - Gumawa ng vocabulary file",
        "5. - Settings",
        "6. - Buksan ang editor",
        "0. - Exit",
        "\n=================================="
    },

    // GREEK (Index 15)
    {
        "============ΕΦΑΡΜΟΓΗ ΓΛΩΣΣΑΣ============",
        "\n1. - Επεξήγηση προγράμματος",
        "2. - Εκκίνηση προγράμματος",
        "3. - Εξάσκηση λαθών",
        "4. - Δημιουργία αρχείου λεξιλογίου",
        "5. - Ρυθμίσεις",
        "6. - Άνοιγμα editor",
        "0. - Έξοδος",
        "\n========================================"
    },

    // HEBREW (Index 16)
    {
        "============אפליקציית שפות============",
        "\n1. - הסבר התוכנית",
        "2. - הפעלת התוכנית",
        "3. - תרגול טעויות",
        "4. - יצירת קובץ מילים",
        "5. - הגדרות",
        "6. - פתיחת עורך",
        "0. - יציאה",
        "\n======================================"
    },

    // PORTUGUESE (Index 17)
    {
        "============APP DE IDIOMAS============",
        "\n1. - Explicação do programa",
        "2. - Iniciar programa",
        "3. - Praticar erros",
        "4. - Criar arquivo de vocabulário",
        "5. - Configurações",
        "6. - Abrir editor",
        "0. - Sair",
        "\n======================================"
    },

    // FARSI (Index 18)
    {
        "============برنامه یادگیری زبان============",
        "\n1. - توضیح برنامه",
        "2. - شروع برنامه",
        "3. - تمرین خطاها",
        "4. - ایجاد فایل واژگان",
        "5. - تنظیمات",
        "6. - باز کردن ویرایشگر",
        "0. - خروج",
        "\n========================================="
    },

    // SWEDISH (Index 19)
    {
        "============SPRÅKINLÄRNINGSAPP============",
        "\n1. - Programförklaring",
        "2. - Starta program",
        "3. - Öva fel",
        "4. - Skapa vokabulärfil",
        "5. - Inställningar",
        "6. - Öppna editor",
        "0. - Avsluta",
        "\n=========================================="
    },

    // DUTCH (Index 20)
    {
        "============TAALAPP============",
        "\n1. - Program uitleg",
        "2. - Start programma",
        "3. - Fouten oefenen",
        "4. - Woordenbestand maken",
        "5. - Instellingen",
        "6. - Editor openen",
        "0. - Afsluiten",
        "\n================================"
    },

    // TURKISH (Index 21)
    {
        "============DİL ÖĞRENME UYGULAMASI============",
        "\n1. - Program açıklaması",
        "2. - Programı başlat",
        "3. - Hataları çalış",
        "4. - Kelime dosyası oluştur",
        "5. - Ayarlar",
        "6. - Editörü aç",
        "0. - Çıkış",
        "\n=============================================="
    },

    // HINDI (Index 22)
    {
        "============भाषा सीखने का ऐप============",
        "\n1. - प्रोग्राम विवरण",
        "2. - प्रोग्राम शुरू करें",
        "3. - गलतियों का अभ्यास",
        "4. - शब्दावली फ़ाइल बनाएं",
        "5. - सेटिंग्स",
        "6. - एडिटर खोलें",
        "0. - बाहर निकलें",
        "\n========================================"
    },

    // LATIN (Index 23)
    {
        "============APP LINGUAE============",
        "\n1. - Explicatio programmatis",
        "2. - Incipere programmam",
        "3. - Exercere errores",
        "4. - Creare fasciculum verborum",
        "5. - Optiones",
        "6. - Aperire editorem",
        "0. - Exire",
        "\n==================================="
    }
};

// number output
const std::vector<NumberOutput> chooseNumberMenuTranslations = {
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

//Explanations || magyarázat
const std::vector<ExplanationStrings> explanationTranslations = {

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

const std::vector<ExitingStrings> exitingTranslations = {
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

const std::vector<InvalidInput> invalidInputTranslations = {
    //hungarian (Index 0)
    {"Hibás bemenet, kérlek csak számot adj meg!\n" },

    //English (Index 1)
        {"Invalid input. Please only enter a number!\n"},
    // CHINESE (Index 2)
    {"输入无效，请只输入数字！\n"},

    // JAPANESE (Index 3)
    {"無効な入力です。数字のみ入力してください！\n"},

    // SPANISH (Index 4)
    {"Entrada inválida. ¡Por favor, introduce solo números!\n"},

    // GERMAN (Index 5)
    {"Ungültige Eingabe. Bitte nur Zahlen eingeben!\n"},

    // FRENCH (Index 6)
    {"Entrée invalide. Veuillez entrer uniquement des nombres !\n"},

    // RUSSIAN (Index 7)
    {"Неверный ввод. Пожалуйста, вводите только числа!\n"},

    // UKRAINIAN (Index 8)
    {"Неправильне введення. Будь ласка, вводьте лише числа!\n"},

    // KOREAN (Index 9)
    {"잘못된 입력입니다. 숫자만 입력하세요!\n"},

    // ITALIAN (Index 10)
    {"Input non valido. Inserisci solo numeri!\n"},

    // POLISH (Index 11)
    {"Nieprawidłowe dane. Wpisz tylko liczby!\n"},

    // ARABIC (Index 12)
    {"إدخال غير صالح. يرجى إدخال أرقام فقط!\n"},

    // VIETNAMESE (Index 13)
    {"Dữ liệu không hợp lệ. Vui lòng chỉ nhập số!\n"},

    // TAGALOG (Index 14)
    {"Di-wastong input. Mangyaring numero lamang ang ilagay!\n"},

    // GREEK (Index 15)
    {"Μη έγκυρη είσοδος. Παρακαλώ εισάγετε μόνο αριθμούς!\n"},

    // HEBREW (Index 16)
    {"קלט לא חוקי. אנא הזן מספרים בלבד!\n"},

    // PORTUGUESE (Index 17)
    {"Entrada inválida. Por favor, insira apenas números!\n"},

    // FARSI (Index 18)
    {"ورودی نامعتبر است. لطفاً فقط عدد وارد کنید!\n"},

    // SWEDISH (Index 19)
    {"Ogiltig inmatning. Ange endast siffror!\n"},

    // DUTCH (Index 20)
    {"Ongeldige invoer. Voer alleen cijfers in!\n"},

    // TURKISH (Index 21)
    {"Geçersiz giriş. Lütfen sadece sayı girin!\n"},

    // HINDI (Index 22)
    {"अमान्य इनपुट। कृपया केवल संख्या दर्ज करें!\n"},

    // LATIN (Index 23)
    {"Input non validus. Quaeso numeros tantum inserere!\n"}
};
const std::vector<EnteringBack> continuationToEnterTranslations = {
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
const std::vector<InvalidInput2>  invalidInputTranslations2 = { // 's' hozzáadva
    //Hungarian (Index 0)
{"Érvénytelen választás! Kérlek próbáld újra és megfelelő számot adj meg!\n"},

    // english (Index 1)
    {"Invalid choice. Please try again and enter a valid number!\n"},

    // CHINESE (Index 2)
    {"无效选择！请重试并输入有效的数字！\n"},

    // JAPANESE (Index 3)
    {"無効な選択です！もう一度試して、有効な数字を入力してください！\n"},

    // SPANISH (Index 4)
    {"¡Elección inválida! Por favor, inténtalo de nuevo e introduce un número válido.\n"},

    // GERMAN (Index 5)
    {"Ungültige Auswahl! Bitte versuche es erneut und gib eine gültige Zahl ein!\n"},

    // FRENCH (Index 6)
    {"Choix invalide ! Veuillez réessayer et entrer un nombre valide !\n"},

    // RUSSIAN (Index 7)
    {"Неверный выбор! Пожалуйста, попробуйте снова и введите корректное число!\n"},

    // UKRAINIAN (Index 8)
    {"Невірний вибір! Будь ласка, спробуйте ще раз і введіть правильне число!\n"},

    // KOREAN (Index 9)
    {"잘못된 선택입니다! 다시 시도하고 올바른 숫자를 입력하세요!\n"},

    // ITALIAN (Index 10)
    {"Scelta non valida! Riprova e inserisci un numero valido!\n"},

    // POLISH (Index 11)
    {"Nieprawidłowy wybór! Spróbuj ponownie i wpisz poprawną liczbę!\n"},

    // ARABIC (Index 12)
    {" \nاختيار غير صالح! يرجى المحاولة مرة أخرى وإدخال رقم صحيح!"},

    // VIETNAMESE (Index 13)
    {"Lựa chọn không hợp lệ! Vui lòng thử lại và nhập số hợp lệ!\n"},

    // TAGALOG (Index 14)
    {"Di-wastong pagpili! Subukan muli at maglagay ng tamang numero!\n"},

    // GREEK (Index 15)
    {"Μη έγκυρη επιλογή! Προσπαθήστε ξανά και εισάγετε έγκυρο αριθμό!\n"},

    // HEBREW (Index 16)
    {"\nבחירה לא חוקית! אנא נסה שוב והזן מספר תקין!"},

    // PORTUGUESE (Index 17)
    {"Escolha inválida! Por favor, tente novamente e insira um número válido!\n"},

    // FARSI (Index 18)
    {"\nانتخاب نامعتبر! لطفاً دوباره تلاش کنید و یک عدد معتبر وارد کنید!"},

    // SWEDISH (Index 19)
    {"Ogiltigt val! Försök igen och ange ett giltigt nummer!\n"},

    // DUTCH (Index 20)
    {"Ongeldige keuze! Probeer opnieuw en voer een geldig nummer in!\n"},

    // TURKISH (Index 21)
    {"Geçersiz seçim! Lütfen tekrar deneyin ve geçerli bir sayı girin!\n"},

    // HINDI (Index 22)
    {"अमान्य चयन! कृपया फिर से प्रयास करें और सही संख्या दर्ज करें!\n"},

    // LATIN (Index 23)
    {"Electio non valida! Quaeso iterum tenta et numerum validum inserere!\n"}

};
const std::vector<HaveNoWords> haveNoWordsTranslations = {
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

const std::vector<ReTry> reTryTranslations = {
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
const std::vector<BadlyAnswer> badlyAnswerTranslations ={
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
const std::vector<GoodAnswer1> goodAnswer1Translations = {
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
    {"Bonne réponse !"},

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
const std::vector<GoodAnswer2> goodAnswer2Translations = {
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
const std::vector<PronunciationString> pronunciationStringTranslations = {
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
const std::vector<HaveFinished> haveFinishedTranslations = {
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
const std::vector<ScoreSys> totalTranslations = {
    // HUNGARIAN (Index 0)
    {
        "\n---=== Eredmény === ---",
        "A kérdések száma: ",
        "Helyes válaszok: ",
        "Helytelen válaszok: ",
        "Teljesítmény százalékban: "
    },

    // ENGLISH (Index 1)
    {
        "\n---=== Results ===---",
        "Number of questions: ",
        "Correct answers: ",
        "Wrong answers: ",
        "Performance percentage: "
    },

    // CHINESE (Index 2)
    {
        "\n---=== 结果 ===---",
        "问题数量: ",
        "正确答案: ",
        "错误答案: ",
        "表现百分比: "
    },

    // JAPANESE (Index 3)
    {
        "\n---=== 結果 ===---",
        "質問数: ",
        "正解数: ",
        "不正解数: ",
        "達成率: "
    },

    // SPANISH (Index 4)
    {
        "\n---=== Resultados ===---",
        "Número de preguntas: ",
        "Respuestas correctas: ",
        "Respuestas incorrectas: ",
        "Porcentaje de rendimiento: "
    },

    // GERMAN (Index 5)
    {
        "\n---=== Ergebnisse ===---",
        "Anzahl der Fragen: ",
        "Richtige Antworten: ",
        "Falsche Antworten: ",
        "Leistungsprozentsatz: "
    },

    // FRENCH (Index 6)
    {
        "\n---=== Résultats ===---",
        "Nombre de questions: ",
        "Réponses correctes: ",
        "Réponses incorrectes: ",
        "Pourcentage de performance: "
    },

    // RUSSIAN (Index 7)
    {
        "\n---=== Результаты ===---",
        "Количество вопросов: ",
        "Правильные ответы: ",
        "Неправильные ответы: ",
        "Процент выполнения: "
    },

    // UKRAINIAN (Index 8)
    {
        "\n---=== Результати ===---",
        "Кількість запитань: ",
        "Правильні відповіді: ",
        "Неправильні відповіді: ",
        "Відсоток виконання: "
    },

    // KOREAN (Index 9)
    {
        "\n---=== 결과 ===---",
        "문제 수: ",
        "정답 수: ",
        "오답 수: ",
        "성과 비율: "
    },

    // ITALIAN (Index 10)
    {
        "\n---=== Risultati ===---",
        "Numero di domande: ",
        "Risposte corrette: ",
        "Risposte sbagliate: ",
        "Percentuale di rendimento: "
    },

    // POLISH (Index 11)
    {
        "\n---=== Wyniki ===---",
        "Liczba pytań: ",
        "Poprawne odpowiedzi: ",
        "Błędne odpowiedzi: ",
        "Procent wydajności: "
    },

    // ARABIC (Index 12)
    {
        "\n---=== النتائج ===---",
        "عدد الأسئلة: ",
        "الإجابات الصحيحة: ",
        "الإجابات الخاطئة: ",
        "نسبة الأداء: "
    },

    // VIETNAMESE (Index 13)
    {
        "\n---=== Kết quả ===---",
        "Số câu hỏi: ",
        "Câu trả lời đúng: ",
        "Câu trả lời sai: ",
        "Phần trăm hiệu suất: "
    },

    // TAGALOG (Index 14)
    {
        "\n---=== Resulta ===---",
        "Bilang ng mga tanong: ",
        "Tamang sagot: ",
        "Maling sagot: ",
        "Porsyento ng performance: "
    },

    // GREEK (Index 15)
    {
        "\n---=== Αποτελέσματα ===---",
        "Αριθμός ερωτήσεων: ",
        "Σωστές απαντήσεις: ",
        "Λάθος απαντήσεις: ",
        "Ποσοστό απόδοσης: "
    },

    // HEBREW (Index 16)
    {
        "\n---=== תוצאות ===---",
        "מספר שאלות: ",
        "תשובות נכונות: ",
        "תשובות שגויות: ",
        "אחוז ביצועים: "
    },

    // PORTUGUESE (Index 17)
    {
        "\n---=== Resultados ===---",
        "Número de perguntas: ",
        "Respostas corretas: ",
        "Respostas erradas: ",
        "Percentagem de desempenho: "
    },

    // FARSI (Index 18)
    {
        "\n---=== نتایج ===---",
        "تعداد سوالات: ",
        "پاسخ‌های صحیح: ",
        "پاسخ‌های نادرست: ",
        "درصد عملکرد: "
    },

    // SWEDISH (Index 19)
    {
        "\n---=== Resultat ===---",
        "Antal frågor: ",
        "Rätta svar: ",
        "Felaktiga svar: ",
        "Prestandaprocent: "
    },

    // DUTCH (Index 20)
    {
        "\n---=== Resultaten ===---",
        "Aantal vragen: ",
        "Correcte antwoorden: ",
        "Foute antwoorden: ",
        "Prestatiepercentage: "
    },

    // TURKISH (Index 21)
    {
        "\n---=== Sonuçlar ===---",
        "Soru sayısı: ",
        "Doğru cevaplar: ",
        "Yanlış cevaplar: ",
        "Performans yüzdesi: "
    },

    // HINDI (Index 22)
    {
        "\n---=== परिणाम ===---",
        "प्रश्नों की संख्या: ",
        "सही उत्तर: ",
        "गलत उत्तर: ",
        "प्रदर्शन प्रतिशत: "
    },

    // LATIN (Index 23)
    {
        "\n---=== Eventus ===---",
        "Numerus quaestionum: ",
        "Responsa recta: ",
        "Responsa falsa: ",
        "Percentum performance: "
    }
};
const std::vector<PercentAge> percentAgeTranslations = {
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
const std::vector<QuizExplanation> quizExplanationTranslations = {

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
const std::vector<VocabWordsPairTotal> vocabWordsPairTotalTranslations = {

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
const std::vector<CreateVocabFile> createVocabFileTranslations = {

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

const std::vector<CreateVocab> createVocabTranslations = {

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
const std::vector<VocabMenu> vocabMenuTranslations = {

    // HUNGARIAN (Index 0)
    {
        "FIGYELEM: Ez a fájl már létezik és ",
        " szópárt tartalmaz.",
        "1. Hozzáfűzés\n2. Felülírás\n3. Mégsem\nVálasztás: ",
        "Hiba: csak 1-3 közötti számot adj meg!",
        "Hiba: Csak számot adj meg!"
    },

    // ENGLISH (Index 1)
    {
        "WARNING: This file already exists and contains ",
        " word pairs.",
        "1. Append\n2. Overwrite\n3. Cancel\nChoice: ",
        "Error: Enter only numbers between 1-3!",
        "Error: Enter only numbers!"
    },

    // CHINESE (Index 2)
    {
        "警告：该文件已存在，并包含 ",
        " 个词对。",
        "1. 追加\n2. 覆盖\n3. 取消\n选择: ",
        "错误：请输入1到3之间的数字！",
        "错误：请输入数字！"
    },

    // JAPANESE (Index 3)
    {
        "警告：このファイルは既に存在し、",
        " 個の単語ペアがあります。",
        "1. 追加\n2. 上書き\n3. キャンセル\n選択: ",
        "エラー：1〜3の数字のみ入力してください！",
        "エラー：数字のみ入力してください！"
    },

    // SPANISH (Index 4)
    {
        "ADVERTENCIA: Este archivo ya existe y contiene ",
        " pares de palabras.",
        "1. Añadir\n2. Sobrescribir\n3. Cancelar\nOpción: ",
        "Error: ¡Introduce solo números entre 1-3!",
        "Error: ¡Introduce solo números!"
    },

    // GERMAN (Index 5)
    {
        "WARNUNG: Diese Datei existiert bereits und enthält ",
        " Wortpaare.",
        "1. Anhängen\n2. Überschreiben\n3. Abbrechen\nAuswahl: ",
        "Fehler: Nur Zahlen zwischen 1-3 eingeben!",
        "Fehler: Nur Zahlen eingeben!"
    },

    // FRENCH (Index 6)
    {
        "ATTENTION : Ce fichier existe déjà et contient ",
        " paires de mots.",
        "1. Ajouter\n2. Écraser\n3. Annuler\nChoix : ",
        "Erreur : Entrez uniquement des nombres entre 1-3 !",
        "Erreur : Entrez uniquement des nombres !"
    },

    // RUSSIAN (Index 7)
    {
        "ВНИМАНИЕ: Этот файл уже существует и содержит ",
        " пар слов.",
        "1. Добавить\n2. Перезаписать\n3. Отмена\nВыбор: ",
        "Ошибка: Введите число от 1 до 3!",
        "Ошибка: Введите только числа!"
    },

    // UKRAINIAN (Index 8)
    {
        "УВАГА: Цей файл вже існує і містить ",
        " пар слів.",
        "1. Додати\n2. Перезаписати\n3. Скасувати\nВибір: ",
        "Помилка: Введіть число від 1 до 3!",
        "Помилка: Вводьте лише числа!"
    },

    // KOREAN (Index 9)
    {
        "경고: 이 파일은 이미 존재하며 ",
        " 개의 단어 쌍이 있습니다.",
        "1. 추가\n2. 덮어쓰기\n3. 취소\n선택: ",
        "오류: 1에서 3 사이의 숫자만 입력하세요!",
        "오류: 숫자만 입력하세요!"
    },

    // ITALIAN (Index 10)
    {
        "ATTENZIONE: Questo file esiste già e contiene ",
        " coppie di parole.",
        "1. Aggiungi\n2. Sovrascrivi\n3. Annulla\nScelta: ",
        "Errore: Inserisci solo numeri tra 1-3!",
        "Errore: Inserisci solo numeri!"
    },

    // POLISH (Index 11)
    {
        "UWAGA: Ten plik już istnieje i zawiera ",
        " par słów.",
        "1. Dodaj\n2. Nadpisz\n3. Anuluj\nWybór: ",
        "Błąd: Podaj liczbę od 1 do 3!",
        "Błąd: Podaj tylko liczby!"
    },

    // ARABIC (Index 12)
    {
        "تحذير: هذا الملف موجود بالفعل ويحتوي على ",
        " أزواج كلمات.",
        "1. إضافة\n2. استبدال\n3. إلغاء\nاختيار: ",
        "خطأ: أدخل رقمًا بين 1 و3 فقط!",
        "خطأ: أدخل أرقامًا فقط!"
    },

    // VIETNAMESE (Index 13)
    {
        "CẢNH BÁO: Tệp này đã tồn tại và chứa ",
        " cặp từ.",
        "1. Thêm\n2. Ghi đè\n3. Hủy\nLựa chọn: ",
        "Lỗi: Chỉ nhập số từ 1-3!",
        "Lỗi: Chỉ nhập số!"
    },

    // TAGALOG (Index 14)
    {
        "BABALA: Ang file na ito ay umiiral na at may ",
        " pares ng salita.",
        "1. Idagdag\n2. I-overwrite\n3. Kanselahin\nPiliin: ",
        "Error: Maglagay lamang ng numero 1-3!",
        "Error: Numero lamang ang ilagay!"
    },

    // GREEK (Index 15)
    {
        "ΠΡΟΕΙΔΟΠΟΙΗΣΗ: Αυτό το αρχείο υπάρχει ήδη και περιέχει ",
        " ζεύγη λέξεων.",
        "1. Προσθήκη\n2. Αντικατάσταση\n3. Ακύρωση\nΕπιλογή: ",
        "Σφάλμα: Εισάγετε αριθμό από 1 έως 3!",
        "Σφάλμα: Εισάγετε μόνο αριθμούς!"
    },

    // HEBREW (Index 16)
    {
        "אזהרה: קובץ זה כבר קיים ומכיל ",
        " זוגות מילים.",
        "1. הוסף\n2. דרוס\n3. בטל\nבחירה: ",
        "שגיאה: הזן מספר בין 1 ל-3 בלבד!",
        "שגיאה: הזן מספרים בלבד!"
    },

    // PORTUGUESE (Index 17)
    {
        "AVISO: Este arquivo já existe e contém ",
        " pares de palavras.",
        "1. Adicionar\n2. Sobrescrever\n3. Cancelar\nEscolha: ",
        "Erro: Digite apenas números entre 1-3!",
        "Erro: Digite apenas números!"
    },

    // FARSI (Index 18)
    {
        "هشدار: این فایل از قبل وجود دارد و شامل ",
        " جفت کلمه است.",
        "1. افزودن\n2. بازنویسی\n3. لغو\nانتخاب: ",
        "خطا: فقط عدد بین 1 تا 3 وارد کنید!",
        "خطا: فقط عدد وارد کنید!"
    },

    // SWEDISH (Index 19)
    {
        "VARNING: Denna fil finns redan och innehåller ",
        " ordpar.",
        "1. Lägg till\n2. Skriv över\n3. Avbryt\nVal: ",
        "Fel: Ange endast siffror mellan 1-3!",
        "Fel: Ange endast siffror!"
    },

    // DUTCH (Index 20)
    {
        "WAARSCHUWING: Dit bestand bestaat al en bevat ",
        " woordparen.",
        "1. Toevoegen\n2. Overschrijven\n3. Annuleren\nKeuze: ",
        "Fout: Voer alleen cijfers tussen 1-3 in!",
        "Fout: Voer alleen cijfers in!"
    },

    // TURKISH (Index 21)
    {
        "UYARI: Bu dosya zaten mevcut ve ",
        " kelime çifti içeriyor.",
        "1. Ekle\n2. Üzerine yaz\n3. İptal\nSeçim: ",
        "Hata: Sadece 1-3 arası sayı girin!",
        "Hata: Sadece sayı girin!"
    },

    // HINDI (Index 22)
    {
        "चेतावनी: यह फ़ाइल पहले से मौजूद है और इसमें ",
        " शब्द जोड़े हैं।",
        "1. जोड़ें\n2. ओवरराइट\n3. रद्द करें\nचयन: ",
        "त्रुटि: केवल 1-3 के बीच संख्या दर्ज करें!",
        "त्रुटि: केवल संख्या दर्ज करें!"
    },

    // LATIN (Index 23)
    {
        "MONITUM: Hic fasciculus iam existit et continet ",
        " paria verborum.",
        "1. Adde\n2. Rescribe\n3. Cancella\nElectio: ",
        "Error: Inseras solum numeros inter 1-3!",
        "Error: Inseras solum numeros!"
    }
};
const std::vector<SettingsMenu> settingsMenuTranslations {

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
        "0. Visszalépés a főmenübe",
        "\n================================================"
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
        "6. Single round quiz on/off",
        "0. Back to main menu",
        "\n=============================================="
    },

    // Chinese (2)
    {
        "================设置菜单================",
        "请选择以下选项：",
        "1. 设置语言",
        "2. 设置学习语言",
        "3. 设置颜色",
        "4. 提示音 开/关",
        "5. 忽略重音 开/关",
        "6. 单轮测验 开/关",
        "0. 返回主菜单",
        "\n========================================"
    },

    // Japanese (3)
    {
        "================設定メニュー================",
        "以下から選択してください：",
        "1. 言語設定",
        "2. 学習言語の設定",
        "3. 色の設定",
        "4. ビープ音 オン/オフ",
        "5. アクセント無視 オン/オフ",
        "6. 1回クイズ オン/オフ",
        "0. メインメニューへ戻る",
        "\n=========================================="
    },

    // Spanish (4)
    {
        "================MENÚ DE CONFIGURACIÓN================",
        "Elige una opción:",
        "1. Configurar idioma",
        "2. Configurar idioma de aprendizaje",
        "3. Configurar colores",
        "4. Sonido beep on/off",
        "5. Ignorar acentos on/off",
        "6. Quiz de una ronda on/off",
        "0. Volver al menú principal",
        "\n===================================================="
    },

    // German (5)
    {
        "================EINSTELLUNGSMENÜ================",
        "Bitte wählen:",
        "1. Sprache einstellen",
        "2. Lernsprache einstellen",
        "3. Farben einstellen",
        "4. Signalton an/aus",
        "5. Akzente ignorieren an/aus",
        "6. Einzelrunde Quiz an/aus",
        "0. Zurück zum Hauptmenü",
        "\n==============================================="
    },

    // French (6)
    {
        "================MENU PARAMÈTRES================",
        "Veuillez choisir :",
        "1. Définir la langue",
        "2. Définir la langue d’apprentissage",
        "3. Définir les couleurs",
        "4. Son beep on/off",
        "5. Ignorer les accents on/off",
        "6. Quiz une manche on/off",
        "0. Retour au menu principal",
        "\n=============================================="
    },

    // Russian (7)
    {
        "================МЕНЮ НАСТРОЕК================",
        "Выберите опцию:",
        "1. Установить язык",
        "2. Установить язык обучения",
        "3. Настроить цвета",
        "4. Звук вкл/выкл",
        "5. Игнорировать акценты вкл/выкл",
        "6. Один раунд викторины вкл/выкл",
        "0. Назад в главное меню",
        "\n=========================================="
    },

    // Ukrainian (8)
    {
        "================МЕНЮ НАЛАШТУВАНЬ================",
        "Оберіть опцію:",
        "1. Встановити мову",
        "2. Встановити мову навчання",
        "3. Налаштувати кольори",
        "4. Звук увімк/вимк",
        "5. Ігнорувати акценти увімк/вимк",
        "6. Один раунд вікторини увімк/вимк",
        "0. Назад до головного меню",
        "\n=============================================="
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
        "6. 1라운드 퀴즈 켜기/끄기",
        "0. 메인 메뉴로 돌아가기",
        "\n======================================"
    },

    // Italian (10)
    {
        "================MENU IMPOSTAZIONI================",
        "Scegli un'opzione:",
        "1. Imposta lingua",
        "2. Imposta lingua di apprendimento",
        "3. Imposta colori",
        "4. Suono beep on/off",
        "5. Ignora accenti on/off",
        "6. Quiz singolo on/off",
        "0. Torna al menu principale",
        "\n================================================"
    },

    // Polish (11)
    {
        "================MENU USTAWIEŃ================",
        "Wybierz opcję:",
        "1. Ustaw język",
        "2. Ustaw język nauki",
        "3. Ustaw kolory",
        "4. Dźwięk on/off",
        "5. Ignoruj akcenty on/off",
        "6. Jedna runda quizu on/off",
        "0. Powrót do menu głównego",
        "\n============================================"
    },

    // Arabic (12)
    {
        "================قائمة الإعدادات================",
        "اختر خياراً:",
        "1. تعيين اللغة",
        "2. تعيين لغة التعلم",
        "3. تعيين الألوان",
        "4. الصوت تشغيل/إيقاف",
        "5. تجاهل التشكيل تشغيل/إيقاف",
        "6. اختبار جولة واحدة تشغيل/إيقاف",
        "0. العودة إلى القائمة الرئيسية",
        "\n============================================"
    },

    // Vietnamese (13)
    {
        "================MENU CÀI ĐẶT================",
        "Chọn một tùy chọn:",
        "1. Cài đặt ngôn ngữ",
        "2. Cài đặt ngôn ngữ học",
        "3. Cài đặt màu sắc",
        "4. Âm thanh bật/tắt",
        "5. Bỏ qua dấu bật/tắt",
        "6. Quiz một vòng bật/tắt",
        "0. Quay lại menu chính",
        "\n=========================================="
    },

    // Tagalog (14)
    {
        "================MENU NG MGA SETTING================",
        "Pumili ng opsyon:",
        "1. Itakda ang wika",
        "2. Itakda ang wikang aaralin",
        "3. Itakda ang kulay",
        "4. Tunog beep on/off",
        "5. Balewalain ang accent on/off",
        "6. Isang round quiz on/off",
        "0. Bumalik sa main menu",
        "\n=============================================="
    },

    // Greek (15)
    {
        "================ΜΕΝΟΥ ΡΥΘΜΙΣΕΩΝ================",
        "Επιλέξτε:",
        "1. Ρύθμιση γλώσσας",
        "2. Ρύθμιση γλώσσας εκμάθησης",
        "3. Ρύθμιση χρωμάτων",
        "4. Ήχος on/off",
        "5. Αγνόηση τόνων on/off",
        "6. Quiz ενός γύρου on/off",
        "0. Επιστροφή στο κύριο μενού",
        "\n============================================"
    },

    // Hebrew (16)
    {
        "================תפריט הגדרות================",
        "בחר אפשרות:",
        "1. הגדרת שפה",
        "2. הגדרת שפת לימוד",
        "3. הגדרת צבעים",
        "4. צליל הפעלה/כיבוי",
        "5. התעלמות מניקוד הפעלה/כיבוי",
        "6. חידון סיבוב אחד הפעלה/כיבוי",
        "0. חזרה לתפריט הראשי",
        "\n=========================================="
    },

    // Portuguese (17)
    {
        "================MENU DE CONFIGURAÇÕES================",
        "Escolha uma opção:",
        "1. Definir idioma",
        "2. Definir idioma de aprendizado",
        "3. Definir cores",
        "4. Som beep on/off",
        "5. Ignorar acentos on/off",
        "6. Quiz de uma rodada on/off",
        "0. Voltar ao menu principal",
        "\n===================================================="
    },

    // Farsi (18)
    {
        "================منوی تنظیمات================",
        "یک گزینه انتخاب کنید:",
        "1. تنظیم زبان",
        "2. تنظیم زبان یادگیری",
        "3. تنظیم رنگ‌ها",
        "4. صدا روشن/خاموش",
        "5. نادیده گرفتن اعراب روشن/خاموش",
        "6. آزمون یک دور روشن/خاموش",
        "0. بازگشت به منوی اصلی",
        "\n=========================================="
    },

    // Swedish (19)
    {
        "================INSTÄLLNINGSMENY================",
        "Välj ett alternativ:",
        "1. Ställ in språk",
        "2. Ställ in inlärningsspråk",
        "3. Ställ in färger",
        "4. Ljud på/av",
        "5. Ignorera accenter på/av",
        "6. Enrundig quiz på/av",
        "0. Tillbaka till huvudmenyn",
        "\n=============================================="
    },

    // Dutch (20)
    {
        "================INSTELLINGEN MENU================",
        "Kies een optie:",
        "1. Stel taal in",
        "2. Stel leertaak in",
        "3. Stel kleuren in",
        "4. Geluid aan/uit",
        "5. Accenten negeren aan/uit",
        "6. Eén ronde quiz aan/uit",
        "0. Terug naar hoofdmenu",
        "\n=============================================="
    },

    // Turkish (21)
    {
        "================AYARLAR MENÜSÜ================",
        "Bir seçenek seçin:",
        "1. Dil ayarla",
        "2. Öğrenme dili ayarla",
        "3. Renkleri ayarla",
        "4. Ses açık/kapalı",
        "5. Aksanları yok say açık/kapalı",
        "6. Tek tur quiz açık/kapalı",
        "0. Ana menüye dön",
        "\n============================================"
    },

    // Hindi (22)
    {
        "================सेटिंग्स मेनू================",
        "एक विकल्प चुनें:",
        "1. भाषा सेट करें",
        "2. सीखने की भाषा सेट करें",
        "3. रंग सेट करें",
        "4. ध्वनि चालू/बंद",
        "5. उच्चारण अनदेखा करें चालू/बंद",
        "6. एक राउंड क्विज़ चालू/बंद",
        "0. मुख्य मेनू पर वापस जाएं",
        "\n=========================================="
    },

    // Latin (23)
    {
        "================MENU CONFIGURATIONIS================",
        "Optionem elige:",
        "1. Linguam pone",
        "2. Linguam discendi pone",
        "3. Colores pone",
        "4. Sonus on/off",
        "5. Accentus ignora on/off",
        "6. Quiz una rota on/off",
        "0. Redi ad menu principale",
        "\n=============================================="
    }

};

const std::vector<LanguageMenu> languageMenuTranslations {
    { // Hungarian (Index 0)
        "============NYELV_VÁLASZTÁSI_MENU============",
        "0. Visszalépés a beállításokba",
        "\nKérlek válaszd ki a program nyelvét: ",
        "\n==============================================",
        "A nyelv sikeresen megváltoztatva"
    },

    // ENGLISH (Index 1)
    {
        "============LANGUAGE_SELECTION_MENU============",
        "0. Return to settings",
        "\nPlease select the program language: ",
        "\n==============================================",
        "Language successfully changed"
    },

    // CHINESE (Index 2)
    {
        "============语言选择菜单============",
        "0. 返回设置",
        "\n请选择程序语言：",
        "\n==============================================",
        "语言修改成功"
    },

    // JAPANESE (Index 3)
    {
        "============言語選択メニュー============",
        "0. 設定に戻る",
        "\nプログラムの言語を選択してください：",
        "\n==============================================",
        "言語が正常に変更されました"
    },

    // SPANISH (Index 4)
    {
        "============MENÚ DE SELECCIÓN DE IDIOMA============",
        "0. Volver a configuración",
        "\nPor favor selecciona el idioma del programa: ",
        "\n==============================================",
        "Idioma cambiado correctamente"
    },

    // GERMAN (Index 5)
    {
        "============SPRACHAUSWAHLMENÜ============",
        "0. Zurück zu den Einstellungen",
        "\nBitte wählen Sie die Programmsprache: ",
        "\n==============================================",
        "Sprache erfolgreich geändert"
    },

    // FRENCH (Index 6)
    {
        "============MENU DE SÉLECTION DE LANGUE============",
        "0. Retour aux paramètres",
        "\nVeuillez sélectionner la langue du programme : ",
        "\n==============================================",
        "Langue modifiée avec succès"
    },

    // RUSSIAN (Index 7)
    {
        "============МЕНЮ ВЫБОРА ЯЗЫКА============",
        "0. Вернуться в настройки",
        "\nПожалуйста, выберите язык программы: ",
        "\n==============================================",
        "Язык успешно изменён"
    },

    // UKRAINIAN (Index 8)
    {
        "============МЕНЮ ВИБОРУ МОВИ============",
        "0. Повернутися до налаштувань",
        "\nБудь ласка, оберіть мову програми: ",
        "\n==============================================",
        "Мову успішно змінено"
    },

    // KOREAN (Index 9)
    {
        "============언어 선택 메뉴============",
        "0. 설정으로 돌아가기",
        "\n프로그램 언어를 선택하세요: ",
        "\n==============================================",
        "언어가 성공적으로 변경되었습니다"
    },

    // ITALIAN (Index 10)
    {
        "============MENU SELEZIONE LINGUA============",
        "0. Torna alle impostazioni",
        "\nSeleziona la lingua del programma: ",
        "\n==============================================",
        "Lingua modificata con successo"
    },

    // POLISH (Index 11)
    {
        "============MENU WYBORU JĘZYKA============",
        "0. Powrót do ustawień",
        "\nWybierz język programu: ",
        "\n==============================================",
        "Język został zmieniony"
    },

    // ARABIC (Index 12)
    {
        "============قائمة اختيار اللغة============",
        "0. العودة إلى الإعدادات",
        "\nيرجى اختيار لغة البرنامج: ",
        "\n==============================================",
        "تم تغيير اللغة بنجاح"
    },

    // VIETNAMESE (Index 13)
    {
        "============MENU CHỌN NGÔN NGỮ============",
        "0. Quay lại cài đặt",
        "\nVui lòng chọn ngôn ngữ chương trình: ",
        "\n==============================================",
        "Đã thay đổi ngôn ngữ thành công"
    },

    // TAGALOG (Index 14)
    {
        "============MENU NG PAGPILI NG WIKA============",
        "0. Bumalik sa settings",
        "\nPumili ng wika ng programa: ",
        "\n==============================================",
        "Matagumpay na napalitan ang wika"
    },

    // GREEK (Index 15)
    {
        "============ΜΕΝΟΥ ΕΠΙΛΟΓΗΣ ΓΛΩΣΣΑΣ============",
        "0. Επιστροφή στις ρυθμίσεις",
        "\nΠαρακαλώ επιλέξτε τη γλώσσα του προγράμματος: ",
        "\n==============================================",
        "Η γλώσσα άλλαξε επιτυχώς"
    },

    // HEBREW (Index 16)
    {
        "============תפריט בחירת שפה============",
        "0. חזרה להגדרות",
        "\nבחר את שפת התוכנית: ",
        "\n==============================================",
        "השפה שונתה בהצלחה"
    },

    // PORTUGUESE (Index 17)
    {
        "============MENU DE SELEÇÃO DE IDIOMA============",
        "0. Voltar para configurações",
        "\nSelecione o idioma do programa: ",
        "\n==============================================",
        "Idioma alterado com sucesso"
    },

    // FARSI (Index 18)
    {
        "============منوی انتخاب زبان============",
        "0. بازگشت به تنظیمات",
        "\nلطفاً زبان برنامه را انتخاب کنید: ",
        "\n==============================================",
        "زبان با موفقیت تغییر یافت"
    },

    // SWEDISH (Index 19)
    {
        "============SPRÅKVALSMENY============",
        "0. Tillbaka till inställningar",
        "\nVälj programspråk: ",
        "\n==============================================",
        "Språket ändrades framgångsrikt"
    },

    // DUTCH (Index 20)
    {
        "============TAALSELECTIEMENU============",
        "0. Terug naar instellingen",
        "\nSelecteer de programmat taal: ",
        "\n==============================================",
        "Taal succesvol gewijzigd"
    },

    // TURKISH (Index 21)
    {
        "============DİL SEÇİM MENÜSÜ============",
        "0. Ayarlara geri dön",
        "\nProgram dilini seçin: ",
        "\n==============================================",
        "Dil başarıyla değiştirildi"
    },

    // HINDI (Index 22)
    {
        "============भाषा चयन मेनू============",
        "0. सेटिंग्स पर वापस जाएँ",
        "\nकृपया प्रोग्राम की भाषा चुनें: ",
        "\n==============================================",
        "भाषा सफलतापूर्वक बदली गई"
    },

    // LATIN (Index 23)
    {
        "============MENU LINGUAE SELECTIONIS============",
        "0. Redire ad configurationes",
        "\nElige linguam programmatis: ",
        "\n==============================================",
        "Lingua feliciter mutata est"
    }


};

const std::vector<ColorsOnset> colorsOSetTranslations {
    { // Hungarian (Index 0)
        "========A SZÍNEK BEÁLLÍTÁSA=========",
        "Jelenlegi állapot: ",
        "BE",
        "KI",
        "1. Be/ki kapcsolás...",
        "\n2. Háttérszín beállítása",
        "\n3. Vissza",
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
        "\n2. Set background color",
        "\n3. Back",
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
        "\n2. 设置背景颜色",
        "\n3. 返回",
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
        "\n2. 背景色の設定",
        "\n3. 戻る",
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
        "\n2. Configurar color de fondo",
        "\n3. Volver",
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
        "\n2. Hintergrundfarbe einstellen",
        "\n3. Zurück",
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
        "\n2. Définir la couleur de fond",
        "\n3. Retour",
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
        "\n2. Установить цвет фона",
        "\n3. Назад",
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
        "\n2. Встановити колір фону",
        "\n3. Назад",
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
        "\n2. 배경 색상 설정",
        "\n3. 뒤로",
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
        "\n2. Imposta colore di sfondo",
        "\n3. Indietro",
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
        "\n2. Ustaw kolor tła",
        "\n3. Powrót",
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
        "\n2. تعيين لون الخلفية",
        "\n3. رجوع",
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
        "\n2. Cài đặt màu nền",
        "\n3. Quay lại",
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
        "\n2. Itakda ang kulay ng background",
        "\n3. Bumalik",
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
        "\n2. Ορισμός χρώματος φόντου",
        "\n3. Πίσω",
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
        "\n2. הגדרת צבע רקע",
        "\n3. חזרה",
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
        "\n2. Definir cor de fundo",
        "\n3. Voltar",
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
        "\n2. تنظیم رنگ پس‌زمینه",
        "\n3. بازگشت",
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
        "\n2. Ställ in bakgrundsfärg",
        "\n3. Tillbaka",
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
        "\n2. Achtergrondkleur instellen",
        "\n3. Terug",
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
        "\n2. Arka plan rengi ayarla",
        "\n3. Geri",
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
        "\n2. पृष्ठभूमि रंग सेट करें",
        "\n3. वापस",
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
        "\n2. Colorem fundi define",
        "\n3. Redire",
        "Electio: ",
        "Colores activati sunt...",
        "Colores deactivati sunt...",
        "Quaeso colores primum activa ut fundum mutare possis!"
    }
};

const std::vector<SaveSettings> saveSettingsTranslations {
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

const std::vector<LearningLanguageSet> learningLanguageSetTranslations {
    { // Hungarian (Index 0)
        "==== A tanulandó nyelv beállítása ====",
        "A jelenlegi anyanyelv: ",
        "A jelenlegi tanult nyelv: ",
        "1. Az anyanyelv módosítása",
        "\n2. A tanult nyelv módosítása",
        "\n3. Visszalépés a beállításokba",
        "Kérlek válaszd ki az anyanyelved: ",
        "\nVálasztás (1-24): ",
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
        "\n2. Change learning language",
        "\n3. Back to settings",
        "Please select your native language: ",
        "\nChoice (1-24): ",
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
        "\n2. 修改学习语言",
        "\n3. 返回设置",
        "请选择你的母语：",
        "\n选择 (1-24)：",
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
        "\n2. 学習言語を変更",
        "\n3. 設定に戻る",
        "母国語を選択してください：",
        "\n選択 (1-24)：",
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
        "\n2. Cambiar idioma de aprendizaje",
        "\n3. Volver a configuración",
        "Por favor selecciona tu idioma nativo: ",
        "\nElección (1-24): ",
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
        "\n2. Lernsprache ändern",
        "\n3. Zurück zu den Einstellungen",
        "Bitte wählen Sie Ihre Muttersprache: ",
        "\nAuswahl (1-24): ",
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
        "\n2. Modifier la langue d'apprentissage",
        "\n3. Retour aux paramètres",
        "Veuillez choisir votre langue maternelle : ",
        "\nChoix (1-24) : ",
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
        "\n2. Изменить изучаемый язык",
        "\n3. Назад к настройкам",
        "Выберите ваш родной язык: ",
        "\nВыбор (1-24): ",
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
        "\n2. Змінити мову навчання",
        "\n3. Назад до налаштувань",
        "Оберіть вашу рідну мову: ",
        "\nВибір (1-24): ",
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
        "\n2. 학습 언어 변경",
        "\n3. 설정으로 돌아가기",
        "모국어를 선택하세요: ",
        "\n선택 (1-24): ",
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
        "\n2. Cambia lingua di apprendimento",
        "\n3. Torna alle impostazioni",
        "Seleziona la tua lingua madre: ",
        "\nScelta (1-24): ",
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
        "\n2. Zmień język nauki",
        "\n3. Powrót do ustawień",
        "Wybierz swój język ojczysty: ",
        "\nWybór (1-24): ",
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
        "\n2. تغيير لغة التعلم",
        "\n3. العودة إلى الإعدادات",
        "يرجى اختيار لغتك الأم: ",
        "\nاختيار (1-24): ",
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
        "\n2. Thay đổi ngôn ngữ học",
        "\n3. Quay lại cài đặt",
        "Chọn ngôn ngữ mẹ đẻ của bạn: ",
        "\nLựa chọn (1-24): ",
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
        "\n2. Baguhin ang pinag-aaralang wika",
        "\n3. Bumalik sa settings",
        "Piliin ang iyong katutubong wika: ",
        "\nPili (1-24): ",
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
        "\n2. Αλλαγή γλώσσας εκμάθησης",
        "\n3. Επιστροφή στις ρυθμίσεις",
        "Επιλέξτε τη μητρική σας γλώσσα: ",
        "\nΕπιλογή (1-24): ",
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
        "\n2. שינוי שפת לימוד",
        "\n3. חזרה להגדרות",
        "בחר את שפת האם שלך: ",
        "\nבחירה (1-24): ",
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
        "\n2. Alterar idioma de aprendizagem",
        "\n3. Voltar às configurações",
        "Selecione seu idioma nativo: ",
        "\nEscolha (1-24): ",
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
        "\n2. تغییر زبان یادگیری",
        "\n3. بازگشت به تنظیمات",
        "لطفاً زبان مادری خود را انتخاب کنید: ",
        "\nانتخاب (1-24): ",
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
        "\n2. Ändra inlärningsspråk",
        "\n3. Tillbaka till inställningar",
        "Välj ditt modersmål: ",
        "\nVal (1-24): ",
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
        "\n2. Leertaal wijzigen",
        "\n3. Terug naar instellingen",
        "Selecteer je moedertaal: ",
        "\nKeuze (1-24): ",
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
        "\n2. Öğrenilen dili değiştir",
        "\n3. Ayarlara geri dön",
        "Ana dilinizi seçin: ",
        "\nSeçim (1-24): ",
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
        "\n2. सीखने की भाषा बदलें",
        "\n3. सेटिंग्स पर वापस जाएँ",
        "अपनी मातृभाषा चुनें: ",
        "\nचयन (1-24): ",
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
        "\n2. Linguam discendam muta",
        "\n3. Redire ad configurationes",
        "Elige linguam maternam: ",
        "\nElectio (1-24): ",
        "Lingua materna feliciter configurata est!",
        "Elige linguam discendam: ",
        "Lingua discenda feliciter configurata est!",
        "Electio: ",
        "0. - redire -",
        "Error: Lingua materna et lingua discenda eadem esse non possunt!",
        "============= Menu =============="
    }
};
const std::vector<TargetLanguageNameSet> targetLanguageSetTranslations {
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

const std::vector<targetLanguageList> targetLanguageListTranslations {

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

const std::vector<ListAndSelectedFile> listAndSelectedFilesTranslations {

    // HUNGARIAN (0)
    {
        "--- Jelenlegi mappa: ",
        "(Üres mappa)\n",
        "[MAPPA] ",
        "---------------------------------------\nParancsok: név +",
        ".. -> kilépés a mappából, del -> törlés, cp -> másolás, mv -> áthelyezés,\nrn -> átnevezés, edit -> szerkesztés, md vagy mkdir -> új mappa, exit -> kilépés",
        "Választás: "
    },

    // ENGLISH (1)
    {
        "--- Current folder: ",
        "(Empty folder)\n",
        "[FOLDER] ",
        "---------------------------------------\nCommands: name +",
        ".. -> up, del -> delete, cp -> copy, mv -> move,\nrn -> rename, edit -> edit, md or mkdir -> new folder, exit -> exit",
        "Selection: "
    },

    // CHINESE (2)
    {
        "--- 当前目录: ",
        "(空文件夹)\n",
        "[文件夹] ",
        "---------------------------------------\n命令: 名称 +",
        ".. -> 返回上级, del -> 删除, cp -> 复制, mv -> 移动,\nrn -> 重命名, edit -> 编辑, md 或 mkdir -> 新建文件夹, exit -> 退出",
        "选择: "
    },

    // JAPANESE (3)
    {
        "--- 現在のフォルダ: ",
        "(空のフォルダ)\n",
        "[フォルダ] ",
        "---------------------------------------\nコマンド: 名前 +",
        ".. -> 上へ戻る, del -> 削除, cp -> コピー, mv -> 移動,\nrn -> 名前変更, edit -> 編集, md または mkdir -> 新しいフォルダ, exit -> 終了",
        "選択: "
    },

    // SPANISH (4)
    {
        "--- Carpeta actual: ",
        "(Carpeta vacía)\n",
        "[CARPETA] ",
        "---------------------------------------\nComandos: nombre +",
        ".. -> subir, del -> eliminar, cp -> copiar, mv -> mover,\nrn -> renombrar, edit -> editar, md o mkdir -> nueva carpeta, exit -> salir",
        "Selección: "
    },

    // GERMAN (5)
    {
        "--- Aktueller Ordner: ",
        "(Leerer Ordner)\n",
        "[ORDNER] ",
        "---------------------------------------\nBefehle: Name +",
        ".. -> zurück, del -> löschen, cp -> kopieren, mv -> verschieben,\nrn -> umbenennen, edit -> bearbeiten, md oder mkdir -> neuer Ordner, exit -> beenden",
        "Auswahl: "
    },

    // FRENCH (6)
    {
        "--- Dossier actuel: ",
        "(Dossier vide)\n",
        "[DOSSIER] ",
        "---------------------------------------\nCommandes: nom +",
        ".. -> retour, del -> supprimer, cp -> copier, mv -> déplacer,\nrn -> renommer, edit -> éditer, md ou mkdir -> nouveau dossier, exit -> quitter",
        "Choix: "
    },

    // RUSSIAN (7)
    {
        "--- Текущая папка: ",
        "(Пустая папка)\n",
        "[ПАПКА] ",
        "---------------------------------------\nКоманды: имя +",
        ".. -> назад, del -> удалить, cp -> копировать, mv -> переместить,\nrn -> переименовать, edit -> редактировать, md или mkdir -> новая папка, exit -> выход",
        "Выбор: "
    },

    // UKRAINIAN (8)
    {
        "--- Поточна папка: ",
        "(Порожня папка)\n",
        "[ПАПКА] ",
        "---------------------------------------\nКоманди: ім'я +",
        ".. -> назад, del -> видалити, cp -> копіювати, mv -> перемістити,\nrn -> перейменувати, edit -> редагувати, md або mkdir -> нова папка, exit -> вихід",
        "Вибір: "
    },

    // KOREAN (9)
    {
        "--- 현재 폴더: ",
        "(빈 폴더)\n",
        "[폴더] ",
        "---------------------------------------\n명령어: 이름 +",
        ".. -> 상위로, del -> 삭제, cp -> 복사, mv -> 이동,\nrn -> 이름변경, edit -> 편집, md 또는 mkdir -> 새 폴더, exit -> 종료",
        "선택: "
    },

    // ITALIAN (10)
    {
        "--- Cartella corrente: ",
        "(Cartella vuota)\n",
        "[CARTELLA] ",
        "---------------------------------------\nComandi: nome +",
        ".. -> su, del -> elimina, cp -> copia, mv -> sposta,\nrn -> rinomina, edit -> modifica, md o mkdir -> nuova cartella, exit -> esci",
        "Scelta: "
    },

    // POLISH (11)
    {
        "--- Bieżący folder: ",
        "(Pusty folder)\n",
        "[FOLDER] ",
        "---------------------------------------\nKomendy: nazwa +",
        ".. -> w górę, del -> usuń, cp -> kopiuj, mv -> przenieś,\nrn -> zmień nazwę, edit -> edytuj, md lub mkdir -> nowy folder, exit -> wyjście",
        "Wybór: "
    },

    // ARABIC (12)
    {
        "--- المجلد الحالي: ",
        "(مجلد فارغ)\n",
        "[مجلد] ",
        "---------------------------------------\nالأوامر: اسم +",
        ".. -> رجوع, del -> حذف, cp -> نسخ, mv -> نقل,\nrn -> إعادة تسمية, edit -> تحرير, md أو mkdir -> مجلد جديد, exit -> خروج",
        "اختيار: "
    },

    // VIETNAMESE (13)
    {
        "--- Thư mục hiện tại: ",
        "(Thư mục trống)\n",
        "[THƯ MỤC] ",
        "---------------------------------------\nLệnh: tên +",
        ".. -> lên, del -> xóa, cp -> sao chép, mv -> di chuyển,\nrn -> đổi tên, edit -> chỉnh sửa, md hoặc mkdir -> thư mục mới, exit -> thoát",
        "Chọn: "
    },

    // TAGALOG (14)
    {
        "--- Kasalukuyang folder: ",
        "(Walang laman ang folder)\n",
        "[FOLDER] ",
        "---------------------------------------\nMga utos: pangalan +",
        ".. -> pataas, del -> tanggal, cp -> kopya, mv -> lipat,\nrn -> palitan pangalan, edit -> edit, md o mkdir -> bagong folder, exit -> labas",
        "Piliin: "
    },

    // GREEK (15)
    {
        "--- Τρέχων φάκελος: ",
        "(Κενός φάκελος)\n",
        "[ΦΑΚΕΛΟΣ] ",
        "---------------------------------------\nΕντολές: όνομα +",
        ".. -> πίσω, del -> διαγραφή, cp -> αντιγραφή, mv -> μετακίνηση,\nrn -> μετονομασία, edit -> επεξεργασία, md ή mkdir -> νέος φάκελος, exit -> έξοδος",
        "Επιλογή: "
    },

    // HEBREW (16)
    {
        "--- תיקייה נוכחית: ",
        "(תיקייה ריקה)\n",
        "[תיקייה] ",
        "---------------------------------------\nפקודות: שם +",
        ".. -> חזרה, del -> מחיקה, cp -> העתקה, mv -> העברה,\nrn -> שינוי שם, edit -> עריכה, md או mkdir -> תיקייה חדשה, exit -> יציאה",
        "בחירה: "
    },

    // PORTUGUESE (17)
    {
        "--- Pasta atual: ",
        "(Pasta vazia)\n",
        "[PASTA] ",
        "---------------------------------------\nComandos: nome +",
        ".. -> voltar, del -> excluir, cp -> copiar, mv -> mover,\nrn -> renomear, edit -> editar, md ou mkdir -> nova pasta, exit -> sair",
        "Seleção: "
    },

    // FARSI (18)
    {
        "--- پوشه فعلی: ",
        "(پوشه خالی)\n",
        "[پوشه] ",
        "---------------------------------------\nدستورات: نام +",
        ".. -> بازگشت, del -> حذف, cp -> کپی, mv -> انتقال,\nrn -> تغییر نام, edit -> ویرایش, md یا mkdir -> پوشه جدید, exit -> خروج",
        "انتخاب: "
    },

    // SWEDISH (19)
    {
        "--- Nuvarande mapp: ",
        "(Tom mapp)\n",
        "[MAPP] ",
        "---------------------------------------\nKommandon: namn +",
        ".. -> upp, del -> radera, cp -> kopiera, mv -> flytta,\nrn -> byt namn, edit -> redigera, md eller mkdir -> ny mapp, exit -> avsluta",
        "Val: "
    },

    // DUTCH (20)
    {
        "--- Huidige map: ",
        "(Lege map)\n",
        "[MAP] ",
        "---------------------------------------\nCommando's: naam +",
        ".. -> omhoog, del -> verwijderen, cp -> kopiëren, mv -> verplaatsen,\nrn -> hernoemen, edit -> bewerken, md of mkdir -> nieuwe map, exit -> afsluiten",
        "Keuze: "
    },

    // TURKISH (21)
    {
        "--- Mevcut klasör: ",
        "(Boş klasör)\n",
        "[KLASÖR] ",
        "---------------------------------------\nKomutlar: isim +",
        ".. -> yukarı, del -> sil, cp -> kopyala, mv -> taşı,\nrn -> yeniden adlandır, edit -> düzenle, md veya mkdir -> yeni klasör, exit -> çıkış",
        "Seçim: "
    },

    // HINDI (22)
    {
        "--- वर्तमान फ़ोल्डर: ",
        "(खाली फ़ोल्डर)\n",
        "[फ़ोल्डर] ",
        "---------------------------------------\nकमांड: नाम +",
        ".. -> ऊपर, del -> हटाएँ, cp -> कॉपी, mv -> मूव,\nrn -> नाम बदलें, edit -> संपादित करें, md या mkdir -> नया फ़ोल्डर, exit -> बाहर",
        "चयन: "
    },

    // LATIN (23)
    {
        "--- Directorium currente: ",
        "(Directorium vacuum)\n",
        "[DIRECTORIUM] ",
        "---------------------------------------\nMandata: nomen +",
        ".. -> retro, del -> delere, cp -> copiare, mv -> movere,\nrn -> renominare, edit -> recensere, md vel mkdir -> novum directorium, exit -> exire",
        "Electio: "
    }
};

const std::vector<RenameFilesAndFolders> renameFilesAndFoldersTranslations {
        { // Hungarian (Index 0)
            "Átnevezendő: " ,
           "\nUj nev: "
        },
    // ENGLISH (Index 1)
   {
       "Rename: ",
       "\nNew name: "
   },

   // CHINESE (Index 2)
   {
       "重命名: ",
       "\n新名称: "
   },

   // JAPANESE (Index 3)
   {
       "名前変更: ",
       "\n新しい名前: "
   },

   // SPANISH (Index 4)
   {
       "Renombrar: ",
       "\nNuevo nombre: "
   },

   // GERMAN (Index 5)
   {
       "Umbenennen: ",
       "\nNeuer Name: "
   },

   // FRENCH (Index 6)
   {
       "Renommer: ",
       "\nNouveau nom: "
   },

   // RUSSIAN (Index 7)
   {
       "Переименовать: ",
       "\nНовое имя: "
   },

   // UKRAINIAN (Index 8)
   {
       "Перейменувати: ",
       "\nНове ім'я: "
   },

   // KOREAN (Index 9)
   {
       "이름 변경: ",
       "\n새 이름: "
   },

   // ITALIAN (Index 10)
   {
       "Rinomina: ",
       "\nNuovo nome: "
   },

   // POLISH (Index 11)
   {
       "Zmień nazwę: ",
       "\nNowa nazwa: "
   },

   // ARABIC (Index 12)
   {
       "إعادة تسمية: ",
       "\nاسم جديد: "
   },

   // VIETNAMESE (Index 13)
   {
       "Đổi tên: ",
       "\nTên mới: "
   },

   // TAGALOG (Index 14)
   {
       "Palitan ang pangalan: ",
       "\nBagong pangalan: "
   },

   // GREEK (Index 15)
   {
       "Μετονομασία: ",
       "\nΝέο όνομα: "
   },

   // HEBREW (Index 16)
   {
       "שנה שם: ",
       "\nשם חדש: "
   },

   // PORTUGUESE (Index 17)
   {
       "Renomear: ",
       "\nNovo nome: "
   },

   // FARSI (Index 18)
   {
       "تغییر نام: ",
       "\nنام جدید: "
   },

   // SWEDISH (Index 19)
   {
       "Byt namn: ",
       "\nNytt namn: "
   },

   // DUTCH (Index 20)
   {
       "Hernoemen: ",
       "\nNieuwe naam: "
   },

   // TURKISH (Index 21)
   {
       "Yeniden adlandır: ",
       "\nYeni ad: "
   },

   // HINDI (Index 22)
   {
       "नाम बदलें: ",
       "\nनया नाम: "
   },

   // LATIN (Index 23)
   {
       "Renominare: ",
       "\nNovum nomen: "
   }
};

const std::vector<MovingFileFolders> movingFileFoldersTranslations {

    { //hungarian (index 0)
        "Áthelyezendő: ",
        "\nUj név/útvonal: "
    },

    // ENGLISH (index 1)
    {
        "Move: ",
        "\nNew name/path: "
    },

    // CHINESE (index 2)
    {
        "移动: ",
        "\n新名称/路径: "
    },

    // JAPANESE (index 3)
    {
        "移動: ",
        "\n新しい名前/パス: "
    },

    // SPANISH (index 4)
    {
        "Mover: ",
        "\nNuevo nombre/ruta: "
    },

    // GERMAN (index 5)
    {
        "Verschieben: ",
        "\nNeuer Name/Pfad: "
    },

    // FRENCH (index 6)
    {
        "Déplacer: ",
        "\nNouveau nom/chemin: "
    },

    // RUSSIAN (index 7)
    {
        "Переместить: ",
        "\nНовое имя/путь: "
    },

    // UKRAINIAN (index 8)
    {
        "Перемістити: ",
        "\nНове ім'я/шлях: "
    },

    // KOREAN (index 9)
    {
        "이동: ",
        "\n새 이름/경로: "
    },

    // ITALIAN (index 10)
    {
        "Sposta: ",
        "\nNuovo nome/percorso: "
    },

    // POLISH (index 11)
    {
        "Przenieś: ",
        "\nNowa nazwa/ścieżka: "
    },

    // ARABIC (index 12)
    {
        "نقل: ",
        "\nاسم/مسار جديد: "
    },

    // VIETNAMESE (index 13)
    {
        "Di chuyển: ",
        "\nTên/đường dẫn mới: "
    },

    // TAGALOG (index 14)
    {
        "Ilipat: ",
        "\nBagong pangalan/landas: "
    },

    // GREEK (index 15)
    {
        "Μετακίνηση: ",
        "\nΝέο όνομα/διαδρομή: "
    },

    // HEBREW (index 16)
    {
        "העבר: ",
        "\nשם/נתיב חדש: "
    },

    // PORTUGUESE (index 17)
    {
        "Mover: ",
        "\nNovo nome/caminho: "
    },

    // FARSI (index 18)
    {
        "انتقال: ",
        "\nنام/مسیر جدید: "
    },

    // SWEDISH (index 19)
    {
        "Flytta: ",
        "\nNytt namn/sökväg: "
    },

    // DUTCH (index 20)
    {
        "Verplaatsen: ",
        "\nNieuwe naam/pad: "
    },

    // TURKISH (index 21)
    {
        "Taşı: ",
        "\nYeni ad/yol: "
    },

    // HINDI (index 22)
    {
        "स्थानांतरित करें: ",
        "\nनया नाम/पथ: "
    },

    // LATIN (index 23)
    {
        "Transferre: ",
        "\nNovum nomen/iter: "
    }
};

const std::vector<DeleteFileFolders> deleteFileFoldersTranslations{

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

const std::vector<CopyFileFolders> copyFileFoldersTranslations{

    { //Hungarian (Index 0)
        "Hiba: Veszélyes forrás útvonal!",
        "Másolandó: ",
        "Útvonal/Új név\npl: (./data/mappaNeve/fajl.data): ",
        "Hiba: Veszélyes cél útvonal!",
        "Sikeres másolás!",
        "Hiba történt!"
    },

    { //English (Index 1)
        "Error: Dangerous source path!",
        "Copying: ",
        "Path/New name\ne.g.: (./data/folderName/file.data): ",
        "Error: Dangerous destination path!",
        "Copy successful!",
        "An error occurred!"
    },

    { //Chinese (Index 2)
        "错误：危险的源路径！",
        "正在复制：",
        "路径/新名称\n例如：(./data/文件夹/文件.data)：",
        "错误：危险的目标路径！",
        "复制成功！",
        "发生错误！"
    },

    { //Japanese (Index 3)
        "エラー：危険なソースパス！",
        "コピー中：",
        "パス/新しい名前\n例：(./data/フォルダ/ファイル.data)：",
        "エラー：危険な宛先パス！",
        "コピー成功！",
        "エラーが発生しました！"
    },

    { //Spanish (Index 4)
        "Error: ¡Ruta de origen peligrosa!",
        "Copiando: ",
        "Ruta/Nuevo nombre\nej.: (./data/carpeta/archivo.data): ",
        "Error: ¡Ruta de destino peligrosa!",
        "¡Copia exitosa!",
        "¡Ocurrió un error!"
    },

    { //German (Index 5)
        "Fehler: Gefährlicher Quellpfad!",
        "Kopiere: ",
        "Pfad/Neuer Name\nz.B.: (./data/ordner/datei.data): ",
        "Fehler: Gefährlicher Zielpfad!",
        "Kopieren erfolgreich!",
        "Ein Fehler ist aufgetreten!"
    },

    { //French (Index 6)
        "Erreur : Chemin source dangereux !",
        "Copie : ",
        "Chemin/Nouveau nom\nex : (./data/dossier/fichier.data) : ",
        "Erreur : Chemin de destination dangereux !",
        "Copie réussie !",
        "Une erreur est survenue !"
    },

    { //Russian (Index 7)
        "Ошибка: Опасный исходный путь!",
        "Копирование: ",
        "Путь/Новое имя\nнапр.: (./data/папка/файл.data): ",
        "Ошибка: Опасный путь назначения!",
        "Копирование успешно!",
        "Произошла ошибка!"
    },

    { //Ukrainian (Index 8)
        "Помилка: Небезпечний шлях джерела!",
        "Копіювання: ",
        "Шлях/Нове ім'я\nнапр.: (./data/папка/файл.data): ",
        "Помилка: Небезпечний шлях призначення!",
        "Копіювання успішне!",
        "Сталася помилка!"
    },

    { //Korean (Index 9)
        "오류: 위험한 원본 경로!",
        "복사 중: ",
        "경로/새 이름\n예: (./data/폴더/파일.data): ",
        "오류: 위험한 대상 경로!",
        "복사 성공!",
        "오류 발생!"
    },

    { //Italian (Index 10)
        "Errore: Percorso sorgente pericoloso!",
        "Copia in corso: ",
        "Percorso/Nuovo nome\nes.: (./data/cartella/file.data): ",
        "Errore: Percorso destinazione pericoloso!",
        "Copia riuscita!",
        "Si è verificato un errore!"
    },

    { //Polish (Index 11)
        "Błąd: Niebezpieczna ścieżka źródłowa!",
        "Kopiowanie: ",
        "Ścieżka/Nowa nazwa\nnp.: (./data/folder/plik.data): ",
        "Błąd: Niebezpieczna ścieżka docelowa!",
        "Kopiowanie zakończone sukcesem!",
        "Wystąpił błąd!"
    },

    { //Arabic (Index 12)
        "خطأ: مسار مصدر خطير!",
        "جاري النسخ: ",
        "المسار/اسم جديد\nمثال: (./data/مجلد/ملف.data): ",
        "خطأ: مسار وجهة خطير!",
        "تم النسخ بنجاح!",
        "حدث خطأ!"
    },

    { //Vietnamese (Index 13)
        "Lỗi: Đường dẫn nguồn nguy hiểm!",
        "Đang sao chép: ",
        "Đường dẫn/Tên mới\nví dụ: (./data/thumuc/tep.data): ",
        "Lỗi: Đường dẫn đích nguy hiểm!",
        "Sao chép thành công!",
        "Đã xảy ra lỗi!"
    },

    { //Tagalog (Index 14)
        "Error: Mapanganib na source path!",
        "Kinokopya: ",
        "Path/Bagong pangalan\nhal: (./data/folder/file.data): ",
        "Error: Mapanganib na destination path!",
        "Tagumpay ang pagkopya!",
        "May naganap na error!"
    },

    { //Greek (Index 15)
        "Σφάλμα: Επικίνδυνη διαδρομή πηγής!",
        "Αντιγραφή: ",
        "Διαδρομή/Νέο όνομα\nπ.χ.: (./data/φάκελος/αρχείο.data): ",
        "Σφάλμα: Επικίνδυνη διαδρομή προορισμού!",
        "Επιτυχής αντιγραφή!",
        "Παρουσιάστηκε σφάλμα!"
    },

    { //Hebrew (Index 16)
        "שגיאה: נתיב מקור מסוכן!",
        "מעתיק: ",
        "נתיב/שם חדש\nלדוגמה: (./data/תיקיה/קובץ.data): ",
        "שגיאה: נתיב יעד מסוכן!",
        "ההעתקה הצליחה!",
        "אירעה שגיאה!"
    },

    { //Portuguese (Index 17)
        "Erro: Caminho de origem perigoso!",
        "Copiando: ",
        "Caminho/Novo nome\nex.: (./data/pasta/arquivo.data): ",
        "Erro: Caminho de destino perigoso!",
        "Cópia bem-sucedida!",
        "Ocorreu um erro!"
    },

    { //Farsi (Index 18)
        "خطا: مسیر مبدأ خطرناک!",
        "در حال کپی: ",
        "مسیر/نام جدید\nمثال: (./data/پوشه/فایل.data): ",
        "خطا: مسیر مقصد خطرناک!",
        "کپی موفق!",
        "خطایی رخ داد!"
    },

    { //Swedish (Index 19)
        "Fel: Farlig källsökväg!",
        "Kopierar: ",
        "Sökväg/Nytt namn\nt.ex.: (./data/mapp/fil.data): ",
        "Fel: Farlig målsökväg!",
        "Kopiering lyckades!",
        "Ett fel uppstod!"
    },

    { //Dutch (Index 20)
        "Fout: Gevaarlijk bronpad!",
        "Kopiëren: ",
        "Pad/Nieuwe naam\nbijv.: (./data/map/bestand.data): ",
        "Fout: Gevaarlijk doelpad!",
        "Kopiëren gelukt!",
        "Er is een fout opgetreden!"
    },

    { //Turkish (Index 21)
        "Hata: Tehlikeli kaynak yolu!",
        "Kopyalanıyor: ",
        "Yol/Yeni ad\nörn.: (./data/klasor/dosya.data): ",
        "Hata: Tehlikeli hedef yolu!",
        "Kopyalama başarılı!",
        "Bir hata oluştu!"
    },

    { //Hindi (Index 22)
        "त्रुटि: खतरनाक स्रोत पथ!",
        "कॉपी हो रहा है: ",
        "पथ/नया नाम\nउदाहरण: (./data/folder/file.data): ",
        "त्रुटि: खतरनाक गंतव्य पथ!",
        "कॉपी सफल!",
        "एक त्रुटि हुई!"
    },

    { //Latin (Index 23)
        "Error: Via fontis periculosa!",
        "Copia: ",
        "Via/Nomen novum\nex: (./data/folder/file.data): ",
        "Error: Via destinationis periculosa!",
        "Copia felix!",
        "Error accidit!"
    }

};

const std::vector<W_wordPair> wordPairErrorTranslations {
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

const std::vector<LlistAndSelectedFile> LlistAndSelectedFileTranslations {
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

const std::vector<OosEditor> OosEditorTranslations{
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

const std::vector<BackgroundSets> backgroundSetsTranslations {
    { // Hungarian (Index 0)
        "--- A Háttérszín beállítása ---",
        "1. Alapértelmezett (fekete)\n",
        "2. Zöld\n",
        "3. Cián\n",
        "4. Piros\n",
        "5. Lila\n",
        "6. Kék\n",
        "7. Fehér\n",
        "8. Szürke\n",
        "9. Visszalépés\n",
        "A háttérszín sikeresen megváltoztatva!",
        "A háttér színe: "
    },

    // ENGLISH (Index 1)
    {
        "--- Background Color Settings ---",
        "1. Default (black)\n",
        "2. Green\n",
        "3. Cyan\n",
        "4. Red\n",
        "5. Purple\n",
        "6. Blue\n",
        "7. White\n",
        "8. Gray\n",
        "9. Back\n",
        "Background color successfully changed!",
        "Background color: "
    },

    // CHINESE (Index 2)
    {
        "--- 背景颜色设置 ---",
        "1. 默认（黑色）\n",
        "2. 绿色\n",
        "3. 青色\n",
        "4. 红色\n",
        "5. 紫色\n",
        "6. 蓝色\n",
        "7. 白色\n",
        "8. 灰色\n",
        "9. 返回\n",
        "背景颜色修改成功！",
        "背景颜色："
    },

    // JAPANESE (Index 3)
    {
        "--- 背景色設定 ---",
        "1. デフォルト（黒）\n",
        "2. 緑\n",
        "3. シアン\n",
        "4. 赤\n",
        "5. 紫\n",
        "6. 青\n",
        "7. 白\n",
        "8. 灰色\n",
        "9. 戻る\n",
        "背景色が正常に変更されました！",
        "背景色："
    },

    // SPANISH (Index 4)
    {
        "--- Configuración de color de fondo ---",
        "1. Predeterminado (negro)\n",
        "2. Verde\n",
        "3. Cian\n",
        "4. Rojo\n",
        "5. Morado\n",
        "6. Azul\n",
        "7. Blanco\n",
        "8. Gris\n",
        "9. Volver\n",
        "¡Color de fondo cambiado correctamente!",
        "Color de fondo: "
    },

    // GERMAN (Index 5)
    {
        "--- Hintergrundfarbe einstellen ---",
        "1. Standard (schwarz)\n",
        "2. Grün\n",
        "3. Cyan\n",
        "4. Rot\n",
        "5. Lila\n",
        "6. Blau\n",
        "7. Weiß\n",
        "8. Grau\n",
        "9. Zurück\n",
        "Hintergrundfarbe erfolgreich geändert!",
        "Hintergrundfarbe: "
    },

    // FRENCH (Index 6)
    {
        "--- Paramètres de couleur d'arrière-plan ---",
        "1. Par défaut (noir)\n",
        "2. Vert\n",
        "3. Cyan\n",
        "4. Rouge\n",
        "5. Violet\n",
        "6. Bleu\n",
        "7. Blanc\n",
        "8. Gris\n",
        "9. Retour\n",
        "Couleur d'arrière-plan modifiée avec succès !",
        "Couleur d'arrière-plan : "
    },

    // RUSSIAN (Index 7)
    {
        "--- Настройка цвета фона ---",
        "1. По умолчанию (чёрный)\n",
        "2. Зелёный\n",
        "3. Голубой\n",
        "4. Красный\n",
        "5. Фиолетовый\n",
        "6. Синий\n",
        "7. Белый\n",
        "8. Серый\n",
        "9. Назад\n",
        "Цвет фона успешно изменён!",
        "Цвет фона: "
    },

    // UKRAINIAN (Index 8)
    {
        "--- Налаштування кольору фону ---",
        "1. За замовчуванням (чорний)\n",
        "2. Зелений\n",
        "3. Блакитний\n",
        "4. Червоний\n",
        "5. Фіолетовий\n",
        "6. Синій\n",
        "7. Білий\n",
        "8. Сірий\n",
        "9. Назад\n",
        "Колір фону успішно змінено!",
        "Колір фону: "
    },

    // KOREAN (Index 9)
    {
        "--- 배경 색상 설정 ---",
        "1. 기본값 (검정)\n",
        "2. 초록\n",
        "3. 시안\n",
        "4. 빨강\n",
        "5. 보라\n",
        "6. 파랑\n",
        "7. 흰색\n",
        "8. 회색\n",
        "9. 뒤로\n",
        "배경 색상이 성공적으로 변경되었습니다!",
        "배경 색상: "
    },

    // ITALIAN (Index 10)
    {
        "--- Impostazioni colore sfondo ---",
        "1. Predefinito (nero)\n",
        "2. Verde\n",
        "3. Ciano\n",
        "4. Rosso\n",
        "5. Viola\n",
        "6. Blu\n",
        "7. Bianco\n",
        "8. Grigio\n",
        "9. Indietro\n",
        "Colore di sfondo modificato con successo!",
        "Colore di sfondo: "
    },

    // POLISH (Index 11)
    {
        "--- Ustawienia koloru tła ---",
        "1. Domyślny (czarny)\n",
        "2. Zielony\n",
        "3. Cyjan\n",
        "4. Czerwony\n",
        "5. Fioletowy\n",
        "6. Niebieski\n",
        "7. Biały\n",
        "8. Szary\n",
        "9. Powrót\n",
        "Kolor tła został zmieniony!",
        "Kolor tła: "
    },

    // ARABIC (Index 12)
    {
        "--- إعدادات لون الخلفية ---",
        "1. افتراضي (أسود)\n",
        "2. أخضر\n",
        "3. سماوي\n",
        "4. أحمر\n",
        "5. بنفسجي\n",
        "6. أزرق\n",
        "7. أبيض\n",
        "8. رمادي\n",
        "9. رجوع\n",
        "تم تغيير لون الخلفية بنجاح!",
        "لون الخلفية: "
    },

    // VIETNAMESE (Index 13)
    {
        "--- Cài đặt màu nền ---",
        "1. Mặc định (đen)\n",
        "2. Xanh lá\n",
        "3. Cyan\n",
        "4. Đỏ\n",
        "5. Tím\n",
        "6. Xanh dương\n",
        "7. Trắng\n",
        "8. Xám\n",
        "9. Quay lại\n",
        "Đã thay đổi màu nền thành công!",
        "Màu nền: "
    },

    // TAGALOG (Index 14)
    {
        "--- Setting ng kulay ng background ---",
        "1. Default (itim)\n",
        "2. Berde\n",
        "3. Cyan\n",
        "4. Pula\n",
        "5. Lila\n",
        "6. Asul\n",
        "7. Puti\n",
        "8. Abo\n",
        "9. Bumalik\n",
        "Matagumpay na nabago ang kulay ng background!",
        "Kulay ng background: "
    },

    // GREEK (Index 15)
    {
        "--- Ρυθμίσεις χρώματος φόντου ---",
        "1. Προεπιλογή (μαύρο)\n",
        "2. Πράσινο\n",
        "3. Κυανό\n",
        "4. Κόκκινο\n",
        "5. Μωβ\n",
        "6. Μπλε\n",
        "7. Λευκό\n",
        "8. Γκρι\n",
        "9. Πίσω\n",
        "Το χρώμα φόντου άλλαξε επιτυχώς!",
        "Χρώμα φόντου: "
    },

    // HEBREW (Index 16)
    {
        "--- הגדרות צבע רקע ---",
        "1. ברירת מחדל (שחור)\n",
        "2. ירוק\n",
        "3. ציאן\n",
        "4. אדום\n",
        "5. סגול\n",
        "6. כחול\n",
        "7. לבן\n",
        "8. אפור\n",
        "9. חזרה\n",
        "צבע הרקע שונה בהצלחה!",
        "צבע רקע: "
    },

    // PORTUGUESE (Index 17)
    {
        "--- Configurações de cor de fundo ---",
        "1. Padrão (preto)\n",
        "2. Verde\n",
        "3. Ciano\n",
        "4. Vermelho\n",
        "5. Roxo\n",
        "6. Azul\n",
        "7. Branco\n",
        "8. Cinza\n",
        "9. Voltar\n",
        "Cor de fundo alterada com sucesso!",
        "Cor de fundo: "
    },

    // FARSI (Index 18)
    {
        "--- تنظیم رنگ پس‌زمینه ---",
        "1. پیش‌فرض (مشکی)\n",
        "2. سبز\n",
        "3. فیروزه‌ای\n",
        "4. قرمز\n",
        "5. بنفش\n",
        "6. آبی\n",
        "7. سفید\n",
        "8. خاکستری\n",
        "9. بازگشت\n",
        "رنگ پس‌زمینه با موفقیت تغییر یافت!",
        "رنگ پس‌زمینه: "
    },

    // SWEDISH (Index 19)
    {
        "--- Inställningar för bakgrundsfärg ---",
        "1. Standard (svart)\n",
        "2. Grön\n",
        "3. Cyan\n",
        "4. Röd\n",
        "5. Lila\n",
        "6. Blå\n",
        "7. Vit\n",
        "8. Grå\n",
        "9. Tillbaka\n",
        "Bakgrundsfärgen ändrades!",
        "Bakgrundsfärg: "
    },

    // DUTCH (Index 20)
    {
        "--- Instellingen achtergrondkleur ---",
        "1. Standaard (zwart)\n",
        "2. Groen\n",
        "3. Cyaan\n",
        "4. Rood\n",
        "5. Paars\n",
        "6. Blauw\n",
        "7. Wit\n",
        "8. Grijs\n",
        "9. Terug\n",
        "Achtergrondkleur succesvol gewijzigd!",
        "Achtergrondkleur: "
    },

    // TURKISH (Index 21)
    {
        "--- Arka plan rengi ayarları ---",
        "1. Varsayılan (siyah)\n",
        "2. Yeşil\n",
        "3. Camgöbeği\n",
        "4. Kırmızı\n",
        "5. Mor\n",
        "6. Mavi\n",
        "7. Beyaz\n",
        "8. Gri\n",
        "9. Geri\n",
        "Arka plan rengi başarıyla değiştirildi!",
        "Arka plan rengi: "
    },

    // HINDI (Index 22)
    {
        "--- पृष्ठभूमि रंग सेटिंग्स ---",
        "1. डिफ़ॉल्ट (काला)\n",
        "2. हरा\n",
        "3. सियान\n",
        "4. लाल\n",
        "5. बैंगनी\n",
        "6. नीला\n",
        "7. सफेद\n",
        "8. ग्रे\n",
        "9. वापस\n",
        "पृष्ठभूमि रंग सफलतापूर्वक बदला गया!",
        "पृष्ठभूमि रंग: "
    },

    // LATIN (Index 23)
    {
        "--- Configurationes coloris fundi ---",
        "1. Default (niger)\n",
        "2. Viridis\n",
        "3. Cyanus\n",
        "4. Ruber\n",
        "5. Purpureus\n",
        "6. Caeruleus\n",
        "7. Albus\n",
        "8. Griseus\n",
        "9. Redire\n",
        "Color fundi feliciter mutatus est!",
        "Color fundi: "
    }
};

const std::vector<SoundOnOff> soundOnOffTranslations {
    { // Hungarian (Index 0)
        "--- A hang beállítása ---",
        "Jelenlegi állapot: ",
        "BE",
        "KI",
        "1. Be/Ki kapcsolás\n0. Vissza\nVálasztás: ",
        "Hang bekapcsolva!",
        "Hang kikapcsolva!"
    },

    // ENGLISH (Index 1)
    {
        "--- Sound Settings ---",
        "Current state: ",
        "ON",
        "OFF",
        "1. Toggle On/Off\n0. Back\nChoice: ",
        "Sound enabled!",
        "Sound disabled!"
    },

    // CHINESE (Index 2)
    {
        "--- 声音设置 ---",
        "当前状态：",
        "开",
        "关",
        "1. 开/关切换\n0. 返回\n选择：",
        "声音已开启！",
        "声音已关闭！"
    },

    // JAPANESE (Index 3)
    {
        "--- サウンド設定 ---",
        "現在の状態：",
        "オン",
        "オフ",
        "1. オン/オフ切替\n0. 戻る\n選択：",
        "サウンドが有効になりました！",
        "サウンドが無効になりました！"
    },

    // SPANISH (Index 4)
    {
        "--- Configuración de sonido ---",
        "Estado actual: ",
        "ENCENDIDO",
        "APAGADO",
        "1. Activar/Desactivar\n0. Volver\nElección: ",
        "¡Sonido activado!",
        "¡Sonido desactivado!"
    },

    // GERMAN (Index 5)
    {
        "--- Soundeinstellungen ---",
        "Aktueller Status: ",
        "AN",
        "AUS",
        "1. Ein/Aus umschalten\n0. Zurück\nAuswahl: ",
        "Sound eingeschaltet!",
        "Sound ausgeschaltet!"
    },

    // FRENCH (Index 6)
    {
        "--- Paramètres du son ---",
        "État actuel : ",
        "ACTIVÉ",
        "DÉSACTIVÉ",
        "1. Activer/Désactiver\n0. Retour\nChoix : ",
        "Son activé !",
        "Son désactivé !"
    },

    // RUSSIAN (Index 7)
    {
        "--- Настройки звука ---",
        "Текущее состояние: ",
        "ВКЛ",
        "ВЫКЛ",
        "1. Вкл/Выкл\n0. Назад\nВыбор: ",
        "Звук включён!",
        "Звук выключен!"
    },

    // UKRAINIAN (Index 8)
    {
        "--- Налаштування звуку ---",
        "Поточний стан: ",
        "УВІМК",
        "ВИМК",
        "1. Увімк/Вимк\n0. Назад\nВибір: ",
        "Звук увімкнено!",
        "Звук вимкнено!"
    },

    // KOREAN (Index 9)
    {
        "--- 사운드 설정 ---",
        "현재 상태: ",
        "켜짐",
        "꺼짐",
        "1. 켜기/끄기\n0. 뒤로\n선택: ",
        "소리가 켜졌습니다!",
        "소리가 꺼졌습니다!"
    },

    // ITALIAN (Index 10)
    {
        "--- Impostazioni audio ---",
        "Stato attuale: ",
        "ON",
        "OFF",
        "1. Attiva/Disattiva\n0. Indietro\nScelta: ",
        "Audio attivato!",
        "Audio disattivato!"
    },

    // POLISH (Index 11)
    {
        "--- Ustawienia dźwięku ---",
        "Aktualny stan: ",
        "WŁ",
        "WYŁ",
        "1. Włącz/Wyłącz\n0. Powrót\nWybór: ",
        "Dźwięk włączony!",
        "Dźwięk wyłączony!"
    },

    // ARABIC (Index 12)
    {
        "--- إعدادات الصوت ---",
        "الحالة الحالية: ",
        "تشغيل",
        "إيقاف",
        "1. تشغيل/إيقاف\n0. رجوع\nاختيار: ",
        "تم تشغيل الصوت!",
        "تم إيقاف الصوت!"
    },

    // VIETNAMESE (Index 13)
    {
        "--- Cài đặt âm thanh ---",
        "Trạng thái hiện tại: ",
        "BẬT",
        "TẮT",
        "1. Bật/Tắt\n0. Quay lại\nLựa chọn: ",
        "Âm thanh đã bật!",
        "Âm thanh đã tắt!"
    },

    // TAGALOG (Index 14)
    {
        "--- Setting ng tunog ---",
        "Kasalukuyang estado: ",
        "BUKAS",
        "SARADO",
        "1. On/Off\n0. Bumalik\nPili: ",
        "Naka-on ang tunog!",
        "Naka-off ang tunog!"
    },

    // GREEK (Index 15)
    {
        "--- Ρυθμίσεις ήχου ---",
        "Τρέχουσα κατάσταση: ",
        "ΕΝΕΡΓΟ",
        "ΑΝΕΝΕΡΓΟ",
        "1. Ενεργοποίηση/Απενεργοποίηση\n0. Πίσω\nΕπιλογή: ",
        "Ο ήχος ενεργοποιήθηκε!",
        "Ο ήχος απενεργοποιήθηκε!"
    },

    // HEBREW (Index 16)
    {
        "--- הגדרות קול ---",
        "מצב נוכחי: ",
        "פועל",
        "כבוי",
        "1. הפעלה/כיבוי\n0. חזרה\nבחירה: ",
        "הקול הופעל!",
        "הקול כובה!"
    },

    // PORTUGUESE (Index 17)
    {
        "--- Configurações de som ---",
        "Estado atual: ",
        "LIGADO",
        "DESLIGADO",
        "1. Ligar/Desligar\n0. Voltar\nEscolha: ",
        "Som ativado!",
        "Som desativado!"
    },

    // FARSI (Index 18)
    {
        "--- تنظیمات صدا ---",
        "وضعیت فعلی: ",
        "روشن",
        "خاموش",
        "1. روشن/خاموش\n0. بازگشت\nانتخاب: ",
        "صدا روشن شد!",
        "صدا خاموش شد!"
    },

    // SWEDISH (Index 19)
    {
        "--- Ljudinställningar ---",
        "Nuvarande status: ",
        "PÅ",
        "AV",
        "1. Slå på/av\n0. Tillbaka\nVal: ",
        "Ljudet är på!",
        "Ljudet är av!"
    },

    // DUTCH (Index 20)
    {
        "--- Geluidsinstellingen ---",
        "Huidige status: ",
        "AAN",
        "UIT",
        "1. Aan/Uit schakelen\n0. Terug\nKeuze: ",
        "Geluid ingeschakeld!",
        "Geluid uitgeschakeld!"
    },

    // TURKISH (Index 21)
    {
        "--- Ses ayarları ---",
        "Mevcut durum: ",
        "AÇIK",
        "KAPALI",
        "1. Aç/Kapat\n0. Geri\nSeçim: ",
        "Ses açıldı!",
        "Ses kapatıldı!"
    },

    // HINDI (Index 22)
    {
        "--- ध्वनि सेटिंग्स ---",
        "वर्तमान स्थिति: ",
        "चालू",
        "बंद",
        "1. चालू/बंद करें\n0. वापस\nचयन: ",
        "ध्वनि चालू की गई!",
        "ध्वनि बंद की गई!"
    },

    // LATIN (Index 23)
    {
        "--- Configurationes soni ---",
        "Status praesens: ",
        "ON",
        "OFF",
        "1. Accende/Extingue\n0. Redire\nElectio: ",
        "Sonus activatus est!",
        "Sonus deactivatus est!"
    }
};

const std::vector<MistakeExercise> mistakeExerciseTranslations {

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

const std::vector<SpellingOutAccents> spellingOutAccentsTranslations {

    // Hungarian (Index 0)
    {
        "--- Ékezetek kezelése ---",
        "Jelenlegi állapot: ",
        "Ki",
        "Be",
        "1. Átkapcsolás\n0. Vissza\nVálasztás: ",
        "",
        ""
    },

    // English (Index 1)
    {
        "--- Accent Handling ---",
        "Current state: ",
        "Off",
        "On",
        "1. Toggle\n0. Back\nChoice: ",
        "",
        ""
    },

    // Chinese (Index 2)
    {
        "--- 重音符号处理 ---",
        "当前状态：",
        "关",
        "开",
        "1. 切换\n0. 返回\n选择：",
        "",
        ""
    },

    // Japanese (Index 3)
    {
        "--- アクセント処理 ---",
        "現在の状態：",
        "オフ",
        "オン",
        "1. 切り替え\n0. 戻る\n選択：",
        "",
        ""
    },

    // Spanish (Index 4)
    {
        "--- Gestión de acentos ---",
        "Estado actual: ",
        "Desactivado",
        "Activado",
        "1. Cambiar\n0. Volver\nOpción: ",
        "",
        ""
    },

    // German (Index 5)
    {
        "--- Akzentverwaltung ---",
        "Aktueller Status: ",
        "Aus",
        "Ein",
        "1. Umschalten\n0. Zurück\nAuswahl: ",
        "",
        ""
    },

    // French (Index 6)
    {
        "--- Gestion des accents ---",
        "État actuel : ",
        "Désactivé",
        "Activé",
        "1. Basculer\n0. Retour\nChoix : ",
        "",
        ""
    },

    // Russian (Index 7)
    {
        "--- Обработка акцентов ---",
        "Текущее состояние: ",
        "Выкл",
        "Вкл",
        "1. Переключить\n0. Назад\nВыбор: ",
        "",
        ""
    },

    // Ukrainian (Index 8)
    {
        "--- Обробка акцентів ---",
        "Поточний стан: ",
        "Вимкнено",
        "Увімкнено",
        "1. Перемкнути\n0. Назад\nВибір: ",
        "",
        ""
    },

    // Korean (Index 9)
    {
        "--- 악센트 처리 ---",
        "현재 상태: ",
        "꺼짐",
        "켜짐",
        "1. 전환\n0. 뒤로\n선택: ",
        "",
        ""
    },

    // Italian (Index 10)
    {
        "--- Gestione accenti ---",
        "Stato attuale: ",
        "Disattivato",
        "Attivato",
        "1. Cambia\n0. Indietro\nScelta: ",
        "",
        ""
    },

    // Polish (Index 11)
    {
        "--- Obsługa akcentów ---",
        "Aktualny stan: ",
        "Wyłączone",
        "Włączone",
        "1. Przełącz\n0. Powrót\nWybór: ",
        "",
        ""
    },

    // Arabic (Index 12)
    {
        "--- معالجة اللكنة ---",
        "الحالة الحالية: ",
        "إيقاف",
        "تشغيل",
        "1. تبديل\n0. رجوع\nاختيار: ",
        "",
        ""
    },

    // Vietnamese (Index 13)
    {
        "--- Xử lý dấu ---",
        "Trạng thái hiện tại: ",
        "Tắt",
        "Bật",
        "1. Chuyển đổi\n0. Quay lại\nLựa chọn: ",
        "",
        ""
    },

    // Tagalog (Index 14)
    {
        "--- Pamamahala ng accent ---",
        "Kasalukuyang estado: ",
        "Patay",
        "Bukas",
        "1. Palitan\n0. Bumalik\nPiliin: ",
        "",
        ""
    },

    // Greek (Index 15)
    {
        "--- Διαχείριση τόνων ---",
        "Τρέχουσα κατάσταση: ",
        "Ανενεργό",
        "Ενεργό",
        "1. Εναλλαγή\n0. Πίσω\nΕπιλογή: ",
        "",
        ""
    },

    // Hebrew (Index 16)
    {
        "--- ניהול מבטאים ---",
        "מצב נוכחי: ",
        "כבוי",
        "פועל",
        "1. החלף\n0. חזור\nבחירה: ",
        "",
        ""
    },

    // Portuguese (Index 17)
    {
        "--- Gestão de acentos ---",
        "Estado atual: ",
        "Desligado",
        "Ligado",
        "1. Alternar\n0. Voltar\nEscolha: ",
        "",
        ""
    },

    // Persian (Index 18)
    {
        "--- مدیریت علائم ---",
        "وضعیت فعلی: ",
        "خاموش",
        "روشن",
        "1. تغییر\n0. بازگشت\nانتخاب: ",
        "",
        ""
    },

    // Swedish (Index 19)
    {
        "--- Accenthantering ---",
        "Nuvarande status: ",
        "Av",
        "På",
        "1. Växla\n0. Tillbaka\nVal: ",
        "",
        ""
    },

    // Dutch (Index 20)
    {
        "--- Accentbeheer ---",
        "Huidige status: ",
        "Uit",
        "Aan",
        "1. Wisselen\n0. Terug\nKeuze: ",
        "",
        ""
    },

    // Turkish (Index 21)
    {
        "--- Aksan yönetimi ---",
        "Mevcut durum: ",
        "Kapalı",
        "Açık",
        "1. Değiştir\n0. Geri\nSeçim: ",
        "",
        ""
    },

    // Hindi (Index 22)
    {
        "--- उच्चारण चिह्न प्रबंधन ---",
        "वर्तमान स्थिति: ",
        "बंद",
        "चालू",
        "1. बदलें\n0. वापस\nचयन: ",
        "",
        ""
    },

    // Latin (Index 23)
    {
        "--- Administratio accentuum ---",
        "Status praesens: ",
        "Off",
        "On",
        "1. Commuta\n0. Redi\nElectio: ",
        "",
        ""
    }
};

const std::vector<CreateVocabListsFileAndFolders> createVocabListsFileAndFoldersTranslations{

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

const std::vector<VocabFileCommands> vocabFileCommandTranslate{

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

const std::vector<CreateFolderStrings> createFolderTranslations{

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
const std::vector<OneRoundQString> oneRoundQuizStringTranslations {

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




//======Vectors end =========