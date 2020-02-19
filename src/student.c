#include "../headers/header.h"

/*Initialise la structure studentList_t*/
studentList_t *studentInitialisation(void)
{
  studentList_t *studentList = malloc(sizeof(*studentList));
  if (studentList == NULL)
  {
    exit(EXIT_FAILURE);
  }
  studentList->student = NULL;
  studentList->next = NULL;
  studentList->nbr = 0;
  return studentList;
}

/*Récuperation des informations de l'étudiant ajouté par l'utilisateur*/
studentList_t *createNewStudent(studentList_t *studentList)
{
  char *studentFirstname = malloc(SIZE_MAX * sizeof(char));
  char *studentLastname = malloc(SIZE_MAX * sizeof(char));
  char *studentPromotion = malloc(SIZE_MAX * sizeof(char));
  if (studentFirstname == NULL || studentLastname == NULL || studentPromotion == NULL)
  {
    printf("ATTENTION TU AS PLUS DE MEMOIRES");
  }

  fgetsCheck(studentFirstname, "Veuillez rentrer votre prénom", SIZE_MAX);

  fgetsCheck(studentLastname, "\nVeuillez rentrer votre nom de famille", SIZE_MAX);

  fgetsCheck(studentPromotion, "\nVeuillez rentrer votre promotion", SIZE_MAX);

  /* Création du nouvel élément */
  student_t *student = malloc(sizeof(*student));
  if (student == NULL)
  {
    exit(EXIT_FAILURE);
  }
  student->firstname = malloc(SIZE_MAX * sizeof(char));
  student->lastname = malloc(SIZE_MAX * sizeof(char));
  student->promotion = malloc(SIZE_MAX * sizeof(char));

  strcpy(student->firstname, studentFirstname);
  strcpy(student->lastname, studentLastname);
  strcpy(student->promotion, studentPromotion);
  if (studentList->student)
  {
    studentList->nbr = studentList->student->id;
  }
  student->id = studentList->nbr + 1;

  studentList = addNewStudent(studentList, student);

  free(studentFirstname);
  free(studentLastname);
  free(studentPromotion);
  return studentList;
}

/*Ajoute l'étudiant dans la structure studentList_t en fonction des données de l'utilisateur*/
studentList_t *addNewStudent(studentList_t *studentList, student_t *student)
{
  if (studentList == NULL)
  {
    exit(EXIT_FAILURE);
  }
  else
  {
    studentList_t *new = malloc(sizeof(studentList_t));

    new->student = student;
    new->next = studentList;
    return new;
  }
}

/*Supprime et libère dans la mémoire le premier étudiant de studentList*/
void deleteFirstStudent(studentList_t *studentList)
{
  if (studentList == NULL)
  {
    exit(EXIT_FAILURE);
  }

  if (studentList->student != NULL)
  {
    student_t *toDelete = studentList->student;
    free(toDelete->firstname);
    free(toDelete->lastname);
    free(toDelete->promotion);
    deleteAllSubject(&toDelete->subjectList);
    studentList = studentList->next;

    free(toDelete);
  }
}
/* Affichage de prenom/nom/id de tous les étudiants */
void printListStudent(studentList_t *studentList)
{
  if (studentList == NULL)
  {
    exit(EXIT_FAILURE);
  }
  if (studentList->student == NULL)
  {
    fprintf(stdout, "-+-+-+-+-+-+-+ Veuillez créer des étudiants -+-+-+-+-+-+-+-+-\n");
  }
  else
  {
    studentList_t *currentList = studentList;
    fprintf(stdout, "-+-+-+-+-+-+-+ Début printListStudent-+-+-+-+-+-+-+-+-\n");

    while (currentList->next)
    {
      fprintf(stdout, "prenom -> %s / nom -> %s / promotion -> %s / id : %d \n", currentList->student->firstname, currentList->student->lastname, currentList->student->promotion, currentList->student->id);
      if (currentList->next->next)
      {
        fprintf(stdout, "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
      }
      currentList = currentList->next;
    }
    fprintf(stdout, "-+-+-+-+-+-+-+ Fin printListStudent-+-+-+-+-+-+-+-+-\n");
  }
}

studentList_t *search(studentList_t *studentList, char *etudiantName)
{
  studentList_t *currentList = studentList;
  while (currentList->next)
  {

    if (strcmp((char *)currentList->student->firstname, etudiantName) == 0)
    {
      return currentList;
    }
    else
    {
      currentList = currentList->next;
    }
  }
  printf("Eleve non trouvé\n");
  return NULL;
}

void displaySearchedStudent(studentList_t *studentList, char *etudiantName)
{
  studentList_t *studentToDisplay = search(studentList, etudiantName);
  if (studentToDisplay)
  {
    printf("ton gars c'est : %s %s %s\n", studentToDisplay->student->firstname, studentToDisplay->student->lastname, studentToDisplay->student->promotion);
    printListSubject(studentToDisplay->student->subjectList);
  }
}

char *deleteSpecificItem(studentList_t **studentList, char *val)
{

  studentList_t *studentToDelete = *studentList;
  if (studentToDelete->student == NULL)
  {
    return "Veuillez créer des étudiants ! ";
  }
  studentList_t *tmp = NULL;

  while (strcmp(studentToDelete->student->firstname, val) != 0 && studentToDelete->next != NULL)
  {
    tmp = studentToDelete;
    studentToDelete = studentToDelete->next;
  }

  if (strcmp(studentToDelete->student->firstname, val) == 0)
  {
    if (tmp)
    {
      tmp->next = studentToDelete->next;
    }
    else
    {
      *studentList = studentToDelete->next;
    }
    free(studentToDelete->student->firstname);
    free(studentToDelete->student->lastname);
    free(studentToDelete->student->promotion);
    deleteAllSubject(&studentToDelete->student->subjectList);
    free(studentToDelete->student);
    free(studentToDelete);
    return val;
  }

  return "NOPE";
}

char *modifySpecificItem(studentList_t **studentList, char *val)
{
  studentList_t *studentList2 = *studentList;
  studentList2 = studentList2;
  val = val;
  return "bonjour";
}
/*
studentList_t *orderStudent(studentList_t *studentList)
{ // ici on va ranger les elements dans l'ordre croisssant avant de les afficher.
  studentList_t *temp, *temp1, *temp3;
  char *min;
  temp = studentList;
  do
  {
    temp3 = temp;
    min=temp->student->firstname;
     for(temp1=temp->next ; temp1!=NULL ; temp1=temp1->next)
     {
        if(min > temp1->student->firstname)
        {
           temp3=temp1; // le 3è temporaire est l'adresse de l'élement où se trouve le minimum
           min=temp3->student->firstname;
        }
     }
     temp3->student->firstname=temp->student->firstname; //echange des 2 elements...
    
    //strcpy(temp->student->firstname,min);
    //printf("min = %s",min);
    //printf("temp->student->firstname = %s",temp->student->firstname);
    printf("studentList->student->firstname = %s\n", temp->student->firstname);
    temp = temp->next;
  } while (temp->next != NULL);
  return "bonjour";
}
*/