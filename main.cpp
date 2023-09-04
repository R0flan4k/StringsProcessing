#include <stdio.h>

#include "my_string.h"
#include "my_assert.h"


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
    const char * literal = "lolkekcheburek";

        printf("1) %p and %p\n", strstr(literal, "kek"), &literal[3]);

        printf("2) %p and %p\n", strstr("Amogus", "Amigos"), literal);
        
        printf("3) %p and %p\n", strstr("Amogus", "gusi"), "Amogus");

        printf("4) %p and %p\n", strstr("Amogusic", "gusi"), "Amogusic");

        printf("5) %p and %p\n", strstr("Bebra", "Abebraka"), "Bebra");

        printf("6) %p and %p\n", strstr("lebedi", "gusi"), "lebedi");
        
        printf("7) %p and %p\n", strstr("aaabc", "aabc"), "aaabc");

        printf("8) %p and %p\n", strstr("aaakaaab", "aaab"), "aaakaaab");

    //------------------------------------------------------------------------------------------------------

    FILE * fp = nullptr;
    
    if ((fp = fopen("string_file.txt", "r")) == NULL)
    {
        puts("File error.");
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