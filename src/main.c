#include "../headers/header.h"

/* libère toutes les variables/structures ayant été malloc dans le programme */

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
    //allFree(studentList);
    printf("SIZE_MAX = %d\nEndProgram\nGoodBye", SIZE_MAX);
    return 0;
}
