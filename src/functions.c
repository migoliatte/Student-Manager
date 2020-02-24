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
        if (atoi(choix) < 1 || atoi(choix) > 20)
        {
            fprintf(stdout, "Veuillez rentrer un int !");
        }
    } while (atoi(choix) < 1 || atoi(choix) > 20);
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
        }
        else
        {
            printf("veuillez rentrer un float ! ...\n");
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
            strcpy(tab[i], "");
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
            tab[i] = 0;
        }
    }
    return tab;
}

void freeDoubleInt(int ***ptab, int N)
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

double **initDoubleDouble(int N, int M)
{
    double **tab;
    int i;
    int j;
    tab = malloc(N * sizeof(*tab));
    for (i = 0; i < N; i++)
    {
        tab[i] = malloc(M * sizeof(*tab[i]));
        for (j = 0; j < M; j++)
        {
            tab[i] = 0;
        }
    }
    return tab;
}

void freeDoubleDouble(double ***ptab, int N)
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
    fprintf(stdout, "11 - Charger sauvegarde\n");
    fprintf(stdout, "12 - Quitter\n");
    fprintf(stdout, "============================================\n");
    int choix;
    char *inputUser = malloc(SIZE_MAX * sizeof(char));
    int inputInt = 0;
    choix = verifInt("Veuillez choisir votre choix :");
    switch (choix)
    {
    case 1:
        system("clear");
        allTypeOfDisplayStudent(studentList, "", 1);
        break;
    case 2:
        system("clear");
        studentList = createNewStudent(studentList);
        break;
    case 3:
        system("clear");
        inputInt = verifInt("Suppression de l'élève numéro : ");
        printf("%s \n", deleteSpecificItem(&studentList, inputInt));
        break;
    case 4:
        system("clear");
        inputInt = verifInt("Modification de l'élève numéro : ");
        displaySearchedStudentForModification(studentList, inputInt);
        break;
    case 5:
        system("clear");
        studentList = createNewSubjectForAllStudent(studentList);
        break;
    case 6:
        system("clear");
        inputInt = verifInt("Détails de l'élève numéro : ");
        displaySearchedStudent(studentList, inputInt);
        break;
    case 7:
        system("clear");
        allTypeOfDisplayStudent(studentList, inputUser, 2);
        break;
    case 8:
        system("clear");
        fgetsCheck(inputUser, "tu cherches quelle promotion ?", SIZE_MAX);
        allTypeOfDisplayStudent(studentList, inputUser, 3);
        break;
    case 9:
        system("clear");
        fgetsCheck(inputUser, "tu cherches quelle promotion ?", SIZE_MAX);
        insertNoteForOnePromotion(studentList, inputUser);
        break;
    case 10:
        system("clear");
        printAllMoyenneBySubject(studentList);
        break;
    case 11:
        system("clear");
        fgetsCheck(inputUser, "Donne moi le nom du fichier avec l'extension :", SIZE_MAX);
        chargeFile(inputUser);
        break;
    case 12:
        checkSauvegarde(studentList, verifInt("Voulez vous vraiment fermer le programme sans sauvaugarder ? \n 1 pour sauv et 2 pour quitter :"));
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

studentList_t *easyAddSubject(studentList_t *studentList, char *name, double note)
{
    subject_t *subject = malloc(sizeof(*subject));

    subject->name = malloc(SIZE_MAX * sizeof(char));
    strcpy(subject->name, name);
    subject->note = note;
    subject->scale = 2;
    subject->id = studentList->student->subjectList->nbr + 1;
    studentList->student->subjectList = addNewSubject(studentList->student->subjectList, subject);
    if (studentList->student->subjectList->subject)
    {
        studentList->student->subjectList->nbr = studentList->student->subjectList->subject->id;
    }

    return studentList;
}
studentList_t *easyAddStudent(studentList_t *studentList, char *name)
{
    student_t *student = malloc(sizeof(*student));

    student->firstname = malloc(SIZE_MAX * sizeof(char));
    student->lastname = malloc(SIZE_MAX * sizeof(char));
    student->promotion = malloc(SIZE_MAX * sizeof(char));
    strcpy(student->firstname, name);
    strcpy(student->lastname, name);
    strcpy(student->promotion, name);

    student->subjectList = subjectInitialisation();
    student->id = studentList->nbr + 1;
    studentList = addNewStudent(studentList, student);
    if (studentList->student)
    {
        studentList->nbr = studentList->student->id;
    }
    return studentList;
}

studentList_t *initForTest(studentList_t *studentList)
{

    studentList = easyAddStudent(studentList, "val");
    studentList = easyAddSubject(studentList, "math", 2);
    studentList = easyAddSubject(studentList, "français", 4);
    studentList = easyAddSubject(studentList, "math", 6);
        studentList = easyAddStudent(studentList, "mac");

    studentList = easyAddSubject(studentList, "truc", 12);
    studentList = easyAddSubject(studentList, "français", 13);
    studentList = easyAddSubject(studentList, "truc", 17);
            studentList = easyAddStudent(studentList, "gana");

    studentList = easyAddSubject(studentList, "math", 20);
    studentList = easyAddSubject(studentList, "machin", 1);

    return studentList;
}

