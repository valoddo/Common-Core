# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#include <stdio.h>    // Per printf, perror
#include <stdlib.h>   // Per free
#include <fcntl.h>    // Per O_RDONLY e open()
#include <unistd.h>   // Per close()

char    *get_next_line(int fd)
{
    char    *buffer;
    int     i = 0;
    int     r = 0;
    char    c;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(1000);
    if (!buffer)
        return (NULL);
    r = read(fd, &c, 1);
    while (r && c != '\n' && c != '\0')
    {
        buffer[i] = c;
        r = read(fd, &c, 1);
        i++;
    }
    if (!r && !i)
        return (free(buffer), NULL);
    if (c == '\n' && r > 0)
        buffer[i++] = '\n';
    buffer[i] = '\0';
    return (buffer);
}
