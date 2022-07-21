#include <stdio.h>

/**
 * main - Super Simple Shell
 *
 * Return: Always 0.
 */
 
int main(int ac, char **av, char **env)
{
        extern char **environ;
        int i = 0;
        
        printf("ENVIRON:\n");
        while(environ[i])
        {
                printf("%s\n", environ[i++]);
        }
        printf("\n");
        
        printf("ENV:\n");
        i = 0;
        while(env[i])
        {
                printf("%s\n", env[i++]);
        }
        (void)ac;
        (void)av;
        return (0);
}
