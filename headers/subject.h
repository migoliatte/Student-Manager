#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include "header.h"

subjectList_t *subjectInitialisation(void);
studentList_t *createNewSubjectForAllStudent(studentList_t *studentList);
subjectList_t *createNewSubject(studentList_t *studentList);
subjectList_t *addNewSubject(subjectList_t *subjectList, subject_t *subject);
void deleteFirstSubject(subjectList_t *subjectList);
void deleteAllSubject(subjectList_t **subjectList);
void printListSubject(subjectList_t *subjectList);

void printListSubjectForModification(subjectList_t *subjectList);
char *modificationSubject(subjectList_t *subjectList, int choice);

#endif