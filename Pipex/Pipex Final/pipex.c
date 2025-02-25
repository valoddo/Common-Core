#include "pipex.h"

void	ft_error(char *str, int error)
{
	perror(str);
	exit(error);
}
char	**ft_get_path(char **envp)
{
	int		i;
	char	**temp;

	i = 0;
	while (envp[i])
	{
		if ((ft_strncmp(envp[i], "PATH=", 5) == 0))  //trova la variabile PATH tra le variabili d'ambiente
		{
			temp = ft_split((envp[i] + 5), ':'); //crea un array he contiene la lista di directory contenente i file eseguibili dei comandi che possono essere eseguiti nel terminale.
			return (temp);
		} 
		i++;
	}
	ft_error("PATH not found", 1);
	return (NULL);
}
char *check_args(char **paths, char *argcmd)
{
	char	*directory;
	char	*cmd;

	while (*paths) // Itera su ogni directory in paths
	{
		directory = ft_strjoin(*paths, "/"); // Crea il percorso della directory con una barra finale
		cmd = ft_strjoin(directory, argcmd); // Aggiunge il nome del comando al percorso
		free(directory); // Libera la memoria allocata per directory
		if (access(cmd, X_OK) == 0) // Verifica se il comando è eseguibile
			return (cmd); // Restituisce il percorso completo del comando
		free(cmd); // Libera la memoria allocata per cmd se non è eseguibile
		paths++; // Passa alla prossima directory
    }
    return (NULL); // Nessun comando valido trovato
}
void	child_process(t_pipex pipex, char **argv, char **envp, int child)
{
	if (child == 1)
	{
		dup2(pipex.pipe_fd[1], STDOUT_FILENO); // Redireziona stdout → pipe[1]
		dup2(pipex.infd, 0);                   // Redireziona stdin → input.txt
		close(pipex.pipe_fd[1]);               // Chiude pipe[1] (duplicato in stdout)
		close(pipex.infd);                     // Chiude input.txt (duplicato in stdin)
		pipex.arg_cmd = ft_split(argv[2], ' '); // Divide il comando in argomenti
	}
	else 
	{
		dup2(pipex.pipe_fd[0], STDIN_FILENO);  // Redireziona stdin → pipe[0]
		dup2(pipex.outfd, 1);                  // Redireziona stdout → output.txt
		close(pipex.pipe_fd[0]);               // Chiude pipe[0] (duplicato in stdin)
		close(pipex.outfd);                    // Chiude output.txt (duplicato in stdout)
		pipex.arg_cmd = ft_split(argv[3], ' '); // Divide il comando in argomenti
	}
	if (!pipex.arg_cmd || !pipex.arg_cmd[0]) // Controlla se il comando è vuoto o non valido
    	ft_errors("Command not found", 1);
	pipex.cmd = check_args(pipex.paths, pipex.arg_cmd[0]); // Cerca il comando in PATH
	if (!pipex.cmd) // Se il comando non è valido, gestisci l'errore
		ft_errors("Command not valid", 1);
	execve(pipex.cmd, pipex.arg_cmd, envp); // Esegue il comando
}
int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error("Argument missed", 1);
	pipex.path = ft_get_path(envp);
	pipex.infd = open(argv[1], O_RDONLY);
	if (pipex.infd == -1)
		ft_error(argv[1], 1);
	pipex.outfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); // O_TRUNC: Se il file esiste già, la sua dimensione viene ridotta a zero (cioè il contenuto viene cancellato) prima di iniziare a scrivere. 0: Il tipo di file (che è regular file), 6: Permessi del proprietario del file: lettura (4) e scrittura (2), quindi 6 significa "lettura e scrittura", 4: Permessi del gruppo del file: solo lettura, 4: Permessi per altri utenti: solo lettura
	if (pipex.outfd == -1)
		ft_error(argv[4], 1);
	if (pipe(pipex.pipe_fd) == -1)
		ft_errors("Error Pipe", 1);
	pipex.p_id = fork();
	if (pipex.p_id == 0)
		child_process(pipex, argv, envp, 1);
	pipex.p_id_2 = fork();
	if (pipex.p_id_2 == 0)
		child_process(pipex, argv, envp, 2);
	waitpid(pipex.p_id, NULL, 0);
	waitpid(pipex.p_id_2, NULL, 0);
	close(pipex.infd);
	close(pipex.outfd);
	return (0);
}

