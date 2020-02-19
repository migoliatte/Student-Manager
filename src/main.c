#include "../headers/header.h"

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    studentList_t *studentList = studentInitialisation();
    menu(studentList);
    free(studentList);
    //printListStudent(studentList);
    //printListSubject(studentList->first->subjectList);
    //deleteFirstSubject(studentList->first->subjectList);
    //deleteFirstStudent(studentList);
    //allFree(studentList);
    printf("End programme : exit %d", SIZE_MAX);
    return 0;
}
