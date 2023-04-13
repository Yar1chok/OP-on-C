#include "op7func.h"

void check_input_person(int* count, person** AllPersons) // Проверка ввода больного и запись их в структуру
{
    char line[50];
    bool flag = true;
    int len_counter = 0;
    int number = 0;
    person* human = malloc(sizeof(person));
    human->enumeratorA = 0;
    human->name = malloc(50 * sizeof *human->name);
    human->surname = malloc(50 * sizeof *human->surname);
    human->patronymic = malloc(50 * sizeof *human->patronymic);
    human->gender = malloc(50 * sizeof *human->gender);
    human->connection = malloc(human->enumeratorA * sizeof *human->connection);
    printf("*Write a patient's name: ");
    gets(line);
    fflush(stdin);
    system("cls");
    while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод имени больного
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
            strcpy(human->name, line);
        }
        else
        {
            len_counter = 0;
            printf("*Write error. Write a patient's name: ");
            memset (line, 0, sizeof(line));
            gets(line);
            fflush(stdin);
            system("cls");
        }
    }
    memset (line, 0, sizeof(line));
    len_counter = 0;
    printf("*Write a patient's surname: ");
    gets(line);
    fflush(stdin);
    system("cls");
    while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод фамилии больного
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
            strcpy(human->surname, line);
        }
        else
        {
            len_counter = 0;
            printf("*Write error. Write a patient's surname: ");
            memset (line, 0, sizeof(line));
            gets(line);
            fflush(stdin);
            system("cls");
        }
    }
    memset (line, 0, sizeof(line));
    len_counter = 0;
    printf("*Write a patient's patronymic: ");
    gets(line);
    fflush(stdin);
    system("cls");
    while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод отчества больного
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
            strcpy(human->patronymic, line);
        }
        else
        {
            len_counter = 0;
            printf("*Write error. Write a patient's patronymic: ");
            memset (line, 0, sizeof(line));
            gets(line);
            fflush(stdin);
            system("cls");
        }
    }
    memset (line, 0, sizeof(line));
    len_counter = 0;
    printf("*Write a day of your birth: ");
    scanf("%d", &number);
    fflush(stdin);
    system("cls");
    while(flag) // Проверка ввода дня рождения больного
    {
        if (number >= 1 && number <= 30)
        {
           human->day = number;
           break;
        }
        else
        {
            printf("*Write error. Write a number again: ");
            scanf("%d", &number);
            fflush(stdin);
            system("cls");
        }
    }
    printf("*Write a month of your birth: ");
    scanf("%d", &number);
    fflush(stdin);
    system("cls");
    while(flag) // Проверка ввода месяца рождения больного
    {
        if (number >= 1 && number <= 12)
        {
           human->month = number;
           break;
        }
        else
        {
            printf("*Write error. Write a number again: ");
            scanf("%d", &number);
            fflush(stdin);
            system("cls");
        }
    }
    printf("*Write year of your birth: ");
    scanf("%d", &number);
    fflush(stdin);
    system("cls");
    while(flag) // Проверка ввода года рождения больного
    {
        if (number >= 1 && number <= 3000)
        {
           human->year = number;
           break;
        }
        else
        {
            printf("*Write error. Write a number again: ");
            scanf("%d", &number);
            fflush(stdin);
            system("cls");
        }
    }
    puts("*Write 1, if you are man:");
    puts("*Write 2, if you are woman:");
    printf("*Write number: ");
    scanf("%d", &number);
    fflush(stdin);
    system("cls");
    while(flag) // Проверка и запись пола больного
    {
        if (flag == 1)
        {
           strcpy(human->gender, "Male"); 
           flag = false;
        }
        else if (flag == 2)
        {
            strcpy(human->gender, "Female");
            flag = false;
        }
        else
        {
            printf("*Write error. Write a number again: ");
            scanf("%d", &number);
            fflush(stdin);
            system("cls");
        }
    }
    if (*AllPersons != NULL)
    {
        person* cur = *AllPersons;
        cur->next = human;
        human->prev = cur;
        human->next = NULL;
        *AllPersons = human;
    }
    else
    {
        *AllPersons = human;
        (*AllPersons)->prev = NULL;
        (*AllPersons)->next = NULL;
    }
    (*count)++;
}

void check_input_disease(int *count, disease** AllDisease) // Проверка ввода болезни и запись их в структуру
{
    char line[50];
    bool flag = true;
    int len_counter = 0;
    int number = 0;
    disease* ill = malloc(sizeof(disease));
    ill->enumeratorB = 0;
    ill->name = malloc(50 * sizeof *ill->name);
    ill->linking = malloc(ill->enumeratorB * sizeof *ill->linking);
    printf("*Write a ill name: ");
    gets(line);
    fflush(stdin);
    system("cls");
    while(len_counter != strlen(line) || strlen(line) == 0) // Проверка на ввод болезни
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
            strcpy(ill->name, line);
        }
        else
        {
            len_counter = 0;
            printf("*Write error. Write an ill name: ");
            memset (line, 0, sizeof(line));
            gets(line);
            fflush(stdin);
            system("cls");
        }
    }
    memset (line, 0, sizeof(line));
    len_counter = 0;
    printf("*Write aduration of your illness: ");
    scanf("%d", &number);
    fflush(stdin);
    system("cls");
    while(flag) // Проверка ввода продолжительности болезни
    {
        if (number >= 1)
        {
           ill->length = number;
           break;
        }
        else
        {
            printf("*Write error. *Write aduration again: ");
            scanf("%d", &number);
            fflush(stdin);
            system("cls");
        }
    }
    printf("*Write severity of the disease: ");
    scanf("%d", &number);
    fflush(stdin);
    system("cls");
    while(flag) // Проверка ввода тяжести болезни
    {
        if (number >= 1 && number <= 10)
        {
           ill->severity = number;
           break;
        }
        else
        {
            printf("*Write error. *Write severity again: ");
            scanf("%d", &number);
            fflush(stdin);
            system("cls");
        }
    }
        if (*AllDisease != NULL)
    {
        disease* cur = *AllDisease;
        cur->next = ill;
        ill->prev = cur;
        ill->next = NULL;
        *AllDisease = ill;
    }
    else
    {
        *AllDisease = ill;
        (*AllDisease)->prev = NULL;
        (*AllDisease)->next = NULL;
    }
    (*count)++;
}

void show_notes_person(int count, person** AllPersons) // Функция вывода больных на экран
{
    if (count == 0) // Если отсутствуют записи
    {
        puts("*The are no notes.");
    }
    else // Вывод записей на экран
    {
        person* cur = *AllPersons;
        while (cur->prev != NULL)
        {
            cur = cur->prev;
        }
        int i = 0;
        while (cur != NULL)
        {
            i++;
            printf("***\n");
            printf("*Number of patient's: %d\n", i);
            printf("*Name: %s %s %s\n", cur->name, cur->surname, cur->patronymic);
            printf("*Date of birth: %d.%d.%d\n", cur->day, cur->month, cur->year);
            printf("*Gender: %s\n", cur->gender);
            printf("*Connection with notes: ");
            for (int j = 0; j < cur->enumeratorA; j++)
            {
                printf("%d ", cur->connection[j]);
            }
            printf("\n***\n");
            cur = cur->next;
        }
    }
}

void show_notes_disease(int count, disease** AllDisease) // Функция вывода болезней на экран
{
    if (count == 0) // Если отсутствуют записи
    {
        puts("*The are no notes.");
    }
    else // Вывод записей на экран
    {
        disease* cur = *AllDisease;
        while (cur->prev != NULL)
        {
            cur = cur->prev;
        }
        int i = 0;
        while (cur != NULL)
        {
            i++;
            printf("***\n");
            printf("*Number of disease: %d\n", i);
            printf("*Name: %s\n", cur->name);
            printf("*Length of disease: %d year\n", cur->length);
            printf("*Severuty of disease: %d\n", cur->severity);
            printf("*Connection with notes: ");
            for (int j = 0; j < cur->enumeratorB; j++)
            {
                printf("%d ", cur->linking[j]);
            }
            printf("\n***\n");
            cur = cur->next;
        }
    }
}

void delete_note_person(int countA, person** AllPersons, int countB, disease** AllDisease) // Удаление записи человека
{
    int point = 0;
    person* curA = *AllPersons;
    while (curA->prev != NULL)
    {
        curA = curA->prev;
    }
    int i = 0;
    while (curA != NULL) // Вывод записей на экран
    {
        i++;
        printf("***\n");
        printf("*Number of patient's: %d\n", i);
        printf("*Name: %s %s %s\n", curA->name, curA->surname, curA->patronymic);
        printf("*Date of birth: %d.%d.%d\n", curA->day, curA->month, curA->year);
        printf("*Gender: %s\n", curA->gender);
        printf("*Connection with notes: ");
        for (int j = 0; j < curA->enumeratorA; j++)
        {
            printf("%d ", curA->connection[j]);
        }
        printf("\n***\n");
        curA = curA->next;
    }
    printf("*Write the entry number: ");
    scanf("%d", &point);
    fflush(stdin);
    system("cls");
    while (point <= 0 || point > countA) // Проверка на номер удаления записи
    {
        puts("*Input error. Write the entry number: ");
        scanf("%d", &point);
        fflush(stdin);
        system("cls");
    }
    curA = *AllPersons;
    while (curA->prev != NULL) // Возвращаемся к 1 элементу
    {
        curA = curA->prev;
    }
    int counter = 1;
    while (counter != point) // Находим нужный элемент
    {
        counter++;
        curA = curA->next;
    }
    
    disease* curB = *AllDisease;
    while (curB->prev != NULL)
    {
        curB = curB->prev;
    }
    while (curB != NULL) // Удаление связей в болезнях
    {
        int *listing = malloc(curB->enumeratorB * sizeof *listing);
        int k = 0;
        for (int j = 0; j < curB->enumeratorB; j++)
        {
            if (curB->linking[j] != point)
            {
                if (curB->linking[j] > point)
                {
                    listing[k] = (curB->linking[j] - 1);
                    k++;
                }
                else
                {
                    listing[k] = curB->linking[j];
                    k++;
                }
            }
        }
        if (k == curB->enumeratorB)
        {
            free(listing);
            curB = curB->next;
        }
        else
        {
            curB->enumeratorB--;
            curB->linking = malloc(curB->enumeratorB * sizeof curB->linking);
            for (int i = 0; i < curB->enumeratorB; i++)
            {
                curB->linking[i] = listing[i];
            }
            // memcpy((curB->linking), listing, (curB->enumeratorB));
            free(listing);
            curB = curB->next;
        }
    }

    if (curA->next == NULL && curA->prev == NULL) // Если всего 1 элемент
    {
        free(curA->name);
        free(curA->surname);
        free(curA->patronymic);
        free(curA->gender);
        free(curA->connection);
        free(curA);
        curA = NULL;
        *AllPersons = curA;
        return;
    }
    if (curA->next == NULL) // Если последний элемент
    {
        person* memory = curA;
        curA = curA->prev;
        curA->next = NULL;
        free(memory);
        *AllPersons = curA;
        return;
    }
    if (curA->prev == NULL) // Если первый элемент
    {
        person* memory = curA;
        curA = curA->next;
        curA->prev = NULL;
        while (curA->next != NULL)
        {
            curA = curA->next;
        }
        free(memory);
        *AllPersons = curA;
        return;
    }
    person* memory = curA; // Ищем нужный элемент
    person* next_cur = curA->next;
    curA = curA->prev;
    curA->next = next_cur;
    next_cur->prev = curA;
    while (curA != NULL)
    {
        if (curA->next != NULL)
        {
            break;
        }
        curA = curA->next;
    }
    free(memory);
    *AllPersons = curA;
    return;
}

void delete_note_disease(int countB, disease** AllDisease, int countA, person** AllPerson) // Удаление записи больного
{
    int point = 0;
    disease* curB = *AllDisease;
    while (curB->prev != NULL)
    {
        curB = curB->prev;
    }
    int i = 0;
    while (curB != NULL)
    {
        i++;
        printf("***\n");
        printf("*Number of disease: %d\n", i);
        printf("*Name: %s\n", curB->name);
        printf("*Length of disease: %d year\n", curB->length);
        printf("*Severuty of disease: %d\n", curB->severity);
        printf("*Connection with notes: ");
        for (int j = 0; j < curB->enumeratorB; j++)
        {
            printf("%d ", curB->linking[j]);
        }
        printf("\n***\n");
        curB = curB->next;
    }
    printf("*Write the entry number: ");
    scanf("%d", &point);
    fflush(stdin);
    system("cls");
    while (point <= 0 || point > countB) // Проверка на номер удаления записи
    {
        puts("*Input error. Write the entry number: ");
        scanf("%d", &point);
        fflush(stdin);
        system("cls");
    }
    curB = *AllDisease;
    while (curB->prev != NULL) // Возвращаемся к 1 элементу
    {
        curB = curB->prev;
    }
    int counter = 1;
    while (counter != point) // Находим нужный элемент
    {
        counter++;
        curB = curB->next;
    }

    person* curA = *AllPerson;
    while (curA->prev != NULL)
    {
        curA = curA->prev;
    }
    while (curA != NULL) // Удаление связей в болезнях
    {
        int *listing = malloc(curA->enumeratorA * sizeof *listing);
        int k = 0;
        for (int j = 0; j < curA->enumeratorA; j++)
        {
            if (curA->connection[j] != point)
            {
                if (curA->connection[j] > point)
                {
                    listing[k] = (curA->connection[j] - 1);
                    k++;
                }
                else
                {
                    listing[k] = curA->connection[j];
                    k++;
                }
            }
        }
        if (k == curA->enumeratorA)
        {
            free(listing);
            curA = curA->next;
        }
        else
        {
            curA->enumeratorA--;
            curA->connection = malloc(curB->enumeratorB * sizeof *curB->linking);
            for (int i = 0; i < curA->enumeratorA; i++)
            {
                curA->connection[i] = listing[i];
            }
            free(listing);
            curA = curA->next;
        }
    }

    if (curB->next == NULL && curB->prev == NULL) // Если всего 1 элемент
    {
        free(curB->name);
        free(curB);
        curB = NULL;
        *AllDisease = curB;
        return;
    }
    if (curB->next == NULL) // Если последний элемент
    {
        disease* memory = curB;
        curB = curB->prev;
        curB->next = NULL;
        free(memory);
        *AllDisease = curB;
        return;
    }
    if (curB->prev == NULL) // Если первый элемент
    {
        disease* memory = curB;
        curB = curB->next;
        curB->prev = NULL;
        while (curB->next != NULL)
        {
            curB = curB->next;
        }
        free(memory);
        *AllDisease = curB;
        return;
    }
    disease* memory = curB; // Ищем нужный элемент
    disease* next_cur = curB->next;
    curB = curB->prev;
    curB->next = next_cur;
    next_cur->prev = curB;
    while (curB != NULL)
    {
        if (curB->next != NULL)
        {
            break;
        }
        curB = curB->next;
    }
    free(memory);
    *AllDisease = curB;
    return;
}

void swap_places_person(person* elem1, person* elem2) // Функция меняет местами элементы связного списка больных
{
    int changing;
    float change;
    char line[50];
    for (int i = 0; i < strlen(elem1->name); i++)
    {
        line[i] = elem1->name[i];
    }
    strcpy(elem1->name, elem2->name);
    strcpy(elem2->name, line);
    memset (line, 0, sizeof(line));

    for (int i = 0; i < strlen(elem1->surname); i++)
    {
        line[i] = elem1->surname[i];
    }
    strcpy(elem1->surname, elem2->surname);
    strcpy(elem2->surname, line);
    memset (line, 0, sizeof(line));

    for (int i = 0; i < strlen(elem1->patronymic); i++)
    {
        line[i] = elem1->patronymic[i];
    }
    strcpy(elem1->patronymic, elem2->patronymic);
    strcpy(elem2->patronymic, line);
    memset (line, 0, sizeof(line));

    changing = elem1->day;
    elem1->day = elem2->day;
    elem2->day = changing;

    changing = elem1->month;
    elem1->month = elem2->month;
    elem2->month = changing;

    changing = elem1->year;
    elem1->year = elem2->year;
    elem2->year = changing;

    for (int i = 0; i < strlen(elem1->gender); i++)
    {
        line[i] = elem1->gender[i];
    }
    strcpy(elem1->gender, elem2->gender);
    strcpy(elem2->gender, line);
    memset (line, 0, sizeof(line));
}

void swap_places_disease(disease* elem1, disease* elem2) // Функция меняет местами элементы связного списка болезней
{
    int changing;
    float change;
    char line[50];
    for (int i = 0; i < strlen(elem1->name); i++)
    {
        line[i] = elem1->name[i];
    }
    strcpy(elem1->name, elem2->name);
    strcpy(elem2->name, line);
    memset (line, 0, sizeof(line));

    changing = elem1->length;
    elem1->length = elem2->length;
    elem2->length = changing;

    changing = elem1->severity;
    elem1->severity = elem2->severity;
    elem2->severity = changing;
}

void add_link_person(int countA, person** AllPersons, int countB, disease** AllDisease) // Добавление связи между больными и болезнями
{
    int pointA = 0, pointB = 0;
    person* curA = *AllPersons;
    disease* curB = *AllDisease;
    while (curA->prev != NULL)
    {
        curA = curA->prev;
    }
    int i = 0;
    while (curA != NULL) // Вывод записи больных
    {
        i++;
        printf("***\n");
        printf("*Number of patient's: %d\n", i);
        printf("*Name: %s %s %s\n", curA->name, curA->surname, curA->patronymic);
        printf("*Date of birth: %d.%d.%d\n", curA->day, curA->month, curA->year);
        printf("*Gender: %s\n", curA->gender);
        printf("*Connection with notes: ");
        for (int j = 0; j < curA->enumeratorA; j++)
        {
            printf("%d ", curA->connection[j]);
        }
        printf("\n***\n");
        curA = curA->next;
    }
    printf("*Select the patient's number: ");
    scanf("%d", &pointA);
    fflush(stdin);
    system("cls");
    while (pointA <= 0 || pointA > countA) // Проверка на номер удаления записи
    {
        puts("*Input error. Write the entry number: ");
        scanf("%d", &pointA);
        fflush(stdin);
        system("cls");
    }

    while (curB->prev != NULL)
    {
        curB = curB->prev;
    }
    i = 0;
    while (curB != NULL) // Вывод записи болезней
    {
        i++;
        printf("***\n");
        printf("*Number of disease: %d\n", i);
        printf("*Name: %s\n", curB->name);
        printf("*Length of disease: %d year\n", curB->length);
        printf("*Severuty of disease: %d\n", curB->severity);
        printf("*Connection with notes: ");
        for (int j = 0; j < curB->enumeratorB; j++)
        {
            printf("%d ", curB->linking[j]);
        }
        printf("\n***\n");
        curB = curB->next;
    }
    printf("*Select the disease number: ");
    scanf("%d", &pointB);
    fflush(stdin);
    system("cls");
    while (pointB <= 0 || pointB > countB) // Проверка на номер удаления записи
    {
        puts("*Input error. Write the entry number: ");
        scanf("%d", &pointA);
        fflush(stdin);
        system("cls");
    }
    curA = *AllPersons;
    while (curA->prev != NULL) // Возвращаемся к 1 элементу
    {
        curA = curA->prev;
    }
    int counterA = 1;
    while (counterA != pointA) // Находим нужный элемент больного
    {
        counterA++;
        curA = curA->next;
    }
    curB = *AllDisease;
    while (curB->prev != NULL) // Возвращаемся к 1 элементу
    {
        curB = curB->prev;
    }
    int counterB = 1;
    while (counterB != pointB) // Находим нужный элемент болезни
    {
        counterB++;
        curB = curB->next;
    }
    curA->enumeratorA++;
    curA->connection = realloc((curA->connection), (curA->enumeratorA) * sizeof *curA->connection);
    curA->connection[(curA->enumeratorA) - 1] = pointB;
    curB->enumeratorB++;
    curB->linking = realloc((curB->linking), (curB->enumeratorB) * sizeof *curB->linking);
    curB->linking[(curB->enumeratorB) - 1] = pointA;
    return;
}