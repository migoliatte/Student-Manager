#include "../HEADERS/student.h"
#include "../HEADERS/subject.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

subjectList_t *subjectInitialisation()
{
    subjectList_t *subjectList = malloc(sizeof(*subjectList));
    if (subjectList == NULL)
    {
        exit(EXIT_FAILURE);
    }
    subjectList->first = NULL;
    subjectList->nbrOfSubject = 0;
    return subjectList;
}

void newSubject(subjectList_t *subjectList, student_t *student, char *subjectName, double subjectNote, double subjectScale)
{
    /* Création du nouvel élément */
    subject_t *subject = malloc(sizeof(*subject));
    if (subjectList == NULL || subject == NULL)
    {
        exit(EXIT_FAILURE);
    }
    subject->name = malloc(10);
    strcpy(subject->name, subjectName);
    subject->note = subjectNote;
    subject->scale = subjectScale;
    subject->student = student;
    subjectList->nbrOfSubject++;

    /* Insertion de l'élément au début de la liste */
    subject->next = subjectList->first;
    subjectList->first = subject;
}

void deleteFirstSubject(subjectList_t *subjectList)
{
    if (subjectList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (subjectList->first != NULL)
    {
        subject_t *toDelete = subjectList->first;
        free(toDelete->name);
        subjectList->first = subjectList->first->next;
        subjectList->nbrOfSubject--;
        free(toDelete);
    }
}

void printListSubject(subjectList_t *subjectList)
{
    if (subjectList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    subject_t *actualSubject = subjectList->first;
    printf("-+-+-+-+-+-+-+ Début printListSubject-+-+-+-+-+-+-+-+-\n");
    while (actualSubject != NULL)
    {
        printf("prenom -> %s / nom -> %s / promotion -> %s / id : %d\n", actualSubject->student->firstname, actualSubject->student->lastname, actualSubject->student->promotion, actualSubject->student->id);
        printf("Nom de matière -> %s / note -> %.2lf / coeff -> %.2lf\n", actualSubject->name, actualSubject->note, actualSubject->scale);
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
        actualSubject = actualSubject->next;
    }
    printf("-+-+-+-+-+-+-+ Début printListSubject-+-+-+-+-+-+-+-+-\n");
}
