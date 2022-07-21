#include <stdio.h>
#include <unistd.h>

/**
 * main - Super Simple Shell
 *
 * Return: Always 0.
 */
 
int main()
{
        extern char **environ;
        int i = 0;
        
        while(environ[i])
        {
                printf("%s\n", environ[i++]);
        }
        return (0);
}
