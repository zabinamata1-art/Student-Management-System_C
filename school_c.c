// School management system in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // when using string functions like strcpy, strlen, etc., we need to include the string.h header file.


struct Student {
    char name[50];
    int age;
    char grade[10];
};




int main () {
    // struct Student s1;
    // s1.age = 20;
    // strcpy(s1.grade, "A"); // The strcpy() function is used to copy the string "A" into the grade field of the s1 struct. The strcpy() function takes two arguments: the destination string (s1.grade) and the source string ("A"). It copies the characters from the source string to the destination string, including the null terminator at the end of the string. This allows us to store a string value in a character array within a struct.
    // // The strcpy() function is used to copy the string "Kwame Nkrumah" into the name field of the s1 struct. The strcpy() function takes two arguments: the destination string (s1.name) and the source string ("Kwame Nkrumah"). It copies the characters from the source string to the destination string, including the null terminator at the end of the string. This allows us to store a string value in a character array within a struct.
    // strcpy(s1.name, "Kwame Nkrumah");

    // struct Student s2;
    // s2.age = 22;
    // strcpy(s2.grade, "B");
    // // The strcpy() function is used to copy the string "Kofi Annan" into the name field of the s2 struct. The strcpy() function takes two arguments: the destination string (s2.name) and the source string ("Kofi Annan"). It copies the characters from the source string to the destination string, including the null terminator at the end of the string. This allows us to store a string value in a character array within a struct.
    // strcpy(s2.name, "Kofi Annan");

    // struct Student s3;
    // s3.age = 21;
    // strcpy(s3.grade, "C");
    // strcpy(s3.name, "John Doe");

    FILE *file; // The FILE type is a structure that represents a file stream in C. It is defined in the stdio.h header file and is used to handle input and output operations on files. The FILE structure contains information about the file, such as its current position, error status, and buffering mode. When we declare a variable of type FILE, we are creating a file stream that can be used to read from or write to a file.
    
    struct Student all_Students[10] = {};

    int new_students = 0; // Initialize the count of students to 0, since we haven't added any students yet.

    char text[300]; // The char text[300] declaration creates an array of characters with a size of 300. This array can be used to store a string of up to 299 characters (plus the null terminator). In this case, it is used to read and store lines of text from the "students.txt" file.
    file = fopen("students.txt", "r"); // The fopen() function is used to open the "students.txt" file in read mode ("r"). This means that we can read the contents of the file, but we cannot modify it. If the file does not exist or cannot be opened for some reason, fopen() will return NULL, indicating an error. The function returns a pointer to a FILE object that can be used for subsequent file operations.
    
if (file != NULL) {
    while (new_students < 10 &&
           fscanf(file, "Name: %49[^,], Age: %d, Grade: %9s\n", // The fscanf() function is used to read formatted input from the "students.txt" file. It takes a format string that specifies how the input should be parsed, and it stores the parsed values into the provided variables. In this case, it reads a student's name (up to 49 characters), age (as an integer), and grade (up to 9 characters) from each line of the file. The %49[^,] format specifier reads up to 49 characters until a comma is encountered, allowing us to capture the student's name correctly. The & operator is used to pass the memory addresses of the variables where the parsed values will be stored.
                  all_Students[new_students].name, // The & operator is used to pass the memory address of the name field of the new student struct to fscanf(). This allows fscanf() to store the parsed name directly into the name field of the struct.
                  &all_Students[new_students].age, //
                  all_Students[new_students].grade) == 3) { // The fscanf() function returns the number of input items successfully matched and assigned. In this case, we expect to read three items (name, age, and grade) from each line of the file. If fscanf() successfully reads all three items, it will return 3. If it fails to read any of the items (e.g., due to a formatting error or end of file), it will return a value less than 3, indicating that we should stop reading further.

        new_students++;
    }

    fclose(file);
}


    while (1) {
        printf("\n");
        printf("\n");
        printf("\t\t\t Welcome to the School Management System!\n");
        printf("\t\t ----------------------------------------------------\n");
        printf("\n");
        printf("\t Please select an option from the menu below:\n");
        printf(" 1. Add a new student\n");
        printf(" 2. View all students\n");
        printf(" 3. Exit\n");
        int choice;
        printf("\n");
        printf(" Enter your choice: ");
        scanf("%d", &choice);

        

        if (choice == 1) {
            printf("\t You selected: Add a new student\n");
            // Code to add a new student would go here
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF); // Clear the input buffer to remove any leftover newline characters from previous input. This is important because when we use scanf() to read an integer, it leaves a newline character in the input buffer. If we don't clear the buffer, the next input operation (like fgets()) may read that leftover newline character instead of waiting for new user input. The while loop continues to read and discard characters from the input buffer until it encounters a newline character ('\n') or reaches the end of the file (EOF). This ensures that the input buffer is clean before we proceed to read the student's name.
            printf("\n");
            printf(" Enter student name: ");
            char new_name[50];
            fgets(new_name, sizeof(new_name), stdin); // The fgets() function is used to read a line of text from the standard input (stdin) and store it in the new_name array. It takes three arguments: the destination array (new_name), the maximum number of characters to read (sizeof(new_name)), and the input stream (stdin). This allows us to read a string input from the user and store it in the new_name variable.
            printf("\n");
            new_name[strcspn(new_name, "\n")] = 0; // The strcspn() function is used to find the first occurrence of a newline character ('\n') in the new_name string. It returns the index of the first occurrence of the newline character, which is then used to replace it with a null terminator ('\0'). This effectively removes the newline character from the end of the string, allowing us to store a clean string value in the new_name variable.
            printf(" Enter student age: ");
            int new_age;
            scanf("%d", &new_age);
            printf("\n");
            printf(" Enter student grade: ");
            char new_grade[10];
            scanf("%9s", new_grade);

            // Create a new Student struct and populate it with the input values
            struct Student newStudent;
            snprintf(newStudent.name, sizeof(newStudent.name), "%s", new_name); // The snprintf() function is used to format and store a string in the newStudent.name field. It takes three arguments: the destination string (newStudent.name), the maximum number of characters to write (sizeof(newStudent.name)), and the format string ("%s") followed by the source string (new_name). This allows us to safely copy the new_name string into the name field of the newStudent struct, ensuring that we do not exceed the allocated size of the name array.
            newStudent.age = new_age;
            snprintf(newStudent.grade, sizeof(newStudent.grade), "%s", new_grade); // The snprintf() function is used to format and store a string in the newStudent.grade field. It takes three arguments: the destination string (newStudent.grade), the maximum number of characters to write (sizeof(newStudent.grade)), and the format string ("%s") followed by the source string (new_grade). This allows us to safely copy the new_grade string into the grade field of the newStudent struct, ensuring that we do not exceed the allocated size of the grade array.

            if (new_students < 10) { // Check if there is space in the all_Students array to add a new student  
                file = fopen("students.txt", "a"); // The fopen() function is used to open the "students.txt" file in append mode ("a"). This means that if the file already exists, new data will be added to the end of the file without overwriting existing content. If the file does not exist, it will be created. The function returns a pointer to a FILE object that can be used for subsequent file operations.
                if (file == NULL) { // Check if the file was opened successfully. If fopen() fails to open the file, it returns NULL, indicating an error. In this case, we print an error message and exit the program with a non-zero status (1) to indicate failure.
                    printf(" Error opening file!\n");
                    return 1;
                }
                else {
                    fprintf(file, "Name: %s, Age: %d, Grade: %s\n",
                    newStudent.name, newStudent.age, newStudent.grade); // The fprintf() function is used to write formatted data to the file pointed to by the file pointer. In this case, we write the student's name, age, and grade to the "students.txt" file in a structured format. The format string specifies how the data should be formatted, and the subsequent arguments provide the actual values to be written.
                    fclose(file); // The fclose() function is used to close the file after writing. This ensures that all data is properly flushed to the file and that system resources are released. It is important to close files when they are no longer needed to avoid resource leaks and potential data corruption.
                }
                all_Students[new_students] = newStudent;
                new_students++;
                printf("\n");
                printf("\t\t Student added successfully!\n");
            } else {
                printf("\n");
                printf("\t\t Cannot add more students. Array is full.\n");
            }
            


        } else if (choice == 2) {
            printf("\n");
            printf("\t You selected: View all students\n");
            // Code to view all students would go here
            printf("\n");
            printf("\t Displaying all students:\n");
            for (int i = 0; i < new_students; i++) {
                printf("\t Student %d: Name: %s, Age: %d, Grade: %s\n", i + 1, all_Students[i].name, all_Students[i].age, all_Students[i].grade);
            }
        } else if (choice == 3) {
            printf("\t Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("\t Invalid choice. Please try again.\n");
        }
    }












    return 0;
}


































