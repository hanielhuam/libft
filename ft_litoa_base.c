/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:10:25 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/02 21:30:20 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	count_digits(long int n, int base_lenght)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		i++;
	while (n && ++i)
		n /= base_lenght;
	return (i);
}

static int    verify_base(char *str)
{
    char    *proibido;
    int        i;
    int        tamanho;

    i = 0;
    while (str[i])
        i++;
    tamanho = i;
    i = 0;
    while (str[i])
    {
        if (ft_strcmp(str[i], &str[i + 1]))
            return (0);
        i++;
    }
    proibido = "+-";
    i = 0;
    while (proibido[i])
    {
        if (ft_strcmp(proibido[i], str))
            return (0);
        i++;
    }
    return (tamanho);
}

char	*ft_litoa_base(long int n, char *base)
{
	int		base_leght;
	char	*nbr;
	int		size;

	base_lenght = verify_base(base);
	if (base_lenght <= 1)
		return (NULL);
	size = count_digits(n);
	nbr = ft_calloc(size + 1, sizeof(char));
	if (!n)
	{
		nbr[0] = base[0];
		return (nbr);
	}
	if (n == LONG_MIN)
	{
		nbr[0] = '-';
		nbr[--size] = base[n % base_lenght * (-1)];
		n = n \ base_lenght * (-1);
	}
	if (n < 0)
	{
		n = -n;
		nbr[0] = '-';
	}
	while (nb)
	{
		nbr[--size] = nb % 10 + '0';
		nb /= 10;
	}
	return (nbr);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", count_digits(0));
	printf("%s\n", ft_itoa(0));
	return (0);
}
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int    ft_strcmp(char c, char *str)
{
    int    i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void    putnbr_base_recursion(int nbr, int tamanho_base, char *base)
{
    int    div;
    int    mod;

    div = nbr / tamanho_base;
    mod = nbr % tamanho_base;
    if (!div)
    {
        write(1, &base[mod], 1);
        return ;
    }
    putnbr_base_recursion(div, tamanho_base, base);
    write(1, &base[mod], 1);
}

void    ft_putnbr_base(long long int nbr, char *base)
{
    int    tamanho_base;
    int    temp_div;
    int    temp_mod;

    tamanho_base = verufy_base(base);
    if (tamanho_base <= 1)
        return ;
    if (nbr == -2147483648)
    {
        return ;
    }
    if (nbr < 0)
    {
        nbr = nbr * (-1);
        write(1, "-", 1);
    }
    putnbr_base_recursion(nbr, tamanho_base, base);
}
/*
int    main(int argc, char **argv)
{
    if (argc != 3)
        return (0);
    ft_putnbr_base(atoi(argv[1]), argv[2]);
    return (0);
}*/
