#ifndef _HEADER_H_
#define _HEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_MAX 10

typedef struct subject_s
{
    char *name;
    double note;
    double scale;
    struct subject_s *next;
} subject_t;

typedef struct
{

    int nbrOfSubject;
    subject_t *first;
} subjectList_t;

typedef struct
{
    int id;
    char *firstname;
    char *lastname;
    char *promotion;
    subjectList_t *subjectList;
    //   struct student_s *next;
} student_t;

typedef struct studentList_s
{
    student_t *student;
    struct studentList_s *next;
} studentList_t;

#include "student.h"
#include "subject.h"
#include "functions.h"
#endif