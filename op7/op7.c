/*
Смолянинов Ярослав Евгеньевич, КИ21-17/2Б, вариант 18
Связь между элементами списков. Две структуры (больные и болезни) осуществлены в виде структур двусвязных списков, 
между которыми осуществляется связь, указанная пользователем.
*/
#include <windows.h>
#include "op7func.h"

int main()
{
    srand(time(NULL));
    enum MenuOptions{addA = 1, addB, showA, showB, deleteA, deleteB, Link, Exit};
    bool menu = true;
    int countA = 0, countB = 0, flag = 0;
    person* AllPersons = NULL;
    disease* Alldisease = NULL;
    while(menu)
    {
        puts("***Menu***");
        puts("*Write 1 to enter the patient's name.");
        puts("*Write 2 to enter the name of the disease.");
        puts("*Write 3 to show patient's added notes.");
        puts("*Write 4 to show disease added notes.");
        puts("*write 5 to delete patient note.");
        puts("*Write 6 to delete disease note.");
        puts("*Write 7 to add link.");
        puts("*Write 8 to exit the program.");
        printf("*Enter an item from the menu: ");
        fflush(stdin);
        scanf("%d", &flag);
        fflush(stdin);
        system("cls");
        switch (flag)
        {
        case addA: // Добавление данных о больном
            check_input_person(&countA, &AllPersons);
            system("cls");
            puts("*Note Patient is added.");
            break;
        case addB:
            check_input_disease(&countB, &Alldisease);
            system("cls");
            puts("*Note disease is added.");
            break;
        case showA: // Вывод структуры с больными на экран
            show_notes_person(countA, &AllPersons);
            break;
        case showB: // Вывод структуры с болезнями на экран
            show_notes_disease(countB, &Alldisease);
            break;
        case deleteA: // Удаление записи больного
            if (countA == 0)
            {
                system("cls");
                puts("*The are no notes.");
            }
            else
            {
                delete_note_person(countA, &AllPersons, countB, &Alldisease);
                countA--;
            }
            break;
        case deleteB: // Удаление записи болезни
            if (countB == 0)
            {
                system("cls");
                puts("*The are no notes.");
            }
            else
            {
                delete_note_disease(countB, &Alldisease, countA, &AllPersons);
                countB--;
            }
            break;
        case Link:
            if (countA == 0 || countB == 0)
            {
                system("cls");
                puts("*There are no records of patients or diseases.");
            }
            else
            {
                add_link_person(countA, &AllPersons, countB, &Alldisease);
            }
            break;
        case Exit: // Завершение программы
            system("cls");
            menu = false;
            while (AllPersons != NULL)
            {
                person* cur = AllPersons;
                free(AllPersons->name);
                free(AllPersons->gender);
                AllPersons = AllPersons->prev;
                free(cur);
            }
            while (Alldisease != NULL)
            {
                disease* cur = Alldisease;
                free(Alldisease->name);
                Alldisease = Alldisease->prev;
                free(cur);
            }
            puts("*The program is end.");
            break;
        default: // Для неправильного ввода
            system("cls");
            printf("*Input error.\n");
        }
    }
}