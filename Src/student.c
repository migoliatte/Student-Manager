#include "../headers/header.h"

/*Initialise la structure studentList_t*/
studentList_t *studentInitialisation(void)
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

/*Récuperation des informations de l'étudiant ajouté par l'utilisateur*/
void createNewStudent(studentList_t *studentList)
{
  char *firstname = malloc(SIZE_MAX * sizeof(char));
  char *lastname = malloc(SIZE_MAX * sizeof(char));
  char *promotion = malloc(SIZE_MAX * sizeof(char));
  if (firstname == NULL || lastname == NULL || promotion == NULL)
  {
    //return 0;
  }

  fgetsCheck(firstname, "Veuillez rentrer votre prénom",SIZE_MAX);

  fgetsCheck(lastname, "\nVeuillez rentrer votre nom de famille",SIZE_MAX);

  fgetsCheck(promotion, "\nVeuillez rentrer votre promotion",SIZE_MAX);

  addNewStudent(studentList, firstname, lastname, promotion);

  free(firstname);
  free(lastname);
  free(promotion);
}

/*Récuperation des informations de la matière ajouté par l'utilisateur, elle se trouve ici et non dans subject.c car studentList_t n'y ai pas défini*/
void createNewSubject(studentList_t *studentList)
{
    char *name = malloc(SIZE_MAX * sizeof(char));
    if (name == NULL)
    {
      exit(EXIT_FAILURE);
    }
    double note = 10.5;
    double scale = 2;
    fgetsCheck(name, "\nVeuillez rentrer le nom de la matière",SIZE_MAX);

    addNewSubject(studentList->first->subjectList, name, note, scale);
    free(name);
}

/*Ajoute l'étudiant dans la structure studentList_t en fonction des données de l'utilisateur*/
void addNewStudent(studentList_t *studentList, char *studentFirstname, char *studentLastname, char *studentPromotion)
{
  /* Création du nouvel élément */
  student_t *student = malloc(sizeof(*student));
  if (studentList == NULL || student == NULL)
  {
    exit(EXIT_FAILURE);
  }
  studentList->nbrOfStudent++;
  student->firstname = malloc(SIZE_MAX * sizeof(char));
  student->lastname = malloc(SIZE_MAX * sizeof(char));
  student->promotion = malloc(SIZE_MAX * sizeof(char));

  strcpy(student->firstname, studentFirstname);
  strcpy(student->lastname, studentLastname);
  strcpy(student->promotion, studentPromotion);
  student->id = studentList->nbrOfStudent;
  student->subjectList = subjectInitialisation();

  /* Insertion de l'élément au début de la liste */
  student->next = studentList->first;
  studentList->first = student;
}

/*Supprime et libère dans la mémoire le premier étudiant de studentList*/
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
    deleteAllSubject(toDelete->subjectList);
    studentList->first = studentList->first->next;

    studentList->nbrOfStudent--;
    free(toDelete);
  }
}

/*
void printListStudent(studentList_t *studentList)
{
  if (studentList == NULL)
  {
    exit(EXIT_FAILURE);
  }

  student_t *actualStudent = studentList->first;
  fprintf(stdout,"-+-+-+-+-+-+-+ Début printListStudent-+-+-+-+-+-+-+-+-\n");

  while (actualStudent != NULL)
  {
    fprintf(stdout,"prenom -> %s / nom -> %s / promotion -> %s / id : %d \n", actualStudent->firstname, actualStudent->lastname, actualStudent->promotion, actualStudent->id);
    fprintf(stdout,"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    actualStudent = actualStudent->next;
  }
  fprintf(stdout,"-+-+-+-+-+-+-+ Fin printListStudent-+-+-+-+-+-+-+-+-\n");
}
*/
