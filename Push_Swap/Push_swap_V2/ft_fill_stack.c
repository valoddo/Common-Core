/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:33:31 by vloddo            #+#    #+#             */
/*   Updated: 2025/03/04 12:33:35 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_atoi(char *argv, int *nb)
{
	int	i;
	int	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (argv[i] == '+' || argv[i] == '-')
	{
		if (argv[i] == '-')
			sign = -1;
		i++;
	}
	while (argv[i] != '\0')
	{
		if (argv[i] >= '0' && argv[i] <= '9') 
			result = (result * 10) + (argv[i] - '0');
		if ((result > INT_MAX || (sign == -1 && result > (long long)INT_MAX + 1) ) || \
			(argv[i] < '0' || argv[i] > '9')) // controlla se il carattere è un numero //controlla se il numero rientra nel max e min di int
			return (0);
		i++;
	}
	*nb = (int)(result * sign);
	return (1);
}

static int	ft_nb_is_present(t_stack *a, int nb)
{
	while (a)
	{
		if (a->value == nb)// Se il numero è già presente
			return (1); // Restituiamo 1 (vero)
		a = a->next; // Passiamo al nodo successivo
	}
	return (0); // Se il numero non è presente, restituiamo 0 (falso)
}
static t_stack	*ft_new_node(int nb)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL); // Restituiamo NULL in caso di errore
	new_node->value = nb; // Assegniamo il valore al nodo
	new_node->next = NULL; // Impostiamo il prossimo nodo come NULL (per ora)
	return (new_node);
}

static void	ft_insert_node (t_stack **a, t_stack *new_node)
{
	t_stack *last;

	if (*a == NULL)
		*a = new_node; //se lo stack è vuoto il nuovo nodo diventa la testa
	else
	{
		last = *a; //la testa viene salvata nela temporanea last
		while (last->next != NULL) //scorro la lista fino alla file
			last = last->next; //trovo la fine della lista
		last->next = new_node; //imposto il nuovo nodo alla fine della lista
	}
}

void	ft_fill_stack(t_stack **a, char **argv, int argc)
{
	int	j;
	int	nb;
	t_stack	*new_node;

	nb = 0;
	j = 1; // Iniziamo dal secondo argomento (argv[1])
	while (argv[j]) // ciclo per ogni argomento
	{
		if (ft_atoi(argv[j], &nb) == 0) // Usa la funzione ft_atoi per convertire la stringa in un numero
			ft_error(a, "Error: insert correct number", 3, argv, argc); //atoi controlla se ci sono lettere o il numero è nel max o min int
		if (ft_nb_is_present(*a, nb) == 1) 
			ft_error(a, "Error: number presents more than once", 4, argv, argc);
        new_node = ft_new_node(nb); // Creiamo il nuovo nodo con il numero
        ft_insert_node(a, new_node); // Inseriamo il nodo nello stack
        j++; // Passiamo al prossimo argomento
    }
}

/* 
int main (int argc, char **argv) 
{
	t_stack *a = NULL; // Inizializziamo lo stack come NULL
    if (argc < 2) 
	{
        printf("Usage: ./program <numbers>\n");
        return 1;
    }

    // Riempie lo stack con i numeri da argv
    if (ft_fill_a(&a, argv) == 1) 
	{
        printf("Stack after filling:\n");
        while (a) // Stampa lo stack per il controllo 
		{
			printf("%d\n", a->value);
			a = a->next;
		}
    } else {
        printf("Error while filling stack\n");
        return 1;
    }
    return 0;
}*/