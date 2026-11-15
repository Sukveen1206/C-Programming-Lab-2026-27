#include <stdio.h>

int main()
{
    // Variables storing the details
    char name[] = "Riya Sharma";
    int age = 16;
    char student_class[] = "11th";
    char division = 'A';
    char uin[] = "UIN12345678";

    // Printing the formatted output
    printf("==============================\n");
    printf("       STUDENT PROFILE        \n");
    printf("==============================\n");

    printf("Name = %s\n", name);
    printf("Age = %d\n", age);
    printf("Student Class = %s\n", student_class);
    printf("Division = %c\n", division);
    printf("UIN = %s\n", uin);

    printf("==============================\n");

    return 0;
}
