/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:06:44 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/13 12:39:08 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_help(t_sort *s, t_count **best, t_count *commn, int *check)
{
	static int	min;

	if (*check)
	{
		min = s->move_stack_a + s->move_stack_b;
		if (!*check)
			free(*best);
		*best = commn;
		*check = 0;
	}
	else if (s->move_stack_a + s->move_stack_b < min)
	{
		free(*best);
		*best = commn;
		min = s->move_stack_a + s->move_stack_b;
	}
	else
		free(commn);
}

int	count_in_a(t_sort *s, int num, char *a)
{
	t_lst	*node;
	int		min_or_max;
	int		move_stack_a;

	node = s->stack_a;
	min_or_max = get_min_or_max(&s->stack_a, num);
	move_stack_a = count_move(&node, get_index(node, min_or_max), a);
	return (move_stack_a);
}

void	count_a(t_sort *s, int num, t_count *commn)
{
	int	move_stack_a;

	move_stack_a = count_in_a(s, num, &s->a);
	if (s->a == 'u')
	{
		commn->ra = move_stack_a;
		commn->rra = 0;
	}
	else if (s->a == 'd')
	{
		commn->rra = move_stack_a;
		commn->ra = 0;
	}
}

t_count	*count_in_b(t_sort *s, int num)
{
	int		move_stack_b;
	t_lst	*node;
	t_count	*commn;

	node = s->stack_b;
	commn = malloc(sizeof(t_count));
	if (!commn)
		exit (1);
	move_stack_b = count_move(&node, get_index(node, num), &s->b);
	if (s->b == 'u')
	{
		commn->rb = move_stack_b;
		commn->rrb = 0;
	}
	else if (s->b == 'd')
	{
		commn->rrb = move_stack_b;
		commn->rb = 0;
	}
	count_a(s, num, commn);
	return (commn);
}

void	best_move(t_sort *s)
{
	t_lst	*tmp;
	t_count	*commn;
	t_count	*best;
	int		check;

	check = 1;
	tmp = s->stack_b;
	while (tmp)
	{
		commn = count_in_b(s, tmp->number);
		s->move_stack_a = max_in_ra_rb(commn);
		s->move_stack_b = max_in_rra_rrb(commn);
		norm_help(s, &best, commn, &check);
		tmp = tmp->next;
	}
	move_top(s, best);
}
