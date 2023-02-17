/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:42:02 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/17 11:11:54 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	convert_to_int(const char *s)
{
	int		i;
	long	n;

	i = 1;
	n = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-')
	{
		i *= -1;
		s++;
	}
	else if (*s == '+')
	{
		s++;
	}
	while (ft_isdigit(*s))
	{
		n = (10 * n) + (*s - 48);
		s++;
	}
	return (n * i);
}

int	repeat_number(char **str)
{
	int		i;
	int		j;
	long	n1;
	long	n2;

	i = 0;
	n1 = 0;
	n2 = 0;
	while (str[i])
	{
		j = i + 1;
		n1 = convert_to_int(str[i]);
		while (str[j])
		{
			n2 = convert_to_int(str[j]);
			if (n1 == n2)
				return (0);
			j++;
		}
		if (!(n1 >= -2147483648 && n1 <= 2147483647)
			|| !(n2 >= -2147483648 && n2 <= 2147483647)
			|| ft_strlen(str[i]) > 11)
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][0] == '-' || str[i][0] == '+')
		{
			j++;
			if (str[i][j] == 0)
				free_str(str, -1, 1);
		}
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				free_str(str, -1, 1);
			j++;
		}
		i++;
	}
	if (!repeat_number(str))
		free_str(str, -1, 1);
}

int	empty_args(char *s)
{
	int	i;

	i = 0;
	while (!(s[i] >= 48 && s[i] <= 57))
	{
		if (!(s[i] >= 48 && s[i] <= 57) && s[i + 1] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_joinargs(int ac, char **av)
{
	int		i;
	char	*list;
	char	**str;

	i = 1;
	str = 0;
	list = ft_strdup("");
	while (i < ac)
	{
		if (!empty_args(av[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free(list);
			exit(1);
		}
		list = ft_strjoin(list, av[i]);
		if (i != ac - 1)
		{
			list = ft_strjoin(list, " ");
		}
		i++;
	}
	str = ft_split(list, ' ');
	free(list);
	return (str);
}
