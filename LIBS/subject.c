#include "../HEADERS/header.h"

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

void newSubject(subjectList_t *subjectList, char *subjectName, double subjectNote, double subjectScale)
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
    subjectList->nbrOfSubject++;

    /* Insertion de l'élément au début de la liste */
    subject->next = subjectList->first;
    subjectList->first = subject;
}

subject_t *deleteFirstSubject(subjectList_t *start)
{
    subject_t *toDelete = start->first;
    if (start->first != NULL)
    {
        start->first = start->first->next;
        free(toDelete);
    }
    return start->first;
}

void *deleteAll(subjectList_t *start)
{
    while (start != NULL)
        start->first = deleteFirstSubject(start);
    return NULL;
}
/*
void printListSubject(subjectList_t *subjectList)
{
    if (subjectList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    subject_t *actualSubject = subjectList->first;
    fprintf(stdout,"-+-+-+-+-+-+-+ Début printListSubject-+-+-+-+-+-+-+-+-\n");
    while (actualSubject != NULL)
    {
        //fprintf(stdout,"prenom -> %s / nom -> %s / promotion -> %s / id : %d\n", actualSubject->student->firstname, actualSubject->student->lastname, actualSubject->student->promotion, actualSubject->student->id);
        //fprintf(stdout,"Nom de matière -> %s / note -> %.2lf / coeff -> %.2lf\n", actualSubject->name, actualSubject->note, actualSubject->scale);
        fprintf(stdout,"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
        actualSubject = actualSubject->next;
    }
    fprintf(stdout,"-+-+-+-+-+-+-+ Fin printListSubject-+-+-+-+-+-+-+-+-\n");
}
*/
