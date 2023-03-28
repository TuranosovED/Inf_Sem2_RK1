#include "ConsoleInput.h"

bool CheakForInputMistakes(char **input) //сверяю правильность ввода ключей 
{
    bool cheak; //тригер
    char templates[4][10] = {"easy", "medium", "hard","help"}; //массив шаблонов комманд, так удобнее сверять

    if(input[1] == NULL) //ошибка при пустом вводе
    {   
        puts("ERROR! : PLEASE ENTER INPUT DATA");
        return 0;
    }
    for(int i =0;i<4;i++) //проверяю текстовый ключ 1
    {
        cheak = false;
        for(int j =0;templates[i][j] != '\0';j++)  //сравниваю шаблоны с argv[1] (сложность)
        {
            if(templates[i][j] == input[1][j])
                cheak = true;
            else
            {
                cheak = false;
                break;
            }
        }
        if(cheak)
        {
            if(i == 3) return 0; //чтобы учесть help
            break;
        }
    }

    if(!cheak) //Ошибка при неверно введеной сложности
    {
        puts("ERROR! : PLEASE ENTER COMPLEXITY CORRRCTLY");
        return 0;
    }
   
    for(int i =2;i<4;i++) //проверяю числовые ключи 2 и 3
    {
        if(input[i] == NULL) //Time
        {
            if(i == 2)puts("ERROR! : PLEASE ENTER TIME");
            else if(i == 3) puts("ERROR! : PLEASE ENTER NUMBER OF MISTAKES");
            return 0;
        } 
            
        for(int j=0;input[i][j]!='\0';j++) //Mistakes
        {
            if(!isdigit(input[i][j]))
            {
                if(i == 2)puts("ERROR! : TIME MUST BE POSITIVE NUMBER");
                else if(i == 3) puts("ERROR! : NUMBER OF MISTAKES MUST BE POSITIVE NUMBER");
                return 0;
            }
        }
    }
    

    if(atoi(input[2])>300 || (atoi(input[2]) == 0)) //Проверяем интервалы (мб на define)
    {
        puts("ERROR! : TIME MUST BE GREATER THAN ZERO AND LESS THAN OR EQUAL TO 300 SECONDS");
        return 0;
    }
    if(atoi(input[3])>20)
    {
        puts("ERROR! : NUMBER OF MISTAKES MUST BE LESS THAN OR EQUAL TO 20");
        return 0;
    }
    return 1;
}