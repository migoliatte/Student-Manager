#ifndef _SAVE_H_
#define _SAVE_H_
#include "header.h"


void checkSauvegarde(studentList_t *studentList,int choice);
void displaySubjectListOfIUserInFile(subjectList_t *subjectList,FILE *file);
void chargeFile(char *nameFile);
#endif