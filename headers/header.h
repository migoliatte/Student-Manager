#ifndef _HEADER_H_
#define _HEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE_MAX 20

typedef struct
{
    int id;
    char *name;
    double note;
    int scale;
} subject_t;

typedef struct subjectList_s
{
  //  int nbr;
    subject_t *subject;
    struct subjectList_s *next;
} subjectList_t;

typedef struct
{
    int id;
    char *firstname;
    char *lastname;
    char *promotion;
    subjectList_t *subjectList;
} student_t;

typedef struct studentList_s
{
  //int nbr;
    student_t *student;
    struct studentList_s *next;
} studentList_t;

#include "student.h"
#include "subject.h"
#include "functions.h"
#endif