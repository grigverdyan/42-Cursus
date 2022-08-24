#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
char *get_next_line(int fd)
{
    int 	i = 0;
    int 	bytes = 0;
    char	character;
    char 	*buffer = malloc(10000);

    while ((bytes = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!buffer[i - 1] && !bytes) || bytes == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] =  '\0';
    return(buffer);
}

int main()
{
    char *line;
    while(1)
    {
        line = malloc(1000);
        line = get_next_line(0);
        printf("%s", line);
        free(line);
    }
}
