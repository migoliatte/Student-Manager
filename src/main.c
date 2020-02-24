#include "../headers/header.h"

/* libère toutes les variables/structures ayant été malloc dans le programme */

int main(int argc, char const *argv[])
{
    system("clear");
    (void)argc;
    (void)argv;
    studentList_t *studentList = studentInitialisation();
    menu(studentList);
    //studentList = initForTest(studentList);
    //printAllMoyenneBySubject(studentList);
    printf("SIZE_MAX = %d\nEndProgram\nGoodBye", SIZE_MAX);
    return 0;
}
