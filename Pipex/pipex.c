/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:28:54 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/12 18:29:00 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main( int argc, char ** argv)
{
	int	fd[2];
	int	pid1;
	
	if (argc != 5)
		return (0);
	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	waitpid(pid1, NULL, 0); 
	return (0);
}
