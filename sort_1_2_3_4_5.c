/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1_2_3_4_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:29:04 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/12 18:11:59 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_sort *s)
{
	int	num_1;
	int	num_2;

	num_1 = s->stack_a->number;
	num_2 = s->stack_a->next->number;
	if (num_1 > num_2)
		sa(&s->stack_a, 1);
}

void	sort_three(t_sort *s)
{
	int		num_1;
	int		num_2;
	int		num_3;

	num_1 = s->stack_a->number;
	num_2 = s->stack_a->next->number;
	num_3 = s->stack_a->next->next->number;
	if (num_1 < num_2 && num_1 < num_3 && num_2 > num_3)
	{
		rra(&s->stack_a, 1);
		sa(&s->stack_a, 1);
	}
	else if (num_1 > num_2 && num_1 > num_3 && num_2 > num_3)
	{
		ra(&s->stack_a, 1);
		sa(&s->stack_a, 1);
	}
	else if (num_1 < num_2 && num_1 > num_3 && num_2 > num_3)
		rra(&s->stack_a, 1);
	else if (num_1 > num_2 && num_1 < num_3 && num_2 < num_3)
		sa(&s->stack_a, 1);
	else if (num_1 > num_2 && num_1 > num_3 && num_2 < num_3)
		ra(&s->stack_a, 1);
}

int	search_min(t_lst *list)
{
	t_lst	*node;
	int		min;
	int		pos;
	int		i;

	i = 0;
	pos = 0;
	min = list->number;
	node = list;
	while (node)
	{
		if (min > node->number)
		{
			min = node->number;
			pos = i;
		}
		node = node->next;
		i++;
	}
	return (pos);
}

void	sort_four(int pos, t_sort *s)
{
	if (pos == 0)
		pb(&s->stack_a, &s->stack_b, 1);
	else if (pos == 1)
	{
		sa(&s->stack_a, 1);
		pb(&s->stack_a, &s->stack_b, 1);
	}
	else if (pos == 2)
	{
		rra(&s->stack_a, 1);
		rra(&s->stack_a, 1);
		pb(&s->stack_a, &s->stack_b, 1);
	}
	else if (pos == 3)
	{
		rra(&s->stack_a, 1);
		pb(&s->stack_a, &s->stack_b, 1);
	}
	sort_three(s);
	pa(&s->stack_a, &s->stack_b, 1);
}

void	sort_five(int pos, t_sort *s)
{
	if (pos == 1)
		sa(&s->stack_a, 1);
	else if (pos == 2)
	{
		ra(&s->stack_a, 1);
		ra(&s->stack_a, 1);
	}
	else if (pos == 3)
	{
		rra(&s->stack_a, 1);
		rra(&s->stack_a, 1);
	}
	else if (pos == 4)
		rra(&s->stack_a, 1);
	pb(&s->stack_a, &s->stack_b, 1);
	sort_four(search_min(s->stack_a), s);
	pa(&s->stack_a, &s->stack_b, 1);
}
