#include "Render.h"

void ListRender(obj **mas,MassiveMemoryNeed necessity,int ListCounter,HANDLE ConsoleHandle)
{
    static int ExitX =0; //координата X последенего выведенного символа
    static int ExitY = 0; //координата Y последенего выведенного символа
    int ShiftCouter= 0; // кол-во подряд идущих без \n
    int StrCounter = 0; //подсчет выведеных строчек, <= CountOfMaxLinesInList
    bool trigger = false; // условие досрочного выхода(при CountOfMaxLinesInList выведеных страницах)
    int counter; //счетчик для учета неполных строк
    system("cls");
    SetConsoleCursorPosition(ConsoleHandle,(COORD){0,0}); //курсор в 0,0
    for(int i = ExitY;(i<(necessity.Lines+1))&&(i<((ListCounter+1) * CountOfMaxLinesInList));i++) // Выводим ровно 10 строк, при этом непрывышаем их общее кол-во
    {
        if(i<necessity.Lines)
            counter = CountOfSignInLine;
        else
            counter = necessity.Columns;
        for(int j = ExitX;j<counter;j++)
        {
            if(mas[i][j].Sign != '\n')ShiftCouter++; //Увеличиваем счетчик отвечающий за кол-во символов идущих подряд без \n
            else
            {
                ShiftCouter = 0;
                StrCounter++; // счетчик отображающий кол-во выведеных строчек
            }
            putchar(mas[i][j].Sign);
            if(ShiftCouter == CountOfSignInLine) // Если Строка заполнена, то переходим на новую
            {
                ShiftCouter = 0;
                StrCounter++;
                putchar('\n');
            }
            if(StrCounter == CountOfMaxLinesInList) // Если выведено необ кол-во строк, то запоминаем корд послед символа из массива и выходим
            {
                trigger = !trigger;
                ExitY = i;
                ExitX = j+1;
                break;
            }
            
        }
        if(trigger)break;
        ExitX = 0; //чтобы цикл корректно работал при перелистывании(учитываем предыдущий сдвиг по x)
    }
    SetConsoleCursorPosition(ConsoleHandle,(COORD){0,0});//курсор в 0,0
}
void Render(obj mas,HANDLE ConsoleHandle,int ListCounter, int ShiftX , int ShiftY)
{
    SetConsoleCursorPosition(ConsoleHandle,(COORD){ShiftX,ShiftY}); // Переводим курсор на необ символ
    switch (mas.IsTrue)
    {
        case 1: //проверка символа, 1 - зеленый
            if(mas.Sign != ' ' && mas.Sign != '\n')
                printf("\033[32m%c\033[0m",mas.Sign);
            else if (mas.Sign == '\n') 
                printf("\033[0;42m \033[0m");
            else 
                printf("\033[0;42m%c\033[0m",mas.Sign); 
            break;
        case 2: //2 - подстветка для cmd
            if(mas.Sign != '\n' && mas.Sign != ' ') //подсветка \n
                printf("\033[0;44m%c\033[0m",mas.Sign); 
            else if(mas.Sign == ' ')
                printf("\033[0;44m_\033[0m",mas.Sign); // вывод _ в подствеке для того чтобы отличать \n и ' '
            else printf("\033[0;44m \033[0m");
            break;
        default: //проверка символа, 0 - красный
            if(mas.Sign != ' ' && mas.Sign != '\n')
                printf("\033[31m%c\033[0m",mas.Sign);
            else if (mas.Sign == '\n')
                printf("\033[0;41m \033[0m");
            else printf("\033[0;41m%c\033[0m",mas.Sign);
                break;
    }
    SetConsoleCursorPosition(ConsoleHandle,(COORD){ShiftX,ShiftY});
}
