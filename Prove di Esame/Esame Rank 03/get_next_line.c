# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#include <stdio.h>    // Per printf, perror
#include <stdlib.h>   // Per free
#include <fcntl.h>    // Per O_RDONLY e open()
#include <unistd.h>   // Per close()

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer);
char	*ft_line(char *buffer);
int		ft_newline(char *buffer);
char	*ft_substr(char *buffer, int lenline, int lenbuffer);
char	*ft_strjoin(char *buffer, char *read_buffer);
int		ft_strlen(char *str);

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

char	*ft_read(int fd, char *buffer)
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

char	*ft_line(char *buffer)
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
int	ft_newline(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char *buffer, int lenline, int lenbuffer)
{
	char	*final;
	int		i;

	if (lenline >= ft_strlen(buffer))
		return (NULL);
	final = malloc(sizeof(char) * (lenbuffer + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (i < lenbuffer)
	{
		final[i] = buffer[lenline + i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

char	*ft_strjoin(char *buffer, char *read_buffer)
{
	char	*final;
	int		i;
	int		j;

	if (!buffer)
		buffer = "";
	i = ft_strlen(buffer);
	j = ft_strlen(read_buffer);
	final = malloc(sizeof(char) * (i + j + 1));
	if (!final)
		return (NULL);
	final[i + j] = '\0';
	while (j > 0)
	{
		j--;
		final[i + j] = read_buffer[j];
	}
	while (i > 0)
	{
		i--;
		final[i] = buffer[i];
	}
	return (final);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	main()
{
	int		fd;
	char	*text;

	fd = open("read_error.txt", O_RDONLY);
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