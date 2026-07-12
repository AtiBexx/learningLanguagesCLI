#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include <map>
#include <string>
#include <vector>


//Enum list for supported Language
//Enum lista a támogatott nyelvekhez
enum class Language {
    HUNGARIAN , // Represents 0
    ENGLISH  ,   // Represents 1
    CHINESE, // Represents 2
    JAPANESE, // Represents 3
    SPANISH, // Represents 4
    GERMAN, // Represents 5
    FRENCH, // Represents 6
    RUSSIAN, // Represents 7
    UKRAINIAN, // Represents 8
    KOREAN, // Represents 9
    ITALIAN, // Represents 10
    POLISH, // Represents 11
    ARABIC, // Represents 12
    VIETNAMESE, // Represents 13
    TAGALOG, // Represents 14
    GREEK, // Represents 15
    HEBREW, // Represents 16
    PORTUGUESE, // Represents 17
    FARSI, // Represents 18
    SWEDISH, // Represents 19
    DUTCH, // Represents 20
    TURKISH, // Represents 21
    HINDI, // Represents 22
    LATIN ,// Represents 23
    COUNT // for counting || a számoláshoz
};

// =======STRUCTS=========

struct MenuStrings {
    std::string titleAndSigns;
    std::string programExplanation;
    std::string startProgram;
    std::string mistakeExercise;
    std::string newFile;
    std::string settings;
    std::string Editor;
    std::string exit;
    std::string signs;
};
//extern const std::vector<MenuStrings> mainMenuTranslations;

//====================================
struct ExplanationStrings {
    std::string description;
    std::string instruction1;
    std::string instruction2;
    std::string instruction3;
    std::string instruction4;
    std::string instruction5;
    std::string instruction6;
    std::string instruction7;
    std::string instruction8;
    std::string instruction9;
    std::string goodLuck;
};
//extern const std::vector<ExplanationStrings> explanationTranslations;

//========================================
struct ExitingStrings {
    std::string exiting;
};
//extern const std::vector<ExitingStrings> exitingTranslations;

//========================================
struct NumberOutput {
    std::string numberOutput;
};
//extern const std::vector<NumberOutput> chooseNumberMenuTranslations;

//========================================
struct ListAndSelectedFile
{
    std::string currentlyFolder;
    std::string emptyFolder;
    std::string isDirectory;
    std::string signs;
    std::string commands;
    std::string fullCommands;
    std::string fullCommands2;
    std::string choice;
};
//extern const std::vector<ListAndSelectedFile> listAndSelectedFilesTranslations;

//=====================================================
struct RenameFilesAndFolders
{
    std::string toBeRenamed;
    std::string newName;
    std::string errorDangerousPath;
};
//extern const std::vector<RenameFilesAndFolders> renameFilesAndFoldersTranslations;

//=====================================================
struct MovingFileFolders
{
    std::string toBeMoved;
    std::string newNameNewPath;
    std::string MFerrorDangerousPath;

};
//extern const std::vector<MovingFileFolders> movingFileFoldersTranslations;

//
//=====================================================
struct DeleteFileFolders
{
    std::string errorDfDangerousPath;
    std::string confirmationDelete;
    std::string successDelete;
    std::string interrupted;
    std::string errorDelete;

};
//extern const std::vector<DeleteFileFolders> deleteFileFoldersTranslations;

//
//=====================================================
struct CopyFileFolders
{
    std::string errorDangerousPath;
    std::string toBeCopied;
    std::string newNameNewPath;
    std::string example;
    std::string errorDangerousGoalAndPath;
    std::string successCopying;
    std::string anErrorOccurred;
};
//extern const std::vector<CopyFileFolders> copyFileFoldersTranslations;

//
//=====================================================
struct CreateFolderStrings
{
    std::string errorDangerousPath;
    std::string successCreate;
    std::string errorCreate;

};
//extern const std::vector<CreateFolderStrings> createFolderTranslations;

//
//=====================================================
struct W_wordPair
{
    std::string ErrorOpenedFile;
};
//extern const std::vector<W_wordPair> wordPairErrorTranslations;

//
//=====================================================
struct InvalidInput {
    std::string invalidInput;
};
//extern const std::vector<InvalidInput> invalidInputTranslations;

//
//=====================================================
struct EnteringBack {
    std::string pressToEnter;
};
//extern const std::vector<EnteringBack> continuationToEnterTranslations;

//
//=====================================================
struct InvalidInput2 {
    std::string invalidInput2;
};
//extern const std::vector<InvalidInput2> invalidInputTranslations2;

//
//=====================================================
struct HaveNoWords {
    std::string haveNoWords;
};
//extern const std::vector<HaveNoWords> haveNoWordsTranslations;

//
//=====================================================
struct ReTry {
    std::string reTry;
};
//extern const std::vector<ReTry> reTryTranslations;

//
//=====================================================
struct BadlyAnswer {
    std::string badlyAnswer;
};
//extern const std::vector<BadlyAnswer> badlyAnswerTranslations;

//
//=====================================================
struct GoodAnswer1 {
    std::string goodAnswer1;
};
//extern const std::vector<GoodAnswer1> goodAnswer1Translations;

//
//=====================================================
struct GoodAnswer2 {
    std::string goodAnswer2;
};
//extern const std::vector<GoodAnswer2> goodAnswer2Translations;

//
//=====================================================
struct PronunciationString {
    std::string pronunciation2str;
};
//extern const std::vector<PronunciationString> pronunciationStringTranslations;

//
//=====================================================
struct HaveFinished {
    std::string haveFinished;
};
//extern const std::vector<HaveFinished> haveFinishedTranslations;

//
//=====================================================
struct ScoreSys {
    std::string total;
    std::string allQuestion;
    std::string correct;
    std::string badly;
    std::string percent;
};
//extern const std::vector<ScoreSys> totalTranslations;

//
//=====================================================
struct PercentAge {
    std::string percentAge100;
    std::string percentAge80;
    std::string percentAgeElse;
};
//extern const std::vector<PercentAge> percentAgeTranslations;

//
//=====================================================
struct QuizExplanation {
    std::string quizExplanation1;
    std::string quizExplanation2;
    std::string quizExplanation3;
};
//extern const std::vector<QuizExplanation> quizExplanationTranslations;

//
//=====================================================
struct VocabWordsPairTotal {
    std::string vocabWordsPairTotal;
    std::string vocabWordsPairTotal2;
    std::string vocabWordsPairTotal3;
};
//extern const std::vector<VocabWordsPairTotal> vocabWordsPairTotalTranslations;

//
//=====================================================
struct CreateVocabFile
{
    std::string inputFileName;
    std::string folderName;
    std::string fullPathError;
    std::string fullPathOpenError;
    std::string fileSave;
    std::string fileSave2;
    std::string folderError;
    std::string folderDoesNotExist;
    std::string askingCreate;
    std::string folderOperationAborted;
};
//extern const std::vector<CreateVocabFile> createVocabFileTranslations;

//
//=====================================================
struct CreateVocab
{
    std::string createVocab;
    std::string createVocab2;
    std::string createVocab3;
    std::string createVocab4;
    std::string createVocab5;
    std::string createVocab6;
    std::string createVocab7;
};
//extern const std::vector<CreateVocab> createVocabTranslations;

//
//=====================================================
struct VocabMenu
{
    std::string vocabMenu1;
    std::string vocabMenu2;
    std::string vocabMenu3;
    std::string vocabMenu4;
    std::string vocabMenu5;
    std::string vocabMenuChoice;
    std::string vocabError1;
    std::string vocabError2;
};
//extern const std::vector<VocabMenu> vocabMenuTranslations;

//
//=====================================================
struct VocabFileCommands
{
    std::string commands1;
    std::string commands2;
    std::string commands3;
    std::string commands4;
};
//extern const std::vector<VocabFileCommands> vocabFileCommandTranslate;

//
//=====================================================
struct SettingsMenu
{
    std::string settingsMenuSign;
    std::string chooseSettingsMenu;
    std::string languageOptions;
    std::string targetLanguageOptions;
    std::string colorsOptions;
    std::string soundOptions;
    std::string accentsOptions;
    std::string oneRoundQuizOption;
    std::string preferIniTranslationsOption;
    std::string backMainMenu;
    std::string settingsMenuSign2;
};
//extern const std::vector<SettingsMenu> settingsMenuTranslations;

//
//=====================================================
struct LanguageMenu
{
    std::string languageMenu1Sign;
    std::string exiting;
    std::string choiceStr;
    std::string languageMenu2Sign;
    std::string choiceSuccessProgramLanguage;
};
//extern const std::vector<LanguageMenu> languageMenuTranslations;

//
//=====================================================
struct ColorsOnset
{
    std::string colorsPrinting1;
    std::string colorsPrinting2;
    std::string useCLR_ON;
    std::string useCLR_OFF;
    std::string colorsMenu1;
    std::string colorsMenu2;
    std::string colorsMenu3;
    std::string choice;
    std::string colorsOnOn;
    std::string colorsOffOff;
    std::string errorEntryDenied;
};
//extern const std::vector<ColorsOnset> colorsOSetTranslations;

//
//=====================================================
struct SaveSettings
{
    std::string saveSettingsError;
};
//extern const std::vector<SaveSettings> saveSettingsTranslations;

//
//=====================================================
struct LearningLanguageSet
{
    std::string Menu;
    std::string CurrentlyMotherLanguage;
    std::string CurrentlyLearningLanguage;
    std::string option1;
    std::string option2;
    std::string option3;
    std::string choice1;
    std::string allChoice;
    std::string motherSuccess;
    std::string choice2;
    std::string targetSuccess;
    std::string choice;
    std::string back;
    std::string error;
    std::string menuSigns;

};
//extern const std::vector<LearningLanguageSet> learningLanguageSetTranslations;

//
//=====================================================
struct TargetLanguageNameSet
{
    std::string English;
    std::string Magyar;
    std::string Chinese;
    std::string Japan;
    std::string Spanish;
    std::string German;
    std::string French;
    std::string Russian;
    std::string Ukrainian;
    std::string Korean;
    std::string Italian;
    std::string Polish;
    std::string Arabic;
    std::string Vietnamese;
    std::string Tagalog;
    std::string Greek;
    std::string Hebrew;
    std::string Portuguese;
    std::string Farsi;
    std::string Swedish;
    std::string Dutch;
    std::string Turkish;
    std::string Hindi;
    std::string Latin;
};
extern const std::vector<TargetLanguageNameSet> targetLanguageSetTranslations;

//
//=====================================================
struct TargetLanguageList
{
    std::string English;
    std::string Magyar;
    std::string Chinese;
    std::string Japan;
    std::string Spanish;
    std::string German;
    std::string French;
    std::string Russian;
    std::string Ukrainian;
    std::string Korean;
    std::string Italian;
    std::string Polish;
    std::string Arabic;
    std::string Vietnamese;
    std::string Tagalog;
    std::string Greek;
    std::string Hebrew;
    std::string Portuguese;
    std::string Farsi;
    std::string Swedish;
    std::string Dutch;
    std::string Turkish;
    std::string Hindi;
    std::string Latin;
};
extern const std::vector<TargetLanguageList> targetLanguageListTranslations;

//
//=====================================================
struct LlistAndSelectedFile
{
    std::string errorFile;
};
//extern const std::vector<LlistAndSelectedFile> LlistAndSelectedFileTranslations;

//
//=====================================================
struct OosEditor
{
    std::string run;
    std::string errorWin32;
    std::string errorLinux;
};
//extern const std::vector<OosEditor> OosEditorTranslations;

//
//=====================================================
struct BackgroundSets
{
    std::string sign;
    std::string DefaultBlack;
    std::string green;
    std::string cian;
    std::string red;
    std::string purple;
    std::string blue;
    std::string white;
    std::string gray;
    std::string stepBack;
    std::string backgroundColorsChange;
    std::string backGroundColor;
};
//extern const std::vector<BackgroundSets> backgroundSetsTranslations;

//
//=====================================================
struct SoundOnOff
{
    std::string soundSet;
    std:: string currentlyState;
    std::string useSoundOn;
    std::string useSoundOff;
    std::string option1;
    std::string option2;
    std::string option3;
    std::string useSoundOn2;
    std::string useSoundOff2;
};
//extern const std::vector<SoundOnOff> soundOnOffTranslations;

//
//=====================================================
struct MistakeExercise
{
    std::string practiceOfWrongWord;
    std::string word;
    std::string answer;
    std::string exerciseEnd;
};
//extern const std::vector<MistakeExercise> mistakeExerciseTranslations;

//
//=====================================================
struct SpellingOutAccents
{
    std::string accentsMenu;
    std::string accentsState;
    std:: string accentsState1Off;
    std::string accentsState2On;
    std::string accentsMenu1;
    std::string accentsMenu2;
    std::string accentsMenu3;
};
//extern const std::vector<SpellingOutAccents> spellingOutAccentsTranslations;

//
//=====================================================
struct CreateVocabListsFileAndFolders
{
    std::string currentlyFileandFolders;
    std::string folderName;
};
//extern const std::vector<CreateVocabListsFileAndFolders> createVocabListsFileAndFoldersTranslations;

//
//===================================================
struct OneRoundQString
{
    std::string mainSigns;
    std::string currentlyState;
    std::string stateON;
    std::string stateOff;
    std::string switching;
    std::string back;
    std::string choose;
    std::string OneRoundStateOn;
    std::string OneRoundStateOff;
};

struct IniStructToggle
{
    std::string mainSigns;
    std::string currentlyState;
    std::string stateON;
    std::string stateOff;
    std::string switchingMenu;
    std::string switchingMenu2;
    std::string switchingMenu3;
    std::string cStateON;
    std::string cStateOff;
};

// Itt mondjuk meg a main-nek az "extern" kulcsszóval, hogy ezek a vektorok
// léteznek valahol máshol (a translations.cpp-ben), de itt hivatkozhat rájuk.
// Here we tell main with the keyword "extern" that these vectors
// they exist somewhere else (in translations.cpp), but you can reference them here.
//extern const std::vector<OneRoundQString> oneRoundQuizStringTranslations;



//======STRUCTS END========

// Nyelvi globális deklaráció érték
extern Language programUiLanguage; // A program nyelve || enum value of the program language
extern Language motherLanguage; // Az anyanyelv enum értéke || enum value of the mother language
extern Language targetLanguage; // A tanult nyelv enum értéke || enum value of the target language
//===========================================

// globális változó || global state
extern bool ignoreAccents; //Az ékezetek kezelésére || To handle accents
extern bool oneRoundQuiz; // Ha true egy kör(for;;) ciklus false estén 2 kör || If true, one loop(for;;) loop, if false, 2 loops

//============================================
// -------- LANG.ini ----------
// Ide töltjük be a lang.ini tartalmát || load the contents of lang.ini here
extern std::map<std::string, std::string> loadedTranslations;

// Flag, ami jelzi, hogy a lang.ini-t használjuk-e || Flag indicating whether lang.ini is used
extern bool useLangIni;

// Megpróbálja betölteni a fordításokat a lang.ini fájlból
// Try to load the translations from the lang.ini file
bool loadTranslationsFromFile(Language lang);

// Létrehozza a lang.ini fájlt az alapértelmezett (hard-coded) fordításokkal
// Creates the lang.ini file with the default (hard-coded) translations
void createDefaultLangIni();

// Központi függvény a fordítások lekéréséhez (akár fájlból, akár hard-coded-ból)
// Central function for retrieving translations (either from a file or hard-coded)
// A lang paramétert kivesszük, mert a programUiLanguage globális.
// // We remove the lang parameter because programUiLanguage is global.
std::string getTranslation(const std::string& key);

#endif
