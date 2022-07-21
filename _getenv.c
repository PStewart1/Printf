#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *_getenv(const char *name)
{
        extern char **environ;
        int i = 0;
        char *var;

        while(environ[i])
        {
                if (strstr(environ[i], name))
                {
                        var = strchr(environ[i], '=');
                        return (++var);        
                }
                i++;
        }
        return (NULL);
}


/**
 * main - Super Simple Shell
 *
 * Return: Always 0.
 */
 
int main(int ac, char **av)
{
        char *var;
        
        if (ac != 2)
        {
                printf("USAGE: ./a.out VARIABLE_NAME\n");
                return (0);
        }
        var = _getenv(av[1]);
        if (var == NULL)
                printf("Variable not found\n");
        else
                printf("[%s] = [%s]\n", av[1], var);
        return (0);
}
