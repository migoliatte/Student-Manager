#include "../headers/header.h"

/*Fait une pause dans le programme avant de clear*/
void enterToContinue(void)
{
    char *choix = malloc(3 * sizeof(char));
    fgetsCheck(choix, "\nEnter to continue ", 3);
    free(choix);
    system("clear");
}
/*Purge le stdin */
void flushForFgetc(void)
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/*Recuperation des données via stdin + verification*/
void fgetsCheck(char *input, char *message, unsigned int size)
{
    char *positionEntree = NULL;
    fprintf(stdout, "%s : ", message);
    if (fgets(input, size, stdin) != NULL)
    {
        positionEntree = strchr(input, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            flushForFgetc();
        }
    }
    else
    {
        flushForFgetc();
    }
}

/*Verification de l'entrée de l'utilisateur afin de s'assurer qu'il s'agit bien d'un int*/
int verifInt(void)
{
    char *choix = malloc(3 * sizeof(char));
    do
    {
        fgetsCheck(choix, "Veuillez choisir votre choix ", 3);
        if (atoi(choix) < 1 || atoi(choix) > 11)
        {
            fprintf(stdout, " >> Veuillez rentrer un chiffre entre 1 et 10 ! ");
        }
    } while (atoi(choix) < 1 || atoi(choix) > 11);
    int number = atoi(choix);
    free(choix);
    return number;
}

/*Affiche et traite le menu*/
void menu(studentList_t *studentList)
{
    enterToContinue();
    fprintf(stdout, "=========== Gestionnaire d'étudiants ==========\n");
    fprintf(stdout, "1 - Lister les étudiants\n");
    fprintf(stdout, "2 - Ajouter un étudiant\n");
    fprintf(stdout, "3 - Supprimer un étudiant\n");
    fprintf(stdout, "4 - Modifier un étudiant\n");
    fprintf(stdout, "5 - Ajouter une note aux étudiants\n");
    fprintf(stdout, "6 - Détail sur un étudiant\n");
    fprintf(stdout, "7 - Lister les étudiants supprimés\n");
    fprintf(stdout, "10 - Quitter\n");
    fprintf(stdout, "============================================\n");
    int choix;
    char * inputUser=malloc(SIZE_MAX * sizeof(char));
    choix = verifInt();
    switch (choix)
    {
    case 1:
        system("clear");
        printListStudent(studentList);
        break;
    case 2:
        system("clear");
        studentList = createNewStudent(studentList);
        break;
    case 3:
        system("clear");
//        fgetsCheck(inputUser, "tu cherches qui ?", SIZE_MAX);
      //  studentList = deleteSearchedStudent(studentList, searchStudent());
        break;
    case 4:
        system("clear");
        // modifyStudent(studentList);
        break;
    case 5:
        system("clear");
        createNewSubject(studentList);
        break;
    case 6:
        system("clear");
        fgetsCheck(inputUser, "tu cherches qui ?", SIZE_MAX);
        displaySearchedStudent(studentList, inputUser);
        break;
    case 7:
        system("clear");
        // listStudentDeleted(studentList);
        break;
    case 10:
        printf("bonjour %d", SIZE_MAX);
        return;
    default:
        system("clear");
        fprintf(stdout, " ! ! ! Erreur  Option Invalide ! ! ! \nVeuillez choisir une option valide.\n");
        menu(studentList);
        break;
    }
    menu(studentList);
}

void allFree(studentList_t *studentList)
{
    if (studentList->student->subjectList->first->name != NULL)
        free(studentList->student->subjectList->first->name);

    if (studentList->student->firstname != NULL)
        free(studentList->student->firstname);

    if (studentList->student->lastname != NULL)
        free(studentList->student->lastname);

    if (studentList->student->promotion != NULL)
        free(studentList->student->promotion);

    if (studentList->student->subjectList != NULL)
        deleteAllSubject(studentList->student->subjectList);

    if (studentList != NULL)
        free(studentList);
}
