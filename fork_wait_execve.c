#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

    child_pid = fork();
    if (child_pid == 0)
    {
        execve(argv[0], argv, NULL);
        return (0);
    }
    else
        wait(NULL);
        
    child_pid = fork();
    if (child_pid == 0)
    {
        execve(argv[0], argv, NULL);
        return (0);
    }
    else
        wait(NULL);
        
    child_pid = fork();
    if (child_pid == 0)
    {
        execve(argv[0], argv, NULL);
        return (0);
    }
    else
        wait(NULL);
        
    child_pid = fork();
    if (child_pid == 0)
    {
        execve(argv[0], argv, NULL);
        return (0);
    }
    else
        wait(NULL);
        
    child_pid = fork();
    if (child_pid == 0)
    {
        execve(argv[0], argv, NULL);
        return (0);
    }
    else
        wait(NULL);
        
    printf("Done\n");
    return (0);
}
