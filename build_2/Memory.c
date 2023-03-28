#include "Memory.h"

void AllocateMemory(MassiveMemoryNeed need, obj***OriginalMas) //выделяем память под символы из файла, так как используем 2-ный массив, то указатель соотв 3 кратности
{
    obj **mas = (obj**)malloc(sizeof(obj*) * (need.Lines+1));   //выделяем память под строки
    for(int i =0;i<need.Lines;i++) //выделяем n кол-во строк по 50 символов, всего у нас n+1 строк, но n+1 содержит <= 50 символов
    {
        mas[i] = (obj*)malloc(sizeof(obj) * (CountOfSignInLine));
    }
    mas[need.Lines] = (obj*)malloc(sizeof(obj) * need.Columns); //память под n+1 строку
    *OriginalMas = mas;  //"возвращаем" массив
}
