#include <stdio.h>
#include <ctype.h>

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


char * my_strchr(const char * string, int character)
{
    MY_ASSERT(string != nullptr);

    int i = 0;
    
    while (string[i] != '\0')
    {
        if (string[i] == character)
            return const_cast <char *> (&string[i]);
        
        i++;
    }

    if (character == '\0')
        return const_cast <char *> (&string[i]);

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

    char * target = nullptr;
    if ((target = (char *) calloc(my_strlen(source) + 1, sizeof(char))) == NULL)
    {
        return NULL;
    }
    
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
        if (i >= *length)
        {
            MY_ASSERT(i == *length);

            *length = i + 1;
            char * pointer = nullptr; 
            if ((pointer = (char *) realloc(*string, *length)) == NULL)
            {
                return NULL;
            }

            *string = pointer;
        }

        MY_ASSERT(i <= *length);

        (*string)[i] = (char) character;
        i++;
    }

    (*string)[i] = '\0';

    return (ssize_t) *length;
}


char * my_strstr(const char * string1, const char * string2)
{
    MY_ASSERT(string1 != nullptr && string2 != nullptr);

    size_t i = 0;
    size_t string1_length = my_strlen(string1);
    size_t string2_length = 0;
    bool string2_letters[ALPHABET_SIZE] = {};
    int character_number = 0;

    while (string2[string2_length] != '\0')
    {
        string2_length++;

        string2_letters[(size_t) string2[i] - 'a'] = true;
    }

    if (string1_length >= string2_length)
    {
        while (i < string1_length - string2_length + 1)
        {
            for (size_t j = 0; j < string2_length; j++)
            {
                if (string1[i + j] != string2[j])
                {
                    character_number = j + 1;

                    break;
                }
            
                character_number = 0;    
            }

            if (character_number == 0)
            {
                return const_cast<char *> (&string1[i]);
            }
            else if (is_in_string(string1[i + character_number - 1], string2_letters))
            {
                while (string1[i + character_number] != string2[character_number - 1] && i < string1_length - string2_length + 1)
                    i++;
            }
            else
            {
                i += character_number;
                continue;
            }

            i++;
        }
    }

    return NULL;
}


bool is_in_string (const char character, const bool * string_letters)
{
    return string_letters[(size_t) tolower(character) - 'a'];
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