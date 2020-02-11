#ifndef _STUDENT_H_
#define _STUDENT_H_

typedef struct student_s
{
    int id;
    char *firstname;
    char *lastname;
    char *promotion;
    subjectList_t *subjectList;
    struct student_s *next;
} student_t;

typedef struct
{
    int nbrOfStudent;
    student_t *first;
} studentList_t;

studentList_t *studentInitialisation(void);

void createNewSubject(studentList_t *studentList);

void createNewStudent(studentList_t *studentList);    
void addNewStudent(studentList_t *studentList, char *studentFirstname, char *studentLastname, char *studentPromotion);
void deleteFirstStudent(studentList_t *studentList);
void printListStudent(studentList_t *studentList);

#endif
