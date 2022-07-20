	#include <stdio.h>
	#include <stdlib.h>
        #include <unistd.h>

       int main()
       {
           char *line = NULL;
           size_t len = 0;
           ssize_t nread;

           printf("$ ");
           nread = getline(&line, &len, stdin);
           write(1, line, nread);
          

           free(line);
           exit(EXIT_SUCCESS);
       }
