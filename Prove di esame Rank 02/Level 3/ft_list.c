/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:12:52 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/11 15:12:54 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct  s_list
{
        struct s_list *next;
        void          *data;
}                    t_list;


int list_size(t_list *begin_list)
{
        int     i;
        
        i = 0;
        while(begin_list)
        {
          begin_list = begin_list->next;
          i++;
        }
        return (i);
}






int main()
{
        t_list *list;
        t_list *listnew;
        t_list *listnewnew;
        int     i = 42;
        int    j = 21;
        int     x = 12;
        
        list = (t_list *)malloc(sizeof(t_list));
        listnew = (t_list *)malloc(sizeof(t_list));
        listnewnew= (t_list *)malloc(sizeof(t_list));

        list->data = &i;
        list->next = NULL;
        listnew->data = &j;
        listnew->next= NULL;
        list->next = listnew;
        listnewnew->data= &x;
        listnewnew->next = NULL;
        listnew->next = listnewnew;
        printf("%d\n", list_size(list));
        printf("%d\n", *(int *)list->data);
        list = list->next;
        printf("%d\n", *(int *)list->data);        
        return(0);
}
