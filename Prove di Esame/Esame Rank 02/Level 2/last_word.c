/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:10:02 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/13 18:10:05 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
        int i;
        
        i = 0;
        if (argc == 2)
        {
                while (argv[1][i])
                        i++;
                i--;
                while (argv[1][i] == ' ')
                        i--;
                while (i >= 0 && argv[1][i] != ' ')
                        i--;
                i++;
                while (argv[1][i] && argv[1][i] != ' ')
                {
                        write(1, &argv[1][i], 1);
                        i++;
                }
        }
        write(1, "\n", 1);
        return(0);
}
