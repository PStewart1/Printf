#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern char **environ;

int _unsetenv(const char *name) 
{
    char **ep;
    size_t nameLength;
    char **moveEnvPointersDown;

    if (name == NULL) 
    {
        errno = EINVAL;
        return -1;
    }
    
    nameLength = strlen(name);
    for (ep = environ; *ep != NULL; ep++)
    {
        /*
         * Validate that the string compares match for the name and nameLength, i.e. just the key part of the
         * environment variable, also validate that the equals sign is at the nameLength field validating it is like
         * so:
         * USER=
         * Rather than a false positive like:
         * USERTWO=
         */
        if (!strncmp(*ep, name, nameLength) && (*ep)[nameLength] == '=')
        {
            /*
             * Move all the environment variable pointers down in the environment char array
             */
            moveEnvPointersDown = ep;
            /*
             * Move all the pointers back one, for example
             * unsetEnvPointer[0] -> enviornmentVariableCharPointer[0] -> char[0..n] -> KEY=VALUE, whiteboarding
             * this logic helps.
             */
            do {
                moveEnvPointersDown[0] = moveEnvPointersDown[1];
            }
            while(*moveEnvPointersDown++);
        }
    }
    return 0;
}
