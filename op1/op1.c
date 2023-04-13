/*
Смолянинов Ярослав Евгеньевич, КИ21-17/2Б, вариант 18
Необходимо выполнить плавную сортировку для переданного массива
*/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

int get_size(void)
{
	int size = 0;
	while (size <= 0)
	{
		printf("*Please write the number of numbers for your list: ");
		scanf("%d", &size);
		system("cls");
		if (size <= 0)
		{
			system("cls");
			printf("*Input error, try again. \n");
			fflush(stdin);
		}
	}
	return size;
}

int check_input(void)
{
	char input[100];
	int number;
	scanf("%s", &input);
	while (sscanf(input, "%d", &number) != 1)
	{
		fflush(stdin);
		printf("Enter an integer: ");
		scanf("%s", &input);
	}
	return number;
}

void SmoothSort(int *listing, int len) // Основная функция, сортирующая массив 
{
	int time_list, final_list, i, j, k, count, max, elem, counter, maxim, maxim1, maxim2, variable, score = 0;
	int *ptime_list, *pfinal_list;
	ptime_list = (int*)malloc(len * sizeof(int));
	pfinal_list = (int*)malloc(len * sizeof(int));
	ptime_list[0] = listing[0];
	ptime_list[1] = listing[1];
	if (len == 1) // Проверка на ввод массива длиной 1
	{
		printf("*Your sorted array: \n");
		printf("%d ", listing[0]);
		printf("\n");
	}
	else if (len == 2) // Проверка на ввод массива длиной 2
	{
		if (listing[0] > listing[1])
		{
			printf("*Your sorted array: \n");
			printf("%d ", listing[1]);
			printf("%d ", listing[0]);
			printf("\n");
		}
		else
		{
			printf("*Your sorted array: \n");
			printf("%d ", listing[0]);
			printf("%d ", listing[1]);
			printf("\n");
		}
	}
	else
	{
		for (i = 2; i < len; i++) // Постройка дерева, максимальный элемент переносится в конец
		{
			ptime_list[i] = listing[i];
			score = i;
			for (score = i; score >= 2; score -= 2)
			{
				if ((ptime_list[score] < ptime_list[score-1]) || (ptime_list[score] < ptime_list[score-2]))
				{
					count = ptime_list[score];
					if (ptime_list[score-1] < ptime_list[score-2])
					{
						max = ptime_list[score-2];
						ptime_list[score-2] = count;
					}
					else
					{
						max = ptime_list[score-1];
						ptime_list[score-1] = count;
					}
					ptime_list[score] = max;
				}
				else
				{
					continue;
				}
				if (ptime_list[score - 2] >= ptime_list[score - 1])
				{	
					elem = ptime_list[score - 2];
					ptime_list[score - 2] = ptime_list[score - 1];
					ptime_list[score - 1] = elem;
				}
			}
		}
		counter = len;
		for (j = 0; j < (len - 3); j++) // Разбор кучи до 3 оставшихся элементов
		{
			pfinal_list[j] = ptime_list[counter-1];
			counter--;
			score = (len - 1);
			for ((score - j); score >= 2; score -= 2)
			{
				if ((ptime_list[score] < ptime_list[score-1]) || (ptime_list[score] < ptime_list[score-2]))
				{
					count = ptime_list[score];
					if (ptime_list[score-1] < ptime_list[score-2])
					{
						max = ptime_list[score-2];
						ptime_list[score-2] = count;
					}
					else
					{
						max = ptime_list[score-1];
						ptime_list[score-1] = count;
					}
					ptime_list[score] = max;
				}
				else
				{
					continue;
				}
				if (ptime_list[score - 2] >= ptime_list[score - 1])
				{	
					elem = ptime_list[score - 2];
					ptime_list[score - 2] = ptime_list[score - 1];
					ptime_list[score - 1] = elem;
				}
			}
		}
		maxim = ptime_list[0];
		maxim1 = ptime_list[1];
		maxim2 = ptime_list[2];

		if (maxim > maxim1 && maxim > maxim2) // Разборка оставшихся элементов
		{
			pfinal_list[len - 3] = maxim;
			if (maxim1 > maxim2)
			{
				pfinal_list[len - 2] = maxim1;
				pfinal_list[len - 1] = maxim2;
			}
			else
			{
				pfinal_list[len - 2] = maxim2;
				pfinal_list[len - 1] = maxim1;
			}
		}
		else if (maxim1 > maxim && maxim1 > maxim2)
		{
			pfinal_list[len - 3] = maxim1;
			if (maxim > maxim2)
			{
				pfinal_list[len - 2] = maxim;
				pfinal_list[len - 1] = maxim2;
			}
			else
			{
				pfinal_list[len - 2] = maxim2;
				pfinal_list[len - 1] = maxim;
			}
		}
		else
		{
			pfinal_list[len - 3] = maxim2;
			if (maxim > maxim1)
			{
				pfinal_list[len - 2] = maxim;
				pfinal_list[len - 1] = maxim1;
			}
			else
			{
				pfinal_list[len - 2] = maxim1;
				pfinal_list[len - 1] = maxim;
			}
		}
		printf("*Your sorted array: \n");
		for (k = len-1; k >= 0; k--) // Вывод отсортированного массива
		{
			printf("%d ", pfinal_list[k]);
		}
		printf("\n");
		free(ptime_list);
		free(pfinal_list);
	}
}

int main(void) // Основное тело программы
{
	srand(time(NULL));
    int i, k, number, flag;
    int *plisting;
	bool menu = true;
	printf("*Write 1 to start the program and write your numbers\n");
	printf("*Write 2 to fill an array with random numbers\n");
	printf("*Write 3 to exit the program\n");
	while (menu)
	{
		printf("*Enter an item from the menu: ");
		scanf("%d", &flag);
		system("cls");
		switch (flag) // Проверка на правильность ввода пункта меню
		{
			case 1: // Ручной ввод чисел пользователем в массив
				number = get_size();
				plisting = (int*)malloc(number * sizeof(int));
				printf("*Please, write your numbers: \n");
				for (k = 0; k < number; k++)
				{
					printf("Array[%d] = ", k);
					plisting[k] = check_input();
				}
				SmoothSort(plisting, number);
				free(plisting);
				break;
			case 2: // Рандомное заполнение чисел в массив
				number = get_size();
				plisting = (int*)malloc(number * sizeof(int));
				printf("*First array: \n");
				for (k = 0; k < number; k++) // Заполнение массива случайными числами
				{
					plisting[k] = rand()%100;
					printf("%d ", plisting[k]);
				}
				printf("\n");
				SmoothSort(plisting, number);
				free(plisting);
				break;
			case 3: // Завершение программы
				printf("The program is completed.\n");
				menu = false;
				fflush(stdin);
				break;
			default: // Ошибочный ввод
				puts("*Input error, try again.");
				break;
		}
		
	}
	return 0;
}