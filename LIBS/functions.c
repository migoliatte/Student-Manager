#include "../HEADERS/header.h"


void enterToContinue()
{
    char enter[3];
    fprintf(stdout,"Enter to continue\n");
    fgets(enter, 3, stdin);
    if (strlen(enter) < 3)
        enter[strlen(enter) - 1] = '\0';
    fflush(stdin);
    system("clear");
    //fprintf(stdout,"touche : %d & %c\n", enter[strlen(enter) - 1], enter[strlen(enter) - 1]);
}

void fgetsCheck(char *input, char *message, int size)
{
    fprintf(stdout,"%s\n", message);
    fgets(input, size, stdin);
    if (strlen(input) < size)
        input[strlen(input) - 1] = '\0';
    fflush(stdin);
    //fprintf(stdout,"touche : %d & %c\n", enter[strlen(enter) - 1], enter[strlen(enter) - 1]);
}

int verifInt()
{
    char *choix = malloc(3 * sizeof(char));
    do
    {
        fgetsCheck(choix, "Veuillez choisir votre choix ", 3);
        if (atoi(choix) < 1 || atoi(choix) > 11)
        {
            //fprintf(stdout," >> Veuillez rentrer un chiffre entre 1 et 10 ! ");
            fprintf(stdout," >> Veuillez rentrer un chiffre entre 1 et 10 ! ");
        }
    } while (atoi(choix) < 1 || atoi(choix) > 11);
    int number = atoi(choix);
    free(choix);
    return number;
}