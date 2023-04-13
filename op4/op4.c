/*
Смолянинов Ярослав Евгеньевич, КИ21-17/2Б, вариант 18
Дано натуральное число n > 2. Программа вычисляет n-ое число Перрена.
*/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int RecPerrinNumber();

int main()
{
    srand(time(NULL));
    bool menu = true;
    int flag = 0, number = 0, count0 = 3, count1 = 0, count2 = 2, count3 = 0;
    while(menu)
    {
        puts("***Menu***");
        puts("*Write 1 to start the program and write your number");
        puts("*Write 2 to exit the program");
        printf("*Enter an item from the menu: ");
        scanf("%d", &flag);
        system("cls");
        switch(flag)
        {
            case 1: // Запуск программы
                printf("*Write your number: ");
                scanf("%d", &number);
                system("cls");
                if (number <= 2)
                {
                    puts("*Input error, try again.");
                    fflush(stdin);
                    break;
                }
                for (int i = 2; i < number; i++)
                {
                    count3 = RecPerrinNumber(number);
                }
                printf("*The number of the platform under the number %d is %d.\n", number, count3);
                fflush(stdin);
                break;
            case 2: // Завершение программы
                puts("*The program is completed.");
                menu = false;
                fflush(stdin);
                break;
            default: // Ошибочный ввод
                puts("*Input error, try again.");
                fflush(stdin);
				break;
        }
    }
}

int RecPerrinNumber(int num) // Рекурсивная функция
{
    if (num == 0)
    {
        return 3;
    }
    else if (num == 1)
    {
        return 0;
    }
    else if (num == 2)
    {
        return 2;
    }
    else
    {
        return (RecPerrinNumber(num - 2) + RecPerrinNumber(num - 3));
    }
}