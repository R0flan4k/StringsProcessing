#ifndef MY_STRING_H
    #define MY_STRING_H

    #include <stdio.h>

    const size_t MAX_LENGTH = 35;

    size_t my_strlen(const char * string);
    char * my_strcpy(char * target, const char * source);
    char * my_strncpy(char * target, const char * source, const size_t target_length);
    size_t my_puts(const char * string);
    char * my_strchr(char * string, int character);
    char * my_strcat(char * target, const char * source);
    char * my_strncat(char * target, const char * source, const size_t string_length);
    char * my_fgets(char * string, const int max_length, FILE * file);
    char * my_strdup(const char * source);
    size_t my_getline(char * string, size_t length, FILE * file);

#endif // MY_STRING_H