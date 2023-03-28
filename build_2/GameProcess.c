#include "GameProcess.h"

void Typing(MassiveMemoryNeed necessity,obj**mas,stats *statistic,HANDLE ConsoleOutputHandle,int ListCounter,int MaxMistakes,int DeadTime)
{
    bool NeedRender = true;
    bool VictoryCheak = true;;
    int counter; //счетчик для учета неполных строк
    double StartTime = clock(); //начальное и конечное время соответственно, для подсчета пройденного времени
    double EndTime = 0;
    int CurrentChar; //выбраный символ в aski, так как использую getch

    int ShiftX = 0; //сдвиг курсора по X, нужен для учета отступов текста (сдвиг каретки)
    int ShiftY=0; //сдвиг курсора по Y, нужен для учета отступов текста

    bool EnterTrigger = false;

    for(int i =0;i<(necessity.Lines + 1);i++) //проверка ввода символа, игровой процесс)
    {
        if(i<necessity.Lines) // Учитываем неполные строки, то есть если есть 4 строки, 3 - 50 символов, 4 < 50 символов, то для корректной работы, присваиваем разные пределы counter(для неполной строки, счетчик будет меньше чем кол-во слов там(для индексов))
            counter = CountOfSignInLine; 
        else
            counter = necessity.Columns;

        for(int j = 0;j<counter;) 
        {
            if(NeedRender) //проверяем необ рендера, учитываем что это цикл и выводить постояно не надо
            {
                Render(mas[i][j],ConsoleOutputHandle,ListCounter,ShiftX, ShiftY);  // подсветка для cmd
                NeedRender = false;
            }
            if(kbhit()) //проверяем нажал ли клавишу пользователь, необходимо для подсчета времени
            {
                if(((CurrentChar = getch()) == (int)mas[i][j].Sign) || (CurrentChar == 13 && (int)mas[i][j].Sign == '\n')) //проверяем ту ли клавишу нажал пользователь, 13 - enter
                {
                    statistic->CountOfTrueSign++; //подсчет кол-ва правильно введеных символов
                    mas[i][j].IsTrue = true; //отмечаем правльность ответа
                }
                else
                {
                    statistic->CountOfFalseSign++;
                    mas[i][j].IsTrue = false; //отмечаем ошибку
                    if(statistic->CountOfFalseSign > MaxMistakes) // Конец игры из-за ошибок
                    {
                        VictoryCheak = false; //Необ для вывода сообщения о поражении
                        break;
                    }
                }

                if(mas[i][j].Sign == '\n')//подсчет кол-ва введеных слов
                {
                    EnterTrigger = true;
                    if(EnterTrigger)
                        statistic->CountOfWords++; //подсчет кол-ва слов
                }
                else if (mas[i][j].Sign == ' ' && (!EnterTrigger))statistic->CountOfWords++;
                else EnterTrigger = false;

                Render(mas[i][j],ConsoleOutputHandle,ListCounter,ShiftX, ShiftY); 

                if(mas[i][j].Sign == '\n') //прибавляем сдвиг по Y для каретки
                {
                    ShiftY++;
                    ShiftX = 0;
                }
                else ShiftX++; //сдвиг по X
                if(ShiftX == CountOfSignInLine) //прибавляем сдвиг по Y для каретки
                {
                    ShiftX=0;
                    ShiftY++;
                }
                
                if(ShiftY==CountOfMaxLinesInList) //проверяем закончилась ли страница
                {
                    ListCounter++;
                    ShiftY = 0;
                    ShiftX = 0;
                    ListRender(mas,necessity,ListCounter,ConsoleOutputHandle); //рендер след страницы
                }


                NeedRender = true; //необ для отрисовки курсора в cmd
                j++; //увеличиваем счетчик
            }
            else 
            {
                if(((EndTime - StartTime)/CLK_TCK) > DeadTime) //проверяем истекло ли время
                {
                    VictoryCheak = false;
                    break;
                }
                EndTime = clock();
            }
        }
        if(!VictoryCheak) //поражение
            break;
    }

    statistic->CountOfWords++; //надо учесть последнее слово

    statistic->MiddleSpeedOfSign = (statistic->CountOfFalseSign + statistic->CountOfTrueSign)/( (EndTime - StartTime)/CLK_TCK ); //подсчет средних скоростей ввода символов и слов соответственно
    statistic->MiddleSpeedOfWords = statistic->CountOfWords/( (EndTime - StartTime)/CLK_TCK );
    system("cls");
    DefeatOrVictoryMessage(VictoryCheak); //вызов уведомления об окончании или поражении
}
