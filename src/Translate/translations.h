#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

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
    LATIN // Represents 23
};

// =======STRUCTS=========

struct MenuStrings {
    std::string titleAndSigns;
    std::string programExplanation;
    std::string startProgram;
    std::string mistakeExercise;
    std::string newFile;
    std::string settings;
    std::string exit;
    std::string signs;
};

struct ExplanationStrings {
    std::string description;
    std::string instruction1;
    std::string instruction2;
    std::string goodLuck;
};

struct ExitingStrings {
    std::string exiting;
};

struct NumberOutput {
    std::string numberOutput;
};

struct ListAndSelectedFile
{
    std::string currentlyFolder;
    std::string emptyFolder;
    std::string isDirectory;
    std::string commands;

};

struct RenameFilesAndFolders
{
    std::string toBeRenamed;
    std::string newName;
};
struct MovingFileFolders
{
    std::string toBeMoved;
    std::string newNameNewPath;

};
struct DeleteFileFolders
{
    std::string errorDfDangerousPath;
    std::string confirmationDelete;
    std::string successDelete;

};
struct CopyFileFolders
{
    std::string errorDangerousPath;
    std::string toBeCopied;
    std::string newNameNewPath;
    std::string errorDangerousGoalAndPath;
    std::string successCopying;
    std::string anErrorOccurred;
};
struct W_wordPair
{
    std::string ErrorOpenedFile;
};

struct InvalidInput {
    std::string invalidInput;
};

struct EnteringBack {
    std::string pressToEnter;
};
struct InvalidInput2 {
    std::string invalidInput2;
};
struct HaveNoWords {
    std::string haveNoWords;
};

struct ReTry {
    std::string reTry;
};
struct BadlyAnswer {
    std::string badlyAnswer;
};
struct GoodAnswer1 {
    std::string goodAnswer1;
};
struct GoodAnswer2 {
    std::string goodAnswer2;
};
struct PronunciationString {
    std::string pronunciation2str;
};
struct HaveFinished {
    std::string haveFinished;
};
struct ScoreSys {
    std::string total;
    std::string allQuestion;
    std::string correct;
    std::string badly;
    std::string percent;
};
struct PercentAge {
    std::string percentAge100;
    std::string percentAge80;
    std::string percentAgeElse;
};
struct QuizExplanation {
    std::string quizExplanation1;
    std::string quizExplanation2;
    std::string quizExplanation3;
};
struct VocabWordsPairTotal {
    std::string vocabWordsPairTotal;
    std::string vocabWordsPairTotal2;
    std::string vocabWordsPairTotal3;
};
struct CreateVocabFile
{
    std::string inputFileName;
    std::string folderName;
    std::string fullPathError;
    std::string fullPathOpenError;
    std::string fileSave;
    std::string fileSave2;
};
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
struct VocabMenu
{
    std::string vocabMenu1;
    std::string vocabMenu2;
    std::string vocabMenu3;
    std::string vocabError1;
    std::string vocabError2;
};
struct SettingsMenu
{
    std::string settingsMenuSign;
    std::string chooseSettingsMenu;
    std::string languageOptions;
    std::string targetLanguageOptions;
    std::string colorsOptions;
    std::string soundOptions;
    std::string accentsOptions;
    std::string backMainMenu;
    std::string settingsMenuSign2;
};
struct LanguageMenu
{
    std::string languageMenu1Sign;
    std::string exiting;
    std::string choiceStr;
    std::string languageMenu2Sign;
    std::string choiceSuccessProgramLanguage;
};

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
struct SaveSettings
{
    std::string saveSettingsError;
};
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

struct targetLanguageList
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

struct LlistAndSelectedFile
{
    std::string errorFile;
};

struct OosEditor
{
    std::string run;
    std::string errorWin32;
    std::string errorLinux;
};

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

struct SoundOnOff
{
    std::string soundSet;
    std:: string currentlyState;
    std::string useSoundOn;
    std::string useSoundOff;
    std::string option1;
    std::string useSoundOn2;
    std::string useSoundOff2;
};

struct MistakeExercise
{
    std::string practiceOfWrongWord;
    std::string word;
    std::string answer;
    std::string exerciseEnd;
};

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



//======STRUCTS END========

// Itt mondjuk meg a main-nek az "extern" kulcsszóval, hogy ezek a vektorok
// léteznek valahol máshol (a translations.cpp-ben), de itt hivatkozhat rájuk.

extern const std::vector<MenuStrings> mainMenuTranslations;
extern const std::vector<NumberOutput> chooseNumberMenuTranslations;
extern const std::vector<ExplanationStrings> explanationTranslations;
extern const std::vector<ExitingStrings> exitingTranslations;
extern const std::vector<ListAndSelectedFile> listAndSelectedFilesTranslations;
extern const std::vector<InvalidInput> invalidInputTranslations;
extern const std::vector<EnteringBack> continuationToEnterTranslations;
extern const std::vector<InvalidInput2> invalidInputTranslations2;
extern const std::vector<HaveNoWords> haveNoWordsTranslations;
extern const std::vector<ReTry> reTryTranslations;
extern const std::vector<BadlyAnswer> badlyAnswerTranslations;
extern const std::vector<GoodAnswer1> goodAnswer1Translations;
extern const std::vector<GoodAnswer2> goodAnswer2Translations;
extern const std::vector<PronunciationString> pronunciationStringTranslations;
extern const std::vector<HaveFinished> haveFinishedTranslations;
extern const std::vector<ScoreSys> totalTranslations;
extern const std::vector<PercentAge> percentAgeTranslations;
extern const std::vector<QuizExplanation> quizExplanationTranslations;
extern const std::vector<VocabWordsPairTotal> vocabWordsPairTotalTranslations;
extern const std::vector<CreateVocabFile> createVocabFileTranslations;
extern const std::vector<CreateVocab> createVocabTranslations;
extern const std::vector<VocabMenu> vocabMenuTranslations;
extern const std::vector<SettingsMenu> settingsMenuTranslations;
extern const std::vector<LanguageMenu> languageMenuTranslations;
extern const std::vector<ColorsOnset> colorsOSetTranslations;
extern const std::vector<SaveSettings> saveSettingsTranslations;
extern const std::vector<LearningLanguageSet> learningLanguageSetTranslations;
extern const std::vector<TargetLanguageNameSet> targetLanguageSetTranslations;
extern const std::vector<targetLanguageList> targetLanguageListTranslations;
extern const std::vector<RenameFilesAndFolders> renameFilesAndFoldersTranslations;
extern const std::vector<MovingFileFolders> movingFileFoldersTranslations;
extern const std::vector<DeleteFileFolders> deleteFileFoldersTranslations;
extern const std::vector<CopyFileFolders> copyFileFoldersTranslations;
extern const std::vector<W_wordPair> wordPairErrorTranslations;
extern const std::vector<LlistAndSelectedFile> LlistAndSelectedFileTranslations;
extern const std::vector<OosEditor> OosEditorTranslations;
extern const std::vector<BackgroundSets> backgroundSetsTranslations;
extern const std::vector<SoundOnOff> soundOnOffTranslations;
extern const std::vector<MistakeExercise> mistakeExerciseTranslations;
extern const std::vector<SpellingOutAccents> spellingOutAccentsTranslations;




// Nyelvi globális deklaráció érték
extern Language programUiLanguage; // A program nyelve || the Program language
extern Language motherLanguage; // Az anyanyelv enum értéke || The mother language
extern Language targetLanguage; // A tanult nyelv enum értéke || The target language
//===========================================
/**
 * @brief Global accent handling flag / Globális ékezetkezelési kapcsoló
 *
 * EN: Indicates whether accents are ignored or used.
 * HU: Meghatározza, hogy az ékezetek figyelmen kívül vannak-e hagyva vagy sem.
 */
// globális változó || global state
extern bool ignoreAccents; //Az ékezetek kezelésére || To handle accents

#endif
