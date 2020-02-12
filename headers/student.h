#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "header.h"

studentList_t *studentInitialisation(void);
studentList_t *createNewStudent(studentList_t *studentList);
studentList_t *addNewStudent(studentList_t *studentList, student_t *student);
void deleteFirstStudent(studentList_t *studentList);
void printListStudent(studentList_t *studentList);


void displaySearchedStudent(studentList_t *studentList, char *firstname);
studentList_t *deleteSearchedStudent(studentList_t *studentList, char *etudiantName);

studentList_t *search(studentList_t *studentList, char *etudiantName);

#endif
