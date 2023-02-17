/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:34:51 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/12 17:50:23 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_top(t_lst **list, int index)
{
	int	len;
	int	move;

	move = 0;
	if (index == 0)
		return ;
	len = lst_size(*list) / 2;
	if (index > len)
		move = lst_size(*list) - index;
	else
		move = index;
	if (index <= len)
	{
		while (move--)
			ra(list, 1);
	}
	else
	{
		while (move--)
			rra(list, 1);
	}
}

int	count_move(t_lst **list, int pos, char *c)
{
	int	len;
	int	move;
	int	count;

	count = 0;
	len = lst_size(*list) / 2;
	if (pos > len)
	{
		move = lst_size(*list) - pos;
		*c = 'd';
	}
	else
	{	
		move = pos;
		*c = 'u';
	}
	while (move--)
		count++;
	return (count);
}

int	get_value(t_lst *list, int index)
{
	int	i;

	i = 0;
	while (list)
	{
		if (i == index)
			return (list->number);
		list = list->next;
		i++;
	}
	return (0);
}

int	get_index(t_lst *list, int min)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->number == min)
			return (i);
		i++;
		list = list->next;
	}
	return (0);
}

void	move_top(t_sort *s, t_count *best)
{
	while (best->rr--)
		rr(&s->stack_a, &s->stack_b, 1);
	while (best->rrr--)
		rrr(&s->stack_a, &s->stack_b, 1);
	while (best->ra--)
		ra(&s->stack_a, 1);
	while (best->rb--)
		rb(&s->stack_b, 1);
	while (best->rra--)
		rra(&s->stack_a, 1);
	while (best->rrb--)
		rrb(&s->stack_b, 1);
	free(best);
}
