/* C Programming Quiz - 20 questions, 1 mark each
   Compile: gcc quiz.c -o quiz */

#include <stdio.h>

struct Question {
    char text[100];
    char opt[4][40];
    char ans;              /* correct option: 'a', 'b', 'c' or 'd' */
};

int main() {
    struct Question q[20] = {
        {"Which symbol ends a statement in C?", {".", ";", ":", ","}, 'b'},
        {"Which header file is needed for printf()?", {"stdlib.h", "string.h", "stdio.h", "math.h"}, 'c'},
        {"Size of int on most computers (in bytes)?", {"1", "2", "4", "8"}, 'c'},
        {"Which is a valid variable name?", {"2num", "my-var", "int", "my_var"}, 'd'},
        {"Format specifier used to print a float?", {"%d", "%f", "%c", "%s"}, 'b'},
        {"What is the value of 10 % 3?", {"1", "3", "0", "3.33"}, 'a'},
        {"Which loop runs at least once?", {"for", "while", "do-while", "none"}, 'c'},
        {"Which keyword leaves a loop immediately?", {"stop", "exit", "break", "end"}, 'c'},
        {"Array index starts from?", {"1", "0", "-1", "2"}, 'b'},
        {"Which function finds the length of a string?", {"strcpy", "strlen", "strcat", "strcmp"}, 'b'},
        {"Which operator gives the address of a variable?", {"*", "#", "&", "@"}, 'c'},
        {"Which function allocates memory dynamically?", {"free", "printf", "malloc", "scanf"}, 'c'},
        {"A function that calls itself is called?", {"Loop", "Recursion", "Array", "Structure"}, 'b'},
        {"Which keyword is used to create a structure?", {"class", "record", "struct", "object"}, 'c'},
        {"Which function opens a file?", {"fclose", "fread", "fopen", "fwrite"}, 'c'},
        {"Which mode opens a file for reading?", {"\"w\"", "\"a\"", "\"x\"", "\"r\""}, 'd'},
        {"Which function closes a file?", {"fprintf", "fopen", "fscanf", "fclose"}, 'd'},
        {"What is the value of 5 / 2 for integers?", {"2.5", "3", "2", "2.0"}, 'c'},
        {"Which statement chooses between many cases?", {"if", "for", "goto", "switch"}, 'd'},
        {"What does return 0; in main() mean?", {"Error", "Program ended successfully", "Infinite loop", "Nothing"}, 'b'}
    };
    int i, score = 0, total = 20;
    char name[50], input[20] = "x";
    float percent;
    FILE *fp;

    printf("===== C PROGRAMMING QUIZ =====\n");
    printf("Enter your name: ");
    scanf(" %49[^\n]", name);

    for (i = 0; i < total; i++) {
        printf("\nQ%d. %s\n", i + 1, q[i].text);
        printf("   a) %s\n   b) %s\n   c) %s\n   d) %s\n", q[i].opt[0], q[i].opt[1], q[i].opt[2], q[i].opt[3]);
        printf("Your answer (a/b/c/d): ");
        scanf("%19s", input);

        if (input[0] >= 'A' && input[0] <= 'Z')   /* capital letter -> small letter */
            input[0] = input[0] + 32;

        if (input[0] == q[i].ans) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. The correct answer is %c.\n", q[i].ans);
        }
    }

    percent = score * 100.0 / total;
    printf("\n========== RESULT ==========\n");
    printf("Name        : %s\n", name);
    printf("Correct     : %d\n", score);
    printf("Wrong       : %d\n", total - score);
    printf("Marks       : %d out of %d\n", score, total);
    printf("Percentage  : %.2f%%\n", percent);
    if (percent >= 80)
        printf("Remark      : Excellent\n");
    else if (percent >= 50)
        printf("Remark      : Good\n");
    else
        printf("Remark      : Needs more practice\n");
    printf("============================\n");

    /* save the score in a file (file handling) */
    fp = fopen("scores.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s - %d/%d (%.2f%%)\n", name, score, total, percent);
        fclose(fp);
        printf("Score saved in scores.txt\n");
    } else {
        printf("Could not save the score.\n");
    }
    return 0;
}
