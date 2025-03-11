/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:03:36 by vloddo            #+#    #+#             */
/*   Updated: 2025/01/13 13:03:41 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_read(int fd, char **buffer)
{
	char		*temp;
	char		*read_buffer;
	ssize_t		byte_read;

	read_buffer = malloc((BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	byte_read = read(fd, read_buffer, BUFFER_SIZE);
	if (byte_read < 0)
	{
		free(read_buffer);
		return (NULL);
	}
	if (byte_read == 0)
	{
		free(read_buffer);
		return (*buffer);
	}
	read_buffer[byte_read] = '\0';
	temp = *buffer;
	*buffer = ft_strjoin(*buffer, read_buffer);
	free(read_buffer);
	free (temp);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	char		*temp;
	char		*prev_buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	buffer[fd] = ft_read(fd, &buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	prev_buffer[fd] = NULL;
	while (!ft_newline(buffer[fd]) && prev_buffer[fd] != buffer[fd])
	{
		prev_buffer[fd] = buffer[fd];
		buffer[fd] = ft_read(fd, &buffer[fd]);
	}
	line = ft_line(buffer[fd]);
	temp = buffer[fd];
	buffer[fd] = ft_substr(buffer[fd], ft_strlen(line), \
	ft_strlen(buffer[fd]) - ft_strlen(line));
	free(temp);
	return (line);
}

// int	main()
// {
// 	int		fd;
// 	char	*text;

// 	fd = open("read_error.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error");
// 		return (1);
// 	}
// 	text = get_next_line(fd);
// 	while (text)
// 	{
// 		printf("%s", text);
// 		free(text);
// 		text = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }

int  main(int argc, char **argv)
{
    int     fd;
    int     fd2;
    int     fd3;
	char *line;
	char *line2;
	char *line3;

	if(argc == 1000000)
		return (0);

    fd = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    fd3 = open(argv[3], O_RDONLY);
    
    line = get_next_line(fd);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
    while (line || line2 || line3)
    {
		printf("%s", line);
		printf("%s", line2);
		printf("%s", line3);
		free(line);
		free(line2);
		free(line3);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		line = get_next_line(fd);
	}
    close(fd);
    close(fd2);
    close(fd);
    return (0);
} 
