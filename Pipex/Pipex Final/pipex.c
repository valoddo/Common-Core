#include "pipex.h"

static char	**ft_get_path(char **envp)
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
	ft_error("Path", 4);
	return (NULL);
}

static char	*check_args(char **paths, char *argcmd)
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

static void	first_child_process(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pipe_fd[1], STDOUT_FILENO);
	dup2(pipex.infd, 0);
	close(pipex.pipe_fd[1]);
	close(pipex.infd);
	pipex.arg_cmd = ft_split(argv[2], ' ');
	if (!pipex.arg_cmd || !pipex.arg_cmd[0])
		ft_error("Cmd", 3);
	pipex.cmd = check_args(pipex.paths, pipex.arg_cmd[0]);
	if (!pipex.cmd)
		ft_error("Cmd", 3);
	execve(pipex.cmd, pipex.arg_cmd, envp);
	if (execve(pipex.cmd, pipex.arg_cmd, envp) == -1)
	{
		free_cmd_and_args(pipex.arg_cmd, pipex.cmd);
		ft_error("zsh", 1);
	}
}

static void	second_child_process(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pipe_fd[0], STDIN_FILENO);
	dup2(pipex.outfd, 1);
	close(pipex.pipe_fd[0]);
	close(pipex.outfd);
	pipex.arg_cmd = ft_split(argv[3], ' ');
	if (!pipex.arg_cmd || !pipex.arg_cmd[0])
		ft_error("Cmd", 3);
	pipex.cmd = check_args(pipex.paths, pipex.arg_cmd[0]);
	if (!pipex.cmd)
		ft_error("Cmd", 3);
	execve(pipex.cmd, pipex.arg_cmd, envp);
	if (execve(pipex.cmd, pipex.arg_cmd, envp) == -1)
	{
		free_cmd_and_args(pipex.arg_cmd, pipex.cmd);
		ft_error("zsh", 1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error("Main", 2);
	pipex.paths = ft_get_path(envp);
	pipex.infd = open(argv[1], O_RDONLY);
	pipex.outfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.infd == -1 || pipex.outfd == -1)
		ft_error("zsh", 1);
	if (pipe(pipex.pipe_fd) == -1)
		ft_error("zsh", 1);
	pipex.p_id = fork();
	if (pipex.p_id == 0)
		first_child_process(pipex, argv, envp);
	close(pipex.pipe_fd[1]);
	pipex.p_id_2 = fork();
	if (pipex.p_id_2 == 0)
		second_child_process(pipex, argv, envp);
	close(pipex.pipe_fd[0]);
	waitpid(pipex.p_id, NULL, 0);
	waitpid(pipex.p_id_2, NULL, 0);
	close(pipex.infd);
	close(pipex.outfd);
	return (0);
}
