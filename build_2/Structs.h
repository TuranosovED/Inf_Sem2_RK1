#pragma once
#include <stdbool.h>

typedef struct stats
{
    int CountOfFalseSign; //кол-во неправильно введеных символов
    int CountOfTrueSign; //кол-во правильно введеных символов
    double MiddleSpeedOfSign; //средняя скорость ввода символов
    double MiddleSpeedOfWords; //средняя скорость ввода слов
    int CountOfWords; //кол-во слов
}stats;

typedef struct MassiveMemoryNeed
{
    int Lines; //кол-во линий в файле
    int Columns; //кол-во столбцов(символов) в файле
}MassiveMemoryNeed;

typedef struct obj
{
    int IsTrue; // 0 - c ошибкой, 1 - без ошибки 2-подсветка (для cmd) (спорная идея, если передумаешь, удаляй в render 2 строчку printf и меняй на bool, в FileWorking удаляй определение)
    char Sign; // хранимый символ
}obj;