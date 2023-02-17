/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:51:07 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/13 11:35:46 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lst **list_a, int n)
{
	int		list_len;
	t_lst	*tmp1;
	t_lst	*tmp2;

	list_len = lst_size(*list_a);
	if (list_len >= 2)
	{
		tmp1 = new_lst(ft_pop(list_a));
		tmp2 = new_lst(ft_pop(list_a));
		ft_push(list_a, tmp1);
		ft_push(list_a, tmp2);
		if (n == 1)
			ft_printf("sa\n");
	}
}

void	sb(t_lst **list_b, int n)
{
	int		list_len;
	t_lst	*tmp1;
	t_lst	*tmp2;

	list_len = lst_size(*list_b);
	if (list_len >= 2)
	{
		tmp1 = new_lst(ft_pop(list_b));
		tmp2 = new_lst(ft_pop(list_b));
		ft_push(list_b, tmp1);
		ft_push(list_b, tmp2);
		if (n == 1)
			ft_printf("sb\n");
	}
}

void	ss(t_lst **list_a, t_lst **list_b, int n)
{
	int	list_a_len;
	int	list_b_len;

	list_a_len = lst_size(*list_a);
	list_b_len = lst_size(*list_b);
	if (list_a_len >= 2)
		sa(list_a, 0);
	if (list_b_len >= 2)
		sb(list_b, 0);
	if (n == 1)
		ft_printf("ss\n");
}

void	pa(t_lst **list_a, t_lst **list_b, int n)
{
	if (lst_size(*list_b))
		ft_push(list_a, new_lst(ft_pop(list_b)));
	if (n == 1)
		ft_printf("pa\n");
}

void	pb(t_lst **list_a, t_lst **list_b, int n)
{
	if (lst_size(*list_a))
		ft_push(list_b, new_lst(ft_pop(list_a)));
	if (n == 1)
		ft_printf("pb\n");
}
