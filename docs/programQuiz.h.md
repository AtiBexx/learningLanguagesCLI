```c++
//
// Created by AtiBexx2 on 2026. 03. 24.
//

#ifndef ENGLISH_PROGRAMQUIZ_H
#define ENGLISH_PROGRAMQUIZ_H
#include "../FileIO/dataFileReading.h"

//Quiz kérdezős logika
void startQuiz (const std::vector<WordPair>& words);
void scoreSystem(int correct,int badly, unsigned long long total);
void mistakeExercise();

#endif //ENGLISH_PROGRAMQUIZ_H
```