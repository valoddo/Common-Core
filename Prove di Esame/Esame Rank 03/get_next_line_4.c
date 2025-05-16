# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *string)
{
	const char	*last_char_in_string;

	if (!string)
		return (0);
	last_char_in_string = string;
	while (*last_char_in_string)
		last_char_in_string++;
	return (last_char_in_string - string);
}

char	*ft_strchr(char *string, int character)
{
	while (*string)
	{
		if (*string == (char)character)
			return (string);
		string++;
	}
	return (NULL);
}

char	*ft_strcpy(char *destination, char *source)
{
	char	*destination_copy;

	destination_copy = destination;
	while (*source)
	{
		*destination_copy = *source;
		destination_copy++;
		source++;
	}
	*destination_copy = '\0';
	return (destination);
}

char	*ft_strdup(char *source)
{
	size_t	length_source;
	char	*duplicate;

	// duplicate = NULL;
	// length_source = 0x0;
	length_source = ft_strlen(source);
	duplicate = (char *)malloc(sizeof(char) * (length_source + 0x1));
	if (duplicate == NULL)
		return (NULL);
	ft_strcpy(duplicate, source);
	return (duplicate);
}

char	*ft_strjoin(char *string_1, char *string_2)
{
	char	*joined_strings;
	size_t	length_string_1;
	size_t	length_string_2;

	if (!string_1 || !string_2)
	{
		free(string_1);
		return (NULL);
	}
	length_string_1 = ft_strlen(string_1);
	length_string_2 = ft_strlen(string_2);
	joined_strings = (char *)malloc(sizeof(char) * \
		((length_string_1 + length_string_2) + 1));
	if (!joined_strings)
	{
		free(string_1);
		return (NULL);
	}
	ft_strcpy(joined_strings, string_1);
	ft_strcpy(joined_strings + length_string_1, string_2);
	free(string_1);
	return (joined_strings);
}

char	*ft_read_line(int fd, char *line, char *buffer)
{
	ssize_t	bytes_read;
	char	*new_line_in_line;

	bytes_read = 0;
	new_line_in_line = NULL;
	while (!new_line_in_line)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		new_line_in_line = ft_strchr(line, '\n');
	}
	if (!line || ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_update_buffer_and_line(char *buffer, char *new_line_in_line)
{
	if (new_line_in_line)
	{
		ft_strcpy(buffer, new_line_in_line + 1);
		*(new_line_in_line + 1) = '\0';
	}
	else
		buffer[0] = '\0';
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*new_line_in_line;
	static char	buffer[BUFFER_SIZE + 1];

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	line = ft_strdup(buffer);
	line = ft_read_line(fd, line, buffer);
	if (!line)
		return (NULL);
	new_line_in_line = ft_strchr(line, '\n');
	ft_update_buffer_and_line(buffer, new_line_in_line);
	return (line);
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int     fd;
    char    *line;
    int     line_count = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", ++line_count, line);
        free(line);
    }

    close(fd);
    return 0;
}