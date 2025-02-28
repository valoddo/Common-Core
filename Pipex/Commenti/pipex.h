/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:29:24 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/28 13:29:27 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		infd; //descrittore di file per input
	int		outfd; //descrittore di file per output
	int		p_id; //ID del primo processo figlio (PID)
	int		p_id_2; //ID del secondo processo figlio (PID)
	int		pipe_fd[2]; //file descriptor per la pipe (array pipe_fd contiene 2 fd: pipe_fd[0] descrittore del file per la lettura, pipe_fd[1] descrittore del file per la scrittura)
	char	*cmd; //comando da eseguire
	char	**arg_cmd; //argomenti del comando (array di stringhe)
	char	**paths; //array di percorsi da cercare per i comandi 
}			t_pipex;

void	child_process(t_pipex pipex, char **argv, char **envp, int child);
char	*check_args(char **paths, char *argcmd);
char	**ft_get_path(char **envp);
void	ft_error(char *str, int error);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	**ft_split(const char *s, char c);
static int	count_words(const char *s, char c);

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *a);
#endif
