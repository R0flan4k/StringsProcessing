#ifndef MY_STRING_H
    #define MY_STRING_H

    #include <stdio.h>

    struct IsLetters {
        char letter;
        bool is_in_string;
    };

    const size_t MAX_LENGTH = 256;
    const size_t ALPHABET_SIZE = 26;

    size_t my_strlen(const char * string);
    char * my_strcpy(char * target, const char * source);
    char * my_strncpy(char * target, const char * source, const size_t target_length);
    size_t my_puts(const char * string);
    char * my_strchr(char * string, int character);
    char * my_strcat(char * target, const char * source);
    char * my_strncat(char * target, const char * source, const size_t string_length);
    char * my_fgets(char * string, const int max_length, FILE * file);
    char * my_strdup(const char * source);
    ssize_t my_getline(char * * string, size_t * length, FILE * file);
    char * strstr(const char * string1, const char * string2);
    int my_strcmp(const char * string1, const char * string2);
    int my_strncmp(const char * string1, const char * string2, const size_t length);
    char * fget_str(FILE * file, char * string);
    int my_strncmp_index(const char * string1, const char * string2, const size_t length);
    IsLetters * get_string_letters(const char * string, const size_t string_length, IsLetters * letters);
    bool is_in_string (const char character, const IsLetters * string_letters);

#endif // MY_STRING_H