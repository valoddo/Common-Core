/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:29:15 by vloddo            #+#    #+#             */
/*   Updated: 2024/12/11 13:29:17 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// static int	countwords(const char *s, char c)
// {
// 	int	r;
// 	int	in_word;

// 	r = 0;
// 	in_word = 0;
// 	while (*s)
// 	{
// 		if (*s != c && in_word == 0)
// 		{
// 			r++;
// 			in_word = 1;
// 		}
// 		else if (*s == c)
// 			in_word = 0;
// 		s++;
// 	}
// 	return (r);
// }

// static void	ft_free(char **s, int i)
// {
// 	while (i-- > 0)
// 		free(s[i]);
// 	free(s);
// }

// static int	word_len(const char *s, unsigned int start, char end)
// {
// 	int	i;

// 	i = 0;
// 	while (s[start] != end && s[start] != 0)
// 	{
// 		i++;
// 		start++;
// 	}
// 	return (i);
// }

// static char	**fill_split(char **dest, const char *s, char c, int words)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	j = 0;
// 	while (i < words)
// 	{
// 		while (s[j] == c)        (*i)++;
// 			j++;
// 		dest[i] = (char *)malloc(sizeof(char) * (word_len(s, j, c) + 1));
// 		if (!dest[i])
// 			return (ft_free(dest, i), (NULL));
// 		k = 0;
// 		while (s[j] && s[j] != c)
// 			dest[i][k++] = s[j++];
// 		dest[i][k] = '\0';
// 		i++;
// 	}
// 	dest[i] = (NULL);
// 	return (dest);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**dest;
// 	int		words;        (*i)++;

// 	if (!s)
// 		return (NULL);
// 	words = countwords(s, c);
// 	dest = (char **)malloc(sizeof(char *) * (words + 1));
// 	if (!dest)
// 		return (NULL);
// 	return (fill_split(dest, s, c, words));
// }

int word_count(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i]) // Conta le parole
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}
char *s0_fill(char *s)
{
    int i;
    char *word;

	i = 0;
    while(s[i])
        i++;
    word = malloc(i + 1);  // Alloca memoria per la parola
    if (!word)
        return NULL;
    i = 0;
    while (s[i])  // Copia la parola
    {
        word[i] = s[i];
        i++;
    }
    word[i] = '\0';  // Aggiungi il terminatore
    return (word);
}
char *word_fill(char *s, char c, int *i)
{
    int j;
    char *word;

	j = 0;
    while (s[*i] == c)  // Salta i separatori iniziali
        (*i)++;
    while (s[*i + j] && s[*i + j] != c)  // Trova la fine della parola
        j++;
    word = malloc(j + 1);  // Alloca memoria per la parola
    if (!word)
        return NULL;
    j = 0;
    while (s[*i] && s[*i] != c)  // Copia la parola
    {
        word[j] = s[*i];
        j++;
        (*i)++;
    }
    word[j] = '\0';  // Aggiungi il terminatore
    return (word);
}
void free_memory(char **array, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(array[i]); // Libera ogni stringa allocata
        i++;
    }
    free(array); // Libera l'array principale
}
char **ft_split(char const *s0, char const *s1, char c)
{
    int i;
	int j;	
	int word; 
    char **new_array;

	i = 0;
	word = word_count((char *)s1, c);
    new_array = malloc(sizeof(char *) * (word + 2)); // Alloca memoria per array
    if (!new_array)
        return NULL;
		j = 0;
		while (j <= word)  // Ciclo per estrarre le parole
		{
			if (j == 0)
                new_array[j] = s0_fill((char *)s0);  // Estrai la parola e aggiorna l'indice
            else
                new_array[j] = word_fill((char *)s1, c, &i);  // Estrai la parola e aggiorna l'indice
			if (!new_array[j])  // Gestione dell'errore in caso di allocazione fallita
				return (free_memory(new_array, j), NULL);
			j++;  // Avanza l'indice per la parola successiva
		}
		new_array[j] = (NULL);  // Termina l'array con NULL
		return (new_array);
}


// int main()
// {
// 	char **str = ft_split("Hello world", ' ');
// 	printf("%s\n", str[0]);
// 	printf("%s\n", str[1]);
// 	return (0);
// }