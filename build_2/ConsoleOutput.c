#include "ConsoleOutput.h"

void PrintStats(stats statistic) //вывод статистики 
{
    puts("#############################");
    printf("CountOfFalseSign: %d \nCountOfTrueSign: %d \nCountOfAllSign: %d \nMiddleSpeedOfSign: %f\nMiddleSpeedOfWords: %f \n",statistic.CountOfFalseSign,statistic.CountOfTrueSign,statistic.CountOfFalseSign+statistic.CountOfTrueSign,statistic.MiddleSpeedOfSign,statistic.MiddleSpeedOfWords);
    puts("#############################");
}


void HelpMessage() // Вызов подсказки
{
    printf("\nUsage:\nmain.exe [complexity] [time] [number of mistakes]\ncomplexity: easy, medium, hard\ntime must be less than 300 seconds\nthe number of errors must be less than or equal to 20\n ");
}

void DefeatOrVictoryMessage(bool cheak) //Сообщение об окончании игры
{
    char win[] = "Congratulations! You won!";
    int color = 31;
    if(cheak)
    {
        for(int i =0;win[i] != '\0';i++)
        {
            printf("\033[%dm%c \033[0m",color,win[i]);
            color++;
            if(color > 37)color =31;
        }
        putchar('\n');
    }
    else puts("\033[31mD e f e a t ! T r y  a g a i n !\033[0m");
}