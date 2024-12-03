/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:56:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/02 18:04:40 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	count_digits(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		i++;
	while (n && ++i)
		n /= 10;
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nbr;
	int		size;
	long	nb;

	size = count_digits(n);
	nbr = ft_calloc(size + 1, sizeof(char));
	if (!n)
	{
		nbr[0] = '0';
		return (nbr);
	}
	nb = (long)n;
	if (nb < 0)
	{
		nb = -nb;
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
	printf("%s\n", ft_uitoa(0));
	return (0);
}
*/
