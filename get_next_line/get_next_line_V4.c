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

int	ft_newline(char *buffer)
{
	int i;
	int j;

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
	char *final;
	int	i;

	if (lenline >= ft_strlen(buffer))
		return (NULL);
	final = malloc(sizeof(char) * (lenbuffer + 1));
	if (!final)
		return (NULL);
	i = 0;
	while(i < lenbuffer)
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
		return(NULL);
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
	return	(final);
}


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}


static char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n') // Conta i caratteri fino a \n o fine del buffer
		i++;
	line = malloc(sizeof(char) * (i + 2)); // Alloca memoria per la linea (+1 per \n e +1 per terminatore \0)
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n') // Copia i caratteri nella nuova linea
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n') 	// Aggiungi il \n se presente
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0'; // Termina la stringa
	return (line);
}

static char	*ft_read(int fd, char *buffer)
{
	char		*temp;
	char		*read_buffer;
	ssize_t		byte_read;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
	read_buffer[byte_read] = '\0'; // Termina la stringa
	temp = buffer;
	buffer = ft_strjoin(buffer, read_buffer); //aggiorna buffer aggiungendo i nuovi caratteri letti 
	free(read_buffer);
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
			return (NULL);
	//printf("\nPrima Lettura: %s\n", buffer);
	while (!ft_newline(buffer)) // Continua a leggere finché non trovi un '\n'
	{	
		buffer = ft_read(fd, buffer);
	}
	//printf("\nLettura dopo il while: %s\n", buffer);
	//printf("\nPrint Line: %s\n", line);
	line = ft_line(buffer); // Estrai la linea dal buffer
	temp = buffer; // Alias: puntatore che punta alla stessa area di memoria di buffer e serve per liberare l'area di memoria di buffer alla fine
	buffer = ft_substr(buffer, ft_strlen(line), ft_strlen(buffer) - ft_strlen(line)); //aggiorna il buffer con i caratteri rimanenti dopo \n
	//printf("\nFinal Buffer: %s\n", buffer);
	free(temp);
	return(line);
}
// int main()
// {
// 	char *str;
// 	char *str2;
// 	char *str3;
// 	char *str4;
// 	char *final;
	
// 	str = "ciao";
// 	str2 = "a tutti";
// 	str3 = "ciao\na tutti";
// 	str4 = "ciao a tutti";
// 	final = ft_line(str4);
// 	printf("%s", final);
// 	return(0);
// }


// int	main(void)
// {
// 	int		fd;
// 	char	*text;

// 	fd = open("file.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error");
// 		return (1);
// 	}
// 	text = get_next_line(fd);
// 	while (text)
// 	{
// 		printf("[%s]", text);
// 		free(text);
// 		text = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }

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
