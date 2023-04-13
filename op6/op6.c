/*
Смолянинов Ярослав Евгеньевич, КИ21-17/2Б, вариант 18
Реализация хранения информации о батарейках со связанными списками.
*/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

typedef struct battery
{
    char *model;
    char *standardSize;
    int cost;
    int voltage;
    char *type;
    float price;
    struct battery* next;
    struct battery* prev;
} battery;

enum Choice{model = 1, standartSize, cost, voltage, type, price};

void check_input(int* count, battery** allChange) // Функция проверки ввода данных для добавления записей
{
    char line[50];
    bool flag = true;
    int len_counter = 0;
    battery* charge = malloc(sizeof(battery));
    charge->model = malloc(50 * sizeof *charge->model);
    charge->standardSize = malloc(50 * sizeof *charge->standardSize);
    charge->type = malloc(50 * sizeof *charge->type);
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
            strcpy(charge->model, line);
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
            strcpy(charge->standardSize, line);
            memset (line, 0, sizeof(line));
            flag = false;
        }
        else if ((line[0] == 'A') && (line[1] == 'A'))
        {
            strcpy(charge->standardSize, line);
            memset (line, 0, sizeof(line));
            flag = false;
        }
        else if ((line[0] == 'A') && (line[1] == 'A') && (line[2] == 'A'))
        {
            strcpy(charge->standardSize, line);
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
            charge->cost = strtol (line, NULL, 10);
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
            charge->voltage = strtol (line, NULL, 10);
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
            strcpy(charge->type, line);
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
    charge->price = ((float)charge->cost / (float)charge->voltage);
    if (*allChange != NULL)
    {
        battery* cur = *allChange;
        cur->next = charge;
        charge->prev = cur;
        charge->next = NULL;
        *allChange = charge;
    }
    else
    {
        *allChange = charge;
        (*allChange)->prev = NULL;
        (*allChange)->next = NULL;
    }
    (*count)++;
}

void show_notes(int count, battery** allChange) // Функция вывода записей на экран
{
    if (count == 0) // Если отсутствуют записи
    {
        puts("*The are no notes.");
    }
    else // Вывод записей на экран
    {
        battery* cur = *allChange;
        while (cur->prev != NULL)
        {
            cur = cur->prev;
        }
        int i = 0;
        while (cur != NULL)
        {
            i++;
            printf("***\n");
            printf("*Number of battery %d\n", i);
            printf("*Model: %s\n", cur->model);
            printf("*Standartsize: %s\n", cur->standardSize);
            printf("*Cost: %d Rub\n", cur->cost);
            printf("*Voltage: %dB\n", cur->voltage);
            printf("*Type: %s\n", cur->type);
            printf("*Price: %2.2f B/Rub\n", cur->price);
            printf("***\n");
            cur = cur->next;
        }
    }
}

void delete_notes(int count, battery** allChange) // Функция удаления записи
{
    int point = 0;
    battery* cur = *allChange;
    while (cur->prev != NULL)
    {
        cur = cur->prev;
    }
    int i = 0;
    while (cur != NULL) // Вывод записей на экран
    {
        i++;
        printf("***\n");
        printf("*Number of battery %d\n", i);
        printf("*Model: %s\n", cur->model);
        printf("*Standartsize: %s\n", cur->standardSize);
        printf("*Cost: %d Rub\n", cur->cost);
        printf("*Voltage: %dB\n", cur->voltage);
        printf("*Type: %s\n", cur->type);
        printf("*Price: %2.2f B/Rub\n", cur->price);
        printf("***\n");
        cur = cur->next;
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
    cur = *allChange;
    while (cur->prev != NULL) // Возвращаемся к 1 элементу
    {
        cur = cur->prev;
    }
    int counter = 1;
    while (counter != point) // Находим нужный элемент
    {
        counter++;
        cur = cur->next;
    }
    if (cur->next == NULL && cur->prev == NULL) // Если всего 1 элемент
    {
        free(cur);
        cur = NULL;
        *allChange = cur;
        return;
    }
    if (cur->next == NULL) // Если последний элемент
    {
        battery* memory = cur;
        cur = cur->prev;
        cur->next = NULL;
        free(memory);
        *allChange = cur;
        return;
    }
    if (cur->prev == NULL) // Если первый элемент
    {
        battery* memory = cur;
        cur = cur->next;
        cur->prev = NULL;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        free(memory);
        *allChange = cur;
        return;
    }
    battery* memory = cur; // Ищем нужный элемент
    battery* next_cur = cur->next;
    cur = cur->prev;
    cur->next = next_cur;
    next_cur->prev = cur;
    while (cur != NULL)
    {
        if (cur->next != NULL)
        {
            break;
        }
        cur = cur->next;
    }
    free(memory);
    *allChange = cur;
    return;
}

void add_file(FILE* file, battery** allChange) // Функция добавления записи в файл
{
    battery* cur = *allChange;
    if (cur == NULL)
    {
        file = fopen("test.txt", "w");
        fclose(file);
        return;
    }
    while (cur->prev != NULL)
    {
        cur = cur->prev;
    }
    file = fopen("test.txt", "w");
    while (cur != NULL)
    {
        char string[256];
        sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.", cur->model,
        cur->standardSize, cur->cost, cur->voltage, cur->type, cur->price);
        fputs(string, file);
        fputc('\n', file);
        cur = cur->next;
    }
    fclose(file);
}

void filtration_notes(int count, battery** allChange) // Функция выводит записи по заданному фильтру
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
        battery* cur = *allChange;
        int i = 0;
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
            while(cur != NULL)
                {
                    if (!cur->model == filter)
                    {
                        i++;
                        char string[128];
                        sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", cur->model,
                        cur->standardSize, cur->cost, cur->voltage, cur->type, cur->price);
                        not_point++;
                        printf("*Number of battery: %d\n%s", i + 1, string);
                    }
                    cur = cur->prev;
                }
                i = 0;
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
            while(cur != NULL)
                {
                    if (!cur->standardSize == filter)
                    {
                        i++;
                        char string[128];
                        sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", cur->model,
                        cur->standardSize, cur->cost, cur->voltage, cur->type, cur->price);
                        not_point++;
                        printf("*Number of battery: %d\n%s", i + 1, string);
                    }
                    cur = cur->prev;
                }
                i = 0;
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
            while(cur != NULL)
                {
                    if (cur->cost == filter)
                    {
                        i++;
                        char string[128];
                        sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", cur->model,
                        cur->standardSize, cur->cost, cur->voltage, cur->type, cur->price);
                        not_point++;
                        printf("*Number of battery: %d\n%s", i + 1, string);
                    }
                    cur = cur->prev;
                }
                i = 0;
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
            while(cur != NULL)
                {
                    if (cur->voltage == filter)
                    {
                        i++;
                        char string[128];
                        sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", cur->model,
                        cur->standardSize, cur->cost, cur->voltage, cur->type, cur->price);
                        not_point++;
                        printf("*Number of battery: %d\n%s", i + 1, string);
                    }
                    cur = cur->prev;
                }
                i = 0;
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
            while(cur != NULL)
                {
                    if (!cur->type == filter)
                    {
                        i++;
                        char string[128];
                        sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", cur->model,
                        cur->standardSize, cur->cost, cur->voltage, cur->type, cur->price);
                        not_point++;
                        printf("*Number of battery: %d\n%s", i + 1, string);
                    }
                    cur = cur->prev;
                }
                i = 0;
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
            while(cur != NULL)
                {
                    if (cur->price == filter)
                    {
                        i++;
                        char string[128];
                        sprintf(string, "Model: %s, StandartSize: %s, Cost: %d, Voltage: %d, Type: %s, Price: %2.2f.\n", cur->model,
                        cur->standardSize, cur->cost, cur->voltage, cur->type, cur->price);
                        not_point++;
                        printf("*Number of battery: %d\n%s", i + 1, string);
                    }
                    cur = cur->prev;
                }
                i = 0;
                break;
        }
        if (not_point == 0)
        {
            puts("*There are no notes.");
        }
    }
}

void swap_places(battery* elem1, battery* elem2) // Функция меняет местами элементы связного списка
{
    int changing;
    float change;
    char line[50];
    for (int i = 0; i < strlen(elem1->model); i++)
    {
        line[i] = elem1->model[i];
    }
    strcpy(elem1->model, elem2->model);
    strcpy(elem2->model, line);
    memset (line, 0, sizeof(line));

    for (int i = 0; i < strlen(elem1->standardSize); i++)
    {
        line[i] = elem1->standardSize[i];
    }
    strcpy(elem1->standardSize, elem2->standardSize);
    strcpy(elem2->standardSize, line);
    memset (line, 0, sizeof(line));

    changing = elem1->cost;
    elem1->cost = elem2->cost;
    elem2->cost = changing;

    changing = elem1->voltage;
    elem1->voltage = elem2->voltage;
    elem2->voltage = changing;

    for (int i = 0; i < strlen(elem1->type); i++)
    {
        line[i] = elem1->type[i];
    }
    strcpy(elem1->type, elem2->type);
    strcpy(elem2->type, line);
    memset (line, 0, sizeof(line));

    change = elem1->price;
    elem1->price = elem2->price;
    elem2->price = change;
}

void ascending_sort(int count, battery** allChange) // Функция выводит записи по возрастанию
{
    int point = 0;
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
            puts("*Write error. Try again.");
            printf("*Your select: ");
            scanf("%d", &point);
            fflush(stdin);
            system("cls");
        }
        fflush(stdin);
        system("cls");
        battery* cur = *allChange;
        while (cur->prev != NULL)
        {
            cur = cur->prev;
        }
        battery* next_cur = cur->next;
        battery* second_el = next_cur;
        char line[50], string[50];
        switch (point)
        {
        case model: // Сортировка по возрастанию в алфавитном порядке названия модели
            while(cur != NULL)
            {
                while(next_cur != NULL)
                {
                    strcpy(line, cur->model);
                    strcpy(string, next_cur->model);
                    if (toupper((int)line[0]) > (toupper((int)string[0])))
                    {
                        swap_places(cur, next_cur);
                    }
                    next_cur = next_cur->next;
                }
                cur = cur->next;
                next_cur = second_el;
            }
            break;
        case standartSize: // Сортировка по возрастанию в алфавитном порядке названия типоразмера
            while(cur != NULL)
            {
                while(next_cur != NULL)
                {
                    strcpy(line, cur->standardSize);
                    strcpy(string, next_cur->standardSize);
                    if (toupper((int)line[0]) > (toupper((int)string[0])))
                    {
                        swap_places(cur, next_cur);
                    }
                    next_cur = next_cur->next;
                }
                cur = cur->next;
                next_cur = second_el;
            }
            break;
        case cost: // Сортировка по возрастанию стоимости батарейки
            while(cur != NULL)
            {
                while(cur != NULL)
                {
                    while(next_cur != NULL)
                    {
                        if (cur->cost > next_cur->cost)
                        {
                            swap_places(cur, next_cur);
                        }
                        next_cur = next_cur->next;
                    }
                    cur = cur->next;
                    next_cur = second_el;
                }
            }
            break;
        case voltage: // Сортировка по возрастанию вольтажа батарейки
            while(cur != NULL)
            {
                while(next_cur != NULL)
                {
                    if (cur->voltage > next_cur->voltage)
                    {
                        swap_places(cur, next_cur);
                    }
                    next_cur = next_cur->next;
                }
                cur = cur->next;
                next_cur = second_el;
            }
            break;
        case type: // Сортировка по возрастанию в алфавитном порядке названия типа
            while(cur != NULL)
            {
                while(next_cur != NULL)
                {
                    strcpy(line, cur->type);
                    strcpy(string, next_cur->type);
                    if (toupper((int)line[0]) > (toupper((int)string[0])))
                    {
                        swap_places(cur, next_cur);
                    }
                    next_cur = next_cur->next;
                }
                cur = cur->next;
                next_cur = second_el;
            }
            break;
        case price: // Сортировка по возрастанию прайса батарейки
            while(cur != NULL)
            {
                while(next_cur != NULL)
                    {
                        if (cur->voltage > next_cur->voltage)
                        {
                            swap_places(cur, next_cur);
                        }
                        next_cur = next_cur->next;
                    }
                cur = cur->next;
                next_cur = second_el;
            }
            break;
        }
        cur = *allChange;
        while (cur->prev != NULL)
        {
            cur = cur->prev;
        }
        int i = 0;
        while (cur != NULL) // Вывод записей на экран
        {
            i++;
            printf("***\n");
            printf("*Number of battery %d\n", i);
            printf("*Model: %s\n", cur->model);
            printf("*Standartsize: %s\n", cur->standardSize);
            printf("*Cost: %d Rub\n", cur->cost);
            printf("*Voltage: %dB\n", cur->voltage);
            printf("*Type: %s\n", cur->type);
            printf("*Price: %2.2f B/Rub\n", cur->price);
            printf("***\n");
            cur = cur->next;
        }
    }
}

void descending_sort(int count, battery** allChange) // Функция выводит записи по убыванию
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
            puts("*Write error. Try again.");
            printf("*Your select: ");
            scanf("%d", &point);
            fflush(stdin);
            system("cls");
        }
        fflush(stdin);
        system("cls");
        battery* cur = *allChange;
        while (cur->prev != NULL)
        {
            cur = cur->prev;
        }
        battery* next_cur = cur->next;
        battery* second_el = next_cur;
        char line[50], string[50];
        switch (point)
        {
        case model: // Сортировка по возрастанию в алфавитном порядке названия модели
            while(cur != NULL)
            {
                while(next_cur != NULL)
                {
                    strcpy(line, cur->model);
                    strcpy(string, next_cur->model);
                    if (toupper((int)line[0]) < (toupper((int)string[0])))
                    {
                        swap_places(cur, next_cur);
                    }
                    next_cur = next_cur->next;
                }
                cur = cur->next;
                next_cur = second_el;
            }
            break;
        case standartSize: // Сортировка по возрастанию в алфавитном порядке названия типоразмера
            while(cur != NULL)
            {
                while(next_cur != NULL)
                {
                    strcpy(line, cur->standardSize);
                    strcpy(string, next_cur->standardSize);
                    if (toupper((int)line[0]) < (toupper((int)string[0])))
                    {
                        swap_places(cur, next_cur);
                    }
                    next_cur = next_cur->next;
                }
                cur = cur->next;
                next_cur = second_el;
            }
            break;
        case cost: // Сортировка по возрастанию стоимости батарейки
            while(cur != NULL)
            {
                while(cur != NULL)
                {
                    while(next_cur != NULL)
                    {
                        if (cur->cost < next_cur->cost)
                        {
                            swap_places(cur, next_cur);
                        }
                        next_cur = next_cur->next;
                    }
                    cur = cur->next;
                    next_cur = second_el;
                }
            }
            break;
        case voltage: // Сортировка по возрастанию вольтажа батарейки
            while(cur != NULL)
            {
                while(next_cur != NULL)
                {
                    if (cur->voltage > next_cur->voltage)
                    {
                        swap_places(cur, next_cur);
                    }
                    next_cur = next_cur->next;
                }
                cur = cur->next;
                next_cur = second_el;
            }
            break;
        case type: // Сортировка по возрастанию в алфавитном порядке названия типа
            while(cur != NULL)
            {
                while(next_cur != NULL)
                {
                    strcpy(line, cur->type);
                    strcpy(string, next_cur->type);
                    if (toupper((int)line[0]) < (toupper((int)string[0])))
                    {
                        swap_places(cur, next_cur);
                    }
                    next_cur = next_cur->next;
                }
                cur = cur->next;
                next_cur = second_el;
            }
            break;
        case price: // Сортировка по возрастанию прайса батарейки
            for (int i = 0; i < count - 1; i++)
            while(cur != NULL)
            {
                while(next_cur != NULL)
                    {
                        if (cur->voltage < next_cur->voltage)
                        {
                            swap_places(cur, next_cur);
                        }
                        next_cur = next_cur->next;
                    }
                cur = cur->next;
                next_cur = second_el;
            }
            break;
        }
        cur = *allChange;
        while (cur->prev != NULL)
        {
            cur = cur->prev;
        }
        int i = 0;
        while (cur != NULL) // Вывод записей на экран
        {
            i++;
            printf("***\n");
            printf("*Number of battery %d\n", i);
            printf("*Model: %s\n", cur->model);
            printf("*Standartsize: %s\n", cur->standardSize);
            printf("*Cost: %d Rub\n", cur->cost);
            printf("*Voltage: %dB\n", cur->voltage);
            printf("*Type: %s\n", cur->type);
            printf("*Price: %2.2f B/Rub\n", cur->price);
            printf("***\n");
            cur = cur->next;
        }
    }
}

void check_notes_file(char* string, battery** allChange, int* count, int* counting) // Функция добавляет записи из файла
{
    int len = strlen(string), counter = 0, flag = 0;
    char line[50];
    battery* charge = malloc(sizeof(battery));
    charge->model = malloc(50 * sizeof *charge->model);
    charge->standardSize = malloc(50 * sizeof *charge->standardSize);
    charge->type = malloc(50 * sizeof *charge->type);
    for (int i = 0; i < len; i++) // Проверка записи в файле
    {
        if (string[i] == ':')
        {
            int j = i;
            j += 2;
            memset (line, 0, sizeof(line));
            for (int k = 0; k < len; k++)
            {
                if (string[j] == ',' || string[j] == '.')
                {
                    break;
                }
                line[k] = string[j];
                j++;
            }
            counter++;
            if (counter == 1)
            {
                strcpy(charge->model, line);
            }
            else if (counter == 2)
            {
                strcpy(charge->standardSize, line);
            }
            else if (counter == 3)
            {
                charge->cost = atoi (line);
            }
            else if (counter == 4)
            {
                charge->voltage = atoi (line);
            }
            else if (counter == 5)
            {
                strcpy(charge->type, line);
            }
            else if (counter == 6)
            {
                charge->price = atoi (line);
            }
        }
    }
    if (counter == 6) // Запись в программу, если строка верная
    {
        if (*allChange != NULL)
        {
            battery* cur = *allChange;
            cur->next = charge;
            charge->prev = cur;
            charge->next = NULL;
            *allChange = charge;
        }
        else
        {
            *allChange = charge;
            (*allChange)->prev = NULL;
            (*allChange)->next = NULL;
        }
        (*count)++;
        (*counting)++;
    }
    else
    {
        return;
    }
}

void inversion(battery** notes) // Функция выполняет инверсию связного списка
{
    battery* cur = *notes;
    if (cur == NULL)
    {
        puts("*There are no notes");
        return;
    }
    while (cur->prev != NULL)
    {
        cur = cur->prev;
    }
    battery* change;
    int i = 0;
    puts("*It was:");
    while(cur != NULL)
    {
        i++;
        printf("***\n");
        printf("*Number of battery %d\n", i);
        printf("*Model: %s\n", cur->model);
        printf("*Standartsize: %s\n", cur->standardSize);
        printf("*Cost: %d Rub\n", cur->cost);
        printf("*Voltage: %dB\n", cur->voltage);
        printf("*Type: %s\n", cur->type);
        printf("*Price: %2.2f B/Rub\n", cur->price);
        printf("***\n");
        cur = cur->next;
    }
    cur = *notes;
    while (cur != NULL)
    {
        change = cur->prev;
        cur->prev = cur->next;
        cur->next = change;
        if (cur->next == NULL)
        {
            *notes = cur;
        }
        cur = cur->next;
    }
    cur = *notes;
    while (cur->prev != NULL)
    {
        cur = cur->prev;
    }
    i = 0;
    puts("*Has bacome:");
    while(cur != NULL)
    {
        i++;
        printf("***\n");
        printf("*Number of battery %d\n", i);
        printf("*Model: %s\n", cur->model);
        printf("*Standartsize: %s\n", cur->standardSize);
        printf("*Cost: %d Rub\n", cur->cost);
        printf("*Voltage: %dB\n", cur->voltage);
        printf("*Type: %s\n", cur->type);
        printf("*Price: %2.2f B/Rub\n", cur->price);
        printf("***\n");
        cur = cur->next;
    }
}

void length(battery** allChange) // Функция ищет длину связного списка
{
    battery* cur = *allChange;
    int count = 0;
    if (cur == NULL)
    {
        printf("The length of the linked list: %d\n", count);
        return;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    while (cur != NULL)
    {
        count++;
        cur = cur->prev;
    }
    printf("The length of the linked list: %d\n", count);
}

int main()
{
    srand(time(NULL));
    bool menu = true;
    int count = 0, flag = 0;
    enum MenuOptions{start = 1, AddNotes, delete, show, filter, SortUp, SortDown, Length, Inversion, exit};
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
        puts("*Write 8 to know the length of the linked list.");
        puts("*Write 9 to inversion the linked list.");
        puts("*Write 10 to exit the program.");
        printf("*Enter an item from the menu: ");
        fflush(stdin);
        scanf("%d", &flag);
        fflush(stdin);
        system("cls");
        switch (flag)
        {
        case start: // Добавление записи
            check_input(&count, &allChange);
            add_file(file, &allChange);
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
                delete_notes(count, &allChange);
                count--;
                add_file(file, &allChange);
            }
            break;
        case show: // Вывод записей на экран
            show_notes(count, &allChange);
            break;
        case filter: // Фильтрация записей
            filtration_notes(count, &allChange);
            break;
        case SortUp: // Сортировка по возрастанию
            ascending_sort(count, &allChange);
            break;
        case SortDown: // Сортировка по убыванию
            descending_sort(count, &allChange);
            break;
        case Length:
            length(&allChange); // Нахождение длины связного списка
            break;
        case Inversion:
            inversion(&allChange); // Инверсия связного списка
            break;
        case exit: // Завершение программы
            system("cls");
            menu = false;
            file = fopen("test.txt", "w");
            fclose(file);
            while (allChange != NULL)
            {
                battery* cur = allChange;
                free(allChange->model);
                free(allChange->standardSize);
                free(allChange->type);
                allChange = allChange->prev;
                free(cur);
            }
            puts("*The program is end.");
            break;
        default:
            system("cls");
            printf("*Input error.\n");
        }
    }
}