/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:50:21 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/12 13:56:10 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*sort_lst_tmp(t_lst *list)
{
	t_lst	*node;
	int		swap;

	node = list;
	while (node->next)
	{
		if (node->number > node->next->number)
		{
			swap = node->number;
			node->number = node->next->number;
			node->next->number = swap;
			node = list;
		}
		else
			node = node->next;
	}
	return (list);
}

int	before(t_lst *list)
{
	t_lst	*new_list;
	t_lst	*node;
	int		value;

	new_list = 0;
	while (list)
	{
		ft_push(&new_list, new_lst(list->number));
		list = list->next;
	}
	node = sort_lst_tmp(new_list);
	value = get_value(node, lst_size(node) / 2);
	while (new_list)
		ft_pop(&new_list);
	return (value);
}	
