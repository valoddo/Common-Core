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
        ft_error(3);
    while (argv[i] >= '0' && argv[i] <= '9')
    {
        nb = (nb * 10) + (argv[i] - '0');
        i++;
    }
    nb *= sign;
    return (nb);
}

int is_duplicate(t_stack *a, int value) // Funzione per controllare se un numero è già nella lista
{
    while (stack)
    {
        if (stack->value == value)
            return (1); // Numero duplicato trovato
        stack = stack->next;
    }
    return (0);
}


void add_to_list(t_stack **stack, int value) // Funzione per aggiungere un nodo in coda alla lista
{
    t_stack *new = new_node(value);
    t_stack *temp = *stack;

    if (!new)
        return;
    if (!*stack)
        *stack = new;
    else
    {
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
}


int ft_fill_a(t_stack **a, char **argv)
{
    int j;
    int nb;
    t_stack *temp;

    j = 1; // Iniziamo dal secondo argomento (argv[1])
    while (argv[j]) // ciclo per ogni argomento
    {
        nb = ft_atoi(argv[j]); // Usa la funzione ft_atoi per convertire la stringa in un numero
        temp = *a;
        while (temp) // Controllo duplicati
        {
            if (temp->value == nb) // Se il numero è già presente nella lista
                return (4); // Errore per numero duplicato
            temp = temp->next;
        }
        add_to_list(a, nb); // Aggiungi il numero alla lista
        j++; // Passa al prossimo argomento
    }
    return (0); // Successo
}
