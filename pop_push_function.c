/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_push_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:34:17 by mzeroual          #+#    #+#             */
/*   Updated: 2023/02/17 09:34:23 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pop(t_lst **lst)
{
	t_lst	*node;
	int		value;

	node = *lst;
	*lst = (*lst)->next;
	value = node->number;
	free(node);
	return (value);
}

void	ft_push(t_lst **lst, t_lst *new)
{
	new->next = *lst;
	*lst = new;
}

int	lst_size(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_lst	*new_lst(int num)
{
	t_lst	*list;

	list = malloc(sizeof(t_lst));
	if (!list)
		exit (1);
	list->number = num;
	list->next = NULL;
	return (list);
}
