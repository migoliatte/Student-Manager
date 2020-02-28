#include "../headers/header.h"

/*Initialise la structure subjectList_t*/
subjectList_t *subjectInitialisation(void)
{
    subjectList_t *subjectList = malloc(sizeof(*subjectList));
    if (subjectList == NULL)
    {
        exit(EXIT_FAILURE);
    }
    subjectList->next = NULL;
    subjectList->subject = NULL;
    subjectList->nbr = 0;
    return subjectList;
}

/*permet de rentrer une note differente ( matiere / note / coeff ) à tous les eleves */
studentList_t *createNewSubjectForAllStudent(studentList_t *studentList)
{
    studentList_t *actualStudent = studentList;
    fprintf(stdout, "-+-+-+-+-+-+-+ Début createNewSubjectForAllStudent-+-+-+-+-+-+-+-+-\n");
    while (actualStudent->next)
    {
        fprintf(stdout, "Ajout d'une note à %s %s de la classe %s\n", actualStudent->student->firstname, actualStudent->student->lastname, actualStudent->student->promotion);

        actualStudent->student->subjectList = createNewSubject(actualStudent->student);
        enterToContinue();
        if (actualStudent->next->next)
        {
            fprintf(stdout, "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
        }
        actualStudent = actualStudent->next;
    }
    fprintf(stdout, "-+-+-+-+-+-+-+ Fin createNewSubjectForAllStudent-+-+-+-+-+-+-+-+-\n");
    return studentList;
}

/*Récuperation des informations de la matière ajouté par l'utilisateur*/
subjectList_t *createNewSubject(student_t *actualStudent)
{
    if (actualStudent)
    {
        char *subjectName = malloc(SIZE_MAX * sizeof(char));
        if (subjectName == NULL)
        {
            exit(EXIT_FAILURE);
        }
        double subjectNote = verifDouble();
        int subjectScale = verifInt("Coefficiant de la matière : ");
        fgetsCheck(subjectName, "\nVeuillez rentrer le nom de la matière", SIZE_MAX);

        /* Création du nouvel élément */
        subject_t *subject = malloc(sizeof(*subject));
        if (subject == NULL)
        {
            exit(EXIT_FAILURE);
        }

        subject->name = malloc(SIZE_MAX * sizeof(char));
        strcpy(subject->name, subjectName);
        subject->note = subjectNote;
        subject->scale = subjectScale;

        subject->id = actualStudent->subjectList->nbr + 1;
        actualStudent->subjectList = addNewSubject(actualStudent->subjectList, subject);
        if (actualStudent->subjectList->subject)
        {
            actualStudent->subjectList->nbr = actualStudent->subjectList->subject->id;
        }
        free(subjectName);
        return actualStudent->subjectList;
    }
    else
    {
        printf("veuillez creer des étudiants !\n");
        return NULL;
    }
}

/*Ajoute la matière dans la structure subjectList_t en fonction des données de l'utilisateur*/
subjectList_t *addNewSubject(subjectList_t *subjectList, subject_t *subject)
{
    if (subjectList == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        subjectList_t *new = malloc(sizeof(subjectList_t));
        new->subject = subject;
        new->next = subjectList;
        return new;
    }
}

/*Supprime et libère dans la mémoire la première matière de subjectList_t d'un étudiant */
void deleteFirstSubject(subjectList_t *subjectList)
{
    if (subjectList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (subjectList->subject != NULL)
    {
        subject_t *toDelete = subjectList->subject;
        free(toDelete->name);
        subjectList = subjectList->next;
        free(toDelete);
    }
}

/*Supprime et libère dans la mémoire toutes les matière de subjectList_t d'un étudiant*/
void deleteAllSubject(subjectList_t **subjectList)
{
    subjectList_t *actualSubject = *subjectList;
    while (actualSubject != NULL)
    {
        subjectList_t *temp = actualSubject;
        actualSubject = actualSubject->next;
        deleteFirstSubject(temp);
    }
    *subjectList = NULL;
}

/*Permet d'afficher toutes les notes et les informations d'un étudiant*/
void printListSubject(subjectList_t *subjectList)
{
    if (subjectList == NULL)
    {
        fprintf(stdout, "-+-+-+-+-+-+-+ Cet étudiant n'a pas de notes -+-+-+-+-+-+-+-+-\n");
    }
    else
    {
        if (subjectList->subject == NULL)
        {
            fprintf(stdout, "-+-+-+-+-+-+-+ Veuillez créer des notes -+-+-+-+-+-+-+-+-\n");
        }
        else
        {
            double *notes = malloc(10 * subjectList->nbr * sizeof(int));
            int *scale = malloc(10 * subjectList->nbr * sizeof(int));
            char **name = initDoubleChar(10 * subjectList->nbr, SIZE_MAX);
            int i = 0;
            int exist = 0;
            double moyenneAll = 0;
            int dividend = 0;
            int *nbrOfEach = malloc(10 * subjectList->nbr * sizeof(int));
            char **nameList = initDoubleChar(10 * subjectList->nbr, SIZE_MAX);
            double *moyenneByName = malloc(10 * subjectList->nbr * sizeof(double));
            int x = 0;
            for (int a = 0; a < subjectList->nbr; a++)
            {
                notes[a] = 0;
                nbrOfEach[a] = 0;
                scale[a] = 0;
                moyenneByName[a] = 0;
            }
            subjectList_t *actualSubject = subjectList;
            while (actualSubject->next)
            {
                notes[i] = actualSubject->subject->note;
                scale[i] = actualSubject->subject->scale;
                strcpy(name[i], actualSubject->subject->name);
                fprintf(stdout, "notes : %.2lf , coeff -> %d matière -> %s \n", notes[i], scale[i], name[i]);
                i++;
                if (actualSubject->next->next)
                {
                    fprintf(stdout, "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
                }
                actualSubject = actualSubject->next;
            }
            fprintf(stdout, "-+-+-+-+-+-+-+ Fin Affichage globale-+-+-+-+-+-+-+-+-\n");
            fprintf(stdout, "-+-+-+-+-+-+-+ Début Moyenne générale + Moyenne par matière-+-+-+-+-+-+-+-+-\n");

            for (int j = 0; j < i; j++)
            {
                moyenneAll += notes[j] * scale[j];
                dividend += 1 * scale[j];
                for (int z = 0; z < j; z++)
                {
                    if (strcmp(name[j], nameList[z]) == 0)
                    {
                        exist = 1;
                        nbrOfEach[z] += 1 * scale[j];
                        moyenneByName[z] += notes[j] * scale[j];
                    }
                }
                if (exist == 0)
                {
                    moyenneByName[x] += notes[j] * scale[j];
                    strcpy(nameList[x], name[j]);
                    nbrOfEach[x] += 1 * scale[j];
                    x++;
                }
                exist = 0;
            }

            fprintf(stdout, "Moyenne de l'eleve : %.2lf\n", moyenneAll / dividend);
            for (int z = 0; z < x; z++)
            {

                fprintf(stdout, "Moyenne de l'eleve dans la matiere : %s est : %.2lf\n", name[z], moyenneByName[z] / nbrOfEach[z]);
            }
            fprintf(stdout, "-+-+-+-+-+-+-+ Fin Moyenne générale + Moyenne par matière-+-+-+-+-+-+-+-+-\n");

            moyenneAll /= dividend;
            free(notes);
            free(scale);
            free(moyenneByName);
            free(nbrOfEach);
            freeDoubleChar(&name, subjectList->nbr);
            freeDoubleChar(&nameList, subjectList->nbr);
        }
    }
}

/*Permet l'affichage des notes pour la modification*/
void printListSubjectForModification(subjectList_t *subjectList)
{
    int choice;
    if (subjectList == NULL)
    {
        fprintf(stdout, "-+-+-+-+-+-+-+ Cet étudiant n'a pas de notes -+-+-+-+-+-+-+-+-\n");
    }
    else
    {
        if (subjectList->subject == NULL)
        {
            fprintf(stdout, "-+-+-+-+-+-+-+ Veuillez créer des notes -+-+-+-+-+-+-+-+-\n");
        }
        else
        {
            subjectList_t *actualSubject = subjectList;
            fprintf(stdout, "\n-+-+-+-+-+-+-+ Début printListSubject-+-+-+-+-+-+-+-+-\n");
            while (actualSubject->next)
            {
                fprintf(stdout, "Id = %d \n", actualSubject->subject->id);
                fprintf(stdout, "Nom de matière -> %s \n", actualSubject->subject->name);
                fprintf(stdout, "Note -> %.2lf \n", actualSubject->subject->note);
                fprintf(stdout, "Coeff -> %d\n", actualSubject->subject->scale);

                if (actualSubject->next->next)
                {
                    fprintf(stdout, "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
                }
                actualSubject = actualSubject->next;
            }
            fprintf(stdout, "-+-+-+-+-+-+-+ Fin printListSubject-+-+-+-+-+-+-+-+-\n");

            choice = verifInt("Quelle note voulez vous modifiez ? Choisissez un ID : ");
            modificationSubject(subjectList, choice);
        }
    }
}

/*Modifie la note choisit*/
char *modificationSubject(subjectList_t *subjectList, int choice)
{
    char *replaceName = malloc(SIZE_MAX * sizeof(char));
    subjectList_t *actualSubject = subjectList;
    while (actualSubject->next)
    {
        if (actualSubject->subject->id == choice)
        {

            //matière
            fgetsCheck(replaceName, "Le nom de la nouvelle matière : \n", SIZE_MAX);
            strcpy(actualSubject->subject->name, replaceName);
            printf("Le nom a été modifié \n");

            //note
            double note = verifDouble();
            actualSubject->subject->note = note;
            printf("La note a été modifié \n");

            //coeff
            int newCoeff = verifInt("Le nouveau coeff est  : ");
            actualSubject->subject->scale = newCoeff;
            printf("Le coeff a été modifié \n");
        }
        actualSubject = actualSubject->next;
    }

    return "test";
}

/*Permet d'ajouter*/
void printAllMoyenneBySubject(studentList_t *studentList)
{
    fprintf(stdout, "-+-+-+-+-+-+-+ Affichage des moyennes de tous les étudiants par matières -+-+-+-+-+-+-+-+-\n");

    if (studentList == NULL || studentList->student == NULL)
    {
        fprintf(stdout, "-+-+-+-+-+-+-+ Veuillez créer des étudiants -+-+-+-+-+-+-+-+-\n");
    }
    else
    {
        int existSubject = 0;
        studentList_t *actualSubject = studentList;
        while (actualSubject->student)
        {
            if (actualSubject->student->subjectList->subject == NULL)
            {
            }
            else
            {
                existSubject = 1;
            }
            actualSubject = actualSubject->next;
        }
        if (existSubject == 0)
        {
            fprintf(stdout, "-+-+-+-+-+-+-+ Aucun étudiant n'a pas de notes -+-+-+-+-+-+-+-+-\n");
            return;
        }

        double *notes = malloc(10 * studentList->student->subjectList->nbr * sizeof(int));
        int *scale = malloc(10 * studentList->student->subjectList->nbr * sizeof(int));
        char **name = initDoubleChar(10 * studentList->student->subjectList->nbr, SIZE_MAX);
        int i = 0;
        int exist = 0;
        double moyenneAll = 0;
        int dividend = 0;
        int *nbrOfEach = malloc(10 * studentList->student->subjectList->nbr * sizeof(int));
        char **nameList = initDoubleChar(10 * studentList->student->subjectList->nbr, SIZE_MAX);
        double *moyenneByName = malloc(10 * studentList->student->subjectList->nbr * sizeof(double));
        int x = 0;
        for (int a = 0; a < studentList->student->subjectList->nbr; a++)
        {
            notes[a] = 0;
            nbrOfEach[a] = 0;
            scale[a] = 0;
            moyenneByName[a] = 0;
        }
        studentList_t *actualStudent = studentList;
        while (actualStudent->student)
        {
            subjectList_t *actualSubject = actualStudent->student->subjectList;
            while (actualSubject->next)
            {
                notes[i] = actualSubject->subject->note;
                scale[i] = actualSubject->subject->scale;
                strcpy(name[i], actualSubject->subject->name);
                //     printf("recuperation des infos \n");
                //    printf("notes[i %d] : %lf, scale[i %d] : %d, name[i %d] : %s\n", i, notes[i], i, scale[i], i, name[i]);
                i++;
                actualSubject = actualSubject->next;
            }
            actualStudent = actualStudent->next;
        }
        for (int j = 0; j < i; j++)
        {
            moyenneAll += notes[j] * scale[j];
            dividend += 1 * scale[j];
            for (int z = 0; z < j; z++)
            {
                if (strcmp(name[j], nameList[z]) == 0)
                {
                    printf("exist : \n");

                    exist = 1;
                    nbrOfEach[z] += 1 * scale[j];
                    moyenneByName[z] += notes[j] * scale[j];
                }
            }
            if (exist == 0)
            {
                moyenneByName[x] += notes[j] * scale[j];
                strcpy(nameList[x], name[j]);
                nbrOfEach[x] = 1 * scale[j];
                x++;
            }

            exist = 0;
        }
        moyenneAll /= dividend;
        fprintf(stdout, "Moyenne générale est : %.2lf\n", moyenneAll);

        for (int z = 0; z < x; z++)
        {

            fprintf(stdout, "Moyenne de l'eleve dans la matiere : %s est : %.2lf\n", nameList[z], moyenneByName[z] / nbrOfEach[z]);
        }

        free(notes);
        free(scale);
        free(moyenneByName);
        free(nbrOfEach);
        freeDoubleChar(&name, studentList->student->subjectList->nbr);
        freeDoubleChar(&nameList, studentList->student->subjectList->nbr);
    }
}