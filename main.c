#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./HEADERS/student.h"
#include "./HEADERS/subject.h"
/*
int menu(studentList_t *studentList)
{
    char *choix = (char *)malloc(2 * sizeof(char *));
    do
    {
        printf("=========== Gestionnaire d'students ==========\n");
        printf("1 - Lister les students\n");
        printf("2 - Ajouter un students\n");
        printf("3 - Supprimer un students\n");
        printf("4 - Modifier un student\n");
        printf("5 - Ajouter une note aux students\n");
        printf("6 - Détail sur un students\n");
        printf("7 - Lister les students supprimés\n");
        printf("10 - Quitter\n");
        printf("============================================\n");
        scanf("%s", choix);
        if (atoi(choix) < 1 && atoi(choix) > 10)
        {
            system("clear");
            printf("Veuillez rentrer un chiffre entre 1 et 10 !");
        }
    } while (atoi(choix) < 1 && atoi(choix) > 11);

    switch (atoi(choix))
    {
    case 1:
        system("clear");
        // listStudent(studentList);
        break;
    case 2:
        system("clear");
        //studentList = createStudent(studentList);
        break;
    case 3:
        system("clear");
        //studentList = deleteOneStudent(studentList);
        break;
    case 4:
        system("clear");
        // modifyStudent(studentList);
        break;
    case 5:
        system("clear");
        // addNoteToStudent(studentList);
        break;
    case 6:
        system("clear");
        // listOneStudent(studentList);
        break;
    case 7:
        system("clear");
        // listStudentDeleted(studentList);
        break;
    case 10:
        system("clear");
        free(choix);
        return 0;
    default:
        system("clear");
        printf(" ! ! ! Erreur  Option Invalide ! ! ! \nVeuillez choisir une option valide.\n");
        menu(studentList);
        break;
    }
    menu(studentList);
    free(choix);

    return 0;
}
*/
void enterToContinue()
{
    char enter[3];
    printf("Enter to continue\n");
    fgets(enter, 3, stdin);
    if (strlen(enter) < 3)
        enter[strlen(enter) - 1] = '\0';
    fflush(stdin);
    system("clear");

    //printf("touche : %d & %c\n", enter[strlen(enter) - 1], enter[strlen(enter) - 1]);
}

int main(int argc, char const *argv[])
{
    system("clear");
    studentList_t *studentList = studentInitialisation();
    subjectList_t *subjectList = subjectInitialisation();

    char *firstname = malloc(10);
    char *lastname = malloc(10);
    char *promotion = malloc(10);

    strcpy(firstname, "valentin");
    strcpy(lastname, "Ramond");
    strcpy(promotion, "3A3");

    newStudent(studentList, firstname, lastname, promotion);

    char *name = malloc(10);
    double note = 10.5;
    double scale = 2;
    strcpy(name, "Mathematique");

    newSubject(subjectList, studentList->first, name, note, scale);

    printListStudent(studentList);

    enterToContinue();

    printListSubject(subjectList);
    free(name);
    free(firstname);
    free(lastname);
    free(promotion);
    deleteFirstSubject(subjectList);
    deleteFirstStudent(studentList);
    free(studentList);
    free(subjectList);

    return 0;
}
