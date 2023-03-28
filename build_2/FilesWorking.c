#include "FilesWorking.h"

char * TxtFormat(char **path,char* copy) //добавляю .txt
{
    int i;
    char template[] = ".txt";
    *path = (char *)malloc((strlen(copy)+4)*sizeof(char)); //выделяем память под название файла из argv

    for(i =0;copy[i]!='\0';i++) //переносим имя
    {
        (*path)[i] = copy[i];
    }

    for(int j =0;template[j]!='\0';j++) //добавляем .txt
    {
        (*path)[i] = template[j];
        i++;
    }
    (*path)[i] = '\0'; //заканчиваем строку
    return (*path);
}

MassiveMemoryNeed FileLen(char*FileName) //функция по подсчету кол-ва символов в файле, нужна для выделения дин масива
{
    MassiveMemoryNeed count;
    count.Columns = 0;
    count.Lines = 0;
    FILE *f = fopen(FileName,"r");
    while (fgetc(f) != EOF)
    {
        count.Columns++;
        if(count.Columns == CountOfSignInLine)
        {
            count.Lines++;
            count.Columns = 0;
        }
    }
    fclose(f);
    return count;
}

void InputFromFile(MassiveMemoryNeed necessity,obj **mas, char *path)
{
    int counter; //нужен для обработки последней строки, где символов меньше, чем в других
    FILE *f = fopen(path,"r");
    for(int i = 0;i<necessity.Lines+1;i++) //установка начальных значений
    {
        if(i<necessity.Lines)
            counter = CountOfSignInLine;
        else
            counter = necessity.Columns;
        for(int j = 0;j<counter;j++)
        {
            mas[i][j].Sign = fgetc(f);
            mas[i][j].IsTrue = 2; //подсветка для cmd (спорная вещь)
        }
    }
    fclose(f); //закрываем файл
}
