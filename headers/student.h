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
char *  deleteSpecificItem(studentList_t **head, char *val);
char *modifySpecificItem(studentList_t **studentList, char *val);
studentList_t *orderStudent(studentList_t *studentList);
void listAllPromotion(studentList_t *studentList);
void listOnePromotion(studentList_t *studentList, char *namePromotion, int type);
void displaySearchedStudentForModification(studentList_t *studentList, char *etudiantName);
char *modificationList(studentList_t **studentList, int choice);


#endif