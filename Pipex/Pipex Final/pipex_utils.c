#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	final = malloc(sizeof(char) * (i + j + 1));
	if (!final)
		return (NULL);
	final[i + j] = '\0';
	while (j > 0)
	{
		j--;
		final[i + j] = s2[j];
	}
	while (i > 0)
	{
		i--;
		final[i] = s1[i];
	}
	return (final);
}

void ft_free_split(char **split_array)
{
    int i;

    if (!split_array)
        return;
    i = 0;
    while (split_array[i] != NULL)
    {
        free(split_array[i]);
        i++;
    }
    free(split_array);
}

void	ft_error(char *str, int error)
{
	if (error == 2)
	{
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
		exit(EXIT_FAILURE);
	}
	else if (error == 3)
	{
		write(2, "zsh: Command not found\n", 24);
		exit(EXIT_FAILURE);
	}
	else if (error == 4)
	{
		write(2, "zsh: Path not set\n", 19);
		exit(EXIT_FAILURE);
	}
	else
	{
		perror(str);
		exit(error);
	}
}


	{
		perror(str);
		exit(error);
	}
}
