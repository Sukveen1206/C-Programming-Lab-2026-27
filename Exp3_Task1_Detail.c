#include <stdio.h>
#include <string.h>

struct Student
{
    int id;
    char name[50];
    float marks1, marks2, marks3;
    float total, average;
    char grade;
};

int main()
{
    struct Student s[100];
    int choice, n = 0, i, id, found, j;

menu:
    printf("\n===== Student Grade and Result Management System =====\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Delete Student by ID\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter Student ID: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < n; i++) {
                if (s[i].id == id) {
                    found = 1;
                    break;
                }
            }

            if (found == 1) {
                printf("Student ID already exists.\n");
                goto menu;
            }

            s[n].id = id;

            printf("Enter Student Name: ");
            scanf(" %[^\n]", s[n].name);

            printf("Enter Marks in Subject 1: ");
            scanf("%f", &s[n].marks1);

            printf("Enter Marks in Subject 2: ");
            scanf("%f", &s[n].marks2);

            printf("Enter Marks in Subject 3: ");
            scanf("%f", &s[n].marks3);

            s[n].total = s[n].marks1 + s[n].marks2 + s[n].marks3;
            s[n].average = s[n].total / 3;

            if (s[n].average >= 90)
                s[n].grade = 'A';
            else if (s[n].average >= 80)
                s[n].grade = 'B';
            else if (s[n].average >= 70)
                s[n].grade = 'C';
            else if (s[n].average >= 60)
                s[n].grade = 'D';
            else if (s[n].average >= 50)
                s[n].grade = 'E';
            else
                s[n].grade = 'F';

            n++;
            printf("Student added successfully.\n");
            goto menu;

        case 2:
            if (n == 0) {
                printf("\nNo student records found.\n");
            } else {
                printf("\n----- Student Records -----\n");
                for (i = 0; i < n; i++) {
                    printf("\nID      : %d\n", s[i].id);
                    printf("Name    : %s\n", s[i].name);
                    printf("Total   : %.2f\n", s[i].total);
                    printf("Average : %.2f\n", s[i].average);
                    printf("Grade   : %c\n", s[i].grade);
                    if (s[i].grade == 'F')
                        printf("Result  : Fail\n");
                    else
                        printf("Result  : Pass\n");
                }
            }
            goto menu;

        case 3:
            if (n == 0) {
                printf("\nNo student records available.\n");
                goto menu;
            }

            printf("\nEnter Student ID to search: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < n; i++) {
                if (s[i].id == id) {
                    printf("\nStudent Found\n");
                    printf("ID      : %d\n", s[i].id);
                    printf("Name    : %s\n", s[i].name);
                    printf("Total   : %.2f\n", s[i].total);
                    printf("Average : %.2f\n", s[i].average);
                    printf("Grade   : %c\n", s[i].grade);
                    if (s[i].grade == 'F')
                        printf("Result  : Fail\n");
                    else
                        printf("Result  : Pass\n");
                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Student ID not found.\n");

            goto menu;

        case 4:
            if (n == 0) {
                printf("\nNo student records available.\n");
                goto menu;
            }

            printf("\nEnter Student ID to delete: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < n; i++) {
                if (s[i].id == id) {
                    for (j = i; j < n - 1; j++) {
                        s[j] = s[j + 1];
                    }
                    n--;
                    found = 1;
                    printf("Student deleted successfully.\n");
                    break;
                }
            }

            if (found == 0)
                printf("Student ID not found.\n");

            goto menu;

        case 5:
            printf("\nExiting program...\n");
            break;

        default:
            printf("\nInvalid choice.\n");
            goto menu;
    }

    return 0;
}
