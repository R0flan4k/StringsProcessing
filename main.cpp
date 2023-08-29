#include <stdio.h>

#include "my_string.h"
#include "my_assert.h"


int main(void)
{
    const char * string = "Hello, World!";
    printf("Hello, World - %d\n", my_strlen(string));
    
    char target[MAX_LENGTH] = "";
    my_strncpy(target, string, MAX_LENGTH);
    
    my_puts(target);

    char * point = NULL;
    point = my_strchr(target, ',');
    printf("%p and %p\n", &target[5], point);

    char str[MAX_LENGTH] = "Hey! ";
    printf("%s\n", my_strcat(str, string));

    FILE * fp = nullptr;
    char file_string[MAX_LENGTH] = "";

    MY_ASSERT((fp = fopen("string_file.txt", "r")) != NULL);

    puts("");

    while (my_fgets(file_string, MAX_LENGTH, fp) != NULL)
    {
        printf("%s", file_string);
    }

    fclose(fp);

    puts("");

    char * string_dup = my_strdup(string);

    printf("%s\n", string_dup);

    free(string_dup);

    char getline_string[MAX_LENGTH] = "";
    int length_getline_string = 0;

    length_getline_string = my_getline(getline_string, MAX_LENGTH, stdin);

    printf("length_getline_string = %d\n", length_getline_string);
    printf("getline_string - %s\n", getline_string);

    return 0;
}