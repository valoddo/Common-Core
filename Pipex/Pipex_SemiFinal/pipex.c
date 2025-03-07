/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:28:47 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/28 13:28:50 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, int error)
{
	write(2, str, ft_strlen(str));
	exit(error);
}

char	**ft_get_path(char **envp)
{
	int		i;
	char	**temp;

	i = 0;
	while (envp[i])
	{
		if ((ft_strncmp(envp[i], "PATH=", 5) == 0))
		{
			temp = ft_split((envp[i] + 5), ':');
			return (temp);
		}
		i++;
	}
	ft_error("PATH not found", 1);
	return (NULL);
}

char	*check_args(char **paths, char *argcmd)
{
	char	*directory;
	char	*cmd;
	int		i;

	i = 0;
	while (paths[i])
	{
		directory = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(directory, argcmd);
		free(directory);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

void	child_process(t_pipex pipex, char **argv, char **envp, int child)
{
	if (child == 1)
	{
		dup2(pipex.pipe_fd[1], STDOUT_FILENO);
		dup2(pipex.infd, 0);
		close(pipex.pipe_fd[1]);
		close(pipex.infd);
		pipex.arg_cmd = ft_split(argv[2], ' ');
	}
	else
	{
		dup2(pipex.pipe_fd[0], STDIN_FILENO);
		dup2(pipex.outfd, 1);
		close(pipex.pipe_fd[0]);
		close(pipex.outfd);
		pipex.arg_cmd = ft_split(argv[3], ' ');
	}
	if (!pipex.arg_cmd || !pipex.arg_cmd[0])
		ft_error("Command not found", 1);
	pipex.cmd = check_args(pipex.paths, pipex.arg_cmd[0]);
	if (!pipex.cmd)
		ft_error("Command not valid", 1);
	execve(pipex.cmd, pipex.arg_cmd, envp);
	if (execve(pipex.cmd, pipex.arg_cmd, envp) == -1) 
	ft_error("Execve failed", 1);
	free_cmd_and_args(pipex.arg_cmd, pipex.cmd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error("Argument missed", 1);
	pipex.paths = ft_get_path(envp);
	pipex.infd = open(argv[1], O_RDONLY);
	if (pipex.infd == -1)
		ft_error("Error file intput", 1);
	pipex.outfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfd == -1)
		ft_error("Error file output", 1);
	if (pipe(pipex.pipe_fd) == -1)
		ft_error("Error Pipe", 1);
	pipex.p_id = fork();
	if (pipex.p_id == 0)
		child_process(pipex, argv, envp, 1);
	close(pipex.pipe_fd[1]);
	pipex.p_id_2 = fork();
	if (pipex.p_id_2 == 0)
		child_process(pipex, argv, envp, 2);
	close(pipex.pipe_fd[0]);
	waitpid(pipex.p_id, NULL, 0);
	waitpid(pipex.p_id_2, NULL, 0);
	close(pipex.infd);
	close(pipex.outfd);
	return (0);
}
