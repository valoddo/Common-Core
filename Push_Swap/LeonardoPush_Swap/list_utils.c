/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:02:06 by lmenoni           #+#    #+#             */
/*   Updated: 2025/02/26 18:02:25 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_lstsize(t_intlist *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_intlist	*int_lstlast(t_intlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	int_lstadd_back(t_intlist **lst, t_intlist *new)
{
	t_intlist	*tmp;

	tmp = int_lstlast(*lst);
	if (!lst || !new)
		return ;
	if (*lst)
	{
		tmp->next = new;
		new->prev = tmp;
	}
	else
		*lst = new;
}

t_intlist	*int_lstnew(int content)
{
	t_intlist	*lst;

	lst = (t_intlist *)malloc(sizeof(t_intlist));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->prev = NULL;
	lst->idx = 0;
	lst->price = 0;
	lst->curr_pos = 0;
	lst->upp_med = false;
	return (lst);
}
