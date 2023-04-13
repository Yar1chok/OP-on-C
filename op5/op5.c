/*
Смолянинов Ярослав Евгеньевич, КИ21-17/2Б, вариант 18
Реализация хранения информации о батарейках.
*/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{
    char *model;
    char *standardSize;
    int cost;
    int voltage;
    char *type;
    float price;
} battery;

enum Choice{model = 1, standartSize, cost, voltage, type, price};

void check_input(int* count, battery** allChange) // Функция проверки ввода данных для добавления записей
{
    char line[50];
    bool flag = true;
    int len_counter = 0;
    battery charge;
    charge.model = malloc(50 * sizeof *charge.model);
    charge.standardSize = malloc(50 * sizeof *charge.standardSize);
    charge.type = malloc(50 * sizeof *charge.type);
    *allChange = realloc(*allChange, ((*count + 1) * sizeof(battery)));
    printf("*Write a name of your battery: ");
    gets(line);
    fflush(stdin);
    system("cls");
    while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод имени батарейки
    {
        for (int i = 0; i < strlen(line); i++)
        {
            if (isalpha(line[i]))
            {
                len_counter++;
            }
        }
        if (len_counter == strlen(line))
        {
            strcpy(charge.model, line);
        }
        else
        {
            len_counter = 0;
            printf("*Write error. Write a name of your battery: ");
            memset (line, 0, sizeof(line));
            gets(line);
            fflush(stdin);
            system("cls");
        }
    }
    memset (line, 0, sizeof(line));
    printf("*Write a standart size of your battery: ");
    gets(line);
    fflush(stdin);
    system("cls");
    while(flag) // Проверка на ввод типоразмера батарейки
    {
        if ((line[0] == 'C') || (line[0] == 'D'))
        {
            strcpy(charge.standardSize, line);
            memset (line, 0, sizeof(line));
            flag = false;
        }
        else if ((line[0] == 'A') && (line[1] == 'A'))
        {
            strcpy(charge.standardSize, line);
            memset (line, 0, sizeof(line));
            flag = false;
        }
        else if ((line[0] == 'A') && (line[1] == 'A') && (line[2] == 'A'))
        {
            strcpy(charge.standardSize, line);
            memset (line, 0, sizeof(line));
            flag = false;
        }
        else
        {
            printf("*Write error. Write a standart size of your battery: ");
            memset (line, 0, sizeof(line));
            gets(line);
            fflush(stdin);
            system("cls");
        }
    }
    len_counter = 0;
    printf("*Write a cost of your battery: ");
    gets(line);
    fflush(stdin);
    system("cls");
    while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод стоимости батарейки
    {
        for (int i = 0; i < strlen(line); i++)
        {
            if (isdigit(line[i]))
            {
                len_counter++;
            }
        }
        if (len_counter == strlen(line))
        {
            charge.cost = atoi (line);
        }
        else
        {
            len_counter = 0;
            printf("*Write error. Write a cost of your battery: ");
            memset (line, 0, sizeof(line));
            gets(line);
            fflush(stdin);
            system("cls");
        }
    }
    len_counter = 0;
    memset (line, 0, sizeof(line));
    printf("*Write a voltage of your battery: ");
    gets(line);
    fflush(stdin);
    system("cls");
    while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод вольтажа батарейки
    {
        for (int j = 0; j < strlen(line); j++)
        {
            if (isdigit(line[j]))
            {
                len_counter++;
            }
        }
        if (len_counter == strlen(line))
        {
            charge.voltage = atoi (line);
        }
        else
        {
            len_counter = 0;
            printf("*Write error. Write a voltage of your battery: ");
            memset (line, 0, sizeof(line));
            gets(line);
            fflush(stdin);
            system("cls");
        }
    }
    len_counter = 0;
    memset (line, 0, sizeof(line));
    printf("*Write a type of your battery (salt, alkaline, mercury, silver, etc): ");
    gets(line);
    fflush(stdin);
    system("cls");
    while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод типа батарейки
    {
        for (int i = 0; i < strlen(line); i++)
        {
            if (isalpha(line[i]))
            {
                len_counter++;
            }
        }
        if (len_counter == strlen(line))
        {
            strcpy(charge.type, line);
        }
        else
        {
            len_counter = 0;
            printf("*Write error. *Write a type of your battery (salt, alkaline, mercury, silver, etc): ");
            memset (line, 0, sizeof(line));
            gets(line);
            fflush(stdin);
            system("cls");
        }
    }
    len_counter = 0;
    memset (line, 0, sizeof(line));
    charge.price = ((float)charge.cost / (float)charge.voltage);
    (*allChange)[*count] = charge;
    (*count)++;
}

void show_notes(int count, battery* allChange) // Функция вывода записей на экран
{
    if (count == 0) // Если отсутствуют записи
    {
        puts("*The are no notes.");
    }
    else // Вывод записей на экран
    {
        for (int i = 0; i < count; i++)
        {
        printf("***\n");
        printf("*Number of battery %d\n", i + 1);
        printf("*Model: %s\n", allChange[i].model);
        printf("*Standartsize: %s\n", allChange[i].standardSize);
        printf("*Cost: %d Rub\n", allChange[i].cost);
        printf("*Voltage: %dB\n", allChange[i].voltage);
        printf("*Type: %s\n", allChange[i].type);
        printf("*Price: %2.2f B/Rub\n", allChange[i].price);
        printf("***\n");
        }
    }
}

battery* delete_notes(int count, battery* allCgange) // Функция удаления записи
{
    int point = 0;
    for (int i = 0; i < count; i++) // Вывод данных
    {
        printf("***\n");
        printf("*Number of battery %d\n", i + 1);
        printf("*Model: %s\n", allCgange[i].model);
        printf("*Standartsize: %s\n", allCgange[i].standardSize);
        printf("*Cost: %d Rub\n", allCgange[i].cost);
        printf("*Voltage: %dB\n", allCgange[i].voltage);
        printf("*Type: %s\n", allCgange[i].type);
        printf("*Price: %2.2f B/Rub\n", allCgange[i].price);
        printf("***\n");
    }
    printf("*Write the entry number: ");
    scanf("%d", &point);
    fflush(stdin);
    system("cls");
    while (point <= 0 || point > count) // Проверка на номер удаления записи
    {
        puts("*Input error. Write the entry number: ");
        scanf("%d", &point);
        fflush(stdin);
        system("cls");
    }
    point--;
    count--;
    battery* new_change = malloc((count) * sizeof(battery));
    if (point == 0) // Если отсутствуют записи
    {
        puts("*Note deleted.");
        return new_change;
    }
    else // Удаление записи
    {
        int j = 0;
        for (int i = 0; i < count; i++)
        {
            if (point == i)
            {
                free(allCgange[i].model);
                free(allCgange[i].standardSize);
                free(allCgange[i].type);
                continue;
            }
            new_change[j] = allCgange[i];
            j++;
        }
        puts("*Notes deleted.");
        return new_change;
    }
}

void add_file(int counter, FILE* file, battery* allChange) // Функция добавления записи в файл
{
    file = fopen("test.txt", "w");
    for (int i = 0; i < counter; i++)
    {
        char string[256];
        sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.", allChange[i].model,
        allChange[i].standardSize, allChange[i].cost, allChange[i].voltage, allChange[i].type, allChange[i].price);
        fputs(string, file);
        fputc('\n', file);
    }
    fclose(file);
}

void filtration_notes(int count, battery* allChange) // Функция выводит записи по заданному фильтру
{
    int point = 0, not_point = 0;
    if (count == 0)
    {
        puts("*The are no notes.");
    }
    else
    {
        puts("*Select a number filtering");
        puts("*1 - Model\n*2 - StandartSize\n*3 - Cost\n*4 - Voltage\n*5 - Type\n*6 - Price");
        printf("*Your select: ");
        scanf("%d", &point);
        while (point < 1 || point > 7)
        {
            puts("Write error. Try again.");
            printf("*Your select: ");
            scanf("%d", &point);
            fflush(stdin);
            system("cls");
        }
        fflush(stdin);
        system("cls");
        char line[50], line_filter[50];
        int filter = 0;
        int len_counter = 0;
        bool flag = true;
        switch (point)
        {
        case model:
            printf("*Write a value for filtering: ");
            gets(line);
            fflush(stdin);
            system("cls");
            while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод имени батарейки
            {
                for (int i = 0; i < strlen(line); i++)
                {
                    if (isalpha(line[i]))
                    {
                        len_counter++;
                    }
                }
                if (len_counter == strlen(line))
                {
                    strcpy(line_filter, line);
                }
                else
                {
                    len_counter = 0;
                    printf("*Write error. Write a value for filtering: ");
                    memset (line, 0, sizeof(line));
                    gets(line);
                    fflush(stdin);
                    system("cls");
                }
            }
            memset (line, 0, sizeof(line));
            for (int i = 0; i < count; i++)
            {
                if (strcmp(allChange[i].model, line_filter) == 0)
                {
                    char string[128];
                    sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", allChange[i].model,
                    allChange[i].standardSize, allChange[i].cost, allChange[i].voltage, allChange[i].type, allChange[i].price);
                    not_point++;
                    printf("*Number of battery: %d\n%s", i + 1, string);
                }
            }
            break;
        case standartSize:
            printf("*Write a standart size of your battery: ");
            gets(line);
            fflush(stdin);
            system("cls");
            while(flag) // Проверка на ввод типоразмера батарейки
            {
                if ((line[0] == 'C') || (line[0] == 'D'))
                {
                    strcpy(line_filter, line);
                    flag = false;
                }
                else if ((line[0] == 'A') && (line[1] == 'A'))
                {
                    strcpy(line_filter, line);
                    flag = false;
                }
                else if ((line[0] == 'A') && (line[1] == 'A') && (line[2] == 'A'))
                {
                    strcpy(line_filter, line);
                    flag = false;
                }
                else
                {
                    printf("*Write error. Write a standart size of your battery: ");
                    memset (line, 0, sizeof(line));
                    gets(line);
                    fflush(stdin);
                    system("cls");
                }
            }
            for (int i = 0; i < count; i++)
            {
                if (strcmp(allChange[i].standardSize, line_filter) == 0)
                {
                    char string[128];
                    sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", allChange[i].model,
                    allChange[i].standardSize, allChange[i].cost, allChange[i].voltage, allChange[i].type, allChange[i].price);
                    not_point++;
                    printf("*Number of battery: %d\n%s", i + 1, string);
                }
            }
            break;
        case cost:
            printf("*Write a cost of your battery: ");
            gets(line);
            fflush(stdin);
            system("cls");
            while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод стоимости батарейки
            {
                for (int i = 0; i < strlen(line); i++)
                {
                    if (isdigit(line[i]))
                    {
                        len_counter++;
                    }
                }
                if (len_counter == strlen(line))
                {
                    filter = atoi (line);
                }
                else
                {
                    len_counter = 0;
                    printf("*Write error. Write a cost of your battery: ");
                    memset (line, 0, sizeof(line));
                    gets(line);
                    fflush(stdin);
                    system("cls");
                }
            }
            for (int i = 0; i < count; i++)
            {
                if (allChange[i].cost == filter)
                {
                    char string[128];
                    sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", allChange[i].model,
                    allChange[i].standardSize, allChange[i].cost, allChange[i].voltage, allChange[i].type, allChange[i].price);
                    not_point++;
                    printf("*Number of battery: %d\n%s", i + 1, string);
                }
            }
            break;
        case voltage:
            printf("*Write a voltage of your battery: ");
            gets(line);
            fflush(stdin);
            system("cls");
            while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод вольтажа батарейки
            {
                for (int j = 0; j < strlen(line); j++)
                {
                    if (isdigit(line[j]))
                    {
                        len_counter++;
                    }
                }
                if (len_counter == strlen(line))
                {
                    filter = atoi (line);
                }
                else
                {
                    len_counter = 0;
                    printf("*Write error. Write a voltage of your battery: ");
                    memset (line, 0, sizeof(line));
                    gets(line);
                    fflush(stdin);
                    system("cls");
                }
            }
            for (int i = 0; i < count; i++)
            {
                if (allChange[i].voltage == filter)
                {
                    char string[128];
                    sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", allChange[i].model,
                    allChange[i].standardSize, allChange[i].cost, allChange[i].voltage, allChange[i].type, allChange[i].price);
                    not_point++;
                    printf("*Number of battery: %d\n%s", i + 1, string);
                }
            }
            break;
        case type:
            while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод типа батарейки
            {
                for (int i = 0; i < strlen(line); i++)
                {
                    if (isalpha(line[i]))
                    {
                        len_counter++;
                    }
                }
                if (len_counter == strlen(line))
                {
                    strcpy(line_filter, line);
                }
                else
                {
                    len_counter = 0;
                    printf("*Write error. *Write a type of your battery (salt, alkaline, mercury, silver, etc): ");
                    memset (line, 0, sizeof(line));
                    gets(line);
                    fflush(stdin);
                    system("cls");
                }
            }
            for (int i = 0; i < count; i++)
            {
                if (strcmp(allChange[i].type, line_filter) == 0)
                {
                    char string[128];
                    sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", allChange[i].model,
                    allChange[i].standardSize, allChange[i].cost, allChange[i].voltage, allChange[i].type, allChange[i].price);
                    not_point++;
                    printf("*Number of battery: %d\n%s", i + 1, string);
                }
            }
            break;
        case price:
            printf("*Write a price of your battery: ");
            gets(line);
            fflush(stdin);
            system("cls");
            while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод вольтажа батарейки
            {
                for (int j = 0; j < strlen(line); j++)
                {
                    if (isdigit(line[j]))
                    {
                        len_counter++;
                    }
                }
                if (len_counter == strlen(line))
                {
                    filter = atoi (line);
                }
                else
                {
                    len_counter = 0;
                    printf("*Write error. Write a price of your battery: ");
                    memset (line, 0, sizeof(line));
                    gets(line);
                    fflush(stdin);
                    system("cls");
                }
            }
            for (int i = 0; i < count; i++)
            {
                int variable = allChange[i].price;
                if (variable == filter)
                {
                    char string[128];
                    sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", allChange[i].model,
                    allChange[i].standardSize, allChange[i].cost, allChange[i].voltage, allChange[i].type, allChange[i].price);
                    not_point++;
                    printf("*Number of battery: %d\n%s", i + 1, string);
                }
            }
            break;
        }
        if (not_point == 0)
        {
            puts("*There are no notes.");
        }
    }
}

void ascending_sort(int count, battery* allChange) // Функция выводит записи по возрастанию
{
    int point = 0, not_point = 0;
    if (count == 0)
    {
        puts("*The are no notes.");
    }
    else
    {
        puts("*Select a number filtering");
        puts("*1 - Model\n*2 - StandartSize\n*3 - Cost\n*4 - Voltage\n*5 - Type\n*6 - Price");
        printf("*Your select: ");
        scanf("%d", &point);
        while (point < 1 || point > 7)
        {
            puts("Write error. Try again.");
            printf("*Your select: ");
            scanf("%d", &point);
            fflush(stdin);
            system("cls");
        }
        fflush(stdin);
        system("cls");
        battery time_change;
        char line[50], string[50];
        switch (point)
        {
        case model: // Сортировка по возрастанию в алфавитном порядке названия модели
            for (int i = 0; i < count - 1; i++)
            {
                strcpy(line, allChange[i].model);
                for (int j = 1; j < count; j++)
                {
                    strcpy(string, allChange[j].model);
                    if (toupper((int)line[0]) > (toupper((int)string[0])))
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
            break;
        case standartSize: // Сортировка по возрастанию в алфавитном порядке названия типоразмера
            for (int i = 0; i < count - 1; i++)
            {
                strcpy(line, allChange[i].standardSize);
                for (int j = 1; j < count; j++)
                {
                    strcpy(string, allChange[j].standardSize);
                    if (toupper((int)line[0]) > (toupper((int)string[0])))
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
            break;
        case cost: // Сортировка по возрастанию стоимости батарейки
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = 1; j < count; j++)
                {
                    if (allChange[i].cost > allChange[j].cost)
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
            break;
        case voltage: // Сортировка по возрастанию вольтажа батарейки
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = 1; j < count; j++)
                {
                    if (allChange[i].voltage > allChange[j].voltage)
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
        case type: // Сортировка по возрастанию в алфавитном порядке названия типа
            for (int i = 0; i < count - 1; i++)
            {
                strcpy(line, allChange[i].type);
                for (int j = 1; j < count; j++)
                {
                    strcpy(string, allChange[j].type);
                    if (toupper((int)line[0]) > (toupper((int)string[0])))
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
            break;
        case price: // Сортировка по возрастанию прайса батарейки
            for (int i = 0; i < count - 1; i++)
            {
                int variable = allChange[i].price;
                for (int j = 1; j < count; j++)
                {
                    int variable1 = allChange[j].price;
                    if (variable > variable1)
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
        }
        for (int i = 0; i < count; i++)
        {
            char string[128];
            sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", allChange[i].model,
            allChange[i].standardSize, allChange[i].cost, allChange[i].voltage, allChange[i].type, allChange[i].price);
            not_point++;
            printf("*Number of battery: %d\n%s", i + 1, string);
        } 
    }
}

void descending_sort(int count, battery* allChange) // Функция выводит записи по убыванию
{
    int point = 0, not_point = 0;
    if (count == 0)
    {
        puts("*The are no notes.");
    }
    else
    {
        puts("*Select a number filtering");
        puts("*1 - Model\n*2 - StandartSize\n*3 - Cost\n*4 - Voltage\n*5 - Type\n*6 - Price");
        printf("*Your select: ");
        scanf("%d", &point);
        while (point < 1 || point > 7)
        {
            puts("Write error. Try again.");
            printf("*Your select: ");
            scanf("%d", &point);
            fflush(stdin);
            system("cls");
        }
        fflush(stdin);
        system("cls");
        battery time_change;
        char line[50], string[50];
        switch (point)
        {
        case model: // Сортировка по возрастанию в алфавитном порядке названия модели
            for (int i = 0; i < count - 1; i++)
            {
                strcpy(line, allChange[i].model);
                for (int j = 1; j < count; j++)
                {
                    strcpy(string, allChange[j].model);
                    if (toupper((int)line[0]) < (toupper((int)string[0])))
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
            break;
        case standartSize: // Сортировка по возрастанию в алфавитном порядке названия типоразмера
            for (int i = 0; i < count - 1; i++)
            {
                strcpy(line, allChange[i].standardSize);
                for (int j = 1; j < count; j++)
                {
                    strcpy(string, allChange[j].standardSize);
                    if (toupper((int)line[0]) < (toupper((int)string[0])))
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
            break;
        case cost: // Сортировка по возрастанию стоимости батарейки
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = 1; j < count; j++)
                {
                    if (allChange[i].cost < allChange[j].cost)
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
            break;
        case voltage: // Сортировка по возрастанию вольтажа батарейки
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = 1; j < count; j++)
                {
                    if (allChange[i].voltage < allChange[j].voltage)
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
        case type: // Сортировка по возрастанию в алфавитном порядке названия типа
            for (int i = 0; i < count - 1; i++)
            {
                strcpy(line, allChange[i].type);
                for (int j = 1; j < count; j++)
                {
                    strcpy(string, allChange[j].type);
                    if (toupper((int)line[0]) < (toupper((int)string[0])))
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
            break;
        case price: // Сортировка по возрастанию прайса батарейки
            for (int i = 0; i < count - 1; i++)
            {
                int variable = allChange[i].price;
                for (int j = 1; j < count; j++)
                {
                    int variable1 = allChange[j].price;
                    if (variable < variable1)
                    {
                        time_change = allChange[i];
                        allChange[i] =  allChange[j];
                        allChange[j] = time_change;
                    }
                }
            }
        }
        for (int i = 0; i < count; i++)
        {
            char string[128];
            sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", allChange[i].model,
            allChange[i].standardSize, allChange[i].cost, allChange[i].voltage, allChange[i].type, allChange[i].price);
            not_point++;
            printf("*Number of battery: %d\n%s", i + 1, string);
        } 
    }
}

void check_notes_file(char* string, battery** allChange, int* count, int* counting) // Функция добавляет записи из файла
{
    int len = strlen(string), counter = 0, flag = 0;
    char line[50];
    battery charge;
    charge.model = malloc(50 * sizeof *charge.model);
    charge.standardSize = malloc(50 * sizeof *charge.standardSize);
    charge.type = malloc(50 * sizeof *charge.type);
    *allChange = realloc(*allChange, ((*count + 1) * sizeof(battery)));
    for (int i = 0; i < len; i++) // Проверка записи в файле
    {
        if (string[i] == ':')
        {
            int j = i;
            j += 2;
            memset (line, 0, sizeof(line));
            for (int k = 0; k < len; k++)
            {
                if (string[j] == ',')
                {
                    break;
                }
                line[k] = string[j];
                j++;
            }
            counter++;
            if (counter == 1)
            {
                strcpy(charge.model, line);
            }
            else if (counter == 2)
            {
                strcpy(charge.standardSize, line);
            }
            else if (counter == 3)
            {
                charge.cost = atoi (line);
            }
            else if (counter == 4)
            {
                charge.voltage = atoi (line);
            }
            else if (counter == 5)
            {
                strcpy(charge.type, line);
            }
            else if (counter == 6)
            {
                charge.price = atoi (line);
            }
        }
    }
    if (counter == 6) // Запись в программу, если строка верная
    {
        (*allChange)[*count] = charge;
        (*count)++;
        (*counting)++;

    }
}

int main()
{
    srand(time(NULL));
    enum MenuOptions{start = 1, AddNotes, delete, show, filter, SortUp, SortDown, exit};
    bool menu = true;
    int count = 0, flag = 0;
    battery* allChange = NULL;
    FILE* file = fopen("test.txt", "r");
    if (file == NULL)
        file = fopen("test.txt", "w");
    fclose(file);
    while(menu)
    {
        puts("***Menu***");
        puts("*Write 1 to start the program and enter the data.");
        puts("*Write 2 to add notes from file.");
        puts("*Write 3 to delete added notes");
        puts("*Write 4 to show added notes.");
        puts("*Write 5 to filtering notes.");
        puts("*Write 6 to sorting up notes.");
        puts("*Write 7 to sorting down notes.");
        puts("*Write 8 to exit the program.");
        printf("*Enter an item from the menu: ");
        fflush(stdin);
        scanf("%d", &flag);
        fflush(stdin);
        system("cls");
        switch (flag)
        {
        case start: // Добавление записи
            check_input(&count, &allChange);
            add_file(count, file, allChange);
            system("cls");
            puts("*Note is added.");
            break;
        case AddNotes: // Добавление записей из файла
            file = fopen("test.txt","r");
            fseek(file ,0, SEEK_END);
            long pos = ftell(file); // Возвращает текущее значение указателя положения в файле
            if (pos == 0) // Файл пустой
            {
                puts("*The file is empty");
                break;
            }
            int counter = 0;
            fseek(file, 0, SEEK_SET); // Возвращает указатель в начало файла
            char string[256];
            while (true) // Считывание строк из файла
            {
                if (NULL != fgets(string, 256, file)) // Считывание строки из файла
                {
                    check_notes_file(string, &allChange, &count, &counter);
                }
                else
                {
                    break;
                }
            }
            fclose(file);
            if (counter == 0)
            {
                puts("*Write error. Notes aren't added.");
            }
            else
            {
                puts("*Notes added.");
            }
            break;
        case delete: // Удаление записи
            if (count == 0)
            {
                puts("*The are no notes.");
                system("cls");
            }
            else
            {
                delete_notes(count, allChange);
                count--;
                add_file(count, file, allChange);
            }
        case show: // Вывод записей на экран
            show_notes(count, allChange);
            break;
        case filter: // Фильтрация записей
            filtration_notes(count, allChange);
            break;
        case SortUp: // Сортировка по возрастанию
            ascending_sort(count, allChange);
            break;
        case SortDown: // Сортировка по убыванию
            descending_sort(count, allChange);
            break;
        case exit: // Завершение программы
            system("cls");
            menu = false;
            for (int i = 0; i < count; i++)
            {
                free(allChange[i].model);
                free(allChange[i].standardSize);
                free(allChange[i].type);
            }
            free(allChange);
            puts("*The program is end.");
            break;
        default:
            system("cls");
            printf("*Input error.");
        }
    }
}