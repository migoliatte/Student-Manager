#include "../headers/header.h"

int main(int argc, char const *argv[])
{
    system("clear");
    (void)argc;
    (void)argv;
    studentList_t *studentList = studentInitialisation();
    menu(studentList);
    printf("SIZE_MAX = %d\nEndProgram\nGoodBye", SIZE_MAX);
    return 0;
}
