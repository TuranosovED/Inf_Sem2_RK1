#include "FilesWorking.h"
#include "ConsoleOutput.h"
#include "Memory.h"
#include "Defines.h"
#include "Render.h"
#include "ConsoleInput.h"
#include "GameProcess.h"

int main(int arhc , char*argv[])
{
    system("cls");  

    HANDLE ConsoleOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE); //Дескриптор стнадартного вывода 

    SetConsoleCursorInfo(ConsoleOutputHandle,&(CONSOLE_CURSOR_INFO){100,0}); //делает каретку невидмой, если работу принимают в cmd раскоментить

    int ListCounter = 0; //счетчик выведеных страниц

    stats statistic = {0,0,0,0,0}; //структура статистики

    if(!CheakForInputMistakes(argv)) //Проверка на ввод данных
    {
        HelpMessage(); //вызов подсказки
        return 0;
    }

    char *path; //путь до .txt

    TxtFormat(&path,argv[1]); //подгоняем путь hard + .txt

    int DeadTime = atoi(argv[2]); //ограничение по времени
    int MaxMistakes = atoi(argv[3]);//кол-во допустимых ошибок при вводе символов пользователем
    
    MassiveMemoryNeed necessity = FileLen(path); //подсчет символо, нужно для выделения памяти

    obj **mas; //текст из файла

    AllocateMemory(necessity,&mas); //функция по выделению памяти под массив, содержащий символы из файла

    int counter; //нужен для обработки последней строки, где символов меньше, чем в других

    InputFromFile(necessity,mas,path); //заполнение массива символами из файла

    ListRender(mas,necessity,ListCounter,ConsoleOutputHandle); //функция для отрисовки страниц (1 страница, далее все в Typing)
    
    Typing(necessity,mas,&statistic,ConsoleOutputHandle,ListCounter,MaxMistakes,DeadTime); //игровой процесс
    
    PrintStats(statistic); //вывод статистики

    system("pause"); // Просмотр статистики
    
    CloseHandle(ConsoleOutputHandle); // Делаю дескриптор недействительным

    return 0;
}

