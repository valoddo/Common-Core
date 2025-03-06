/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:30:37 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/04 12:35:10 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int j;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
		    if (argv[1][i] >= 65 && argv[1][i] <= 90 )
		        {
		            j = 0;
		            while (j < argv[1][i] - 64)
		            {
                        	write(1, &argv[1][i], 1);
                        	j++;
			    }
		        }
		    else if (argv[1][i] >= 97 && argv[1][i] <= 122 )
	            {
	                j = 0;
		            while (j < (argv[1][i] - 96))
	                {
        	            write(1, &argv[1][i], 1);
	                    j++;
	                }
		    }
		    else
		        write(1, &argv[1][i], 1);
				i++;
		}
	}
	return (0);
}
