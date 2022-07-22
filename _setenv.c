#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
    register char **ep = 0;
    const size_t nameLength = strlen(name);
    const size_t valueLength = strlen(value) + 1;
    size_t totalLength, size = 0;
    char *new_string;
    
    for (ep = environ; *ep != NULL; ep++) 
    {
        if (strncmp(*ep, name, nameLength) >= 0 && (*ep)[nameLength] == '=') 
        {
            if (overwrite)
                break;
            else
                return 0;
        }
        size++;
    }
    if (environ == NULL || *ep == NULL) 
    {
        char *newEnvironmentVariable = malloc(nameLength + valueLength + 1);
        memcpy(newEnvironmentVariable, name, nameLength);
        newEnvironmentVariable[nameLength] = '=';
        memcpy(&newEnvironmentVariable[nameLength + 1], value, valueLength);

        return putenv(newEnvironmentVariable);
    } 
    else if (overwrite) 
    {
        totalLength = strlen (*ep);
        if (totalLength + 1 < nameLength + 1 + valueLength) 
        {
            new_string = (char *) malloc (nameLength + 1 + valueLength);
            if (new_string == NULL) 
                return -1;
            *ep = new_string;
        }
        memcpy (*ep, name, nameLength);
        (*ep)[nameLength] = '=';
        memcpy (&(*ep)[nameLength + 1], value, valueLength);
    }
    return 0;
}
