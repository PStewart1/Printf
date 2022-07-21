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


void _path()
{
        int i;
        char *token, *line = _getenv("PATH");
        
        
        for (i = 0; ; i++, line = NULL) {
                token = strtok(line, ":");
                printf("%s\n", token);
                if (token == NULL)
                        break;
        }
}
