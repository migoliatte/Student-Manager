#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include "header.h"

subjectList_t *subjectInitialisation(void);
void createNewSubject(studentList_t *studentList);
void addNewSubject(subjectList_t *subjectList, char *subjectName, double subjectNote, double subjectScale);
subject_t *deleteFirstSubject(subjectList_t *start);
void *deleteAllSubject(subjectList_t *start);
void printListSubject(student_t *student);

#endif