/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:53:27 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/12 17:48:47 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_lst **list_a, int n)
{
	t_lst	*tmp;
	int		value;
	int		list_a_len;

	tmp = 0;
	list_a_len = lst_size(*list_a);
	if (list_a_len >= 2)
	{
		value = ft_pop(list_a);
		while (*list_a)
			ft_push(&tmp, new_lst(ft_pop(list_a)));
		ft_push(list_a, new_lst(value));
		while (tmp)
			ft_push(list_a, new_lst(ft_pop(&tmp)));
		if (n == 1)
			ft_printf("ra\n");
	}
}

void	rb(t_lst **list_b, int n)
{
	t_lst	*tmp;
	int		value;
	int		list_a_len;

	tmp = 0;
	list_a_len = lst_size(*list_b);
	if (list_a_len >= 2)
	{
		value = ft_pop(list_b);
		while (*list_b)
			ft_push(&tmp, new_lst(ft_pop(list_b)));
		ft_push(list_b, new_lst(value));
		while (tmp)
			ft_push(list_b, new_lst(ft_pop(&tmp)));
		if (n == 1)
			ft_printf("rb\n");
	}
}

void	rr(t_lst **list_a, t_lst **list_b, int n)
{
	int	list_a_len;
	int	list_b_len;

	list_a_len = lst_size(*list_a);
	list_b_len = lst_size(*list_b);
	if (list_a_len >= 2)
		ra(list_a, 0);
	if (list_b_len >= 2)
		rb(list_b, 0);
	if (n == 1)
		ft_printf("rr\n");
}
