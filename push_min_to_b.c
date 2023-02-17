/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:53:15 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/12 18:10:09 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fun(t_sort *s, int value)
{
	int	brk;
	int	check;

	check = 1;
	brk = 0;
	while (s->stack_a)
	{
		if (s->stack_a->number < value)
			pb(&s->stack_a, &s->stack_b, 1);
		else if (s->stack_a->number == brk)
			break ;
		else
		{
			if (check)
			{
				brk = s->stack_a->number;
				check = 0;
			}
			ra(&s->stack_a, 1);
		}
	}
}

void	push_min_to_b(t_sort *s, int value)
{
	while (s->stack_a)
	{
		if (lst_size(s->stack_a) == 2)
			break ;
		else
		{
			fun(s, value);
			push_min_to_b(s, before(s->stack_a));
		}
	}
}
