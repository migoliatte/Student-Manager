#include "../HEADERS/student.h"
#include "../HEADERS/subject.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

studentList_t *studentInitialisation()
{
  studentList_t *liste = malloc(sizeof(*liste));
  if (liste == NULL)
  {
    exit(EXIT_FAILURE);
  }
  liste->first = NULL;
  liste->nbrOfStudent = 0;
  return liste;
}

void newStudent(studentList_t *studentList, char *studentFirstname, char *studentLastname, char *studentPromotion)
{
  /* Création du nouvel élément */
  student_t *student = malloc(sizeof(*student));
  if (studentList == NULL || student == NULL)
  {
    exit(EXIT_FAILURE);
  }
  studentList->nbrOfStudent++;
  student->firstname = malloc(10);
  student->lastname = malloc(10);
  student->promotion = malloc(10);

  strcpy(student->firstname, studentFirstname);
  strcpy(student->lastname, studentLastname);
  strcpy(student->promotion, studentPromotion);
  student->id = studentList->nbrOfStudent;

  /* Insertion de l'élément au début de la liste */
  student->next = studentList->first;
  studentList->first = student;
}

void deleteFirstStudent(studentList_t *studentList)
{
  if (studentList == NULL)
  {
    exit(EXIT_FAILURE);
  }

  if (studentList->first != NULL)
  {
    student_t *toDelete = studentList->first;
    free(toDelete->firstname);
    free(toDelete->lastname);
    free(toDelete->promotion);
    studentList->first = studentList->first->next;
    studentList->nbrOfStudent--;
    free(toDelete);
  }
}

void printListStudent(studentList_t *studentList)
{
  if (studentList == NULL)
  {
    exit(EXIT_FAILURE);
  }

  student_t *actualStudent = studentList->first;
  printf("-+-+-+-+-+-+-+ Début printListStudent-+-+-+-+-+-+-+-+-\n");

  while (actualStudent != NULL)
  {
    printf("prenom -> %s / nom -> %s / promotion -> %s / id : %d \n", actualStudent->firstname, actualStudent->lastname, actualStudent->promotion, actualStudent->id);
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    actualStudent = actualStudent->next;
  }
  printf("-+-+-+-+-+-+-+ Fin printListStudent-+-+-+-+-+-+-+-+-\n");
}
