#include <stdio.h>
#include <string.h>

#include "my_string.h"
#include "my_assert.h"


size_t my_strlen(const char * string)
{
    MY_ASSERT(string != nullptr);

    size_t length = 0;
    int i = 0;

    while (string[i] != '\0')
    {
        length += 1;
        i += 1;
    }
    return length;
}


char * my_strcpy(char * target, const char * source)
{
    MY_ASSERT(target != nullptr && source != nullptr);
    
    int i = 0;

    while (source [i] != '\0')
    {
        MY_ASSERT(0 <= i);

        target[i] = source[i];
        i++;
    }

    target[i] = '\0';

    return target;
}


char * my_strncpy(char * target, const char * source, const size_t target_length)
{
    MY_ASSERT(target != nullptr && source != nullptr);

    int i = 0;

    while (source[i] != '\0' && (size_t) i < target_length - 1)
    {
        MY_ASSERT(0 <= i);

        target[i] = source [i];
        i++;
    }
    
    target[i] = '\0';

    return target;
}


size_t my_puts(const char * string)
{
    return printf("%s\n", string) - 1;
}


char * my_strchr(char * string, int character)
{
    int i = 0;
    
    while (string[i] != '\0')
    {
        if (string[i] == character)
            return &string[i];
        
        i++;
    }

    if (character == '\0')
        return &string[i];

    return NULL;
}


char * my_strcat(char * target, const char * source)
{
    int i = 0;

    while (target[i] != '\0')
        i++;

    int j = 0;

    while (source[j] != '\0')
    {
        target[i] = source[j];
        j++;
        i++;
    }

    target[i] = '\0';

    return target;
}


char * my_strncat(char * target, const char * source, const size_t string_length)
{
    int i = 0;

    while (target[i] != '\0')
        i++;

    int j = 0;

    while (source[j] != '\0' && (size_t) j < string_length - 1)
    {
        target[i] = source[j];
        j++;
        i++;
    }

    target[i] = '\0';

    return target;
}


char * my_fgets(char * string, const int max_length, FILE * file)
{
    int i = 0;
    int character = 0;

    while (i < max_length - 2 && ((character = fgetc(file)) != '\n' && character != EOF))
    {
        string[i] = (char) character;
        i++;
    }

    string[i] =     '\n';
    string[i + 1] = '\0';

    if (character == EOF)
        return NULL;
    else 
        return string;
}


char * my_strdup(const char * source)
{
    char * target = (char *) calloc(my_strlen(source) + 1, sizeof(char));
    
    my_strcpy(target, source);

    return target;
}

size_t my_getline(char * string, size_t length, FILE * file)
{
    char character = 0;
    size_t i = 0;

    while (i < length - 1 && (character = (char) fgetc(file)) != '\n' && character != EOF)
    {
        string[i] = character;
        i++;
    }

    string[i] = '\0';

    return i;
}