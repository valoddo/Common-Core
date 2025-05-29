/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/28 12:50:15 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_token(const char *input)
{
	int	count;
	
	count = 0;
	while (*input)
	{
		while (*input == ' ') // Salta spazi iniziali
			input++;
		if (*input == '\0')  // fine stringa
			break;
		if (*input == '\'')  // quote singola
		{
			input++;
			while (*input && *input != '\'')
				input++;
			if (*input == '\'')
				input++;
			else
				ft_error("Unclosed single quote"); //Errore in caso single quote non e chiusa
			count++;
		}
		else if (*input == '\"')  // quote doppia
		{
			input++;
			while (*input && *input != '\"')
				input++;
			if (*input == '\"')
				input++;
			else
				ft_error("Unclosed double quote"); //Errore in caso double quote non e chiusa
			count++;
		}
		else if (*input == '|' || *input == '<' || *input == '>')  // conta i metacaratteri
		{
			if ((*input == '<' && *(input + 1) == '<') || (*input == '>' && *(input + 1) == '>'))
				input += 2;
			else
				input++;
			count++;
		}
		else  // token normale
		{
			while (*input && *input != ' ' && *input != '\'' && *input != '\"' && *input != '|' && *input != '<' && *input != '>')
				input++;
			count++;
		}
	}
	return (count);
}


static void	ft_free(char **s, int i)
{
	while (i-- > 0)
		free(s[i]);
	free(s);
}

static int	token_len(const char *input, unsigned int start)
{
	int	len;
	
	len = 0;
	if (input[start] == '\'') // single quote
	{
		len++; // includi la quote iniziale
		start++;
		while (input[start + len - 1] && input[start + len - 1] != '\'')
			len++;
	}
	else if (input[start] == '\"') // double quote
	{
		len++; // includi la quote iniziale
		start++;
		while (input[start + len - 1] && input[start + len - 1] != '\"')
			len++;
	}
	else if (input[start] == '|' || input[start] == '<' || input[start] == '>')
	{
		if ((input[start] == '<' && input[start + 1] == '<') || (input[start] == '>' && input[start + 1] == '>'))
			return 2;
		else
			return 1;
	}
	else
	{
		while (input[start + len] && input[start + len] != ' ' && input[start + len] != '\'' &&
				input[start + len] != '\"' && input[start + len] != '|' && input[start + len] != '<' &&
				input[start + len] != '>')
				len++;
	}
	return (len);
}

static char	**fill_token(char **dest, const char *input, int token)
{
	int	i;
	int	j;
	int	len;
	int	k;

	i = 0;
	j = 0;
	while (i < token)
	{
		while (input[j] == ' ') // Salta spazi
			j++;
		len = token_len(input, j);
		dest[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!dest[i])
			return (ft_free(dest, i), NULL);
		k = 0;
		while (k < len)
		{
			dest[i][k] = input[j + k];
			k++;
		}
		dest[i][k] = '\0';
		j += len;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

static char	**ft_tokenize(const char *input)
{
	char	**dest;
	int		token;

	if (!input)
		return (NULL);
	token = count_token(input);
	if (token <= 0)
		return (NULL);  // gestisci errore di parsing o input vuoto
	dest = (char **)malloc(sizeof(char *) * (token + 1));
	if (!dest)
		return (NULL);
	return fill_token(dest, input, token);
}

static void ft_print_token(char ** token)
{
	if (token)
	{
		int i = 0;
		while (token[i])
		{
			printf("Token[%d]: %s\n", i, token[i]);
			i++;
		}
	}
}

int	main(void)
{
	char	*input;
	t_token *token;
	
	token = NULL;
	while (1)
	{
		input = readline("minishell$ "); // Se l’utente digita qualcosa e preme Invio, readline() ritorna un puntatore a una stringa allocata dinamicamente contenente quel testo (senza il carattere \n).
		if (!input) // Se l’utente preme Ctrl-D a inizio riga, readline() ritorna NULL.
			break; // il programma termina
		if (input && *input) // se input != NULL e non vuota
			add_history(input); // aggiungere una riga di testo alla cronologia dei comandi.
		token = ft_tokenize(input); // conta i token e crear l'array 
		ft_print_token(token);
		ft_free_token(token);
		free(input);
	}
	rl_clear_history(); // NON prende parametri.
	return (0);
}
