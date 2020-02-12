#ifndef _SUBJECT_H_
#define _SUBJECT_H_

typedef struct subject_s
{
    char *name;
    double note;
    double scale;
    struct subject_s *next;
} subject_t;

typedef struct subjectList_s
{
    int nbrOfSubject;
    subject_t *first;
} subjectList_t;

subjectList_t *subjectInitialisation(void);
void addNewSubject(subjectList_t *subjectList, char *subjectName, double subjectNote, double subjectScale);
subject_t *deleteFirstSubject(subjectList_t *start);
void *deleteAllSubject(subjectList_t *start);
void printListSubject(subjectList_t *subjectList);

#endif