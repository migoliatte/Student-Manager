#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include "header.h"

void enterToContinue(void);
void flushForFgetc(void);
void fgetsCheck(char *input, char *message, unsigned int size);
int verifInt(char *message);
double verifDouble(void);
void menu(studentList_t *studentList);
void allFree(studentList_t *studentList);
void freeDoubleChar(char ***ptab, int N);
char **initDoubleChar(int N, int M);
void freeDoubleInt(int ***ptab, int N);
int **initDoubleInt(int N, int M);
double **initDoubleDouble(int N, int M);
void freeDoubleDouble(double ***ptab, int N);
#endif
