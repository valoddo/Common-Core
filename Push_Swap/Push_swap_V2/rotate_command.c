/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:20:52 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/28 14:20:54 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack *first;
	t_stack *last;

	if (!head || !*head || !(*head)->next) // 1. Controllo sicurezza per liste vuote o con un solo elemento
		return;    
	first = *head; // 2. Salva il primo elemento e trova l'ultimo
	last = *head;
	while (last->next != NULL) // 3. Trova l'ultimo nodo della lista
		last = last->next;
	*head = first->next;   // 4. Aggiorna i puntatori per la rotazione// La nuova testa è il secondo elemento
	first->next = NULL;    // Il primo elemento diventa l'ultimo
	last->next = first;    // Collega l'ex primo alla fine
}

void	ft_rotate_a(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}
void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	rotate(a);
    rotate(b);
	write(1, "rr\n", 3);
}
