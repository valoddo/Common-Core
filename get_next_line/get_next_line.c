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

char	*get_next_line(int fd)
{
	static char	*file;
	char		*stamp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);	
	file = read(fd, file, BUFFER_SIZE);
	while (file != '\n' || file != )
	{

	}

}

int main()
{
	int		fd;
	char	*text;

	fd = open("file", O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (1);
	}
	text = get_next_line(fd);
	while (text != NULL)
	{
		printf("%s", text);
		free(text);
	}
	close(fd);
	return (0);
}