#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include <string>
#include <vector>

//Enum list for supported Language
//Enum lista a támogatott nyelvekhez
enum class Language {
    HUNGARIAN , // Represents 0
    ENGLISH  ,   // Represents 1
    CHINESE,
    JAPANESE,
    SPANISH,
    GERMAN,
    FRENCH,
    RUSSIAN,
    UKRAINIAN,
    KOREAN,
    ITALIAN,
    POLISH,
    ARABIC,
    VIETNAMESE,
    TAGALOG,
    GREEK,
    HEBREW,
    PORTUGUESE,
    FARSI,
    SWEDISH,
    DUTCH,
    TURKISH,
    HINDI,
    LATIN
};

// =======STRUCTS=========

struct MenuStrings {
    std::string title;
    std::string programExplanation;
    std::string startProgram;
    std::string mistakeExecise;
    std::string newFile;
    std::string settings;
    std::string exit;
    std::string signs;
};

struct ExplanationStrings {
    std::string description;
    std::string instruction1;
    std::string instruction2;
    std::string goodluck;
};

struct ExitingStrings {
    std::string exiting;
};

struct NumberOutput {
    std::string numberOutput;
};

struct BackStrings {
    std::string backStrings;
};

struct InvalidInput {
    std::string invalidInput;
};

struct EnteringBack {
    std::string enteringBack;
};
struct InvalidInput2 {
    std::string invalidInput2;
};
struct HaveNoWords {
    std::string haveNoWords;
};
struct Question1 {
    std::string question1;
};
struct Question2 {
    std::string question2;
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
    std::string settingsMenuError1;
    std::string settingsMenuError2;
    std::string settingsMenu1;
    std::string settingsMenu2;
    std::string settingsMenu3;
    std::string settingsMenu4;
    std::string settingsMenu5;
    std::string settingsMenu6;
    std::string settingsMenu7;
    std::string settingsMenu8;
};
struct LanguageMenu
{
    std::string languageMenu1Sign;
    std::string option1;
    std::string option2;
    std::string exiting;
    std::string choiceStr;
    std::string languageMenu2Sign;
};
struct LanguageMenu2
{
    std::string Error1;
    std::string Error2;
    std::string choiceSucess1;
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
    std::string colorsONON;
    std::string colorsOFFOFF;
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
    std::string option4;
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

struct TargetlanguageList
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



//======STRUCTS END========

// Itt mondjuk meg a main-nek az "extern" kulcsszóval, hogy ezek a vektorok
// léteznek valahol máshol (a translations.cpp-ben), de itt hivatkozhat rájuk.

extern const std::vector<MenuStrings> menuTranslations;
extern const std::vector<NumberOutput> numberOutputTranslations;
extern const std::vector<ExplanationStrings> explanationTranslations;
extern const std::vector<ExitingStrings> exitingTranslations;
extern const std::vector<BackStrings> backbackTranslations;
extern const std::vector<InvalidInput> invalidInputTranslations;
extern const std::vector<EnteringBack> enteringBackTranslations;
extern const std::vector<InvalidInput2> invalidInputTranslations2;
extern const std::vector<HaveNoWords> haveNoWordsTranslations;
extern const std::vector<Question1> question1Translations;
extern const std::vector<Question2> question2Translations;
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
extern const std::vector<LanguageMenu2> languageMenu2Translations;
extern const std::vector<ColorsOnset> colorsOSetTranslations;
extern const std::vector<SaveSettings> saveSettingsTranslations;
extern const std::vector<LearningLanguageSet> learningLanguageSetTranslations;
extern const std::vector<TargetLanguageNameSet> targetLanguageSetTranslations;
extern const std::vector<TargetlanguageList> targetlanguagelistsTranslations;



// Nyelvi globális deklaráció érték
extern Language currentLanguage; // A program nyelve
extern Language motherLanguage; // Az anyanyelv enum értéke
extern Language targetLanguage; // A tanult nyelv enum értéke

#endif
