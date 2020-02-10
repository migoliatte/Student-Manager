#ifndef _SUBJECT_H_
#define _SUBJECT_H_

typedef struct subject_s
{
    char *name;
    double note;
    double scale;
    struct subject_s *next;
    student_t *student;
} subject_t;

typedef struct
{
    int nbrOfSubject;
    subject_t *first;
} subjectList_t;

subjectList_t *subjectInitialisation();
void newSubject(subjectList_t *subjectList, student_t *student, char *subjectName, double subjectNote, double subjectScale);
void deleteFirstSubject(subjectList_t *subjectList);
void printListSubject(subjectList_t *subjectList);

#endif
