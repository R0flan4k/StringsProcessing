#include <stdio.h>

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

    size_t i = 0;

    while (source[i] != '\0' && i < target_length - 1)
    {
        target[i] = source [i];
        i++;
    }
    
    target[i] = '\0';

    return target;
}


size_t my_puts(const char * string)
{
    MY_ASSERT(string != nullptr);

    return printf("%s\n", string) - 1;
}


char * my_strchr(char * string, int character)
{
    MY_ASSERT(string != nullptr);

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
    MY_ASSERT(target != nullptr && source != nullptr);

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
    MY_ASSERT(target != nullptr && source != nullptr);

    size_t i = 0;

    while (target[i] != '\0')
        i++;

    size_t j = 0;

    while (source[j] != '\0' && j < string_length - 1)
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
    MY_ASSERT(file != nullptr && string != nullptr);

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
    MY_ASSERT(source != nullptr);

    char * target = (char *) calloc(my_strlen(source) + 1, sizeof(char));
    
    my_strcpy(target, source);

    return target;
}

ssize_t my_getline(char * * string, size_t * length, FILE * file)
{
    MY_ASSERT(file != nullptr && string != nullptr && length != nullptr);

    int character = 0;
    size_t i = 0;

    while ((character = fgetc(file)) != '\n' && character != EOF)
    {
            printf("current str: %s\n", *string);
            printf("current len: %zu\n", *length);

        if (i >= *length)
        {
            MY_ASSERT(i == *length);

            *length = i + 1;
            char * pointer = (char *) realloc(*string, *length);

            MY_ASSERT(pointer != nullptr);

            *string = pointer;

            printf("current str: %s\n", *string);
            printf("current len: %zu\n", *length);
        }

        MY_ASSERT(i <= *length);

        (*string)[i] = (char) character;
        i++;
    }

    (*string)[i] = '\0';

    return (ssize_t) *length;
}


char * strstr(const char * string1, const char * string2) // ????????????????????? CNST
{
    MY_ASSERT(string1 != nullptr && string2 != nullptr);

    size_t i = 0;
    size_t string1_length = my_strlen(string1);
    size_t string2_length = my_strlen(string2);
    IsLetters string2_letters[ALPHABET_SIZE] = {};
    int index = 0;

    get_string_letters(string2, string2_length, string2_letters);

    if (string1_length >= string2_length)
    {
        while (string1[i + string2_length - 1] != '\0')
        {
            if ((index = my_strncmp_index(&string1[i], string2, string2_length)) == 0)
            {
                return (char *) &string1[i];
            }
            else if (is_in_string(string1[i + index - 1], string2_letters))
            {
                while (string1[i + index] != string2[index - 1] && string1[i + string2_length - 1] != '\0')
                    i++;
            }
            else
            {
                i += index - 1;
            }

            i++;
        }
    }

    return NULL;

}


IsLetters * get_string_letters(const char * string, const size_t string_length, IsLetters * letters)
{
    size_t i = 0;
    IsLetters alphabet_letters[ALPHABET_SIZE] = {{'a', false},
                                                 {'b', false},
                                                 {'c', false},
                                                 {'d', false},
                                                 {'e', false},
                                                 {'f', false},
                                                 {'g', false},
                                                 {'h', false},
                                                 {'i', false},
                                                 {'j', false},
                                                 {'k', false},
                                                 {'l', false},
                                                 {'m', false},
                                                 {'n', false},
                                                 {'o', false},
                                                 {'p', false},
                                                 {'q', false},
                                                 {'r', false},
                                                 {'s', false},
                                                 {'t', false},
                                                 {'u', false},
                                                 {'v', false},
                                                 {'w', false},
                                                 {'x', false},
                                                 {'y', false},
                                                 {'z', false}};

    for (size_t j = 0; j < ALPHABET_SIZE; j++)
    {
        letters[j].letter = alphabet_letters[j].letter;
        letters[j].is_in_string = alphabet_letters[j].is_in_string;
    }

    while (i < string_length)
    {
        for (size_t j = 0; j < ALPHABET_SIZE; j++)
        {
            if (string[i] == letters[j].letter)
                letters[j].is_in_string = true;
        }

        i++;
    }

    return letters;
}


bool is_in_string (const char character, const IsLetters * string_letters)
{
    size_t i = 0;

    while (i < ALPHABET_SIZE)
    {
        if (character == string_letters[i].letter && string_letters[i].is_in_string == true)
            return true;

        i++;
    }

    return false;
}


int my_strcmp(const char * string1, const char * string2)
{
    MY_ASSERT(string1 != nullptr && string2 != nullptr);

    int i = 0;

    while (string1[i] != '\0')
    {
        if      (string1[i] > string2[i])
        {
            return 1;
        }   
        else if (string1[i] < string2[i])
        {
            return -1;
        }    
        else
            i++;
    }

    if (string2[i] == '\0')
        return 0;
    else 
        return -1;
}


int my_strncmp(const char * string1, const char * string2, const size_t length)
{
    MY_ASSERT(string1 != nullptr && string2 != nullptr);

    size_t i = 0;
    
    while (string2[i] != '\0' && i < length)
    {
        if      (string1[i] > string2[i])
        {
            return 1;
        }   
        else if (string1[i] < string2[i])
        {
            return -1;
        }    
        else
        {
            i++;
        }
    }

    return 0;
}


char * fget_str(FILE * file, char * string)
{
    size_t i = 0;
    int character = 0;

    while ((character = fgetc(file)) != '\n' && character != EOF)
    {
        string[i] = (char) character;
        i++;
    }

    return string;
}


int my_strncmp_index(const char * string1, const char * string2, const size_t length)
{
    MY_ASSERT(string1 != nullptr && string2 != nullptr);

    size_t i = 0;
    
    while (string2[i] != '\0' && i < length)
    {
        if (string1[i] != string2[i])
        {
            return i+1;
        }
        else
        {
            i++;
        }
    }

    return 0;
}