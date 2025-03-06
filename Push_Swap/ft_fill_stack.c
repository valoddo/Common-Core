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

int ft_atoi(char *argv)
{
    int	i;
    int	nb;
    int	sign;

    i = 0;
    nb = 0;
    sign = 1;
    while (argv[i])
    {
        if (argv[0] == '+')
            i++;
        else if (argv[0] == '-')
        {
            sign = -1;
            i++;
        }
		if (argv[i] < '0' || argv[i] > '9') // controlla se il primo carattere è un numero
		{
			return(ft_error(3));
		}	
		while (argv[i] >= '0' && argv[i] <= '9')
		{
			nb = (nb * 10) + (argv[i] - '0');
			i++;
		}
	}
	return (nb *= sign);
}
int	ft_nb_is_present(t_stack *a, int nb)
{
	while (a)
	{
		if (a->value == nb)// Se il numero è già presente
			return (1); // Restituiamo 1 (vero)
		a = a->next; // Passiamo al nodo successivo
	}
	return (0); // Se il numero non è presente, restituiamo 0 (falso)
}
t_stack	*ft_new_node(int nb)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL); // Restituiamo NULL in caso di errore
	new_node->value = nb; // Assegniamo il valore al nodo
	new_node->next = NULL; // Impostiamo il prossimo nodo come NULL (per ora)
	return (new_node);
}

void	ft_insert_node (t_stack **a, t_stack *temp)
{
    if (*a == NULL)
        *a = temp; // Se lo stack è vuoto, il nuovo nodo diventa la testa
    else 
	{
        temp->next = *a; // Colleghiamo il nuovo nodo alla testa attuale
        *a = temp; // Il nuovo nodo diventa la nuova testa
    }
}

void	ft_fill_stack(t_stack **a, char **argv)
{
	int	j;
	int	nb;
	t_stack	*temp;

	j = 1; // Iniziamo dal secondo argomento (argv[1])
	while (argv[j]) // ciclo per ogni argomento
	{
		nb = ft_atoi(argv[j]); // Usa la funzione ft_atoi per convertire la stringa in un numero
		if (ft_nb_is_present(*a, nb) == 1) 
			ft_error(4);
        temp = ft_new_node(nb); // Creiamo il nuovo nodo con il numero
        ft_insert_node(a, temp); // Inseriamo il nodo nello stack
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