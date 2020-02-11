#include "./headers/header.h"

/* libère toutes les variables/structures ayant été malloc dans le programme */
void allFree(studentList_t *studentList)
{
    if (studentList->first->subjectList->first->name != NULL)
        free(studentList->first->subjectList->first->name);

    if (studentList->first->firstname != NULL)
        free(studentList->first->firstname);

    if (studentList->first->lastname != NULL)
        free(studentList->first->lastname);

    if (studentList->first->promotion != NULL)
        free(studentList->first->promotion);

    if (studentList->first->subjectList != NULL)
        deleteAllSubject(studentList->first->subjectList);

    if (studentList != NULL)
        free(studentList);
}

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    studentList_t *studentList = studentInitialisation();
    menu(studentList);

    //printListStudent(studentList);
    //printListSubject(studentList->first->subjectList);
    //deleteFirstSubject(studentList->first->subjectList);
    //deleteFirstStudent(studentList);
    
    allFree(studentList);
    printf("bonjour %d", SIZE_MAX);
    return 0;
}
