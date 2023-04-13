/*
Смолянинов Ярослав Евгеньевич, КИ21-17/2Б, вариант 18
Необходимо выполнить произведение Кронекера-Капелли для двух матриц
*/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

int get_lines(void) // Проверка на ввод количества строк матрицы
{
	int lines = 0;
	while (lines <= 0)
	{
		printf("*Please write the number of lines: ");
		scanf("%d", &lines);
		system("cls");
		if (lines <= 0)
		{
			system("cls");
			printf("*Input error, try again. \n");
			fflush(stdin);
		}
	}
	return lines;
}

int get_columns(void) // Проверка на ввод количества столбцов матрицы
{
	int columns = 0;
	while (columns <= 0)
	{
		printf("*Please write the number of columns: ");
		scanf("%d", &columns);
		system("cls");
		if (columns <= 0)
		{
			system("cls");
			printf("*Input error, try again. \n");
			fflush(stdin);
		}
	}
	return columns;
}

int check_input(void) // Проверка на ввод значений в матрицу
{
	char input[100];
	int number = 0;
	scanf("%s", &input);
	while (sscanf(input, "%d", &number) != 1)
	{
		fflush(stdin);
		printf("Enter an integer: ");
		scanf("%s", &input);
	}
	return number;
}

int multiply_matrices_1(int flag) // Нахождение произведения Кронекера Копели с пользовательским вводом
{
    int line1, column1, line2, column2, fline, fcolumn, var = 0, count = 0, counter = 0, multiply, score = 0, number;
    printf("*Input dimension for first matrices\n"); // Ввод данных для первой матрицы
    line1 = get_lines();
    column1 = get_columns();
    int **plisting1 = (int**)malloc(line1 * sizeof(int));
    printf("*Input numbers for first matrices\n");
    for (int i = 0; i < line1; i++)
    {   
        plisting1[i] = (int*)malloc(column1 * sizeof(int));
        for (int j = 0; j < column1; j++)
        {
            printf("Array[%d] = ", score);
            score++;
            number = check_input();
            plisting1[i][j] = number;
        }
    }
    printf("*Input dimension for second matrices\n"); // Ввод данных для второй таблицы
    line2 = get_lines();
    column2 = get_columns();
    int **plisting2 = (int**)malloc(line2 * sizeof(int));
    printf("*Input numbers for second matrices\n");
    score = 0;
    for (int i = 0; i < line2; i++)
    {
        plisting2[i] = (int*)malloc(column2 * sizeof(int));
        for (int j = 0; j < column2; j++)
        {
            printf("Array[%d] = ", score);
            score++;
            number = check_input();
            plisting2[i][j] = number;
        }
    }
    printf("*First array: \n");
    for (int i = 0; i < line1; i++) // Вывод значений из 1 на экран
    {
        for (int j = 0; j < column1; j++)
        {
            printf("%d ", plisting1[i][j]);
        }
        printf("\n");
    }
    printf("*Second array: \n");
    for (int i = 0; i < line2; i++) // Вывод значений из 2 на экран
    {
        for (int j = 0; j < column2; j++)
        {
            printf("%d ", plisting2[i][j]);
        }
        printf("\n");
    }
    fline = line1 * line2; // Кол-во строк в новой матрице
    fcolumn = column1 * column2; // Кол-во столбцов в новой матрице
    multiply = fline * fcolumn;
    int *pflisting = (int*)malloc(multiply * sizeof(int));
    printf("*Final array: \n");
    for (int i = 0; i < line1; i++) // Заполнение и вывод значений из финальной матрицы
    {
        for (int j = 0; j < line2; j++)
        {
            for (int k = 0; k < column1; k++)
            {
                for (int p = 0; p < column2; p++)
                {
                    var = plisting1[i][k] * plisting2[j][p];
                    pflisting[count] = var;
                    counter++;
                    printf("%d ", pflisting[count]);
                    if (counter == fcolumn)
                    {
                        counter = 0;
                        printf("\n");
                    }
                    count++;
                }
            }
        }
    }
    for (int i = 0; i < line1; i++)
    {
        free(plisting1[i]);
    }
    free(plisting1);
    for (int j = 0; j < line2; j++)
    {
        free(plisting2[j]);
    }
    free(plisting2);
    free(pflisting);
}

int multiply_matrices_2(int flag) // Нахождение произведения Кронекера Копели со случайными числами
{
    int line1, column1, line2, column2, fline, fcolumn, var = 0, count = 0, counter = 0, multiply, score = 0, number;
    int **plisting1, **plisting2, *pflisting;
    printf("*Input dimension for first matrices\n"); // Ввод данных для первой матрицы
    line1 = get_lines();
    column1 = get_columns();
    plisting1 = (int**)malloc(line1 * sizeof(int));
    printf("*Input dimension for second matrices\n"); // Ввод данных для второй таблицы
    line2 = get_lines();
    column2 = get_columns();
    plisting2 = (int**)malloc(line2 * sizeof(int));
    printf("*First array: \n");
    for (int i = 0; i < line1; i++) // Заполнение 1 матрицы случайными числами и вывод на экран
    {
        plisting1[i] = (int*)malloc(column1 * sizeof(int));
        for (int j = 0; j < column1; j++)
        {
            if (flag == 2)
            {
                plisting1[i][j] = rand()%10;
            }
            printf("%d ", plisting1[i][j]);
        }
        printf("\n");
    }
    printf("*Second array: \n");
    for (int i = 0; i < line2; i++) // Заполнение 2 матрицы случайными числами и вывод на экран
    {
        plisting2[i] = (int*)malloc(column2 * sizeof(int));
        for (int j = 0; j < column2; j++)
        {
            if (flag == 2)
            {
                plisting2[i][j] = rand()%10;
            }
            printf("%d ", plisting2[i][j]);
        }
        printf("\n");
    }
    fline = line1 * line2; // Кол-во строк в новой матрице
    fcolumn = column1 * column2; // Кол-во столбцов в новой матрице
    multiply = fline * fcolumn;
    pflisting = (int*)malloc(multiply * sizeof(int));
    printf("*Final array: \n");
    for (int i = 0; i < line1; i++) // Заполнение и вывод значений из финальной матрицы
    {
        for (int j = 0; j < line2; j++)
        {
            for (int k = 0; k < column1; k++)
            {
                for (int p = 0; p < column2; p++)
                {
                    var = plisting1[i][k] * plisting2[j][p];
                    pflisting[count] = var;
                    counter++;
                    printf("%d ", pflisting[count]);
                    if (counter == fcolumn)
                    {
                        counter = 0;
                        printf("\n");
                    }
                    count++;
                }
            }
        }
    }
    for (int i = 0; i < line1; i++)
    {
        free(plisting1[i]);
    }
    free(plisting1);
    for (int j = 0; j < line2; j++)
    {
        free(plisting2[j]);
    }
    free(plisting2);
    free(pflisting);
}

int main() // Основное тело программы
{
    srand(time(NULL));
    bool menu = true;
    int flag, number;
    printf("***Menu***\n");
    printf("*Write 1 to start the program and write your numbers\n");
	printf("*Write 2 to fill an array with random numbers\n");
	printf("*Write 3 to exit the program\n");
    while(menu)
    {
        printf("*Enter an item from the menu: ");
		scanf("%d", &flag);
		system("cls");
        switch(flag) // Проверка на правильность ввода пункта меню
        {
            case 1: // Ручное заполнение массивов числами
                multiply_matrices_1(flag);
                fflush(stdin);
                break;
            case 2: // Рандомное заполнение чисел в массивы
                multiply_matrices_2(flag);
                fflush(stdin);
                break;
            case 3: // Завершение программы
				printf("The program is completed.\n");
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