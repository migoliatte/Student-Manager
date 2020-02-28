#include "../headers/header.h"

void checkSauvegarde(studentList_t *studentList, int choice)
{
    FILE *file = NULL;
    studentList_t *actualStudentList = studentList;
    file = fopen("test.xml", "w");
    if (choice == 1)
    {
        if (file != NULL)
        {
            fputs("<?xml version = \"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>\n", file);
            while (actualStudentList->next)
            {
                fputs("<student>\n", file);

                fprintf(file, "     <userId> %d </userId>\n", actualStudentList->student->id);
                fprintf(file, "     <firstname> %s </firstname>\n", actualStudentList->student->firstname);
                fprintf(file, "     <lastname> %s </lastname>\n", actualStudentList->student->lastname);
                fprintf(file, "     <promotion> %s </promotion>\n", actualStudentList->student->promotion);

                displaySubjectListOfIUserInFile(actualStudentList->student->subjectList, file);

                fputs("</student>\n", file);
                actualStudentList = actualStudentList->next;
            }
            fclose(file);
        }
        else
        {
            printf("Impossible d'ouvrir le fichier test.txt");
        }
    }
    else
    {
        printf("Pas de sauvegarde");
    }
}

void displaySubjectListOfIUserInFile(subjectList_t *subjectList, FILE *file)
{
    if (subjectList == NULL)
    {
        printf("Pas de note pour un étudiant");
    }
    else
    {
        if (subjectList->subject == NULL)
        {
            printf("Pur avoir des données de sauvegarde des note vueillez ajouter des notes au user");
        }
        else
        {
            subjectList_t *actualSubject = subjectList;
            while (actualSubject->next)
            {
                fputs("     <subject>\n", file);

                fprintf(file, "             <sId> %d </sId>\n", actualSubject->subject->id);
                fprintf(file, "             <name> %s </name>\n", actualSubject->subject->name);
                fprintf(file, "             <note> %lf </note>\n", actualSubject->subject->note);
                fprintf(file, "             <scale> %d </scale>\n", actualSubject->subject->scale);

                fputs("     </subject>\n", file);
                actualSubject = actualSubject->next;
            }
        }
    }
}

studentList_t *chargeFile(char *nameFile, studentList_t *studentListG)
{
    int i = 0;
    FILE *file = NULL;
    file = fopen(nameFile, "r");
    // studentList_t *studentList = studentInitialisation();
    studentList_t *studentList = studentListG;

    char *studentFirstname = malloc(SIZE_MAX * sizeof(char));
    char *studentLastname = malloc(SIZE_MAX * sizeof(char));
    char *studentPromotion = malloc(SIZE_MAX * sizeof(char));
    if (studentFirstname == NULL || studentLastname == NULL || studentPromotion == NULL)
    {
        printf("error");
    }

    char *subjectName = malloc(SIZE_MAX * sizeof(char));
    double subjectNote;
    int subjectScale;
    if (subjectName == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (file != NULL)
    {

        printf("\n ------------------ Réussis ------------------ \n");

        int u;
        char line[255];
        int inFirst = 0;
        char *first = malloc(SIZE_MAX * sizeof(char));
        strcpy(first, "NULL");
        int a = 0;
        while (fgets(line, 255, file))
        {

            //ID USER
            for (u = 0; u < 255; u++)
            {
                if (line[u] == 60 && line[u + 1] == 117)
                {
                    inFirst = 1;
                    u += 8;
                }
                if (line[u] == 60 && line[u + 1] == 47 && line[u + 2] == 117)
                {
                    inFirst = 0;
                }
                if (inFirst)
                {
                    first[a] = line[u];
first[a+1] = '\0';
                    a++;
                }
            }
            a = 0;
            if (strcmp(first, "NULL") != 0)
            {
                int intFirst;
                intFirst = atoi(first);
                printf(" Voici IDUSER en INT:%d \n", intFirst);
            }
            strcpy(first, "NULL");

            //FIRSTNAME
            //    printf("%d ere line : %s \n",i,line);
            for (u = 0; u < 255; u++)
            {
                //si line[u] => <f alors :
                if (line[u] == 60 && line[u + 1] == 102)
                {
                    inFirst = 1;
                    u += 12; //se rend apres e>ESPACE
                }
                //si line est </f donc fin de la balise alors :
                if (line[u] == 60 && line[u + 1] == 47 && line[u + 2] == 102)
                {
                    inFirst = 0;
                }

                if (inFirst)
                {
                    first[a] = line[u];
first[a+1] = '\0';
                    a++;
                }
            }
            a = 0;

            if (strcmp(first, "NULL") != 0)
            {
                printf(" voici firstname : %s\n", first);
                strcpy(studentFirstname, first);
            }
            strcpy(first, "NULL");
            i++;

            //LASTNAME
            for (u = 0; u < 255; u++)
            {
                if (line[u] == 60 && line[u + 1] == 108)
                {
                    inFirst = 1;
                    u += 11;
                }
                if (line[u] == 60 && line[u + 1] == 47 && line[u + 2] == 108)
                {
                    inFirst = 0;
                }
                if (inFirst)
                {
                    first[a] = line[u];
first[a+1] = '\0';
                    a++;
                }
            }
            a = 0;
            if (strcmp(first, "NULL") != 0)
            {
                printf(" Voici lastname : %s \n", first);
                strcpy(studentLastname, first);
            }
            strcpy(first, "NULL");

            //PROMOTION
            for (u = 0; u < 255; u++)
            {
                if (line[u] == 60 && line[u + 1] == 112)
                {
                    inFirst = 1;
                    u += 12;
                }
                if (line[u] == 60 && line[u + 1] == 47 && line[u + 2] == 112)
                {
                    inFirst = 0;
                }
                if (inFirst)
                {
                    first[a] = line[u];
first[a+1] = '\0';
                    a++;
                }
            }
            a = 0;
            if (strcmp(first, "NULL") != 0)
            {
                printf(" Voici promotion : %s \n\n", first);
                strcpy(studentPromotion, first);
            }
            strcpy(first, "NULL");

            //ID SUBJECT
            for (u = 0; u < 255; u++)
            {
                if (line[u] == 60 && line[u + 1] == 115 && line[u + 2] == 73)
                {
                    inFirst = 1;
                    u += 5;
                }
                if (line[u] == 60 && line[u + 1] == 47 && line[u + 2] == 115 && line[u + 3] == 73)
                {
                    inFirst = 0;
                }
                if (inFirst)
                {
                    first[a] = line[u];
first[a+1] = '\0';
                    a++;
                }
            }
            a = 0;
            if (strcmp(first, "NULL") != 0)
            {
                printf(" Voici ID SUBJECT : %s \n", first);
            }
            strcpy(first, "NULL");

            //NAME SUBJECT
            for (u = 0; u < 255; u++)
            {
                if (line[u] == 60 && line[u + 1] == 110 && line[u + 2] == 97)
                {
                    inFirst = 1;
                    u += 7;
                }
                if (line[u] == 60 && line[u + 1] == 47 && line[u + 2] == 110 && line[u + 3] == 97)
                {
                    inFirst = 0;
                }
                if (inFirst)
                {
                    first[a] = line[u];
first[a+1] = '\0';
                    a++;
                }
            }
            a = 0;
            if (strcmp(first, "NULL") != 0)
            {
                printf(" Voici Name Subjet : %s \n", first);
                strcpy(subjectName, first);
            }
            strcpy(first, "NULL");

            for (u = 0; u < 255; u++)
            {
                if (line[u] == 60 && line[u + 1] == 110 && line[u + 2] == 111)
                {
                    inFirst = 1;
                    u += 7;
                }
                if (line[u] == 60 && line[u + 1] == 47 && line[u + 2] == 110 && line[u + 3] == 111)
                {
                    inFirst = 0;
                }
                if (inFirst)
                {
                    first[a] = line[u];
first[a+1] = '\0';
                    a++;
                }
            }
            a = 0;
            if (strcmp(first, "NULL") != 0)
            {
                printf("Voici la note : %s \n", first);
                double note;
                note = atof(first);
                subjectNote = note;
            }
            strcpy(first, "NULL");

            for (u = 0; u < 255; u++)
            {
                if (line[u] == 60 && line[u + 1] == 115 && line[u + 2] == 99)
                {
                    inFirst = 1;
                    u += 8;
                }
                if (line[u] == 60 && line[u + 1] == 47 && line[u + 2] == 115 && line[u + 3] == 99)
                {
                    inFirst = 0;
                }
                if (inFirst)
                {
                    first[a] = line[u];
first[a+1] = '\0';
                    a++;
                }
            }
            a = 0;
            if (strcmp(first, "NULL") != 0)
            {
                printf("Voici le coeff : %s \n\n", first);
                int coeff;
                coeff = atof(first);
                subjectScale = coeff;
            }
            strcpy(first, "NULL");

            for (u = 0; u < 255; u++)
            {
                if (line[u] == 60 && line[u + 1] == 47 && line[u + 2] == 115 && line[u + 3] == 116)
                {
                    if (studentList)
                    {
                        student_t *student = malloc(sizeof(*student));
                        if (student)
                        {
                            student->firstname = malloc(SIZE_MAX * sizeof(char));
                            student->lastname = malloc(SIZE_MAX * sizeof(char));
                            student->promotion = malloc(SIZE_MAX * sizeof(char));

                            strcpy(student->firstname, studentFirstname);
                            strcpy(student->lastname, studentLastname);
                            strcpy(student->promotion, studentPromotion);
                            student->subjectList = subjectInitialisation();
                            student->id = studentList->nbr + 1;
                            studentList = addNewStudent(studentList, student);

                            if (studentList->student)
                            {
                                studentList->nbr = studentList->student->id;
                            }
                            //student->subjectList

                            subject_t *subject = malloc(sizeof(*subject));
                            if (subject)
                            {
                                subject->name = malloc(SIZE_MAX * sizeof(char));
                                strcpy(subject->name, subjectName);
                                subject->note = subjectNote;
                                subject->scale = subjectScale;
                                if (studentList->student->subjectList->subject)
                                {
                                    studentList->student->subjectList->nbr = studentList->student->subjectList->subject->id;
                                }
                                subject->id = studentList->student->subjectList->nbr + 1;
                                studentList->student->subjectList = addNewSubject(studentList->student->subjectList, subject);
                            }
                            else
                            {
                                exit(EXIT_FAILURE);
                            }
                        }
                        else
                        {
                            exit(EXIT_FAILURE);
                        }
                    }
                    else
                    {
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }

        fclose(file);
        free(studentFirstname);
        free(studentLastname);
        free(studentPromotion);
        free(subjectName);
        printListStudent(studentList);
    }
    else
    {
        printf("\n ------------------ Impossible d'ouvrire le fichier test.xml ------------------ \n");
        
    }
    return studentList;
    // printListSubject(studentList);
}
