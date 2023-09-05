#include <stdio.h>

#include "my_string.h"
#include "my_assert.h"
#include "input-output.h"


int main(void)
{
    // const char * string = "Hello, World!";
    // printf("Hello, World - %d\n", my_strlen(string));
    
    // char target[MAX_LENGTH] = "";
    // my_strncpy(target, string, MAX_LENGTH);
    
    // my_puts(target);

    // char * point = NULL;
    // point = my_strchr(target, ',');
    // printf("%p and %p\n", &target[5], point);

    // char str[MAX_LENGTH] = "Hey! ";
    // printf("%s\n", my_strcat(str, string));

    // char file_string[MAX_LENGTH] = "";


    // puts("");

    // while (my_fgets(file_string, MAX_LENGTH, fp) != NULL)
    // {
    //     printf("%s", file_string);
    // }

    // puts("");

    // char * string_dup = my_strdup(string);

    // printf("%s\n", string_dup);

    // free(string_dup);

    // printf("%d\n", my_strcmp("llolp", "llolo"));
    // printf("%d\n", my_strncmp("llol", "llolkek", 4));
    // printf("%d\n", my_strncmp("llolp", "llolo", 4));
    // printf("%d\n", my_strncmp("llolpdsa", "llolo", 5));

    // puts("");

    // const char * pt = nullptr;
    char * arrow = NULL;
    const char * literal = "lolkekcheburek";

        printf("1) %p and %p\n", arrow = my_strstr(literal, "kek"), &literal[3]);

        if (arrow == &literal[3])
            puts(COLOR_GREEN "1 test passed." COLOR_DEFAULT);
        else
            puts(COLOR_RED   "1 test failed." COLOR_DEFAULT);


        printf("2) %p and %p\n", arrow = my_strstr("Amogus", "Amigos"), literal);

        if (arrow == NULL)
            puts(COLOR_GREEN "2 test passed." COLOR_DEFAULT);
        else
            puts(COLOR_RED   "2 test failed." COLOR_DEFAULT);

        
        printf("3) %p and %p\n", arrow = my_strstr("Amogus", "gusi"), "Amogus");

        if (arrow == NULL)
            puts(COLOR_GREEN "3 test passed." COLOR_DEFAULT);
        else
            puts(COLOR_RED   "3 test failed." COLOR_DEFAULT);


        printf("4) %p and %p\n", arrow = my_strstr("Amogusic", "gusi"), "Amogusic");

        if (arrow == "Amogusic" + 3)
            puts(COLOR_GREEN "4 test passed." COLOR_DEFAULT);
        else
            puts(COLOR_RED   "4 test failed." COLOR_DEFAULT);


        printf("5) %p and %p\n", arrow = my_strstr("Bebra", "Abebraka"), "Bebra");

        if (arrow == NULL)
            puts(COLOR_GREEN "5 test passed." COLOR_DEFAULT);
        else
            puts(COLOR_RED   "5 test failed." COLOR_DEFAULT);


        printf("6) %p and %p\n", arrow = my_strstr("lebedi", "gusi"), "lebedi");

        if (arrow == NULL)
            puts(COLOR_GREEN "6 test passed." COLOR_DEFAULT);
        else
            puts(COLOR_RED   "6 test failed." COLOR_DEFAULT);

        
        printf("7) %p and %p\n", arrow = my_strstr("aaabc", "aabc"), "aaabc");

        if (arrow == "aaabc" + 1)
            puts(COLOR_GREEN "7 test passed." COLOR_DEFAULT);
        else
            puts(COLOR_RED   "7 test failed." COLOR_DEFAULT);


        printf("8) %p and %p\n", arrow = my_strstr("aaakaaab", "aaab"), "aaakaaab");

        if (arrow == "aaakaaab" + 4)
            puts(COLOR_GREEN "8 test passed." COLOR_DEFAULT);
        else
            puts(COLOR_RED   "8 test failed." COLOR_DEFAULT);


        printf("9) %p and %p\n", arrow = my_strstr("l", "lol"), "l");

        if (arrow == NULL)
            puts(COLOR_GREEN "9 test passed." COLOR_DEFAULT);
        else
            puts(COLOR_RED   "9 test failed." COLOR_DEFAULT);

        
        printf("10) %p and %p\n", arrow = my_strstr("kek", "kek"), "kek");

        if (arrow == "kek" + 0)
            puts(COLOR_GREEN "10 test passed." COLOR_DEFAULT);
        else
            puts(COLOR_RED   "10 test failed." COLOR_DEFAULT);

        puts("\n\n");

    //------------------------------------------------------------------------------------------------------

    FILE * fp = nullptr;
    
    if ((fp = fopen("string_file.txt", "r")) == NULL)
    {
        puts(COLOR_RED "File error." COLOR_DEFAULT);
        return 1;
    }

    char * pt = NULL;
    size_t getline_length = 0;

    if (my_getline(&pt, &getline_length, fp) == NULL)
    {
        puts("Memory allocation error.");
        
        return 1;
    }

    printf("%s\n", pt);
    printf("%d\n", getline_length);
    printf("After my_getline() test\n");
    
    free(pt);

    fclose(fp);

    return 0;
}