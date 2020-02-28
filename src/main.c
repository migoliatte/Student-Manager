#include "../headers/header.h"

/* libère toutes les variables/structures ayant été malloc dans le programme */
int main(int argc, char const *argv[])
{
    system("clear");
    (void)argc;
    (void)argv;
    studentList_t *studentList = studentInitialisation();
    menu(studentList);
    allFree(studentList);
    return 0;
}
