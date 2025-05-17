/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:29:11 by lmenoni           #+#    #+#             */
/*   Updated: 2025/03/19 15:29:13 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char *get_remain(char *s)
{
    int i = 0;
    int j = 0;
    char *r;

    while (s[i] != '\n' && s[i] != '\0')
        i++;
    if (s[i] == '\n')
        i++;
    if (s[i] == '\0')
        return (free(s), NULL);
    while (s[i + j] != '\0')
        j++;
    r = malloc((j + 1) * sizeof(char));
    if (!r)
        return (free(s), NULL);
    j = 0;
    while (s[i] != '\0')
    {
        r[j] = s[i];
        j++;
        i++;
    }
    r[j] = '\0';
    free(s);
    return (r);
}

char *get_line(char *s)
{
    int i = 0;
    char *r;

    while (s[i] != '\n' && s[i] != '\0')
        i++;
    if (s[i] == '\n')
        i++;
    r = malloc((i + 1) * sizeof(char));
    i = 0;
    while (s[i] != '\n' && s[i] != '\0')
    {
        r[i] = s[i];
        i++;
    }
    if (s[i] == '\n')
    {
        r[i] = '\n';
        i++;
    }
    r[i] = '\0';
    return (r);
}

char *buff_join(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int len = 0;
    char *r;

    while (s1 && s1[i] != '\0')
        i++;
    while (s2 && s2[j] != '\0')
        j++;
    len = i + j;
    r = malloc((len + 1) * sizeof(char));
    if (!r)
        return (NULL);
    i = 0;
    j = 0;
    while (s1 && s1[i] != '\0')
    {
        r[i] = s1[i];
        i++;
    }
    while (s2 && s2[j] != '\0')
    {
        r[i + j] = s2[j];
        j++;
    }
    r[i + j] = '\0';
    free(s1);
    return (r);
}

char *get_next_line(int fd)
{
    static char *archive;
    char *line;
    char *buffer;
    int byte = -1;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    while (byte != 0)
    {
        byte = read(fd, buffer, BUFFER_SIZE);
        if (byte == -1)
            return (free(buffer), NULL);
        buffer[byte] = 0;
        archive = buff_join(archive, buffer);
        if (byte == 0 && archive[0] == '\0')
            return (free(archive), free(buffer), NULL);
    }
    free(buffer);
    line = get_line(archive);
    archive = get_remain(archive);
    return (line);
}

int main()
{
    int fd = open("infile", O_RDONLY);
    char *line = "ciao";

    while (line)
    {
        line = get_next_line(fd);
        if (line)
        {
            printf("%s", line);
            free(line);
        }
    }
    close(fd);
    return (0);
}
