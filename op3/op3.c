/*
Смолянинов Ярослав Евгеньевич, КИ21-17/2Б, вариант 18
Необходимо проверить правильность расстановки скобок в математическом выражении
*/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

unsigned char* find_errors_input();
void find_errors_file(unsigned char* line);

int main(void)
{
    srand(time(NULL));
    unsigned char* plisting = NULL;
    bool menu = true;
    int flag, len, size = 0;
    char chr;
    FILE* file = fopen("test.txt", "r");
    if (file == NULL)
    file = fopen("test.txt", "w");
    fclose(file);
    while(menu)
    {
        puts("***Menu***");
        puts("*Write 1 to start the program and write your expression");
        puts("*Write 2 line to file");
        puts("*Write 3 to read line from file");
        puts("*Write 4 to exit the program");
        printf("*Enter an item from the menu: ");
		scanf("%d", &flag);
		system("cls");
        switch(flag)
        {
            case 1: // Ручной ввод данных пользователем
                plisting = find_errors_input();
                fflush(stdin);
                break;
            case 2: // Запись в файл
                plisting = find_errors_input();
                len = strlen(plisting);
                file = fopen("test.txt", "w");
                for (int i = 0; i < len; i++)
                {
                    fputc(plisting[i], file);
                }
                fclose(file);
                fflush(stdin);
                break;
            case 3: // Ввод данных из файла
                file = fopen("test.txt","r");
                fseek(file ,0, SEEK_END);
                long pos = ftell(file); // Возвращает текущее значение указателя положения в файле
                if (pos == 0) // Файл пустой
                {
                    puts("*The file is empty");
                    break;
                }
                fseek(file, 0, SEEK_SET); // Возвращает указатель в начало файла
                char string[100];
                puts("*Source string");
                if (NULL != fgets(string, 100, file)) // Считывание строки из файла
                {
                    printf("%s", string);
                }
                fclose(file);
                printf("\n");
                find_errors_file(string);
                fflush(stdin);
                break;
            case 4: // Завершение программы
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
    return 0;
}

void find_errors_file(unsigned char* line)
{
    char operations[5] = {'+', '-', '*', '/'};
    int len = strlen(line), countL = 0, countR = 0, point = 0, listingL[len], listingR[len];
    int* listingErrorL, *listingErrorR;
    for (int i = 0; i < len; i++) // Считаем кол-во скобочек
    {
        if (line[i] == '(')
        {
            listingL[countL] = i + 1;
            countL++;
        }
        else if (line[i] == ')')
        {
            listingR[countR] = i + 1;
            countR++;
        }
    }
    if (countR == countL) // Если нет ошибок
    {
        puts("*Errors not found.");
    }
    else if (countR != countL) // Есть лишние скобки
    {
        if (countL > countR) // Если больше левых скобок
        {
            puts("*False positions for left brackets:");
            if (listingL[countR] > listingR[countR - 1])
            {
                for (int i = (countL - countR); i <= countL; i++)
                {
                    printf("%d ", listingL[i - 1]);
                }
                printf("\n");
            }
            else
            {
                for (int j = 0; j < (countL - countR); j++)
                {
                    printf("%d ", listingL[j]);
                }
                printf("\n");
            }
        }
        else // Если больше правых скобок
            puts("*False positions for left brackets:");
            if (listingR[countL] > listingL[countL - 1])
            {
                for (int i = (countR - countL); i <= countR; i++)
                {
                    printf("%d ", listingR[i - 1]);
                }
                printf("\n");
            }
            else
            {
                for (int j = 0; j < (countR - countL); j++)
                {
                    printf("%d ", listingR[j]);
                }
                printf("\n");
            }
    }
}

unsigned char* find_errors_input()
{
    unsigned char line[1024];
    char operations[5] = {'+', '-', '*', '/', '\0'};
    puts("*Write your line:"); // Вводим выражение
    scanf("%s", &line);
    system("cls");
    int len = strlen(line), countL = 0, countR = 0, point = 0, listingL[len], listingR[len];
    int* listingErrorL, *listingErrorR;
    for (int i = 0; i < len; i++) // Считаем кол-во скобочек
    {
        if (line[i] == '(')
        {
            listingL[countL] = i + 1;
            countL++;
        }
        else if (line[i] == ')')
        {
            listingR[countR] = i + 1;
            countR++;
        }
    }
    if (countR == countL) // Если нет ошибок
    {
        puts("*Errors not found.");
    }
    else if (countR != countL) // Есть лишние скобки
    {
        if (countL > countR) // Если больше левых скобок
        {
            puts("*False positions for left brackets:");
            if (listingL[countR] > listingR[countR - 1])
            {
                for (int i = (countL - countR); i <= countL; i++)
                {
                    printf("%d ", listingL[i - 1]);
                }
                printf("\n");
            }
            else
            {
                for (int j = 0; j < (countL - countR); j++)
                {
                    printf("%d ", listingL[j]);
                }
                printf("\n");
            }
        }
        else // Если больше правых скобок
        {
            puts("*False positions for right brackets:");
            if (listingR[countL - 1] > listingL[countL - 1])
            {
                for (int i = ((countR - countL) + 1); i <= countR; i++)
                {
                    printf("%d ", listingR[i - 1]);
                }
                printf("\n");
            }
            else
            {
                for (int j = 0; j < (countR - countL); j++)
                {
                    printf("%d ", listingR[j]);
                }
                printf("\n");
            }
        }
    }
    unsigned char* result = malloc((strlen(line) + 1) * sizeof(unsigned char));
    strcpy(result, line);
    return result;
}
