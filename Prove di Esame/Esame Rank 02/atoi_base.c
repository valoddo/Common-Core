/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:03:26 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/19 19:03:32 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Funzione per verificare se il carattere è valido per la base
int isvalid(int ch, int baselen)
{
    char *lcbase = "0123456789abcdef";
    char *ucbase = "0123456789ABCDEF";
    int i = 0;
    
    // Controlla se il carattere è valido nella base
    while (i < baselen)
    {
        if (ch == lcbase[i] || ch == ucbase[i])  // Trova il carattere nella base
            return 1;
        i++;
    }
    return 0;
}
int ft_atoi_base(const char *str, int str_base)
{
    int res = 0; 
    int sign = 1; 
    int i = 0;
    
    while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
        i++;
    if (str[i] == '-')
    {
        sign = sign * -1;
        i++;
    }
     else if (str[i] == '+')
        i++;
    while (str[i] && isvalid(str[i], str_base))   // Cicla attraverso la stringa e converte il numero nella base 10
    {
        res *= str_base;         // Moltiplica il risultato per la base
        if (str[i] >= '0' && str[i] <= '9')     // Aggiungi il valore del carattere al risultato
            res += str[i] - '0';  // Se è un numero
        else if (str[i] >= 'a' && str[i] <= 'f')
            res += str[i] - 'a' + 10;  // Se è una lettera minuscola
        else if (str[i] >= 'A' && str[i] <= 'F')
            res += str[i] - 'A' + 10;  // Se è una lettera maiuscola
        i++;
    }
    return (res * sign);
}
// Funzione di test (main)
#include <stdio.h>
int	main(int ac, char **av)
{
    if (ac == 3)
    {
        // Converti il secondo parametro in base 10 e usalo come base per il primo parametro
        printf("%d", ft_atoi_base(av[1], ft_atoi_base(av[2], 10)));
        return 0;
    }
    return 1;
}

