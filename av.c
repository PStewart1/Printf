#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */

int main(int ac, char *av[])
{
	int i;

	for (i = 0; *av[i] != '\0'; i++)
	{
		printf("%s\n", av[i]);
	}
	printf("[%d]\n", ac);
	return (0);
}
