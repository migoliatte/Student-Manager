#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include "header.h"

void enterToContinue(void);
void flushForFgetc(void);
void fgetsCheck(char *input, char *message, unsigned int size);
int verifInt(void);
void menu(studentList_t *studentList);
void allFree(studentList_t *studentList);

#endif