#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct list_s
{
	char *path;
	unsigned int num;
	struct list_s *next;
} list_t;

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


list_t *add_node_end(list_t **head, const char *str, unsigned int num)
{
	list_t *node = malloc(sizeof(list_t));
	list_t *last;

	if (node == NULL)
		return (NULL);

	node->path = strdup(str);
	node->num = num;
	node->next = NULL;
	if (*head == NULL)
		*head = node;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;

		last->next = node;
	}
	return (node);
}

list_t *_path_list()
{
        int i;
        char *str, *line = _getenv("PATH");
        list_t *head = NULL;

        for (i = 0; ; i++, line = NULL) {
                str = strtok(line, ":");
                if (str == NULL)
                        break;
                add_node_end(&head, str, i);
        }
        return (head);
}

/**
 * main - Super Simple Shell
 *
 * Return: Always 0.
 */
 
int main()
{
        list_t *h;

        h = _path_list();
	while (h != NULL)
	{
		if (h->path == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", h->num, h->path);
		}
		h = h->next;
	}
        
        return (0);
}
