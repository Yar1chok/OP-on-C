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

typedef struct person // Записи больных
{
    char *name;
    char *surname;
    char *patronymic;
    int day;
    int month;
    int year;
    char *gender;
    int *connection;
    int enumeratorA;
    struct person* next;
    struct person* prev;
} person;

typedef struct disease // Записи болезней
{
    char *name;
    int length;
    int severity;
    int *linking;
    int enumeratorB;
    struct disease* next;
    struct disease* prev;
} disease;

enum ChoicePerson{namePerson = 1, surname, patronymic, day, month, year, gender}; // Параметры для записей больных

enum ChoiceDisease{nameDisease = 1, length, severity}; // Параметры для записей болезней

void check_input_person(int* count, person** AllPersons);
void check_input_disease(int *count, disease** AllDisease);
void show_notes_person(int count, person** AllPersons);
void show_notes_disease(int count, disease** AllDisease);
void delete_note_person(int countA, person** AllPersons, int countB, disease** AllDisease);
void delete_note_disease(int countB, disease** AllDisease, int countA, person** AllPerson);
void swap_places_person(person* elem1, person* elem2);
void swap_places_disease(disease* elem1, disease* elem2);
void add_link_person(int countA, person** AllPersons, int countB, disease** AllDisease);
