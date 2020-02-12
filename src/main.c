#include "../headers/header.h"

/* libère toutes les variables/structures ayant été malloc dans le programme */

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    studentList_t *studentList = studentInitialisation();
    int a = 1;
    menu(studentList);

    //printListStudent(studentList);
    //printListSubject(studentList->first->subjectList);
    //deleteFirstSubject(studentList->first->subjectList);
    //deleteFirstStudent(studentList);
    printf("bonjour %d", a);

    //allFree(studentList);
    printf("b onjour %d", SIZE_MAX);
    return 0;
}
