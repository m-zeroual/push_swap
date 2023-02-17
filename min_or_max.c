/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_or_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:32 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/17 08:37:03 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_or_max(t_lst **list, int num)
{
	int		min;
	int		check;
	int		max;
	t_lst	*tmp;

	check = 1;
	min = (*list)->number;
	tmp = *list;
	while (*list)
	{
		if ((*list)->number > num && ((*list)->number < max || check))
		{
			max = (*list)->number;
			check = 0;
		}
		if (min < (*list)->number)
			min = (*list)->number;
		*list = (*list)->next;
	}
	*list = tmp;
	if (!check)
		return (max);
	else
		return (min);
}
