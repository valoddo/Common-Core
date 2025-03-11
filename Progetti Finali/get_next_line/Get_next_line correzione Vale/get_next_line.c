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

#include "get_next_line.h"

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

static char	*ft_read(int fd, char *buffer)
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
		return (buffer);
	}
	read_buffer[byte_read] = '\0';
	temp = buffer;
	buffer = ft_strjoin(buffer, read_buffer);
	free(read_buffer);
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	char		*prev_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	prev_buffer = NULL;
	while (!ft_newline(buffer) && prev_buffer != buffer)
	{
		prev_buffer = buffer;
		buffer = ft_read(fd, buffer);
	}
	line = ft_line(buffer);
	temp = buffer;
	buffer = ft_substr(buffer, ft_strlen(line), \
	ft_strlen(buffer) - ft_strlen(line));
	free(temp);
	return (line);
}

int	main()
{
	int		fd;
	char	*text;

	fd = open("pippo.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (1);
	}
	text = get_next_line(fd);
	while (text)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
	}
	close(fd);
	return (0);
}

// int  main(int argc, char **argv)
// {
//     int     fd;

//     fd = open(argv[1], O_RDONLY);
//     if (argc != 2)
//     {
//         write(1, "\n", 1);
//         return (1);
//     }
//     else
//     {
//         char *line = get_next_line(fd);
//         while (line)
//         {
//             printf("[%s]", line);
//             free(line);
//             line = get_next_line(fd);
//         }
//     	//get_next_line(fd);
//     //    get_next_line(fd);
//     }
//     close(fd);    
//     return (0);
// } 
