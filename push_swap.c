/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:17:40 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/15 16:42:20 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_a(t_sort *s, char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i--)
		ft_push(&s->stack_a, new_lst(ft_atoi(str[i])));
	free_str(str, 0, 3);
}

void	sort(t_sort *s)
{
	t_lst	*node;
	int		min;

	push_min_to_b(s, before(s->stack_a));
	while (s->stack_b)
	{
		best_move(s);
		pa(&s->stack_a, &s->stack_b, 1);
	}
	node = s->stack_a;
	min = node->number;
	while (node)
	{
		if (node->number < min)
			min = node->number;
		node = node->next;
	}
	move_min_top(&s->stack_a, get_index(s->stack_a, min));
}

int	is_sorted(t_lst *list)
{
	while (list->next)
	{
		if (list->number < list->next->number)
			list = list->next;
		else
			return (0);
	}
	return (1);
}

void	push_swap(t_sort *s, int ac, char **av)
{
	char	**str;
	int		len;

	str = ft_joinargs(ac, av);
	ft_check_digit(str);
	fill_stack_a(s, str);
	len = lst_size(s->stack_a);
	if (len == 1 && !is_sorted(s->stack_a))
		return ;
	else if (len == 2 && !is_sorted(s->stack_a))
		sort_two(s);
	else if (len == 3 && !is_sorted(s->stack_a))
		sort_three(s);
	else if (len == 4 && !is_sorted(s->stack_a))
		sort_four(search_min(s->stack_a), s);
	else if (len == 5 && !is_sorted(s->stack_a))
		sort_five(search_min(s->stack_a), s);
	else if (len > 5 && !is_sorted(s->stack_a))
		sort(s);
	free_linked(&s->stack_a);
}
