/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:31:05 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/17 09:52:19 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_sort	s;
	char	**str;

	s.stack_a = 0;
	s.stack_b = 0;
	if (ac != 1)
	{
		str = ft_joinargs(ac, av);
		ft_check_digit(str);
		fill_stack_a(&s, str);
		ft(&s);
		if (is_sorted(s.stack_a) && !s.stack_b)
		{
			free_linked(&s.stack_a);
			print_res("OK", 1);
		}
		else
		{
			free_linked(&s.stack_a);
			print_res("KO", 1);
		}
		free_linked(&s.stack_a);
	}
}
