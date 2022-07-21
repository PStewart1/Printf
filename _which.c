#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Super Simple Shell
 *
 * Return: Always 0.
 */
 
int main(void)
{
        char *line = NULL;
        size_t len = 0;
        /*ssize_t nread;*/
        pid_t pid;
        char *argv[2] /* = {"/bin/ls", "-l", "/tmp", NULL}*/ ;
        char *saveptr;
        int i, status;


        while (1)
        {
                pid = fork();
                if (pid == 0)
                {
                        
                        printf("#cisfun$ ");
                        /*nread =*/ getline(&line, &len, stdin);
                        for (i = 0; ; i++, line = NULL)
                        {
                                argv[i] = strtok_r(line, " \n", &saveptr);
                                if (argv[i] == NULL)
                                break;
                        }
                        if (strchr(argv[0], '/') == NULL)
                        {
                                argv[1] = argv[0];
                                argv[0] = "/usr/bin/which";
                                argv[2] = NULL;
                                printf("Command location: ");
                        }
                        status = execve(argv[0], argv, NULL);
                        printf("Status: %d\n", status);
                        return (0);
                }
                else
                        wait(NULL);
        }

        free(line);
        return (0);
}
