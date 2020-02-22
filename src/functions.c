#include "../headers/header.h"

/*Fait une pause dans le programme avant de clear*/
void enterToContinue(void)
{
    char *choix = malloc(3 * sizeof(char));
    printf("Enter to continue : ");
    fgets(choix, 3, stdin);
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
    do
    {
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
    } while (strlen(input) < 1);
}

/*Verification de l'entrée de l'utilisateur afin de s'assurer qu'il s'agit bien d'un int*/
int verifInt(char *message)
{
    char *choix = malloc(3 * sizeof(char));
    do
    {
        fgetsCheck(choix, message, 3);
        if (atoi(choix) < 1 || atoi(choix) > 11)
        {
            fprintf(stdout, "Veuillez rentrer un int !");
        }
    } while (atoi(choix) < 1 || atoi(choix) > 11);
    int number = atoi(choix);
    free(choix);
    return number;
}

double verifDouble(void)
{
    char *choix = malloc(3 * sizeof(char));
    double value;
    char *endptr;
    int isFloat = 1;
    do
    {
        fgetsCheck(choix, "Veuillez choisir la note de l'étudiant ", 6);
        if (choix == NULL)
        {
            return -1; /* Unexpected error */
        }

        value = strtod(choix, &endptr);
        if (((*endptr == '\0') || (isspace(*endptr) != 0)) && value >= 0 && value <= 20)
        {
            isFloat = 0;
            printf("It's a float %.1lf ...\n", value);
        }
        else
        {
            printf("It's NOT a float ...\n");
        }
    } while (isFloat);
    free(choix);
    return value;
}

char **initDoubleChar(int N, int M)
{
    char **tab;
    int i;
    int j;
    tab = malloc(N * sizeof(*tab));
    for (i = 0; i < N; i++)
    {
        tab[i] = malloc(M * sizeof(*tab[i]));
        for (j = 0; j < M; j++)
        {
            strcpy(tab[i],"");
        }
    }
    return tab;
}

void freeDoubleChar(char ***ptab, int N)
{
    if (ptab)
    {
        for (int i = 0; i < N; i++)
        {
            free(ptab[0][i]);
        }
    }
    free(*ptab);
    *ptab = NULL;
}

int **initDoubleInt(int N, int M)
{
    int **tab;
    int i;
    int j;
    tab = malloc(N * sizeof(*tab));
    for (i = 0; i < N; i++)
    {
        tab[i] = malloc(M * sizeof(*tab[i]));
        for (j = 0; j < M; j++)
        {
            tab[i]=0;
        }
    }
    return tab;
}

int freeDoubleInt(int ***ptab, int N)
{
    if (ptab)
    {
        for (int i = 0; i < N; i++)
        {
            free(ptab[0][i]);
        }
    }
    free(*ptab);
    *ptab = NULL;
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
    fprintf(stdout, "7 - Lister les promotions\n");
    fprintf(stdout, "8 - Lister les élèves d'une promotion particulière\n");
    fprintf(stdout, "9 - Ajouter une note à une promotion particulière\n");
    fprintf(stdout, "10 - Lister les moyennes par matières\n");
    fprintf(stdout, "11 - Quitter\n");
    fprintf(stdout, "============================================\n");
    int choix;
    char *inputUser = malloc(SIZE_MAX * sizeof(char));
    choix = verifInt("Veuillez choisir votre choix :");
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
        fgetsCheck(inputUser, "tu cherches qui ?", SIZE_MAX);
        deleteSpecificItem(&studentList, inputUser);
        break;
    case 4:
        system("clear");
        // modifyStudent(studentList);
        break;
    case 5:
        system("clear");
        studentList = createNewSubjectForAllStudent(studentList);
        break;
    case 6:
        system("clear");
        fgetsCheck(inputUser, "tu cherches qui ?", SIZE_MAX);
        displaySearchedStudent(studentList, inputUser);
        break;
    case 7:
        system("clear");
        //fgetsCheck(inputUser, "tu cherches quelle promotion ?", SIZE_MAX);
        listOnePromotion(studentList, inputUser, 2);
        break;
    case 8:
        system("clear");
        fgetsCheck(inputUser, "tu cherches quelle promotion ?", SIZE_MAX);
        listOnePromotion(studentList, inputUser, 3);
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
    if (studentList->student->subjectList->next->subject->name != NULL)
        free(studentList->student->subjectList->next->subject->name);

    if (studentList->student->firstname != NULL)
        free(studentList->student->firstname);

    if (studentList->student->lastname != NULL)
        free(studentList->student->lastname);

    if (studentList->student->promotion != NULL)
        free(studentList->student->promotion);

    if (studentList->student->subjectList != NULL)
        deleteAllSubject(&studentList->student->subjectList);

    if (studentList != NULL)
        free(studentList);
}
