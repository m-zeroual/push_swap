/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:08:19 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/17 08:52:55 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_int(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_unsigned(unsigned int nb)
{	
	unsigned int	num;

	num = len_int(nb);
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_unsigned(nb / 10);
		ft_unsigned(nb % 10);
	}
	return (num);
}
