#include "./HEADERS/header.h"

int menu()
{

    fprintf(stdout,"=========== Gestionnaire d'students ==========\n");
    fprintf(stdout,"1 - Lister les students\n");
    fprintf(stdout,"2 - Ajouter un students\n");
    fprintf(stdout,"3 - Supprimer un students\n");
    fprintf(stdout,"4 - Modifier un student\n");
    fprintf(stdout,"5 - Ajouter une note aux students\n");
    fprintf(stdout,"6 - Détail sur un students\n");
    fprintf(stdout,"7 - Lister les students supprimés\n");
    fprintf(stdout,"10 - Quitter\n");
    fprintf(stdout,"============================================\n");
    int choix;
    choix = verifInt();
    switch (choix)
    {
    case 1:
        system("clear");
        fprintf(stdout," 1 !! \n");
        // listStudent(studentList);
        break;
    case 2:
        system("clear");
        fprintf(stdout," 2 !! \n");

        //studentList = createStudent(studentList);
        break;
    case 3:
        system("clear");
        fprintf(stdout," 3 !! \n");

        //studentList = deleteOneStudent(studentList);
        break;
    case 4:
        system("clear");
        // modifyStudent(studentList);
        break;
    case 5:
        system("clear");
        // addNoteToStudent(studentList);
        break;
    case 6:
        system("clear");
        // listOneStudent(studentList);
        break;
    case 7:
        system("clear");
        // listStudentDeleted(studentList);
        break;
    case 10:
        system("clear");
        return 0;
    default:
        system("clear");
        fprintf(stdout," ! ! ! Erreur  Option Invalide ! ! ! \nVeuillez choisir une option valide.\n");
        menu();
        break;
    }
    menu();
    return 0;
}

int main(int argc, char const *argv[])
{
    system("clear");
    studentList_t *studentList = studentInitialisation();
    //subjectList_t *subjectList = subjectInitialisation();
    menu();
    char *firstname = malloc(15);
    char *lastname = malloc(15);
    char *promotion = malloc(15);

    fgetsCheck(firstname, "Veuillez rentrer votre prénom", 15);
    fgetsCheck(lastname, "Veuillez rentrer votre nom de famille", 15);
    fgetsCheck(promotion, "Veuillez rentrer votre promotion", 15);
    newStudent(studentList, firstname, lastname, promotion);

    char *name = malloc(15);
    double note = 10.5;
    double scale = 2;
    fgetsCheck(name, "Veuillez rentrer le nom de la matière", 15);

    newSubject(studentList->first->subjectList, name, note, scale);

    //    printListStudent(studentList);

    enterToContinue();

    //    printListSubject(studentList->first->subjectList);
    free(name);
    free(firstname);
    free(lastname);
    free(promotion);
    deleteFirstSubject(studentList->first->subjectList);
    deleteFirstStudent(studentList);
    free(studentList);
    free(studentList->first->subjectList);

    return 0;
}