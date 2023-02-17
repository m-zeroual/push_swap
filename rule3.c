/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:55:17 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/12 18:09:02 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_lst **list_a, int n)
{
	t_lst	*tmp;
	t_lst	*tmp1;
	int		list_a_len;

	tmp = 0;
	tmp1 = 0;
	list_a_len = lst_size(*list_a);
	if (list_a_len >= 2)
	{
		while ((*list_a)->next)
			ft_push(&tmp, new_lst(ft_pop(list_a)));
		tmp1 = new_lst(ft_pop(list_a));
		while (tmp)
			ft_push(list_a, new_lst(ft_pop(&tmp)));
		ft_push(list_a, tmp1);
		if (n == 1)
			ft_printf("rra\n");
	}
}

void	rrb(t_lst **list_b, int n)
{
	t_lst	*tmp;
	t_lst	*tmp1;
	int		list_b_len;

	tmp = 0;
	tmp1 = 0;
	list_b_len = lst_size(*list_b);
	if (list_b_len >= 2)
	{
		while ((*list_b)->next)
			ft_push(&tmp, new_lst(ft_pop(list_b)));
		tmp1 = new_lst(ft_pop(list_b));
		while (tmp)
			ft_push(list_b, new_lst(ft_pop(&tmp)));
		ft_push(list_b, tmp1);
		if (n == 1)
			ft_printf("rrb\n");
	}
}

void	rrr(t_lst **list_a, t_lst **list_b, int n)
{
	int	list_a_len;
	int	list_b_len;

	list_a_len = lst_size(*list_a);
	list_b_len = lst_size(*list_b);
	if (list_a_len >= 2)
		rra(list_a, 0);
	if (list_b_len >= 2)
		rrb(list_b, 0);
	if (n == 1)
		ft_printf("rrr\n");
}
